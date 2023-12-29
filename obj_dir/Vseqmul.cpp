// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vseqmul.h for the primary calling header

#include "Vseqmul.h"
#include "Vseqmul__Syms.h"

//==========

void Vseqmul::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vseqmul::eval\n"); );
    Vseqmul__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("seqmul.sv", 131, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vseqmul::_eval_initial_loop(Vseqmul__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("seqmul.sv", 131, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__2(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__2\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->Datapath__02Ereset) {
        vlTOPp->Datapath__DOT__shiftcarry = 0U;
    } else {
        if (vlTOPp->Datapath__02Eshift_signal) {
            vlTOPp->Datapath__DOT__shiftcarry = 0U;
        }
    }
    if (vlTOPp->Datapath__02Ereset) {
        vlTOPp->Datapath__DOT__shift_multiplier = 0U;
    } else {
        if (vlTOPp->Datapath__02Eshift_signal) {
            vlTOPp->Datapath__DOT__shift_multiplier 
                = (0xffffU & (((IData)(vlTOPp->Datapath__02Emultiplier) 
                               >> 1U) | (0x8000U & 
                                         ((IData)(vlTOPp->Datapath__DOT__intermediate_accumulator) 
                                          << 0xfU))));
        }
    }
    if (vlTOPp->Datapath__02Ereset) {
        vlTOPp->Datapath__DOT__shift_accumulator = 0U;
    } else {
        if (vlTOPp->Datapath__02Eshift_signal) {
            vlTOPp->Datapath__DOT__shift_accumulator 
                = (0xffffU & (((IData)(vlTOPp->Datapath__DOT__intermediate_accumulator) 
                               >> 1U) | (0x8000U & 
                                         ((IData)(vlTOPp->Datapath__DOT__carryout) 
                                          << 0xfU))));
        }
    }
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__3(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__3\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__Controller__DOT__state;
    CData/*3:0*/ __Vdly__Controller__DOT__count;
    // Body
    __Vdly__Controller__DOT__count = vlTOPp->Controller__DOT__count;
    __Vdly__Controller__DOT__state = vlTOPp->Controller__DOT__state;
    if (vlTOPp->Controller__02Ereset) {
        __Vdly__Controller__DOT__state = 0U;
        __Vdly__Controller__DOT__count = 0U;
        vlTOPp->Controller__02Eadd_signal = 0U;
        vlTOPp->Controller__02Eshift_signal = 0U;
        vlTOPp->Controller__02Emux_signal = 0U;
    } else {
        if ((2U & (IData)(vlTOPp->Controller__DOT__state))) {
            if ((1U & (IData)(vlTOPp->Controller__DOT__state))) {
                __Vdly__Controller__DOT__count = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->Controller__DOT__count)));
                vlTOPp->Controller__02Eshift_signal = 1U;
                __Vdly__Controller__DOT__state = 1U;
            } else {
                vlTOPp->Controller__02Eadd_signal = 1U;
                __Vdly__Controller__DOT__state = 3U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->Controller__DOT__state))) {
                vlTOPp->Controller__02Emux_signal = 
                    (1U & (IData)(vlTOPp->Controller__02Emultiplier));
                __Vdly__Controller__DOT__state = 2U;
            } else {
                if (vlTOPp->Controller__02Estart) {
                    __Vdly__Controller__DOT__count = 0U;
                    vlTOPp->Controller__02Eadd_signal = 0U;
                    vlTOPp->Controller__02Eshift_signal = 0U;
                    vlTOPp->Controller__02Emux_signal = 0U;
                    __Vdly__Controller__DOT__state = 1U;
                }
            }
        }
    }
    vlTOPp->Controller__DOT__state = __Vdly__Controller__DOT__state;
    vlTOPp->Controller__DOT__count = __Vdly__Controller__DOT__count;
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__4(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__4\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath__DOT__intermediate_accumulator 
        = ((IData)(vlTOPp->Datapath__02Eadd_signal)
            ? ((IData)(vlTOPp->Datapath__DOT__mux_output) 
               ^ (IData)(vlTOPp->accumulator)) : (IData)(vlTOPp->accumulator));
    vlTOPp->Datapath__DOT__carryout = (1U & (((IData)(vlTOPp->Datapath__DOT__mux_output) 
                                              & (IData)(vlTOPp->accumulator)) 
                                             | ((IData)(vlTOPp->Datapath__DOT__carryin) 
                                                & ((IData)(vlTOPp->Datapath__DOT__mux_output) 
                                                   ^ (IData)(vlTOPp->accumulator)))));
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__6(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__6\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath__DOT__shiftcarry = 0U;
    vlTOPp->Datapath__DOT__shift_multiplier = 0U;
    vlTOPp->Datapath__DOT__shift_accumulator = 0U;
    vlTOPp->Datapath__DOT__intermediate_accumulator = 0U;
    vlTOPp->Datapath__DOT__carryout = 0U;
    vlTOPp->Datapath__DOT__carryin = 0U;
    vlTOPp->Datapath__DOT__mux_output = 0U;
}

VL_INLINE_OPT void Vseqmul::_combo__TOP__7(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_combo__TOP__7\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath__DOT__mux_output = ((IData)(vlTOPp->Datapath__02Emux_signal)
                                          ? (IData)(vlTOPp->multiplicand)
                                          : 0U);
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__8(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__8\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->product = (((IData)(vlTOPp->Datapath__DOT__shift_accumulator) 
                        << 0x10U) | (IData)(vlTOPp->Datapath__DOT__shift_multiplier));
}

void Vseqmul::_eval(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->Datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Eclk))) 
         | ((IData)(vlTOPp->Datapath__02Ereset) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Ereset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->Controller__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Controller__02Eclk))) 
         | ((IData)(vlTOPp->Controller__02Ereset) & 
            (~ (IData)(vlTOPp->__Vclklast__TOP__Controller__02Ereset))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->Datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Eclk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->Datapath__02Ereset) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Ereset)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    if ((((IData)(vlTOPp->Datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Eclk))) 
         | ((IData)(vlTOPp->Datapath__02Ereset) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Ereset))))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__Datapath__02Ereset = vlTOPp->Datapath__02Ereset;
    vlTOPp->__Vclklast__TOP__Datapath__02Eclk = vlTOPp->Datapath__02Eclk;
    vlTOPp->__Vclklast__TOP__Controller__02Eclk = vlTOPp->Controller__02Eclk;
    vlTOPp->__Vclklast__TOP__Controller__02Ereset = vlTOPp->Controller__02Ereset;
}

VL_INLINE_OPT QData Vseqmul::_change_request(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_change_request\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vseqmul::_change_request_1(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_change_request_1\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vseqmul::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((Controller__02Eclk & 0xfeU))) {
        Verilated::overWidthError("Controller.clk");}
    if (VL_UNLIKELY((Controller__02Ereset & 0xfeU))) {
        Verilated::overWidthError("Controller.reset");}
    if (VL_UNLIKELY((Controller__02Estart & 0xfeU))) {
        Verilated::overWidthError("Controller.start");}
    if (VL_UNLIKELY((Datapath__02Eclk & 0xfeU))) {
        Verilated::overWidthError("Datapath.clk");}
    if (VL_UNLIKELY((Datapath__02Ereset & 0xfeU))) {
        Verilated::overWidthError("Datapath.reset");}
    if (VL_UNLIKELY((Datapath__02Estart & 0xfeU))) {
        Verilated::overWidthError("Datapath.start");}
    if (VL_UNLIKELY((Datapath__02Eadd_signal & 0xfeU))) {
        Verilated::overWidthError("Datapath.add_signal");}
    if (VL_UNLIKELY((Datapath__02Eshift_signal & 0xfeU))) {
        Verilated::overWidthError("Datapath.shift_signal");}
    if (VL_UNLIKELY((Datapath__02Emux_signal & 0xfeU))) {
        Verilated::overWidthError("Datapath.mux_signal");}
}
#endif  // VL_DEBUG

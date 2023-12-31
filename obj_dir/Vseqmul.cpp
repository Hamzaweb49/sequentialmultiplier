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
            VL_FATAL_MT("seqmul.sv", 10, "",
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
            VL_FATAL_MT("seqmul.sv", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__1(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__1\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__count 
        = vlTOPp->TopModule__DOT__ctrl_inst__DOT__count;
    vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__state 
        = vlTOPp->TopModule__DOT__ctrl_inst__DOT__state;
    vlTOPp->__Vdly__TopModule__DOT__mux_signal_int 
        = vlTOPp->TopModule__DOT__mux_signal_int;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->TopModule__DOT__shift_signal_int) {
            vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier 
                = (0xffffU & ((IData)(vlTOPp->TopModule__DOT__top_multiplier) 
                              >> 1U));
            vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier 
                = ((0x7fffU & (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier)) 
                   | (0x8000U & ((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__intermediate_accumulator) 
                                 << 0xfU)));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shiftcarry = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shiftcarry = 0U;
    } else {
        if (vlTOPp->TopModule__DOT__shift_signal_int) {
            vlTOPp->TopModule__DOT__dp_inst__DOT__shiftcarry = 0U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done = 0U;
    } else {
        if (vlTOPp->TopModule__DOT__shift_signal_int) {
            vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done = 1U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator = 0U;
    } else {
        if (vlTOPp->TopModule__DOT__shift_signal_int) {
            vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator 
                = (0xffffU & ((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__intermediate_accumulator) 
                              >> 1U));
            vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator 
                = ((0x7fffU & (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator)) 
                   | ((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__carryout) 
                      << 0xfU));
        }
    }
    vlTOPp->__Vdly__TopModule__DOT__shift_signal_int 
        = vlTOPp->TopModule__DOT__shift_signal_int;
    vlTOPp->product = (((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator) 
                        << 0x10U) | (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier));
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__carryout = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__intermediate_accumulator = 0U;
    }
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__2(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__2\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TopModule__DOT__dp_inst__DOT__carryout 
        = (1U & (((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output) 
                  & (IData)(vlTOPp->TopModule__DOT__top_accumulator)) 
                 | ((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__carryin) 
                    & ((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output) 
                       ^ (IData)(vlTOPp->TopModule__DOT__top_accumulator)))));
    vlTOPp->TopModule__DOT__dp_inst__DOT__intermediate_accumulator 
        = ((IData)(vlTOPp->TopModule__DOT__add_signal_int)
            ? ((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output) 
               ^ (IData)(vlTOPp->TopModule__DOT__top_accumulator))
            : (IData)(vlTOPp->TopModule__DOT__top_accumulator));
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__4(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__4\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__TopModule__DOT__add_signal_int;
    // Body
    __Vdly__TopModule__DOT__add_signal_int = vlTOPp->TopModule__DOT__add_signal_int;
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__carryin = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__top_accumulator = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__state = 0U;
        vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__count = 0U;
        __Vdly__TopModule__DOT__add_signal_int = 0U;
        vlTOPp->__Vdly__TopModule__DOT__shift_signal_int = 0U;
        vlTOPp->__Vdly__TopModule__DOT__mux_signal_int = 0U;
    } else {
        if ((2U & (IData)(vlTOPp->TopModule__DOT__ctrl_inst__DOT__state))) {
            if ((1U & (IData)(vlTOPp->TopModule__DOT__ctrl_inst__DOT__state))) {
                vlTOPp->TopModule__DOT__ctrl_inst__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->TopModule__DOT__ctrl_inst__DOT__count)));
                vlTOPp->TopModule__DOT__shift_signal_int = 0U;
                vlTOPp->TopModule__DOT__ctrl_inst__DOT__state = 0U;
            } else {
                vlTOPp->TopModule__DOT__add_signal_int = 0U;
                vlTOPp->TopModule__DOT__ctrl_inst__DOT__state = 3U;
                vlTOPp->__Vdly__TopModule__DOT__shift_signal_int = 1U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->TopModule__DOT__ctrl_inst__DOT__state))) {
                vlTOPp->TopModule__DOT__shift_signal_int = 0U;
                vlTOPp->TopModule__DOT__add_signal_int = 1U;
                vlTOPp->TopModule__DOT__ctrl_inst__DOT__state = 2U;
            } else {
                if (VL_UNLIKELY(vlTOPp->start)) {
                    vlTOPp->TopModule__DOT__mux_signal_int 
                        = (1U & (IData)(vlTOPp->TopModule__DOT__top_multiplier));
                    VL_WRITEF("The value of multiplier is %b and mux signal is %b\n",
                              16,vlTOPp->TopModule__DOT__top_multiplier,
                              1,(IData)(vlTOPp->TopModule__DOT__mux_signal_int));
                    vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__state = 1U;
                }
            }
        }
    }
    vlTOPp->TopModule__DOT__ctrl_inst__DOT__state = vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__state;
    vlTOPp->TopModule__DOT__ctrl_inst__DOT__count = vlTOPp->__Vdly__TopModule__DOT__ctrl_inst__DOT__count;
    vlTOPp->TopModule__DOT__add_signal_int = __Vdly__TopModule__DOT__add_signal_int;
    vlTOPp->TopModule__DOT__shift_signal_int = vlTOPp->__Vdly__TopModule__DOT__shift_signal_int;
    vlTOPp->TopModule__DOT__mux_signal_int = vlTOPp->__Vdly__TopModule__DOT__mux_signal_int;
    vlTOPp->add_signal = vlTOPp->TopModule__DOT__add_signal_int;
    vlTOPp->shift_signal = vlTOPp->TopModule__DOT__shift_signal_int;
    vlTOPp->mux_signal = vlTOPp->TopModule__DOT__mux_signal_int;
    if (vlTOPp->reset) {
        vlTOPp->TopModule__DOT__top_multiplier = 0U;
    }
}

VL_INLINE_OPT void Vseqmul::_combo__TOP__5(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_combo__TOP__5\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (VL_UNLIKELY(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done)) {
        VL_WRITEF("The value of shift multiplier is %b\n",
                  16,vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier);
        vlTOPp->TopModule__DOT__top_multiplier = vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier;
        vlTOPp->TopModule__DOT__top_accumulator = vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator;
    } else {
        if ((1U & (~ (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done)))) {
            vlTOPp->TopModule__DOT__top_multiplier 
                = vlTOPp->multiplier;
            vlTOPp->TopModule__DOT__top_accumulator 
                = vlTOPp->accumulator;
        }
    }
    vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output 
        = ((IData)(vlTOPp->TopModule__DOT__mux_signal_int)
            ? (IData)(vlTOPp->multiplicand) : 0U);
}

void Vseqmul::_eval(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
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
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((start & 0xfeU))) {
        Verilated::overWidthError("start");}
}
#endif  // VL_DEBUG

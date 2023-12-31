// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vseqmul__Syms.h"


//======================

void Vseqmul::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vseqmul::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vseqmul::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vseqmul::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vseqmul::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+11,"clk", false,-1);
        tracep->declBit(c+12,"reset", false,-1);
        tracep->declBit(c+13,"start", false,-1);
        tracep->declBus(c+14,"multiplier", false,-1, 15,0);
        tracep->declBus(c+15,"multiplicand", false,-1, 15,0);
        tracep->declBus(c+16,"accumulator", false,-1, 15,0);
        tracep->declBit(c+17,"add_signal", false,-1);
        tracep->declBit(c+18,"shift_signal", false,-1);
        tracep->declBit(c+19,"mux_signal", false,-1);
        tracep->declBus(c+20,"product", false,-1, 31,0);
        tracep->declBit(c+11,"TopModule clk", false,-1);
        tracep->declBit(c+12,"TopModule reset", false,-1);
        tracep->declBit(c+13,"TopModule start", false,-1);
        tracep->declBus(c+14,"TopModule multiplier", false,-1, 15,0);
        tracep->declBus(c+15,"TopModule multiplicand", false,-1, 15,0);
        tracep->declBus(c+16,"TopModule accumulator", false,-1, 15,0);
        tracep->declBit(c+17,"TopModule add_signal", false,-1);
        tracep->declBit(c+18,"TopModule shift_signal", false,-1);
        tracep->declBit(c+19,"TopModule mux_signal", false,-1);
        tracep->declBus(c+20,"TopModule product", false,-1, 31,0);
        tracep->declBit(c+5,"TopModule add_signal_int", false,-1);
        tracep->declBit(c+6,"TopModule shift_signal_int", false,-1);
        tracep->declBit(c+7,"TopModule mux_signal_int", false,-1);
        tracep->declBus(c+21,"TopModule top_multiplier", false,-1, 15,0);
        tracep->declBus(c+22,"TopModule top_accumulator", false,-1, 15,0);
        tracep->declBit(c+11,"TopModule dp_inst clk", false,-1);
        tracep->declBit(c+12,"TopModule dp_inst reset", false,-1);
        tracep->declBit(c+13,"TopModule dp_inst start", false,-1);
        tracep->declBit(c+5,"TopModule dp_inst add_signal", false,-1);
        tracep->declBit(c+6,"TopModule dp_inst shift_signal", false,-1);
        tracep->declBit(c+7,"TopModule dp_inst mux_signal", false,-1);
        tracep->declBus(c+15,"TopModule dp_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+22,"TopModule dp_inst accumulator", false,-1, 15,0);
        tracep->declBus(c+21,"TopModule dp_inst multiplier", false,-1, 15,0);
        tracep->declBus(c+20,"TopModule dp_inst product", false,-1, 31,0);
        tracep->declBus(c+1,"TopModule dp_inst shift_accumulator", false,-1, 15,0);
        tracep->declBus(c+23,"TopModule dp_inst mux_output", false,-1, 15,0);
        tracep->declBus(c+24,"TopModule dp_inst intermediate_accumulator", false,-1, 15,0);
        tracep->declBus(c+2,"TopModule dp_inst shift_multiplier", false,-1, 15,0);
        tracep->declBit(c+8,"TopModule dp_inst carryin", false,-1);
        tracep->declBit(c+25,"TopModule dp_inst carryout", false,-1);
        tracep->declBit(c+3,"TopModule dp_inst shiftcarry", false,-1);
        tracep->declBit(c+4,"TopModule dp_inst shift_done", false,-1);
        tracep->declBus(c+15,"TopModule dp_inst mux_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+26,"TopModule dp_inst mux_inst zeros", false,-1, 15,0);
        tracep->declBit(c+7,"TopModule dp_inst mux_inst mux_signal", false,-1);
        tracep->declBus(c+23,"TopModule dp_inst mux_inst selected_input", false,-1, 15,0);
        tracep->declBit(c+11,"TopModule dp_inst add_inst clk", false,-1);
        tracep->declBus(c+23,"TopModule dp_inst add_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+22,"TopModule dp_inst add_inst accumulator", false,-1, 15,0);
        tracep->declBit(c+8,"TopModule dp_inst add_inst carryin", false,-1);
        tracep->declBit(c+5,"TopModule dp_inst add_inst add_signal", false,-1);
        tracep->declBus(c+24,"TopModule dp_inst add_inst accumulator_out", false,-1, 15,0);
        tracep->declBit(c+25,"TopModule dp_inst add_inst carryout", false,-1);
        tracep->declBit(c+11,"TopModule dp_inst shift_inst clk", false,-1);
        tracep->declBit(c+12,"TopModule dp_inst shift_inst reset", false,-1);
        tracep->declBit(c+6,"TopModule dp_inst shift_inst enable", false,-1);
        tracep->declBus(c+24,"TopModule dp_inst shift_inst accumulator", false,-1, 15,0);
        tracep->declBus(c+21,"TopModule dp_inst shift_inst multiplier", false,-1, 15,0);
        tracep->declBus(c+25,"TopModule dp_inst shift_inst carry", false,-1, 0,0);
        tracep->declBit(c+4,"TopModule dp_inst shift_inst shift_done", false,-1);
        tracep->declBus(c+1,"TopModule dp_inst shift_inst accumulator_out", false,-1, 15,0);
        tracep->declBus(c+2,"TopModule dp_inst shift_inst multiplier_out", false,-1, 15,0);
        tracep->declBus(c+3,"TopModule dp_inst shift_inst carry_out", false,-1, 0,0);
        tracep->declBit(c+11,"TopModule ctrl_inst clk", false,-1);
        tracep->declBit(c+12,"TopModule ctrl_inst reset", false,-1);
        tracep->declBit(c+13,"TopModule ctrl_inst start", false,-1);
        tracep->declBus(c+21,"TopModule ctrl_inst multiplier", false,-1, 15,0);
        tracep->declBit(c+5,"TopModule ctrl_inst add_signal", false,-1);
        tracep->declBit(c+6,"TopModule ctrl_inst shift_signal", false,-1);
        tracep->declBit(c+7,"TopModule ctrl_inst mux_signal", false,-1);
        tracep->declBus(c+27,"TopModule ctrl_inst IDLE", false,-1, 1,0);
        tracep->declBus(c+28,"TopModule ctrl_inst ADD", false,-1, 1,0);
        tracep->declBus(c+29,"TopModule ctrl_inst SHIFT", false,-1, 1,0);
        tracep->declBus(c+30,"TopModule ctrl_inst CHECKCOUNT", false,-1, 1,0);
        tracep->declBus(c+9,"TopModule ctrl_inst state", false,-1, 1,0);
        tracep->declBus(c+10,"TopModule ctrl_inst count", false,-1, 3,0);
    }
}

void Vseqmul::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vseqmul::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vseqmul::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator),16);
        tracep->fullSData(oldp+2,(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier),16);
        tracep->fullBit(oldp+3,(vlTOPp->TopModule__DOT__dp_inst__DOT__shiftcarry));
        tracep->fullBit(oldp+4,(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done));
        tracep->fullBit(oldp+5,(vlTOPp->TopModule__DOT__add_signal_int));
        tracep->fullBit(oldp+6,(vlTOPp->TopModule__DOT__shift_signal_int));
        tracep->fullBit(oldp+7,(vlTOPp->TopModule__DOT__mux_signal_int));
        tracep->fullBit(oldp+8,(vlTOPp->TopModule__DOT__dp_inst__DOT__carryin));
        tracep->fullCData(oldp+9,(vlTOPp->TopModule__DOT__ctrl_inst__DOT__state),2);
        tracep->fullCData(oldp+10,(vlTOPp->TopModule__DOT__ctrl_inst__DOT__count),4);
        tracep->fullBit(oldp+11,(vlTOPp->clk));
        tracep->fullBit(oldp+12,(vlTOPp->reset));
        tracep->fullBit(oldp+13,(vlTOPp->start));
        tracep->fullSData(oldp+14,(vlTOPp->multiplier),16);
        tracep->fullSData(oldp+15,(vlTOPp->multiplicand),16);
        tracep->fullSData(oldp+16,(vlTOPp->accumulator),16);
        tracep->fullBit(oldp+17,(vlTOPp->add_signal));
        tracep->fullBit(oldp+18,(vlTOPp->shift_signal));
        tracep->fullBit(oldp+19,(vlTOPp->mux_signal));
        tracep->fullIData(oldp+20,(vlTOPp->product),32);
        tracep->fullSData(oldp+21,(vlTOPp->TopModule__DOT__top_multiplier),16);
        tracep->fullSData(oldp+22,(vlTOPp->TopModule__DOT__top_accumulator),16);
        tracep->fullSData(oldp+23,(vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output),16);
        tracep->fullSData(oldp+24,(vlTOPp->TopModule__DOT__dp_inst__DOT__intermediate_accumulator),16);
        tracep->fullBit(oldp+25,(vlTOPp->TopModule__DOT__dp_inst__DOT__carryout));
        tracep->fullSData(oldp+26,(0U),16);
        tracep->fullCData(oldp+27,(0U),2);
        tracep->fullCData(oldp+28,(1U),2);
        tracep->fullCData(oldp+29,(2U),2);
        tracep->fullCData(oldp+30,(3U),2);
    }
}

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
        tracep->declBit(c+1,"Controller.clk", false,-1);
        tracep->declBit(c+2,"Controller.reset", false,-1);
        tracep->declBit(c+3,"Controller.start", false,-1);
        tracep->declBus(c+4,"Controller.multiplier", false,-1, 15,0);
        tracep->declBit(c+5,"Controller.add_signal", false,-1);
        tracep->declBit(c+6,"Controller.shift_signal", false,-1);
        tracep->declBit(c+7,"Controller.mux_signal", false,-1);
        tracep->declBit(c+8,"Datapath.clk", false,-1);
        tracep->declBit(c+9,"Datapath.reset", false,-1);
        tracep->declBit(c+10,"Datapath.start", false,-1);
        tracep->declBit(c+11,"Datapath.add_signal", false,-1);
        tracep->declBit(c+12,"Datapath.shift_signal", false,-1);
        tracep->declBit(c+13,"Datapath.mux_signal", false,-1);
        tracep->declBus(c+14,"multiplicand", false,-1, 15,0);
        tracep->declBus(c+15,"accumulator", false,-1, 15,0);
        tracep->declBus(c+16,"Datapath.multiplier", false,-1, 15,0);
        tracep->declBus(c+17,"product", false,-1, 31,0);
        tracep->declBit(c+1,"Controller clk", false,-1);
        tracep->declBit(c+2,"Controller reset", false,-1);
        tracep->declBit(c+3,"Controller start", false,-1);
        tracep->declBus(c+4,"Controller multiplier", false,-1, 15,0);
        tracep->declBit(c+5,"Controller add_signal", false,-1);
        tracep->declBit(c+6,"Controller shift_signal", false,-1);
        tracep->declBit(c+7,"Controller mux_signal", false,-1);
        tracep->declBus(c+27,"Controller IDLE", false,-1, 1,0);
        tracep->declBus(c+28,"Controller CHECKLSB", false,-1, 1,0);
        tracep->declBus(c+29,"Controller ADD", false,-1, 1,0);
        tracep->declBus(c+30,"Controller SHIFT", false,-1, 1,0);
        tracep->declBus(c+18,"Controller state", false,-1, 1,0);
        tracep->declBus(c+19,"Controller count", false,-1, 3,0);
        tracep->declBit(c+8,"Datapath clk", false,-1);
        tracep->declBit(c+9,"Datapath reset", false,-1);
        tracep->declBit(c+10,"Datapath start", false,-1);
        tracep->declBit(c+11,"Datapath add_signal", false,-1);
        tracep->declBit(c+12,"Datapath shift_signal", false,-1);
        tracep->declBit(c+13,"Datapath mux_signal", false,-1);
        tracep->declBus(c+14,"Datapath multiplicand", false,-1, 15,0);
        tracep->declBus(c+15,"Datapath accumulator", false,-1, 15,0);
        tracep->declBus(c+16,"Datapath multiplier", false,-1, 15,0);
        tracep->declBus(c+17,"Datapath product", false,-1, 31,0);
        tracep->declBus(c+20,"Datapath shift_accumulator", false,-1, 15,0);
        tracep->declBus(c+21,"Datapath mux_output", false,-1, 15,0);
        tracep->declBus(c+22,"Datapath intermediate_accumulator", false,-1, 15,0);
        tracep->declBus(c+23,"Datapath shift_multiplier", false,-1, 15,0);
        tracep->declBit(c+24,"Datapath carryin", false,-1);
        tracep->declBit(c+25,"Datapath carryout", false,-1);
        tracep->declBit(c+26,"Datapath shiftcarry", false,-1);
        tracep->declBus(c+14,"Datapath mux_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+31,"Datapath mux_inst zeros", false,-1, 15,0);
        tracep->declBit(c+13,"Datapath mux_inst mux_signal", false,-1);
        tracep->declBus(c+21,"Datapath mux_inst selected_input", false,-1, 15,0);
        tracep->declBit(c+8,"Datapath add_inst clk", false,-1);
        tracep->declBus(c+21,"Datapath add_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+15,"Datapath add_inst accumulator", false,-1, 15,0);
        tracep->declBit(c+24,"Datapath add_inst carryin", false,-1);
        tracep->declBit(c+11,"Datapath add_inst add_signal", false,-1);
        tracep->declBus(c+22,"Datapath add_inst accumulator_out", false,-1, 15,0);
        tracep->declBit(c+25,"Datapath add_inst carryout", false,-1);
        tracep->declBit(c+8,"Datapath shift_inst clk", false,-1);
        tracep->declBit(c+9,"Datapath shift_inst reset", false,-1);
        tracep->declBit(c+12,"Datapath shift_inst enable", false,-1);
        tracep->declBus(c+22,"Datapath shift_inst accumulator", false,-1, 15,0);
        tracep->declBus(c+16,"Datapath shift_inst multiplier", false,-1, 15,0);
        tracep->declBus(c+25,"Datapath shift_inst carry", false,-1, 0,0);
        tracep->declBus(c+20,"Datapath shift_inst accumulator_out", false,-1, 15,0);
        tracep->declBus(c+23,"Datapath shift_inst multiplier_out", false,-1, 15,0);
        tracep->declBus(c+26,"Datapath shift_inst carry_out", false,-1, 0,0);
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
        tracep->fullBit(oldp+1,(vlTOPp->Controller__02Eclk));
        tracep->fullBit(oldp+2,(vlTOPp->Controller__02Ereset));
        tracep->fullBit(oldp+3,(vlTOPp->Controller__02Estart));
        tracep->fullSData(oldp+4,(vlTOPp->Controller__02Emultiplier),16);
        tracep->fullBit(oldp+5,(vlTOPp->Controller__02Eadd_signal));
        tracep->fullBit(oldp+6,(vlTOPp->Controller__02Eshift_signal));
        tracep->fullBit(oldp+7,(vlTOPp->Controller__02Emux_signal));
        tracep->fullBit(oldp+8,(vlTOPp->Datapath__02Eclk));
        tracep->fullBit(oldp+9,(vlTOPp->Datapath__02Ereset));
        tracep->fullBit(oldp+10,(vlTOPp->Datapath__02Estart));
        tracep->fullBit(oldp+11,(vlTOPp->Datapath__02Eadd_signal));
        tracep->fullBit(oldp+12,(vlTOPp->Datapath__02Eshift_signal));
        tracep->fullBit(oldp+13,(vlTOPp->Datapath__02Emux_signal));
        tracep->fullSData(oldp+14,(vlTOPp->multiplicand),16);
        tracep->fullSData(oldp+15,(vlTOPp->accumulator),16);
        tracep->fullSData(oldp+16,(vlTOPp->Datapath__02Emultiplier),16);
        tracep->fullIData(oldp+17,(vlTOPp->product),32);
        tracep->fullCData(oldp+18,(vlTOPp->Controller__DOT__state),2);
        tracep->fullCData(oldp+19,(vlTOPp->Controller__DOT__count),4);
        tracep->fullSData(oldp+20,(vlTOPp->Datapath__DOT__shift_accumulator),16);
        tracep->fullSData(oldp+21,(vlTOPp->Datapath__DOT__mux_output),16);
        tracep->fullSData(oldp+22,(vlTOPp->Datapath__DOT__intermediate_accumulator),16);
        tracep->fullSData(oldp+23,(vlTOPp->Datapath__DOT__shift_multiplier),16);
        tracep->fullBit(oldp+24,(vlTOPp->Datapath__DOT__carryin));
        tracep->fullBit(oldp+25,(vlTOPp->Datapath__DOT__carryout));
        tracep->fullBit(oldp+26,(vlTOPp->Datapath__DOT__shiftcarry));
        tracep->fullCData(oldp+27,(0U),2);
        tracep->fullCData(oldp+28,(1U),2);
        tracep->fullCData(oldp+29,(2U),2);
        tracep->fullCData(oldp+30,(3U),2);
        tracep->fullSData(oldp+31,(0U),16);
    }
}

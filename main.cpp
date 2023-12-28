#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include "verilated_vcd_c.h"
#include <memory>
#include "obj_dir/Vseqmul.h" 

vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    Vseqmul* top = new Vseqmul;

    // Add any additional setup code if needed
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    // Simulation loop
    while (!Verilated::gotFinish() && sim_time < 10000) {
        // Toggle clock
        // top->clk = !top->clk;

        // Apply inputs
        // For example, set inputs for the Datapath module
        // top->reset = 0;  // Set your inputs accordingly
        // top->start = 1;
        // top->multiplicand = 16'h0001;
        // top->multiplier = 16'h0001;

        // Evaluate model
        top->eval();

        // Dump waveform
        tfp->dump(sim_time);

        // Advance simulation time
        sim_time += 5;  // Adjust as needed
    }

    // Close VCD file and clean up
    tfp->close();
    delete top;
    exit(0);
}

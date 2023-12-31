#include <verilated.h>
#include <verilated_vcd_c.h> // Include VCD tracing header
#include "Vseqmul.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Create an instance of the Verilated module
    Vseqmul* top = new Vseqmul;

    // Initialize inputs
    top->clk = 0;
    top->reset = 1;
    top->start = 0;
    // top->add_signal = 0;
    // top->shift_signal = 0;
    // top->mux_signal = 0;

    for (int i = 0; i < 10; ++i) {
    }

    top->reset = 0;
    top->start = 1;
    

    top->multiplicand = 0x0002; 
    top->multiplier = 0x0005; 
    top->accumulator = 0x0000;

    // Enable VCD (Value Change Dump) tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    // Associate the trace file with the Verilated instance
    top->trace(tfp, 99); // The trace level controls the size of the trace file
    tfp->open("waveform.vcd");

    // Simulate for a few clock cycles
    for (int i = 0; i < 500; ++i) {
        top->clk = !top->clk;

        // Dump VCD data
        tfp->dump(i);

        top->eval();

        // top->eval();
    }

    printf("Product = %d\n", top->product);

    // Close the VCD file
    tfp->close();

    // Clean up
    delete top;

    // Exit
    return 0;
}

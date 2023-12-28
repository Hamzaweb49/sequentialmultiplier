module tb_SequentialMultiplier;

/* verilator lint_off UNUSED */
logic clk;
logic reset;
logic start;
// verilator lint_off BLKANDNBLK 
logic add_signal;
logic shift_signal;
logic mux_signal;
// verilator lint_on BLKANDNBLK 
logic [15:0] multiplicand;
logic [15:0] accumulator; 
logic [15:0] multiplier;
logic [31:0] product;
/* verilator lint_on UNUSED */

// Instantiate the UUT
Datapath uut (
    .clk(clk),
    .reset(reset),
    .start(start),
    .add_signal(add_signal),
    .shift_signal(shift_signal),
    .mux_signal(mux_signal),
    .multiplicand(multiplicand),
    .accumulator(accumulator),
    .multiplier(multiplier),
    .product(product)
);

Controller dut (
    .clk(clk),
    .reset(reset),
    .start(start),
    .add_signal(add_signal),
    .shift_signal(shift_signal),
    .mux_signal(mux_signal),
    .multiplier(multiplier)
);


// Clock generation
initial begin
    clk = 0;
    /* verilator lint_off STMTDLY */
    /* verilator lint_off INFINITELOOP */
    forever #5 clk = ~clk;
    /* verilator lint_on INFINITELOOP */
    /* verilator lint_on STMTDLY */
end

// Initial stimulus
initial begin
    reset = 1;
    start = 0;
    multiplicand = 16'b0;
    accumulator = 16'b0;
    multiplier = 16'b0;
    /* verilator lint_off STMTDLY */
    #10 reset = 0;  // Release reset
    /* verilator lint_on STMTDLY */
    start = 1;  // Start the multiplication process

    multiplicand = 16'h0001;
    multiplier = 16'h0001;
    /* verilator lint_off STMTDLY */
    #500 $finish;  // Finish simulation after some time
    /* verilator lint_on STMTDLY */
end

endmodule

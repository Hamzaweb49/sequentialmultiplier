/* verilator lint_off STMTDLY */
/* verilator lint_off INFINITELOOP */
/* verilator lint_off UNUSED */
// verilator lint_off BLKANDNBLK 
module tb_SequentialMultiplier;

logic clk;
logic reset;
logic start;
logic add_signal;
logic shift_signal;
logic mux_signal;
logic [15:0] multiplicand;
logic [15:0] accumulator; 
logic [15:0] multiplier;
logic [31:0] product;

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
    forever #5 clk = ~clk;
end

// Initial stimulus
initial begin
    reset = 1;
    start = 0;
    multiplicand = 16'b0;
    accumulator = 16'b0;
    multiplier = 16'b0;
    #10 reset = 0; 
    start = 1; 

    multiplicand = 16'h1312;
    multiplier = 16'h1212;

    #100 multiplicand = 16'hA5A5;
    multiplier = 16'h0000;

    #100 multiplicand = 16'hA5A5;
    multiplier = 16'h0000;

    #100 multiplicand = 16'hB5B5;
    multiplier = 16'h1234;

    // #100

    // start = 0;
    // reset = 1;

    // #10 reset = 1;
    // start = 1;

    // multiplicand = 16'h0031;
    // multiplier = 16'h0001;
    #1000 $finish; 
end

endmodule

/* verilator lint_on UNUSED */
// verilator lint_on BLKANDNBLK 
/* verilator lint_on STMTDLY */
/* verilator lint_on INFINITELOOP */
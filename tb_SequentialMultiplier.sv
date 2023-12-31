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
// logic shift_done;
logic [15:0] multiplicand;
logic [15:0] accumulator; 
logic [15:0] multiplier;
logic [31:0] product;

// Instantiate the UUT
// Datapath uut (
//     .clk(clk),
//     .reset(reset),
//     .start(start),
//     .add_signal(add_signal),
//     .shift_signal(shift_signal),
//     .mux_signal(mux_signal),
//     .multiplicand(multiplicand),
//     .accumulator(accumulator),
//     .multiplier(multiplier),
//     .product(product)
// );

// Controller dut (
//     .clk(clk),
//     .reset(reset),
//     .start(start),
//     .add_signal(add_signal),
//     .shift_signal(shift_signal),
//     .mux_signal(mux_signal),
//     .multiplier(multiplier)
// );

  TopModule uut (
    .clk(clk),
    .reset(reset),
    .start(start),
    .add_signal(add_signal),
    .shift_signal(shift_signal),
    .mux_signal(mux_signal),
    .multiplier(multiplier),
    .multiplicand(multiplicand),
    .accumulator(accumulator),
    // .shift_done(shift_done),
    .product(product)
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
    // shift_done = 0;
    multiplicand = 16'b0;
    accumulator = 16'b0;
    multiplier = 16'b0;
    #10 reset = 0; 
    multiplicand = 16'h0008; // 4882
    multiplier = 16'h0010; //4626
    start = 1; 

    #1000 $finish; 
end

endmodule

/* verilator lint_on UNUSED */
// verilator lint_on BLKANDNBLK 
/* verilator lint_on STMTDLY */
/* verilator lint_on INFINITELOOP */
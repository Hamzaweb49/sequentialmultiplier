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
    .product(product)
  );



initial begin
    clk = 0;
    forever #5 clk = ~clk;
end

initial begin
    reset = 1;
    start = 0;
    multiplicand = 16'b0;
    accumulator = 16'b0;
    multiplier = 16'b0;
    #10 reset = 0; 
    multiplicand = 120;
    multiplier = 80; 
    start = 1; 

    #1000 $finish; 
end

endmodule

/* verilator lint_on UNUSED */
// verilator lint_on BLKANDNBLK 
/* verilator lint_on STMTDLY */
/* verilator lint_on INFINITELOOP */
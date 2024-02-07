/* verilator lint_off STMTDLY */
/* verilator lint_off INFINITELOOP */
/* verilator lint_off UNUSED */
// verilator lint_off BLKANDNBLK


module tb_SequentialMultiplier(
`ifdef VERILATOR
    input logic clk,
    input logic reset,
    input logic start
`endif
);

`ifndef VERILATOR
    logic                   clk;
    logic                   reset;
    logic                   start
`endif;

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


`ifndef VERILATOR
initial begin
    clk = 0;
    forever #5 clk = ~clk;
end
`endif

initial begin
    `ifndef VERILATOR
    reset = 1;
    start = 0;
    `endif
    multiplicand = 16'b0;
    accumulator = 16'b0;
    multiplier = 16'b0;
    `ifndef VERILATOR
    #10 reset = 0; 
    `endif
    multiplicand = 20;
    multiplier = 30; 
    `ifndef VERILATOR
    start = 1; 
    `endif
    #1000 $finish; 
    
end

endmodule

/* verilator lint_on UNUSED */
// verilator lint_on BLKANDNBLK 
/* verilator lint_on STMTDLY */
/* verilator lint_on INFINITELOOP */
/* verilator lint_off STMTDLY */
/* verilator lint_off INFINITELOOP */
/* verilator lint_off UNUSED */
// verilator lint_off BLKANDNBLK

module SM_tb(
    `ifdef VERILATOR
    input logic clk,
    input logic reset,
    input logic start
    `endif
);

    // Declare signals
    `ifndef VERILATOR
    logic                   clk;
    logic                   reset;
    logic                   start
    `endif;
    logic ready;
    logic [15:0] multiplicand;
    logic [15:0] multiplier;
    logic [31:0] product;

    // Instantiate SM module
    SM sm (
        .clk(clk),
        .reset(reset),
        .start(start),
        .multiplicand(multiplicand),
        .multiplier(multiplier),
        .product(product),
        .ready(ready)
    );

`ifndef VERILATOR
initial begin
    clk = 0;
    forever #5 clk = ~clk;
end
`endif

    // Initial values
    initial begin
        `ifndef VERILATOR
        reset = 1;
        start = 0;
        `endif
        multiplicand = 16'h1234;
        multiplier = 16'h0040;
        `ifndef VERILATOR
        #10 reset = 0; 
        #10 start = 1;
        `endif
        #160 $finish;
    end

endmodule

/* verilator lint_on UNUSED */
// verilator lint_on BLKANDNBLK 
/* verilator lint_on STMTDLY */
/* verilator lint_on INFINITELOOP */
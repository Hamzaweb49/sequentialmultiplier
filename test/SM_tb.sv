/* verilator lint_off STMTDLY */
/* verilator lint_off INFINITELOOP */
/* verilator lint_off UNUSED */
// verilator lint_off BLKANDNBLK

module SM_tb(
    `ifdef VERILATOR
    input logic clk,
    `endif
);

    // Declare signals
    `ifndef VERILATOR
    logic                   clk;
    `endif;
    logic                   reset;
    logic                   start;
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
        reset = 1;
        start = 0;
        multiplicand = $random;
        multiplier = $random;
        @(posedge clk); 
        reset = 0;
        @(posedge clk);
        start = 1;
        @(posedge clk);
        start = 0;
        #170 $finish;
    end

endmodule

/* verilator lint_on UNUSED */
// verilator lint_on BLKANDNBLK 
/* verilator lint_on STMTDLY */
/* verilator lint_on INFINITELOOP */
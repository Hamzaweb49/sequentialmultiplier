/* verilator lint_off NULLPORT */

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
        repeat (65536) begin 
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
        while (!ready) begin
            @(posedge clk);
        end
        if (product == multiplicand * multiplier) begin
            $display("Product calculated successfuly!");
        end 
        `ifndef VERILATOR
        #160;
        `endif
        end
        #200 $finish;
    end

endmodule

/* verilator lint_on NULLPORT */

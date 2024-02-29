module SM(
    input logic clk, 
    input logic reset,
    input logic start, 
    input logic [15:0] multiplicand,
    input logic [15:0] multiplier,
    output logic [31:0] product,
    output logic ready
);

logic load_words, add_shift, shift, count_check;

Controller C1(
    .clk(clk),
    .reset(reset),
    .start(start),
    .multiplier_lsb(D1.shifted_multiplier[0]),
    .count_check(D1.count_check),
    .load_words(load_words),
    .ready(ready),
    .shift(shift),
    .add_shift(add_shift)
);

Datapath D1(
    .clk(clk),
    .reset(reset),
    .load_words(load_words),
    .add_shift(add_shift),
    .shift(shift),
    .ready(ready),
    .multiplier(multiplier),
    .multiplicand(multiplicand),
    .product(product),
    .count_check(count_check)
);

endmodule
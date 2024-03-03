module SM #(
  parameter WIDTH_M = 16,
  parameter WIDTH_P = 32
) ( 
  input logic                clk, 
  input logic                reset,
  
  input logic                start, 
  input logic [WIDTH_M-1:0]  multiplicand,
  input logic [WIDTH_M-1:0]  multiplier,
    
  output logic [WIDTH_P-1:0] product,
  output logic               ready
);

logic load_words, add_shift, flush;
logic shift, count_check, empty;

Controller C1 (
  .clk(clk),
  .reset(reset),
    
  .start(start),
    
  .multiplier_lsb(D1.shifted_multiplier[0]),
  .count_check(D1.count_check),
  .empty(D1.empty),  
  .load_words(load_words),
  .ready(ready),
  .shift(shift),
  .add_shift(add_shift),
  .flush(flush)
);

Datapath D1(
  .clk(clk),
  .reset(reset),
    
  .load_words(C1.load_words),
  .add_shift(C1.add_shift),
  .shift(C1.shift),
  .ready(C1.ready),
  .flush(C1.flush),
    
  .multiplier(multiplier),
  .multiplicand(multiplicand),
    
  .product(product),
  .count_check(count_check),
  .empty(empty)
);

endmodule

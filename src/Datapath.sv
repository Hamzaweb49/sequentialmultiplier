// 180ns
module Datapath #(
  parameter WIDTH_M = 16,
  parameter WIDTH_P = 32,
  parameter WIDTH_C = 4
) (
  input logic                clk,           
  input logic                reset,    

  input logic                load_words,    
  input logic                add_shift, 
  input logic                shift,
  input logic                ready,
  input logic                flush,

  input logic [WIDTH_M-1:0]  multiplier, 
  input logic [WIDTH_M-1:0]  multiplicand,
    
  output logic [WIDTH_P-1:0] product,  
  output logic               count_check,
  output logic               empty
);

logic [WIDTH_C-1:0] count;
logic [WIDTH_P-1:0] shifted_multiplicand;
logic [WIDTH_M-1:0] shifted_multiplier;
logic [WIDTH_P-1:0] alu_result;

//Check if any of the multiplier or multiplicand is zero
assign empty = (~|multiplier) || (~|multiplicand);


Counter counter_inst (
  .clk(clk),
  .reset(reset),
    
  .add_shift(add_shift),
  .shift(shift),
    
  .count(count),
  .count_check(count_check)
);

ALU alu_inst (
  .clk(clk),
  .reset(reset),
    
  .flush(flush),  
  .add_shift(add_shift),
  .A(shifted_multiplicand),
    
  .result(product)
);

// Load Multiplicand
always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    shifted_multiplicand <= 32'h00000000;
  end else if (load_words) begin
    shifted_multiplicand <= {16'b0,multiplicand};
  end
end


// Load Multiplier
always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    shifted_multiplier <= 32'h00000000;
  end else if (load_words) begin
    shifted_multiplier <= multiplier;
  end
end

// Left Shifter
always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    shifted_multiplicand <= 32'h00000000;
  end else if (shift || add_shift) begin
    shifted_multiplicand <= shifted_multiplicand << 1;
  end
end

// Right Shifter
always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    shifted_multiplicand <= 32'h00000000;
    shifted_multiplier   <= 32'h00000000;
  end else if (shift || add_shift) begin
    shifted_multiplier   <= shifted_multiplier >> 1;
  end
end

endmodule
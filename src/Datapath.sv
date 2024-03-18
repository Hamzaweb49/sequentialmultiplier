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


  // Counter
  always_ff @(posedge clk or negedge reset) begin
    if (!reset) begin
      count <= 4'b0000;
    end else if (add_shift || shift) begin
      count <= (count == 15) ? 4'b0000 : count + 1;
    end
  end

  assign count_check = (count == 4'b1111);

  //Check if any of the multiplier or multiplicand is zero
  assign empty = ((multiplier == 0) || (multiplicand == 0));

  // ALU
  always_ff @(posedge clk or negedge reset) begin
    if (!reset) begin
      product <= 32'h00000000;
    end else if(flush) begin
      product <= 32'h00000000;
    end else if (add_shift) begin
      product <= shifted_multiplicand + product;
    end
  end

  // Load and Left Shift Multiplicand
  always_ff @(posedge clk or negedge reset) begin
    if (!reset) begin
      shifted_multiplicand <= 32'h00000000;
    end else if (load_words) begin
      shifted_multiplicand <= {16'b0,multiplicand};
    end else if (add_shift || shift) begin
      shifted_multiplicand <= shifted_multiplicand << 1;
    end
  end
  
  // Load and Left Shift Multiplier
  always_ff @(posedge clk or negedge reset) begin
    if (!reset) begin
      shifted_multiplier <= 32'h00000000;
    end else if (load_words) begin
      shifted_multiplier <= multiplier;
    end  else if (add_shift || shift) begin
      shifted_multiplier <= shifted_multiplier >> 1;
    end
  end

endmodule

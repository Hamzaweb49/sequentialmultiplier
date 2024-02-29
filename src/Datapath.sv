// 180ns
module Datapath(
    input logic clk,           
    input logic reset,         
    input logic load_words,    
    input logic add_shift, 
    input logic shift,
    input logic ready,
    input logic [15:0] multiplier, 
    input logic [15:0] multiplicand,
    output logic [31:0] product,  
    output logic count_check
);

logic [3:0] count;
logic [31:0] shifted_multiplicand;
logic [15:0] shifted_multiplier;
logic [31:0] alu_result;

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
    .add_shift(add_shift),
    .A(shifted_multiplicand),
    .result(product)
);


// Output product
// always_ff @(posedge clk or posedge reset) begin
//     end else if (add_shift) begin
//         shifted_multiplicand <= shifted_multiplicand << 1;
//         shifted_multiplier <= shifted_multiplier >> 1;
//     end
// end

// Multiplicand and multiplier shifting
always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
        shifted_multiplicand <= 32'h00000000;
        shifted_multiplier <= 32'h00000000;
    end else if (load_words) begin
        shifted_multiplicand <= {16'b0,multiplicand};
        shifted_multiplier <= multiplier;
    end else if (shift || add_shift) begin
        shifted_multiplicand <= shifted_multiplicand << 1;
        shifted_multiplier <= shifted_multiplier >> 1;
    end
end

endmodule

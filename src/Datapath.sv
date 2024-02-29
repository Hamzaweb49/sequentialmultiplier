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
logic [31:0] hold_multiplicand;
logic [31:0] partial_multiplicand;
logic [15:0] shifted_multiplier;
logic [15:0] hold_multiplier;
logic [15:0] partial_multiplier;
logic [31:0] alu_result;
logic multiplier_shift_done;
logic multiplicand_shift_done;

Counter counter_inst (
    .clk(clk),
    .reset(reset),
    .add_shift(add_shift),
    .shift(shift),
    .count(count),
    .count_check(count_check)
);

MultiplierLoader multiplier_loader_inst (
    .clk(clk),
    .reset(reset),
    .load_words(load_words),
    .data_in(multiplier),
    .data_out(hold_multiplier)
);

MultiplicandLoader multiplicand_loader_inst (
    .clk(clk),
    .reset(reset),
    .load_words(load_words),
    .data_in(multiplicand),
    .data_out(hold_multiplicand)
);

ALU alu_inst (
    .clk(clk),
    .reset(reset),
    .add_shift(add_shift),
    .A(shifted_multiplicand),
    .result(product)
);

LeftShifter shifter_inst (
    .clk(clk),
    .reset(reset),
    .shift_done(multiplicand_shift_done),
    .shift(shift),
    .add_shift(add_shift),
    .data_in(partial_multiplicand),
    .data_out(shifted_multiplicand)
);

RightShifter multiplier_shifter_inst (
    .clk(clk),
    .reset(reset),
    .shift_done(multiplier_shift_done),
    .shift(shift),
    .add_shift(add_shift),
    .data_in(partial_multiplier),
    .data_out(shifted_multiplier)
);


always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
        product <= 32'h00000000;
        partial_multiplicand <= 32'h0;
        partial_multiplier <= 16'h0;
    end
    if (load_words) begin
        partial_multiplicand <= multiplicand;
        partial_multiplier <= multiplier;
    end
    if (multiplicand_shift_done) begin
        partial_multiplicand <= shifted_multiplicand;
        partial_multiplier <= shifted_multiplier;
    end
    if (multiplier_shift_done) begin
        partial_multiplier <= shifted_multiplier;
    end
end

endmodule

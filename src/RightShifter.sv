module RightShifter(
    input logic clk,           
    input logic reset,   
    input logic shift,         
    input logic add_shift,
    input logic [15:0] data_in,
    output logic shift_done,    
    output logic [15:0] data_out
);

always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
        data_out <= 32'h00000000;
    end else if (shift || add_shift) begin
        data_out <= data_in >> 1;
        shift_done = 1;
    end
end

endmodule
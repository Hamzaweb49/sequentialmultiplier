module ALU(
    input logic clk,           
    input logic reset,         
    input logic add_shift,     
    input logic [31:0] A,
    output logic [31:0] result 
);

always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
        result <= 32'h00000000;
    end else if (add_shift) begin
        result <= A + result;
    end
end

endmodule
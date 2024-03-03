module ALU #(
  parameter WIDTH_P = 32
) (
  input logic                clk,           
  input logic                reset,         
  
  input logic                flush,
  input logic                add_shift,     
  input reg [WIDTH_P-1:0]    A,
   
  output logic [WIDTH_P-1:0] result 
);

always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    result <= 32'h00000000;
    A      <= 32'h00000000;
  end else if(flush) begin
    result <= 32'h00000000;
  end else if (add_shift) begin
    result <= A + result;
  end
end

endmodule
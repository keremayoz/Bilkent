`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/09/2017 09:27:36 AM
// Design Name: 
// Module Name: Counter
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module ClockDivider(
    input clk_in,
    input [1:0] speed,
    input reset,
    output logic clk_out
    );
    

logic [30:0] count;
logic clk_NoBuf;
	
always@ (posedge clk_in or negedge reset) begin
if(reset) 
    count = 0;
else
	count = count + 1;    
end//always

always_comb
    case (speed)
       // 2'b00:  clk_NoBuf = clk_in;
        2'b01:  clk_NoBuf = count[20];
        2'b10:  clk_NoBuf = count[19];
        2'b11:  clk_NoBuf = count[18];
    endcase

BUFG BUFG_inst (
  .I(clk_NoBuf),  // 1-bit input: Clock input
  .O(clk_out) // 1-bit output: Clock output
  
);

endmodule

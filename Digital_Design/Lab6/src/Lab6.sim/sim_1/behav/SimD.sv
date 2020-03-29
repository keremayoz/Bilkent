`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/20/2017 09:46:51 AM
// Design Name: 
// Module Name: SimD
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


module SimD();
reg [3:0] R2;
reg [3:0] R3;
reg clk;
reg en;
reg [2:0] sel;
wire [3:0] R1;

partD pp (R2,R3,clk,en,sel,R1);

initial
begin
clk = 0; en = 1; sel = 3'b000; R2 = 4'b0101; R3 = 4'b0001; #100 sel = 3'b001; #100 sel = 3'b010; #100 sel = 3'b011; #100 sel = 3'b100; 
#100 sel = 3'b101; #100 sel = 3'b110; #100 sel = 3'b111;
end   

always #23 clk = ~clk;
endmodule

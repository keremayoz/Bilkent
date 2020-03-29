`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/20/2017 10:08:41 AM
// Design Name: 
// Module Name: AluSim
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


module AluSim();
reg [3:0] A;
reg [3:0] B;
reg [2:0] F;
wire Cout;
wire [3:0] Y;

Alu a(F,A,B,Cout,Y);

initial
begin
/*
F = 3'b000; A = 4'b0101; B = 4'b0001; #100 F = 3'b001; #100 F = 3'b010; #100 F = 3'b011; #100 F = 3'b100; 
#100 F = 3'b101; #100 F = 3'b110; #100 F = 3'b111;*/
F = 3'b110; A = 4'b1101; B = 4'b0101;
end  

endmodule

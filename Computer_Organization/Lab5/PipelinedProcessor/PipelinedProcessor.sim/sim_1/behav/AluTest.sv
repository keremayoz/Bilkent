`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/14/2017 11:24:44 PM
// Design Name: 
// Module Name: AluTest
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


module AluTest();

reg [31:0] sourceA;
reg [31:0] sourceB;
reg [2:0] control;
wire [31:0] result;
wire zero;

alu aluTested(sourceA, sourceB, control, result, zero);

initial
begin
control = 3'b000; sourceA = 32'h000000AA; sourceB = 32'h00000022; 
#100
control = 3'b001;
#100
control = 3'b010; 
#100
control = 3'b011; 
#100
control = 3'b100; 
#100
control = 3'b101; 
#100
control = 3'b110; 
#100
control = 3'b111; 
end

endmodule

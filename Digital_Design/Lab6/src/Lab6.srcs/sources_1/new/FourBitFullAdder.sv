`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/19/2017 08:48:37 PM
// Design Name: 
// Module Name: FourBitFullAdder
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

module FourBitFullAdder(
    input [3:0] A,
    input [3:0] B,
    input Cin,
    output Cout,
    output [3:0] Y
    );
    
    assign #23 {Cout, Y} = A + B + Cin;
endmodule

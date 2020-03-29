`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/19/2017 08:38:24 PM
// Design Name: 
// Module Name: OneBitFullAdder
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


module FullAdder(
    input A,
    input B,
    input Cin,
    output Cout,
    output Y
    );
    
    logic u1,u2,u3,u4,u5,u6,u7;
    
    Nand g1(A,B,u1);
    Nand g2(A,u1,u2);
    Nand g3(B,u1,u3);
    Nand g4(u2,u3,u4);
    Nand g5(u4,Cin,u5);
    Nand g6(u4,u5,u6);
    Nand g7(u5,Cin,u7);
    Nand g8(u6,u7,Y);
    Nand g9(u1,u5,Cout);
    
endmodule

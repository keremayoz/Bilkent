`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/19/2017 08:23:39 PM
// Design Name: 
// Module Name: Alu
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


module Alu(
    input [2:0] F,
    input [3:0] A,
    input [3:0] B,
    output Cout,
    output [3:0] Y
    );
    
    logic [3:0]muxFirst;
    Mux21 twoToOne(~B,B,F[2],muxFirst); 
    
    logic [3:0] mux0,mux1,mux2,mux3;
    assign #7 mux0 = A & muxFirst; //7408
    
    assign #6 mux1 = A | muxFirst; //7432
    
    FourBitFullAdder fbfa(A,muxFirst,F[2],Cout,mux2); //Delay inside
    
    assign mux3 = 4'b0000 + mux2[3]; 
    
    Mux41 fourToOne(mux3,mux2,mux1,mux0,F[1:0],Y);
    
endmodule

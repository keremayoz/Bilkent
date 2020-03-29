`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/20/2017 09:06:01 AM
// Design Name: 
// Module Name: Alu181
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


module Alu181(
    input [2:0] F,
    input [3:0] A,
    input [3:0] B,
    output Cout,
    output [3:0] Z
    );
    
    logic [3:0] Y;
    
    always_comb
        case (F)
        3'b000: Y = A & B;
        3'b001: Y = A | B;
        3'b010: {Cout,Y} = A + B;
        3'b100: Y = A & ~B;
        3'b101: Y = A | ~B;
        3'b110: {Cout,Y} = A - B;
        3'b111: Y = (A < B) + 4'b0000;
        endcase
        
        assign #50 Z = Y;
endmodule

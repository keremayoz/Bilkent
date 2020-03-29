`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/09/2017 08:57:43 AM
// Design Name: 
// Module Name: GrayCounter
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


module GrayCounter(
    input logic clk,
    input logic clr,
    input logic pr,
    output logic n2,
    output logic n1,
    output logic n0
    );
       
    logic c2,c1,c0;
    
    flipflop ff1 (clk,clr,pr,n2,c2);
    flipflop ff2 (clk,clr,pr,n1,c1);
    flipflop ff3 (clk,clr,pr,n0,c0);
    
    assign n2 = (c2 & c0) | (c1 & ~c0);
    assign n1 = (~c2 & c0) | (c1 & ~c0);
    assign n0 = (~c2 & ~c1) | (c2 & c1);
    
endmodule

module flipflop(
    input logic clk,
    input logic reset,
    input logic pr,
    input logic d,
    output logic q
    );
    
    always_ff@(posedge clk, posedge reset, posedge pr)
        if (reset) q <= 0;
        else if (pr) q <= 1;
        else q <= d;
        
endmodule
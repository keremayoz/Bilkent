`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/09/2017 11:44:07 AM
// Design Name: 
// Module Name: top
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


module top(

        input logic clk,
        input logic clr,
        input logic pr,
        output logic n2,
        output logic n1,
        output logic n0
        );
        
        logic clk_out;
        
        GrayCounter gc (
            .clk(clk_out),
            .clr(clr),
            .pr(pr),
            .n2(n2),
            .n1(n1),
            .n0(n0)
            );
            
            
         ClockDivider cd(
           .clk_in(clk),
           .clk_out(clk_out)
           );
           
endmodule

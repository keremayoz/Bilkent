`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 21.03.2017 22:23:51
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
        input logic sa,
        input logic sb,
        input logic clk,
        input logic rst,
        output logic[2:0] al,
        output logic[2:0] bl
        );
        
        logic clk_out;
        
        traffic t(
                .sa(sa),
                .sb(sb),
                .clk(clk_out),
                .rst(rst),
                .al(al),
                .bl(bl)
                );
            
         ClockDivider cd(
           .clk_in(clk),
           .clk_out(clk_out)
           );
           
endmodule

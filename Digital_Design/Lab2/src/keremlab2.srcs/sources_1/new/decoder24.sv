`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/02/2017 10:04:30 AM
// Design Name: 
// Module Name: decoder24
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

//2:4 decoder implementation
module decoder24(
    input x,
    input y,
    output d0,
    output d1,
    output d2,
    output d3
    );
    
    assign d0 = ~x & ~y;
    assign d1 = ~x & y;
    assign d2 = x & ~y;
    assign d3 = x & y;
    
endmodule

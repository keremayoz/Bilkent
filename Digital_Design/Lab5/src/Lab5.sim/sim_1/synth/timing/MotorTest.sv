`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/05/2017 09:39:00 PM
// Design Name: 
// Module Name: DriverTest
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


module MotorTest();
    reg clk;
    reg rst;
    reg cw;
    wire [3:0] L;
    
    MotorDriver md(
        .clk(clk),
        .rst(rst),
        .cw(cw),
        .L(L)
        );
    initial
        begin
        clk = 0; rst = 1; cw = 0; #30 rst = 0; cw = 1; #100 cw = 0; #100 cw = 1;
        end
   
   always #10 clk = ~clk;       
endmodule

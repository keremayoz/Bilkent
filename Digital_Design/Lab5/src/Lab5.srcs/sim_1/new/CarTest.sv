`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/06/2017 12:52:22 AM
// Design Name: 
// Module Name: SimCar
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


module CarTest();
    logic start;
    logic [1:0]speed;
    logic reverse;
    logic clk;
    logic rst;
    logic clk_outt;
    logic rs,ls,rss,lss;
    
    Car cf(
        start,
        speed,
        reverse,
        clk,
        rst,
        rs,ls,rss,lss,
        );
        
    initial
        begin
        clk = 0; rst = 1;  rst = 0; start = 0; speed = 2'b00; reverse = 0; #50 start = 1; speed = 2'b01; #50 speed = 2'b10; #50 speed = 2'b11; reverse = 1; #50 speed = 2'b10;
        
        end
        
   always #10 clk = ~clk;   
   
endmodule

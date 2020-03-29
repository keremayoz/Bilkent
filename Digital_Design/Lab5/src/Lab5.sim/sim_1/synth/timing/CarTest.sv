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
    logic [3:0] outSpeed;
    logic clk_outt;
    
    CarSim cf(
        start,
        speed,
        reverse,
        clk,
        rst,
        outSpeed,
        clk_outt
        );
        
    initial
        begin
        clk = 0; rst = 1;  rst = 0; start = 0; speed = 2'b00; reverse = 0; #30 start = 1; speed = 2'b01; #100 speed = 2'b10; #100 speed = 2'b11; reverse = 1; #100 speed = 2'b10;
        
        end
        
   always #10 clk = ~clk;   
   
endmodule

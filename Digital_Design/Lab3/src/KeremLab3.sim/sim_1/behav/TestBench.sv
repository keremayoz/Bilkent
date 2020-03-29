`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/09/2017 10:07:57 AM
// Design Name: 
// Module Name: TestBench
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


module TestBench();
    reg clock;
    reg clear;
    reg preset;
    wire t2;
    wire t1;
    wire t0;
  
    GrayCounter gc(
        .clk(clock),
        .clr(clear),
        .pr(preset),
        .n2(t2),
        .n1(t1),
        .n0(t0)
        );
        
    initial begin
        clock = 0; clear = 0; preset = 0; #30 clear = 1; preset = 1; #200 clear =0; preset = 0; // #10 preset = 1;
    end
    
    always  #10  clock  = ~clock;
        
        
       
   
endmodule

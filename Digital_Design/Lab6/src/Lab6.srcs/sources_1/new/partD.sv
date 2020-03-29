`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/20/2017 09:35:36 AM
// Design Name: 
// Module Name: partD
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


module partD(
    input logic [3:0] R2,
    input logic [3:0] R3,
    input logic clk,
    input logic en,
    input logic  [2:0] sel,
    output logic [3:0] R1
    );
    
    //Registers R2 and R3
    logic [3:0] r2,r3; //Mid logics
    always_ff@(posedge clk)
        if (en) 
        begin 
        r2 <= R2;
        r3 <= R3;
        end
        
    //Alu    
    logic cout;
    logic [3:0] out;
    Alu alu(sel,r2,r3,cout,out);
    
    //Register R1
    always_ff@(posedge clk)
    if (en)
    R1 <= out;
    
endmodule

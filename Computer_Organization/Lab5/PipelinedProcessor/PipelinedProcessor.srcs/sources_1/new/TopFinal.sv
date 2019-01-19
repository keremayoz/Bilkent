`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/06/2017 09:54:22 AM
// Design Name: 
// Module Name: TopFinal
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


module TopFinal (input   logic 	 clk, reset, clkButton,         
                 output  logic       memwrite,
                 output logic [3:0] AN,
                 output logic [6:0] C,
                 output logic DP);
                 
    logic[31:0] writedata, dataadr, pc, instr;
    
    logic debouncedClock;
    logic[3:0] enables = 4'b1111;
    top  topp(debouncedClock, reset,writedata, dataadr, pc,instr,memwrite);  
    
    display_controller dp (clk, reset,enables,writedata[7:4],writedata[3:0], dataadr[7:4], dataadr[3:0],AN,C,DP);
    pulse_controller pcc(clk, clkButton, reset,debouncedClock );
    
endmodule

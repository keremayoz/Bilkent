`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 21.03.2017 21:11:57
// Design Name: 
// Module Name: traffic
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


module trafficsim ();
    reg sa;
    reg sb;
    reg clk;
    reg rst;
    wire [2:0] al;
    wire [2:0] bl;
    
    traffic t(
        .sa(sa),
        .sb(sb),
        .clk(clk),
        .rst(rst),
        .al(al),
        .bl(bl)
        );
        
        initial
        begin
        clk = 0; sa = 1; sb = 0; rst = 1; #30 rst = 0; sb = 1; sa = 0; #30 sa = 1; sb = 0; #30 sb = 1; sa = 0; #30 sa = 1; sb = 0;
        end
      
        always  #10  clk  = ~clk; 
endmodule

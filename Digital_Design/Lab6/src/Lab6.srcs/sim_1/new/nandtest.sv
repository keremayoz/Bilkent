`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/19/2017 08:31:27 PM
// Design Name: 
// Module Name: nandtest
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


module nandtest();
reg a;
reg b;
wire y;

Nand n (a,b,y);

initial
begin
a = 0; b = 0; #20 a = 1; #20 b = 1; #20 a = 0; #20 b = 0;
end

endmodule

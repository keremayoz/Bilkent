`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/09/2017 09:27:36 AM
// Design Name: 
// Module Name: Counter
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


module ClockTest();
logic clk_in;
logic [1:0] speed;
logic clk_out;
logic reset;

ClockDivider cc(
    .clk_in(clk_in),
    .speed(speed),
    .reset(reset),
    .clk_out(clk_out)
    );

initial
begin
clk_in = 0; reset = 1; speed = 2'b11; #500 reset = 0; speed = 2'b11;  #500 speed = 2'b11;  #500 speed = 2'b11;
end

always #100 clk_in = ~clk_in;
endmodule

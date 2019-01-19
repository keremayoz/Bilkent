`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/14/2017 11:19:43 PM
// Design Name: 
// Module Name: MIPSLiteTest
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

module MIPSLiteTest(); 
	reg clk;
 	reg rst;
    reg [31:0] writeData;
    reg [31:0] dataAddress;
    reg memWrite;
    reg [31:0] pc;   
    reg [31:0] instr;
    
	top proc(clk,rst,writeData,dataAddress,pc,instr,memWrite);
	
	always 
		#5 clk = ~clk;
	
	initial
	begin

		// time = 0	
		clk = 1'b0;
		// Reset CPU
		rst = 1'b1;
		// run 1st iteration to reset cpu, and load first instruction
		@(posedge clk);
		
		// set Rest to 0
		rst = 1'b0;
		
		// Run through 5 CPU cycles
      repeat(50)
			@(posedge clk);
			
		$finish();
	end

endmodule

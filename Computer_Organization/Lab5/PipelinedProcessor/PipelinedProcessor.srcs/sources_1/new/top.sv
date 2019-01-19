`timescale 1ns / 1ps

// Written by David_Harris@hmc.edu

// Top level system including MIPS and memories


module top  (input   logic 	 clk, reset,            
	     output  logic[31:0] writedata, dataadr, pc, instr,          
	     output  logic       memwrite);  

   logic [31:0] pcTemp, instrTemp, readdata,aluOutM,writeDataM;
   logic memWriteM;    

   // instantiate processor and memories  
   mips mips (clk, reset, pcTemp, instrTemp, memwrite, dataadr, writedata, readdata,aluOutM,writeDataM,memWriteM);  
   imem imem (pcTemp[7:2], instrTemp);  
   dmem dmem (clk, memWriteM, aluOutM, writeDataM, readdata);
   
   assign pc = pcTemp;
   assign instr = instrTemp;
   
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/05/2017 02:07:16 AM
// Design Name: 
// Module Name: pipeRegister
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


//Pipe register between fetch and decode
module pipeRegisterFD
              (input logic clk, reset,en, clear,
	           input logic[31:0] instrF, 
               input logic[31:0] pcplus4F,
               output logic[31:0] instrD,
               output logic[31:0] pcplus4D);

  always_ff@(posedge clk, posedge reset)
    if (reset | clear)  begin instrD <= 0; pcplus4D <= 0; end 
    else if (en)        begin instrD <= instrF; pcplus4D <= pcplus4F; end
endmodule

//Pipe register between decode and execute
module pipeRegisterDE
              (input logic clk, reset,clear,
	           input logic[31:0] source1D,source2D,
               input logic [4:0] rsD,rtD,rdD,
               input logic[31:0] signImmD,
               output logic[31:0] source1E,source2E,
               output logic[4:0] rsE,rtE,rdE,
               output logic[31:0] signImmE,
               //Control Signals
              input logic pcsrcD,
              input logic regwriteD,memtoregD,memwriteD,
              input logic[2:0] alucontrolD,
              input logic alusrcD, regdstD,
              output logic pcsrcE,
              output logic regwriteE,memtoregE,memwriteE,
              output logic[2:0] alucontrolE,
              output logic alusrcE, regdstE);
               
  always_ff@(posedge clk, posedge reset)
    if (reset | clear) begin
        source1E <= 0; source2E <= 0; 
        rsE <= 0; rtE <= 0; rdE <= 0;
        signImmE <= 0;
        //Signals
        pcsrcE <= 0; regwriteE <= 0;
        memtoregE <= 0; memwriteE <= 0;  alucontrolE <= 0;
        alusrcE <= 0; regdstE <= 0;
        end 
    else  begin
        source1E <= source1D; source2E <= source2D; 
        rsE <= rsD; rtE <= rtD; rdE <= rdD;
        signImmE <= signImmD;
        //Signals
        pcsrcE <= pcsrcD; regwriteE <= regwriteD;
        memtoregE <= memtoregD; memwriteE <= memwriteD;  alucontrolE <= alucontrolD;
        alusrcE <= alusrcD; regdstE <= regdstD;
        end
endmodule

//Pipe register between execute and memory
module pipeRegisterEM
              (input logic clk, reset,
	           input logic[31:0] aluOutE,writeDataE,
               input logic [4:0] writeRegE,
               output logic[31:0] aluOutM,writeDataM,
               output logic[4:0] writeRegM,
               //Control Signals
               input logic regwriteE,memtoregE,memwriteE,
               output logic regwriteM,memtoregM,memwriteM);
               
  always_ff@(posedge clk, posedge reset)
    if (reset) begin
        aluOutM <= 0; writeDataM <= 0;  
        writeRegM <= 0; 
        //Signals
        regwriteM <= 0; memtoregM <= 0; memwriteM <= 0;
        end 
    else  begin
        aluOutM <= aluOutE; writeDataM <= writeDataE;  
        writeRegM <= writeRegE;
        //Signals
        regwriteM <= regwriteE; memtoregM <= memtoregE; memwriteM <= memwriteE;
        end
endmodule


//Pipe register between memory and writeback
module pipeRegisterMW
              (input logic clk, reset,
	           input logic[31:0] readDataM, 
               input logic[31:0] aluOutM,
               input logic [4:0] writeRegM,
               output logic[31:0] readDataW, 
               output logic[31:0] aluOutW,
               output logic[4:0] writeRegW,
              //Control Signals
              input logic regwriteM,memtoregM,
              output logic regwriteW,memtoregW);
              
  always_ff@(posedge clk, posedge reset)
    if (reset) begin
        readDataW <= 0; aluOutW <= 0;  
        writeRegW <= 0;
        //Signals
        regwriteW <= 0; memtoregW <= 0;
        end 
    else  begin
        readDataW <= readDataM; aluOutW <= aluOutM;  
        writeRegW <= writeRegM;
        //Signals
        regwriteW <= regwriteM; memtoregW <= memtoregM; 
        end
endmodule




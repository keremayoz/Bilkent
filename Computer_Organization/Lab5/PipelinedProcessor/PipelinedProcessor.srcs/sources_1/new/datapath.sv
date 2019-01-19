`timescale 1ns / 1ps
module datapath (input  logic clk, reset, memtoreg, branch, alusrc, regdst,
                 input  logic regwrite, jump,memwrite, 
		         input  logic[2:0]  alucontrol,
		         output logic[31:0] pc, 
	             input  logic[31:0] instr,
                 output logic[31:0] aluout, writedata, 
	             input  logic[31:0] readdata,
	             output logic[31:0] aluOutM,writeDataM,
	             output logic memWriteM,
	             output logic[31:0] instrD);

  logic [31:0] pcnext, pcnextbr, pcplus4, pcbranch;
  logic [31:0] signimm, signimmsh, srca, result;
  //Pipe logics                   
  logic           stallD,stallF,flushE, pcsrc,
                  pcsrcE,regwriteE,memtoregE,memwriteE,alusrcE,regdstE,
                  regwriteM,memtoregM,
                  regwriteW,memtoregW,
                  forwardAD,forwardBD;
                  
  logic[31:0]     source1E,source2E,
                  signImmE,writeDataE,
                  readDataW,aluOutW,
                  srcaComp,srcbComp,
                  srcAE,srcBE,pcplus4D;
                  
  logic[4:0] rsE,rtE,rdE,writeRegE,writeRegM,writeRegW;
  logic[2:0] alucontrolE;
  logic[1:0] forwardAE,forwardBE;
   
  // next PC logic
  flopr #(32) pcreg(clk, reset,~stallF, pcnext, pc);
  adder       pcadd1(pc, 32'b100, pcplus4);
  sl2         immsh(signimm, signimmsh);
  adder       pcadd2(pcplus4D, signimmsh, pcbranch);
  mux2 pcbrmux(pcplus4, pcbranch, pcsrc,pcnextbr);
  mux2 pcmux(pcnextbr, {pcplus4D[31:28],instrD[25:0], 2'b00}, jump, pcnext);

//Hazard Unit
hazard h(instrD[25:21], instrD[20:16], rsE, rtE, writeRegE, writeRegM,
         writeRegW,regwriteE, regwriteM, regwriteW,
         memtoregE, memtoregM, branch,
         forwardAD, forwardBD, forwardAE,forwardBE,
         stallF, stallD, flushE);
       
//Pipe F-D
pipeRegisterFD fdreg (clk,reset,~stallD,(jump | pcsrc),instr,pcplus4,instrD,pcplus4D);

//Pipe D-E
pipeRegisterDE dereg(clk,reset,flushE,srca,writedata,
               instrD[25:21],instrD[20:16],instrD[15:11],
               signimm,source1E,source2E,rsE,rtE,rdE,signImmE,
               //Control Signals
               pcsrc,regwrite,memtoreg,memwrite,alucontrol,alusrc,regdst,
               pcsrcE,regwriteE,memtoregE,memwriteE,alucontrolE,alusrcE,regdstE);
               
//Pipe E-M
pipeRegisterEM emreg(clk,reset,aluout,
               writeDataE,writeRegE,
               aluOutM,writeDataM,writeRegM,
               //Control Signals
               regwriteE,memtoregE,memwriteE,
               regwriteM,memtoregM,memwriteM);

//Pipe M-W
pipeRegisterMW mwreg(clk,reset,
               readdata, aluOutM,writeRegM,
               readDataW,aluOutW,writeRegW,
              //Control Signals
              regwriteM,memtoregM,
              regwriteW,memtoregW);
          
// branch Decision
mux2 srcaMux(srca,aluOutM,forwardAD,srcaComp);
mux2 srcbMux(writedata,aluOutM,forwardBD,srcbComp);
assign pcsrc = branch & (srcaComp == srcbComp);

// register file logic
regfile     rf (clk, regwriteW, instrD[25:21], instrD[20:16], writeRegW,
               result, srca, writedata);

mux3 alu1(source1E,result,aluOutM,forwardAE,srcAE);
mux3 alu2(source2E,result,aluOutM,forwardBE,writeDataE);

mux2p #(5)    wrmux (rtE, rdE, regdstE, writeRegE);
mux2p #(32)  resmux (aluOutW, readDataW, memtoregW, result);
signext         se (instrD[15:0], signimm);

// ALU logic
mux2p #(32)  srcbmux (writeDataE, signImmE, alusrcE, srcBE);
alu         alu (srcAE, srcBE, alucontrolE, aluout);

endmodule

//2-to-1 MUX
module mux2(input  logic[31:0] d0, d1,  
            input  logic s, 
            output logic[31:0] y);
  
   assign y = s ? d1 : d0; 
endmodule

//3-yo-1 MUX
module mux3(input logic [31:0] d0,d1,d2,
            input logic [1:0] S,
            output logic [31:0] Y
            );
            
assign Y = S[1] ? (S[0] ? 32'bX : d2)
 : (S[0] ? d1 : d0);
 
endmodule

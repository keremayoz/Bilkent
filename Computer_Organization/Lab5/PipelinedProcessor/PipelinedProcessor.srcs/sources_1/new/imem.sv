`timescale 1ns / 1ps

// External instruction memory used by MIPS single-cycle
// processor. It models instruction memory as a stored-program 
// ROM, with address as input, and instruction as output


module imem ( input logic [5:0] addr, output logic [31:0] instr);

// imem is modeled as a lookup table, a stored-program byte-addressable ROM
	always_comb
	   case ({addr,2'b00})		 /*  	// word-aligned fetch
//		address		instruction
//		-------		-----------
		8'h00: instr = 32'h20020005;  	  //ADDI $v0 $zero 0x0005
		8'h04: instr = 32'h2003000c;  	  //ADDI $v1 $zero 0x000C
		8'h08: instr = 32'h2067fff7;  	  //ADDI $a3 $v1 0xFFF7
		8'h0c: instr = 32'h20020005;//32'h00e22025;  	  //OR $a0 $a3 $v0
		8'h10: instr = 32'h00642824;      //AND $a1 $v1 $a0
		8'h14: instr = 32'h00a42820;      //ADD $a1 $a1 $a0
		8'h18: instr = 32'h21080050;      // addi $t0, $t0, 0x0054
		8'h1c: instr = 32'h0064202a;      //SLT $a0 $v1 $a0
		8'h20: instr = 32'h10800001;      //BEQ $a0 $zero 0x0001
		8'h24: instr = 32'h20050000;      //ADDI $a1 $zero 0x0000
		8'h28: instr = 32'h00e2202a;      //SLT $a0 $a3 $v0
		8'h2c: instr = 32'h00853820;      //ADD $a3 $a0 $a1
		8'h30: instr = 32'h00e23822;      //SUB $a3 $a3 $v0
		8'h34: instr = 32'hac670044;      //SW $a3 0x0044 $v1
		8'h38: instr = 32'h8c020050;      //LW $v0 0x0050 $zero
		8'h3c: instr = 32'h08000011;      //J 0x0000011
		8'h40: instr = 32'h20020001;      //ADDI $v0 $zero 0x0001
		8'h44: instr = 32'hac02aa54;      //SW $v0 0x0054 $zero
		
		//Modified much
	
	    8'h48: instr = 32'h21080050;//32'h3c09000c;      // lui $t1, 12
	    8'h4c: instr = 32'h21080050;      // addi $t0, $t0, 0x0054
		8'h50: instr = 32'h21080050;//32'h0d0a0000;      // jalm $t2, 0($t0)
		8'h54: instr = 32'h08000014;	  //J 0x0000012 j 48, so it will loop here*/
		
		8'h00: instr = 32'h08000003;
		8'h04: instr = 32'h00000020;
		8'h08: instr = 32'h00000020;
		8'h0c: instr = 32'h21080050; 
	     default:  instr = {32{1'bx}};	// unknown address
	   endcase
endmodule

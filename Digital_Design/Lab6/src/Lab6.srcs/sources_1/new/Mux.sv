`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/19/2017 09:15:18 PM
// Design Name: 
// Module Name: Mux
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

// 74HC157
module Mux21( 
    input [3:0] A,
    input [3:0] B,
    input S,
    output [3:0] Y
    );  
    
    assign #12 Y = S ? A:B; //plus 7
    
endmodule

//74HC153
module Mux41(
    input logic [3:0] d3,d2,d1,d0,
    input logic [1:0] S,
    output logic [3:0] Y
    );
    
    assign #15 Y = S[1] ? (S[0] ? d3 : d2)
                        : (S[0] ? d1 : d0);
                        
endmodule
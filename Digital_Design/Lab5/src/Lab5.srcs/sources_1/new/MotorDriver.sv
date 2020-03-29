`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/05/2017 09:09:42 PM
// Design Name: 
// Module Name: Car
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


module MotorDriver(
    input logic clk,
    input logic rst,
    input logic cw,
    output logic [3:0] L
    );
    
    typedef enum logic [3:0] {s0,s1,s2,s3} statetype;
        statetype state,nextstate;
        
    always_ff@(posedge clk,posedge rst)
        if(rst) state <= s0; else state <= nextstate;
        
    always_comb
        case(state)
            s0: if(cw) nextstate = s1; else nextstate = s3;
            s1: if(cw) nextstate = s2; else nextstate = s0;
            s2: if(cw) nextstate = s3; else nextstate = s1;
            s3: if(cw) nextstate = s0; else nextstate = s2;
        endcase
        
    always_comb
        case(state)
            s0: begin L = 4'b1001; end
            s1: begin L = 4'b0101; end
            s2: begin L = 4'b0110; end
            s3: begin L = 4'b1010; end
        endcase   
endmodule


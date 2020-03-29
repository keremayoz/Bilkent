`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 21.03.2017 20:20:42
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


module traffic(
    input logic sa,
    input logic sb,
    input logic clk,
    input logic rst,
    output logic[2:0] al,
    output logic[2:0] bl
    );
    
    typedef enum logic [2:0] {s0,s1,s2,s3,s4,s5,s6,s7} statetype;
    statetype state,nextstate;
    
    always_ff@(posedge clk,posedge rst)
    if(rst) state <= s0; else state <= nextstate;
    
    always_comb
        case(state)
            s0: if(sa) nextstate = s0; else nextstate = s1;
            s1: nextstate = s2;
            s2: if(~sb) nextstate = s2; else nextstate = s3;
            s3: nextstate = s4;
            s4: if(sb) nextstate = s4; else nextstate = s5;
            s5: nextstate = s6;
            s6: if(~sa) nextstate = s6; else nextstate = s7;
            s7: nextstate = s0;
        endcase
        
    always_comb
        case(state) 
            s0: begin al = 3'b011; bl = 3'b111; end
            s1: begin al = 3'b001; bl = 3'b111; end
            s2: begin al = 3'b111; bl = 3'b111; end
            s3: begin al = 3'b111; bl = 3'b001; end
            s4: begin al = 3'b111; bl = 3'b011; end
            s5: begin al = 3'b111; bl = 3'b001; end
            s6: begin al = 3'b111; bl = 3'b111; end
            s7: begin al = 3'b001; bl = 3'b111; end
        endcase
        
endmodule

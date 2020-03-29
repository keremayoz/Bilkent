`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/05/2017 10:02:05 PM
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


module Car(
    input logic start,
    input [1:0]speed,
    input logic reverse,
    input logic clk,
    input logic rst,
    input logic rs, ls,
    output logic rss, lss,
    output logic  a, b, c, d, e, f, g, dp,
    output logic [3:0] an,
    output logic [3:0] newL
    );
    
    logic clk_outt;
    logic [3:0] outSpeed;
    
    assign rss = rs;
    assign lss = ls;
    
    always_comb
        case(speed)
            2'b00:
            begin 
            outSpeed = 4'b0000;
            end
            
            2'b01:
            begin 
            outSpeed = 4'b0001;
            end
            
            2'b10:
            begin
            outSpeed = 4'b0010;
            end
            
            2'b11:
            begin 
            outSpeed = 4'b0011;   
            end
        endcase
        
    ClockDivider cc(
            clk,
            speed,
            rst,
            clk_outt
            );
         
    MotorDriver m(
        .clk(clk_outt),
        .rst(rst),
        .cw(reverse),
        .L(newL)
        );
        
    SevSeg_4digit s(
        .clk(clk),
        .in0(4'b0000), 
        .in1(4'b0000),
        .in2(4'b0000), 
        .in3(outSpeed),
         .a(a), 
         .b(b), 
         .c(c), 
         .d(d), 
         .e(e), 
         .f(f), 
         .g(g), 
         .dp(dp), 
         .an(an)   
         );
    
endmodule
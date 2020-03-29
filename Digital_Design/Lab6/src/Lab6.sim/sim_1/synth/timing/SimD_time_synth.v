// Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
// Date        : Thu Apr 20 10:34:24 2017
// Host        : EALAB01 running 64-bit Service Pack 1  (build 7601)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               D:/Users/TEMP/Desktop/Lab6/Lab6/Lab6.sim/sim_1/synth/timing/SimD_time_synth.v
// Design      : Alu
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* NotValidForBitStream *)
module Alu
   (F,
    A,
    B,
    Cout,
    Y);
  input [2:0]F;
  input [3:0]A;
  input [3:0]B;
  output Cout;
  output [3:0]Y;

  wire [3:0]A;
  wire [3:0]A_IBUF;
  wire [3:0]B;
  wire [3:0]B_IBUF;
  wire Cout;
  wire Cout_OBUF;
  wire Cout_OBUF_inst_i_2_n_0;
  wire [2:0]F;
  wire [2:0]F_IBUF;
  wire [3:0]Y;
  wire [3:0]Y_OBUF;
  wire \Y_OBUF[0]_inst_i_2_n_0 ;
  wire \Y_OBUF[0]_inst_i_3_n_0 ;
  wire \Y_OBUF[1]_inst_i_2_n_0 ;
  wire \Y_OBUF[3]_inst_i_2_n_0 ;
  wire \Y_OBUF[3]_inst_i_3_n_0 ;
  wire \Y_OBUF[3]_inst_i_4_n_0 ;
  wire \Y_OBUF[3]_inst_i_5_n_0 ;

initial begin
 $sdf_annotate("SimD_time_synth.sdf",,,,"tool_control");
end
  IBUF \A_IBUF[0]_inst 
       (.I(A[0]),
        .O(A_IBUF[0]));
  IBUF \A_IBUF[1]_inst 
       (.I(A[1]),
        .O(A_IBUF[1]));
  IBUF \A_IBUF[2]_inst 
       (.I(A[2]),
        .O(A_IBUF[2]));
  IBUF \A_IBUF[3]_inst 
       (.I(A[3]),
        .O(A_IBUF[3]));
  IBUF \B_IBUF[0]_inst 
       (.I(B[0]),
        .O(B_IBUF[0]));
  IBUF \B_IBUF[1]_inst 
       (.I(B[1]),
        .O(B_IBUF[1]));
  IBUF \B_IBUF[2]_inst 
       (.I(B[2]),
        .O(B_IBUF[2]));
  IBUF \B_IBUF[3]_inst 
       (.I(B[3]),
        .O(B_IBUF[3]));
  OBUF Cout_OBUF_inst
       (.I(Cout_OBUF),
        .O(Cout));
  LUT6 #(
    .INIT(64'h2BFFFF8E002B8E00)) 
    Cout_OBUF_inst_i_1
       (.I0(A_IBUF[2]),
        .I1(B_IBUF[2]),
        .I2(Cout_OBUF_inst_i_2_n_0),
        .I3(B_IBUF[3]),
        .I4(F_IBUF[2]),
        .I5(A_IBUF[3]),
        .O(Cout_OBUF));
  LUT5 #(
    .INIT(32'h4007F74F)) 
    Cout_OBUF_inst_i_2
       (.I0(A_IBUF[0]),
        .I1(B_IBUF[0]),
        .I2(F_IBUF[2]),
        .I3(B_IBUF[1]),
        .I4(A_IBUF[1]),
        .O(Cout_OBUF_inst_i_2_n_0));
  IBUF \F_IBUF[0]_inst 
       (.I(F[0]),
        .O(F_IBUF[0]));
  IBUF \F_IBUF[1]_inst 
       (.I(F[1]),
        .O(F_IBUF[1]));
  IBUF \F_IBUF[2]_inst 
       (.I(F[2]),
        .O(F_IBUF[2]));
  OBUF \Y_OBUF[0]_inst 
       (.I(Y_OBUF[0]),
        .O(Y[0]));
  LUT6 #(
    .INIT(64'h00000000BBEBEBEE)) 
    \Y_OBUF[0]_inst_i_1 
       (.I0(\Y_OBUF[0]_inst_i_2_n_0 ),
        .I1(\Y_OBUF[3]_inst_i_3_n_0 ),
        .I2(Cout_OBUF_inst_i_2_n_0),
        .I3(\Y_OBUF[3]_inst_i_4_n_0 ),
        .I4(A_IBUF[2]),
        .I5(\Y_OBUF[0]_inst_i_3_n_0 ),
        .O(Y_OBUF[0]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT2 #(
    .INIT(4'h7)) 
    \Y_OBUF[0]_inst_i_2 
       (.I0(F_IBUF[0]),
        .I1(F_IBUF[1]),
        .O(\Y_OBUF[0]_inst_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'h0009C39F)) 
    \Y_OBUF[0]_inst_i_3 
       (.I0(F_IBUF[2]),
        .I1(B_IBUF[0]),
        .I2(A_IBUF[0]),
        .I3(F_IBUF[1]),
        .I4(F_IBUF[0]),
        .O(\Y_OBUF[0]_inst_i_3_n_0 ));
  OBUF \Y_OBUF[1]_inst 
       (.I(Y_OBUF[1]),
        .O(Y[1]));
  LUT6 #(
    .INIT(64'h3804373837383804)) 
    \Y_OBUF[1]_inst_i_1 
       (.I0(\Y_OBUF[1]_inst_i_2_n_0 ),
        .I1(F_IBUF[1]),
        .I2(F_IBUF[0]),
        .I3(A_IBUF[1]),
        .I4(B_IBUF[1]),
        .I5(F_IBUF[2]),
        .O(Y_OBUF[1]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT3 #(
    .INIT(8'h35)) 
    \Y_OBUF[1]_inst_i_2 
       (.I0(F_IBUF[2]),
        .I1(A_IBUF[0]),
        .I2(B_IBUF[0]),
        .O(\Y_OBUF[1]_inst_i_2_n_0 ));
  OBUF \Y_OBUF[2]_inst 
       (.I(Y_OBUF[2]),
        .O(Y[2]));
  LUT6 #(
    .INIT(64'h3804373837383804)) 
    \Y_OBUF[2]_inst_i_1 
       (.I0(Cout_OBUF_inst_i_2_n_0),
        .I1(F_IBUF[1]),
        .I2(F_IBUF[0]),
        .I3(A_IBUF[2]),
        .I4(B_IBUF[2]),
        .I5(F_IBUF[2]),
        .O(Y_OBUF[2]));
  OBUF \Y_OBUF[3]_inst 
       (.I(Y_OBUF[3]),
        .O(Y[3]));
  LUT6 #(
    .INIT(64'hFFFFFFFF22828288)) 
    \Y_OBUF[3]_inst_i_1 
       (.I0(\Y_OBUF[3]_inst_i_2_n_0 ),
        .I1(\Y_OBUF[3]_inst_i_3_n_0 ),
        .I2(Cout_OBUF_inst_i_2_n_0),
        .I3(\Y_OBUF[3]_inst_i_4_n_0 ),
        .I4(A_IBUF[2]),
        .I5(\Y_OBUF[3]_inst_i_5_n_0 ),
        .O(Y_OBUF[3]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \Y_OBUF[3]_inst_i_2 
       (.I0(F_IBUF[1]),
        .I1(F_IBUF[0]),
        .O(\Y_OBUF[3]_inst_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \Y_OBUF[3]_inst_i_3 
       (.I0(A_IBUF[3]),
        .I1(F_IBUF[2]),
        .I2(B_IBUF[3]),
        .O(\Y_OBUF[3]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \Y_OBUF[3]_inst_i_4 
       (.I0(F_IBUF[2]),
        .I1(B_IBUF[2]),
        .O(\Y_OBUF[3]_inst_i_4_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'h00008EE8)) 
    \Y_OBUF[3]_inst_i_5 
       (.I0(F_IBUF[0]),
        .I1(A_IBUF[3]),
        .I2(F_IBUF[2]),
        .I3(B_IBUF[3]),
        .I4(F_IBUF[1]),
        .O(\Y_OBUF[3]_inst_i_5_n_0 ));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif

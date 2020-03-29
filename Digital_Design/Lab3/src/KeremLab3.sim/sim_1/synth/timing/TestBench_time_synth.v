// Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
// Date        : Thu Mar 09 11:54:45 2017
// Host        : EALAB01 running 64-bit Service Pack 1  (build 7601)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               D:/Users/TEMP/Desktop/KeremLab3/KeremLab3.sim/sim_1/synth/timing/TestBench_time_synth.v
// Design      : top
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

module ClockDivider
   (clk);
  input clk;

  wire BUFG_inst_n_0;
  wire clk;
  wire clk_NoBuf;
  wire \count[0]_i_1_n_0 ;
  wire \count_reg[10]_i_1_n_0 ;
  wire \count_reg[10]_i_2_n_0 ;
  wire \count_reg[11]_i_1_n_0 ;
  wire \count_reg[11]_i_2_n_0 ;
  wire \count_reg[12]_i_1_n_0 ;
  wire \count_reg[12]_i_2_n_0 ;
  wire \count_reg[13]_i_1_n_0 ;
  wire \count_reg[13]_i_2_n_0 ;
  wire \count_reg[14]_i_1_n_0 ;
  wire \count_reg[14]_i_2_n_0 ;
  wire \count_reg[15]_i_1_n_0 ;
  wire \count_reg[15]_i_2_n_0 ;
  wire \count_reg[16]_i_1_n_0 ;
  wire \count_reg[16]_i_2_n_0 ;
  wire \count_reg[17]_i_1_n_0 ;
  wire \count_reg[17]_i_2_n_0 ;
  wire \count_reg[18]_i_1_n_0 ;
  wire \count_reg[18]_i_2_n_0 ;
  wire \count_reg[19]_i_1_n_0 ;
  wire \count_reg[19]_i_2_n_0 ;
  wire \count_reg[1]_i_1_n_0 ;
  wire \count_reg[20]_i_1_n_0 ;
  wire \count_reg[20]_i_2_n_0 ;
  wire \count_reg[21]_i_1_n_0 ;
  wire \count_reg[21]_i_2_n_0 ;
  wire \count_reg[22]_i_1_n_0 ;
  wire \count_reg[22]_i_2_n_0 ;
  wire \count_reg[23]_i_1_n_0 ;
  wire \count_reg[23]_i_2_n_0 ;
  wire \count_reg[24]_i_1_n_0 ;
  wire \count_reg[24]_i_2_n_0 ;
  wire \count_reg[25]_i_1_n_0 ;
  wire \count_reg[25]_i_2_n_0 ;
  wire \count_reg[2]_i_1_n_0 ;
  wire \count_reg[2]_i_2_n_0 ;
  wire \count_reg[3]_i_1_n_0 ;
  wire \count_reg[3]_i_2_n_0 ;
  wire \count_reg[4]_i_1_n_0 ;
  wire \count_reg[4]_i_2_n_0 ;
  wire \count_reg[5]_i_1_n_0 ;
  wire \count_reg[5]_i_2_n_0 ;
  wire \count_reg[6]_i_1_n_0 ;
  wire \count_reg[6]_i_2_n_0 ;
  wire \count_reg[7]_i_1_n_0 ;
  wire \count_reg[7]_i_2_n_0 ;
  wire \count_reg[8]_i_1_n_0 ;
  wire \count_reg[8]_i_2_n_0 ;
  wire \count_reg[9]_i_1_n_0 ;
  wire \count_reg[9]_i_2_n_0 ;
  wire \count_reg_n_0_[0] ;
  wire \count_reg_n_0_[10] ;
  wire \count_reg_n_0_[11] ;
  wire \count_reg_n_0_[12] ;
  wire \count_reg_n_0_[13] ;
  wire \count_reg_n_0_[14] ;
  wire \count_reg_n_0_[15] ;
  wire \count_reg_n_0_[16] ;
  wire \count_reg_n_0_[17] ;
  wire \count_reg_n_0_[18] ;
  wire \count_reg_n_0_[19] ;
  wire \count_reg_n_0_[1] ;
  wire \count_reg_n_0_[20] ;
  wire \count_reg_n_0_[21] ;
  wire \count_reg_n_0_[22] ;
  wire \count_reg_n_0_[23] ;
  wire \count_reg_n_0_[24] ;
  wire \count_reg_n_0_[2] ;
  wire \count_reg_n_0_[3] ;
  wire \count_reg_n_0_[4] ;
  wire \count_reg_n_0_[5] ;
  wire \count_reg_n_0_[6] ;
  wire \count_reg_n_0_[7] ;
  wire \count_reg_n_0_[8] ;
  wire \count_reg_n_0_[9] ;
  wire [3:0]\NLW_count_reg[25]_i_1_CARRY4_CO_UNCONNECTED ;
  wire [3:0]\NLW_count_reg[25]_i_1_CARRY4_DI_UNCONNECTED ;
  wire [3:1]\NLW_count_reg[25]_i_1_CARRY4_O_UNCONNECTED ;
  wire [3:1]\NLW_count_reg[25]_i_1_CARRY4_S_UNCONNECTED ;

  (* BOX_TYPE = "PRIMITIVE" *) 
  BUFG BUFG_inst
       (.I(clk_NoBuf),
        .O(BUFG_inst_n_0));
  LUT1 #(
    .INIT(2'h1)) 
    \count[0]_i_1 
       (.I0(\count_reg_n_0_[0] ),
        .O(\count[0]_i_1_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(\count[0]_i_1_n_0 ),
        .Q(\count_reg_n_0_[0] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[10] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[10]_i_1_n_0 ),
        .Q(\count_reg_n_0_[10] ),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  (* XILINX_TRANSFORM_PINMAP = "LO:O" *) 
  CARRY4 \count_reg[10]_i_2_CARRY4 
       (.CI(\count_reg[9]_i_2_n_0 ),
        .CO({\count_reg[13]_i_2_n_0 ,\count_reg[12]_i_2_n_0 ,\count_reg[11]_i_2_n_0 ,\count_reg[10]_i_2_n_0 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[12]_i_1_n_0 ,\count_reg[11]_i_1_n_0 ,\count_reg[10]_i_1_n_0 ,\count_reg[9]_i_1_n_0 }),
        .S({\count_reg_n_0_[12] ,\count_reg_n_0_[11] ,\count_reg_n_0_[10] ,\count_reg_n_0_[9] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[11] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[11]_i_1_n_0 ),
        .Q(\count_reg_n_0_[11] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[12] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[12]_i_1_n_0 ),
        .Q(\count_reg_n_0_[12] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[13] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[13]_i_1_n_0 ),
        .Q(\count_reg_n_0_[13] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[14] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[14]_i_1_n_0 ),
        .Q(\count_reg_n_0_[14] ),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  (* XILINX_TRANSFORM_PINMAP = "LO:O" *) 
  CARRY4 \count_reg[14]_i_2_CARRY4 
       (.CI(\count_reg[13]_i_2_n_0 ),
        .CO({\count_reg[17]_i_2_n_0 ,\count_reg[16]_i_2_n_0 ,\count_reg[15]_i_2_n_0 ,\count_reg[14]_i_2_n_0 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[16]_i_1_n_0 ,\count_reg[15]_i_1_n_0 ,\count_reg[14]_i_1_n_0 ,\count_reg[13]_i_1_n_0 }),
        .S({\count_reg_n_0_[16] ,\count_reg_n_0_[15] ,\count_reg_n_0_[14] ,\count_reg_n_0_[13] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[15] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[15]_i_1_n_0 ),
        .Q(\count_reg_n_0_[15] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[16] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[16]_i_1_n_0 ),
        .Q(\count_reg_n_0_[16] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[17] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[17]_i_1_n_0 ),
        .Q(\count_reg_n_0_[17] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[18] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[18]_i_1_n_0 ),
        .Q(\count_reg_n_0_[18] ),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  (* XILINX_TRANSFORM_PINMAP = "LO:O" *) 
  CARRY4 \count_reg[18]_i_2_CARRY4 
       (.CI(\count_reg[17]_i_2_n_0 ),
        .CO({\count_reg[21]_i_2_n_0 ,\count_reg[20]_i_2_n_0 ,\count_reg[19]_i_2_n_0 ,\count_reg[18]_i_2_n_0 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[20]_i_1_n_0 ,\count_reg[19]_i_1_n_0 ,\count_reg[18]_i_1_n_0 ,\count_reg[17]_i_1_n_0 }),
        .S({\count_reg_n_0_[20] ,\count_reg_n_0_[19] ,\count_reg_n_0_[18] ,\count_reg_n_0_[17] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[19] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[19]_i_1_n_0 ),
        .Q(\count_reg_n_0_[19] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[1] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[1]_i_1_n_0 ),
        .Q(\count_reg_n_0_[1] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[20] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[20]_i_1_n_0 ),
        .Q(\count_reg_n_0_[20] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[21] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[21]_i_1_n_0 ),
        .Q(\count_reg_n_0_[21] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[22] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[22]_i_1_n_0 ),
        .Q(\count_reg_n_0_[22] ),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  (* XILINX_TRANSFORM_PINMAP = "LO:O" *) 
  CARRY4 \count_reg[22]_i_2_CARRY4 
       (.CI(\count_reg[21]_i_2_n_0 ),
        .CO({\count_reg[25]_i_2_n_0 ,\count_reg[24]_i_2_n_0 ,\count_reg[23]_i_2_n_0 ,\count_reg[22]_i_2_n_0 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[24]_i_1_n_0 ,\count_reg[23]_i_1_n_0 ,\count_reg[22]_i_1_n_0 ,\count_reg[21]_i_1_n_0 }),
        .S({\count_reg_n_0_[24] ,\count_reg_n_0_[23] ,\count_reg_n_0_[22] ,\count_reg_n_0_[21] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[23] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[23]_i_1_n_0 ),
        .Q(\count_reg_n_0_[23] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[24] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[24]_i_1_n_0 ),
        .Q(\count_reg_n_0_[24] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[25] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[25]_i_1_n_0 ),
        .Q(clk_NoBuf),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  CARRY4 \count_reg[25]_i_1_CARRY4 
       (.CI(\count_reg[25]_i_2_n_0 ),
        .CO(\NLW_count_reg[25]_i_1_CARRY4_CO_UNCONNECTED [3:0]),
        .CYINIT(1'b0),
        .DI(\NLW_count_reg[25]_i_1_CARRY4_DI_UNCONNECTED [3:0]),
        .O({\NLW_count_reg[25]_i_1_CARRY4_O_UNCONNECTED [3:1],\count_reg[25]_i_1_n_0 }),
        .S({\NLW_count_reg[25]_i_1_CARRY4_S_UNCONNECTED [3:1],clk_NoBuf}));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[2] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[2]_i_1_n_0 ),
        .Q(\count_reg_n_0_[2] ),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  (* XILINX_TRANSFORM_PINMAP = "LO:O" *) 
  CARRY4 \count_reg[2]_i_2_CARRY4 
       (.CI(1'b0),
        .CO({\count_reg[5]_i_2_n_0 ,\count_reg[4]_i_2_n_0 ,\count_reg[3]_i_2_n_0 ,\count_reg[2]_i_2_n_0 }),
        .CYINIT(\count_reg_n_0_[0] ),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[4]_i_1_n_0 ,\count_reg[3]_i_1_n_0 ,\count_reg[2]_i_1_n_0 ,\count_reg[1]_i_1_n_0 }),
        .S({\count_reg_n_0_[4] ,\count_reg_n_0_[3] ,\count_reg_n_0_[2] ,\count_reg_n_0_[1] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[3] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[3]_i_1_n_0 ),
        .Q(\count_reg_n_0_[3] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[4] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[4]_i_1_n_0 ),
        .Q(\count_reg_n_0_[4] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[5] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[5]_i_1_n_0 ),
        .Q(\count_reg_n_0_[5] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[6] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[6]_i_1_n_0 ),
        .Q(\count_reg_n_0_[6] ),
        .R(1'b0));
  (* XILINX_LEGACY_PRIM = "(MUXCY,XORCY)" *) 
  (* XILINX_TRANSFORM_PINMAP = "LO:O" *) 
  CARRY4 \count_reg[6]_i_2_CARRY4 
       (.CI(\count_reg[5]_i_2_n_0 ),
        .CO({\count_reg[9]_i_2_n_0 ,\count_reg[8]_i_2_n_0 ,\count_reg[7]_i_2_n_0 ,\count_reg[6]_i_2_n_0 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[8]_i_1_n_0 ,\count_reg[7]_i_1_n_0 ,\count_reg[6]_i_1_n_0 ,\count_reg[5]_i_1_n_0 }),
        .S({\count_reg_n_0_[8] ,\count_reg_n_0_[7] ,\count_reg_n_0_[6] ,\count_reg_n_0_[5] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[7] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[7]_i_1_n_0 ),
        .Q(\count_reg_n_0_[7] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[8] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[8]_i_1_n_0 ),
        .Q(\count_reg_n_0_[8] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[9] 
       (.C(clk),
        .CE(1'b1),
        .D(\count_reg[9]_i_1_n_0 ),
        .Q(\count_reg_n_0_[9] ),
        .R(1'b0));
endmodule

module GrayCounter
   (n2_OBUF,
    pr_IBUF_BUFG,
    clr_IBUF);
  output n2_OBUF;
  input pr_IBUF_BUFG;
  input clr_IBUF;

  wire clr_IBUF;
  wire n2_OBUF;
  wire pr_IBUF_BUFG;

  flipflop ff1
       (.clr_IBUF(clr_IBUF),
        .n2_OBUF(n2_OBUF),
        .pr_IBUF_BUFG(pr_IBUF_BUFG));
endmodule

module flipflop
   (n2_OBUF,
    pr_IBUF_BUFG,
    clr_IBUF);
  output n2_OBUF;
  input pr_IBUF_BUFG;
  input clr_IBUF;

  wire clr_IBUF;
  wire n2_OBUF;
  wire pr_IBUF_BUFG;

  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    q_reg_LDC
       (.CLR(clr_IBUF),
        .D(1'b1),
        .G(pr_IBUF_BUFG),
        .GE(1'b1),
        .Q(n2_OBUF));
endmodule

(* NotValidForBitStream *)
module top
   (clk,
    clr,
    pr,
    n2,
    n1,
    n0);
  input clk;
  input clr;
  input pr;
  output n2;
  output n1;
  output n0;

  wire clk;
  wire clk_IBUF;
  wire clk_IBUF_BUFG;
  wire clr;
  wire clr_IBUF;
  wire n0;
  wire n1;
  wire n2;
  wire n2_OBUF;
  wire pr;
  wire pr_IBUF;
  wire pr_IBUF_BUFG;

initial begin
 $sdf_annotate("TestBench_time_synth.sdf",,,,"tool_control");
end
  ClockDivider cd
       (.clk(clk_IBUF_BUFG));
  BUFG clk_IBUF_BUFG_inst
       (.I(clk_IBUF),
        .O(clk_IBUF_BUFG));
  IBUF clk_IBUF_inst
       (.I(clk),
        .O(clk_IBUF));
  IBUF clr_IBUF_inst
       (.I(clr),
        .O(clr_IBUF));
  GrayCounter gc
       (.clr_IBUF(clr_IBUF),
        .n2_OBUF(n2_OBUF),
        .pr_IBUF_BUFG(pr_IBUF_BUFG));
  OBUF n0_OBUF_inst
       (.I(1'b1),
        .O(n0));
  OBUF n1_OBUF_inst
       (.I(1'b0),
        .O(n1));
  OBUF n2_OBUF_inst
       (.I(n2_OBUF),
        .O(n2));
  BUFG pr_IBUF_BUFG_inst
       (.I(pr_IBUF),
        .O(pr_IBUF_BUFG));
  IBUF pr_IBUF_inst
       (.I(pr),
        .O(pr_IBUF));
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

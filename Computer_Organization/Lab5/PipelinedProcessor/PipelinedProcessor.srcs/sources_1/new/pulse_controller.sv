/////////////////////////////////////////////////////////////////////////////////
// 
//   pulse_controller.sv
// 
//   Will Sawyer on 03/31/2017
// 
//   This module takes a slide switch or pushbutton input and 
//   does the following:
//     --debounces it on both its low-to-high transition, and its high-to-low transition
//      (by ignoring any addtional changes (typical "switch bounce" for ~40 milliseconds)
//     --synchronizes it with the clock edges
//     --produces just one pulse, lasting for one clock period, for a pushed and released switch
//   
//   Note that the 40 millisecond debounce time = 4000000 cycles of 
//   100 MHz clock (which has 10 nsec period)
// 
//   CLK: the 100 MHz system clock from the BASYS3 board  
//   sw_input: the signal coming from the slide switch or pushbutton
//   clear: this debouncer takes a direct clear input to reset its state, at start-up
//   clk_pulse: the synchronized debounced single-pulse output
//
//////////////////////////////////////////////////////////////////////////////////

module pulse_controller(
	input  logic CLK, sw_input, clear,
	output logic clk_pulse );

	 logic [2:0] state, nextstate;
	 logic [20:0] CNT; 
	 logic cnt_zero; 

	always_ff @ (posedge CLK, posedge clear)
	   if(clear)
	    	state <=3'b000;
	   else
	    	state <= nextstate;

	always_comb
          case (state)
             3'b000: begin if (sw_input) nextstate = 3'b001; 
                           else nextstate = 3'b000; clk_pulse = 0; end	     
             3'b001: begin nextstate = 3'b010; clk_pulse = 1; end
             3'b010: begin if (cnt_zero) nextstate = 3'b011; 
                           else nextstate = 3'b010; clk_pulse = 0; end
             3'b011: begin if (sw_input) nextstate = 3'b011; 
                           else nextstate = 3'b100; clk_pulse = 0; end
             3'b100: begin if (cnt_zero) nextstate = 3'b000; 
                           else nextstate = 3'b100; clk_pulse = 0; end
            default: begin nextstate = 3'b000; clk_pulse = 0; end
          endcase

	always_ff @(posedge CLK)
	   case(state)
		3'b001: CNT <= 4000000;
		3'b010: CNT <= CNT-1;
		3'b011: CNT <= 4000000;
		3'b100: CNT <= CNT-1;
	   endcase

//  reduction operator |CNT gives the OR of all bits in the CNT register	
	assign cnt_zero = ~|CNT;

endmodule

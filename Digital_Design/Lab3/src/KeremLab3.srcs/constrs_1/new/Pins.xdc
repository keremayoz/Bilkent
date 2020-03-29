#------------------------------------------------------------
#---------------------- Clock signal ------------------------
#------------------------------------------------------------
set_property PACKAGE_PIN W5 [get_ports clk_in]  	 	 	 	  
set_property IOSTANDARD LVCMOS33 [get_ports clk_in] 
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports clk_in]

##Pmod Header JA 
##Sch name = JA1 
set_property PACKAGE_PIN J1 [get_ports {clk_out}] 	 	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {clk_out}]
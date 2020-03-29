
 set_property PACKAGE_PIN W5 [get_ports clk]  	 	 	 	  
        set_property IOSTANDARD LVCMOS33 [get_ports clk] 
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports clk]

set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets pr_IBUF]

set_property PACKAGE_PIN V17 [get_ports {clr}] 	 	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {clr}] 
set_property PACKAGE_PIN V16 [get_ports {pr}] 	 	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {pr}] 
 	
 set_property PACKAGE_PIN U16 [get_ports {n0}]  	 	 	 	 
    set_property IOSTANDARD LVCMOS33 [get_ports {n0}] 
set_property PACKAGE_PIN E19 [get_ports {n1}]                      
    set_property IOSTANDARD LVCMOS33 [get_ports {n1}] 
set_property PACKAGE_PIN U19 [get_ports {n2}]                      
          set_property IOSTANDARD LVCMOS33 [get_ports {n2}] 

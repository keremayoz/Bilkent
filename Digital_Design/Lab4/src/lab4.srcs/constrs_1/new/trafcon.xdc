#Sensors A and B
set_property PACKAGE_PIN T1 [get_ports {sb}] 	 	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {sb}] 
set_property PACKAGE_PIN R2 [get_ports {sa}] 	 	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {sa}]
 	 
#Ligth A
set_property PACKAGE_PIN N3 [get_ports {al[0]}]  	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {al[0]}] 
set_property PACKAGE_PIN P1 [get_ports {al[1]}]  	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {al[1]}] 
set_property PACKAGE_PIN L1 [get_ports {al[2]}]  	 	 	 	  			
    set_property IOSTANDARD LVCMOS33 [get_ports {al[2]}] 

#Ligth B
set_property PACKAGE_PIN V3 [get_ports {bl[0]}] 	 	 	 	 	 
    set_property IOSTANDARD LVCMOS33 [get_ports {bl[0]}] 
set_property PACKAGE_PIN W3 [get_ports {bl[1]}]                      
    set_property IOSTANDARD LVCMOS33 [get_ports {bl[1]}] 
set_property PACKAGE_PIN U3 [get_ports {bl[2]}]                      
    set_property IOSTANDARD LVCMOS33 [get_ports {bl[2]}]
    
#Clock
set_property PACKAGE_PIN W5 [get_ports clk]  	 	 	 	  
    set_property IOSTANDARD LVCMOS33 [get_ports clk] 
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports clk] 

#Reset
set_property PACKAGE_PIN U1 [get_ports {rst}] 	 	 	 	 	 
 	set_property IOSTANDARD LVCMOS33 [get_ports {rst}] 



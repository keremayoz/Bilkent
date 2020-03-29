#Start
set_property PACKAGE_PIN R2 [get_ports {start}]
    set_property IOSTANDARD LVCMOS33 [get_ports {start}]
    
#Speed input
set_property PACKAGE_PIN W2 [get_ports {speed[0]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {speed[0]}]

set_property PACKAGE_PIN U1 [get_ports {speed[1]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {speed[1]}]
    
#Reset
set_property PACKAGE_PIN T1 [get_ports {rst}]
    set_property IOSTANDARD LVCMOS33 [get_ports {rst}]

#Reverse
set_property PACKAGE_PIN R3 [get_ports {reverse}]
    set_property IOSTANDARD LVCMOS33 [get_ports {reverse}]
    
#Clock
set_property PACKAGE_PIN W5 [get_ports clk]
    set_property IOSTANDARD LVCMOS33 [get_ports clk]
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports clk]

#Signals   
set_property PACKAGE_PIN W19 [get_ports ls]
    set_property IOSTANDARD LVCMOS33 [get_ports ls]
   
set_property PACKAGE_PIN T17 [get_ports rs]
    set_property IOSTANDARD LVCMOS33 [get_ports rs]
    
#Signal-outputs
set_property PACKAGE_PIN U16 [get_ports {rss}]
    set_property IOSTANDARD LVCMOS33 [get_ports {rss}]

set_property PACKAGE_PIN E19 [get_ports {lss}]
    set_property IOSTANDARD LVCMOS33 [get_ports {lss}]
    
#7Segment
set_property PACKAGE_PIN W7 [get_ports {a}]
    set_property IOSTANDARD LVCMOS33 [get_ports {a}]

set_property PACKAGE_PIN W6 [get_ports {b}]
    set_property IOSTANDARD LVCMOS33 [get_ports {b}]

set_property PACKAGE_PIN U8 [get_ports {c}]
    set_property IOSTANDARD LVCMOS33 [get_ports {c}]

set_property PACKAGE_PIN V8 [get_ports {d}]
    set_property IOSTANDARD LVCMOS33 [get_ports {d}]

set_property PACKAGE_PIN U5 [get_ports {e}]
    set_property IOSTANDARD LVCMOS33 [get_ports {e}]

set_property PACKAGE_PIN V5 [get_ports {f}]
    set_property IOSTANDARD LVCMOS33 [get_ports {f}]

set_property PACKAGE_PIN U7 [get_ports {g}]
    set_property IOSTANDARD LVCMOS33 [get_ports {g}]

set_property PACKAGE_PIN V7 [get_ports dp]
    set_property IOSTANDARD LVCMOS33 [get_ports dp]

set_property PACKAGE_PIN U2 [get_ports {an[0]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {an[0]}]

set_property PACKAGE_PIN U4 [get_ports {an[1]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {an[1]}]

set_property PACKAGE_PIN V4 [get_ports {an[2]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {an[2]}]

set_property PACKAGE_PIN W4 [get_ports {an[3]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {an[3]}]

##Pmod Header JB

##Sch name = JB1

set_property PACKAGE_PIN A14 [get_ports {newL[0]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {newL[0]}]

##Sch name = JB2

set_property PACKAGE_PIN A16 [get_ports {newL[1]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {newL[1]}]

##Sch name = JB3

set_property PACKAGE_PIN B15 [get_ports {newL[2]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {newL[2]}]

##Sch name = JB4

set_property PACKAGE_PIN B16 [get_ports {newL[3]}]
    set_property IOSTANDARD LVCMOS33 [get_ports {newL[3]}]

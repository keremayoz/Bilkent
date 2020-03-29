# 
# Synthesis run script generated by Vivado
# 

debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a35tcpg236-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir D:/Users/TEMP/Desktop/Lab6/Lab6/Lab6.cache/wt [current_project]
set_property parent.project_path D:/Users/TEMP/Desktop/Lab6/Lab6/Lab6.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib -sv {
  D:/Users/TEMP/Desktop/Lab6/Lab6/Lab6.srcs/sources_1/new/Mux.sv
  D:/Users/TEMP/Desktop/Lab6/Lab6/Lab6.srcs/sources_1/new/FourBitFullAdder.sv
  D:/Users/TEMP/Desktop/Lab6/Lab6/Lab6.srcs/sources_1/new/Alu.sv
}
synth_design -top Alu -part xc7a35tcpg236-1
write_checkpoint -noxdef Alu.dcp
catch { report_utilization -file Alu_utilization_synth.rpt -pb Alu_utilization_synth.pb }
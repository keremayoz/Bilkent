@echo off
set xv_path=D:\\Vivado\\Vivado\\2016.4\\bin
call %xv_path%/xelab  -wto 6efa96a82860428b8dff3354c526572a -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot trafficsim_behav xil_defaultlib.trafficsim xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0

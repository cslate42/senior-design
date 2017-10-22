%---------------------------------------------------
%               HDL Toolset Config
%---------------------------------------------------
hdlsetuptoolpath('ToolName', 'Xilinx Vivado', 'ToolPath', 'F:\Xilinx\Vivado\2016.2\bin\vivado.bat');
z = zynq();
z.setupZynqHardware();

%---------------------------------------------------
%               More?
%---------------------------------------------------

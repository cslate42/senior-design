% https://www.mathworks.com/help/hdlverifier/ug/verify-hdl-model-with-simulink-test-bench.html
% https://www.mathworks.com/help/hdlverifier/gs/hdl-cosimulation.html


% https://www.mathworks.com/help/hdlfilter/cosimulation-of-hdl-code-with-hdl-simulators-.html
% https://fr.mathworks.com/examples/simulink-hdl-coder
% https://www.tutorialspoint.com/matlab/pdf/matlab_simulink.pdf
hdlsetuptoolpath('ToolName', 'Xilinx Vivado', 'ToolPath', 'F:\Xilinx\Vivado\2016.2\bin\vivado.bat');
z = zynq();
z.setupZynqHardware();
%helpview(fullfile(docroot,'toolbox','hdlverifier','helptargets.map'),'EDACosimAssistTutorialSL')

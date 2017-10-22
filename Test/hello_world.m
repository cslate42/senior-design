% https://www.mathworks.com/help/hdlcoder/examples/using-ip-core-generation-workflow-from-matlab-led-blinking.html
% https://www.mathworks.com/help/hdlcoder/examples/define-and-register-custom-board-and-reference-design-for-soc-workflow.html
% https://www.mathworks.com/examples/matlab-hdl-coder/mw/hdlcoder_product-hdlcoder_ip_core_tutorial_zynq-getting-started-with-hardware-software-co-design-workflow-for-xilinx-zynq-platform

% can look at embedded coder zynq 7000 support package example
% https://www.xilinx.com/support/documentation-navigation/self-paced-tutorials/vivado-design-suite.html

% https://www.xilinx.com/support/documentation-navigation/design-hubs/dh0014-vivado-system-generator-hub.html
% https://www.xilinx.com/support/documentation-navigation/self-paced-tutorials/see-all-tutorials.html

% VIDEO TUTS
% 1: https://www.mathworks.com/videos/run-a-simulink-model-on-zynq-introduction-and-requirements-1-of-4-89508.html
% 2: https://www.mathworks.com/videos/run-a-simulink-model-on-zynq-zedboard-set-up-2-of-4-89509.html
% 3: https://www.mathworks.com/videos/run-a-simulink-model-on-zynq-exploring-the-simulink-model-3-of-4-89510.html
% 4: https://www.mathworks.com/videos/run-a-simulink-model-on-zynq-code-generation-and-deployment-4-of-4-89511.html

hdlsetuptoolpath('ToolName', 'Xilinx Vivado', 'ToolPath', 'F:\Xilinx\Vivado\2017.1\bin\vivado.bat');
%mex -setup;
%targetupdater;
%xmakefilesetup;
z = zynq();
z.setupZynqHardware();
hdlcoder_led_blinking;




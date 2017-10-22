% http://www.help2educate.com/generate-pwm-signal-in-matlab-simulink/
% https://www.mathworks.com/examples/simulink-hdl-coder/mw/hdlcoder_product-hdlcoder_multiclock-using-multiple-clocks-in-hdl-coder-8482
%{
pwmStruct = "HELLO CALEB"
while(1)
    % toggle manual switch
    switchPath = ''
    set_param(switchPath, 'sw', switchValue)
end
%}

%{
hdlsetuptoolpath('ToolName', 'Xilinx Vivado', 'ToolPath', 'F:\Xilinx\Vivado\2016.2\bin\vivado.bat');
z = zynq();
z.setupZynqHardware();
%}
open('simple_pwm_model')
%called with property inspecter
pulseWidth = 25;
set_param('simple_pwm/pwmGenerator', 'PulseWidth', pulseWidth);
disp('Pulse Width');
disp(pulseWidth);
%pwmGenerator:PulseWidth = 25

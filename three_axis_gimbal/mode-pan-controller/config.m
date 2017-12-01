% https://www.mathworks.com/help/hdlcoder/examples/using-multiple-clocks-in-hdl-coder.html
% https://www.mathworks.com/help/hdlcoder/examples/delay-balancing-and-validation-model-workflow-in-hdl-coder.html
% https://www.mathworks.com/help/xpc/ug/interrupt-configuration.html
load_system('hdlcoder_clockdemo');
open_system('hdlcoder_clockdemo/DUT');

open_system('hdl_delaybalancing');

%https://www.mathworks.com/help/xpc/examples/pll-based-interrupt-generation-from-fpga-input.html
open_system('dslrtExtDIOInt')

%https://www.mathworks.com/videos/hdl-coder-clock-rate-pipelining-part-1-introduction-120117.html

function a = () {
    
}

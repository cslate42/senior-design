%---------------------------------------------------
%               Starting Params
%---------------------------------------------------
%set_param();
hdlsetup('three_axis_gimbal');

% trigger info
% web(fullfile(docroot, 'hdlcoder/ref/triggeredsubsystem.html'));

% to watch!!!
% EDGE DETECTION https://www.youtube.com/watch?v=yapF8MLWORY

% clocks
% https://www.mathworks.com/help/hdlverifier/ug/clock-reset-and-enable-signals.html#bt9u4xl-90

%{
Function Gen
    50 hz
    2.2 peak to peak
    1.2 offset
    clockwise 5% - 7.5%
    counterclockwise 7.5% to 10%
Power
    11.6 volts
    1.5 ampsish?
    
Motor P (Camera holder)
    White wires
Motor R (B4 Camera)
    Red wires
Motor Y (Base)
    Blue wires
%}
%---------------------------------------------------
%               More?
%---------------------------------------------------

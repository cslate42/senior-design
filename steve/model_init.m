SaturationLimit=256; % Saturation in controller
PWM_CNT = 1024e3; % uint32(50e-3/SampleTime)  % 50mS pulse width
Kp = 16;
Ki = 4;
Kd = 1;

% Coefficients for extracting "green" image
% Rgain = -0.75;
% Ggain = 1.25;
% Bgain = -0.75;
% Gthresh = 40; % Threshold for creating binary image

if (~exist('R'))
R = 1080;
C = 1920;
end

Rbits = ceil(log2(R));
Cbits = ceil(log2(C));

% Arm Parameters
intC = int16(C);
C_numberOfBits=double(11);
MaxDeltaAngle = double(floor(255*(8/90)));
deadZone=double(floor(0.1*C));

% Coefficients for extracting orange ball
% SatTarg = 0.44;
% SatTol = 0.025;
% ValTarg = 195;
% ValTol = 25;
% HueTarg = 20;
% HueTol = 5;

% Green ball
% Saturation 0 - 1
SatTarg = 0.38;
SatTol = 0.05;
% Value 0 - 255
ValTarg = 170;
ValTol = 45;
% Hue 0 - 360
% HueTarg = 110;
HueTarg = 150;  % for avi input
HueTol = 20;

FrRt = 30; % Frame /sec
TsFr = 1/FrRt; % Hz
TsFPGA = TsFr/(R*C); %Hz

% SampleRate = 1/TsFPGA; % 30e6;           % 50 MHz Sample Rate
% SampleTime = TsFPGA; % 1/SampleRate;   % 20ns Sample Time

% Arm Parameters
msize = max(floor(40 * R/1080),5); % size of the marker (msize x msize)
xmsize = max(floor(10 * R/1080),5); % size of the marker (msize x msize)

%% CFA Properties
% G at R or B
KernG = [ 0 0 -1 0 0;...
          0 0 2 0 0;...
          -1 2 4 2 -1;...
          0 0 2 0 0;...
          0 0 -1 0 0];

% R at G(1), B at G(2)
KernR1B2 = [0 0 -1 0 0;...
        0 -1 4 -1 0;...
        1/2 0 5 0 1/2;...
        0 -1 4 -1 0;...
        0 0 -1 0 0];      
      
% R at G(2), B at G(1)
KernR2B1 = KernR1B2';

% R at B, B at R
KernRB = [0 0 -3/2 0 0;...
        0 2 0 2 0;...
        -3/2 0 6 0 -3/2;...
        0 2 0 2 0;...
        0 0 -3/2 0 0];
    
KernG = KernG / sum(sum(KernG));    
KernR1B2 = KernR1B2 / sum(sum(KernR1B2));    
KernR2B1 = KernR2B1 / sum(sum(KernR2B1));    
KernRB = KernRB / sum(sum(KernRB)); 

KernG_hdl = reshape(KernG,[],1);
KernR1B2_hdl = reshape(KernR1B2,[],1);
KernR2B1_hdl = reshape(KernR2B1,[],1);
KernRB_hdl = reshape(KernRB,[],1);

%% Gamma Correction
GammaErr = 2.2;
P = calc_gamma(GammaErr,3);

%% Newton Raphson Constants
NR_SCALE = 255;
NR_DENOM_DT = numerictype(1,18,17);
NR_RECIP_DT = numerictype(1,25,16);
NR_RECIP_OUT_DT = numerictype(1,25,24);
NR_INTERNAL_DT = numerictype(1,18,9);

%{
%%% Refer to 
% http://ctms.engin.umich.edu/CTMS/index.php?example=MotorSpeed&section=ControlPID
J = 0.01;
b = 0.1;
K = 0.01;
R = 1;
L = 0.5;
s = tf('s');
P_motor = K/((J*s+b)*(L*s+R)+K^2);
%}

%%%%%%%%%%%%%%%%%%%% Calebs Design %%%%%%%%%%%%%%%%%%%%%%%%%%
% get transfer function of thing in variables
% pid tune stuff based on real model
% button to find new vars 
motorsPath = Files.getDir()

J = 0.01;
b = 0.1;
K = 0.01;
R = 1;
L = 0.5;
s = tf('s');
P_motor = K/((J*s+b)*(L*s+R)+K^2);



% mfilename()
% [folder, name, ext] = fileparts(which('object'))
% pwd
% addpath()
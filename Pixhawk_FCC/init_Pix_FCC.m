%% initialize Flight Control Model to Flash on Pixhawk
%
%
% INPUT:
% 
%
%
% OUTPUT:
% FCC_PIX_Data   [1x*]  [struct]  Data struct containing all parameters needed for the flashed flight controller model
%
%
%
% DESCRIPTION:
% 
%
%
%
% PROJECT:
% Guided Research Missile / Cornetto
%
%
% AUTHOR:
% Max Hiepp
%

%% Include the necessary libraries!!!
%  (in the correct matlab version for the PX4 Toolchain)
%  - lib_flight_controller
%  - lib_fin_deflections
%  - lib_servo


%% Add paths to the libraries

addpath(genpath([pwd,'\libraries']));


%% Set global sample time [s]

% ???
if exist('HIL_Sample_Time','var')
    
else
    HIL_Sample_Time = 0.001; % -> tbd
end


%% Specify Parameters

% Controller Gains

    Roll.PreGain = 315.5;    
    Roll.Gain = 0.001;
    Roll.Lead.Num = [1 2.3];
    Roll.Lead.Denom = [1 40];
    
    Pitch.innerLoop.PropGain = 0.7231;
    Pitch.outerLoop.PropGain = -0.01779;
    Pitch.outerLoop.IntGain.Num = [-0.58935];
    Pitch.outerLoop.IntGain.Denom = [1 0];
    
    Yaw.innerLoop.PropGain = 0.7231;
    Yaw.outerLoop.PropGain = -0.01779;
    Yaw.outerLoop.IntGain.Num = [-0.58935];
    Yaw.outerLoop.IntGain.Denom = [1 0];

% Fin Deflections

    Control_Surfaces.phi_f1_rad = -pi/2;
    Control_Surfaces.phi_f2_rad = pi/2;
    Control_Surfaces.phi_f3_rad = 3*pi/2;
    Control_Surfaces.phi_f4_rad = -3*pi/2;
    
    Control_Surfaces.max_deflection_rad = 20*(2*pi/360);


% Servo Cmd

    PWM.Update_rate_Hz = 250; %Specify rate used in PixhawkPSP PWM Output Block
    PWM.periode_ms = 1/(1000*PWM.Update_rate_Hz);
    PWM.Pulswidth_cmd_middle_pos_ms = 1.5;
    PWM.Pulswidth_cmd_max_ms = 2; % ???? -> check
    PWM.Pulswidth_cmd_min_ms = 1; % ???? -> check
    PWM.Voltage_level_V = 5;      % ???? -> check
    PWM.max_deflection_rad = 20 *(2*pi/360); % ???? -> check

%% Add Data to Struct
    
    FCC_PIX_Data.Controller.Roll = Roll;
    FCC_PIX_Data.Controller.Pitch = Pitch;
    FCC_PIX_Data.Controller.Yaw = Yaw;
    FCC_PIX_Data.Control_Surfaces = Control_Surfaces;
    FCC_PIX_Data.Servo.PWM = PWM;
    
    clear Roll;
    clear Pitch;
    clear Yaw;
    clear Control_Surfaces;
    clear PWM;
    


% ------- EOF -------%% 
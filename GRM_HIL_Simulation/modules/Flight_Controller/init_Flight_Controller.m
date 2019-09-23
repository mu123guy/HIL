%% Initialize emulated Flight Controller
%
%
% INPUT:
% FCC_Sample_Time   [1]    [double] Samp Time for emulated Flight Controller
%
%
% OUTPUT:
% HIL_Data.FCC      [1x*]  [struct]  Data struct containing all parameters needed for the flight controller
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

function Flight_Controller = init_Flight_Controller (FCC_Sample_Time)
    
    %% define continous controller gains
    
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
    
    
    %% define discrete controller gains
    
    
    %% add to struct
    Flight_Controller.Roll = Roll;
    Flight_Controller.Pitch = Pitch;
    Flight_Controller.Yaw = Yaw;
    
end
% ------- EOF -------%% 
%% Initialize External Inputs to the Simulation
%
%
% INPUT:
%  --- 
%
%
% OUTPUT:
% HIL_Data.External_Inputs   [1x*]  [struct]  Data struct containing all
%                                             parameters that specify the
%                                             conditions of the simulation
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

function External_Inputs = init_External_Inputs()
    
    %% External Inputs to FDM
    FDM.Motor_Ignition_time_s = 10;
    
    
    %% External Inputs to FCC
    FCC.Flight_Termination_flg = 0;
    
    % Generate Commands
    FCC.CMD.roll.pulse_cmd_flg = 0; %0->constant commands
    FCC.CMD.pitch.pulse_cmd_flg = 1;
    FCC.CMD.yaw.pulse_cmd_flg = 0;
    % Constant Commands
    FCC.CMD.roll.const.phi_rad = 0;
    FCC.CMD.pitch.const.acc_z_mDs2 = 0;
    FCC.CMD.yaw.const.acc_y_mDs2 = 0;
    % Pulse commands
    FCC.CMD.roll.pulse.alternating_flg = 1; % alternate between + and - for every pulse
    FCC.CMD.roll.pulse.ampl_rad = 2;
    FCC.CMD.roll.pulse.period_s = 20;
    FCC.CMD.roll.pulse.pulse_width_perc = 50;
    FCC.CMD.roll.pulse.delay_s = 10;
    FCC.CMD.pitch.pulse.alternating_flg = 1; % alternate between + and - for every pulse
    FCC.CMD.pitch.pulse.ampl_mDs2 = 5;
    FCC.CMD.pitch.pulse.period_s = 30;
    FCC.CMD.pitch.pulse.pulse_width_perc = 30;
    FCC.CMD.pitch.pulse.delay_s = 10;
    FCC.CMD.yaw.pulse.alternating_flg = 1; % alternate between + and - for every pulse
    FCC.CMD.yaw.pulse.ampl_mDs2 = 5;
    FCC.CMD.yaw.pulse.period_s = 30;
    FCC.CMD.yaw.pulse.pulse_width_perc = 30;
    FCC.CMD.yaw.pulse.delay_s = 10;
    
    
    %% Add to struct
    External_Inputs.FDM = FDM;
    External_Inputs.FCC = FCC;
    
end
% ------- EOF -------
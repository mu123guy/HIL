%% Initialize Simulation Control
%
%
% INPUT:
% realtime                          [bool]    run sim in realtime or not
% external                          [bool]    run sim in external mode
% HW_usage                                    Cell Array containg the Hardware Components to simulate
%
% OUTPUT:
% HIL_Data.Simulation_Ctrl   [1x*]  [struct]  Data struct containing all
%                                             parameters that specify the
%                                             conditions of the simulation
%
%
%
% DESCRIPTION:
% This script defines the boundary conditions and the specifications on how
% the simulation should run
%
%
% PROJECT:
% Guided Research Missile / Cornetto
%
%
% AUTHOR:
% Max Hiepp
%

function Simulation_Ctrl = init_Simulation_Ctrl(realtime,external,HW_usage)
    
    %% Specify Simulation Paramteters
    Simulation_Ctrl.run          = 1; % <1> run / <0> stop
    Simulation_Ctrl.reset        = 0; % <1> reset
    Simulation_Ctrl.realtime_flg = realtime;
    Simulation_Ctrl.external_flg = external;
    Simulation_Ctrl.max_missed_ticks = 1000;
    
    % Configurate Flight Dynamic Model
    Simulation_Ctrl.FDM_Ctrl.enable_propulsion_flg = 0;
    Simulation_Ctrl.FDM_Ctrl.enable_drag_flg = 0;
    Simulation_Ctrl.FDM_Ctrl.enable_gravity_flg = 0;
    
    % Configure Hardware Components
    Simulation_Ctrl.HW_Ctrl.enable_gimbal_ctrl_flg = 1; % enable physical cmd signal passing to flight table
    Simulation_Ctrl.HW_Ctrl.stop_gimbal_flg = 0;
    
    % Check if any real HW is used
    Simulation_Ctrl.offline_flg = (HW_usage{2,2} & HW_usage{3,2} & HW_usage{4,2});
    
    % Specify Communication Rates and Params
    Simulation_Ctrl.Com_Ctrl.Pix.Com_freq_Hz = 200;  %must be nat fraction of Sim sample freq!!
    Simulation_Ctrl.Com_Ctrl.Pix.enable_CRC_flg = 0; %enable cyclic redundancy check for com with pixhawk
    Simulation_Ctrl.Com_Ctrl.FT.Com_freq_Hz = 500;  %must be nat fraction of Sim sample freq!!
    
    % Specify FCC Emulation Parameters
    Simulation_Ctrl.FCC_Ctrl.discrTF_flg = 0; %enable discrete Control TF for FCC emulation (<0> for continous TF)
    Simulation_Ctrl.FCC_Ctrl.FCC_ComFB_SampTime = 0.02;
    %anything else??
    
    %% Configure Sim Heartbeat
    
    %heartbeat is implemented as free running counter (uint16) that consecutivly numbers every timestep
    Simulation_Ctrl.heartbeat.range = 16; %number of bits for free running counter
    
    %% Define Variant Objects
    % (variants have to be in base workspace)
    assignin('base', 'VSS_GIMBAL_REAL', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_Gimbal==1'));
    assignin('base', 'VSS_GIMBAL_EMUL', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_Gimbal==2'));
    assignin('base', 'VSS_GIMBAL_HWICC', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_Gimbal==3'));
    assignin('base', 'VSS_FCC_REAL', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_FCC==1')); 
    assignin('base', 'VSS_FCC_EMUL', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_FCC==2'));
    assignin('base', 'VSS_ACT_REAL', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_ACT==1')); 
    assignin('base', 'VSS_ACT_EMUL', Simulink.Variant('HIL_Data.Simulation_Ctrl.VSS.VSS_ACT==2'));
    assignin('base', 'VSS_FLIGHTGEAR_ON', Simulink.Variant('HIL_Data.Simulation_Ctrl.external_flg==0'));
    assignin('base', 'VSS_FLIGHTGEAR_OFF', Simulink.Variant('HIL_Data.Simulation_Ctrl.external_flg==1 '));
    
    % for R2017a use this instead
    %assignin('base', 'VSS_GIMBAL_REAL', Simulink.Variant('VSS_Gimbal==1'));
    %assignin('base', 'VSS_GIMBAL_EMUL', Simulink.Variant('VSS_Gimbal==2'));
    %assignin('base', 'VSS_FCC_REAL', Simulink.Variant('VSS_FCC==1')); 
    %assignin('base', 'VSS_FCC_EMUL', Simulink.Variant('VSS_FCC==2'));
    %assignin('base', 'VSS_ACT_REAL', Simulink.Variant('VSS_ACT==1')); 
    %assignin('base', 'VSS_ACT_EMUL', Simulink.Variant('VSS_ACT==2'));
    
    %% Specify the HW components to simulate
    % by choosing the corresponding Variant Subsystem
    % FCC
    if HW_usage{2,2}
        %simulate
        VSS.VSS_FCC = 2;
        % for R2017a
        %assignin('base', 'VSS_FCC', 2);
    else
        %real
        VSS.VSS_FCC = 1;
        % for R2017a
        %assignin('base', 'VSS_FCC', 1);
    end
    
    % Servos
    if HW_usage{3,2}
        %simulate
        VSS.VSS_ACT = 2;
        % for R2017a
        %assignin('base', 'VSS_ACT', 2);
    else
        %real
        VSS.VSS_ACT = 1;
        % for R2017a
        %assignin('base', 'VSS_ACT', 1);
    end
    
    % Gimbal
    if HW_usage{4,2} == 1
        %simulate
        VSS.VSS_Gimbal = 2;
        % for R2017a
        %assignin('base', 'VSS_Gimbal', 2);
    elseif HW_usage{4,2} == 2
        %use HW interface CC
        VSS.VSS_Gimbal = 3;
    else
        %real
        VSS.VSS_Gimbal = 1;
        % for R2017a
        %assignin('base', 'VSS_Gimbal', 1);
    end
    
    
    %% Add to struct
    Simulation_Ctrl.VSS = VSS; %leave this out for R2017a
    
end
% ------- EOF -------
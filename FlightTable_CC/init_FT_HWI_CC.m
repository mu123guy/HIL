%% initialize Flight Table Hardware Interface Control Computer
%
%
% INPUT:
% 
%
%
% OUTPUT:
% FT_HWI_CC_Data   [1x*]  [struct]  Data struct containing all parameters needed for the model running on the Flight Table HW Interface Control Computer
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
%  (in the correct matlab version for the FT HW Interface control computer R2017a)
%  - lib_Gimbal
%  - lib_Gimbal_Ctrl
%  including their respective initialisation scripts
%  - init_Gimbal
%  - init_Gimbal_Ctrl
%
%% Include necessary bus objects
%  - ATT_Euler_Bus
%  - ATT_Quaternions_Bus
%  - Attitude_States_Bus
%  - COM_Ctrl_Bus
%  - Encoder_Resolved_Bus
%  - Encoder_Signal_Bus
%  - FDM_Ctrl_Bus
%  - Gimbal_Cmd_Bus
%  - Gimbal_Ctrl_Bus
%  - Gimbal_Encoder_Bus
%  - Gimbal_Monitor_Bus
%  - Gimbal_State_Bus
%  - Gimbal_Status_Bus
%  - HW_Ctrl_Bus
%  - Simulation_Ctrl_Bus



%% Add paths to the libraries

addpath(genpath([pwd,'\libraries']));
addpath(genpath([pwd,'\buses']));


%% Communication Specification

%Specify Com Connection directly in Library Block


%% Set FT Controller sample time [s]

FT_HWI_CC_Data.SampTime = 1/1000;
FT_HWI_CC_Data.SampFreq = 1/FT_HWI_CC_Data.SampTime;
FT_HWI_CC_Data.MaxMissTicks = 10;


%% Configure FCC Heartbeat
    
%heartbeat is implemented as free running counter (uint16) that consecutivly numbers every timestep
FT_HWI_CC_Data.heartbeat.range = 16; %number of bits for free running counter

%% Specify Parameters

% Specify Frequency of Feedback Communication
FT_HWI_CC_Data.ComFreq_Hz = 1000; %must be nat fraction of base sample time

%implement as counter
FT_HWI_CC_Data.ComFreq_mark = FT_HWI_CC_Data.SampFreq/FT_HWI_CC_Data.ComFreq_Hz-1;


%% Initialize Submodules

FT_HWI_CC_Data.HIL_Data.Gimbal_Ctrl = init_Gimbal_Ctrl;
FT_HWI_CC_Data.HIL_Data.Gimbal = init_Gimbal(2,0); %specification for FTHWICC configuration

%% Initialize Needed Bus Objects

ATT_Euler_Bus;
ATT_Quaternions_Bus;
Attitude_States_Bus;
COM_Ctrl_Bus;
Encoder_Resolved_Bus;
Encoder_Signal_Bus;
FCC_Ctrl_Bus;
FCC_Ctrl_Bus;
FDM_Ctrl_Bus;
Gimbal_Cmd_Bus;
Gimbal_Ctrl_Bus;
Gimbal_Encoder_Bus;
Gimbal_Monitor_Bus;
Gimbal_State_Bus;
Gimbal_Status_Bus;
HW_Ctrl_Bus;
Simulation_Ctrl_Bus;


%% Add Data to Struct
    
%if necessary
%and clear sub busses



% ------- EOF -------%% 
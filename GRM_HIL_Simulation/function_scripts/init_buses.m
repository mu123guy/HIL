%% Initialize the bus objects used for the data transfer within the HIL Simulation
%
%
% INPUT:
%  ---
%
%
% OUTPUT:
%  ---
%
%
%
% DESCRIPTION:
% This script calls all bus object defining functions
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
%% Call all bus objects

Airframe_Cmd_Bus;
Airframe_States_Bus;
Airframe_States_Dot_Bus;
Atm_States_Bus;
Attitude_States_Bus;
ATT_Cmd_Bus;
ATT_Euler_Bus;
ATT_Euler_Dot_Bus;
ATT_Quaternions_Bus;

COM_Ctrl_Bus;
Configuration_Values_Bus;
Controller_Cmd_Bus;
Control_Surface_Bus;
Control_Surface_Cmd_Bus;
Control_Surface_Deflections_Bus;
Control_Surface_Encoder_Bus;

Disturbances_Bus

Encoder_Resolved_Bus;
Encoder_Signal_Bus;
External_Inputs_Bus;

FCC_Commands_Bus;
FCC_Ctrl_Bus;
FCC_External_Inputs_Bus;
FDM_Ctrl_Bus;
FDM_External_Inputs_Bus;
FDM_Rot_Body_Bus;
FDM_States_Bus;
FDM_States_Dot_Bus;

Gimbal_Attitude_Bus;
Gimbal_Cmd_Bus;
Gimbal_Ctrl_Bus;
Gimbal_Encoder_Bus;
Gimbal_Monitor_Bus;
Gimbal_State_Bus;
Gimbal_Status_Bus;
Guidance_Cmd_Bus;

HW_Ctrl_Bus;

Inc_Encoder_Signal_Bus;

Position_States_Bus;
Position_States_Dot_Bus;
POS_NED_Bus;
POS_NED_Dot_Bus;
POS_WGS84_Bus;
POS_WGS84_Dot_Bus;
PWM_Cmd_Bus;

Rigid_Body_States_Bus;
Rotation_States_Bus;
Rotation_States_Dot_Bus;

Servo_Cmd_Bus;
Servo_Positions_Bus;
Servo_State_Bus;
Simulation_Ctrl_Bus;
States_Bus;

Translation_States_Bus;
Translation_States_Dot_Bus;



% ------- EOF -------
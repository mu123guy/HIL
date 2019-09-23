%% Initialize Gimbal Control
%
%
% INPUT:
%  ---
%
%
% OUTPUT:
% HIL_Data.Gimbal_Ctrl   [1x*]  [struct]  Data struct containing all parameters needed for the Gimbal Controller
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

function Gimbal_Ctrl = init_Gimbal_Ctrl ()

    % Specify Gimbal Controller Paramters
    
    %SampFreq=300; % [Hz]
    Gimbal_Ctrl.SampFreq=1000; % [Hz]

    Gimbal_Ctrl.SampTime=1/Gimbal_Ctrl.SampFreq;       % 0.003;
    Gimbal_Ctrl.MaxMissTick=10; % for external mode
    % Gimbal_Ctrl.MaxMissTick=1000; % for normal mode
    Gimbal_Ctrl.MaxCheck=5*Gimbal_Ctrl.SampTime;
    Gimbal_Ctrl.YawMaxV=100;
    Gimbal_Ctrl.PitchMaxV=150;
    Gimbal_Ctrl.RollMaxV=480;

    %Output Limitations
    Gimbal_Ctrl.Enable_Voltage_Limits_atOutput=0;
    Gimbal_Ctrl.Enable_Voltage_Limits_atController=0;
    Gimbal_Ctrl.YawCmdMaxVolt=0.8;
    Gimbal_Ctrl.YawCmdMinVolt=-0.8;
    Gimbal_Ctrl.PitchCmdMaxVolt=1;
    Gimbal_Ctrl.PitchCmdMinVolt=-0.2;
    Gimbal_Ctrl.RollCmdMaxVolt=1.1;
    Gimbal_Ctrl.RollCmdMinVolt=1.1;

    %Tune Controller Voltage Limitation
    Gimbal_Ctrl.Yaw_soft_limit_vel=0.5*Gimbal_Ctrl.YawMaxV;
    Gimbal_Ctrl.Yaw_hard_limit_vel=0.9*Gimbal_Ctrl.YawMaxV;
    Gimbal_Ctrl.Yaw_limit_adaption_coef=10;
    Gimbal_Ctrl.Pitch_soft_limit_vel=0.5*Gimbal_Ctrl.PitchMaxV;
    Gimbal_Ctrl.Pitch_hard_limit_vel=0.9*Gimbal_Ctrl.PitchMaxV;
    Gimbal_Ctrl.Pitch_limit_adaption_coef=10;
    Gimbal_Ctrl.Roll_soft_limit_vel=0.5*Gimbal_Ctrl.RollMaxV;
    Gimbal_Ctrl.Roll_hard_limit_vel=0.9*Gimbal_Ctrl.RollMaxV;
    Gimbal_Ctrl.Roll_limit_adaption_coef=10;

    %Custom Dynamic Limit PID Controller
    Gimbal_Ctrl.PID_Yaw_Proportional_Gain=3;
    Gimbal_Ctrl.PID_Yaw_Integral_Gain=0.1;
    Gimbal_Ctrl.PID_Yaw_Derivative_Gain=0.4;
    Gimbal_Ctrl.PID_Yaw_Filter_Coefficient=100;
    Gimbal_Ctrl.PID_Yaw_BackCalculation_Coefficient=sqrt(Gimbal_Ctrl.PID_Yaw_Integral_Gain*Gimbal_Ctrl.PID_Yaw_Derivative_Gain);

    Gimbal_Ctrl.PID_Pitch_Proportional_Gain=20;
    Gimbal_Ctrl.PID_Pitch_Integral_Gain=0;
    Gimbal_Ctrl.PID_Pitch_Derivative_Gain=0.4;
    Gimbal_Ctrl.PID_Pitch_Filter_Coefficient=100;
    Gimbal_Ctrl.PID_Pitch_BackCalculation_Coefficient=sqrt(Gimbal_Ctrl.PID_Pitch_Integral_Gain*Gimbal_Ctrl.PID_Pitch_Derivative_Gain);

    Gimbal_Ctrl.PID_Roll_Proportional_Gain=8;
    Gimbal_Ctrl.PID_Roll_Integral_Gain=0.2;
    Gimbal_Ctrl.PID_Roll_Derivative_Gain=0.35;
    Gimbal_Ctrl.PID_Roll_Filter_Coefficient=100;
    Gimbal_Ctrl.PID_Roll_BackCalculation_Coefficient=sqrt(Gimbal_Ctrl.PID_Roll_Integral_Gain*Gimbal_Ctrl.PID_Roll_Derivative_Gain);

    %Limiting_Controllers
    Gimbal_Ctrl.Enable_Limit_Controllers=0;
    Gimbal_Ctrl.Yaw_LC_Proportional_Gain=3;
    Gimbal_Ctrl.Yaw_LC_Integral_Gain=0;
    Gimbal_Ctrl.Yaw_LC_Derivative_Gain=0.4;
    Gimbal_Ctrl.Yaw_LC_Weighting=1;
    Gimbal_Ctrl.Pitch_LC_Proportional_Gain=20;
    Gimbal_Ctrl.Pitch_LC_Integral_Gain=0;
    Gimbal_Ctrl.Pitch_LC_Derivative_Gain=0.4;
    Gimbal_Ctrl.Pitch_LC_Weighting=1;
    Gimbal_Ctrl.Roll_LC_Proportional_Gain=8;
    Gimbal_Ctrl.Roll_LC_Integral_Gain=0;
    Gimbal_Ctrl.Roll_LC_Derivative_Gain=0.4;
    Gimbal_Ctrl.Roll_LC_Weighting=1;

    
    
end
% ------- EOF -------
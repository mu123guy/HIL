%% Initialize Servo
%
%
% INPUT:
%  ---
%
%
% OUTPUT:
% HIL_Data.Servo   [1x*]  [struct]  Data struct containing all parameters that specify the Servo behaviour
%
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

function Servo = init_Servo()
    
    % Specify PWM command characteristics
    PWM.Update_rate_Hz = 250; %Specify rate used in PixhawkPSP PWM Output Block
    PWM.periode_ms = 1/(1000*PWM.Update_rate_Hz);
    PWM.Pulswidth_cmd_middle_pos_ms = 1.5;
    PWM.Pulswidth_cmd_max_ms = 2; % ???? -> check
    PWM.Pulswidth_cmd_min_ms = 1; % ???? -> check
    PWM.Voltage_level_V = 5;      % ???? -> check
    PWM.max_deflection_rad = 20 *(2*pi/360); % ???? -> check
    
    % Specify Transfer Function of Servo
    TF.Servo1_Numerator_Coefs = [746.4];
    TF.Servo1_Denominator_Coefs = [1 75.77 3591];
    TF.Servo2_Numerator_Coefs = TF.Servo1_Numerator_Coefs;
    TF.Servo2_Denominator_Coefs = TF.Servo1_Denominator_Coefs;
    TF.Servo3_Numerator_Coefs = TF.Servo1_Numerator_Coefs;
    TF.Servo3_Denominator_Coefs = TF.Servo1_Denominator_Coefs;
    TF.Servo4_Numerator_Coefs = TF.Servo1_Numerator_Coefs;
    TF.Servo4_Denominator_Coefs = TF.Servo1_Denominator_Coefs;
    
    Servo.TF = TF;
    Servo.PWM = PWM;
    
end
% ------- EOF -------
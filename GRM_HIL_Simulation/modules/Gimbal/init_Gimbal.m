%% Inizialize Gimbal Emulator
%
%
% INPUT:
% emulate           [1]    [double] <1> if Gimbal should be simulated, <0> if real gimbal is used, <2> if Gimbal is used and controlled via HW interface Control Computer
% variant           [1]    [double] <1> for TF representation, <2> for physical simulation, <3> for Simscape representation
% 
% OUTPUT:
% HIL_Data.Gimbal   [1x*]  [struct]  Data struct containing all parameters needed for the Gimbal Emulation
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

function Gimbal = init_Gimbal (emulate,variant)
    
    %% Define Gimbal Variants
    assignin('base', 'VSS_GIMBAL_TF', Simulink.Variant('HIL_Data.Gimbal.Mode.VSS_Gimbal_MODE==1'));
    assignin('base', 'VSS_GIMBAL_PH', Simulink.Variant('HIL_Data.Gimbal.Mode.VSS_Gimbal_MODE==2'));
    assignin('base', 'VSS_GIMBAL_SC', Simulink.Variant('HIL_Data.Gimbal.Mode.VSS_Gimbal_MODE==3'));
    
    % for R2017a use this instead
    %assignin('base', 'VSS_GIMBAL_TF', Simulink.Variant('VSS_Gimbal_MODE==1'));
    %assignin('base', 'VSS_GIMBAL_PH', Simulink.Variant('VSS_Gimbal_MODE==2'));
    %assignin('base', 'VSS_GIMBAL_SC', Simulink.Variant('VSS_Gimbal_MODE==3'));
    
    if emulate == 1 && variant == 1
    %% Simulate Gimbal via Transfer Functions     
        
        %Choose Variant Subsystem
        Mode.VSS_Gimbal_MODE = 1;
        % for R2017a use this instead
        %assignin('base', 'VSS_Gimbal_MODE', 1);
        
        %Specify Transfer Functions 
        %(pure gimbal system, open loop under closed loop conditions, without controller)
        TF.Psi2Motor_to_Yaw.Num_Coef = [4.207 368.2];
        TF.Psi2Motor_to_Yaw.Denom_Coef = [1 18.62 365.1];
        TF.Theta2Motor_to_Yaw.Num_Coef = [0]; %Cross Coupling
        TF.Theta2Motor_to_Yaw.Denom_Coef = [1]; %Cross Coupling
        TF.Phi2Motor_to_Yaw.Num_Coef = [0]; %Cross Coupling
        TF.Phi2Motor_to_Yaw.Denom_Coef = [1]; %Cross Coupling
        TF.Psi2Motor_to_Pitch.Num_Coef = [0]; %Cross Coupling
        TF.Psi2Motor_to_Pitch.Denom_Coef = [1]; %Cross Coupling
        TF.Theta2Motor_to_Pitch.Num_Coef = [-0.1691 6.862 80.36 1063 -95.88];
        TF.Theta2Motor_to_Pitch.Denom_Coef = [1 26.16 229.7 1734 2366 1787];
        TF.Phi2Motor_to_Pitch.Num_Coef = [0]; %Cross Coupling
        TF.Phi2Motor_to_Pitch.Denom_Coef = [1]; %Cross Coupling
        TF.Psi2Motor_to_Roll.Num_Coef = [0]; %Cross Coupling
        TF.Psi2Motor_to_Roll.Denom_Coef = [1]; %Cross Coupling
        TF.Theta2Motor_to_Roll.Num_Coef = [0]; %Cross Coupling
        TF.Theta2Motor_to_Roll.Denom_Coef = [1]; %Cross Coupling
        TF.Phi2Motor_to_Roll.Num_Coef = [-0.3003 128.8 6.16];
        TF.Phi2Motor_to_Roll.Denom_Coef = [1 12.34 201.8 184.5];
    
        Gimbal.TF = TF;
    
        
    elseif emulate == 1 && variant == 2
    %% Simulate Gimbal via Physical Representation
        
        
        %Choose Variant Subsystem
        Mode.VSS_Gimbal_MODE = 2;
        % for R2017a use this instead
        %assignin('base', 'VSS_Gimbal_MODE', 1);
        
        %Parameters
        PH.param1 = 0;
        
        
        
        
        %add to struct
        Gimbal.PH = PH;
        
    elseif emulate == 1 && variant == 3
    %% Simulate Gimbal via Simscape
        
        
        %Choose Variant Subsystem
        Mode.VSS_Gimbal_MODE = 3;
        % for R2017a use this instead
        %assignin('base', 'VSS_Gimbal_MODE', 3);
        
        %Parameters
        SC.param1 = 0;
        
        
        
        
        %add to struct
        Gimbal.SC = SC;
        
       
    elseif emulate == 2
    %% Control Gimbal via HW interface Control Computer
        
        %Frequency of communication with HWI CC
        HW.SampTime = 1/1000;
        %FTHWICC.SampTime = HIL_Sample_Time; %TBD!!
        HW.MaxMissTick = 10;
        
        %Specify directly in Library block!!!
        %FTHWICC.Port = 36864;
        %FTHWICC.RemoteIP = '192.168.1.156';
        %FTHWICC.RemotePort = 36880;
        
        Mode = -1; % not needed for that one
        Gimbal.HW = HW;
        
    else
    %% Use real Gimbal     
        
        HW.SampTime = 1/1000;
        HW.MaxMissTick = 10;
        
        
        
        
        Mode = -1; % not needed for that one
        Gimbal.HW = HW;
        
    end
    
    
    
    
    % add to struct
    Gimbal.Mode = Mode; %leave this out for R2017a
    
    
end
% ------- EOF -------
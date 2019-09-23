%% Flight Dynamic Model
%
%
% INPUT:
% variant        [1]    [double] <1> for Basic Version, <2> for Student Version, <3> for Sophisticated Version
%
%
% OUTPUT:
% HIL_Data.FDM   [1x*]  [struct]  Data struct containing all parameters needed for the flight dynamics model
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

function FDM = init_FDM (variant)
    
    %% Specify Configuration and Aerodynamic Values
    % --> explenation!!

    Configuration_Data.d_m = 0.09;
    Configuration_Data.S_ref_m2 = 0.0064;
    Configuration_Data.MAC_m = 0.05;
    Configuration_Data.mass_kg = 4.171;
    Configuration_Data.mass_preburn_kg = 4.19; %tbd
    Configuration_Data.I_x_kgDm2 = 0.0037;
    Configuration_Data.I_y_kgDm2 = 0.4319;
    Configuration_Data.I_z_kgDm2 = 0.4319;
    Configuration_Data.I_x_preburn_kgDm2 = 0.0042;
    Configuration_Data.I_y_preburn_kgDm2 = 0.4319; %tbd
    Configuration_Data.I_z_preburn_kgDm2 = 0.4319; %tbd
    
    Configuration_Data.Propulsion.burntime_s = 3.5;
    Configuration_Data.Propulsion.thrust_avg_N = 455;
    
    Aero_Data.C_l_delta = 3.9123;
    Aero_Data.C_l_p = -18.3840;
    Aero_Data.C_z_alpha = -28.2919;
    Aero_Data.C_z_delta = 4.4436;
    Aero_Data.C_m_alpha = -31.5283;
    Aero_Data.C_m_delta = 18.4916;
    Aero_Data.C_m_q = -380.077;
    Aero_Data.C_y_beta = -28.2919;
    Aero_Data.C_y_delta = -4.4436;
    Aero_Data.C_n_beta = -31.5283;
    Aero_Data.C_n_delta = 18.4916;
    Aero_Data.C_n_r = -380.077;
    
    Environment_Data.gravity_mDs2 = 9.81;
    
    
    %% Define FDM Variants
    assignin('base', 'VSS_FDM_LIN', Simulink.Variant('HIL_Data.FDM.Mode.VSS_FDM_MODE==1'));
    assignin('base', 'VSS_FDM_BASIC', Simulink.Variant('HIL_Data.FDM.Mode.VSS_FDM_MODE==2'));
    assignin('base', 'VSS_FDM_STUD', Simulink.Variant('HIL_Data.FDM.Mode.VSS_FDM_MODE==3'));
    assignin('base', 'VSS_FDM_SOPH', Simulink.Variant('HIL_Data.FDM.Mode.VSS_FDM_MODE==4'));
    
    % for R2017a use this instead
    %assignin('base', 'VSS_FDM_BASIC', Simulink.Variant('VSS_FDM_MODE==1'));
    %assignin('base', 'VSS_FDM_STUD', Simulink.Variant('VSS_FDM_MODE==2'));
    %assignin('base', 'VSS_FDM_SOPH', Simulink.Variant('VSS_FDM_MODE==3'));
    
    if variant == 1
    %% FDM Lin    
        
        % Choose Variant Subsystem
        Mode.VSS_FDM_MODE = 1;
        
        
        % Specify Complexity
        %Basic.enable_propulsion_flg = 0;
        %Basic.enable_drag_flg = 0;
        %Basic.enable_gravity_flg = 0;
        % -> moved to simulation control
        
        
        % Parameters
        Lin.param1 = -1;
        
        
        
        % Specify Static Flight State
        Flight_State.alt_m = 1000;
        Flight_State.vel_mDs = 80;
        Flight_State.mach = 0.15;
        Flight_State.rho_kgDm3 = 1.225;
        Flight_State.q_kgDms2 = 1/2*Flight_State.rho_kgDm3*Flight_State.vel_mDs; %dynamic pressure
        
        % Transfer Functions
        [TF.dr2roll, TF.dp2pitch, TF.dy2yaw, TF.pitch2az, TF.dp2az, TF.yaw2ay, TF.dy2ay] = computeTF(Configuration_Data,Aero_Data,Flight_State);
        
        % Add to struct
        FDM.Lin = Lin;
        FDM.Lin.FS = Flight_State;
        FDM.Lin.TF = TF;
        
        
        
    elseif variant == 2
    %% FDM BASIC
        
        % Choose Variant Subsystem
        Mode.VSS_FDM_MODE = 2;
        
        
        % Parameters
        Basic.param1 = -1;
              
        
        
        
        % Add to struct
        FDM.Basic = Basic;
    
    elseif variant == 3
    %% FDM Students 
        
        % Choose Variant Subsystem
        Mode.VSS_FDM_MODE = 3;
        % for R2017a use this instead
        %assignin('base', 'VSS_FDM_MODE', 2);
        
        % Parameters
        Students.param1 = 0;
        
        
        % Add to struct
        FDM.Students = Students;
        
    elseif variant == 4
    %% FDM Sophisticated
        
        % Choose Variant Subsystem
        Mode.VSS_FDM_MODE = 4;
        % for R2017a use this instead
        %assignin('base', 'VSS_FDM_MODE', 3);
        
        % Parameters
        Soph.param1 = 0;
        
        
        
        % Add to struct
        FDM.Soph = Soph;
        
        
    end
    
    
    
    % add to struct
    FDM.Mode = Mode; %leave this out for R2017a
    FDM.Configuration_Data = Configuration_Data;
    FDM.Aero_Data = Aero_Data;
    FDM.Environment_Data = Environment_Data;
    
end
% ------- EOF -------%% 
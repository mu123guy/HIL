%% Initialize Initial States for FDM
%
%
% INPUT:
%  --- 
%
%
% OUTPUT:
% HIL_Data.Initial_States    [1x*]  [struct]  Data struct containing all
%                                             parameters that specify the
%                                             initial state of the FDM
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

function Initial_States = init_Initial_States()
    
    %% Specify Rigid Body Initial States
    Transl.VEL_u_K_R_E_B_mDs = 0;
    Transl.VEL_v_K_R_E_B_mDs = 0;
    Transl.VEL_w_K_R_E_B_mDs = 0;
    
    Transl_Dot.ACC_x_B_mDs2 = 0;
    Transl_Dot.ACC_y_B_mDs2 = 0;
    Transl_Dot.ACC_z_B_mDs2 = 0;
    
    Rot.w_x_K_IB_B_radDs = 0;
    Rot.w_y_K_IB_B_radDs = 0;
    Rot.w_z_K_IB_B_radDs = 0;
    
    Att.ATT_Phi_rad = 0;
    Att.ATT_Theta_rad = 0;
    Att.ATT_Psi_rad = 0;
    
    Pos.POS_lambda_WGS84_rad = 0;
    Pos.POS_mue_WGS84_rad = 0;
    Pos.POS_h_WGS84_m = 0;
    Pos.POS_x_NED_m = 0;
    Pos.POS_y_NED_m = 0;
    Pos.POS_z_NED_m = 0;
    
    
    Rigid_Body.Transl = Transl;
    Rigid_Body.Transl_Dot = Transl_Dot;
    Rigid_Body.Rot = Rot;
    Rigid_Body.Att = Att;
    Rigid_Body.Pos = Pos;
    
    
    %% Specify Airframe Initial States
    Airframe.motor_state_perc = 0;
    Airframe.mass_kg = 4.171;
    
    
    
    %% Specify Atmosphere Initial States
    Atm.VEL_u_Wind_A_E_O_mDs = 0;
    Atm.VEL_v_Wind_A_E_O_mDs = 0;
    Atm.VEL_w_Wind_A_E_O_mDs = 0;
    
    
    
    %% Add to struct
    Initial_States.Rigid_Body = Rigid_Body;
    Initial_States.Airframe = Airframe;
    Initial_States.Atm = Atm;
    
end
% ------- EOF -------
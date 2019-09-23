%% Compute Transfer Functions for Basic FDM
%
%
% INPUT:
% config        [1x*]  [struct]  Configuration Values of Airframe
% aero          [1x*]  [struct]  Aerodynamic Constants
% state         [1x*]  [struct]  Constant Flight State
%
% OUTPUT:
% dr2roll   [1x2]  [struct]  Transfer function fin deflection to roll
% dp2pitch  [1x2]  [struct]  Transfer function fin deflection to pitch
% dy2yaw    [1x2]  [struct]  Transfer function fin deflection to yaw
% pitch2az  [1x2]  [struct]  Transfer function pitch to acc in z axis
% dp2az     [1x2]  [struct]  Transfer function fin deflection to acc in z axis
% yaw2ay    [1x2]  [struct]  Transfer function yaw to acc in y axis
% dy2ay     [1x2]  [struct]  Transfer function fin deflection to acc in y axis
% 
% DESCRIPTION:
%
%
% PROJECT:
% Guided Research Missile / Cornetto
%
% AUTHOR:
% Max Hiepp
%

function [dr2roll, dp2pitch, dy2yaw, pitch2az, dp2az, yaw2ay, dy2ay] = computeTF (config, aero, state)
    
    
    % dr2roll
    %dr2roll.num = [aero.C_l_delta];
    dr2roll.num = [3.9123];
    %dr2roll.denom = [config.I_x_kgDm2/(config.S_ref_m2*state.q_kgDms2*config.d_m) -config.d_m/(2*state.vel_mDs)*aero.C_l_p];
    dr2roll.denom = [0.0065 0.0147];
    
    %to shorten and simplify calculation
    
   
    s = config.S_ref_m2;
    d = config.d_m;
    m = config.mass_kg;
    i = config.I_y_kgDm2;
    q = state.q_kgDms2;
    u = state.vel_mDs;
    
    cza = aero.C_z_alpha;
    czd = aero.C_z_delta;
    cma = aero.C_m_alpha;
    cmd = aero.C_m_delta;
    cmq = aero.C_m_q;
    cyb = aero.C_y_beta;
    cyd = aero.C_y_delta;
    cnb = aero.C_n_beta;
    cnd = aero.C_n_delta;
    cnr = aero.C_n_r;
    
    a = s*q/(m*u);
    b = s*q*d/i;
    c = s*q*d^2/(2*u*i);
    a2 = s*q/m;
    
    
    
    % dp2pitch
    %dp2pitch.num = [b*cmd b*cma*a*czd-b*cmd*a*cza];
    dp2pitch.num = [96.0992 148.7807];
    %dp2pitch.denom = [1 -(c*cmq+a*cza) c*cmq*a*cza-b*cma];
    dp2pitch.denom = [1 3.2255 166.199];
    
    % pitch2az
    %pitch2az.num = [a2*czd -a2*czd*c*cmq b*cmd*a2*cza-b*cma*a2*czd];
    pitch2az.num = [26.5678 29.5185 -11902];
    %pitch2az.denom = [b*cmd b*cma*a*czd-b*cmd*a*cza];
    pitch2az.denom = [1 3.2255 166.199];
    
    
    % dy2yaw
    %dy2yaw.num = [b*cnd b*cnb*a*cyd-b*cnd*a*cyb];
    dy2yaw.num = [96.0992 148.7807];
    %dy2yaw.denom = [1 -(c*cnr+a*cyb) c*cnr*a*cyb-b*cnb];
    dy2yaw.denom = [1 3.2255 166.199];
    
    % dp2az
    dp2az.num = pitch2az.num;
    dp2az.denom = dp2pitch.denom;
    
    % yaw2ay
    %yaw2ay.num = [a2*cyd -a2*cyd*c*cnr b*cnd*a2*cyb-b*cnb*a2*cyd];
    yaw2ay.num = [-26.5678 -29.5185 -11902];
    %yaw2ay.denom = [b*cnd b*cnb*a*cyd-b*cnd*a*cyb];
    yaw2ay.denom = [1 3.2255 166.199];
    
    % dy2ay
    dy2ay.num = yaw2ay.num;
    dy2ay.denom = dy2yaw.denom;
    
end
% ------- EOF -------%% 
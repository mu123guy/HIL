%% Initialize Control Surfaces
%
%
% INPUT:
%  ---
%
%
% OUTPUT:
% HIL_Data.Control_Surfaces   [1x*]  [struct]  Data struct containing all parameters needed for the module to compute the fin deflections
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

function Control_Surfaces = init_Control_Surfaces ()
    
    % position of fins on Body
    % must be according to definition!!!
    Control_Surfaces.phi_f1_rad = -pi/2;
    Control_Surfaces.phi_f2_rad = pi/2;
    Control_Surfaces.phi_f3_rad = 3*pi/2;
    Control_Surfaces.phi_f4_rad = -3*pi/2;
    
    % maximum possible defelction of fin
    Control_Surfaces.max_deflection_rad = 20*(2*pi/360);
    
    
    
end
% ------- EOF -------
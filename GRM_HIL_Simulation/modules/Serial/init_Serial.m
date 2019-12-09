%% Initialize Serial Communication Interfaces
%
%
% INPUT:
% external_flg                      [bool]    run sim in external mode indication
%
%
% OUTPUT:
% HIL_Data.Serial   [1x*]  [struct]  Data struct containing all parameters needed for the Serial Communication within the distributed simulation
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

function Serial = init_Serial (external_flg)
    
    %% Set up Serial Com to Pixhawk
    
    % manually select the COM Port within the Model!!!
    
    Pix.param1 = -1;
    
    %Pix.Receive.SampTime = HIL_Sample_Time; %??!
    
    
    %if external_flg
    % specification for external mode connection
    
        % specify comport/baudrate/ect directly in library block!!!
        
        
        Pix.Send.MaxMissedTicks = 10;
        Pix.Receive.MaxMissedTicks = 10;
        
        
    %end
    
    % Specify Sample Time in Serial Recieve Block!!!
    
    
    
    %% Add to struct
    Serial.Pix = Pix;
    
end
% ------- EOF -------
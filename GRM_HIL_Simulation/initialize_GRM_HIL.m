%% Hardware in the Loop Simulation Initialization Script
%
%
% INPUT:
%  ---
%
%
% OUTPUT:
% HIL_Data   [1x*]  [struct]  Data struct containing all parameters needed for the HIL simulation
%
%
%
% DESCRIPTION:
% This script sets the overall paramters and initiates the initialization
% of the bus objects and all submodules needed for the HIL simulation
%
%
% PROJECT:
% Guided Research Missile / Cornetto
%
%
% AUTHOR:
% Max Hiepp
%

%% Toggle Command Line Output
enable_output = 1;
if(enable_output) disp([newline 'INITIALIZE GRM HARDWARE IN THE LOOP SIMULATION ENVIRONMENT' newline]), end

%% Specify Simulation Parameters

% run simulation in real time
enable_realtime = 1; % <1> if simulation should run in realtime, <0> if not

% run simulation in external mode
enable_external_mode = 1; % <1> for external mode, <0> for normal mode

% Specify if the following components are used in hardware or should be simulated
% <0> if real HW is used, <1> if HW should be simulated
Emulate_FCC      = 1;
Emulate_Servos   = 1;
Emulate_Gimbal   = 1; % <2> if Gimbal is used and controlled via HW interface Control Computer



% Specify Variant of module to use
Gimbal_Variant = 1;      % <1> for simulation via Transfer Functions
                         % <2> for physical simulation
                         % <3> for Simscape model
FDM_Variant = 1;         % <1> Linear Version
                         % <2> Basic Version
                         % <3> Student Version
                         % <4> Sophisticated Version

% pack to Cell Array
Modules = {'Module', 'Emulate/Real'; ...
           'Flight Control Computer', Emulate_FCC; ...
           'Servos', Emulate_Servos; ...
           'Gimbal', Emulate_Gimbal};

%% Display Specifications
if(enable_output) 
    disp(['Initialization Specifications:' ])
    if(enable_realtime) disp(['  - Run Simulation in Realtime' ]), end
    if(Modules{2,2} && Modules{3,2} && Modules{4,2}) disp(['  - Run Simulation offline' ]), end
    if(enable_external_mode) disp(['  - Run Simulation in External Mode' ]), else disp(['  - Run Simulation in Normal Mode' ]), end
    if(Emulate_FCC) disp(['  - Emulate FCC' ]), else disp(['  - Use FCC Hardware' ]), end
    if(Emulate_Servos) disp(['  - Emulate Servos' ]), else disp(['  - Use Servo Hardware' ]), end
    if(Emulate_Gimbal == 1) disp(['  - Emulate Flight Table' ]), elseif(Emulate_Gimbal == 2) disp(['  - Use Flight Table via HW Interface Control Computer' ]), else disp(['  - Use Flight Table' ]), end
    %include variants??
end

%% Specify Connection Communication Data
    
    %TBD - specify here instead of subscripts
    
    %also specify the rate of the communictaions!!! instead of sim ctrl
    
%% Com Checks!!

% TBD

% add disp


    
%% Set global sample time [s]

% ???
if exist('HIL_Sample_Time','var')
    if(enable_output) disp(['inherit HIL sample frequency (' num2str(1/HIL_Sample_Time) 'Hz)' ]), end
else
    HIL_Sample_Time = 0.01; % -> tbd
    if(enable_output) disp(['setting HIL sample frequency to ' num2str(1/HIL_Sample_Time) 'Hz ...' ]), end
end


%% Set FCC sample time

FCC_Sample_Time = 0.01; % only effective if FCC is emulated
% specify rest of FCC Emulation Parameters in Simulation Control Script!!
if(Emulate_FCC) && (enable_output)  
    disp(['setting FCC sample frequency to ' num2str(1/FCC_Sample_Time) 'Hz ...' ]) 
end   
    
%% Add paths to the Current Directory

if(enable_output) disp(['adding relevant folders to path ...' ]), end
addpath(genpath([pwd,'\function_scripts']));
addpath(genpath([pwd,'\modules']));


%% Initialize Simulation Control

if(enable_output) disp(['initialize simulation control ...' ]), end
HIL_Data.Simulation_Ctrl = init_Simulation_Ctrl(enable_realtime,enable_external_mode,Modules);
% add addidtional data
HIL_Data.Simulation_Ctrl.Modules = Modules;
HIL_Data.Simulation_Ctrl.FCC_Ctrl.FCC_Sample_Time = FCC_Sample_Time; 


%% Initialize FDM Inputs

if(enable_output) disp(['initialize inputs ...' ]), end
HIL_Data.Initial_States = init_Initial_States;
HIL_Data.External_Inputs = init_External_Inputs;


%% Load Busses

if(enable_output) disp(['create bus objects ...' ]), end
init_buses;


%% Initialize Submodules

if(enable_output) disp(['Initialize Submodules' ]), end
% Flight Dynamics Model
if(enable_output) disp(['  - initialize FDM ...' ]), end
HIL_Data.FDM = init_FDM(FDM_Variant);
%HIL_Data.INS_GPS = init_IMU_GPS_Emulator;

% FCC
if(enable_output) disp(['  - initialize FCC ...' ]), end
HIL_Data.Flight_Controller = init_Flight_Controller(FCC_Sample_Time);
HIL_Data.Control_Surfaces = init_Control_Surfaces;

% Actuators
if(enable_output) disp(['  - initialize Actuators ...' ]), end
HIL_Data.Servo = init_Servo;
%HIL_Data.Encoder = init_Encoder;

% Gimbal
if(enable_output) disp(['  - initialize Flight Table ...' ]), end
HIL_Data.Gimbal_Cmd = init_Gimbal_Cmd;
HIL_Data.Gimbal_Ctrl = init_Gimbal_Ctrl;
HIL_Data.Gimbal = init_Gimbal(Modules{4,2},Gimbal_Variant);

% Serial Communication
if(enable_output) disp(['  - initialize Serial Communication ...' ]), end
HIL_Data.Serial = init_Serial(enable_external_mode);



%% Initialize Inputs


if(enable_output) disp(['All Modules Succesfully Initialized' ]), end

%% Clear Temporary Variables

if(enable_output) disp(['clear temporary variables ...' ]), end
clear enable_realtime;
clear enable_external_mode;
clear Emulate_FCC;
clear Emulate_Servos;
clear Emulate_Gimbal;
clear Gimbal_Emul_Version;
clear Modules;
clear FCC_Sample_Time;
clear Gimbal_Variant;
clear FDM_Variant;

if(enable_output) disp([newline 'HIL ENVIRONMENT SUCCESSFULLY INITIALIZED' newline]), end
if(enable_output) disp(['READY FOR HIL SIMULATION' newline]), end
clear enable_output;
% ------- EOF -------

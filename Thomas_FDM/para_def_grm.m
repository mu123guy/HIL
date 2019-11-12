%% Defines the parameters of the GRM Simulink model
%
%
% SUMMARY:
% Defines the parameters of the subsystems of the Guided Research Missile
% Airframe model. Loads two .mat-files.
%
% DESCRIPTION:
% Defines the parameters of the subsystems of the Guided Research Missile
% Airframe model. Loads two .mat-files containing the thrust of the solid
% fuel rocket motor over time and the massflow over time.
%
% DEPENDENCIES:
% d_mB.mat
% aero.mat
%
% PROJECT:
% *** LOW COST MISSILE TESTBED ***
%
% RESOURCES:
% Modeling and Simulation of the Guided Research Missile, Lausenhammer
% Thomas; Semester Thesis, Technical University Munich, 2018
%
% CHANGE DIRECTORY
% Date          Name                    Description         Version
% 2018/11/12    Lausenhammer, Thomas    initial version     V 1.0
% 2019/05/07    Lausenhammer, Thomas    changed Header      V 1.1
% 2019/05/07    Lausenhammer, Thomas    added comments      V 1.2
% 2019/11/12    Lausenhammer, Thomas    added Wind          V 1.3
%                                       uncertainty   
%
%
%%  Load Parameters
%%  Propulsion
%Time and thrust data for Propulstion look-up table
t_prp1 = [0.04;0.28;0.54;1;1.48;1.99;2.51;3;3.5;3.67;3.82;4];   %[s] TImestamps for Thrust over time
F_prp = [450.52;428.7;423.25;391.61;352.34;304.35;266.17;243.26;216.92;
    126.54;64.36;0];  %[N] Thrust over time
load('d_mB.mat');           % Look-Up Table Data mass flow over time [kg/s]
t_prp2 = 0:0.25:4;          %[s] Timestamps for Massflow over time
t_prp2 = t_prp2';
pNPB = [0;0;0];             %[m] position vector of the noozle

%%  Weight and Balance

m_fuel_lookup = [0;0.0573;0.1127;0.1667;0.2186;0.2681;0.3149;0.3588;
    0.3996;0.4378;0.4736;0.5074;0.5397;0.5704;0.5994;0.619;0.625];  % Look-Up Table Data used propelland mass over time [kg]

de_mM =  m_fuel_lookup(end);    % structural mass motor [kg]
mB_0 = 3.30977;             % Missile structure mass without motor [kg]
m0 = mB_0;
mM_0 = 1.119;               % motor mass full [kg]
mB_e = mB_0 + de_mM;        % Missile mass after motor burn out [kg]
mM_e = de_mM;

x0PB = -0.5;                % x-position Missile center of gravity [m]
xMPB = -0.9;                % x-position motor center of gravity [m]
y0PB = 0;                   % y-position Missile center of gravity [m]
yMPB = 0;                   % y-position motor center of gravity [m]
z0PB = 0;                   % z-position Missile center of gravity [m]
zMPB = 0;                   % z-position motor center of gravity [m]
pMPB = [xMPB;yMPB;zMPB];    %[m] position vector motor center of gravity
p0PB = [x0PB;y0PB;z0PB];    %[m] position vector missile structure center of gravity

% Moment of inertia tensor is defined in a coordinate system that is 45°
% rotated around the body fixed x-axis.
kg2g = 1e3;                 %[-] COnversion factor from kg to g
m22mm2 = 1e6;               %[m] Conversion factor from m^2 to mm^2
% [
J0PP_0 = [4205678.86, -14068.58, 14084.08;-14068.58,2563420799.30,-598.13;14084.08,-598.13,2563420799.30]/kg2g/m22mm2;
J0PP_e = [3713581.64,-14068.58,14084.08;-14068.58,1367885705.36,-598.13;14084.08,-598.13,1367885705.36]/kg2g/m22mm2;
tmp_al = pi/4;
TBP = [1,0,0;0,cos(tmp_al),sin(tmp_al);0,-sin(tmp_al),cos(tmp_al)];
J0PB_0 = TBP*J0PP_0*TBP';
J0PB_e = TBP*J0PP_e*TBP';

JMMM_0 = TBP*J0PP_0*TBP';
JMMM_e = TBP*J0PP_e*TBP';

% Values for calculating
JBBB_xx_0 = 0.125;
JBBB_xx_e = 0.125;
JBBB_yy_0 = 0.125;
JBBB_yy_e = 0.125;
JBBB_zz_0 = 0.125;
JBBB_zz_e = 0.125;

de_JBBB_xx = JBBB_xx_0 - JBBB_xx_e;
de_JBBB_yy = JBBB_yy_0 - JBBB_yy_e;
de_JBBB_zz = JBBB_zz_0 - JBBB_zz_e;

%%  Fins and Fin actuators
% position, velocity and acceleration limitations of the 2nd order actuator
% system
siB_max = deg2rad(30);              %[rad]
siB_min = deg2rad(-30);             %[rad]
d_siB_min = deg2rad(-1200);         %[rad/S]
d_siB_max = deg2rad(1200);          %[rad/s]
dd_siB_min = deg2rad(-50000);       %[rad/s^2]
dd_siB_max = deg2rad(50000);        %[rad/s^2]

act_omega = 59.9250;                %[rad/s] Sys-ID Technion
act_dmp = 0.6322;                   %[-] damping Sys-ID Technion
unc_act_bl = 0;                     %[rad] bias error
unc_act_scale = 1;                  %[-] scale factor error
unc_act_off = 0;                    %[rad] actuator offset
siB_0 = 0;                          %[rad] initial value
d_siB_0 = 0;                        %[rad/s] initial value
tRRR = 0;
Tr4r3 = [1,1,-1;1,1,1;1,-1,1;1,-1,-1];  % Control allocation matrix
Tr3r4 = [1,1,1,1;1,1,-1,-1;-1,1,1,-1]*0.25; %pseudo-inverse Control allocation matrix

%%  Sensors
%%  IMU
% IMU-Accelerometer
%settings for IMU time step, update rate and time offset have to be in
%compliance with the simulation time step
imu_dt = 0.001;             %[s] IMU time step
imu_UpdateRate = 100;       %[Hz] IMU Update rate
imu_delay = 0.001;         %[s] IMU time offset
imu_seed = 0;            %[-] initialization value for random number generator (either zero or positive integer)
imu_a_limits = [16*9.81];     %[m/s^2] accelerometer saturation
imu_a_sigmanoise = zeros(3,1);       %[m/sqrt(s)] white sensor noise
imu_a_quantization = 0.001; %[m/s^2] Quantization
imu_a_bias_static = zeros(3,1);    %[m/s^2] static acc-imu bias
imu_a_bias_randomwalk = zeros(3,1);   %[m/s^2] standard deviation in run stability
imu_a_bias_timeconstant = 1;         %[s] dynamic in run stability
imu_a_omega = zeros(3,1);            %[rad/s] acc-imu dynamic frequency
imu_a_damping = zeros(3,1);          %[-] damping
imu_a_ScaleFactor = zeros(3,1);      %[ppm] linear scale factor acc
imu_a_ScaleFactorN = zeros(3,1);     %[ppm] quadratic scale factor acc
imu_a_ScaleFactorA = zeros(3,1);     %[ppm] absolute scale factor acc
imu_a_misalignment = zeros(3,1);     %[rad] misalignment
imu_a_nonorthogonality = zeros(3,1); %[rad] deviation from ideal orthogonal projection
imu_a_CrossCoupling = zeros(3,1);    %[-] cross coupling
% IMU-Gyroscope
imu_w_limits = [100];         %[rad/s] gyroscope saturation
imu_w_sigmanoise = zeros(3,1);       %[rad/sqrt(s)] gyroscope white sensor noise
imu_w_quantization = 0.001; %[rad/s] quantization gyroscope
imu_w_bias_static = zeros(3,1);      %[rad/s] static bias gyroscope
imu_w_bias_randomwalk = zeros(3,1);  %[rad/s] standard deviation in run stability
imu_w_bias_timeconstant = 1;        %[s] dynamic in run stability
imu_w_bias_AccelerationEffect = zeros(3,3);  %[rad*s/m] ruck effect
imu_w_omega = zeros(3,1);          %[rad/s] Imu dynamic frequency
imu_w_damping = zeros(3,1);          %[-] damping
imu_w_ScaleFactor = zeros(3,1);      %[ppm] linear scale factor error
imu_w_ScaleFactorN = zeros(3,1);     %[ppm] quadratic scale factor error
imu_w_ScaleFactorA = zeros(3,1);     %[ppm] norm scale factor error
imu_w_misalignment = zeros(3,1);     %[rad] misalignment
imu_w_nonorthogonality = zeros(3,1); %[rad] deviation from ideal orthogonal projection
imu_w_CrossCoupling = zeros(3,1);    %[-] cross coupling

TUB = [1,0,0;0,1,0;0,0,1];          %IMU rotation Transformation matrix
pUPB = [0;0;0];                     %[m] IMU position from the reference point

TU1B = [1,0,0;0,1,0;0,0,1];          %IMU rotation Transformation matrix
pU1PB = [0;0;0];                     %[m] IMU position from the reference point

TU2B = [1,0,0;0,1,0;0,0,1];          %IMU rotation Transformation matrix
TBU2 = TU2B';
pU2PB = [-0.2;0.08;0.08];            %[m] IMU position from the reference point

%%  Aerodynamics

aero = load('aero.mat');             % load Aerodynamics data struct

%%  Controller

t_sample_contr = 0.001;

%%  Implemented uncertainties:

%   Wind uncertainties
unc_a_vBEW_bl = 0;          %   [m/s] Bias uncertainty absolute value wind velocity
unc_chW_bl = 0;                %   [rad] Bias uncertainty course angle wind


unc_fin_def_roll =          0;
unc_fin_def_pitch =         0;
unc_fin_def_yaw =           0;

%  Weight and Balance
unc_cg_x = 0;
unc_cg_y = 0;
unc_cg_z = 0;

unc_moi_Jxx = 0;
unc_moi_Jyy = 0;
unc_moi_Jzz = 0;
unc_mB_bl = 0;
unc_mB_scale = 1;

%   Propulsion
unc_prp_z = 0;
unc_prp_y = 0;
unc_prp_x = 0;
unc_prp_scale = 1;

%   Aerodynamic coefficients
unc_aero_Cx_scale = 1;
unc_aero_Cy_scale = 1;
unc_aero_Cz_scale = 1;
unc_aero_Cl_scale = 1;
unc_aero_Cm_scale = 1;
unc_aero_Cn_scale = 1;

%   Actuator Failure
unc_act_fail_flag_1 = 1;
unc_act_fail_position_1 = 0;
unc_act_fail_flag_2 = 1;
unc_act_fail_position_2 = 0;
unc_act_fail_flag_3 = 1;
unc_act_fail_position_3 = 0;
unc_act_fail_flag_4 = 1;
unc_act_fail_position_4 = 0;
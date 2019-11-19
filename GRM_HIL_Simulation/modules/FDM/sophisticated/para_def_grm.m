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
% PROJECT::
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

function bus1 = para_def_grm()
    %%  Load Parameters
    %%  Propulsion
    %Time and thrust data for Propulstion look-up table
    bus1.t_prp1 = [0.04;0.28;0.54;1;1.48;1.99;2.51;3;3.5;3.67;3.82;4];   %[s] TImestamps for Thrust over time
    bus1.F_prp = [450.52;428.7;423.25;391.61;352.34;304.35;266.17;243.26;216.92;
        126.54;64.36;0];  %[N] Thrust over time
    bus1.d_mB = load('d_mB.mat');           % Look-Up Table Data mass flow over time [kg/s]
    bus1.t_prp2 = 0:0.25:4;          %[s] Timestamps for Massflow over time
    bus1.t_prp2 = (bus1.t_prp2)';
    bus1.pNPB = [0;0;0];             %[m] position vector of the noozle

    %%  Weight and Balance

    bus1.m_fuel_lookup = [0;0.0573;0.1127;0.1667;0.2186;0.2681;0.3149;0.3588;
        0.3996;0.4378;0.4736;0.5074;0.5397;0.5704;0.5994;0.619;0.625];  % Look-Up Table Data used propelland mass over time [kg]

    bus1.de_mM =  bus1.m_fuel_lookup(end);    % structural mass motor [kg]
    bus1.mB_0 = 3.30977;             % Missile structure mass without motor [kg]
    bus1.m0 = bus1.mB_0;
    bus1.mM_0 = 1.119;               % motor mass full [kg]
    bus1.mB_e = bus1.mB_0 + bus1.de_mM;        % Missile mass after motor burn out [kg]
    bus1.mM_e = bus1.de_mM;

    bus1.x0PB = -0.5;                % x-position Missile center of gravity [m]
    bus1.xMPB = -0.9;                % x-position motor center of gravity [m]
    bus1.y0PB = 0;                   % y-position Missile center of gravity [m]
    bus1.yMPB = 0;                   % y-position motor center of gravity [m]
    bus1.z0PB = 0;                   % z-position Missile center of gravity [m]
    bus1.zMPB = 0;                   % z-position motor center of gravity [m]
    bus1.pMPB = [bus1.xMPB;bus1.yMPB;bus1.zMPB];    %[m] position vector motor center of gravity
    bus1.p0PB = [bus1.x0PB;bus1.y0PB;bus1.z0PB];    %[m] position vector missile structure center of gravity

    % Moment of inertia tensor is defined in a coordinate system that is 45?
    % rotated around the body fixed x-axis.
    bus1.kg2g = 1e3;                 %[-] COnversion factor from kg to g
    bus1.m22mm2 = 1e6;               %[m] Conversion factor from m^2 to mm^2
    % [
    bus1.J0PP_0 = [4205678.86, -14068.58, 14084.08;-14068.58,2563420799.30,-598.13;14084.08,-598.13,2563420799.30]/bus1.kg2g/bus1.m22mm2;
    bus1.J0PP_e = [3713581.64,-14068.58,14084.08;-14068.58,1367885705.36,-598.13;14084.08,-598.13,1367885705.36]/bus1.kg2g/bus1.m22mm2;
    bus1.tmp_al = pi/4;
    bus1.TBP = [1,0,0;0,cos(bus1.tmp_al),sin(bus1.tmp_al);0,-sin(bus1.tmp_al),cos(bus1.tmp_al)];
    bus1.J0PB_0 = bus1.TBP*bus1.J0PP_0*(bus1.TBP)';
    bus1.J0PB_e = bus1.TBP*bus1.J0PP_e*(bus1.TBP)';

    bus1.JMMM_0 = bus1.TBP*bus1.J0PP_0*(bus1.TBP)';
    bus1.JMMM_e = bus1.TBP*bus1.J0PP_e*(bus1.TBP)';

    % Values for calculating
    bus1.JBBB_xx_0 = 0.125;
    bus1.JBBB_xx_e = 0.125;
    bus1.JBBB_yy_0 = 0.125;
    bus1.JBBB_yy_e = 0.125;
    bus1.JBBB_zz_0 = 0.125;
    bus1.JBBB_zz_e = 0.125;

    bus1.de_JBBB_xx = bus1.JBBB_xx_0 - bus1.JBBB_xx_e;
    bus1.de_JBBB_yy = bus1.JBBB_yy_0 - bus1.JBBB_yy_e;
    bus1.de_JBBB_zz = bus1.JBBB_zz_0 - bus1.JBBB_zz_e;

    %%  Fins and Fin actuators
    % position, velocity and acceleration limitations of the 2nd order actuator
    % system
    bus1.siB_max = deg2rad(30);              %[rad]
    bus1.siB_min = deg2rad(-30);             %[rad]
    bus1.d_siB_min = deg2rad(-1200);         %[rad/S]
    bus1.d_siB_max = deg2rad(1200);          %[rad/s]
    bus1.dd_siB_min = deg2rad(-50000);       %[rad/s^2]
    bus1.dd_siB_max = deg2rad(50000);        %[rad/s^2]

    bus1.act_omega = 59.9250;                %[rad/s] Sys-ID Technion
    bus1.act_dmp = 0.6322;                   %[-] damping Sys-ID Technion
    bus1.unc_act_bl = 0;                     %[rad] bias error
    bus1.unc_act_scale = 1;                  %[-] scale factor error
    bus1.unc_act_off = 0;                    %[rad] actuator offset
    bus1.siB_0 = 0;                          %[rad] initial value
    bus1.d_siB_0 = 0;                        %[rad/s] initial value
    bus1.tRRR = 0;
    bus1.Tr4r3 = [1,1,-1;1,1,1;1,-1,1;1,-1,-1];  % Control allocation matrix
    bus1.Tr3r4 = [1,1,1,1;1,1,-1,-1;-1,1,1,-1]*0.25; %pseudo-inverse Control allocation matrix

    %%  Sensors
    %%  IMU
    % IMU-Accelerometer
    %settings for IMU time step, update rate and time offset have to be in
    %compliance with the simulation time step
    bus1.imu_dt = 0.001;             %[s] IMU time step
    bus1.imu_UpdateRate = 100;       %[Hz] IMU Update rate
    bus1.imu_delay = 0.001;         %[s] IMU time offset
    bus1.imu_seed = 0;            %[-] initialization value for random number generator (either zero or positive integer)
    bus1.imu_a_limits = [16*9.81];     %[m/s^2] accelerometer saturation
    bus1.imu_a_sigmanoise = zeros(3,1);       %[m/sqrt(s)] white sensor noise
    bus1.imu_a_quantization = 0.001; %[m/s^2] Quantization
    bus1.imu_a_bias_static = zeros(3,1);    %[m/s^2] static acc-imu bias
    bus1.imu_a_bias_randomwalk = zeros(3,1);   %[m/s^2] standard deviation in run stability
    bus1.imu_a_bias_timeconstant = 1;         %[s] dynamic in run stability
    bus1.imu_a_omega = zeros(3,1);            %[rad/s] acc-imu dynamic frequency
    bus1.imu_a_damping = zeros(3,1);          %[-] damping
    bus1.imu_a_ScaleFactor = zeros(3,1);      %[ppm] linear scale factor acc
    bus1.imu_a_ScaleFactorN = zeros(3,1);     %[ppm] quadratic scale factor acc
    bus1.imu_a_ScaleFactorA = zeros(3,1);     %[ppm] absolute scale factor acc
    bus1.imu_a_misalignment = zeros(3,1);     %[rad] misalignment
    bus1.imu_a_nonorthogonality = zeros(3,1); %[rad] deviation from ideal orthogonal projection
    bus1.imu_a_CrossCoupling = zeros(3,1);    %[-] cross coupling
    % IMU-Gyroscope
    bus1.imu_w_limits = [100];         %[rad/s] gyroscope saturation
    bus1.imu_w_sigmanoise = zeros(3,1);       %[rad/sqrt(s)] gyroscope white sensor noise
    bus1.imu_w_quantization = 0.001; %[rad/s] quantization gyroscope
    bus1.imu_w_bias_static = zeros(3,1);      %[rad/s] static bias gyroscope
    bus1.imu_w_bias_randomwalk = zeros(3,1);  %[rad/s] standard deviation in run stability
    bus1.imu_w_bias_timeconstant = 1;        %[s] dynamic in run stability
    bus1.imu_w_bias_AccelerationEffect = zeros(3,3);  %[rad*s/m] ruck effect
    bus1.imu_w_omega = zeros(3,1);          %[rad/s] Imu dynamic frequency
    bus1.imu_w_damping = zeros(3,1);          %[-] damping
    bus1.imu_w_ScaleFactor = zeros(3,1);      %[ppm] linear scale factor error
    bus1.imu_w_ScaleFactorN = zeros(3,1);     %[ppm] quadratic scale factor error
    bus1.imu_w_ScaleFactorA = zeros(3,1);     %[ppm] norm scale factor error
    bus1.imu_w_misalignment = zeros(3,1);     %[rad] misalignment
    bus1.imu_w_nonorthogonality = zeros(3,1); %[rad] deviation from ideal orthogonal projection
    bus1.imu_w_CrossCoupling = zeros(3,1);    %[-] cross coupling

    bus1.TUB = [1,0,0;0,1,0;0,0,1];          %IMU rotation Transformation matrix
    bus1.pUPB = [0;0;0];                     %[m] IMU position from the reference point

    bus1.TU1B = [1,0,0;0,1,0;0,0,1];          %IMU rotation Transformation matrix
    bus1.pU1PB = [0;0;0];                     %[m] IMU position from the reference point

    bus1.TU2B = [1,0,0;0,1,0;0,0,1];          %IMU rotation Transformation matrix
    bus1.TBU2 = (bus1.TU2B)';
    bus1.pU2PB = [-0.2;0.08;0.08];            %[m] IMU position from the reference point

    %%  Aerodynamics

    bus1.aero = load('aero.mat');             % load Aerodynamics data struct

    %%  Controller

    bus1.t_sample_contr = 0.001;

    %%  Implemented uncertainties:

    %   Wind uncertainties
    bus1.unc_a_vBEW_bl = 0;          %   [m/s] Bias uncertainty absolute value wind velocity
    bus1.unc_chW_bl = 0;                %   [rad] Bias uncertainty course angle wind


    bus1.unc_fin_def_roll =          1;
    bus1.unc_fin_def_pitch =         0;
    bus1.unc_fin_def_yaw =           0;

    %  Weight and Balance
    bus1.unc_cg_x = 0;
    bus1.unc_cg_y = 0;
    bus1.unc_cg_z = 0;

    bus1.unc_moi_Jxx = 0;
    bus1.unc_moi_Jyy = 0;
    bus1.unc_moi_Jzz = 0;
    bus1.unc_mB_bl = 0;
    bus1.unc_mB_scale = 1;

    %   Propulsion
    bus1.unc_prp_z = 0;
    bus1.unc_prp_y = 0;
    bus1.unc_prp_x = 0;
    bus1.unc_prp_scale = 1;

    %   Aerodynamic coefficients
    bus1.unc_aero_Cx_scale = 1;
    bus1.unc_aero_Cy_scale = 1;
    bus1.unc_aero_Cz_scale = 1;
    bus1.unc_aero_Cl_scale = 1;
    bus1.unc_aero_Cm_scale = 1;
    bus1.unc_aero_Cn_scale = 1;

    %   Actuator Failure
    bus1.unc_act_fail_flag_1 = 1;
    bus1.unc_act_fail_position_1 = 0;
    bus1.unc_act_fail_flag_2 = 1;
    bus1.unc_act_fail_position_2 = 0;
    bus1.unc_act_fail_flag_3 = 1;
    bus1.unc_act_fail_position_3 = 0;
    bus1.unc_act_fail_flag_4 = 1;
    bus1.unc_act_fail_position_4 = 0;
end
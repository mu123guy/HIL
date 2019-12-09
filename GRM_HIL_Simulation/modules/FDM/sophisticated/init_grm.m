%% Initialises the grm Simulink model
%
%
% SUMMARY:
% Loads the initial states and variables of the guided research missile
% flight simulation into the base workspace to be used by simulink.
%
% DESCRIPTION:
% First it loads the globally defined constants, then initializes the
% states and finally initializes non-cosntant global variables
%
% DEPENDENCIES:
% qumul()
% conjq()
% euler_to_q()
% lla_to_dcm_ne()
% q12_from_T12()
% lla_to_ecef()
% comp_julian_date()
% T12_yaw()
% r2_from_r1_trans_q21()
%
% PROJECT:
% *** LOW COST MISSILE TESTBED ***
%
% RESOURCES:
% <used resources/citations>
%
% CHANGE DIRECTORY
% Date          Name                    Description         Version
% 2018/11/12    Lausenhammer, Thomas    initial version     V 1.0
% 2019/05/07    Lausenhammer, Thomas    change Quaternion-  V 1.1
%                                       functions
% 2019/05/07    Lausenhammer, Thomas    added comments      V 1.2
% 2019/09/19    Lausenhammer, Thomas    changes for the new V 1.3
%                                       model version
% 2019/11/12    Lausenhammer, Thomas    added Wind velocity V 1.4
%
%% temp_header_en( )


function bus2 = init_grm()
    %%  Setting initialization for required simulation mode
    % uncomment used one

    %   Simulation mode full missile flight
    bus2.flag_sim_mode = 3;

    %   Simulation mode Monte Carlo Safety assessment
    % flag_sim_mode = 2;

    %   Simulation mode trim and linearize
    % flag_sim_mode = 3;

    %%  Loading Constants
    % Environment
    % WGS84 ellipsoid
    bus2.c_rot = 7.292115e-5;        % [rad/s] earth rotation rate
    bus2.c_g0 = 9.80665;             % [m/s^2] norm gravitational acceleration
    bus2.c_r0 = 6371000.79;          % [m] mean earth radius WGS84
    bus2.c_wgs_a = 6378137;          % [m] semi major axis WGS84
    bus2.c_wgs_b = 6356752.3142;     % [m] semi minor axis WGS84
    bus2.c_wgs_f = 1/298.257223563;  % [-] flattening WGS84

    % Atmosphere
    bus2.c_pa0 = 101325;             % [Pa] ambient pressure Mean sea level
    bus2.c_Tmp0 = 288.15;            % [K] ambient temperature mean sea level
    bus2.c_rho0 = 1.225;             % [kg/m^3] density mean sea level
    bus2.hcr = 1.4;                  % [-] heat constant ratio
    bus2.c_S = 110.4;                % [K] Sutherland Temperature
    bus2.c_beS = 1.458e-6;           % [kg/(m*s*K^1/2)] Sutherland exponent
    bus2.sgc = 287.05287;            % [J/(kg*K)] specific gas constant air (ideal gas)
    bus2.c_be = -6.5e-3;             % [K/m] vertical temperature gradient troposphere
    bus2.c_h_geope = 11e3;           %
    bus2.c_h_geop0 = 0;              % [m] geopotential height mean sea level
    bus2.c_pe = -bus2.c_g0/bus2.c_be/bus2.sgc;

    %%  Initializing states
    %   Decision if rotating/non-rotating and flat/spherical earth
    bus2.flag_I_rot = 0;             % [-] 0- non rotating, 1- rotating earth
    bus2.flag_I_flat = 1;            % [-] 0- round earth, 1- flat earth

    if bus2.flag_I_flat == 1
        %%  Change the initial Conditions HERE!!!!!
        %   in a flat earth scenario the inertial and earth fixed frame reduce
        %   down to a NED oriented navigation Frame, usually notated with an L
        %   according to the ISim design guidelines
        bus2.hBE_0 = 556.3;                 % [m] initial geoemtric height/altitude
        bus2.pBII_0 = [0;0;-bus2.hBE_0 ];        % [m] initial position in the L frame
        %   for the WGS84 gravitational model some values for the longitude and
        %   lattitude have to be given. In the flat earth case they are set to
        %   their initial values over the whole simulation time.
        bus2.lon_0 = 0;                  % [rad] initial longitude
        bus2.lat_0 = 0;                  % [rad] initial lattitude


        %   Hence a flat, rotating earth doesn't make sense, the case is
        %   immediately dropped and the rotation rate set accordingly
        bus2.flag_I_rot = 0;             % [-] 0- non rotating
        bus2.wBIB_0 = [0;0;0];           % [rad/s] initial rotation rate

        %   Therefore the initial orientation is calculated accordingly
        bus2.qIE_0 = [0;0;0;1];
        bus2.qEG_0 = bus2.qIE_0;
        bus2.qIG_0 = qumul(bus2.qIE_0,bus2.qEG_0);
        %   With the orientation of the missile relative to the NED-Frame
        bus2.qGB_0 = euler_to_q([0;-1.356;0]);
            %bus2.qGB_0 = euler_to_q([0;0;0]);
    %     qGB_0 = euler_to_q([0;0;0]);
        bus2.qIB_0 = qumul(bus2.qIG_0,bus2.qGB_0);
        %   And the initial Velocity follows to
        bus2.vBII_0 = [49.201;0;-223.014]*1;           % [m/s]

    else
        %   For a spherical earth the position has to be above the reference
        %   ellipsoid, as the WGS84 gravity model will crash otherwise. This is
        %   guaranteed by calcualting the cartessian coordinates based on
        %   WGS84-coordinates
        bus2.lon_0 = 0;                  % [rad] initial longitude
        bus2.lat_0 = 0;                  % [rad] initial lattitude
        bus2.hBE_0 = 12;                  % [m] initial geoemtric height/altitude

        %   The orientation between the E-System and the NED-System is
        %   calcualted from the position:
        TGE = lla_to_dcm_ne([bus2.lon_0;bus2.lat_0;bus2.hBE_0]);
        TEG = (bus2.TGE)';
        qEG_0 = q12_from_T12(bus2.TEG);
        %   Depending on the initial orientation of the E-Frame in respect to
        %   the I-Frame the calculation of the position differs
        if bus2.flag_I_rot == 0
            bus2.pBII_0 = lla_to_ecef([bus2.lon_0;bus2.lat_0;bus2.hBE_0]);
            bus2.qIE_0 = [0;0;0;1];
            bus2.qIG_0 = qumul(bus2.qIE_0,bus2.qEG_0);
            %   With the orientation of the missile relative to the NED-Frame
            bus2.qGB_0 = euler_to_q([0;-pi/2+0.17;0]);
            bus2.qIB_0 = qumul(bus2.qIG_0,bus2.qGB_0);
            %   Hence the initial translational and rotational velocities
            %   follow to:
            bus2.wBIB_0 = [0;0;0];           % [rad/s] initial roation rate
            bus2.vBII_0 = [0;0;0];           % [m/s]

        else
            %   Calculation initial orientation between I-Frame and E-Frame
            %   based on the desired launch date (Approximation)
            %   Input launch-date
            %   Note: this would have also been possible using the Matlab
            %   function dcmeci2ecef from the Aerospace toolbox, but we 
            %   decide to don't use any toolboxes, because money.
            year = 2019;
            month = 12;
            day = 24;
            hour = 12;
            minute = 00;
            second = 00;
            %   Merry Christmas by the way

            %   Calculation julian date vector
            bus2.julian_date = comp_julian_date(year, month, day, hour, minute, second);

            %   Calculate Greenwich Apparent Sideral Time (GAST) based on the
            %   Greenwich Mean Sidereal Time (GMST) with the Julian Date vector
            bus2.thIE_0 = GAST_from_JD(bus2.julian_date);

            %   Hence the initial transformation matrix between the E and the I
            %   System is calculated
            bus2.TIE_0 = T12_yaw(bus2.thIE_0);
            %   With the initial orientation quaternion
            bus2.qIE_0 = q12_from_T12(bus2.TIE_0);
            bus2.qIG_0 = qumul(bus2.qIE_0,bus2.qEG_0);
            %   With the orientation of the missile relative to the NED-Frame
            bus2.qGB_0 = euler_to_q([0;-pi/2+0.17;0]);
            bus2.qIB_0 = qumul(bus2.qIG_0,bus2.qGB_0);

            %   The resulting position in the inertial frame is then calculated
            %   with the base transformation:
            bus2.pBEE_0 = lla_to_ecef([bus2.lon_0;bus2.lat_0;bus2.hBE_0]);
            bus2.pBII_0 = bus2.TIE_0*bus2.pBEE_0;

            %   The initial rotational velocity correspond to the earth
            %   rotation rate
            bus2.wIEI_0 = [0;0;bus2.c_rot];
            bus2.wBII_0 = bus2.wIEI_0;
            bus2.qBI_0 = conjq(bus2.qIB_0);
            bus2.wBIB_0 = r2_from_r1_trans_q21(bus2.wBII_0,bus2.qBI_0);

            %   and the initial translational velocity
            bus2.vBEE_0 = [0;0;0];       % [m/s] initial velocity relative to E-System
            bus2.vBII_0 = bus2.vBEE_0 + cross(bus2.wIEI_0,bus2.pBII_0);
        end
    end


    %%  Initializing global variables
    bus2.e_Tmp = 0;                      %[K] Temperature deviation MSL
    bus2.e_pa = 0;                       %[Pa] pressure deviation MSL

    bus2.T_sim = inf;                     % [s] Simulation time per flight

    %   Wind velocity
    bus2.a_vBEW = 0;                     % [m/s] absolute value wind velocity relative to earth surface
    bus2.chW = 0;                        % [rad] course angle wind direction 

    if bus2.flag_sim_mode == 1
        bus2.T_sim_lnch = 1;                 %[s] start time missile in global simulation time
        bus2.flag_I_gravity_switch = 0;    % [m] Threshhold launch gravity switch default
        bus2.flag_I_aero_switch = 0;
    elseif bus2.flag_sim_mode == 2
        bus2.T_sim_lnch = 0;                 %[s] start time missile in global simulation time
        bus2.flag_I_aero_switch = 0;
        bus2.flag_I_gravity_switch = 0;    % [m] Threshhold launch gravity switch default
    elseif bus2.flag_sim_mode == 3
        bus2.T_sim_lnch = -5;                 %[s] start time missile in global simulation time
        bus2.flag_I_gravity_switch = 1;    % [m] Threshhold launch gravity switch default
        bus2.flag_I_aero_switch = 1;
    end
    
    %Construct Bus
    
    
end
    %%  Supporting Functions

    function GMST = GMST_from_JD(JD)
    JDmin = floor(JD)-.5;
    JDmax = floor(JD)+.5;
    JD0(JD > JDmin) = JDmin(JD > JDmin);
    JD0(JD > JDmax) = JDmax(JD > JDmax);
    H = (JD-JD0).*24;       %Time in hours past previous midnight
    D = JD - 2451545.0;     %Compute the number of days since J2000
    D0 = JD0 - 2451545.0;   %Compute the number of days since J2000
    T = D./36525;           %Compute the number of centuries since J2000
    %Calculate GMST in hours (0h to 24h) ... then convert to degrees
    GMST = mod(6.697374558 + 0.06570982441908.*D0  + 1.00273790935.*H + ...
        0.000026.*(T.^2),24).*15;
end

function GAST = GAST_from_JD(JD)

thIE_m = GMST_from_JD(JD);
%Compute the number of centuries since J2000
T = (JD - 2451545.0)./36525;

%Mean obliquity of the ecliptic (ep_m)
% see Vallado, Fundamentals of Astrodynamics and Applications, second edition.
%pg. 214 EQ 3-53
ep_m = 23.439291-0.0130111.*T - 1.64E-07.*(T.^2) + 5.04E-07.*(T.^3);

%Nutations in obliquity and longitude (degrees)
L = 280.4665 + 36000.7698.*T;
dL = 218.3165 + 481267.8813.*T;
om = 125.04452 - 1934.136261.*T;

%Calculate nutations using the following two equations:
d_ps = -17.20.*sind(om) - 1.32.*sind(2.*L) - .23.*sind(2.*dL) ...
    + .21.*sind(2.*om);
d_ep = 9.20.*cosd(om) + .57.*cosd(2.*L) + .10.*cosd(2.*dL) - ...
    .09.*cosd(2.*om);

%Convert the units from arc-seconds to degrees
d_ps = d_ps.*(1/3600);
d_ep = d_ep.*(1/3600);

%(GAST) Greenwhich apparent sidereal time expression in degrees
GAST = mod(thIE_m + d_ps.*cosd(ep_m+d_ep),360);
end

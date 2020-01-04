clear,clc
%% Parameteres
d = 0.08;
S = pi*d^2/4;
U0 = 228.4;  % ~~ 0.67Ma
rho = 1.225;
TechnionConfig = 0;

if (TechnionConfig)
    Clp = -51;
    Cld = 4.03;
    Ix = 6.331e-3;
else
    load('aero.mat','Clp','Cl_delta_l');
    Clp = Clp(6,9,9);
    Cld = -Cl_delta_l(6,9,9);
    Ix = 3.7e-3;
end

Lp =rho*S*U0*d^2*Clp/(4*Ix);
Ld =rho*S*U0^2*d*Cld/(4*Ix);

tauServo = 0.1;
tauSensor = 0.01;

%% Inner Loop Design
dyn = tf(Ld,[1 -Lp]);
servo = tf(1,[tauServo 1]);
sensor = tf(1,[tauSensor 1]);
rlocus(dyn*servo*sensor)
sgrid(0.6,1e10)
Kinner=0.1;

%% Outer Loop Design
innerLoop = feedback((Kinner*dyn*servo),sensor);
int = tf(1,[1 0]);
rlocus(innerLoop*int)
sgrid(0.6,1e10)
Kouter = 12;
Ki = 0.3;
s = tf('s');
outerLoop = feedback((Kouter+Ki/s)*innerLoop*int,sensor);

%% Stability margins
outerLoopOpen = (Kouter+Ki/s)*innerLoop*int;
margin(outerLoopOpen)
systemBandwidth = bandwidth(outerLoop)
grid
sim('roll_control_loop');
TF = tf([10],[1,10])
U = 228.4
tauServo = 0.1;
tauSensor = 0.01;
Lp = -0.07946*U;
Ld = 0.1568*U^2;

dyn = tf(Ld,[1 -Lp]);
servo = tf(1,[tauServo 1]);
sensor = tf(1,[tauSensor 1]);

rlocus(dyn*servo*sensor)
sgrid(0.6,1e10)
%pick zeta=0.6 -> K=0.004
Kinner=0.003;

innerLoop = feedback((Kinner*dyn*servo),sensor);
int = tf(1,[1 0]);
rlocus(innerLoop*int)
sgrid(0.6,1e10)
Kouter = 2.72

outerLoop = feedback(Kouter*innerLoop*int,sensor)
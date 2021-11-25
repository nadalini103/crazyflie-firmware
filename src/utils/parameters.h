#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// Lab 2 função PWM
const float kmotor1 = 1.16e-07; //*x^2
const float kmotor2 = 4.488e-12; //*x

// Lab 3 K de sustentação
const float kl = 1.726e-08; // N*s^2

// Lab 4 K de arrasto
const float kd= 1.434e-10;//N*m*s^2

// Lab 7 acelerometro e giroscopio:
const float dt= 0.002;
const float wc= 1; //rad/s
const float alpha= wc*dt/(1+wc*dt);

//Lab 8 - ganhos dos controladores para phi/theta (1) e psi (2):
// Calculo para a dinamica phi/theta:
const float Ts_1=0.3;
const float OS_1=0.005;
const float zeta_cont_1= abs(log(OS_1))/sqrt(pow(log(OS_1),2)+pow(pi,2));
const float wn_cont_1 = 4.0/(zeta_cont_1*Ts_1);
const float kd_contr_1=2.0*zeta_cont_1*wn_cont_1;;
const float kp_contr_1=pow(wn_cont_1,2);

//psi:
const float Ts_2=0.6;
const float OS_2=0.005;
const float zeta_cont_2= abs(log(OS_2))/sqrt(pow(log(OS_2),2)+pow(pi,2));
const float wn_cont_2 = 4.0/(zeta_cont_2*Ts_2);
const float kd_contr_2=2.0*zeta_cont_2*wn_cont_2;;
const float kp_contr_2=pow(wn_cont_2,2);

//Lab 9- estimador vertical:
const float dt_range=0.05;
const float wc_vert=10; // wc=l<1/dt_range
const float l1=pow(wc_vert,2);
const float zeta_vert= (sqrt(2)/2);
const float l2=2*zeta_vert*wc_vert;

//Lab 10- controlador vertical:
const float kp_vert = 5.86;
const float kd_vert = 3.42;

//Lab 11 - estimador horizontal:
const float gama = 42*pi/180; //°
const float res_W = 420; //pixels
const float sigma = 2*tan(gama/2)/(res_W*dt);
const float wc_hor = 50; // wc=l<1/dt_range

//Lab 12 - controlador horizontal:
const float Ts_hor=0.6;
const float OS_hor=0.005;
const float zeta_hor= abs(log(OS_hor))/sqrt(pow(log(OS_hor),2)+pow(pi,2));
const float wn_hor = 4.0/(zeta_hor*Ts_hor);
const float kd_hor=2.0*zeta_hor*wn_hor;;
const float kp_hor=pow(wn_hor,2);
#endif
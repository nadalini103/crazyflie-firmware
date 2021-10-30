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
const float wc= 10; //rad/s
const float alpha= wc*dt/(1+wc*dt);

//Lab 8 - ganhos dos controladores para phi/theta (1) e psi (2):
const float kd_contr_1=0;
const float kp_contr_1=0;
const float kd_contr_2=0;
const float kp_contr_2=0;

#endif
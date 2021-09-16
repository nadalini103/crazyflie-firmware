# include "mbed.h"
# include "crazyflie.h"

// Define motor as PWM output object
PwmOut motor_1 ( MOTOR1 ) ;
PwmOut motor_2 ( MOTOR2 ) ;
PwmOut motor_3 ( MOTOR3 ) ;
PwmOut motor_4 ( MOTOR4 ) ;

// Define angular velocities (rad/s)
float omega_1 ;
float omega_2 ;
float omega_3 ;
float omega_4 ;

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor ( float omega_r )
{
    return kmotor1 * pow(omega_r,2) + kmotor2 *omega_r;
}
// Converts total trust force (N) and torques (N.m) to angular velocities (rad/s)
void mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    if(f_t>=0 & tau_phi >=0 & tau_theta>=0 & tau_psi>=0){
        omega_1=pow((f_t/(4*kl) -tau_phi/(4*kl*l) -tau_theta/(4*kl*l) -tau_psi/(4*kd)),0.5);
        omega_2=pow((f_t/(4*kl) -tau_phi/(4*kl*l) +tau_theta/(4*kl*l) +tau_psi/(4*kd)),0.5);
        omega_3=pow((f_t/(4*kl) +tau_phi/(4*kl*l) +tau_theta/(4*kl*l) -tau_psi/(4*kd)),0.5);
        omega_4=pow((f_t/(4*kl) +tau_phi/(4*kl*l) -tau_theta/(4*kl*l) +tau_psi/(4*kd)),0.5);
    }
    else{
        omega_1=0;
        omega_2=0;
        omega_3=0;
        omega_4=0;
    }
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
mixer (f_t , tau_phi , tau_theta , tau_psi );
motor_1 = control_motor ( omega_1 ) ;
motor_2 = control_motor ( omega_2 ) ;
motor_3 = control_motor ( omega_3 ) ;
motor_4 = control_motor ( omega_4 ) ;
}

// Main program
int main ()
{
// Set all PWM frequencies to 500 Hz
motor_1 . period (1.0/500.0) ;
motor_2 . period (1.0/500.0) ;
motor_3 . period (1.0/500.0) ;
motor_4 . period (1.0/500.0) ;
// Actuate motor with 70% mg total thrust force (N) and zero torques (N.m)
actuate (0.7* m*g ,0 ,0 ,0) ;
wait (5) ;
// Turn off all motors
actuate (0 ,0 ,0 ,0) ;
// End of program
while ( true )
{
}
}
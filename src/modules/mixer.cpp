#include "mixer.h"

// Class constructor
Mixer :: Mixer () : motor_1 ( MOTOR1 ) , motor_2 ( MOTOR2 ) , motor_3 ( MOTOR3 ) , motor_4 ( MOTOR4 ), led_azul (LED_BLUE_L,!false), led_vermR (LED_RED_R,!false), led_vermL (LED_RED_L,!false), led_verdR (LED_GREEN_R,!false), led_verdL (LED_GREEN_L,!false)
{
motor_1 . period (1.0/500.0) ;
motor_2 . period (1.0/500.0) ;
motor_3 . period (1.0/500.0) ;
motor_4 . period (1.0/500.0) ;
motor_1 = 0.0;
motor_2 = 0.0;
motor_3 = 0.0;
motor_4 = 0.0;
armed = 0;
}
// Função de segurança para armar os motores:
void Mixer :: arm()
{
    armed=1;
}
void Mixer :: disarm()
{
    armed=0;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
}
// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer :: actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    if (armed==1)
    {
        mixer (f_t , tau_phi , tau_theta , tau_psi );
        motor_1 = control_motor ( omega_1 ) ;
        motor_2 = control_motor ( omega_2 ) ;
        motor_3 = control_motor ( omega_3 ) ;
        motor_4 = control_motor ( omega_4 ) ;
    }
}

// Convert total trust force (N) and torques (N.m) to angular velocities ( rad /s)
void Mixer :: mixer (float f_t , float tau_phi , float tau_theta , float tau_psi)
{
    omega_1=pow((f_t/(4*kl) -tau_phi/(4*kl*l) -tau_theta/(4*kl*l) -tau_psi/(4*kd)),0.5);
    omega_2=pow((f_t/(4*kl) -tau_phi/(4*kl*l) +tau_theta/(4*kl*l) +tau_psi/(4*kd)),0.5);
    omega_3=pow((f_t/(4*kl) +tau_phi/(4*kl*l) +tau_theta/(4*kl*l) -tau_psi/(4*kd)),0.5);
    omega_4=pow((f_t/(4*kl) +tau_phi/(4*kl*l) -tau_theta/(4*kl*l) +tau_psi/(4*kd)),0.5);
    if (omega_1 < 0) 
    {
        omega_1=0;
    }
    if (omega_2 < 0) 
    {
        omega_2=0;
    }
    if (omega_3 < 0) 
    {
        omega_3=0;
    }
    if (omega_4 < 0) 
    {
        omega_4=0;
    }
}

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer :: control_motor ( float omega )
{
    return kmotor1 * pow(omega,2) + kmotor2 *omega;
}

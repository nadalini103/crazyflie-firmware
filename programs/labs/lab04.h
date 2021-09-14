# include "mbed.h"
# include "crazyflie.h"

// Define motor as PWM output object
PwmOut motor1 ( MOTOR1 ) ;
PwmOut motor2 ( MOTOR2 ) ;
PwmOut motor3 ( MOTOR3 ) ;
PwmOut motor4 ( MOTOR4 ) ;

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor ( float omega_r )
{
 return kmotor1 * pow(omega_r,2) + kmotor2 *omega_r;
}

// Main program
int main ()
{
    wait(3);
    // Set PWM frequency to 500 Hz
    motor1 . period (1.0/500.0) ;
    motor2 . period (1.0/500.0) ;
    motor3 . period (1.0/500.0) ;
    motor4 . period (1.0/500.0) ;

    // Turn on motors with X rad /s for 5s
    motor1 = control_motor (1000.0) ;
    motor2 = control_motor (2000.0) ;
    motor3 = control_motor (1000.0) ;
    motor4 = control_motor (2000.0) ;
    wait(5) ;
    // Turn off motor
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    // End of program
    while ( true )
    {
        
    }
}

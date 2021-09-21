# include "mbed.h"
# include "crazyflie.h"

// Declare mixer
Mixer mixer ;

// Main program
int main ()
{
    wait(2);
    // Actuate motor with 70% mg total thrust force (N) and zero torques
    mixer.actuate(0, 0, 0, 0) ;
    wait(1);
    // Turn off all motors
    mixer.actuate(0, 0, 0, 0) ;
    // End of program
    while (true)
    {
    }
}
#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led_azul(LED_BLUE_L,!false);
DigitalOut led_vermR(LED_RED_R,!false);
DigitalOut led_vermL(LED_RED_L,!false);
DigitalOut led_verdR(LED_GREEN_R,!false);
DigitalOut led_verdL(LED_GREEN_L,!false);
// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    for (int i=0; i<10;i++){
        led_azul=!led_azul;
        wait(0.5);
    }
    led_azul=0;

    // Turn on red LEDs indicating motors are armed
    led_vermL=!led_vermL;
    led_vermR=!led_vermR;

    // Test all motors with different frequencies (to make different noises)
    motor1 = 0.1;
    motor2 = 0.1;
    motor3 = 0.1;
    motor4 = 0.1;
    int F[]={264,297,330,352,396,440,495,528};
    for (int f=0; f<8; f++) {
        motor1.period(1.0/F[f]);
        motor2.period(1.0/F[f]);
        motor3.period(1.0/F[f]);
        motor4.period(1.0/F[f]);
        wait(1);
    }

    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;


    // Turn off red LEDs indicating motors are disarmed
    led_vermL=!led_vermL;
    led_vermR=!led_vermR;

    // Blink green LEDs indicating end of program
    for (int i=0; i<10;i++){
        led_verdR=!led_verdR;
        led_verdL=!led_verdL;
        wait(0.4);
    }

    while(true)
    {
        
    }
}

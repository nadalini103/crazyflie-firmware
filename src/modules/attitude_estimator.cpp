# include "attitude_estimator.h"

// Class constructor
AttitudeEstimator :: AttitudeEstimator () : imu ( IMU_SDA , IMU_SCL )
{
    float phi=0;
    float theta=0;
    float psy=0;
    float p=0;
    float q=0;
    float r=0;
    float p_bias=0;
}

// Initialize class
void AttitudeEstimator::init()
{
    imu.init();
    for ( int i=0;i<500;i++)
    {
        imu.read();
        p_bias += (imu.gx/500);
        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator :: estimate ()
{
imu.read();
p=imu.gx-p_bias;
float phi_g=phi_g+p*dt;
phi=phi_g;
/*imu.read();
float phi_a=atan2(-imu.ay,-imu.az);
phi=(1-alpha)*phi+alpha*phi_a;*/

}
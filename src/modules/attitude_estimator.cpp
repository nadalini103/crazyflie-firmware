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
}

// Initialize class
void AttitudeEstimator :: init ()
{
imu.init();
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator :: estimate ()
{
imu.read();
float phi_a=atan2(-imu.ay,-imu.az);
phi=(1-alpha)*phi+alpha*phi_a;
}
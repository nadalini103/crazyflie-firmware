# include "attitude_estimator.h"

// Class constructor
AttitudeEstimator:: AttitudeEstimator(): imu(IMU_SDA,IMU_SCL)
{
    phi=0;
    theta=0;
    psi=0;
    p=0;
    q=0;
    r=0;
    p_bias=0;
    q_bias=0;
    r_bias=0;
}

// Initialize class
void AttitudeEstimator::init()
{
    imu.init();
    //Calculando o erro sistemático:
    for ( int i=0;i<500;i++)
    {
        imu.read();
        p_bias += (imu.gx/500);
        q_bias += (imu.gy/500);
        r_bias += (imu.gz/500);
        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator::estimate()
{
imu.read();
//Velocidades angulares menos o erro sistemático:
p=imu.gx-p_bias;
q=imu.gy-q_bias;
r=imu.gz-r_bias;
//Calculando os angulos a partir do giroscopio:
float phi_g=phi+(p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt;
float theta_g=theta+(cos(phi)*q-sin(phi)*r)*dt;
float psi_g=psi+(sin(phi)/cos(theta)*q+cos(phi)/cos(theta)*r)*dt;
//Calculando os angulos a partir do acelerometro:
float phi_a=atan2(-imu.ay,-imu.az);
float theta_a=atan2(imu.ax,-((imu.az>0)-(imu.az<0))*sqrt(pow(imu.ay,2)+pow(imu.az,2)));
//Filtro complementar:
phi=(1-alpha)*phi_g+alpha*phi_a;
theta=(1-alpha)*theta_g+alpha*theta_a;
psi=psi_g;

}
// Arquivo onde são implementados os códigos fonte das funções.
# include "attitude_controller.h"

// Class constructor
AttitudeController :: AttitudeController()
{
    //Inicialização das variáveis públicas e privadas:
    tau_phi=0;
    tau_psi=0;
    tau_theta=0;
}

// Control torques (N.m) given reference angles ( rad) and current angles ( rad ) and angular velocities ( rad /s)
void AttitudeController :: control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r)
{
    tau_phi=I_xx*control_siso(phi_r,phi,p,kp_contr_1,kd_contr_1);
    tau_theta=I_yy*control_siso(theta_r,theta,q,kp_contr_1,kd_contr_1);
    tau_psi=I_zz*control_siso(psi_r,psi,r,kp_contr_2,kd_contr_2);
}

// Angular aceleration (rad/s^2) given reference angle ( rad ) and current angle ( rad ) and angular velocity ( rad /s) with given controller gains
float AttitudeController :: control_siso (float angle_r, float angle, float rate, float kp, float kd)
{
    //Em cascata:
    /*float rate_r = kp*(angle_r-angle);
    return kd*(rate_r-rate);*/
    //Regulador de estados:
    return kp*(angle_r-angle)+kd*(0-rate);
}

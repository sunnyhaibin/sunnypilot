#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6577315047741695773);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1977980201720716769);
void car_H_mod_fun(double *state, double *out_3855454271302654333);
void car_f_fun(double *state, double dt, double *out_3046888606918275198);
void car_F_fun(double *state, double dt, double *out_5302708174877967124);
void car_h_25(double *state, double *unused, double *out_8951489129296429946);
void car_H_25(double *state, double *unused, double *out_7492389928257591884);
void car_h_24(double *state, double *unused, double *out_5227397427983060307);
void car_H_24(double *state, double *unused, double *out_5319740329252092318);
void car_h_30(double *state, double *unused, double *out_855377467694579786);
void car_H_30(double *state, double *unused, double *out_8436021186944711105);
void car_h_26(double *state, double *unused, double *out_2823045465769633222);
void car_H_26(double *state, double *unused, double *out_3750886609383535660);
void car_h_27(double *state, double *unused, double *out_3949815861635584301);
void car_H_27(double *state, double *unused, double *out_789930286329558775);
void car_h_29(double *state, double *unused, double *out_1002089871280099340);
void car_H_29(double *state, double *unused, double *out_7925789842630318921);
void car_h_28(double *state, double *unused, double *out_2967731768300286189);
void car_H_28(double *state, double *unused, double *out_5438555214009702121);
void car_h_31(double *state, double *unused, double *out_9220060882128615781);
void car_H_31(double *state, double *unused, double *out_3124678507150184184);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}
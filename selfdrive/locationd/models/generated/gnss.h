#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3091736425893176274);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_395858737264161989);
void gnss_H_mod_fun(double *state, double *out_4724540122826202881);
void gnss_f_fun(double *state, double dt, double *out_2708008813438395572);
void gnss_F_fun(double *state, double dt, double *out_7420477308285821792);
void gnss_h_6(double *state, double *sat_pos, double *out_8671466866109907242);
void gnss_H_6(double *state, double *sat_pos, double *out_5585166090243062255);
void gnss_h_20(double *state, double *sat_pos, double *out_2571050700492479581);
void gnss_H_20(double *state, double *sat_pos, double *out_1399948580511547396);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_318521577718092107);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2080774137273878998);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_318521577718092107);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2080774137273878998);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}
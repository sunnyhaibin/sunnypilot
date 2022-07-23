#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2371134415192855578);
void live_err_fun(double *nom_x, double *delta_x, double *out_8346643765801733285);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7659926232156838011);
void live_H_mod_fun(double *state, double *out_2316424480753417441);
void live_f_fun(double *state, double dt, double *out_4391588121978318731);
void live_F_fun(double *state, double dt, double *out_1171520194403940403);
void live_h_4(double *state, double *unused, double *out_772062353137008250);
void live_H_4(double *state, double *unused, double *out_5685240714358944534);
void live_h_9(double *state, double *unused, double *out_5323728778463845524);
void live_H_9(double *state, double *unused, double *out_5474284424086159612);
void live_h_10(double *state, double *unused, double *out_736296095451225427);
void live_H_10(double *state, double *unused, double *out_2248528365336139792);
void live_h_12(double *state, double *unused, double *out_1347916463491024439);
void live_H_12(double *state, double *unused, double *out_696017662683788462);
void live_h_35(double *state, double *unused, double *out_5698654690754227408);
void live_H_35(double *state, double *unused, double *out_9051902771731551910);
void live_h_32(double *state, double *unused, double *out_6619486108574102812);
void live_H_32(double *state, double *unused, double *out_9183067556672292379);
void live_h_13(double *state, double *unused, double *out_4193743935506485275);
void live_H_13(double *state, double *unused, double *out_1674154273183340047);
void live_h_14(double *state, double *unused, double *out_5323728778463845524);
void live_H_14(double *state, double *unused, double *out_5474284424086159612);
void live_h_33(double *state, double *unused, double *out_3308212013704557851);
void live_H_33(double *state, double *unused, double *out_6244284297339142102);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}
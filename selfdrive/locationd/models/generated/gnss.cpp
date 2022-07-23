#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3091736425893176274) {
   out_3091736425893176274[0] = delta_x[0] + nom_x[0];
   out_3091736425893176274[1] = delta_x[1] + nom_x[1];
   out_3091736425893176274[2] = delta_x[2] + nom_x[2];
   out_3091736425893176274[3] = delta_x[3] + nom_x[3];
   out_3091736425893176274[4] = delta_x[4] + nom_x[4];
   out_3091736425893176274[5] = delta_x[5] + nom_x[5];
   out_3091736425893176274[6] = delta_x[6] + nom_x[6];
   out_3091736425893176274[7] = delta_x[7] + nom_x[7];
   out_3091736425893176274[8] = delta_x[8] + nom_x[8];
   out_3091736425893176274[9] = delta_x[9] + nom_x[9];
   out_3091736425893176274[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_395858737264161989) {
   out_395858737264161989[0] = -nom_x[0] + true_x[0];
   out_395858737264161989[1] = -nom_x[1] + true_x[1];
   out_395858737264161989[2] = -nom_x[2] + true_x[2];
   out_395858737264161989[3] = -nom_x[3] + true_x[3];
   out_395858737264161989[4] = -nom_x[4] + true_x[4];
   out_395858737264161989[5] = -nom_x[5] + true_x[5];
   out_395858737264161989[6] = -nom_x[6] + true_x[6];
   out_395858737264161989[7] = -nom_x[7] + true_x[7];
   out_395858737264161989[8] = -nom_x[8] + true_x[8];
   out_395858737264161989[9] = -nom_x[9] + true_x[9];
   out_395858737264161989[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_4724540122826202881) {
   out_4724540122826202881[0] = 1.0;
   out_4724540122826202881[1] = 0;
   out_4724540122826202881[2] = 0;
   out_4724540122826202881[3] = 0;
   out_4724540122826202881[4] = 0;
   out_4724540122826202881[5] = 0;
   out_4724540122826202881[6] = 0;
   out_4724540122826202881[7] = 0;
   out_4724540122826202881[8] = 0;
   out_4724540122826202881[9] = 0;
   out_4724540122826202881[10] = 0;
   out_4724540122826202881[11] = 0;
   out_4724540122826202881[12] = 1.0;
   out_4724540122826202881[13] = 0;
   out_4724540122826202881[14] = 0;
   out_4724540122826202881[15] = 0;
   out_4724540122826202881[16] = 0;
   out_4724540122826202881[17] = 0;
   out_4724540122826202881[18] = 0;
   out_4724540122826202881[19] = 0;
   out_4724540122826202881[20] = 0;
   out_4724540122826202881[21] = 0;
   out_4724540122826202881[22] = 0;
   out_4724540122826202881[23] = 0;
   out_4724540122826202881[24] = 1.0;
   out_4724540122826202881[25] = 0;
   out_4724540122826202881[26] = 0;
   out_4724540122826202881[27] = 0;
   out_4724540122826202881[28] = 0;
   out_4724540122826202881[29] = 0;
   out_4724540122826202881[30] = 0;
   out_4724540122826202881[31] = 0;
   out_4724540122826202881[32] = 0;
   out_4724540122826202881[33] = 0;
   out_4724540122826202881[34] = 0;
   out_4724540122826202881[35] = 0;
   out_4724540122826202881[36] = 1.0;
   out_4724540122826202881[37] = 0;
   out_4724540122826202881[38] = 0;
   out_4724540122826202881[39] = 0;
   out_4724540122826202881[40] = 0;
   out_4724540122826202881[41] = 0;
   out_4724540122826202881[42] = 0;
   out_4724540122826202881[43] = 0;
   out_4724540122826202881[44] = 0;
   out_4724540122826202881[45] = 0;
   out_4724540122826202881[46] = 0;
   out_4724540122826202881[47] = 0;
   out_4724540122826202881[48] = 1.0;
   out_4724540122826202881[49] = 0;
   out_4724540122826202881[50] = 0;
   out_4724540122826202881[51] = 0;
   out_4724540122826202881[52] = 0;
   out_4724540122826202881[53] = 0;
   out_4724540122826202881[54] = 0;
   out_4724540122826202881[55] = 0;
   out_4724540122826202881[56] = 0;
   out_4724540122826202881[57] = 0;
   out_4724540122826202881[58] = 0;
   out_4724540122826202881[59] = 0;
   out_4724540122826202881[60] = 1.0;
   out_4724540122826202881[61] = 0;
   out_4724540122826202881[62] = 0;
   out_4724540122826202881[63] = 0;
   out_4724540122826202881[64] = 0;
   out_4724540122826202881[65] = 0;
   out_4724540122826202881[66] = 0;
   out_4724540122826202881[67] = 0;
   out_4724540122826202881[68] = 0;
   out_4724540122826202881[69] = 0;
   out_4724540122826202881[70] = 0;
   out_4724540122826202881[71] = 0;
   out_4724540122826202881[72] = 1.0;
   out_4724540122826202881[73] = 0;
   out_4724540122826202881[74] = 0;
   out_4724540122826202881[75] = 0;
   out_4724540122826202881[76] = 0;
   out_4724540122826202881[77] = 0;
   out_4724540122826202881[78] = 0;
   out_4724540122826202881[79] = 0;
   out_4724540122826202881[80] = 0;
   out_4724540122826202881[81] = 0;
   out_4724540122826202881[82] = 0;
   out_4724540122826202881[83] = 0;
   out_4724540122826202881[84] = 1.0;
   out_4724540122826202881[85] = 0;
   out_4724540122826202881[86] = 0;
   out_4724540122826202881[87] = 0;
   out_4724540122826202881[88] = 0;
   out_4724540122826202881[89] = 0;
   out_4724540122826202881[90] = 0;
   out_4724540122826202881[91] = 0;
   out_4724540122826202881[92] = 0;
   out_4724540122826202881[93] = 0;
   out_4724540122826202881[94] = 0;
   out_4724540122826202881[95] = 0;
   out_4724540122826202881[96] = 1.0;
   out_4724540122826202881[97] = 0;
   out_4724540122826202881[98] = 0;
   out_4724540122826202881[99] = 0;
   out_4724540122826202881[100] = 0;
   out_4724540122826202881[101] = 0;
   out_4724540122826202881[102] = 0;
   out_4724540122826202881[103] = 0;
   out_4724540122826202881[104] = 0;
   out_4724540122826202881[105] = 0;
   out_4724540122826202881[106] = 0;
   out_4724540122826202881[107] = 0;
   out_4724540122826202881[108] = 1.0;
   out_4724540122826202881[109] = 0;
   out_4724540122826202881[110] = 0;
   out_4724540122826202881[111] = 0;
   out_4724540122826202881[112] = 0;
   out_4724540122826202881[113] = 0;
   out_4724540122826202881[114] = 0;
   out_4724540122826202881[115] = 0;
   out_4724540122826202881[116] = 0;
   out_4724540122826202881[117] = 0;
   out_4724540122826202881[118] = 0;
   out_4724540122826202881[119] = 0;
   out_4724540122826202881[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_2708008813438395572) {
   out_2708008813438395572[0] = dt*state[3] + state[0];
   out_2708008813438395572[1] = dt*state[4] + state[1];
   out_2708008813438395572[2] = dt*state[5] + state[2];
   out_2708008813438395572[3] = state[3];
   out_2708008813438395572[4] = state[4];
   out_2708008813438395572[5] = state[5];
   out_2708008813438395572[6] = dt*state[7] + state[6];
   out_2708008813438395572[7] = dt*state[8] + state[7];
   out_2708008813438395572[8] = state[8];
   out_2708008813438395572[9] = state[9];
   out_2708008813438395572[10] = state[10];
}
void F_fun(double *state, double dt, double *out_7420477308285821792) {
   out_7420477308285821792[0] = 1;
   out_7420477308285821792[1] = 0;
   out_7420477308285821792[2] = 0;
   out_7420477308285821792[3] = dt;
   out_7420477308285821792[4] = 0;
   out_7420477308285821792[5] = 0;
   out_7420477308285821792[6] = 0;
   out_7420477308285821792[7] = 0;
   out_7420477308285821792[8] = 0;
   out_7420477308285821792[9] = 0;
   out_7420477308285821792[10] = 0;
   out_7420477308285821792[11] = 0;
   out_7420477308285821792[12] = 1;
   out_7420477308285821792[13] = 0;
   out_7420477308285821792[14] = 0;
   out_7420477308285821792[15] = dt;
   out_7420477308285821792[16] = 0;
   out_7420477308285821792[17] = 0;
   out_7420477308285821792[18] = 0;
   out_7420477308285821792[19] = 0;
   out_7420477308285821792[20] = 0;
   out_7420477308285821792[21] = 0;
   out_7420477308285821792[22] = 0;
   out_7420477308285821792[23] = 0;
   out_7420477308285821792[24] = 1;
   out_7420477308285821792[25] = 0;
   out_7420477308285821792[26] = 0;
   out_7420477308285821792[27] = dt;
   out_7420477308285821792[28] = 0;
   out_7420477308285821792[29] = 0;
   out_7420477308285821792[30] = 0;
   out_7420477308285821792[31] = 0;
   out_7420477308285821792[32] = 0;
   out_7420477308285821792[33] = 0;
   out_7420477308285821792[34] = 0;
   out_7420477308285821792[35] = 0;
   out_7420477308285821792[36] = 1;
   out_7420477308285821792[37] = 0;
   out_7420477308285821792[38] = 0;
   out_7420477308285821792[39] = 0;
   out_7420477308285821792[40] = 0;
   out_7420477308285821792[41] = 0;
   out_7420477308285821792[42] = 0;
   out_7420477308285821792[43] = 0;
   out_7420477308285821792[44] = 0;
   out_7420477308285821792[45] = 0;
   out_7420477308285821792[46] = 0;
   out_7420477308285821792[47] = 0;
   out_7420477308285821792[48] = 1;
   out_7420477308285821792[49] = 0;
   out_7420477308285821792[50] = 0;
   out_7420477308285821792[51] = 0;
   out_7420477308285821792[52] = 0;
   out_7420477308285821792[53] = 0;
   out_7420477308285821792[54] = 0;
   out_7420477308285821792[55] = 0;
   out_7420477308285821792[56] = 0;
   out_7420477308285821792[57] = 0;
   out_7420477308285821792[58] = 0;
   out_7420477308285821792[59] = 0;
   out_7420477308285821792[60] = 1;
   out_7420477308285821792[61] = 0;
   out_7420477308285821792[62] = 0;
   out_7420477308285821792[63] = 0;
   out_7420477308285821792[64] = 0;
   out_7420477308285821792[65] = 0;
   out_7420477308285821792[66] = 0;
   out_7420477308285821792[67] = 0;
   out_7420477308285821792[68] = 0;
   out_7420477308285821792[69] = 0;
   out_7420477308285821792[70] = 0;
   out_7420477308285821792[71] = 0;
   out_7420477308285821792[72] = 1;
   out_7420477308285821792[73] = dt;
   out_7420477308285821792[74] = 0;
   out_7420477308285821792[75] = 0;
   out_7420477308285821792[76] = 0;
   out_7420477308285821792[77] = 0;
   out_7420477308285821792[78] = 0;
   out_7420477308285821792[79] = 0;
   out_7420477308285821792[80] = 0;
   out_7420477308285821792[81] = 0;
   out_7420477308285821792[82] = 0;
   out_7420477308285821792[83] = 0;
   out_7420477308285821792[84] = 1;
   out_7420477308285821792[85] = dt;
   out_7420477308285821792[86] = 0;
   out_7420477308285821792[87] = 0;
   out_7420477308285821792[88] = 0;
   out_7420477308285821792[89] = 0;
   out_7420477308285821792[90] = 0;
   out_7420477308285821792[91] = 0;
   out_7420477308285821792[92] = 0;
   out_7420477308285821792[93] = 0;
   out_7420477308285821792[94] = 0;
   out_7420477308285821792[95] = 0;
   out_7420477308285821792[96] = 1;
   out_7420477308285821792[97] = 0;
   out_7420477308285821792[98] = 0;
   out_7420477308285821792[99] = 0;
   out_7420477308285821792[100] = 0;
   out_7420477308285821792[101] = 0;
   out_7420477308285821792[102] = 0;
   out_7420477308285821792[103] = 0;
   out_7420477308285821792[104] = 0;
   out_7420477308285821792[105] = 0;
   out_7420477308285821792[106] = 0;
   out_7420477308285821792[107] = 0;
   out_7420477308285821792[108] = 1;
   out_7420477308285821792[109] = 0;
   out_7420477308285821792[110] = 0;
   out_7420477308285821792[111] = 0;
   out_7420477308285821792[112] = 0;
   out_7420477308285821792[113] = 0;
   out_7420477308285821792[114] = 0;
   out_7420477308285821792[115] = 0;
   out_7420477308285821792[116] = 0;
   out_7420477308285821792[117] = 0;
   out_7420477308285821792[118] = 0;
   out_7420477308285821792[119] = 0;
   out_7420477308285821792[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_8671466866109907242) {
   out_8671466866109907242[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_5585166090243062255) {
   out_5585166090243062255[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5585166090243062255[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5585166090243062255[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5585166090243062255[3] = 0;
   out_5585166090243062255[4] = 0;
   out_5585166090243062255[5] = 0;
   out_5585166090243062255[6] = 1;
   out_5585166090243062255[7] = 0;
   out_5585166090243062255[8] = 0;
   out_5585166090243062255[9] = 0;
   out_5585166090243062255[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_2571050700492479581) {
   out_2571050700492479581[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_1399948580511547396) {
   out_1399948580511547396[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1399948580511547396[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1399948580511547396[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1399948580511547396[3] = 0;
   out_1399948580511547396[4] = 0;
   out_1399948580511547396[5] = 0;
   out_1399948580511547396[6] = 1;
   out_1399948580511547396[7] = 0;
   out_1399948580511547396[8] = 0;
   out_1399948580511547396[9] = 1;
   out_1399948580511547396[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_318521577718092107) {
   out_318521577718092107[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_2080774137273878998) {
   out_2080774137273878998[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[6] = 0;
   out_2080774137273878998[7] = 1;
   out_2080774137273878998[8] = 0;
   out_2080774137273878998[9] = 0;
   out_2080774137273878998[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_318521577718092107) {
   out_318521577718092107[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_2080774137273878998) {
   out_2080774137273878998[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2080774137273878998[6] = 0;
   out_2080774137273878998[7] = 1;
   out_2080774137273878998[8] = 0;
   out_2080774137273878998[9] = 0;
   out_2080774137273878998[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3091736425893176274) {
  err_fun(nom_x, delta_x, out_3091736425893176274);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_395858737264161989) {
  inv_err_fun(nom_x, true_x, out_395858737264161989);
}
void gnss_H_mod_fun(double *state, double *out_4724540122826202881) {
  H_mod_fun(state, out_4724540122826202881);
}
void gnss_f_fun(double *state, double dt, double *out_2708008813438395572) {
  f_fun(state,  dt, out_2708008813438395572);
}
void gnss_F_fun(double *state, double dt, double *out_7420477308285821792) {
  F_fun(state,  dt, out_7420477308285821792);
}
void gnss_h_6(double *state, double *sat_pos, double *out_8671466866109907242) {
  h_6(state, sat_pos, out_8671466866109907242);
}
void gnss_H_6(double *state, double *sat_pos, double *out_5585166090243062255) {
  H_6(state, sat_pos, out_5585166090243062255);
}
void gnss_h_20(double *state, double *sat_pos, double *out_2571050700492479581) {
  h_20(state, sat_pos, out_2571050700492479581);
}
void gnss_H_20(double *state, double *sat_pos, double *out_1399948580511547396) {
  H_20(state, sat_pos, out_1399948580511547396);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_318521577718092107) {
  h_7(state, sat_pos_vel, out_318521577718092107);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2080774137273878998) {
  H_7(state, sat_pos_vel, out_2080774137273878998);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_318521577718092107) {
  h_21(state, sat_pos_vel, out_318521577718092107);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2080774137273878998) {
  H_21(state, sat_pos_vel, out_2080774137273878998);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);

#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6577315047741695773) {
   out_6577315047741695773[0] = delta_x[0] + nom_x[0];
   out_6577315047741695773[1] = delta_x[1] + nom_x[1];
   out_6577315047741695773[2] = delta_x[2] + nom_x[2];
   out_6577315047741695773[3] = delta_x[3] + nom_x[3];
   out_6577315047741695773[4] = delta_x[4] + nom_x[4];
   out_6577315047741695773[5] = delta_x[5] + nom_x[5];
   out_6577315047741695773[6] = delta_x[6] + nom_x[6];
   out_6577315047741695773[7] = delta_x[7] + nom_x[7];
   out_6577315047741695773[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1977980201720716769) {
   out_1977980201720716769[0] = -nom_x[0] + true_x[0];
   out_1977980201720716769[1] = -nom_x[1] + true_x[1];
   out_1977980201720716769[2] = -nom_x[2] + true_x[2];
   out_1977980201720716769[3] = -nom_x[3] + true_x[3];
   out_1977980201720716769[4] = -nom_x[4] + true_x[4];
   out_1977980201720716769[5] = -nom_x[5] + true_x[5];
   out_1977980201720716769[6] = -nom_x[6] + true_x[6];
   out_1977980201720716769[7] = -nom_x[7] + true_x[7];
   out_1977980201720716769[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3855454271302654333) {
   out_3855454271302654333[0] = 1.0;
   out_3855454271302654333[1] = 0;
   out_3855454271302654333[2] = 0;
   out_3855454271302654333[3] = 0;
   out_3855454271302654333[4] = 0;
   out_3855454271302654333[5] = 0;
   out_3855454271302654333[6] = 0;
   out_3855454271302654333[7] = 0;
   out_3855454271302654333[8] = 0;
   out_3855454271302654333[9] = 0;
   out_3855454271302654333[10] = 1.0;
   out_3855454271302654333[11] = 0;
   out_3855454271302654333[12] = 0;
   out_3855454271302654333[13] = 0;
   out_3855454271302654333[14] = 0;
   out_3855454271302654333[15] = 0;
   out_3855454271302654333[16] = 0;
   out_3855454271302654333[17] = 0;
   out_3855454271302654333[18] = 0;
   out_3855454271302654333[19] = 0;
   out_3855454271302654333[20] = 1.0;
   out_3855454271302654333[21] = 0;
   out_3855454271302654333[22] = 0;
   out_3855454271302654333[23] = 0;
   out_3855454271302654333[24] = 0;
   out_3855454271302654333[25] = 0;
   out_3855454271302654333[26] = 0;
   out_3855454271302654333[27] = 0;
   out_3855454271302654333[28] = 0;
   out_3855454271302654333[29] = 0;
   out_3855454271302654333[30] = 1.0;
   out_3855454271302654333[31] = 0;
   out_3855454271302654333[32] = 0;
   out_3855454271302654333[33] = 0;
   out_3855454271302654333[34] = 0;
   out_3855454271302654333[35] = 0;
   out_3855454271302654333[36] = 0;
   out_3855454271302654333[37] = 0;
   out_3855454271302654333[38] = 0;
   out_3855454271302654333[39] = 0;
   out_3855454271302654333[40] = 1.0;
   out_3855454271302654333[41] = 0;
   out_3855454271302654333[42] = 0;
   out_3855454271302654333[43] = 0;
   out_3855454271302654333[44] = 0;
   out_3855454271302654333[45] = 0;
   out_3855454271302654333[46] = 0;
   out_3855454271302654333[47] = 0;
   out_3855454271302654333[48] = 0;
   out_3855454271302654333[49] = 0;
   out_3855454271302654333[50] = 1.0;
   out_3855454271302654333[51] = 0;
   out_3855454271302654333[52] = 0;
   out_3855454271302654333[53] = 0;
   out_3855454271302654333[54] = 0;
   out_3855454271302654333[55] = 0;
   out_3855454271302654333[56] = 0;
   out_3855454271302654333[57] = 0;
   out_3855454271302654333[58] = 0;
   out_3855454271302654333[59] = 0;
   out_3855454271302654333[60] = 1.0;
   out_3855454271302654333[61] = 0;
   out_3855454271302654333[62] = 0;
   out_3855454271302654333[63] = 0;
   out_3855454271302654333[64] = 0;
   out_3855454271302654333[65] = 0;
   out_3855454271302654333[66] = 0;
   out_3855454271302654333[67] = 0;
   out_3855454271302654333[68] = 0;
   out_3855454271302654333[69] = 0;
   out_3855454271302654333[70] = 1.0;
   out_3855454271302654333[71] = 0;
   out_3855454271302654333[72] = 0;
   out_3855454271302654333[73] = 0;
   out_3855454271302654333[74] = 0;
   out_3855454271302654333[75] = 0;
   out_3855454271302654333[76] = 0;
   out_3855454271302654333[77] = 0;
   out_3855454271302654333[78] = 0;
   out_3855454271302654333[79] = 0;
   out_3855454271302654333[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3046888606918275198) {
   out_3046888606918275198[0] = state[0];
   out_3046888606918275198[1] = state[1];
   out_3046888606918275198[2] = state[2];
   out_3046888606918275198[3] = state[3];
   out_3046888606918275198[4] = state[4];
   out_3046888606918275198[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3046888606918275198[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3046888606918275198[7] = state[7];
   out_3046888606918275198[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5302708174877967124) {
   out_5302708174877967124[0] = 1;
   out_5302708174877967124[1] = 0;
   out_5302708174877967124[2] = 0;
   out_5302708174877967124[3] = 0;
   out_5302708174877967124[4] = 0;
   out_5302708174877967124[5] = 0;
   out_5302708174877967124[6] = 0;
   out_5302708174877967124[7] = 0;
   out_5302708174877967124[8] = 0;
   out_5302708174877967124[9] = 0;
   out_5302708174877967124[10] = 1;
   out_5302708174877967124[11] = 0;
   out_5302708174877967124[12] = 0;
   out_5302708174877967124[13] = 0;
   out_5302708174877967124[14] = 0;
   out_5302708174877967124[15] = 0;
   out_5302708174877967124[16] = 0;
   out_5302708174877967124[17] = 0;
   out_5302708174877967124[18] = 0;
   out_5302708174877967124[19] = 0;
   out_5302708174877967124[20] = 1;
   out_5302708174877967124[21] = 0;
   out_5302708174877967124[22] = 0;
   out_5302708174877967124[23] = 0;
   out_5302708174877967124[24] = 0;
   out_5302708174877967124[25] = 0;
   out_5302708174877967124[26] = 0;
   out_5302708174877967124[27] = 0;
   out_5302708174877967124[28] = 0;
   out_5302708174877967124[29] = 0;
   out_5302708174877967124[30] = 1;
   out_5302708174877967124[31] = 0;
   out_5302708174877967124[32] = 0;
   out_5302708174877967124[33] = 0;
   out_5302708174877967124[34] = 0;
   out_5302708174877967124[35] = 0;
   out_5302708174877967124[36] = 0;
   out_5302708174877967124[37] = 0;
   out_5302708174877967124[38] = 0;
   out_5302708174877967124[39] = 0;
   out_5302708174877967124[40] = 1;
   out_5302708174877967124[41] = 0;
   out_5302708174877967124[42] = 0;
   out_5302708174877967124[43] = 0;
   out_5302708174877967124[44] = 0;
   out_5302708174877967124[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5302708174877967124[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5302708174877967124[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5302708174877967124[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5302708174877967124[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5302708174877967124[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5302708174877967124[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5302708174877967124[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5302708174877967124[53] = -9.8000000000000007*dt;
   out_5302708174877967124[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5302708174877967124[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5302708174877967124[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5302708174877967124[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5302708174877967124[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5302708174877967124[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5302708174877967124[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5302708174877967124[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5302708174877967124[62] = 0;
   out_5302708174877967124[63] = 0;
   out_5302708174877967124[64] = 0;
   out_5302708174877967124[65] = 0;
   out_5302708174877967124[66] = 0;
   out_5302708174877967124[67] = 0;
   out_5302708174877967124[68] = 0;
   out_5302708174877967124[69] = 0;
   out_5302708174877967124[70] = 1;
   out_5302708174877967124[71] = 0;
   out_5302708174877967124[72] = 0;
   out_5302708174877967124[73] = 0;
   out_5302708174877967124[74] = 0;
   out_5302708174877967124[75] = 0;
   out_5302708174877967124[76] = 0;
   out_5302708174877967124[77] = 0;
   out_5302708174877967124[78] = 0;
   out_5302708174877967124[79] = 0;
   out_5302708174877967124[80] = 1;
}
void h_25(double *state, double *unused, double *out_8951489129296429946) {
   out_8951489129296429946[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7492389928257591884) {
   out_7492389928257591884[0] = 0;
   out_7492389928257591884[1] = 0;
   out_7492389928257591884[2] = 0;
   out_7492389928257591884[3] = 0;
   out_7492389928257591884[4] = 0;
   out_7492389928257591884[5] = 0;
   out_7492389928257591884[6] = 1;
   out_7492389928257591884[7] = 0;
   out_7492389928257591884[8] = 0;
}
void h_24(double *state, double *unused, double *out_5227397427983060307) {
   out_5227397427983060307[0] = state[4];
   out_5227397427983060307[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5319740329252092318) {
   out_5319740329252092318[0] = 0;
   out_5319740329252092318[1] = 0;
   out_5319740329252092318[2] = 0;
   out_5319740329252092318[3] = 0;
   out_5319740329252092318[4] = 1;
   out_5319740329252092318[5] = 0;
   out_5319740329252092318[6] = 0;
   out_5319740329252092318[7] = 0;
   out_5319740329252092318[8] = 0;
   out_5319740329252092318[9] = 0;
   out_5319740329252092318[10] = 0;
   out_5319740329252092318[11] = 0;
   out_5319740329252092318[12] = 0;
   out_5319740329252092318[13] = 0;
   out_5319740329252092318[14] = 1;
   out_5319740329252092318[15] = 0;
   out_5319740329252092318[16] = 0;
   out_5319740329252092318[17] = 0;
}
void h_30(double *state, double *unused, double *out_855377467694579786) {
   out_855377467694579786[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8436021186944711105) {
   out_8436021186944711105[0] = 0;
   out_8436021186944711105[1] = 0;
   out_8436021186944711105[2] = 0;
   out_8436021186944711105[3] = 0;
   out_8436021186944711105[4] = 1;
   out_8436021186944711105[5] = 0;
   out_8436021186944711105[6] = 0;
   out_8436021186944711105[7] = 0;
   out_8436021186944711105[8] = 0;
}
void h_26(double *state, double *unused, double *out_2823045465769633222) {
   out_2823045465769633222[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3750886609383535660) {
   out_3750886609383535660[0] = 0;
   out_3750886609383535660[1] = 0;
   out_3750886609383535660[2] = 0;
   out_3750886609383535660[3] = 0;
   out_3750886609383535660[4] = 0;
   out_3750886609383535660[5] = 0;
   out_3750886609383535660[6] = 0;
   out_3750886609383535660[7] = 1;
   out_3750886609383535660[8] = 0;
}
void h_27(double *state, double *unused, double *out_3949815861635584301) {
   out_3949815861635584301[0] = state[3];
}
void H_27(double *state, double *unused, double *out_789930286329558775) {
   out_789930286329558775[0] = 0;
   out_789930286329558775[1] = 0;
   out_789930286329558775[2] = 0;
   out_789930286329558775[3] = 1;
   out_789930286329558775[4] = 0;
   out_789930286329558775[5] = 0;
   out_789930286329558775[6] = 0;
   out_789930286329558775[7] = 0;
   out_789930286329558775[8] = 0;
}
void h_29(double *state, double *unused, double *out_1002089871280099340) {
   out_1002089871280099340[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7925789842630318921) {
   out_7925789842630318921[0] = 0;
   out_7925789842630318921[1] = 1;
   out_7925789842630318921[2] = 0;
   out_7925789842630318921[3] = 0;
   out_7925789842630318921[4] = 0;
   out_7925789842630318921[5] = 0;
   out_7925789842630318921[6] = 0;
   out_7925789842630318921[7] = 0;
   out_7925789842630318921[8] = 0;
}
void h_28(double *state, double *unused, double *out_2967731768300286189) {
   out_2967731768300286189[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5438555214009702121) {
   out_5438555214009702121[0] = 1;
   out_5438555214009702121[1] = 0;
   out_5438555214009702121[2] = 0;
   out_5438555214009702121[3] = 0;
   out_5438555214009702121[4] = 0;
   out_5438555214009702121[5] = 0;
   out_5438555214009702121[6] = 0;
   out_5438555214009702121[7] = 0;
   out_5438555214009702121[8] = 0;
}
void h_31(double *state, double *unused, double *out_9220060882128615781) {
   out_9220060882128615781[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3124678507150184184) {
   out_3124678507150184184[0] = 0;
   out_3124678507150184184[1] = 0;
   out_3124678507150184184[2] = 0;
   out_3124678507150184184[3] = 0;
   out_3124678507150184184[4] = 0;
   out_3124678507150184184[5] = 0;
   out_3124678507150184184[6] = 0;
   out_3124678507150184184[7] = 0;
   out_3124678507150184184[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_6577315047741695773) {
  err_fun(nom_x, delta_x, out_6577315047741695773);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1977980201720716769) {
  inv_err_fun(nom_x, true_x, out_1977980201720716769);
}
void car_H_mod_fun(double *state, double *out_3855454271302654333) {
  H_mod_fun(state, out_3855454271302654333);
}
void car_f_fun(double *state, double dt, double *out_3046888606918275198) {
  f_fun(state,  dt, out_3046888606918275198);
}
void car_F_fun(double *state, double dt, double *out_5302708174877967124) {
  F_fun(state,  dt, out_5302708174877967124);
}
void car_h_25(double *state, double *unused, double *out_8951489129296429946) {
  h_25(state, unused, out_8951489129296429946);
}
void car_H_25(double *state, double *unused, double *out_7492389928257591884) {
  H_25(state, unused, out_7492389928257591884);
}
void car_h_24(double *state, double *unused, double *out_5227397427983060307) {
  h_24(state, unused, out_5227397427983060307);
}
void car_H_24(double *state, double *unused, double *out_5319740329252092318) {
  H_24(state, unused, out_5319740329252092318);
}
void car_h_30(double *state, double *unused, double *out_855377467694579786) {
  h_30(state, unused, out_855377467694579786);
}
void car_H_30(double *state, double *unused, double *out_8436021186944711105) {
  H_30(state, unused, out_8436021186944711105);
}
void car_h_26(double *state, double *unused, double *out_2823045465769633222) {
  h_26(state, unused, out_2823045465769633222);
}
void car_H_26(double *state, double *unused, double *out_3750886609383535660) {
  H_26(state, unused, out_3750886609383535660);
}
void car_h_27(double *state, double *unused, double *out_3949815861635584301) {
  h_27(state, unused, out_3949815861635584301);
}
void car_H_27(double *state, double *unused, double *out_789930286329558775) {
  H_27(state, unused, out_789930286329558775);
}
void car_h_29(double *state, double *unused, double *out_1002089871280099340) {
  h_29(state, unused, out_1002089871280099340);
}
void car_H_29(double *state, double *unused, double *out_7925789842630318921) {
  H_29(state, unused, out_7925789842630318921);
}
void car_h_28(double *state, double *unused, double *out_2967731768300286189) {
  h_28(state, unused, out_2967731768300286189);
}
void car_H_28(double *state, double *unused, double *out_5438555214009702121) {
  H_28(state, unused, out_5438555214009702121);
}
void car_h_31(double *state, double *unused, double *out_9220060882128615781) {
  h_31(state, unused, out_9220060882128615781);
}
void car_H_31(double *state, double *unused, double *out_3124678507150184184) {
  H_31(state, unused, out_3124678507150184184);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);

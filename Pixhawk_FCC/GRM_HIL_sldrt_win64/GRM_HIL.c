/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.71
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Dec 12 15:00:53 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GRM_HIL.h"
#include "GRM_HIL_private.h"
#include "GRM_HIL_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* options for Simulink Desktop Real-Time board 1 */
static double SLDRTBoardOptions1[] = {
  0.0,
  36880.0,
  49.0,
  46.0,
  49.0,
  46.0,
  49.0,
  46.0,
  49.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "Standard_Devices/Serial_Port", 3U, 8, SLDRTBoardOptions0 },

  { "Standard_Devices/UDP_Protocol", 36864U, 256, SLDRTBoardOptions1 },
};

/* Block signals (default storage) */
B_GRM_HIL_T GRM_HIL_B;

/* Continuous states */
X_GRM_HIL_T GRM_HIL_X;

/* Block states (default storage) */
DW_GRM_HIL_T GRM_HIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_GRM_HIL_T GRM_HIL_PrevZCX;

/* Real-time model */
RT_MODEL_GRM_HIL_T GRM_HIL_M_;
RT_MODEL_GRM_HIL_T *const GRM_HIL_M = &GRM_HIL_M_;

/* Forward declaration for local functions */
static void GRM_HIL_nullAssignment(real_T x_data[], int32_T x_size[2], const
  boolean_T idx_data[], const int32_T idx_size[2]);
static void rate_scheduler(void);
uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0;
  }

  return bpIndex;
}

real_T intrp3d_l_pw(const uint32_T bpIndex[], const real_T frac[], const real_T
                    table[], const uint32_T stride[])
{
  real_T yL_2d;
  uint32_T offset_2d;
  real_T yL_1d;
  uint32_T offset_0d;

  /* Column-major Interpolation 3-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_2d = (bpIndex[2U] * stride[2U] + bpIndex[1U] * stride[1U]) + bpIndex[0U];
  yL_1d = (table[offset_2d + 1U] - table[offset_2d]) * frac[0U] +
    table[offset_2d];
  offset_0d = offset_2d + stride[1U];
  yL_2d = (((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
            table[offset_0d]) - yL_1d) * frac[1U] + yL_1d;
  offset_2d += stride[2U];
  yL_1d = (table[offset_2d + 1U] - table[offset_2d]) * frac[0U] +
    table[offset_2d];
  offset_0d = offset_2d + stride[1U];
  return (((((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
             table[offset_0d]) - yL_1d) * frac[1U] + yL_1d) - yL_2d) * frac[2U]
    + yL_2d;
}

real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T y;
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
  }

  return y;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (GRM_HIL_M->Timing.TaskCounters.TID[2])++;
  if ((GRM_HIL_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.002s, 0.0s] */
    GRM_HIL_M->Timing.TaskCounters.TID[2] = 0;
  }

  GRM_HIL_M->Timing.sampleHits[2] = (GRM_HIL_M->Timing.TaskCounters.TID[2] == 0);
  (GRM_HIL_M->Timing.TaskCounters.TID[3])++;
  if ((GRM_HIL_M->Timing.TaskCounters.TID[3]) > 4) {/* Sample time: [0.005s, 0.0s] */
    GRM_HIL_M->Timing.TaskCounters.TID[3] = 0;
  }

  GRM_HIL_M->Timing.sampleHits[3] = (GRM_HIL_M->Timing.TaskCounters.TID[3] == 0);
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 37;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  GRM_HIL_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  GRM_HIL_output();
  GRM_HIL_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  GRM_HIL_output();
  GRM_HIL_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S26>/Counter_with_external_limit'
 *    '<S35>/Counter_with_external_limit'
 */
void GRM_HIL_Counter_with_external_limit(real_T rtu_limit, real_T rtu_last_value,
  B_Counter_with_external_limit_GRM_HIL_T *localB)
{
  if (rtu_last_value < rtu_limit) {
    localB->value = rtu_last_value + 1.0;
  } else {
    localB->value = 0.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S125>/Limiting_Acceleration'
 *    '<S126>/Limiting_Acceleration'
 *    '<S127>/Limiting_Acceleration'
 *    '<S128>/Limiting_Acceleration'
 */
void GRM_HIL_Limiting_Acceleration(real_T rtu_siB, real_T rtu_d_siB, real_T
  rtu_dd_siB, B_Limiting_Acceleration_GRM_HIL_T *localB, real_T rtp_d_siB_max,
  real_T rtp_d_siB_min, real_T rtp_dd_siB_max, real_T rtp_dd_siB_min, real_T
  rtp_siB_max, real_T rtp_siB_min)
{
  localB->dd_siB_l = rtu_dd_siB;
  if (rtu_dd_siB < rtp_dd_siB_min) {
    localB->dd_siB_l = rtp_dd_siB_min;
  } else {
    if (rtp_dd_siB_max < rtu_dd_siB) {
      localB->dd_siB_l = rtp_dd_siB_max;
    }
  }

  if (((rtu_siB <= rtp_siB_min) && (rtu_d_siB < 0.0)) || ((rtp_siB_max <=
        rtu_siB) && (0.0 < rtu_d_siB))) {
    localB->dd_siB_l = 0.0;
  }

  if (((rtu_d_siB <= rtp_d_siB_min) && (rtu_dd_siB < 0.0)) || ((rtp_d_siB_max <=
        rtu_d_siB) && (0.0 < rtu_dd_siB))) {
    localB->dd_siB_l = 0.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S125>/Limiting_Rate'
 *    '<S126>/Limiting_Rate'
 *    '<S127>/Limiting_Rate'
 *    '<S128>/Limiting_Rate'
 */
void GRM_HIL_Limiting_Rate(real_T rtu_siB, real_T rtu_d_siB,
  B_Limiting_Rate_GRM_HIL_T *localB, real_T rtp_d_siB_max, real_T rtp_d_siB_min,
  real_T rtp_siB_max, real_T rtp_siB_min)
{
  localB->d_siB_l = rtu_d_siB;
  if (rtu_d_siB < rtp_d_siB_min) {
    localB->d_siB_l = rtp_d_siB_min;
  } else {
    if (rtp_d_siB_max < rtu_d_siB) {
      localB->d_siB_l = rtp_d_siB_max;
    }
  }

  if (((rtu_siB <= rtp_siB_min) && (rtu_d_siB < 0.0)) || ((rtp_siB_max <=
        rtu_siB) && (0.0 < rtu_d_siB))) {
    localB->d_siB_l = 0.0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S22>/ExtractMessage' */
static void GRM_HIL_nullAssignment(real_T x_data[], int32_T x_size[2], const
  boolean_T idx_data[], const int32_T idx_size[2])
{
  int32_T nxout;
  int32_T k0;
  int32_T k;
  nxout = 0;
  for (k0 = 0; k0 < idx_size[1]; k0++) {
    nxout += idx_data[k0];
  }

  nxout = x_size[1] - nxout;
  k0 = -1;
  for (k = 0; k < x_size[1]; k++) {
    if ((k + 1 > idx_size[1]) || (!idx_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }

  if (1 > nxout) {
    x_size[1] = 0;
  } else {
    x_size[1] = nxout;
  }
}

void rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(const real_T u0[9], const real_T u1[3],
  real_T y[3])
{
  real_T A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&A[0], &u0[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u0[0]);
  a21 = fabs(u0[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u0[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u0[r2] / u0[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (fabs(A[r3 + 3]) > fabs(A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  y[1] = u1[r2] - u1[r1] * A[r2];
  y[2] = (u1[r3] - u1[r1] * A[r3]) - A[r3 + 3] * y[1];
  y[2] /= A[r3 + 6];
  y[0] = u1[r1] - A[r1 + 6] * y[2];
  y[1] -= A[r2 + 6] * y[2];
  y[1] /= A[r2 + 3];
  y[0] -= A[r1 + 3] * y[1];
  y[0] /= A[r1];
}

/* Model output function */
void GRM_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_siB;
  real_T rtb_siB_d;
  real_T rtb_siB_i;
  real_T rtb_siB_o;
  real_T rtb_d_siB;
  real_T rtb_d_siB_l;
  real_T rtb_d_siB_f;
  real_T rtb_d_siB_k;
  real_T rtb_dd_siB;
  real_T rtb_dd_siB_c;
  real_T rtb_dd_siB_o;
  real_T rtb_dd_siB_od;
  real_T rtb_Add_a;
  real_T rtb_Memory;
  real_T rtb_Add_d;
  real_T rtb_Memory_m;
  boolean_T rtb_PacketInput_o3;
  boolean_T rtb_PacketInput_o2;
  boolean_T rtb_error;
  ZCEventType zcEvent;
  real_T *lastU;
  boolean_T packetfound;
  uint8_T packet_data[77];
  real_T start_data[78];
  boolean_T x[78];
  int8_T ii_data[78];
  boolean_T p;
  int32_T idx;
  uint16_T PixHeartbeat;
  real32_T TestSignal;
  real32_T ServoCMD1;
  real32_T ServoCMD2;
  real32_T ServoCMD3;
  real32_T ServoCMD4;
  real32_T SensorACC1;
  real32_T SensorACC2;
  real32_T SensorACC3;
  real32_T SensorROT1;
  real32_T SensorROT2;
  real32_T SensorROT3;
  real32_T quaternion1;
  real32_T quaternion2;
  real32_T quaternion3;
  real32_T quaternion4;
  uint8_T x_0[2];
  uint8_T b_x[4];
  uint8_T package[56];
  uint8_T c_y[4];
  uint8_T d_y[4];
  uint8_T e_y[4];
  uint8_T f_y[4];
  uint8_T g_y[4];
  uint8_T h_y[4];
  uint8_T i_y[4];
  uint8_T j_y[4];
  uint8_T k_y[4];
  uint8_T l_y[4];
  uint8_T m_y[4];
  uint8_T n_y[4];
  real_T rtb_Subtract_cl;
  real_T rtb_Tmp;
  real_T rtb_Step1;
  real_T rtb_siB_h[4];
  real_T rtb_Product4_n[4];
  real_T rtb_Switch1;
  uint32_T rtb_k_Mach;
  uint32_T rtb_k_alB;
  real_T rtb_Subtract_ju;
  uint32_T rtb_k_beB;
  real_T rtb_f_beB;
  real_T rtb_siB_c5;
  real_T rtb_Cx;
  real_T rtb_Product1_m[3];
  real_T rtb_Gain_g;
  real_T rtb_Product_l;
  real_T rtb_Gain_lt;
  real_T rtb_Product1;
  real_T rtb_Gain_af;
  real_T rtb_Gain_fl;
  real_T rtb_Product3_hu;
  real_T rtb_Gain_nk;
  real_T rtb_Product4_e;
  real_T rtb_Gain_n;
  real_T rtb_Product5;
  real_T rtb_Product6_n4;
  real_T rtb_Product6_e;
  real_T rtb_d_qGE[4];
  real_T rtb_VectorConcatenate3[9];
  uint16_T rtb_FixPtSum1;
  real_T rtb_d_qBI[4];
  real_T rtb_JBBB[9];
  real_T rtb_Add;
  real_T rtb_pBEE[3];
  real_T rtb_Sqrt_j;
  real_T rtb_lat;
  real_T rtb_vBEB_a[3];
  real_T rtb_TBG[9];
  real_T rtb_sincos_o2[3];
  real_T rtb_MathFunction2[9];
  real_T frac[3];
  uint32_T bpIndex[3];
  real_T frac_0[3];
  uint32_T bpIndex_0[3];
  real_T frac_1[3];
  uint32_T bpIndex_1[3];
  real_T frac_2[3];
  uint32_T bpIndex_2[3];
  real_T frac_3[3];
  uint32_T bpIndex_3[3];
  real_T frac_4[3];
  uint32_T bpIndex_4[3];
  real_T frac_5[3];
  uint32_T bpIndex_5[3];
  real_T frac_6[3];
  uint32_T bpIndex_6[3];
  real_T frac_7[3];
  uint32_T bpIndex_7[3];
  real_T frac_8[3];
  uint32_T bpIndex_8[3];
  real_T frac_9[3];
  uint32_T bpIndex_9[3];
  real_T frac_a[3];
  uint32_T bpIndex_a[3];
  real_T frac_b[3];
  uint32_T bpIndex_b[3];
  real_T frac_c[3];
  uint32_T bpIndex_c[3];
  real_T frac_d[3];
  uint32_T bpIndex_d[3];
  real_T frac_e[3];
  uint32_T bpIndex_e[3];
  real_T frac_f[3];
  uint32_T bpIndex_f[3];
  real_T frac_g[3];
  uint32_T bpIndex_g[3];
  real_T frac_h[3];
  uint32_T bpIndex_h[3];
  real_T frac_i[3];
  uint32_T bpIndex_i[3];
  real_T frac_j[3];
  uint32_T bpIndex_j[3];
  real_T frac_k[3];
  uint32_T bpIndex_k[3];
  real_T frac_l[3];
  uint32_T bpIndex_l[3];
  real_T frac_m[3];
  uint32_T bpIndex_m[3];
  real_T frac_n[3];
  uint32_T bpIndex_n[3];
  real_T frac_o[3];
  uint32_T bpIndex_o[3];
  real_T frac_p[3];
  uint32_T bpIndex_p[3];
  real_T frac_q[3];
  uint32_T bpIndex_q[3];
  real_T frac_r[3];
  uint32_T bpIndex_r[3];
  real_T frac_s[3];
  uint32_T bpIndex_s[3];
  real_T frac_t[3];
  uint32_T bpIndex_t[3];
  real_T frac_u[3];
  uint32_T bpIndex_u[3];
  real_T frac_v[3];
  uint32_T bpIndex_v[3];
  real_T frac_w[3];
  uint32_T bpIndex_w[3];
  real_T frac_x[3];
  uint32_T bpIndex_x[3];
  real_T frac_y[3];
  uint32_T bpIndex_y[3];
  real_T frac_z[3];
  uint32_T bpIndex_z[3];
  real_T frac_10[3];
  uint32_T bpIndex_10[3];
  real_T frac_11[3];
  uint32_T bpIndex_11[3];
  real_T frac_12[3];
  uint32_T bpIndex_12[3];
  real_T frac_13[3];
  uint32_T bpIndex_13[3];
  real_T frac_14[3];
  uint32_T bpIndex_14[3];
  real_T frac_15[3];
  uint32_T bpIndex_15[3];
  real_T frac_16[3];
  uint32_T bpIndex_16[3];
  real_T frac_17[3];
  uint32_T bpIndex_17[3];
  real_T rtb_MultiportSwitch[9];
  real_T rtb_MultiportSwitch1[9];
  real_T rtb_MultiportSwitch2[9];
  uint8_T rtb_message[64];
  uint8_T MessageToSend[128];
  real_T rtb_MatrixMultiply_tmp[9];
  real_T rtb_vBEB_a_tmp[9];
  int32_T i;
  int32_T loop_ub;
  real_T tmp[16];
  int32_T start_size[2];
  int32_T tmp_size[2];
  int32_T start_size_0[2];
  real_T rtb_VectorConcatenate_f_idx_2;
  real_T rtb_VectorConcatenate_f_idx_1;
  real_T rtb_VectorConcatenate_f_idx_0;
  real_T rtb_Product_idx_2;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_0;
  real_T rtb_Product_idx_3;
  real_T u0;
  real_T rtb_TBG_tmp;
  real_T rtb_TBG_tmp_0;
  real_T rtb_TBG_tmp_1;
  real_T rtb_TBG_tmp_2;
  real_T rtb_TBG_tmp_3;
  real_T rtb_TBG_tmp_4;
  real_T rtb_Gain1_n4_tmp;
  real_T rtb_Switch1_tmp;
  real_T frac_tmp;
  real_T frac_tmp_0;
  real_T rtb_Cx_tmp;
  real_T rtb_Subtract_ay_tmp;
  real_T rtb_TBG_tmp_5;
  int32_T rtb_MultiportSwitch1_tmp;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    /* set solver stop time */
    if (!(GRM_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&GRM_HIL_M->solverInfo,
                            ((GRM_HIL_M->Timing.clockTickH0 + 1) *
        GRM_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&GRM_HIL_M->solverInfo,
                            ((GRM_HIL_M->Timing.clockTick0 + 1) *
        GRM_HIL_M->Timing.stepSize0 + GRM_HIL_M->Timing.clockTickH0 *
        GRM_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(GRM_HIL_M)) {
    GRM_HIL_M->Timing.t[0] = rtsiGetT(&GRM_HIL_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Receive_ExternalMode_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.hold_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.input_hold_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Send_ExternalMode_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.no_CRC_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.send_to_pix_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Construct_Bus_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S182>/Constant' */
    memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
           (real_T));
  }

  /* Integrator: '<S189>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK != 0) {
    memcpy(&GRM_HIL_X.integration_eom_CSTATE[0], &GRM_HIL_B.Constant[0], 13U *
           sizeof(real_T));
  }

  /* Gain: '<S49>/Gain17' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.POS_z_NED_m = GRM_HIL_P.Gain17_Gain *
    GRM_HIL_X.integration_eom_CSTATE[2];

  /* RelationalOperator: '<S242>/Compare' incorporates:
   *  Constant: '<S242>/Constant'
   */
  GRM_HIL_B.Compare = (GRM_HIL_B.POS_z_NED_m >=
                       GRM_HIL_P.CompareToConstant_const);

  /* Stop: '<S8>/Stop Simulation' */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && GRM_HIL_B.Compare) {
    rtmSetStopRequested(GRM_HIL_M, 1);
  }

  /* End of Stop: '<S8>/Stop Simulation' */

  /* Gain: '<S12>/Gain' incorporates:
   *  TransferFcn: '<S11>/Transfer Fcn'
   */
  GRM_HIL_B.Fin_1_Pos_rad = (GRM_HIL_P.Servo_TF.Servo1_Numerator_Coefs /
    GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[0] *
    GRM_HIL_X.TransferFcn_CSTATE[1] + 0.0 * GRM_HIL_X.TransferFcn_CSTATE[0]) *
    GRM_HIL_P.Gain_Gain_pl;

  /* TransferFcn: '<S11>/Transfer Fcn1' incorporates:
   *  TransferFcn: '<S11>/Transfer Fcn2'
   *  TransferFcn: '<S11>/Transfer Fcn3'
   */
  rtb_Product_idx_0 = GRM_HIL_P.Servo_TF.Servo2_Numerator_Coefs /
    GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[0];

  /* Gain: '<S12>/Gain1' incorporates:
   *  TransferFcn: '<S11>/Transfer Fcn1'
   */
  GRM_HIL_B.Fin_2_Pos_rad = (rtb_Product_idx_0 * GRM_HIL_X.TransferFcn1_CSTATE[1]
    + 0.0 * GRM_HIL_X.TransferFcn1_CSTATE[0]) * GRM_HIL_P.Gain1_Gain_j5;

  /* Gain: '<S12>/Gain2' incorporates:
   *  TransferFcn: '<S11>/Transfer Fcn2'
   */
  GRM_HIL_B.Fin_3_Pos_rad = (rtb_Product_idx_0 * GRM_HIL_X.TransferFcn2_CSTATE[1]
    + 0.0 * GRM_HIL_X.TransferFcn2_CSTATE[0]) * GRM_HIL_P.Gain2_Gain_g;

  /* Gain: '<S12>/Gain3' incorporates:
   *  TransferFcn: '<S11>/Transfer Fcn3'
   */
  GRM_HIL_B.Fin_4_Pos_rad = (rtb_Product_idx_0 * GRM_HIL_X.TransferFcn3_CSTATE[1]
    + 0.0 * GRM_HIL_X.TransferFcn3_CSTATE[0]) * GRM_HIL_P.Gain3_Gain_d;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S10>/Constant' */
    GRM_HIL_B.A = GRM_HIL_P.Constant_Value_ei;

    /* Constant: '<S10>/Constant1' */
    GRM_HIL_B.B = GRM_HIL_P.Constant1_Value_d;

    /* Constant: '<S10>/Constant2' */
    GRM_HIL_B.Z = GRM_HIL_P.Constant2_Value_h;

    /* Constant: '<S10>/Constant3' */
    GRM_HIL_B.A_i = GRM_HIL_P.Constant3_Value_o;

    /* Constant: '<S10>/Constant4' */
    GRM_HIL_B.B_d = GRM_HIL_P.Constant4_Value_om;

    /* Constant: '<S10>/Constant5' */
    GRM_HIL_B.Z_d = GRM_HIL_P.Constant5_Value_m;

    /* Constant: '<S10>/Constant6' */
    GRM_HIL_B.A_m = GRM_HIL_P.Constant6_Value_d;

    /* Constant: '<S10>/Constant7' */
    GRM_HIL_B.B_c = GRM_HIL_P.Constant7_Value_ny;

    /* Constant: '<S10>/Constant8' */
    GRM_HIL_B.Z_h = GRM_HIL_P.Constant8_Value_lk;

    /* Constant: '<S10>/Constant9' */
    GRM_HIL_B.A_f = GRM_HIL_P.Constant9_Value_e;

    /* Constant: '<S10>/Constant10' */
    GRM_HIL_B.B_n = GRM_HIL_P.Constant10_Value_j;

    /* Constant: '<S10>/Constant11' */
    GRM_HIL_B.Z_l = GRM_HIL_P.Constant11_Value_i;

    /* ToAsyncQueueBlock generated from: '<Root>/Actuators' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_1_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1533596113U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_2_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2108015381U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_3_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3897222426U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_4_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1486197303U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(150556468U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(131087738U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(559979152U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_i;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3577981102U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1799768454U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(751118283U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1265596107U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_c;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4294716106U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2117412826U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_f;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4285785062U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_n;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(926773787U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2827069962U, time, pData, size);
      }
    }

    /* S-Function (sldrtpi): '<S34>/Receive_from_FTHWICC' */
    /* S-Function Block: <S34>/Receive_from_FTHWICC */
    {
      uint8_T indata[66U];
      int status = RTBIO_DriverIO(1, STREAMINPUT, IOREAD, 66U,
        &GRM_HIL_P.Receive_from_FTHWICC_PacketID, (double*) indata, NULL);
      rtb_PacketInput_o2 = (status>>1) & 0x1;/* Data Error port */
      rtb_PacketInput_o3 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;
        GRM_HIL_B.Receive_from_FTHWICC_o1 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o2 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o3 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o4 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o5 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o6 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o7 = *indp.p_real_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o8 = *indp.p_uint16_T++;
        GRM_HIL_B.Receive_from_FTHWICC_o9 = *indp.p_real_T++;
      }
    }

    /* Outputs for Enabled SubSystem: '<S34>/Construct_Bus' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    /* Logic: '<S34>/Logical Operator' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S40>/Constant10'
     *  Constant: '<S40>/Constant11'
     *  Constant: '<S40>/Constant2'
     *  Constant: '<S40>/Constant3'
     *  Constant: '<S40>/Constant4'
     *  Constant: '<S40>/Constant5'
     *  Constant: '<S40>/Constant6'
     *  Constant: '<S40>/Constant7'
     *  Constant: '<S40>/Constant8'
     *  Constant: '<S40>/Constant9'
     *  Logic: '<S34>/NOT'
     *  Trigonometry: '<S42>/sincos'
     */
    if (rtb_PacketInput_o3 && (!rtb_PacketInput_o2)) {
      /* SignalConversion generated from: '<S36>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_operational_flg = GRM_HIL_B.Receive_from_FTHWICC_o1;

      /* SignalConversion generated from: '<S36>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_Ramp_flg = GRM_HIL_B.Receive_from_FTHWICC_o2;

      /* SignalConversion generated from: '<S36>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_B.Receive_from_FTHWICC_o3;

      /* SignalConversion generated from: '<S36>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_B.Receive_from_FTHWICC_o4;
      GRM_HIL_B.Data_plus = GRM_HIL_P.Constant_Value_n;
      GRM_HIL_B.Data_minus = GRM_HIL_P.Constant1_Value;
      GRM_HIL_B.Clock_plus = GRM_HIL_P.Constant2_Value;
      GRM_HIL_B.Clock_minus = GRM_HIL_P.Constant3_Value;

      /* SignalConversion generated from: '<S40>/Constant1' incorporates:
       *  Constant: '<S40>/Constant'
       *  Constant: '<S40>/Constant1'
       *  Constant: '<S40>/Constant2'
       *  Constant: '<S40>/Constant3'
       */
      GRM_HIL_B.Data_minus_j = GRM_HIL_B.Data_minus;

      /* SignalConversion generated from: '<S40>/Constant2' */
      GRM_HIL_B.Clock_plus_j = GRM_HIL_B.Clock_plus;

      /* SignalConversion generated from: '<S40>/Constant3' */
      GRM_HIL_B.Clock_minus_d = GRM_HIL_B.Clock_minus;

      /* SignalConversion generated from: '<S40>/Constant' */
      GRM_HIL_B.Data_plus_p = GRM_HIL_B.Data_plus;
      GRM_HIL_B.Data_plus_pq = GRM_HIL_P.Constant4_Value;
      GRM_HIL_B.Data_minus_b = GRM_HIL_P.Constant5_Value;
      GRM_HIL_B.Clock_plus_l = GRM_HIL_P.Constant6_Value;
      GRM_HIL_B.Clock_minus_c = GRM_HIL_P.Constant7_Value_a;

      /* SignalConversion generated from: '<S40>/Constant4' incorporates:
       *  Constant: '<S40>/Constant4'
       *  Constant: '<S40>/Constant5'
       *  Constant: '<S40>/Constant6'
       *  Constant: '<S40>/Constant7'
       */
      GRM_HIL_B.Data_plus_pe = GRM_HIL_B.Data_plus_pq;

      /* SignalConversion generated from: '<S40>/Constant5' */
      GRM_HIL_B.Data_minus_jy = GRM_HIL_B.Data_minus_b;

      /* SignalConversion generated from: '<S40>/Constant6' */
      GRM_HIL_B.Clock_plus_jb = GRM_HIL_B.Clock_plus_l;

      /* SignalConversion generated from: '<S40>/Constant7' */
      GRM_HIL_B.Clock_minus_d1 = GRM_HIL_B.Clock_minus_c;
      GRM_HIL_B.Clock_plus_a = GRM_HIL_P.Constant10_Value;
      GRM_HIL_B.Clock_minus_h = GRM_HIL_P.Constant11_Value_c;
      GRM_HIL_B.Data_plus_n = GRM_HIL_P.Constant8_Value;
      GRM_HIL_B.Data_minus_g = GRM_HIL_P.Constant9_Value_m;

      /* SignalConversion generated from: '<S40>/Constant10' incorporates:
       *  Constant: '<S40>/Constant10'
       *  Constant: '<S40>/Constant11'
       *  Constant: '<S40>/Constant8'
       *  Constant: '<S40>/Constant9'
       */
      GRM_HIL_B.Clock_plus_jbf = GRM_HIL_B.Clock_plus_a;

      /* SignalConversion generated from: '<S40>/Constant11' */
      GRM_HIL_B.Clock_minus_d1h = GRM_HIL_B.Clock_minus_h;

      /* SignalConversion generated from: '<S40>/Constant8' */
      GRM_HIL_B.Data_plus_pek = GRM_HIL_B.Data_plus_n;

      /* SignalConversion generated from: '<S40>/Constant9' */
      GRM_HIL_B.Data_minus_jye = GRM_HIL_B.Data_minus_g;

      /* Gain: '<S39>/Shaft2radYaw' */
      GRM_HIL_B.ATT_Psi_rad_e = GRM_HIL_P.Shaft2radYaw_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o5;

      /* Gain: '<S39>/Shaft2radPitch' */
      GRM_HIL_B.ATT_Theta_rad_e = GRM_HIL_P.Shaft2radPitch_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o6;

      /* Gain: '<S39>/Shaft2radRoll' */
      GRM_HIL_B.ATT_Phi_rad_p = GRM_HIL_P.Shaft2radRoll_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o7;

      /* Gain: '<S42>/1//2' */
      rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.u2_Gain *
        GRM_HIL_B.ATT_Psi_rad_e;
      rtb_VectorConcatenate_f_idx_1 = GRM_HIL_P.u2_Gain *
        GRM_HIL_B.ATT_Theta_rad_e;
      rtb_VectorConcatenate_f_idx_2 = GRM_HIL_P.u2_Gain *
        GRM_HIL_B.ATT_Phi_rad_p;

      /* Trigonometry: '<S42>/sincos' */
      rtb_sincos_o2[0] = cos(rtb_VectorConcatenate_f_idx_0);
      rtb_VectorConcatenate_f_idx_0 = sin(rtb_VectorConcatenate_f_idx_0);

      /* Trigonometry: '<S42>/sincos' */
      rtb_sincos_o2[1] = cos(rtb_VectorConcatenate_f_idx_1);
      rtb_VectorConcatenate_f_idx_1 = sin(rtb_VectorConcatenate_f_idx_1);

      /* Trigonometry: '<S42>/sincos' */
      rtb_sincos_o2[2] = cos(rtb_VectorConcatenate_f_idx_2);
      rtb_Product_idx_0 = sin(rtb_VectorConcatenate_f_idx_2);

      /* Fcn: '<S42>/q0' incorporates:
       *  Fcn: '<S42>/q3'
       */
      rtb_Product_idx_1 = rtb_sincos_o2[0] * rtb_sincos_o2[1];
      rtb_Product_idx_2 = rtb_VectorConcatenate_f_idx_0 *
        rtb_VectorConcatenate_f_idx_1;
      GRM_HIL_B.q0_d = rtb_Product_idx_1 * rtb_sincos_o2[2] - rtb_Product_idx_2 *
        rtb_Product_idx_0;

      /* Fcn: '<S42>/q1' incorporates:
       *  Fcn: '<S42>/q2'
       */
      rtb_Product_idx_3 = rtb_sincos_o2[0] * rtb_VectorConcatenate_f_idx_1;
      rtb_VectorConcatenate_f_idx_1 = rtb_VectorConcatenate_f_idx_0 *
        rtb_sincos_o2[1];
      GRM_HIL_B.q1_o = rtb_Product_idx_3 * rtb_Product_idx_0 +
        rtb_VectorConcatenate_f_idx_1 * rtb_sincos_o2[2];

      /* Fcn: '<S42>/q2' */
      GRM_HIL_B.q2_i = rtb_Product_idx_3 * rtb_sincos_o2[2] -
        rtb_VectorConcatenate_f_idx_1 * rtb_Product_idx_0;

      /* Fcn: '<S42>/q3' */
      GRM_HIL_B.q3_o = rtb_Product_idx_1 * rtb_Product_idx_0 + rtb_Product_idx_2
        * rtb_sincos_o2[2];

      /* SignalConversion generated from: '<S36>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_yaw_sns = GRM_HIL_B.Receive_from_FTHWICC_o5;

      /* SignalConversion generated from: '<S36>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_pitch_sns = GRM_HIL_B.Receive_from_FTHWICC_o6;

      /* SignalConversion generated from: '<S36>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_roll_sns = GRM_HIL_B.Receive_from_FTHWICC_o7;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Construct_Bus_SubsysRanBC);
      }
    }

    /* End of Logic: '<S34>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S34>/Construct_Bus' */

    /* ToAsyncQueueBlock generated from: '<Root>/Gimbal' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_operational_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4204101375U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_Ramp_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1106368433U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_Limit_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3339964882U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_StopSim_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(809391663U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad_p;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1494754325U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad_e;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(982459983U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad_e;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1814893170U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2719267787U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1_o;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(92785663U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2_i;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4291155925U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3_o;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(824796519U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_yaw_sns;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3665366077U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_pitch_sns;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1431666087U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_roll_sns;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2180223251U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_p;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1016941105U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_j;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2000626225U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_j;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1194450856U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1683558264U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_pe;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3362153872U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_jy;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(955203092U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_jb;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(116244583U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(7779213U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_pek;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(857871040U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_jye;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3672520929U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_jbf;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(882682160U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d1h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1792818526U, time, pData, size);
      }
    }
  }

  /* Sum: '<S192>/Add' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S192>/Product1'
   *  Product: '<S192>/Product2'
   *  Product: '<S192>/Product3'
   *  Product: '<S192>/Product4'
   */
  rtb_Subtract_cl = ((GRM_HIL_X.integration_eom_CSTATE[6] *
                      GRM_HIL_X.integration_eom_CSTATE[6] +
                      GRM_HIL_X.integration_eom_CSTATE[7] *
                      GRM_HIL_X.integration_eom_CSTATE[7]) +
                     GRM_HIL_X.integration_eom_CSTATE[8] *
                     GRM_HIL_X.integration_eom_CSTATE[8]) +
    GRM_HIL_X.integration_eom_CSTATE[9] * GRM_HIL_X.integration_eom_CSTATE[9];

  /* Math: '<S192>/Math Function'
   *
   * About '<S192>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Subtract_cl < 0.0) {
    rtb_Subtract_cl = -sqrt(fabs(rtb_Subtract_cl));
  } else {
    rtb_Subtract_cl = sqrt(rtb_Subtract_cl);
  }

  /* End of Math: '<S192>/Math Function' */

  /* Product: '<S192>/Product' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  rtb_Product_idx_0 = GRM_HIL_X.integration_eom_CSTATE[6] / rtb_Subtract_cl;
  rtb_Product_idx_1 = GRM_HIL_X.integration_eom_CSTATE[7] / rtb_Subtract_cl;
  rtb_Product_idx_2 = GRM_HIL_X.integration_eom_CSTATE[8] / rtb_Subtract_cl;
  rtb_Product_idx_3 = GRM_HIL_X.integration_eom_CSTATE[9] / rtb_Subtract_cl;

  /* Math: '<S147>/Math Function1' incorporates:
   *  Math: '<S147>/Math Function5'
   *  Math: '<S147>/Math Function9'
   */
  rtb_VectorConcatenate_f_idx_1 = rtb_Product_idx_1 * rtb_Product_idx_1;

  /* Math: '<S147>/Math Function' incorporates:
   *  Math: '<S147>/Math Function4'
   *  Math: '<S147>/Math Function8'
   */
  rtb_Tmp = rtb_Product_idx_0 * rtb_Product_idx_0;

  /* Math: '<S147>/Math Function2' incorporates:
   *  Math: '<S147>/Math Function10'
   *  Math: '<S147>/Math Function6'
   */
  rtb_lat = rtb_Product_idx_2 * rtb_Product_idx_2;

  /* Math: '<S147>/Math Function3' incorporates:
   *  Math: '<S147>/Math Function11'
   *  Math: '<S147>/Math Function7'
   */
  rtb_Add = rtb_Product_idx_3 * rtb_Product_idx_3;

  /* Sum: '<S147>/Add' incorporates:
   *  Math: '<S147>/Math Function'
   *  Math: '<S147>/Math Function1'
   *  Math: '<S147>/Math Function2'
   *  Math: '<S147>/Math Function3'
   *  Sum: '<S190>/Add'
   *  Switch: '<S188>/Switch'
   */
  rtb_VectorConcatenate_f_idx_2 = ((rtb_Tmp - rtb_VectorConcatenate_f_idx_1) -
    rtb_lat) + rtb_Add;
  rtb_TBG[0] = rtb_VectorConcatenate_f_idx_2;

  /* Product: '<S147>/Product' incorporates:
   *  Product: '<S147>/Product6'
   *  Product: '<S190>/Product'
   *  Product: '<S190>/Product6'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp = rtb_Product_idx_0 * rtb_Product_idx_1;

  /* Product: '<S147>/Product1' incorporates:
   *  Product: '<S147>/Product7'
   *  Product: '<S190>/Product1'
   *  Product: '<S190>/Product7'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp_0 = rtb_Product_idx_2 * rtb_Product_idx_3;

  /* Sum: '<S147>/Add1' incorporates:
   *  Gain: '<S147>/Gain1'
   *  Gain: '<S147>/Gain2'
   *  Product: '<S147>/Product'
   *  Product: '<S147>/Product1'
   */
  rtb_TBG[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_c - rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain2_Gain_c;

  /* Product: '<S147>/Product8' incorporates:
   *  Product: '<S147>/Product4'
   *  Product: '<S190>/Product4'
   *  Product: '<S190>/Product8'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp_1 = rtb_Product_idx_0 * rtb_Product_idx_2;

  /* Product: '<S147>/Product9' incorporates:
   *  Product: '<S147>/Product5'
   *  Product: '<S190>/Product5'
   *  Product: '<S190>/Product9'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp_2 = rtb_Product_idx_1 * rtb_Product_idx_3;

  /* Sum: '<S147>/Add5' incorporates:
   *  Gain: '<S147>/Gain10'
   *  Gain: '<S147>/Gain9'
   *  Product: '<S147>/Product8'
   *  Product: '<S147>/Product9'
   */
  rtb_TBG[2] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain9_Gain_c + rtb_TBG_tmp_2 *
    GRM_HIL_P.Gain10_Gain_g;

  /* Sum: '<S147>/Add4' incorporates:
   *  Gain: '<S147>/Gain7'
   *  Gain: '<S147>/Gain8'
   */
  rtb_TBG[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain_c + rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain8_Gain_b;

  /* Sum: '<S147>/Add6' incorporates:
   *  Sum: '<S190>/Add6'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp_5 = ((rtb_VectorConcatenate_f_idx_1 - rtb_Tmp) - rtb_lat) +
    rtb_Add;
  rtb_TBG[4] = rtb_TBG_tmp_5;

  /* Product: '<S147>/Product2' incorporates:
   *  Product: '<S147>/Product10'
   *  Product: '<S190>/Product10'
   *  Product: '<S190>/Product2'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp_3 = rtb_Product_idx_1 * rtb_Product_idx_2;

  /* Product: '<S147>/Product3' incorporates:
   *  Product: '<S147>/Product11'
   *  Product: '<S190>/Product11'
   *  Product: '<S190>/Product3'
   *  Switch: '<S188>/Switch'
   */
  rtb_TBG_tmp_4 = rtb_Product_idx_0 * rtb_Product_idx_3;

  /* Sum: '<S147>/Add2' incorporates:
   *  Gain: '<S147>/Gain3'
   *  Gain: '<S147>/Gain4'
   *  Product: '<S147>/Product2'
   *  Product: '<S147>/Product3'
   */
  rtb_TBG[5] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain3_Gain_p - rtb_TBG_tmp_4 *
    GRM_HIL_P.Gain4_Gain_o;

  /* Sum: '<S147>/Add3' incorporates:
   *  Gain: '<S147>/Gain5'
   *  Gain: '<S147>/Gain6'
   */
  rtb_TBG[6] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain5_Gain_l - rtb_TBG_tmp_2 *
    GRM_HIL_P.Gain6_Gain_p;

  /* Sum: '<S147>/Add8' incorporates:
   *  Gain: '<S147>/Gain11'
   *  Gain: '<S147>/Gain12'
   */
  rtb_TBG[7] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain11_Gain_d + rtb_TBG_tmp_4 *
    GRM_HIL_P.Gain12_Gain_g;

  /* Sum: '<S147>/Add7' incorporates:
   *  Sum: '<S190>/Add7'
   *  Switch: '<S188>/Switch'
   */
  rtb_VectorConcatenate_f_idx_1 = ((rtb_lat - rtb_Tmp) -
    rtb_VectorConcatenate_f_idx_1) + rtb_Add;
  rtb_TBG[8] = rtb_VectorConcatenate_f_idx_1;
  for (i = 0; i < 3; i++) {
    /* Math: '<S181>/Math Function' incorporates:
     *  Math: '<S198>/Math Function'
     */
    rtb_MatrixMultiply_tmp[3 * i] = rtb_TBG[i];
    rtb_MatrixMultiply_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_MatrixMultiply_tmp[3 * i + 2] = rtb_TBG[i + 6];
  }

  /* Product: '<S181>/Product1' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Math: '<S181>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    rtb_sincos_o2[i] = rtb_MatrixMultiply_tmp[i + 6] *
      GRM_HIL_X.integration_eom_CSTATE[5] + (rtb_MatrixMultiply_tmp[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[4] + rtb_MatrixMultiply_tmp[i] *
      GRM_HIL_X.integration_eom_CSTATE[3]);
  }

  /* End of Product: '<S181>/Product1' */

  /* Gain: '<S49>/Gain' */
  GRM_HIL_B.VEL_u_K_R_E_B_mDs = GRM_HIL_P.Gain_Gain_k1 * rtb_sincos_o2[0];

  /* Gain: '<S49>/Gain1' */
  GRM_HIL_B.VEL_v_K_R_E_B_mDs = GRM_HIL_P.Gain1_Gain_mm * rtb_sincos_o2[1];

  /* Gain: '<S49>/Gain2' */
  GRM_HIL_B.VEL_w_K_R_E_B_mDs = GRM_HIL_P.Gain2_Gain_e * rtb_sincos_o2[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S157>/Constant8' */
    GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];
    GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];
    GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];
    GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];
  }

  /* Integrator: '<S157>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_g != 0) {
    GRM_HIL_X.integration_eom_CSTATE_b[0] = GRM_HIL_B.Constant8[0];
    GRM_HIL_X.integration_eom_CSTATE_b[1] = GRM_HIL_B.Constant8[1];
    GRM_HIL_X.integration_eom_CSTATE_b[2] = GRM_HIL_B.Constant8[2];
    GRM_HIL_X.integration_eom_CSTATE_b[3] = GRM_HIL_B.Constant8[3];
  }

  /* Sum: '<S161>/Add' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Math: '<S161>/Math Function'
   *  Math: '<S161>/Math Function1'
   *  Math: '<S161>/Math Function2'
   *  Math: '<S161>/Math Function3'
   */
  rtb_VectorConcatenate3[0] = ((GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0] - GRM_HIL_X.integration_eom_CSTATE_b[1]
    * GRM_HIL_X.integration_eom_CSTATE_b[1]) -
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[2])
    + GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S161>/Add1' incorporates:
   *  Gain: '<S161>/Gain1'
   *  Gain: '<S161>/Gain2'
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S161>/Product'
   *  Product: '<S161>/Product1'
   */
  rtb_VectorConcatenate3[1] = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[1] * GRM_HIL_P.Gain1_Gain_i -
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[3]
    * GRM_HIL_P.Gain2_Gain_iy;

  /* Product: '<S161>/Product8' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S161>/Product4'
   */
  rtb_Tmp = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S161>/Product9' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S161>/Product5'
   */
  rtb_lat = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S161>/Add5' incorporates:
   *  Gain: '<S161>/Gain10'
   *  Gain: '<S161>/Gain9'
   *  Product: '<S161>/Product8'
   *  Product: '<S161>/Product9'
   */
  rtb_VectorConcatenate3[2] = rtb_Tmp * GRM_HIL_P.Gain9_Gain_g + rtb_lat *
    GRM_HIL_P.Gain10_Gain_h;

  /* Sum: '<S161>/Add4' incorporates:
   *  Gain: '<S161>/Gain7'
   *  Gain: '<S161>/Gain8'
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S161>/Product6'
   *  Product: '<S161>/Product7'
   */
  rtb_VectorConcatenate3[3] = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[1] * GRM_HIL_P.Gain7_Gain_i +
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[3]
    * GRM_HIL_P.Gain8_Gain_d;

  /* Math: '<S161>/Math Function6' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Math: '<S161>/Math Function10'
   */
  rtb_Add = GRM_HIL_X.integration_eom_CSTATE_b[2] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Math: '<S161>/Math Function4' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Math: '<S161>/Math Function8'
   */
  rtb_Sqrt_j = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0];

  /* Math: '<S161>/Math Function5' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Math: '<S161>/Math Function9'
   */
  rtb_f_beB = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];

  /* Math: '<S161>/Math Function7' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Math: '<S161>/Math Function11'
   */
  rtb_siB_c5 = GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S161>/Add6' incorporates:
   *  Math: '<S161>/Math Function4'
   *  Math: '<S161>/Math Function5'
   *  Math: '<S161>/Math Function6'
   *  Math: '<S161>/Math Function7'
   */
  rtb_VectorConcatenate3[4] = ((rtb_f_beB - rtb_Sqrt_j) - rtb_Add) + rtb_siB_c5;

  /* Product: '<S161>/Product2' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S161>/Product10'
   */
  rtb_Gain_g = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S161>/Product3' incorporates:
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S161>/Product11'
   */
  rtb_Gain_lt = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S161>/Add2' incorporates:
   *  Gain: '<S161>/Gain3'
   *  Gain: '<S161>/Gain4'
   *  Product: '<S161>/Product2'
   *  Product: '<S161>/Product3'
   */
  rtb_VectorConcatenate3[5] = rtb_Gain_g * GRM_HIL_P.Gain3_Gain_i - rtb_Gain_lt *
    GRM_HIL_P.Gain4_Gain_f;

  /* Sum: '<S161>/Add3' incorporates:
   *  Gain: '<S161>/Gain5'
   *  Gain: '<S161>/Gain6'
   */
  rtb_VectorConcatenate3[6] = rtb_Tmp * GRM_HIL_P.Gain5_Gain_i - rtb_lat *
    GRM_HIL_P.Gain6_Gain_n;

  /* Sum: '<S161>/Add8' incorporates:
   *  Gain: '<S161>/Gain11'
   *  Gain: '<S161>/Gain12'
   */
  rtb_VectorConcatenate3[7] = rtb_Gain_g * GRM_HIL_P.Gain11_Gain_n + rtb_Gain_lt
    * GRM_HIL_P.Gain12_Gain_h;

  /* Sum: '<S161>/Add7' */
  rtb_VectorConcatenate3[8] = ((rtb_Add - rtb_Sqrt_j) - rtb_f_beB) + rtb_siB_c5;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S156>/Switch' incorporates:
     *  Constant: '<S156>/Constant7'
     *  Constant: '<S156>/Constant9'
     */
    if (GRM_HIL_P.Constant9_Value_p > GRM_HIL_P.Switch_Threshold) {
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant7_Value_i;

      /* SignalConversion generated from: '<S156>/Vector Concatenate' incorporates:
       *  Constant: '<S156>/Constant6'
       *  Constant: '<S156>/Constant7'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant6_Value_j;

      /* SignalConversion generated from: '<S156>/Vector Concatenate' incorporates:
       *  Constant: '<S156>/Constant6'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant6_Value_j;
    } else {
      /* SignalConversion generated from: '<S156>/Vector Concatenate1' incorporates:
       *  Constant: '<S156>/Constant8'
       */
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant8_Value_b;

      /* SignalConversion generated from: '<S156>/Vector Concatenate1' incorporates:
       *  Constant: '<S156>/Constant8'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant8_Value_b;

      /* SignalConversion generated from: '<S156>/Vector Concatenate1' incorporates:
       *  Constant: '<S156>/Constant8'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant8_Value_b;
    }

    /* End of Switch: '<S156>/Switch' */
  }

  /* Product: '<S200>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_sincos_o2[i] = rtb_VectorConcatenate3[i + 6] * GRM_HIL_B.wIEE[2] +
      (rtb_VectorConcatenate3[i + 3] * GRM_HIL_B.wIEE[1] +
       rtb_VectorConcatenate3[i] * GRM_HIL_B.wIEE[0]);
  }

  /* End of Product: '<S200>/Product' */

  /* Sum: '<S200>/Add' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S205>/Product2'
   *  Product: '<S205>/Product3'
   *  Product: '<S205>/Product4'
   *  Product: '<S205>/Product5'
   *  Product: '<S205>/Product6'
   *  Product: '<S205>/Product7'
   *  Sum: '<S205>/Sum'
   *  Sum: '<S205>/Sum1'
   *  Sum: '<S205>/Sum2'
   */
  rtb_Product1_m[0] = GRM_HIL_X.integration_eom_CSTATE[3] - (rtb_sincos_o2[1] *
    GRM_HIL_X.integration_eom_CSTATE[2] - rtb_sincos_o2[2] *
    GRM_HIL_X.integration_eom_CSTATE[1]);
  rtb_Product1_m[1] = GRM_HIL_X.integration_eom_CSTATE[4] - (rtb_sincos_o2[2] *
    GRM_HIL_X.integration_eom_CSTATE[0] - rtb_sincos_o2[0] *
    GRM_HIL_X.integration_eom_CSTATE[2]);
  rtb_Gain_fl = GRM_HIL_X.integration_eom_CSTATE[5] - (rtb_sincos_o2[0] *
    GRM_HIL_X.integration_eom_CSTATE[1] - rtb_sincos_o2[1] *
    GRM_HIL_X.integration_eom_CSTATE[0]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S158>/Constant8' */
    GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];
    GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];
    GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];
    GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];
  }

  /* Integrator: '<S158>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_l != 0) {
    GRM_HIL_X.integration_eom_CSTATE_f[0] = GRM_HIL_B.Constant8_h[0];
    GRM_HIL_X.integration_eom_CSTATE_f[1] = GRM_HIL_B.Constant8_h[1];
    GRM_HIL_X.integration_eom_CSTATE_f[2] = GRM_HIL_B.Constant8_h[2];
    GRM_HIL_X.integration_eom_CSTATE_f[3] = GRM_HIL_B.Constant8_h[3];
  }

  /* Sum: '<S152>/Add' incorporates:
   *  Constant: '<S152>/Q_1'
   *  Constant: '<S152>/Q_2'
   *  Constant: '<S152>/Q_3'
   *  Constant: '<S152>/Q_4'
   *  Integrator: '<S157>/integration_eom'
   *  Product: '<S152>/Product'
   *  Product: '<S152>/Product1'
   *  Product: '<S152>/Product2'
   *  Product: '<S152>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_d[i] * GRM_HIL_X.integration_eom_CSTATE_b[0]
               + GRM_HIL_P.Q_2_Value_nt[i] * GRM_HIL_X.integration_eom_CSTATE_b
               [1]) + GRM_HIL_P.Q_3_Value_o[i] *
              GRM_HIL_X.integration_eom_CSTATE_b[2]) + GRM_HIL_P.Q_4_Value_n[i] *
      GRM_HIL_X.integration_eom_CSTATE_b[3];
  }

  /* End of Sum: '<S152>/Add' */

  /* Product: '<S152>/Product8' incorporates:
   *  Integrator: '<S158>/integration_eom'
   */
  for (i = 0; i < 4; i++) {
    rtb_Subtract_cl = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] +
      (tmp[i + 8] * GRM_HIL_X.integration_eom_CSTATE_f[2] + (tmp[i + 4] *
        GRM_HIL_X.integration_eom_CSTATE_f[1] + tmp[i] *
        GRM_HIL_X.integration_eom_CSTATE_f[0]));
    rtb_siB_h[i] = rtb_Subtract_cl;
  }

  /* End of Product: '<S152>/Product8' */

  /* Sum: '<S155>/Add' incorporates:
   *  Product: '<S155>/Product1'
   *  Product: '<S155>/Product2'
   *  Product: '<S155>/Product3'
   *  Product: '<S155>/Product4'
   */
  rtb_VectorConcatenate_f_idx_0 = ((rtb_siB_h[0] * rtb_siB_h[0] + rtb_siB_h[1] *
    rtb_siB_h[1]) + rtb_siB_h[2] * rtb_siB_h[2]) + rtb_siB_h[3] * rtb_siB_h[3];

  /* Math: '<S155>/Math Function'
   *
   * About '<S155>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_VectorConcatenate_f_idx_0 < 0.0) {
    rtb_VectorConcatenate_f_idx_0 = -sqrt(fabs(rtb_VectorConcatenate_f_idx_0));
  } else {
    rtb_VectorConcatenate_f_idx_0 = sqrt(rtb_VectorConcatenate_f_idx_0);
  }

  /* End of Math: '<S155>/Math Function' */

  /* Product: '<S155>/Product' */
  rtb_siB_h[0] /= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[1] /= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[2] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Subtract_cl = rtb_siB_h[3] / rtb_VectorConcatenate_f_idx_0;

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/Constant'
   *  Constant: '<S152>/Constant1'
   */
  if (rtb_Subtract_cl >= GRM_HIL_P.Switch_Threshold_g) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant_Value_gc;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant1_Value_ja;
  }

  /* End of Switch: '<S152>/Switch' */

  /* Product: '<S152>/Product4' */
  rtb_siB_h[0] *= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[1] *= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[2] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Subtract_cl *= rtb_VectorConcatenate_f_idx_0;

  /* Gain: '<S149>/Gain1' */
  rtb_Product4_n[0] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[0];
  rtb_Product4_n[1] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[1];
  rtb_Product4_n[2] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[2];

  /* Sum: '<S150>/Add' incorporates:
   *  Constant: '<S150>/Q_1'
   *  Constant: '<S150>/Q_2'
   *  Constant: '<S150>/Q_3'
   *  Constant: '<S150>/Q_4'
   *  Product: '<S150>/Product'
   *  Product: '<S150>/Product1'
   *  Product: '<S150>/Product2'
   *  Product: '<S150>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_k[i] * rtb_Product4_n[0] +
               GRM_HIL_P.Q_2_Value_c[i] * rtb_Product4_n[1]) +
              GRM_HIL_P.Q_3_Value_f[i] * rtb_Product4_n[2]) +
      GRM_HIL_P.Q_4_Value_e[i] * rtb_Subtract_cl;
  }

  /* End of Sum: '<S150>/Add' */

  /* Product: '<S150>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Product5 = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_Product_idx_2 + (tmp[i + 4] * rtb_Product_idx_1 + tmp[i] *
      rtb_Product_idx_0));
    rtb_Product4_n[i] = rtb_Product5;
  }

  /* End of Product: '<S150>/Product8' */

  /* Sum: '<S153>/Add' incorporates:
   *  Product: '<S153>/Product1'
   *  Product: '<S153>/Product2'
   *  Product: '<S153>/Product3'
   *  Product: '<S153>/Product4'
   */
  rtb_VectorConcatenate_f_idx_0 = ((rtb_Product4_n[0] * rtb_Product4_n[0] +
    rtb_Product4_n[1] * rtb_Product4_n[1]) + rtb_Product4_n[2] * rtb_Product4_n
    [2]) + rtb_Product4_n[3] * rtb_Product4_n[3];

  /* Math: '<S153>/Math Function'
   *
   * About '<S153>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_VectorConcatenate_f_idx_0 < 0.0) {
    rtb_VectorConcatenate_f_idx_0 = -sqrt(fabs(rtb_VectorConcatenate_f_idx_0));
  } else {
    rtb_VectorConcatenate_f_idx_0 = sqrt(rtb_VectorConcatenate_f_idx_0);
  }

  /* End of Math: '<S153>/Math Function' */

  /* Product: '<S153>/Product' */
  rtb_Product4_n[0] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[1] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[2] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Product5 = rtb_Product4_n[3] / rtb_VectorConcatenate_f_idx_0;

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S150>/Constant1'
   */
  if (rtb_Product5 >= GRM_HIL_P.Switch_Threshold_h) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant_Value_ie;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant1_Value_m;
  }

  /* End of Switch: '<S150>/Switch' */

  /* Product: '<S150>/Product4' */
  rtb_Product4_n[0] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[1] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[2] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Product5 *= rtb_VectorConcatenate_f_idx_0;

  /* Math: '<S148>/Math Function1' incorporates:
   *  Math: '<S148>/Math Function5'
   *  Math: '<S148>/Math Function9'
   */
  rtb_Tmp = rtb_Product4_n[1] * rtb_Product4_n[1];

  /* Math: '<S148>/Math Function' incorporates:
   *  Math: '<S148>/Math Function4'
   *  Math: '<S148>/Math Function8'
   */
  rtb_lat = rtb_Product4_n[0] * rtb_Product4_n[0];

  /* Math: '<S148>/Math Function2' incorporates:
   *  Math: '<S148>/Math Function10'
   *  Math: '<S148>/Math Function6'
   */
  rtb_Add = rtb_Product4_n[2] * rtb_Product4_n[2];

  /* Math: '<S148>/Math Function3' incorporates:
   *  Math: '<S148>/Math Function11'
   *  Math: '<S148>/Math Function7'
   */
  rtb_Sqrt_j = rtb_Product5 * rtb_Product5;

  /* Sum: '<S148>/Add' incorporates:
   *  Math: '<S148>/Math Function'
   *  Math: '<S148>/Math Function1'
   *  Math: '<S148>/Math Function2'
   *  Math: '<S148>/Math Function3'
   */
  rtb_TBG[0] = ((rtb_lat - rtb_Tmp) - rtb_Add) + rtb_Sqrt_j;

  /* Product: '<S148>/Product' incorporates:
   *  Product: '<S148>/Product6'
   */
  rtb_f_beB = rtb_Product4_n[0] * rtb_Product4_n[1];

  /* Product: '<S148>/Product1' incorporates:
   *  Product: '<S148>/Product7'
   */
  rtb_siB_c5 = rtb_Product4_n[2] * rtb_Product5;

  /* Sum: '<S148>/Add1' incorporates:
   *  Gain: '<S148>/Gain1'
   *  Gain: '<S148>/Gain2'
   *  Product: '<S148>/Product'
   *  Product: '<S148>/Product1'
   */
  rtb_TBG[1] = rtb_f_beB * GRM_HIL_P.Gain1_Gain_e - rtb_siB_c5 *
    GRM_HIL_P.Gain2_Gain_j;

  /* Product: '<S148>/Product8' incorporates:
   *  Product: '<S148>/Product4'
   */
  rtb_Gain_g = rtb_Product4_n[0] * rtb_Product4_n[2];

  /* Product: '<S148>/Product9' incorporates:
   *  Product: '<S148>/Product5'
   */
  rtb_Gain_lt = rtb_Product4_n[1] * rtb_Product5;

  /* Sum: '<S148>/Add5' incorporates:
   *  Gain: '<S148>/Gain10'
   *  Gain: '<S148>/Gain9'
   *  Product: '<S148>/Product8'
   *  Product: '<S148>/Product9'
   */
  rtb_TBG[2] = rtb_Gain_g * GRM_HIL_P.Gain9_Gain_m + rtb_Gain_lt *
    GRM_HIL_P.Gain10_Gain_d;

  /* Sum: '<S148>/Add4' incorporates:
   *  Gain: '<S148>/Gain7'
   *  Gain: '<S148>/Gain8'
   */
  rtb_TBG[3] = rtb_f_beB * GRM_HIL_P.Gain7_Gain_h + rtb_siB_c5 *
    GRM_HIL_P.Gain8_Gain_l;

  /* Sum: '<S148>/Add6' */
  rtb_TBG[4] = ((rtb_Tmp - rtb_lat) - rtb_Add) + rtb_Sqrt_j;

  /* Product: '<S148>/Product2' incorporates:
   *  Product: '<S148>/Product10'
   */
  rtb_f_beB = rtb_Product4_n[1] * rtb_Product4_n[2];

  /* Product: '<S148>/Product3' incorporates:
   *  Product: '<S148>/Product11'
   */
  rtb_siB_c5 = rtb_Product4_n[0] * rtb_Product5;

  /* Sum: '<S148>/Add2' incorporates:
   *  Gain: '<S148>/Gain3'
   *  Gain: '<S148>/Gain4'
   *  Product: '<S148>/Product2'
   *  Product: '<S148>/Product3'
   */
  rtb_TBG[5] = rtb_f_beB * GRM_HIL_P.Gain3_Gain_e - rtb_siB_c5 *
    GRM_HIL_P.Gain4_Gain_c;

  /* Sum: '<S148>/Add3' incorporates:
   *  Gain: '<S148>/Gain5'
   *  Gain: '<S148>/Gain6'
   */
  rtb_TBG[6] = rtb_Gain_g * GRM_HIL_P.Gain5_Gain_c - rtb_Gain_lt *
    GRM_HIL_P.Gain6_Gain_b;

  /* Sum: '<S148>/Add8' incorporates:
   *  Gain: '<S148>/Gain11'
   *  Gain: '<S148>/Gain12'
   */
  rtb_TBG[7] = rtb_f_beB * GRM_HIL_P.Gain11_Gain_g + rtb_siB_c5 *
    GRM_HIL_P.Gain12_Gain_j;

  /* Sum: '<S148>/Add7' */
  rtb_TBG[8] = ((rtb_Add - rtb_lat) - rtb_Tmp) + rtb_Sqrt_j;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S208>/Add' incorporates:
     *  Constant: '<S208>/course_angle_uncertainty'
     *  Constant: '<S208>/course_angle_wind'
     */
    rtb_Add = GRM_HIL_P.course_angle_wind_Value +
      GRM_HIL_P.course_angle_uncertainty_Value;

    /* MultiPortSwitch: '<S210>/Multiport Switch' incorporates:
     *  Constant: '<S210>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1) {
     case 1:
      /* Trigonometry: '<S211>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S211>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(rtb_Add);

      /* Trigonometry: '<S211>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S211>/Trigonometric Function'
       */
      rtb_Subtract_cl = cos(rtb_Add);

      /* SignalConversion generated from: '<S211>/Matrix Concatenate' incorporates:
       *  Constant: '<S211>/Constant7'
       *  Trigonometry: '<S211>/Trigonometric Function1'
       *  Trigonometry: '<S211>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_j;
      rtb_MultiportSwitch[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[8] = rtb_Subtract_cl;

      /* SignalConversion generated from: '<S211>/Matrix Concatenate' incorporates:
       *  Constant: '<S211>/Constant8'
       *  Gain: '<S211>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_af;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_kj *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S211>/Matrix Concatenate' incorporates:
       *  Constant: '<S211>/Constant'
       *  Constant: '<S211>/Constant1'
       *  Constant: '<S211>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_b;
      break;

     case 2:
      /* Trigonometry: '<S212>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S212>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(rtb_Add);

      /* Trigonometry: '<S212>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S212>/Trigonometric Function2'
       */
      rtb_Subtract_cl = sin(rtb_Add);

      /* SignalConversion generated from: '<S212>/Matrix Concatenate' incorporates:
       *  Constant: '<S212>/Constant7'
       *  Gain: '<S212>/Gain1'
       *  Trigonometry: '<S212>/Trigonometric Function1'
       *  Trigonometry: '<S212>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_j * rtb_Subtract_cl;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_d1;
      rtb_MultiportSwitch[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S212>/Matrix Concatenate' incorporates:
       *  Constant: '<S212>/Constant'
       *  Constant: '<S212>/Constant1'
       *  Constant: '<S212>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ob;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_i;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_g;

      /* SignalConversion generated from: '<S212>/Matrix Concatenate' incorporates:
       *  Constant: '<S212>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_ky;
      rtb_MultiportSwitch[2] = rtb_Subtract_cl;
      break;

     default:
      /* SignalConversion generated from: '<S213>/Matrix Concatenate' incorporates:
       *  Constant: '<S213>/Constant10'
       *  Constant: '<S213>/Constant11'
       *  Constant: '<S213>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_o;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_d;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_a;

      /* Trigonometry: '<S213>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S213>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(rtb_Add);

      /* Trigonometry: '<S213>/Trigonometric Function' incorporates:
       *  Trigonometry: '<S213>/Trigonometric Function3'
       */
      rtb_Subtract_cl = cos(rtb_Add);

      /* SignalConversion generated from: '<S213>/Matrix Concatenate' incorporates:
       *  Constant: '<S213>/Constant7'
       *  Trigonometry: '<S213>/Trigonometric Function'
       *  Trigonometry: '<S213>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_g;

      /* SignalConversion generated from: '<S213>/Matrix Concatenate' incorporates:
       *  Constant: '<S213>/Constant8'
       *  Gain: '<S213>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Subtract_cl;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_jn *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gg;
      break;
    }

    /* End of MultiPortSwitch: '<S210>/Multiport Switch' */

    /* Sum: '<S208>/Add1' incorporates:
     *  Constant: '<S208>/vWW'
     *  Constant: '<S208>/vWW_uncertainty'
     */
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.vWW_uncertainty_Value +
      GRM_HIL_P.vWW_Value;

    /* Product: '<S209>/Product' incorporates:
     *  Constant: '<S208>/Constant1'
     */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.vec2[i] = 0.0;
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i] *
        rtb_VectorConcatenate_f_idx_0;
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i + 3] *
        GRM_HIL_P.Constant1_Value_fr;
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i + 6] *
        GRM_HIL_P.Constant1_Value_fr;
    }

    /* End of Product: '<S209>/Product' */
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S198>/Math Function1' incorporates:
     *  Math: '<S55>/Math Function'
     */
    rtb_vBEB_a_tmp[3 * i] = rtb_TBG[i];
    rtb_vBEB_a_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_vBEB_a_tmp[3 * i + 2] = rtb_TBG[i + 6];

    /* Product: '<S198>/Product' */
    rtb_pBEE[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_Gain_fl +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_Product1_m[1] +
       rtb_MatrixMultiply_tmp[i] * rtb_Product1_m[0]);
  }

  /* DotProduct: '<S203>/Dot Product1' */
  rtb_Add = 0.0;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S199>/Subtract' incorporates:
     *  Math: '<S198>/Math Function1'
     *  Product: '<S198>/Product1'
     */
    rtb_Tmp = rtb_pBEE[i] - (rtb_vBEB_a_tmp[i + 6] * GRM_HIL_B.vec2[2] +
      (rtb_vBEB_a_tmp[i + 3] * GRM_HIL_B.vec2[1] + rtb_vBEB_a_tmp[i] *
       GRM_HIL_B.vec2[0]));

    /* DotProduct: '<S203>/Dot Product1' */
    rtb_Add += rtb_Tmp * rtb_Tmp;

    /* Sum: '<S199>/Subtract' */
    rtb_vBEB_a[i] = rtb_Tmp;
  }

  /* Math: '<S203>/Math Function1' incorporates:
   *  DotProduct: '<S203>/Dot Product1'
   *
   * About '<S203>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Add < 0.0) {
    rtb_VectorConcatenate_f_idx_0 = -sqrt(fabs(rtb_Add));
  } else {
    rtb_VectorConcatenate_f_idx_0 = sqrt(rtb_Add);
  }

  /* End of Math: '<S203>/Math Function1' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S122>/Subtract1' incorporates:
     *  Constant: '<S122>/Tmp_norm_msl'
     *  Constant: '<S207>/deviation_Tmp'
     */
    GRM_HIL_B.Tmp_ref = GRM_HIL_P.deviation_Tmp_Value +
      GRM_HIL_P.Tmp_norm_msl_Value;

    /* Constant: '<S183>/Constant' */
    GRM_HIL_B.VectorConcatenate1[0] = GRM_HIL_P.Constant_Value_b;

    /* Constant: '<S183>/Constant2' */
    GRM_HIL_B.VectorConcatenate1[1] = GRM_HIL_P.Constant2_Value_e5;

    /* Product: '<S187>/Product' incorporates:
     *  Constant: '<S185>/c_flat'
     *  Constant: '<S185>/c_rsma'
     *  Constant: '<S187>/Constant'
     *  Sum: '<S187>/Subtract'
     */
    GRM_HIL_B.Product = (GRM_HIL_P.Constant_Value_ne - GRM_HIL_P.c_flat_Value_e)
      * GRM_HIL_P.c_rsma_Value_j;

    /* Product: '<S187>/Product5' */
    rtb_Switch1 = GRM_HIL_B.Product * GRM_HIL_B.Product;

    /* Product: '<S187>/Divide' incorporates:
     *  Constant: '<S185>/c_rsma'
     *  Product: '<S187>/Product4'
     *  Sum: '<S187>/Subtract2'
     */
    GRM_HIL_B.Divide = (GRM_HIL_P.c_rsma_Value_j * GRM_HIL_P.c_rsma_Value_j -
                        rtb_Switch1) / rtb_Switch1;

    /* Product: '<S187>/Product3' incorporates:
     *  Constant: '<S185>/c_flat'
     *  Product: '<S186>/Product3'
     */
    rtb_Tmp = GRM_HIL_P.c_flat_Value_e * GRM_HIL_P.c_flat_Value_e;

    /* Sum: '<S187>/Subtract1' incorporates:
     *  Constant: '<S185>/c_flat'
     *  Gain: '<S187>/Gain'
     *  Product: '<S187>/Product3'
     */
    GRM_HIL_B.Subtract1 = GRM_HIL_P.Gain_Gain_le * GRM_HIL_P.c_flat_Value_e -
      rtb_Tmp;

    /* Sum: '<S186>/Subtract' incorporates:
     *  Constant: '<S185>/c_flat'
     *  Gain: '<S186>/Gain'
     */
    GRM_HIL_B.Subtract = GRM_HIL_P.Gain_Gain_iy * GRM_HIL_P.c_flat_Value_e -
      rtb_Tmp;
  }

  /* Switch: '<S183>/Switch' incorporates:
   *  Constant: '<S183>/Constant1'
   */
  if (GRM_HIL_P.Constant1_Value_bt > GRM_HIL_P.Switch_Threshold_c) {
    /* Gain: '<S183>/Gain' incorporates:
     *  Integrator: '<S189>/integration_eom'
     */
    GRM_HIL_B.VectorConcatenate1[2] = GRM_HIL_P.Gain_Gain_p *
      GRM_HIL_X.integration_eom_CSTATE[2];
    GRM_HIL_B.Switch[0] = GRM_HIL_B.VectorConcatenate1[0];
    GRM_HIL_B.Switch[1] = GRM_HIL_B.VectorConcatenate1[1];
    GRM_HIL_B.Switch[2] = GRM_HIL_B.VectorConcatenate1[2];
  } else {
    /* Product: '<S183>/Product' incorporates:
     *  Integrator: '<S189>/integration_eom'
     *  Math: '<S183>/Math Function'
     */
    for (i = 0; i < 3; i++) {
      rtb_pBEE[i] = rtb_VectorConcatenate3[3 * i + 2] *
        GRM_HIL_X.integration_eom_CSTATE[2] + (rtb_VectorConcatenate3[3 * i + 1]
        * GRM_HIL_X.integration_eom_CSTATE[1] + rtb_VectorConcatenate3[3 * i] *
        GRM_HIL_X.integration_eom_CSTATE[0]);
    }

    /* End of Product: '<S183>/Product' */

    /* Sqrt: '<S187>/Sqrt' incorporates:
     *  Product: '<S187>/Product1'
     *  Product: '<S187>/Product2'
     *  Sqrt: '<S186>/Sqrt'
     *  Sum: '<S187>/Add'
     */
    rtb_Add = sqrt(rtb_pBEE[0] * rtb_pBEE[0] + rtb_pBEE[1] * rtb_pBEE[1]);

    /* Trigonometry: '<S187>/Trigonometric Function' incorporates:
     *  Constant: '<S185>/c_rsma'
     *  Product: '<S187>/Divide1'
     *  Product: '<S187>/Product6'
     *  Product: '<S187>/Product7'
     *  Sqrt: '<S187>/Sqrt'
     */
    rtb_Sqrt_j = atan(rtb_pBEE[2] * GRM_HIL_P.c_rsma_Value_j / (rtb_Add *
      GRM_HIL_B.Product));

    /* Trigonometry: '<S187>/Trigonometric Function3' */
    rtb_lat = cos(rtb_Sqrt_j);

    /* Trigonometry: '<S187>/Trigonometric Function2' */
    rtb_Sqrt_j = sin(rtb_Sqrt_j);

    /* Trigonometry: '<S187>/Trigonometric Function1' incorporates:
     *  Constant: '<S185>/c_rsma'
     *  Product: '<S187>/Divide2'
     *  Product: '<S187>/Product10'
     *  Product: '<S187>/Product11'
     *  Product: '<S187>/Product8'
     *  Product: '<S187>/Product9'
     *  Sqrt: '<S187>/Sqrt'
     *  Sum: '<S187>/Add1'
     *  Sum: '<S187>/Subtract3'
     */
    rtb_lat = atan((rtb_Sqrt_j * rtb_Sqrt_j * rtb_Sqrt_j * (GRM_HIL_B.Divide *
      GRM_HIL_B.Product) + rtb_pBEE[2]) / (rtb_Add - rtb_lat * rtb_lat * rtb_lat
      * (GRM_HIL_B.Subtract1 * GRM_HIL_P.c_rsma_Value_j)));

    /* Trigonometry: '<S186>/Trigonometric Function' */
    rtb_Sqrt_j = sin(rtb_lat);

    /* Sqrt: '<S186>/Sqrt1' incorporates:
     *  Constant: '<S186>/Constant'
     *  Product: '<S186>/Product5'
     *  Sum: '<S186>/Subtract1'
     */
    rtb_Sqrt_j = sqrt(GRM_HIL_P.Constant_Value_nr - rtb_Sqrt_j * rtb_Sqrt_j *
                      GRM_HIL_B.Subtract);

    /* Sum: '<S186>/Sum' incorporates:
     *  Constant: '<S185>/c_rsma'
     *  Product: '<S186>/Product'
     *  Product: '<S186>/Product4'
     *  Trigonometry: '<S186>/cos(latGD)'
     */
    GRM_HIL_B.Switch[2] = rtb_Add / cos(rtb_lat) - GRM_HIL_P.c_rsma_Value_j /
      rtb_Sqrt_j;

    /* SignalConversion generated from: '<S183>/Vector Concatenate' */
    GRM_HIL_B.Switch[1] = rtb_lat;

    /* Trigonometry: '<S185>/Trigonometric Function1' */
    GRM_HIL_B.Switch[0] = rt_atan2d_snf(rtb_pBEE[1], rtb_pBEE[0]);
  }

  /* End of Switch: '<S183>/Switch' */

  /* Product: '<S120>/Divide' incorporates:
   *  Constant: '<S120>/mean_earth_radius'
   *  Sum: '<S120>/Add'
   */
  rtb_Step1 = GRM_HIL_B.Switch[2] / (GRM_HIL_B.Switch[2] +
    GRM_HIL_P.geopot_height_mean_earth_radius) *
    GRM_HIL_P.geopot_height_mean_earth_radius;

  /* Saturate: '<S110>/Saturation' */
  if (rtb_Step1 > GRM_HIL_P.Saturation_UpperSat_h) {
    rtb_Step1 = GRM_HIL_P.Saturation_UpperSat_h;
  } else {
    if (rtb_Step1 < GRM_HIL_P.Saturation_LowerSat_k) {
      rtb_Step1 = GRM_HIL_P.Saturation_LowerSat_k;
    }
  }

  /* End of Saturate: '<S110>/Saturation' */

  /* Sum: '<S123>/Subtract' incorporates:
   *  Constant: '<S122>/geopotential_height_ref'
   *  Sum: '<S124>/Subtract'
   */
  rtb_Step1 -= GRM_HIL_P.geopotential_height_ref_Value;

  /* Sum: '<S123>/Add' incorporates:
   *  Constant: '<S123>/Tmp_gradient_tropo'
   *  Product: '<S123>/Product'
   *  Sum: '<S123>/Subtract'
   */
  rtb_Tmp = rtb_Step1 * GRM_HIL_P.Tmp_gradient_tropo_Value + GRM_HIL_B.Tmp_ref;

  /* PreLookup: '<S95>/Prelookup_Mach' incorporates:
   *  Constant: '<S121>/heat_capacity_ratio'
   *  Constant: '<S121>/specific_gas_constant'
   *  Product: '<S121>/Product'
   *  Product: '<S199>/Divide'
   *  Sqrt: '<S121>/Sqrt'
   */
  rtb_k_Mach = plook_binc(rtb_VectorConcatenate_f_idx_0 / sqrt
    (GRM_HIL_P.specific_gas_constant_Value * GRM_HIL_P.heat_capacity_ratio_Value
     * rtb_Tmp), GRM_HIL_P.Prelookup_Mach_BreakpointsData, 8U, &rtb_lat);

  /* DotProduct: '<S204>/Dot Product1' */
  rtb_Add = (rtb_vBEB_a[0] * rtb_vBEB_a[0] + rtb_vBEB_a[1] * rtb_vBEB_a[1]) +
    rtb_vBEB_a[2] * rtb_vBEB_a[2];

  /* Math: '<S204>/Math Function1' incorporates:
   *  DotProduct: '<S204>/Dot Product1'
   *
   * About '<S204>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Add < 0.0) {
    rtb_Add = -sqrt(fabs(rtb_Add));
  } else {
    rtb_Add = sqrt(rtb_Add);
  }

  /* End of Math: '<S204>/Math Function1' */

  /* Switch: '<S201>/Switch' incorporates:
   *  Constant: '<S201>/Constant'
   */
  if (rtb_Add != 0.0) {
    /* SignalConversion generated from: '<S201>/Vector Concatenate' */
    rtb_siB_h[3] = rtb_Add;

    /* SignalConversion generated from: '<S201>/Vector Concatenate' */
    rtb_siB_h[2] = rtb_vBEB_a[2];

    /* SignalConversion generated from: '<S201>/Vector Concatenate' */
    rtb_siB_h[1] = rtb_vBEB_a[1];

    /* SignalConversion generated from: '<S201>/Vector Concatenate' */
    rtb_siB_h[0] = rtb_vBEB_a[0];
  } else {
    rtb_siB_h[0] = GRM_HIL_P.Constant_Value_jc[0];
    rtb_siB_h[1] = GRM_HIL_P.Constant_Value_jc[1];
    rtb_siB_h[2] = GRM_HIL_P.Constant_Value_jc[2];
    rtb_siB_h[3] = GRM_HIL_P.Constant_Value_jc[3];
  }

  /* End of Switch: '<S201>/Switch' */

  /* Gain: '<S100>/Gain' incorporates:
   *  Trigonometry: '<S201>/Trigonometric Function'
   */
  rtb_Subtract_cl = GRM_HIL_P.Gain_Gain_nn * rt_atan2d_snf(rtb_siB_h[2],
    rtb_siB_h[0]);

  /* PreLookup: '<S95>/Prelookup_alB' */
  rtb_k_alB = plook_binc(rtb_Subtract_cl,
    GRM_HIL_P.Prelookup_alB_BreakpointsData, 16U, &rtb_Sqrt_j);

  /* Product: '<S201>/Divide' */
  u0 = rtb_siB_h[1] / rtb_siB_h[3];

  /* Trigonometry: '<S201>/Trigonometric Function1' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Gain: '<S101>/Gain' incorporates:
   *  Trigonometry: '<S201>/Trigonometric Function1'
   */
  rtb_Subtract_ju = GRM_HIL_P.Gain_Gain_kz * asin(u0);

  /* PreLookup: '<S95>/Prelookup_beB' */
  rtb_k_beB = plook_binc(rtb_Subtract_ju,
    GRM_HIL_P.Prelookup_beB_BreakpointsData, 16U, &rtb_f_beB);

  /* Interpolation_n-D: '<S92>/Cx_Interpolation' */
  frac[0] = rtb_lat;
  frac[1] = rtb_Sqrt_j;
  frac[2] = rtb_f_beB;
  bpIndex[0] = rtb_k_Mach;
  bpIndex[1] = rtb_k_alB;
  bpIndex[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex, frac, GRM_HIL_P.Cx_Interpolation_Table,
    GRM_HIL_P.Cx_Interpolation_dimSize);

  /* Product: '<S92>/Product' incorporates:
   *  Constant: '<S92>/Constant'
   */
  rtb_Cx = GRM_HIL_P.Constant_Value_i3 * rtb_siB_c5;

  /* Saturate: '<S202>/Saturation1' */
  if (rtb_VectorConcatenate_f_idx_0 > GRM_HIL_P.Saturation1_UpperSat) {
    rtb_Add = GRM_HIL_P.Saturation1_UpperSat;
  } else if (rtb_VectorConcatenate_f_idx_0 < GRM_HIL_P.Saturation1_LowerSat) {
    rtb_Add = GRM_HIL_P.Saturation1_LowerSat;
  } else {
    rtb_Add = rtb_VectorConcatenate_f_idx_0;
  }

  /* End of Saturate: '<S202>/Saturation1' */

  /* Product: '<S202>/Divide1' incorporates:
   *  Constant: '<S202>/Constant1'
   */
  rtb_siB_c5 = 1.0 / rtb_Add * GRM_HIL_P.Constant1_Value_is;

  /* Product: '<S202>/Product3' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  rtb_Product1_m[1] = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[11];

  /* Product: '<S202>/Product4' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  rtb_Product1_m[2] = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[12];

  /* Gain: '<S105>/Gain' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S202>/Product2'
   */
  rtb_Gain_g = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[10] *
    GRM_HIL_P.Gain_Gain_b;

  /* Interpolation_n-D: '<S92>/Cxp_Interpolation' */
  frac_0[0] = rtb_lat;
  frac_0[1] = rtb_Sqrt_j;
  frac_0[2] = rtb_f_beB;
  bpIndex_0[0] = rtb_k_Mach;
  bpIndex_0[1] = rtb_k_alB;
  bpIndex_0[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_0, frac_0, GRM_HIL_P.Cxp_Interpolation_Table,
    GRM_HIL_P.Cxp_Interpolation_dimSize);

  /* Product: '<S72>/Product' */
  rtb_Product_l = rtb_Gain_g * rtb_siB_c5;

  /* Gain: '<S106>/Gain' */
  rtb_Gain_lt = GRM_HIL_P.Gain_Gain_hp * rtb_Product1_m[1];

  /* Interpolation_n-D: '<S92>/Cxq_Interpolation' */
  frac_1[0] = rtb_lat;
  frac_1[1] = rtb_Sqrt_j;
  frac_1[2] = rtb_f_beB;
  bpIndex_1[0] = rtb_k_Mach;
  bpIndex_1[1] = rtb_k_alB;
  bpIndex_1[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_1, frac_1, GRM_HIL_P.Cxq_Interpolation_Table,
    GRM_HIL_P.Cxq_Interpolation_dimSize);

  /* Product: '<S72>/Product1' */
  rtb_Product1 = rtb_Gain_lt * rtb_siB_c5;

  /* Gain: '<S107>/Gain' */
  rtb_Gain_af = GRM_HIL_P.Gain_Gain_bz * rtb_Product1_m[2];

  /* Interpolation_n-D: '<S92>/Cxr_Interpolation' */
  frac_2[0] = rtb_lat;
  frac_2[1] = rtb_Sqrt_j;
  frac_2[2] = rtb_f_beB;
  bpIndex_2[0] = rtb_k_Mach;
  bpIndex_2[1] = rtb_k_alB;
  bpIndex_2[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_2, frac_2, GRM_HIL_P.Cxr_Interpolation_Table,
    GRM_HIL_P.Cxr_Interpolation_dimSize);

  /* Integrator: '<S125>/Integrator1' */
  /* Limited  Integrator  (w/ Saturation Port) */
  if (GRM_HIL_X.Integrator1_CSTATE >= GRM_HIL_P.Rudder_siB_max) {
    GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_P.Rudder_siB_max;
    GRM_HIL_B.sat = 1.0;
  } else if (GRM_HIL_X.Integrator1_CSTATE <= GRM_HIL_P.Rudder_siB_min) {
    GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_P.Rudder_siB_min;
    GRM_HIL_B.sat = -1.0;
  } else {
    GRM_HIL_B.sat = 0.0;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Signum: '<S125>/Sign' incorporates:
     *  Constant: '<S54>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp = 0.0;
    } else {
      rtb_Subtract_ay_tmp = (rtNaN);
    }

    /* End of Signum: '<S125>/Sign' */

    /* Gain: '<S125>/Gain3' */
    GRM_HIL_B.Gain3 = GRM_HIL_P.Rudder_unc_bl * rtb_Subtract_ay_tmp;
  }

  /* Sum: '<S125>/Add2' incorporates:
   *  Constant: '<S125>/Constant'
   *  Gain: '<S125>/Gain1'
   *  Integrator: '<S125>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder_unc_scale * GRM_HIL_X.Integrator1_CSTATE +
        GRM_HIL_P.Rudder_unc_off) + GRM_HIL_B.Gain3;

  /* Saturate: '<S125>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder_siB_max) {
    rtb_siB = GRM_HIL_P.Rudder_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder_siB_min) {
    rtb_siB = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_siB = u0;
  }

  /* End of Saturate: '<S125>/Saturation1' */

  /* Integrator: '<S126>/Integrator1' */
  /* Limited  Integrator  (w/ Saturation Port) */
  if (GRM_HIL_X.Integrator1_CSTATE_g >= GRM_HIL_P.Rudder1_siB_max) {
    GRM_HIL_X.Integrator1_CSTATE_g = GRM_HIL_P.Rudder1_siB_max;
    GRM_HIL_B.sat_c = 1.0;
  } else if (GRM_HIL_X.Integrator1_CSTATE_g <= GRM_HIL_P.Rudder1_siB_min) {
    GRM_HIL_X.Integrator1_CSTATE_g = GRM_HIL_P.Rudder1_siB_min;
    GRM_HIL_B.sat_c = -1.0;
  } else {
    GRM_HIL_B.sat_c = 0.0;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Signum: '<S126>/Sign' incorporates:
     *  Constant: '<S54>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp = 0.0;
    } else {
      rtb_Subtract_ay_tmp = (rtNaN);
    }

    /* End of Signum: '<S126>/Sign' */

    /* Gain: '<S126>/Gain3' */
    GRM_HIL_B.Gain3_m = GRM_HIL_P.Rudder1_unc_bl * rtb_Subtract_ay_tmp;
  }

  /* Sum: '<S126>/Add2' incorporates:
   *  Constant: '<S126>/Constant'
   *  Gain: '<S126>/Gain1'
   *  Integrator: '<S126>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder1_unc_scale * GRM_HIL_X.Integrator1_CSTATE_g +
        GRM_HIL_P.Rudder1_unc_off) + GRM_HIL_B.Gain3_m;

  /* Saturate: '<S126>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder1_siB_max) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder1_siB_min) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_siB_d = u0;
  }

  /* End of Saturate: '<S126>/Saturation1' */

  /* Integrator: '<S127>/Integrator1' */
  /* Limited  Integrator  (w/ Saturation Port) */
  if (GRM_HIL_X.Integrator1_CSTATE_a >= GRM_HIL_P.Rudder2_siB_max) {
    GRM_HIL_X.Integrator1_CSTATE_a = GRM_HIL_P.Rudder2_siB_max;
    GRM_HIL_B.sat_a = 1.0;
  } else if (GRM_HIL_X.Integrator1_CSTATE_a <= GRM_HIL_P.Rudder2_siB_min) {
    GRM_HIL_X.Integrator1_CSTATE_a = GRM_HIL_P.Rudder2_siB_min;
    GRM_HIL_B.sat_a = -1.0;
  } else {
    GRM_HIL_B.sat_a = 0.0;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Signum: '<S127>/Sign' incorporates:
     *  Constant: '<S54>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp = 0.0;
    } else {
      rtb_Subtract_ay_tmp = (rtNaN);
    }

    /* End of Signum: '<S127>/Sign' */

    /* Gain: '<S127>/Gain3' */
    GRM_HIL_B.Gain3_b = GRM_HIL_P.Rudder2_unc_bl * rtb_Subtract_ay_tmp;
  }

  /* Sum: '<S127>/Add2' incorporates:
   *  Constant: '<S127>/Constant'
   *  Gain: '<S127>/Gain1'
   *  Integrator: '<S127>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder2_unc_scale * GRM_HIL_X.Integrator1_CSTATE_a +
        GRM_HIL_P.Rudder2_unc_off) + GRM_HIL_B.Gain3_b;

  /* Saturate: '<S127>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder2_siB_max) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder2_siB_min) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_siB_i = u0;
  }

  /* End of Saturate: '<S127>/Saturation1' */

  /* Integrator: '<S128>/Integrator1' */
  /* Limited  Integrator  (w/ Saturation Port) */
  if (GRM_HIL_X.Integrator1_CSTATE_i >= GRM_HIL_P.Rudder3_siB_max) {
    GRM_HIL_X.Integrator1_CSTATE_i = GRM_HIL_P.Rudder3_siB_max;
    GRM_HIL_B.sat_o = 1.0;
  } else if (GRM_HIL_X.Integrator1_CSTATE_i <= GRM_HIL_P.Rudder3_siB_min) {
    GRM_HIL_X.Integrator1_CSTATE_i = GRM_HIL_P.Rudder3_siB_min;
    GRM_HIL_B.sat_o = -1.0;
  } else {
    GRM_HIL_B.sat_o = 0.0;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Signum: '<S128>/Sign' incorporates:
     *  Constant: '<S54>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp = 0.0;
    } else {
      rtb_Subtract_ay_tmp = (rtNaN);
    }

    /* End of Signum: '<S128>/Sign' */

    /* Gain: '<S128>/Gain3' */
    GRM_HIL_B.Gain3_h = GRM_HIL_P.Rudder3_unc_bl * rtb_Subtract_ay_tmp;
  }

  /* Sum: '<S128>/Add2' incorporates:
   *  Constant: '<S128>/Constant'
   *  Gain: '<S128>/Gain1'
   *  Integrator: '<S128>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder3_unc_scale * GRM_HIL_X.Integrator1_CSTATE_i +
        GRM_HIL_P.Rudder3_unc_off) + GRM_HIL_B.Gain3_h;

  /* Saturate: '<S128>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder3_siB_max) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder3_siB_min) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_min;
  } else {
    rtb_siB_o = u0;
  }

  /* End of Saturate: '<S128>/Saturation1' */

  /* Product: '<S129>/Product' incorporates:
   *  Constant: '<S129>/Constant8'
   *  SignalConversion generated from: '<S54>/Vector Concatenate1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain_fl = GRM_HIL_P.Constant8_Value_g2[i + 9] * rtb_siB_o +
      (GRM_HIL_P.Constant8_Value_g2[i + 6] * rtb_siB_i +
       (GRM_HIL_P.Constant8_Value_g2[i + 3] * rtb_siB_d +
        GRM_HIL_P.Constant8_Value_g2[i] * rtb_siB));
    rtb_Product1_m[i] = rtb_Gain_fl;
  }

  /* End of Product: '<S129>/Product' */

  /* Gain: '<S102>/Gain' */
  rtb_Gain_fl = GRM_HIL_P.Gain_Gain_aj * rtb_Product1_m[0];

  /* Interpolation_n-D: '<S92>/Cx_delta_l_Interpolation' */
  frac_3[0] = rtb_lat;
  frac_3[1] = rtb_Sqrt_j;
  frac_3[2] = rtb_f_beB;
  bpIndex_3[0] = rtb_k_Mach;
  bpIndex_3[1] = rtb_k_alB;
  bpIndex_3[2] = rtb_k_beB;
  rtb_Product6_e = intrp3d_l_pw(bpIndex_3, frac_3,
    GRM_HIL_P.Cx_delta_l_Interpolation_Table,
    GRM_HIL_P.Cx_delta_l_Interpolation_dimSize);

  /* Product: '<S72>/Product3' */
  rtb_Product3_hu = rtb_Gain_fl * rtb_Product6_e;

  /* Gain: '<S103>/Gain' */
  rtb_Gain_nk = GRM_HIL_P.Gain_Gain_l4 * rtb_Product1_m[1];

  /* Interpolation_n-D: '<S92>/Cx_delta_m_Interpolation' */
  frac_4[0] = rtb_lat;
  frac_4[1] = rtb_Sqrt_j;
  frac_4[2] = rtb_f_beB;
  bpIndex_4[0] = rtb_k_Mach;
  bpIndex_4[1] = rtb_k_alB;
  bpIndex_4[2] = rtb_k_beB;
  rtb_Product6_e = intrp3d_l_pw(bpIndex_4, frac_4,
    GRM_HIL_P.Cx_delta_m_Interpolation_Table,
    GRM_HIL_P.Cx_delta_m_Interpolation_dimSize);

  /* Product: '<S72>/Product4' */
  rtb_Product4_e = rtb_Gain_nk * rtb_Product6_e;

  /* Gain: '<S104>/Gain' */
  rtb_Gain_n = GRM_HIL_P.Gain_Gain_pr * rtb_Product1_m[2];

  /* Interpolation_n-D: '<S92>/Cx_delta_n_Interpolation' */
  frac_5[0] = rtb_lat;
  frac_5[1] = rtb_Sqrt_j;
  frac_5[2] = rtb_f_beB;
  bpIndex_5[0] = rtb_k_Mach;
  bpIndex_5[1] = rtb_k_alB;
  bpIndex_5[2] = rtb_k_beB;
  rtb_Product6_e = intrp3d_l_pw(bpIndex_5, frac_5,
    GRM_HIL_P.Cx_delta_n_Interpolation_Table,
    GRM_HIL_P.Cx_delta_n_Interpolation_dimSize);

  /* Product: '<S72>/Product5' */
  rtb_Product5 = rtb_Gain_n * rtb_Product6_e;

  /* Interpolation_n-D: '<S92>/Cx_alt_Interpolation' incorporates:
   *  PreLookup: '<S92>/Prelookup_altitude'
   */
  bpIndex_6[2] = plook_binc(GRM_HIL_B.Switch[2],
    GRM_HIL_P.Prelookup_altitude_BreakpointsData, 19U, &rtb_Product6_e);
  frac_6[0] = rtb_lat;
  frac_6[1] = rtb_Sqrt_j;
  frac_6[2] = rtb_Product6_e;
  bpIndex_6[0] = rtb_k_Mach;
  bpIndex_6[1] = rtb_k_alB;
  rtb_Product6_e = intrp3d_l_pw(bpIndex_6, frac_6,
    GRM_HIL_P.Cx_alt_Interpolation_Table, GRM_HIL_P.Cx_alt_Interpolation_dimSize);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sqrt: '<S96>/Sqrt' incorporates:
     *  Constant: '<S96>/Constant3'
     */
    GRM_HIL_B.Sqrt = sqrt(GRM_HIL_P.Constant3_Value_f);
  }

  /* Gain: '<S99>/Gain' incorporates:
   *  Gain: '<S97>/Gain1'
   *  Gain: '<S98>/Gain1'
   *  Product: '<S96>/Product1'
   *  Trigonometry: '<S96>/Trigonometric Function'
   *  Trigonometry: '<S96>/Trigonometric Function1'
   *  Trigonometry: '<S96>/Trigonometric Function2'
   */
  u0 = acos(cos(GRM_HIL_P.Gain1_Gain_b * rtb_Subtract_cl) * cos
            (GRM_HIL_P.Gain1_Gain_e2 * rtb_Subtract_ju)) *
    GRM_HIL_P.Gain_Gain_if;

  /* Saturate: '<S96>/Saturation' */
  if (u0 > GRM_HIL_P.Saturation_UpperSat_f) {
    u0 = GRM_HIL_P.Saturation_UpperSat_f;
  } else {
    if (u0 < GRM_HIL_P.Saturation_LowerSat_g) {
      u0 = GRM_HIL_P.Saturation_LowerSat_g;
    }
  }

  /* End of Saturate: '<S96>/Saturation' */

  /* Abs: '<S96>/Abs2' incorporates:
   *  Abs: '<S96>/Abs'
   *  Abs: '<S96>/Abs1'
   *  Product: '<S96>/Divide2'
   *  Product: '<S96>/Product6'
   *  Product: '<S96>/Product7'
   *  Sum: '<S96>/Add'
   */
  rtb_Product6_n4 = fabs((fabs(rtb_Subtract_cl) * rtb_Gain_nk + fabs
    (rtb_Subtract_ju) * rtb_Gain_n) * GRM_HIL_B.Sqrt / u0);

  /* Interpolation_n-D: '<S92>/Cx_delta_t_Interpolation' incorporates:
   *  PreLookup: '<S92>/Prelookup_delta_t'
   */
  bpIndex_7[2] = plook_binc(rtb_Product6_n4,
    GRM_HIL_P.Prelookup_delta_t_BreakpointsData, 8U, &rtb_Product6_n4);
  frac_7[0] = rtb_lat;
  frac_7[1] = rtb_Sqrt_j;
  frac_7[2] = rtb_Product6_n4;
  bpIndex_7[0] = rtb_k_Mach;
  bpIndex_7[1] = rtb_k_alB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_7, frac_7,
    GRM_HIL_P.Cx_delta_t_Interpolation_Table,
    GRM_HIL_P.Cx_delta_t_Interpolation_dimSize);

  /* Interpolation_n-D: '<S92>/Cx_base_Interpolation' */
  frac_8[0] = rtb_lat;
  frac_8[1] = rtb_Sqrt_j;
  frac_8[2] = rtb_f_beB;
  bpIndex_8[0] = rtb_k_Mach;
  bpIndex_8[1] = rtb_k_alB;
  bpIndex_8[2] = rtb_k_beB;
  rtb_Subtract_ju = intrp3d_l_pw(bpIndex_8, frac_8,
    GRM_HIL_P.Cx_base_Interpolation_Table,
    GRM_HIL_P.Cx_base_Interpolation_dimSize);

  /* Clock: '<S206>/Clock' incorporates:
   *  Derivative: '<S159>/Derivative'
   *  Derivative: '<S159>/Derivative1'
   */
  rtb_Add = GRM_HIL_M->Timing.t[0];

  /* Sum: '<S71>/Subtract' incorporates:
   *  Clock: '<S206>/Clock'
   *  Constant: '<S206>/Constant6'
   *  Sum: '<S168>/Subtract'
   *  Sum: '<S64>/Subtract'
   */
  rtb_Subtract_ay_tmp = rtb_Add - GRM_HIL_P.Constant6_Value_i;

  /* Sum: '<S72>/Add' incorporates:
   *  Constant: '<S71>/Constant'
   *  MATLAB Function: '<S71>/MATLAB Function'
   *  Product: '<S72>/Product2'
   *  Product: '<S72>/Product8'
   *  Sum: '<S71>/Subtract'
   */
  rtb_Product1_m[0] = ((((((((rtb_Cx + rtb_Product_l) + rtb_Product1) +
    rtb_Gain_af * rtb_siB_c5) + rtb_Product3_hu) + rtb_Product4_e) +
    rtb_Product5) + rtb_Product6_e) + rtb_Product6_n4) + (real_T)
    ((!(rtb_Subtract_ay_tmp >= 0.0)) || (!(rtb_Subtract_ay_tmp <=
       GRM_HIL_P.Constant_Value_ok))) * rtb_Subtract_ju;

  /* Interpolation_n-D: '<S93>/Cy_Interpolation' */
  frac_9[0] = rtb_lat;
  frac_9[1] = rtb_Sqrt_j;
  frac_9[2] = rtb_f_beB;
  bpIndex_9[0] = rtb_k_Mach;
  bpIndex_9[1] = rtb_k_alB;
  bpIndex_9[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_9, frac_9,
    GRM_HIL_P.Cy_Interpolation_Table, GRM_HIL_P.Cy_Interpolation_dimSize);

  /* Product: '<S93>/Product' incorporates:
   *  Constant: '<S93>/Constant'
   */
  rtb_siB_c5 = GRM_HIL_P.Constant_Value_oz * rtb_Product6_n4;

  /* Interpolation_n-D: '<S93>/Cyp_Interpolation' */
  frac_a[0] = rtb_lat;
  frac_a[1] = rtb_Sqrt_j;
  frac_a[2] = rtb_f_beB;
  bpIndex_a[0] = rtb_k_Mach;
  bpIndex_a[1] = rtb_k_alB;
  bpIndex_a[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_a, frac_a,
    GRM_HIL_P.Cyp_Interpolation_Table, GRM_HIL_P.Cyp_Interpolation_dimSize);

  /* Product: '<S72>/Product6' */
  rtb_Product6_e = rtb_Gain_g * rtb_Product6_n4;

  /* Interpolation_n-D: '<S93>/Cyq_Interpolation' */
  frac_b[0] = rtb_lat;
  frac_b[1] = rtb_Sqrt_j;
  frac_b[2] = rtb_f_beB;
  bpIndex_b[0] = rtb_k_Mach;
  bpIndex_b[1] = rtb_k_alB;
  bpIndex_b[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_b, frac_b,
    GRM_HIL_P.Cyq_Interpolation_Table, GRM_HIL_P.Cyq_Interpolation_dimSize);

  /* Product: '<S72>/Product7' */
  rtb_Subtract_ju = rtb_Gain_lt * rtb_Product6_n4;

  /* Interpolation_n-D: '<S93>/Cyr_Interpolation' */
  frac_c[0] = rtb_lat;
  frac_c[1] = rtb_Sqrt_j;
  frac_c[2] = rtb_f_beB;
  bpIndex_c[0] = rtb_k_Mach;
  bpIndex_c[1] = rtb_k_alB;
  bpIndex_c[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_c, frac_c,
    GRM_HIL_P.Cyr_Interpolation_Table, GRM_HIL_P.Cyr_Interpolation_dimSize);

  /* Product: '<S72>/Product9' */
  rtb_Subtract_cl = rtb_Gain_af * rtb_Product6_n4;

  /* Interpolation_n-D: '<S93>/Cy_delta_l_Interpolation' */
  frac_d[0] = rtb_lat;
  frac_d[1] = rtb_Sqrt_j;
  frac_d[2] = rtb_f_beB;
  bpIndex_d[0] = rtb_k_Mach;
  bpIndex_d[1] = rtb_k_alB;
  bpIndex_d[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_d, frac_d,
    GRM_HIL_P.Cy_delta_l_Interpolation_Table,
    GRM_HIL_P.Cy_delta_l_Interpolation_dimSize);

  /* Product: '<S72>/Product10' */
  rtb_Cx = rtb_Gain_fl * rtb_Product6_n4;

  /* Interpolation_n-D: '<S93>/Cy_delta_m_Interpolation' */
  frac_e[0] = rtb_lat;
  frac_e[1] = rtb_Sqrt_j;
  frac_e[2] = rtb_f_beB;
  bpIndex_e[0] = rtb_k_Mach;
  bpIndex_e[1] = rtb_k_alB;
  bpIndex_e[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_e, frac_e,
    GRM_HIL_P.Cy_delta_m_Interpolation_Table,
    GRM_HIL_P.Cy_delta_m_Interpolation_dimSize);

  /* Product: '<S72>/Product11' */
  rtb_Product_l = rtb_Gain_nk * rtb_Product6_n4;

  /* Interpolation_n-D: '<S93>/Cy_delta_n_Interpolation' */
  frac_f[0] = rtb_lat;
  frac_f[1] = rtb_Sqrt_j;
  frac_f[2] = rtb_f_beB;
  bpIndex_f[0] = rtb_k_Mach;
  bpIndex_f[1] = rtb_k_alB;
  bpIndex_f[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_f, frac_f,
    GRM_HIL_P.Cy_delta_n_Interpolation_Table,
    GRM_HIL_P.Cy_delta_n_Interpolation_dimSize);

  /* Sum: '<S72>/Add1' incorporates:
   *  Product: '<S72>/Product12'
   */
  rtb_Product1_m[1] = (((((rtb_siB_c5 + rtb_Product6_e) + rtb_Subtract_ju) +
    rtb_Subtract_cl) + rtb_Cx) + rtb_Product_l) + rtb_Gain_n * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Cz_Interpolation' */
  frac_g[0] = rtb_lat;
  frac_g[1] = rtb_Sqrt_j;
  frac_g[2] = rtb_f_beB;
  bpIndex_g[0] = rtb_k_Mach;
  bpIndex_g[1] = rtb_k_alB;
  bpIndex_g[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_g, frac_g,
    GRM_HIL_P.Cz_Interpolation_Table, GRM_HIL_P.Cz_Interpolation_dimSize);

  /* Product: '<S94>/Product' incorporates:
   *  Constant: '<S94>/Constant'
   */
  rtb_siB_c5 = GRM_HIL_P.Constant_Value_gw * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Czp_Interpolation' */
  frac_h[0] = rtb_lat;
  frac_h[1] = rtb_Sqrt_j;
  frac_h[2] = rtb_f_beB;
  bpIndex_h[0] = rtb_k_Mach;
  bpIndex_h[1] = rtb_k_alB;
  bpIndex_h[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_h, frac_h,
    GRM_HIL_P.Czp_Interpolation_Table, GRM_HIL_P.Czp_Interpolation_dimSize);

  /* Product: '<S72>/Product16' */
  rtb_Product6_e = rtb_Gain_g * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Czq_Interpolation' */
  frac_i[0] = rtb_lat;
  frac_i[1] = rtb_Sqrt_j;
  frac_i[2] = rtb_f_beB;
  bpIndex_i[0] = rtb_k_Mach;
  bpIndex_i[1] = rtb_k_alB;
  bpIndex_i[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_i, frac_i,
    GRM_HIL_P.Czq_Interpolation_Table, GRM_HIL_P.Czq_Interpolation_dimSize);

  /* Product: '<S72>/Product17' */
  rtb_Subtract_ju = rtb_Gain_lt * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Czr_Interpolation' */
  frac_j[0] = rtb_lat;
  frac_j[1] = rtb_Sqrt_j;
  frac_j[2] = rtb_f_beB;
  bpIndex_j[0] = rtb_k_Mach;
  bpIndex_j[1] = rtb_k_alB;
  bpIndex_j[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_j, frac_j,
    GRM_HIL_P.Czr_Interpolation_Table, GRM_HIL_P.Czr_Interpolation_dimSize);

  /* Product: '<S72>/Product18' */
  rtb_Subtract_cl = rtb_Gain_af * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Cz_delta_l_Interpolation' */
  frac_k[0] = rtb_lat;
  frac_k[1] = rtb_Sqrt_j;
  frac_k[2] = rtb_f_beB;
  bpIndex_k[0] = rtb_k_Mach;
  bpIndex_k[1] = rtb_k_alB;
  bpIndex_k[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_k, frac_k,
    GRM_HIL_P.Cz_delta_l_Interpolation_Table,
    GRM_HIL_P.Cz_delta_l_Interpolation_dimSize);

  /* Product: '<S72>/Product13' */
  rtb_Cx = rtb_Gain_fl * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Cz_delta_m_Interpolation' */
  frac_l[0] = rtb_lat;
  frac_l[1] = rtb_Sqrt_j;
  frac_l[2] = rtb_f_beB;
  bpIndex_l[0] = rtb_k_Mach;
  bpIndex_l[1] = rtb_k_alB;
  bpIndex_l[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_l, frac_l,
    GRM_HIL_P.Cz_delta_m_Interpolation_Table,
    GRM_HIL_P.Cz_delta_m_Interpolation_dimSize);

  /* Product: '<S72>/Product14' */
  rtb_Product_l = rtb_Gain_nk * rtb_Product6_n4;

  /* Interpolation_n-D: '<S94>/Cz_delta_n_Interpolation' */
  frac_m[0] = rtb_lat;
  frac_m[1] = rtb_Sqrt_j;
  frac_m[2] = rtb_f_beB;
  bpIndex_m[0] = rtb_k_Mach;
  bpIndex_m[1] = rtb_k_alB;
  bpIndex_m[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_m, frac_m,
    GRM_HIL_P.Cz_delta_n_Interpolation_Table,
    GRM_HIL_P.Cz_delta_n_Interpolation_dimSize);

  /* Sum: '<S72>/Add2' incorporates:
   *  Product: '<S72>/Product15'
   */
  rtb_Product1_m[2] = (((((rtb_siB_c5 + rtb_Product6_e) + rtb_Subtract_ju) +
    rtb_Subtract_cl) + rtb_Cx) + rtb_Product_l) + rtb_Gain_n * rtb_Product6_n4;

  /* Sum: '<S124>/Add' incorporates:
   *  Constant: '<S124>/Constant1'
   *  Constant: '<S124>/Tmp_gradient_tropo'
   *  Product: '<S124>/Divide'
   */
  rtb_Product6_n4 = rtb_Step1 / GRM_HIL_B.Tmp_ref *
    GRM_HIL_P.Tmp_gradient_tropo_Value_l + GRM_HIL_P.Constant1_Value_mh;

  /* Math: '<S124>/Math Function' incorporates:
   *  Constant: '<S124>/pressure_exponent'
   */
  if ((rtb_Product6_n4 < 0.0) && (GRM_HIL_P.pressure_exponent_Value > floor
       (GRM_HIL_P.pressure_exponent_Value))) {
    rtb_Product6_n4 = -rt_powd_snf(-rtb_Product6_n4,
      GRM_HIL_P.pressure_exponent_Value);
  } else {
    rtb_Product6_n4 = rt_powd_snf(rtb_Product6_n4,
      GRM_HIL_P.pressure_exponent_Value);
  }

  /* End of Math: '<S124>/Math Function' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S122>/Subtract2' incorporates:
     *  Constant: '<S122>/pa_norm_msl'
     *  Constant: '<S207>/deviation_pa_QFH'
     */
    GRM_HIL_B.pa_ref = GRM_HIL_P.deviation_pa_QFH_Value +
      GRM_HIL_P.pa_norm_msl_Value;
  }

  /* Product: '<S73>/Product2' incorporates:
   *  Constant: '<S119>/specific_gas_constant'
   *  Constant: '<S199>/Constant'
   *  Constant: '<S73>/Constant2'
   *  Math: '<S199>/Math Function1'
   *  Product: '<S119>/Divide'
   *  Product: '<S124>/Product'
   *  Product: '<S199>/Product1'
   */
  rtb_Step1 = 1.0 / rtb_Tmp * (rtb_Product6_n4 * GRM_HIL_B.pa_ref) /
    GRM_HIL_P.specific_gas_constant_Value_c * (rtb_VectorConcatenate_f_idx_0 *
    rtb_VectorConcatenate_f_idx_0 * GRM_HIL_P.Constant_Value_ii) *
    GRM_HIL_P.Constant2_Value_a2;

  /* Product: '<S73>/Product' */
  frac[0] = rtb_Product1_m[0] * rtb_Step1;
  frac[1] = rtb_Product1_m[1] * rtb_Step1;
  frac[2] = rtb_Product1_m[2] * rtb_Step1;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S81>/Switch1' incorporates:
     *  Constant: '<S81>/Constant'
     *  Constant: '<S81>/Constant2'
     *  Constant: '<S82>/c_flat'
     *  Constant: '<S82>/c_rsma'
     *  Constant: '<S83>/Constant'
     *  Gain: '<S81>/Gain'
     *  Gain: '<S83>/Gain'
     *  Product: '<S83>/Product'
     *  Product: '<S83>/Product4'
     *  Product: '<S83>/Product5'
     *  Sqrt: '<S83>/Sqrt1'
     *  Sum: '<S83>/Subtract'
     *  Sum: '<S83>/Subtract1'
     *  Sum: '<S83>/Sum'
     *  Trigonometry: '<S83>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_o > GRM_HIL_P.Switch1_Threshold) {
      GRM_HIL_B.hBE_0 = GRM_HIL_P.Gain_Gain_i * GRM_HIL_P.Constant_Value_iu[2];
    } else {
      /* Sqrt: '<S84>/Sqrt' incorporates:
       *  Constant: '<S81>/Constant'
       *  Product: '<S84>/Product1'
       *  Product: '<S84>/Product2'
       *  Sqrt: '<S83>/Sqrt'
       *  Sum: '<S84>/Add'
       */
      rtb_Product6_n4 = sqrt(GRM_HIL_P.Constant_Value_iu[0] *
        GRM_HIL_P.Constant_Value_iu[0] + GRM_HIL_P.Constant_Value_iu[1] *
        GRM_HIL_P.Constant_Value_iu[1]);

      /* Product: '<S84>/Product' incorporates:
       *  Constant: '<S82>/c_flat'
       *  Constant: '<S82>/c_rsma'
       *  Constant: '<S84>/Constant'
       *  Sum: '<S84>/Subtract'
       */
      rtb_Tmp = (GRM_HIL_P.Constant_Value_g - GRM_HIL_P.c_flat_Value) *
        GRM_HIL_P.c_rsma_Value;

      /* Trigonometry: '<S84>/Trigonometric Function' incorporates:
       *  Constant: '<S81>/Constant'
       *  Constant: '<S82>/c_rsma'
       *  Product: '<S84>/Divide1'
       *  Product: '<S84>/Product6'
       *  Product: '<S84>/Product7'
       *  Sqrt: '<S84>/Sqrt'
       */
      rtb_siB_c5 = atan(GRM_HIL_P.Constant_Value_iu[2] * GRM_HIL_P.c_rsma_Value /
                        (rtb_Product6_n4 * rtb_Tmp));

      /* Trigonometry: '<S84>/Trigonometric Function3' */
      rtb_Product6_e = cos(rtb_siB_c5);

      /* Product: '<S84>/Product9' */
      rtb_VectorConcatenate_f_idx_0 = rtb_Product6_e * rtb_Product6_e *
        rtb_Product6_e;

      /* Trigonometry: '<S84>/Trigonometric Function2' */
      rtb_siB_c5 = sin(rtb_siB_c5);

      /* Product: '<S84>/Product5' */
      rtb_Product6_e = rtb_Tmp * rtb_Tmp;

      /* Product: '<S84>/Product10' incorporates:
       *  Constant: '<S82>/c_rsma'
       *  Product: '<S84>/Divide'
       *  Product: '<S84>/Product4'
       *  Product: '<S84>/Product8'
       *  Sum: '<S84>/Subtract2'
       */
      rtb_Tmp = (GRM_HIL_P.c_rsma_Value * GRM_HIL_P.c_rsma_Value -
                 rtb_Product6_e) / rtb_Product6_e * rtb_Tmp * (rtb_siB_c5 *
        rtb_siB_c5 * rtb_siB_c5);

      /* Sum: '<S84>/Add1' incorporates:
       *  Constant: '<S81>/Constant'
       */
      rtb_Tmp += GRM_HIL_P.Constant_Value_iu[2];

      /* Product: '<S84>/Product3' incorporates:
       *  Constant: '<S82>/c_flat'
       *  Product: '<S83>/Product3'
       */
      rtb_Product_l = GRM_HIL_P.c_flat_Value * GRM_HIL_P.c_flat_Value;

      /* Trigonometry: '<S84>/Trigonometric Function1' incorporates:
       *  Constant: '<S82>/c_flat'
       *  Constant: '<S82>/c_rsma'
       *  Gain: '<S84>/Gain'
       *  Product: '<S84>/Divide2'
       *  Product: '<S84>/Product11'
       *  Product: '<S84>/Product3'
       *  Sqrt: '<S84>/Sqrt'
       *  Sum: '<S84>/Subtract1'
       *  Sum: '<S84>/Subtract3'
       */
      rtb_Product6_e = atan(rtb_Tmp / (rtb_Product6_n4 - (GRM_HIL_P.Gain_Gain_c *
        GRM_HIL_P.c_flat_Value - rtb_Product_l) * GRM_HIL_P.c_rsma_Value *
        rtb_VectorConcatenate_f_idx_0));

      /* Trigonometry: '<S83>/Trigonometric Function' */
      rtb_siB_c5 = sin(rtb_Product6_e);
      GRM_HIL_B.hBE_0 = rtb_Product6_n4 / cos(rtb_Product6_e) -
        GRM_HIL_P.c_rsma_Value / sqrt(GRM_HIL_P.Constant_Value_j -
        (GRM_HIL_P.Gain_Gain * GRM_HIL_P.c_flat_Value - rtb_Product_l) *
        (rtb_siB_c5 * rtb_siB_c5));
    }

    /* End of Switch: '<S81>/Switch1' */

    /* SignalConversion generated from: '<S79>/Vector Concatenate' incorporates:
     *  Constant: '<S79>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[0] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S79>/Vector Concatenate' incorporates:
     *  Constant: '<S79>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[1] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S79>/Vector Concatenate' incorporates:
     *  Constant: '<S79>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[2] = GRM_HIL_P.Constant3_Value_f4;
  }

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<S79>/Constant1'
   *  Sum: '<S79>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_lx) - GRM_HIL_B.hBE_0 >
      GRM_HIL_P.Switch_Threshold_f) {
    rtb_Product1_m[0] = frac[0];
    rtb_Product1_m[1] = frac[1];
    rtb_Product1_m[2] = frac[2];
  } else {
    rtb_Product1_m[0] = GRM_HIL_B.VectorConcatenate[0];
    rtb_Product1_m[1] = GRM_HIL_B.VectorConcatenate[1];
    rtb_Product1_m[2] = GRM_HIL_B.VectorConcatenate[2];
  }

  /* End of Switch: '<S79>/Switch' */

  /* Saturate: '<S53>/Saturation' */
  if (GRM_HIL_B.Switch[2] > GRM_HIL_P.Saturation_UpperSat_d) {
    rtb_Product6_n4 = GRM_HIL_P.Saturation_UpperSat_d;
  } else if (GRM_HIL_B.Switch[2] < GRM_HIL_P.Saturation_LowerSat_j) {
    rtb_Product6_n4 = GRM_HIL_P.Saturation_LowerSat_j;
  } else {
    rtb_Product6_n4 = GRM_HIL_B.Switch[2];
  }

  /* End of Saturate: '<S53>/Saturation' */

  /* Trigonometry: '<S117>/Trigonometric Function' incorporates:
   *  Switch: '<S159>/Switch'
   *  Trigonometry: '<S115>/Trigonometric Function2'
   *  Trigonometry: '<S159>/Trigonometric Function'
   */
  rtb_Tmp = sin(GRM_HIL_B.Switch[1]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S118>/Divide' incorporates:
     *  Constant: '<S117>/WGS84 Semi-major Axis, [m]'
     *  Constant: '<S117>/WGS84 Semi-minor Axis, [m]'
     *  Sum: '<S118>/Add'
     */
    rtb_Switch1 = (GRM_HIL_P.WGS84SemimajorAxism_Value -
                   GRM_HIL_P.WGS84SemiminorAxism_Value) /
      GRM_HIL_P.WGS84SemimajorAxism_Value;

    /* Product: '<S118>/Divide1' incorporates:
     *  Constant: '<S118>/a2'
     *  Sum: '<S118>/Add1'
     */
    rtb_Switch1 *= GRM_HIL_P.a2_Value - rtb_Switch1;

    /* Sqrt: '<S118>/Sqrt' */
    rtb_Switch1 = sqrt(rtb_Switch1);

    /* Product: '<S117>/Divide' */
    GRM_HIL_B.e2 = rtb_Switch1 * rtb_Switch1;

    /* Sum: '<S115>/Add1' incorporates:
     *  Constant: '<S115>/Constant'
     *  Product: '<S115>/Divide2'
     */
    GRM_HIL_B.Add1 = GRM_HIL_P.Constant_Value_ov - rtb_Switch1 * rtb_Switch1;
  }

  /* Product: '<S117>/Divide3' incorporates:
   *  Constant: '<S117>/WGS84 Semi-major Axis, [m]'
   *  Constant: '<S117>/a3'
   *  Product: '<S117>/Divide1'
   *  Product: '<S117>/Divide2'
   *  Sqrt: '<S117>/Sqrt'
   *  Sum: '<S117>/Add2'
   *  Trigonometry: '<S117>/Trigonometric Function'
   */
  rtb_Product6_e = 1.0 / sqrt(GRM_HIL_P.a3_Value - rtb_Tmp * rtb_Tmp *
    GRM_HIL_B.e2) * GRM_HIL_P.WGS84SemimajorAxism_Value;

  /* Sum: '<S115>/Add3' */
  rtb_Subtract_ju = rtb_Product6_n4 + rtb_Product6_e;

  /* Trigonometry: '<S115>/Trigonometric Function3' incorporates:
   *  Switch: '<S159>/Switch'
   *  Trigonometry: '<S159>/Trigonometric Function1'
   */
  rtb_siB_c5 = cos(GRM_HIL_B.Switch[1]);

  /* Trigonometry: '<S115>/Trigonometric Function1' incorporates:
   *  MATLAB Function: '<S109>/WGS84_Gravity_Implementation'
   */
  frac_tmp = cos(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S116>/ SFunction ' incorporates:
   *  MATLAB Function: '<S109>/WGS84_Gravity_Implementation'
   *  Product: '<S115>/Divide'
   *  Trigonometry: '<S115>/Trigonometric Function1'
   *  Trigonometry: '<S115>/Trigonometric Function3'
   */
  frac_0[0] = rtb_Subtract_ju * frac_tmp * rtb_siB_c5;

  /* Trigonometry: '<S115>/Trigonometric Function' incorporates:
   *  MATLAB Function: '<S109>/WGS84_Gravity_Implementation'
   */
  frac_tmp_0 = sin(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S116>/ SFunction ' incorporates:
   *  MATLAB Function: '<S109>/WGS84_Gravity_Implementation'
   *  Product: '<S115>/Divide1'
   *  Product: '<S115>/Divide3'
   *  Product: '<S115>/Divide4'
   *  Sum: '<S115>/Add2'
   *  Trigonometry: '<S115>/Trigonometric Function'
   *  Trigonometry: '<S115>/Trigonometric Function3'
   */
  frac_0[1] = rtb_Subtract_ju * frac_tmp_0 * rtb_siB_c5;
  frac_0[2] = (rtb_Product6_e * GRM_HIL_B.Add1 + rtb_Product6_n4) * rtb_Tmp;

  /* MATLAB Function: '<S109>/WGS84_Gravity_Implementation' */
  rtb_Product_l = GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS;
  u0 = GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma;
  rtb_Product6_e = sqrt(u0 - rtb_Product_l);
  rtb_Product3_hu = rtb_Product6_e * rtb_Product6_e;
  rtb_Gain1_n4_tmp = frac_0[2] * frac_0[2];
  rtb_Subtract_ju = frac_0[0] * frac_0[0] + frac_0[1] * frac_0[1];
  rtb_Switch1 = (rtb_Subtract_ju + rtb_Gain1_n4_tmp) - rtb_Product3_hu;
  rtb_VectorConcatenate_f_idx_0 = sqrt((sqrt(rtb_Product3_hu * 4.0 *
    rtb_Gain1_n4_tmp / (rtb_Switch1 * rtb_Switch1) + 1.0) + 1.0) * (rtb_Switch1 *
    0.5));
  rtb_Product4_e = rtb_VectorConcatenate_f_idx_0 * rtb_VectorConcatenate_f_idx_0;
  rtb_Switch1_tmp = rtb_Product4_e + rtb_Product3_hu;
  rtb_Switch1 = sqrt(rtb_Switch1_tmp);
  rtb_Subtract_ju = rt_atan2d_snf(frac_0[2] * rtb_Switch1, sqrt(rtb_Subtract_ju)
    * rtb_VectorConcatenate_f_idx_0);
  rtb_Subtract_cl = sin(rtb_Subtract_ju);
  rtb_Cx_tmp = rtb_Subtract_cl * rtb_Subtract_cl;
  rtb_Cx = sqrt((rtb_Product3_hu * rtb_Cx_tmp + rtb_Product4_e) /
                rtb_Switch1_tmp);
  rtb_Product_l = ((rtb_Product_l * 3.0 / rtb_Product3_hu + 1.0) * rt_atan2d_snf
                   (rtb_Product6_e,
                    GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS) - 3.0 *
                   GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS /
                   rtb_Product6_e) * 0.5;
  rtb_Product1 = cos(rtb_Subtract_ju);
  rtb_Product5 = rt_atan2d_snf(rtb_Product6_e, rtb_VectorConcatenate_f_idx_0);
  rtb_TBG[0] = rtb_VectorConcatenate_f_idx_0 / (rtb_Cx * rtb_Switch1) *
    rtb_Product1 * frac_tmp;
  rtb_TBG[3] = -1.0 / rtb_Cx * rtb_Subtract_cl * frac_tmp;
  rtb_TBG[6] = -frac_tmp_0;
  rtb_Gain1_n4_tmp = rtb_VectorConcatenate_f_idx_0 / (sqrt
    (rtb_VectorConcatenate_f_idx_0 * rtb_VectorConcatenate_f_idx_0 +
     rtb_Product6_e * rtb_Product6_e) * rtb_Cx) * cos(rtb_Subtract_ju);
  rtb_TBG[1] = rtb_Gain1_n4_tmp * frac_tmp_0;
  rtb_TBG[4] = -1.0 / rtb_Cx * sin(rtb_Subtract_ju) * frac_tmp_0;
  rtb_TBG[7] = frac_tmp;
  rtb_TBG[2] = 1.0 / rtb_Cx * rtb_Subtract_cl;
  rtb_TBG[5] = rtb_Gain1_n4_tmp;
  rtb_TBG[8] = 0.0;
  rtb_Subtract_ju = GRM_HIL_P.WGS84_Gravity_Implementation_c_rot *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rot;
  frac_tmp = GRM_HIL_P.WGS84_Gravitation_flg_omega_enabled / rtb_Cx *
    rtb_Subtract_ju;
  rtb_Cx_tmp = (((rtb_Product4_e / rtb_Product3_hu + 1.0) * 3.0 * (1.0 -
    rtb_VectorConcatenate_f_idx_0 / rtb_Product6_e * rtb_Product5) - 1.0) *
                (rtb_Subtract_ju * u0 * rtb_Product6_e / rtb_Switch1_tmp) /
                rtb_Product_l * (rtb_Cx_tmp * 0.5 - 0.16666666666666666) +
                GRM_HIL_P.WGS84_Gravity_Implementation_c_grav / rtb_Switch1_tmp)
    * (-1.0 / rtb_Cx) + frac_tmp * rtb_VectorConcatenate_f_idx_0 * (rtb_Product1
    * rtb_Product1);
  rtb_Switch1 = ((rtb_Product4_e * 3.0 / rtb_Product3_hu + 1.0) * rtb_Product5 -
                 3.0 * rtb_VectorConcatenate_f_idx_0 / rtb_Product6_e) * 0.5 *
    (1.0 / rtb_Cx * rtb_Subtract_ju * u0 / rtb_Switch1_tmp) / rtb_Product_l *
    rtb_Subtract_cl * rtb_Product1 - frac_tmp * rtb_Switch1 * rtb_Subtract_cl *
    rtb_Product1;
  for (i = 0; i < 3; i++) {
    frac_0[i] = rtb_TBG[i + 6] * 0.0 + (rtb_TBG[i + 3] * rtb_Switch1 + rtb_TBG[i]
      * rtb_Cx_tmp);
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S139>/Switch1' incorporates:
     *  Constant: '<S139>/Constant'
     *  Constant: '<S139>/Constant2'
     *  Constant: '<S140>/c_flat'
     *  Constant: '<S140>/c_rsma'
     *  Constant: '<S141>/Constant'
     *  Gain: '<S139>/Gain'
     *  Gain: '<S141>/Gain'
     *  Product: '<S141>/Product'
     *  Product: '<S141>/Product4'
     *  Product: '<S141>/Product5'
     *  Sqrt: '<S141>/Sqrt1'
     *  Sum: '<S141>/Subtract'
     *  Sum: '<S141>/Subtract1'
     *  Sum: '<S141>/Sum'
     *  Trigonometry: '<S141>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_id > GRM_HIL_P.Switch1_Threshold_d) {
      GRM_HIL_B.hBE_0_l = GRM_HIL_P.Gain_Gain_g * GRM_HIL_P.Constant_Value_g4[2];
    } else {
      /* Sqrt: '<S142>/Sqrt' incorporates:
       *  Constant: '<S139>/Constant'
       *  Product: '<S142>/Product1'
       *  Product: '<S142>/Product2'
       *  Sqrt: '<S141>/Sqrt'
       *  Sum: '<S142>/Add'
       */
      rtb_Product6_e = sqrt(GRM_HIL_P.Constant_Value_g4[0] *
                            GRM_HIL_P.Constant_Value_g4[0] +
                            GRM_HIL_P.Constant_Value_g4[1] *
                            GRM_HIL_P.Constant_Value_g4[1]);

      /* Product: '<S142>/Product' incorporates:
       *  Constant: '<S140>/c_flat'
       *  Constant: '<S140>/c_rsma'
       *  Constant: '<S142>/Constant'
       *  Sum: '<S142>/Subtract'
       */
      rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_P.Constant_Value_e -
        GRM_HIL_P.c_flat_Value_c) * GRM_HIL_P.c_rsma_Value_m;

      /* Trigonometry: '<S142>/Trigonometric Function' incorporates:
       *  Constant: '<S139>/Constant'
       *  Constant: '<S140>/c_rsma'
       *  Product: '<S142>/Divide1'
       *  Product: '<S142>/Product6'
       *  Product: '<S142>/Product7'
       *  Sqrt: '<S142>/Sqrt'
       */
      rtb_Switch1 = atan(GRM_HIL_P.Constant_Value_g4[2] *
                         GRM_HIL_P.c_rsma_Value_m / (rtb_Product6_e *
        rtb_VectorConcatenate_f_idx_0));

      /* Trigonometry: '<S142>/Trigonometric Function3' */
      rtb_Subtract_ju = cos(rtb_Switch1);

      /* Product: '<S142>/Product9' */
      rtb_Subtract_cl = rtb_Subtract_ju * rtb_Subtract_ju * rtb_Subtract_ju;

      /* Trigonometry: '<S142>/Trigonometric Function2' */
      rtb_Switch1 = sin(rtb_Switch1);

      /* Product: '<S142>/Product5' */
      rtb_Subtract_ju = rtb_VectorConcatenate_f_idx_0 *
        rtb_VectorConcatenate_f_idx_0;

      /* Product: '<S142>/Product10' incorporates:
       *  Constant: '<S140>/c_rsma'
       *  Product: '<S142>/Divide'
       *  Product: '<S142>/Product4'
       *  Product: '<S142>/Product8'
       *  Sum: '<S142>/Subtract2'
       */
      rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_P.c_rsma_Value_m *
        GRM_HIL_P.c_rsma_Value_m - rtb_Subtract_ju) / rtb_Subtract_ju *
        rtb_VectorConcatenate_f_idx_0 * (rtb_Switch1 * rtb_Switch1 * rtb_Switch1);

      /* Sum: '<S142>/Add1' incorporates:
       *  Constant: '<S139>/Constant'
       */
      rtb_VectorConcatenate_f_idx_0 += GRM_HIL_P.Constant_Value_g4[2];

      /* Product: '<S142>/Product3' incorporates:
       *  Constant: '<S140>/c_flat'
       *  Product: '<S141>/Product3'
       */
      rtb_Cx = GRM_HIL_P.c_flat_Value_c * GRM_HIL_P.c_flat_Value_c;

      /* Trigonometry: '<S142>/Trigonometric Function1' incorporates:
       *  Constant: '<S140>/c_flat'
       *  Constant: '<S140>/c_rsma'
       *  Gain: '<S142>/Gain'
       *  Product: '<S142>/Divide2'
       *  Product: '<S142>/Product11'
       *  Product: '<S142>/Product3'
       *  Sqrt: '<S142>/Sqrt'
       *  Sum: '<S142>/Subtract1'
       *  Sum: '<S142>/Subtract3'
       */
      rtb_Subtract_ju = atan(rtb_VectorConcatenate_f_idx_0 / (rtb_Product6_e -
        (GRM_HIL_P.Gain_Gain_j * GRM_HIL_P.c_flat_Value_c - rtb_Cx) *
        GRM_HIL_P.c_rsma_Value_m * rtb_Subtract_cl));

      /* Trigonometry: '<S141>/Trigonometric Function' */
      rtb_Switch1 = sin(rtb_Subtract_ju);
      GRM_HIL_B.hBE_0_l = rtb_Product6_e / cos(rtb_Subtract_ju) -
        GRM_HIL_P.c_rsma_Value_m / sqrt(GRM_HIL_P.Constant_Value_o -
        (GRM_HIL_P.Gain_Gain_l * GRM_HIL_P.c_flat_Value_c - rtb_Cx) *
        (rtb_Switch1 * rtb_Switch1));
    }

    /* End of Switch: '<S139>/Switch1' */

    /* SignalConversion generated from: '<S138>/Vector Concatenate' incorporates:
     *  Constant: '<S138>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[0] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S138>/Vector Concatenate' incorporates:
     *  Constant: '<S138>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[1] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S138>/Vector Concatenate' incorporates:
     *  Constant: '<S138>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[2] = GRM_HIL_P.Constant3_Value_j;
  }

  /* Switch: '<S138>/Switch' incorporates:
   *  Constant: '<S138>/Constant1'
   *  Sum: '<S138>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_mm) - GRM_HIL_B.hBE_0_l >
      GRM_HIL_P.Switch_Threshold_gn) {
    /* Sqrt: '<S111>/Sqrt' incorporates:
     *  DotProduct: '<S111>/Dot Product'
     */
    rtb_sincos_o2[2] = sqrt((frac_0[0] * frac_0[0] + frac_0[1] * frac_0[1]) +
      frac_0[2] * frac_0[2]);

    /* SignalConversion generated from: '<S111>/Vector Concatenate' incorporates:
     *  Constant: '<S111>/Constant1'
     */
    rtb_sincos_o2[1] = GRM_HIL_P.Constant1_Value_cj;

    /* SignalConversion generated from: '<S111>/Vector Concatenate' incorporates:
     *  Constant: '<S111>/Constant1'
     */
    rtb_sincos_o2[0] = GRM_HIL_P.Constant1_Value_cj;
  } else {
    rtb_sincos_o2[0] = GRM_HIL_B.VectorConcatenate_f[0];
    rtb_sincos_o2[1] = GRM_HIL_B.VectorConcatenate_f[1];
    rtb_sincos_o2[2] = GRM_HIL_B.VectorConcatenate_f[2];
  }

  /* End of Switch: '<S138>/Switch' */

  /* Sum: '<S64>/Subtract' */
  rtb_Product6_e = rtb_Subtract_ay_tmp;

  /* Switch: '<S216>/Switch' incorporates:
   *  Constant: '<S216>/Constant'
   */
  if (!(rtb_Subtract_ay_tmp > GRM_HIL_P.Switch_Threshold_fo)) {
    rtb_Product6_e = GRM_HIL_P.Constant_Value_k;
  }

  /* End of Switch: '<S216>/Switch' */

  /* Switch: '<S216>/Switch1' incorporates:
   *  Lookup_n-D: '<S216>/1-D Lookup Table'
   */
  if (rtb_Product6_e > GRM_HIL_P.Switch1_Threshold_f) {
    /* Saturate: '<S216>/Saturation' */
    if (rtb_Product6_e > GRM_HIL_P.Saturation_UpperSat_c) {
      rtb_Product6_e = GRM_HIL_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Product6_e < GRM_HIL_P.Saturation_LowerSat_h) {
        rtb_Product6_e = GRM_HIL_P.Saturation_LowerSat_h;
      }
    }

    /* End of Saturate: '<S216>/Saturation' */
    rtb_Product6_e = look1_binlcapw(rtb_Product6_e,
      GRM_HIL_P.uDLookupTable_bp01Data, GRM_HIL_P.uDLookupTable_tableData, 16U);
  }

  /* End of Switch: '<S216>/Switch1' */

  /* Sum: '<S217>/Add' incorporates:
   *  Constant: '<S216>/Constant1'
   *  Constant: '<S216>/Constant2'
   *  Constant: '<S217>/Constant'
   *  Constant: '<S217>/Constant1'
   *  Product: '<S217>/Product'
   *  Sum: '<S216>/Subtract1'
   */
  rtb_Subtract_ju = ((GRM_HIL_P.Constant1_Value_iw - rtb_Product6_e) +
                     GRM_HIL_P.Constant2_Value_p) * GRM_HIL_P.Constant1_Value_mo
    + GRM_HIL_P.Constant_Value_bs;

  /* Product: '<S56>/Product' */
  rtb_sincos_o2[0] *= rtb_Subtract_ju;
  rtb_sincos_o2[1] *= rtb_Subtract_ju;
  rtb_Switch1 = rtb_sincos_o2[2] * rtb_Subtract_ju;

  /* Product: '<S55>/Product' incorporates:
   *  Math: '<S55>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac_1[i] = rtb_vBEB_a_tmp[i + 6] * rtb_Switch1 + (rtb_vBEB_a_tmp[i + 3] *
      rtb_sincos_o2[1] + rtb_vBEB_a_tmp[i] * rtb_sincos_o2[0]);
  }

  /* End of Product: '<S55>/Product' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S170>/Multiport Switch2' incorporates:
     *  Constant: '<S170>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3) {
     case 1:
      /* Trigonometry: '<S178>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/thrust_rot_x'
       *  Trigonometry: '<S178>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S178>/Trigonometric Function3' incorporates:
       *  Constant: '<S169>/thrust_rot_x'
       *  Trigonometry: '<S178>/Trigonometric Function'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S178>/Matrix Concatenate' incorporates:
       *  Constant: '<S178>/Constant7'
       *  Trigonometry: '<S178>/Trigonometric Function1'
       *  Trigonometry: '<S178>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_k;
      rtb_MultiportSwitch[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[8] = rtb_Subtract_cl;

      /* SignalConversion generated from: '<S178>/Matrix Concatenate' incorporates:
       *  Constant: '<S178>/Constant8'
       *  Gain: '<S178>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_a;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_h *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S178>/Matrix Concatenate' incorporates:
       *  Constant: '<S178>/Constant'
       *  Constant: '<S178>/Constant1'
       *  Constant: '<S178>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_d;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_j;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_j;
      break;

     case 2:
      /* Trigonometry: '<S179>/Trigonometric Function3' incorporates:
       *  Constant: '<S169>/thrust_rot_x'
       *  Trigonometry: '<S179>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S179>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/thrust_rot_x'
       *  Trigonometry: '<S179>/Trigonometric Function2'
       */
      rtb_Subtract_cl = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S179>/Matrix Concatenate' incorporates:
       *  Constant: '<S179>/Constant7'
       *  Gain: '<S179>/Gain1'
       *  Trigonometry: '<S179>/Trigonometric Function1'
       *  Trigonometry: '<S179>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_d * rtb_Subtract_cl;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_a5;
      rtb_MultiportSwitch[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S179>/Matrix Concatenate' incorporates:
       *  Constant: '<S179>/Constant'
       *  Constant: '<S179>/Constant1'
       *  Constant: '<S179>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ek;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_k;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_f;

      /* SignalConversion generated from: '<S179>/Matrix Concatenate' incorporates:
       *  Constant: '<S179>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_k;
      rtb_MultiportSwitch[2] = rtb_Subtract_cl;
      break;

     default:
      /* SignalConversion generated from: '<S180>/Matrix Concatenate' incorporates:
       *  Constant: '<S180>/Constant10'
       *  Constant: '<S180>/Constant11'
       *  Constant: '<S180>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_b;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_f;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_o;

      /* Trigonometry: '<S180>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/thrust_rot_x'
       *  Trigonometry: '<S180>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S180>/Trigonometric Function' incorporates:
       *  Constant: '<S169>/thrust_rot_x'
       *  Trigonometry: '<S180>/Trigonometric Function3'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S180>/Matrix Concatenate' incorporates:
       *  Constant: '<S180>/Constant7'
       *  Trigonometry: '<S180>/Trigonometric Function'
       *  Trigonometry: '<S180>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_is;

      /* SignalConversion generated from: '<S180>/Matrix Concatenate' incorporates:
       *  Constant: '<S180>/Constant8'
       *  Gain: '<S180>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Subtract_cl;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_e *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_d;
      break;
    }

    /* End of MultiPortSwitch: '<S170>/Multiport Switch2' */

    /* MultiPortSwitch: '<S170>/Multiport Switch1' incorporates:
     *  Constant: '<S170>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2) {
     case 1:
      /* Trigonometry: '<S175>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/thrust_rot_y'
       *  Trigonometry: '<S175>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S175>/Trigonometric Function3' incorporates:
       *  Constant: '<S169>/thrust_rot_y'
       *  Trigonometry: '<S175>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S175>/Matrix Concatenate' incorporates:
       *  Constant: '<S175>/Constant7'
       *  Trigonometry: '<S175>/Trigonometric Function1'
       *  Trigonometry: '<S175>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_f;
      rtb_MultiportSwitch1[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S175>/Matrix Concatenate' incorporates:
       *  Constant: '<S175>/Constant8'
       *  Gain: '<S175>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_e;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_jq *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S175>/Matrix Concatenate' incorporates:
       *  Constant: '<S175>/Constant'
       *  Constant: '<S175>/Constant1'
       *  Constant: '<S175>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_a;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_n;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_e;
      break;

     case 2:
      /* Trigonometry: '<S176>/Trigonometric Function3' incorporates:
       *  Constant: '<S169>/thrust_rot_y'
       *  Trigonometry: '<S176>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S176>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/thrust_rot_y'
       *  Trigonometry: '<S176>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S176>/Matrix Concatenate' incorporates:
       *  Constant: '<S176>/Constant7'
       *  Gain: '<S176>/Gain1'
       *  Trigonometry: '<S176>/Trigonometric Function1'
       *  Trigonometry: '<S176>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_h * rtb_Switch1;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_ib;
      rtb_MultiportSwitch1[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S176>/Matrix Concatenate' incorporates:
       *  Constant: '<S176>/Constant'
       *  Constant: '<S176>/Constant1'
       *  Constant: '<S176>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_dk;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_l;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_m;

      /* SignalConversion generated from: '<S176>/Matrix Concatenate' incorporates:
       *  Constant: '<S176>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_bs;
      rtb_MultiportSwitch1[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S177>/Matrix Concatenate' incorporates:
       *  Constant: '<S177>/Constant10'
       *  Constant: '<S177>/Constant11'
       *  Constant: '<S177>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_h;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_fw;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_p;

      /* Trigonometry: '<S177>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/thrust_rot_y'
       *  Trigonometry: '<S177>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S177>/Trigonometric Function' incorporates:
       *  Constant: '<S169>/thrust_rot_y'
       *  Trigonometry: '<S177>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S177>/Matrix Concatenate' incorporates:
       *  Constant: '<S177>/Constant7'
       *  Trigonometry: '<S177>/Trigonometric Function'
       *  Trigonometry: '<S177>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_d;

      /* SignalConversion generated from: '<S177>/Matrix Concatenate' incorporates:
       *  Constant: '<S177>/Constant8'
       *  Gain: '<S177>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Switch1;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_hf *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_o;
      break;
    }

    /* End of MultiPortSwitch: '<S170>/Multiport Switch1' */

    /* MultiPortSwitch: '<S170>/Multiport Switch' incorporates:
     *  Constant: '<S170>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_m) {
     case 1:
      /* Trigonometry: '<S172>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/Thrust_rot_z'
       *  Trigonometry: '<S172>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S172>/Trigonometric Function3' incorporates:
       *  Constant: '<S169>/Thrust_rot_z'
       *  Trigonometry: '<S172>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S172>/Matrix Concatenate' incorporates:
       *  Constant: '<S172>/Constant7'
       *  Trigonometry: '<S172>/Trigonometric Function1'
       *  Trigonometry: '<S172>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_b;
      rtb_MultiportSwitch2[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S172>/Matrix Concatenate' incorporates:
       *  Constant: '<S172>/Constant8'
       *  Gain: '<S172>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_ks;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_lj *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S172>/Matrix Concatenate' incorporates:
       *  Constant: '<S172>/Constant'
       *  Constant: '<S172>/Constant1'
       *  Constant: '<S172>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_l;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_o;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_fh;
      break;

     case 2:
      /* Trigonometry: '<S173>/Trigonometric Function3' incorporates:
       *  Constant: '<S169>/Thrust_rot_z'
       *  Trigonometry: '<S173>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S173>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/Thrust_rot_z'
       *  Trigonometry: '<S173>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S173>/Matrix Concatenate' incorporates:
       *  Constant: '<S173>/Constant7'
       *  Gain: '<S173>/Gain1'
       *  Trigonometry: '<S173>/Trigonometric Function1'
       *  Trigonometry: '<S173>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_hx * rtb_Switch1;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_f2;
      rtb_MultiportSwitch2[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S173>/Matrix Concatenate' incorporates:
       *  Constant: '<S173>/Constant'
       *  Constant: '<S173>/Constant1'
       *  Constant: '<S173>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_nd;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_b;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_d;

      /* SignalConversion generated from: '<S173>/Matrix Concatenate' incorporates:
       *  Constant: '<S173>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_g;
      rtb_MultiportSwitch2[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S174>/Matrix Concatenate' incorporates:
       *  Constant: '<S174>/Constant10'
       *  Constant: '<S174>/Constant11'
       *  Constant: '<S174>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_l;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_l;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_l;

      /* Trigonometry: '<S174>/Trigonometric Function1' incorporates:
       *  Constant: '<S169>/Thrust_rot_z'
       *  Trigonometry: '<S174>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S174>/Trigonometric Function' incorporates:
       *  Constant: '<S169>/Thrust_rot_z'
       *  Trigonometry: '<S174>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S174>/Matrix Concatenate' incorporates:
       *  Constant: '<S174>/Constant7'
       *  Trigonometry: '<S174>/Trigonometric Function'
       *  Trigonometry: '<S174>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_c;

      /* SignalConversion generated from: '<S174>/Matrix Concatenate' incorporates:
       *  Constant: '<S174>/Constant8'
       *  Gain: '<S174>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Switch1;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_k *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_f;
      break;
    }

    /* End of MultiPortSwitch: '<S170>/Multiport Switch' */

    /* Product: '<S170>/3. Rotation' */
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        rtb_MultiportSwitch1_tmp = idx + 3 * i;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] = 0.0;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 * i] *
          rtb_MultiportSwitch1[idx];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 * i +
          1] * rtb_MultiportSwitch1[idx + 3];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 * i +
          2] * rtb_MultiportSwitch1[idx + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        rtb_MultiportSwitch1_tmp = idx + 3 * i;
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] = 0.0;
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i] *
          rtb_MultiportSwitch[idx];
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 1] *
          rtb_MultiportSwitch[idx + 3];
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 2] *
          rtb_MultiportSwitch[idx + 6];
      }
    }

    /* End of Product: '<S170>/3. Rotation' */
  }

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/Constant'
   */
  if (rtb_Subtract_ay_tmp > GRM_HIL_P.Switch_Threshold_n) {
    rtb_VectorConcatenate_f_idx_0 = rtb_Subtract_ay_tmp;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant_Value_a0;
  }

  /* End of Switch: '<S168>/Switch' */

  /* Switch: '<S168>/Switch1' incorporates:
   *  Lookup_n-D: '<S168>/thrust_lookup'
   */
  if (rtb_VectorConcatenate_f_idx_0 > GRM_HIL_P.Switch1_Threshold_a) {
    /* Saturate: '<S168>/Saturation' */
    if (rtb_VectorConcatenate_f_idx_0 > GRM_HIL_P.Saturation_UpperSat) {
      rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_UpperSat;
    } else {
      if (rtb_VectorConcatenate_f_idx_0 < GRM_HIL_P.Saturation_LowerSat) {
        rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S168>/Saturation' */
    rtb_sincos_o2[0] = look1_binlcapw(rtb_VectorConcatenate_f_idx_0,
      GRM_HIL_P.thrust_lookup_bp01Data, GRM_HIL_P.thrust_lookup_tableData, 11U);
  } else {
    rtb_sincos_o2[0] = rtb_VectorConcatenate_f_idx_0;
  }

  /* End of Switch: '<S168>/Switch1' */

  /* Product: '<S169>/Product1' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Constant: '<S169>/uncert_thrust'
   */
  rtb_sincos_o2[0] *= GRM_HIL_P.uncert_thrust_Value;
  rtb_Switch1 = GRM_HIL_P.Constant1_Value_h * GRM_HIL_P.uncert_thrust_Value;

  /* Product: '<S169>/Product' incorporates:
   *  Product: '<S169>/Product1'
   */
  for (i = 0; i < 3; i++) {
    frac_0[i] = GRM_HIL_B.T12[i + 6] * rtb_Switch1 + (GRM_HIL_B.T12[i + 3] *
      rtb_Switch1 + GRM_HIL_B.T12[i] * rtb_sincos_o2[0]);
  }

  /* End of Product: '<S169>/Product' */

  /* Step: '<Root>/External Force' incorporates:
   *  Sin: '<Root>/Sine Wave'
   *  Step: '<Root>/External Moment'
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   */
  rtb_Subtract_ay_tmp = GRM_HIL_M->Timing.t[0];
  if (rtb_Subtract_ay_tmp < GRM_HIL_P.ExternalForce_Time) {
    rtb_Switch1 = GRM_HIL_P.ExternalForce_Y0;
  } else {
    rtb_Switch1 = GRM_HIL_P.ExternalForce_YFinal;
  }

  /* End of Step: '<Root>/External Force' */

  /* Step: '<Root>/Step' */
  if (rtb_Subtract_ay_tmp < GRM_HIL_P.Step_Time) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step_Y0;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step_YFinal;
  }

  /* Sum: '<S55>/Add' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  frac_2[0] = ((rtb_Product1_m[0] + frac_1[0]) + frac_0[0]) + (rtb_Switch1 +
    rtb_VectorConcatenate_f_idx_0) * GRM_HIL_P.Gain_Gain_pd;
  frac_2[1] = ((rtb_Product1_m[1] + frac_1[1]) + frac_0[1]) +
    GRM_HIL_P.Constant1_Value_fp;
  frac_2[2] = ((rtb_Product1_m[2] + frac_1[2]) + frac_0[2]) +
    GRM_HIL_P.Constant1_Value_fp;

  /* Switch: '<S188>/Switch' incorporates:
   *  Constant: '<S188>/Constant'
   *  Product: '<S188>/Product2'
   */
  if (GRM_HIL_P.Rigid_Body_EOM_6_DOF_flag_Kraft > GRM_HIL_P.Switch_Threshold_j)
  {
    frac_1[0] = frac_2[0];
    frac_1[1] = frac_2[1];
    frac_1[2] = frac_2[2];
  } else {
    /* Sum: '<S190>/Add7' */
    rtb_MathFunction2[8] = rtb_VectorConcatenate_f_idx_1;

    /* Sum: '<S190>/Add8' incorporates:
     *  Gain: '<S190>/Gain11'
     *  Gain: '<S190>/Gain12'
     */
    rtb_MathFunction2[7] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain11_Gain + rtb_TBG_tmp_4
      * GRM_HIL_P.Gain12_Gain;

    /* Sum: '<S190>/Add3' incorporates:
     *  Gain: '<S190>/Gain5'
     *  Gain: '<S190>/Gain6'
     */
    rtb_MathFunction2[6] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain5_Gain - rtb_TBG_tmp_2 *
      GRM_HIL_P.Gain6_Gain;

    /* Sum: '<S190>/Add2' incorporates:
     *  Gain: '<S190>/Gain3'
     *  Gain: '<S190>/Gain4'
     */
    rtb_MathFunction2[5] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain3_Gain - rtb_TBG_tmp_4 *
      GRM_HIL_P.Gain4_Gain;

    /* Sum: '<S190>/Add6' */
    rtb_MathFunction2[4] = rtb_TBG_tmp_5;

    /* Sum: '<S190>/Add4' incorporates:
     *  Gain: '<S190>/Gain7'
     *  Gain: '<S190>/Gain8'
     */
    rtb_MathFunction2[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain + rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain8_Gain;

    /* Sum: '<S190>/Add5' incorporates:
     *  Gain: '<S190>/Gain10'
     *  Gain: '<S190>/Gain9'
     */
    rtb_MathFunction2[2] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain9_Gain + rtb_TBG_tmp_2 *
      GRM_HIL_P.Gain10_Gain;

    /* Sum: '<S190>/Add1' incorporates:
     *  Gain: '<S190>/Gain1'
     *  Gain: '<S190>/Gain2'
     */
    rtb_MathFunction2[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_m - rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain2_Gain_i;

    /* Sum: '<S190>/Add' */
    rtb_MathFunction2[0] = rtb_VectorConcatenate_f_idx_2;

    /* Math: '<S188>/Math Function2' */
    for (i = 0; i < 3; i++) {
      rtb_TBG[3 * i] = rtb_MathFunction2[i];
      rtb_TBG[3 * i + 1] = rtb_MathFunction2[i + 3];
      rtb_TBG[3 * i + 2] = rtb_MathFunction2[i + 6];
    }

    memcpy(&rtb_MathFunction2[0], &rtb_TBG[0], 9U * sizeof(real_T));

    /* End of Math: '<S188>/Math Function2' */
    for (i = 0; i < 3; i++) {
      frac_1[i] = rtb_MathFunction2[i + 6] * frac_2[2] + (rtb_MathFunction2[i +
        3] * frac_2[1] + rtb_MathFunction2[i] * frac_2[0]);
    }
  }

  /* Saturate: '<S191>/Saturation' */
  if (rtb_Subtract_ju > GRM_HIL_P.Saturation_UpperSat_m) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_UpperSat_m;
  } else if (rtb_Subtract_ju < GRM_HIL_P.Saturation_LowerSat_a) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_LowerSat_a;
  } else {
    rtb_VectorConcatenate_f_idx_0 = rtb_Subtract_ju;
  }

  /* End of Saturate: '<S191>/Saturation' */

  /* Product: '<S191>/Divide' */
  frac_1[0] /= rtb_VectorConcatenate_f_idx_0;
  frac_1[1] /= rtb_VectorConcatenate_f_idx_0;

  /* SignalConversion generated from: '<S195>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[0] = frac_1[0];

  /* SignalConversion generated from: '<S195>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[1] = frac_1[1];

  /* SignalConversion generated from: '<S195>/Vector Concatenate' incorporates:
   *  Product: '<S191>/Divide'
   */
  GRM_HIL_B.VectorConcatenate_b[2] = frac_1[2] / rtb_VectorConcatenate_f_idx_0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S195>/Constant' */
    GRM_HIL_B.VectorConcatenate_b[3] = GRM_HIL_P.Constant_Value_eq;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Constant: '<S195>/Q_1'
   *  Constant: '<S195>/Q_2'
   *  Constant: '<S195>/Q_3'
   *  Constant: '<S195>/Q_4'
   *  Product: '<S195>/Product'
   *  Product: '<S195>/Product1'
   *  Product: '<S195>/Product2'
   *  Product: '<S195>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_i[i] * rtb_Product_idx_0 +
               GRM_HIL_P.Q_2_Value_n[i] * rtb_Product_idx_1) +
              GRM_HIL_P.Q_3_Value_m[i] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value_f[i] * rtb_Product_idx_3;
  }

  /* End of Sum: '<S195>/Add' */

  /* Product: '<S195>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Switch1 = tmp[i + 12] * GRM_HIL_B.VectorConcatenate_b[3] + (tmp[i + 8] *
      GRM_HIL_B.VectorConcatenate_b[2] + (tmp[i + 4] *
      GRM_HIL_B.VectorConcatenate_b[1] + tmp[i] * GRM_HIL_B.VectorConcatenate_b
      [0]));
    rtb_d_qGE[i] = rtb_Switch1;
  }

  /* Sum: '<S195>/Add1' incorporates:
   *  Constant: '<S195>/Q~_1'
   *  Constant: '<S195>/Q~_2'
   *  Constant: '<S195>/Q~_3'
   *  Constant: '<S195>/Q~_4'
   *  Product: '<S195>/Product4'
   *  Product: '<S195>/Product5'
   *  Product: '<S195>/Product6'
   *  Product: '<S195>/Product7'
   */
  for (i = 0; i < 4; i++) {
    idx = i << 2;
    tmp[idx] = ((GRM_HIL_P.Q_1_Value[i] * rtb_Product_idx_0 +
                 GRM_HIL_P.Q_2_Value[i] * rtb_Product_idx_1) +
                GRM_HIL_P.Q_3_Value[i] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i] * rtb_Product_idx_3;
    tmp[idx + 1] = ((GRM_HIL_P.Q_1_Value[i + 4] * rtb_Product_idx_0 +
                     GRM_HIL_P.Q_2_Value[i + 4] * rtb_Product_idx_1) +
                    GRM_HIL_P.Q_3_Value[i + 4] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i + 4] * rtb_Product_idx_3;
    tmp[idx + 2] = ((GRM_HIL_P.Q_1_Value[i + 8] * rtb_Product_idx_0 +
                     GRM_HIL_P.Q_2_Value[i + 8] * rtb_Product_idx_1) +
                    GRM_HIL_P.Q_3_Value[i + 8] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i + 8] * rtb_Product_idx_3;
    tmp[idx + 3] = ((GRM_HIL_P.Q_1_Value[i + 12] * rtb_Product_idx_0 +
                     GRM_HIL_P.Q_2_Value[i + 12] * rtb_Product_idx_1) +
                    GRM_HIL_P.Q_3_Value[i + 12] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i + 12] * rtb_Product_idx_3;
  }

  /* End of Sum: '<S195>/Add1' */

  /* Product: '<S195>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Subtract_cl = tmp[i + 12] * rtb_d_qGE[3] + (tmp[i + 8] * rtb_d_qGE[2] +
      (tmp[i + 4] * rtb_d_qGE[1] + tmp[i] * rtb_d_qGE[0]));
    rtb_siB_h[i] = rtb_Subtract_cl;
  }

  /* Product: '<S181>/Product' incorporates:
   *  Math: '<S181>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac_1[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_siB_h[2] +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_siB_h[1] + rtb_MatrixMultiply_tmp[i] *
       rtb_siB_h[0]);
  }

  /* End of Product: '<S181>/Product' */

  /* Gain: '<S49>/Gain3' */
  GRM_HIL_B.ACC_x_B_mDs2 = GRM_HIL_P.Gain3_Gain_df * frac_1[0];

  /* Gain: '<S49>/Gain4' */
  GRM_HIL_B.ACC_y_B_mDs2 = GRM_HIL_P.Gain4_Gain_g * frac_1[1];

  /* Gain: '<S49>/Gain5' */
  GRM_HIL_B.ACC_z_B_mDs2 = GRM_HIL_P.Gain5_Gain_n * frac_1[2];

  /* Gain: '<S49>/Gain6' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.w_x_K_IB_B_radDs = GRM_HIL_P.Gain6_Gain_a *
    GRM_HIL_X.integration_eom_CSTATE[10];

  /* Gain: '<S49>/Gain7' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.w_y_K_IB_B_radDs = GRM_HIL_P.Gain7_Gain_ia *
    GRM_HIL_X.integration_eom_CSTATE[11];

  /* Gain: '<S49>/Gain8' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.w_z_K_IB_B_radDs = GRM_HIL_P.Gain8_Gain_l1 *
    GRM_HIL_X.integration_eom_CSTATE[12];

  /* Product: '<S60>/Product3' incorporates:
   *  MATLAB Function: '<S48>/MATLAB Function'
   *  Product: '<S60>/Product8'
   */
  rtb_Switch1 = -rtb_Product_idx_1 * -rtb_Product_idx_1;

  /* Gain: '<S49>/Gain9' incorporates:
   *  Constant: '<S60>/Constant'
   *  MATLAB Function: '<S48>/MATLAB Function'
   *  Product: '<S60>/Product'
   *  Product: '<S60>/Product1'
   *  Product: '<S60>/Product2'
   *  Product: '<S60>/Product3'
   *  Sum: '<S60>/Add'
   *  Sum: '<S60>/Add1'
   *  Trigonometry: '<S60>/Trigonometric Function'
   */
  GRM_HIL_B.ATT_Phi_rad = rt_atan2d_snf(-rtb_Product_idx_0 * rtb_Product_idx_3 +
    -rtb_Product_idx_1 * -rtb_Product_idx_2, (GRM_HIL_P.Constant_Value_pf -
    -rtb_Product_idx_0 * -rtb_Product_idx_0) - rtb_Switch1) *
    GRM_HIL_P.Gain9_Gain_f;

  /* Gain: '<S60>/Gain' incorporates:
   *  MATLAB Function: '<S48>/MATLAB Function'
   *  Product: '<S60>/Product4'
   *  Product: '<S60>/Product5'
   *  Sum: '<S60>/Add2'
   */
  u0 = (-rtb_Product_idx_1 * rtb_Product_idx_3 - -rtb_Product_idx_0 *
        -rtb_Product_idx_2) * GRM_HIL_P.Gain_Gain_m;

  /* Saturate: '<S60>/Saturation' */
  if (u0 > GRM_HIL_P.Saturation_UpperSat_g) {
    u0 = GRM_HIL_P.Saturation_UpperSat_g;
  } else {
    if (u0 < GRM_HIL_P.Saturation_LowerSat_ku) {
      u0 = GRM_HIL_P.Saturation_LowerSat_ku;
    }
  }

  /* End of Saturate: '<S60>/Saturation' */

  /* Trigonometry: '<S60>/Trigonometric Function1' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Gain: '<S49>/Gain10' incorporates:
   *  Trigonometry: '<S60>/Trigonometric Function1'
   */
  GRM_HIL_B.ATT_Theta_rad = GRM_HIL_P.Gain10_Gain_k * asin(u0);

  /* Gain: '<S49>/Gain11' incorporates:
   *  Constant: '<S60>/Constant1'
   *  MATLAB Function: '<S48>/MATLAB Function'
   *  Product: '<S60>/Product6'
   *  Product: '<S60>/Product7'
   *  Product: '<S60>/Product9'
   *  Sum: '<S60>/Add3'
   *  Sum: '<S60>/Add4'
   *  Trigonometry: '<S60>/Trigonometric Function2'
   */
  GRM_HIL_B.ATT_Psi_rad = rt_atan2d_snf(-rtb_Product_idx_0 * -rtb_Product_idx_1
    + -rtb_Product_idx_2 * rtb_Product_idx_3, (GRM_HIL_P.Constant1_Value_jl -
    rtb_Switch1) - -rtb_Product_idx_2 * -rtb_Product_idx_2) *
    GRM_HIL_P.Gain11_Gain_o;

  /* Gain: '<S65>/1//2' */
  frac_1[0] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Phi_rad;
  frac_1[1] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Theta_rad;
  frac_1[2] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Psi_rad;

  /* Trigonometry: '<S65>/sincos' */
  rtb_Product1_m[0] = cos(frac_1[0]);
  frac_1[0] = sin(frac_1[0]);
  rtb_Product1_m[1] = cos(frac_1[1]);
  frac_1[1] = sin(frac_1[1]);
  rtb_Product1_m[2] = cos(frac_1[2]);
  rtb_Switch1 = sin(frac_1[2]);

  /* Fcn: '<S65>/q0' incorporates:
   *  Fcn: '<S65>/q1'
   */
  rtb_VectorConcatenate_f_idx_1 = rtb_Product1_m[0] * rtb_Product1_m[1];
  rtb_VectorConcatenate_f_idx_2 = frac_1[0] * frac_1[1];
  GRM_HIL_B.q0 = rtb_VectorConcatenate_f_idx_1 * rtb_Product1_m[2] +
    rtb_VectorConcatenate_f_idx_2 * rtb_Switch1;

  /* Fcn: '<S65>/q1' */
  GRM_HIL_B.q1 = rtb_VectorConcatenate_f_idx_1 * rtb_Switch1 -
    rtb_VectorConcatenate_f_idx_2 * rtb_Product1_m[2];

  /* Fcn: '<S65>/q2' incorporates:
   *  Fcn: '<S65>/q3'
   */
  rtb_VectorConcatenate_f_idx_1 = frac_1[0] * rtb_Product1_m[1];
  rtb_VectorConcatenate_f_idx_2 = rtb_Product1_m[0] * frac_1[1];
  GRM_HIL_B.q2 = rtb_VectorConcatenate_f_idx_2 * rtb_Product1_m[2] +
    rtb_VectorConcatenate_f_idx_1 * rtb_Switch1;

  /* Fcn: '<S65>/q3' */
  GRM_HIL_B.q3 = rtb_VectorConcatenate_f_idx_1 * rtb_Product1_m[2] -
    rtb_VectorConcatenate_f_idx_2 * rtb_Switch1;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S49>/Gain12' incorporates:
     *  Constant: '<S48>/Constant5'
     */
    GRM_HIL_B.POS_lambda_WGS84_rad = GRM_HIL_P.Gain12_Gain_b *
      GRM_HIL_P.Constant5_Value_k;

    /* Gain: '<S49>/Gain13' incorporates:
     *  Constant: '<S48>/Constant4'
     */
    GRM_HIL_B.POS_mue_WGS84_rad = GRM_HIL_P.Gain13_Gain *
      GRM_HIL_P.Constant4_Value_d;

    /* Gain: '<S49>/Gain18' incorporates:
     *  Constant: '<S48>/Constant7'
     */
    GRM_HIL_B.motor_state_perc = GRM_HIL_P.Gain18_Gain *
      GRM_HIL_P.Constant7_Value_l;
  }

  /* Gain: '<S49>/Gain14' */
  GRM_HIL_B.POS_h_WGS84_m = GRM_HIL_P.Gain14_Gain * GRM_HIL_B.Switch[2];

  /* Gain: '<S49>/Gain15' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.POS_x_NED_m = GRM_HIL_P.Gain15_Gain *
    GRM_HIL_X.integration_eom_CSTATE[0];

  /* Gain: '<S49>/Gain16' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.POS_y_NED_m = GRM_HIL_P.Gain16_Gain *
    GRM_HIL_X.integration_eom_CSTATE[1];

  /* Gain: '<S49>/Gain22' */
  GRM_HIL_B.mass_kg = GRM_HIL_P.Gain22_Gain * rtb_Subtract_ju;

  /* Outputs for Enabled SubSystem: '<S20>/send_to_pix' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S49>/Gain19' incorporates:
     *  Constant: '<S48>/Constant3'
     */
    GRM_HIL_B.VEL_u_Wind_A_E_O_mDs = GRM_HIL_P.Gain19_Gain *
      GRM_HIL_P.Constant3_Value_i;

    /* Gain: '<S49>/Gain20' incorporates:
     *  Constant: '<S48>/Constant2'
     */
    GRM_HIL_B.VEL_v_Wind_A_E_O_mDs = GRM_HIL_P.Gain20_Gain *
      GRM_HIL_P.Constant2_Value_pm;

    /* Gain: '<S49>/Gain21' incorporates:
     *  Constant: '<S48>/Constant1'
     */
    GRM_HIL_B.VEL_w_Wind_A_E_O_mDs = GRM_HIL_P.Gain21_Gain *
      GRM_HIL_P.Constant1_Value_ay;

    /* ToAsyncQueueBlock generated from: '<Root>/Simulation' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1193792460U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2860753568U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(207445950U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_x_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(313472459U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_y_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4099508758U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_z_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1767311687U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_x_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1035092242U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_y_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4093516575U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_z_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1525905411U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4066766668U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(516186281U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1283066072U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(713772202U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(128729584U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2383369565U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3133156319U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_lambda_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(733889209U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_mue_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3495300234U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_h_WGS84_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(46766108U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_x_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1604517648U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_y_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4196790192U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_z_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1809530598U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.motor_state_perc;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2848644258U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.mass_kg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3103882081U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3614700303U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(764006832U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(12040291U, time, pData, size);
      }
    }

    /* Outputs for Enabled SubSystem: '<S19>/Receive_ExternalMode' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    /* Constant: '<S19>/One' */
    if (GRM_HIL_P.One_Value_g > 0.0) {
      /* S-Function (sldrtpi): '<S21>/Packet Input' */
      /* S-Function Block: <S21>/Packet Input */
      {
        uint8_T indata[78U];
        int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 78U,
          &GRM_HIL_P.PacketInput_PacketID, (double*) indata, NULL);
        rtb_PacketInput_o3 = (status>>1) & 0x1;/* Data Error port */
        rtb_PacketInput_o2 = status & 0x1;/* Data Ready port */
        if (status & 0x1) {
          RTWin_ANYTYPEPTR indp;
          indp.p_uint8_T = indata;

          {
            int_T i1;
            uint8_T *y0 = &GRM_HIL_B.PacketInput_o1[0];
            for (i1=0; i1 < 78; i1++) {
              y0[i1] = *indp.p_uint8_T++;
            }
          }
        }
      }

      /* ToAsyncQueueBlock generated from: '<S21>/Packet Input' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.PacketInput_o1[0];
          int32_T size = 78*sizeof(uint8_T);
          sendToAsyncQueueTgtAppSvc(2010764621U, time, pData, size);
        }
      }

      /* Logic: '<S21>/AND' incorporates:
       *  Logic: '<S21>/NOT'
       */
      GRM_HIL_B.AND_h = (rtb_PacketInput_o2 && (!rtb_PacketInput_o3));
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Receive_ExternalMode_SubsysRanBC);
      }
    }

    /* End of Constant: '<S19>/One' */
    /* End of Outputs for SubSystem: '<S19>/Receive_ExternalMode' */

    /* Outputs for Enabled SubSystem: '<S19>/input_hold' incorporates:
     *  EnablePort: '<S22>/Enable'
     */
    if (GRM_HIL_B.AND_h) {
      /* MATLAB Function: '<S22>/ExtractMessage' */
      rtb_MultiportSwitch1_tmp = 64;
      memset(&packet_data[0], 0, sizeof(uint8_T) << 6U);
      packetfound = false;
      for (i = 0; i < 78; i++) {
        x[i] = (GRM_HIL_B.PacketInput_o1[i] == 5);
      }

      idx = 0;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 78)) {
        if (x[i]) {
          idx++;
          ii_data[idx - 1] = (int8_T)(i + 1);
          if (idx >= 78) {
            exitg1 = true;
          } else {
            i++;
          }
        } else {
          i++;
        }
      }

      if (1 > idx) {
        idx = 0;
      }

      start_size[0] = 1;
      start_size[1] = idx;
      loop_ub = idx - 1;
      for (i = 0; i <= loop_ub; i++) {
        start_data[i] = ii_data[i];
      }

      start_size_0[0] = 1;
      start_size_0[1] = idx;
      for (i = 0; i < idx; i++) {
        x[i] = ((start_data[i] + 2.0) - 1.0 > 78.0);
      }

      GRM_HIL_nullAssignment(start_data, start_size, x, start_size_0);
      tmp_size[0] = 1;
      tmp_size[1] = start_size[1];
      loop_ub = start_size[0] * start_size[1];
      for (i = 0; i < loop_ub; i++) {
        x[i] = (GRM_HIL_B.PacketInput_o1[(int32_T)((start_data[i] + 2.0) - 1.0)
                - 1] != 5);
      }

      GRM_HIL_nullAssignment(start_data, start_size, x, tmp_size);
      if (start_size[1] != 0) {
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i <= start_size[1] - 2)) {
          p = false;
          rtb_Switch1 = start_data[i + 1];
          if (rtb_Switch1 - start_data[i] == 66.0) {
            p = true;
          }

          if (p) {
            if (start_data[i] + 2.0 > rtb_Switch1 - 1.0) {
              idx = 0;
              i = 0;
            } else {
              idx = (int32_T)(start_data[i] + 2.0) - 1;
              i = (int_T)(start_data[i + 1] - 1.0);
            }

            rtb_MultiportSwitch1_tmp = i - idx;
            for (i = 0; i < rtb_MultiportSwitch1_tmp; i++) {
              packet_data[i] = GRM_HIL_B.PacketInput_o1[idx + i];
            }

            packetfound = true;
            exitg1 = true;
          } else {
            i++;
          }
        }
      }

      GRM_HIL_DW.SFunction_DIMS2[0] = 1;
      GRM_HIL_DW.SFunction_DIMS2[1] = rtb_MultiportSwitch1_tmp;
      if (0 <= rtb_MultiportSwitch1_tmp - 1) {
        memcpy(&rtb_message[0], &packet_data[0], rtb_MultiportSwitch1_tmp *
               sizeof(uint8_T));
      }

      /* MATLAB Function: '<S22>/ByteUnpack' */
      x_0[0] = rtb_message[0];
      x_0[1] = rtb_message[1];
      memcpy((void *)&PixHeartbeat, (void *)&x_0[0], (uint32_T)((size_t)1 *
              sizeof(uint16_T)));
      b_x[0] = rtb_message[4];
      b_x[1] = rtb_message[5];
      b_x[2] = rtb_message[6];
      b_x[3] = rtb_message[7];
      memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[8];
      b_x[1] = rtb_message[9];
      b_x[2] = rtb_message[10];
      b_x[3] = rtb_message[11];
      memcpy((void *)&ServoCMD2, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[12];
      b_x[1] = rtb_message[13];
      b_x[2] = rtb_message[14];
      b_x[3] = rtb_message[15];
      memcpy((void *)&ServoCMD3, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[16];
      b_x[1] = rtb_message[17];
      b_x[2] = rtb_message[18];
      b_x[3] = rtb_message[19];
      memcpy((void *)&ServoCMD4, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[20];
      b_x[1] = rtb_message[21];
      b_x[2] = rtb_message[22];
      b_x[3] = rtb_message[23];
      memcpy((void *)&SensorACC1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[24];
      b_x[1] = rtb_message[25];
      b_x[2] = rtb_message[26];
      b_x[3] = rtb_message[27];
      memcpy((void *)&SensorACC2, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[28];
      b_x[1] = rtb_message[29];
      b_x[2] = rtb_message[30];
      b_x[3] = rtb_message[31];
      memcpy((void *)&SensorACC3, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[32];
      b_x[1] = rtb_message[33];
      b_x[2] = rtb_message[34];
      b_x[3] = rtb_message[35];
      memcpy((void *)&SensorROT1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[36];
      b_x[1] = rtb_message[37];
      b_x[2] = rtb_message[38];
      b_x[3] = rtb_message[39];
      memcpy((void *)&SensorROT2, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[40];
      b_x[1] = rtb_message[41];
      b_x[2] = rtb_message[42];
      b_x[3] = rtb_message[43];
      memcpy((void *)&SensorROT3, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      b_x[0] = rtb_message[44];
      b_x[1] = rtb_message[45];
      b_x[2] = rtb_message[46];
      b_x[3] = rtb_message[47];
      memcpy((void *)&quaternion1, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[48];
      b_x[1] = rtb_message[49];
      b_x[2] = rtb_message[50];
      b_x[3] = rtb_message[51];
      memcpy((void *)&quaternion2, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[52];
      b_x[1] = rtb_message[53];
      b_x[2] = rtb_message[54];
      b_x[3] = rtb_message[55];
      memcpy((void *)&quaternion3, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[56];
      b_x[1] = rtb_message[57];
      b_x[2] = rtb_message[58];
      b_x[3] = rtb_message[59];
      memcpy((void *)&quaternion4, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[60];
      b_x[1] = rtb_message[61];
      b_x[2] = rtb_message[62];
      b_x[3] = rtb_message[63];
      memcpy((void *)&TestSignal, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));

      /* Outputs for Enabled SubSystem: '<S22>/hold' incorporates:
       *  EnablePort: '<S25>/Enable'
       */
      /* MATLAB Function: '<S22>/ExtractMessage' incorporates:
       *  Inport: '<S25>/SensorACC_update'
       *  Inport: '<S25>/SensorROT_update'
       *  Inport: '<S25>/ServoCMD_update'
       *  Inport: '<S25>/quaternion_update'
       *  MATLAB Function: '<S22>/ByteUnpack'
       */
      if (packetfound) {
        GRM_HIL_B.ServoCMD_update[0] = ServoCMD1;
        GRM_HIL_B.ServoCMD_update[1] = ServoCMD2;
        GRM_HIL_B.ServoCMD_update[2] = ServoCMD3;
        GRM_HIL_B.ServoCMD_update[3] = ServoCMD4;
        GRM_HIL_B.SensorACC_update[0] = SensorACC1;
        GRM_HIL_B.SensorACC_update[1] = SensorACC2;
        GRM_HIL_B.SensorACC_update[2] = SensorACC3;
        GRM_HIL_B.SensorROT_update[0] = SensorROT1;
        GRM_HIL_B.SensorROT_update[1] = SensorROT2;
        GRM_HIL_B.SensorROT_update[2] = SensorROT3;
        GRM_HIL_B.quaternion_update[0] = quaternion1;
        GRM_HIL_B.quaternion_update[1] = quaternion2;
        GRM_HIL_B.quaternion_update[2] = quaternion3;
        GRM_HIL_B.quaternion_update[3] = quaternion4;
        srUpdateBC(GRM_HIL_DW.hold_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S22>/hold' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.input_hold_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S19>/input_hold' */

    /* Product: '<S13>/Divide' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S16>/Constant1'
     *  Product: '<S14>/Divide'
     *  Product: '<S15>/Divide'
     *  Product: '<S16>/Divide'
     */
    rtb_Switch1 = GRM_HIL_P.Servo_PWM.Pulswidth_cmd_max_ms -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms;

    /* Product: '<S13>/Multiply' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  DataTypeConversion: '<S18>/Cast To Double2'
     *  Product: '<S13>/Divide'
     *  Sum: '<S13>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[0] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Switch1 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S13>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation = u0;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant2'
     *  DataTypeConversion: '<S18>/Cast To Double2'
     *  Product: '<S14>/Divide'
     *  Sum: '<S14>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[1] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Switch1 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S14>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_c = u0;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* Product: '<S15>/Multiply' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant2'
     *  DataTypeConversion: '<S18>/Cast To Double2'
     *  Product: '<S15>/Divide'
     *  Sum: '<S15>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[2] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Switch1 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S15>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_j = u0;
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* Product: '<S16>/Multiply' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant2'
     *  DataTypeConversion: '<S18>/Cast To Double2'
     *  Product: '<S16>/Divide'
     *  Sum: '<S16>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[3] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Switch1 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S16>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_a = u0;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator1' */
    rtb_Switch1 = (GRM_HIL_DW.clockTickCounter < GRM_HIL_P.PulseGenerator1_Duty)
      && (GRM_HIL_DW.clockTickCounter >= 0) ? GRM_HIL_P.PulseGenerator1_Amp :
      0.0;
    if (GRM_HIL_DW.clockTickCounter >= GRM_HIL_P.PulseGenerator1_Period - 1.0) {
      GRM_HIL_DW.clockTickCounter = 0;
    } else {
      GRM_HIL_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator1' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator' */
    rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_DW.clockTickCounter_d <
      GRM_HIL_P.PulseGenerator_Duty) && (GRM_HIL_DW.clockTickCounter_d >= 0) ?
      GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.pulse.ampl_rad :
      0.0;
    if (GRM_HIL_DW.clockTickCounter_d >= GRM_HIL_P.PulseGenerator_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_d = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_d++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator' */

    /* Switch: '<S17>/Switch1' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant2'
     *  Product: '<S17>/Multiply'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.pulse_cmd_flg >
        GRM_HIL_P.Switch1_Threshold_m) {
      /* Switch: '<S17>/Switch3' incorporates:
       *  Constant: '<S17>/Constant12'
       *  Constant: '<S17>/Constant6'
       *  Constant: '<S17>/Constant7'
       *  Sum: '<S17>/Add'
       */
      if (GRM_HIL_P.Constant6_Value_b) {
        rtb_Switch1 += GRM_HIL_P.Constant12_Value;
      } else {
        rtb_Switch1 = GRM_HIL_P.Constant7_Value;
      }

      /* End of Switch: '<S17>/Switch3' */
      rtb_Switch1 *= rtb_VectorConcatenate_f_idx_0;
    } else {
      rtb_Switch1 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.constant.phi_rad;
    }

    /* End of Switch: '<S17>/Switch1' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator4' */
    rtb_Subtract_cl = (GRM_HIL_DW.clockTickCounter_d3 <
                       GRM_HIL_P.PulseGenerator4_Duty) &&
      (GRM_HIL_DW.clockTickCounter_d3 >= 0) ? GRM_HIL_P.PulseGenerator4_Amp :
      0.0;
    if (GRM_HIL_DW.clockTickCounter_d3 >= GRM_HIL_P.PulseGenerator4_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_d3 = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_d3++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator4' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator3' */
    rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_DW.clockTickCounter_e <
      GRM_HIL_P.PulseGenerator3_Duty) && (GRM_HIL_DW.clockTickCounter_e >= 0) ?
      GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.pulse.ampl_mDs2 :
      0.0;
    if (GRM_HIL_DW.clockTickCounter_e >= GRM_HIL_P.PulseGenerator3_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_e = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_e++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator3' */

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant3'
     *  Product: '<S17>/Multiply1'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.pulse_cmd_flg >
        GRM_HIL_P.Switch_Threshold_p) {
      /* Switch: '<S17>/Switch4' incorporates:
       *  Constant: '<S17>/Constant13'
       *  Constant: '<S17>/Constant8'
       *  Constant: '<S17>/Constant9'
       *  Sum: '<S17>/Add1'
       */
      if (GRM_HIL_P.Constant8_Value_ej) {
        rtb_Subtract_cl += GRM_HIL_P.Constant13_Value;
      } else {
        rtb_Subtract_cl = GRM_HIL_P.Constant9_Value;
      }

      /* End of Switch: '<S17>/Switch4' */
      rtb_VectorConcatenate_f_idx_0 *= rtb_Subtract_cl;
    } else {
      rtb_VectorConcatenate_f_idx_0 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.constant.acc_z_mDs2;
    }

    /* End of Switch: '<S17>/Switch' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator7' */
    rtb_Cx = (GRM_HIL_DW.clockTickCounter_o < GRM_HIL_P.PulseGenerator7_Duty) &&
      (GRM_HIL_DW.clockTickCounter_o >= 0) ? GRM_HIL_P.PulseGenerator7_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter_o >= GRM_HIL_P.PulseGenerator7_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_o = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_o++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator7' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator6' */
    rtb_Subtract_cl = (GRM_HIL_DW.clockTickCounter_l <
                       GRM_HIL_P.PulseGenerator6_Duty) &&
      (GRM_HIL_DW.clockTickCounter_l >= 0) ?
      GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.pulse.ampl_mDs2 :
      0.0;
    if (GRM_HIL_DW.clockTickCounter_l >= GRM_HIL_P.PulseGenerator6_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_l = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_l++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator6' */

    /* Switch: '<S17>/Switch2' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Constant: '<S17>/Constant5'
     *  Product: '<S17>/Multiply2'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.pulse_cmd_flg >
        GRM_HIL_P.Switch2_Threshold) {
      /* Switch: '<S17>/Switch5' incorporates:
       *  Constant: '<S17>/Constant10'
       *  Constant: '<S17>/Constant11'
       *  Constant: '<S17>/Constant14'
       *  Sum: '<S17>/Add2'
       */
      if (GRM_HIL_P.Constant10_Value_ca) {
        rtb_Cx += GRM_HIL_P.Constant14_Value;
      } else {
        rtb_Cx = GRM_HIL_P.Constant11_Value;
      }

      /* End of Switch: '<S17>/Switch5' */
      rtb_Subtract_cl *= rtb_Cx;
    } else {
      rtb_Subtract_cl =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.constant.acc_y_mDs2;
    }

    /* End of Switch: '<S17>/Switch2' */

    /* Sum: '<S26>/Add' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant2'
     *  Constant: '<S7>/Constant10'
     *  Product: '<S26>/Divide'
     *  Product: '<S26>/Divide1'
     */
    rtb_Add_a = GRM_HIL_P.Constant1_Value_bx / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant10_Value_ly - GRM_HIL_P.Constant2_Value_d1;

    /* Memory: '<S26>/Memory' */
    rtb_Memory = GRM_HIL_DW.Memory_PreviousInput;

    /* MATLAB Function: '<S26>/Counter_with_external_limit' */
    GRM_HIL_Counter_with_external_limit(rtb_Add_a, rtb_Memory,
      &GRM_HIL_B.sf_Counter_with_external_limit);

    /* Logic: '<S26>/OR' incorporates:
     *  Constant: '<S7>/Constant9'
     *  RelationalOperator: '<S26>/Equal'
     */
    GRM_HIL_B.OR = ((rtb_Add_a == GRM_HIL_B.sf_Counter_with_external_limit.value)
                    || GRM_HIL_P.Constant9_Value_b);

    /* DataTypeConversion: '<S20>/Data Type Conversion3' */
    GRM_HIL_B.DataTypeConversion3 = (real32_T)rtb_Switch1;

    /* DataTypeConversion: '<S20>/Data Type Conversion1' */
    GRM_HIL_B.DataTypeConversion1 = (real32_T)rtb_Subtract_cl;

    /* DataTypeConversion: '<S20>/Data Type Conversion2' */
    GRM_HIL_B.DataTypeConversion2 = (real32_T)rtb_VectorConcatenate_f_idx_0;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      if (GRM_HIL_B.OR) {
        GRM_HIL_DW.send_to_pix_MODE = true;
      } else {
        if (GRM_HIL_DW.send_to_pix_MODE) {
          /* Disable for Enabled SubSystem: '<S28>/Send_ExternalMode' */
          GRM_HIL_DW.Send_ExternalMode_MODE = false;

          /* End of Disable for SubSystem: '<S28>/Send_ExternalMode' */

          /* Disable for Enabled SubSystem: '<S28>/no_CRC' */
          GRM_HIL_DW.no_CRC_MODE = false;

          /* End of Disable for SubSystem: '<S28>/no_CRC' */
          GRM_HIL_DW.send_to_pix_MODE = false;
        }
      }
    }
  }

  /* End of Outputs for SubSystem: '<S20>/send_to_pix' */

  /* MATLAB Function: '<S20>/CreateVector' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion10'
   *  DataTypeConversion: '<S20>/Data Type Conversion11'
   *  DataTypeConversion: '<S20>/Data Type Conversion12'
   *  DataTypeConversion: '<S20>/Data Type Conversion13'
   *  DataTypeConversion: '<S20>/Data Type Conversion5'
   *  DataTypeConversion: '<S20>/Data Type Conversion6'
   *  DataTypeConversion: '<S20>/Data Type Conversion7'
   *  DataTypeConversion: '<S20>/Data Type Conversion8'
   *  DataTypeConversion: '<S20>/Data Type Conversion9'
   */
  ServoCMD1 = (real32_T)GRM_HIL_B.ACC_x_B_mDs2;
  ServoCMD2 = (real32_T)GRM_HIL_B.ACC_y_B_mDs2;
  ServoCMD3 = (real32_T)GRM_HIL_B.ACC_z_B_mDs2;
  ServoCMD4 = (real32_T)GRM_HIL_B.w_x_K_IB_B_radDs;
  SensorACC1 = (real32_T)GRM_HIL_B.w_y_K_IB_B_radDs;
  SensorACC2 = (real32_T)GRM_HIL_B.w_z_K_IB_B_radDs;
  SensorACC3 = (real32_T)GRM_HIL_B.ATT_Phi_rad;
  SensorROT1 = (real32_T)GRM_HIL_B.ATT_Theta_rad;
  SensorROT2 = (real32_T)GRM_HIL_B.ATT_Psi_rad;

  /* Outputs for Enabled SubSystem: '<S20>/send_to_pix' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  if (GRM_HIL_DW.send_to_pix_MODE) {
    /* Outputs for Enabled SubSystem: '<S28>/Send_ExternalMode' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
         GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
        (GRM_HIL_M)) {
      /* Constant: '<S28>/One' */
      GRM_HIL_DW.Send_ExternalMode_MODE = (GRM_HIL_P.One_Value > 0.0);
    }

    if (GRM_HIL_DW.Send_ExternalMode_MODE) {
      if (rtmIsMajorTimeStep(GRM_HIL_M) &&
          GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
        /* S-Function (sldrtpo): '<S31>/Packet Output' */
        /* S-Function Block: <S31>/Packet Output */
        {
          int status = RTBIO_DriverIO(0, STREAMOUTPUT, IOSTATUS, 128U, NULL,
            NULL, NULL);
          rtb_error = (status>>1) & 0x1;/* Data Error port */
        }
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Send_ExternalMode_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S28>/Send_ExternalMode' */

    /* MATLAB Function: '<S28>/MessageAssembly' incorporates:
     *  Constant: '<S18>/Constant6'
     *  Constant: '<S20>/Constant'
     *  Constant: '<S20>/Constant1'
     *  Constant: '<S20>/Constant2'
     *  Constant: '<S28>/Constant'
     *  MATLAB Function: '<S20>/CreateVector'
     */
    if (GRM_HIL_P.Constant_Value == 1.0) {
      memcpy((void *)&x_0[0], (void *)&GRM_HIL_P.Constant2_Value_l, (uint32_T)
             ((size_t)2 * sizeof(uint8_T)));
      memcpy((void *)&b_x[0], (void *)&GRM_HIL_B.DataTypeConversion3, (uint32_T)
             ((size_t)4 * sizeof(uint8_T)));
      memcpy((void *)&c_y[0], (void *)&GRM_HIL_B.DataTypeConversion1, (uint32_T)
             ((size_t)4 * sizeof(uint8_T)));
      memcpy((void *)&d_y[0], (void *)&GRM_HIL_B.DataTypeConversion2, (uint32_T)
             ((size_t)4 * sizeof(uint8_T)));
      memcpy((void *)&e_y[0], (void *)&ServoCMD1, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&f_y[0], (void *)&ServoCMD2, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&g_y[0], (void *)&ServoCMD3, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&h_y[0], (void *)&ServoCMD4, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&i_y[0], (void *)&SensorACC1, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&j_y[0], (void *)&SensorACC2, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&k_y[0], (void *)&SensorACC3, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&l_y[0], (void *)&SensorROT1, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&m_y[0], (void *)&SensorROT2, (uint32_T)((size_t)4 * sizeof
              (uint8_T)));
      memcpy((void *)&n_y[0], (void *)&GRM_HIL_P.Constant6_Value_c, (uint32_T)
             ((size_t)4 * sizeof(uint8_T)));
      package[0] = x_0[0];
      package[1] = x_0[1];
      package[2] = GRM_HIL_P.Constant_Value_jh;
      package[3] = GRM_HIL_P.Constant1_Value_ec;
      package[4] = b_x[0];
      package[8] = c_y[0];
      package[12] = d_y[0];
      package[16] = e_y[0];
      package[20] = f_y[0];
      package[24] = g_y[0];
      package[28] = h_y[0];
      package[32] = i_y[0];
      package[36] = j_y[0];
      package[40] = k_y[0];
      package[44] = l_y[0];
      package[48] = m_y[0];
      package[52] = n_y[0];
      package[5] = b_x[1];
      package[9] = c_y[1];
      package[13] = d_y[1];
      package[17] = e_y[1];
      package[21] = f_y[1];
      package[25] = g_y[1];
      package[29] = h_y[1];
      package[33] = i_y[1];
      package[37] = j_y[1];
      package[41] = k_y[1];
      package[45] = l_y[1];
      package[49] = m_y[1];
      package[53] = n_y[1];
      package[6] = b_x[2];
      package[10] = c_y[2];
      package[14] = d_y[2];
      package[18] = e_y[2];
      package[22] = f_y[2];
      package[26] = g_y[2];
      package[30] = h_y[2];
      package[34] = i_y[2];
      package[38] = j_y[2];
      package[42] = k_y[2];
      package[46] = l_y[2];
      package[50] = m_y[2];
      package[54] = n_y[2];
      package[7] = b_x[3];
      package[11] = c_y[3];
      package[15] = d_y[3];
      package[19] = e_y[3];
      package[23] = f_y[3];
      package[27] = g_y[3];
      package[31] = h_y[3];
      package[35] = i_y[3];
      package[39] = j_y[3];
      package[43] = k_y[3];
      package[47] = l_y[3];
      package[51] = m_y[3];
      package[55] = n_y[3];
      for (i = 0; i < 5; i++) {
        MessageToSend[i] = 0U;
      }

      MessageToSend[5] = 7U;
      MessageToSend[6] = 7U;
      MessageToSend[63] = 7U;
      MessageToSend[64] = 7U;
      for (i = 0; i < 56; i++) {
        MessageToSend[i + 7] = package[i];
        MessageToSend[i + 65] = package[i];
      }

      MessageToSend[121] = 7U;
      MessageToSend[122] = 7U;
      for (i = 0; i < 5; i++) {
        MessageToSend[i + 123] = 0U;
      }
    } else {
      memset(&MessageToSend[0], 0, sizeof(uint8_T) << 7U);
    }

    /* End of MATLAB Function: '<S28>/MessageAssembly' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Logic: '<S28>/NOT' incorporates:
       *  Constant: '<S7>/Constant12'
       */
      GRM_HIL_B.NOT = !GRM_HIL_P.Constant12_Value_e;

      /* Outputs for Enabled SubSystem: '<S28>/no_CRC' incorporates:
       *  EnablePort: '<S32>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        GRM_HIL_DW.no_CRC_MODE = GRM_HIL_B.NOT;
      }

      /* End of Outputs for SubSystem: '<S28>/no_CRC' */
    }

    /* Outputs for Enabled SubSystem: '<S28>/no_CRC' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    if (GRM_HIL_DW.no_CRC_MODE) {
      /* Inport: '<S32>/message' */
      memcpy(&GRM_HIL_B.message[0], &MessageToSend[0], sizeof(uint8_T) << 7U);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.no_CRC_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S28>/no_CRC' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.send_to_pix_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S20>/send_to_pix' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* ToAsyncQueueBlock generated from: '<S18>/Serial_Recieve_from_Pixhawk' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.SensorACC_update[0];
        int32_T size = 3*sizeof(real32_T);
        sendToAsyncQueueTgtAppSvc(2712243081U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<S18>/Serial_Recieve_from_Pixhawk' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.SensorROT_update[0];
        int32_T size = 3*sizeof(real32_T);
        sendToAsyncQueueTgtAppSvc(1211757120U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<S18>/Serial_Recieve_from_Pixhawk' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.quaternion_update[0];
        int32_T size = 4*sizeof(real32_T);
        sendToAsyncQueueTgtAppSvc(2191383419U, time, pData, size);
      }
    }

    /* UnitDelay: '<S239>/Output' */
    rtb_FixPtSum1 = GRM_HIL_DW.Output_DSTATE;

    /* DataTypeConversion: '<S238>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S239>/Output'
     */
    GRM_HIL_B.DataTypeConversion1_p = GRM_HIL_DW.Output_DSTATE;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
    /* Constant: '<S7>/Constant' */
    GRM_HIL_B.run = GRM_HIL_P.Constant_Value_gt;

    /* Constant: '<S7>/Constant2' */
    GRM_HIL_B.reset = GRM_HIL_P.Constant2_Value_f5;

    /* Constant: '<S7>/Constant7' */
    GRM_HIL_B.enable_gimbal_ctrl_flg = GRM_HIL_P.Constant7_Value_e;

    /* Constant: '<S7>/Constant8' */
    GRM_HIL_B.stop_gimbal_flg = GRM_HIL_P.Constant8_Value_lr;

    /* Constant: '<S34>/Constant' */
    GRM_HIL_B.Constant_i = GRM_HIL_P.Constant_Value_p3;
  }

  /* Gain: '<S46>/rad2deg' */
  GRM_HIL_B.Gimbal_Phi_Cmd_deg = GRM_HIL_P.rad2deg_Gain * GRM_HIL_B.ATT_Phi_rad;

  /* Gain: '<S46>/rad2deg1' */
  GRM_HIL_B.Gimbal_Theta_Cmd_deg = GRM_HIL_P.rad2deg1_Gain *
    GRM_HIL_B.ATT_Theta_rad;

  /* Gain: '<S46>/rad2deg2' */
  GRM_HIL_B.Gimbal_Psi_Cmd_deg = GRM_HIL_P.rad2deg2_Gain * GRM_HIL_B.ATT_Psi_rad;

  /* Outputs for Enabled SubSystem: '<S34>/Send_to_FTHWICC' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S35>/Constant3' */
    GRM_HIL_DW.Send_to_FTHWICC_MODE = GRM_HIL_P.Constant3_Value_k;
  }

  if (GRM_HIL_DW.Send_to_FTHWICC_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
      /* S-Function (sldrtpo): '<S37>/Send_to_FTHWICC' */
      /* S-Function Block: <S37>/Send_to_FTHWICC */

      /* no code required */
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* ToAsyncQueueBlock generated from: '<S37>/Gimbal_Phi_Cmd_deg' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.Gimbal_Phi_Cmd_deg;
          int32_T size = 1*sizeof(real_T);
          sendToAsyncQueueTgtAppSvc(2208301248U, time, pData, size);
        }
      }
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S34>/Send_to_FTHWICC' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S35>/Add' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     *  Constant: '<S35>/Constant2'
     *  Constant: '<S7>/Constant11'
     *  Product: '<S35>/Divide'
     *  Product: '<S35>/Divide1'
     */
    rtb_Add_d = GRM_HIL_P.Constant1_Value_e / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant11_Value_p3 - GRM_HIL_P.Constant2_Value_ik;

    /* Memory: '<S35>/Memory' */
    rtb_Memory_m = GRM_HIL_DW.Memory_PreviousInput_d;

    /* MATLAB Function: '<S35>/Counter_with_external_limit' */
    GRM_HIL_Counter_with_external_limit(rtb_Add_d, rtb_Memory_m,
      &GRM_HIL_B.sf_Counter_with_external_limit_j);

    /* Gain: '<S66>/Gain1' incorporates:
     *  Constant: '<S51>/Constant1'
     */
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Gain1_Gain_ps *
      GRM_HIL_P.Constant1_Value_lj;

    /* Gain: '<S67>/Gain1' incorporates:
     *  Constant: '<S51>/Constant2'
     */
    rtb_VectorConcatenate_f_idx_1 = GRM_HIL_P.Gain1_Gain_n3 *
      GRM_HIL_P.Constant2_Value_ff;

    /* Gain: '<S68>/Gain1' incorporates:
     *  Constant: '<S51>/Constant3'
     */
    rtb_VectorConcatenate_f_idx_2 = GRM_HIL_P.Gain1_Gain_g *
      GRM_HIL_P.Constant3_Value_i5;

    /* Product: '<S69>/Product' incorporates:
     *  Constant: '<S69>/Constant7'
     */
    for (i = 0; i < 4; i++) {
      GRM_HIL_B.siB_cmd[i] = 0.0;
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i] *
        rtb_VectorConcatenate_f_idx_0;
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i + 4] *
        rtb_VectorConcatenate_f_idx_1;
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i + 8] *
        rtb_VectorConcatenate_f_idx_2;
    }

    /* End of Product: '<S69>/Product' */

    /* Product: '<S214>/Product' incorporates:
     *  Constant: '<S214>/Constant'
     *  Constant: '<S214>/Constant6'
     */
    GRM_HIL_B.Product_a = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant6_Value_d5;
  }

  /* Sum: '<S51>/Sum' incorporates:
   *  SignalConversion generated from: '<S51>/Vector Concatenate'
   */
  rtb_Product4_n[0] = GRM_HIL_B.Fin_1_Pos_rad + GRM_HIL_B.siB_cmd[0];
  rtb_Product4_n[1] = GRM_HIL_B.Fin_2_Pos_rad + GRM_HIL_B.siB_cmd[1];
  rtb_Product4_n[2] = GRM_HIL_B.Fin_3_Pos_rad + GRM_HIL_B.siB_cmd[2];
  rtb_Product5 = GRM_HIL_B.Fin_4_Pos_rad + GRM_HIL_B.siB_cmd[3];

  /* Sum: '<S216>/Add' incorporates:
   *  Constant: '<S216>/Constant2'
   */
  rtb_Product6_e = GRM_HIL_P.Constant2_Value_p - rtb_Product6_e;

  /* Sum: '<S214>/Add4' incorporates:
   *  Constant: '<S214>/Constant3'
   *  Constant: '<S214>/Constant4'
   *  Product: '<S214>/Divide'
   *  Product: '<S214>/Product1'
   *  Sum: '<S214>/Add'
   */
  frac_2[0] = (rtb_Product6_e * GRM_HIL_P.Constant4_Value_p +
               GRM_HIL_B.Product_a) * (1.0 / rtb_Subtract_ju) +
    GRM_HIL_P.Constant3_Value_fn;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S214>/Product2' incorporates:
     *  Constant: '<S214>/Constant'
     *  Constant: '<S214>/Constant5'
     */
    GRM_HIL_B.Product2 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant5_Value_e;

    /* Product: '<S214>/Product4' incorporates:
     *  Constant: '<S214>/Constant'
     *  Constant: '<S214>/Constant8'
     */
    GRM_HIL_B.Product4 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant8_Value_l5;
  }

  /* Sum: '<S214>/Add3' incorporates:
   *  Constant: '<S214>/Constant1'
   *  Constant: '<S214>/Constant7'
   *  Product: '<S214>/Divide1'
   *  Product: '<S214>/Product3'
   *  Sum: '<S214>/Add1'
   */
  frac_2[1] = (rtb_Product6_e * GRM_HIL_P.Constant7_Value_jc +
               GRM_HIL_B.Product2) * (1.0 / rtb_Subtract_ju) +
    GRM_HIL_P.Constant1_Value_in;

  /* Sum: '<S214>/Add5' incorporates:
   *  Constant: '<S214>/Constant2'
   *  Constant: '<S214>/Constant9'
   *  Product: '<S214>/Divide2'
   *  Product: '<S214>/Product5'
   *  Sum: '<S214>/Add2'
   */
  frac_2[2] = (rtb_Product6_e * GRM_HIL_P.Constant9_Value_c + GRM_HIL_B.Product4)
    * (1.0 / rtb_Subtract_ju) + GRM_HIL_P.Constant2_Value_mg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S80>/Vector Concatenate' incorporates:
     *  Constant: '<S80>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[0] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S80>/Vector Concatenate' incorporates:
     *  Constant: '<S80>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[1] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S80>/Vector Concatenate' incorporates:
     *  Constant: '<S80>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[2] = GRM_HIL_P.Constant3_Value_m;

    /* Switch: '<S85>/Switch1' incorporates:
     *  Constant: '<S85>/Constant'
     *  Constant: '<S85>/Constant2'
     *  Constant: '<S86>/c_flat'
     *  Constant: '<S86>/c_rsma'
     *  Constant: '<S87>/Constant'
     *  Gain: '<S85>/Gain'
     *  Gain: '<S87>/Gain'
     *  Product: '<S87>/Product'
     *  Product: '<S87>/Product4'
     *  Product: '<S87>/Product5'
     *  Sqrt: '<S87>/Sqrt1'
     *  Sum: '<S87>/Subtract'
     *  Sum: '<S87>/Subtract1'
     *  Sum: '<S87>/Sum'
     *  Trigonometry: '<S87>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_ad > GRM_HIL_P.Switch1_Threshold_n) {
      GRM_HIL_B.hBE_0_h = GRM_HIL_P.Gain_Gain_f * GRM_HIL_P.Constant_Value_iee[2];
    } else {
      /* Sqrt: '<S88>/Sqrt' incorporates:
       *  Constant: '<S85>/Constant'
       *  Product: '<S88>/Product1'
       *  Product: '<S88>/Product2'
       *  Sqrt: '<S87>/Sqrt'
       *  Sum: '<S88>/Add'
       */
      rtb_Switch1 = sqrt(GRM_HIL_P.Constant_Value_iee[0] *
                         GRM_HIL_P.Constant_Value_iee[0] +
                         GRM_HIL_P.Constant_Value_iee[1] *
                         GRM_HIL_P.Constant_Value_iee[1]);

      /* Product: '<S88>/Product' incorporates:
       *  Constant: '<S86>/c_flat'
       *  Constant: '<S86>/c_rsma'
       *  Constant: '<S88>/Constant'
       *  Sum: '<S88>/Subtract'
       */
      rtb_Subtract_ju = (GRM_HIL_P.Constant_Value_f - GRM_HIL_P.c_flat_Value_f) *
        GRM_HIL_P.c_rsma_Value_b;

      /* Trigonometry: '<S88>/Trigonometric Function' incorporates:
       *  Constant: '<S85>/Constant'
       *  Constant: '<S86>/c_rsma'
       *  Product: '<S88>/Divide1'
       *  Product: '<S88>/Product6'
       *  Product: '<S88>/Product7'
       *  Sqrt: '<S88>/Sqrt'
       */
      rtb_Subtract_cl = atan(GRM_HIL_P.Constant_Value_iee[2] *
        GRM_HIL_P.c_rsma_Value_b / (rtb_Switch1 * rtb_Subtract_ju));

      /* Trigonometry: '<S88>/Trigonometric Function3' */
      rtb_Cx = cos(rtb_Subtract_cl);

      /* Product: '<S88>/Product9' */
      rtb_Product_l = rtb_Cx * rtb_Cx * rtb_Cx;

      /* Trigonometry: '<S88>/Trigonometric Function2' */
      rtb_Subtract_cl = sin(rtb_Subtract_cl);

      /* Product: '<S88>/Product5' */
      rtb_Cx = rtb_Subtract_ju * rtb_Subtract_ju;

      /* Product: '<S88>/Product10' incorporates:
       *  Constant: '<S86>/c_rsma'
       *  Product: '<S88>/Divide'
       *  Product: '<S88>/Product4'
       *  Product: '<S88>/Product8'
       *  Sum: '<S88>/Subtract2'
       */
      rtb_Subtract_ju = (GRM_HIL_P.c_rsma_Value_b * GRM_HIL_P.c_rsma_Value_b -
                         rtb_Cx) / rtb_Cx * rtb_Subtract_ju * (rtb_Subtract_cl *
        rtb_Subtract_cl * rtb_Subtract_cl);

      /* Sum: '<S88>/Add1' incorporates:
       *  Constant: '<S85>/Constant'
       */
      rtb_Subtract_ju += GRM_HIL_P.Constant_Value_iee[2];

      /* Product: '<S88>/Product3' incorporates:
       *  Constant: '<S86>/c_flat'
       *  Product: '<S87>/Product3'
       */
      rtb_Cx_tmp = GRM_HIL_P.c_flat_Value_f * GRM_HIL_P.c_flat_Value_f;

      /* Trigonometry: '<S88>/Trigonometric Function1' incorporates:
       *  Constant: '<S86>/c_flat'
       *  Constant: '<S86>/c_rsma'
       *  Gain: '<S88>/Gain'
       *  Product: '<S88>/Divide2'
       *  Product: '<S88>/Product11'
       *  Product: '<S88>/Product3'
       *  Sqrt: '<S88>/Sqrt'
       *  Sum: '<S88>/Subtract1'
       *  Sum: '<S88>/Subtract3'
       */
      rtb_Cx = atan(rtb_Subtract_ju / (rtb_Switch1 - (GRM_HIL_P.Gain_Gain_o *
        GRM_HIL_P.c_flat_Value_f - rtb_Cx_tmp) * GRM_HIL_P.c_rsma_Value_b *
        rtb_Product_l));

      /* Trigonometry: '<S87>/Trigonometric Function' */
      rtb_Subtract_cl = sin(rtb_Cx);
      GRM_HIL_B.hBE_0_h = rtb_Switch1 / cos(rtb_Cx) - GRM_HIL_P.c_rsma_Value_b /
        sqrt(GRM_HIL_P.Constant_Value_m - (GRM_HIL_P.Gain_Gain_a *
              GRM_HIL_P.c_flat_Value_f - rtb_Cx_tmp) * (rtb_Subtract_cl *
              rtb_Subtract_cl));
    }

    /* End of Switch: '<S85>/Switch1' */
  }

  /* Switch: '<S80>/Switch' incorporates:
   *  Constant: '<S73>/Constant1'
   *  Constant: '<S80>/Constant1'
   *  Constant: '<S89>/Constant'
   *  Product: '<S73>/Product1'
   *  Product: '<S89>/Product'
   *  Sum: '<S72>/Add3'
   *  Sum: '<S73>/Add'
   *  Sum: '<S80>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_p) - GRM_HIL_B.hBE_0_h >
      GRM_HIL_P.Switch_Threshold_j0) {
    /* Interpolation_n-D: '<S91>/Cn_delta_n_Interpolation' */
    frac_n[0] = rtb_lat;
    frac_n[1] = rtb_Sqrt_j;
    frac_n[2] = rtb_f_beB;
    bpIndex_n[0] = rtb_k_Mach;
    bpIndex_n[1] = rtb_k_alB;
    bpIndex_n[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_n, frac_n,
      GRM_HIL_P.Cn_delta_n_Interpolation_Table,
      GRM_HIL_P.Cn_delta_n_Interpolation_dimSize);

    /* Product: '<S72>/Product33' */
    rtb_Subtract_ju = rtb_Gain_n * rtb_Switch1;

    /* Interpolation_n-D: '<S91>/Cn_delta_m_Interpolation' */
    frac_o[0] = rtb_lat;
    frac_o[1] = rtb_Sqrt_j;
    frac_o[2] = rtb_f_beB;
    bpIndex_o[0] = rtb_k_Mach;
    bpIndex_o[1] = rtb_k_alB;
    bpIndex_o[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_o, frac_o,
      GRM_HIL_P.Cn_delta_m_Interpolation_Table,
      GRM_HIL_P.Cn_delta_m_Interpolation_dimSize);

    /* Product: '<S72>/Product32' */
    rtb_Subtract_cl = rtb_Gain_nk * rtb_Switch1;

    /* Interpolation_n-D: '<S91>/Cn_delta_l_Interpolation' */
    frac_p[0] = rtb_lat;
    frac_p[1] = rtb_Sqrt_j;
    frac_p[2] = rtb_f_beB;
    bpIndex_p[0] = rtb_k_Mach;
    bpIndex_p[1] = rtb_k_alB;
    bpIndex_p[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_p, frac_p,
      GRM_HIL_P.Cn_delta_l_Interpolation_Table,
      GRM_HIL_P.Cn_delta_l_Interpolation_dimSize);

    /* Product: '<S72>/Product31' */
    rtb_Cx = rtb_Gain_fl * rtb_Switch1;

    /* Interpolation_n-D: '<S91>/Cnr_Interpolation' */
    frac_q[0] = rtb_lat;
    frac_q[1] = rtb_Sqrt_j;
    frac_q[2] = rtb_f_beB;
    bpIndex_q[0] = rtb_k_Mach;
    bpIndex_q[1] = rtb_k_alB;
    bpIndex_q[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_q, frac_q,
      GRM_HIL_P.Cnr_Interpolation_Table, GRM_HIL_P.Cnr_Interpolation_dimSize);

    /* Product: '<S72>/Product36' */
    rtb_Product_l = rtb_Gain_af * rtb_Switch1;

    /* Interpolation_n-D: '<S91>/Cnq_Interpolation' */
    frac_r[0] = rtb_lat;
    frac_r[1] = rtb_Sqrt_j;
    frac_r[2] = rtb_f_beB;
    bpIndex_r[0] = rtb_k_Mach;
    bpIndex_r[1] = rtb_k_alB;
    bpIndex_r[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_r, frac_r,
      GRM_HIL_P.Cnq_Interpolation_Table, GRM_HIL_P.Cnq_Interpolation_dimSize);

    /* Product: '<S72>/Product35' */
    rtb_Product1 = rtb_Gain_lt * rtb_Switch1;

    /* Interpolation_n-D: '<S91>/Cnp_Interpolation' */
    frac_s[0] = rtb_lat;
    frac_s[1] = rtb_Sqrt_j;
    frac_s[2] = rtb_f_beB;
    bpIndex_s[0] = rtb_k_Mach;
    bpIndex_s[1] = rtb_k_alB;
    bpIndex_s[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_s, frac_s,
      GRM_HIL_P.Cnp_Interpolation_Table, GRM_HIL_P.Cnp_Interpolation_dimSize);

    /* Product: '<S72>/Product34' */
    rtb_Product3_hu = rtb_Gain_g * rtb_Switch1;

    /* Interpolation_n-D: '<S91>/Cn_Interpolation' */
    frac_t[0] = rtb_lat;
    frac_t[1] = rtb_Sqrt_j;
    frac_t[2] = rtb_f_beB;
    bpIndex_t[0] = rtb_k_Mach;
    bpIndex_t[1] = rtb_k_alB;
    bpIndex_t[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_t, frac_t,
      GRM_HIL_P.Cn_Interpolation_Table, GRM_HIL_P.Cn_Interpolation_dimSize);

    /* Sum: '<S72>/Add5' incorporates:
     *  Constant: '<S91>/Constant'
     *  Product: '<S91>/Product'
     */
    frac_1[2] = (((((GRM_HIL_P.Constant_Value_ml * rtb_Switch1 + rtb_Product3_hu)
                    + rtb_Product1) + rtb_Product_l) + rtb_Cx) + rtb_Subtract_cl)
      + rtb_Subtract_ju;

    /* Interpolation_n-D: '<S90>/Cm_delta_n_Interpolation' */
    frac_u[0] = rtb_lat;
    frac_u[1] = rtb_Sqrt_j;
    frac_u[2] = rtb_f_beB;
    bpIndex_u[0] = rtb_k_Mach;
    bpIndex_u[1] = rtb_k_alB;
    bpIndex_u[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_u, frac_u,
      GRM_HIL_P.Cm_delta_n_Interpolation_Table,
      GRM_HIL_P.Cm_delta_n_Interpolation_dimSize);

    /* Product: '<S72>/Product27' */
    rtb_Subtract_ju = rtb_Gain_n * rtb_Switch1;

    /* Interpolation_n-D: '<S90>/Cm_delta_m_Interpolation' */
    frac_v[0] = rtb_lat;
    frac_v[1] = rtb_Sqrt_j;
    frac_v[2] = rtb_f_beB;
    bpIndex_v[0] = rtb_k_Mach;
    bpIndex_v[1] = rtb_k_alB;
    bpIndex_v[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_v, frac_v,
      GRM_HIL_P.Cm_delta_m_Interpolation_Table,
      GRM_HIL_P.Cm_delta_m_Interpolation_dimSize);

    /* Product: '<S72>/Product26' */
    rtb_Subtract_cl = rtb_Gain_nk * rtb_Switch1;

    /* Interpolation_n-D: '<S90>/Cm_delta_l_Interpolation' */
    frac_w[0] = rtb_lat;
    frac_w[1] = rtb_Sqrt_j;
    frac_w[2] = rtb_f_beB;
    bpIndex_w[0] = rtb_k_Mach;
    bpIndex_w[1] = rtb_k_alB;
    bpIndex_w[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_w, frac_w,
      GRM_HIL_P.Cm_delta_l_Interpolation_Table,
      GRM_HIL_P.Cm_delta_l_Interpolation_dimSize);

    /* Product: '<S72>/Product25' */
    rtb_Cx = rtb_Gain_fl * rtb_Switch1;

    /* Interpolation_n-D: '<S90>/Cmr_Interpolation' */
    frac_x[0] = rtb_lat;
    frac_x[1] = rtb_Sqrt_j;
    frac_x[2] = rtb_f_beB;
    bpIndex_x[0] = rtb_k_Mach;
    bpIndex_x[1] = rtb_k_alB;
    bpIndex_x[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_x, frac_x,
      GRM_HIL_P.Cmr_Interpolation_Table, GRM_HIL_P.Cmr_Interpolation_dimSize);

    /* Product: '<S72>/Product30' */
    rtb_Product_l = rtb_Gain_af * rtb_Switch1;

    /* Interpolation_n-D: '<S90>/Cmq_Interpolation' */
    frac_y[0] = rtb_lat;
    frac_y[1] = rtb_Sqrt_j;
    frac_y[2] = rtb_f_beB;
    bpIndex_y[0] = rtb_k_Mach;
    bpIndex_y[1] = rtb_k_alB;
    bpIndex_y[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_y, frac_y,
      GRM_HIL_P.Cmq_Interpolation_Table, GRM_HIL_P.Cmq_Interpolation_dimSize);

    /* Product: '<S72>/Product29' */
    rtb_Product1 = rtb_Gain_lt * rtb_Switch1;

    /* Interpolation_n-D: '<S90>/Cmp_Interpolation' */
    frac_z[0] = rtb_lat;
    frac_z[1] = rtb_Sqrt_j;
    frac_z[2] = rtb_f_beB;
    bpIndex_z[0] = rtb_k_Mach;
    bpIndex_z[1] = rtb_k_alB;
    bpIndex_z[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_z, frac_z,
      GRM_HIL_P.Cmp_Interpolation_Table, GRM_HIL_P.Cmp_Interpolation_dimSize);

    /* Product: '<S72>/Product28' */
    rtb_Product3_hu = rtb_Gain_g * rtb_Switch1;

    /* Interpolation_n-D: '<S90>/Cm_Interpolation' */
    frac_10[0] = rtb_lat;
    frac_10[1] = rtb_Sqrt_j;
    frac_10[2] = rtb_f_beB;
    bpIndex_10[0] = rtb_k_Mach;
    bpIndex_10[1] = rtb_k_alB;
    bpIndex_10[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_10, frac_10,
      GRM_HIL_P.Cm_Interpolation_Table, GRM_HIL_P.Cm_Interpolation_dimSize);

    /* Sum: '<S72>/Add4' incorporates:
     *  Constant: '<S90>/Constant'
     *  Product: '<S90>/Product'
     */
    frac_1[1] = (((((GRM_HIL_P.Constant_Value_jm * rtb_Switch1 + rtb_Product3_hu)
                    + rtb_Product1) + rtb_Product_l) + rtb_Cx) + rtb_Subtract_cl)
      + rtb_Subtract_ju;

    /* Interpolation_n-D: '<S89>/Cl_delta_n_Interpolation' */
    frac_11[0] = rtb_lat;
    frac_11[1] = rtb_Sqrt_j;
    frac_11[2] = rtb_f_beB;
    bpIndex_11[0] = rtb_k_Mach;
    bpIndex_11[1] = rtb_k_alB;
    bpIndex_11[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_11, frac_11,
      GRM_HIL_P.Cl_delta_n_Interpolation_Table,
      GRM_HIL_P.Cl_delta_n_Interpolation_dimSize);

    /* Product: '<S72>/Product21' */
    rtb_Gain_n *= rtb_Switch1;

    /* Interpolation_n-D: '<S89>/Cl_delta_m_Interpolation' */
    frac_12[0] = rtb_lat;
    frac_12[1] = rtb_Sqrt_j;
    frac_12[2] = rtb_f_beB;
    bpIndex_12[0] = rtb_k_Mach;
    bpIndex_12[1] = rtb_k_alB;
    bpIndex_12[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_12, frac_12,
      GRM_HIL_P.Cl_delta_m_Interpolation_Table,
      GRM_HIL_P.Cl_delta_m_Interpolation_dimSize);

    /* Product: '<S72>/Product20' */
    rtb_Gain_nk *= rtb_Switch1;

    /* Interpolation_n-D: '<S89>/Cl_delta_l_Interpolation' */
    frac_13[0] = rtb_lat;
    frac_13[1] = rtb_Sqrt_j;
    frac_13[2] = rtb_f_beB;
    bpIndex_13[0] = rtb_k_Mach;
    bpIndex_13[1] = rtb_k_alB;
    bpIndex_13[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_13, frac_13,
      GRM_HIL_P.Cl_delta_l_Interpolation_Table,
      GRM_HIL_P.Cl_delta_l_Interpolation_dimSize);

    /* Product: '<S72>/Product19' */
    rtb_Gain_fl *= rtb_Switch1;

    /* Interpolation_n-D: '<S89>/Clr_Interpolation' */
    frac_14[0] = rtb_lat;
    frac_14[1] = rtb_Sqrt_j;
    frac_14[2] = rtb_f_beB;
    bpIndex_14[0] = rtb_k_Mach;
    bpIndex_14[1] = rtb_k_alB;
    bpIndex_14[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_14, frac_14,
      GRM_HIL_P.Clr_Interpolation_Table, GRM_HIL_P.Clr_Interpolation_dimSize);

    /* Product: '<S72>/Product24' */
    rtb_Gain_af *= rtb_Switch1;

    /* Interpolation_n-D: '<S89>/Clq_Interpolation' */
    frac_15[0] = rtb_lat;
    frac_15[1] = rtb_Sqrt_j;
    frac_15[2] = rtb_f_beB;
    bpIndex_15[0] = rtb_k_Mach;
    bpIndex_15[1] = rtb_k_alB;
    bpIndex_15[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_15, frac_15,
      GRM_HIL_P.Clq_Interpolation_Table, GRM_HIL_P.Clq_Interpolation_dimSize);

    /* Product: '<S72>/Product23' */
    rtb_Gain_lt *= rtb_Switch1;

    /* Interpolation_n-D: '<S89>/Clp_Interpolation' */
    frac_16[0] = rtb_lat;
    frac_16[1] = rtb_Sqrt_j;
    frac_16[2] = rtb_f_beB;
    bpIndex_16[0] = rtb_k_Mach;
    bpIndex_16[1] = rtb_k_alB;
    bpIndex_16[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_16, frac_16,
      GRM_HIL_P.Clp_Interpolation_Table, GRM_HIL_P.Clp_Interpolation_dimSize);

    /* Product: '<S72>/Product22' */
    rtb_Gain_g *= rtb_Switch1;

    /* Interpolation_n-D: '<S89>/Cl_Interpolation' */
    frac_17[0] = rtb_lat;
    frac_17[1] = rtb_Sqrt_j;
    frac_17[2] = rtb_f_beB;
    bpIndex_17[0] = rtb_k_Mach;
    bpIndex_17[1] = rtb_k_alB;
    bpIndex_17[2] = rtb_k_beB;
    rtb_Switch1 = intrp3d_l_pw(bpIndex_17, frac_17,
      GRM_HIL_P.Cl_Interpolation_Table, GRM_HIL_P.Cl_Interpolation_dimSize);

    /* Product: '<S73>/Product1' incorporates:
     *  Constant: '<S73>/Constant1'
     */
    rtb_VectorConcatenate_f_idx_1 = rtb_Step1 * frac_1[1] *
      GRM_HIL_P.Constant1_Value_bk;
    rtb_VectorConcatenate_f_idx_2 = rtb_Step1 * frac_1[2] *
      GRM_HIL_P.Constant1_Value_bk;

    /* Sum: '<S78>/Sum2' incorporates:
     *  Product: '<S78>/Product6'
     *  Product: '<S78>/Product7'
     */
    frac_1[2] = frac_2[0] * frac[1] - frac_2[1] * frac[0];

    /* Sum: '<S78>/Sum1' incorporates:
     *  Product: '<S78>/Product4'
     *  Product: '<S78>/Product5'
     */
    frac_1[1] = frac_2[2] * frac[0] - frac_2[0] * frac[2];

    /* Sum: '<S78>/Sum' incorporates:
     *  Product: '<S78>/Product2'
     *  Product: '<S78>/Product3'
     */
    frac_1[0] = frac_2[1] * frac[2] - frac_2[2] * frac[1];
    frac_1[0] += ((((((GRM_HIL_P.Constant_Value_e0 * rtb_Switch1 + rtb_Gain_g) +
                      rtb_Gain_lt) + rtb_Gain_af) + rtb_Gain_fl) + rtb_Gain_nk)
                  + rtb_Gain_n) * rtb_Step1 * GRM_HIL_P.Constant1_Value_bk;
    frac_1[1] += rtb_VectorConcatenate_f_idx_1;
    frac_1[2] += rtb_VectorConcatenate_f_idx_2;
  } else {
    frac_1[0] = GRM_HIL_B.VectorConcatenate_e[0];
    frac_1[1] = GRM_HIL_B.VectorConcatenate_e[1];
    frac_1[2] = GRM_HIL_B.VectorConcatenate_e[2];
  }

  /* End of Switch: '<S80>/Switch' */

  /* RelationalOperator: '<S112>/Compare' incorporates:
   *  Constant: '<S112>/Constant'
   */
  GRM_HIL_B.Compare_k = (rtb_Product6_n4 >= GRM_HIL_P.CompareToConstant_const_i);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S109>/Assertion' */
    utAssert(GRM_HIL_B.Compare_k);
  }

  /* Logic: '<S113>/AND' incorporates:
   *  Constant: '<S113>/Lower Limit'
   *  Constant: '<S113>/Upper Limit'
   *  RelationalOperator: '<S113>/Lower Test'
   *  RelationalOperator: '<S113>/Upper Test'
   */
  GRM_HIL_B.AND = ((GRM_HIL_P.IntervalTest_lowlimit <= GRM_HIL_B.Switch[0]) &&
                   (GRM_HIL_B.Switch[0] <= GRM_HIL_P.IntervalTest_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S109>/Assertion1' */
    utAssert(GRM_HIL_B.AND);
  }

  /* Logic: '<S114>/AND' incorporates:
   *  Constant: '<S114>/Lower Limit'
   *  Constant: '<S114>/Upper Limit'
   *  RelationalOperator: '<S114>/Lower Test'
   *  RelationalOperator: '<S114>/Upper Test'
   */
  GRM_HIL_B.AND_i = ((GRM_HIL_P.IntervalTest1_lowlimit <= GRM_HIL_B.Switch[1]) &&
                     (GRM_HIL_B.Switch[1] <= GRM_HIL_P.IntervalTest1_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S109>/Assertion2' */
    utAssert(GRM_HIL_B.AND_i);
  }

  /* Integrator: '<S125>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE,
                       (GRM_HIL_B.sat));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE = GRM_HIL_P.Rudder_d_siB_0;
    }
  }

  rtb_d_siB = GRM_HIL_X.Integrator_CSTATE;

  /* End of Integrator: '<S125>/Integrator' */

  /* MATLAB Function: '<S125>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB, rtb_d_siB, &GRM_HIL_B.sf_Limiting_Rate,
                        GRM_HIL_P.Rudder_d_siB_max, GRM_HIL_P.Rudder_d_siB_min,
                        GRM_HIL_P.Rudder_siB_max, GRM_HIL_P.Rudder_siB_min);

  /* Integrator: '<S126>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h,
                       (GRM_HIL_B.sat_c));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Rudder1_d_siB_0;
    }
  }

  rtb_d_siB_l = GRM_HIL_X.Integrator_CSTATE_e;

  /* End of Integrator: '<S126>/Integrator' */

  /* MATLAB Function: '<S126>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_d, rtb_d_siB_l, &GRM_HIL_B.sf_Limiting_Rate_o,
                        GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
                        GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Integrator: '<S127>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k,
                       (GRM_HIL_B.sat_a));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;
    }
  }

  rtb_d_siB_f = GRM_HIL_X.Integrator_CSTATE_f;

  /* End of Integrator: '<S127>/Integrator' */

  /* MATLAB Function: '<S127>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_i, rtb_d_siB_f, &GRM_HIL_B.sf_Limiting_Rate_g,
                        GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
                        GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Integrator: '<S128>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n,
                       (GRM_HIL_B.sat_o));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Rudder3_d_siB_0;
    }
  }

  rtb_d_siB_k = GRM_HIL_X.Integrator_CSTATE_g;

  /* End of Integrator: '<S128>/Integrator' */

  /* MATLAB Function: '<S128>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_o, rtb_d_siB_k, &GRM_HIL_B.sf_Limiting_Rate_d,
                        GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
                        GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Saturate: '<S125>/Saturation' */
  if (rtb_Product4_n[0] > GRM_HIL_P.Rudder_siB_max) {
    rtb_Switch1 = GRM_HIL_P.Rudder_siB_max;
  } else if (rtb_Product4_n[0] < GRM_HIL_P.Rudder_siB_min) {
    rtb_Switch1 = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_Switch1 = rtb_Product4_n[0];
  }

  /* End of Saturate: '<S125>/Saturation' */

  /* Sum: '<S125>/Add1' incorporates:
   *  Gain: '<S125>/Gain'
   *  Gain: '<S125>/Gain2'
   *  Integrator: '<S125>/Integrator1'
   *  Sum: '<S125>/Add'
   */
  rtb_dd_siB = (rtb_Switch1 - GRM_HIL_X.Integrator1_CSTATE) *
    GRM_HIL_P.Gain_Gain_oz - 2.0 * GRM_HIL_P.Rudder_dmp * GRM_HIL_P.Rudder_omega
    * rtb_d_siB;

  /* MATLAB Function: '<S125>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB, GRM_HIL_B.sf_Limiting_Rate.d_siB_l,
    rtb_dd_siB, &GRM_HIL_B.sf_Limiting_Acceleration, GRM_HIL_P.Rudder_d_siB_max,
    GRM_HIL_P.Rudder_d_siB_min, GRM_HIL_P.Rudder_dd_siB_max,
    GRM_HIL_P.Rudder_dd_siB_min, GRM_HIL_P.Rudder_siB_max,
    GRM_HIL_P.Rudder_siB_min);

  /* Saturate: '<S126>/Saturation' */
  if (rtb_Product4_n[1] > GRM_HIL_P.Rudder1_siB_max) {
    rtb_Switch1 = GRM_HIL_P.Rudder1_siB_max;
  } else if (rtb_Product4_n[1] < GRM_HIL_P.Rudder1_siB_min) {
    rtb_Switch1 = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_Switch1 = rtb_Product4_n[1];
  }

  /* End of Saturate: '<S126>/Saturation' */

  /* Sum: '<S126>/Add1' incorporates:
   *  Gain: '<S126>/Gain'
   *  Gain: '<S126>/Gain2'
   *  Integrator: '<S126>/Integrator1'
   *  Sum: '<S126>/Add'
   */
  rtb_dd_siB_c = (rtb_Switch1 - GRM_HIL_X.Integrator1_CSTATE_g) *
    GRM_HIL_P.Gain_Gain_a3 - 2.0 * GRM_HIL_P.Rudder1_dmp *
    GRM_HIL_P.Rudder1_omega * rtb_d_siB_l;

  /* MATLAB Function: '<S126>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_d, GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l,
    rtb_dd_siB_c, &GRM_HIL_B.sf_Limiting_Acceleration_i,
    GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
    GRM_HIL_P.Rudder1_dd_siB_max, GRM_HIL_P.Rudder1_dd_siB_min,
    GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Saturate: '<S127>/Saturation' */
  if (rtb_Product4_n[2] > GRM_HIL_P.Rudder2_siB_max) {
    rtb_Switch1 = GRM_HIL_P.Rudder2_siB_max;
  } else if (rtb_Product4_n[2] < GRM_HIL_P.Rudder2_siB_min) {
    rtb_Switch1 = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_Switch1 = rtb_Product4_n[2];
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* Sum: '<S127>/Add1' incorporates:
   *  Gain: '<S127>/Gain'
   *  Gain: '<S127>/Gain2'
   *  Integrator: '<S127>/Integrator1'
   *  Sum: '<S127>/Add'
   */
  rtb_dd_siB_o = (rtb_Switch1 - GRM_HIL_X.Integrator1_CSTATE_a) *
    GRM_HIL_P.Gain_Gain_hm - 2.0 * GRM_HIL_P.Rudder2_dmp *
    GRM_HIL_P.Rudder2_omega * rtb_d_siB_f;

  /* MATLAB Function: '<S127>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_i, GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l,
    rtb_dd_siB_o, &GRM_HIL_B.sf_Limiting_Acceleration_p,
    GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
    GRM_HIL_P.Rudder2_dd_siB_max, GRM_HIL_P.Rudder2_dd_siB_min,
    GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Saturate: '<S128>/Saturation' */
  if (rtb_Product5 > GRM_HIL_P.Rudder3_siB_max) {
    rtb_Product5 = GRM_HIL_P.Rudder3_siB_max;
  } else {
    if (rtb_Product5 < GRM_HIL_P.Rudder3_siB_min) {
      rtb_Product5 = GRM_HIL_P.Rudder3_siB_min;
    }
  }

  /* End of Saturate: '<S128>/Saturation' */

  /* Sum: '<S128>/Add1' incorporates:
   *  Gain: '<S128>/Gain'
   *  Gain: '<S128>/Gain2'
   *  Integrator: '<S128>/Integrator1'
   *  Sum: '<S128>/Add'
   */
  rtb_dd_siB_od = (rtb_Product5 - GRM_HIL_X.Integrator1_CSTATE_i) *
    GRM_HIL_P.Gain_Gain_d - 2.0 * GRM_HIL_P.Rudder3_dmp *
    GRM_HIL_P.Rudder3_omega * rtb_d_siB_k;

  /* MATLAB Function: '<S128>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_o, GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l,
    rtb_dd_siB_od, &GRM_HIL_B.sf_Limiting_Acceleration_h,
    GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
    GRM_HIL_P.Rudder3_dd_siB_max, GRM_HIL_P.Rudder3_dd_siB_min,
    GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Sum: '<S169>/Subtract' incorporates:
   *  Constant: '<S169>/pNPB'
   */
  rtb_Product1_m[0] = frac_2[0] - GRM_HIL_P.pNPB_Value[0];
  rtb_Product1_m[1] = frac_2[1] - GRM_HIL_P.pNPB_Value[1];
  rtb_Product1_m[2] = frac_2[2] - GRM_HIL_P.pNPB_Value[2];

  /* Step: '<Root>/External Moment' */
  if (rtb_Subtract_ay_tmp < GRM_HIL_P.ExternalMoment_Time) {
    rtb_Switch1 = GRM_HIL_P.ExternalMoment_Y0;
  } else {
    rtb_Switch1 = GRM_HIL_P.ExternalMoment_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (rtb_Subtract_ay_tmp < GRM_HIL_P.Step1_Time) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step1_Y0;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step1_YFinal;
  }

  /* Sum: '<S55>/Add1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  Product: '<S171>/Product2'
   *  Product: '<S171>/Product3'
   *  Product: '<S171>/Product4'
   *  Product: '<S171>/Product5'
   *  Product: '<S171>/Product6'
   *  Product: '<S171>/Product7'
   *  Sin: '<Root>/Sine Wave'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S171>/Sum'
   *  Sum: '<S171>/Sum1'
   *  Sum: '<S171>/Sum2'
   */
  frac_1[0] = ((rtb_Product1_m[1] * frac_0[2] - rtb_Product1_m[2] * frac_0[1]) +
               frac_1[0]) + (rtb_Switch1 + rtb_VectorConcatenate_f_idx_0) *
    GRM_HIL_P.Gain1_Gain_j2;
  frac_1[1] = ((rtb_Product1_m[2] * frac_0[0] - rtb_Product1_m[0] * frac_0[2]) +
               frac_1[1]) + GRM_HIL_P.Constant_Value_ko;
  frac_1[2] = (sin(GRM_HIL_P.SineWave_Freq * rtb_Subtract_ay_tmp +
                   GRM_HIL_P.SineWave_Phase) * GRM_HIL_P.SineWave_Amp +
               GRM_HIL_P.SineWave_Bias) + ((rtb_Product1_m[0] * frac_0[1] -
    rtb_Product1_m[1] * frac_0[0]) + frac_1[2]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S145>/Gain' */
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[0];
    rtb_VectorConcatenate_f_idx_1 = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[1];
    rtb_VectorConcatenate_f_idx_2 = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[2];

    /* Sum: '<S160>/Add' incorporates:
     *  Constant: '<S160>/Constant8'
     *  Constant: '<S160>/Q_1'
     *  Constant: '<S160>/Q_2'
     *  Constant: '<S160>/Q_3'
     *  Constant: '<S160>/Q_4'
     *  Product: '<S160>/Product1'
     *  Product: '<S160>/Product2'
     *  Product: '<S160>/Product3'
     *  Product: '<S160>/Product4'
     *  SignalConversion generated from: '<S160>/Vector Concatenate'
     */
    for (i = 0; i < 16; i++) {
      GRM_HIL_B.Add[i] = ((GRM_HIL_P.Q_1_Value_o[i] *
                           rtb_VectorConcatenate_f_idx_0 +
                           GRM_HIL_P.Q_2_Value_b[i] *
                           rtb_VectorConcatenate_f_idx_1) +
                          GRM_HIL_P.Q_3_Value_j[i] *
                          rtb_VectorConcatenate_f_idx_2) +
        GRM_HIL_P.Q_4_Value_d[i] * GRM_HIL_P.Constant8_Value_h;
    }

    /* End of Sum: '<S160>/Add' */
  }

  /* Gain: '<S162>/Gain1' incorporates:
   *  Integrator: '<S157>/integration_eom'
   */
  rtb_d_qGE[0] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[0];
  rtb_d_qGE[1] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[1];
  rtb_d_qGE[2] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[2];
  for (i = 0; i < 4; i++) {
    /* Product: '<S160>/Product5' incorporates:
     *  Integrator: '<S157>/integration_eom'
     */
    rtb_Subtract_ay_tmp = GRM_HIL_B.Add[i + 12] *
      GRM_HIL_X.integration_eom_CSTATE_b[3] + (GRM_HIL_B.Add[i + 8] * rtb_d_qGE
      [2] + (GRM_HIL_B.Add[i + 4] * rtb_d_qGE[1] + GRM_HIL_B.Add[i] * rtb_d_qGE
             [0]));

    /* Gain: '<S160>/Gain' */
    rtb_Product4_n[i] = GRM_HIL_P.Gain_Gain_e4 * rtb_Subtract_ay_tmp;
  }

  /* SignalConversion generated from: '<S163>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_m[3] = rtb_Product4_n[3];

  /* Gain: '<S163>/Gain1' */
  GRM_HIL_B.VectorConcatenate_m[0] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[0];
  GRM_HIL_B.VectorConcatenate_m[1] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[1];
  GRM_HIL_B.VectorConcatenate_m[2] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S159>/Vector Concatenate1' incorporates:
     *  Constant: '<S159>/Constant8'
     */
    GRM_HIL_B.wEGG[0] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S159>/Vector Concatenate1' incorporates:
     *  Constant: '<S159>/Constant8'
     */
    GRM_HIL_B.wEGG[1] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S159>/Vector Concatenate1' incorporates:
     *  Constant: '<S159>/Constant8'
     */
    GRM_HIL_B.wEGG[2] = GRM_HIL_P.Constant8_Value_ck;
  }

  /* Derivative: '<S159>/Derivative1' */
  if ((GRM_HIL_DW.TimeStampA >= rtb_Add) && (GRM_HIL_DW.TimeStampB >= rtb_Add))
  {
    rtb_lat = 0.0;
  } else {
    rtb_Sqrt_j = GRM_HIL_DW.TimeStampA;
    lastU = &GRM_HIL_DW.LastUAtTimeA;
    if (GRM_HIL_DW.TimeStampA < GRM_HIL_DW.TimeStampB) {
      if (GRM_HIL_DW.TimeStampB < rtb_Add) {
        rtb_Sqrt_j = GRM_HIL_DW.TimeStampB;
        lastU = &GRM_HIL_DW.LastUAtTimeB;
      }
    } else {
      if (GRM_HIL_DW.TimeStampA >= rtb_Add) {
        rtb_Sqrt_j = GRM_HIL_DW.TimeStampB;
        lastU = &GRM_HIL_DW.LastUAtTimeB;
      }
    }

    rtb_lat = (GRM_HIL_B.Switch[0] - *lastU) / (rtb_Add - rtb_Sqrt_j);
  }

  /* Derivative: '<S159>/Derivative' */
  if ((GRM_HIL_DW.TimeStampA_b >= rtb_Add) && (GRM_HIL_DW.TimeStampB_j >=
       rtb_Add)) {
    rtb_Add = 0.0;
  } else {
    rtb_Sqrt_j = GRM_HIL_DW.TimeStampA_b;
    lastU = &GRM_HIL_DW.LastUAtTimeA_b;
    if (GRM_HIL_DW.TimeStampA_b < GRM_HIL_DW.TimeStampB_j) {
      if (GRM_HIL_DW.TimeStampB_j < rtb_Add) {
        rtb_Sqrt_j = GRM_HIL_DW.TimeStampB_j;
        lastU = &GRM_HIL_DW.LastUAtTimeB_p;
      }
    } else {
      if (GRM_HIL_DW.TimeStampA_b >= rtb_Add) {
        rtb_Sqrt_j = GRM_HIL_DW.TimeStampB_j;
        lastU = &GRM_HIL_DW.LastUAtTimeB_p;
      }
    }

    rtb_Add = (GRM_HIL_B.Switch[1] - *lastU) / (rtb_Add - rtb_Sqrt_j);
  }

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/Constant9'
   */
  if (GRM_HIL_P.Constant9_Value_l > GRM_HIL_P.Switch_Threshold_m) {
    frac_0[0] = GRM_HIL_B.wEGG[0];
    frac_0[1] = GRM_HIL_B.wEGG[1];
    frac_0[2] = GRM_HIL_B.wEGG[2];
  } else {
    /* Gain: '<S159>/Gain2' incorporates:
     *  Product: '<S159>/Product'
     */
    frac_0[2] = rtb_Tmp * rtb_lat * GRM_HIL_P.Gain2_Gain;

    /* Gain: '<S159>/Gain1' */
    frac_0[1] = GRM_HIL_P.Gain1_Gain * rtb_Add;

    /* Product: '<S159>/Product1' */
    frac_0[0] = rtb_lat * rtb_siB_c5;
  }

  /* Gain: '<S145>/Gain1' */
  frac_0[0] *= GRM_HIL_P.Gain1_Gain_k;
  frac_0[1] *= GRM_HIL_P.Gain1_Gain_k;

  /* SignalConversion generated from: '<S164>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[0] = frac_0[0];

  /* SignalConversion generated from: '<S164>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[1] = frac_0[1];

  /* SignalConversion generated from: '<S164>/Vector Concatenate' incorporates:
   *  Gain: '<S145>/Gain1'
   */
  GRM_HIL_B.VectorConcatenate_a[2] = GRM_HIL_P.Gain1_Gain_k * frac_0[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S164>/Constant8' */
    GRM_HIL_B.VectorConcatenate_a[3] = GRM_HIL_P.Constant8_Value_p;
  }

  /* Gain: '<S166>/Gain1' incorporates:
   *  Integrator: '<S158>/integration_eom'
   */
  rtb_d_qBI[0] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[0];
  rtb_d_qBI[1] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[1];
  rtb_d_qBI[2] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[2];

  /* Sum: '<S164>/Add' incorporates:
   *  Constant: '<S164>/Q_1'
   *  Constant: '<S164>/Q_2'
   *  Constant: '<S164>/Q_3'
   *  Constant: '<S164>/Q_4'
   *  Product: '<S164>/Product1'
   *  Product: '<S164>/Product2'
   *  Product: '<S164>/Product3'
   *  Product: '<S164>/Product4'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_h[i] * GRM_HIL_B.VectorConcatenate_a[0] +
               GRM_HIL_P.Q_2_Value_g[i] * GRM_HIL_B.VectorConcatenate_a[1]) +
              GRM_HIL_P.Q_3_Value_oc[i] * GRM_HIL_B.VectorConcatenate_a[2]) +
      GRM_HIL_P.Q_4_Value_ea[i] * GRM_HIL_B.VectorConcatenate_a[3];
  }

  /* End of Sum: '<S164>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S164>/Product5' incorporates:
     *  Integrator: '<S158>/integration_eom'
     */
    rtb_Subtract_ay_tmp = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] +
      (tmp[i + 8] * rtb_d_qBI[2] + (tmp[i + 4] * rtb_d_qBI[1] + tmp[i] *
        rtb_d_qBI[0]));

    /* Gain: '<S164>/Gain' */
    rtb_d_qGE[i] = GRM_HIL_P.Gain_Gain_ba * rtb_Subtract_ay_tmp;
  }

  /* SignalConversion generated from: '<S167>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_k[3] = rtb_d_qGE[3];

  /* Gain: '<S167>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[0] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[0];

  /* SignalConversion generated from: '<S189>/Vector Concatenate' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.d_x[0] = GRM_HIL_X.integration_eom_CSTATE[3];

  /* SignalConversion generated from: '<S189>/Vector Concatenate' */
  GRM_HIL_B.d_x[3] = rtb_siB_h[0];

  /* Gain: '<S167>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[1] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[1];

  /* SignalConversion generated from: '<S189>/Vector Concatenate' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.d_x[1] = GRM_HIL_X.integration_eom_CSTATE[4];

  /* SignalConversion generated from: '<S189>/Vector Concatenate' */
  GRM_HIL_B.d_x[4] = rtb_siB_h[1];

  /* Gain: '<S167>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[2] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[2];

  /* SignalConversion generated from: '<S189>/Vector Concatenate' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.d_x[2] = GRM_HIL_X.integration_eom_CSTATE[5];

  /* SignalConversion generated from: '<S189>/Vector Concatenate' */
  GRM_HIL_B.d_x[5] = rtb_siB_h[2];

  /* SignalConversion generated from: '<S193>/Vector Concatenate' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[0] = GRM_HIL_X.integration_eom_CSTATE[10];

  /* SignalConversion generated from: '<S193>/Vector Concatenate' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[1] = GRM_HIL_X.integration_eom_CSTATE[11];

  /* SignalConversion generated from: '<S193>/Vector Concatenate' incorporates:
   *  Integrator: '<S189>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[2] = GRM_HIL_X.integration_eom_CSTATE[12];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S193>/Constant' */
    GRM_HIL_B.VectorConcatenate_p[3] = GRM_HIL_P.Constant_Value_lp;
  }

  /* Gain: '<S196>/Gain1' */
  rtb_siB_h[0] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_0;
  rtb_siB_h[1] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_1;
  rtb_siB_h[2] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_2;

  /* Sum: '<S193>/Add' incorporates:
   *  Constant: '<S193>/Q_1'
   *  Constant: '<S193>/Q_2'
   *  Constant: '<S193>/Q_3'
   *  Constant: '<S193>/Q_4'
   *  Product: '<S193>/Product2'
   *  Product: '<S193>/Product3'
   *  Product: '<S193>/Product4'
   *  Product: '<S193>/Product5'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_f[i] * GRM_HIL_B.VectorConcatenate_p[0] +
               GRM_HIL_P.Q_2_Value_n1[i] * GRM_HIL_B.VectorConcatenate_p[1]) +
              GRM_HIL_P.Q_3_Value_a[i] * GRM_HIL_B.VectorConcatenate_p[2]) +
      GRM_HIL_P.Q_4_Value_b[i] * GRM_HIL_B.VectorConcatenate_p[3];
  }

  /* End of Sum: '<S193>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S193>/Product6' incorporates:
     *  SignalConversion generated from: '<S196>/Vector Concatenate'
     */
    rtb_Subtract_ay_tmp = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_siB_h[2] + (tmp[i + 4] * rtb_siB_h[1] + tmp[i] * rtb_siB_h[0]));

    /* Gain: '<S193>/Gain' */
    rtb_d_qBI[i] = GRM_HIL_P.Gain_Gain_pq * rtb_Subtract_ay_tmp;
  }

  /* SignalConversion generated from: '<S197>/Vector Concatenate' */
  GRM_HIL_B.d_x[9] = rtb_d_qBI[3];

  /* Gain: '<S197>/Gain1' */
  GRM_HIL_B.d_x[6] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[0];

  /* Sum: '<S223>/Subtract' incorporates:
   *  Constant: '<S223>/Constant17'
   */
  frac_0[0] = frac_2[0] - GRM_HIL_P.Constant17_Value[0];

  /* Gain: '<S197>/Gain1' */
  GRM_HIL_B.d_x[7] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[1];

  /* Sum: '<S223>/Subtract' incorporates:
   *  Constant: '<S223>/Constant17'
   */
  frac_0[1] = frac_2[1] - GRM_HIL_P.Constant17_Value[1];

  /* Gain: '<S197>/Gain1' */
  GRM_HIL_B.d_x[8] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[2];

  /* Sum: '<S223>/Subtract' incorporates:
   *  Constant: '<S223>/Constant17'
   */
  frac_0[2] = frac_2[2] - GRM_HIL_P.Constant17_Value[2];

  /* Product: '<S235>/Product1' */
  rtb_Product6_n4 = frac_0[1] * frac_0[1];

  /* Product: '<S235>/Product2' */
  rtb_Add = frac_0[2] * frac_0[2];

  /* Sum: '<S235>/Add' */
  rtb_JBBB[0] = rtb_Product6_n4 + rtb_Add;

  /* Gain: '<S235>/Gain' incorporates:
   *  Product: '<S235>/Product3'
   */
  rtb_lat = frac_0[0] * frac_0[1] * GRM_HIL_P.Gain_Gain_ky;

  /* SignalConversion generated from: '<S235>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_lat;

  /* Gain: '<S235>/Gain1' incorporates:
   *  Product: '<S235>/Product4'
   */
  rtb_Sqrt_j = frac_0[0] * frac_0[2] * GRM_HIL_P.Gain1_Gain_oe;

  /* SignalConversion generated from: '<S235>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S235>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_lat;

  /* Product: '<S235>/Product5' */
  rtb_lat = frac_0[0] * frac_0[0];

  /* Sum: '<S235>/Add5' */
  rtb_JBBB[4] = rtb_Product6_n4 + rtb_lat;

  /* Gain: '<S235>/Gain3' incorporates:
   *  Product: '<S235>/Product6'
   */
  rtb_Product6_n4 = frac_0[1] * frac_0[2] * GRM_HIL_P.Gain3_Gain_c;

  /* SignalConversion generated from: '<S235>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_Product6_n4;

  /* SignalConversion generated from: '<S235>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S235>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_Product6_n4;

  /* Sum: '<S235>/Add4' */
  rtb_JBBB[8] = rtb_Add + rtb_lat;

  /* Sum: '<S218>/Add5' incorporates:
   *  Constant: '<S218>/Constant15'
   *  Constant: '<S223>/Constant'
   *  Product: '<S223>/Product'
   */
  for (i = 0; i < 9; i++) {
    rtb_TBG[i] = GRM_HIL_P.Constant_Value_bk * rtb_JBBB[i] +
      GRM_HIL_P.Constant15_Value[i];
  }

  /* End of Sum: '<S218>/Add5' */

  /* Sum: '<S224>/Subtract4' incorporates:
   *  Constant: '<S224>/Constant16'
   */
  frac_0[0] = frac_2[0] - GRM_HIL_P.Constant16_Value[0];
  frac_0[1] = frac_2[1] - GRM_HIL_P.Constant16_Value[1];
  frac_0[2] = frac_2[2] - GRM_HIL_P.Constant16_Value[2];

  /* Product: '<S236>/Product1' */
  rtb_Product6_n4 = frac_0[1] * frac_0[1];

  /* Product: '<S236>/Product2' */
  rtb_Add = frac_0[2] * frac_0[2];

  /* Sum: '<S236>/Add' */
  rtb_JBBB[0] = rtb_Product6_n4 + rtb_Add;

  /* Gain: '<S236>/Gain' incorporates:
   *  Product: '<S236>/Product3'
   */
  rtb_lat = frac_0[0] * frac_0[1] * GRM_HIL_P.Gain_Gain_lt;

  /* SignalConversion generated from: '<S236>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_lat;

  /* Gain: '<S236>/Gain1' incorporates:
   *  Product: '<S236>/Product4'
   */
  rtb_Sqrt_j = frac_0[0] * frac_0[2] * GRM_HIL_P.Gain1_Gain_iq;

  /* SignalConversion generated from: '<S236>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S236>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_lat;

  /* Product: '<S236>/Product5' */
  rtb_lat = frac_0[0] * frac_0[0];

  /* Sum: '<S236>/Add5' */
  rtb_JBBB[4] = rtb_Product6_n4 + rtb_lat;

  /* Gain: '<S236>/Gain3' incorporates:
   *  Product: '<S236>/Product6'
   */
  rtb_Product6_n4 = frac_0[1] * frac_0[2] * GRM_HIL_P.Gain3_Gain_fm;

  /* SignalConversion generated from: '<S236>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_Product6_n4;

  /* SignalConversion generated from: '<S236>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S236>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_Product6_n4;

  /* Sum: '<S236>/Add4' */
  rtb_JBBB[8] = rtb_Add + rtb_lat;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S225>/Multiport Switch2' incorporates:
     *  Constant: '<S225>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3_m) {
     case 1:
      /* Trigonometry: '<S232>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/thrust_rot_x'
       *  Trigonometry: '<S232>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S232>/Trigonometric Function3' incorporates:
       *  Constant: '<S221>/thrust_rot_x'
       *  Trigonometry: '<S232>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S232>/Matrix Concatenate' incorporates:
       *  Constant: '<S232>/Constant7'
       *  Trigonometry: '<S232>/Trigonometric Function1'
       *  Trigonometry: '<S232>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_p;
      rtb_MultiportSwitch2[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S232>/Matrix Concatenate' incorporates:
       *  Constant: '<S232>/Constant8'
       *  Gain: '<S232>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_cs;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_pk *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S232>/Matrix Concatenate' incorporates:
       *  Constant: '<S232>/Constant'
       *  Constant: '<S232>/Constant1'
       *  Constant: '<S232>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_i;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_f;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_bt;
      break;

     case 2:
      /* Trigonometry: '<S233>/Trigonometric Function3' incorporates:
       *  Constant: '<S221>/thrust_rot_x'
       *  Trigonometry: '<S233>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S233>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/thrust_rot_x'
       *  Trigonometry: '<S233>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S233>/Matrix Concatenate' incorporates:
       *  Constant: '<S233>/Constant7'
       *  Gain: '<S233>/Gain1'
       *  Trigonometry: '<S233>/Trigonometric Function1'
       *  Trigonometry: '<S233>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_n * rtb_Switch1;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_jt;
      rtb_MultiportSwitch2[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S233>/Matrix Concatenate' incorporates:
       *  Constant: '<S233>/Constant'
       *  Constant: '<S233>/Constant1'
       *  Constant: '<S233>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_p;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_c4;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_jp;

      /* SignalConversion generated from: '<S233>/Matrix Concatenate' incorporates:
       *  Constant: '<S233>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_c;
      rtb_MultiportSwitch2[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S234>/Matrix Concatenate' incorporates:
       *  Constant: '<S234>/Constant10'
       *  Constant: '<S234>/Constant11'
       *  Constant: '<S234>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_a;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_g;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_h;

      /* Trigonometry: '<S234>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/thrust_rot_x'
       *  Trigonometry: '<S234>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S234>/Trigonometric Function' incorporates:
       *  Constant: '<S221>/thrust_rot_x'
       *  Trigonometry: '<S234>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S234>/Matrix Concatenate' incorporates:
       *  Constant: '<S234>/Constant7'
       *  Trigonometry: '<S234>/Trigonometric Function'
       *  Trigonometry: '<S234>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_cr;

      /* SignalConversion generated from: '<S234>/Matrix Concatenate' incorporates:
       *  Constant: '<S234>/Constant8'
       *  Gain: '<S234>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Switch1;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_ow *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_os;
      break;
    }

    /* End of MultiPortSwitch: '<S225>/Multiport Switch2' */

    /* MultiPortSwitch: '<S225>/Multiport Switch1' incorporates:
     *  Constant: '<S225>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2_h) {
     case 1:
      /* Trigonometry: '<S229>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/thrust_rot_y'
       *  Trigonometry: '<S229>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S229>/Trigonometric Function3' incorporates:
       *  Constant: '<S221>/thrust_rot_y'
       *  Trigonometry: '<S229>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S229>/Matrix Concatenate' incorporates:
       *  Constant: '<S229>/Constant7'
       *  Trigonometry: '<S229>/Trigonometric Function1'
       *  Trigonometry: '<S229>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_n;
      rtb_MultiportSwitch1[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S229>/Matrix Concatenate' incorporates:
       *  Constant: '<S229>/Constant8'
       *  Gain: '<S229>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_n;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_ax *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S229>/Matrix Concatenate' incorporates:
       *  Constant: '<S229>/Constant'
       *  Constant: '<S229>/Constant1'
       *  Constant: '<S229>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_lx;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_nq;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_c;
      break;

     case 2:
      /* Trigonometry: '<S230>/Trigonometric Function3' incorporates:
       *  Constant: '<S221>/thrust_rot_y'
       *  Trigonometry: '<S230>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S230>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/thrust_rot_y'
       *  Trigonometry: '<S230>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S230>/Matrix Concatenate' incorporates:
       *  Constant: '<S230>/Constant7'
       *  Gain: '<S230>/Gain1'
       *  Trigonometry: '<S230>/Trigonometric Function1'
       *  Trigonometry: '<S230>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_j0 * rtb_Switch1;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_fv;
      rtb_MultiportSwitch1[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S230>/Matrix Concatenate' incorporates:
       *  Constant: '<S230>/Constant'
       *  Constant: '<S230>/Constant1'
       *  Constant: '<S230>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_c;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_a;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_js;

      /* SignalConversion generated from: '<S230>/Matrix Concatenate' incorporates:
       *  Constant: '<S230>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_dg;
      rtb_MultiportSwitch1[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S231>/Matrix Concatenate' incorporates:
       *  Constant: '<S231>/Constant10'
       *  Constant: '<S231>/Constant11'
       *  Constant: '<S231>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_bq;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_m;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_l2;

      /* Trigonometry: '<S231>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/thrust_rot_y'
       *  Trigonometry: '<S231>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S231>/Trigonometric Function' incorporates:
       *  Constant: '<S221>/thrust_rot_y'
       *  Trigonometry: '<S231>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S231>/Matrix Concatenate' incorporates:
       *  Constant: '<S231>/Constant7'
       *  Trigonometry: '<S231>/Trigonometric Function'
       *  Trigonometry: '<S231>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_ch;

      /* SignalConversion generated from: '<S231>/Matrix Concatenate' incorporates:
       *  Constant: '<S231>/Constant8'
       *  Gain: '<S231>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Switch1;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_n *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_ke;
      break;
    }

    /* End of MultiPortSwitch: '<S225>/Multiport Switch1' */

    /* MultiPortSwitch: '<S225>/Multiport Switch' incorporates:
     *  Constant: '<S225>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_md) {
     case 1:
      /* Trigonometry: '<S226>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/Thrust_rot_z'
       *  Trigonometry: '<S226>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S226>/Trigonometric Function3' incorporates:
       *  Constant: '<S221>/Thrust_rot_z'
       *  Trigonometry: '<S226>/Trigonometric Function'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S226>/Matrix Concatenate' incorporates:
       *  Constant: '<S226>/Constant7'
       *  Trigonometry: '<S226>/Trigonometric Function1'
       *  Trigonometry: '<S226>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_gi;
      rtb_MultiportSwitch[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[8] = rtb_Subtract_cl;

      /* SignalConversion generated from: '<S226>/Matrix Concatenate' incorporates:
       *  Constant: '<S226>/Constant8'
       *  Gain: '<S226>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_j;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_cy *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S226>/Matrix Concatenate' incorporates:
       *  Constant: '<S226>/Constant'
       *  Constant: '<S226>/Constant1'
       *  Constant: '<S226>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_of;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_g;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_a;
      break;

     case 2:
      /* Trigonometry: '<S227>/Trigonometric Function3' incorporates:
       *  Constant: '<S221>/Thrust_rot_z'
       *  Trigonometry: '<S227>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S227>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/Thrust_rot_z'
       *  Trigonometry: '<S227>/Trigonometric Function2'
       */
      rtb_Subtract_cl = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S227>/Matrix Concatenate' incorporates:
       *  Constant: '<S227>/Constant7'
       *  Gain: '<S227>/Gain1'
       *  Trigonometry: '<S227>/Trigonometric Function1'
       *  Trigonometry: '<S227>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_hv * rtb_Subtract_cl;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_je;
      rtb_MultiportSwitch[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S227>/Matrix Concatenate' incorporates:
       *  Constant: '<S227>/Constant'
       *  Constant: '<S227>/Constant1'
       *  Constant: '<S227>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_hw;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_k0;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_i;

      /* SignalConversion generated from: '<S227>/Matrix Concatenate' incorporates:
       *  Constant: '<S227>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_l;
      rtb_MultiportSwitch[2] = rtb_Subtract_cl;
      break;

     default:
      /* SignalConversion generated from: '<S228>/Matrix Concatenate' incorporates:
       *  Constant: '<S228>/Constant10'
       *  Constant: '<S228>/Constant11'
       *  Constant: '<S228>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_l5;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_c;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_h1;

      /* Trigonometry: '<S228>/Trigonometric Function1' incorporates:
       *  Constant: '<S221>/Thrust_rot_z'
       *  Trigonometry: '<S228>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S228>/Trigonometric Function' incorporates:
       *  Constant: '<S221>/Thrust_rot_z'
       *  Trigonometry: '<S228>/Trigonometric Function3'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S228>/Matrix Concatenate' incorporates:
       *  Constant: '<S228>/Constant7'
       *  Trigonometry: '<S228>/Trigonometric Function'
       *  Trigonometry: '<S228>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_p5;

      /* SignalConversion generated from: '<S228>/Matrix Concatenate' incorporates:
       *  Constant: '<S228>/Constant8'
       *  Gain: '<S228>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Subtract_cl;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_f0 *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gw;
      break;
    }

    /* End of MultiPortSwitch: '<S225>/Multiport Switch' */

    /* Product: '<S225>/3. Rotation' */
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        rtb_MultiportSwitch1_tmp = idx + 3 * i;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] = 0.0;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i] *
          rtb_MultiportSwitch1[idx];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i +
          1] * rtb_MultiportSwitch1[idx + 3];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i +
          2] * rtb_MultiportSwitch1[idx + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        rtb_MultiportSwitch1_tmp = idx + 3 * i;
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] = 0.0;
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i] *
          rtb_MultiportSwitch2[idx];
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 1] *
          rtb_MultiportSwitch2[idx + 3];
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 2] *
          rtb_MultiportSwitch2[idx + 6];
      }
    }

    /* End of Product: '<S225>/3. Rotation' */

    /* Sum: '<S220>/Subtract' incorporates:
     *  Constant: '<S220>/Constant16'
     *  Constant: '<S220>/Constant17'
     */
    for (i = 0; i < 9; i++) {
      GRM_HIL_B.Subtract_d[i] = GRM_HIL_P.Constant17_Value_j[i] -
        GRM_HIL_P.Constant16_Value_i[i];
    }

    /* End of Sum: '<S220>/Subtract' */

    /* Sum: '<S220>/Subtract4' incorporates:
     *  Constant: '<S220>/Constant18'
     *  Constant: '<S220>/Constant19'
     */
    GRM_HIL_B.Subtract4 = GRM_HIL_P.Constant19_Value -
      GRM_HIL_P.Constant18_Value;

    /* Math: '<S221>/Math Function' */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.MathFunction[3 * i] = GRM_HIL_B.T12_o[i];
      GRM_HIL_B.MathFunction[3 * i + 1] = GRM_HIL_B.T12_o[i + 3];
      GRM_HIL_B.MathFunction[3 * i + 2] = GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Math: '<S221>/Math Function' */
  }

  /* Sum: '<S220>/Subtract5' incorporates:
   *  Constant: '<S220>/Constant20'
   */
  rtb_Add = rtb_Product6_e - GRM_HIL_P.Constant20_Value;

  /* Sum: '<S220>/Subtract6' incorporates:
   *  Constant: '<S220>/Constant21'
   *  Product: '<S220>/Divide'
   */
  for (i = 0; i < 9; i++) {
    rtb_MatrixMultiply_tmp[i] = rtb_Add * GRM_HIL_B.Subtract_d[i] /
      GRM_HIL_B.Subtract4 + GRM_HIL_P.Constant21_Value[i];
  }

  /* End of Sum: '<S220>/Subtract6' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S221>/Matrix Multiply' */
    for (idx = 0; idx < 3; idx++) {
      rtb_MultiportSwitch1_tmp = i + 3 * idx;
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] = 0.0;
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] += rtb_MatrixMultiply_tmp[3 *
        idx] * GRM_HIL_B.T12_o[i];
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] += rtb_MatrixMultiply_tmp[3 *
        idx + 1] * GRM_HIL_B.T12_o[i + 3];
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] += rtb_MatrixMultiply_tmp[3 *
        idx + 2] * GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Product: '<S221>/Matrix Multiply' */

    /* Product: '<S191>/Product1' */
    rtb_Product1_m[i] = 0.0;
    for (idx = 0; idx < 3; idx++) {
      /* Sum: '<S222>/Add7' incorporates:
       *  Constant: '<S222>/Constant16'
       *  Product: '<S191>/Product1'
       *  Product: '<S221>/Matrix Multiply1'
       *  Product: '<S224>/Product'
       *  Sum: '<S218>/Add'
       *  Sum: '<S218>/Add4'
       */
      rtb_MultiportSwitch1_tmp = 3 * idx + i;
      rtb_JBBB[rtb_MultiportSwitch1_tmp] = ((((GRM_HIL_B.MathFunction[3 * idx +
        1] * rtb_MultiportSwitch[i + 3] + GRM_HIL_B.MathFunction[3 * idx] *
        rtb_MultiportSwitch[i]) + GRM_HIL_B.MathFunction[3 * idx + 2] *
        rtb_MultiportSwitch[i + 6]) + rtb_JBBB[rtb_MultiportSwitch1_tmp] *
        rtb_Product6_e) + rtb_TBG[rtb_MultiportSwitch1_tmp]) +
        GRM_HIL_P.Constant16_Value_c[rtb_MultiportSwitch1_tmp];

      /* Product: '<S191>/Product1' incorporates:
       *  Integrator: '<S189>/integration_eom'
       */
      rtb_Product1_m[i] += rtb_JBBB[rtb_MultiportSwitch1_tmp] *
        GRM_HIL_X.integration_eom_CSTATE[idx + 10];
    }
  }

  /* Sum: '<S194>/Sum' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S194>/Product2'
   *  Product: '<S194>/Product3'
   */
  rtb_sincos_o2[0] = GRM_HIL_X.integration_eom_CSTATE[11] * rtb_Product1_m[2] -
    GRM_HIL_X.integration_eom_CSTATE[12] * rtb_Product1_m[1];

  /* Sum: '<S194>/Sum1' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S194>/Product4'
   *  Product: '<S194>/Product5'
   */
  rtb_sincos_o2[1] = GRM_HIL_X.integration_eom_CSTATE[12] * rtb_Product1_m[0] -
    GRM_HIL_X.integration_eom_CSTATE[10] * rtb_Product1_m[2];

  /* Sum: '<S194>/Sum2' incorporates:
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S194>/Product6'
   *  Product: '<S194>/Product7'
   */
  rtb_sincos_o2[2] = GRM_HIL_X.integration_eom_CSTATE[10] * rtb_Product1_m[1] -
    GRM_HIL_X.integration_eom_CSTATE[11] * rtb_Product1_m[0];

  /* Sum: '<S191>/Subtract' incorporates:
   *  Constant: '<S182>/Constant9'
   *  Integrator: '<S189>/integration_eom'
   *  Product: '<S191>/Product'
   */
  for (i = 0; i < 3; i++) {
    frac_1[i] = (frac_1[i] - ((GRM_HIL_P.Constant9_Value_cv[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[11] + GRM_HIL_P.Constant9_Value_cv[i] *
      GRM_HIL_X.integration_eom_CSTATE[10]) + GRM_HIL_P.Constant9_Value_cv[i + 6]
      * GRM_HIL_X.integration_eom_CSTATE[12])) - rtb_sincos_o2[i];
  }

  /* End of Sum: '<S191>/Subtract' */

  /* Product: '<S191>/Divide1' */
  rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(rtb_JBBB, frac_1, &GRM_HIL_B.d_x[10]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S7>/Synchronize_to_realtime' incorporates:
     *  EnablePort: '<S237>/Enable'
     */
    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant9'
     *  Logic: '<S7>/NOT'
     */
    if (GRM_HIL_P.Constant1_Value_c3 && (!GRM_HIL_P.Constant9_Value_b) &&
        GRM_HIL_P.Constant3_Value_it) {
      /* S-Function (sldrtsync): '<S237>/Real-Time Synchronization' */
      /* S-Function Block: <S237>/Real-Time Synchronization */
      {
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
      }
    }

    /* End of Logic: '<S7>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S7>/Synchronize_to_realtime' */

    /* Sum: '<S240>/FixPt Sum1' incorporates:
     *  Constant: '<S240>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)rtb_FixPtSum1 +
      GRM_HIL_P.FixPtConstant_Value);

    /* Switch: '<S241>/FixPt Switch' incorporates:
     *  Constant: '<S241>/Constant'
     */
    if (rtb_FixPtSum1 > GRM_HIL_P.WrapToZero_Threshold) {
      GRM_HIL_B.FixPtSwitch = GRM_HIL_P.Constant_Value_lk;
    } else {
      GRM_HIL_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S241>/FixPt Switch' */
  }
}

/* Model update function */
void GRM_HIL_update(void)
{
  real_T *lastU;

  /* Update for Integrator: '<S189>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK = 0;

  /* Update for Integrator: '<S157>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_g = 0;

  /* Update for Integrator: '<S158>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_l = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S26>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput =
      GRM_HIL_B.sf_Counter_with_external_limit.value;
  }

  /* Update for Enabled SubSystem: '<S20>/send_to_pix' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  /* Update for Enabled SubSystem: '<S28>/Send_ExternalMode' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (GRM_HIL_DW.send_to_pix_MODE && GRM_HIL_DW.Send_ExternalMode_MODE &&
      (rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[3] == 0)) {
    /* Update for S-Function (sldrtpo): '<S31>/Packet Output' */

    /* S-Function Block: <S31>/Packet Output */
    {
      uint8_T outdata[128U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        int_T i1;
        const uint8_T *u0 = &GRM_HIL_B.message[0];
        for (i1=0; i1 < 128; i1++) {
          {
            uint8_T pktout = u0[i1];
            *outdp.p_uint8_T++ = pktout;
          }
        }
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 128U,
                     &GRM_HIL_P.PacketOutput_PacketID, (double*) outdata, NULL);
    }
  }

  /* End of Update for SubSystem: '<S28>/Send_ExternalMode' */
  /* End of Update for SubSystem: '<S20>/send_to_pix' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S239>/Output' */
    GRM_HIL_DW.Output_DSTATE = GRM_HIL_B.FixPtSwitch;
  }

  /* Update for Enabled SubSystem: '<S34>/Send_to_FTHWICC' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if (GRM_HIL_DW.Send_to_FTHWICC_MODE && (rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[2] == 0)) {
    /* Update for S-Function (sldrtpo): '<S37>/Send_to_FTHWICC' */

    /* S-Function Block: <S37>/Send_to_FTHWICC */
    {
      uint8_T outdata[52U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        boolean_T pktout = GRM_HIL_B.run;
        *outdp.p_boolean_T++ = pktout;
      }

      {
        boolean_T pktout = GRM_HIL_B.reset;
        *outdp.p_boolean_T++ = pktout;
      }

      {
        real_T pktout = GRM_HIL_B.enable_gimbal_ctrl_flg;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = GRM_HIL_B.stop_gimbal_flg;
        *outdp.p_real_T++ = pktout;
      }

      {
        uint16_T pktout = GRM_HIL_B.DataTypeConversion1_p;
        *outdp.p_uint16_T++ = pktout;
      }

      {
        real_T pktout = GRM_HIL_B.Gimbal_Phi_Cmd_deg;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = GRM_HIL_B.Gimbal_Theta_Cmd_deg;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = GRM_HIL_B.Gimbal_Psi_Cmd_deg;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = GRM_HIL_B.Constant_i;
        *outdp.p_real_T++ = pktout;
      }

      RTBIO_DriverIO(1, STREAMOUTPUT, IOWRITE, 52U,
                     &GRM_HIL_P.Send_to_FTHWICC_PacketID, (double*) outdata,
                     NULL);
    }
  }

  /* End of Update for SubSystem: '<S34>/Send_to_FTHWICC' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S35>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput_d =
      GRM_HIL_B.sf_Counter_with_external_limit_j.value;
  }

  /* Update for Derivative: '<S159>/Derivative1' */
  if (GRM_HIL_DW.TimeStampA == (rtInf)) {
    GRM_HIL_DW.TimeStampA = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeA;
  } else if (GRM_HIL_DW.TimeStampB == (rtInf)) {
    GRM_HIL_DW.TimeStampB = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeB;
  } else if (GRM_HIL_DW.TimeStampA < GRM_HIL_DW.TimeStampB) {
    GRM_HIL_DW.TimeStampA = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeA;
  } else {
    GRM_HIL_DW.TimeStampB = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeB;
  }

  *lastU = GRM_HIL_B.Switch[0];

  /* End of Update for Derivative: '<S159>/Derivative1' */

  /* Update for Derivative: '<S159>/Derivative' */
  if (GRM_HIL_DW.TimeStampA_b == (rtInf)) {
    GRM_HIL_DW.TimeStampA_b = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeA_b;
  } else if (GRM_HIL_DW.TimeStampB_j == (rtInf)) {
    GRM_HIL_DW.TimeStampB_j = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeB_p;
  } else if (GRM_HIL_DW.TimeStampA_b < GRM_HIL_DW.TimeStampB_j) {
    GRM_HIL_DW.TimeStampA_b = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeA_b;
  } else {
    GRM_HIL_DW.TimeStampB_j = GRM_HIL_M->Timing.t[0];
    lastU = &GRM_HIL_DW.LastUAtTimeB_p;
  }

  *lastU = GRM_HIL_B.Switch[1];

  /* End of Update for Derivative: '<S159>/Derivative' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&GRM_HIL_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++GRM_HIL_M->Timing.clockTick0)) {
    ++GRM_HIL_M->Timing.clockTickH0;
  }

  GRM_HIL_M->Timing.t[0] = rtsiGetSolverStopTime(&GRM_HIL_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++GRM_HIL_M->Timing.clockTick1)) {
      ++GRM_HIL_M->Timing.clockTickH1;
    }

    GRM_HIL_M->Timing.t[1] = GRM_HIL_M->Timing.clockTick1 *
      GRM_HIL_M->Timing.stepSize1 + GRM_HIL_M->Timing.clockTickH1 *
      GRM_HIL_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++GRM_HIL_M->Timing.clockTick2)) {
      ++GRM_HIL_M->Timing.clockTickH2;
    }

    GRM_HIL_M->Timing.t[2] = GRM_HIL_M->Timing.clockTick2 *
      GRM_HIL_M->Timing.stepSize2 + GRM_HIL_M->Timing.clockTickH2 *
      GRM_HIL_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++GRM_HIL_M->Timing.clockTick3)) {
      ++GRM_HIL_M->Timing.clockTickH3;
    }

    GRM_HIL_M->Timing.t[3] = GRM_HIL_M->Timing.clockTick3 *
      GRM_HIL_M->Timing.stepSize3 + GRM_HIL_M->Timing.clockTickH3 *
      GRM_HIL_M->Timing.stepSize3 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void GRM_HIL_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  real_T TransferFcn1_CSTATE_tmp;
  real_T TransferFcn1_CSTATE_tmp_0;
  XDot_GRM_HIL_T *_rtXdot;
  _rtXdot = ((XDot_GRM_HIL_T *) GRM_HIL_M->derivs);

  /* Derivatives for Integrator: '<S189>/integration_eom' */
  memcpy(&_rtXdot->integration_eom_CSTATE[0], &GRM_HIL_B.d_x[0], 13U * sizeof
         (real_T));

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] +=
    -GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[1] /
    GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[0] *
    GRM_HIL_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] +=
    -GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[2] /
    GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[0] *
    GRM_HIL_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += GRM_HIL_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += GRM_HIL_B.Saturation;

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn1' incorporates:
   *  TransferFcn: '<S11>/Transfer Fcn2'
   *  TransferFcn: '<S11>/Transfer Fcn3'
   */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  TransferFcn1_CSTATE_tmp = -GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[1] /
    GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[0];
  _rtXdot->TransferFcn1_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  TransferFcn1_CSTATE_tmp_0 = -GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[2] /
    GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[0];
  _rtXdot->TransferFcn1_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += GRM_HIL_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += GRM_HIL_B.Saturation_c;

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] += GRM_HIL_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] += GRM_HIL_B.Saturation_j;

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += GRM_HIL_B.Saturation_a;

  /* Derivatives for Integrator: '<S157>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[0] = GRM_HIL_B.VectorConcatenate_m[0];

  /* Derivatives for Integrator: '<S158>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[0] = GRM_HIL_B.VectorConcatenate_k[0];

  /* Derivatives for Integrator: '<S157>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[1] = GRM_HIL_B.VectorConcatenate_m[1];

  /* Derivatives for Integrator: '<S158>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[1] = GRM_HIL_B.VectorConcatenate_k[1];

  /* Derivatives for Integrator: '<S157>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[2] = GRM_HIL_B.VectorConcatenate_m[2];

  /* Derivatives for Integrator: '<S158>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[2] = GRM_HIL_B.VectorConcatenate_k[2];

  /* Derivatives for Integrator: '<S157>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[3] = GRM_HIL_B.VectorConcatenate_m[3];

  /* Derivatives for Integrator: '<S158>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[3] = GRM_HIL_B.VectorConcatenate_k[3];

  /* Derivatives for Integrator: '<S125>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE <= GRM_HIL_P.Rudder_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE >= GRM_HIL_P.Rudder_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l > 0.0))
      || (usat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE = GRM_HIL_B.sf_Limiting_Rate.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S125>/Integrator1' */

  /* Derivatives for Integrator: '<S126>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_g <= GRM_HIL_P.Rudder1_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_g >= GRM_HIL_P.Rudder1_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_g = GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_g = 0.0;
  }

  /* End of Derivatives for Integrator: '<S126>/Integrator1' */

  /* Derivatives for Integrator: '<S127>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_a <= GRM_HIL_P.Rudder2_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_a >= GRM_HIL_P.Rudder2_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_a = GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_a = 0.0;
  }

  /* End of Derivatives for Integrator: '<S127>/Integrator1' */

  /* Derivatives for Integrator: '<S128>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_i <= GRM_HIL_P.Rudder3_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_i >= GRM_HIL_P.Rudder3_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_i = GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_i = 0.0;
  }

  /* End of Derivatives for Integrator: '<S128>/Integrator1' */

  /* Derivatives for Integrator: '<S125>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.sf_Limiting_Acceleration.dd_siB_l;

  /* Derivatives for Integrator: '<S126>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = GRM_HIL_B.sf_Limiting_Acceleration_i.dd_siB_l;

  /* Derivatives for Integrator: '<S127>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = GRM_HIL_B.sf_Limiting_Acceleration_p.dd_siB_l;

  /* Derivatives for Integrator: '<S128>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = GRM_HIL_B.sf_Limiting_Acceleration_h.dd_siB_l;
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
  /* Start for Constant: '<S182>/Constant' */
  memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
         (real_T));

  /* Start for Constant: '<S157>/Constant8' */
  GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];

  /* Start for Constant: '<S158>/Constant8' */
  GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];

  /* Start for Constant: '<S157>/Constant8' */
  GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];

  /* Start for Constant: '<S158>/Constant8' */
  GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];

  /* Start for Constant: '<S157>/Constant8' */
  GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];

  /* Start for Constant: '<S158>/Constant8' */
  GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];

  /* Start for Constant: '<S157>/Constant8' */
  GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];

  /* Start for Constant: '<S158>/Constant8' */
  GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];

  /* Start for DiscretePulseGenerator: '<S17>/Pulse Generator1' */
  GRM_HIL_DW.clockTickCounter = -30000;

  /* Start for DiscretePulseGenerator: '<S17>/Pulse Generator' */
  GRM_HIL_DW.clockTickCounter_d = -10000;

  /* Start for DiscretePulseGenerator: '<S17>/Pulse Generator4' */
  GRM_HIL_DW.clockTickCounter_d3 = -40000;

  /* Start for DiscretePulseGenerator: '<S17>/Pulse Generator3' */
  GRM_HIL_DW.clockTickCounter_e = -10000;

  /* Start for DiscretePulseGenerator: '<S17>/Pulse Generator7' */
  GRM_HIL_DW.clockTickCounter_o = -40000;

  /* Start for DiscretePulseGenerator: '<S17>/Pulse Generator6' */
  GRM_HIL_DW.clockTickCounter_l = -10000;

  /* Start for Enabled SubSystem: '<S20>/send_to_pix' */
  GRM_HIL_DW.send_to_pix_MODE = false;

  /* Start for Enabled SubSystem: '<S28>/Send_ExternalMode' */
  GRM_HIL_DW.Send_ExternalMode_MODE = false;

  /* Start for S-Function (sldrtpo): '<S31>/Packet Output' */

  /* S-Function Block: <S31>/Packet Output */
  /* no initial value should be set */

  /* End of Start for SubSystem: '<S28>/Send_ExternalMode' */

  /* Start for Enabled SubSystem: '<S28>/no_CRC' */
  GRM_HIL_DW.no_CRC_MODE = false;

  /* End of Start for SubSystem: '<S28>/no_CRC' */
  /* End of Start for SubSystem: '<S20>/send_to_pix' */
  /* Start for Constant: '<S7>/Constant' */
  GRM_HIL_B.run = GRM_HIL_P.Constant_Value_gt;

  /* Start for Constant: '<S7>/Constant2' */
  GRM_HIL_B.reset = GRM_HIL_P.Constant2_Value_f5;

  /* Start for Constant: '<S7>/Constant7' */
  GRM_HIL_B.enable_gimbal_ctrl_flg = GRM_HIL_P.Constant7_Value_e;

  /* Start for Constant: '<S7>/Constant8' */
  GRM_HIL_B.stop_gimbal_flg = GRM_HIL_P.Constant8_Value_lr;

  /* Start for Constant: '<S34>/Constant' */
  GRM_HIL_B.Constant_i = GRM_HIL_P.Constant_Value_p3;

  /* Start for Enabled SubSystem: '<S34>/Send_to_FTHWICC' */
  GRM_HIL_DW.Send_to_FTHWICC_MODE = false;

  /* Start for S-Function (sldrtpo): '<S37>/Send_to_FTHWICC' */

  /* S-Function Block: <S37>/Send_to_FTHWICC */
  /* no initial value should be set */
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S189>/integration_eom' incorporates:
     *  Integrator: '<S157>/integration_eom'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.integration_eom_CSTATE[0] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[1] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[2] = -556.3;
      GRM_HIL_X.integration_eom_CSTATE[3] = 49.201;
      GRM_HIL_X.integration_eom_CSTATE[4] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[5] = -223.014;
      GRM_HIL_X.integration_eom_CSTATE[6] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[7] = -0.62723662203210129;
      GRM_HIL_X.integration_eom_CSTATE[8] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[9] = 0.77882874881565523;
      GRM_HIL_X.integration_eom_CSTATE[10] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[11] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE[12] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[0] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[1] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[2] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[3] = 1.0;
    }

    GRM_HIL_DW.integration_eom_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S189>/integration_eom' */

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn3' */
    GRM_HIL_X.TransferFcn3_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn3' */
    GRM_HIL_X.TransferFcn3_CSTATE[1] = 0.0;

    /* InitializeConditions for Integrator: '<S157>/integration_eom' */
    GRM_HIL_DW.integration_eom_IWORK_g = 1;

    /* InitializeConditions for Integrator: '<S158>/integration_eom' */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.integration_eom_CSTATE_f[0] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_f[1] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_f[2] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_f[3] = 1.0;
    }

    GRM_HIL_DW.integration_eom_IWORK_l = 1;

    /* End of InitializeConditions for Integrator: '<S158>/integration_eom' */

    /* InitializeConditions for Integrator: '<S125>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_P.Rudder_siB_0;

    /* InitializeConditions for Integrator: '<S126>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE_g = GRM_HIL_P.Rudder1_siB_0;

    /* InitializeConditions for Integrator: '<S127>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE_a = GRM_HIL_P.Rudder2_siB_0;

    /* InitializeConditions for Integrator: '<S128>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE_i = GRM_HIL_P.Rudder3_siB_0;

    /* InitializeConditions for Memory: '<S26>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S239>/Output' */
    GRM_HIL_DW.Output_DSTATE = GRM_HIL_P.Output_InitialCondition;

    /* InitializeConditions for Memory: '<S35>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput_d = GRM_HIL_P.Memory_InitialCondition_i;

    /* InitializeConditions for Integrator: '<S125>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE = GRM_HIL_P.Rudder_d_siB_0;

    /* InitializeConditions for Integrator: '<S126>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Rudder1_d_siB_0;

    /* InitializeConditions for Integrator: '<S127>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;

    /* InitializeConditions for Integrator: '<S128>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Rudder3_d_siB_0;

    /* InitializeConditions for Derivative: '<S159>/Derivative1' */
    GRM_HIL_DW.TimeStampA = (rtInf);
    GRM_HIL_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S159>/Derivative' */
    GRM_HIL_DW.TimeStampA_b = (rtInf);
    GRM_HIL_DW.TimeStampB_j = (rtInf);

    /* SystemInitialize for Enabled SubSystem: '<S34>/Construct_Bus' */
    /* SystemInitialize for Outport: '<S36>/Gimbal_Status' */
    GRM_HIL_B.Gimbal_operational_flg =
      GRM_HIL_P.Gimbal_Status_Y0.Gimbal_operational_flg;
    GRM_HIL_B.Gimbal_Ramp_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_Ramp_flg;
    GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_Limit_flg;
    GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_StopSim_flg;

    /* SystemInitialize for Outport: '<S36>/Gimbal_Pos' */
    GRM_HIL_B.ATT_Phi_rad_p = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Phi_rad;
    GRM_HIL_B.ATT_Theta_rad_e =
      GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Theta_rad;
    GRM_HIL_B.ATT_Psi_rad_e = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Psi_rad;
    GRM_HIL_B.q0_d = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_0;
    GRM_HIL_B.q1_o = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_1;
    GRM_HIL_B.q2_i = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_2;
    GRM_HIL_B.q3_o = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_3;

    /* SystemInitialize for Outport: '<S36>/Gimbal_Pos_Encoder' */
    GRM_HIL_B.Gimbal_yaw_sns =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_yaw_sns;
    GRM_HIL_B.Gimbal_pitch_sns =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_pitch_sns;
    GRM_HIL_B.Gimbal_roll_sns =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_roll_sns;
    GRM_HIL_B.Data_plus_p =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Data_plus;
    GRM_HIL_B.Data_minus_j =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Data_minus;
    GRM_HIL_B.Clock_plus_j =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Clock_plus;
    GRM_HIL_B.Clock_minus_d =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Clock_minus;
    GRM_HIL_B.Data_plus_pe =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Data_plus;
    GRM_HIL_B.Data_minus_jy =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Data_minus;
    GRM_HIL_B.Clock_plus_jb =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Clock_plus;
    GRM_HIL_B.Clock_minus_d1 =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Clock_minus;
    GRM_HIL_B.Data_plus_pek =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Data_plus;
    GRM_HIL_B.Data_minus_jye =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Data_minus;
    GRM_HIL_B.Clock_plus_jbf =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Clock_plus;
    GRM_HIL_B.Clock_minus_d1h =
      GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Clock_minus;

    /* End of SystemInitialize for SubSystem: '<S34>/Construct_Bus' */

    /* SystemInitialize for Enabled SubSystem: '<S19>/Receive_ExternalMode' */
    /* SystemInitialize for Outport: '<S21>/Status' */
    GRM_HIL_B.AND_h = GRM_HIL_P.Status_Y0;

    /* SystemInitialize for Outport: '<S21>/Data' */
    for (i = 0; i < 78; i++) {
      GRM_HIL_B.PacketInput_o1[i] = GRM_HIL_P.Data_Y0;
    }

    /* End of SystemInitialize for Outport: '<S21>/Data' */
    /* End of SystemInitialize for SubSystem: '<S19>/Receive_ExternalMode' */

    /* SystemInitialize for Enabled SubSystem: '<S19>/input_hold' */
    /* SystemInitialize for Enabled SubSystem: '<S22>/hold' */
    /* SystemInitialize for Outport: '<S25>/ServoCMD' */
    GRM_HIL_B.ServoCMD_update[0] = GRM_HIL_P.ServoCMD_Y0;
    GRM_HIL_B.ServoCMD_update[1] = GRM_HIL_P.ServoCMD_Y0;
    GRM_HIL_B.ServoCMD_update[2] = GRM_HIL_P.ServoCMD_Y0;
    GRM_HIL_B.ServoCMD_update[3] = GRM_HIL_P.ServoCMD_Y0;

    /* SystemInitialize for Outport: '<S25>/SensorACC' */
    GRM_HIL_B.SensorACC_update[0] = GRM_HIL_P.SensorACC_Y0;

    /* SystemInitialize for Outport: '<S25>/SensorROT' */
    GRM_HIL_B.SensorROT_update[0] = GRM_HIL_P.SensorROT_Y0;

    /* SystemInitialize for Outport: '<S25>/SensorACC' */
    GRM_HIL_B.SensorACC_update[1] = GRM_HIL_P.SensorACC_Y0;

    /* SystemInitialize for Outport: '<S25>/SensorROT' */
    GRM_HIL_B.SensorROT_update[1] = GRM_HIL_P.SensorROT_Y0;

    /* SystemInitialize for Outport: '<S25>/SensorACC' */
    GRM_HIL_B.SensorACC_update[2] = GRM_HIL_P.SensorACC_Y0;

    /* SystemInitialize for Outport: '<S25>/SensorROT' */
    GRM_HIL_B.SensorROT_update[2] = GRM_HIL_P.SensorROT_Y0;

    /* SystemInitialize for Outport: '<S25>/quaternion' */
    GRM_HIL_B.quaternion_update[0] = GRM_HIL_P.quaternion_Y0;
    GRM_HIL_B.quaternion_update[1] = GRM_HIL_P.quaternion_Y0;
    GRM_HIL_B.quaternion_update[2] = GRM_HIL_P.quaternion_Y0;
    GRM_HIL_B.quaternion_update[3] = GRM_HIL_P.quaternion_Y0;

    /* End of SystemInitialize for SubSystem: '<S22>/hold' */
    /* End of SystemInitialize for SubSystem: '<S19>/input_hold' */

    /* SystemInitialize for Enabled SubSystem: '<S20>/send_to_pix' */
    /* SystemInitialize for Enabled SubSystem: '<S28>/no_CRC' */
    /* SystemInitialize for Outport: '<S32>/message_pass' */
    for (i = 0; i < 128; i++) {
      GRM_HIL_B.message[i] = GRM_HIL_P.message_pass_Y0;
    }

    /* End of SystemInitialize for Outport: '<S32>/message_pass' */
    /* End of SystemInitialize for SubSystem: '<S28>/no_CRC' */
    /* End of SystemInitialize for SubSystem: '<S20>/send_to_pix' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      rtmSetFirstInitCond(GRM_HIL_M, 0);
    }
  }
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S20>/send_to_pix' */
  /* Terminate for Enabled SubSystem: '<S28>/Send_ExternalMode' */
  /* Terminate for S-Function (sldrtpo): '<S31>/Packet Output' */

  /* S-Function Block: <S31>/Packet Output */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S28>/Send_ExternalMode' */
  /* End of Terminate for SubSystem: '<S20>/send_to_pix' */

  /* Terminate for Enabled SubSystem: '<S34>/Send_to_FTHWICC' */
  /* Terminate for S-Function (sldrtpo): '<S37>/Send_to_FTHWICC' */

  /* S-Function Block: <S37>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S34>/Send_to_FTHWICC' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  GRM_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  GRM_HIL_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  GRM_HIL_initialize();
}

void MdlTerminate(void)
{
  GRM_HIL_terminate();
}

/* Registration function */
RT_MODEL_GRM_HIL_T *GRM_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  GRM_HIL_P.Saturation1_UpperSat = rtInf;
  GRM_HIL_P.Saturation_UpperSat_f = rtInf;
  GRM_HIL_P.Saturation_UpperSat_d = rtInf;
  GRM_HIL_P.Saturation_UpperSat_m = rtInf;

  /* initialize real-time model */
  (void) memset((void *)GRM_HIL_M, 0,
                sizeof(RT_MODEL_GRM_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&GRM_HIL_M->solverInfo, &GRM_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&GRM_HIL_M->solverInfo, &rtmGetTPtr(GRM_HIL_M));
    rtsiSetStepSizePtr(&GRM_HIL_M->solverInfo, &GRM_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&GRM_HIL_M->solverInfo, &GRM_HIL_M->derivs);
    rtsiSetContStatesPtr(&GRM_HIL_M->solverInfo, (real_T **)
                         &GRM_HIL_M->contStates);
    rtsiSetNumContStatesPtr(&GRM_HIL_M->solverInfo,
      &GRM_HIL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&GRM_HIL_M->solverInfo,
      &GRM_HIL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&GRM_HIL_M->solverInfo,
      &GRM_HIL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&GRM_HIL_M->solverInfo,
      &GRM_HIL_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&GRM_HIL_M->solverInfo, (&rtmGetErrorStatus(GRM_HIL_M)));
    rtsiSetRTModelPtr(&GRM_HIL_M->solverInfo, GRM_HIL_M);
  }

  rtsiSetSimTimeStep(&GRM_HIL_M->solverInfo, MAJOR_TIME_STEP);
  GRM_HIL_M->intgData.y = GRM_HIL_M->odeY;
  GRM_HIL_M->intgData.f[0] = GRM_HIL_M->odeF[0];
  GRM_HIL_M->intgData.f[1] = GRM_HIL_M->odeF[1];
  GRM_HIL_M->intgData.f[2] = GRM_HIL_M->odeF[2];
  GRM_HIL_M->contStates = ((real_T *) &GRM_HIL_X);
  rtsiSetSolverData(&GRM_HIL_M->solverInfo, (void *)&GRM_HIL_M->intgData);
  rtsiSetSolverName(&GRM_HIL_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = GRM_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    GRM_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GRM_HIL_M->Timing.sampleTimes = (&GRM_HIL_M->Timing.sampleTimesArray[0]);
    GRM_HIL_M->Timing.offsetTimes = (&GRM_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GRM_HIL_M->Timing.sampleTimes[0] = (0.0);
    GRM_HIL_M->Timing.sampleTimes[1] = (0.001);
    GRM_HIL_M->Timing.sampleTimes[2] = (0.002);
    GRM_HIL_M->Timing.sampleTimes[3] = (0.005);

    /* task offsets */
    GRM_HIL_M->Timing.offsetTimes[0] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[1] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[2] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(GRM_HIL_M, &GRM_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GRM_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    mdlSampleHits[3] = 1;
    GRM_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GRM_HIL_M, 60.0);
  GRM_HIL_M->Timing.stepSize0 = 0.001;
  GRM_HIL_M->Timing.stepSize1 = 0.001;
  GRM_HIL_M->Timing.stepSize2 = 0.002;
  GRM_HIL_M->Timing.stepSize3 = 0.005;
  rtmSetFirstInitCond(GRM_HIL_M, 1);

  /* External mode info */
  GRM_HIL_M->Sizes.checksums[0] = (2598223174U);
  GRM_HIL_M->Sizes.checksums[1] = (3665355216U);
  GRM_HIL_M->Sizes.checksums[2] = (2059130372U);
  GRM_HIL_M->Sizes.checksums[3] = (1554374079U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[78];
    GRM_HIL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)&GRM_HIL_DW.Receive_ExternalMode_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&GRM_HIL_DW.input_hold_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&GRM_HIL_DW.input_hold_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&GRM_HIL_DW.hold_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&GRM_HIL_DW.input_hold_SubsysRanBC;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = (sysRanDType *)&GRM_HIL_DW.send_to_pix_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&GRM_HIL_DW.Send_ExternalMode_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&GRM_HIL_DW.no_CRC_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&GRM_HIL_DW.send_to_pix_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)&GRM_HIL_DW.Construct_Bus_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = &rtAlwaysEnabled;
    systemRan[71] = &rtAlwaysEnabled;
    systemRan[72] = &rtAlwaysEnabled;
    systemRan[73] = &rtAlwaysEnabled;
    systemRan[74] = &rtAlwaysEnabled;
    systemRan[75] = &rtAlwaysEnabled;
    systemRan[76] = (sysRanDType *)
      &GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC;
    systemRan[77] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GRM_HIL_M->extModeInfo,
      &GRM_HIL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GRM_HIL_M->extModeInfo, GRM_HIL_M->Sizes.checksums);
    rteiSetTPtr(GRM_HIL_M->extModeInfo, rtmGetTPtr(GRM_HIL_M));
  }

  GRM_HIL_M->solverInfoPtr = (&GRM_HIL_M->solverInfo);
  GRM_HIL_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&GRM_HIL_M->solverInfo, 0.001);
  rtsiSetSolverMode(&GRM_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  GRM_HIL_M->blockIO = ((void *) &GRM_HIL_B);
  (void) memset(((void *) &GRM_HIL_B), 0,
                sizeof(B_GRM_HIL_T));

  /* parameters */
  GRM_HIL_M->defaultParam = ((real_T *)&GRM_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &GRM_HIL_X;
    GRM_HIL_M->contStates = (x);
    (void) memset((void *)&GRM_HIL_X, 0,
                  sizeof(X_GRM_HIL_T));
  }

  /* states (dwork) */
  GRM_HIL_M->dwork = ((void *) &GRM_HIL_DW);
  (void) memset((void *)&GRM_HIL_DW, 0,
                sizeof(DW_GRM_HIL_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GRM_HIL_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 89;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_M->Sizes.numContStates = (37);/* Number of continuous states */
  GRM_HIL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (4); /* Number of sample times */
  GRM_HIL_M->Sizes.numBlocks = (2013); /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (181); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (117838);/* Sum of parameter "widths" */
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

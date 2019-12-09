/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
<<<<<<< HEAD
 * Model version              : 1.67
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Dec  5 17:25:03 2019
=======
 * Model version              : 1.44
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Nov  8 10:21:14 2019
>>>>>>> origin/master
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
  0.0,
  36880.0,
  49.0,
<<<<<<< HEAD
  46.0,
  49.0,
=======
  57.0,
  50.0,
  46.0,
  49.0,
  54.0,
  56.0,
>>>>>>> origin/master
  46.0,
  49.0,
  46.0,
  49.0,
<<<<<<< HEAD
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
=======
  53.0,
  54.0,
>>>>>>> origin/master
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
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/UDP_Protocol", 36864U, 256, SLDRTBoardOptions0 },
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
static void rate_scheduler(void);
<<<<<<< HEAD
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
=======
>>>>>>> origin/master

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
  if ((GRM_HIL_M->Timing.TaskCounters.TID[3]) > 9) {/* Sample time: [0.01s, 0.0s] */
    GRM_HIL_M->Timing.TaskCounters.TID[3] = 0;
  }

  GRM_HIL_M->Timing.sampleHits[3] = (GRM_HIL_M->Timing.TaskCounters.TID[3] == 0);
  (GRM_HIL_M->Timing.TaskCounters.TID[4])++;
  if ((GRM_HIL_M->Timing.TaskCounters.TID[4]) > 19) {/* Sample time: [0.02s, 0.0s] */
    GRM_HIL_M->Timing.TaskCounters.TID[4] = 0;
  }

  GRM_HIL_M->Timing.sampleHits[4] = (GRM_HIL_M->Timing.TaskCounters.TID[4] == 0);
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
<<<<<<< HEAD
  int_T nXc = 39;
=======
  int_T nXc = 33;
>>>>>>> origin/master
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
<<<<<<< HEAD
 *    '<S19>/Counter_with_external_limit'
 *    '<S39>/Counter_with_external_limit'
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
 *    '<S129>/Limiting_Acceleration'
 *    '<S130>/Limiting_Acceleration'
 *    '<S131>/Limiting_Acceleration'
 *    '<S132>/Limiting_Acceleration'
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
 *    '<S129>/Limiting_Rate'
 *    '<S130>/Limiting_Rate'
 *    '<S131>/Limiting_Rate'
 *    '<S132>/Limiting_Rate'
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
=======
 *    '<S18>/Counter_with_external_limit'
 *    '<S38>/Counter_with_external_limit'
 */
void GRM_HIL_Counter_with_external_limit(real_T rtu_limit, real_T rtu_last_value,
  B_Counter_with_external_limit_GRM_HIL_T *localB)
{
  if (rtu_last_value < rtu_limit) {
    localB->value = rtu_last_value + 1.0;
  } else {
    localB->value = 0.0;
  }
>>>>>>> origin/master
}

/* Model output function */
void GRM_HIL_output(void)
{
  /* local block i/o variables */
<<<<<<< HEAD
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
  real_T rtb_Add_d;
  real_T rtb_Memory;
  boolean_T rtb_Receive_from_FTHWICC_o10;
  boolean_T rtb_Receive_from_FTHWICC_o11;
  ZCEventType zcEvent;
  real_T *lastU;
  real_T rtb_Subtract_cl;
  real_T rtb_Abs;
  real_T rtb_Step1;
  real_T rtb_siB_h[4];
  real_T rtb_Product4_n[4];
  real_T rtb_e;
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
  real_T rtb_Product7_ma;
  real_T rtb_d_qGE[4];
  real_T rtb_VectorConcatenate3[9];
  real_T rtb_PulseGenerator1;
  real_T rtb_PulseGenerator;
  real_T rtb_PulseGenerator4;
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
  real_T rtb_MatrixMultiply_tmp[9];
  real_T rtb_vBEB_a_tmp[9];
  int32_T i;
  real_T tmp[16];
  int32_T i_0;
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
  real_T rtb_Step1_tmp;
  real_T frac_tmp;
  real_T frac_tmp_0;
  real_T rtb_Subtract_ay_tmp;
  real_T rtb_Subtract_ay_tmp_0;
  real_T rtb_TBG_tmp_5;
  int32_T rtb_MultiportSwitch1_tmp;
=======
  real_T rtb_Add_n;
  real_T rtb_Memory;
  real_T rtb_Add_p;
  real_T rtb_Memory_m;
  boolean_T rtb_Receive_from_FTHWICC_o10;
  boolean_T rtb_Receive_from_FTHWICC_o11;
  boolean_T didZcEventOccur;
  real_T rtb_Fin_1_Pos_rad;
  real_T rtb_Fin_2_Pos_rad;
  real_T rtb_Fin_3_Pos_rad;
  real_T rtb_Fin_4_Pos_rad;
  real_T rtb_q_B_radDs;
  real_T rtb_r_B_radDs;
  real_T rtb_ACC_y_B_mDs2_d;
  real_T rtb_ACC_z_B_mDs2_i;
  real_T rtb_PulseGenerator1;
  real_T rtb_PulseGenerator;
  real_T rtb_p_B_radDs;
  real_T rtb_Add16_j;
  real_T rtb_Add3;
  uint16_T rtb_FixPtSum1;
  real_T rtb_Add_g;
  real_T rtb_sincos_o1_idx_2;
  real_T rtb_sincos_o1_idx_1;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_sincos_o2_idx_0;
>>>>>>> origin/master
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
  srClearBC(GRM_HIL_DW.Com_to_FCC_emul_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Pass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Saturate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.FB_Com_freq_emul_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Construct_Bus_SubsysRanBC);
<<<<<<< HEAD

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S186>/Constant' */
    memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
           (real_T));
  }

  /* Integrator: '<S193>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK != 0) {
    memcpy(&GRM_HIL_X.integration_eom_CSTATE[0], &GRM_HIL_B.Constant[0], 13U *
           sizeof(real_T));
  }

  /* Gain: '<S53>/Gain17' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.POS_z_NED_m = GRM_HIL_P.Gain17_Gain *
    GRM_HIL_X.integration_eom_CSTATE[2];

  /* RelationalOperator: '<S246>/Compare' incorporates:
   *  Constant: '<S246>/Constant'
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
=======

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);
>>>>>>> origin/master

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

<<<<<<< HEAD
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
        sendToAsyncQueueTgtAppSvc(534490233U, time, pData, size);
=======
  /* Outputs for Enabled SubSystem: '<S54>/Propulsion' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S7>/Constant4' */
    if (GRM_HIL_P.Constant4_Value_g) {
      GRM_HIL_DW.Propulsion_MODE = true;
    } else {
      if (GRM_HIL_DW.Propulsion_MODE) {
        /* Disable for Enabled SubSystem: '<S60>/hold_time' */
        GRM_HIL_DW.hold_time_MODE = false;

        /* End of Disable for SubSystem: '<S60>/hold_time' */

        /* Disable for Enabled SubSystem: '<S60>/Subsystem' */
        if (GRM_HIL_DW.Subsystem_MODE) {
          /* Disable for Outport: '<S67>/thrust' */
          GRM_HIL_B.OutportBufferForthrust = GRM_HIL_P.thrust_Y0;
          GRM_HIL_DW.Subsystem_MODE = false;
        }

        /* End of Disable for SubSystem: '<S60>/Subsystem' */

        /* Disable for Outport: '<S60>/motor_state_perc_dot' */
        GRM_HIL_B.OutportBufferFormotor_state_perc_dot =
          GRM_HIL_P.motor_state_perc_dot_Y0;
        GRM_HIL_DW.Propulsion_MODE = false;
>>>>>>> origin/master
      }

<<<<<<< HEAD
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_2_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2247678117U, time, pData, size);
      }
=======
    /* End of Constant: '<S7>/Constant4' */
  }

  if (GRM_HIL_DW.Propulsion_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S60>/lock' */
      GRM_HIL_B.lock = GRM_HIL_DW.lock_PreviousInput;
    }
>>>>>>> origin/master

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_3_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2566677196U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_4_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(907741790U, time, pData, size);
      }

<<<<<<< HEAD
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(995973964U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2126573311U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(239892720U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_i;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1370050257U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(18228391U, time, pData, size);
=======
    /* Logic: '<S60>/Logical Operator1' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    GRM_HIL_B.LogicalOperator1 = ((rtb_Add_g != 0.0) || GRM_HIL_B.lock);

    /* Logic: '<S60>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_h = !GRM_HIL_B.LogicalOperator1;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S68>/Enable' */
      GRM_HIL_B.HiddenBuf_InsertedFor_hold_time_at_inport_0 =
        GRM_HIL_B.LogicalOperator_h;

      /* Outputs for Enabled SubSystem: '<S60>/hold_time' incorporates:
       *  EnablePort: '<S68>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        GRM_HIL_DW.hold_time_MODE =
          GRM_HIL_B.HiddenBuf_InsertedFor_hold_time_at_inport_0;
      }

      /* End of Outputs for SubSystem: '<S60>/hold_time' */
    }

    /* Outputs for Enabled SubSystem: '<S60>/hold_time' incorporates:
     *  EnablePort: '<S68>/Enable'
     */
    if (GRM_HIL_DW.hold_time_MODE) {
      /* Clock: '<S68>/Clock' */
      GRM_HIL_B.Clock = GRM_HIL_M->Timing.t[0];
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.hold_time_SubsysRanBC);
>>>>>>> origin/master
      }

<<<<<<< HEAD
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(851128855U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3887155668U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_c;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3512087179U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2958682624U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_f;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2917152931U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_n;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(247623123U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4098337573U, time, pData, size);
      }
    }

    /* S-Function (sldrtpi): '<S38>/Receive_from_FTHWICC' */
    /* S-Function Block: <S38>/Receive_from_FTHWICC */
    {
      uint8_T indata[66U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 66U,
        &GRM_HIL_P.Receive_from_FTHWICC_PacketID, (double*) indata, NULL);
      rtb_Receive_from_FTHWICC_o11 = (status>>1) & 0x1;/* Data Error port */
      rtb_Receive_from_FTHWICC_o10 = status & 0x1;/* Data Ready port */
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
=======
    /* End of Outputs for SubSystem: '<S60>/hold_time' */

    /* Sum: '<S60>/Add' incorporates:
     *  Clock: '<S60>/Clock'
     */
    rtb_Add_g = GRM_HIL_M->Timing.t[0] - GRM_HIL_B.Clock;

    /* Logic: '<S60>/Logical Operator2' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S66>/Compare'
     */
    GRM_HIL_B.LogicalOperator2_m = (GRM_HIL_B.LogicalOperator1 && (rtb_Add_g <
      GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.Propulsion.burntime_s));
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S67>/Enable' */
      GRM_HIL_B.HiddenBuf_InsertedFor_Subsystem_at_inport_1 =
        GRM_HIL_B.LogicalOperator2_m;

      /* Outputs for Enabled SubSystem: '<S60>/Subsystem' incorporates:
       *  EnablePort: '<S67>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        if (GRM_HIL_B.HiddenBuf_InsertedFor_Subsystem_at_inport_1) {
          GRM_HIL_DW.Subsystem_MODE = true;
        } else {
          if (GRM_HIL_DW.Subsystem_MODE) {
            /* Disable for Outport: '<S67>/thrust' */
            GRM_HIL_B.OutportBufferForthrust = GRM_HIL_P.thrust_Y0;
            GRM_HIL_DW.Subsystem_MODE = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S60>/Subsystem' */
    }

    /* Outputs for Enabled SubSystem: '<S60>/Subsystem' incorporates:
     *  EnablePort: '<S67>/Enable'
     */
    if (GRM_HIL_DW.Subsystem_MODE) {
      if (rtmIsMajorTimeStep(GRM_HIL_M) &&
          GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
        /* SignalConversion generated from: '<S67>/thrust' incorporates:
         *  Constant: '<S67>/Constant'
         */
        GRM_HIL_B.OutportBufferForthrust =
          GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.Propulsion.thrust_avg_N;
      }

      /* Sum: '<S67>/Add1' incorporates:
       *  Constant: '<S67>/Constant1'
       *  Constant: '<S67>/Constant2'
       *  Product: '<S67>/Divide'
       */
      GRM_HIL_B.Add1 = GRM_HIL_P.Constant2_Value_d - rtb_Add_g /
        GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.Propulsion.burntime_s;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Subsystem_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S60>/Subsystem' */

    /* SignalConversion generated from: '<S60>/motor_state_perc_dot' */
    GRM_HIL_B.OutportBufferFormotor_state_perc_dot = GRM_HIL_B.Add1;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Propulsion_SubsysRanBC);
>>>>>>> origin/master
    }

<<<<<<< HEAD
    /* Outputs for Enabled SubSystem: '<S38>/Construct_Bus' incorporates:
     *  EnablePort: '<S40>/Enable'
     */
    /* Logic: '<S38>/Logical Operator' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant1'
     *  Constant: '<S44>/Constant10'
     *  Constant: '<S44>/Constant11'
     *  Constant: '<S44>/Constant2'
     *  Constant: '<S44>/Constant3'
     *  Constant: '<S44>/Constant4'
     *  Constant: '<S44>/Constant5'
     *  Constant: '<S44>/Constant6'
     *  Constant: '<S44>/Constant7'
     *  Constant: '<S44>/Constant8'
     *  Constant: '<S44>/Constant9'
     *  Logic: '<S38>/NOT'
     *  Trigonometry: '<S46>/sincos'
=======
  /* End of Outputs for SubSystem: '<S54>/Propulsion' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S7>/Constant2' */
    GRM_HIL_B.reset = GRM_HIL_P.Constant2_Value_f5;

    /* Gain: '<S46>/Gain18' incorporates:
     *  Constant: '<S5>/Constant18'
     */
    GRM_HIL_B.motor_state_perc = GRM_HIL_P.Gain18_Gain *
      GRM_HIL_P.Initial_States_Airframe.motor_state_perc;

    /* Gain: '<S46>/Gain9' incorporates:
     *  Constant: '<S5>/Constant9'
>>>>>>> origin/master
     */
    if (rtb_Receive_from_FTHWICC_o10 && (!rtb_Receive_from_FTHWICC_o11)) {
      /* SignalConversion generated from: '<S40>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_operational_flg = GRM_HIL_B.Receive_from_FTHWICC_o1;

      /* SignalConversion generated from: '<S40>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_Ramp_flg = GRM_HIL_B.Receive_from_FTHWICC_o2;

      /* SignalConversion generated from: '<S40>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_B.Receive_from_FTHWICC_o3;

      /* SignalConversion generated from: '<S40>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_B.Receive_from_FTHWICC_o4;
      GRM_HIL_B.Data_plus = GRM_HIL_P.Constant_Value;
      GRM_HIL_B.Data_minus = GRM_HIL_P.Constant1_Value;
      GRM_HIL_B.Clock_plus = GRM_HIL_P.Constant2_Value;
      GRM_HIL_B.Clock_minus = GRM_HIL_P.Constant3_Value;

      /* SignalConversion generated from: '<S44>/Constant1' incorporates:
       *  Constant: '<S44>/Constant'
       *  Constant: '<S44>/Constant1'
       *  Constant: '<S44>/Constant2'
       *  Constant: '<S44>/Constant3'
       */
      GRM_HIL_B.Data_minus_j = GRM_HIL_B.Data_minus;

      /* SignalConversion generated from: '<S44>/Constant2' */
      GRM_HIL_B.Clock_plus_j = GRM_HIL_B.Clock_plus;

      /* SignalConversion generated from: '<S44>/Constant3' */
      GRM_HIL_B.Clock_minus_d = GRM_HIL_B.Clock_minus;

      /* SignalConversion generated from: '<S44>/Constant' */
      GRM_HIL_B.Data_plus_p = GRM_HIL_B.Data_plus;
      GRM_HIL_B.Data_plus_pq = GRM_HIL_P.Constant4_Value;
      GRM_HIL_B.Data_minus_b = GRM_HIL_P.Constant5_Value;
      GRM_HIL_B.Clock_plus_l = GRM_HIL_P.Constant6_Value;
      GRM_HIL_B.Clock_minus_c = GRM_HIL_P.Constant7_Value_a;

      /* SignalConversion generated from: '<S44>/Constant4' incorporates:
       *  Constant: '<S44>/Constant4'
       *  Constant: '<S44>/Constant5'
       *  Constant: '<S44>/Constant6'
       *  Constant: '<S44>/Constant7'
       */
      GRM_HIL_B.Data_plus_pe = GRM_HIL_B.Data_plus_pq;

      /* SignalConversion generated from: '<S44>/Constant5' */
      GRM_HIL_B.Data_minus_jy = GRM_HIL_B.Data_minus_b;

      /* SignalConversion generated from: '<S44>/Constant6' */
      GRM_HIL_B.Clock_plus_jb = GRM_HIL_B.Clock_plus_l;

      /* SignalConversion generated from: '<S44>/Constant7' */
      GRM_HIL_B.Clock_minus_d1 = GRM_HIL_B.Clock_minus_c;
      GRM_HIL_B.Clock_plus_a = GRM_HIL_P.Constant10_Value;
      GRM_HIL_B.Clock_minus_h = GRM_HIL_P.Constant11_Value_c;
      GRM_HIL_B.Data_plus_n = GRM_HIL_P.Constant8_Value;
      GRM_HIL_B.Data_minus_g = GRM_HIL_P.Constant9_Value_m;

      /* SignalConversion generated from: '<S44>/Constant10' incorporates:
       *  Constant: '<S44>/Constant10'
       *  Constant: '<S44>/Constant11'
       *  Constant: '<S44>/Constant8'
       *  Constant: '<S44>/Constant9'
       */
      GRM_HIL_B.Clock_plus_jbf = GRM_HIL_B.Clock_plus_a;

<<<<<<< HEAD
      /* SignalConversion generated from: '<S44>/Constant11' */
      GRM_HIL_B.Clock_minus_d1h = GRM_HIL_B.Clock_minus_h;

      /* SignalConversion generated from: '<S44>/Constant8' */
      GRM_HIL_B.Data_plus_pek = GRM_HIL_B.Data_plus_n;

      /* SignalConversion generated from: '<S44>/Constant9' */
      GRM_HIL_B.Data_minus_jye = GRM_HIL_B.Data_minus_g;

      /* Gain: '<S43>/Shaft2radYaw' */
      GRM_HIL_B.ATT_Psi_rad_e = GRM_HIL_P.Shaft2radYaw_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o5;

      /* Gain: '<S43>/Shaft2radPitch' */
      GRM_HIL_B.ATT_Theta_rad_e = GRM_HIL_P.Shaft2radPitch_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o6;

      /* Gain: '<S43>/Shaft2radRoll' */
      GRM_HIL_B.ATT_Phi_rad_p = GRM_HIL_P.Shaft2radRoll_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o7;

      /* Gain: '<S46>/1//2' */
      rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.u2_Gain *
        GRM_HIL_B.ATT_Psi_rad_e;
      rtb_VectorConcatenate_f_idx_1 = GRM_HIL_P.u2_Gain *
        GRM_HIL_B.ATT_Theta_rad_e;
      rtb_VectorConcatenate_f_idx_2 = GRM_HIL_P.u2_Gain *
        GRM_HIL_B.ATT_Phi_rad_p;

      /* Trigonometry: '<S46>/sincos' */
      rtb_sincos_o2[0] = cos(rtb_VectorConcatenate_f_idx_0);
      rtb_VectorConcatenate_f_idx_0 = sin(rtb_VectorConcatenate_f_idx_0);

      /* Trigonometry: '<S46>/sincos' */
      rtb_sincos_o2[1] = cos(rtb_VectorConcatenate_f_idx_1);
      rtb_VectorConcatenate_f_idx_1 = sin(rtb_VectorConcatenate_f_idx_1);

      /* Trigonometry: '<S46>/sincos' */
      rtb_sincos_o2[2] = cos(rtb_VectorConcatenate_f_idx_2);
      rtb_Product_idx_0 = sin(rtb_VectorConcatenate_f_idx_2);

      /* Fcn: '<S46>/q0' incorporates:
       *  Fcn: '<S46>/q3'
       */
      rtb_Product_idx_1 = rtb_sincos_o2[0] * rtb_sincos_o2[1];
      rtb_Product_idx_2 = rtb_VectorConcatenate_f_idx_0 *
        rtb_VectorConcatenate_f_idx_1;
      GRM_HIL_B.q0_d = rtb_Product_idx_1 * rtb_sincos_o2[2] - rtb_Product_idx_2 *
        rtb_Product_idx_0;

      /* Fcn: '<S46>/q1' incorporates:
       *  Fcn: '<S46>/q2'
       */
      rtb_Product_idx_3 = rtb_sincos_o2[0] * rtb_VectorConcatenate_f_idx_1;
      rtb_VectorConcatenate_f_idx_1 = rtb_VectorConcatenate_f_idx_0 *
        rtb_sincos_o2[1];
      GRM_HIL_B.q1_o = rtb_Product_idx_3 * rtb_Product_idx_0 +
        rtb_VectorConcatenate_f_idx_1 * rtb_sincos_o2[2];

      /* Fcn: '<S46>/q2' */
      GRM_HIL_B.q2_i = rtb_Product_idx_3 * rtb_sincos_o2[2] -
        rtb_VectorConcatenate_f_idx_1 * rtb_Product_idx_0;

      /* Fcn: '<S46>/q3' */
      GRM_HIL_B.q3_o = rtb_Product_idx_1 * rtb_Product_idx_0 + rtb_Product_idx_2
        * rtb_sincos_o2[2];

      /* SignalConversion generated from: '<S40>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_yaw_sns = GRM_HIL_B.Receive_from_FTHWICC_o5;

      /* SignalConversion generated from: '<S40>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_pitch_sns = GRM_HIL_B.Receive_from_FTHWICC_o6;

      /* SignalConversion generated from: '<S40>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_roll_sns = GRM_HIL_B.Receive_from_FTHWICC_o7;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Construct_Bus_SubsysRanBC);
      }
    }

    /* End of Logic: '<S38>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S38>/Construct_Bus' */

    /* ToAsyncQueueBlock generated from: '<Root>/Gimbal' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_operational_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4242144941U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_Ramp_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(195777777U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_Limit_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2862780090U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_StopSim_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3850325976U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad_p;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1865950052U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad_e;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2559885073U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad_e;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3545546000U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1816354602U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1_o;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2195006954U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2_i;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3069084417U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3_o;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1649172418U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_yaw_sns;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2850325010U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_pitch_sns;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2469082244U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_roll_sns;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2414373843U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_p;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(8604856U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_j;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3616794591U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_j;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3822359819U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(293475379U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_pe;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3502846206U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_jy;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2802034374U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_jb;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(992975U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2271144442U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_pek;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3985107761U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_jye;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2286043056U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_jbf;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1251080209U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d1h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(237126732U, time, pData, size);
      }
    }
  }

  /* Sum: '<S196>/Add' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S196>/Product1'
   *  Product: '<S196>/Product2'
   *  Product: '<S196>/Product3'
   *  Product: '<S196>/Product4'
   */
  rtb_Subtract_cl = ((GRM_HIL_X.integration_eom_CSTATE[6] *
                      GRM_HIL_X.integration_eom_CSTATE[6] +
                      GRM_HIL_X.integration_eom_CSTATE[7] *
                      GRM_HIL_X.integration_eom_CSTATE[7]) +
                     GRM_HIL_X.integration_eom_CSTATE[8] *
                     GRM_HIL_X.integration_eom_CSTATE[8]) +
    GRM_HIL_X.integration_eom_CSTATE[9] * GRM_HIL_X.integration_eom_CSTATE[9];

  /* Math: '<S196>/Math Function'
   *
   * About '<S196>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Subtract_cl < 0.0) {
    rtb_Subtract_cl = -sqrt(fabs(rtb_Subtract_cl));
  } else {
    rtb_Subtract_cl = sqrt(rtb_Subtract_cl);
  }

  /* End of Math: '<S196>/Math Function' */

  /* Product: '<S196>/Product' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  rtb_Product_idx_0 = GRM_HIL_X.integration_eom_CSTATE[6] / rtb_Subtract_cl;
  rtb_Product_idx_1 = GRM_HIL_X.integration_eom_CSTATE[7] / rtb_Subtract_cl;
  rtb_Product_idx_2 = GRM_HIL_X.integration_eom_CSTATE[8] / rtb_Subtract_cl;
  rtb_Product_idx_3 = GRM_HIL_X.integration_eom_CSTATE[9] / rtb_Subtract_cl;

  /* Math: '<S151>/Math Function1' incorporates:
   *  Math: '<S151>/Math Function5'
   *  Math: '<S151>/Math Function9'
   */
  rtb_VectorConcatenate_f_idx_1 = rtb_Product_idx_1 * rtb_Product_idx_1;

  /* Math: '<S151>/Math Function' incorporates:
   *  Math: '<S151>/Math Function4'
   *  Math: '<S151>/Math Function8'
   */
  rtb_lat = rtb_Product_idx_0 * rtb_Product_idx_0;

  /* Math: '<S151>/Math Function2' incorporates:
   *  Math: '<S151>/Math Function10'
   *  Math: '<S151>/Math Function6'
   */
  rtb_Abs = rtb_Product_idx_2 * rtb_Product_idx_2;

  /* Math: '<S151>/Math Function3' incorporates:
   *  Math: '<S151>/Math Function11'
   *  Math: '<S151>/Math Function7'
   */
  rtb_Cx = rtb_Product_idx_3 * rtb_Product_idx_3;

  /* Sum: '<S151>/Add' incorporates:
   *  Math: '<S151>/Math Function'
   *  Math: '<S151>/Math Function1'
   *  Math: '<S151>/Math Function2'
   *  Math: '<S151>/Math Function3'
   *  Sum: '<S194>/Add'
   *  Switch: '<S192>/Switch'
   */
  rtb_VectorConcatenate_f_idx_2 = ((rtb_lat - rtb_VectorConcatenate_f_idx_1) -
    rtb_Abs) + rtb_Cx;
  rtb_TBG[0] = rtb_VectorConcatenate_f_idx_2;

  /* Product: '<S151>/Product' incorporates:
   *  Product: '<S151>/Product6'
   *  Product: '<S194>/Product'
   *  Product: '<S194>/Product6'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp = rtb_Product_idx_0 * rtb_Product_idx_1;

  /* Product: '<S151>/Product1' incorporates:
   *  Product: '<S151>/Product7'
   *  Product: '<S194>/Product1'
   *  Product: '<S194>/Product7'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp_0 = rtb_Product_idx_2 * rtb_Product_idx_3;

  /* Sum: '<S151>/Add1' incorporates:
   *  Gain: '<S151>/Gain1'
   *  Gain: '<S151>/Gain2'
   *  Product: '<S151>/Product'
   *  Product: '<S151>/Product1'
   */
  rtb_TBG[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_c - rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain2_Gain_c;

  /* Product: '<S151>/Product8' incorporates:
   *  Product: '<S151>/Product4'
   *  Product: '<S194>/Product4'
   *  Product: '<S194>/Product8'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp_1 = rtb_Product_idx_0 * rtb_Product_idx_2;

  /* Product: '<S151>/Product9' incorporates:
   *  Product: '<S151>/Product5'
   *  Product: '<S194>/Product5'
   *  Product: '<S194>/Product9'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp_2 = rtb_Product_idx_1 * rtb_Product_idx_3;

  /* Sum: '<S151>/Add5' incorporates:
   *  Gain: '<S151>/Gain10'
   *  Gain: '<S151>/Gain9'
   *  Product: '<S151>/Product8'
   *  Product: '<S151>/Product9'
   */
  rtb_TBG[2] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain9_Gain_c + rtb_TBG_tmp_2 *
    GRM_HIL_P.Gain10_Gain_g;

  /* Sum: '<S151>/Add4' incorporates:
   *  Gain: '<S151>/Gain7'
   *  Gain: '<S151>/Gain8'
   */
  rtb_TBG[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain_c + rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain8_Gain_b;

  /* Sum: '<S151>/Add6' incorporates:
   *  Sum: '<S194>/Add6'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp_5 = ((rtb_VectorConcatenate_f_idx_1 - rtb_lat) - rtb_Abs) + rtb_Cx;
  rtb_TBG[4] = rtb_TBG_tmp_5;

  /* Product: '<S151>/Product2' incorporates:
   *  Product: '<S151>/Product10'
   *  Product: '<S194>/Product10'
   *  Product: '<S194>/Product2'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp_3 = rtb_Product_idx_1 * rtb_Product_idx_2;

  /* Product: '<S151>/Product3' incorporates:
   *  Product: '<S151>/Product11'
   *  Product: '<S194>/Product11'
   *  Product: '<S194>/Product3'
   *  Switch: '<S192>/Switch'
   */
  rtb_TBG_tmp_4 = rtb_Product_idx_0 * rtb_Product_idx_3;

  /* Sum: '<S151>/Add2' incorporates:
   *  Gain: '<S151>/Gain3'
   *  Gain: '<S151>/Gain4'
   *  Product: '<S151>/Product2'
   *  Product: '<S151>/Product3'
   */
  rtb_TBG[5] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain3_Gain_p - rtb_TBG_tmp_4 *
    GRM_HIL_P.Gain4_Gain_o;

  /* Sum: '<S151>/Add3' incorporates:
   *  Gain: '<S151>/Gain5'
   *  Gain: '<S151>/Gain6'
   */
  rtb_TBG[6] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain5_Gain_l - rtb_TBG_tmp_2 *
    GRM_HIL_P.Gain6_Gain_p;

  /* Sum: '<S151>/Add8' incorporates:
   *  Gain: '<S151>/Gain11'
   *  Gain: '<S151>/Gain12'
   */
  rtb_TBG[7] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain11_Gain_d + rtb_TBG_tmp_4 *
    GRM_HIL_P.Gain12_Gain_g;

  /* Sum: '<S151>/Add7' incorporates:
   *  Sum: '<S194>/Add7'
   *  Switch: '<S192>/Switch'
   */
  rtb_VectorConcatenate_f_idx_1 = ((rtb_Abs - rtb_lat) -
    rtb_VectorConcatenate_f_idx_1) + rtb_Cx;
  rtb_TBG[8] = rtb_VectorConcatenate_f_idx_1;
  for (i = 0; i < 3; i++) {
    /* Math: '<S185>/Math Function' incorporates:
     *  Math: '<S202>/Math Function'
     */
    rtb_MatrixMultiply_tmp[3 * i] = rtb_TBG[i];
    rtb_MatrixMultiply_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_MatrixMultiply_tmp[3 * i + 2] = rtb_TBG[i + 6];
  }

  /* Product: '<S185>/Product1' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Math: '<S185>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    rtb_sincos_o2[i] = rtb_MatrixMultiply_tmp[i + 6] *
      GRM_HIL_X.integration_eom_CSTATE[5] + (rtb_MatrixMultiply_tmp[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[4] + rtb_MatrixMultiply_tmp[i] *
      GRM_HIL_X.integration_eom_CSTATE[3]);
  }

  /* End of Product: '<S185>/Product1' */

  /* Gain: '<S53>/Gain' */
  GRM_HIL_B.VEL_u_K_R_E_B_mDs = GRM_HIL_P.Gain_Gain_k1 * rtb_sincos_o2[0];

  /* Gain: '<S53>/Gain1' */
  GRM_HIL_B.VEL_v_K_R_E_B_mDs = GRM_HIL_P.Gain1_Gain_mm * rtb_sincos_o2[1];

  /* Gain: '<S53>/Gain2' */
  GRM_HIL_B.VEL_w_K_R_E_B_mDs = GRM_HIL_P.Gain2_Gain_e * rtb_sincos_o2[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S161>/Constant8' */
    GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];
    GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];
    GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];
    GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];
  }

  /* Integrator: '<S161>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_g != 0) {
    GRM_HIL_X.integration_eom_CSTATE_b[0] = GRM_HIL_B.Constant8[0];
    GRM_HIL_X.integration_eom_CSTATE_b[1] = GRM_HIL_B.Constant8[1];
    GRM_HIL_X.integration_eom_CSTATE_b[2] = GRM_HIL_B.Constant8[2];
    GRM_HIL_X.integration_eom_CSTATE_b[3] = GRM_HIL_B.Constant8[3];
  }

  /* Sum: '<S165>/Add' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Math: '<S165>/Math Function'
   *  Math: '<S165>/Math Function1'
   *  Math: '<S165>/Math Function2'
   *  Math: '<S165>/Math Function3'
   */
  rtb_VectorConcatenate3[0] = ((GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0] - GRM_HIL_X.integration_eom_CSTATE_b[1]
    * GRM_HIL_X.integration_eom_CSTATE_b[1]) -
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[2])
    + GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S165>/Add1' incorporates:
   *  Gain: '<S165>/Gain1'
   *  Gain: '<S165>/Gain2'
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S165>/Product'
   *  Product: '<S165>/Product1'
   */
  rtb_VectorConcatenate3[1] = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[1] * GRM_HIL_P.Gain1_Gain_i -
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[3]
    * GRM_HIL_P.Gain2_Gain_iy;

  /* Product: '<S165>/Product8' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S165>/Product4'
   */
  rtb_lat = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S165>/Product9' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S165>/Product5'
   */
  rtb_Abs = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S165>/Add5' incorporates:
   *  Gain: '<S165>/Gain10'
   *  Gain: '<S165>/Gain9'
   *  Product: '<S165>/Product8'
   *  Product: '<S165>/Product9'
   */
  rtb_VectorConcatenate3[2] = rtb_lat * GRM_HIL_P.Gain9_Gain_g + rtb_Abs *
    GRM_HIL_P.Gain10_Gain_h;

  /* Sum: '<S165>/Add4' incorporates:
   *  Gain: '<S165>/Gain7'
   *  Gain: '<S165>/Gain8'
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S165>/Product6'
   *  Product: '<S165>/Product7'
   */
  rtb_VectorConcatenate3[3] = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[1] * GRM_HIL_P.Gain7_Gain_i +
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[3]
    * GRM_HIL_P.Gain8_Gain_d;

  /* Math: '<S165>/Math Function6' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Math: '<S165>/Math Function10'
   */
  rtb_Cx = GRM_HIL_X.integration_eom_CSTATE_b[2] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Math: '<S165>/Math Function4' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Math: '<S165>/Math Function8'
   */
  rtb_Add = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0];

  /* Math: '<S165>/Math Function5' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Math: '<S165>/Math Function9'
   */
  rtb_Sqrt_j = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];

  /* Math: '<S165>/Math Function7' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Math: '<S165>/Math Function11'
   */
  rtb_f_beB = GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S165>/Add6' incorporates:
   *  Math: '<S165>/Math Function4'
   *  Math: '<S165>/Math Function5'
   *  Math: '<S165>/Math Function6'
   *  Math: '<S165>/Math Function7'
   */
  rtb_VectorConcatenate3[4] = ((rtb_Sqrt_j - rtb_Add) - rtb_Cx) + rtb_f_beB;

  /* Product: '<S165>/Product2' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S165>/Product10'
   */
  rtb_siB_c5 = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S165>/Product3' incorporates:
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S165>/Product11'
   */
  rtb_Gain_g = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S165>/Add2' incorporates:
   *  Gain: '<S165>/Gain3'
   *  Gain: '<S165>/Gain4'
   *  Product: '<S165>/Product2'
   *  Product: '<S165>/Product3'
   */
  rtb_VectorConcatenate3[5] = rtb_siB_c5 * GRM_HIL_P.Gain3_Gain_i - rtb_Gain_g *
    GRM_HIL_P.Gain4_Gain_f;

  /* Sum: '<S165>/Add3' incorporates:
   *  Gain: '<S165>/Gain5'
   *  Gain: '<S165>/Gain6'
   */
  rtb_VectorConcatenate3[6] = rtb_lat * GRM_HIL_P.Gain5_Gain_i - rtb_Abs *
    GRM_HIL_P.Gain6_Gain_n;

  /* Sum: '<S165>/Add8' incorporates:
   *  Gain: '<S165>/Gain11'
   *  Gain: '<S165>/Gain12'
   */
  rtb_VectorConcatenate3[7] = rtb_siB_c5 * GRM_HIL_P.Gain11_Gain_n + rtb_Gain_g *
    GRM_HIL_P.Gain12_Gain_h;

  /* Sum: '<S165>/Add7' */
  rtb_VectorConcatenate3[8] = ((rtb_Cx - rtb_Add) - rtb_Sqrt_j) + rtb_f_beB;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S160>/Switch' incorporates:
     *  Constant: '<S160>/Constant7'
     *  Constant: '<S160>/Constant9'
     */
    if (GRM_HIL_P.Constant9_Value_p > GRM_HIL_P.Switch_Threshold) {
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant7_Value_i;

      /* SignalConversion generated from: '<S160>/Vector Concatenate' incorporates:
       *  Constant: '<S160>/Constant6'
       *  Constant: '<S160>/Constant7'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant6_Value_j;

      /* SignalConversion generated from: '<S160>/Vector Concatenate' incorporates:
       *  Constant: '<S160>/Constant6'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant6_Value_j;
    } else {
      /* SignalConversion generated from: '<S160>/Vector Concatenate1' incorporates:
       *  Constant: '<S160>/Constant8'
       */
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant8_Value_b;

      /* SignalConversion generated from: '<S160>/Vector Concatenate1' incorporates:
       *  Constant: '<S160>/Constant8'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant8_Value_b;

      /* SignalConversion generated from: '<S160>/Vector Concatenate1' incorporates:
       *  Constant: '<S160>/Constant8'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant8_Value_b;
    }

    /* End of Switch: '<S160>/Switch' */
  }

  /* Product: '<S204>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_sincos_o2[i] = rtb_VectorConcatenate3[i + 6] * GRM_HIL_B.wIEE[2] +
      (rtb_VectorConcatenate3[i + 3] * GRM_HIL_B.wIEE[1] +
       rtb_VectorConcatenate3[i] * GRM_HIL_B.wIEE[0]);
  }

  /* End of Product: '<S204>/Product' */

  /* Sum: '<S204>/Add' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S209>/Product2'
   *  Product: '<S209>/Product3'
   *  Product: '<S209>/Product4'
   *  Product: '<S209>/Product5'
   *  Product: '<S209>/Product6'
   *  Product: '<S209>/Product7'
   *  Sum: '<S209>/Sum'
   *  Sum: '<S209>/Sum1'
   *  Sum: '<S209>/Sum2'
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
    /* Constant: '<S162>/Constant8' */
    GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];
    GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];
    GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];
    GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];
  }

  /* Integrator: '<S162>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_l != 0) {
    GRM_HIL_X.integration_eom_CSTATE_f[0] = GRM_HIL_B.Constant8_h[0];
    GRM_HIL_X.integration_eom_CSTATE_f[1] = GRM_HIL_B.Constant8_h[1];
    GRM_HIL_X.integration_eom_CSTATE_f[2] = GRM_HIL_B.Constant8_h[2];
    GRM_HIL_X.integration_eom_CSTATE_f[3] = GRM_HIL_B.Constant8_h[3];
  }

  /* Sum: '<S156>/Add' incorporates:
   *  Constant: '<S156>/Q_1'
   *  Constant: '<S156>/Q_2'
   *  Constant: '<S156>/Q_3'
   *  Constant: '<S156>/Q_4'
   *  Integrator: '<S161>/integration_eom'
   *  Product: '<S156>/Product'
   *  Product: '<S156>/Product1'
   *  Product: '<S156>/Product2'
   *  Product: '<S156>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_d[i] * GRM_HIL_X.integration_eom_CSTATE_b[0]
               + GRM_HIL_P.Q_2_Value_nt[i] * GRM_HIL_X.integration_eom_CSTATE_b
               [1]) + GRM_HIL_P.Q_3_Value_o[i] *
              GRM_HIL_X.integration_eom_CSTATE_b[2]) + GRM_HIL_P.Q_4_Value_n[i] *
      GRM_HIL_X.integration_eom_CSTATE_b[3];
  }

  /* End of Sum: '<S156>/Add' */

  /* Product: '<S156>/Product8' incorporates:
   *  Integrator: '<S162>/integration_eom'
   */
  for (i = 0; i < 4; i++) {
    rtb_Subtract_cl = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] +
      (tmp[i + 8] * GRM_HIL_X.integration_eom_CSTATE_f[2] + (tmp[i + 4] *
        GRM_HIL_X.integration_eom_CSTATE_f[1] + tmp[i] *
        GRM_HIL_X.integration_eom_CSTATE_f[0]));
    rtb_siB_h[i] = rtb_Subtract_cl;
  }

  /* End of Product: '<S156>/Product8' */

  /* Sum: '<S159>/Add' incorporates:
   *  Product: '<S159>/Product1'
   *  Product: '<S159>/Product2'
   *  Product: '<S159>/Product3'
   *  Product: '<S159>/Product4'
   */
  rtb_VectorConcatenate_f_idx_0 = ((rtb_siB_h[0] * rtb_siB_h[0] + rtb_siB_h[1] *
    rtb_siB_h[1]) + rtb_siB_h[2] * rtb_siB_h[2]) + rtb_siB_h[3] * rtb_siB_h[3];

  /* Math: '<S159>/Math Function'
   *
   * About '<S159>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_VectorConcatenate_f_idx_0 < 0.0) {
    rtb_VectorConcatenate_f_idx_0 = -sqrt(fabs(rtb_VectorConcatenate_f_idx_0));
  } else {
    rtb_VectorConcatenate_f_idx_0 = sqrt(rtb_VectorConcatenate_f_idx_0);
  }

  /* End of Math: '<S159>/Math Function' */

  /* Product: '<S159>/Product' */
  rtb_siB_h[0] /= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[1] /= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[2] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Subtract_cl = rtb_siB_h[3] / rtb_VectorConcatenate_f_idx_0;

  /* Switch: '<S156>/Switch' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S156>/Constant1'
   */
  if (rtb_Subtract_cl >= GRM_HIL_P.Switch_Threshold_g) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant_Value_gc;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant1_Value_ja;
  }

  /* End of Switch: '<S156>/Switch' */

  /* Product: '<S156>/Product4' */
  rtb_siB_h[0] *= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[1] *= rtb_VectorConcatenate_f_idx_0;
  rtb_siB_h[2] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Subtract_cl *= rtb_VectorConcatenate_f_idx_0;

  /* Gain: '<S153>/Gain1' */
  rtb_Product4_n[0] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[0];
  rtb_Product4_n[1] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[1];
  rtb_Product4_n[2] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[2];

  /* Sum: '<S154>/Add' incorporates:
   *  Constant: '<S154>/Q_1'
   *  Constant: '<S154>/Q_2'
   *  Constant: '<S154>/Q_3'
   *  Constant: '<S154>/Q_4'
   *  Product: '<S154>/Product'
   *  Product: '<S154>/Product1'
   *  Product: '<S154>/Product2'
   *  Product: '<S154>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_k[i] * rtb_Product4_n[0] +
               GRM_HIL_P.Q_2_Value_c[i] * rtb_Product4_n[1]) +
              GRM_HIL_P.Q_3_Value_f[i] * rtb_Product4_n[2]) +
      GRM_HIL_P.Q_4_Value_e[i] * rtb_Subtract_cl;
  }

  /* End of Sum: '<S154>/Add' */

  /* Product: '<S154>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Product_l = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_Product_idx_2 + (tmp[i + 4] * rtb_Product_idx_1 + tmp[i] *
      rtb_Product_idx_0));
    rtb_Product4_n[i] = rtb_Product_l;
  }

  /* End of Product: '<S154>/Product8' */

  /* Sum: '<S157>/Add' incorporates:
   *  Product: '<S157>/Product1'
   *  Product: '<S157>/Product2'
   *  Product: '<S157>/Product3'
   *  Product: '<S157>/Product4'
   */
  rtb_VectorConcatenate_f_idx_0 = ((rtb_Product4_n[0] * rtb_Product4_n[0] +
    rtb_Product4_n[1] * rtb_Product4_n[1]) + rtb_Product4_n[2] * rtb_Product4_n
    [2]) + rtb_Product4_n[3] * rtb_Product4_n[3];

  /* Math: '<S157>/Math Function'
   *
   * About '<S157>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_VectorConcatenate_f_idx_0 < 0.0) {
    rtb_VectorConcatenate_f_idx_0 = -sqrt(fabs(rtb_VectorConcatenate_f_idx_0));
  } else {
    rtb_VectorConcatenate_f_idx_0 = sqrt(rtb_VectorConcatenate_f_idx_0);
  }

  /* End of Math: '<S157>/Math Function' */

  /* Product: '<S157>/Product' */
  rtb_Product4_n[0] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[1] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[2] /= rtb_VectorConcatenate_f_idx_0;
  rtb_Product_l = rtb_Product4_n[3] / rtb_VectorConcatenate_f_idx_0;

  /* Switch: '<S154>/Switch' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S154>/Constant1'
   */
  if (rtb_Product_l >= GRM_HIL_P.Switch_Threshold_h) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant_Value_ie;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant1_Value_m;
  }

  /* End of Switch: '<S154>/Switch' */

  /* Product: '<S154>/Product4' */
  rtb_Product4_n[0] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[1] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Product4_n[2] *= rtb_VectorConcatenate_f_idx_0;
  rtb_Product_l *= rtb_VectorConcatenate_f_idx_0;

  /* Math: '<S152>/Math Function1' incorporates:
   *  Math: '<S152>/Math Function5'
   *  Math: '<S152>/Math Function9'
   */
  rtb_lat = rtb_Product4_n[1] * rtb_Product4_n[1];

  /* Math: '<S152>/Math Function' incorporates:
   *  Math: '<S152>/Math Function4'
   *  Math: '<S152>/Math Function8'
   */
  rtb_Abs = rtb_Product4_n[0] * rtb_Product4_n[0];

  /* Math: '<S152>/Math Function2' incorporates:
   *  Math: '<S152>/Math Function10'
   *  Math: '<S152>/Math Function6'
   */
  rtb_Cx = rtb_Product4_n[2] * rtb_Product4_n[2];

  /* Math: '<S152>/Math Function3' incorporates:
   *  Math: '<S152>/Math Function11'
   *  Math: '<S152>/Math Function7'
   */
  rtb_Add = rtb_Product_l * rtb_Product_l;

  /* Sum: '<S152>/Add' incorporates:
   *  Math: '<S152>/Math Function'
   *  Math: '<S152>/Math Function1'
   *  Math: '<S152>/Math Function2'
   *  Math: '<S152>/Math Function3'
   */
  rtb_TBG[0] = ((rtb_Abs - rtb_lat) - rtb_Cx) + rtb_Add;

  /* Product: '<S152>/Product' incorporates:
   *  Product: '<S152>/Product6'
   */
  rtb_Sqrt_j = rtb_Product4_n[0] * rtb_Product4_n[1];

  /* Product: '<S152>/Product1' incorporates:
   *  Product: '<S152>/Product7'
   */
  rtb_f_beB = rtb_Product4_n[2] * rtb_Product_l;

  /* Sum: '<S152>/Add1' incorporates:
   *  Gain: '<S152>/Gain1'
   *  Gain: '<S152>/Gain2'
   *  Product: '<S152>/Product'
   *  Product: '<S152>/Product1'
   */
  rtb_TBG[1] = rtb_Sqrt_j * GRM_HIL_P.Gain1_Gain_e - rtb_f_beB *
    GRM_HIL_P.Gain2_Gain_j;

  /* Product: '<S152>/Product8' incorporates:
   *  Product: '<S152>/Product4'
   */
  rtb_siB_c5 = rtb_Product4_n[0] * rtb_Product4_n[2];

  /* Product: '<S152>/Product9' incorporates:
   *  Product: '<S152>/Product5'
   */
  rtb_Gain_g = rtb_Product4_n[1] * rtb_Product_l;

  /* Sum: '<S152>/Add5' incorporates:
   *  Gain: '<S152>/Gain10'
   *  Gain: '<S152>/Gain9'
   *  Product: '<S152>/Product8'
   *  Product: '<S152>/Product9'
   */
  rtb_TBG[2] = rtb_siB_c5 * GRM_HIL_P.Gain9_Gain_m + rtb_Gain_g *
    GRM_HIL_P.Gain10_Gain_d;

  /* Sum: '<S152>/Add4' incorporates:
   *  Gain: '<S152>/Gain7'
   *  Gain: '<S152>/Gain8'
   */
  rtb_TBG[3] = rtb_Sqrt_j * GRM_HIL_P.Gain7_Gain_h + rtb_f_beB *
    GRM_HIL_P.Gain8_Gain_l;

  /* Sum: '<S152>/Add6' */
  rtb_TBG[4] = ((rtb_lat - rtb_Abs) - rtb_Cx) + rtb_Add;

  /* Product: '<S152>/Product2' incorporates:
   *  Product: '<S152>/Product10'
   */
  rtb_Sqrt_j = rtb_Product4_n[1] * rtb_Product4_n[2];

  /* Product: '<S152>/Product3' incorporates:
   *  Product: '<S152>/Product11'
   */
  rtb_f_beB = rtb_Product4_n[0] * rtb_Product_l;

  /* Sum: '<S152>/Add2' incorporates:
   *  Gain: '<S152>/Gain3'
   *  Gain: '<S152>/Gain4'
   *  Product: '<S152>/Product2'
   *  Product: '<S152>/Product3'
   */
  rtb_TBG[5] = rtb_Sqrt_j * GRM_HIL_P.Gain3_Gain_e - rtb_f_beB *
    GRM_HIL_P.Gain4_Gain_c;

  /* Sum: '<S152>/Add3' incorporates:
   *  Gain: '<S152>/Gain5'
   *  Gain: '<S152>/Gain6'
   */
  rtb_TBG[6] = rtb_siB_c5 * GRM_HIL_P.Gain5_Gain_c - rtb_Gain_g *
    GRM_HIL_P.Gain6_Gain_b;

  /* Sum: '<S152>/Add8' incorporates:
   *  Gain: '<S152>/Gain11'
   *  Gain: '<S152>/Gain12'
   */
  rtb_TBG[7] = rtb_Sqrt_j * GRM_HIL_P.Gain11_Gain_g + rtb_f_beB *
    GRM_HIL_P.Gain12_Gain_j;

  /* Sum: '<S152>/Add7' */
  rtb_TBG[8] = ((rtb_Cx - rtb_Abs) - rtb_lat) + rtb_Add;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S212>/Add' incorporates:
     *  Constant: '<S212>/course_angle_uncertainty'
     *  Constant: '<S212>/course_angle_wind'
     */
    rtb_Add = GRM_HIL_P.course_angle_wind_Value +
      GRM_HIL_P.course_angle_uncertainty_Value;

    /* MultiPortSwitch: '<S214>/Multiport Switch' incorporates:
     *  Constant: '<S214>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1) {
     case 1:
      /* Trigonometry: '<S215>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S215>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(rtb_Add);

      /* Trigonometry: '<S215>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S215>/Trigonometric Function'
       */
      rtb_Step1 = cos(rtb_Add);

      /* SignalConversion generated from: '<S215>/Matrix Concatenate' incorporates:
       *  Constant: '<S215>/Constant7'
       *  Trigonometry: '<S215>/Trigonometric Function1'
       *  Trigonometry: '<S215>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_j;
      rtb_MultiportSwitch[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[8] = rtb_Step1;

      /* SignalConversion generated from: '<S215>/Matrix Concatenate' incorporates:
       *  Constant: '<S215>/Constant8'
       *  Gain: '<S215>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_af;
      rtb_MultiportSwitch[4] = rtb_Step1;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_kj *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S215>/Matrix Concatenate' incorporates:
       *  Constant: '<S215>/Constant'
       *  Constant: '<S215>/Constant1'
       *  Constant: '<S215>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_b;
      break;

     case 2:
      /* Trigonometry: '<S216>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S216>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(rtb_Add);

      /* Trigonometry: '<S216>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S216>/Trigonometric Function2'
       */
      rtb_Step1 = sin(rtb_Add);

      /* SignalConversion generated from: '<S216>/Matrix Concatenate' incorporates:
       *  Constant: '<S216>/Constant7'
       *  Gain: '<S216>/Gain1'
       *  Trigonometry: '<S216>/Trigonometric Function1'
       *  Trigonometry: '<S216>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_j * rtb_Step1;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_d1;
      rtb_MultiportSwitch[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S216>/Matrix Concatenate' incorporates:
       *  Constant: '<S216>/Constant'
       *  Constant: '<S216>/Constant1'
       *  Constant: '<S216>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ob;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_i;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_g;

      /* SignalConversion generated from: '<S216>/Matrix Concatenate' incorporates:
       *  Constant: '<S216>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_ky;
      rtb_MultiportSwitch[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S217>/Matrix Concatenate' incorporates:
       *  Constant: '<S217>/Constant10'
       *  Constant: '<S217>/Constant11'
       *  Constant: '<S217>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_o;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_d;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_a;

      /* Trigonometry: '<S217>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S217>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(rtb_Add);

      /* Trigonometry: '<S217>/Trigonometric Function' incorporates:
       *  Trigonometry: '<S217>/Trigonometric Function3'
       */
      rtb_Step1 = cos(rtb_Add);

      /* SignalConversion generated from: '<S217>/Matrix Concatenate' incorporates:
       *  Constant: '<S217>/Constant7'
       *  Trigonometry: '<S217>/Trigonometric Function'
       *  Trigonometry: '<S217>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[4] = rtb_Step1;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_g;

      /* SignalConversion generated from: '<S217>/Matrix Concatenate' incorporates:
       *  Constant: '<S217>/Constant8'
       *  Gain: '<S217>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Step1;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_jn *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gg;
      break;
    }

    /* End of MultiPortSwitch: '<S214>/Multiport Switch' */

    /* Sum: '<S212>/Add1' incorporates:
     *  Constant: '<S212>/vWW'
     *  Constant: '<S212>/vWW_uncertainty'
     */
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.vWW_uncertainty_Value +
      GRM_HIL_P.vWW_Value;

    /* Product: '<S213>/Product' incorporates:
     *  Constant: '<S212>/Constant1'
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

    /* End of Product: '<S213>/Product' */
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S202>/Math Function1' incorporates:
     *  Math: '<S59>/Math Function'
     */
    rtb_vBEB_a_tmp[3 * i] = rtb_TBG[i];
    rtb_vBEB_a_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_vBEB_a_tmp[3 * i + 2] = rtb_TBG[i + 6];

    /* Product: '<S202>/Product' */
    rtb_pBEE[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_Gain_fl +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_Product1_m[1] +
       rtb_MatrixMultiply_tmp[i] * rtb_Product1_m[0]);
  }

  /* DotProduct: '<S207>/Dot Product1' */
  rtb_Cx = 0.0;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S203>/Subtract' incorporates:
     *  Math: '<S202>/Math Function1'
     *  Product: '<S202>/Product1'
     */
    rtb_lat = rtb_pBEE[i] - (rtb_vBEB_a_tmp[i + 6] * GRM_HIL_B.vec2[2] +
      (rtb_vBEB_a_tmp[i + 3] * GRM_HIL_B.vec2[1] + rtb_vBEB_a_tmp[i] *
       GRM_HIL_B.vec2[0]));

    /* DotProduct: '<S207>/Dot Product1' */
    rtb_Cx += rtb_lat * rtb_lat;

    /* Sum: '<S203>/Subtract' */
    rtb_vBEB_a[i] = rtb_lat;
  }

  /* Math: '<S207>/Math Function1' incorporates:
   *  DotProduct: '<S207>/Dot Product1'
   *
   * About '<S207>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Cx < 0.0) {
    rtb_VectorConcatenate_f_idx_0 = -sqrt(fabs(rtb_Cx));
  } else {
    rtb_VectorConcatenate_f_idx_0 = sqrt(rtb_Cx);
  }

  /* End of Math: '<S207>/Math Function1' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S126>/Subtract1' incorporates:
     *  Constant: '<S126>/Tmp_norm_msl'
     *  Constant: '<S211>/deviation_Tmp'
     */
    GRM_HIL_B.Tmp_ref = GRM_HIL_P.deviation_Tmp_Value +
      GRM_HIL_P.Tmp_norm_msl_Value;

    /* Constant: '<S187>/Constant' */
    GRM_HIL_B.VectorConcatenate1[0] = GRM_HIL_P.Constant_Value_b;

    /* Constant: '<S187>/Constant2' */
    GRM_HIL_B.VectorConcatenate1[1] = GRM_HIL_P.Constant2_Value_e5;

    /* Product: '<S191>/Product' incorporates:
     *  Constant: '<S189>/c_flat'
     *  Constant: '<S189>/c_rsma'
     *  Constant: '<S191>/Constant'
     *  Sum: '<S191>/Subtract'
     */
    GRM_HIL_B.Product = (GRM_HIL_P.Constant_Value_ne - GRM_HIL_P.c_flat_Value_e)
      * GRM_HIL_P.c_rsma_Value_j;

    /* Product: '<S191>/Product5' */
    rtb_e = GRM_HIL_B.Product * GRM_HIL_B.Product;

    /* Product: '<S191>/Divide' incorporates:
     *  Constant: '<S189>/c_rsma'
     *  Product: '<S191>/Product4'
     *  Sum: '<S191>/Subtract2'
     */
    GRM_HIL_B.Divide = (GRM_HIL_P.c_rsma_Value_j * GRM_HIL_P.c_rsma_Value_j -
                        rtb_e) / rtb_e;

    /* Product: '<S191>/Product3' incorporates:
     *  Constant: '<S189>/c_flat'
     *  Product: '<S190>/Product3'
     */
    rtb_lat = GRM_HIL_P.c_flat_Value_e * GRM_HIL_P.c_flat_Value_e;

    /* Sum: '<S191>/Subtract1' incorporates:
     *  Constant: '<S189>/c_flat'
     *  Gain: '<S191>/Gain'
     *  Product: '<S191>/Product3'
     */
    GRM_HIL_B.Subtract1 = GRM_HIL_P.Gain_Gain_le * GRM_HIL_P.c_flat_Value_e -
      rtb_lat;

    /* Sum: '<S190>/Subtract' incorporates:
     *  Constant: '<S189>/c_flat'
     *  Gain: '<S190>/Gain'
     */
    GRM_HIL_B.Subtract = GRM_HIL_P.Gain_Gain_iy * GRM_HIL_P.c_flat_Value_e -
      rtb_lat;
  }

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Constant1'
   */
  if (GRM_HIL_P.Constant1_Value_bt > GRM_HIL_P.Switch_Threshold_c) {
    /* Gain: '<S187>/Gain' incorporates:
     *  Integrator: '<S193>/integration_eom'
     */
    GRM_HIL_B.VectorConcatenate1[2] = GRM_HIL_P.Gain_Gain_p *
      GRM_HIL_X.integration_eom_CSTATE[2];
    GRM_HIL_B.Switch[0] = GRM_HIL_B.VectorConcatenate1[0];
    GRM_HIL_B.Switch[1] = GRM_HIL_B.VectorConcatenate1[1];
    GRM_HIL_B.Switch[2] = GRM_HIL_B.VectorConcatenate1[2];
  } else {
    /* Product: '<S187>/Product' incorporates:
     *  Integrator: '<S193>/integration_eom'
     *  Math: '<S187>/Math Function'
     */
    for (i = 0; i < 3; i++) {
      rtb_pBEE[i] = rtb_VectorConcatenate3[3 * i + 2] *
        GRM_HIL_X.integration_eom_CSTATE[2] + (rtb_VectorConcatenate3[3 * i + 1]
        * GRM_HIL_X.integration_eom_CSTATE[1] + rtb_VectorConcatenate3[3 * i] *
        GRM_HIL_X.integration_eom_CSTATE[0]);
    }

    /* End of Product: '<S187>/Product' */

    /* Sqrt: '<S191>/Sqrt' incorporates:
     *  Product: '<S191>/Product1'
     *  Product: '<S191>/Product2'
     *  Sqrt: '<S190>/Sqrt'
     *  Sum: '<S191>/Add'
     */
    rtb_Add = sqrt(rtb_pBEE[0] * rtb_pBEE[0] + rtb_pBEE[1] * rtb_pBEE[1]);

    /* Trigonometry: '<S191>/Trigonometric Function' incorporates:
     *  Constant: '<S189>/c_rsma'
     *  Product: '<S191>/Divide1'
     *  Product: '<S191>/Product6'
     *  Product: '<S191>/Product7'
     *  Sqrt: '<S191>/Sqrt'
     */
    rtb_Sqrt_j = atan(rtb_pBEE[2] * GRM_HIL_P.c_rsma_Value_j / (rtb_Add *
      GRM_HIL_B.Product));

    /* Trigonometry: '<S191>/Trigonometric Function3' */
    rtb_lat = cos(rtb_Sqrt_j);

    /* Trigonometry: '<S191>/Trigonometric Function2' */
    rtb_Sqrt_j = sin(rtb_Sqrt_j);

    /* Trigonometry: '<S191>/Trigonometric Function1' incorporates:
     *  Constant: '<S189>/c_rsma'
     *  Product: '<S191>/Divide2'
     *  Product: '<S191>/Product10'
     *  Product: '<S191>/Product11'
     *  Product: '<S191>/Product8'
     *  Product: '<S191>/Product9'
     *  Sqrt: '<S191>/Sqrt'
     *  Sum: '<S191>/Add1'
     *  Sum: '<S191>/Subtract3'
     */
    rtb_lat = atan((rtb_Sqrt_j * rtb_Sqrt_j * rtb_Sqrt_j * (GRM_HIL_B.Divide *
      GRM_HIL_B.Product) + rtb_pBEE[2]) / (rtb_Add - rtb_lat * rtb_lat * rtb_lat
      * (GRM_HIL_B.Subtract1 * GRM_HIL_P.c_rsma_Value_j)));

    /* Trigonometry: '<S190>/Trigonometric Function' */
    rtb_Sqrt_j = sin(rtb_lat);

    /* Sqrt: '<S190>/Sqrt1' incorporates:
     *  Constant: '<S190>/Constant'
     *  Product: '<S190>/Product5'
     *  Sum: '<S190>/Subtract1'
     */
    rtb_Sqrt_j = sqrt(GRM_HIL_P.Constant_Value_nr - rtb_Sqrt_j * rtb_Sqrt_j *
                      GRM_HIL_B.Subtract);

    /* Sum: '<S190>/Sum' incorporates:
     *  Constant: '<S189>/c_rsma'
     *  Product: '<S190>/Product'
     *  Product: '<S190>/Product4'
     *  Trigonometry: '<S190>/cos(latGD)'
     */
    GRM_HIL_B.Switch[2] = rtb_Add / cos(rtb_lat) - GRM_HIL_P.c_rsma_Value_j /
      rtb_Sqrt_j;

    /* SignalConversion generated from: '<S187>/Vector Concatenate' */
    GRM_HIL_B.Switch[1] = rtb_lat;

    /* Trigonometry: '<S189>/Trigonometric Function1' */
    GRM_HIL_B.Switch[0] = rt_atan2d_snf(rtb_pBEE[1], rtb_pBEE[0]);
  }

  /* End of Switch: '<S187>/Switch' */

  /* Product: '<S124>/Divide' incorporates:
   *  Constant: '<S124>/mean_earth_radius'
   *  Sum: '<S124>/Add'
   */
  rtb_Step1 = GRM_HIL_B.Switch[2] / (GRM_HIL_B.Switch[2] +
    GRM_HIL_P.geopot_height_mean_earth_radius) *
    GRM_HIL_P.geopot_height_mean_earth_radius;

  /* Saturate: '<S114>/Saturation' */
  if (rtb_Step1 > GRM_HIL_P.Saturation_UpperSat_h) {
    rtb_Step1 = GRM_HIL_P.Saturation_UpperSat_h;
  } else {
    if (rtb_Step1 < GRM_HIL_P.Saturation_LowerSat_k) {
      rtb_Step1 = GRM_HIL_P.Saturation_LowerSat_k;
    }
  }

  /* End of Saturate: '<S114>/Saturation' */

  /* Sum: '<S127>/Subtract' incorporates:
   *  Constant: '<S126>/geopotential_height_ref'
   *  Sum: '<S128>/Subtract'
   */
  rtb_Step1 -= GRM_HIL_P.geopotential_height_ref_Value;

  /* Sum: '<S127>/Add' incorporates:
   *  Constant: '<S127>/Tmp_gradient_tropo'
   *  Product: '<S127>/Product'
   *  Sum: '<S127>/Subtract'
   */
  rtb_Abs = rtb_Step1 * GRM_HIL_P.Tmp_gradient_tropo_Value + GRM_HIL_B.Tmp_ref;

  /* PreLookup: '<S99>/Prelookup_Mach' incorporates:
   *  Constant: '<S125>/heat_capacity_ratio'
   *  Constant: '<S125>/specific_gas_constant'
   *  Product: '<S125>/Product'
   *  Product: '<S203>/Divide'
   *  Sqrt: '<S125>/Sqrt'
   */
  rtb_k_Mach = plook_binc(rtb_VectorConcatenate_f_idx_0 / sqrt
    (GRM_HIL_P.specific_gas_constant_Value * GRM_HIL_P.heat_capacity_ratio_Value
     * rtb_Abs), GRM_HIL_P.Prelookup_Mach_BreakpointsData, 8U, &rtb_lat);

  /* DotProduct: '<S208>/Dot Product1' */
  rtb_Cx = (rtb_vBEB_a[0] * rtb_vBEB_a[0] + rtb_vBEB_a[1] * rtb_vBEB_a[1]) +
    rtb_vBEB_a[2] * rtb_vBEB_a[2];

  /* Math: '<S208>/Math Function1' incorporates:
   *  DotProduct: '<S208>/Dot Product1'
   *
   * About '<S208>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Cx < 0.0) {
    rtb_Add = -sqrt(fabs(rtb_Cx));
  } else {
    rtb_Add = sqrt(rtb_Cx);
  }

  /* End of Math: '<S208>/Math Function1' */

  /* Switch: '<S205>/Switch' incorporates:
   *  Constant: '<S205>/Constant'
   */
  if (rtb_Add != 0.0) {
    /* SignalConversion generated from: '<S205>/Vector Concatenate' */
    rtb_siB_h[3] = rtb_Add;

    /* SignalConversion generated from: '<S205>/Vector Concatenate' */
    rtb_siB_h[2] = rtb_vBEB_a[2];

    /* SignalConversion generated from: '<S205>/Vector Concatenate' */
    rtb_siB_h[1] = rtb_vBEB_a[1];

    /* SignalConversion generated from: '<S205>/Vector Concatenate' */
    rtb_siB_h[0] = rtb_vBEB_a[0];
  } else {
    rtb_siB_h[0] = GRM_HIL_P.Constant_Value_jc[0];
    rtb_siB_h[1] = GRM_HIL_P.Constant_Value_jc[1];
    rtb_siB_h[2] = GRM_HIL_P.Constant_Value_jc[2];
    rtb_siB_h[3] = GRM_HIL_P.Constant_Value_jc[3];
  }

  /* End of Switch: '<S205>/Switch' */

  /* Gain: '<S104>/Gain' incorporates:
   *  Trigonometry: '<S205>/Trigonometric Function'
   */
  rtb_Subtract_cl = GRM_HIL_P.Gain_Gain_nn * rt_atan2d_snf(rtb_siB_h[2],
    rtb_siB_h[0]);

  /* PreLookup: '<S99>/Prelookup_alB' */
  rtb_k_alB = plook_binc(rtb_Subtract_cl,
    GRM_HIL_P.Prelookup_alB_BreakpointsData, 16U, &rtb_Sqrt_j);

  /* Product: '<S205>/Divide' */
  u0 = rtb_siB_h[1] / rtb_siB_h[3];

  /* Trigonometry: '<S205>/Trigonometric Function1' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Gain: '<S105>/Gain' incorporates:
   *  Trigonometry: '<S205>/Trigonometric Function1'
   */
  rtb_Subtract_ju = GRM_HIL_P.Gain_Gain_kz * asin(u0);

  /* PreLookup: '<S99>/Prelookup_beB' */
  rtb_k_beB = plook_binc(rtb_Subtract_ju,
    GRM_HIL_P.Prelookup_beB_BreakpointsData, 16U, &rtb_f_beB);

  /* Interpolation_n-D: '<S96>/Cx_Interpolation' */
  frac[0] = rtb_lat;
  frac[1] = rtb_Sqrt_j;
  frac[2] = rtb_f_beB;
  bpIndex[0] = rtb_k_Mach;
  bpIndex[1] = rtb_k_alB;
  bpIndex[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex, frac, GRM_HIL_P.Cx_Interpolation_Table,
    GRM_HIL_P.Cx_Interpolation_dimSize);

  /* Product: '<S96>/Product' incorporates:
   *  Constant: '<S96>/Constant'
   */
  rtb_Cx = GRM_HIL_P.Constant_Value_i3 * rtb_siB_c5;

  /* Saturate: '<S206>/Saturation1' */
  if (rtb_VectorConcatenate_f_idx_0 > GRM_HIL_P.Saturation1_UpperSat) {
    rtb_Add = GRM_HIL_P.Saturation1_UpperSat;
  } else if (rtb_VectorConcatenate_f_idx_0 < GRM_HIL_P.Saturation1_LowerSat) {
    rtb_Add = GRM_HIL_P.Saturation1_LowerSat;
  } else {
    rtb_Add = rtb_VectorConcatenate_f_idx_0;
  }

  /* End of Saturate: '<S206>/Saturation1' */

  /* Product: '<S206>/Divide1' incorporates:
   *  Constant: '<S206>/Constant1'
   */
  rtb_siB_c5 = 1.0 / rtb_Add * GRM_HIL_P.Constant1_Value_is;

  /* Product: '<S206>/Product3' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  rtb_Product1_m[1] = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[11];

  /* Product: '<S206>/Product4' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  rtb_Product1_m[2] = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[12];

  /* Gain: '<S109>/Gain' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S206>/Product2'
   */
  rtb_Gain_g = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[10] *
    GRM_HIL_P.Gain_Gain_b;

  /* Interpolation_n-D: '<S96>/Cxp_Interpolation' */
  frac_0[0] = rtb_lat;
  frac_0[1] = rtb_Sqrt_j;
  frac_0[2] = rtb_f_beB;
  bpIndex_0[0] = rtb_k_Mach;
  bpIndex_0[1] = rtb_k_alB;
  bpIndex_0[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_0, frac_0, GRM_HIL_P.Cxp_Interpolation_Table,
    GRM_HIL_P.Cxp_Interpolation_dimSize);

  /* Product: '<S76>/Product' */
  rtb_Product_l = rtb_Gain_g * rtb_siB_c5;

  /* Gain: '<S110>/Gain' */
  rtb_Gain_lt = GRM_HIL_P.Gain_Gain_hp * rtb_Product1_m[1];

  /* Interpolation_n-D: '<S96>/Cxq_Interpolation' */
  frac_1[0] = rtb_lat;
  frac_1[1] = rtb_Sqrt_j;
  frac_1[2] = rtb_f_beB;
  bpIndex_1[0] = rtb_k_Mach;
  bpIndex_1[1] = rtb_k_alB;
  bpIndex_1[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_1, frac_1, GRM_HIL_P.Cxq_Interpolation_Table,
    GRM_HIL_P.Cxq_Interpolation_dimSize);

  /* Product: '<S76>/Product1' */
  rtb_Product1 = rtb_Gain_lt * rtb_siB_c5;

  /* Gain: '<S111>/Gain' */
  rtb_Gain_af = GRM_HIL_P.Gain_Gain_bz * rtb_Product1_m[2];

  /* Interpolation_n-D: '<S96>/Cxr_Interpolation' */
  frac_2[0] = rtb_lat;
  frac_2[1] = rtb_Sqrt_j;
  frac_2[2] = rtb_f_beB;
  bpIndex_2[0] = rtb_k_Mach;
  bpIndex_2[1] = rtb_k_alB;
  bpIndex_2[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_2, frac_2, GRM_HIL_P.Cxr_Interpolation_Table,
    GRM_HIL_P.Cxr_Interpolation_dimSize);

  /* Integrator: '<S129>/Integrator1' */
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
    /* Signum: '<S129>/Sign' incorporates:
     *  Constant: '<S58>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp_0 = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp_0 = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp_0 = 0.0;
    } else {
      rtb_Subtract_ay_tmp_0 = (rtNaN);
    }

    /* End of Signum: '<S129>/Sign' */

    /* Gain: '<S129>/Gain3' */
    GRM_HIL_B.Gain3 = GRM_HIL_P.Rudder_unc_bl * rtb_Subtract_ay_tmp_0;
  }

  /* Sum: '<S129>/Add2' incorporates:
   *  Constant: '<S129>/Constant'
   *  Gain: '<S129>/Gain1'
   *  Integrator: '<S129>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder_unc_scale * GRM_HIL_X.Integrator1_CSTATE +
        GRM_HIL_P.Rudder_unc_off) + GRM_HIL_B.Gain3;

  /* Saturate: '<S129>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder_siB_max) {
    rtb_siB = GRM_HIL_P.Rudder_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder_siB_min) {
    rtb_siB = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_siB = u0;
  }

  /* End of Saturate: '<S129>/Saturation1' */

  /* Integrator: '<S130>/Integrator1' */
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
    /* Signum: '<S130>/Sign' incorporates:
     *  Constant: '<S58>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp_0 = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp_0 = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp_0 = 0.0;
    } else {
      rtb_Subtract_ay_tmp_0 = (rtNaN);
    }

    /* End of Signum: '<S130>/Sign' */

    /* Gain: '<S130>/Gain3' */
    GRM_HIL_B.Gain3_m = GRM_HIL_P.Rudder1_unc_bl * rtb_Subtract_ay_tmp_0;
  }

  /* Sum: '<S130>/Add2' incorporates:
   *  Constant: '<S130>/Constant'
   *  Gain: '<S130>/Gain1'
   *  Integrator: '<S130>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder1_unc_scale * GRM_HIL_X.Integrator1_CSTATE_g +
        GRM_HIL_P.Rudder1_unc_off) + GRM_HIL_B.Gain3_m;

  /* Saturate: '<S130>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder1_siB_max) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder1_siB_min) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_siB_d = u0;
  }

  /* End of Saturate: '<S130>/Saturation1' */

  /* Integrator: '<S131>/Integrator1' */
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
    /* Signum: '<S131>/Sign' incorporates:
     *  Constant: '<S58>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp_0 = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp_0 = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp_0 = 0.0;
    } else {
      rtb_Subtract_ay_tmp_0 = (rtNaN);
    }

    /* End of Signum: '<S131>/Sign' */

    /* Gain: '<S131>/Gain3' */
    GRM_HIL_B.Gain3_b = GRM_HIL_P.Rudder2_unc_bl * rtb_Subtract_ay_tmp_0;
  }

  /* Sum: '<S131>/Add2' incorporates:
   *  Constant: '<S131>/Constant'
   *  Gain: '<S131>/Gain1'
   *  Integrator: '<S131>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder2_unc_scale * GRM_HIL_X.Integrator1_CSTATE_a +
        GRM_HIL_P.Rudder2_unc_off) + GRM_HIL_B.Gain3_b;

  /* Saturate: '<S131>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder2_siB_max) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder2_siB_min) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_siB_i = u0;
  }

  /* End of Saturate: '<S131>/Saturation1' */

  /* Integrator: '<S132>/Integrator1' */
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
    /* Signum: '<S132>/Sign' incorporates:
     *  Constant: '<S58>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Subtract_ay_tmp_0 = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Subtract_ay_tmp_0 = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Subtract_ay_tmp_0 = 0.0;
    } else {
      rtb_Subtract_ay_tmp_0 = (rtNaN);
    }

    /* End of Signum: '<S132>/Sign' */

    /* Gain: '<S132>/Gain3' */
    GRM_HIL_B.Gain3_h = GRM_HIL_P.Rudder3_unc_bl * rtb_Subtract_ay_tmp_0;
  }

  /* Sum: '<S132>/Add2' incorporates:
   *  Constant: '<S132>/Constant'
   *  Gain: '<S132>/Gain1'
   *  Integrator: '<S132>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder3_unc_scale * GRM_HIL_X.Integrator1_CSTATE_i +
        GRM_HIL_P.Rudder3_unc_off) + GRM_HIL_B.Gain3_h;

  /* Saturate: '<S132>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder3_siB_max) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder3_siB_min) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_min;
  } else {
    rtb_siB_o = u0;
  }

  /* End of Saturate: '<S132>/Saturation1' */

  /* Product: '<S133>/Product' incorporates:
   *  Constant: '<S133>/Constant8'
   *  SignalConversion generated from: '<S58>/Vector Concatenate1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain_fl = GRM_HIL_P.Constant8_Value_g2[i + 9] * rtb_siB_o +
      (GRM_HIL_P.Constant8_Value_g2[i + 6] * rtb_siB_i +
       (GRM_HIL_P.Constant8_Value_g2[i + 3] * rtb_siB_d +
        GRM_HIL_P.Constant8_Value_g2[i] * rtb_siB));
    rtb_Product1_m[i] = rtb_Gain_fl;
  }

  /* End of Product: '<S133>/Product' */

  /* Gain: '<S106>/Gain' */
  rtb_Gain_fl = GRM_HIL_P.Gain_Gain_aj * rtb_Product1_m[0];

  /* Interpolation_n-D: '<S96>/Cx_delta_l_Interpolation' */
  frac_3[0] = rtb_lat;
  frac_3[1] = rtb_Sqrt_j;
  frac_3[2] = rtb_f_beB;
  bpIndex_3[0] = rtb_k_Mach;
  bpIndex_3[1] = rtb_k_alB;
  bpIndex_3[2] = rtb_k_beB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_3, frac_3,
    GRM_HIL_P.Cx_delta_l_Interpolation_Table,
    GRM_HIL_P.Cx_delta_l_Interpolation_dimSize);

  /* Product: '<S76>/Product3' */
  rtb_Product3_hu = rtb_Gain_fl * rtb_Product7_ma;

  /* Gain: '<S107>/Gain' */
  rtb_Gain_nk = GRM_HIL_P.Gain_Gain_l4 * rtb_Product1_m[1];

  /* Interpolation_n-D: '<S96>/Cx_delta_m_Interpolation' */
  frac_4[0] = rtb_lat;
  frac_4[1] = rtb_Sqrt_j;
  frac_4[2] = rtb_f_beB;
  bpIndex_4[0] = rtb_k_Mach;
  bpIndex_4[1] = rtb_k_alB;
  bpIndex_4[2] = rtb_k_beB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_4, frac_4,
    GRM_HIL_P.Cx_delta_m_Interpolation_Table,
    GRM_HIL_P.Cx_delta_m_Interpolation_dimSize);

  /* Product: '<S76>/Product4' */
  rtb_Product4_e = rtb_Gain_nk * rtb_Product7_ma;

  /* Gain: '<S108>/Gain' */
  rtb_Gain_n = GRM_HIL_P.Gain_Gain_pr * rtb_Product1_m[2];

  /* Interpolation_n-D: '<S96>/Cx_delta_n_Interpolation' */
  frac_5[0] = rtb_lat;
  frac_5[1] = rtb_Sqrt_j;
  frac_5[2] = rtb_f_beB;
  bpIndex_5[0] = rtb_k_Mach;
  bpIndex_5[1] = rtb_k_alB;
  bpIndex_5[2] = rtb_k_beB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_5, frac_5,
    GRM_HIL_P.Cx_delta_n_Interpolation_Table,
    GRM_HIL_P.Cx_delta_n_Interpolation_dimSize);

  /* Product: '<S76>/Product5' */
  rtb_Product5 = rtb_Gain_n * rtb_Product7_ma;

  /* Interpolation_n-D: '<S96>/Cx_alt_Interpolation' incorporates:
   *  PreLookup: '<S96>/Prelookup_altitude'
   */
  bpIndex_6[2] = plook_binc(GRM_HIL_B.Switch[2],
    GRM_HIL_P.Prelookup_altitude_BreakpointsData, 19U, &rtb_Product7_ma);
  frac_6[0] = rtb_lat;
  frac_6[1] = rtb_Sqrt_j;
  frac_6[2] = rtb_Product7_ma;
  bpIndex_6[0] = rtb_k_Mach;
  bpIndex_6[1] = rtb_k_alB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_6, frac_6,
    GRM_HIL_P.Cx_alt_Interpolation_Table, GRM_HIL_P.Cx_alt_Interpolation_dimSize);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sqrt: '<S100>/Sqrt' incorporates:
     *  Constant: '<S100>/Constant3'
     */
    GRM_HIL_B.Sqrt = sqrt(GRM_HIL_P.Constant3_Value_f);
  }

  /* Gain: '<S103>/Gain' incorporates:
   *  Gain: '<S101>/Gain1'
   *  Gain: '<S102>/Gain1'
   *  Product: '<S100>/Product1'
   *  Trigonometry: '<S100>/Trigonometric Function'
   *  Trigonometry: '<S100>/Trigonometric Function1'
   *  Trigonometry: '<S100>/Trigonometric Function2'
   */
  u0 = acos(cos(GRM_HIL_P.Gain1_Gain_b * rtb_Subtract_cl) * cos
            (GRM_HIL_P.Gain1_Gain_e2 * rtb_Subtract_ju)) *
    GRM_HIL_P.Gain_Gain_if;

  /* Saturate: '<S100>/Saturation' */
  if (u0 > GRM_HIL_P.Saturation_UpperSat_f) {
    u0 = GRM_HIL_P.Saturation_UpperSat_f;
  } else {
    if (u0 < GRM_HIL_P.Saturation_LowerSat_g) {
      u0 = GRM_HIL_P.Saturation_LowerSat_g;
    }
  }

  /* End of Saturate: '<S100>/Saturation' */

  /* Abs: '<S100>/Abs2' incorporates:
   *  Abs: '<S100>/Abs'
   *  Abs: '<S100>/Abs1'
   *  Product: '<S100>/Divide2'
   *  Product: '<S100>/Product6'
   *  Product: '<S100>/Product7'
   *  Sum: '<S100>/Add'
   */
  rtb_Product6_n4 = fabs((fabs(rtb_Subtract_cl) * rtb_Gain_nk + fabs
    (rtb_Subtract_ju) * rtb_Gain_n) * GRM_HIL_B.Sqrt / u0);

  /* Interpolation_n-D: '<S96>/Cx_delta_t_Interpolation' incorporates:
   *  PreLookup: '<S96>/Prelookup_delta_t'
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

  /* Interpolation_n-D: '<S96>/Cx_base_Interpolation' */
  frac_8[0] = rtb_lat;
  frac_8[1] = rtb_Sqrt_j;
  frac_8[2] = rtb_f_beB;
  bpIndex_8[0] = rtb_k_Mach;
  bpIndex_8[1] = rtb_k_alB;
  bpIndex_8[2] = rtb_k_beB;
  rtb_Subtract_ju = intrp3d_l_pw(bpIndex_8, frac_8,
    GRM_HIL_P.Cx_base_Interpolation_Table,
    GRM_HIL_P.Cx_base_Interpolation_dimSize);

  /* Clock: '<S210>/Clock' incorporates:
   *  Derivative: '<S163>/Derivative'
   *  Derivative: '<S163>/Derivative1'
   */
  rtb_Add = GRM_HIL_M->Timing.t[0];

  /* Sum: '<S75>/Subtract' incorporates:
   *  Clock: '<S210>/Clock'
   *  Constant: '<S210>/Constant6'
   *  Sum: '<S172>/Subtract'
   *  Sum: '<S68>/Subtract'
   */
  rtb_Subtract_ay_tmp_0 = rtb_Add - GRM_HIL_P.Constant6_Value_i;

  /* Sum: '<S76>/Add' incorporates:
   *  Constant: '<S75>/Constant'
   *  MATLAB Function: '<S75>/MATLAB Function'
   *  Product: '<S76>/Product2'
   *  Product: '<S76>/Product8'
   *  Sum: '<S75>/Subtract'
   */
  rtb_Product1_m[0] = ((((((((rtb_Cx + rtb_Product_l) + rtb_Product1) +
    rtb_Gain_af * rtb_siB_c5) + rtb_Product3_hu) + rtb_Product4_e) +
    rtb_Product5) + rtb_Product7_ma) + rtb_Product6_n4) + (real_T)
    ((!(rtb_Subtract_ay_tmp_0 >= 0.0)) || (!(rtb_Subtract_ay_tmp_0 <=
       GRM_HIL_P.Constant_Value_ok))) * rtb_Subtract_ju;

  /* Interpolation_n-D: '<S97>/Cy_Interpolation' */
  frac_9[0] = rtb_lat;
  frac_9[1] = rtb_Sqrt_j;
  frac_9[2] = rtb_f_beB;
  bpIndex_9[0] = rtb_k_Mach;
  bpIndex_9[1] = rtb_k_alB;
  bpIndex_9[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_9, frac_9,
    GRM_HIL_P.Cy_Interpolation_Table, GRM_HIL_P.Cy_Interpolation_dimSize);

  /* Product: '<S97>/Product' incorporates:
   *  Constant: '<S97>/Constant'
   */
  rtb_siB_c5 = GRM_HIL_P.Constant_Value_oz * rtb_Product6_n4;

  /* Interpolation_n-D: '<S97>/Cyp_Interpolation' */
  frac_a[0] = rtb_lat;
  frac_a[1] = rtb_Sqrt_j;
  frac_a[2] = rtb_f_beB;
  bpIndex_a[0] = rtb_k_Mach;
  bpIndex_a[1] = rtb_k_alB;
  bpIndex_a[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_a, frac_a,
    GRM_HIL_P.Cyp_Interpolation_Table, GRM_HIL_P.Cyp_Interpolation_dimSize);

  /* Product: '<S76>/Product6' */
  rtb_Cx = rtb_Gain_g * rtb_Product6_n4;

  /* Interpolation_n-D: '<S97>/Cyq_Interpolation' */
  frac_b[0] = rtb_lat;
  frac_b[1] = rtb_Sqrt_j;
  frac_b[2] = rtb_f_beB;
  bpIndex_b[0] = rtb_k_Mach;
  bpIndex_b[1] = rtb_k_alB;
  bpIndex_b[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_b, frac_b,
    GRM_HIL_P.Cyq_Interpolation_Table, GRM_HIL_P.Cyq_Interpolation_dimSize);

  /* Product: '<S76>/Product7' */
  rtb_Product7_ma = rtb_Gain_lt * rtb_Product6_n4;

  /* Interpolation_n-D: '<S97>/Cyr_Interpolation' */
  frac_c[0] = rtb_lat;
  frac_c[1] = rtb_Sqrt_j;
  frac_c[2] = rtb_f_beB;
  bpIndex_c[0] = rtb_k_Mach;
  bpIndex_c[1] = rtb_k_alB;
  bpIndex_c[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_c, frac_c,
    GRM_HIL_P.Cyr_Interpolation_Table, GRM_HIL_P.Cyr_Interpolation_dimSize);

  /* Product: '<S76>/Product9' */
  rtb_Subtract_ju = rtb_Gain_af * rtb_Product6_n4;

  /* Interpolation_n-D: '<S97>/Cy_delta_l_Interpolation' */
  frac_d[0] = rtb_lat;
  frac_d[1] = rtb_Sqrt_j;
  frac_d[2] = rtb_f_beB;
  bpIndex_d[0] = rtb_k_Mach;
  bpIndex_d[1] = rtb_k_alB;
  bpIndex_d[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_d, frac_d,
    GRM_HIL_P.Cy_delta_l_Interpolation_Table,
    GRM_HIL_P.Cy_delta_l_Interpolation_dimSize);

  /* Product: '<S76>/Product10' */
  rtb_Subtract_cl = rtb_Gain_fl * rtb_Product6_n4;

  /* Interpolation_n-D: '<S97>/Cy_delta_m_Interpolation' */
  frac_e[0] = rtb_lat;
  frac_e[1] = rtb_Sqrt_j;
  frac_e[2] = rtb_f_beB;
  bpIndex_e[0] = rtb_k_Mach;
  bpIndex_e[1] = rtb_k_alB;
  bpIndex_e[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_e, frac_e,
    GRM_HIL_P.Cy_delta_m_Interpolation_Table,
    GRM_HIL_P.Cy_delta_m_Interpolation_dimSize);

  /* Product: '<S76>/Product11' */
  rtb_Product_l = rtb_Gain_nk * rtb_Product6_n4;

  /* Interpolation_n-D: '<S97>/Cy_delta_n_Interpolation' */
  frac_f[0] = rtb_lat;
  frac_f[1] = rtb_Sqrt_j;
  frac_f[2] = rtb_f_beB;
  bpIndex_f[0] = rtb_k_Mach;
  bpIndex_f[1] = rtb_k_alB;
  bpIndex_f[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_f, frac_f,
    GRM_HIL_P.Cy_delta_n_Interpolation_Table,
    GRM_HIL_P.Cy_delta_n_Interpolation_dimSize);

  /* Sum: '<S76>/Add1' incorporates:
   *  Product: '<S76>/Product12'
   */
  rtb_Product1_m[1] = (((((rtb_siB_c5 + rtb_Cx) + rtb_Product7_ma) +
    rtb_Subtract_ju) + rtb_Subtract_cl) + rtb_Product_l) + rtb_Gain_n *
    rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Cz_Interpolation' */
  frac_g[0] = rtb_lat;
  frac_g[1] = rtb_Sqrt_j;
  frac_g[2] = rtb_f_beB;
  bpIndex_g[0] = rtb_k_Mach;
  bpIndex_g[1] = rtb_k_alB;
  bpIndex_g[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_g, frac_g,
    GRM_HIL_P.Cz_Interpolation_Table, GRM_HIL_P.Cz_Interpolation_dimSize);

  /* Product: '<S98>/Product' incorporates:
   *  Constant: '<S98>/Constant'
   */
  rtb_siB_c5 = GRM_HIL_P.Constant_Value_gw * rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Czp_Interpolation' */
  frac_h[0] = rtb_lat;
  frac_h[1] = rtb_Sqrt_j;
  frac_h[2] = rtb_f_beB;
  bpIndex_h[0] = rtb_k_Mach;
  bpIndex_h[1] = rtb_k_alB;
  bpIndex_h[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_h, frac_h,
    GRM_HIL_P.Czp_Interpolation_Table, GRM_HIL_P.Czp_Interpolation_dimSize);

  /* Product: '<S76>/Product16' */
  rtb_Cx = rtb_Gain_g * rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Czq_Interpolation' */
  frac_i[0] = rtb_lat;
  frac_i[1] = rtb_Sqrt_j;
  frac_i[2] = rtb_f_beB;
  bpIndex_i[0] = rtb_k_Mach;
  bpIndex_i[1] = rtb_k_alB;
  bpIndex_i[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_i, frac_i,
    GRM_HIL_P.Czq_Interpolation_Table, GRM_HIL_P.Czq_Interpolation_dimSize);

  /* Product: '<S76>/Product17' */
  rtb_Product7_ma = rtb_Gain_lt * rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Czr_Interpolation' */
  frac_j[0] = rtb_lat;
  frac_j[1] = rtb_Sqrt_j;
  frac_j[2] = rtb_f_beB;
  bpIndex_j[0] = rtb_k_Mach;
  bpIndex_j[1] = rtb_k_alB;
  bpIndex_j[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_j, frac_j,
    GRM_HIL_P.Czr_Interpolation_Table, GRM_HIL_P.Czr_Interpolation_dimSize);

  /* Product: '<S76>/Product18' */
  rtb_Subtract_ju = rtb_Gain_af * rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Cz_delta_l_Interpolation' */
  frac_k[0] = rtb_lat;
  frac_k[1] = rtb_Sqrt_j;
  frac_k[2] = rtb_f_beB;
  bpIndex_k[0] = rtb_k_Mach;
  bpIndex_k[1] = rtb_k_alB;
  bpIndex_k[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_k, frac_k,
    GRM_HIL_P.Cz_delta_l_Interpolation_Table,
    GRM_HIL_P.Cz_delta_l_Interpolation_dimSize);

  /* Product: '<S76>/Product13' */
  rtb_Subtract_cl = rtb_Gain_fl * rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Cz_delta_m_Interpolation' */
  frac_l[0] = rtb_lat;
  frac_l[1] = rtb_Sqrt_j;
  frac_l[2] = rtb_f_beB;
  bpIndex_l[0] = rtb_k_Mach;
  bpIndex_l[1] = rtb_k_alB;
  bpIndex_l[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_l, frac_l,
    GRM_HIL_P.Cz_delta_m_Interpolation_Table,
    GRM_HIL_P.Cz_delta_m_Interpolation_dimSize);

  /* Product: '<S76>/Product14' */
  rtb_Product_l = rtb_Gain_nk * rtb_Product6_n4;

  /* Interpolation_n-D: '<S98>/Cz_delta_n_Interpolation' */
  frac_m[0] = rtb_lat;
  frac_m[1] = rtb_Sqrt_j;
  frac_m[2] = rtb_f_beB;
  bpIndex_m[0] = rtb_k_Mach;
  bpIndex_m[1] = rtb_k_alB;
  bpIndex_m[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_m, frac_m,
    GRM_HIL_P.Cz_delta_n_Interpolation_Table,
    GRM_HIL_P.Cz_delta_n_Interpolation_dimSize);

  /* Sum: '<S76>/Add2' incorporates:
   *  Product: '<S76>/Product15'
   */
  rtb_Product1_m[2] = (((((rtb_siB_c5 + rtb_Cx) + rtb_Product7_ma) +
    rtb_Subtract_ju) + rtb_Subtract_cl) + rtb_Product_l) + rtb_Gain_n *
    rtb_Product6_n4;

  /* Sum: '<S128>/Add' incorporates:
   *  Constant: '<S128>/Constant1'
   *  Constant: '<S128>/Tmp_gradient_tropo'
   *  Product: '<S128>/Divide'
   */
  rtb_Product6_n4 = rtb_Step1 / GRM_HIL_B.Tmp_ref *
    GRM_HIL_P.Tmp_gradient_tropo_Value_l + GRM_HIL_P.Constant1_Value_mh;

  /* Math: '<S128>/Math Function' incorporates:
   *  Constant: '<S128>/pressure_exponent'
   */
  if ((rtb_Product6_n4 < 0.0) && (GRM_HIL_P.pressure_exponent_Value > floor
       (GRM_HIL_P.pressure_exponent_Value))) {
    rtb_Product6_n4 = -rt_powd_snf(-rtb_Product6_n4,
      GRM_HIL_P.pressure_exponent_Value);
  } else {
    rtb_Product6_n4 = rt_powd_snf(rtb_Product6_n4,
      GRM_HIL_P.pressure_exponent_Value);
  }

  /* End of Math: '<S128>/Math Function' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S126>/Subtract2' incorporates:
     *  Constant: '<S126>/pa_norm_msl'
     *  Constant: '<S211>/deviation_pa_QFH'
     */
    GRM_HIL_B.pa_ref = GRM_HIL_P.deviation_pa_QFH_Value +
      GRM_HIL_P.pa_norm_msl_Value;
  }

  /* Product: '<S77>/Product2' incorporates:
   *  Constant: '<S123>/specific_gas_constant'
   *  Constant: '<S203>/Constant'
   *  Constant: '<S77>/Constant2'
   *  Math: '<S203>/Math Function1'
   *  Product: '<S123>/Divide'
   *  Product: '<S128>/Product'
   *  Product: '<S203>/Product1'
   */
  rtb_Abs = 1.0 / rtb_Abs * (rtb_Product6_n4 * GRM_HIL_B.pa_ref) /
    GRM_HIL_P.specific_gas_constant_Value_c * (rtb_VectorConcatenate_f_idx_0 *
    rtb_VectorConcatenate_f_idx_0 * GRM_HIL_P.Constant_Value_ii) *
    GRM_HIL_P.Constant2_Value_a2;

  /* Product: '<S77>/Product' */
  frac[0] = rtb_Product1_m[0] * rtb_Abs;
  frac[1] = rtb_Product1_m[1] * rtb_Abs;
  frac[2] = rtb_Product1_m[2] * rtb_Abs;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
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
    if (GRM_HIL_P.Constant2_Value_o > GRM_HIL_P.Switch1_Threshold) {
      GRM_HIL_B.hBE_0 = GRM_HIL_P.Gain_Gain_i * GRM_HIL_P.Constant_Value_iu[2];
    } else {
      /* Sqrt: '<S88>/Sqrt' incorporates:
       *  Constant: '<S85>/Constant'
       *  Product: '<S88>/Product1'
       *  Product: '<S88>/Product2'
       *  Sqrt: '<S87>/Sqrt'
       *  Sum: '<S88>/Add'
       */
      rtb_Product6_n4 = sqrt(GRM_HIL_P.Constant_Value_iu[0] *
        GRM_HIL_P.Constant_Value_iu[0] + GRM_HIL_P.Constant_Value_iu[1] *
        GRM_HIL_P.Constant_Value_iu[1]);

      /* Product: '<S88>/Product' incorporates:
       *  Constant: '<S86>/c_flat'
       *  Constant: '<S86>/c_rsma'
       *  Constant: '<S88>/Constant'
       *  Sum: '<S88>/Subtract'
       */
      rtb_siB_c5 = (GRM_HIL_P.Constant_Value_g - GRM_HIL_P.c_flat_Value) *
        GRM_HIL_P.c_rsma_Value;

      /* Trigonometry: '<S88>/Trigonometric Function' incorporates:
       *  Constant: '<S85>/Constant'
       *  Constant: '<S86>/c_rsma'
       *  Product: '<S88>/Divide1'
       *  Product: '<S88>/Product6'
       *  Product: '<S88>/Product7'
       *  Sqrt: '<S88>/Sqrt'
       */
      rtb_Cx = atan(GRM_HIL_P.Constant_Value_iu[2] * GRM_HIL_P.c_rsma_Value /
                    (rtb_Product6_n4 * rtb_siB_c5));

      /* Trigonometry: '<S88>/Trigonometric Function3' */
      rtb_Product7_ma = cos(rtb_Cx);

      /* Product: '<S88>/Product9' */
      rtb_VectorConcatenate_f_idx_0 = rtb_Product7_ma * rtb_Product7_ma *
        rtb_Product7_ma;

      /* Trigonometry: '<S88>/Trigonometric Function2' */
      rtb_Cx = sin(rtb_Cx);

      /* Product: '<S88>/Product5' */
      rtb_Product7_ma = rtb_siB_c5 * rtb_siB_c5;

      /* Product: '<S88>/Product10' incorporates:
       *  Constant: '<S86>/c_rsma'
       *  Product: '<S88>/Divide'
       *  Product: '<S88>/Product4'
       *  Product: '<S88>/Product8'
       *  Sum: '<S88>/Subtract2'
       */
      rtb_siB_c5 = (GRM_HIL_P.c_rsma_Value * GRM_HIL_P.c_rsma_Value -
                    rtb_Product7_ma) / rtb_Product7_ma * rtb_siB_c5 * (rtb_Cx *
        rtb_Cx * rtb_Cx);

      /* Sum: '<S88>/Add1' incorporates:
       *  Constant: '<S85>/Constant'
       */
      rtb_siB_c5 += GRM_HIL_P.Constant_Value_iu[2];

      /* Product: '<S88>/Product3' incorporates:
       *  Constant: '<S86>/c_flat'
       *  Product: '<S87>/Product3'
       */
      rtb_Product_l = GRM_HIL_P.c_flat_Value * GRM_HIL_P.c_flat_Value;

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
      rtb_Product7_ma = atan(rtb_siB_c5 / (rtb_Product6_n4 -
        (GRM_HIL_P.Gain_Gain_c * GRM_HIL_P.c_flat_Value - rtb_Product_l) *
        GRM_HIL_P.c_rsma_Value * rtb_VectorConcatenate_f_idx_0));

      /* Trigonometry: '<S87>/Trigonometric Function' */
      rtb_Cx = sin(rtb_Product7_ma);
      GRM_HIL_B.hBE_0 = rtb_Product6_n4 / cos(rtb_Product7_ma) -
        GRM_HIL_P.c_rsma_Value / sqrt(GRM_HIL_P.Constant_Value_j -
        (GRM_HIL_P.Gain_Gain * GRM_HIL_P.c_flat_Value - rtb_Product_l) * (rtb_Cx
        * rtb_Cx));
    }

    /* End of Switch: '<S85>/Switch1' */

    /* SignalConversion generated from: '<S83>/Vector Concatenate' incorporates:
     *  Constant: '<S83>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[0] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S83>/Vector Concatenate' incorporates:
     *  Constant: '<S83>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[1] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S83>/Vector Concatenate' incorporates:
     *  Constant: '<S83>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[2] = GRM_HIL_P.Constant3_Value_f4;
  }

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant1'
   *  Sum: '<S83>/Subtract'
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

  /* End of Switch: '<S83>/Switch' */

  /* Saturate: '<S57>/Saturation' */
  if (GRM_HIL_B.Switch[2] > GRM_HIL_P.Saturation_UpperSat_d) {
    rtb_Product6_n4 = GRM_HIL_P.Saturation_UpperSat_d;
  } else if (GRM_HIL_B.Switch[2] < GRM_HIL_P.Saturation_LowerSat_j) {
    rtb_Product6_n4 = GRM_HIL_P.Saturation_LowerSat_j;
  } else {
    rtb_Product6_n4 = GRM_HIL_B.Switch[2];
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Trigonometry: '<S121>/Trigonometric Function' incorporates:
   *  Switch: '<S163>/Switch'
   *  Trigonometry: '<S119>/Trigonometric Function2'
   *  Trigonometry: '<S163>/Trigonometric Function'
   */
  rtb_siB_c5 = sin(GRM_HIL_B.Switch[1]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S122>/Divide' incorporates:
     *  Constant: '<S121>/WGS84 Semi-major Axis, [m]'
     *  Constant: '<S121>/WGS84 Semi-minor Axis, [m]'
     *  Sum: '<S122>/Add'
     */
    rtb_e = (GRM_HIL_P.WGS84SemimajorAxism_Value -
             GRM_HIL_P.WGS84SemiminorAxism_Value) /
      GRM_HIL_P.WGS84SemimajorAxism_Value;

    /* Product: '<S122>/Divide1' incorporates:
     *  Constant: '<S122>/a2'
     *  Sum: '<S122>/Add1'
     */
    rtb_e *= GRM_HIL_P.a2_Value - rtb_e;

    /* Sqrt: '<S122>/Sqrt' */
    rtb_e = sqrt(rtb_e);

    /* Product: '<S121>/Divide' */
    GRM_HIL_B.e2 = rtb_e * rtb_e;

    /* Sum: '<S119>/Add1' incorporates:
     *  Constant: '<S119>/Constant'
     *  Product: '<S119>/Divide2'
     */
    GRM_HIL_B.Add1 = GRM_HIL_P.Constant_Value_ov - rtb_e * rtb_e;
  }

  /* Product: '<S121>/Divide3' incorporates:
   *  Constant: '<S121>/WGS84 Semi-major Axis, [m]'
   *  Constant: '<S121>/a3'
   *  Product: '<S121>/Divide1'
   *  Product: '<S121>/Divide2'
   *  Sqrt: '<S121>/Sqrt'
   *  Sum: '<S121>/Add2'
   *  Trigonometry: '<S121>/Trigonometric Function'
   */
  rtb_Product7_ma = 1.0 / sqrt(GRM_HIL_P.a3_Value - rtb_siB_c5 * rtb_siB_c5 *
    GRM_HIL_B.e2) * GRM_HIL_P.WGS84SemimajorAxism_Value;

  /* Sum: '<S119>/Add3' */
  rtb_Subtract_ju = rtb_Product6_n4 + rtb_Product7_ma;

  /* Trigonometry: '<S119>/Trigonometric Function3' incorporates:
   *  Switch: '<S163>/Switch'
   *  Trigonometry: '<S163>/Trigonometric Function1'
   */
  rtb_Cx = cos(GRM_HIL_B.Switch[1]);

  /* Trigonometry: '<S119>/Trigonometric Function1' incorporates:
   *  MATLAB Function: '<S113>/WGS84_Gravity_Implementation'
   */
  frac_tmp = cos(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S120>/ SFunction ' incorporates:
   *  MATLAB Function: '<S113>/WGS84_Gravity_Implementation'
   *  Product: '<S119>/Divide'
   *  Trigonometry: '<S119>/Trigonometric Function1'
   *  Trigonometry: '<S119>/Trigonometric Function3'
   */
  frac_0[0] = rtb_Subtract_ju * frac_tmp * rtb_Cx;

  /* Trigonometry: '<S119>/Trigonometric Function' incorporates:
   *  MATLAB Function: '<S113>/WGS84_Gravity_Implementation'
   */
  frac_tmp_0 = sin(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S120>/ SFunction ' incorporates:
   *  MATLAB Function: '<S113>/WGS84_Gravity_Implementation'
   *  Product: '<S119>/Divide1'
   *  Product: '<S119>/Divide3'
   *  Product: '<S119>/Divide4'
   *  Sum: '<S119>/Add2'
   *  Trigonometry: '<S119>/Trigonometric Function'
   *  Trigonometry: '<S119>/Trigonometric Function3'
   */
  frac_0[1] = rtb_Subtract_ju * frac_tmp_0 * rtb_Cx;
  frac_0[2] = (rtb_Product7_ma * GRM_HIL_B.Add1 + rtb_Product6_n4) * rtb_siB_c5;

  /* MATLAB Function: '<S113>/WGS84_Gravity_Implementation' */
  rtb_Product_l = GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS;
  rtb_Product3_hu = GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma;
  rtb_Product7_ma = sqrt(rtb_Product3_hu - rtb_Product_l);
  rtb_Product4_e = rtb_Product7_ma * rtb_Product7_ma;
  rtb_Gain1_n4_tmp = frac_0[2] * frac_0[2];
  rtb_e = frac_0[0] * frac_0[0] + frac_0[1] * frac_0[1];
  rtb_Subtract_ju = (rtb_e + rtb_Gain1_n4_tmp) - rtb_Product4_e;
  rtb_VectorConcatenate_f_idx_0 = sqrt((sqrt(rtb_Product4_e * 4.0 *
    rtb_Gain1_n4_tmp / (rtb_Subtract_ju * rtb_Subtract_ju) + 1.0) + 1.0) *
    (rtb_Subtract_ju * 0.5));
  u0 = rtb_VectorConcatenate_f_idx_0 * rtb_VectorConcatenate_f_idx_0;
  rtb_Step1_tmp = u0 + rtb_Product4_e;
  rtb_Step1 = sqrt(rtb_Step1_tmp);
  rtb_e = rt_atan2d_snf(frac_0[2] * rtb_Step1, sqrt(rtb_e) *
                        rtb_VectorConcatenate_f_idx_0);
  rtb_Subtract_ju = sin(rtb_e);
  rtb_Subtract_ay_tmp = rtb_Subtract_ju * rtb_Subtract_ju;
  rtb_Subtract_cl = sqrt((rtb_Product4_e * rtb_Subtract_ay_tmp + u0) /
    rtb_Step1_tmp);
  rtb_Product_l = ((rtb_Product_l * 3.0 / rtb_Product4_e + 1.0) * rt_atan2d_snf
                   (rtb_Product7_ma,
                    GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS) - 3.0 *
                   GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS /
                   rtb_Product7_ma) * 0.5;
  rtb_Product1 = cos(rtb_e);
  rtb_Product5 = rt_atan2d_snf(rtb_Product7_ma, rtb_VectorConcatenate_f_idx_0);
  rtb_TBG[0] = rtb_VectorConcatenate_f_idx_0 / (rtb_Subtract_cl * rtb_Step1) *
    rtb_Product1 * frac_tmp;
  rtb_TBG[3] = -1.0 / rtb_Subtract_cl * rtb_Subtract_ju * frac_tmp;
  rtb_TBG[6] = -frac_tmp_0;
  rtb_Gain1_n4_tmp = rtb_VectorConcatenate_f_idx_0 / (sqrt
    (rtb_VectorConcatenate_f_idx_0 * rtb_VectorConcatenate_f_idx_0 +
     rtb_Product7_ma * rtb_Product7_ma) * rtb_Subtract_cl) * cos(rtb_e);
  rtb_TBG[1] = rtb_Gain1_n4_tmp * frac_tmp_0;
  rtb_TBG[4] = -1.0 / rtb_Subtract_cl * sin(rtb_e) * frac_tmp_0;
  rtb_TBG[7] = frac_tmp;
  rtb_TBG[2] = 1.0 / rtb_Subtract_cl * rtb_Subtract_ju;
  rtb_TBG[5] = rtb_Gain1_n4_tmp;
  rtb_TBG[8] = 0.0;
  rtb_e = GRM_HIL_P.WGS84_Gravity_Implementation_c_rot *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rot;
  frac_tmp = GRM_HIL_P.WGS84_Gravitation_flg_omega_enabled / rtb_Subtract_cl *
    rtb_e;
  frac_tmp_0 = (((u0 / rtb_Product4_e + 1.0) * 3.0 * (1.0 -
    rtb_VectorConcatenate_f_idx_0 / rtb_Product7_ma * rtb_Product5) - 1.0) *
                (rtb_e * rtb_Product3_hu * rtb_Product7_ma / rtb_Step1_tmp) /
                rtb_Product_l * (rtb_Subtract_ay_tmp * 0.5 - 0.16666666666666666)
                + GRM_HIL_P.WGS84_Gravity_Implementation_c_grav / rtb_Step1_tmp)
    * (-1.0 / rtb_Subtract_cl) + frac_tmp * rtb_VectorConcatenate_f_idx_0 *
    (rtb_Product1 * rtb_Product1);
  rtb_e = ((u0 * 3.0 / rtb_Product4_e + 1.0) * rtb_Product5 - 3.0 *
           rtb_VectorConcatenate_f_idx_0 / rtb_Product7_ma) * 0.5 * (1.0 /
    rtb_Subtract_cl * rtb_e * rtb_Product3_hu / rtb_Step1_tmp) / rtb_Product_l *
    rtb_Subtract_ju * rtb_Product1 - frac_tmp * rtb_Step1 * rtb_Subtract_ju *
    rtb_Product1;
  for (i = 0; i < 3; i++) {
    frac_0[i] = rtb_TBG[i + 6] * 0.0 + (rtb_TBG[i + 3] * rtb_e + rtb_TBG[i] *
      frac_tmp_0);
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S143>/Switch1' incorporates:
     *  Constant: '<S143>/Constant'
     *  Constant: '<S143>/Constant2'
     *  Constant: '<S144>/c_flat'
     *  Constant: '<S144>/c_rsma'
     *  Constant: '<S145>/Constant'
     *  Gain: '<S143>/Gain'
     *  Gain: '<S145>/Gain'
     *  Product: '<S145>/Product'
     *  Product: '<S145>/Product4'
     *  Product: '<S145>/Product5'
     *  Sqrt: '<S145>/Sqrt1'
     *  Sum: '<S145>/Subtract'
     *  Sum: '<S145>/Subtract1'
     *  Sum: '<S145>/Sum'
     *  Trigonometry: '<S145>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_id > GRM_HIL_P.Switch1_Threshold_d) {
      GRM_HIL_B.hBE_0_l = GRM_HIL_P.Gain_Gain_g * GRM_HIL_P.Constant_Value_g4[2];
    } else {
      /* Sqrt: '<S146>/Sqrt' incorporates:
       *  Constant: '<S143>/Constant'
       *  Product: '<S146>/Product1'
       *  Product: '<S146>/Product2'
       *  Sqrt: '<S145>/Sqrt'
       *  Sum: '<S146>/Add'
       */
      rtb_Product7_ma = sqrt(GRM_HIL_P.Constant_Value_g4[0] *
        GRM_HIL_P.Constant_Value_g4[0] + GRM_HIL_P.Constant_Value_g4[1] *
        GRM_HIL_P.Constant_Value_g4[1]);

      /* Product: '<S146>/Product' incorporates:
       *  Constant: '<S144>/c_flat'
       *  Constant: '<S144>/c_rsma'
       *  Constant: '<S146>/Constant'
       *  Sum: '<S146>/Subtract'
       */
      rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_P.Constant_Value_e -
        GRM_HIL_P.c_flat_Value_c) * GRM_HIL_P.c_rsma_Value_m;

      /* Trigonometry: '<S146>/Trigonometric Function' incorporates:
       *  Constant: '<S143>/Constant'
       *  Constant: '<S144>/c_rsma'
       *  Product: '<S146>/Divide1'
       *  Product: '<S146>/Product6'
       *  Product: '<S146>/Product7'
       *  Sqrt: '<S146>/Sqrt'
       */
      rtb_Step1 = atan(GRM_HIL_P.Constant_Value_g4[2] * GRM_HIL_P.c_rsma_Value_m
                       / (rtb_Product7_ma * rtb_VectorConcatenate_f_idx_0));

      /* Trigonometry: '<S146>/Trigonometric Function3' */
      rtb_e = cos(rtb_Step1);

      /* Product: '<S146>/Product9' */
      rtb_Subtract_ju = rtb_e * rtb_e * rtb_e;

      /* Trigonometry: '<S146>/Trigonometric Function2' */
      rtb_Step1 = sin(rtb_Step1);

      /* Product: '<S146>/Product5' */
      rtb_e = rtb_VectorConcatenate_f_idx_0 * rtb_VectorConcatenate_f_idx_0;

      /* Product: '<S146>/Product10' incorporates:
       *  Constant: '<S144>/c_rsma'
       *  Product: '<S146>/Divide'
       *  Product: '<S146>/Product4'
       *  Product: '<S146>/Product8'
       *  Sum: '<S146>/Subtract2'
       */
      rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_P.c_rsma_Value_m *
        GRM_HIL_P.c_rsma_Value_m - rtb_e) / rtb_e *
        rtb_VectorConcatenate_f_idx_0 * (rtb_Step1 * rtb_Step1 * rtb_Step1);

      /* Sum: '<S146>/Add1' incorporates:
       *  Constant: '<S143>/Constant'
       */
      rtb_VectorConcatenate_f_idx_0 += GRM_HIL_P.Constant_Value_g4[2];

      /* Product: '<S146>/Product3' incorporates:
       *  Constant: '<S144>/c_flat'
       *  Product: '<S145>/Product3'
       */
      rtb_Subtract_cl = GRM_HIL_P.c_flat_Value_c * GRM_HIL_P.c_flat_Value_c;

      /* Trigonometry: '<S146>/Trigonometric Function1' incorporates:
       *  Constant: '<S144>/c_flat'
       *  Constant: '<S144>/c_rsma'
       *  Gain: '<S146>/Gain'
       *  Product: '<S146>/Divide2'
       *  Product: '<S146>/Product11'
       *  Product: '<S146>/Product3'
       *  Sqrt: '<S146>/Sqrt'
       *  Sum: '<S146>/Subtract1'
       *  Sum: '<S146>/Subtract3'
       */
      rtb_e = atan(rtb_VectorConcatenate_f_idx_0 / (rtb_Product7_ma -
        (GRM_HIL_P.Gain_Gain_j * GRM_HIL_P.c_flat_Value_c - rtb_Subtract_cl) *
        GRM_HIL_P.c_rsma_Value_m * rtb_Subtract_ju));

      /* Trigonometry: '<S145>/Trigonometric Function' */
      rtb_Step1 = sin(rtb_e);
      GRM_HIL_B.hBE_0_l = rtb_Product7_ma / cos(rtb_e) -
        GRM_HIL_P.c_rsma_Value_m / sqrt(GRM_HIL_P.Constant_Value_o -
        (GRM_HIL_P.Gain_Gain_l * GRM_HIL_P.c_flat_Value_c - rtb_Subtract_cl) *
        (rtb_Step1 * rtb_Step1));
    }

    /* End of Switch: '<S143>/Switch1' */

    /* SignalConversion generated from: '<S142>/Vector Concatenate' incorporates:
     *  Constant: '<S142>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[0] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S142>/Vector Concatenate' incorporates:
     *  Constant: '<S142>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[1] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S142>/Vector Concatenate' incorporates:
     *  Constant: '<S142>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[2] = GRM_HIL_P.Constant3_Value_j;
  }

  /* Switch: '<S142>/Switch' incorporates:
   *  Constant: '<S142>/Constant1'
   *  Sum: '<S142>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_mm) - GRM_HIL_B.hBE_0_l >
      GRM_HIL_P.Switch_Threshold_gn) {
    /* Sqrt: '<S115>/Sqrt' incorporates:
     *  DotProduct: '<S115>/Dot Product'
     */
    rtb_sincos_o2[2] = sqrt((frac_0[0] * frac_0[0] + frac_0[1] * frac_0[1]) +
      frac_0[2] * frac_0[2]);

    /* SignalConversion generated from: '<S115>/Vector Concatenate' incorporates:
     *  Constant: '<S115>/Constant1'
     */
    rtb_sincos_o2[1] = GRM_HIL_P.Constant1_Value_cj;

    /* SignalConversion generated from: '<S115>/Vector Concatenate' incorporates:
     *  Constant: '<S115>/Constant1'
     */
    rtb_sincos_o2[0] = GRM_HIL_P.Constant1_Value_cj;
  } else {
    rtb_sincos_o2[0] = GRM_HIL_B.VectorConcatenate_f[0];
    rtb_sincos_o2[1] = GRM_HIL_B.VectorConcatenate_f[1];
    rtb_sincos_o2[2] = GRM_HIL_B.VectorConcatenate_f[2];
  }

  /* End of Switch: '<S142>/Switch' */

  /* Sum: '<S68>/Subtract' */
  rtb_Product7_ma = rtb_Subtract_ay_tmp_0;

  /* Switch: '<S220>/Switch' incorporates:
   *  Constant: '<S220>/Constant'
   */
  if (!(rtb_Subtract_ay_tmp_0 > GRM_HIL_P.Switch_Threshold_fo)) {
    rtb_Product7_ma = GRM_HIL_P.Constant_Value_k;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Switch: '<S220>/Switch1' incorporates:
   *  Lookup_n-D: '<S220>/1-D Lookup Table'
   */
  if (rtb_Product7_ma > GRM_HIL_P.Switch1_Threshold_f) {
    /* Saturate: '<S220>/Saturation' */
    if (rtb_Product7_ma > GRM_HIL_P.Saturation_UpperSat_c) {
      rtb_Product7_ma = GRM_HIL_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Product7_ma < GRM_HIL_P.Saturation_LowerSat_h) {
        rtb_Product7_ma = GRM_HIL_P.Saturation_LowerSat_h;
      }
    }

    /* End of Saturate: '<S220>/Saturation' */
    rtb_Product7_ma = look1_binlcapw(rtb_Product7_ma,
      GRM_HIL_P.uDLookupTable_bp01Data, GRM_HIL_P.uDLookupTable_tableData, 16U);
  }

  /* End of Switch: '<S220>/Switch1' */

  /* Sum: '<S221>/Add' incorporates:
   *  Constant: '<S220>/Constant1'
   *  Constant: '<S220>/Constant2'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S221>/Constant1'
   *  Product: '<S221>/Product'
   *  Sum: '<S220>/Subtract1'
   */
  rtb_Subtract_ju = ((GRM_HIL_P.Constant1_Value_iw - rtb_Product7_ma) +
                     GRM_HIL_P.Constant2_Value_p) * GRM_HIL_P.Constant1_Value_mo
    + GRM_HIL_P.Constant_Value_bs;

  /* Product: '<S60>/Product' */
  rtb_sincos_o2[0] *= rtb_Subtract_ju;
  rtb_sincos_o2[1] *= rtb_Subtract_ju;
  rtb_e = rtb_sincos_o2[2] * rtb_Subtract_ju;

  /* Product: '<S59>/Product' incorporates:
   *  Math: '<S59>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac_1[i] = rtb_vBEB_a_tmp[i + 6] * rtb_e + (rtb_vBEB_a_tmp[i + 3] *
      rtb_sincos_o2[1] + rtb_vBEB_a_tmp[i] * rtb_sincos_o2[0]);
  }

  /* End of Product: '<S59>/Product' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S174>/Multiport Switch2' incorporates:
     *  Constant: '<S174>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3) {
     case 1:
      /* Trigonometry: '<S182>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/thrust_rot_x'
       *  Trigonometry: '<S182>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S182>/Trigonometric Function3' incorporates:
       *  Constant: '<S173>/thrust_rot_x'
       *  Trigonometry: '<S182>/Trigonometric Function'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S182>/Matrix Concatenate' incorporates:
       *  Constant: '<S182>/Constant7'
       *  Trigonometry: '<S182>/Trigonometric Function1'
       *  Trigonometry: '<S182>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_k;
      rtb_MultiportSwitch[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[8] = rtb_Step1;

      /* SignalConversion generated from: '<S182>/Matrix Concatenate' incorporates:
       *  Constant: '<S182>/Constant8'
       *  Gain: '<S182>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_a;
      rtb_MultiportSwitch[4] = rtb_Step1;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_h *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S182>/Matrix Concatenate' incorporates:
       *  Constant: '<S182>/Constant'
       *  Constant: '<S182>/Constant1'
       *  Constant: '<S182>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_d;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_j;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_j;
      break;

     case 2:
      /* Trigonometry: '<S183>/Trigonometric Function3' incorporates:
       *  Constant: '<S173>/thrust_rot_x'
       *  Trigonometry: '<S183>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S183>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/thrust_rot_x'
       *  Trigonometry: '<S183>/Trigonometric Function2'
       */
      rtb_Step1 = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S183>/Matrix Concatenate' incorporates:
       *  Constant: '<S183>/Constant7'
       *  Gain: '<S183>/Gain1'
       *  Trigonometry: '<S183>/Trigonometric Function1'
       *  Trigonometry: '<S183>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_d * rtb_Step1;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_a5;
      rtb_MultiportSwitch[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S183>/Matrix Concatenate' incorporates:
       *  Constant: '<S183>/Constant'
       *  Constant: '<S183>/Constant1'
       *  Constant: '<S183>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ek;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_k;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_f;

      /* SignalConversion generated from: '<S183>/Matrix Concatenate' incorporates:
       *  Constant: '<S183>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_k;
      rtb_MultiportSwitch[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S184>/Matrix Concatenate' incorporates:
       *  Constant: '<S184>/Constant10'
       *  Constant: '<S184>/Constant11'
       *  Constant: '<S184>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_b;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_f;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_o;

      /* Trigonometry: '<S184>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/thrust_rot_x'
       *  Trigonometry: '<S184>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S184>/Trigonometric Function' incorporates:
       *  Constant: '<S173>/thrust_rot_x'
       *  Trigonometry: '<S184>/Trigonometric Function3'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S184>/Matrix Concatenate' incorporates:
       *  Constant: '<S184>/Constant7'
       *  Trigonometry: '<S184>/Trigonometric Function'
       *  Trigonometry: '<S184>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[4] = rtb_Step1;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_is;

      /* SignalConversion generated from: '<S184>/Matrix Concatenate' incorporates:
       *  Constant: '<S184>/Constant8'
       *  Gain: '<S184>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Step1;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_e *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_d;
      break;
    }

    /* End of MultiPortSwitch: '<S174>/Multiport Switch2' */

    /* MultiPortSwitch: '<S174>/Multiport Switch1' incorporates:
     *  Constant: '<S174>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2) {
     case 1:
      /* Trigonometry: '<S179>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/thrust_rot_y'
       *  Trigonometry: '<S179>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S179>/Trigonometric Function3' incorporates:
       *  Constant: '<S173>/thrust_rot_y'
       *  Trigonometry: '<S179>/Trigonometric Function'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S179>/Matrix Concatenate' incorporates:
       *  Constant: '<S179>/Constant7'
       *  Trigonometry: '<S179>/Trigonometric Function1'
       *  Trigonometry: '<S179>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_f;
      rtb_MultiportSwitch1[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[8] = rtb_Step1;

      /* SignalConversion generated from: '<S179>/Matrix Concatenate' incorporates:
       *  Constant: '<S179>/Constant8'
       *  Gain: '<S179>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_e;
      rtb_MultiportSwitch1[4] = rtb_Step1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_jq *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S179>/Matrix Concatenate' incorporates:
       *  Constant: '<S179>/Constant'
       *  Constant: '<S179>/Constant1'
       *  Constant: '<S179>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_a;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_n;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_e;
      break;

     case 2:
      /* Trigonometry: '<S180>/Trigonometric Function3' incorporates:
       *  Constant: '<S173>/thrust_rot_y'
       *  Trigonometry: '<S180>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S180>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/thrust_rot_y'
       *  Trigonometry: '<S180>/Trigonometric Function2'
       */
      rtb_Step1 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S180>/Matrix Concatenate' incorporates:
       *  Constant: '<S180>/Constant7'
       *  Gain: '<S180>/Gain1'
       *  Trigonometry: '<S180>/Trigonometric Function1'
       *  Trigonometry: '<S180>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_h * rtb_Step1;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_ib;
      rtb_MultiportSwitch1[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S180>/Matrix Concatenate' incorporates:
       *  Constant: '<S180>/Constant'
       *  Constant: '<S180>/Constant1'
       *  Constant: '<S180>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_dk;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_l;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_m;

      /* SignalConversion generated from: '<S180>/Matrix Concatenate' incorporates:
       *  Constant: '<S180>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_bs;
      rtb_MultiportSwitch1[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S181>/Matrix Concatenate' incorporates:
       *  Constant: '<S181>/Constant10'
       *  Constant: '<S181>/Constant11'
       *  Constant: '<S181>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_h;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_fw;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_p;

      /* Trigonometry: '<S181>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/thrust_rot_y'
       *  Trigonometry: '<S181>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S181>/Trigonometric Function' incorporates:
       *  Constant: '<S173>/thrust_rot_y'
       *  Trigonometry: '<S181>/Trigonometric Function3'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S181>/Matrix Concatenate' incorporates:
       *  Constant: '<S181>/Constant7'
       *  Trigonometry: '<S181>/Trigonometric Function'
       *  Trigonometry: '<S181>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[4] = rtb_Step1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_d;

      /* SignalConversion generated from: '<S181>/Matrix Concatenate' incorporates:
       *  Constant: '<S181>/Constant8'
       *  Gain: '<S181>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Step1;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_hf *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_o;
      break;
    }

    /* End of MultiPortSwitch: '<S174>/Multiport Switch1' */

    /* MultiPortSwitch: '<S174>/Multiport Switch' incorporates:
     *  Constant: '<S174>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_m) {
     case 1:
      /* Trigonometry: '<S176>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/Thrust_rot_z'
       *  Trigonometry: '<S176>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S176>/Trigonometric Function3' incorporates:
       *  Constant: '<S173>/Thrust_rot_z'
       *  Trigonometry: '<S176>/Trigonometric Function'
       */
      rtb_Step1 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S176>/Matrix Concatenate' incorporates:
       *  Constant: '<S176>/Constant7'
       *  Trigonometry: '<S176>/Trigonometric Function1'
       *  Trigonometry: '<S176>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_b;
      rtb_MultiportSwitch2[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[8] = rtb_Step1;

      /* SignalConversion generated from: '<S176>/Matrix Concatenate' incorporates:
       *  Constant: '<S176>/Constant8'
       *  Gain: '<S176>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_ks;
      rtb_MultiportSwitch2[4] = rtb_Step1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_lj *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S176>/Matrix Concatenate' incorporates:
       *  Constant: '<S176>/Constant'
       *  Constant: '<S176>/Constant1'
       *  Constant: '<S176>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_l;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_o;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_fh;
      break;

     case 2:
      /* Trigonometry: '<S177>/Trigonometric Function3' incorporates:
       *  Constant: '<S173>/Thrust_rot_z'
       *  Trigonometry: '<S177>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S177>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/Thrust_rot_z'
       *  Trigonometry: '<S177>/Trigonometric Function2'
       */
      rtb_Step1 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S177>/Matrix Concatenate' incorporates:
       *  Constant: '<S177>/Constant7'
       *  Gain: '<S177>/Gain1'
       *  Trigonometry: '<S177>/Trigonometric Function1'
       *  Trigonometry: '<S177>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_hx * rtb_Step1;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_f2;
      rtb_MultiportSwitch2[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S177>/Matrix Concatenate' incorporates:
       *  Constant: '<S177>/Constant'
       *  Constant: '<S177>/Constant1'
       *  Constant: '<S177>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_n;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_b;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_d;

      /* SignalConversion generated from: '<S177>/Matrix Concatenate' incorporates:
       *  Constant: '<S177>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_g;
      rtb_MultiportSwitch2[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S178>/Matrix Concatenate' incorporates:
       *  Constant: '<S178>/Constant10'
       *  Constant: '<S178>/Constant11'
       *  Constant: '<S178>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_l;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_l;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_l;

      /* Trigonometry: '<S178>/Trigonometric Function1' incorporates:
       *  Constant: '<S173>/Thrust_rot_z'
       *  Trigonometry: '<S178>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S178>/Trigonometric Function' incorporates:
       *  Constant: '<S173>/Thrust_rot_z'
       *  Trigonometry: '<S178>/Trigonometric Function3'
       */
      rtb_Step1 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S178>/Matrix Concatenate' incorporates:
       *  Constant: '<S178>/Constant7'
       *  Trigonometry: '<S178>/Trigonometric Function'
       *  Trigonometry: '<S178>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[4] = rtb_Step1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_c;

      /* SignalConversion generated from: '<S178>/Matrix Concatenate' incorporates:
       *  Constant: '<S178>/Constant8'
       *  Gain: '<S178>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Step1;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_k *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_f;
      break;
    }

    /* End of MultiPortSwitch: '<S174>/Multiport Switch' */

    /* Product: '<S174>/3. Rotation' */
    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_MultiportSwitch1_tmp = i_0 + 3 * i;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] = 0.0;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 * i] *
          rtb_MultiportSwitch1[i_0];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 * i +
          1] * rtb_MultiportSwitch1[i_0 + 3];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 * i +
          2] * rtb_MultiportSwitch1[i_0 + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_MultiportSwitch1_tmp = i_0 + 3 * i;
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] = 0.0;
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i] *
          rtb_MultiportSwitch[i_0];
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 1] *
          rtb_MultiportSwitch[i_0 + 3];
        GRM_HIL_B.T12[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 2] *
          rtb_MultiportSwitch[i_0 + 6];
      }
    }

    /* End of Product: '<S174>/3. Rotation' */
  }

  /* Switch: '<S172>/Switch' incorporates:
   *  Constant: '<S172>/Constant'
   */
  if (rtb_Subtract_ay_tmp_0 > GRM_HIL_P.Switch_Threshold_n) {
    rtb_VectorConcatenate_f_idx_0 = rtb_Subtract_ay_tmp_0;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant_Value_a0;
  }

  /* End of Switch: '<S172>/Switch' */

  /* Switch: '<S172>/Switch1' incorporates:
   *  Lookup_n-D: '<S172>/thrust_lookup'
   */
  if (rtb_VectorConcatenate_f_idx_0 > GRM_HIL_P.Switch1_Threshold_a) {
    /* Saturate: '<S172>/Saturation' */
    if (rtb_VectorConcatenate_f_idx_0 > GRM_HIL_P.Saturation_UpperSat) {
      rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_UpperSat;
    } else {
      if (rtb_VectorConcatenate_f_idx_0 < GRM_HIL_P.Saturation_LowerSat) {
        rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S172>/Saturation' */
    rtb_sincos_o2[0] = look1_binlcapw(rtb_VectorConcatenate_f_idx_0,
      GRM_HIL_P.thrust_lookup_bp01Data, GRM_HIL_P.thrust_lookup_tableData, 11U);
  } else {
    rtb_sincos_o2[0] = rtb_VectorConcatenate_f_idx_0;
  }

  /* End of Switch: '<S172>/Switch1' */

  /* Product: '<S173>/Product1' incorporates:
   *  Constant: '<S172>/Constant1'
   *  Constant: '<S173>/uncert_thrust'
   */
  rtb_sincos_o2[0] *= GRM_HIL_P.uncert_thrust_Value;
  rtb_e = GRM_HIL_P.Constant1_Value_h * GRM_HIL_P.uncert_thrust_Value;

  /* Product: '<S173>/Product' incorporates:
   *  Product: '<S173>/Product1'
   */
  for (i = 0; i < 3; i++) {
    frac_0[i] = GRM_HIL_B.T12[i + 6] * rtb_e + (GRM_HIL_B.T12[i + 3] * rtb_e +
      GRM_HIL_B.T12[i] * rtb_sincos_o2[0]);
  }

  /* End of Product: '<S173>/Product' */

  /* Step: '<Root>/External Force' incorporates:
   *  Sin: '<Root>/Sine Wave'
   *  Step: '<Root>/External Moment'
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   */
  rtb_Subtract_ay_tmp_0 = GRM_HIL_M->Timing.t[0];
  if (rtb_Subtract_ay_tmp_0 < GRM_HIL_P.ExternalForce_Time) {
    rtb_e = GRM_HIL_P.ExternalForce_Y0;
  } else {
    rtb_e = GRM_HIL_P.ExternalForce_YFinal;
  }

  /* End of Step: '<Root>/External Force' */

  /* Step: '<Root>/Step' */
  if (rtb_Subtract_ay_tmp_0 < GRM_HIL_P.Step_Time) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step_Y0;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step_YFinal;
  }

  /* Sum: '<S59>/Add' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  frac_2[0] = ((rtb_Product1_m[0] + frac_1[0]) + frac_0[0]) + (rtb_e +
    rtb_VectorConcatenate_f_idx_0) * GRM_HIL_P.Gain_Gain_pd;
  frac_2[1] = ((rtb_Product1_m[1] + frac_1[1]) + frac_0[1]) +
    GRM_HIL_P.Constant1_Value_fp;
  frac_2[2] = ((rtb_Product1_m[2] + frac_1[2]) + frac_0[2]) +
    GRM_HIL_P.Constant1_Value_fp;

  /* Switch: '<S192>/Switch' incorporates:
   *  Constant: '<S192>/Constant'
   *  Product: '<S192>/Product2'
   */
  if (GRM_HIL_P.Rigid_Body_EOM_6_DOF_flag_Kraft > GRM_HIL_P.Switch_Threshold_j)
  {
    frac_1[0] = frac_2[0];
    frac_1[1] = frac_2[1];
    frac_1[2] = frac_2[2];
  } else {
    /* Sum: '<S194>/Add7' */
    rtb_MathFunction2[8] = rtb_VectorConcatenate_f_idx_1;

    /* Sum: '<S194>/Add8' incorporates:
     *  Gain: '<S194>/Gain11'
     *  Gain: '<S194>/Gain12'
     */
    rtb_MathFunction2[7] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain11_Gain + rtb_TBG_tmp_4
      * GRM_HIL_P.Gain12_Gain;

    /* Sum: '<S194>/Add3' incorporates:
     *  Gain: '<S194>/Gain5'
     *  Gain: '<S194>/Gain6'
     */
    rtb_MathFunction2[6] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain5_Gain - rtb_TBG_tmp_2 *
      GRM_HIL_P.Gain6_Gain;

    /* Sum: '<S194>/Add2' incorporates:
     *  Gain: '<S194>/Gain3'
     *  Gain: '<S194>/Gain4'
     */
    rtb_MathFunction2[5] = rtb_TBG_tmp_3 * GRM_HIL_P.Gain3_Gain - rtb_TBG_tmp_4 *
      GRM_HIL_P.Gain4_Gain;

    /* Sum: '<S194>/Add6' */
    rtb_MathFunction2[4] = rtb_TBG_tmp_5;

    /* Sum: '<S194>/Add4' incorporates:
     *  Gain: '<S194>/Gain7'
     *  Gain: '<S194>/Gain8'
     */
    rtb_MathFunction2[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain + rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain8_Gain;

    /* Sum: '<S194>/Add5' incorporates:
     *  Gain: '<S194>/Gain10'
     *  Gain: '<S194>/Gain9'
     */
    rtb_MathFunction2[2] = rtb_TBG_tmp_1 * GRM_HIL_P.Gain9_Gain + rtb_TBG_tmp_2 *
      GRM_HIL_P.Gain10_Gain;

    /* Sum: '<S194>/Add1' incorporates:
     *  Gain: '<S194>/Gain1'
     *  Gain: '<S194>/Gain2'
     */
    rtb_MathFunction2[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_m - rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain2_Gain_i;

    /* Sum: '<S194>/Add' */
    rtb_MathFunction2[0] = rtb_VectorConcatenate_f_idx_2;

    /* Math: '<S192>/Math Function2' */
    for (i = 0; i < 3; i++) {
      rtb_TBG[3 * i] = rtb_MathFunction2[i];
      rtb_TBG[3 * i + 1] = rtb_MathFunction2[i + 3];
      rtb_TBG[3 * i + 2] = rtb_MathFunction2[i + 6];
    }

    memcpy(&rtb_MathFunction2[0], &rtb_TBG[0], 9U * sizeof(real_T));

    /* End of Math: '<S192>/Math Function2' */
    for (i = 0; i < 3; i++) {
      frac_1[i] = rtb_MathFunction2[i + 6] * frac_2[2] + (rtb_MathFunction2[i +
        3] * frac_2[1] + rtb_MathFunction2[i] * frac_2[0]);
    }
  }

  /* Saturate: '<S195>/Saturation' */
  if (rtb_Subtract_ju > GRM_HIL_P.Saturation_UpperSat_m) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_UpperSat_m;
  } else if (rtb_Subtract_ju < GRM_HIL_P.Saturation_LowerSat_a) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Saturation_LowerSat_a;
  } else {
    rtb_VectorConcatenate_f_idx_0 = rtb_Subtract_ju;
  }

  /* End of Saturate: '<S195>/Saturation' */

  /* Product: '<S195>/Divide' */
  frac_1[0] /= rtb_VectorConcatenate_f_idx_0;
  frac_1[1] /= rtb_VectorConcatenate_f_idx_0;

  /* SignalConversion generated from: '<S199>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[0] = frac_1[0];

  /* SignalConversion generated from: '<S199>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[1] = frac_1[1];

  /* SignalConversion generated from: '<S199>/Vector Concatenate' incorporates:
   *  Product: '<S195>/Divide'
   */
  GRM_HIL_B.VectorConcatenate_b[2] = frac_1[2] / rtb_VectorConcatenate_f_idx_0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S199>/Constant' */
    GRM_HIL_B.VectorConcatenate_b[3] = GRM_HIL_P.Constant_Value_eq;
  }

  /* Sum: '<S199>/Add' incorporates:
   *  Constant: '<S199>/Q_1'
   *  Constant: '<S199>/Q_2'
   *  Constant: '<S199>/Q_3'
   *  Constant: '<S199>/Q_4'
   *  Product: '<S199>/Product'
   *  Product: '<S199>/Product1'
   *  Product: '<S199>/Product2'
   *  Product: '<S199>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_i[i] * rtb_Product_idx_0 +
               GRM_HIL_P.Q_2_Value_n[i] * rtb_Product_idx_1) +
              GRM_HIL_P.Q_3_Value_m[i] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value_f[i] * rtb_Product_idx_3;
  }

  /* End of Sum: '<S199>/Add' */

  /* Product: '<S199>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_e = tmp[i + 12] * GRM_HIL_B.VectorConcatenate_b[3] + (tmp[i + 8] *
      GRM_HIL_B.VectorConcatenate_b[2] + (tmp[i + 4] *
      GRM_HIL_B.VectorConcatenate_b[1] + tmp[i] * GRM_HIL_B.VectorConcatenate_b
      [0]));
    rtb_d_qGE[i] = rtb_e;
  }

  /* Sum: '<S199>/Add1' incorporates:
   *  Constant: '<S199>/Q~_1'
   *  Constant: '<S199>/Q~_2'
   *  Constant: '<S199>/Q~_3'
   *  Constant: '<S199>/Q~_4'
   *  Product: '<S199>/Product4'
   *  Product: '<S199>/Product5'
   *  Product: '<S199>/Product6'
   *  Product: '<S199>/Product7'
   */
  for (i = 0; i < 4; i++) {
    i_0 = i << 2;
    tmp[i_0] = ((GRM_HIL_P.Q_1_Value[i] * rtb_Product_idx_0 +
                 GRM_HIL_P.Q_2_Value[i] * rtb_Product_idx_1) +
                GRM_HIL_P.Q_3_Value[i] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i] * rtb_Product_idx_3;
    tmp[i_0 + 1] = ((GRM_HIL_P.Q_1_Value[i + 4] * rtb_Product_idx_0 +
                     GRM_HIL_P.Q_2_Value[i + 4] * rtb_Product_idx_1) +
                    GRM_HIL_P.Q_3_Value[i + 4] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i + 4] * rtb_Product_idx_3;
    tmp[i_0 + 2] = ((GRM_HIL_P.Q_1_Value[i + 8] * rtb_Product_idx_0 +
                     GRM_HIL_P.Q_2_Value[i + 8] * rtb_Product_idx_1) +
                    GRM_HIL_P.Q_3_Value[i + 8] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i + 8] * rtb_Product_idx_3;
    tmp[i_0 + 3] = ((GRM_HIL_P.Q_1_Value[i + 12] * rtb_Product_idx_0 +
                     GRM_HIL_P.Q_2_Value[i + 12] * rtb_Product_idx_1) +
                    GRM_HIL_P.Q_3_Value[i + 12] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value[i + 12] * rtb_Product_idx_3;
  }

  /* End of Sum: '<S199>/Add1' */

  /* Product: '<S199>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Subtract_cl = tmp[i + 12] * rtb_d_qGE[3] + (tmp[i + 8] * rtb_d_qGE[2] +
      (tmp[i + 4] * rtb_d_qGE[1] + tmp[i] * rtb_d_qGE[0]));
    rtb_siB_h[i] = rtb_Subtract_cl;
  }

  /* Product: '<S185>/Product' incorporates:
   *  Math: '<S185>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac_1[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_siB_h[2] +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_siB_h[1] + rtb_MatrixMultiply_tmp[i] *
       rtb_siB_h[0]);
  }

  /* End of Product: '<S185>/Product' */

  /* Gain: '<S53>/Gain3' */
  GRM_HIL_B.ACC_x_B_mDs2 = GRM_HIL_P.Gain3_Gain_df * frac_1[0];

  /* Gain: '<S53>/Gain4' */
  GRM_HIL_B.ACC_y_B_mDs2 = GRM_HIL_P.Gain4_Gain_g * frac_1[1];

  /* Gain: '<S53>/Gain5' */
  GRM_HIL_B.ACC_z_B_mDs2 = GRM_HIL_P.Gain5_Gain_n * frac_1[2];

  /* Gain: '<S53>/Gain6' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.w_x_K_IB_B_radDs = GRM_HIL_P.Gain6_Gain_a *
    GRM_HIL_X.integration_eom_CSTATE[10];

  /* Gain: '<S53>/Gain7' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.w_y_K_IB_B_radDs = GRM_HIL_P.Gain7_Gain_ia *
    GRM_HIL_X.integration_eom_CSTATE[11];

  /* Gain: '<S53>/Gain8' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.w_z_K_IB_B_radDs = GRM_HIL_P.Gain8_Gain_l1 *
    GRM_HIL_X.integration_eom_CSTATE[12];

  /* Product: '<S64>/Product3' incorporates:
   *  MATLAB Function: '<S52>/MATLAB Function'
   *  Product: '<S64>/Product8'
   */
  rtb_VectorConcatenate_f_idx_1 = -rtb_Product_idx_1 * -rtb_Product_idx_1;

  /* Gain: '<S53>/Gain9' incorporates:
   *  Constant: '<S64>/Constant'
   *  MATLAB Function: '<S52>/MATLAB Function'
   *  Product: '<S64>/Product'
   *  Product: '<S64>/Product1'
   *  Product: '<S64>/Product2'
   *  Product: '<S64>/Product3'
   *  Sum: '<S64>/Add'
   *  Sum: '<S64>/Add1'
   *  Trigonometry: '<S64>/Trigonometric Function'
   */
  GRM_HIL_B.ATT_Phi_rad = rt_atan2d_snf(-rtb_Product_idx_0 * rtb_Product_idx_3 +
    -rtb_Product_idx_1 * -rtb_Product_idx_2, (GRM_HIL_P.Constant_Value_pf -
    -rtb_Product_idx_0 * -rtb_Product_idx_0) - rtb_VectorConcatenate_f_idx_1) *
    GRM_HIL_P.Gain9_Gain_f;

  /* Gain: '<S64>/Gain' incorporates:
   *  MATLAB Function: '<S52>/MATLAB Function'
   *  Product: '<S64>/Product4'
   *  Product: '<S64>/Product5'
   *  Sum: '<S64>/Add2'
   */
  u0 = (-rtb_Product_idx_1 * rtb_Product_idx_3 - -rtb_Product_idx_0 *
        -rtb_Product_idx_2) * GRM_HIL_P.Gain_Gain_m;

  /* Saturate: '<S64>/Saturation' */
  if (u0 > GRM_HIL_P.Saturation_UpperSat_g) {
    u0 = GRM_HIL_P.Saturation_UpperSat_g;
  } else {
    if (u0 < GRM_HIL_P.Saturation_LowerSat_ku) {
      u0 = GRM_HIL_P.Saturation_LowerSat_ku;
    }
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Trigonometry: '<S64>/Trigonometric Function1' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Gain: '<S53>/Gain10' incorporates:
   *  Trigonometry: '<S64>/Trigonometric Function1'
   */
  GRM_HIL_B.ATT_Theta_rad = GRM_HIL_P.Gain10_Gain_k * asin(u0);

  /* Gain: '<S53>/Gain11' incorporates:
   *  Constant: '<S64>/Constant1'
   *  MATLAB Function: '<S52>/MATLAB Function'
   *  Product: '<S64>/Product6'
   *  Product: '<S64>/Product7'
   *  Product: '<S64>/Product9'
   *  Sum: '<S64>/Add3'
   *  Sum: '<S64>/Add4'
   *  Trigonometry: '<S64>/Trigonometric Function2'
   */
  GRM_HIL_B.ATT_Psi_rad = rt_atan2d_snf(-rtb_Product_idx_0 * -rtb_Product_idx_1
    + -rtb_Product_idx_2 * rtb_Product_idx_3, (GRM_HIL_P.Constant1_Value_jl -
    rtb_VectorConcatenate_f_idx_1) - -rtb_Product_idx_2 * -rtb_Product_idx_2) *
    GRM_HIL_P.Gain11_Gain_o;

  /* Gain: '<S69>/1//2' */
  frac_1[0] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Phi_rad;
  frac_1[1] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Theta_rad;
  frac_1[2] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Psi_rad;

  /* Trigonometry: '<S69>/sincos' */
  rtb_Product1_m[0] = cos(frac_1[0]);
  frac_1[0] = sin(frac_1[0]);
  rtb_Product1_m[1] = cos(frac_1[1]);
  frac_1[1] = sin(frac_1[1]);
  rtb_Product1_m[2] = cos(frac_1[2]);
  rtb_VectorConcatenate_f_idx_1 = sin(frac_1[2]);

  /* Fcn: '<S69>/q0' incorporates:
   *  Fcn: '<S69>/q1'
   */
  rtb_VectorConcatenate_f_idx_2 = rtb_Product1_m[0] * rtb_Product1_m[1];
  rtb_TBG_tmp = frac_1[0] * frac_1[1];
  GRM_HIL_B.q0 = rtb_VectorConcatenate_f_idx_2 * rtb_Product1_m[2] + rtb_TBG_tmp
    * rtb_VectorConcatenate_f_idx_1;

  /* Fcn: '<S69>/q1' */
  GRM_HIL_B.q1 = rtb_VectorConcatenate_f_idx_2 * rtb_VectorConcatenate_f_idx_1 -
    rtb_TBG_tmp * rtb_Product1_m[2];

  /* Fcn: '<S69>/q2' incorporates:
   *  Fcn: '<S69>/q3'
   */
  rtb_VectorConcatenate_f_idx_2 = frac_1[0] * rtb_Product1_m[1];
  rtb_TBG_tmp = rtb_Product1_m[0] * frac_1[1];
  GRM_HIL_B.q2 = rtb_TBG_tmp * rtb_Product1_m[2] + rtb_VectorConcatenate_f_idx_2
    * rtb_VectorConcatenate_f_idx_1;

  /* Fcn: '<S69>/q3' */
  GRM_HIL_B.q3 = rtb_VectorConcatenate_f_idx_2 * rtb_Product1_m[2] - rtb_TBG_tmp
    * rtb_VectorConcatenate_f_idx_1;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S53>/Gain12' incorporates:
     *  Constant: '<S52>/Constant5'
     */
    GRM_HIL_B.POS_lambda_WGS84_rad = GRM_HIL_P.Gain12_Gain_b *
      GRM_HIL_P.Constant5_Value_k;

    /* Gain: '<S53>/Gain13' incorporates:
     *  Constant: '<S52>/Constant4'
     */
    GRM_HIL_B.POS_mue_WGS84_rad = GRM_HIL_P.Gain13_Gain *
      GRM_HIL_P.Constant4_Value_d;

    /* Gain: '<S53>/Gain18' incorporates:
     *  Constant: '<S52>/Constant7'
     */
    GRM_HIL_B.motor_state_perc = GRM_HIL_P.Gain18_Gain *
      GRM_HIL_P.Constant7_Value_l;
  }

  /* Gain: '<S53>/Gain14' */
  GRM_HIL_B.POS_h_WGS84_m = GRM_HIL_P.Gain14_Gain * GRM_HIL_B.Switch[2];

  /* Gain: '<S53>/Gain15' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.POS_x_NED_m = GRM_HIL_P.Gain15_Gain *
    GRM_HIL_X.integration_eom_CSTATE[0];

  /* Gain: '<S53>/Gain16' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.POS_y_NED_m = GRM_HIL_P.Gain16_Gain *
    GRM_HIL_X.integration_eom_CSTATE[1];

  /* Gain: '<S53>/Gain22' */
  GRM_HIL_B.mass_kg = GRM_HIL_P.Gain22_Gain * rtb_Subtract_ju;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S53>/Gain19' incorporates:
     *  Constant: '<S52>/Constant3'
     */
    GRM_HIL_B.VEL_u_Wind_A_E_O_mDs = GRM_HIL_P.Gain19_Gain *
      GRM_HIL_P.Constant3_Value_i;

    /* Gain: '<S53>/Gain20' incorporates:
     *  Constant: '<S52>/Constant2'
     */
    GRM_HIL_B.VEL_v_Wind_A_E_O_mDs = GRM_HIL_P.Gain20_Gain *
      GRM_HIL_P.Constant2_Value_pm;

    /* Gain: '<S53>/Gain21' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    GRM_HIL_B.VEL_w_Wind_A_E_O_mDs = GRM_HIL_P.Gain21_Gain *
      GRM_HIL_P.Constant1_Value_ay;

    /* ToAsyncQueueBlock generated from: '<Root>/Simulation' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4142623812U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3185120568U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3735177854U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_x_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(617676290U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_y_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(995537745U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_z_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(303667376U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_x_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1318681627U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_y_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4085788184U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_z_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2544271548U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3709084709U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1332293375U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2665288915U, time, pData, size);
=======
  /* Integrator: '<S74>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset && (GRM_HIL_PrevZCX.Integrator_Reset_ZCE
      != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator_IWORK != 0)) {
      GRM_HIL_X.Integrator_CSTATE = GRM_HIL_B.motor_state_perc;
    }
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S46>/Gain10' incorporates:
     *  Constant: '<S5>/Constant10'
     */
    GRM_HIL_B.ATT_Theta_rad = GRM_HIL_P.Gain10_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Att.ATT_Theta_rad;
  }

  /* Integrator: '<S72>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_f != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_f = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator_IWORK_i != 0)) {
      GRM_HIL_X.Integrator_CSTATE_k = GRM_HIL_B.ATT_Phi_rad;
    }
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S46>/Gain11' incorporates:
     *  Constant: '<S5>/Constant11'
     */
    GRM_HIL_B.ATT_Psi_rad = GRM_HIL_P.Gain11_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Att.ATT_Psi_rad;
  }

  /* Integrator: '<S72>/Integrator1' incorporates:
   *  Integrator: '<S72>/Integrator2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset && (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE
      != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator1_IWORK != 0)) {
      GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_B.ATT_Theta_rad;
    }

    didZcEventOccur = (GRM_HIL_B.reset && (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE
      != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator2_IWORK != 0)) {
      GRM_HIL_X.Integrator2_CSTATE = GRM_HIL_B.ATT_Psi_rad;
    }
  }

  /* Outputs for Enabled SubSystem: '<S54>/Gravity' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S7>/Constant6' */
    if (GRM_HIL_P.Constant6_Value_k) {
      GRM_HIL_DW.Gravity_MODE = true;
    } else {
      if (GRM_HIL_DW.Gravity_MODE) {
        /* Disable for Outport: '<S58>/acc_x_grav_mDs' */
        GRM_HIL_B.acc_x = GRM_HIL_P.acc_x_grav_mDs_Y0;

        /* Disable for Outport: '<S58>/acc_y_grav_mDs' */
        GRM_HIL_B.acc_y = GRM_HIL_P.acc_y_grav_mDs_Y0;

        /* Disable for Outport: '<S58>/acc_z_grav_mDs' */
        GRM_HIL_B.acc_z = GRM_HIL_P.acc_z_grav_mDs_Y0;
        GRM_HIL_DW.Gravity_MODE = false;
>>>>>>> origin/master
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4181754500U, time, pData, size);
      }

<<<<<<< HEAD
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1026352185U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(967157817U, time, pData, size);
=======
  if (GRM_HIL_DW.Gravity_MODE) {
    /* MATLAB Function: '<S58>/MATLAB Function' incorporates:
     *  Constant: '<S58>/Constant1'
     *  Integrator: '<S72>/Integrator'
     *  Integrator: '<S72>/Integrator1'
     */
    GRM_HIL_B.acc_x = -sin(GRM_HIL_X.Integrator1_CSTATE) *
      GRM_HIL_P.FDM_Linear_FDM.Environment_Data.gravity_mDs2;
    rtb_Add_g = cos(GRM_HIL_X.Integrator1_CSTATE);
    GRM_HIL_B.acc_y = rtb_Add_g * sin(GRM_HIL_X.Integrator_CSTATE_k) *
      GRM_HIL_P.FDM_Linear_FDM.Environment_Data.gravity_mDs2;
    GRM_HIL_B.acc_z = rtb_Add_g * cos(GRM_HIL_X.Integrator_CSTATE_k) *
      GRM_HIL_P.FDM_Linear_FDM.Environment_Data.gravity_mDs2;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Gravity_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S54>/Gravity' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S54>/Drag' incorporates:
     *  EnablePort: '<S57>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S7>/Constant5' */
      if (GRM_HIL_P.Constant5_Value_k) {
        GRM_HIL_DW.Drag_MODE = true;
      } else {
        if (GRM_HIL_DW.Drag_MODE) {
          /* Disable for Outport: '<S57>/acc_x_drag_mDs2' */
          GRM_HIL_B.OutportBufferForacc_x_drag_mDs2 =
            GRM_HIL_P.acc_x_drag_mDs2_Y0;

          /* Disable for Outport: '<S57>/acc_y_drag_mDs2' */
          GRM_HIL_B.OutportBufferForacc_y_drag_mDs2 =
            GRM_HIL_P.acc_y_drag_mDs2_Y0;

          /* Disable for Outport: '<S57>/acc_z_drag_mDs2' */
          GRM_HIL_B.OutportBufferForacc_z_drag_mDs2 =
            GRM_HIL_P.acc_z_drag_mDs2_Y0;
          GRM_HIL_DW.Drag_MODE = false;
        }
>>>>>>> origin/master
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1923638803U, time, pData, size);
      }

<<<<<<< HEAD
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_lambda_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1662894120U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_mue_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2817964943U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_h_WGS84_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(127727085U, time, pData, size);
=======
    if (GRM_HIL_DW.Drag_MODE) {
      /* SignalConversion generated from: '<S57>/acc_x_drag_mDs2' incorporates:
       *  Constant: '<S57>/Constant'
       */
      GRM_HIL_B.OutportBufferForacc_x_drag_mDs2 = GRM_HIL_P.Constant_Value_d;

      /* SignalConversion generated from: '<S57>/acc_y_drag_mDs2' incorporates:
       *  Constant: '<S57>/Constant1'
       */
      GRM_HIL_B.OutportBufferForacc_y_drag_mDs2 = GRM_HIL_P.Constant1_Value_o;

      /* SignalConversion generated from: '<S57>/acc_z_drag_mDs2' incorporates:
       *  Constant: '<S57>/Constant2'
       */
      GRM_HIL_B.OutportBufferForacc_z_drag_mDs2 = GRM_HIL_P.Constant2_Value_o;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Drag_SubsysRanBC);
>>>>>>> origin/master
      }

<<<<<<< HEAD
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_x_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3003255823U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_y_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1413605450U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_z_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2474778787U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.motor_state_perc;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2660148452U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.mass_kg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2517901921U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3970422542U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2966210976U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1923707466U, time, pData, size);
      }
    }

    /* DiscretePulseGenerator: '<S17>/Pulse Generator1' */
=======
    /* End of Outputs for SubSystem: '<S54>/Drag' */
  }

  /* Sum: '<S54>/Add' incorporates:
   *  Constant: '<S73>/Constant'
   *  Constant: '<S73>/Constant1'
   *  Integrator: '<S74>/Integrator'
   *  Product: '<S54>/Divide'
   *  Product: '<S73>/Multiply'
   *  Sum: '<S73>/Add'
   */
  rtb_Add_g = (GRM_HIL_B.OutportBufferForthrust /
               ((GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.mass_preburn_kg -
                 GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.mass_kg) *
                GRM_HIL_X.Integrator_CSTATE +
                GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.mass_kg) +
               GRM_HIL_B.acc_x) + GRM_HIL_B.OutportBufferForacc_x_drag_mDs2;

  /* Gain: '<S52>/Gain3' */
  GRM_HIL_B.ACC_x_B_mDs2 = GRM_HIL_P.Gain3_Gain * rtb_Add_g;

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn'
   */
  rtb_Fin_1_Pos_rad = (GRM_HIL_P.Servo_TF.Servo1_Numerator_Coefs /
                       GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[0] *
                       GRM_HIL_X.TransferFcn_CSTATE[1] + 0.0 *
                       GRM_HIL_X.TransferFcn_CSTATE[0]) * GRM_HIL_P.Gain_Gain;

  /* TransferFcn: '<S10>/Transfer Fcn1' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn2'
   *  TransferFcn: '<S10>/Transfer Fcn3'
   */
  rtb_Fin_4_Pos_rad = GRM_HIL_P.Servo_TF.Servo2_Numerator_Coefs /
    GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[0];

  /* Gain: '<S11>/Gain1' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn1'
   */
  rtb_Fin_2_Pos_rad = (rtb_Fin_4_Pos_rad * GRM_HIL_X.TransferFcn1_CSTATE[1] +
                       0.0 * GRM_HIL_X.TransferFcn1_CSTATE[0]) *
    GRM_HIL_P.Gain1_Gain;

  /* Gain: '<S11>/Gain2' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn2'
   */
  rtb_Fin_3_Pos_rad = (rtb_Fin_4_Pos_rad * GRM_HIL_X.TransferFcn2_CSTATE[1] +
                       0.0 * GRM_HIL_X.TransferFcn2_CSTATE[0]) *
    GRM_HIL_P.Gain2_Gain;

  /* Gain: '<S11>/Gain3' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn3'
   */
  rtb_Fin_4_Pos_rad = (rtb_Fin_4_Pos_rad * GRM_HIL_X.TransferFcn3_CSTATE[1] +
                       0.0 * GRM_HIL_X.TransferFcn3_CSTATE[0]) *
    GRM_HIL_P.Gain3_Gain_d;

  /* Sum: '<S61>/Add18' incorporates:
   *  Constant: '<S61>/Constant4'
   *  Integrator: '<S72>/Integrator'
   *  Sum: '<S61>/Add13'
   */
  rtb_ACC_z_B_mDs2_i = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f1_rad;

  /* Sum: '<S61>/Add20' incorporates:
   *  Constant: '<S61>/Constant5'
   *  Integrator: '<S72>/Integrator'
   *  Sum: '<S61>/Add14'
   */
  rtb_p_B_radDs = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f2_rad;

  /* Sum: '<S61>/Add23' incorporates:
   *  Constant: '<S61>/Constant6'
   *  Integrator: '<S72>/Integrator'
   *  Sum: '<S61>/Add15'
   */
  rtb_q_B_radDs = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f3_rad;

  /* Sum: '<S61>/Add22' incorporates:
   *  Constant: '<S61>/Constant7'
   *  Integrator: '<S72>/Integrator'
   *  Sum: '<S61>/Add16'
   */
  rtb_r_B_radDs = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f4_rad;

  /* Gain: '<S61>/Gain2' incorporates:
   *  Fcn: '<S61>/Fcn12'
   *  Fcn: '<S61>/Fcn13'
   *  Fcn: '<S61>/Fcn15'
   *  Fcn: '<S61>/Fcn16'
   *  Product: '<S61>/Multiply12'
   *  Product: '<S61>/Multiply13'
   *  Product: '<S61>/Multiply14'
   *  Product: '<S61>/Multiply15'
   *  Sum: '<S61>/Add18'
   *  Sum: '<S61>/Add19'
   *  Sum: '<S61>/Add20'
   *  Sum: '<S61>/Add22'
   *  Sum: '<S61>/Add23'
   */
  GRM_HIL_B.Gain2 = (((-cos(rtb_ACC_z_B_mDs2_i) * rtb_Fin_1_Pos_rad + -cos
                       (rtb_p_B_radDs) * rtb_Fin_2_Pos_rad) + -cos(rtb_q_B_radDs)
                      * rtb_Fin_3_Pos_rad) + -cos(rtb_r_B_radDs) *
                     rtb_Fin_4_Pos_rad) * GRM_HIL_P.Gain2_Gain_a;

  /* TransferFcn: '<S54>/dy2ay' */
  rtb_ACC_y_B_mDs2_d = GRM_HIL_P.FDM_Linear_TF.dy2ay.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0];

  /* Sum: '<S54>/Add1' incorporates:
   *  TransferFcn: '<S54>/dy2ay'
   */
  rtb_ACC_y_B_mDs2_d = ((((GRM_HIL_P.FDM_Linear_TF.dy2ay.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] - rtb_ACC_y_B_mDs2_d *
    (GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[1] /
     GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0])) * GRM_HIL_X.dy2ay_CSTATE[0] +
    GRM_HIL_P.FDM_Linear_TF.dy2ay.num[0] / GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0]
    * GRM_HIL_B.Gain2) + (GRM_HIL_P.FDM_Linear_TF.dy2ay.num[2] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] - rtb_ACC_y_B_mDs2_d *
    (GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[2] /
     GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0])) * GRM_HIL_X.dy2ay_CSTATE[1]) +
                        GRM_HIL_B.acc_y) +
    GRM_HIL_B.OutportBufferForacc_y_drag_mDs2;

  /* Gain: '<S52>/Gain4' */
  GRM_HIL_B.ACC_y_B_mDs2 = GRM_HIL_P.Gain4_Gain * rtb_ACC_y_B_mDs2_d;

  /* Gain: '<S61>/Gain1' incorporates:
   *  Fcn: '<S61>/Fcn10'
   *  Fcn: '<S61>/Fcn11'
   *  Fcn: '<S61>/Fcn8'
   *  Fcn: '<S61>/Fcn9'
   *  Product: '<S61>/Multiply10'
   *  Product: '<S61>/Multiply11'
   *  Product: '<S61>/Multiply8'
   *  Product: '<S61>/Multiply9'
   *  Sum: '<S61>/Add17'
   */
  GRM_HIL_B.Gain1 = (((sin(rtb_ACC_z_B_mDs2_i) * rtb_Fin_1_Pos_rad + sin
                       (rtb_p_B_radDs) * rtb_Fin_2_Pos_rad) + sin(rtb_q_B_radDs)
                      * rtb_Fin_3_Pos_rad) + sin(rtb_r_B_radDs) *
                     rtb_Fin_4_Pos_rad) * GRM_HIL_P.Gain1_Gain_n;

  /* TransferFcn: '<S54>/dp2az' */
  rtb_ACC_z_B_mDs2_i = GRM_HIL_P.FDM_Linear_TF.dp2az.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0];

  /* Sum: '<S54>/Add2' incorporates:
   *  TransferFcn: '<S54>/dp2az'
   */
  rtb_ACC_z_B_mDs2_i = ((((GRM_HIL_P.FDM_Linear_TF.dp2az.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] - rtb_ACC_z_B_mDs2_i *
    (GRM_HIL_P.FDM_Linear_TF.dp2az.denom[1] /
     GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0])) * GRM_HIL_X.dp2az_CSTATE[0] +
    GRM_HIL_P.FDM_Linear_TF.dp2az.num[0] / GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0]
    * GRM_HIL_B.Gain1) + (GRM_HIL_P.FDM_Linear_TF.dp2az.num[2] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] - rtb_ACC_z_B_mDs2_i *
    (GRM_HIL_P.FDM_Linear_TF.dp2az.denom[2] /
     GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0])) * GRM_HIL_X.dp2az_CSTATE[1]) +
                        GRM_HIL_B.acc_z) +
    GRM_HIL_B.OutportBufferForacc_z_drag_mDs2;

  /* Gain: '<S52>/Gain5' */
  GRM_HIL_B.ACC_z_B_mDs2 = GRM_HIL_P.Gain5_Gain * rtb_ACC_z_B_mDs2_i;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S52>/Gain9' incorporates:
   *  Integrator: '<S72>/Integrator'
   */
  GRM_HIL_B.ATT_Phi_rad_l = GRM_HIL_P.Gain9_Gain_b *
    GRM_HIL_X.Integrator_CSTATE_k;

  /* Gain: '<S52>/Gain10' incorporates:
   *  Integrator: '<S72>/Integrator1'
   */
  GRM_HIL_B.ATT_Theta_rad_k = GRM_HIL_P.Gain10_Gain_f *
    GRM_HIL_X.Integrator1_CSTATE;

  /* Gain: '<S52>/Gain11' incorporates:
   *  Integrator: '<S72>/Integrator2'
   */
  GRM_HIL_B.ATT_Psi_rad_j = GRM_HIL_P.Gain11_Gain_d *
    GRM_HIL_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscretePulseGenerator: '<S16>/Pulse Generator1' */
>>>>>>> origin/master
    rtb_PulseGenerator1 = (GRM_HIL_DW.clockTickCounter <
      GRM_HIL_P.PulseGenerator1_Duty) && (GRM_HIL_DW.clockTickCounter >= 0) ?
      GRM_HIL_P.PulseGenerator1_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter >= GRM_HIL_P.PulseGenerator1_Period - 1.0) {
      GRM_HIL_DW.clockTickCounter = 0;
    } else {
      GRM_HIL_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator1' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator' */
    rtb_PulseGenerator = (GRM_HIL_DW.clockTickCounter_d <
                          GRM_HIL_P.PulseGenerator_Duty) &&
      (GRM_HIL_DW.clockTickCounter_d >= 0) ?
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
        rtb_PulseGenerator1 += GRM_HIL_P.Constant12_Value;
      } else {
        rtb_PulseGenerator1 = GRM_HIL_P.Constant7_Value;
      }

      /* End of Switch: '<S17>/Switch3' */
      rtb_PulseGenerator *= rtb_PulseGenerator1;
    } else {
      rtb_PulseGenerator =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.constant.phi_rad;
    }

    /* End of Switch: '<S17>/Switch1' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator4' */
    rtb_PulseGenerator4 = (GRM_HIL_DW.clockTickCounter_d3 <
      GRM_HIL_P.PulseGenerator4_Duty) && (GRM_HIL_DW.clockTickCounter_d3 >= 0) ?
      GRM_HIL_P.PulseGenerator4_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter_d3 >= GRM_HIL_P.PulseGenerator4_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_d3 = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_d3++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator4' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator3' */
    rtb_PulseGenerator1 = (GRM_HIL_DW.clockTickCounter_e <
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
        rtb_PulseGenerator4 += GRM_HIL_P.Constant13_Value;
      } else {
        rtb_PulseGenerator4 = GRM_HIL_P.Constant9_Value;
      }

      /* End of Switch: '<S17>/Switch4' */
      rtb_PulseGenerator1 *= rtb_PulseGenerator4;
    } else {
      rtb_PulseGenerator1 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.constant.acc_z_mDs2;
    }

    /* End of Switch: '<S17>/Switch' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator7' */
    rtb_VectorConcatenate_f_idx_0 = (GRM_HIL_DW.clockTickCounter_o <
      GRM_HIL_P.PulseGenerator7_Duty) && (GRM_HIL_DW.clockTickCounter_o >= 0) ?
      GRM_HIL_P.PulseGenerator7_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter_o >= GRM_HIL_P.PulseGenerator7_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_o = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_o++;
    }

    /* End of DiscretePulseGenerator: '<S17>/Pulse Generator7' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator6' */
    rtb_PulseGenerator4 = (GRM_HIL_DW.clockTickCounter_l <
      GRM_HIL_P.PulseGenerator6_Duty) && (GRM_HIL_DW.clockTickCounter_l >= 0) ?
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
        rtb_VectorConcatenate_f_idx_0 += GRM_HIL_P.Constant14_Value;
      } else {
        rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Constant11_Value;
      }

      /* End of Switch: '<S17>/Switch5' */
      rtb_PulseGenerator4 *= rtb_VectorConcatenate_f_idx_0;
    } else {
      rtb_PulseGenerator4 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.constant.acc_y_mDs2;
    }

<<<<<<< HEAD
    /* End of Switch: '<S17>/Switch2' */

    /* Product: '<S19>/Divide' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S19>/Constant1'
     */
    GRM_HIL_B.Sim_Sample_freq_Hz = GRM_HIL_P.Constant1_Value_a3 /
      GRM_HIL_P.HIL_Sample_Time;

    /* Constant: '<S7>/Constant10' */
    GRM_HIL_B.Pix_Com_freq_Hz = GRM_HIL_P.Constant10_Value_ly;

    /* Sum: '<S19>/Add' incorporates:
     *  Constant: '<S19>/Constant2'
     *  Product: '<S19>/Divide1'
     */
    GRM_HIL_B.Add = GRM_HIL_B.Sim_Sample_freq_Hz / GRM_HIL_B.Pix_Com_freq_Hz -
      GRM_HIL_P.Constant2_Value_aj;

    /* Memory: '<S19>/Memory' */
    GRM_HIL_B.Memory = GRM_HIL_DW.Memory_PreviousInput;

    /* MATLAB Function: '<S19>/Counter_with_external_limit' */
    GRM_HIL_Counter_with_external_limit(GRM_HIL_B.Add, GRM_HIL_B.Memory,
      &GRM_HIL_B.sf_Counter_with_external_limit);

    /* RelationalOperator: '<S19>/Equal' */
    GRM_HIL_B.Equal = (GRM_HIL_B.Add ==
                       GRM_HIL_B.sf_Counter_with_external_limit.value);

    /* Outputs for Enabled SubSystem: '<S18>/Com_to_FCC_emul' incorporates:
     *  EnablePort: '<S20>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Com_to_FCC_emul_MODE = GRM_HIL_B.Equal;
    }

    /* End of Outputs for SubSystem: '<S18>/Com_to_FCC_emul' */
  }

  /* Outputs for Enabled SubSystem: '<S18>/Com_to_FCC_emul' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (GRM_HIL_DW.Com_to_FCC_emul_MODE) {
    /* SignalConversion generated from: '<S20>/States_hold' */
    GRM_HIL_B.ATT_Phi_rad_f = GRM_HIL_B.ATT_Phi_rad;

    /* SignalConversion generated from: '<S20>/States_hold' */
    GRM_HIL_B.ACC_y_B_mDs2_o = GRM_HIL_B.ACC_y_B_mDs2;

    /* SignalConversion generated from: '<S20>/States_hold' */
    GRM_HIL_B.ACC_z_B_mDs2_e = GRM_HIL_B.ACC_z_B_mDs2;

    /* SignalConversion generated from: '<S20>/States_hold' */
    GRM_HIL_B.w_x_K_IB_B_radDs_f = GRM_HIL_B.w_x_K_IB_B_radDs;

    /* SignalConversion generated from: '<S20>/States_hold' */
    GRM_HIL_B.w_y_K_IB_B_radDs_e = GRM_HIL_B.w_y_K_IB_B_radDs;

    /* SignalConversion generated from: '<S20>/States_hold' */
    GRM_HIL_B.w_z_K_IB_B_radDs_n = GRM_HIL_B.w_z_K_IB_B_radDs;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S20>/External_Inputs_hold' */
      GRM_HIL_B.CMD_phi_rad = rtb_PulseGenerator;

      /* SignalConversion generated from: '<S20>/External_Inputs_hold' */
      GRM_HIL_B.CMD_acc_z_mDs2 = rtb_PulseGenerator1;

      /* SignalConversion generated from: '<S20>/External_Inputs_hold' */
      GRM_HIL_B.CMD_acc_y_mDs2 = rtb_PulseGenerator4;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Com_to_FCC_emul_SubsysRanBC);
=======
    /* End of Switch: '<S16>/Switch2' */
  }

  /* TransferFcn: '<S54>/dr2roll' */
  rtb_p_B_radDs = GRM_HIL_P.FDM_Linear_TF.dr2roll.num /
    GRM_HIL_P.FDM_Linear_TF.dr2roll.denom[0] * GRM_HIL_X.dr2roll_CSTATE;

  /* Gain: '<S52>/Gain6' */
  GRM_HIL_B.w_x_K_IB_B_radDs = GRM_HIL_P.Gain6_Gain * rtb_p_B_radDs;

  /* TransferFcn: '<S54>/dp2pitch' */
  rtb_q_B_radDs = GRM_HIL_P.FDM_Linear_TF.dp2pitch.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[0] +
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[1];

  /* Gain: '<S52>/Gain7' */
  GRM_HIL_B.w_y_K_IB_B_radDs = GRM_HIL_P.Gain7_Gain * rtb_q_B_radDs;

  /* TransferFcn: '<S54>/dy2yaw' */
  rtb_r_B_radDs = GRM_HIL_P.FDM_Linear_TF.dy2yaw.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[0] +
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[1];

  /* Gain: '<S52>/Gain8' */
  GRM_HIL_B.w_z_K_IB_B_radDs = GRM_HIL_P.Gain8_Gain * rtb_r_B_radDs;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtpi): '<S37>/Receive_from_FTHWICC' */
    /* S-Function Block: <S37>/Receive_from_FTHWICC */
    {
      uint8_T indata[66U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 66U,
        &GRM_HIL_P.Receive_from_FTHWICC_PacketID, (double*) indata, NULL);
      rtb_Receive_from_FTHWICC_o11 = (status>>1) & 0x1;/* Data Error port */
      rtb_Receive_from_FTHWICC_o10 = status & 0x1;/* Data Ready port */
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

    /* Outputs for Enabled SubSystem: '<S37>/Construct_Bus' incorporates:
     *  EnablePort: '<S39>/Enable'
     */
    /* Logic: '<S37>/Logical Operator' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S43>/Constant10'
     *  Constant: '<S43>/Constant11'
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Constant: '<S43>/Constant4'
     *  Constant: '<S43>/Constant5'
     *  Constant: '<S43>/Constant6'
     *  Constant: '<S43>/Constant7'
     *  Constant: '<S43>/Constant8'
     *  Constant: '<S43>/Constant9'
     *  Logic: '<S37>/NOT'
     *  Trigonometry: '<S45>/sincos'
     */
    if (rtb_Receive_from_FTHWICC_o10 && (!rtb_Receive_from_FTHWICC_o11)) {
      /* SignalConversion generated from: '<S39>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_operational_flg = GRM_HIL_B.Receive_from_FTHWICC_o1;

      /* SignalConversion generated from: '<S39>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_Ramp_flg = GRM_HIL_B.Receive_from_FTHWICC_o2;

      /* SignalConversion generated from: '<S39>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_B.Receive_from_FTHWICC_o3;

      /* SignalConversion generated from: '<S39>/Gimbal_Status' */
      GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_B.Receive_from_FTHWICC_o4;
      GRM_HIL_B.Data_plus = GRM_HIL_P.Constant_Value;
      GRM_HIL_B.Data_minus = GRM_HIL_P.Constant1_Value;
      GRM_HIL_B.Clock_plus = GRM_HIL_P.Constant2_Value;
      GRM_HIL_B.Clock_minus = GRM_HIL_P.Constant3_Value;

      /* SignalConversion generated from: '<S43>/Constant1' incorporates:
       *  Constant: '<S43>/Constant'
       *  Constant: '<S43>/Constant1'
       *  Constant: '<S43>/Constant2'
       *  Constant: '<S43>/Constant3'
       */
      GRM_HIL_B.Data_minus_o = GRM_HIL_B.Data_minus;

      /* SignalConversion generated from: '<S43>/Constant2' */
      GRM_HIL_B.Clock_plus_f = GRM_HIL_B.Clock_plus;

      /* SignalConversion generated from: '<S43>/Constant3' */
      GRM_HIL_B.Clock_minus_c = GRM_HIL_B.Clock_minus;

      /* SignalConversion generated from: '<S43>/Constant' */
      GRM_HIL_B.Data_plus_j = GRM_HIL_B.Data_plus;
      GRM_HIL_B.Data_plus_p = GRM_HIL_P.Constant4_Value;
      GRM_HIL_B.Data_minus_p = GRM_HIL_P.Constant5_Value;
      GRM_HIL_B.Clock_plus_j = GRM_HIL_P.Constant6_Value;
      GRM_HIL_B.Clock_minus_e = GRM_HIL_P.Constant7_Value_h;

      /* SignalConversion generated from: '<S43>/Constant4' incorporates:
       *  Constant: '<S43>/Constant4'
       *  Constant: '<S43>/Constant5'
       *  Constant: '<S43>/Constant6'
       *  Constant: '<S43>/Constant7'
       */
      GRM_HIL_B.Data_plus_j1 = GRM_HIL_B.Data_plus_p;

      /* SignalConversion generated from: '<S43>/Constant5' */
      GRM_HIL_B.Data_minus_oy = GRM_HIL_B.Data_minus_p;

      /* SignalConversion generated from: '<S43>/Constant6' */
      GRM_HIL_B.Clock_plus_fx = GRM_HIL_B.Clock_plus_j;

      /* SignalConversion generated from: '<S43>/Constant7' */
      GRM_HIL_B.Clock_minus_cm = GRM_HIL_B.Clock_minus_e;
      GRM_HIL_B.Clock_plus_m = GRM_HIL_P.Constant10_Value;
      GRM_HIL_B.Clock_minus_h = GRM_HIL_P.Constant11_Value_d;
      GRM_HIL_B.Data_plus_g = GRM_HIL_P.Constant8_Value;
      GRM_HIL_B.Data_minus_d = GRM_HIL_P.Constant9_Value_g;

      /* SignalConversion generated from: '<S43>/Constant10' incorporates:
       *  Constant: '<S43>/Constant10'
       *  Constant: '<S43>/Constant11'
       *  Constant: '<S43>/Constant8'
       *  Constant: '<S43>/Constant9'
       */
      GRM_HIL_B.Clock_plus_fx0 = GRM_HIL_B.Clock_plus_m;

      /* SignalConversion generated from: '<S43>/Constant11' */
      GRM_HIL_B.Clock_minus_cmq = GRM_HIL_B.Clock_minus_h;

      /* SignalConversion generated from: '<S43>/Constant8' */
      GRM_HIL_B.Data_plus_j13 = GRM_HIL_B.Data_plus_g;

      /* SignalConversion generated from: '<S43>/Constant9' */
      GRM_HIL_B.Data_minus_oyn = GRM_HIL_B.Data_minus_d;

      /* Gain: '<S42>/Shaft2radYaw' */
      GRM_HIL_B.ATT_Psi_rad_o = GRM_HIL_P.Shaft2radYaw_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o5;

      /* Gain: '<S42>/Shaft2radPitch' */
      GRM_HIL_B.ATT_Theta_rad_j = GRM_HIL_P.Shaft2radPitch_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o6;

      /* Gain: '<S42>/Shaft2radRoll' */
      GRM_HIL_B.ATT_Phi_rad_lz = GRM_HIL_P.Shaft2radRoll_Gain *
        GRM_HIL_B.Receive_from_FTHWICC_o7;

      /* Gain: '<S45>/1//2' */
      rtb_sincos_o1_idx_0 = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Psi_rad_o;
      rtb_sincos_o1_idx_1 = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Theta_rad_j;
      rtb_sincos_o1_idx_2 = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Phi_rad_lz;

      /* Trigonometry: '<S45>/sincos' */
      rtb_sincos_o2_idx_0 = cos(rtb_sincos_o1_idx_0);
      rtb_sincos_o1_idx_0 = sin(rtb_sincos_o1_idx_0);

      /* Trigonometry: '<S45>/sincos' */
      rtb_PulseGenerator1 = cos(rtb_sincos_o1_idx_1);
      rtb_sincos_o1_idx_1 = sin(rtb_sincos_o1_idx_1);

      /* Trigonometry: '<S45>/sincos' */
      rtb_PulseGenerator = cos(rtb_sincos_o1_idx_2);
      rtb_sincos_o1_idx_2 = sin(rtb_sincos_o1_idx_2);

      /* Fcn: '<S45>/q0' incorporates:
       *  Fcn: '<S45>/q3'
       */
      rtb_Add3 = rtb_sincos_o2_idx_0 * rtb_PulseGenerator1;
      rtb_Add16_j = rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1;
      GRM_HIL_B.q0 = rtb_Add3 * rtb_PulseGenerator - rtb_Add16_j *
        rtb_sincos_o1_idx_2;

      /* Fcn: '<S45>/q1' incorporates:
       *  Fcn: '<S45>/q2'
       */
      rtb_sincos_o1_idx_1 *= rtb_sincos_o2_idx_0;
      rtb_sincos_o1_idx_0 *= rtb_PulseGenerator1;
      GRM_HIL_B.q1 = rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_2 +
        rtb_sincos_o1_idx_0 * rtb_PulseGenerator;

      /* Fcn: '<S45>/q2' */
      GRM_HIL_B.q2 = rtb_sincos_o1_idx_1 * rtb_PulseGenerator -
        rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_2;

      /* Fcn: '<S45>/q3' */
      GRM_HIL_B.q3 = rtb_Add3 * rtb_sincos_o1_idx_2 + rtb_Add16_j *
        rtb_PulseGenerator;

      /* SignalConversion generated from: '<S39>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_yaw_sns = GRM_HIL_B.Receive_from_FTHWICC_o5;

      /* SignalConversion generated from: '<S39>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_pitch_sns = GRM_HIL_B.Receive_from_FTHWICC_o6;

      /* SignalConversion generated from: '<S39>/Gimbal_Pos_Encoder' */
      GRM_HIL_B.Gimbal_roll_sns = GRM_HIL_B.Receive_from_FTHWICC_o7;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Construct_Bus_SubsysRanBC);
      }
    }

    /* End of Logic: '<S37>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S37>/Construct_Bus' */
  }

  /* Gain: '<S49>/rad2deg' */
  GRM_HIL_B.Gimbal_Phi_Cmd_deg = GRM_HIL_P.rad2deg_Gain *
    GRM_HIL_B.ATT_Phi_rad_l;

  /* Gain: '<S49>/rad2deg1' */
  GRM_HIL_B.Gimbal_Theta_Cmd_deg = GRM_HIL_P.rad2deg1_Gain *
    GRM_HIL_B.ATT_Theta_rad_k;

  /* Gain: '<S49>/rad2deg2' */
  GRM_HIL_B.Gimbal_Psi_Cmd_deg = GRM_HIL_P.rad2deg2_Gain *
    GRM_HIL_B.ATT_Psi_rad_j;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S18>/Add' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S18>/Constant1'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S7>/Constant10'
     *  Product: '<S18>/Divide'
     *  Product: '<S18>/Divide1'
     */
    rtb_Add_n = GRM_HIL_P.Constant1_Value_a / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant10_Value_l - GRM_HIL_P.Constant2_Value_a;

    /* Memory: '<S18>/Memory' */
    rtb_Memory = GRM_HIL_DW.Memory_PreviousInput;

    /* MATLAB Function: '<S18>/Counter_with_external_limit' */
    GRM_HIL_Counter_with_external_limit(rtb_Add_n, rtb_Memory,
      &GRM_HIL_B.sf_Counter_with_external_limit);

    /* RelationalOperator: '<S18>/Equal' */
    GRM_HIL_B.Equal = (rtb_Add_n ==
                       GRM_HIL_B.sf_Counter_with_external_limit.value);

    /* Outputs for Enabled SubSystem: '<S17>/Com_to_FCC_emul' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Com_to_FCC_emul_MODE = GRM_HIL_B.Equal;
>>>>>>> origin/master
    }

    /* End of Outputs for SubSystem: '<S17>/Com_to_FCC_emul' */
  }

<<<<<<< HEAD
  /* End of Outputs for SubSystem: '<S18>/Com_to_FCC_emul' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S26>/Gain2' */
    GRM_HIL_B.phi_rad = GRM_HIL_P.Gain2_Gain_b * GRM_HIL_B.CMD_phi_rad;
  }

  /* DataTypeConversion: '<S25>/Cast To Double' incorporates:
   *  Gain: '<S25>/Gain5'
   *  Gain: '<S25>/Gain6'
   *  Gain: '<S25>/Gain7'
   *  Sum: '<S25>/Sum'
   *  Sum: '<S25>/Sum7'
   */
  GRM_HIL_B.Phi_Cmd_rad = ((GRM_HIL_B.phi_rad - GRM_HIL_B.ATT_Phi_rad_f) *
    GRM_HIL_P.Gain6_Gain_at - GRM_HIL_B.w_x_K_IB_B_radDs_f) *
    GRM_HIL_P.Gain5_Gain_m * GRM_HIL_P.Gain7_Gain_b;

  /* Saturate: '<S24>/Limit2maxDeflection' */
  if (GRM_HIL_B.Phi_Cmd_rad >
      GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_VectorConcatenate_f_idx_0 =
      GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else if (GRM_HIL_B.Phi_Cmd_rad <
             -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_VectorConcatenate_f_idx_0 =
      -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_B.Phi_Cmd_rad;
  }

  /* End of Saturate: '<S24>/Limit2maxDeflection' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S26>/Gain' */
    GRM_HIL_B.acc_y_mDs2 = GRM_HIL_P.Gain_Gain_eu * GRM_HIL_B.CMD_acc_y_mDs2;

    /* Gain: '<S26>/Gain1' */
    GRM_HIL_B.acc_z_mDs2 = GRM_HIL_P.Gain1_Gain_cw * GRM_HIL_B.CMD_acc_z_mDs2;
  }

  /* Sum: '<S25>/Sum3' */
  GRM_HIL_B.Sum3 = GRM_HIL_B.acc_y_mDs2 - GRM_HIL_B.ACC_y_B_mDs2_o;

  /* Gain: '<S25>/Gain2' incorporates:
   *  Gain: '<S25>/Gain4'
   *  Sum: '<S25>/Sum4'
   *  Sum: '<S25>/Sum6'
   *  TransferFcn: '<S25>/Transfer Fcn2'
   */
  GRM_HIL_B.Psi_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Num /
      GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[0] *
      GRM_HIL_X.TransferFcn2_CSTATE_e +
      GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.PropGain * GRM_HIL_B.Sum3) -
     GRM_HIL_B.w_z_K_IB_B_radDs_n) *
    GRM_HIL_P.FlightController_FCC.Yaw.innerLoop.PropGain;

  /* Sum: '<S25>/Sum1' */
  GRM_HIL_B.Sum1 = GRM_HIL_B.acc_z_mDs2 - GRM_HIL_B.ACC_z_B_mDs2_e;

  /* Gain: '<S25>/Gain1' incorporates:
   *  Gain: '<S25>/Gain3'
   *  Sum: '<S25>/Sum2'
   *  Sum: '<S25>/Sum5'
   *  TransferFcn: '<S25>/Transfer Fcn1'
   */
  GRM_HIL_B.Theta_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Num /
      GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[0] *
      GRM_HIL_X.TransferFcn1_CSTATE_e +
      GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.PropGain * GRM_HIL_B.Sum1)
     - GRM_HIL_B.w_y_K_IB_B_radDs_e) *
    GRM_HIL_P.FlightController_FCC.Pitch.innerLoop.PropGain;

  /* Sum: '<S24>/Add4' incorporates:
   *  Constant: '<S24>/Constant'
   *  Sum: '<S24>/Add5'
   */
  rtb_PulseGenerator = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f1_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add' incorporates:
   *  Fcn: '<S24>/Fcn'
   *  Fcn: '<S24>/Fcn1'
   *  Product: '<S24>/Multiply'
   *  Product: '<S24>/Multiply1'
   *  Sum: '<S24>/Add4'
   */
  rtb_PulseGenerator = -cos(rtb_PulseGenerator) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_PulseGenerator) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S24>/Add6' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Sum: '<S24>/Add7'
   */
  rtb_PulseGenerator1 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f2_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add1' incorporates:
   *  Fcn: '<S24>/Fcn2'
   *  Fcn: '<S24>/Fcn3'
   *  Product: '<S24>/Multiply2'
   *  Product: '<S24>/Multiply3'
   *  Sum: '<S24>/Add6'
   */
  rtb_PulseGenerator1 = -cos(rtb_PulseGenerator1) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_PulseGenerator1) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S24>/Add8' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Sum: '<S24>/Add9'
   */
  rtb_PulseGenerator4 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f3_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add2' incorporates:
   *  Fcn: '<S24>/Fcn4'
   *  Fcn: '<S24>/Fcn5'
   *  Product: '<S24>/Multiply4'
   *  Product: '<S24>/Multiply5'
   *  Sum: '<S24>/Add8'
   */
  rtb_PulseGenerator4 = -cos(rtb_PulseGenerator4) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_PulseGenerator4) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S24>/Add10' incorporates:
   *  Constant: '<S24>/Constant3'
   *  Sum: '<S24>/Add11'
   */
  rtb_Subtract_cl = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f4_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add3' incorporates:
   *  Fcn: '<S24>/Fcn6'
   *  Fcn: '<S24>/Fcn7'
   *  Product: '<S24>/Multiply6'
   *  Product: '<S24>/Multiply7'
   *  Sum: '<S24>/Add10'
   */
  rtb_e = -cos(rtb_Subtract_cl) * GRM_HIL_B.Psi_Cmd_rad + sin(rtb_Subtract_cl) *
    GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S24>/Add16' incorporates:
   *  Abs: '<S24>/Abs'
   *  Constant: '<S24>/Constant4'
   */
  rtb_Subtract_cl = GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad
    - fabs(rtb_VectorConcatenate_f_idx_0);

  /* Logic: '<S30>/OR' incorporates:
   *  Abs: '<S30>/Abs'
   *  Abs: '<S30>/Abs1'
   *  Abs: '<S30>/Abs2'
   *  Abs: '<S30>/Abs3'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  RelationalOperator: '<S30>/Relational Operator1'
   *  RelationalOperator: '<S30>/Relational Operator2'
   *  RelationalOperator: '<S30>/Relational Operator3'
   */
  GRM_HIL_B.OR = ((fabs(rtb_PulseGenerator) > rtb_Subtract_cl) || (fabs
    (rtb_PulseGenerator1) > rtb_Subtract_cl) || (fabs(rtb_PulseGenerator4) >
    rtb_Subtract_cl) || (fabs(rtb_e) > rtb_Subtract_cl));

  /* Logic: '<S29>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_a = !GRM_HIL_B.OR;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S31>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4 =
      GRM_HIL_B.LogicalOperator_a;

    /* Outputs for Enabled SubSystem: '<S29>/Pass' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Pass_MODE = GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4;
    }

    /* End of Outputs for SubSystem: '<S29>/Pass' */
  }

  /* Outputs for Enabled SubSystem: '<S29>/Pass' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (GRM_HIL_DW.Pass_MODE) {
    /* Inport: '<S31>/Fin_1_Cmd_rad' */
    GRM_HIL_B.Merge = rtb_PulseGenerator;

    /* Inport: '<S31>/Fin_2_Cmd_rad' */
    GRM_HIL_B.Merge1 = rtb_PulseGenerator1;

    /* Inport: '<S31>/Fin_3_Cmd_rad' */
    GRM_HIL_B.Merge2 = rtb_PulseGenerator4;

    /* Inport: '<S31>/Fin_4_Cmd_rad' */
    GRM_HIL_B.Merge3 = rtb_e;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Pass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S29>/Pass' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S32>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturate_at_inport_5 = GRM_HIL_B.OR;

    /* Outputs for Enabled SubSystem: '<S29>/Saturate' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Saturate_MODE =
        GRM_HIL_B.HiddenBuf_InsertedFor_Saturate_at_inport_5;
    }

    /* End of Outputs for SubSystem: '<S29>/Saturate' */
  }

  /* Outputs for Enabled SubSystem: '<S29>/Saturate' incorporates:
   *  EnablePort: '<S32>/Enable'
   */
  if (GRM_HIL_DW.Saturate_MODE) {
    /* Abs: '<S32>/Abs1' incorporates:
     *  MinMax: '<S32>/Max'
     */
    rtb_Step1 = fabs(fmax(fmax(fmax(rtb_PulseGenerator, rtb_PulseGenerator1),
      rtb_PulseGenerator4), rtb_e));

    /* Product: '<S32>/Multiply' incorporates:
     *  Product: '<S32>/Divide'
     */
    GRM_HIL_B.Merge = rtb_PulseGenerator / rtb_Step1 * rtb_Subtract_cl;

    /* Product: '<S32>/Multiply1' incorporates:
     *  Product: '<S32>/Divide1'
     */
    GRM_HIL_B.Merge1 = rtb_PulseGenerator1 / rtb_Step1 * rtb_Subtract_cl;

    /* Product: '<S32>/Multiply2' incorporates:
     *  Product: '<S32>/Divide4'
     */
    GRM_HIL_B.Merge2 = rtb_PulseGenerator4 / rtb_Step1 * rtb_Subtract_cl;

    /* Product: '<S32>/Multiply3' incorporates:
     *  Product: '<S32>/Divide2'
     */
    GRM_HIL_B.Merge3 = rtb_e / rtb_Step1 * rtb_Subtract_cl;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Saturate_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S29>/Saturate' */

  /* Product: '<S36>/Product' incorporates:
   *  Constant: '<S33>/Constant6'
   *  Constant: '<S34>/Constant6'
   *  Constant: '<S35>/Constant6'
   *  Constant: '<S36>/Constant6'
   *  Product: '<S33>/Product'
   *  Product: '<S34>/Product'
   *  Product: '<S35>/Product'
   */
  rtb_PulseGenerator = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms -
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant6'
   *  Product: '<S36>/Divide'
   *  Product: '<S36>/Product'
   *  Sum: '<S24>/Add14'
   */
  u0 = (rtb_VectorConcatenate_f_idx_0 + GRM_HIL_B.Merge3) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_PulseGenerator
    + GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S36>/Saturation' */
  if (u0 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (u0 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms = u0;
  }

  /* End of Saturate: '<S36>/Saturation' */

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S35>/Constant2'
   *  Product: '<S35>/Divide'
   *  Product: '<S35>/Product'
   *  Sum: '<S24>/Add13'
   */
  u0 = (rtb_VectorConcatenate_f_idx_0 + GRM_HIL_B.Merge2) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_PulseGenerator
    + GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S35>/Saturation' */
  if (u0 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (u0 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_e = u0;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S34>/Constant2'
   *  Product: '<S34>/Divide'
   *  Product: '<S34>/Product'
   *  Sum: '<S24>/Add12'
   */
  u0 = (rtb_VectorConcatenate_f_idx_0 + GRM_HIL_B.Merge1) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_PulseGenerator
    + GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S34>/Saturation' */
  if (u0 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (u0 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_c = u0;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S33>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S33>/Constant2'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Product'
   *  Sum: '<S24>/Add15'
   */
  u0 = (rtb_VectorConcatenate_f_idx_0 + GRM_HIL_B.Merge) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_PulseGenerator
    + GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S33>/Saturation' */
  if (u0 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_p = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (u0 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_p = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_p = u0;
  }

  /* End of Saturate: '<S33>/Saturation' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[4] == 0) {
    /* S-Function (fcncallgen): '<S18>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S18>/FB_Com_freq_emul'
     */
    GRM_HIL_DW.FB_Com_freq_emul_SubsysRanBC = 4;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator1' */

    /* Product: '<S13>/Divide' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S16>/Constant1'
     *  Product: '<S14>/Divide'
     *  Product: '<S15>/Divide'
     *  Product: '<S16>/Divide'
     */
    rtb_PulseGenerator = GRM_HIL_P.Servo_PWM.Pulswidth_cmd_max_ms -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms;

    /* S-Function (fcncallgen): '<S18>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S18>/FB_Com_freq_emul'
     */
    /* Product: '<S13>/Multiply' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Product: '<S13>/Divide'
     *  SignalConversion generated from: '<S21>/hold'
     *  Sum: '<S13>/Add'
     */
    u0 = (GRM_HIL_B.pulse_width_ms_p -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator1' */

    /* Saturate: '<S13>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation = u0;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* S-Function (fcncallgen): '<S18>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S18>/FB_Com_freq_emul'
     */
    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant2'
     *  Product: '<S14>/Divide'
     *  SignalConversion generated from: '<S21>/hold'
     *  Sum: '<S14>/Add'
     */
    u0 = (GRM_HIL_B.pulse_width_ms_c -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator1' */

    /* Saturate: '<S14>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_c = u0;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* S-Function (fcncallgen): '<S18>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S18>/FB_Com_freq_emul'
     */
    /* Product: '<S15>/Multiply' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant2'
     *  Product: '<S15>/Divide'
     *  SignalConversion generated from: '<S21>/hold'
     *  Sum: '<S15>/Add'
     */
    u0 = (GRM_HIL_B.pulse_width_ms_e -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator1' */

    /* Saturate: '<S15>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_j = u0;
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* S-Function (fcncallgen): '<S18>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S18>/FB_Com_freq_emul'
     */
    /* Product: '<S16>/Multiply' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant2'
     *  Product: '<S16>/Divide'
     *  SignalConversion generated from: '<S21>/hold'
     *  Sum: '<S16>/Add'
     */
    u0 = (GRM_HIL_B.pulse_width_ms -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator1' */

    /* Saturate: '<S16>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_a = u0;
    }

    /* End of Saturate: '<S16>/Saturation' */
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S7>/Constant' */
    GRM_HIL_B.run = GRM_HIL_P.Constant_Value_gt;

    /* Constant: '<S7>/Constant2' */
    GRM_HIL_B.reset = GRM_HIL_P.Constant2_Value_f5;

    /* Constant: '<S7>/Constant7' */
    GRM_HIL_B.enable_gimbal_ctrl_flg = GRM_HIL_P.Constant7_Value_e;

    /* Constant: '<S7>/Constant8' */
    GRM_HIL_B.stop_gimbal_flg = GRM_HIL_P.Constant8_Value_lr;

    /* UnitDelay: '<S243>/Output' */
    rtb_FixPtSum1 = GRM_HIL_DW.Output_DSTATE;

    /* DataTypeConversion: '<S242>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S243>/Output'
     */
    GRM_HIL_B.DataTypeConversion1 = GRM_HIL_DW.Output_DSTATE;
  }

  /* Gain: '<S50>/rad2deg' */
  GRM_HIL_B.Gimbal_Phi_Cmd_deg = GRM_HIL_P.rad2deg_Gain * GRM_HIL_B.ATT_Phi_rad;

  /* Gain: '<S50>/rad2deg1' */
  GRM_HIL_B.Gimbal_Theta_Cmd_deg = GRM_HIL_P.rad2deg1_Gain *
    GRM_HIL_B.ATT_Theta_rad;

  /* Gain: '<S50>/rad2deg2' */
  GRM_HIL_B.Gimbal_Psi_Cmd_deg = GRM_HIL_P.rad2deg2_Gain * GRM_HIL_B.ATT_Psi_rad;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
    /* Constant: '<S38>/Constant' */
    GRM_HIL_B.Constant_i = GRM_HIL_P.Constant_Value_p3;
  }

  /* Outputs for Enabled SubSystem: '<S38>/Send_to_FTHWICC' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S39>/Constant3' */
    GRM_HIL_DW.Send_to_FTHWICC_MODE = GRM_HIL_P.Constant3_Value_k;
  }

  if (GRM_HIL_DW.Send_to_FTHWICC_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
      /* S-Function (sldrtpo): '<S41>/Send_to_FTHWICC' */
      /* S-Function Block: <S41>/Send_to_FTHWICC */

      /* no code required */
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* ToAsyncQueueBlock generated from: '<S41>/Gimbal_Phi_Cmd_deg' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.Gimbal_Phi_Cmd_deg;
          int32_T size = 1*sizeof(real_T);
          sendToAsyncQueueTgtAppSvc(3818145517U, time, pData, size);
        }
      }
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);
=======
  /* Outputs for Enabled SubSystem: '<S17>/Com_to_FCC_emul' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (GRM_HIL_DW.Com_to_FCC_emul_MODE) {
    /* ManualSwitch generated from: '<S50>/Manual Switch' */
    if (GRM_HIL_P.ManualSwitch_10_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.ATT_Phi_rad_f = GRM_HIL_B.ATT_Phi_rad_l;
    } else {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.ATT_Phi_rad_f = 0.0;
    }

    /* ManualSwitch generated from: '<S50>/Manual Switch' */
    if (GRM_HIL_P.ManualSwitch_5_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.ACC_y_B_mDs2_o = GRM_HIL_B.ACC_y_B_mDs2;
    } else {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.ACC_y_B_mDs2_o = 0.0;
    }

    /* ManualSwitch generated from: '<S50>/Manual Switch' */
    if (GRM_HIL_P.ManualSwitch_6_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.ACC_z_B_mDs2_e = GRM_HIL_B.ACC_z_B_mDs2;
    } else {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.ACC_z_B_mDs2_e = 0.0;
    }

    /* ManualSwitch generated from: '<S50>/Manual Switch' */
    if (GRM_HIL_P.ManualSwitch_7_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.w_x_K_IB_B_radDs_f = GRM_HIL_B.w_x_K_IB_B_radDs;
    } else {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.w_x_K_IB_B_radDs_f = 0.0;
    }

    /* ManualSwitch generated from: '<S50>/Manual Switch' */
    if (GRM_HIL_P.ManualSwitch_8_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.w_y_K_IB_B_radDs_e = GRM_HIL_B.w_y_K_IB_B_radDs;
    } else {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.w_y_K_IB_B_radDs_e = 0.0;
>>>>>>> origin/master
    }
  }

<<<<<<< HEAD
  /* End of Outputs for SubSystem: '<S38>/Send_to_FTHWICC' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S39>/Add' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant1'
     *  Constant: '<S39>/Constant2'
     *  Constant: '<S7>/Constant11'
     *  Product: '<S39>/Divide'
     *  Product: '<S39>/Divide1'
     */
    rtb_Add_d = GRM_HIL_P.Constant1_Value_e / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant11_Value_p3 - GRM_HIL_P.Constant2_Value_ik;

    /* Memory: '<S39>/Memory' */
    rtb_Memory = GRM_HIL_DW.Memory_PreviousInput_d;

    /* MATLAB Function: '<S39>/Counter_with_external_limit' */
    GRM_HIL_Counter_with_external_limit(rtb_Add_d, rtb_Memory,
      &GRM_HIL_B.sf_Counter_with_external_limit_j);

    /* Gain: '<S70>/Gain1' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Gain1_Gain_ps *
      GRM_HIL_P.Constant1_Value_lj;

    /* Gain: '<S71>/Gain1' incorporates:
     *  Constant: '<S55>/Constant2'
     */
    rtb_VectorConcatenate_f_idx_1 = GRM_HIL_P.Gain1_Gain_n3 *
      GRM_HIL_P.Constant2_Value_ff;

    /* Gain: '<S72>/Gain1' incorporates:
     *  Constant: '<S55>/Constant3'
     */
    rtb_VectorConcatenate_f_idx_2 = GRM_HIL_P.Gain1_Gain_g *
      GRM_HIL_P.Constant3_Value_i5;

    /* Product: '<S73>/Product' incorporates:
     *  Constant: '<S73>/Constant7'
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

    /* End of Product: '<S73>/Product' */

    /* Product: '<S218>/Product' incorporates:
     *  Constant: '<S218>/Constant'
     *  Constant: '<S218>/Constant6'
     */
    GRM_HIL_B.Product_a = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant6_Value_d5;
  }

  /* Sum: '<S55>/Sum' incorporates:
   *  SignalConversion generated from: '<S55>/Vector Concatenate'
   */
  rtb_Product4_n[0] = GRM_HIL_B.Fin_1_Pos_rad + GRM_HIL_B.siB_cmd[0];
  rtb_Product4_n[1] = GRM_HIL_B.Fin_2_Pos_rad + GRM_HIL_B.siB_cmd[1];
  rtb_Product4_n[2] = GRM_HIL_B.Fin_3_Pos_rad + GRM_HIL_B.siB_cmd[2];
  rtb_Product_l = GRM_HIL_B.Fin_4_Pos_rad + GRM_HIL_B.siB_cmd[3];

  /* Sum: '<S220>/Add' incorporates:
   *  Constant: '<S220>/Constant2'
   */
  rtb_Product7_ma = GRM_HIL_P.Constant2_Value_p - rtb_Product7_ma;

  /* Sum: '<S218>/Add4' incorporates:
   *  Constant: '<S218>/Constant3'
   *  Constant: '<S218>/Constant4'
   *  Product: '<S218>/Divide'
   *  Product: '<S218>/Product1'
   *  Sum: '<S218>/Add'
   */
  frac_2[0] = (rtb_Product7_ma * GRM_HIL_P.Constant4_Value_p +
               GRM_HIL_B.Product_a) * (1.0 / rtb_Subtract_ju) +
    GRM_HIL_P.Constant3_Value_fn;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S218>/Product2' incorporates:
     *  Constant: '<S218>/Constant'
     *  Constant: '<S218>/Constant5'
     */
    GRM_HIL_B.Product2 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant5_Value_e;

    /* Product: '<S218>/Product4' incorporates:
     *  Constant: '<S218>/Constant'
     *  Constant: '<S218>/Constant8'
     */
    GRM_HIL_B.Product4 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant8_Value_l5;
  }

  /* Sum: '<S218>/Add3' incorporates:
   *  Constant: '<S218>/Constant1'
   *  Constant: '<S218>/Constant7'
   *  Product: '<S218>/Divide1'
   *  Product: '<S218>/Product3'
   *  Sum: '<S218>/Add1'
   */
  frac_2[1] = (rtb_Product7_ma * GRM_HIL_P.Constant7_Value_jc +
               GRM_HIL_B.Product2) * (1.0 / rtb_Subtract_ju) +
    GRM_HIL_P.Constant1_Value_in;

  /* Sum: '<S218>/Add5' incorporates:
   *  Constant: '<S218>/Constant2'
   *  Constant: '<S218>/Constant9'
   *  Product: '<S218>/Divide2'
   *  Product: '<S218>/Product5'
   *  Sum: '<S218>/Add2'
   */
  frac_2[2] = (rtb_Product7_ma * GRM_HIL_P.Constant9_Value_c +
               GRM_HIL_B.Product4) * (1.0 / rtb_Subtract_ju) +
    GRM_HIL_P.Constant2_Value_mg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S84>/Vector Concatenate' incorporates:
     *  Constant: '<S84>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[0] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S84>/Vector Concatenate' incorporates:
     *  Constant: '<S84>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[1] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S84>/Vector Concatenate' incorporates:
     *  Constant: '<S84>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[2] = GRM_HIL_P.Constant3_Value_m;

    /* Switch: '<S89>/Switch1' incorporates:
     *  Constant: '<S89>/Constant'
     *  Constant: '<S89>/Constant2'
     *  Constant: '<S90>/c_flat'
     *  Constant: '<S90>/c_rsma'
     *  Constant: '<S91>/Constant'
     *  Gain: '<S89>/Gain'
     *  Gain: '<S91>/Gain'
     *  Product: '<S91>/Product'
     *  Product: '<S91>/Product4'
     *  Product: '<S91>/Product5'
     *  Sqrt: '<S91>/Sqrt1'
     *  Sum: '<S91>/Subtract'
     *  Sum: '<S91>/Subtract1'
     *  Sum: '<S91>/Sum'
     *  Trigonometry: '<S91>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_ad > GRM_HIL_P.Switch1_Threshold_n) {
      GRM_HIL_B.hBE_0_h = GRM_HIL_P.Gain_Gain_f * GRM_HIL_P.Constant_Value_iee[2];
    } else {
      /* Sqrt: '<S92>/Sqrt' incorporates:
       *  Constant: '<S89>/Constant'
       *  Product: '<S92>/Product1'
       *  Product: '<S92>/Product2'
       *  Sqrt: '<S91>/Sqrt'
       *  Sum: '<S92>/Add'
       */
      rtb_PulseGenerator = sqrt(GRM_HIL_P.Constant_Value_iee[0] *
        GRM_HIL_P.Constant_Value_iee[0] + GRM_HIL_P.Constant_Value_iee[1] *
        GRM_HIL_P.Constant_Value_iee[1]);

      /* Product: '<S92>/Product' incorporates:
       *  Constant: '<S90>/c_flat'
       *  Constant: '<S90>/c_rsma'
       *  Constant: '<S92>/Constant'
       *  Sum: '<S92>/Subtract'
       */
      rtb_PulseGenerator1 = (GRM_HIL_P.Constant_Value_f -
        GRM_HIL_P.c_flat_Value_f) * GRM_HIL_P.c_rsma_Value_b;

      /* Trigonometry: '<S92>/Trigonometric Function' incorporates:
       *  Constant: '<S89>/Constant'
       *  Constant: '<S90>/c_rsma'
       *  Product: '<S92>/Divide1'
       *  Product: '<S92>/Product6'
       *  Product: '<S92>/Product7'
       *  Sqrt: '<S92>/Sqrt'
       */
      rtb_PulseGenerator4 = atan(GRM_HIL_P.Constant_Value_iee[2] *
        GRM_HIL_P.c_rsma_Value_b / (rtb_PulseGenerator * rtb_PulseGenerator1));

      /* Trigonometry: '<S92>/Trigonometric Function3' */
      rtb_Step1 = cos(rtb_PulseGenerator4);

      /* Product: '<S92>/Product9' */
      rtb_e = rtb_Step1 * rtb_Step1 * rtb_Step1;

      /* Trigonometry: '<S92>/Trigonometric Function2' */
      rtb_PulseGenerator4 = sin(rtb_PulseGenerator4);

      /* Product: '<S92>/Product5' */
      rtb_Step1 = rtb_PulseGenerator1 * rtb_PulseGenerator1;

      /* Product: '<S92>/Product10' incorporates:
       *  Constant: '<S90>/c_rsma'
       *  Product: '<S92>/Divide'
       *  Product: '<S92>/Product4'
       *  Product: '<S92>/Product8'
       *  Sum: '<S92>/Subtract2'
       */
      rtb_PulseGenerator1 = (GRM_HIL_P.c_rsma_Value_b * GRM_HIL_P.c_rsma_Value_b
        - rtb_Step1) / rtb_Step1 * rtb_PulseGenerator1 * (rtb_PulseGenerator4 *
        rtb_PulseGenerator4 * rtb_PulseGenerator4);

      /* Sum: '<S92>/Add1' incorporates:
       *  Constant: '<S89>/Constant'
       */
      rtb_PulseGenerator1 += GRM_HIL_P.Constant_Value_iee[2];

      /* Product: '<S92>/Product3' incorporates:
       *  Constant: '<S90>/c_flat'
       *  Product: '<S91>/Product3'
       */
      u0 = GRM_HIL_P.c_flat_Value_f * GRM_HIL_P.c_flat_Value_f;

      /* Trigonometry: '<S92>/Trigonometric Function1' incorporates:
       *  Constant: '<S90>/c_flat'
       *  Constant: '<S90>/c_rsma'
       *  Gain: '<S92>/Gain'
       *  Product: '<S92>/Divide2'
       *  Product: '<S92>/Product11'
       *  Product: '<S92>/Product3'
       *  Sqrt: '<S92>/Sqrt'
       *  Sum: '<S92>/Subtract1'
       *  Sum: '<S92>/Subtract3'
       */
      rtb_Step1 = atan(rtb_PulseGenerator1 / (rtb_PulseGenerator -
        (GRM_HIL_P.Gain_Gain_o * GRM_HIL_P.c_flat_Value_f - u0) *
        GRM_HIL_P.c_rsma_Value_b * rtb_e));

      /* Trigonometry: '<S91>/Trigonometric Function' */
      rtb_PulseGenerator4 = sin(rtb_Step1);
      GRM_HIL_B.hBE_0_h = rtb_PulseGenerator / cos(rtb_Step1) -
        GRM_HIL_P.c_rsma_Value_b / sqrt(GRM_HIL_P.Constant_Value_m -
        (GRM_HIL_P.Gain_Gain_a * GRM_HIL_P.c_flat_Value_f - u0) *
        (rtb_PulseGenerator4 * rtb_PulseGenerator4));
    }

    /* End of Switch: '<S89>/Switch1' */
  }

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S77>/Constant1'
   *  Constant: '<S84>/Constant1'
   *  Constant: '<S93>/Constant'
   *  Product: '<S77>/Product1'
   *  Product: '<S93>/Product'
   *  Sum: '<S76>/Add3'
   *  Sum: '<S77>/Add'
   *  Sum: '<S84>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_p) - GRM_HIL_B.hBE_0_h >
      GRM_HIL_P.Switch_Threshold_j0) {
    /* Interpolation_n-D: '<S95>/Cn_delta_n_Interpolation' */
    frac_n[0] = rtb_lat;
    frac_n[1] = rtb_Sqrt_j;
    frac_n[2] = rtb_f_beB;
    bpIndex_n[0] = rtb_k_Mach;
    bpIndex_n[1] = rtb_k_alB;
    bpIndex_n[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_n, frac_n,
      GRM_HIL_P.Cn_delta_n_Interpolation_Table,
      GRM_HIL_P.Cn_delta_n_Interpolation_dimSize);

    /* Product: '<S76>/Product33' */
    rtb_PulseGenerator1 = rtb_Gain_n * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S95>/Cn_delta_m_Interpolation' */
    frac_o[0] = rtb_lat;
    frac_o[1] = rtb_Sqrt_j;
    frac_o[2] = rtb_f_beB;
    bpIndex_o[0] = rtb_k_Mach;
    bpIndex_o[1] = rtb_k_alB;
    bpIndex_o[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_o, frac_o,
      GRM_HIL_P.Cn_delta_m_Interpolation_Table,
      GRM_HIL_P.Cn_delta_m_Interpolation_dimSize);

    /* Product: '<S76>/Product32' */
    rtb_PulseGenerator4 = rtb_Gain_nk * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S95>/Cn_delta_l_Interpolation' */
    frac_p[0] = rtb_lat;
    frac_p[1] = rtb_Sqrt_j;
    frac_p[2] = rtb_f_beB;
    bpIndex_p[0] = rtb_k_Mach;
    bpIndex_p[1] = rtb_k_alB;
    bpIndex_p[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_p, frac_p,
      GRM_HIL_P.Cn_delta_l_Interpolation_Table,
      GRM_HIL_P.Cn_delta_l_Interpolation_dimSize);

    /* Product: '<S76>/Product31' */
    rtb_Step1 = rtb_Gain_fl * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S95>/Cnr_Interpolation' */
    frac_q[0] = rtb_lat;
    frac_q[1] = rtb_Sqrt_j;
    frac_q[2] = rtb_f_beB;
    bpIndex_q[0] = rtb_k_Mach;
    bpIndex_q[1] = rtb_k_alB;
    bpIndex_q[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_q, frac_q,
      GRM_HIL_P.Cnr_Interpolation_Table, GRM_HIL_P.Cnr_Interpolation_dimSize);

    /* Product: '<S76>/Product36' */
    rtb_e = rtb_Gain_af * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S95>/Cnq_Interpolation' */
    frac_r[0] = rtb_lat;
    frac_r[1] = rtb_Sqrt_j;
    frac_r[2] = rtb_f_beB;
    bpIndex_r[0] = rtb_k_Mach;
    bpIndex_r[1] = rtb_k_alB;
    bpIndex_r[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_r, frac_r,
      GRM_HIL_P.Cnq_Interpolation_Table, GRM_HIL_P.Cnq_Interpolation_dimSize);

    /* Product: '<S76>/Product35' */
    rtb_Subtract_ju = rtb_Gain_lt * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S95>/Cnp_Interpolation' */
    frac_s[0] = rtb_lat;
    frac_s[1] = rtb_Sqrt_j;
    frac_s[2] = rtb_f_beB;
    bpIndex_s[0] = rtb_k_Mach;
    bpIndex_s[1] = rtb_k_alB;
    bpIndex_s[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_s, frac_s,
      GRM_HIL_P.Cnp_Interpolation_Table, GRM_HIL_P.Cnp_Interpolation_dimSize);

    /* Product: '<S76>/Product34' */
    rtb_Subtract_cl = rtb_Gain_g * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S95>/Cn_Interpolation' */
    frac_t[0] = rtb_lat;
    frac_t[1] = rtb_Sqrt_j;
    frac_t[2] = rtb_f_beB;
    bpIndex_t[0] = rtb_k_Mach;
    bpIndex_t[1] = rtb_k_alB;
    bpIndex_t[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_t, frac_t,
      GRM_HIL_P.Cn_Interpolation_Table, GRM_HIL_P.Cn_Interpolation_dimSize);

    /* Sum: '<S76>/Add5' incorporates:
     *  Constant: '<S95>/Constant'
     *  Product: '<S95>/Product'
     */
    frac_1[2] = (((((GRM_HIL_P.Constant_Value_ml * rtb_PulseGenerator +
                     rtb_Subtract_cl) + rtb_Subtract_ju) + rtb_e) + rtb_Step1) +
                 rtb_PulseGenerator4) + rtb_PulseGenerator1;

    /* Interpolation_n-D: '<S94>/Cm_delta_n_Interpolation' */
    frac_u[0] = rtb_lat;
    frac_u[1] = rtb_Sqrt_j;
    frac_u[2] = rtb_f_beB;
    bpIndex_u[0] = rtb_k_Mach;
    bpIndex_u[1] = rtb_k_alB;
    bpIndex_u[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_u, frac_u,
      GRM_HIL_P.Cm_delta_n_Interpolation_Table,
      GRM_HIL_P.Cm_delta_n_Interpolation_dimSize);

    /* Product: '<S76>/Product27' */
    rtb_PulseGenerator1 = rtb_Gain_n * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S94>/Cm_delta_m_Interpolation' */
    frac_v[0] = rtb_lat;
    frac_v[1] = rtb_Sqrt_j;
    frac_v[2] = rtb_f_beB;
    bpIndex_v[0] = rtb_k_Mach;
    bpIndex_v[1] = rtb_k_alB;
    bpIndex_v[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_v, frac_v,
      GRM_HIL_P.Cm_delta_m_Interpolation_Table,
      GRM_HIL_P.Cm_delta_m_Interpolation_dimSize);

    /* Product: '<S76>/Product26' */
    rtb_PulseGenerator4 = rtb_Gain_nk * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S94>/Cm_delta_l_Interpolation' */
    frac_w[0] = rtb_lat;
    frac_w[1] = rtb_Sqrt_j;
    frac_w[2] = rtb_f_beB;
    bpIndex_w[0] = rtb_k_Mach;
    bpIndex_w[1] = rtb_k_alB;
    bpIndex_w[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_w, frac_w,
      GRM_HIL_P.Cm_delta_l_Interpolation_Table,
      GRM_HIL_P.Cm_delta_l_Interpolation_dimSize);

    /* Product: '<S76>/Product25' */
    rtb_Step1 = rtb_Gain_fl * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S94>/Cmr_Interpolation' */
    frac_x[0] = rtb_lat;
    frac_x[1] = rtb_Sqrt_j;
    frac_x[2] = rtb_f_beB;
    bpIndex_x[0] = rtb_k_Mach;
    bpIndex_x[1] = rtb_k_alB;
    bpIndex_x[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_x, frac_x,
      GRM_HIL_P.Cmr_Interpolation_Table, GRM_HIL_P.Cmr_Interpolation_dimSize);

    /* Product: '<S76>/Product30' */
    rtb_e = rtb_Gain_af * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S94>/Cmq_Interpolation' */
    frac_y[0] = rtb_lat;
    frac_y[1] = rtb_Sqrt_j;
    frac_y[2] = rtb_f_beB;
    bpIndex_y[0] = rtb_k_Mach;
    bpIndex_y[1] = rtb_k_alB;
    bpIndex_y[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_y, frac_y,
      GRM_HIL_P.Cmq_Interpolation_Table, GRM_HIL_P.Cmq_Interpolation_dimSize);

    /* Product: '<S76>/Product29' */
    rtb_Subtract_ju = rtb_Gain_lt * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S94>/Cmp_Interpolation' */
    frac_z[0] = rtb_lat;
    frac_z[1] = rtb_Sqrt_j;
    frac_z[2] = rtb_f_beB;
    bpIndex_z[0] = rtb_k_Mach;
    bpIndex_z[1] = rtb_k_alB;
    bpIndex_z[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_z, frac_z,
      GRM_HIL_P.Cmp_Interpolation_Table, GRM_HIL_P.Cmp_Interpolation_dimSize);

    /* Product: '<S76>/Product28' */
    rtb_Subtract_cl = rtb_Gain_g * rtb_PulseGenerator;

    /* Interpolation_n-D: '<S94>/Cm_Interpolation' */
    frac_10[0] = rtb_lat;
    frac_10[1] = rtb_Sqrt_j;
    frac_10[2] = rtb_f_beB;
    bpIndex_10[0] = rtb_k_Mach;
    bpIndex_10[1] = rtb_k_alB;
    bpIndex_10[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_10, frac_10,
      GRM_HIL_P.Cm_Interpolation_Table, GRM_HIL_P.Cm_Interpolation_dimSize);

    /* Sum: '<S76>/Add4' incorporates:
     *  Constant: '<S94>/Constant'
     *  Product: '<S94>/Product'
     */
    frac_1[1] = (((((GRM_HIL_P.Constant_Value_jm * rtb_PulseGenerator +
                     rtb_Subtract_cl) + rtb_Subtract_ju) + rtb_e) + rtb_Step1) +
                 rtb_PulseGenerator4) + rtb_PulseGenerator1;

    /* Interpolation_n-D: '<S93>/Cl_delta_n_Interpolation' */
    frac_11[0] = rtb_lat;
    frac_11[1] = rtb_Sqrt_j;
    frac_11[2] = rtb_f_beB;
    bpIndex_11[0] = rtb_k_Mach;
    bpIndex_11[1] = rtb_k_alB;
    bpIndex_11[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_11, frac_11,
      GRM_HIL_P.Cl_delta_n_Interpolation_Table,
      GRM_HIL_P.Cl_delta_n_Interpolation_dimSize);

    /* Product: '<S76>/Product21' */
    rtb_Gain_n *= rtb_PulseGenerator;

    /* Interpolation_n-D: '<S93>/Cl_delta_m_Interpolation' */
    frac_12[0] = rtb_lat;
    frac_12[1] = rtb_Sqrt_j;
    frac_12[2] = rtb_f_beB;
    bpIndex_12[0] = rtb_k_Mach;
    bpIndex_12[1] = rtb_k_alB;
    bpIndex_12[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_12, frac_12,
      GRM_HIL_P.Cl_delta_m_Interpolation_Table,
      GRM_HIL_P.Cl_delta_m_Interpolation_dimSize);

    /* Product: '<S76>/Product20' */
    rtb_Gain_nk *= rtb_PulseGenerator;

    /* Interpolation_n-D: '<S93>/Cl_delta_l_Interpolation' */
    frac_13[0] = rtb_lat;
    frac_13[1] = rtb_Sqrt_j;
    frac_13[2] = rtb_f_beB;
    bpIndex_13[0] = rtb_k_Mach;
    bpIndex_13[1] = rtb_k_alB;
    bpIndex_13[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_13, frac_13,
      GRM_HIL_P.Cl_delta_l_Interpolation_Table,
      GRM_HIL_P.Cl_delta_l_Interpolation_dimSize);

    /* Product: '<S76>/Product19' */
    rtb_Gain_fl *= rtb_PulseGenerator;

    /* Interpolation_n-D: '<S93>/Clr_Interpolation' */
    frac_14[0] = rtb_lat;
    frac_14[1] = rtb_Sqrt_j;
    frac_14[2] = rtb_f_beB;
    bpIndex_14[0] = rtb_k_Mach;
    bpIndex_14[1] = rtb_k_alB;
    bpIndex_14[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_14, frac_14,
      GRM_HIL_P.Clr_Interpolation_Table, GRM_HIL_P.Clr_Interpolation_dimSize);

    /* Product: '<S76>/Product24' */
    rtb_Gain_af *= rtb_PulseGenerator;

    /* Interpolation_n-D: '<S93>/Clq_Interpolation' */
    frac_15[0] = rtb_lat;
    frac_15[1] = rtb_Sqrt_j;
    frac_15[2] = rtb_f_beB;
    bpIndex_15[0] = rtb_k_Mach;
    bpIndex_15[1] = rtb_k_alB;
    bpIndex_15[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_15, frac_15,
      GRM_HIL_P.Clq_Interpolation_Table, GRM_HIL_P.Clq_Interpolation_dimSize);

    /* Product: '<S76>/Product23' */
    rtb_Gain_lt *= rtb_PulseGenerator;

    /* Interpolation_n-D: '<S93>/Clp_Interpolation' */
    frac_16[0] = rtb_lat;
    frac_16[1] = rtb_Sqrt_j;
    frac_16[2] = rtb_f_beB;
    bpIndex_16[0] = rtb_k_Mach;
    bpIndex_16[1] = rtb_k_alB;
    bpIndex_16[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_16, frac_16,
      GRM_HIL_P.Clp_Interpolation_Table, GRM_HIL_P.Clp_Interpolation_dimSize);

    /* Product: '<S76>/Product22' */
    rtb_Gain_g *= rtb_PulseGenerator;

    /* Interpolation_n-D: '<S93>/Cl_Interpolation' */
    frac_17[0] = rtb_lat;
    frac_17[1] = rtb_Sqrt_j;
    frac_17[2] = rtb_f_beB;
    bpIndex_17[0] = rtb_k_Mach;
    bpIndex_17[1] = rtb_k_alB;
    bpIndex_17[2] = rtb_k_beB;
    rtb_PulseGenerator = intrp3d_l_pw(bpIndex_17, frac_17,
      GRM_HIL_P.Cl_Interpolation_Table, GRM_HIL_P.Cl_Interpolation_dimSize);

    /* Product: '<S77>/Product1' incorporates:
     *  Constant: '<S77>/Constant1'
     */
    rtb_VectorConcatenate_f_idx_1 = rtb_Abs * frac_1[1] *
      GRM_HIL_P.Constant1_Value_bk;
    rtb_VectorConcatenate_f_idx_2 = rtb_Abs * frac_1[2] *
      GRM_HIL_P.Constant1_Value_bk;

    /* Sum: '<S82>/Sum2' incorporates:
     *  Product: '<S82>/Product6'
     *  Product: '<S82>/Product7'
     */
    frac_1[2] = frac_2[0] * frac[1] - frac_2[1] * frac[0];

    /* Sum: '<S82>/Sum1' incorporates:
     *  Product: '<S82>/Product4'
     *  Product: '<S82>/Product5'
     */
    frac_1[1] = frac_2[2] * frac[0] - frac_2[0] * frac[2];

    /* Sum: '<S82>/Sum' incorporates:
     *  Product: '<S82>/Product2'
     *  Product: '<S82>/Product3'
     */
    frac_1[0] = frac_2[1] * frac[2] - frac_2[2] * frac[1];
    frac_1[0] += ((((((GRM_HIL_P.Constant_Value_e0 * rtb_PulseGenerator +
                       rtb_Gain_g) + rtb_Gain_lt) + rtb_Gain_af) + rtb_Gain_fl)
                   + rtb_Gain_nk) + rtb_Gain_n) * rtb_Abs *
      GRM_HIL_P.Constant1_Value_bk;
    frac_1[1] += rtb_VectorConcatenate_f_idx_1;
    frac_1[2] += rtb_VectorConcatenate_f_idx_2;
  } else {
    frac_1[0] = GRM_HIL_B.VectorConcatenate_e[0];
    frac_1[1] = GRM_HIL_B.VectorConcatenate_e[1];
    frac_1[2] = GRM_HIL_B.VectorConcatenate_e[2];
  }

  /* End of Switch: '<S84>/Switch' */

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Constant: '<S116>/Constant'
   */
  GRM_HIL_B.Compare_k = (rtb_Product6_n4 >= GRM_HIL_P.CompareToConstant_const_i);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S113>/Assertion' */
    utAssert(GRM_HIL_B.Compare_k);
  }

  /* Logic: '<S117>/AND' incorporates:
   *  Constant: '<S117>/Lower Limit'
   *  Constant: '<S117>/Upper Limit'
   *  RelationalOperator: '<S117>/Lower Test'
   *  RelationalOperator: '<S117>/Upper Test'
   */
  GRM_HIL_B.AND = ((GRM_HIL_P.IntervalTest_lowlimit <= GRM_HIL_B.Switch[0]) &&
                   (GRM_HIL_B.Switch[0] <= GRM_HIL_P.IntervalTest_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S113>/Assertion1' */
    utAssert(GRM_HIL_B.AND);
  }

  /* Logic: '<S118>/AND' incorporates:
   *  Constant: '<S118>/Lower Limit'
   *  Constant: '<S118>/Upper Limit'
   *  RelationalOperator: '<S118>/Lower Test'
   *  RelationalOperator: '<S118>/Upper Test'
   */
  GRM_HIL_B.AND_i = ((GRM_HIL_P.IntervalTest1_lowlimit <= GRM_HIL_B.Switch[1]) &&
                     (GRM_HIL_B.Switch[1] <= GRM_HIL_P.IntervalTest1_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S113>/Assertion2' */
    utAssert(GRM_HIL_B.AND_i);
  }

  /* Integrator: '<S129>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE,
                       (GRM_HIL_B.sat));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE = GRM_HIL_P.Rudder_d_siB_0;
    }
  }

  rtb_d_siB = GRM_HIL_X.Integrator_CSTATE;

  /* End of Integrator: '<S129>/Integrator' */
=======
    /* ManualSwitch generated from: '<S50>/Manual Switch' */
    if (GRM_HIL_P.ManualSwitch_9_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.w_z_K_IB_B_radDs_n = GRM_HIL_B.w_z_K_IB_B_radDs;
    } else {
      /* SignalConversion generated from: '<S19>/States_hold' */
      GRM_HIL_B.w_z_K_IB_B_radDs_n = 0.0;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S19>/External_Inputs_hold' */
      GRM_HIL_B.CMD_phi_rad = GRM_HIL_B.Switch1;
>>>>>>> origin/master

  /* MATLAB Function: '<S129>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB, rtb_d_siB, &GRM_HIL_B.sf_Limiting_Rate,
                        GRM_HIL_P.Rudder_d_siB_max, GRM_HIL_P.Rudder_d_siB_min,
                        GRM_HIL_P.Rudder_siB_max, GRM_HIL_P.Rudder_siB_min);

  /* Integrator: '<S130>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h,
                       (GRM_HIL_B.sat_c));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Rudder1_d_siB_0;
    }
  }

<<<<<<< HEAD
  rtb_d_siB_l = GRM_HIL_X.Integrator_CSTATE_e;

  /* End of Integrator: '<S130>/Integrator' */

  /* MATLAB Function: '<S130>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_d, rtb_d_siB_l, &GRM_HIL_B.sf_Limiting_Rate_o,
                        GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
                        GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);
=======
  /* End of Outputs for SubSystem: '<S17>/Com_to_FCC_emul' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S25>/Gain2' */
    GRM_HIL_B.phi_rad = GRM_HIL_P.Gain2_Gain_b * GRM_HIL_B.CMD_phi_rad;
  }

  /* Gain: '<S24>/Gain' incorporates:
   *  Sum: '<S24>/Sum'
   */
  GRM_HIL_B.Gain = (GRM_HIL_B.phi_rad - GRM_HIL_B.w_x_K_IB_B_radDs_f) *
    GRM_HIL_P.FlightController_FCC.Roll.Gain;

  /* TransferFcn: '<S24>/Transfer Fcn' */
  GRM_HIL_B.Phi_Cmd_rad = 0.0;
  rtb_PulseGenerator = GRM_HIL_P.FlightController_FCC.Roll.Lead.Num[0] /
    GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0];
  GRM_HIL_B.Phi_Cmd_rad += rtb_PulseGenerator * GRM_HIL_B.Gain;
  GRM_HIL_B.Phi_Cmd_rad += (GRM_HIL_P.FlightController_FCC.Roll.Lead.Num[1] /
    GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0] - rtb_PulseGenerator *
    (GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[1] /
     GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0])) *
    GRM_HIL_X.TransferFcn_CSTATE_j;

  /* Saturate: '<S23>/Limit2maxDeflection' */
  if (GRM_HIL_B.Phi_Cmd_rad >
      GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_PulseGenerator =
      GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else if (GRM_HIL_B.Phi_Cmd_rad <
             -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_PulseGenerator =
      -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else {
    rtb_PulseGenerator = GRM_HIL_B.Phi_Cmd_rad;
  }
>>>>>>> origin/master

  /* Integrator: '<S131>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k,
                       (GRM_HIL_B.sat_a));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;
    }
  }

<<<<<<< HEAD
  rtb_d_siB_f = GRM_HIL_X.Integrator_CSTATE_f;

  /* End of Integrator: '<S131>/Integrator' */

  /* MATLAB Function: '<S131>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_i, rtb_d_siB_f, &GRM_HIL_B.sf_Limiting_Rate_g,
                        GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
                        GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Integrator: '<S132>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n,
                       (GRM_HIL_B.sat_o));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Rudder3_d_siB_0;
    }
  }

  rtb_d_siB_k = GRM_HIL_X.Integrator_CSTATE_g;

  /* End of Integrator: '<S132>/Integrator' */

  /* MATLAB Function: '<S132>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_o, rtb_d_siB_k, &GRM_HIL_B.sf_Limiting_Rate_d,
                        GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
                        GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Saturate: '<S129>/Saturation' */
  if (rtb_Product4_n[0] > GRM_HIL_P.Rudder_siB_max) {
    rtb_PulseGenerator = GRM_HIL_P.Rudder_siB_max;
  } else if (rtb_Product4_n[0] < GRM_HIL_P.Rudder_siB_min) {
    rtb_PulseGenerator = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_PulseGenerator = rtb_Product4_n[0];
  }

  /* End of Saturate: '<S129>/Saturation' */
=======
  /* Sum: '<S24>/Sum3' */
  GRM_HIL_B.Sum3 = GRM_HIL_B.acc_y_mDs2 - GRM_HIL_B.ACC_y_B_mDs2_o;

  /* Gain: '<S24>/Gain2' incorporates:
   *  Gain: '<S24>/Gain4'
   *  Sum: '<S24>/Sum4'
   *  Sum: '<S24>/Sum6'
   *  TransferFcn: '<S24>/Transfer Fcn2'
   */
  GRM_HIL_B.Psi_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Num /
      GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[0] *
      GRM_HIL_X.TransferFcn2_CSTATE_e +
      GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.PropGain * GRM_HIL_B.Sum3) -
     GRM_HIL_B.w_z_K_IB_B_radDs_n) *
    GRM_HIL_P.FlightController_FCC.Yaw.innerLoop.PropGain;

  /* Sum: '<S24>/Sum1' */
  GRM_HIL_B.Sum1 = GRM_HIL_B.acc_z_mDs2 - GRM_HIL_B.ACC_z_B_mDs2_e;

  /* Gain: '<S24>/Gain1' incorporates:
   *  Gain: '<S24>/Gain3'
   *  Sum: '<S24>/Sum2'
   *  Sum: '<S24>/Sum5'
   *  TransferFcn: '<S24>/Transfer Fcn1'
   */
  GRM_HIL_B.Theta_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Num /
      GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[0] *
      GRM_HIL_X.TransferFcn1_CSTATE_e +
      GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.PropGain * GRM_HIL_B.Sum1)
     - GRM_HIL_B.w_y_K_IB_B_radDs_e) *
    GRM_HIL_P.FlightController_FCC.Pitch.innerLoop.PropGain;

  /* Sum: '<S23>/Add4' incorporates:
   *  Constant: '<S23>/Constant'
   *  Sum: '<S23>/Add5'
   */
  rtb_sincos_o1_idx_0 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f1_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add' incorporates:
   *  Fcn: '<S23>/Fcn'
   *  Fcn: '<S23>/Fcn1'
   *  Product: '<S23>/Multiply'
   *  Product: '<S23>/Multiply1'
   *  Sum: '<S23>/Add4'
   */
  rtb_sincos_o1_idx_0 = -cos(rtb_sincos_o1_idx_0) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_sincos_o1_idx_0) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add6' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Sum: '<S23>/Add7'
   */
  rtb_PulseGenerator1 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f2_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add1' incorporates:
   *  Fcn: '<S23>/Fcn2'
   *  Fcn: '<S23>/Fcn3'
   *  Product: '<S23>/Multiply2'
   *  Product: '<S23>/Multiply3'
   *  Sum: '<S23>/Add6'
   */
  rtb_PulseGenerator1 = -cos(rtb_PulseGenerator1) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_PulseGenerator1) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add8' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Sum: '<S23>/Add9'
   */
  rtb_sincos_o1_idx_2 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f3_rad +
    GRM_HIL_B.ATT_Phi_rad_f;
>>>>>>> origin/master

  /* Sum: '<S129>/Add1' incorporates:
   *  Gain: '<S129>/Gain'
   *  Gain: '<S129>/Gain2'
   *  Integrator: '<S129>/Integrator1'
   *  Sum: '<S129>/Add'
   */
<<<<<<< HEAD
  rtb_dd_siB = (rtb_PulseGenerator - GRM_HIL_X.Integrator1_CSTATE) *
    GRM_HIL_P.Gain_Gain_oz - 2.0 * GRM_HIL_P.Rudder_dmp * GRM_HIL_P.Rudder_omega
    * rtb_d_siB;

  /* MATLAB Function: '<S129>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB, GRM_HIL_B.sf_Limiting_Rate.d_siB_l,
    rtb_dd_siB, &GRM_HIL_B.sf_Limiting_Acceleration, GRM_HIL_P.Rudder_d_siB_max,
    GRM_HIL_P.Rudder_d_siB_min, GRM_HIL_P.Rudder_dd_siB_max,
    GRM_HIL_P.Rudder_dd_siB_min, GRM_HIL_P.Rudder_siB_max,
    GRM_HIL_P.Rudder_siB_min);

  /* Saturate: '<S130>/Saturation' */
  if (rtb_Product4_n[1] > GRM_HIL_P.Rudder1_siB_max) {
    rtb_PulseGenerator = GRM_HIL_P.Rudder1_siB_max;
  } else if (rtb_Product4_n[1] < GRM_HIL_P.Rudder1_siB_min) {
    rtb_PulseGenerator = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_PulseGenerator = rtb_Product4_n[1];
  }

  /* End of Saturate: '<S130>/Saturation' */
=======
  rtb_sincos_o1_idx_2 = -cos(rtb_sincos_o1_idx_2) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_sincos_o1_idx_2) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add10' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Sum: '<S23>/Add11'
   */
  rtb_Add3 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f4_rad +
    GRM_HIL_B.ATT_Phi_rad_f;
>>>>>>> origin/master

  /* Sum: '<S130>/Add1' incorporates:
   *  Gain: '<S130>/Gain'
   *  Gain: '<S130>/Gain2'
   *  Integrator: '<S130>/Integrator1'
   *  Sum: '<S130>/Add'
   */
<<<<<<< HEAD
  rtb_dd_siB_c = (rtb_PulseGenerator - GRM_HIL_X.Integrator1_CSTATE_g) *
    GRM_HIL_P.Gain_Gain_a3 - 2.0 * GRM_HIL_P.Rudder1_dmp *
    GRM_HIL_P.Rudder1_omega * rtb_d_siB_l;

  /* MATLAB Function: '<S130>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_d, GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l,
    rtb_dd_siB_c, &GRM_HIL_B.sf_Limiting_Acceleration_i,
    GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
    GRM_HIL_P.Rudder1_dd_siB_max, GRM_HIL_P.Rudder1_dd_siB_min,
    GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Saturate: '<S131>/Saturation' */
  if (rtb_Product4_n[2] > GRM_HIL_P.Rudder2_siB_max) {
    rtb_PulseGenerator = GRM_HIL_P.Rudder2_siB_max;
  } else if (rtb_Product4_n[2] < GRM_HIL_P.Rudder2_siB_min) {
    rtb_PulseGenerator = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_PulseGenerator = rtb_Product4_n[2];
  }

  /* End of Saturate: '<S131>/Saturation' */
=======
  rtb_Add3 = -cos(rtb_Add3) * GRM_HIL_B.Psi_Cmd_rad + sin(rtb_Add3) *
    GRM_HIL_B.Theta_Cmd_rad;
>>>>>>> origin/master

  /* Sum: '<S131>/Add1' incorporates:
   *  Gain: '<S131>/Gain'
   *  Gain: '<S131>/Gain2'
   *  Integrator: '<S131>/Integrator1'
   *  Sum: '<S131>/Add'
   */
<<<<<<< HEAD
  rtb_dd_siB_o = (rtb_PulseGenerator - GRM_HIL_X.Integrator1_CSTATE_a) *
    GRM_HIL_P.Gain_Gain_hm - 2.0 * GRM_HIL_P.Rudder2_dmp *
    GRM_HIL_P.Rudder2_omega * rtb_d_siB_f;

  /* MATLAB Function: '<S131>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_i, GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l,
    rtb_dd_siB_o, &GRM_HIL_B.sf_Limiting_Acceleration_p,
    GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
    GRM_HIL_P.Rudder2_dd_siB_max, GRM_HIL_P.Rudder2_dd_siB_min,
    GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Saturate: '<S132>/Saturation' */
  if (rtb_Product_l > GRM_HIL_P.Rudder3_siB_max) {
    rtb_Product_l = GRM_HIL_P.Rudder3_siB_max;
  } else {
    if (rtb_Product_l < GRM_HIL_P.Rudder3_siB_min) {
      rtb_Product_l = GRM_HIL_P.Rudder3_siB_min;
    }
  }

  /* End of Saturate: '<S132>/Saturation' */

  /* Sum: '<S132>/Add1' incorporates:
   *  Gain: '<S132>/Gain'
   *  Gain: '<S132>/Gain2'
   *  Integrator: '<S132>/Integrator1'
   *  Sum: '<S132>/Add'
   */
  rtb_dd_siB_od = (rtb_Product_l - GRM_HIL_X.Integrator1_CSTATE_i) *
    GRM_HIL_P.Gain_Gain_d - 2.0 * GRM_HIL_P.Rudder3_dmp *
    GRM_HIL_P.Rudder3_omega * rtb_d_siB_k;

  /* MATLAB Function: '<S132>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_o, GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l,
    rtb_dd_siB_od, &GRM_HIL_B.sf_Limiting_Acceleration_h,
    GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
    GRM_HIL_P.Rudder3_dd_siB_max, GRM_HIL_P.Rudder3_dd_siB_min,
    GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Sum: '<S173>/Subtract' incorporates:
   *  Constant: '<S173>/pNPB'
   */
  rtb_Product1_m[0] = frac_2[0] - GRM_HIL_P.pNPB_Value[0];
  rtb_Product1_m[1] = frac_2[1] - GRM_HIL_P.pNPB_Value[1];
  rtb_Product1_m[2] = frac_2[2] - GRM_HIL_P.pNPB_Value[2];

  /* Step: '<Root>/External Moment' */
  if (rtb_Subtract_ay_tmp_0 < GRM_HIL_P.ExternalMoment_Time) {
    rtb_e = GRM_HIL_P.ExternalMoment_Y0;
  } else {
    rtb_e = GRM_HIL_P.ExternalMoment_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (rtb_Subtract_ay_tmp_0 < GRM_HIL_P.Step1_Time) {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step1_Y0;
  } else {
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Step1_YFinal;
  }

  /* Sum: '<S59>/Add1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  Product: '<S175>/Product2'
   *  Product: '<S175>/Product3'
   *  Product: '<S175>/Product4'
   *  Product: '<S175>/Product5'
   *  Product: '<S175>/Product6'
   *  Product: '<S175>/Product7'
   *  Sin: '<Root>/Sine Wave'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S175>/Sum'
   *  Sum: '<S175>/Sum1'
   *  Sum: '<S175>/Sum2'
   */
  frac_1[0] = ((rtb_Product1_m[1] * frac_0[2] - rtb_Product1_m[2] * frac_0[1]) +
               frac_1[0]) + (rtb_e + rtb_VectorConcatenate_f_idx_0) *
    GRM_HIL_P.Gain1_Gain_j2;
  frac_1[1] = ((rtb_Product1_m[2] * frac_0[0] - rtb_Product1_m[0] * frac_0[2]) +
               frac_1[1]) + GRM_HIL_P.Constant_Value_ko;
  frac_1[2] = (sin(GRM_HIL_P.SineWave_Freq * rtb_Subtract_ay_tmp_0 +
                   GRM_HIL_P.SineWave_Phase) * GRM_HIL_P.SineWave_Amp +
               GRM_HIL_P.SineWave_Bias) + ((rtb_Product1_m[0] * frac_0[1] -
    rtb_Product1_m[1] * frac_0[0]) + frac_1[2]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S149>/Gain' */
    rtb_VectorConcatenate_f_idx_0 = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[0];
    rtb_VectorConcatenate_f_idx_1 = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[1];
    rtb_VectorConcatenate_f_idx_2 = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[2];

    /* Sum: '<S164>/Add' incorporates:
     *  Constant: '<S164>/Constant8'
     *  Constant: '<S164>/Q_1'
     *  Constant: '<S164>/Q_2'
     *  Constant: '<S164>/Q_3'
     *  Constant: '<S164>/Q_4'
     *  Product: '<S164>/Product1'
     *  Product: '<S164>/Product2'
     *  Product: '<S164>/Product3'
     *  Product: '<S164>/Product4'
     *  SignalConversion generated from: '<S164>/Vector Concatenate'
=======
  rtb_Add16_j = GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad -
    fabs(rtb_PulseGenerator);

  /* Logic: '<S29>/OR' incorporates:
   *  Abs: '<S29>/Abs'
   *  Abs: '<S29>/Abs1'
   *  Abs: '<S29>/Abs2'
   *  Abs: '<S29>/Abs3'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator1'
   *  RelationalOperator: '<S29>/Relational Operator2'
   *  RelationalOperator: '<S29>/Relational Operator3'
   */
  GRM_HIL_B.OR = ((fabs(rtb_sincos_o1_idx_0) > rtb_Add16_j) || (fabs
    (rtb_PulseGenerator1) > rtb_Add16_j) || (fabs(rtb_sincos_o1_idx_2) >
    rtb_Add16_j) || (fabs(rtb_Add3) > rtb_Add16_j));

  /* Logic: '<S28>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_a = !GRM_HIL_B.OR;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S30>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4 =
      GRM_HIL_B.LogicalOperator_a;

    /* Outputs for Enabled SubSystem: '<S28>/Pass' incorporates:
     *  EnablePort: '<S30>/Enable'
>>>>>>> origin/master
     */
    for (i = 0; i < 16; i++) {
      GRM_HIL_B.Add_f[i] = ((GRM_HIL_P.Q_1_Value_o[i] *
        rtb_VectorConcatenate_f_idx_0 + GRM_HIL_P.Q_2_Value_b[i] *
        rtb_VectorConcatenate_f_idx_1) + GRM_HIL_P.Q_3_Value_j[i] *
                            rtb_VectorConcatenate_f_idx_2) +
        GRM_HIL_P.Q_4_Value_d[i] * GRM_HIL_P.Constant8_Value_h;
    }

    /* End of Sum: '<S164>/Add' */
  }

  /* Gain: '<S166>/Gain1' incorporates:
   *  Integrator: '<S161>/integration_eom'
   */
<<<<<<< HEAD
  rtb_d_qGE[0] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[0];
  rtb_d_qGE[1] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[1];
  rtb_d_qGE[2] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[2];
  for (i = 0; i < 4; i++) {
    /* Product: '<S164>/Product5' incorporates:
     *  Integrator: '<S161>/integration_eom'
     */
    rtb_Subtract_ay_tmp_0 = GRM_HIL_B.Add_f[i + 12] *
      GRM_HIL_X.integration_eom_CSTATE_b[3] + (GRM_HIL_B.Add_f[i + 8] *
      rtb_d_qGE[2] + (GRM_HIL_B.Add_f[i + 4] * rtb_d_qGE[1] + GRM_HIL_B.Add_f[i]
                      * rtb_d_qGE[0]));

    /* Gain: '<S164>/Gain' */
    rtb_Product4_n[i] = GRM_HIL_P.Gain_Gain_e4 * rtb_Subtract_ay_tmp_0;
=======
  if (GRM_HIL_DW.Pass_MODE) {
    /* Inport: '<S30>/Fin_1_Cmd_rad' */
    GRM_HIL_B.Merge = rtb_sincos_o1_idx_0;

    /* Inport: '<S30>/Fin_2_Cmd_rad' */
    GRM_HIL_B.Merge1 = rtb_PulseGenerator1;

    /* Inport: '<S30>/Fin_3_Cmd_rad' */
    GRM_HIL_B.Merge2 = rtb_sincos_o1_idx_2;

    /* Inport: '<S30>/Fin_4_Cmd_rad' */
    GRM_HIL_B.Merge3 = rtb_Add3;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Pass_SubsysRanBC);
    }
>>>>>>> origin/master
  }

  /* SignalConversion generated from: '<S167>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_m[3] = rtb_Product4_n[3];

  /* Gain: '<S167>/Gain1' */
  GRM_HIL_B.VectorConcatenate_m[0] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[0];
  GRM_HIL_B.VectorConcatenate_m[1] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[1];
  GRM_HIL_B.VectorConcatenate_m[2] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S163>/Vector Concatenate1' incorporates:
     *  Constant: '<S163>/Constant8'
     */
    GRM_HIL_B.wEGG[0] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S163>/Vector Concatenate1' incorporates:
     *  Constant: '<S163>/Constant8'
     */
    GRM_HIL_B.wEGG[1] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S163>/Vector Concatenate1' incorporates:
     *  Constant: '<S163>/Constant8'
     */
    GRM_HIL_B.wEGG[2] = GRM_HIL_P.Constant8_Value_ck;
  }

  /* Derivative: '<S163>/Derivative1' */
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

<<<<<<< HEAD
  /* Derivative: '<S163>/Derivative' */
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
=======
  /* Outputs for Enabled SubSystem: '<S28>/Saturate' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (GRM_HIL_DW.Saturate_MODE) {
    /* Abs: '<S31>/Abs1' incorporates:
     *  MinMax: '<S31>/Max'
     */
    rtb_sincos_o1_idx_1 = fabs(fmax(fmax(fmax(rtb_sincos_o1_idx_0,
      rtb_PulseGenerator1), rtb_sincos_o1_idx_2), rtb_Add3));

    /* Product: '<S31>/Multiply' incorporates:
     *  Product: '<S31>/Divide'
     */
    GRM_HIL_B.Merge = rtb_sincos_o1_idx_0 / rtb_sincos_o1_idx_1 * rtb_Add16_j;
>>>>>>> origin/master

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/Constant9'
   */
  if (GRM_HIL_P.Constant9_Value_l > GRM_HIL_P.Switch_Threshold_m) {
    frac_0[0] = GRM_HIL_B.wEGG[0];
    frac_0[1] = GRM_HIL_B.wEGG[1];
    frac_0[2] = GRM_HIL_B.wEGG[2];
  } else {
    /* Gain: '<S163>/Gain2' incorporates:
     *  Product: '<S163>/Product'
     */
<<<<<<< HEAD
    frac_0[2] = rtb_siB_c5 * rtb_lat * GRM_HIL_P.Gain2_Gain;

    /* Gain: '<S163>/Gain1' */
    frac_0[1] = GRM_HIL_P.Gain1_Gain * rtb_Add;

    /* Product: '<S163>/Product1' */
    frac_0[0] = rtb_lat * rtb_Cx;
=======
    GRM_HIL_B.Merge1 = rtb_PulseGenerator1 / rtb_sincos_o1_idx_1 * rtb_Add16_j;

    /* Product: '<S31>/Multiply2' incorporates:
     *  Product: '<S31>/Divide4'
     */
    GRM_HIL_B.Merge2 = rtb_sincos_o1_idx_2 / rtb_sincos_o1_idx_1 * rtb_Add16_j;

    /* Product: '<S31>/Multiply3' incorporates:
     *  Product: '<S31>/Divide2'
     */
    GRM_HIL_B.Merge3 = rtb_Add3 / rtb_sincos_o1_idx_1 * rtb_Add16_j;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Saturate_SubsysRanBC);
    }
>>>>>>> origin/master
  }

  /* Gain: '<S149>/Gain1' */
  frac_0[0] *= GRM_HIL_P.Gain1_Gain_k;
  frac_0[1] *= GRM_HIL_P.Gain1_Gain_k;

<<<<<<< HEAD
  /* SignalConversion generated from: '<S168>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[0] = frac_0[0];
=======
  /* Sum: '<S23>/Add14' */
  GRM_HIL_B.Fin_4_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge3;
>>>>>>> origin/master

  /* SignalConversion generated from: '<S168>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[1] = frac_0[1];

  /* SignalConversion generated from: '<S168>/Vector Concatenate' incorporates:
   *  Gain: '<S149>/Gain1'
   */
<<<<<<< HEAD
  GRM_HIL_B.VectorConcatenate_a[2] = GRM_HIL_P.Gain1_Gain_k * frac_0[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S168>/Constant8' */
    GRM_HIL_B.VectorConcatenate_a[3] = GRM_HIL_P.Constant8_Value_p;
  }
=======
  rtb_sincos_o1_idx_0 = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms -
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;
>>>>>>> origin/master

  /* Gain: '<S170>/Gain1' incorporates:
   *  Integrator: '<S162>/integration_eom'
   */
<<<<<<< HEAD
  rtb_d_qBI[0] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[0];
  rtb_d_qBI[1] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[1];
  rtb_d_qBI[2] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[2];

  /* Sum: '<S168>/Add' incorporates:
   *  Constant: '<S168>/Q_1'
   *  Constant: '<S168>/Q_2'
   *  Constant: '<S168>/Q_3'
   *  Constant: '<S168>/Q_4'
   *  Product: '<S168>/Product1'
   *  Product: '<S168>/Product2'
   *  Product: '<S168>/Product3'
   *  Product: '<S168>/Product4'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_h[i] * GRM_HIL_B.VectorConcatenate_a[0] +
               GRM_HIL_P.Q_2_Value_g[i] * GRM_HIL_B.VectorConcatenate_a[1]) +
              GRM_HIL_P.Q_3_Value_oc[i] * GRM_HIL_B.VectorConcatenate_a[2]) +
      GRM_HIL_P.Q_4_Value_ea[i] * GRM_HIL_B.VectorConcatenate_a[3];
  }

  /* End of Sum: '<S168>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S168>/Product5' incorporates:
     *  Integrator: '<S162>/integration_eom'
     */
    rtb_Subtract_ay_tmp_0 = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3]
      + (tmp[i + 8] * rtb_d_qBI[2] + (tmp[i + 4] * rtb_d_qBI[1] + tmp[i] *
          rtb_d_qBI[0]));

    /* Gain: '<S168>/Gain' */
    rtb_d_qGE[i] = GRM_HIL_P.Gain_Gain_ba * rtb_Subtract_ay_tmp_0;
=======
  rtb_PulseGenerator1 = rtb_sincos_o1_idx_0 * (GRM_HIL_B.Fin_4_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S35>/Saturation' */
  if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_PulseGenerator1 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms)
  {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms = rtb_PulseGenerator1;
>>>>>>> origin/master
  }

  /* SignalConversion generated from: '<S171>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_k[3] = rtb_d_qGE[3];

<<<<<<< HEAD
  /* Gain: '<S171>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[0] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[0];
=======
  /* Sum: '<S23>/Add13' */
  GRM_HIL_B.Fin_3_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge2;
>>>>>>> origin/master

  /* SignalConversion generated from: '<S193>/Vector Concatenate' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
<<<<<<< HEAD
  GRM_HIL_B.d_x[0] = GRM_HIL_X.integration_eom_CSTATE[3];

  /* SignalConversion generated from: '<S193>/Vector Concatenate' */
  GRM_HIL_B.d_x[3] = rtb_siB_h[0];
=======
  rtb_PulseGenerator1 = rtb_sincos_o1_idx_0 * (GRM_HIL_B.Fin_3_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S34>/Saturation' */
  if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_PulseGenerator1 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms)
  {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_e = rtb_PulseGenerator1;
  }
>>>>>>> origin/master

  /* Gain: '<S171>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[1] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[1];

<<<<<<< HEAD
  /* SignalConversion generated from: '<S193>/Vector Concatenate' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.d_x[1] = GRM_HIL_X.integration_eom_CSTATE[4];
=======
  /* Sum: '<S23>/Add12' */
  GRM_HIL_B.Fin_2_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge1;
>>>>>>> origin/master

  /* SignalConversion generated from: '<S193>/Vector Concatenate' */
  GRM_HIL_B.d_x[4] = rtb_siB_h[1];

  /* Gain: '<S171>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[2] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[2];

  /* SignalConversion generated from: '<S193>/Vector Concatenate' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
<<<<<<< HEAD
  GRM_HIL_B.d_x[2] = GRM_HIL_X.integration_eom_CSTATE[5];

  /* SignalConversion generated from: '<S193>/Vector Concatenate' */
  GRM_HIL_B.d_x[5] = rtb_siB_h[2];
=======
  rtb_PulseGenerator1 = rtb_sincos_o1_idx_0 * (GRM_HIL_B.Fin_2_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S33>/Saturation' */
  if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_PulseGenerator1 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms)
  {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_c = rtb_PulseGenerator1;
  }
>>>>>>> origin/master

  /* SignalConversion generated from: '<S197>/Vector Concatenate' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[0] = GRM_HIL_X.integration_eom_CSTATE[10];

<<<<<<< HEAD
  /* SignalConversion generated from: '<S197>/Vector Concatenate' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[1] = GRM_HIL_X.integration_eom_CSTATE[11];
=======
  /* Sum: '<S23>/Add15' */
  GRM_HIL_B.Fin_1_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge;
>>>>>>> origin/master

  /* SignalConversion generated from: '<S197>/Vector Concatenate' incorporates:
   *  Integrator: '<S193>/integration_eom'
   */
<<<<<<< HEAD
  GRM_HIL_B.VectorConcatenate_p[2] = GRM_HIL_X.integration_eom_CSTATE[12];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S197>/Constant' */
    GRM_HIL_B.VectorConcatenate_p[3] = GRM_HIL_P.Constant_Value_lp;
  }

  /* Gain: '<S200>/Gain1' */
  rtb_siB_h[0] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_0;
  rtb_siB_h[1] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_1;
  rtb_siB_h[2] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_2;

  /* Sum: '<S197>/Add' incorporates:
   *  Constant: '<S197>/Q_1'
   *  Constant: '<S197>/Q_2'
   *  Constant: '<S197>/Q_3'
   *  Constant: '<S197>/Q_4'
   *  Product: '<S197>/Product2'
   *  Product: '<S197>/Product3'
   *  Product: '<S197>/Product4'
   *  Product: '<S197>/Product5'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_f[i] * GRM_HIL_B.VectorConcatenate_p[0] +
               GRM_HIL_P.Q_2_Value_n1[i] * GRM_HIL_B.VectorConcatenate_p[1]) +
              GRM_HIL_P.Q_3_Value_a[i] * GRM_HIL_B.VectorConcatenate_p[2]) +
      GRM_HIL_P.Q_4_Value_b[i] * GRM_HIL_B.VectorConcatenate_p[3];
  }

  /* End of Sum: '<S197>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S197>/Product6' incorporates:
     *  SignalConversion generated from: '<S200>/Vector Concatenate'
=======
  rtb_PulseGenerator1 = rtb_sincos_o1_idx_0 * (GRM_HIL_B.Fin_1_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S32>/Saturation' */
  if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_p = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_PulseGenerator1 < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms)
  {
    GRM_HIL_B.pulse_width_ms_p = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_p = rtb_PulseGenerator1;
  }

  /* End of Saturate: '<S32>/Saturation' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[4] == 0) {
    /* S-Function (fcncallgen): '<S17>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S17>/FB_Com_freq_emul'
>>>>>>> origin/master
     */
    rtb_Subtract_ay_tmp_0 = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_siB_h[2] + (tmp[i + 4] * rtb_siB_h[1] + tmp[i] * rtb_siB_h[0]));

    /* Gain: '<S197>/Gain' */
    rtb_d_qBI[i] = GRM_HIL_P.Gain_Gain_pq * rtb_Subtract_ay_tmp_0;
  }

  /* SignalConversion generated from: '<S201>/Vector Concatenate' */
  GRM_HIL_B.d_x[9] = rtb_d_qBI[3];

  /* Gain: '<S201>/Gain1' */
  GRM_HIL_B.d_x[6] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[0];

  /* Sum: '<S227>/Subtract' incorporates:
   *  Constant: '<S227>/Constant17'
   */
  frac_0[0] = frac_2[0] - GRM_HIL_P.Constant17_Value[0];

  /* Gain: '<S201>/Gain1' */
  GRM_HIL_B.d_x[7] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[1];

  /* Sum: '<S227>/Subtract' incorporates:
   *  Constant: '<S227>/Constant17'
   */
  frac_0[1] = frac_2[1] - GRM_HIL_P.Constant17_Value[1];

  /* Gain: '<S201>/Gain1' */
  GRM_HIL_B.d_x[8] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[2];

  /* Sum: '<S227>/Subtract' incorporates:
   *  Constant: '<S227>/Constant17'
   */
  frac_0[2] = frac_2[2] - GRM_HIL_P.Constant17_Value[2];

<<<<<<< HEAD
  /* Product: '<S239>/Product1' */
  rtb_Product6_n4 = frac_0[1] * frac_0[1];

  /* Product: '<S239>/Product2' */
  rtb_Add = frac_0[2] * frac_0[2];

  /* Sum: '<S239>/Add' */
  rtb_JBBB[0] = rtb_Product6_n4 + rtb_Add;

  /* Gain: '<S239>/Gain' incorporates:
   *  Product: '<S239>/Product3'
   */
  rtb_lat = frac_0[0] * frac_0[1] * GRM_HIL_P.Gain_Gain_ky;

  /* SignalConversion generated from: '<S239>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_lat;

  /* Gain: '<S239>/Gain1' incorporates:
   *  Product: '<S239>/Product4'
   */
  rtb_Sqrt_j = frac_0[0] * frac_0[2] * GRM_HIL_P.Gain1_Gain_oe;

  /* SignalConversion generated from: '<S239>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S239>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_lat;

  /* Product: '<S239>/Product5' */
  rtb_lat = frac_0[0] * frac_0[0];

  /* Sum: '<S239>/Add5' */
  rtb_JBBB[4] = rtb_Product6_n4 + rtb_lat;

  /* Gain: '<S239>/Gain3' incorporates:
   *  Product: '<S239>/Product6'
   */
  rtb_Product6_n4 = frac_0[1] * frac_0[2] * GRM_HIL_P.Gain3_Gain_c;

  /* SignalConversion generated from: '<S239>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_Product6_n4;

  /* SignalConversion generated from: '<S239>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S239>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_Product6_n4;

  /* Sum: '<S239>/Add4' */
  rtb_JBBB[8] = rtb_Add + rtb_lat;

  /* Sum: '<S222>/Add5' incorporates:
   *  Constant: '<S222>/Constant15'
   *  Constant: '<S227>/Constant'
   *  Product: '<S227>/Product'
   */
  for (i = 0; i < 9; i++) {
    rtb_TBG[i] = GRM_HIL_P.Constant_Value_bk * rtb_JBBB[i] +
      GRM_HIL_P.Constant15_Value[i];
  }

  /* End of Sum: '<S222>/Add5' */

  /* Sum: '<S228>/Subtract4' incorporates:
   *  Constant: '<S228>/Constant16'
   */
  frac_0[0] = frac_2[0] - GRM_HIL_P.Constant16_Value[0];
  frac_0[1] = frac_2[1] - GRM_HIL_P.Constant16_Value[1];
  frac_0[2] = frac_2[2] - GRM_HIL_P.Constant16_Value[2];

  /* Product: '<S240>/Product1' */
  rtb_Product6_n4 = frac_0[1] * frac_0[1];
=======
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S46>/Gain' incorporates:
     *  Constant: '<S5>/Constant'
     */
    GRM_HIL_B.VEL_u_K_R_E_B_mDs = GRM_HIL_P.Gain_Gain_d *
      GRM_HIL_P.Initial_States_Rigid_Body.Transl.VEL_u_K_R_E_B_mDs;
  }

  /* Integrator: '<S77>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_i != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_i = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator_IWORK_ic != 0)) {
      GRM_HIL_X.Integrator_CSTATE_j = GRM_HIL_B.VEL_u_K_R_E_B_mDs;
    }
  }

  /* Gain: '<S52>/Gain' incorporates:
   *  Integrator: '<S77>/Integrator'
   */
  GRM_HIL_B.VEL_u_K_R_E_B_mDs_e = GRM_HIL_P.Gain_Gain_k *
    GRM_HIL_X.Integrator_CSTATE_j;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S46>/Gain1' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    GRM_HIL_B.VEL_v_K_R_E_B_mDs = GRM_HIL_P.Gain1_Gain_i *
      GRM_HIL_P.Initial_States_Rigid_Body.Transl.VEL_v_K_R_E_B_mDs;
  }

  /* Integrator: '<S77>/Integrator1' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_p != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_p = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator1_IWORK_g != 0)) {
      GRM_HIL_X.Integrator1_CSTATE_p = GRM_HIL_B.VEL_v_K_R_E_B_mDs;
    }
  }

  /* Gain: '<S52>/Gain1' incorporates:
   *  Integrator: '<S77>/Integrator1'
   */
  GRM_HIL_B.VEL_v_K_R_E_B_mDs_e = GRM_HIL_P.Gain1_Gain_b *
    GRM_HIL_X.Integrator1_CSTATE_p;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S46>/Gain2' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    GRM_HIL_B.VEL_w_K_R_E_B_mDs = GRM_HIL_P.Gain2_Gain_l *
      GRM_HIL_P.Initial_States_Rigid_Body.Transl.VEL_w_K_R_E_B_mDs;
  }

  /* Integrator: '<S77>/Integrator2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_f != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_f = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator2_IWORK_m != 0)) {
      GRM_HIL_X.Integrator2_CSTATE_a = GRM_HIL_B.VEL_w_K_R_E_B_mDs;
    }
  }

  /* Gain: '<S52>/Gain2' incorporates:
   *  Integrator: '<S77>/Integrator2'
   */
  GRM_HIL_B.VEL_w_K_R_E_B_mDs_d = GRM_HIL_P.Gain2_Gain_e *
    GRM_HIL_X.Integrator2_CSTATE_a;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S7>/Constant' */
    GRM_HIL_B.run = GRM_HIL_P.Constant_Value_g;

    /* Constant: '<S7>/Constant7' */
    GRM_HIL_B.enable_gimbal_ctrl_flg = GRM_HIL_P.Constant7_Value_e;

    /* Constant: '<S7>/Constant8' */
    GRM_HIL_B.stop_gimbal_flg = GRM_HIL_P.Constant8_Value_l;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[4] == 0) {
    /* Product: '<S12>/Divide' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S15>/Constant1'
     *  Product: '<S13>/Divide'
     *  Product: '<S14>/Divide'
     *  Product: '<S15>/Divide'
     */
    rtb_sincos_o1_idx_0 = GRM_HIL_P.Servo_PWM.Pulswidth_cmd_max_ms -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms;

    /* Product: '<S12>/Multiply' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S12>/Constant2'
     *  Product: '<S12>/Divide'
     *  Sum: '<S12>/Add'
     */
    rtb_PulseGenerator1 = (GRM_HIL_B.pulse_width_ms_p2 -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_sincos_o1_idx_0 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S12>/Saturation' */
    if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_PulseGenerator1 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation = rtb_PulseGenerator1;
    }
>>>>>>> origin/master

  /* Product: '<S240>/Product2' */
  rtb_Add = frac_0[2] * frac_0[2];

<<<<<<< HEAD
  /* Sum: '<S240>/Add' */
  rtb_JBBB[0] = rtb_Product6_n4 + rtb_Add;

  /* Gain: '<S240>/Gain' incorporates:
   *  Product: '<S240>/Product3'
   */
  rtb_lat = frac_0[0] * frac_0[1] * GRM_HIL_P.Gain_Gain_lt;
=======
    /* Product: '<S13>/Multiply' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant2'
     *  Product: '<S13>/Divide'
     *  Sum: '<S13>/Add'
     */
    rtb_PulseGenerator1 = (GRM_HIL_B.pulse_width_ms_p2d -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_sincos_o1_idx_0 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S13>/Saturation' */
    if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_PulseGenerator1 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_c = rtb_PulseGenerator1;
    }
>>>>>>> origin/master

  /* SignalConversion generated from: '<S240>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_lat;

<<<<<<< HEAD
  /* Gain: '<S240>/Gain1' incorporates:
   *  Product: '<S240>/Product4'
   */
  rtb_Sqrt_j = frac_0[0] * frac_0[2] * GRM_HIL_P.Gain1_Gain_iq;

  /* SignalConversion generated from: '<S240>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Sqrt_j;
=======
    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant2'
     *  Product: '<S14>/Divide'
     *  Sum: '<S14>/Add'
     */
    rtb_PulseGenerator1 = (GRM_HIL_B.pulse_width_ms_p2de -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_sincos_o1_idx_0 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S14>/Saturation' */
    if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_PulseGenerator1 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_j = rtb_PulseGenerator1;
    }
>>>>>>> origin/master

  /* SignalConversion generated from: '<S240>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_lat;

<<<<<<< HEAD
  /* Product: '<S240>/Product5' */
  rtb_lat = frac_0[0] * frac_0[0];

  /* Sum: '<S240>/Add5' */
  rtb_JBBB[4] = rtb_Product6_n4 + rtb_lat;
=======
    /* Product: '<S15>/Multiply' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant2'
     *  Product: '<S15>/Divide'
     *  Sum: '<S15>/Add'
     */
    rtb_PulseGenerator1 = (GRM_HIL_B.pulse_width_ms_p2dee -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_sincos_o1_idx_0 *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S15>/Saturation' */
    if (rtb_PulseGenerator1 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_PulseGenerator1 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_a = rtb_PulseGenerator1;
    }
>>>>>>> origin/master

  /* Gain: '<S240>/Gain3' incorporates:
   *  Product: '<S240>/Product6'
   */
  rtb_Product6_n4 = frac_0[1] * frac_0[2] * GRM_HIL_P.Gain3_Gain_fm;

  /* SignalConversion generated from: '<S240>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_Product6_n4;

  /* SignalConversion generated from: '<S240>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S240>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_Product6_n4;

  /* Sum: '<S240>/Add4' */
  rtb_JBBB[8] = rtb_Add + rtb_lat;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
<<<<<<< HEAD
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S229>/Multiport Switch2' incorporates:
     *  Constant: '<S229>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3_m) {
     case 1:
      /* Trigonometry: '<S236>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/thrust_rot_x'
       *  Trigonometry: '<S236>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S236>/Trigonometric Function3' incorporates:
       *  Constant: '<S225>/thrust_rot_x'
       *  Trigonometry: '<S236>/Trigonometric Function'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S236>/Matrix Concatenate' incorporates:
       *  Constant: '<S236>/Constant7'
       *  Trigonometry: '<S236>/Trigonometric Function1'
       *  Trigonometry: '<S236>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_p;
      rtb_MultiportSwitch2[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[8] = rtb_Step1;

      /* SignalConversion generated from: '<S236>/Matrix Concatenate' incorporates:
       *  Constant: '<S236>/Constant8'
       *  Gain: '<S236>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_cs;
      rtb_MultiportSwitch2[4] = rtb_Step1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_pk *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S236>/Matrix Concatenate' incorporates:
       *  Constant: '<S236>/Constant'
       *  Constant: '<S236>/Constant1'
       *  Constant: '<S236>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_i;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_f;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_bt;
      break;

     case 2:
      /* Trigonometry: '<S237>/Trigonometric Function3' incorporates:
       *  Constant: '<S225>/thrust_rot_x'
       *  Trigonometry: '<S237>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S237>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/thrust_rot_x'
       *  Trigonometry: '<S237>/Trigonometric Function2'
       */
      rtb_Step1 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S237>/Matrix Concatenate' incorporates:
       *  Constant: '<S237>/Constant7'
       *  Gain: '<S237>/Gain1'
       *  Trigonometry: '<S237>/Trigonometric Function1'
       *  Trigonometry: '<S237>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_n * rtb_Step1;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_jt;
      rtb_MultiportSwitch2[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S237>/Matrix Concatenate' incorporates:
       *  Constant: '<S237>/Constant'
       *  Constant: '<S237>/Constant1'
       *  Constant: '<S237>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_p;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_c4;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_jp;

      /* SignalConversion generated from: '<S237>/Matrix Concatenate' incorporates:
       *  Constant: '<S237>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_c;
      rtb_MultiportSwitch2[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S238>/Matrix Concatenate' incorporates:
       *  Constant: '<S238>/Constant10'
       *  Constant: '<S238>/Constant11'
       *  Constant: '<S238>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_a;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_g;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_h;

      /* Trigonometry: '<S238>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/thrust_rot_x'
       *  Trigonometry: '<S238>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S238>/Trigonometric Function' incorporates:
       *  Constant: '<S225>/thrust_rot_x'
       *  Trigonometry: '<S238>/Trigonometric Function3'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S238>/Matrix Concatenate' incorporates:
       *  Constant: '<S238>/Constant7'
       *  Trigonometry: '<S238>/Trigonometric Function'
       *  Trigonometry: '<S238>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[4] = rtb_Step1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_cr;

      /* SignalConversion generated from: '<S238>/Matrix Concatenate' incorporates:
       *  Constant: '<S238>/Constant8'
       *  Gain: '<S238>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Step1;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_ow *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_os;
      break;
    }

    /* End of MultiPortSwitch: '<S229>/Multiport Switch2' */

    /* MultiPortSwitch: '<S229>/Multiport Switch1' incorporates:
     *  Constant: '<S229>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2_h) {
     case 1:
      /* Trigonometry: '<S233>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/thrust_rot_y'
       *  Trigonometry: '<S233>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S233>/Trigonometric Function3' incorporates:
       *  Constant: '<S225>/thrust_rot_y'
       *  Trigonometry: '<S233>/Trigonometric Function'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S233>/Matrix Concatenate' incorporates:
       *  Constant: '<S233>/Constant7'
       *  Trigonometry: '<S233>/Trigonometric Function1'
       *  Trigonometry: '<S233>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_n;
      rtb_MultiportSwitch1[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[8] = rtb_Step1;

      /* SignalConversion generated from: '<S233>/Matrix Concatenate' incorporates:
       *  Constant: '<S233>/Constant8'
       *  Gain: '<S233>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_n;
      rtb_MultiportSwitch1[4] = rtb_Step1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_ax *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S233>/Matrix Concatenate' incorporates:
       *  Constant: '<S233>/Constant'
       *  Constant: '<S233>/Constant1'
       *  Constant: '<S233>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_lx;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_nq;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_c;
      break;

     case 2:
      /* Trigonometry: '<S234>/Trigonometric Function3' incorporates:
       *  Constant: '<S225>/thrust_rot_y'
       *  Trigonometry: '<S234>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S234>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/thrust_rot_y'
       *  Trigonometry: '<S234>/Trigonometric Function2'
       */
      rtb_Step1 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S234>/Matrix Concatenate' incorporates:
       *  Constant: '<S234>/Constant7'
       *  Gain: '<S234>/Gain1'
       *  Trigonometry: '<S234>/Trigonometric Function1'
       *  Trigonometry: '<S234>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_j0 * rtb_Step1;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_fv;
      rtb_MultiportSwitch1[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S234>/Matrix Concatenate' incorporates:
       *  Constant: '<S234>/Constant'
       *  Constant: '<S234>/Constant1'
       *  Constant: '<S234>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_c;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_a;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_js;

      /* SignalConversion generated from: '<S234>/Matrix Concatenate' incorporates:
       *  Constant: '<S234>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_dg;
      rtb_MultiportSwitch1[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S235>/Matrix Concatenate' incorporates:
       *  Constant: '<S235>/Constant10'
       *  Constant: '<S235>/Constant11'
       *  Constant: '<S235>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_bq;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_m;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_l2;

      /* Trigonometry: '<S235>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/thrust_rot_y'
       *  Trigonometry: '<S235>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S235>/Trigonometric Function' incorporates:
       *  Constant: '<S225>/thrust_rot_y'
       *  Trigonometry: '<S235>/Trigonometric Function3'
       */
      rtb_Step1 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S235>/Matrix Concatenate' incorporates:
       *  Constant: '<S235>/Constant7'
       *  Trigonometry: '<S235>/Trigonometric Function'
       *  Trigonometry: '<S235>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[4] = rtb_Step1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_ch;

      /* SignalConversion generated from: '<S235>/Matrix Concatenate' incorporates:
       *  Constant: '<S235>/Constant8'
       *  Gain: '<S235>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Step1;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_n *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_ke;
      break;
    }

    /* End of MultiPortSwitch: '<S229>/Multiport Switch1' */

    /* MultiPortSwitch: '<S229>/Multiport Switch' incorporates:
     *  Constant: '<S229>/Constant'
=======
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
    /* UnitDelay: '<S80>/Output' */
    rtb_FixPtSum1 = GRM_HIL_DW.Output_DSTATE;

    /* DataTypeConversion: '<S79>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S80>/Output'
     */
    GRM_HIL_B.DataTypeConversion1 = GRM_HIL_DW.Output_DSTATE;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
    /* Constant: '<S37>/Constant' */
    GRM_HIL_B.Constant = GRM_HIL_P.Constant_Value_b;
  }

  /* Outputs for Enabled SubSystem: '<S37>/Send_to_FTHWICC' incorporates:
   *  EnablePort: '<S40>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S38>/Constant3' */
    GRM_HIL_DW.Send_to_FTHWICC_MODE = GRM_HIL_P.Constant3_Value_b;
  }

  if (GRM_HIL_DW.Send_to_FTHWICC_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
      /* S-Function (sldrtpo): '<S40>/Send_to_FTHWICC' */
      /* S-Function Block: <S40>/Send_to_FTHWICC */

      /* no code required */
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S37>/Send_to_FTHWICC' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S38>/Add' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant1'
     *  Constant: '<S38>/Constant2'
     *  Constant: '<S7>/Constant11'
     *  Product: '<S38>/Divide'
     *  Product: '<S38>/Divide1'
     */
    rtb_Add_p = GRM_HIL_P.Constant1_Value_h / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant11_Value_p - GRM_HIL_P.Constant2_Value_f;

    /* Memory: '<S38>/Memory' */
    rtb_Memory_m = GRM_HIL_DW.Memory_PreviousInput_g;

    /* MATLAB Function: '<S38>/Counter_with_external_limit' */
    GRM_HIL_Counter_with_external_limit(rtb_Add_p, rtb_Memory_m,
      &GRM_HIL_B.sf_Counter_with_external_limit_b);

    /* Gain: '<S46>/Gain12' incorporates:
     *  Constant: '<S5>/Constant12'
     */
    GRM_HIL_B.POS_lambda_WGS84_rad = GRM_HIL_P.Gain12_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_lambda_WGS84_rad;

    /* Gain: '<S46>/Gain13' incorporates:
     *  Constant: '<S5>/Constant13'
     */
    GRM_HIL_B.POS_mue_WGS84_rad = GRM_HIL_P.Gain13_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_mue_WGS84_rad;

    /* Gain: '<S46>/Gain14' incorporates:
     *  Constant: '<S5>/Constant14'
     */
    GRM_HIL_B.POS_h_WGS84_m = GRM_HIL_P.Gain14_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_h_WGS84_m;

    /* Gain: '<S46>/Gain15' incorporates:
     *  Constant: '<S5>/Constant15'
     */
    GRM_HIL_B.POS_x_NED_m = GRM_HIL_P.Gain15_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_x_NED_m;

    /* Gain: '<S46>/Gain16' incorporates:
     *  Constant: '<S5>/Constant16'
>>>>>>> origin/master
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_md) {
     case 1:
      /* Trigonometry: '<S230>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/Thrust_rot_z'
       *  Trigonometry: '<S230>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

<<<<<<< HEAD
      /* Trigonometry: '<S230>/Trigonometric Function3' incorporates:
       *  Constant: '<S225>/Thrust_rot_z'
       *  Trigonometry: '<S230>/Trigonometric Function'
       */
      rtb_Step1 = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S230>/Matrix Concatenate' incorporates:
       *  Constant: '<S230>/Constant7'
       *  Trigonometry: '<S230>/Trigonometric Function1'
       *  Trigonometry: '<S230>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_gi;
      rtb_MultiportSwitch[7] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[8] = rtb_Step1;

      /* SignalConversion generated from: '<S230>/Matrix Concatenate' incorporates:
       *  Constant: '<S230>/Constant8'
       *  Gain: '<S230>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_j;
      rtb_MultiportSwitch[4] = rtb_Step1;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_cy *
        rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S230>/Matrix Concatenate' incorporates:
       *  Constant: '<S230>/Constant'
       *  Constant: '<S230>/Constant1'
       *  Constant: '<S230>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_of;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_g;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_a;
      break;

     case 2:
      /* Trigonometry: '<S231>/Trigonometric Function3' incorporates:
       *  Constant: '<S225>/Thrust_rot_z'
       *  Trigonometry: '<S231>/Trigonometric Function'
       */
      rtb_VectorConcatenate_f_idx_0 = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S231>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/Thrust_rot_z'
       *  Trigonometry: '<S231>/Trigonometric Function2'
       */
      rtb_Step1 = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S231>/Matrix Concatenate' incorporates:
       *  Constant: '<S231>/Constant7'
       *  Gain: '<S231>/Gain1'
       *  Trigonometry: '<S231>/Trigonometric Function1'
       *  Trigonometry: '<S231>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_hv * rtb_Step1;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_je;
      rtb_MultiportSwitch[8] = rtb_VectorConcatenate_f_idx_0;

      /* SignalConversion generated from: '<S231>/Matrix Concatenate' incorporates:
       *  Constant: '<S231>/Constant'
       *  Constant: '<S231>/Constant1'
       *  Constant: '<S231>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_hw;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_k0;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_i;

      /* SignalConversion generated from: '<S231>/Matrix Concatenate' incorporates:
       *  Constant: '<S231>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_l;
      rtb_MultiportSwitch[2] = rtb_Step1;
      break;

     default:
      /* SignalConversion generated from: '<S232>/Matrix Concatenate' incorporates:
       *  Constant: '<S232>/Constant10'
       *  Constant: '<S232>/Constant11'
       *  Constant: '<S232>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_l5;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_c;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_h1;

      /* Trigonometry: '<S232>/Trigonometric Function1' incorporates:
       *  Constant: '<S225>/Thrust_rot_z'
       *  Trigonometry: '<S232>/Trigonometric Function4'
       */
      rtb_VectorConcatenate_f_idx_0 = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S232>/Trigonometric Function' incorporates:
       *  Constant: '<S225>/Thrust_rot_z'
       *  Trigonometry: '<S232>/Trigonometric Function3'
       */
      rtb_Step1 = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S232>/Matrix Concatenate' incorporates:
       *  Constant: '<S232>/Constant7'
       *  Trigonometry: '<S232>/Trigonometric Function'
       *  Trigonometry: '<S232>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[4] = rtb_Step1;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_p5;

      /* SignalConversion generated from: '<S232>/Matrix Concatenate' incorporates:
       *  Constant: '<S232>/Constant8'
       *  Gain: '<S232>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Step1;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_f0 *
        rtb_VectorConcatenate_f_idx_0;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gw;
      break;
    }

    /* End of MultiPortSwitch: '<S229>/Multiport Switch' */

    /* Product: '<S229>/3. Rotation' */
    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_MultiportSwitch1_tmp = i_0 + 3 * i;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] = 0.0;
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i] *
          rtb_MultiportSwitch1[i_0];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i +
          1] * rtb_MultiportSwitch1[i_0 + 3];
        rtb_vBEB_a_tmp[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i +
          2] * rtb_MultiportSwitch1[i_0 + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_MultiportSwitch1_tmp = i_0 + 3 * i;
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] = 0.0;
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i] *
          rtb_MultiportSwitch2[i_0];
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 1] *
          rtb_MultiportSwitch2[i_0 + 3];
        GRM_HIL_B.T12_o[rtb_MultiportSwitch1_tmp] += rtb_vBEB_a_tmp[3 * i + 2] *
          rtb_MultiportSwitch2[i_0 + 6];
      }
=======
    /* Gain: '<S46>/Gain17' incorporates:
     *  Constant: '<S5>/Constant17'
     */
    GRM_HIL_B.POS_z_NED_m = GRM_HIL_P.Gain17_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_z_NED_m;
  }

  /* MATLAB Function: '<S63>/MATLAB Function' incorporates:
   *  Fcn: '<S62>/Fcn1'
   *  Fcn: '<S62>/Fcn10'
   *  Fcn: '<S62>/Fcn11'
   *  Fcn: '<S62>/Fcn12'
   *  Fcn: '<S62>/Fcn4'
   *  Fcn: '<S62>/Fcn6'
   *  Fcn: '<S62>/Fcn8'
   *  Fcn: '<S62>/Fcn9'
   *  Integrator: '<S72>/Integrator'
   *  Integrator: '<S72>/Integrator1'
   *  Integrator: '<S72>/Integrator2'
   *  Integrator: '<S77>/Integrator'
   *  Integrator: '<S77>/Integrator1'
   *  Integrator: '<S77>/Integrator2'
   *  MATLAB Function: '<S63>/MATLAB Function1'
   *  MATLAB Function: '<S63>/MATLAB Function2'
   */
  rtb_Add3 = cos(GRM_HIL_X.Integrator2_CSTATE);
  rtb_sincos_o1_idx_1 = sin(GRM_HIL_X.Integrator2_CSTATE);
  rtb_sincos_o1_idx_0 = sin(GRM_HIL_X.Integrator_CSTATE_k);
  rtb_Add16_j = sin(GRM_HIL_X.Integrator1_CSTATE);
  rtb_PulseGenerator = cos(GRM_HIL_X.Integrator1_CSTATE);
  rtb_PulseGenerator1 = cos(GRM_HIL_X.Integrator_CSTATE_k);
  rtb_sincos_o1_idx_2 = ((rtb_Add3 * rtb_Add16_j * rtb_sincos_o1_idx_0 -
    rtb_sincos_o1_idx_1 * rtb_PulseGenerator1) * GRM_HIL_X.Integrator1_CSTATE_p
    + GRM_HIL_X.Integrator_CSTATE_j * rtb_Add3 * rtb_PulseGenerator) + (rtb_Add3
    * rtb_Add3 * rtb_Add16_j + rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_0) *
    GRM_HIL_X.Integrator2_CSTATE_a;

  /* MATLAB Function: '<S63>/MATLAB Function1' incorporates:
   *  Integrator: '<S77>/Integrator'
   *  Integrator: '<S77>/Integrator1'
   *  Integrator: '<S77>/Integrator2'
   */
  rtb_Add3 = ((rtb_sincos_o1_idx_0 * rtb_Add16_j * rtb_sincos_o1_idx_1 +
               rtb_Add3 * rtb_PulseGenerator1) * GRM_HIL_X.Integrator1_CSTATE_p
              + GRM_HIL_X.Integrator_CSTATE_j * rtb_sincos_o1_idx_1 *
              rtb_PulseGenerator) + (rtb_Add16_j * rtb_sincos_o1_idx_1 *
    rtb_PulseGenerator1 - rtb_Add3 * rtb_sincos_o1_idx_0) *
    GRM_HIL_X.Integrator2_CSTATE_a;

  /* MATLAB Function: '<S63>/MATLAB Function2' incorporates:
   *  Integrator: '<S77>/Integrator'
   *  Integrator: '<S77>/Integrator1'
   *  Integrator: '<S77>/Integrator2'
   */
  rtb_Add16_j = (GRM_HIL_X.Integrator1_CSTATE_p * rtb_PulseGenerator *
                 rtb_sincos_o1_idx_0 + -GRM_HIL_X.Integrator_CSTATE_j *
                 rtb_Add16_j) + GRM_HIL_X.Integrator2_CSTATE_a *
    rtb_PulseGenerator * rtb_PulseGenerator1;

  /* Integrator: '<S76>/Integrator1' incorporates:
   *  Integrator: '<S76>/Integrator2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_d != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_d = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator1_IWORK_n != 0)) {
      GRM_HIL_X.Integrator1_CSTATE_e = GRM_HIL_B.POS_mue_WGS84_rad;
    }

    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_g != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_g = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator2_IWORK_e != 0)) {
      GRM_HIL_X.Integrator2_CSTATE_d = GRM_HIL_B.POS_h_WGS84_m;
    }
  }

  /* MATLAB Function: '<S59>/MATLAB Function' incorporates:
   *  Integrator: '<S76>/Integrator1'
   */
  rtb_sincos_o1_idx_1 = sin(GRM_HIL_X.Integrator1_CSTATE_e);
  rtb_sincos_o1_idx_1 = 1.0 - rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_1 *
    0.0066943800042608363;
  rtb_sincos_o2_idx_0 = 6.378137E+6 / sqrt(rtb_sincos_o1_idx_1);

  /* Gain: '<S61>/Gain' incorporates:
   *  Sum: '<S61>/Add12'
   */
  GRM_HIL_B.Gain_o = (((rtb_Fin_1_Pos_rad + rtb_Fin_2_Pos_rad) +
                       rtb_Fin_3_Pos_rad) + rtb_Fin_4_Pos_rad) *
    GRM_HIL_P.Gain_Gain_kk;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S72>/Data Type Conversion' */
    GRM_HIL_B.DataTypeConversion = GRM_HIL_B.run;

    /* DataTypeConversion: '<S74>/Data Type Conversion' */
    GRM_HIL_B.DataTypeConversion_d = GRM_HIL_B.run;
  }

  /* Fcn: '<S62>/Fcn5' incorporates:
   *  Fcn: '<S62>/Fcn7'
   *  Integrator: '<S72>/Integrator1'
   */
  rtb_Fin_1_Pos_rad = tan(GRM_HIL_X.Integrator1_CSTATE);

  /* Product: '<S72>/Product' incorporates:
   *  Fcn: '<S62>/Fcn5'
   *  Product: '<S62>/Multiply'
   *  Product: '<S62>/Multiply1'
   *  Product: '<S62>/Multiply2'
   *  Product: '<S62>/Multiply3'
   *  Sum: '<S62>/Add'
   */
  GRM_HIL_B.Product = ((rtb_sincos_o1_idx_0 * rtb_Fin_1_Pos_rad * rtb_q_B_radDs
                        + rtb_p_B_radDs) + rtb_PulseGenerator1 *
                       rtb_Fin_1_Pos_rad * rtb_r_B_radDs) *
    GRM_HIL_B.DataTypeConversion;

  /* Product: '<S72>/Product1' incorporates:
   *  Fcn: '<S62>/Fcn1'
   *  Product: '<S62>/Multiply4'
   *  Product: '<S62>/Multiply5'
   *  Sum: '<S62>/Add1'
   */
  GRM_HIL_B.Product1 = (rtb_PulseGenerator1 * rtb_q_B_radDs +
                        -rtb_sincos_o1_idx_0 * rtb_r_B_radDs) *
    GRM_HIL_B.DataTypeConversion;

  /* Product: '<S72>/Product2' incorporates:
   *  Product: '<S62>/Divide'
   *  Product: '<S62>/Divide1'
   *  Product: '<S62>/Multiply6'
   *  Product: '<S62>/Multiply7'
   *  Sum: '<S62>/Add2'
   */
  GRM_HIL_B.Product2 = (rtb_sincos_o1_idx_0 / rtb_PulseGenerator * rtb_q_B_radDs
                        + rtb_PulseGenerator1 / rtb_PulseGenerator *
                        rtb_r_B_radDs) * GRM_HIL_B.DataTypeConversion;

  /* Product: '<S74>/Multiply' */
  GRM_HIL_B.Multiply = GRM_HIL_B.OutportBufferFormotor_state_perc_dot *
    GRM_HIL_B.DataTypeConversion_d;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S75>/Data Type Conversion' */
    GRM_HIL_B.DataTypeConversion_n = GRM_HIL_B.run;
  }

  /* Integrator: '<S75>/Integrator' incorporates:
   *  Integrator: '<S75>/Integrator1'
   *  Integrator: '<S75>/Integrator2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator_IWORK_m != 0)) {
      GRM_HIL_X.Integrator_CSTATE_d = GRM_HIL_B.POS_x_NED_m;
    }

    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_i != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_i = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator1_IWORK_m != 0)) {
      GRM_HIL_X.Integrator1_CSTATE_eg = GRM_HIL_B.POS_y_NED_m;
    }

    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_m != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_m = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator2_IWORK_c != 0)) {
      GRM_HIL_X.Integrator2_CSTATE_e = GRM_HIL_B.POS_z_NED_m;
>>>>>>> origin/master
    }

<<<<<<< HEAD
    /* End of Product: '<S229>/3. Rotation' */

    /* Sum: '<S224>/Subtract' incorporates:
     *  Constant: '<S224>/Constant16'
     *  Constant: '<S224>/Constant17'
     */
    for (i = 0; i < 9; i++) {
      GRM_HIL_B.Subtract_d[i] = GRM_HIL_P.Constant17_Value_j[i] -
        GRM_HIL_P.Constant16_Value_i[i];
    }

    /* End of Sum: '<S224>/Subtract' */

    /* Sum: '<S224>/Subtract4' incorporates:
     *  Constant: '<S224>/Constant18'
     *  Constant: '<S224>/Constant19'
     */
    GRM_HIL_B.Subtract4 = GRM_HIL_P.Constant19_Value -
      GRM_HIL_P.Constant18_Value;

    /* Math: '<S225>/Math Function' */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.MathFunction[3 * i] = GRM_HIL_B.T12_o[i];
      GRM_HIL_B.MathFunction[3 * i + 1] = GRM_HIL_B.T12_o[i + 3];
      GRM_HIL_B.MathFunction[3 * i + 2] = GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Math: '<S225>/Math Function' */
  }

  /* Sum: '<S224>/Subtract5' incorporates:
   *  Constant: '<S224>/Constant20'
   */
  rtb_Add = rtb_Product7_ma - GRM_HIL_P.Constant20_Value;

  /* Sum: '<S224>/Subtract6' incorporates:
   *  Constant: '<S224>/Constant21'
   *  Product: '<S224>/Divide'
   */
  for (i = 0; i < 9; i++) {
    rtb_MatrixMultiply_tmp[i] = rtb_Add * GRM_HIL_B.Subtract_d[i] /
      GRM_HIL_B.Subtract4 + GRM_HIL_P.Constant21_Value[i];
  }

  /* End of Sum: '<S224>/Subtract6' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S225>/Matrix Multiply' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_MultiportSwitch1_tmp = i + 3 * i_0;
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] = 0.0;
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] += rtb_MatrixMultiply_tmp[3 *
        i_0] * GRM_HIL_B.T12_o[i];
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] += rtb_MatrixMultiply_tmp[3 *
        i_0 + 1] * GRM_HIL_B.T12_o[i + 3];
      rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] += rtb_MatrixMultiply_tmp[3 *
        i_0 + 2] * GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Product: '<S225>/Matrix Multiply' */

    /* Product: '<S195>/Product1' */
    rtb_Product1_m[i] = 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* Sum: '<S226>/Add7' incorporates:
       *  Constant: '<S226>/Constant16'
       *  Product: '<S195>/Product1'
       *  Product: '<S225>/Matrix Multiply1'
       *  Product: '<S228>/Product'
       *  Sum: '<S222>/Add'
       *  Sum: '<S222>/Add4'
       */
      rtb_MultiportSwitch1_tmp = 3 * i_0 + i;
      rtb_JBBB[rtb_MultiportSwitch1_tmp] = ((((GRM_HIL_B.MathFunction[3 * i_0 +
        1] * rtb_MultiportSwitch[i + 3] + GRM_HIL_B.MathFunction[3 * i_0] *
        rtb_MultiportSwitch[i]) + GRM_HIL_B.MathFunction[3 * i_0 + 2] *
        rtb_MultiportSwitch[i + 6]) + rtb_JBBB[rtb_MultiportSwitch1_tmp] *
        rtb_Product7_ma) + rtb_TBG[rtb_MultiportSwitch1_tmp]) +
        GRM_HIL_P.Constant16_Value_c[rtb_MultiportSwitch1_tmp];

      /* Product: '<S195>/Product1' incorporates:
       *  Integrator: '<S193>/integration_eom'
       */
      rtb_Product1_m[i] += rtb_JBBB[rtb_MultiportSwitch1_tmp] *
        GRM_HIL_X.integration_eom_CSTATE[i_0 + 10];
    }
  }

  /* Sum: '<S198>/Sum' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S198>/Product2'
   *  Product: '<S198>/Product3'
   */
  rtb_sincos_o2[0] = GRM_HIL_X.integration_eom_CSTATE[11] * rtb_Product1_m[2] -
    GRM_HIL_X.integration_eom_CSTATE[12] * rtb_Product1_m[1];

  /* Sum: '<S198>/Sum1' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S198>/Product4'
   *  Product: '<S198>/Product5'
   */
  rtb_sincos_o2[1] = GRM_HIL_X.integration_eom_CSTATE[12] * rtb_Product1_m[0] -
    GRM_HIL_X.integration_eom_CSTATE[10] * rtb_Product1_m[2];

  /* Sum: '<S198>/Sum2' incorporates:
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S198>/Product6'
   *  Product: '<S198>/Product7'
   */
  rtb_sincos_o2[2] = GRM_HIL_X.integration_eom_CSTATE[10] * rtb_Product1_m[1] -
    GRM_HIL_X.integration_eom_CSTATE[11] * rtb_Product1_m[0];

  /* Sum: '<S195>/Subtract' incorporates:
   *  Constant: '<S186>/Constant9'
   *  Integrator: '<S193>/integration_eom'
   *  Product: '<S195>/Product'
   */
  for (i = 0; i < 3; i++) {
    frac_1[i] = (frac_1[i] - ((GRM_HIL_P.Constant9_Value_cv[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[11] + GRM_HIL_P.Constant9_Value_cv[i] *
      GRM_HIL_X.integration_eom_CSTATE[10]) + GRM_HIL_P.Constant9_Value_cv[i + 6]
      * GRM_HIL_X.integration_eom_CSTATE[12])) - rtb_sincos_o2[i];
  }

  /* End of Sum: '<S195>/Subtract' */

  /* Product: '<S195>/Divide1' */
  rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(rtb_JBBB, frac_1, &GRM_HIL_B.d_x[10]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S7>/Synchronize_to_realtime' incorporates:
     *  EnablePort: '<S241>/Enable'
     */
=======
  /* End of Integrator: '<S75>/Integrator' */

  /* Product: '<S75>/Product' */
  GRM_HIL_B.Product_b = rtb_sincos_o1_idx_2 * GRM_HIL_B.DataTypeConversion_n;

  /* Product: '<S75>/Product1' */
  GRM_HIL_B.Product1_f = rtb_Add3 * GRM_HIL_B.DataTypeConversion_n;

  /* Product: '<S75>/Product2' */
  GRM_HIL_B.Product2_d = rtb_Add16_j * GRM_HIL_B.DataTypeConversion_n;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S76>/Data Type Conversion' */
    GRM_HIL_B.DataTypeConversion_k = GRM_HIL_B.run;
  }

  /* Integrator: '<S76>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    didZcEventOccur = (GRM_HIL_B.reset &&
                       (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_ff != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_ff = GRM_HIL_B.reset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (GRM_HIL_DW.Integrator_IWORK_l != 0)) {
      GRM_HIL_X.Integrator_CSTATE_jz = GRM_HIL_B.POS_lambda_WGS84_rad;
    }
  }

  /* End of Integrator: '<S76>/Integrator' */

  /* Product: '<S76>/Product' incorporates:
   *  Integrator: '<S76>/Integrator1'
   *  Integrator: '<S76>/Integrator2'
   *  MATLAB Function: '<S59>/MATLAB Function'
   */
  GRM_HIL_B.Product_g = rtb_Add3 / ((rtb_sincos_o2_idx_0 +
    GRM_HIL_X.Integrator2_CSTATE_d) * cos(GRM_HIL_X.Integrator1_CSTATE_e)) *
    GRM_HIL_B.DataTypeConversion_k;

  /* Product: '<S76>/Product1' incorporates:
   *  Integrator: '<S76>/Integrator2'
   *  MATLAB Function: '<S59>/MATLAB Function'
   */
  GRM_HIL_B.Product1_g = rtb_sincos_o1_idx_2 / (rtb_sincos_o2_idx_0 *
    0.99330561999573919 / rtb_sincos_o1_idx_1 + GRM_HIL_X.Integrator2_CSTATE_d) *
    GRM_HIL_B.DataTypeConversion_k;

  /* Product: '<S76>/Product2' incorporates:
   *  MATLAB Function: '<S59>/MATLAB Function'
   */
  GRM_HIL_B.Product2_d1 = -rtb_Add16_j * GRM_HIL_B.DataTypeConversion_k;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S77>/Data Type Conversion' */
    GRM_HIL_B.DataTypeConversion_e = GRM_HIL_B.run;

>>>>>>> origin/master
    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant9'
     *  Logic: '<S7>/NOT'
     */
<<<<<<< HEAD
    if (GRM_HIL_P.Constant1_Value_c3 && (!GRM_HIL_P.Constant9_Value_b) &&
        GRM_HIL_P.Constant3_Value_it) {
      /* S-Function (sldrtsync): '<S241>/Real-Time Synchronization' */
      /* S-Function Block: <S241>/Real-Time Synchronization */
=======
    GRM_HIL_B.LogicalOperator2 = (GRM_HIL_P.Constant1_Value_c &&
      (!GRM_HIL_P.Constant9_Value_b) && GRM_HIL_P.Constant3_Value_i);
  }

  /* Product: '<S77>/Product' */
  GRM_HIL_B.Product_p = rtb_Add_g * GRM_HIL_B.DataTypeConversion_e;

  /* Product: '<S77>/Product1' */
  GRM_HIL_B.Product1_o = rtb_ACC_y_B_mDs2_d * GRM_HIL_B.DataTypeConversion_e;

  /* Product: '<S77>/Product2' */
  GRM_HIL_B.Product2_n = rtb_ACC_z_B_mDs2_i * GRM_HIL_B.DataTypeConversion_e;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
    /* Outputs for Enabled SubSystem: '<S7>/Synchronize_to_realtime' incorporates:
     *  EnablePort: '<S78>/Enable'
     */
    /* SignalConversion generated from: '<S78>/Enable' */
    if (GRM_HIL_B.LogicalOperator2) {
      /* S-Function (sldrtsync): '<S78>/Real-Time Synchronization' */
      /* S-Function Block: <S78>/Real-Time Synchronization */
>>>>>>> origin/master
      {
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
      }
    }

<<<<<<< HEAD
    /* End of Logic: '<S7>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S7>/Synchronize_to_realtime' */

    /* Sum: '<S244>/FixPt Sum1' incorporates:
     *  Constant: '<S244>/FixPt Constant'
=======
    /* End of SignalConversion generated from: '<S78>/Enable' */
    /* End of Outputs for SubSystem: '<S7>/Synchronize_to_realtime' */

    /* Sum: '<S81>/FixPt Sum1' incorporates:
     *  Constant: '<S81>/FixPt Constant'
>>>>>>> origin/master
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)rtb_FixPtSum1 +
      GRM_HIL_P.FixPtConstant_Value);

<<<<<<< HEAD
    /* Switch: '<S245>/FixPt Switch' incorporates:
     *  Constant: '<S245>/Constant'
     */
    if (rtb_FixPtSum1 > GRM_HIL_P.WrapToZero_Threshold) {
      GRM_HIL_B.FixPtSwitch = GRM_HIL_P.Constant_Value_lk;
=======
    /* Switch: '<S82>/FixPt Switch' incorporates:
     *  Constant: '<S82>/Constant'
     */
    if (rtb_FixPtSum1 > GRM_HIL_P.WrapToZero_Threshold) {
      GRM_HIL_B.FixPtSwitch = GRM_HIL_P.Constant_Value_l;
>>>>>>> origin/master
    } else {
      GRM_HIL_B.FixPtSwitch = rtb_FixPtSum1;
    }

<<<<<<< HEAD
    /* End of Switch: '<S245>/FixPt Switch' */
=======
    /* End of Switch: '<S82>/FixPt Switch' */
>>>>>>> origin/master
  }
}

/* Model update function */
void GRM_HIL_update(void)
{
<<<<<<< HEAD
  real_T *lastU;

  /* Update for Integrator: '<S193>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK = 0;

  /* Update for Integrator: '<S161>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_g = 0;

  /* Update for Integrator: '<S162>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_l = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S19>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput =
      GRM_HIL_B.sf_Counter_with_external_limit.value;

    /* Update for UnitDelay: '<S243>/Output' */
    GRM_HIL_DW.Output_DSTATE = GRM_HIL_B.FixPtSwitch;
  }

  /* Update for Enabled SubSystem: '<S38>/Send_to_FTHWICC' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  if (GRM_HIL_DW.Send_to_FTHWICC_MODE && (rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[2] == 0)) {
    /* Update for S-Function (sldrtpo): '<S41>/Send_to_FTHWICC' */

    /* S-Function Block: <S41>/Send_to_FTHWICC */
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
        uint16_T pktout = GRM_HIL_B.DataTypeConversion1;
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

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 52U,
                     &GRM_HIL_P.Send_to_FTHWICC_PacketID, (double*) outdata,
                     NULL);
    }
  }

  /* End of Update for SubSystem: '<S38>/Send_to_FTHWICC' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S39>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput_d =
      GRM_HIL_B.sf_Counter_with_external_limit_j.value;
  }

  /* Update for Derivative: '<S163>/Derivative1' */
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

  /* End of Update for Derivative: '<S163>/Derivative1' */

  /* Update for Derivative: '<S163>/Derivative' */
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

  /* End of Update for Derivative: '<S163>/Derivative' */
=======
  /* Update for Enabled SubSystem: '<S54>/Propulsion' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (GRM_HIL_DW.Propulsion_MODE && (rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0)) {
    /* Update for Memory: '<S60>/lock' */
    GRM_HIL_DW.lock_PreviousInput = GRM_HIL_B.LogicalOperator1;
  }

  /* End of Update for SubSystem: '<S54>/Propulsion' */

  /* Update for Integrator: '<S74>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK = 0;

  /* Update for Integrator: '<S72>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_i = 0;

  /* Update for Integrator: '<S72>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S72>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S18>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput =
      GRM_HIL_B.sf_Counter_with_external_limit.value;
  }

  /* Update for Integrator: '<S77>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_ic = 0;

  /* Update for Integrator: '<S77>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_g = 0;

  /* Update for Integrator: '<S77>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_m = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay: '<S80>/Output' */
    GRM_HIL_DW.Output_DSTATE = GRM_HIL_B.FixPtSwitch;
  }

  /* Update for Enabled SubSystem: '<S37>/Send_to_FTHWICC' incorporates:
   *  EnablePort: '<S40>/Enable'
   */
  if (GRM_HIL_DW.Send_to_FTHWICC_MODE && (rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[2] == 0)) {
    /* Update for S-Function (sldrtpo): '<S40>/Send_to_FTHWICC' */

    /* S-Function Block: <S40>/Send_to_FTHWICC */
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
        uint16_T pktout = GRM_HIL_B.DataTypeConversion1;
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
        real_T pktout = GRM_HIL_B.Constant;
        *outdp.p_real_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 52U,
                     &GRM_HIL_P.Send_to_FTHWICC_PacketID, (double*) outdata,
                     NULL);
    }
  }

  /* End of Update for SubSystem: '<S37>/Send_to_FTHWICC' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S38>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput_g =
      GRM_HIL_B.sf_Counter_with_external_limit_b.value;
  }

  /* Update for Integrator: '<S76>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_n = 0;

  /* Update for Integrator: '<S76>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_e = 0;

  /* Update for Integrator: '<S75>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_m = 0;

  /* Update for Integrator: '<S75>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_m = 0;

  /* Update for Integrator: '<S75>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_c = 0;

  /* Update for Integrator: '<S76>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_l = 0;
>>>>>>> origin/master
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
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
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

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++GRM_HIL_M->Timing.clockTick4)) {
      ++GRM_HIL_M->Timing.clockTickH4;
    }

    GRM_HIL_M->Timing.t[4] = GRM_HIL_M->Timing.clockTick4 *
      GRM_HIL_M->Timing.stepSize4 + GRM_HIL_M->Timing.clockTickH4 *
      GRM_HIL_M->Timing.stepSize4 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void GRM_HIL_derivatives(void)
{
<<<<<<< HEAD
  boolean_T lsat;
  boolean_T usat;
=======
>>>>>>> origin/master
  real_T TransferFcn1_CSTATE_tmp;
  real_T TransferFcn1_CSTATE_tmp_0;
  XDot_GRM_HIL_T *_rtXdot;
  _rtXdot = ((XDot_GRM_HIL_T *) GRM_HIL_M->derivs);

<<<<<<< HEAD
  /* Derivatives for Integrator: '<S193>/integration_eom' */
  memcpy(&_rtXdot->integration_eom_CSTATE[0], &GRM_HIL_B.d_x[0], 13U * sizeof
         (real_T));

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn' */
=======
  /* Derivatives for Integrator: '<S74>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.Multiply;

  /* Derivatives for Integrator: '<S72>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = GRM_HIL_B.Product;

  /* Derivatives for Integrator: '<S72>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = GRM_HIL_B.Product1;

  /* Derivatives for Integrator: '<S72>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = GRM_HIL_B.Product2;

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn' */
>>>>>>> origin/master
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

<<<<<<< HEAD
  /* Derivatives for Integrator: '<S161>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[0] = GRM_HIL_B.VectorConcatenate_m[0];

  /* Derivatives for Integrator: '<S162>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[0] = GRM_HIL_B.VectorConcatenate_k[0];

  /* Derivatives for Integrator: '<S161>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[1] = GRM_HIL_B.VectorConcatenate_m[1];

  /* Derivatives for Integrator: '<S162>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[1] = GRM_HIL_B.VectorConcatenate_k[1];

  /* Derivatives for Integrator: '<S161>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[2] = GRM_HIL_B.VectorConcatenate_m[2];

  /* Derivatives for Integrator: '<S162>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[2] = GRM_HIL_B.VectorConcatenate_k[2];

  /* Derivatives for Integrator: '<S161>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[3] = GRM_HIL_B.VectorConcatenate_m[3];

  /* Derivatives for Integrator: '<S162>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[3] = GRM_HIL_B.VectorConcatenate_k[3];

  /* Derivatives for Integrator: '<S129>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE <= GRM_HIL_P.Rudder_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE >= GRM_HIL_P.Rudder_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l > 0.0))
      || (usat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE = GRM_HIL_B.sf_Limiting_Rate.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S129>/Integrator1' */

  /* Derivatives for Integrator: '<S130>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_g <= GRM_HIL_P.Rudder1_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_g >= GRM_HIL_P.Rudder1_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_g = GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_g = 0.0;
  }

  /* End of Derivatives for Integrator: '<S130>/Integrator1' */

  /* Derivatives for Integrator: '<S131>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_a <= GRM_HIL_P.Rudder2_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_a >= GRM_HIL_P.Rudder2_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_a = GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_a = 0.0;
  }

  /* End of Derivatives for Integrator: '<S131>/Integrator1' */

  /* Derivatives for Integrator: '<S132>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_i <= GRM_HIL_P.Rudder3_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_i >= GRM_HIL_P.Rudder3_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_i = GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_i = 0.0;
  }

  /* End of Derivatives for Integrator: '<S132>/Integrator1' */

  /* Derivatives for TransferFcn: '<S25>/Transfer Fcn2' */
=======
  /* Derivatives for TransferFcn: '<S54>/dy2ay' */
  _rtXdot->dy2ay_CSTATE[0] = 0.0;
  _rtXdot->dy2ay_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] * GRM_HIL_X.dy2ay_CSTATE[0];
  _rtXdot->dy2ay_CSTATE[1] = 0.0;
  _rtXdot->dy2ay_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] * GRM_HIL_X.dy2ay_CSTATE[1];
  _rtXdot->dy2ay_CSTATE[1] += GRM_HIL_X.dy2ay_CSTATE[0];
  _rtXdot->dy2ay_CSTATE[0] += GRM_HIL_B.Gain2;

  /* Derivatives for TransferFcn: '<S54>/dp2az' */
  _rtXdot->dp2az_CSTATE[0] = 0.0;
  _rtXdot->dp2az_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2az.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] * GRM_HIL_X.dp2az_CSTATE[0];
  _rtXdot->dp2az_CSTATE[1] = 0.0;
  _rtXdot->dp2az_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2az.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] * GRM_HIL_X.dp2az_CSTATE[1];
  _rtXdot->dp2az_CSTATE[1] += GRM_HIL_X.dp2az_CSTATE[0];
  _rtXdot->dp2az_CSTATE[0] += GRM_HIL_B.Gain1;

  /* Derivatives for TransferFcn: '<S54>/dr2roll' */
  _rtXdot->dr2roll_CSTATE = 0.0;
  _rtXdot->dr2roll_CSTATE += -GRM_HIL_P.FDM_Linear_TF.dr2roll.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dr2roll.denom[0] * GRM_HIL_X.dr2roll_CSTATE;
  _rtXdot->dr2roll_CSTATE += GRM_HIL_B.Gain_o;

  /* Derivatives for TransferFcn: '<S54>/dp2pitch' */
  _rtXdot->dp2pitch_CSTATE[0] = 0.0;
  _rtXdot->dp2pitch_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[0];
  _rtXdot->dp2pitch_CSTATE[1] = 0.0;
  _rtXdot->dp2pitch_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[1];
  _rtXdot->dp2pitch_CSTATE[1] += GRM_HIL_X.dp2pitch_CSTATE[0];
  _rtXdot->dp2pitch_CSTATE[0] += GRM_HIL_B.Gain1;

  /* Derivatives for TransferFcn: '<S54>/dy2yaw' */
  _rtXdot->dy2yaw_CSTATE[0] = 0.0;
  _rtXdot->dy2yaw_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[0];
  _rtXdot->dy2yaw_CSTATE[1] = 0.0;
  _rtXdot->dy2yaw_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[1];
  _rtXdot->dy2yaw_CSTATE[1] += GRM_HIL_X.dy2yaw_CSTATE[0];
  _rtXdot->dy2yaw_CSTATE[0] += GRM_HIL_B.Gain2;

  /* Derivatives for TransferFcn: '<S24>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_j = 0.0;
  _rtXdot->TransferFcn_CSTATE_j +=
    -GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[1] /
    GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0] *
    GRM_HIL_X.TransferFcn_CSTATE_j;
  _rtXdot->TransferFcn_CSTATE_j += GRM_HIL_B.Gain;

  /* Derivatives for TransferFcn: '<S24>/Transfer Fcn2' */
>>>>>>> origin/master
  _rtXdot->TransferFcn2_CSTATE_e = 0.0;
  _rtXdot->TransferFcn2_CSTATE_e +=
    -GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[1] /
    GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn2_CSTATE_e;
  _rtXdot->TransferFcn2_CSTATE_e += GRM_HIL_B.Sum3;

  /* Derivatives for TransferFcn: '<S25>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_e = 0.0;
  _rtXdot->TransferFcn1_CSTATE_e +=
    -GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[1] /
    GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_e;
  _rtXdot->TransferFcn1_CSTATE_e += GRM_HIL_B.Sum1;
<<<<<<< HEAD

  /* Derivatives for Integrator: '<S129>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.sf_Limiting_Acceleration.dd_siB_l;

  /* Derivatives for Integrator: '<S130>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = GRM_HIL_B.sf_Limiting_Acceleration_i.dd_siB_l;

  /* Derivatives for Integrator: '<S131>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = GRM_HIL_B.sf_Limiting_Acceleration_p.dd_siB_l;

  /* Derivatives for Integrator: '<S132>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = GRM_HIL_B.sf_Limiting_Acceleration_h.dd_siB_l;
=======

  /* Derivatives for Integrator: '<S77>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = GRM_HIL_B.Product_p;

  /* Derivatives for Integrator: '<S77>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = GRM_HIL_B.Product1_o;

  /* Derivatives for Integrator: '<S77>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = GRM_HIL_B.Product2_n;

  /* Derivatives for Integrator: '<S76>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = GRM_HIL_B.Product1_g;

  /* Derivatives for Integrator: '<S76>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_d = GRM_HIL_B.Product2_d1;

  /* Derivatives for Integrator: '<S75>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = GRM_HIL_B.Product_b;

  /* Derivatives for Integrator: '<S75>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_eg = GRM_HIL_B.Product1_f;

  /* Derivatives for Integrator: '<S75>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = GRM_HIL_B.Product2_d;

  /* Derivatives for Integrator: '<S76>/Integrator' */
  _rtXdot->Integrator_CSTATE_jz = GRM_HIL_B.Product_g;
>>>>>>> origin/master
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
<<<<<<< HEAD
  /* Start for Constant: '<S186>/Constant' */
  memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
         (real_T));

  /* Start for Constant: '<S161>/Constant8' */
  GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];

  /* Start for Constant: '<S162>/Constant8' */
  GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];

  /* Start for Constant: '<S161>/Constant8' */
  GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];

  /* Start for Constant: '<S162>/Constant8' */
  GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];

  /* Start for Constant: '<S161>/Constant8' */
  GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];

  /* Start for Constant: '<S162>/Constant8' */
  GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];

  /* Start for Constant: '<S161>/Constant8' */
  GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];

  /* Start for Constant: '<S162>/Constant8' */
  GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];
=======
  /* Start for Enabled SubSystem: '<S54>/Propulsion' */
  GRM_HIL_DW.Propulsion_MODE = false;

  /* Start for Enabled SubSystem: '<S60>/hold_time' */
  GRM_HIL_DW.hold_time_MODE = false;

  /* End of Start for SubSystem: '<S60>/hold_time' */

  /* Start for Enabled SubSystem: '<S60>/Subsystem' */
  GRM_HIL_DW.Subsystem_MODE = false;

  /* End of Start for SubSystem: '<S60>/Subsystem' */
  /* End of Start for SubSystem: '<S54>/Propulsion' */

  /* Start for Constant: '<S7>/Constant2' */
  GRM_HIL_B.reset = GRM_HIL_P.Constant2_Value_f5;

  /* Start for Enabled SubSystem: '<S54>/Gravity' */
  GRM_HIL_DW.Gravity_MODE = false;

  /* End of Start for SubSystem: '<S54>/Gravity' */

  /* Start for Enabled SubSystem: '<S54>/Drag' */
  GRM_HIL_DW.Drag_MODE = false;

  /* End of Start for SubSystem: '<S54>/Drag' */
>>>>>>> origin/master

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

<<<<<<< HEAD
  /* Start for Enabled SubSystem: '<S18>/Com_to_FCC_emul' */
=======
  /* Start for Enabled SubSystem: '<S17>/Com_to_FCC_emul' */
>>>>>>> origin/master
  GRM_HIL_DW.Com_to_FCC_emul_MODE = false;

  /* End of Start for SubSystem: '<S18>/Com_to_FCC_emul' */

  /* Start for Enabled SubSystem: '<S29>/Pass' */
  GRM_HIL_DW.Pass_MODE = false;

  /* End of Start for SubSystem: '<S29>/Pass' */

  /* Start for Enabled SubSystem: '<S29>/Saturate' */
  GRM_HIL_DW.Saturate_MODE = false;

  /* End of Start for SubSystem: '<S29>/Saturate' */

  /* Start for Constant: '<S7>/Constant' */
<<<<<<< HEAD
  GRM_HIL_B.run = GRM_HIL_P.Constant_Value_gt;

  /* Start for Constant: '<S7>/Constant2' */
  GRM_HIL_B.reset = GRM_HIL_P.Constant2_Value_f5;

  /* Start for Constant: '<S7>/Constant7' */
  GRM_HIL_B.enable_gimbal_ctrl_flg = GRM_HIL_P.Constant7_Value_e;

  /* Start for Constant: '<S7>/Constant8' */
  GRM_HIL_B.stop_gimbal_flg = GRM_HIL_P.Constant8_Value_lr;

  /* Start for Constant: '<S38>/Constant' */
  GRM_HIL_B.Constant_i = GRM_HIL_P.Constant_Value_p3;

  /* Start for Enabled SubSystem: '<S38>/Send_to_FTHWICC' */
  GRM_HIL_DW.Send_to_FTHWICC_MODE = false;

  /* Start for S-Function (sldrtpo): '<S41>/Send_to_FTHWICC' */

  /* S-Function Block: <S41>/Send_to_FTHWICC */
  /* no initial value should be set */
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S193>/integration_eom' incorporates:
   *  Integrator: '<S161>/integration_eom'
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

  /* End of InitializeConditions for Integrator: '<S193>/integration_eom' */

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

  /* InitializeConditions for Integrator: '<S161>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_g = 1;

  /* InitializeConditions for Integrator: '<S162>/integration_eom' */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.integration_eom_CSTATE_f[0] = 0.0;
    GRM_HIL_X.integration_eom_CSTATE_f[1] = 0.0;
    GRM_HIL_X.integration_eom_CSTATE_f[2] = 0.0;
    GRM_HIL_X.integration_eom_CSTATE_f[3] = 1.0;
  }

  GRM_HIL_DW.integration_eom_IWORK_l = 1;

  /* End of InitializeConditions for Integrator: '<S162>/integration_eom' */

  /* InitializeConditions for Integrator: '<S129>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_P.Rudder_siB_0;

  /* InitializeConditions for Integrator: '<S130>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE_g = GRM_HIL_P.Rudder1_siB_0;

  /* InitializeConditions for Integrator: '<S131>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE_a = GRM_HIL_P.Rudder2_siB_0;

  /* InitializeConditions for Integrator: '<S132>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE_i = GRM_HIL_P.Rudder3_siB_0;

  /* InitializeConditions for Memory: '<S19>/Memory' */
  GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_P.Memory_InitialCondition;

  /* InitializeConditions for TransferFcn: '<S25>/Transfer Fcn2' */
  GRM_HIL_X.TransferFcn2_CSTATE_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S25>/Transfer Fcn1' */
  GRM_HIL_X.TransferFcn1_CSTATE_e = 0.0;

  /* InitializeConditions for UnitDelay: '<S243>/Output' */
  GRM_HIL_DW.Output_DSTATE = GRM_HIL_P.Output_InitialCondition;

  /* InitializeConditions for Memory: '<S39>/Memory' */
  GRM_HIL_DW.Memory_PreviousInput_d = GRM_HIL_P.Memory_InitialCondition_i;

  /* InitializeConditions for Integrator: '<S129>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE = GRM_HIL_P.Rudder_d_siB_0;

  /* InitializeConditions for Integrator: '<S130>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Rudder1_d_siB_0;

  /* InitializeConditions for Integrator: '<S131>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;

  /* InitializeConditions for Integrator: '<S132>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Rudder3_d_siB_0;

  /* InitializeConditions for Derivative: '<S163>/Derivative1' */
  GRM_HIL_DW.TimeStampA = (rtInf);
  GRM_HIL_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S163>/Derivative' */
  GRM_HIL_DW.TimeStampA_b = (rtInf);
  GRM_HIL_DW.TimeStampB_j = (rtInf);

  /* SystemInitialize for Enabled SubSystem: '<S38>/Construct_Bus' */
  /* SystemInitialize for Outport: '<S40>/Gimbal_Status' */
=======
  GRM_HIL_B.run = GRM_HIL_P.Constant_Value_g;

  /* Start for Constant: '<S7>/Constant7' */
  GRM_HIL_B.enable_gimbal_ctrl_flg = GRM_HIL_P.Constant7_Value_e;

  /* Start for Constant: '<S7>/Constant8' */
  GRM_HIL_B.stop_gimbal_flg = GRM_HIL_P.Constant8_Value_l;

  /* Start for Constant: '<S37>/Constant' */
  GRM_HIL_B.Constant = GRM_HIL_P.Constant_Value_b;

  /* Start for Enabled SubSystem: '<S37>/Send_to_FTHWICC' */
  GRM_HIL_DW.Send_to_FTHWICC_MODE = false;

  /* Start for S-Function (sldrtpo): '<S40>/Send_to_FTHWICC' */

  /* S-Function Block: <S40>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* End of Start for SubSystem: '<S37>/Send_to_FTHWICC' */
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_ff = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S74>/Integrator' incorporates:
   *  Integrator: '<S72>/Integrator'
   */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator_CSTATE = 0.0;
    GRM_HIL_X.Integrator_CSTATE_k = 0.0;
  }

  GRM_HIL_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S74>/Integrator' */

  /* InitializeConditions for Integrator: '<S72>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_i = 1;

  /* InitializeConditions for Integrator: '<S72>/Integrator1' incorporates:
   *  Integrator: '<S72>/Integrator2'
   */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator1_CSTATE = 0.0;
    GRM_HIL_X.Integrator2_CSTATE = 0.0;
  }

  GRM_HIL_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S72>/Integrator1' */

  /* InitializeConditions for Integrator: '<S72>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK = 1;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn' */
  GRM_HIL_X.TransferFcn_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn1' */
  GRM_HIL_X.TransferFcn1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn2' */
  GRM_HIL_X.TransferFcn2_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn3' */
  GRM_HIL_X.TransferFcn3_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dy2ay' */
  GRM_HIL_X.dy2ay_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dp2az' */
  GRM_HIL_X.dp2az_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn' */
  GRM_HIL_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn1' */
  GRM_HIL_X.TransferFcn1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn2' */
  GRM_HIL_X.TransferFcn2_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn3' */
  GRM_HIL_X.TransferFcn3_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dy2ay' */
  GRM_HIL_X.dy2ay_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dp2az' */
  GRM_HIL_X.dp2az_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dr2roll' */
  GRM_HIL_X.dr2roll_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dp2pitch' */
  GRM_HIL_X.dp2pitch_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dy2yaw' */
  GRM_HIL_X.dy2yaw_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dp2pitch' */
  GRM_HIL_X.dp2pitch_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S54>/dy2yaw' */
  GRM_HIL_X.dy2yaw_CSTATE[1] = 0.0;

  /* InitializeConditions for Memory: '<S18>/Memory' */
  GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_P.Memory_InitialCondition;

  /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn' */
  GRM_HIL_X.TransferFcn_CSTATE_j = 0.0;

  /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn2' */
  GRM_HIL_X.TransferFcn2_CSTATE_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn1' */
  GRM_HIL_X.TransferFcn1_CSTATE_e = 0.0;

  /* InitializeConditions for Integrator: '<S77>/Integrator' incorporates:
   *  Integrator: '<S77>/Integrator1'
   */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator_CSTATE_j = 0.0;
    GRM_HIL_X.Integrator1_CSTATE_p = 0.0;
  }

  GRM_HIL_DW.Integrator_IWORK_ic = 1;

  /* End of InitializeConditions for Integrator: '<S77>/Integrator' */

  /* InitializeConditions for Integrator: '<S77>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_g = 1;

  /* InitializeConditions for Integrator: '<S77>/Integrator2' incorporates:
   *  Integrator: '<S76>/Integrator1'
   */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator2_CSTATE_a = 0.0;
    GRM_HIL_X.Integrator1_CSTATE_e = 0.0;
  }

  GRM_HIL_DW.Integrator2_IWORK_m = 1;

  /* End of InitializeConditions for Integrator: '<S77>/Integrator2' */

  /* InitializeConditions for UnitDelay: '<S80>/Output' */
  GRM_HIL_DW.Output_DSTATE = GRM_HIL_P.Output_InitialCondition;

  /* InitializeConditions for Memory: '<S38>/Memory' */
  GRM_HIL_DW.Memory_PreviousInput_g = GRM_HIL_P.Memory_InitialCondition_o;

  /* InitializeConditions for Integrator: '<S76>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_n = 1;

  /* InitializeConditions for Integrator: '<S76>/Integrator2' incorporates:
   *  Integrator: '<S75>/Integrator'
   */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator2_CSTATE_d = 0.0;
    GRM_HIL_X.Integrator_CSTATE_d = 0.0;
  }

  GRM_HIL_DW.Integrator2_IWORK_e = 1;

  /* End of InitializeConditions for Integrator: '<S76>/Integrator2' */

  /* InitializeConditions for Integrator: '<S75>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_m = 1;

  /* InitializeConditions for Integrator: '<S75>/Integrator1' incorporates:
   *  Integrator: '<S75>/Integrator2'
   */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator1_CSTATE_eg = 0.0;
    GRM_HIL_X.Integrator2_CSTATE_e = 0.0;
  }

  GRM_HIL_DW.Integrator1_IWORK_m = 1;

  /* End of InitializeConditions for Integrator: '<S75>/Integrator1' */

  /* InitializeConditions for Integrator: '<S75>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_c = 1;

  /* InitializeConditions for Integrator: '<S76>/Integrator' */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.Integrator_CSTATE_jz = 0.0;
  }

  GRM_HIL_DW.Integrator_IWORK_l = 1;

  /* End of InitializeConditions for Integrator: '<S76>/Integrator' */

  /* SystemInitialize for Enabled SubSystem: '<S54>/Propulsion' */
  /* InitializeConditions for Memory: '<S60>/lock' */
  GRM_HIL_DW.lock_PreviousInput = GRM_HIL_P.lock_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S60>/hold_time' */
  /* SystemInitialize for Outport: '<S68>/exec_time_hold_s' */
  GRM_HIL_B.Clock = GRM_HIL_P.exec_time_hold_s_Y0;

  /* End of SystemInitialize for SubSystem: '<S60>/hold_time' */

  /* SystemInitialize for Enabled SubSystem: '<S60>/Subsystem' */
  /* SystemInitialize for Outport: '<S67>/thrust' */
  GRM_HIL_B.OutportBufferForthrust = GRM_HIL_P.thrust_Y0;

  /* SystemInitialize for Outport: '<S67>/state_percentage_change' */
  GRM_HIL_B.Add1 = GRM_HIL_P.state_percentage_change_Y0;

  /* End of SystemInitialize for SubSystem: '<S60>/Subsystem' */

  /* SystemInitialize for Outport: '<S60>/motor_state_perc_dot' */
  GRM_HIL_B.OutportBufferFormotor_state_perc_dot =
    GRM_HIL_P.motor_state_perc_dot_Y0;

  /* End of SystemInitialize for SubSystem: '<S54>/Propulsion' */

  /* SystemInitialize for Enabled SubSystem: '<S54>/Gravity' */
  /* SystemInitialize for Outport: '<S58>/acc_x_grav_mDs' */
  GRM_HIL_B.acc_x = GRM_HIL_P.acc_x_grav_mDs_Y0;

  /* SystemInitialize for Outport: '<S58>/acc_y_grav_mDs' */
  GRM_HIL_B.acc_y = GRM_HIL_P.acc_y_grav_mDs_Y0;

  /* SystemInitialize for Outport: '<S58>/acc_z_grav_mDs' */
  GRM_HIL_B.acc_z = GRM_HIL_P.acc_z_grav_mDs_Y0;

  /* End of SystemInitialize for SubSystem: '<S54>/Gravity' */

  /* SystemInitialize for Enabled SubSystem: '<S54>/Drag' */
  /* SystemInitialize for Outport: '<S57>/acc_x_drag_mDs2' */
  GRM_HIL_B.OutportBufferForacc_x_drag_mDs2 = GRM_HIL_P.acc_x_drag_mDs2_Y0;

  /* SystemInitialize for Outport: '<S57>/acc_y_drag_mDs2' */
  GRM_HIL_B.OutportBufferForacc_y_drag_mDs2 = GRM_HIL_P.acc_y_drag_mDs2_Y0;

  /* SystemInitialize for Outport: '<S57>/acc_z_drag_mDs2' */
  GRM_HIL_B.OutportBufferForacc_z_drag_mDs2 = GRM_HIL_P.acc_z_drag_mDs2_Y0;

  /* End of SystemInitialize for SubSystem: '<S54>/Drag' */

  /* SystemInitialize for Enabled SubSystem: '<S37>/Construct_Bus' */
  /* SystemInitialize for Outport: '<S39>/Gimbal_Status' */
>>>>>>> origin/master
  GRM_HIL_B.Gimbal_operational_flg =
    GRM_HIL_P.Gimbal_Status_Y0.Gimbal_operational_flg;
  GRM_HIL_B.Gimbal_Ramp_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_Ramp_flg;
  GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_Limit_flg;
  GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_StopSim_flg;

<<<<<<< HEAD
  /* SystemInitialize for Outport: '<S40>/Gimbal_Pos' */
  GRM_HIL_B.ATT_Phi_rad_p = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Phi_rad;
  GRM_HIL_B.ATT_Theta_rad_e =
    GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Theta_rad;
  GRM_HIL_B.ATT_Psi_rad_e = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Psi_rad;
  GRM_HIL_B.q0_d = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_0;
  GRM_HIL_B.q1_o = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_1;
  GRM_HIL_B.q2_i = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_2;
  GRM_HIL_B.q3_o = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_3;

  /* SystemInitialize for Outport: '<S40>/Gimbal_Pos_Encoder' */
=======
  /* SystemInitialize for Outport: '<S39>/Gimbal_Pos' */
  GRM_HIL_B.ATT_Phi_rad_lz = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Phi_rad;
  GRM_HIL_B.ATT_Theta_rad_j =
    GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Theta_rad;
  GRM_HIL_B.ATT_Psi_rad_o = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Euler_Bus.ATT_Psi_rad;
  GRM_HIL_B.q0 = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_0;
  GRM_HIL_B.q1 = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_1;
  GRM_HIL_B.q2 = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_2;
  GRM_HIL_B.q3 = GRM_HIL_P.Gimbal_Pos_Y0.ATT_Quaternions_Bus.ATT_q_3;

  /* SystemInitialize for Outport: '<S39>/Gimbal_Pos_Encoder' */
>>>>>>> origin/master
  GRM_HIL_B.Gimbal_yaw_sns =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_yaw_sns;
  GRM_HIL_B.Gimbal_pitch_sns =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_pitch_sns;
  GRM_HIL_B.Gimbal_roll_sns =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_roll_sns;
<<<<<<< HEAD
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

  /* End of SystemInitialize for SubSystem: '<S38>/Construct_Bus' */

  /* SystemInitialize for Enabled SubSystem: '<S18>/Com_to_FCC_emul' */
  /* SystemInitialize for Outport: '<S20>/States_hold' */
=======
  GRM_HIL_B.Data_plus_j =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Data_plus;
  GRM_HIL_B.Data_minus_o =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Data_minus;
  GRM_HIL_B.Clock_plus_f =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Clock_plus;
  GRM_HIL_B.Clock_minus_c =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Yaw_Encoder.Clock_minus;
  GRM_HIL_B.Data_plus_j1 =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Data_plus;
  GRM_HIL_B.Data_minus_oy =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Data_minus;
  GRM_HIL_B.Clock_plus_fx =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Clock_plus;
  GRM_HIL_B.Clock_minus_cm =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Pitch_Encoder.Clock_minus;
  GRM_HIL_B.Data_plus_j13 =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Data_plus;
  GRM_HIL_B.Data_minus_oyn =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Data_minus;
  GRM_HIL_B.Clock_plus_fx0 =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Clock_plus;
  GRM_HIL_B.Clock_minus_cmq =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Pos_Roll_Encoder.Clock_minus;

  /* End of SystemInitialize for SubSystem: '<S37>/Construct_Bus' */

  /* SystemInitialize for Enabled SubSystem: '<S17>/Com_to_FCC_emul' */
  /* SystemInitialize for Outport: '<S19>/States_hold' */
>>>>>>> origin/master
  GRM_HIL_B.ACC_y_B_mDs2_o =
    GRM_HIL_P.States_hold_Y0.Rigid_Body_States.Translation_States_Dot.ACC_y_B_mDs2;
  GRM_HIL_B.ACC_z_B_mDs2_e =
    GRM_HIL_P.States_hold_Y0.Rigid_Body_States.Translation_States_Dot.ACC_z_B_mDs2;
  GRM_HIL_B.w_x_K_IB_B_radDs_f =
    GRM_HIL_P.States_hold_Y0.Rigid_Body_States.Rotation_States.w_x_K_IB_B_radDs;
  GRM_HIL_B.w_y_K_IB_B_radDs_e =
    GRM_HIL_P.States_hold_Y0.Rigid_Body_States.Rotation_States.w_y_K_IB_B_radDs;
  GRM_HIL_B.w_z_K_IB_B_radDs_n =
    GRM_HIL_P.States_hold_Y0.Rigid_Body_States.Rotation_States.w_z_K_IB_B_radDs;
  GRM_HIL_B.ATT_Phi_rad_f =
    GRM_HIL_P.States_hold_Y0.Rigid_Body_States.Attitude_States.ATT_Euler.ATT_Phi_rad;

<<<<<<< HEAD
  /* SystemInitialize for Outport: '<S20>/External_Inputs_hold' */
=======
  /* SystemInitialize for Outport: '<S19>/External_Inputs_hold' */
>>>>>>> origin/master
  GRM_HIL_B.CMD_phi_rad =
    GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_phi_rad;
  GRM_HIL_B.CMD_acc_z_mDs2 =
    GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_acc_z_mDs2;
  GRM_HIL_B.CMD_acc_y_mDs2 =
    GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_acc_y_mDs2;

<<<<<<< HEAD
  /* End of SystemInitialize for SubSystem: '<S18>/Com_to_FCC_emul' */
=======
  /* End of SystemInitialize for SubSystem: '<S17>/Com_to_FCC_emul' */

  /* SystemInitialize for S-Function (fcncallgen): '<S17>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S17>/FB_Com_freq_emul'
   */
  /* SystemInitialize for Outport: '<S20>/hold' */
  GRM_HIL_B.Fin_1_Cmd_rad_l =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Control_Surface_Cmd.Fin_1_Cmd_rad;
  GRM_HIL_B.Fin_2_Cmd_rad_e =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Control_Surface_Cmd.Fin_2_Cmd_rad;
  GRM_HIL_B.Fin_3_Cmd_rad_o =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Control_Surface_Cmd.Fin_3_Cmd_rad;
  GRM_HIL_B.Fin_4_Cmd_rad_c =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Control_Surface_Cmd.Fin_4_Cmd_rad;
  GRM_HIL_B.pulse_width_ms_p2 =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Servo_Cmd.Servo_1_Cmd_PWM.pulse_width_ms;
  GRM_HIL_B.pulse_width_ms_p2d =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Servo_Cmd.Servo_2_Cmd_PWM.pulse_width_ms;
  GRM_HIL_B.pulse_width_ms_p2de =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Servo_Cmd.Servo_3_Cmd_PWM.pulse_width_ms;
  GRM_HIL_B.pulse_width_ms_p2dee =
    GRM_HIL_P.hold_Y0.Airframe_Cmd.Servo_Cmd.Servo_4_Cmd_PWM.pulse_width_ms;

  /* End of SystemInitialize for S-Function (fcncallgen): '<S17>/Function-Call Generator1' */
>>>>>>> origin/master

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    rtmSetFirstInitCond(GRM_HIL_M, 0);
  }
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
<<<<<<< HEAD
  /* Terminate for Enabled SubSystem: '<S38>/Send_to_FTHWICC' */

  /* Terminate for S-Function (sldrtpo): '<S41>/Send_to_FTHWICC' */

  /* S-Function Block: <S41>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S38>/Send_to_FTHWICC' */
=======
  /* Terminate for Enabled SubSystem: '<S37>/Send_to_FTHWICC' */

  /* Terminate for S-Function (sldrtpo): '<S40>/Send_to_FTHWICC' */

  /* S-Function Block: <S40>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S37>/Send_to_FTHWICC' */
>>>>>>> origin/master
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

<<<<<<< HEAD
  /* non-finite (run-time) assignments */
  GRM_HIL_P.Saturation1_UpperSat = rtInf;
  GRM_HIL_P.Saturation_UpperSat_f = rtInf;
  GRM_HIL_P.Saturation_UpperSat_d = rtInf;
  GRM_HIL_P.Saturation_UpperSat_m = rtInf;

=======
>>>>>>> origin/master
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
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    GRM_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GRM_HIL_M->Timing.sampleTimes = (&GRM_HIL_M->Timing.sampleTimesArray[0]);
    GRM_HIL_M->Timing.offsetTimes = (&GRM_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GRM_HIL_M->Timing.sampleTimes[0] = (0.0);
    GRM_HIL_M->Timing.sampleTimes[1] = (0.001);
    GRM_HIL_M->Timing.sampleTimes[2] = (0.002);
    GRM_HIL_M->Timing.sampleTimes[3] = (0.01);
    GRM_HIL_M->Timing.sampleTimes[4] = (0.02);

    /* task offsets */
    GRM_HIL_M->Timing.offsetTimes[0] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[1] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[2] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[3] = (0.0);
    GRM_HIL_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(GRM_HIL_M, &GRM_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GRM_HIL_M->Timing.sampleHitArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlSampleHits[i] = 1;
    }

    GRM_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GRM_HIL_M, 60.0);
  GRM_HIL_M->Timing.stepSize0 = 0.001;
  GRM_HIL_M->Timing.stepSize1 = 0.001;
  GRM_HIL_M->Timing.stepSize2 = 0.002;
  GRM_HIL_M->Timing.stepSize3 = 0.01;
  GRM_HIL_M->Timing.stepSize4 = 0.02;
  rtmSetFirstInitCond(GRM_HIL_M, 1);

  /* External mode info */
<<<<<<< HEAD
  GRM_HIL_M->Sizes.checksums[0] = (4165539840U);
  GRM_HIL_M->Sizes.checksums[1] = (1900587666U);
  GRM_HIL_M->Sizes.checksums[2] = (3386896294U);
  GRM_HIL_M->Sizes.checksums[3] = (2135803952U);
=======
  GRM_HIL_M->Sizes.checksums[0] = (3149021053U);
  GRM_HIL_M->Sizes.checksums[1] = (2131411835U);
  GRM_HIL_M->Sizes.checksums[2] = (2724286297U);
  GRM_HIL_M->Sizes.checksums[3] = (1645203036U);
>>>>>>> origin/master

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
<<<<<<< HEAD
    static const sysRanDType *systemRan[72];
=======
    static const sysRanDType *systemRan[33];
>>>>>>> origin/master
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
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = (sysRanDType *)&GRM_HIL_DW.Com_to_FCC_emul_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&GRM_HIL_DW.FB_Com_freq_emul_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&GRM_HIL_DW.Pass_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&GRM_HIL_DW.Saturate_SubsysRanBC;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)&GRM_HIL_DW.Construct_Bus_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC;
<<<<<<< HEAD
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
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
    systemRan[70] = (sysRanDType *)
      &GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC;
    systemRan[71] = &rtAlwaysEnabled;
=======
    systemRan[21] = (sysRanDType *)&GRM_HIL_DW.Drag_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&GRM_HIL_DW.Gravity_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&GRM_HIL_DW.Gravity_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)&GRM_HIL_DW.Subsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&GRM_HIL_DW.hold_time_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&GRM_HIL_DW.Propulsion_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = (sysRanDType *)
      &GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC;
    systemRan[32] = &rtAlwaysEnabled;
>>>>>>> origin/master
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
<<<<<<< HEAD
    dtInfo.numDataTypes = 118;
=======
    dtInfo.numDataTypes = 137;
>>>>>>> origin/master
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
<<<<<<< HEAD
  GRM_HIL_M->Sizes.numContStates = (39);/* Number of continuous states */
=======
  GRM_HIL_M->Sizes.numContStates = (33);/* Number of continuous states */
>>>>>>> origin/master
  GRM_HIL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (5); /* Number of sample times */
<<<<<<< HEAD
  GRM_HIL_M->Sizes.numBlocks = (2103); /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (205); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (117826);/* Sum of parameter "widths" */
=======
  GRM_HIL_M->Sizes.numBlocks = (528);  /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (174); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (165);/* Sum of parameter "widths" */
>>>>>>> origin/master
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

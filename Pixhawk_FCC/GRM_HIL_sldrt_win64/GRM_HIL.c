/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.88
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Jan  3 00:07:39 2020
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

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 3U, 8, SLDRTBoardOptions0 },
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

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

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
  if ((GRM_HIL_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.05s, 0.0s] */
    GRM_HIL_M->Timing.TaskCounters.TID[2] = 0;
  }

  GRM_HIL_M->Timing.sampleHits[2] = (GRM_HIL_M->Timing.TaskCounters.TID[2] == 0);
  (GRM_HIL_M->Timing.TaskCounters.TID[3])++;
  if ((GRM_HIL_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [0.1s, 0.0s] */
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
  int_T nXc = 71;
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
 * Disable for enable system:
 *    '<S52>/Enabled pass'
 *    '<S61>/Enabled pass'
 *    '<S71>/Enabled pass'
 */
void GRM_HIL_Enabledpass_Disable(DW_Enabledpass_GRM_HIL_T *localDW)
{
  localDW->Enabledpass_MODE = false;
}

/*
 * Start for enable system:
 *    '<S52>/Enabled pass'
 *    '<S61>/Enabled pass'
 *    '<S71>/Enabled pass'
 */
void GRM_HIL_Enabledpass_Start(DW_Enabledpass_GRM_HIL_T *localDW)
{
  localDW->Enabledpass_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S52>/Enabled pass'
 *    '<S61>/Enabled pass'
 *    '<S71>/Enabled pass'
 */
void GRM_HIL_Enabledpass(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_upper_limit, real_T rtu_lower_limit, real_T
  *rty_upper_limit_pass, real_T *rty_lower_limit_pass, DW_Enabledpass_GRM_HIL_T *
  localDW)
{
  /* Outputs for Enabled SubSystem: '<S52>/Enabled pass' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    if (rtu_Enable) {
      localDW->Enabledpass_MODE = true;
    } else {
      if (localDW->Enabledpass_MODE) {
        GRM_HIL_Enabledpass_Disable(localDW);
      }
    }
  }

  if (localDW->Enabledpass_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Inport: '<S57>/upper_limit' */
      *rty_upper_limit_pass = rtu_upper_limit;

      /* Inport: '<S57>/lower_limit' */
      *rty_lower_limit_pass = rtu_lower_limit;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(localDW->Enabledpass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S52>/Enabled pass' */
}

/*
 * Output and update for enable system:
 *    '<S53>/Saturation'
 *    '<S62>/Saturation'
 *    '<S72>/Saturation'
 */
void GRM_HIL_Saturation(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_upper_limit, real_T rtu_lower_limit, real_T rtu_in,
  real_T *rty_out, DW_Saturation_GRM_HIL_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S53>/Saturation' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  if (rtu_Enable) {
    /* Switch: '<S60>/Switch2' incorporates:
     *  RelationalOperator: '<S60>/LowerRelop1'
     *  RelationalOperator: '<S60>/UpperRelop'
     *  Switch: '<S60>/Switch'
     */
    if (rtu_in > rtu_upper_limit) {
      /* SignalConversion generated from: '<S58>/out' */
      *rty_out = rtu_upper_limit;
    } else if (rtu_in < rtu_lower_limit) {
      /* Switch: '<S60>/Switch' incorporates:
       *  SignalConversion generated from: '<S58>/out'
       */
      *rty_out = rtu_lower_limit;
    } else {
      /* SignalConversion generated from: '<S58>/out' incorporates:
       *  Switch: '<S60>/Switch'
       */
      *rty_out = rtu_in;
    }

    /* End of Switch: '<S60>/Switch2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(localDW->Saturation_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S53>/Saturation' */
}

/*
 * Output and update for enable system:
 *    '<S53>/pass'
 *    '<S62>/pass'
 *    '<S72>/pass'
 */
void GRM_HIL_pass(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T rtu_Enable,
                  real_T rtu_in, real_T *rty_out, DW_pass_GRM_HIL_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S53>/pass' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (rtu_Enable) {
    /* Inport: '<S59>/in' */
    *rty_out = rtu_in;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(localDW->pass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S53>/pass' */
}

/*
 * System initialize for action system:
 *    '<S173>/If Action Subsystem1'
 *    '<S174>/If Action Subsystem1'
 *    '<S175>/If Action Subsystem1'
 */
void GRM_HIL_IfActionSubsystem1_Init(B_IfActionSubsystem1_GRM_HIL_T *localB,
  P_IfActionSubsystem1_GRM_HIL_T *localP)
{
  /* SystemInitialize for Outport: '<S177>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S173>/If Action Subsystem1'
 *    '<S174>/If Action Subsystem1'
 *    '<S175>/If Action Subsystem1'
 */
void GRM_HIL_IfActionSubsystem1(real_T rtu_In1, B_IfActionSubsystem1_GRM_HIL_T
  *localB)
{
  if (1) {
    /* Inport: '<S177>/In1' */
    localB->In1 = rtu_In1;
  }
}

/*
 * System initialize for action system:
 *    '<S173>/If Action Subsystem'
 *    '<S174>/If Action Subsystem'
 *    '<S175>/If Action Subsystem'
 */
void GRM_HIL_IfActionSubsystem_Init(B_IfActionSubsystem_GRM_HIL_T *localB,
  P_IfActionSubsystem_GRM_HIL_T *localP)
{
  /* SystemInitialize for Outport: '<S176>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S173>/If Action Subsystem'
 *    '<S174>/If Action Subsystem'
 *    '<S175>/If Action Subsystem'
 */
void GRM_HIL_IfActionSubsystem(real_T rtu_In1, B_IfActionSubsystem_GRM_HIL_T
  *localB)
{
  /* Inport: '<S176>/In1' */
  localB->In1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S51>/If Action pass_yaw'
 *    '<S51>/If Action pass_pitch'
 *    '<S51>/If Action pass_roll'
 */
void GRM_HIL_IfActionpass_yaw(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S187>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S270>/Limiting_Acceleration'
 *    '<S271>/Limiting_Acceleration'
 *    '<S272>/Limiting_Acceleration'
 *    '<S273>/Limiting_Acceleration'
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
 *    '<S270>/Limiting_Rate'
 *    '<S271>/Limiting_Rate'
 *    '<S272>/Limiting_Rate'
 *    '<S273>/Limiting_Rate'
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

/* Function for MATLAB Function: '<S24>/ExtractMessage' */
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
  real_T rtb_Gain2_dm;
  boolean_T rtb_Compare_l;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Compare_e;
  real_T rtb_Sum_a;
  real_T rtb_Sum_m;
  real_T rtb_Sum_g;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator1_c;
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
  real_T rtb_Abs_n;
  real_T rtb_Gain1_c;
  real_T rtb_q_conj[4];
  real_T rtb_ZeroOrderHold[3];
  real_T rtb_Product4_n[4];
  real_T rtb_Switch1;
  uint32_T rtb_k_Mach;
  uint32_T rtb_k_alB;
  real_T rtb_Subtract_ju;
  uint32_T rtb_k_beB;
  real_T rtb_jxi;
  real_T rtb_Cx;
  real_T rtb_Product_l;
  real_T rtb_Product1;
  real_T rtb_Product3_hu;
  real_T rtb_Gain_pu;
  real_T rtb_Product4_e;
  real_T rtb_Gain_nv;
  real_T rtb_Product5;
  real_T rtb_jxk;
  real_T rtb_Cy;
  real_T rtb_Product_i[3];
  real_T rtb_d_qGE[4];
  real_T rtb_VectorConcatenate_hm[3];
  int32_T idx_0;
  real_T rtb_Add1;
  real_T rtb_Add3;
  real_T rtb_ProportionalGain;
  real_T rtb_DerivativeGain;
  real_T rtb_ProportionalGain_l;
  real_T rtb_DerivativeGain_e;
  real_T rtb_ProportionalGain_a;
  real_T rtb_DerivativeGain_j0;
  real_T rtb_VectorConcatenate3[9];
  uint16_T rtb_FixPtSum1;
  real_T rtb_d_qBI[4];
  real_T rtb_JBBB[9];
  int8_T rtAction;
  real_T rtb_pBEE[3];
  real_T rtb_vBEB_a[3];
  real_T rtb_Add1_p;
  real_T rtb_Sqrt_k;
  real_T rtb_Product2_m;
  real_T rtb_TBG[9];
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
  uint8_T rtb_message[64];
  real_T rtb_MultiportSwitch[9];
  real_T rtb_MultiportSwitch1[9];
  real_T rtb_MultiportSwitch2[9];
  real_T rtb_MatrixMultiply_tmp[9];
  real_T rtb_vBEB_a_tmp[9];
  int32_T i;
  real_T tmp[16];
  int32_T start_size[2];
  int32_T tmp_size[2];
  int32_T start_size_0[2];
  real_T rtb_Product_idx_2;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_0;
  real_T rtb_Product_idx_3;
  real_T u0;
  real_T rtb_q_conj_e;
  real_T rtb_TBG_tmp;
  real_T rtb_TBG_tmp_0;
  real_T rtb_Gain2_dm_tmp;
  real_T rtb_TBG_tmp_1;
  real_T rtb_TBG_tmp_2;
  real_T rtb_TBG_tmp_3;
  real_T rtb_TBG_tmp_4;
  real_T rtb_TBG_tmp_5;
  real_T rtb_TBG_tmp_6;
  real_T rtb_TBG_tmp_7;
  int32_T packet_size_idx_1_tmp;
  real_T q0_tmp;
  real_T rtb_Cy_tmp;
  real_T rtb_Switch1_tmp;
  real_T frac_tmp;
  real_T frac_tmp_0;
  real_T rtb_Cx_tmp;
  real_T rtb_TBG_tmp_8;
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
  srClearBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Enabledpass.Enabledpass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Saturation.Saturation_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.pass.pass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_d);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Control_Limits_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.pass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionPass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionlimit_yaw_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionlimit_pitch_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.IfActionlimit_roll_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Voltage_Limitations_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S21>/Receive_ExternalMode' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S21>/One' */
      if (GRM_HIL_P.One_Value_g > 0.0) {
        if (!GRM_HIL_DW.Receive_ExternalMode_MODE) {
          /* Enable for Sin: '<S23>/Sine Wave' */
          GRM_HIL_DW.systemEnable_c = 1;
          GRM_HIL_DW.Receive_ExternalMode_MODE = true;
        }
      } else {
        GRM_HIL_DW.Receive_ExternalMode_MODE = false;
      }

      /* End of Constant: '<S21>/One' */
    }

    if (GRM_HIL_DW.Receive_ExternalMode_MODE) {
      /* S-Function (sldrtpi): '<S23>/Packet Input' */
      /* S-Function Block: <S23>/Packet Input */
      {
        uint8_T indata[78U];
        int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 78U,
          &GRM_HIL_P.PacketInput_PacketID, (double*) indata, NULL);
        rtb_LogicalOperator2 = (status>>1) & 0x1;/* Data Error port */
        rtb_LogicalOperator1_c = status & 0x1;/* Data Ready port */
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

      /* ToAsyncQueueBlock generated from: '<S23>/Packet Input' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.PacketInput_o1[0];
          int32_T size = 78*sizeof(uint8_T);
          sendToAsyncQueueTgtAppSvc(3685774264U, time, pData, size);
        }
      }

      /* Logic: '<S23>/AND' incorporates:
       *  Logic: '<S23>/NOT'
       */
      GRM_HIL_B.AND_h = (rtb_LogicalOperator1_c && (!rtb_LogicalOperator2));

      /* Sin: '<S23>/Sine Wave' */
      if (GRM_HIL_DW.systemEnable_c != 0) {
        rtb_Product_idx_0 = GRM_HIL_P.SineWave_Freq * GRM_HIL_M->Timing.t[1];
        GRM_HIL_DW.lastSin_h = sin(rtb_Product_idx_0);
        GRM_HIL_DW.lastCos_c = cos(rtb_Product_idx_0);
        GRM_HIL_DW.systemEnable_c = 0;
      }

      GRM_HIL_B.SineWave_g = ((GRM_HIL_DW.lastSin_h * GRM_HIL_P.SineWave_PCos +
        GRM_HIL_DW.lastCos_c * GRM_HIL_P.SineWave_PSin) *
        GRM_HIL_P.SineWave_HCos + (GRM_HIL_DW.lastCos_c *
        GRM_HIL_P.SineWave_PCos - GRM_HIL_DW.lastSin_h * GRM_HIL_P.SineWave_PSin)
        * GRM_HIL_P.SineWave_Hsin) * GRM_HIL_P.SineWave_Amp +
        GRM_HIL_P.SineWave_Bias;

      /* End of Sin: '<S23>/Sine Wave' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Receive_ExternalMode_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S21>/Receive_ExternalMode' */

    /* Outputs for Enabled SubSystem: '<S21>/input_hold' incorporates:
     *  EnablePort: '<S24>/Enable'
     */
    if (GRM_HIL_B.AND_h) {
      /* MATLAB Function: '<S24>/ExtractMessage' */
      packet_size_idx_1_tmp = 64;
      memset(&packet_data[0], 0, sizeof(uint8_T) << 6U);
      packetfound = false;
      for (i = 0; i < 78; i++) {
        x[i] = (GRM_HIL_B.PacketInput_o1[i] == 5);
      }

      idx = 0;
      idx_0 = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_0 < 78)) {
        if (x[idx_0]) {
          idx++;
          ii_data[idx - 1] = (int8_T)(idx_0 + 1);
          if (idx >= 78) {
            exitg1 = true;
          } else {
            idx_0++;
          }
        } else {
          idx_0++;
        }
      }

      if (1 > idx) {
        idx = 0;
      }

      start_size[0] = 1;
      start_size[1] = idx;
      idx_0 = idx - 1;
      for (i = 0; i <= idx_0; i++) {
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
      idx_0 = start_size[0] * start_size[1];
      for (i = 0; i < idx_0; i++) {
        x[i] = (GRM_HIL_B.PacketInput_o1[(int32_T)((start_data[i] + 2.0) - 1.0)
                - 1] != 5);
      }

      GRM_HIL_nullAssignment(start_data, start_size, x, tmp_size);
      if (start_size[1] != 0) {
        idx_0 = 5;
        idx = 0;
        exitg1 = false;
        while ((!exitg1) && (idx <= start_size[1] - 2)) {
          idx_0 = 6;
          p = false;
          rtb_q_conj_e = start_data[idx + 1];
          if (rtb_q_conj_e - start_data[idx] == 66.0) {
            p = true;
          }

          if (p) {
            if (start_data[idx] + 2.0 > rtb_q_conj_e - 1.0) {
              idx_0 = 0;
              idx = 0;
            } else {
              idx_0 = (int32_T)(start_data[idx] + 2.0) - 1;
              idx = (int32_T)(start_data[idx + 1] - 1.0);
            }

            packet_size_idx_1_tmp = idx - idx_0;
            for (i = 0; i < packet_size_idx_1_tmp; i++) {
              packet_data[i] = GRM_HIL_B.PacketInput_o1[idx_0 + i];
            }

            packetfound = true;
            idx_0 = 9;
            exitg1 = true;
          } else {
            idx++;
          }
        }
      } else {
        idx_0 = 777;
      }

      GRM_HIL_DW.SFunction_DIMS2[0] = 1;
      GRM_HIL_DW.SFunction_DIMS2[1] = packet_size_idx_1_tmp;
      if (0 <= packet_size_idx_1_tmp - 1) {
        memcpy(&rtb_message[0], &packet_data[0], packet_size_idx_1_tmp * sizeof
               (uint8_T));
      }

      GRM_HIL_B.stage = idx_0;

      /* MATLAB Function: '<S24>/ByteUnpack' */
      x_0[0] = rtb_message[0];
      x_0[1] = rtb_message[1];
      memcpy((void *)&GRM_HIL_B.PixHeartbeat, (void *)&x_0[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
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
      memcpy((void *)&quaternion1, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[52];
      b_x[1] = rtb_message[53];
      b_x[2] = rtb_message[54];
      b_x[3] = rtb_message[55];
      memcpy((void *)&quaternion1, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[56];
      b_x[1] = rtb_message[57];
      b_x[2] = rtb_message[58];
      b_x[3] = rtb_message[59];
      memcpy((void *)&quaternion1, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));
      b_x[0] = rtb_message[60];
      b_x[1] = rtb_message[61];
      b_x[2] = rtb_message[62];
      b_x[3] = rtb_message[63];
      memcpy((void *)&quaternion1, (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(real32_T)));

      /* ToAsyncQueueBlock generated from: '<S24>/ByteUnpack' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.PixHeartbeat;
          int32_T size = 1*sizeof(uint16_T);
          sendToAsyncQueueTgtAppSvc(2759144746U, time, pData, size);
        }
      }

      /* ToAsyncQueueBlock generated from: '<S24>/ExtractMessage' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.stage;
          int32_T size = 1*sizeof(real_T);
          sendToAsyncQueueTgtAppSvc(2918050724U, time, pData, size);
        }
      }

      /* Outputs for Enabled SubSystem: '<S24>/hold' incorporates:
       *  EnablePort: '<S27>/Enable'
       */
      /* MATLAB Function: '<S24>/ExtractMessage' incorporates:
       *  Inport: '<S27>/SensorACC_update'
       *  Inport: '<S27>/SensorROT_update'
       *  Inport: '<S27>/ServoCMD_update'
       *  MATLAB Function: '<S24>/ByteUnpack'
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
        srUpdateBC(GRM_HIL_DW.hold_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S24>/hold' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.input_hold_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S21>/input_hold' */
    /* Sum: '<Root>/Sum of Elements' incorporates:
     *  Math: '<Root>/Math Function'
     */
    ServoCMD1 = (GRM_HIL_B.SensorACC_update[0] * GRM_HIL_B.SensorACC_update[0] +
                 GRM_HIL_B.SensorACC_update[1] * GRM_HIL_B.SensorACC_update[1])
      + GRM_HIL_B.SensorACC_update[2] * GRM_HIL_B.SensorACC_update[2];

    /* Math: '<Root>/Math Function1'
     *
     * About '<Root>/Math Function1':
     *  Operator: sqrt
     */
    if (ServoCMD1 < 0.0F) {
      GRM_HIL_B.MathFunction1 = -sqrtf(fabsf(ServoCMD1));
    } else {
      GRM_HIL_B.MathFunction1 = sqrtf(ServoCMD1);
    }

    /* End of Math: '<Root>/Math Function1' */
    /* Constant: '<S327>/Constant' */
    memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
           (real_T));
  }

  /* Integrator: '<S334>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK != 0) {
    memcpy(&GRM_HIL_X.integration_eom_CSTATE[0], &GRM_HIL_B.Constant[0], 13U *
           sizeof(real_T));
  }

  /* Product: '<S337>/Product3' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_Gain2_dm = GRM_HIL_X.integration_eom_CSTATE[8] *
    GRM_HIL_X.integration_eom_CSTATE[8];

  /* Sum: '<S337>/Add' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Product: '<S337>/Product1'
   *  Product: '<S337>/Product2'
   *  Product: '<S337>/Product4'
   */
  rtb_Subtract_cl = ((GRM_HIL_X.integration_eom_CSTATE[6] *
                      GRM_HIL_X.integration_eom_CSTATE[6] +
                      GRM_HIL_X.integration_eom_CSTATE[7] *
                      GRM_HIL_X.integration_eom_CSTATE[7]) + rtb_Gain2_dm) +
    GRM_HIL_X.integration_eom_CSTATE[9] * GRM_HIL_X.integration_eom_CSTATE[9];

  /* Math: '<S337>/Math Function'
   *
   * About '<S337>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Subtract_cl < 0.0) {
    rtb_Subtract_cl = -sqrt(fabs(rtb_Subtract_cl));
  } else {
    rtb_Subtract_cl = sqrt(rtb_Subtract_cl);
  }

  /* End of Math: '<S337>/Math Function' */

  /* Product: '<S337>/Product' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_Product_idx_0 = GRM_HIL_X.integration_eom_CSTATE[6] / rtb_Subtract_cl;
  rtb_Product_idx_1 = GRM_HIL_X.integration_eom_CSTATE[7] / rtb_Subtract_cl;
  rtb_Product_idx_2 = GRM_HIL_X.integration_eom_CSTATE[8] / rtb_Subtract_cl;
  rtb_Product_idx_3 = GRM_HIL_X.integration_eom_CSTATE[9] / rtb_Subtract_cl;

  /* Math: '<S292>/Math Function1' incorporates:
   *  Math: '<S292>/Math Function5'
   *  Math: '<S292>/Math Function9'
   *  Math: '<S335>/Math Function5'
   *  Math: '<S335>/Math Function9'
   *  Switch: '<S333>/Switch'
   */
  rtb_Gain2_dm_tmp = rtb_Product_idx_1 * rtb_Product_idx_1;
  rtb_Gain2_dm = rtb_Gain2_dm_tmp;

  /* Math: '<S292>/Math Function' incorporates:
   *  Math: '<S292>/Math Function4'
   *  Math: '<S292>/Math Function8'
   *  Math: '<S335>/Math Function4'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_1 = rtb_Product_idx_0 * rtb_Product_idx_0;

  /* Math: '<S292>/Math Function2' incorporates:
   *  Math: '<S292>/Math Function10'
   *  Math: '<S292>/Math Function6'
   *  Math: '<S335>/Math Function6'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_2 = rtb_Product_idx_2 * rtb_Product_idx_2;

  /* Math: '<S292>/Math Function3' incorporates:
   *  Math: '<S292>/Math Function11'
   *  Math: '<S292>/Math Function7'
   *  Math: '<S335>/Math Function11'
   *  Math: '<S335>/Math Function7'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_3 = rtb_Product_idx_3 * rtb_Product_idx_3;

  /* Sum: '<S292>/Add' incorporates:
   *  Math: '<S292>/Math Function'
   *  Math: '<S292>/Math Function2'
   *  Math: '<S292>/Math Function3'
   */
  rtb_TBG[0] = ((rtb_TBG_tmp_1 - rtb_Gain2_dm) - rtb_TBG_tmp_2) + rtb_TBG_tmp_3;

  /* Product: '<S292>/Product' incorporates:
   *  Product: '<S292>/Product6'
   *  Product: '<S335>/Product'
   *  Product: '<S335>/Product6'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp = rtb_Product_idx_0 * rtb_Product_idx_1;

  /* Product: '<S292>/Product1' incorporates:
   *  Product: '<S292>/Product7'
   *  Product: '<S335>/Product1'
   *  Product: '<S335>/Product7'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_0 = rtb_Product_idx_2 * rtb_Product_idx_3;

  /* Sum: '<S292>/Add1' incorporates:
   *  Gain: '<S292>/Gain1'
   *  Gain: '<S292>/Gain2'
   *  Product: '<S292>/Product'
   *  Product: '<S292>/Product1'
   */
  rtb_TBG[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_c - rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain2_Gain_c;

  /* Product: '<S292>/Product8' incorporates:
   *  Product: '<S292>/Product4'
   *  Product: '<S335>/Product4'
   *  Product: '<S335>/Product8'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_4 = rtb_Product_idx_0 * rtb_Product_idx_2;

  /* Product: '<S292>/Product9' incorporates:
   *  Product: '<S292>/Product5'
   *  Product: '<S335>/Product5'
   *  Product: '<S335>/Product9'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_5 = rtb_Product_idx_1 * rtb_Product_idx_3;

  /* Sum: '<S292>/Add5' incorporates:
   *  Gain: '<S292>/Gain10'
   *  Gain: '<S292>/Gain9'
   *  Product: '<S292>/Product8'
   *  Product: '<S292>/Product9'
   */
  rtb_TBG[2] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain9_Gain_c + rtb_TBG_tmp_5 *
    GRM_HIL_P.Gain10_Gain_g;

  /* Sum: '<S292>/Add4' incorporates:
   *  Gain: '<S292>/Gain7'
   *  Gain: '<S292>/Gain8'
   */
  rtb_TBG[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain_c + rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain8_Gain_b;

  /* Math: '<S292>/Math Function5' */
  rtb_Gain2_dm = rtb_Gain2_dm_tmp;

  /* Sum: '<S292>/Add6' */
  rtb_TBG[4] = ((rtb_Gain2_dm - rtb_TBG_tmp_1) - rtb_TBG_tmp_2) + rtb_TBG_tmp_3;

  /* Product: '<S292>/Product2' incorporates:
   *  Product: '<S292>/Product10'
   *  Product: '<S335>/Product10'
   *  Product: '<S335>/Product2'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_6 = rtb_Product_idx_1 * rtb_Product_idx_2;

  /* Product: '<S292>/Product3' incorporates:
   *  Product: '<S292>/Product11'
   *  Product: '<S335>/Product11'
   *  Product: '<S335>/Product3'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_7 = rtb_Product_idx_0 * rtb_Product_idx_3;

  /* Sum: '<S292>/Add2' incorporates:
   *  Gain: '<S292>/Gain3'
   *  Gain: '<S292>/Gain4'
   *  Product: '<S292>/Product2'
   *  Product: '<S292>/Product3'
   */
  rtb_TBG[5] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain3_Gain_p - rtb_TBG_tmp_7 *
    GRM_HIL_P.Gain4_Gain_o;

  /* Sum: '<S292>/Add3' incorporates:
   *  Gain: '<S292>/Gain5'
   *  Gain: '<S292>/Gain6'
   */
  rtb_TBG[6] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain5_Gain_l - rtb_TBG_tmp_5 *
    GRM_HIL_P.Gain6_Gain_p;

  /* Sum: '<S292>/Add8' incorporates:
   *  Gain: '<S292>/Gain11'
   *  Gain: '<S292>/Gain12'
   */
  rtb_TBG[7] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain11_Gain_d + rtb_TBG_tmp_7 *
    GRM_HIL_P.Gain12_Gain_g;

  /* Math: '<S292>/Math Function9' */
  rtb_Gain2_dm = rtb_Gain2_dm_tmp;

  /* Sum: '<S292>/Add7' incorporates:
   *  Sum: '<S335>/Add7'
   *  Switch: '<S333>/Switch'
   */
  rtb_TBG_tmp_8 = rtb_TBG_tmp_2 - rtb_TBG_tmp_1;
  rtb_TBG[8] = (rtb_TBG_tmp_8 - rtb_Gain2_dm) + rtb_TBG_tmp_3;
  for (i = 0; i < 3; i++) {
    /* Math: '<S326>/Math Function' incorporates:
     *  Math: '<S343>/Math Function'
     */
    rtb_MatrixMultiply_tmp[3 * i] = rtb_TBG[i];
    rtb_MatrixMultiply_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_MatrixMultiply_tmp[3 * i + 2] = rtb_TBG[i + 6];
  }

  /* Product: '<S326>/Product1' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Math: '<S326>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_i[i] = rtb_MatrixMultiply_tmp[i + 6] *
      GRM_HIL_X.integration_eom_CSTATE[5] + (rtb_MatrixMultiply_tmp[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[4] + rtb_MatrixMultiply_tmp[i] *
      GRM_HIL_X.integration_eom_CSTATE[3]);
  }

  /* End of Product: '<S326>/Product1' */

  /* Gain: '<S194>/Gain' */
  GRM_HIL_B.VEL_u_K_R_E_B_mDs = GRM_HIL_P.Gain_Gain_k1 * rtb_Product_i[0];

  /* Gain: '<S194>/Gain1' */
  GRM_HIL_B.VEL_v_K_R_E_B_mDs = GRM_HIL_P.Gain1_Gain_mm * rtb_Product_i[1];

  /* Gain: '<S194>/Gain2' */
  GRM_HIL_B.VEL_w_K_R_E_B_mDs = GRM_HIL_P.Gain2_Gain_e * rtb_Product_i[2];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  GRM_HIL_B.U0 = (GRM_HIL_B.VEL_u_K_R_E_B_mDs * GRM_HIL_B.VEL_u_K_R_E_B_mDs +
                  GRM_HIL_B.VEL_v_K_R_E_B_mDs * GRM_HIL_B.VEL_v_K_R_E_B_mDs) +
    GRM_HIL_B.VEL_w_K_R_E_B_mDs * GRM_HIL_B.VEL_w_K_R_E_B_mDs;
  GRM_HIL_B.U0 = sqrt(GRM_HIL_B.U0);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S194>/Gain17' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.POS_z_NED_m = GRM_HIL_P.Gain17_Gain *
    GRM_HIL_X.integration_eom_CSTATE[2];

  /* RelationalOperator: '<S387>/Compare' incorporates:
   *  Constant: '<S387>/Constant'
   */
  GRM_HIL_B.Compare = (GRM_HIL_B.POS_z_NED_m >=
                       GRM_HIL_P.CompareToConstant_const);

  /* Stop: '<S9>/Stop Simulation' */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && GRM_HIL_B.Compare) {
    rtmSetStopRequested(GRM_HIL_M, 1);
  }

  /* End of Stop: '<S9>/Stop Simulation' */

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S13>/Transfer Fcn'
   */
  GRM_HIL_B.Fin_1_Pos_rad = (GRM_HIL_P.Servo_TF.Servo1_Numerator_Coefs /
    GRM_HIL_P.Servo_TF.Servo1_Denominator_Coefs[0] *
    GRM_HIL_X.TransferFcn_CSTATE[1] + 0.0 * GRM_HIL_X.TransferFcn_CSTATE[0]) *
    GRM_HIL_P.Gain_Gain_pl;

  /* TransferFcn: '<S13>/Transfer Fcn1' incorporates:
   *  TransferFcn: '<S13>/Transfer Fcn2'
   *  TransferFcn: '<S13>/Transfer Fcn3'
   */
  rtb_Product2_m = GRM_HIL_P.Servo_TF.Servo2_Numerator_Coefs /
    GRM_HIL_P.Servo_TF.Servo2_Denominator_Coefs[0];

  /* Gain: '<S14>/Gain1' incorporates:
   *  TransferFcn: '<S13>/Transfer Fcn1'
   */
  GRM_HIL_B.Fin_2_Pos_rad = (rtb_Product2_m * GRM_HIL_X.TransferFcn1_CSTATE[1] +
    0.0 * GRM_HIL_X.TransferFcn1_CSTATE[0]) * GRM_HIL_P.Gain1_Gain_j5;

  /* Gain: '<S14>/Gain2' incorporates:
   *  TransferFcn: '<S13>/Transfer Fcn2'
   */
  GRM_HIL_B.Fin_3_Pos_rad = (rtb_Product2_m * GRM_HIL_X.TransferFcn2_CSTATE[1] +
    0.0 * GRM_HIL_X.TransferFcn2_CSTATE[0]) * GRM_HIL_P.Gain2_Gain_g;

  /* Gain: '<S14>/Gain3' incorporates:
   *  TransferFcn: '<S13>/Transfer Fcn3'
   */
  GRM_HIL_B.Fin_4_Pos_rad = (rtb_Product2_m * GRM_HIL_X.TransferFcn3_CSTATE[1] +
    0.0 * GRM_HIL_X.TransferFcn3_CSTATE[0]) * GRM_HIL_P.Gain3_Gain_d;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S12>/Constant' */
    GRM_HIL_B.A = GRM_HIL_P.Constant_Value_ei;

    /* Constant: '<S12>/Constant1' */
    GRM_HIL_B.B = GRM_HIL_P.Constant1_Value_d;

    /* Constant: '<S12>/Constant2' */
    GRM_HIL_B.Z = GRM_HIL_P.Constant2_Value_h;

    /* Constant: '<S12>/Constant3' */
    GRM_HIL_B.A_i = GRM_HIL_P.Constant3_Value_o;

    /* Constant: '<S12>/Constant4' */
    GRM_HIL_B.B_d = GRM_HIL_P.Constant4_Value_om;

    /* Constant: '<S12>/Constant5' */
    GRM_HIL_B.Z_d = GRM_HIL_P.Constant5_Value;

    /* Constant: '<S12>/Constant6' */
    GRM_HIL_B.A_m = GRM_HIL_P.Constant6_Value_d;

    /* Constant: '<S12>/Constant7' */
    GRM_HIL_B.B_c = GRM_HIL_P.Constant7_Value_ny;

    /* Constant: '<S12>/Constant8' */
    GRM_HIL_B.Z_h = GRM_HIL_P.Constant8_Value_lk;

    /* Constant: '<S12>/Constant9' */
    GRM_HIL_B.A_f = GRM_HIL_P.Constant9_Value_e;

    /* Constant: '<S12>/Constant10' */
    GRM_HIL_B.B_n = GRM_HIL_P.Constant10_Value_j;

    /* Constant: '<S12>/Constant11' */
    GRM_HIL_B.Z_l = GRM_HIL_P.Constant11_Value_i;

    /* ToAsyncQueueBlock generated from: '<Root>/Actuators' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_1_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2019685508U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_2_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3549267901U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_3_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3530171564U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_4_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2103377955U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3732719497U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1853753753U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3445598233U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_i;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(773567699U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(816143410U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(256366903U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3390687037U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_c;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4127515693U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3084088169U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_f;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3421848115U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_n;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1717588779U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(457575933U, time, pData, size);
      }
    }

    /* Memory generated from: '<S35>/Memory' */
    rtb_LogicalOperator2 = GRM_HIL_DW.Memory_1_PreviousInput;

    /* Memory generated from: '<S35>/Memory' */
    rtb_LogicalOperator1_c = GRM_HIL_DW.Memory_2_PreviousInput;

    /* Logic: '<S37>/Logical Operator2' incorporates:
     *  Logic: '<S37>/Logical Operator3'
     */
    rtb_LogicalOperator2 = (rtb_LogicalOperator2 && (!rtb_LogicalOperator1_c));

    /* DataTypeConversion: '<S37>/Data Type Conversion1' */
    GRM_HIL_B.Gimbal_operational_flg = rtb_LogicalOperator2;

    /* Constant: '<S37>/Constant1' */
    GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_P.Constant1_Value_lj;

    /* Constant: '<S37>/Constant2' */
    GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_P.Constant2_Value_gj;

    /* Gain: '<S44>/Shaft2degYaw' incorporates:
     *  Memory generated from: '<S35>/Memory1'
     */
    GRM_HIL_B.yaw_deg = GRM_HIL_P.Shaft2degYaw_Gain *
      GRM_HIL_DW.Memory1_1_PreviousInput;
  }

  /* TransferFcn: '<S48>/Transfer Fcn1' */
  rtb_Gain1_c = GRM_HIL_P.TransferFcn1_C[0] * GRM_HIL_X.TransferFcn1_CSTATE_k[0]
    + GRM_HIL_P.TransferFcn1_C[1] * GRM_HIL_X.TransferFcn1_CSTATE_k[1];

  /* Sum: '<S48>/Subtract' incorporates:
   *  Constant: '<S48>/Constant2'
   */
  rtb_Gain2_dm = rtb_Gain1_c - GRM_HIL_P.Constant2_Value_bl;

  /* Abs: '<S48>/Abs' */
  rtb_Gain2_dm = fabs(rtb_Gain2_dm);

  /* DataTypeConversion: '<S37>/Data Type Conversion' incorporates:
   *  Constant: '<S172>/Constant'
   *  Logic: '<S37>/Logical Operator'
   *  RelationalOperator: '<S172>/Compare'
   */
  GRM_HIL_B.Gimbal_Ramp_flg = !(rtb_Gain2_dm <
    GRM_HIL_P.CompareToConstant_const_h);

  /* TransportDelay: '<S175>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Gain2_dm = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK.Last,
      GRM_HIL_DW.TransportDelay_IWORK.Tail,
      GRM_HIL_DW.TransportDelay_IWORK.Head,
      GRM_HIL_P.TransportDelay_InitOutput,
      1,
      0);
  }

  /* Gain: '<S175>/Gain' incorporates:
   *  Sum: '<S175>/Sum'
   */
  GRM_HIL_B.Gain = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.yaw_deg - rtb_Gain2_dm);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S44>/Shaft2degPitch' incorporates:
     *  Memory generated from: '<S35>/Memory1'
     */
    GRM_HIL_B.pitch_deg = GRM_HIL_P.Shaft2degPitch_Gain *
      GRM_HIL_DW.Memory1_2_PreviousInput;
  }

  /* TransportDelay: '<S173>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_i.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_i.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Gain2_dm = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK_p.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK_p.Last,
      GRM_HIL_DW.TransportDelay_IWORK_p.Tail,
      GRM_HIL_DW.TransportDelay_IWORK_p.Head,
      GRM_HIL_P.TransportDelay_InitOutput_m,
      1,
      0);
  }

  /* Gain: '<S173>/Gain' incorporates:
   *  Sum: '<S173>/Sum'
   */
  GRM_HIL_B.Gain_a = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.pitch_deg - rtb_Gain2_dm);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S44>/Shaft2degRoll' incorporates:
     *  Memory generated from: '<S35>/Memory1'
     */
    GRM_HIL_B.roll_deg = GRM_HIL_P.Shaft2degRoll_Gain *
      GRM_HIL_DW.Memory1_3_PreviousInput;
  }

  /* TransportDelay: '<S174>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_is.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_is.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Gain2_dm = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK_f.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK_f.Last,
      GRM_HIL_DW.TransportDelay_IWORK_f.Tail,
      GRM_HIL_DW.TransportDelay_IWORK_f.Head,
      GRM_HIL_P.TransportDelay_InitOutput_i,
      1,
      0);
  }

  /* Gain: '<S174>/Gain' incorporates:
   *  Sum: '<S174>/Sum'
   */
  GRM_HIL_B.Gain_d = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.roll_deg - rtb_Gain2_dm);

  /* Outputs for Enabled SubSystem: '<S44>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  /* Abs: '<S71>/Abs' incorporates:
   *  Abs: '<S175>/Abs'
   *  Abs: '<S51>/Abs'
   */
  rtb_Product2_m = fabs(GRM_HIL_B.Gain);

  /* End of Outputs for SubSystem: '<S44>/Voltage_Limitations' */

  /* RelationalOperator: '<S166>/Compare' incorporates:
   *  Abs: '<S71>/Abs'
   *  Constant: '<S166>/Constant'
   */
  rtb_Compare_l = (rtb_Product2_m >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S71>/Enabled pass' */
  /* Constant: '<S71>/const_upper_limit' incorporates:
   *  Constant: '<S71>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_l,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMinVolt,
                      &GRM_HIL_B.Merge, &GRM_HIL_B.Merge1,
                      &GRM_HIL_DW.Enabledpass_e);

  /* End of Outputs for SubSystem: '<S71>/Enabled pass' */

  /* Logic: '<S71>/Logical Operator' */
  GRM_HIL_B.LogicalOperator = !rtb_Compare_l;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S167>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3 =
      GRM_HIL_B.LogicalOperator;

    /* Outputs for Enabled SubSystem: '<S71>/Enabled adapt' incorporates:
     *  EnablePort: '<S167>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3;
    }

    /* End of Outputs for SubSystem: '<S71>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S71>/Enabled adapt' incorporates:
   *  EnablePort: '<S167>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S167>/Abs' incorporates:
       *  Constant: '<S167>/Constant'
       */
      GRM_HIL_B.Abs = fabs(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_hard_limit_vel);
    }

    /* Sum: '<S167>/Add' incorporates:
     *  Abs: '<S71>/Abs'
     *  Constant: '<S167>/Constant1'
     *  Gain: '<S167>/Gain'
     *  Product: '<S167>/Divide'
     */
    rtb_jxk = GRM_HIL_B.Abs / rtb_Product2_m *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_limit_adaption_coef - 1.0);

    /* Product: '<S167>/Product' incorporates:
     *  Constant: '<S71>/const_upper_limit'
     */
    GRM_HIL_B.Merge = rtb_jxk * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;

    /* Product: '<S167>/Product1' incorporates:
     *  Constant: '<S71>/const_lower_limit'
     */
    GRM_HIL_B.Merge1 = rtb_jxk * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S71>/Enabled adapt' */

  /* Switch: '<S71>/Switch2' incorporates:
   *  Constant: '<S71>/Constant2'
   */
  if (GRM_HIL_B.Gain > GRM_HIL_P.Switch2_Threshold) {
    GRM_HIL_B.Switch2 = GRM_HIL_B.Merge;
  } else {
    GRM_HIL_B.Switch2 = GRM_HIL_P.Constant2_Value_k;
  }

  /* End of Switch: '<S71>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S71>/Gain' incorporates:
     *  Constant: '<S71>/Constant2'
     */
    GRM_HIL_B.Gain_c = GRM_HIL_P.Gain_Gain_d * GRM_HIL_P.Constant2_Value_k;
  }

  /* Switch: '<S71>/Switch1' */
  if (GRM_HIL_B.Gain > GRM_HIL_P.Switch1_Threshold) {
    GRM_HIL_B.Switch1 = GRM_HIL_B.Gain_c;
  } else {
    GRM_HIL_B.Switch1 = GRM_HIL_B.Merge1;
  }

  /* End of Switch: '<S71>/Switch1' */

  /* Product: '<S205>/Product' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   */
  rtb_Gain2_dm = -rtb_Product_idx_0 * rtb_Product_idx_3;

  /* Sum: '<S205>/Add' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   *  Product: '<S205>/Product1'
   */
  rtb_jxk = -rtb_Product_idx_1 * -rtb_Product_idx_2 + rtb_Gain2_dm;

  /* Product: '<S205>/Product2' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   */
  rtb_Gain2_dm = -rtb_Product_idx_0 * -rtb_Product_idx_0;

  /* Product: '<S205>/Product3' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   *  Product: '<S205>/Product8'
   */
  rtb_Add1_p = -rtb_Product_idx_1 * -rtb_Product_idx_1;

  /* Sum: '<S205>/Add1' incorporates:
   *  Constant: '<S205>/Constant'
   *  Product: '<S205>/Product3'
   */
  rtb_Add1 = (GRM_HIL_P.Constant_Value_pf - rtb_Gain2_dm) - rtb_Add1_p;

  /* Product: '<S205>/Product4' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   */
  rtb_Gain2_dm = -rtb_Product_idx_1 * rtb_Product_idx_3;

  /* Gain: '<S205>/Gain' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   *  Product: '<S205>/Product5'
   *  Sum: '<S205>/Add2'
   */
  rtb_Gain2_dm = (rtb_Gain2_dm - -rtb_Product_idx_0 * -rtb_Product_idx_2) *
    GRM_HIL_P.Gain_Gain_m;

  /* Saturate: '<S205>/Saturation' */
  if (rtb_Gain2_dm > GRM_HIL_P.Saturation_UpperSat_g) {
    rtb_Gain2_dm = GRM_HIL_P.Saturation_UpperSat_g;
  } else {
    if (rtb_Gain2_dm < GRM_HIL_P.Saturation_LowerSat_k) {
      rtb_Gain2_dm = GRM_HIL_P.Saturation_LowerSat_k;
    }
  }

  /* End of Saturate: '<S205>/Saturation' */

  /* Trigonometry: '<S205>/Trigonometric Function1' */
  if (rtb_Gain2_dm > 1.0) {
    rtb_Sqrt_k = 1.0;
  } else if (rtb_Gain2_dm < -1.0) {
    rtb_Sqrt_k = -1.0;
  } else {
    rtb_Sqrt_k = rtb_Gain2_dm;
  }

  /* Product: '<S205>/Product6' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   */
  rtb_Gain2_dm = -rtb_Product_idx_0 * -rtb_Product_idx_1;

  /* Sum: '<S205>/Add3' incorporates:
   *  MATLAB Function: '<S193>/MATLAB Function'
   *  Product: '<S205>/Product7'
   */
  rtb_Add3 = -rtb_Product_idx_2 * rtb_Product_idx_3 + rtb_Gain2_dm;

  /* Product: '<S205>/Product8' */
  rtb_Gain2_dm = rtb_Add1_p;

  /* Gain: '<S194>/Gain9' incorporates:
   *  Trigonometry: '<S205>/Trigonometric Function'
   */
  GRM_HIL_B.ATT_Phi_rad = GRM_HIL_P.Gain9_Gain_f * rt_atan2d_snf(rtb_jxk,
    rtb_Add1);

  /* Product: '<S47>/Product' incorporates:
   *  Gain: '<S191>/rad2deg'
   */
  GRM_HIL_B.Product = GRM_HIL_P.rad2deg_Gain * GRM_HIL_B.ATT_Phi_rad *
    rtb_Gain1_c;

  /* Sum: '<S47>/Sum' */
  GRM_HIL_B.Yaw_err = GRM_HIL_B.Product - GRM_HIL_B.yaw_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S72>/Proportional Gain' */
    rtb_ProportionalGain =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Proportional_Gain *
      GRM_HIL_B.Yaw_err;

    /* Gain: '<S72>/Derivative Gain' */
    rtb_DerivativeGain =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Derivative_Gain *
      GRM_HIL_B.Yaw_err;
  }

  /* Integrator: '<S72>/Integrator' */
  GRM_HIL_B.Integrator = GRM_HIL_X.Integrator_CSTATE;

  /* Integrator: '<S72>/Filter' */
  GRM_HIL_B.Filter = GRM_HIL_X.Filter_CSTATE;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S72>/Filter Coefficient' incorporates:
     *  Sum: '<S72>/SumD'
     */
    GRM_HIL_B.FilterCoefficient = (rtb_DerivativeGain - GRM_HIL_B.Filter) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Filter_Coefficient;

    /* Sum: '<S72>/Sum' */
    rtb_Sum_a = (rtb_ProportionalGain + GRM_HIL_B.Integrator) +
      GRM_HIL_B.FilterCoefficient;

    /* Logic: '<S71>/Logical Operator1' incorporates:
     *  Constant: '<S71>/Constant'
     */
    GRM_HIL_B.LogicalOperator1 =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S71>/Switch' incorporates:
   *  Abs: '<S71>/Abs'
   *  Constant: '<S165>/Constant'
   *  Constant: '<S71>/Constant1'
   *  RelationalOperator: '<S165>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1) {
    GRM_HIL_B.Switch_m = GRM_HIL_P.Constant1_Value_pw;
  } else {
    GRM_HIL_B.Switch_m = (rtb_Product2_m >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_soft_limit_vel);
  }

  /* End of Switch: '<S71>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S169>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3 = GRM_HIL_B.Switch_m;

    /* Outputs for Enabled SubSystem: '<S72>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3,
                       GRM_HIL_B.Switch2, GRM_HIL_B.Switch1, rtb_Sum_a,
                       &GRM_HIL_B.Merge_l, &GRM_HIL_DW.Saturation_h4);

    /* End of Outputs for SubSystem: '<S72>/Saturation' */

    /* Logic: '<S72>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_c = !GRM_HIL_B.Switch_m;

    /* Outputs for Enabled SubSystem: '<S72>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_c, rtb_Sum_a,
                 &GRM_HIL_B.Merge_l, &GRM_HIL_DW.pass_k);

    /* End of Outputs for SubSystem: '<S72>/pass' */

    /* Outputs for Enabled SubSystem: '<S70>/pass' incorporates:
     *  EnablePort: '<S74>/Enable'
     */
    /* Logic: '<S70>/Logical Operator' incorporates:
     *  Constant: '<S70>/Constant'
     *  Inport: '<S74>/Controller_Cmd'
     */
    if (!(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Limit_Controllers != 0.0)) {
      GRM_HIL_B.Merge_f = GRM_HIL_B.Merge_l;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.pass_SubsysRanBC);
      }
    }

    /* End of Logic: '<S70>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S70>/pass' */

    /* Outputs for Enabled SubSystem: '<S70>/Control_Limits' incorporates:
     *  EnablePort: '<S73>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S70>/Constant' */
      GRM_HIL_DW.Control_Limits_MODE =
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Limit_Controllers > 0.0);
    }

    /* End of Outputs for SubSystem: '<S70>/Control_Limits' */
  }

  /* Outputs for Enabled SubSystem: '<S70>/Control_Limits' incorporates:
   *  EnablePort: '<S73>/Enable'
   */
  if (GRM_HIL_DW.Control_Limits_MODE) {
    /* Product: '<S73>/Divide' incorporates:
     *  Constant: '<S73>/Constant'
     *  Constant: '<S73>/Constant1'
     *  Gain: '<S73>/Gain2'
     *  Sum: '<S73>/Subtract'
     */
    rtb_jxk = GRM_HIL_P.Constant_Value_g /
      ((GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV - GRM_HIL_B.Gain) *
       GRM_HIL_P.Gain2_Gain);

    /* Product: '<S73>/Divide1' incorporates:
     *  Constant: '<S73>/Constant2'
     *  Constant: '<S73>/Constant3'
     *  Gain: '<S73>/Gain3'
     *  Sum: '<S73>/Subtract1'
     */
    rtb_Cy = GRM_HIL_P.Constant3_Value / ((GRM_HIL_B.Gain -
      (-GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV)) * GRM_HIL_P.Gain3_Gain);

    /* Gain: '<S109>/Filter Coefficient' incorporates:
     *  Gain: '<S100>/Derivative Gain'
     *  Integrator: '<S101>/Filter'
     *  Sum: '<S101>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_d =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Derivative_Gain * rtb_jxk -
       GRM_HIL_X.Filter_CSTATE_l) * GRM_HIL_P.PIDController_N;

    /* Sum: '<S115>/Sum' incorporates:
     *  Gain: '<S111>/Proportional Gain'
     *  Integrator: '<S106>/Integrator'
     */
    rtb_ProportionalGain =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Proportional_Gain * rtb_jxk +
       GRM_HIL_X.Integrator_CSTATE_l) + GRM_HIL_B.FilterCoefficient_d;

    /* Saturate: '<S113>/Saturation' */
    if (rtb_ProportionalGain > GRM_HIL_P.PIDController_UpperSaturationLimit) {
      rtb_DerivativeGain = GRM_HIL_P.PIDController_UpperSaturationLimit;
    } else if (rtb_ProportionalGain <
               GRM_HIL_P.PIDController_LowerSaturationLimit) {
      rtb_DerivativeGain = GRM_HIL_P.PIDController_LowerSaturationLimit;
    } else {
      rtb_DerivativeGain = rtb_ProportionalGain;
    }

    /* End of Saturate: '<S113>/Saturation' */

    /* Gain: '<S153>/Filter Coefficient' incorporates:
     *  Gain: '<S144>/Derivative Gain'
     *  Integrator: '<S145>/Filter'
     *  Sum: '<S145>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_g =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Derivative_Gain * rtb_Cy -
       GRM_HIL_X.Filter_CSTATE_b) * GRM_HIL_P.PIDController1_N;

    /* Sum: '<S159>/Sum' incorporates:
     *  Gain: '<S155>/Proportional Gain'
     *  Integrator: '<S150>/Integrator'
     */
    rtb_Add1 = (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Proportional_Gain *
                rtb_Cy + GRM_HIL_X.Integrator_CSTATE_i) +
      GRM_HIL_B.FilterCoefficient_g;

    /* Saturate: '<S157>/Saturation' */
    if (rtb_Add1 > GRM_HIL_P.PIDController1_UpperSaturationLimit) {
      rtb_jxi = GRM_HIL_P.PIDController1_UpperSaturationLimit;
    } else if (rtb_Add1 < GRM_HIL_P.PIDController1_LowerSaturationLimit) {
      rtb_jxi = GRM_HIL_P.PIDController1_LowerSaturationLimit;
    } else {
      rtb_jxi = rtb_Add1;
    }

    /* End of Saturate: '<S157>/Saturation' */

    /* Sum: '<S99>/SumI4' incorporates:
     *  Gain: '<S103>/Integral Gain'
     *  Gain: '<S99>/Kb'
     *  Sum: '<S99>/SumI2'
     */
    GRM_HIL_B.SumI4 = (rtb_DerivativeGain - rtb_ProportionalGain) *
      GRM_HIL_P.PIDController_Kb +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Integral_Gain * rtb_jxk;

    /* Sum: '<S143>/SumI4' incorporates:
     *  Gain: '<S143>/Kb'
     *  Gain: '<S147>/Integral Gain'
     *  Sum: '<S143>/SumI2'
     */
    GRM_HIL_B.SumI4_g = (rtb_jxi - rtb_Add1) * GRM_HIL_P.PIDController1_Kb +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Integral_Gain * rtb_Cy;

    /* Sum: '<S73>/Sum' incorporates:
     *  Gain: '<S73>/Gain'
     *  Gain: '<S73>/Gain1'
     */
    GRM_HIL_B.Merge_f = (GRM_HIL_B.Merge_l -
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Weighting *
                         rtb_DerivativeGain) +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Weighting * rtb_jxi;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Control_Limits_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S70>/Control_Limits' */

  /* Outputs for Enabled SubSystem: '<S44>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  /* Abs: '<S52>/Abs' incorporates:
   *  Abs: '<S173>/Abs'
   *  Abs: '<S51>/Abs2'
   */
  rtb_Add1_p = fabs(GRM_HIL_B.Gain_a);

  /* End of Outputs for SubSystem: '<S44>/Voltage_Limitations' */

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S55>/Constant'
   */
  rtb_Compare_o = (rtb_Add1_p >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S52>/Enabled pass' */
  /* Constant: '<S52>/const_upper_limit' incorporates:
   *  Constant: '<S52>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_o,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMinVolt,
                      &GRM_HIL_B.Merge_lo, &GRM_HIL_B.Merge1_f,
                      &GRM_HIL_DW.Enabledpass);

  /* End of Outputs for SubSystem: '<S52>/Enabled pass' */

  /* Logic: '<S52>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_l = !rtb_Compare_o;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S56>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_n =
      GRM_HIL_B.LogicalOperator_l;

    /* Outputs for Enabled SubSystem: '<S52>/Enabled adapt' incorporates:
     *  EnablePort: '<S56>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE_l =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_n;
    }

    /* End of Outputs for SubSystem: '<S52>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S52>/Enabled adapt' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE_l) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S56>/Abs' incorporates:
       *  Constant: '<S56>/Constant'
       */
      GRM_HIL_B.Abs_j = fabs
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_hard_limit_vel);
    }

    /* Sum: '<S56>/Add' incorporates:
     *  Abs: '<S52>/Abs'
     *  Constant: '<S56>/Constant1'
     *  Gain: '<S56>/Gain'
     *  Product: '<S56>/Divide'
     */
    rtb_jxk = GRM_HIL_B.Abs_j / rtb_Add1_p *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_limit_adaption_coef - 1.0);

    /* Product: '<S56>/Product' incorporates:
     *  Constant: '<S52>/const_upper_limit'
     */
    GRM_HIL_B.Merge_lo = rtb_jxk *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;

    /* Product: '<S56>/Product1' incorporates:
     *  Constant: '<S52>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_f = rtb_jxk *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_e);
    }
  }

  /* End of Outputs for SubSystem: '<S52>/Enabled adapt' */

  /* Switch: '<S52>/Switch2' incorporates:
   *  Constant: '<S52>/Constant2'
   */
  if (GRM_HIL_B.Gain_a > GRM_HIL_P.Switch2_Threshold_a) {
    GRM_HIL_B.Switch2_m = GRM_HIL_B.Merge_lo;
  } else {
    GRM_HIL_B.Switch2_m = GRM_HIL_P.Constant2_Value_gu;
  }

  /* End of Switch: '<S52>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S52>/Gain' incorporates:
     *  Constant: '<S52>/Constant2'
     */
    GRM_HIL_B.Gain_cg = GRM_HIL_P.Gain_Gain_ec * GRM_HIL_P.Constant2_Value_gu;
  }

  /* Switch: '<S52>/Switch1' */
  if (GRM_HIL_B.Gain_a > GRM_HIL_P.Switch1_Threshold_a) {
    GRM_HIL_B.Switch1_p = GRM_HIL_B.Gain_cg;
  } else {
    GRM_HIL_B.Switch1_p = GRM_HIL_B.Merge1_f;
  }

  /* End of Switch: '<S52>/Switch1' */

  /* Gain: '<S194>/Gain10' incorporates:
   *  Trigonometry: '<S205>/Trigonometric Function1'
   */
  GRM_HIL_B.ATT_Theta_rad = GRM_HIL_P.Gain10_Gain_k * asin(rtb_Sqrt_k);

  /* Product: '<S45>/Product' incorporates:
   *  Gain: '<S191>/rad2deg1'
   */
  GRM_HIL_B.pitch_cmd = GRM_HIL_P.rad2deg1_Gain * GRM_HIL_B.ATT_Theta_rad *
    rtb_Gain1_c;

  /* Sum: '<S45>/Sum2' */
  GRM_HIL_B.pitch_err = GRM_HIL_B.pitch_cmd - GRM_HIL_B.pitch_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S53>/Proportional Gain' */
    rtb_ProportionalGain_l =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Proportional_Gain *
      GRM_HIL_B.pitch_err;

    /* Gain: '<S53>/Derivative Gain' */
    rtb_DerivativeGain_e =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Derivative_Gain *
      GRM_HIL_B.pitch_err;
  }

  /* Integrator: '<S53>/Integrator' */
  GRM_HIL_B.Integrator_e = GRM_HIL_X.Integrator_CSTATE_e;

  /* Integrator: '<S53>/Filter' */
  GRM_HIL_B.Filter_e = GRM_HIL_X.Filter_CSTATE_h;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S53>/Filter Coefficient' incorporates:
     *  Sum: '<S53>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_a = (rtb_DerivativeGain_e - GRM_HIL_B.Filter_e) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Filter_Coefficient;

    /* Sum: '<S53>/Sum' */
    rtb_Sum_m = (rtb_ProportionalGain_l + GRM_HIL_B.Integrator_e) +
      GRM_HIL_B.FilterCoefficient_a;

    /* Logic: '<S52>/Logical Operator1' incorporates:
     *  Constant: '<S52>/Constant'
     */
    GRM_HIL_B.LogicalOperator1_o =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S52>/Constant1'
   *  Constant: '<S54>/Constant'
   *  RelationalOperator: '<S54>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1_o) {
    GRM_HIL_B.Switch_i = GRM_HIL_P.Constant1_Value_n3;
  } else {
    GRM_HIL_B.Switch_i = (rtb_Add1_p >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_soft_limit_vel);
  }

  /* End of Switch: '<S52>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S58>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_m =
      GRM_HIL_B.Switch_i;

    /* Outputs for Enabled SubSystem: '<S53>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_m,
                       GRM_HIL_B.Switch2_m, GRM_HIL_B.Switch1_p, rtb_Sum_m,
                       &GRM_HIL_B.Merge_p, &GRM_HIL_DW.Saturation);

    /* End of Outputs for SubSystem: '<S53>/Saturation' */

    /* Logic: '<S53>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_k = !GRM_HIL_B.Switch_i;

    /* Outputs for Enabled SubSystem: '<S53>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_k, rtb_Sum_m,
                 &GRM_HIL_B.Merge_p, &GRM_HIL_DW.pass);

    /* End of Outputs for SubSystem: '<S53>/pass' */
  }

  /* Outputs for Enabled SubSystem: '<S44>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  /* Abs: '<S61>/Abs' incorporates:
   *  Abs: '<S174>/Abs'
   *  Abs: '<S51>/Abs4'
   */
  rtb_Sqrt_k = fabs(GRM_HIL_B.Gain_d);

  /* End of Outputs for SubSystem: '<S44>/Voltage_Limitations' */

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Abs: '<S61>/Abs'
   *  Constant: '<S64>/Constant'
   */
  rtb_Compare_e = (rtb_Sqrt_k >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S61>/Enabled pass' */
  /* Constant: '<S61>/const_upper_limit' incorporates:
   *  Constant: '<S61>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_e,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMinVolt,
                      &GRM_HIL_B.Merge_g, &GRM_HIL_B.Merge1_fu,
                      &GRM_HIL_DW.Enabledpass_l);

  /* End of Outputs for SubSystem: '<S61>/Enabled pass' */

  /* Logic: '<S61>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_e = !rtb_Compare_e;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S65>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_nw =
      GRM_HIL_B.LogicalOperator_e;

    /* Outputs for Enabled SubSystem: '<S61>/Enabled adapt' incorporates:
     *  EnablePort: '<S65>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE_g =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_nw;
    }

    /* End of Outputs for SubSystem: '<S61>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S61>/Enabled adapt' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE_g) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S65>/Abs' incorporates:
       *  Constant: '<S65>/Constant'
       */
      GRM_HIL_B.Abs_l = fabs
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_hard_limit_vel);
    }

    /* Sum: '<S65>/Add' incorporates:
     *  Abs: '<S61>/Abs'
     *  Constant: '<S65>/Constant1'
     *  Gain: '<S65>/Gain'
     *  Product: '<S65>/Divide'
     */
    rtb_jxk = GRM_HIL_B.Abs_l / rtb_Sqrt_k *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_limit_adaption_coef - 1.0);

    /* Product: '<S65>/Product' incorporates:
     *  Constant: '<S61>/const_upper_limit'
     */
    GRM_HIL_B.Merge_g = rtb_jxk *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;

    /* Product: '<S65>/Product1' incorporates:
     *  Constant: '<S61>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_fu = rtb_jxk *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_d);
    }
  }

  /* End of Outputs for SubSystem: '<S61>/Enabled adapt' */

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S61>/Constant2'
   */
  if (GRM_HIL_B.Gain_d > GRM_HIL_P.Switch2_Threshold_f) {
    GRM_HIL_B.Switch2_k = GRM_HIL_B.Merge_g;
  } else {
    GRM_HIL_B.Switch2_k = GRM_HIL_P.Constant2_Value_n;
  }

  /* End of Switch: '<S61>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S61>/Gain' incorporates:
     *  Constant: '<S61>/Constant2'
     */
    GRM_HIL_B.Gain_m = GRM_HIL_P.Gain_Gain_fh * GRM_HIL_P.Constant2_Value_n;
  }

  /* Switch: '<S61>/Switch1' */
  if (GRM_HIL_B.Gain_d > GRM_HIL_P.Switch1_Threshold_f) {
    GRM_HIL_B.Switch1_j = GRM_HIL_B.Gain_m;
  } else {
    GRM_HIL_B.Switch1_j = GRM_HIL_B.Merge1_fu;
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Gain: '<S194>/Gain11' incorporates:
   *  Constant: '<S205>/Constant1'
   *  MATLAB Function: '<S193>/MATLAB Function'
   *  Product: '<S205>/Product9'
   *  Sum: '<S205>/Add4'
   *  Trigonometry: '<S205>/Trigonometric Function2'
   */
  GRM_HIL_B.ATT_Psi_rad = rt_atan2d_snf(rtb_Add3, (GRM_HIL_P.Constant1_Value_jl
    - rtb_Gain2_dm) - -rtb_Product_idx_2 * -rtb_Product_idx_2) *
    GRM_HIL_P.Gain11_Gain_o;

  /* Product: '<S46>/Product1' incorporates:
   *  Gain: '<S191>/rad2deg2'
   */
  GRM_HIL_B.Product1 = GRM_HIL_P.rad2deg2_Gain * GRM_HIL_B.ATT_Psi_rad *
    rtb_Gain1_c;

  /* Sum: '<S46>/Sum1' */
  GRM_HIL_B.Roll_err = GRM_HIL_B.Product1 - GRM_HIL_B.roll_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S62>/Proportional Gain' */
    rtb_ProportionalGain_a =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Proportional_Gain *
      GRM_HIL_B.Roll_err;

    /* Gain: '<S62>/Derivative Gain' */
    rtb_DerivativeGain_j0 =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Derivative_Gain *
      GRM_HIL_B.Roll_err;
  }

  /* Integrator: '<S62>/Integrator' */
  GRM_HIL_B.Integrator_f = GRM_HIL_X.Integrator_CSTATE_g;

  /* Integrator: '<S62>/Filter' */
  GRM_HIL_B.Filter_f = GRM_HIL_X.Filter_CSTATE_e;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S62>/Filter Coefficient' incorporates:
     *  Sum: '<S62>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_l = (rtb_DerivativeGain_j0 - GRM_HIL_B.Filter_f)
      * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Filter_Coefficient;

    /* Sum: '<S62>/Sum' */
    rtb_Sum_g = (rtb_ProportionalGain_a + GRM_HIL_B.Integrator_f) +
      GRM_HIL_B.FilterCoefficient_l;

    /* Logic: '<S61>/Logical Operator1' incorporates:
     *  Constant: '<S61>/Constant'
     */
    GRM_HIL_B.LogicalOperator1_i =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S61>/Switch' incorporates:
   *  Abs: '<S61>/Abs'
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S63>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1_i) {
    GRM_HIL_B.Switch_c = GRM_HIL_P.Constant1_Value_gc;
  } else {
    GRM_HIL_B.Switch_c = (rtb_Sqrt_k >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_soft_limit_vel);
  }

  /* End of Switch: '<S61>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S67>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_m2 =
      GRM_HIL_B.Switch_c;

    /* Outputs for Enabled SubSystem: '<S62>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_m2,
                       GRM_HIL_B.Switch2_k, GRM_HIL_B.Switch1_j, rtb_Sum_g,
                       &GRM_HIL_B.Merge_a, &GRM_HIL_DW.Saturation_h);

    /* End of Outputs for SubSystem: '<S62>/Saturation' */

    /* Logic: '<S62>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_b = !GRM_HIL_B.Switch_c;

    /* Outputs for Enabled SubSystem: '<S62>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_b, rtb_Sum_g,
                 &GRM_HIL_B.Merge_a, &GRM_HIL_DW.pass_c);

    /* End of Outputs for SubSystem: '<S62>/pass' */

    /* Outputs for Enabled SubSystem: '<S44>/Voltage_Limitations' incorporates:
     *  EnablePort: '<S51>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S44>/Constant2' */
      if (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atOutput > 0.0)
      {
        GRM_HIL_DW.Voltage_Limitations_MODE = true;
      } else {
        if (GRM_HIL_DW.Voltage_Limitations_MODE) {
          /* Disable for If: '<S51>/If' */
          GRM_HIL_DW.If_ActiveSubsystem_d = -1;

          /* Disable for If: '<S51>/If1' */
          GRM_HIL_DW.If1_ActiveSubsystem = -1;

          /* Disable for If: '<S51>/If2' */
          GRM_HIL_DW.If2_ActiveSubsystem = -1;
          GRM_HIL_DW.Voltage_Limitations_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S44>/Voltage_Limitations' */
  }

  /* Outputs for Enabled SubSystem: '<S44>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  if (GRM_HIL_DW.Voltage_Limitations_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S51>/Abs1' incorporates:
       *  Constant: '<S51>/max_vel_yaw'
       */
      GRM_HIL_B.Abs1 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV);
    }

    /* If: '<S51>/If' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_Product2_m >= GRM_HIL_B.Abs1);
      GRM_HIL_DW.If_ActiveSubsystem_d = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If_ActiveSubsystem_d;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S51>/If Action limit_yaw' incorporates:
       *  ActionPort: '<S184>/Action Port'
       */
      /* Saturate: '<S184>/Limit_Voltage_Yaw' */
      if (GRM_HIL_B.Merge_f > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt) {
        GRM_HIL_B.Merge_b = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_f <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt) {
        GRM_HIL_B.Merge_b = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge_b = GRM_HIL_B.Merge_f;
      }

      /* End of Saturate: '<S184>/Limit_Voltage_Yaw' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionlimit_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S51>/If Action limit_yaw' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S51>/If Action pass_yaw' incorporates:
       *  ActionPort: '<S187>/Action Port'
       */
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_f, &GRM_HIL_B.Merge_b);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S51>/If Action pass_yaw' */
      break;
    }

    /* End of If: '<S51>/If' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S51>/Abs3' incorporates:
       *  Constant: '<S51>/max_vel_pitch'
       */
      GRM_HIL_B.Abs3 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchMaxV);
    }

    /* If: '<S51>/If1' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_Add1_p >= GRM_HIL_B.Abs3);
      GRM_HIL_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If1_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S51>/If Action limit_pitch' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
      /* Saturate: '<S182>/Limit_Voltage_Pitch' */
      if (GRM_HIL_B.Merge_p > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt)
      {
        GRM_HIL_B.Merge1_f0 = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_p <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt) {
        GRM_HIL_B.Merge1_f0 = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge1_f0 = GRM_HIL_B.Merge_p;
      }

      /* End of Saturate: '<S182>/Limit_Voltage_Pitch' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionlimit_pitch_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S51>/If Action limit_pitch' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S51>/If Action pass_pitch' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_p, &GRM_HIL_B.Merge1_f0);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S51>/If Action pass_pitch' */
      break;
    }

    /* End of If: '<S51>/If1' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S51>/Abs5' incorporates:
       *  Constant: '<S51>/max_vel_roll'
       */
      GRM_HIL_B.Abs5 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollMaxV);
    }

    /* If: '<S51>/If2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_Sqrt_k >= GRM_HIL_B.Abs5);
      GRM_HIL_DW.If2_ActiveSubsystem = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If2_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S51>/If Action limit_roll' incorporates:
       *  ActionPort: '<S183>/Action Port'
       */
      /* Saturate: '<S183>/Limit_Voltage_Roll' */
      if (GRM_HIL_B.Merge_a > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt)
      {
        GRM_HIL_B.Merge2 = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_a <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt) {
        GRM_HIL_B.Merge2 = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge2 = GRM_HIL_B.Merge_a;
      }

      /* End of Saturate: '<S183>/Limit_Voltage_Roll' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionlimit_roll_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S51>/If Action limit_roll' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S51>/If Action pass_roll' incorporates:
       *  ActionPort: '<S186>/Action Port'
       */
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_a, &GRM_HIL_B.Merge2);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_roll.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S51>/If Action pass_roll' */
      break;
    }

    /* End of If: '<S51>/If2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Voltage_Limitations_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S44>/Voltage_Limitations' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Logic: '<S44>/Logical Operator' incorporates:
     *  Constant: '<S44>/Constant2'
     */
    GRM_HIL_B.LogicalOperator_fl =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atOutput != 0.0);

    /* Outputs for Enabled SubSystem: '<S44>/If Action Pass' incorporates:
     *  EnablePort: '<S49>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.IfActionPass_MODE = GRM_HIL_B.LogicalOperator_fl;
    }

    /* End of Outputs for SubSystem: '<S44>/If Action Pass' */
  }

  /* Outputs for Enabled SubSystem: '<S44>/If Action Pass' incorporates:
   *  EnablePort: '<S49>/Enable'
   */
  if (GRM_HIL_DW.IfActionPass_MODE) {
    /* Inport: '<S49>/yaw' */
    GRM_HIL_B.Merge_b = GRM_HIL_B.Merge_f;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Inport: '<S49>/pitch' */
      GRM_HIL_B.Merge1_f0 = GRM_HIL_B.Merge_p;

      /* Inport: '<S49>/roll' */
      GRM_HIL_B.Merge2 = GRM_HIL_B.Merge_a;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionPass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S44>/If Action Pass' */

  /* TransferFcn: '<S38>/Theta2Motor -> Roll' */
  rtb_Gain2_dm = 0.0;
  rtb_Gain2_dm +=
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Roll.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Roll.Denom_Coef *
    GRM_HIL_B.Merge1_f0;

  /* Sum: '<S38>/Sum2' incorporates:
   *  TransferFcn: '<S38>/Phi2Motor -> Roll'
   *  TransferFcn: '<S38>/Psi2Motor -> Roll'
   */
  GRM_HIL_B.Sum2 =
    (GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Roll.Num_Coef /
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Roll.Denom_Coef *
     GRM_HIL_B.Merge_b + rtb_Gain2_dm) +
    ((GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Num_Coef[0] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
      GRM_HIL_X.Phi2MotorRoll_CSTATE[0] +
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Num_Coef[1] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
      GRM_HIL_X.Phi2MotorRoll_CSTATE[1]) +
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Num_Coef[2] /
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
     GRM_HIL_X.Phi2MotorRoll_CSTATE[2]);

  /* Gain: '<S39>/Shaft2radRoll' */
  GRM_HIL_B.ATT_Phi_rad_p = GRM_HIL_P.Shaft2radRoll_Gain * GRM_HIL_B.Sum2;

  /* TransferFcn: '<S38>/Theta2Motor -> Pitch' */
  rtb_Gain2_dm = 0.0;
  for (idx_0 = 0; idx_0 < 5; idx_0++) {
    rtb_Gain2_dm +=
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Pitch.Num_Coef[idx_0]
      / GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Pitch.Denom_Coef[0]
      * GRM_HIL_X.Theta2MotorPitch_CSTATE[idx_0];
  }

  /* End of TransferFcn: '<S38>/Theta2Motor -> Pitch' */

  /* Sum: '<S38>/Sum1' incorporates:
   *  TransferFcn: '<S38>/Phi2Motor -> Pitch'
   *  TransferFcn: '<S38>/Psi2Motor -> Pitch'
   */
  GRM_HIL_B.Sum1 =
    (GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Pitch.Num_Coef /
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Pitch.Denom_Coef *
     GRM_HIL_B.Merge_b + rtb_Gain2_dm) +
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Pitch.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Pitch.Denom_Coef *
    GRM_HIL_B.Merge2;

  /* Gain: '<S39>/Shaft2radPitch' */
  GRM_HIL_B.ATT_Theta_rad_c = GRM_HIL_P.Shaft2radPitch_Gain * GRM_HIL_B.Sum1;

  /* TransferFcn: '<S38>/Theta2Motor -> Yaw' */
  rtb_Gain2_dm = 0.0;
  rtb_Gain2_dm +=
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Yaw.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Yaw.Denom_Coef *
    GRM_HIL_B.Merge1_f0;

  /* Sum: '<S38>/Sum' incorporates:
   *  TransferFcn: '<S38>/Phi2Motor -> Yaw'
   *  TransferFcn: '<S38>/Psi2Motor -> Yaw'
   */
  GRM_HIL_B.Sum =
    ((GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Num_Coef[0] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[0] *
      GRM_HIL_X.Psi2MotorYaw_CSTATE[0] +
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Num_Coef[1] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[0] *
      GRM_HIL_X.Psi2MotorYaw_CSTATE[1]) + rtb_Gain2_dm) +
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Yaw.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Yaw.Denom_Coef *
    GRM_HIL_B.Merge2;

  /* Gain: '<S39>/Shaft2radYaw' */
  GRM_HIL_B.ATT_Psi_rad_h = GRM_HIL_P.Shaft2radYaw_Gain * GRM_HIL_B.Sum;

  /* Gain: '<S42>/1//2' */
  rtb_Product_i[0] = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Psi_rad_h;
  rtb_Product_i[1] = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Theta_rad_c;
  rtb_Product_i[2] = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Phi_rad_p;

  /* Trigonometry: '<S42>/sincos' */
  rtb_ZeroOrderHold[0] = cos(rtb_Product_i[0]);
  rtb_Product_i[0] = sin(rtb_Product_i[0]);
  rtb_ZeroOrderHold[1] = cos(rtb_Product_i[1]);
  rtb_Product_i[1] = sin(rtb_Product_i[1]);
  rtb_ZeroOrderHold[2] = cos(rtb_Product_i[2]);
  rtb_Cx = sin(rtb_Product_i[2]);

  /* Fcn: '<S42>/q0' incorporates:
   *  Fcn: '<S42>/q3'
   */
  q0_tmp = rtb_ZeroOrderHold[0] * rtb_ZeroOrderHold[1];
  rtb_DerivativeGain_j0 = rtb_Product_i[0] * rtb_Product_i[1];
  GRM_HIL_B.q0 = q0_tmp * rtb_ZeroOrderHold[2] - rtb_DerivativeGain_j0 * rtb_Cx;

  /* Fcn: '<S42>/q1' incorporates:
   *  Fcn: '<S42>/q2'
   */
  rtb_ProportionalGain_l = rtb_ZeroOrderHold[0] * rtb_Product_i[1];
  rtb_DerivativeGain_e = rtb_Product_i[0] * rtb_ZeroOrderHold[1];
  GRM_HIL_B.q1 = rtb_ProportionalGain_l * rtb_Cx + rtb_DerivativeGain_e *
    rtb_ZeroOrderHold[2];

  /* Fcn: '<S42>/q2' */
  GRM_HIL_B.q2 = rtb_ProportionalGain_l * rtb_ZeroOrderHold[2] -
    rtb_DerivativeGain_e * rtb_Cx;

  /* Fcn: '<S42>/q3' */
  GRM_HIL_B.q3 = q0_tmp * rtb_Cx + rtb_DerivativeGain_j0 * rtb_ZeroOrderHold[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S40>/Constant' */
    GRM_HIL_B.Data_plus = GRM_HIL_P.Constant_Value_c1;

    /* Constant: '<S40>/Constant1' */
    GRM_HIL_B.Data_minus = GRM_HIL_P.Constant1_Value_bz;

    /* Constant: '<S40>/Constant2' */
    GRM_HIL_B.Clock_plus = GRM_HIL_P.Constant2_Value_jr;

    /* Constant: '<S40>/Constant3' */
    GRM_HIL_B.Clock_minus = GRM_HIL_P.Constant3_Value_h;

    /* Constant: '<S40>/Constant4' */
    GRM_HIL_B.Data_plus_n = GRM_HIL_P.Constant4_Value_c;

    /* Constant: '<S40>/Constant5' */
    GRM_HIL_B.Data_minus_l = GRM_HIL_P.Constant5_Value_j;

    /* Constant: '<S40>/Constant6' */
    GRM_HIL_B.Clock_plus_b = GRM_HIL_P.Constant6_Value_k;

    /* Constant: '<S40>/Constant7' */
    GRM_HIL_B.Clock_minus_b = GRM_HIL_P.Constant7_Value_o;

    /* Constant: '<S40>/Constant8' */
    GRM_HIL_B.Data_plus_nf = GRM_HIL_P.Constant8_Value_kz;

    /* Constant: '<S40>/Constant9' */
    GRM_HIL_B.Data_minus_g = GRM_HIL_P.Constant9_Value_c;

    /* Constant: '<S40>/Constant10' */
    GRM_HIL_B.Clock_plus_g = GRM_HIL_P.Constant10_Value_jg;

    /* Constant: '<S40>/Constant11' */
    GRM_HIL_B.Clock_minus_d = GRM_HIL_P.Constant11_Value_f;

    /* ToAsyncQueueBlock generated from: '<Root>/Gimbal' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_operational_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3581233937U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_Ramp_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2815326209U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_Limit_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2575509423U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Gimbal_StopSim_flg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1882671143U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad_p;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2864846352U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad_c;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2296397721U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3654869859U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1660762U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3530392617U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(360685698U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(264416174U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Sum;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1636319246U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Sum1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2336629595U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Sum2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(43165169U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3414981629U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(907881417U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1479291502U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(170020782U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_n;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3816275064U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3029744459U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_b;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3394260916U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_b;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1624853172U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_plus_nf;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(991454816U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Data_minus_g;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3634553370U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_plus_g;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3023253040U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Clock_minus_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2118052306U, time, pData, size);
      }
    }

    /* Constant: '<S302>/Constant8' */
    GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];
    GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];
    GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];
    GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];
  }

  /* Integrator: '<S302>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_g != 0) {
    GRM_HIL_X.integration_eom_CSTATE_b[0] = GRM_HIL_B.Constant8[0];
    GRM_HIL_X.integration_eom_CSTATE_b[1] = GRM_HIL_B.Constant8[1];
    GRM_HIL_X.integration_eom_CSTATE_b[2] = GRM_HIL_B.Constant8[2];
    GRM_HIL_X.integration_eom_CSTATE_b[3] = GRM_HIL_B.Constant8[3];
  }

  /* Math: '<S306>/Math Function1' incorporates:
   *  Integrator: '<S302>/integration_eom'
   */
  rtb_Gain2_dm = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];

  /* Sum: '<S306>/Add' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Math: '<S306>/Math Function'
   *  Math: '<S306>/Math Function2'
   *  Math: '<S306>/Math Function3'
   */
  rtb_VectorConcatenate3[0] = ((GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0] - rtb_Gain2_dm) -
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[2])
    + GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Product: '<S306>/Product' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S306>/Product6'
   */
  rtb_DerivativeGain_j0 = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];

  /* Product: '<S306>/Product1' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S306>/Product7'
   */
  rtb_ProportionalGain_l = GRM_HIL_X.integration_eom_CSTATE_b[2] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S306>/Add1' incorporates:
   *  Gain: '<S306>/Gain1'
   *  Gain: '<S306>/Gain2'
   *  Product: '<S306>/Product'
   *  Product: '<S306>/Product1'
   */
  rtb_VectorConcatenate3[1] = rtb_DerivativeGain_j0 * GRM_HIL_P.Gain1_Gain_i -
    rtb_ProportionalGain_l * GRM_HIL_P.Gain2_Gain_iy;

  /* Product: '<S306>/Product8' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S306>/Product4'
   */
  rtb_DerivativeGain_e = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S306>/Product9' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S306>/Product5'
   */
  rtb_ProportionalGain_a = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S306>/Add5' incorporates:
   *  Gain: '<S306>/Gain10'
   *  Gain: '<S306>/Gain9'
   *  Product: '<S306>/Product8'
   *  Product: '<S306>/Product9'
   */
  rtb_VectorConcatenate3[2] = rtb_DerivativeGain_e * GRM_HIL_P.Gain9_Gain_g +
    rtb_ProportionalGain_a * GRM_HIL_P.Gain10_Gain_h;

  /* Sum: '<S306>/Add4' incorporates:
   *  Gain: '<S306>/Gain7'
   *  Gain: '<S306>/Gain8'
   */
  rtb_VectorConcatenate3[3] = rtb_DerivativeGain_j0 * GRM_HIL_P.Gain7_Gain_i +
    rtb_ProportionalGain_l * GRM_HIL_P.Gain8_Gain_d;

  /* Math: '<S306>/Math Function5' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Math: '<S306>/Math Function9'
   */
  q0_tmp = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];
  rtb_Gain2_dm = q0_tmp;

  /* Math: '<S306>/Math Function6' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Math: '<S306>/Math Function10'
   */
  rtb_DerivativeGain_j0 = GRM_HIL_X.integration_eom_CSTATE_b[2] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Math: '<S306>/Math Function4' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Math: '<S306>/Math Function8'
   */
  rtb_ProportionalGain_l = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0];

  /* Math: '<S306>/Math Function7' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Math: '<S306>/Math Function11'
   */
  rtb_ProportionalGain = GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S306>/Add6' incorporates:
   *  Math: '<S306>/Math Function4'
   *  Math: '<S306>/Math Function6'
   *  Math: '<S306>/Math Function7'
   */
  rtb_VectorConcatenate3[4] = ((rtb_Gain2_dm - rtb_ProportionalGain_l) -
    rtb_DerivativeGain_j0) + rtb_ProportionalGain;

  /* Product: '<S306>/Product2' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S306>/Product10'
   */
  rtb_DerivativeGain = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S306>/Product3' incorporates:
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S306>/Product11'
   */
  rtb_jxk = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S306>/Add2' incorporates:
   *  Gain: '<S306>/Gain3'
   *  Gain: '<S306>/Gain4'
   *  Product: '<S306>/Product2'
   *  Product: '<S306>/Product3'
   */
  rtb_VectorConcatenate3[5] = rtb_DerivativeGain * GRM_HIL_P.Gain3_Gain_if -
    rtb_jxk * GRM_HIL_P.Gain4_Gain_f;

  /* Sum: '<S306>/Add3' incorporates:
   *  Gain: '<S306>/Gain5'
   *  Gain: '<S306>/Gain6'
   */
  rtb_VectorConcatenate3[6] = rtb_DerivativeGain_e * GRM_HIL_P.Gain5_Gain_i -
    rtb_ProportionalGain_a * GRM_HIL_P.Gain6_Gain_n;

  /* Sum: '<S306>/Add8' incorporates:
   *  Gain: '<S306>/Gain11'
   *  Gain: '<S306>/Gain12'
   */
  rtb_VectorConcatenate3[7] = rtb_DerivativeGain * GRM_HIL_P.Gain11_Gain_n +
    rtb_jxk * GRM_HIL_P.Gain12_Gain_h;

  /* Math: '<S306>/Math Function9' */
  rtb_Gain2_dm = q0_tmp;

  /* Sum: '<S306>/Add7' */
  rtb_VectorConcatenate3[8] = ((rtb_DerivativeGain_j0 - rtb_ProportionalGain_l)
    - rtb_Gain2_dm) + rtb_ProportionalGain;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S301>/Switch' incorporates:
     *  Constant: '<S301>/Constant7'
     *  Constant: '<S301>/Constant9'
     */
    if (GRM_HIL_P.Constant9_Value_p > GRM_HIL_P.Switch_Threshold) {
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant7_Value_i;

      /* SignalConversion generated from: '<S301>/Vector Concatenate' incorporates:
       *  Constant: '<S301>/Constant6'
       *  Constant: '<S301>/Constant7'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant6_Value;

      /* SignalConversion generated from: '<S301>/Vector Concatenate' incorporates:
       *  Constant: '<S301>/Constant6'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant6_Value;
    } else {
      /* SignalConversion generated from: '<S301>/Vector Concatenate1' incorporates:
       *  Constant: '<S301>/Constant8'
       */
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant8_Value;

      /* SignalConversion generated from: '<S301>/Vector Concatenate1' incorporates:
       *  Constant: '<S301>/Constant8'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant8_Value;

      /* SignalConversion generated from: '<S301>/Vector Concatenate1' incorporates:
       *  Constant: '<S301>/Constant8'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant8_Value;
    }

    /* End of Switch: '<S301>/Switch' */
  }

  /* Product: '<S345>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_ZeroOrderHold[i] = rtb_VectorConcatenate3[i + 6] * GRM_HIL_B.wIEE[2] +
      (rtb_VectorConcatenate3[i + 3] * GRM_HIL_B.wIEE[1] +
       rtb_VectorConcatenate3[i] * GRM_HIL_B.wIEE[0]);
  }

  /* End of Product: '<S345>/Product' */

  /* Product: '<S350>/Product3' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_Gain2_dm = rtb_ZeroOrderHold[2] * GRM_HIL_X.integration_eom_CSTATE[1];

  /* Sum: '<S350>/Sum' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Product: '<S350>/Product2'
   */
  rtb_Product_i[0] = rtb_ZeroOrderHold[1] * GRM_HIL_X.integration_eom_CSTATE[2]
    - rtb_Gain2_dm;

  /* Product: '<S350>/Product5' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_Gain2_dm = rtb_ZeroOrderHold[0] * GRM_HIL_X.integration_eom_CSTATE[2];

  /* Sum: '<S350>/Sum1' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Product: '<S350>/Product4'
   */
  rtb_Product_i[1] = rtb_ZeroOrderHold[2] * GRM_HIL_X.integration_eom_CSTATE[0]
    - rtb_Gain2_dm;

  /* Product: '<S350>/Product7' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_Gain2_dm = rtb_ZeroOrderHold[1] * GRM_HIL_X.integration_eom_CSTATE[0];

  /* Sum: '<S345>/Add' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Product: '<S350>/Product6'
   *  Sum: '<S350>/Sum2'
   */
  rtb_Product_i[0] = GRM_HIL_X.integration_eom_CSTATE[3] - rtb_Product_i[0];
  rtb_Product_i[1] = GRM_HIL_X.integration_eom_CSTATE[4] - rtb_Product_i[1];
  rtb_Cx = GRM_HIL_X.integration_eom_CSTATE[5] - (rtb_ZeroOrderHold[0] *
    GRM_HIL_X.integration_eom_CSTATE[1] - rtb_Gain2_dm);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S303>/Constant8' */
    GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];
    GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];
    GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];
    GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];
  }

  /* Integrator: '<S303>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_l != 0) {
    GRM_HIL_X.integration_eom_CSTATE_f[0] = GRM_HIL_B.Constant8_h[0];
    GRM_HIL_X.integration_eom_CSTATE_f[1] = GRM_HIL_B.Constant8_h[1];
    GRM_HIL_X.integration_eom_CSTATE_f[2] = GRM_HIL_B.Constant8_h[2];
    GRM_HIL_X.integration_eom_CSTATE_f[3] = GRM_HIL_B.Constant8_h[3];
  }

  /* Sum: '<S297>/Add' incorporates:
   *  Constant: '<S297>/Q_1'
   *  Constant: '<S297>/Q_2'
   *  Constant: '<S297>/Q_3'
   *  Constant: '<S297>/Q_4'
   *  Integrator: '<S302>/integration_eom'
   *  Product: '<S297>/Product'
   *  Product: '<S297>/Product1'
   *  Product: '<S297>/Product2'
   *  Product: '<S297>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_d[i] * GRM_HIL_X.integration_eom_CSTATE_b[0]
               + GRM_HIL_P.Q_2_Value_nt[i] * GRM_HIL_X.integration_eom_CSTATE_b
               [1]) + GRM_HIL_P.Q_3_Value_o[i] *
              GRM_HIL_X.integration_eom_CSTATE_b[2]) + GRM_HIL_P.Q_4_Value_n[i] *
      GRM_HIL_X.integration_eom_CSTATE_b[3];
  }

  /* End of Sum: '<S297>/Add' */

  /* Product: '<S297>/Product8' incorporates:
   *  Integrator: '<S303>/integration_eom'
   */
  for (i = 0; i < 4; i++) {
    rtb_q_conj_e = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] + (tmp[i
      + 8] * GRM_HIL_X.integration_eom_CSTATE_f[2] + (tmp[i + 4] *
      GRM_HIL_X.integration_eom_CSTATE_f[1] + tmp[i] *
      GRM_HIL_X.integration_eom_CSTATE_f[0]));
    rtb_q_conj[i] = rtb_q_conj_e;
  }

  /* End of Product: '<S297>/Product8' */

  /* Product: '<S300>/Product2' */
  rtb_Gain2_dm = rtb_q_conj[1] * rtb_q_conj[1];

  /* Sum: '<S300>/Add' incorporates:
   *  Product: '<S300>/Product1'
   *  Product: '<S300>/Product3'
   *  Product: '<S300>/Product4'
   */
  rtb_Gain1_c = ((rtb_q_conj[0] * rtb_q_conj[0] + rtb_Gain2_dm) + rtb_q_conj[2] *
                 rtb_q_conj[2]) + rtb_q_conj[3] * rtb_q_conj[3];

  /* Math: '<S300>/Math Function'
   *
   * About '<S300>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Gain1_c < 0.0) {
    rtb_Gain1_c = -sqrt(fabs(rtb_Gain1_c));
  } else {
    rtb_Gain1_c = sqrt(rtb_Gain1_c);
  }

  /* End of Math: '<S300>/Math Function' */

  /* Product: '<S300>/Product' */
  rtb_q_conj[0] /= rtb_Gain1_c;
  rtb_q_conj[1] /= rtb_Gain1_c;
  rtb_q_conj[2] /= rtb_Gain1_c;
  rtb_q_conj_e = rtb_q_conj[3] / rtb_Gain1_c;

  /* Switch: '<S297>/Switch' incorporates:
   *  Constant: '<S297>/Constant'
   *  Constant: '<S297>/Constant1'
   */
  if (rtb_q_conj_e >= GRM_HIL_P.Switch_Threshold_g) {
    rtb_Gain1_c = GRM_HIL_P.Constant_Value_gc;
  } else {
    rtb_Gain1_c = GRM_HIL_P.Constant1_Value_ja;
  }

  /* End of Switch: '<S297>/Switch' */

  /* Product: '<S297>/Product4' */
  rtb_q_conj[0] *= rtb_Gain1_c;
  rtb_q_conj[1] *= rtb_Gain1_c;
  rtb_q_conj[2] *= rtb_Gain1_c;
  rtb_q_conj_e *= rtb_Gain1_c;

  /* Gain: '<S294>/Gain1' */
  rtb_Product4_n[0] = GRM_HIL_P.Gain1_Gain_p * rtb_q_conj[0];
  rtb_Product4_n[1] = GRM_HIL_P.Gain1_Gain_p * rtb_q_conj[1];
  rtb_Product4_n[2] = GRM_HIL_P.Gain1_Gain_p * rtb_q_conj[2];

  /* Sum: '<S295>/Add' incorporates:
   *  Constant: '<S295>/Q_1'
   *  Constant: '<S295>/Q_2'
   *  Constant: '<S295>/Q_3'
   *  Constant: '<S295>/Q_4'
   *  Product: '<S295>/Product'
   *  Product: '<S295>/Product1'
   *  Product: '<S295>/Product2'
   *  Product: '<S295>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_k[i] * rtb_Product4_n[0] +
               GRM_HIL_P.Q_2_Value_c[i] * rtb_Product4_n[1]) +
              GRM_HIL_P.Q_3_Value_f[i] * rtb_Product4_n[2]) +
      GRM_HIL_P.Q_4_Value_e[i] * rtb_q_conj_e;
  }

  /* End of Sum: '<S295>/Add' */

  /* Product: '<S295>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Subtract_cl = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_Product_idx_2 + (tmp[i + 4] * rtb_Product_idx_1 + tmp[i] *
      rtb_Product_idx_0));
    rtb_Product4_n[i] = rtb_Subtract_cl;
  }

  /* End of Product: '<S295>/Product8' */

  /* Product: '<S298>/Product2' */
  rtb_Gain2_dm = rtb_Product4_n[1] * rtb_Product4_n[1];

  /* Sum: '<S298>/Add' incorporates:
   *  Product: '<S298>/Product1'
   *  Product: '<S298>/Product3'
   *  Product: '<S298>/Product4'
   */
  rtb_Gain1_c = ((rtb_Product4_n[0] * rtb_Product4_n[0] + rtb_Gain2_dm) +
                 rtb_Product4_n[2] * rtb_Product4_n[2]) + rtb_Product4_n[3] *
    rtb_Product4_n[3];

  /* Math: '<S298>/Math Function'
   *
   * About '<S298>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Gain1_c < 0.0) {
    rtb_Gain1_c = -sqrt(fabs(rtb_Gain1_c));
  } else {
    rtb_Gain1_c = sqrt(rtb_Gain1_c);
  }

  /* End of Math: '<S298>/Math Function' */

  /* Product: '<S298>/Product' */
  rtb_Product4_n[0] /= rtb_Gain1_c;
  rtb_Product4_n[1] /= rtb_Gain1_c;
  rtb_Product4_n[2] /= rtb_Gain1_c;
  rtb_Subtract_cl = rtb_Product4_n[3] / rtb_Gain1_c;

  /* Switch: '<S295>/Switch' incorporates:
   *  Constant: '<S295>/Constant'
   *  Constant: '<S295>/Constant1'
   */
  if (rtb_Subtract_cl >= GRM_HIL_P.Switch_Threshold_h) {
    rtb_Gain1_c = GRM_HIL_P.Constant_Value_ie;
  } else {
    rtb_Gain1_c = GRM_HIL_P.Constant1_Value_m;
  }

  /* End of Switch: '<S295>/Switch' */

  /* Product: '<S295>/Product4' */
  rtb_Product4_n[0] *= rtb_Gain1_c;
  rtb_Product4_n[1] *= rtb_Gain1_c;
  rtb_Product4_n[2] *= rtb_Gain1_c;
  rtb_Subtract_cl *= rtb_Gain1_c;

  /* Math: '<S293>/Math Function1' incorporates:
   *  Math: '<S293>/Math Function5'
   *  Math: '<S293>/Math Function9'
   */
  q0_tmp = rtb_Product4_n[1] * rtb_Product4_n[1];
  rtb_Gain2_dm = q0_tmp;

  /* Math: '<S293>/Math Function' incorporates:
   *  Math: '<S293>/Math Function4'
   *  Math: '<S293>/Math Function8'
   */
  rtb_DerivativeGain_j0 = rtb_Product4_n[0] * rtb_Product4_n[0];

  /* Math: '<S293>/Math Function2' incorporates:
   *  Math: '<S293>/Math Function10'
   *  Math: '<S293>/Math Function6'
   */
  rtb_ProportionalGain_l = rtb_Product4_n[2] * rtb_Product4_n[2];

  /* Math: '<S293>/Math Function3' incorporates:
   *  Math: '<S293>/Math Function11'
   *  Math: '<S293>/Math Function7'
   */
  rtb_DerivativeGain_e = rtb_Subtract_cl * rtb_Subtract_cl;

  /* Sum: '<S293>/Add' incorporates:
   *  Math: '<S293>/Math Function'
   *  Math: '<S293>/Math Function2'
   *  Math: '<S293>/Math Function3'
   */
  rtb_TBG[0] = ((rtb_DerivativeGain_j0 - rtb_Gain2_dm) - rtb_ProportionalGain_l)
    + rtb_DerivativeGain_e;

  /* Product: '<S293>/Product' incorporates:
   *  Product: '<S293>/Product6'
   */
  rtb_ProportionalGain_a = rtb_Product4_n[0] * rtb_Product4_n[1];

  /* Product: '<S293>/Product1' incorporates:
   *  Product: '<S293>/Product7'
   */
  rtb_ProportionalGain = rtb_Product4_n[2] * rtb_Subtract_cl;

  /* Sum: '<S293>/Add1' incorporates:
   *  Gain: '<S293>/Gain1'
   *  Gain: '<S293>/Gain2'
   *  Product: '<S293>/Product'
   *  Product: '<S293>/Product1'
   */
  rtb_TBG[1] = rtb_ProportionalGain_a * GRM_HIL_P.Gain1_Gain_e -
    rtb_ProportionalGain * GRM_HIL_P.Gain2_Gain_j;

  /* Product: '<S293>/Product8' incorporates:
   *  Product: '<S293>/Product4'
   */
  rtb_DerivativeGain = rtb_Product4_n[0] * rtb_Product4_n[2];

  /* Product: '<S293>/Product9' incorporates:
   *  Product: '<S293>/Product5'
   */
  rtb_jxk = rtb_Product4_n[1] * rtb_Subtract_cl;

  /* Sum: '<S293>/Add5' incorporates:
   *  Gain: '<S293>/Gain10'
   *  Gain: '<S293>/Gain9'
   *  Product: '<S293>/Product8'
   *  Product: '<S293>/Product9'
   */
  rtb_TBG[2] = rtb_DerivativeGain * GRM_HIL_P.Gain9_Gain_m + rtb_jxk *
    GRM_HIL_P.Gain10_Gain_d;

  /* Sum: '<S293>/Add4' incorporates:
   *  Gain: '<S293>/Gain7'
   *  Gain: '<S293>/Gain8'
   */
  rtb_TBG[3] = rtb_ProportionalGain_a * GRM_HIL_P.Gain7_Gain_h +
    rtb_ProportionalGain * GRM_HIL_P.Gain8_Gain_l;

  /* Math: '<S293>/Math Function5' */
  rtb_Gain2_dm = q0_tmp;

  /* Sum: '<S293>/Add6' */
  rtb_TBG[4] = ((rtb_Gain2_dm - rtb_DerivativeGain_j0) - rtb_ProportionalGain_l)
    + rtb_DerivativeGain_e;

  /* Product: '<S293>/Product2' incorporates:
   *  Product: '<S293>/Product10'
   */
  rtb_ProportionalGain_a = rtb_Product4_n[1] * rtb_Product4_n[2];

  /* Product: '<S293>/Product3' incorporates:
   *  Product: '<S293>/Product11'
   */
  rtb_ProportionalGain = rtb_Product4_n[0] * rtb_Subtract_cl;

  /* Sum: '<S293>/Add2' incorporates:
   *  Gain: '<S293>/Gain3'
   *  Gain: '<S293>/Gain4'
   *  Product: '<S293>/Product2'
   *  Product: '<S293>/Product3'
   */
  rtb_TBG[5] = rtb_ProportionalGain_a * GRM_HIL_P.Gain3_Gain_e -
    rtb_ProportionalGain * GRM_HIL_P.Gain4_Gain_c;

  /* Sum: '<S293>/Add3' incorporates:
   *  Gain: '<S293>/Gain5'
   *  Gain: '<S293>/Gain6'
   */
  rtb_TBG[6] = rtb_DerivativeGain * GRM_HIL_P.Gain5_Gain_c - rtb_jxk *
    GRM_HIL_P.Gain6_Gain_b;

  /* Sum: '<S293>/Add8' incorporates:
   *  Gain: '<S293>/Gain11'
   *  Gain: '<S293>/Gain12'
   */
  rtb_TBG[7] = rtb_ProportionalGain_a * GRM_HIL_P.Gain11_Gain_g +
    rtb_ProportionalGain * GRM_HIL_P.Gain12_Gain_j;

  /* Math: '<S293>/Math Function9' */
  rtb_Gain2_dm = q0_tmp;

  /* Sum: '<S293>/Add7' */
  rtb_TBG[8] = ((rtb_ProportionalGain_l - rtb_DerivativeGain_j0) - rtb_Gain2_dm)
    + rtb_DerivativeGain_e;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S353>/Add' incorporates:
     *  Constant: '<S353>/course_angle_uncertainty'
     *  Constant: '<S353>/course_angle_wind'
     */
    rtb_jxk = GRM_HIL_P.course_angle_wind_Value +
      GRM_HIL_P.course_angle_uncertainty_Value;

    /* MultiPortSwitch: '<S355>/Multiport Switch' incorporates:
     *  Constant: '<S355>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1) {
     case 1:
      /* Trigonometry: '<S356>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S356>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(rtb_jxk);

      /* Trigonometry: '<S356>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S356>/Trigonometric Function'
       */
      rtb_Subtract_cl = cos(rtb_jxk);

      /* SignalConversion generated from: '<S356>/Matrix Concatenate' incorporates:
       *  Constant: '<S356>/Constant7'
       *  Trigonometry: '<S356>/Trigonometric Function1'
       *  Trigonometry: '<S356>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_j;
      rtb_MultiportSwitch[7] = rtb_Gain1_c;
      rtb_MultiportSwitch[8] = rtb_Subtract_cl;

      /* SignalConversion generated from: '<S356>/Matrix Concatenate' incorporates:
       *  Constant: '<S356>/Constant8'
       *  Gain: '<S356>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_af;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_kj * rtb_Gain1_c;

      /* SignalConversion generated from: '<S356>/Matrix Concatenate' incorporates:
       *  Constant: '<S356>/Constant'
       *  Constant: '<S356>/Constant1'
       *  Constant: '<S356>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_b;
      break;

     case 2:
      /* Trigonometry: '<S357>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S357>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(rtb_jxk);

      /* Trigonometry: '<S357>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S357>/Trigonometric Function2'
       */
      rtb_Subtract_cl = sin(rtb_jxk);

      /* SignalConversion generated from: '<S357>/Matrix Concatenate' incorporates:
       *  Constant: '<S357>/Constant7'
       *  Gain: '<S357>/Gain1'
       *  Trigonometry: '<S357>/Trigonometric Function1'
       *  Trigonometry: '<S357>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_j * rtb_Subtract_cl;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_d1;
      rtb_MultiportSwitch[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S357>/Matrix Concatenate' incorporates:
       *  Constant: '<S357>/Constant'
       *  Constant: '<S357>/Constant1'
       *  Constant: '<S357>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ob;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_i;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_g;

      /* SignalConversion generated from: '<S357>/Matrix Concatenate' incorporates:
       *  Constant: '<S357>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_Gain1_c;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_ky;
      rtb_MultiportSwitch[2] = rtb_Subtract_cl;
      break;

     default:
      /* SignalConversion generated from: '<S358>/Matrix Concatenate' incorporates:
       *  Constant: '<S358>/Constant10'
       *  Constant: '<S358>/Constant11'
       *  Constant: '<S358>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_o;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_d;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_a;

      /* Trigonometry: '<S358>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S358>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(rtb_jxk);

      /* Trigonometry: '<S358>/Trigonometric Function' incorporates:
       *  Trigonometry: '<S358>/Trigonometric Function3'
       */
      rtb_Subtract_cl = cos(rtb_jxk);

      /* SignalConversion generated from: '<S358>/Matrix Concatenate' incorporates:
       *  Constant: '<S358>/Constant7'
       *  Trigonometry: '<S358>/Trigonometric Function'
       *  Trigonometry: '<S358>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_Gain1_c;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_g;

      /* SignalConversion generated from: '<S358>/Matrix Concatenate' incorporates:
       *  Constant: '<S358>/Constant8'
       *  Gain: '<S358>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Subtract_cl;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_jn * rtb_Gain1_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gg;
      break;
    }

    /* End of MultiPortSwitch: '<S355>/Multiport Switch' */

    /* Sum: '<S353>/Add1' incorporates:
     *  Constant: '<S353>/vWW'
     *  Constant: '<S353>/vWW_uncertainty'
     */
    rtb_VectorConcatenate_hm[0] = GRM_HIL_P.vWW_uncertainty_Value +
      GRM_HIL_P.vWW_Value;

    /* Product: '<S354>/Product' incorporates:
     *  Constant: '<S353>/Constant1'
     */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.vec2[i] = 0.0;
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i] * rtb_VectorConcatenate_hm[0];
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i + 3] *
        GRM_HIL_P.Constant1_Value_fr;
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i + 6] *
        GRM_HIL_P.Constant1_Value_fr;
    }

    /* End of Product: '<S354>/Product' */
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S343>/Math Function1' incorporates:
     *  Math: '<S200>/Math Function'
     */
    rtb_vBEB_a_tmp[3 * i] = rtb_TBG[i];
    rtb_vBEB_a_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_vBEB_a_tmp[3 * i + 2] = rtb_TBG[i + 6];

    /* Product: '<S343>/Product' */
    rtb_pBEE[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_Cx +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_Product_i[1] +
       rtb_MatrixMultiply_tmp[i] * rtb_Product_i[0]);
  }

  /* DotProduct: '<S348>/Dot Product1' */
  rtb_ProportionalGain_l = 0.0;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S344>/Subtract' incorporates:
     *  Math: '<S343>/Math Function1'
     *  Product: '<S343>/Product1'
     */
    q0_tmp = rtb_pBEE[i] - (rtb_vBEB_a_tmp[i + 6] * GRM_HIL_B.vec2[2] +
      (rtb_vBEB_a_tmp[i + 3] * GRM_HIL_B.vec2[1] + rtb_vBEB_a_tmp[i] *
       GRM_HIL_B.vec2[0]));

    /* DotProduct: '<S348>/Dot Product1' */
    rtb_ProportionalGain_l += q0_tmp * q0_tmp;

    /* Sum: '<S344>/Subtract' */
    rtb_vBEB_a[i] = q0_tmp;
  }

  /* Math: '<S348>/Math Function1' incorporates:
   *  DotProduct: '<S348>/Dot Product1'
   *
   * About '<S348>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_ProportionalGain_l < 0.0) {
    rtb_Gain1_c = -sqrt(fabs(rtb_ProportionalGain_l));
  } else {
    rtb_Gain1_c = sqrt(rtb_ProportionalGain_l);
  }

  /* End of Math: '<S348>/Math Function1' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S267>/Subtract1' incorporates:
     *  Constant: '<S267>/Tmp_norm_msl'
     *  Constant: '<S352>/deviation_Tmp'
     */
    GRM_HIL_B.Tmp_ref = GRM_HIL_P.deviation_Tmp_Value +
      GRM_HIL_P.Tmp_norm_msl_Value;

    /* Constant: '<S328>/Constant' */
    GRM_HIL_B.VectorConcatenate1[0] = GRM_HIL_P.Constant_Value_b;

    /* Constant: '<S328>/Constant2' */
    GRM_HIL_B.VectorConcatenate1[1] = GRM_HIL_P.Constant2_Value_e5;

    /* Product: '<S332>/Product' incorporates:
     *  Constant: '<S330>/c_flat'
     *  Constant: '<S330>/c_rsma'
     *  Constant: '<S332>/Constant'
     *  Sum: '<S332>/Subtract'
     */
    GRM_HIL_B.Product_m = (GRM_HIL_P.Constant_Value_ne -
      GRM_HIL_P.c_flat_Value_e) * GRM_HIL_P.c_rsma_Value_j;

    /* Product: '<S332>/Product5' */
    rtb_Switch1 = GRM_HIL_B.Product_m * GRM_HIL_B.Product_m;

    /* Product: '<S332>/Divide' incorporates:
     *  Constant: '<S330>/c_rsma'
     *  Product: '<S332>/Product4'
     *  Sum: '<S332>/Subtract2'
     */
    GRM_HIL_B.Divide = (GRM_HIL_P.c_rsma_Value_j * GRM_HIL_P.c_rsma_Value_j -
                        rtb_Switch1) / rtb_Switch1;

    /* Product: '<S332>/Product3' incorporates:
     *  Constant: '<S330>/c_flat'
     *  Product: '<S331>/Product3'
     */
    q0_tmp = GRM_HIL_P.c_flat_Value_e * GRM_HIL_P.c_flat_Value_e;

    /* Sum: '<S332>/Subtract1' incorporates:
     *  Constant: '<S330>/c_flat'
     *  Gain: '<S332>/Gain'
     *  Product: '<S332>/Product3'
     */
    GRM_HIL_B.Subtract1 = GRM_HIL_P.Gain_Gain_le * GRM_HIL_P.c_flat_Value_e -
      q0_tmp;

    /* Sum: '<S331>/Subtract' incorporates:
     *  Constant: '<S330>/c_flat'
     *  Gain: '<S331>/Gain'
     */
    GRM_HIL_B.Subtract = GRM_HIL_P.Gain_Gain_iy * GRM_HIL_P.c_flat_Value_e -
      q0_tmp;
  }

  /* Switch: '<S328>/Switch' incorporates:
   *  Constant: '<S328>/Constant1'
   */
  if (GRM_HIL_P.Constant1_Value_bt > GRM_HIL_P.Switch_Threshold_c) {
    /* Gain: '<S328>/Gain' incorporates:
     *  Integrator: '<S334>/integration_eom'
     */
    GRM_HIL_B.VectorConcatenate1[2] = GRM_HIL_P.Gain_Gain_p *
      GRM_HIL_X.integration_eom_CSTATE[2];
    GRM_HIL_B.Switch[0] = GRM_HIL_B.VectorConcatenate1[0];
    GRM_HIL_B.Switch[1] = GRM_HIL_B.VectorConcatenate1[1];
    GRM_HIL_B.Switch[2] = GRM_HIL_B.VectorConcatenate1[2];
  } else {
    /* Product: '<S328>/Product' incorporates:
     *  Integrator: '<S334>/integration_eom'
     *  Math: '<S328>/Math Function'
     */
    for (i = 0; i < 3; i++) {
      rtb_pBEE[i] = rtb_VectorConcatenate3[3 * i + 2] *
        GRM_HIL_X.integration_eom_CSTATE[2] + (rtb_VectorConcatenate3[3 * i + 1]
        * GRM_HIL_X.integration_eom_CSTATE[1] + rtb_VectorConcatenate3[3 * i] *
        GRM_HIL_X.integration_eom_CSTATE[0]);
    }

    /* End of Product: '<S328>/Product' */

    /* Sqrt: '<S332>/Sqrt' incorporates:
     *  Product: '<S332>/Product1'
     *  Product: '<S332>/Product2'
     *  Sqrt: '<S331>/Sqrt'
     *  Sum: '<S332>/Add'
     */
    rtb_jxk = sqrt(rtb_pBEE[0] * rtb_pBEE[0] + rtb_pBEE[1] * rtb_pBEE[1]);

    /* Trigonometry: '<S332>/Trigonometric Function' incorporates:
     *  Constant: '<S330>/c_rsma'
     *  Product: '<S332>/Divide1'
     *  Product: '<S332>/Product6'
     *  Product: '<S332>/Product7'
     *  Sqrt: '<S332>/Sqrt'
     */
    rtb_DerivativeGain_j0 = atan(rtb_pBEE[2] * GRM_HIL_P.c_rsma_Value_j /
      (rtb_jxk * GRM_HIL_B.Product_m));

    /* Trigonometry: '<S332>/Trigonometric Function3' */
    rtb_ProportionalGain_a = cos(rtb_DerivativeGain_j0);

    /* Trigonometry: '<S332>/Trigonometric Function2' */
    rtb_DerivativeGain_j0 = sin(rtb_DerivativeGain_j0);

    /* Trigonometry: '<S332>/Trigonometric Function1' incorporates:
     *  Constant: '<S330>/c_rsma'
     *  Product: '<S332>/Divide2'
     *  Product: '<S332>/Product10'
     *  Product: '<S332>/Product11'
     *  Product: '<S332>/Product8'
     *  Product: '<S332>/Product9'
     *  Sqrt: '<S332>/Sqrt'
     *  Sum: '<S332>/Add1'
     *  Sum: '<S332>/Subtract3'
     */
    rtb_ProportionalGain_a = atan((rtb_DerivativeGain_j0 * rtb_DerivativeGain_j0
      * rtb_DerivativeGain_j0 * (GRM_HIL_B.Divide * GRM_HIL_B.Product_m) +
      rtb_pBEE[2]) / (rtb_jxk - rtb_ProportionalGain_a * rtb_ProportionalGain_a *
                      rtb_ProportionalGain_a * (GRM_HIL_B.Subtract1 *
      GRM_HIL_P.c_rsma_Value_j)));

    /* Trigonometry: '<S331>/Trigonometric Function' */
    rtb_DerivativeGain_j0 = sin(rtb_ProportionalGain_a);

    /* Sqrt: '<S331>/Sqrt1' incorporates:
     *  Constant: '<S331>/Constant'
     *  Product: '<S331>/Product5'
     *  Sum: '<S331>/Subtract1'
     */
    rtb_DerivativeGain_j0 = sqrt(GRM_HIL_P.Constant_Value_nr -
      rtb_DerivativeGain_j0 * rtb_DerivativeGain_j0 * GRM_HIL_B.Subtract);

    /* Sum: '<S331>/Sum' incorporates:
     *  Constant: '<S330>/c_rsma'
     *  Product: '<S331>/Product'
     *  Product: '<S331>/Product4'
     *  Trigonometry: '<S331>/cos(latGD)'
     */
    GRM_HIL_B.Switch[2] = rtb_jxk / cos(rtb_ProportionalGain_a) -
      GRM_HIL_P.c_rsma_Value_j / rtb_DerivativeGain_j0;

    /* SignalConversion generated from: '<S328>/Vector Concatenate' */
    GRM_HIL_B.Switch[1] = rtb_ProportionalGain_a;

    /* Trigonometry: '<S330>/Trigonometric Function1' */
    GRM_HIL_B.Switch[0] = rt_atan2d_snf(rtb_pBEE[1], rtb_pBEE[0]);
  }

  /* End of Switch: '<S328>/Switch' */

  /* Sum: '<S265>/Add' incorporates:
   *  Constant: '<S265>/mean_earth_radius'
   */
  rtb_Gain2_dm = GRM_HIL_B.Switch[2] + GRM_HIL_P.geopot_height_mean_earth_radius;

  /* Product: '<S265>/Divide' incorporates:
   *  Constant: '<S265>/mean_earth_radius'
   */
  rtb_Gain2_dm = GRM_HIL_B.Switch[2] / rtb_Gain2_dm *
    GRM_HIL_P.geopot_height_mean_earth_radius;

  /* Saturate: '<S255>/Saturation' */
  if (rtb_Gain2_dm > GRM_HIL_P.Saturation_UpperSat_h) {
    rtb_Gain2_dm = GRM_HIL_P.Saturation_UpperSat_h;
  } else {
    if (rtb_Gain2_dm < GRM_HIL_P.Saturation_LowerSat_kz) {
      rtb_Gain2_dm = GRM_HIL_P.Saturation_LowerSat_kz;
    }
  }

  /* End of Saturate: '<S255>/Saturation' */

  /* Sum: '<S268>/Subtract' incorporates:
   *  Constant: '<S267>/geopotential_height_ref'
   *  Sum: '<S269>/Subtract'
   */
  q0_tmp = rtb_Gain2_dm - GRM_HIL_P.geopotential_height_ref_Value;

  /* Sum: '<S268>/Add' incorporates:
   *  Constant: '<S268>/Tmp_gradient_tropo'
   *  Product: '<S268>/Product'
   *  Sum: '<S268>/Subtract'
   */
  rtb_Abs_n = q0_tmp * GRM_HIL_P.Tmp_gradient_tropo_Value + GRM_HIL_B.Tmp_ref;

  /* PreLookup: '<S240>/Prelookup_Mach' incorporates:
   *  Constant: '<S266>/heat_capacity_ratio'
   *  Constant: '<S266>/specific_gas_constant'
   *  Product: '<S266>/Product'
   *  Product: '<S344>/Divide'
   *  Sqrt: '<S266>/Sqrt'
   */
  rtb_k_Mach = plook_binc(rtb_Gain1_c / sqrt
    (GRM_HIL_P.specific_gas_constant_Value * GRM_HIL_P.heat_capacity_ratio_Value
     * rtb_Abs_n), GRM_HIL_P.Prelookup_Mach_BreakpointsData, 8U,
    &rtb_DerivativeGain_j0);

  /* DotProduct: '<S349>/Dot Product1' */
  rtb_ProportionalGain_l = (rtb_vBEB_a[0] * rtb_vBEB_a[0] + rtb_vBEB_a[1] *
    rtb_vBEB_a[1]) + rtb_vBEB_a[2] * rtb_vBEB_a[2];

  /* Math: '<S349>/Math Function1' incorporates:
   *  DotProduct: '<S349>/Dot Product1'
   *
   * About '<S349>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_ProportionalGain_l < 0.0) {
    rtb_jxk = -sqrt(fabs(rtb_ProportionalGain_l));
  } else {
    rtb_jxk = sqrt(rtb_ProportionalGain_l);
  }

  /* End of Math: '<S349>/Math Function1' */

  /* Switch: '<S346>/Switch' incorporates:
   *  Constant: '<S346>/Constant'
   */
  if (rtb_jxk != 0.0) {
    /* SignalConversion generated from: '<S346>/Vector Concatenate' */
    rtb_q_conj[3] = rtb_jxk;

    /* SignalConversion generated from: '<S346>/Vector Concatenate' */
    rtb_q_conj[2] = rtb_vBEB_a[2];

    /* SignalConversion generated from: '<S346>/Vector Concatenate' */
    rtb_q_conj[1] = rtb_vBEB_a[1];

    /* SignalConversion generated from: '<S346>/Vector Concatenate' */
    rtb_q_conj[0] = rtb_vBEB_a[0];
  } else {
    rtb_q_conj[0] = GRM_HIL_P.Constant_Value_jc[0];
    rtb_q_conj[1] = GRM_HIL_P.Constant_Value_jc[1];
    rtb_q_conj[2] = GRM_HIL_P.Constant_Value_jc[2];
    rtb_q_conj[3] = GRM_HIL_P.Constant_Value_jc[3];
  }

  /* End of Switch: '<S346>/Switch' */

  /* Gain: '<S245>/Gain' incorporates:
   *  Trigonometry: '<S346>/Trigonometric Function'
   */
  rtb_Subtract_cl = GRM_HIL_P.Gain_Gain_nn * rt_atan2d_snf(rtb_q_conj[2],
    rtb_q_conj[0]);

  /* PreLookup: '<S240>/Prelookup_alB' */
  rtb_k_alB = plook_binc(rtb_Subtract_cl,
    GRM_HIL_P.Prelookup_alB_BreakpointsData, 16U, &rtb_ProportionalGain_l);

  /* Product: '<S346>/Divide' */
  u0 = rtb_q_conj[1] / rtb_q_conj[3];

  /* Trigonometry: '<S346>/Trigonometric Function1' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Gain: '<S246>/Gain' incorporates:
   *  Trigonometry: '<S346>/Trigonometric Function1'
   */
  rtb_Subtract_ju = GRM_HIL_P.Gain_Gain_kz * asin(u0);

  /* PreLookup: '<S240>/Prelookup_beB' */
  rtb_k_beB = plook_binc(rtb_Subtract_ju,
    GRM_HIL_P.Prelookup_beB_BreakpointsData, 16U, &rtb_DerivativeGain_e);

  /* Interpolation_n-D: '<S237>/Cx_Interpolation' */
  frac[0] = rtb_DerivativeGain_j0;
  frac[1] = rtb_ProportionalGain_l;
  frac[2] = rtb_DerivativeGain_e;
  bpIndex[0] = rtb_k_Mach;
  bpIndex[1] = rtb_k_alB;
  bpIndex[2] = rtb_k_beB;
  rtb_jxi = intrp3d_l_pw(bpIndex, frac, GRM_HIL_P.Cx_Interpolation_Table,
    GRM_HIL_P.Cx_Interpolation_dimSize);

  /* Product: '<S237>/Product' incorporates:
   *  Constant: '<S237>/Constant'
   */
  rtb_Cx = GRM_HIL_P.Constant_Value_i3 * rtb_jxi;

  /* Saturate: '<S347>/Saturation1' */
  if (rtb_Gain1_c > GRM_HIL_P.Saturation1_UpperSat) {
    rtb_ProportionalGain_a = GRM_HIL_P.Saturation1_UpperSat;
  } else if (rtb_Gain1_c < GRM_HIL_P.Saturation1_LowerSat) {
    rtb_ProportionalGain_a = GRM_HIL_P.Saturation1_LowerSat;
  } else {
    rtb_ProportionalGain_a = rtb_Gain1_c;
  }

  /* End of Saturate: '<S347>/Saturation1' */

  /* Product: '<S347>/Divide1' incorporates:
   *  Constant: '<S347>/Constant1'
   */
  rtb_jxi = 1.0 / rtb_ProportionalGain_a * GRM_HIL_P.Constant1_Value_is;

  /* Product: '<S347>/Product3' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_ZeroOrderHold[1] = rtb_jxi * GRM_HIL_X.integration_eom_CSTATE[11];

  /* Product: '<S347>/Product4' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  rtb_ZeroOrderHold[2] = rtb_jxi * GRM_HIL_X.integration_eom_CSTATE[12];

  /* Gain: '<S250>/Gain' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Product: '<S347>/Product2'
   */
  rtb_Add3 = rtb_jxi * GRM_HIL_X.integration_eom_CSTATE[10] *
    GRM_HIL_P.Gain_Gain_b;

  /* Interpolation_n-D: '<S237>/Cxp_Interpolation' */
  frac_0[0] = rtb_DerivativeGain_j0;
  frac_0[1] = rtb_ProportionalGain_l;
  frac_0[2] = rtb_DerivativeGain_e;
  bpIndex_0[0] = rtb_k_Mach;
  bpIndex_0[1] = rtb_k_alB;
  bpIndex_0[2] = rtb_k_beB;
  rtb_jxi = intrp3d_l_pw(bpIndex_0, frac_0, GRM_HIL_P.Cxp_Interpolation_Table,
    GRM_HIL_P.Cxp_Interpolation_dimSize);

  /* Product: '<S217>/Product' */
  rtb_Product_l = rtb_Add3 * rtb_jxi;

  /* Gain: '<S251>/Gain' */
  rtb_ProportionalGain = GRM_HIL_P.Gain_Gain_hp * rtb_ZeroOrderHold[1];

  /* Interpolation_n-D: '<S237>/Cxq_Interpolation' */
  frac_1[0] = rtb_DerivativeGain_j0;
  frac_1[1] = rtb_ProportionalGain_l;
  frac_1[2] = rtb_DerivativeGain_e;
  bpIndex_1[0] = rtb_k_Mach;
  bpIndex_1[1] = rtb_k_alB;
  bpIndex_1[2] = rtb_k_beB;
  rtb_jxi = intrp3d_l_pw(bpIndex_1, frac_1, GRM_HIL_P.Cxq_Interpolation_Table,
    GRM_HIL_P.Cxq_Interpolation_dimSize);

  /* Product: '<S217>/Product1' */
  rtb_Product1 = rtb_ProportionalGain * rtb_jxi;

  /* Gain: '<S252>/Gain' */
  rtb_DerivativeGain = GRM_HIL_P.Gain_Gain_bz * rtb_ZeroOrderHold[2];

  /* Interpolation_n-D: '<S237>/Cxr_Interpolation' */
  frac_2[0] = rtb_DerivativeGain_j0;
  frac_2[1] = rtb_ProportionalGain_l;
  frac_2[2] = rtb_DerivativeGain_e;
  bpIndex_2[0] = rtb_k_Mach;
  bpIndex_2[1] = rtb_k_alB;
  bpIndex_2[2] = rtb_k_beB;
  rtb_jxi = intrp3d_l_pw(bpIndex_2, frac_2, GRM_HIL_P.Cxr_Interpolation_Table,
    GRM_HIL_P.Cxr_Interpolation_dimSize);

  /* Integrator: '<S270>/Integrator1' */
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
    /* Signum: '<S270>/Sign' incorporates:
     *  Constant: '<S199>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_q_conj_e = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_q_conj_e = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_q_conj_e = 0.0;
    } else {
      rtb_q_conj_e = (rtNaN);
    }

    /* End of Signum: '<S270>/Sign' */

    /* Gain: '<S270>/Gain3' */
    GRM_HIL_B.Gain3 = GRM_HIL_P.Rudder_unc_bl * rtb_q_conj_e;
  }

  /* Sum: '<S270>/Add2' incorporates:
   *  Constant: '<S270>/Constant'
   *  Gain: '<S270>/Gain1'
   *  Integrator: '<S270>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder_unc_scale * GRM_HIL_X.Integrator1_CSTATE +
        GRM_HIL_P.Rudder_unc_off) + GRM_HIL_B.Gain3;

  /* Saturate: '<S270>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder_siB_max) {
    rtb_siB = GRM_HIL_P.Rudder_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder_siB_min) {
    rtb_siB = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_siB = u0;
  }

  /* End of Saturate: '<S270>/Saturation1' */

  /* Integrator: '<S271>/Integrator1' */
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
    /* Signum: '<S271>/Sign' incorporates:
     *  Constant: '<S199>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_q_conj_e = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_q_conj_e = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_q_conj_e = 0.0;
    } else {
      rtb_q_conj_e = (rtNaN);
    }

    /* End of Signum: '<S271>/Sign' */

    /* Gain: '<S271>/Gain3' */
    GRM_HIL_B.Gain3_m = GRM_HIL_P.Rudder1_unc_bl * rtb_q_conj_e;
  }

  /* Sum: '<S271>/Add2' incorporates:
   *  Constant: '<S271>/Constant'
   *  Gain: '<S271>/Gain1'
   *  Integrator: '<S271>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder1_unc_scale * GRM_HIL_X.Integrator1_CSTATE_g +
        GRM_HIL_P.Rudder1_unc_off) + GRM_HIL_B.Gain3_m;

  /* Saturate: '<S271>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder1_siB_max) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder1_siB_min) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_siB_d = u0;
  }

  /* End of Saturate: '<S271>/Saturation1' */

  /* Integrator: '<S272>/Integrator1' */
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
    /* Signum: '<S272>/Sign' incorporates:
     *  Constant: '<S199>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_q_conj_e = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_q_conj_e = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_q_conj_e = 0.0;
    } else {
      rtb_q_conj_e = (rtNaN);
    }

    /* End of Signum: '<S272>/Sign' */

    /* Gain: '<S272>/Gain3' */
    GRM_HIL_B.Gain3_b = GRM_HIL_P.Rudder2_unc_bl * rtb_q_conj_e;
  }

  /* Sum: '<S272>/Add2' incorporates:
   *  Constant: '<S272>/Constant'
   *  Gain: '<S272>/Gain1'
   *  Integrator: '<S272>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder2_unc_scale * GRM_HIL_X.Integrator1_CSTATE_a +
        GRM_HIL_P.Rudder2_unc_off) + GRM_HIL_B.Gain3_b;

  /* Saturate: '<S272>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder2_siB_max) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder2_siB_min) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_siB_i = u0;
  }

  /* End of Saturate: '<S272>/Saturation1' */

  /* Integrator: '<S273>/Integrator1' */
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
    /* Signum: '<S273>/Sign' incorporates:
     *  Constant: '<S199>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_q_conj_e = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_q_conj_e = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_q_conj_e = 0.0;
    } else {
      rtb_q_conj_e = (rtNaN);
    }

    /* End of Signum: '<S273>/Sign' */

    /* Gain: '<S273>/Gain3' */
    GRM_HIL_B.Gain3_h = GRM_HIL_P.Rudder3_unc_bl * rtb_q_conj_e;
  }

  /* Sum: '<S273>/Add2' incorporates:
   *  Constant: '<S273>/Constant'
   *  Gain: '<S273>/Gain1'
   *  Integrator: '<S273>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder3_unc_scale * GRM_HIL_X.Integrator1_CSTATE_i +
        GRM_HIL_P.Rudder3_unc_off) + GRM_HIL_B.Gain3_h;

  /* Saturate: '<S273>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder3_siB_max) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder3_siB_min) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_min;
  } else {
    rtb_siB_o = u0;
  }

  /* End of Saturate: '<S273>/Saturation1' */

  /* Product: '<S274>/Product' incorporates:
   *  Constant: '<S274>/Constant8'
   *  SignalConversion generated from: '<S199>/Vector Concatenate1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add1 = GRM_HIL_P.Constant8_Value_g2[i + 9] * rtb_siB_o +
      (GRM_HIL_P.Constant8_Value_g2[i + 6] * rtb_siB_i +
       (GRM_HIL_P.Constant8_Value_g2[i + 3] * rtb_siB_d +
        GRM_HIL_P.Constant8_Value_g2[i] * rtb_siB));
    rtb_ZeroOrderHold[i] = rtb_Add1;
  }

  /* End of Product: '<S274>/Product' */

  /* Gain: '<S247>/Gain' */
  rtb_Add1 = GRM_HIL_P.Gain_Gain_aj * rtb_ZeroOrderHold[0];

  /* Interpolation_n-D: '<S237>/Cx_delta_l_Interpolation' */
  frac_3[0] = rtb_DerivativeGain_j0;
  frac_3[1] = rtb_ProportionalGain_l;
  frac_3[2] = rtb_DerivativeGain_e;
  bpIndex_3[0] = rtb_k_Mach;
  bpIndex_3[1] = rtb_k_alB;
  bpIndex_3[2] = rtb_k_beB;
  rtb_Cy = intrp3d_l_pw(bpIndex_3, frac_3,
                        GRM_HIL_P.Cx_delta_l_Interpolation_Table,
                        GRM_HIL_P.Cx_delta_l_Interpolation_dimSize);

  /* Product: '<S217>/Product3' */
  rtb_Product3_hu = rtb_Add1 * rtb_Cy;

  /* Gain: '<S248>/Gain' */
  rtb_Gain_pu = GRM_HIL_P.Gain_Gain_l4 * rtb_ZeroOrderHold[1];

  /* Interpolation_n-D: '<S237>/Cx_delta_m_Interpolation' */
  frac_4[0] = rtb_DerivativeGain_j0;
  frac_4[1] = rtb_ProportionalGain_l;
  frac_4[2] = rtb_DerivativeGain_e;
  bpIndex_4[0] = rtb_k_Mach;
  bpIndex_4[1] = rtb_k_alB;
  bpIndex_4[2] = rtb_k_beB;
  rtb_Cy = intrp3d_l_pw(bpIndex_4, frac_4,
                        GRM_HIL_P.Cx_delta_m_Interpolation_Table,
                        GRM_HIL_P.Cx_delta_m_Interpolation_dimSize);

  /* Product: '<S217>/Product4' */
  rtb_Product4_e = rtb_Gain_pu * rtb_Cy;

  /* Gain: '<S249>/Gain' */
  rtb_Gain_nv = GRM_HIL_P.Gain_Gain_pr * rtb_ZeroOrderHold[2];

  /* Interpolation_n-D: '<S237>/Cx_delta_n_Interpolation' */
  frac_5[0] = rtb_DerivativeGain_j0;
  frac_5[1] = rtb_ProportionalGain_l;
  frac_5[2] = rtb_DerivativeGain_e;
  bpIndex_5[0] = rtb_k_Mach;
  bpIndex_5[1] = rtb_k_alB;
  bpIndex_5[2] = rtb_k_beB;
  rtb_Cy = intrp3d_l_pw(bpIndex_5, frac_5,
                        GRM_HIL_P.Cx_delta_n_Interpolation_Table,
                        GRM_HIL_P.Cx_delta_n_Interpolation_dimSize);

  /* Product: '<S217>/Product5' */
  rtb_Product5 = rtb_Gain_nv * rtb_Cy;

  /* Interpolation_n-D: '<S237>/Cx_alt_Interpolation' incorporates:
   *  PreLookup: '<S237>/Prelookup_altitude'
   */
  bpIndex_6[2] = plook_binc(GRM_HIL_B.Switch[2],
    GRM_HIL_P.Prelookup_altitude_BreakpointsData, 19U, &rtb_Cy);
  frac_6[0] = rtb_DerivativeGain_j0;
  frac_6[1] = rtb_ProportionalGain_l;
  frac_6[2] = rtb_Cy;
  bpIndex_6[0] = rtb_k_Mach;
  bpIndex_6[1] = rtb_k_alB;
  rtb_Cy = intrp3d_l_pw(bpIndex_6, frac_6, GRM_HIL_P.Cx_alt_Interpolation_Table,
                        GRM_HIL_P.Cx_alt_Interpolation_dimSize);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sqrt: '<S241>/Sqrt' incorporates:
     *  Constant: '<S241>/Constant3'
     */
    GRM_HIL_B.Sqrt = sqrt(GRM_HIL_P.Constant3_Value_f);
  }

  /* Gain: '<S244>/Gain' incorporates:
   *  Gain: '<S242>/Gain1'
   *  Gain: '<S243>/Gain1'
   *  Product: '<S241>/Product1'
   *  Trigonometry: '<S241>/Trigonometric Function'
   *  Trigonometry: '<S241>/Trigonometric Function1'
   *  Trigonometry: '<S241>/Trigonometric Function2'
   */
  u0 = acos(cos(GRM_HIL_P.Gain1_Gain_b * rtb_Subtract_cl) * cos
            (GRM_HIL_P.Gain1_Gain_e2 * rtb_Subtract_ju)) *
    GRM_HIL_P.Gain_Gain_if;

  /* Saturate: '<S241>/Saturation' */
  if (u0 > GRM_HIL_P.Saturation_UpperSat_f) {
    u0 = GRM_HIL_P.Saturation_UpperSat_f;
  } else {
    if (u0 < GRM_HIL_P.Saturation_LowerSat_g) {
      u0 = GRM_HIL_P.Saturation_LowerSat_g;
    }
  }

  /* End of Saturate: '<S241>/Saturation' */

  /* Abs: '<S241>/Abs2' incorporates:
   *  Abs: '<S241>/Abs'
   *  Abs: '<S241>/Abs1'
   *  Product: '<S241>/Divide2'
   *  Product: '<S241>/Product6'
   *  Product: '<S241>/Product7'
   *  Sum: '<S241>/Add'
   */
  rtb_jxk = fabs((fabs(rtb_Subtract_cl) * rtb_Gain_pu + fabs(rtb_Subtract_ju) *
                  rtb_Gain_nv) * GRM_HIL_B.Sqrt / u0);

  /* Interpolation_n-D: '<S237>/Cx_delta_t_Interpolation' incorporates:
   *  PreLookup: '<S237>/Prelookup_delta_t'
   */
  bpIndex_7[2] = plook_binc(rtb_jxk, GRM_HIL_P.Prelookup_delta_t_BreakpointsData,
    8U, &rtb_jxk);
  frac_7[0] = rtb_DerivativeGain_j0;
  frac_7[1] = rtb_ProportionalGain_l;
  frac_7[2] = rtb_jxk;
  bpIndex_7[0] = rtb_k_Mach;
  bpIndex_7[1] = rtb_k_alB;
  rtb_jxk = intrp3d_l_pw(bpIndex_7, frac_7,
    GRM_HIL_P.Cx_delta_t_Interpolation_Table,
    GRM_HIL_P.Cx_delta_t_Interpolation_dimSize);

  /* Interpolation_n-D: '<S237>/Cx_base_Interpolation' */
  frac_8[0] = rtb_DerivativeGain_j0;
  frac_8[1] = rtb_ProportionalGain_l;
  frac_8[2] = rtb_DerivativeGain_e;
  bpIndex_8[0] = rtb_k_Mach;
  bpIndex_8[1] = rtb_k_alB;
  bpIndex_8[2] = rtb_k_beB;
  rtb_Subtract_ju = intrp3d_l_pw(bpIndex_8, frac_8,
    GRM_HIL_P.Cx_base_Interpolation_Table,
    GRM_HIL_P.Cx_base_Interpolation_dimSize);

  /* Clock: '<S351>/Clock' incorporates:
   *  Derivative: '<S304>/Derivative'
   *  Derivative: '<S304>/Derivative1'
   */
  rtb_ProportionalGain_a = GRM_HIL_M->Timing.t[0];

  /* Sum: '<S216>/Subtract' incorporates:
   *  Clock: '<S351>/Clock'
   *  Constant: '<S351>/Constant6'
   *  Sum: '<S209>/Subtract'
   *  Sum: '<S313>/Subtract'
   */
  rtb_q_conj_e = rtb_ProportionalGain_a - GRM_HIL_P.Constant6_Value_i;

  /* Sum: '<S217>/Add' incorporates:
   *  Constant: '<S216>/Constant'
   *  MATLAB Function: '<S216>/MATLAB Function'
   *  Product: '<S217>/Product2'
   *  Product: '<S217>/Product8'
   *  Sum: '<S216>/Subtract'
   */
  rtb_ZeroOrderHold[0] = ((((((((rtb_Cx + rtb_Product_l) + rtb_Product1) +
    rtb_DerivativeGain * rtb_jxi) + rtb_Product3_hu) + rtb_Product4_e) +
    rtb_Product5) + rtb_Cy) + rtb_jxk) + (real_T)((!(rtb_q_conj_e >= 0.0)) ||
    (!(rtb_q_conj_e <= GRM_HIL_P.Constant_Value_ok))) * rtb_Subtract_ju;

  /* Interpolation_n-D: '<S238>/Cy_Interpolation' */
  frac_9[0] = rtb_DerivativeGain_j0;
  frac_9[1] = rtb_ProportionalGain_l;
  frac_9[2] = rtb_DerivativeGain_e;
  bpIndex_9[0] = rtb_k_Mach;
  bpIndex_9[1] = rtb_k_alB;
  bpIndex_9[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_9, frac_9, GRM_HIL_P.Cy_Interpolation_Table,
    GRM_HIL_P.Cy_Interpolation_dimSize);

  /* Product: '<S238>/Product' incorporates:
   *  Constant: '<S238>/Constant'
   */
  rtb_Cy = GRM_HIL_P.Constant_Value_oz * rtb_jxk;

  /* Interpolation_n-D: '<S238>/Cyp_Interpolation' */
  frac_a[0] = rtb_DerivativeGain_j0;
  frac_a[1] = rtb_ProportionalGain_l;
  frac_a[2] = rtb_DerivativeGain_e;
  bpIndex_a[0] = rtb_k_Mach;
  bpIndex_a[1] = rtb_k_alB;
  bpIndex_a[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_a, frac_a, GRM_HIL_P.Cyp_Interpolation_Table,
    GRM_HIL_P.Cyp_Interpolation_dimSize);

  /* Product: '<S217>/Product6' */
  rtb_jxi = rtb_Add3 * rtb_jxk;

  /* Interpolation_n-D: '<S238>/Cyq_Interpolation' */
  frac_b[0] = rtb_DerivativeGain_j0;
  frac_b[1] = rtb_ProportionalGain_l;
  frac_b[2] = rtb_DerivativeGain_e;
  bpIndex_b[0] = rtb_k_Mach;
  bpIndex_b[1] = rtb_k_alB;
  bpIndex_b[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_b, frac_b, GRM_HIL_P.Cyq_Interpolation_Table,
    GRM_HIL_P.Cyq_Interpolation_dimSize);

  /* Product: '<S217>/Product7' */
  rtb_Subtract_ju = rtb_ProportionalGain * rtb_jxk;

  /* Interpolation_n-D: '<S238>/Cyr_Interpolation' */
  frac_c[0] = rtb_DerivativeGain_j0;
  frac_c[1] = rtb_ProportionalGain_l;
  frac_c[2] = rtb_DerivativeGain_e;
  bpIndex_c[0] = rtb_k_Mach;
  bpIndex_c[1] = rtb_k_alB;
  bpIndex_c[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_c, frac_c, GRM_HIL_P.Cyr_Interpolation_Table,
    GRM_HIL_P.Cyr_Interpolation_dimSize);

  /* Product: '<S217>/Product9' */
  rtb_Subtract_cl = rtb_DerivativeGain * rtb_jxk;

  /* Interpolation_n-D: '<S238>/Cy_delta_l_Interpolation' */
  frac_d[0] = rtb_DerivativeGain_j0;
  frac_d[1] = rtb_ProportionalGain_l;
  frac_d[2] = rtb_DerivativeGain_e;
  bpIndex_d[0] = rtb_k_Mach;
  bpIndex_d[1] = rtb_k_alB;
  bpIndex_d[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_d, frac_d,
    GRM_HIL_P.Cy_delta_l_Interpolation_Table,
    GRM_HIL_P.Cy_delta_l_Interpolation_dimSize);

  /* Product: '<S217>/Product10' */
  rtb_Cx = rtb_Add1 * rtb_jxk;

  /* Interpolation_n-D: '<S238>/Cy_delta_m_Interpolation' */
  frac_e[0] = rtb_DerivativeGain_j0;
  frac_e[1] = rtb_ProportionalGain_l;
  frac_e[2] = rtb_DerivativeGain_e;
  bpIndex_e[0] = rtb_k_Mach;
  bpIndex_e[1] = rtb_k_alB;
  bpIndex_e[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_e, frac_e,
    GRM_HIL_P.Cy_delta_m_Interpolation_Table,
    GRM_HIL_P.Cy_delta_m_Interpolation_dimSize);

  /* Product: '<S217>/Product11' */
  rtb_Product_l = rtb_Gain_pu * rtb_jxk;

  /* Interpolation_n-D: '<S238>/Cy_delta_n_Interpolation' */
  frac_f[0] = rtb_DerivativeGain_j0;
  frac_f[1] = rtb_ProportionalGain_l;
  frac_f[2] = rtb_DerivativeGain_e;
  bpIndex_f[0] = rtb_k_Mach;
  bpIndex_f[1] = rtb_k_alB;
  bpIndex_f[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_f, frac_f,
    GRM_HIL_P.Cy_delta_n_Interpolation_Table,
    GRM_HIL_P.Cy_delta_n_Interpolation_dimSize);

  /* Sum: '<S217>/Add1' incorporates:
   *  Product: '<S217>/Product12'
   */
  rtb_ZeroOrderHold[1] = (((((rtb_Cy + rtb_jxi) + rtb_Subtract_ju) +
    rtb_Subtract_cl) + rtb_Cx) + rtb_Product_l) + rtb_Gain_nv * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Cz_Interpolation' */
  frac_g[0] = rtb_DerivativeGain_j0;
  frac_g[1] = rtb_ProportionalGain_l;
  frac_g[2] = rtb_DerivativeGain_e;
  bpIndex_g[0] = rtb_k_Mach;
  bpIndex_g[1] = rtb_k_alB;
  bpIndex_g[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_g, frac_g, GRM_HIL_P.Cz_Interpolation_Table,
    GRM_HIL_P.Cz_Interpolation_dimSize);

  /* Product: '<S239>/Product' incorporates:
   *  Constant: '<S239>/Constant'
   */
  rtb_Cy = GRM_HIL_P.Constant_Value_gw * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Czp_Interpolation' */
  frac_h[0] = rtb_DerivativeGain_j0;
  frac_h[1] = rtb_ProportionalGain_l;
  frac_h[2] = rtb_DerivativeGain_e;
  bpIndex_h[0] = rtb_k_Mach;
  bpIndex_h[1] = rtb_k_alB;
  bpIndex_h[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_h, frac_h, GRM_HIL_P.Czp_Interpolation_Table,
    GRM_HIL_P.Czp_Interpolation_dimSize);

  /* Product: '<S217>/Product16' */
  rtb_jxi = rtb_Add3 * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Czq_Interpolation' */
  frac_i[0] = rtb_DerivativeGain_j0;
  frac_i[1] = rtb_ProportionalGain_l;
  frac_i[2] = rtb_DerivativeGain_e;
  bpIndex_i[0] = rtb_k_Mach;
  bpIndex_i[1] = rtb_k_alB;
  bpIndex_i[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_i, frac_i, GRM_HIL_P.Czq_Interpolation_Table,
    GRM_HIL_P.Czq_Interpolation_dimSize);

  /* Product: '<S217>/Product17' */
  rtb_Subtract_ju = rtb_ProportionalGain * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Czr_Interpolation' */
  frac_j[0] = rtb_DerivativeGain_j0;
  frac_j[1] = rtb_ProportionalGain_l;
  frac_j[2] = rtb_DerivativeGain_e;
  bpIndex_j[0] = rtb_k_Mach;
  bpIndex_j[1] = rtb_k_alB;
  bpIndex_j[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_j, frac_j, GRM_HIL_P.Czr_Interpolation_Table,
    GRM_HIL_P.Czr_Interpolation_dimSize);

  /* Product: '<S217>/Product18' */
  rtb_Subtract_cl = rtb_DerivativeGain * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Cz_delta_l_Interpolation' */
  frac_k[0] = rtb_DerivativeGain_j0;
  frac_k[1] = rtb_ProportionalGain_l;
  frac_k[2] = rtb_DerivativeGain_e;
  bpIndex_k[0] = rtb_k_Mach;
  bpIndex_k[1] = rtb_k_alB;
  bpIndex_k[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_k, frac_k,
    GRM_HIL_P.Cz_delta_l_Interpolation_Table,
    GRM_HIL_P.Cz_delta_l_Interpolation_dimSize);

  /* Product: '<S217>/Product13' */
  rtb_Cx = rtb_Add1 * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Cz_delta_m_Interpolation' */
  frac_l[0] = rtb_DerivativeGain_j0;
  frac_l[1] = rtb_ProportionalGain_l;
  frac_l[2] = rtb_DerivativeGain_e;
  bpIndex_l[0] = rtb_k_Mach;
  bpIndex_l[1] = rtb_k_alB;
  bpIndex_l[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_l, frac_l,
    GRM_HIL_P.Cz_delta_m_Interpolation_Table,
    GRM_HIL_P.Cz_delta_m_Interpolation_dimSize);

  /* Product: '<S217>/Product14' */
  rtb_Product_l = rtb_Gain_pu * rtb_jxk;

  /* Interpolation_n-D: '<S239>/Cz_delta_n_Interpolation' */
  frac_m[0] = rtb_DerivativeGain_j0;
  frac_m[1] = rtb_ProportionalGain_l;
  frac_m[2] = rtb_DerivativeGain_e;
  bpIndex_m[0] = rtb_k_Mach;
  bpIndex_m[1] = rtb_k_alB;
  bpIndex_m[2] = rtb_k_beB;
  rtb_jxk = intrp3d_l_pw(bpIndex_m, frac_m,
    GRM_HIL_P.Cz_delta_n_Interpolation_Table,
    GRM_HIL_P.Cz_delta_n_Interpolation_dimSize);

  /* Sum: '<S217>/Add2' incorporates:
   *  Product: '<S217>/Product15'
   */
  rtb_ZeroOrderHold[2] = (((((rtb_Cy + rtb_jxi) + rtb_Subtract_ju) +
    rtb_Subtract_cl) + rtb_Cx) + rtb_Product_l) + rtb_Gain_nv * rtb_jxk;

  /* Sum: '<S269>/Add' incorporates:
   *  Constant: '<S269>/Constant1'
   *  Constant: '<S269>/Tmp_gradient_tropo'
   *  Product: '<S269>/Divide'
   */
  rtb_jxk = q0_tmp / GRM_HIL_B.Tmp_ref * GRM_HIL_P.Tmp_gradient_tropo_Value_l +
    GRM_HIL_P.Constant1_Value_mh;

  /* Math: '<S269>/Math Function' incorporates:
   *  Constant: '<S269>/pressure_exponent'
   */
  if ((rtb_jxk < 0.0) && (GRM_HIL_P.pressure_exponent_Value > floor
                          (GRM_HIL_P.pressure_exponent_Value))) {
    rtb_jxk = -rt_powd_snf(-rtb_jxk, GRM_HIL_P.pressure_exponent_Value);
  } else {
    rtb_jxk = rt_powd_snf(rtb_jxk, GRM_HIL_P.pressure_exponent_Value);
  }

  /* End of Math: '<S269>/Math Function' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S267>/Subtract2' incorporates:
     *  Constant: '<S267>/pa_norm_msl'
     *  Constant: '<S352>/deviation_pa_QFH'
     */
    GRM_HIL_B.pa_ref = GRM_HIL_P.deviation_pa_QFH_Value +
      GRM_HIL_P.pa_norm_msl_Value;
  }

  /* Product: '<S218>/Product2' incorporates:
   *  Constant: '<S218>/Constant2'
   *  Constant: '<S264>/specific_gas_constant'
   *  Constant: '<S344>/Constant'
   *  Math: '<S344>/Math Function1'
   *  Product: '<S264>/Divide'
   *  Product: '<S269>/Product'
   *  Product: '<S344>/Product1'
   */
  rtb_Abs_n = 1.0 / rtb_Abs_n * (rtb_jxk * GRM_HIL_B.pa_ref) /
    GRM_HIL_P.specific_gas_constant_Value_c * (rtb_Gain1_c * rtb_Gain1_c *
    GRM_HIL_P.Constant_Value_ii) * GRM_HIL_P.Constant2_Value_a2;

  /* Product: '<S218>/Product' */
  frac_1[0] = rtb_ZeroOrderHold[0] * rtb_Abs_n;
  frac_1[1] = rtb_ZeroOrderHold[1] * rtb_Abs_n;
  frac_1[2] = rtb_ZeroOrderHold[2] * rtb_Abs_n;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S226>/Switch1' incorporates:
     *  Constant: '<S226>/Constant'
     *  Constant: '<S226>/Constant2'
     *  Constant: '<S227>/c_flat'
     *  Constant: '<S227>/c_rsma'
     *  Constant: '<S228>/Constant'
     *  Gain: '<S226>/Gain'
     *  Gain: '<S228>/Gain'
     *  Product: '<S228>/Product'
     *  Product: '<S228>/Product4'
     *  Product: '<S228>/Product5'
     *  Sqrt: '<S228>/Sqrt1'
     *  Sum: '<S228>/Subtract'
     *  Sum: '<S228>/Subtract1'
     *  Sum: '<S228>/Sum'
     *  Trigonometry: '<S228>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_o > GRM_HIL_P.Switch1_Threshold_m) {
      GRM_HIL_B.hBE_0 = GRM_HIL_P.Gain_Gain_i * GRM_HIL_P.Constant_Value_iu[2];
    } else {
      /* Sqrt: '<S229>/Sqrt' incorporates:
       *  Constant: '<S226>/Constant'
       *  Product: '<S229>/Product1'
       *  Product: '<S229>/Product2'
       *  Sqrt: '<S228>/Sqrt'
       *  Sum: '<S229>/Add'
       */
      rtb_jxk = sqrt(GRM_HIL_P.Constant_Value_iu[0] *
                     GRM_HIL_P.Constant_Value_iu[0] +
                     GRM_HIL_P.Constant_Value_iu[1] *
                     GRM_HIL_P.Constant_Value_iu[1]);

      /* Product: '<S229>/Product' incorporates:
       *  Constant: '<S227>/c_flat'
       *  Constant: '<S227>/c_rsma'
       *  Constant: '<S229>/Constant'
       *  Sum: '<S229>/Subtract'
       */
      rtb_Gain1_c = (GRM_HIL_P.Constant_Value_gq - GRM_HIL_P.c_flat_Value) *
        GRM_HIL_P.c_rsma_Value;

      /* Trigonometry: '<S229>/Trigonometric Function' incorporates:
       *  Constant: '<S226>/Constant'
       *  Constant: '<S227>/c_rsma'
       *  Product: '<S229>/Divide1'
       *  Product: '<S229>/Product6'
       *  Product: '<S229>/Product7'
       *  Sqrt: '<S229>/Sqrt'
       */
      rtb_Cy = atan(GRM_HIL_P.Constant_Value_iu[2] * GRM_HIL_P.c_rsma_Value /
                    (rtb_jxk * rtb_Gain1_c));

      /* Trigonometry: '<S229>/Trigonometric Function3' */
      rtb_jxi = cos(rtb_Cy);

      /* Product: '<S229>/Product9' */
      rtb_Subtract_ju = rtb_jxi * rtb_jxi * rtb_jxi;

      /* Trigonometry: '<S229>/Trigonometric Function2' */
      rtb_Cy = sin(rtb_Cy);

      /* Product: '<S229>/Product5' */
      rtb_jxi = rtb_Gain1_c * rtb_Gain1_c;

      /* Product: '<S229>/Product10' incorporates:
       *  Constant: '<S227>/c_rsma'
       *  Product: '<S229>/Divide'
       *  Product: '<S229>/Product4'
       *  Product: '<S229>/Product8'
       *  Sum: '<S229>/Subtract2'
       */
      rtb_Gain1_c = (GRM_HIL_P.c_rsma_Value * GRM_HIL_P.c_rsma_Value - rtb_jxi) /
        rtb_jxi * rtb_Gain1_c * (rtb_Cy * rtb_Cy * rtb_Cy);

      /* Sum: '<S229>/Add1' incorporates:
       *  Constant: '<S226>/Constant'
       */
      rtb_Gain1_c += GRM_HIL_P.Constant_Value_iu[2];

      /* Product: '<S229>/Product3' incorporates:
       *  Constant: '<S227>/c_flat'
       *  Product: '<S228>/Product3'
       */
      q0_tmp = GRM_HIL_P.c_flat_Value * GRM_HIL_P.c_flat_Value;

      /* Trigonometry: '<S229>/Trigonometric Function1' incorporates:
       *  Constant: '<S227>/c_flat'
       *  Constant: '<S227>/c_rsma'
       *  Gain: '<S229>/Gain'
       *  Product: '<S229>/Divide2'
       *  Product: '<S229>/Product11'
       *  Product: '<S229>/Product3'
       *  Sqrt: '<S229>/Sqrt'
       *  Sum: '<S229>/Subtract1'
       *  Sum: '<S229>/Subtract3'
       */
      rtb_jxi = atan(rtb_Gain1_c / (rtb_jxk - (GRM_HIL_P.Gain_Gain_c *
        GRM_HIL_P.c_flat_Value - q0_tmp) * GRM_HIL_P.c_rsma_Value *
        rtb_Subtract_ju));

      /* Trigonometry: '<S228>/Trigonometric Function' */
      rtb_Cy = sin(rtb_jxi);
      GRM_HIL_B.hBE_0 = rtb_jxk / cos(rtb_jxi) - GRM_HIL_P.c_rsma_Value / sqrt
        (GRM_HIL_P.Constant_Value_j - (GRM_HIL_P.Gain_Gain *
          GRM_HIL_P.c_flat_Value - q0_tmp) * (rtb_Cy * rtb_Cy));
    }

    /* End of Switch: '<S226>/Switch1' */

    /* SignalConversion generated from: '<S224>/Vector Concatenate' incorporates:
     *  Constant: '<S224>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[0] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S224>/Vector Concatenate' incorporates:
     *  Constant: '<S224>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[1] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S224>/Vector Concatenate' incorporates:
     *  Constant: '<S224>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[2] = GRM_HIL_P.Constant3_Value_f4;
  }

  /* Switch: '<S224>/Switch' incorporates:
   *  Constant: '<S224>/Constant1'
   *  Sum: '<S224>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_lx) - GRM_HIL_B.hBE_0 >
      GRM_HIL_P.Switch_Threshold_f) {
    rtb_ZeroOrderHold[0] = frac_1[0];
    rtb_ZeroOrderHold[1] = frac_1[1];
    rtb_ZeroOrderHold[2] = frac_1[2];
  } else {
    rtb_ZeroOrderHold[0] = GRM_HIL_B.VectorConcatenate[0];
    rtb_ZeroOrderHold[1] = GRM_HIL_B.VectorConcatenate[1];
    rtb_ZeroOrderHold[2] = GRM_HIL_B.VectorConcatenate[2];
  }

  /* End of Switch: '<S224>/Switch' */

  /* Saturate: '<S198>/Saturation' */
  if (GRM_HIL_B.Switch[2] > GRM_HIL_P.Saturation_UpperSat_d) {
    rtb_jxk = GRM_HIL_P.Saturation_UpperSat_d;
  } else if (GRM_HIL_B.Switch[2] < GRM_HIL_P.Saturation_LowerSat_j) {
    rtb_jxk = GRM_HIL_P.Saturation_LowerSat_j;
  } else {
    rtb_jxk = GRM_HIL_B.Switch[2];
  }

  /* End of Saturate: '<S198>/Saturation' */

  /* Trigonometry: '<S262>/Trigonometric Function' incorporates:
   *  Switch: '<S304>/Switch'
   *  Trigonometry: '<S260>/Trigonometric Function2'
   *  Trigonometry: '<S304>/Trigonometric Function'
   */
  rtb_jxi = sin(GRM_HIL_B.Switch[1]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S263>/Divide' incorporates:
     *  Constant: '<S262>/WGS84 Semi-major Axis, [m]'
     *  Constant: '<S262>/WGS84 Semi-minor Axis, [m]'
     *  Sum: '<S263>/Add'
     */
    rtb_Switch1 = (GRM_HIL_P.WGS84SemimajorAxism_Value -
                   GRM_HIL_P.WGS84SemiminorAxism_Value) /
      GRM_HIL_P.WGS84SemimajorAxism_Value;

    /* Product: '<S263>/Divide1' incorporates:
     *  Constant: '<S263>/a2'
     *  Sum: '<S263>/Add1'
     */
    rtb_Switch1 *= GRM_HIL_P.a2_Value - rtb_Switch1;

    /* Sqrt: '<S263>/Sqrt' */
    rtb_Switch1 = sqrt(rtb_Switch1);

    /* Product: '<S262>/Divide' */
    GRM_HIL_B.e2 = rtb_Switch1 * rtb_Switch1;

    /* Sum: '<S260>/Add1' incorporates:
     *  Constant: '<S260>/Constant'
     *  Product: '<S260>/Divide2'
     */
    GRM_HIL_B.Add1 = GRM_HIL_P.Constant_Value_ov - rtb_Switch1 * rtb_Switch1;
  }

  /* Product: '<S262>/Divide3' incorporates:
   *  Constant: '<S262>/WGS84 Semi-major Axis, [m]'
   *  Constant: '<S262>/a3'
   *  Product: '<S262>/Divide1'
   *  Product: '<S262>/Divide2'
   *  Sqrt: '<S262>/Sqrt'
   *  Sum: '<S262>/Add2'
   *  Trigonometry: '<S262>/Trigonometric Function'
   */
  rtb_Cy = 1.0 / sqrt(GRM_HIL_P.a3_Value - rtb_jxi * rtb_jxi * GRM_HIL_B.e2) *
    GRM_HIL_P.WGS84SemimajorAxism_Value;

  /* Sum: '<S260>/Add3' */
  rtb_Subtract_ju = rtb_jxk + rtb_Cy;

  /* Trigonometry: '<S260>/Trigonometric Function3' incorporates:
   *  Switch: '<S304>/Switch'
   *  Trigonometry: '<S304>/Trigonometric Function1'
   */
  q0_tmp = cos(GRM_HIL_B.Switch[1]);
  rtb_Gain2_dm = q0_tmp;

  /* Trigonometry: '<S260>/Trigonometric Function1' incorporates:
   *  MATLAB Function: '<S254>/WGS84_Gravity_Implementation'
   */
  frac_tmp = cos(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S261>/ SFunction ' incorporates:
   *  MATLAB Function: '<S254>/WGS84_Gravity_Implementation'
   *  Product: '<S260>/Divide'
   *  Trigonometry: '<S260>/Trigonometric Function1'
   */
  frac_2[0] = rtb_Subtract_ju * frac_tmp * rtb_Gain2_dm;

  /* Trigonometry: '<S260>/Trigonometric Function' incorporates:
   *  MATLAB Function: '<S254>/WGS84_Gravity_Implementation'
   */
  frac_tmp_0 = sin(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S261>/ SFunction ' incorporates:
   *  MATLAB Function: '<S254>/WGS84_Gravity_Implementation'
   *  Product: '<S260>/Divide1'
   *  Product: '<S260>/Divide3'
   *  Product: '<S260>/Divide4'
   *  Sum: '<S260>/Add2'
   *  Trigonometry: '<S260>/Trigonometric Function'
   */
  frac_2[1] = rtb_Subtract_ju * frac_tmp_0 * rtb_Gain2_dm;
  frac_2[2] = (rtb_Cy * GRM_HIL_B.Add1 + rtb_jxk) * rtb_jxi;

  /* MATLAB Function: '<S254>/WGS84_Gravity_Implementation' */
  rtb_Product_l = GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS;
  u0 = GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma;
  rtb_Gain1_c = sqrt(u0 - rtb_Product_l);
  rtb_Product3_hu = rtb_Gain1_c * rtb_Gain1_c;
  rtb_Cy_tmp = frac_2[2] * frac_2[2];
  rtb_Subtract_ju = frac_2[0] * frac_2[0] + frac_2[1] * frac_2[1];
  rtb_Switch1 = (rtb_Subtract_ju + rtb_Cy_tmp) - rtb_Product3_hu;
  rtb_Cy = sqrt((sqrt(rtb_Product3_hu * 4.0 * rtb_Cy_tmp / (rtb_Switch1 *
    rtb_Switch1) + 1.0) + 1.0) * (rtb_Switch1 * 0.5));
  rtb_Product4_e = rtb_Cy * rtb_Cy;
  rtb_Switch1_tmp = rtb_Product4_e + rtb_Product3_hu;
  rtb_Switch1 = sqrt(rtb_Switch1_tmp);
  rtb_Subtract_ju = rt_atan2d_snf(frac_2[2] * rtb_Switch1, sqrt(rtb_Subtract_ju)
    * rtb_Cy);
  rtb_Subtract_cl = sin(rtb_Subtract_ju);
  rtb_Cx_tmp = rtb_Subtract_cl * rtb_Subtract_cl;
  rtb_Cx = sqrt((rtb_Product3_hu * rtb_Cx_tmp + rtb_Product4_e) /
                rtb_Switch1_tmp);
  rtb_Product_l = ((rtb_Product_l * 3.0 / rtb_Product3_hu + 1.0) * rt_atan2d_snf
                   (rtb_Gain1_c, GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS)
                   - 3.0 * GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS /
                   rtb_Gain1_c) * 0.5;
  rtb_Product1 = cos(rtb_Subtract_ju);
  rtb_Product5 = rt_atan2d_snf(rtb_Gain1_c, rtb_Cy);
  rtb_TBG[0] = rtb_Cy / (rtb_Cx * rtb_Switch1) * rtb_Product1 * frac_tmp;
  rtb_TBG[3] = -1.0 / rtb_Cx * rtb_Subtract_cl * frac_tmp;
  rtb_TBG[6] = -frac_tmp_0;
  rtb_Cy_tmp = rtb_Cy / (sqrt(rtb_Cy * rtb_Cy + rtb_Gain1_c * rtb_Gain1_c) *
    rtb_Cx) * cos(rtb_Subtract_ju);
  rtb_TBG[1] = rtb_Cy_tmp * frac_tmp_0;
  rtb_TBG[4] = -1.0 / rtb_Cx * sin(rtb_Subtract_ju) * frac_tmp_0;
  rtb_TBG[7] = frac_tmp;
  rtb_TBG[2] = 1.0 / rtb_Cx * rtb_Subtract_cl;
  rtb_TBG[5] = rtb_Cy_tmp;
  rtb_TBG[8] = 0.0;
  rtb_Subtract_ju = GRM_HIL_P.WGS84_Gravity_Implementation_c_rot *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rot;
  frac_tmp = GRM_HIL_P.WGS84_Gravitation_flg_omega_enabled / rtb_Cx *
    rtb_Subtract_ju;
  frac_tmp_0 = (((rtb_Product4_e / rtb_Product3_hu + 1.0) * 3.0 * (1.0 - rtb_Cy /
    rtb_Gain1_c * rtb_Product5) - 1.0) * (rtb_Subtract_ju * u0 * rtb_Gain1_c /
    rtb_Switch1_tmp) / rtb_Product_l * (rtb_Cx_tmp * 0.5 - 0.16666666666666666)
                + GRM_HIL_P.WGS84_Gravity_Implementation_c_grav /
                rtb_Switch1_tmp) * (-1.0 / rtb_Cx) + frac_tmp * rtb_Cy *
    (rtb_Product1 * rtb_Product1);
  rtb_Switch1 = ((rtb_Product4_e * 3.0 / rtb_Product3_hu + 1.0) * rtb_Product5 -
                 3.0 * rtb_Cy / rtb_Gain1_c) * 0.5 * (1.0 / rtb_Cx *
    rtb_Subtract_ju * u0 / rtb_Switch1_tmp) / rtb_Product_l * rtb_Subtract_cl *
    rtb_Product1 - frac_tmp * rtb_Switch1 * rtb_Subtract_cl * rtb_Product1;
  for (i = 0; i < 3; i++) {
    frac[i] = rtb_TBG[i + 6] * 0.0 + (rtb_TBG[i + 3] * rtb_Switch1 + rtb_TBG[i] *
      frac_tmp_0);
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S284>/Switch1' incorporates:
     *  Constant: '<S284>/Constant'
     *  Constant: '<S284>/Constant2'
     *  Constant: '<S285>/c_flat'
     *  Constant: '<S285>/c_rsma'
     *  Constant: '<S286>/Constant'
     *  Gain: '<S284>/Gain'
     *  Gain: '<S286>/Gain'
     *  Product: '<S286>/Product'
     *  Product: '<S286>/Product4'
     *  Product: '<S286>/Product5'
     *  Sqrt: '<S286>/Sqrt1'
     *  Sum: '<S286>/Subtract'
     *  Sum: '<S286>/Subtract1'
     *  Sum: '<S286>/Sum'
     *  Trigonometry: '<S286>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_id > GRM_HIL_P.Switch1_Threshold_d) {
      GRM_HIL_B.hBE_0_l = GRM_HIL_P.Gain_Gain_g * GRM_HIL_P.Constant_Value_g4[2];
    } else {
      /* Sqrt: '<S287>/Sqrt' incorporates:
       *  Constant: '<S284>/Constant'
       *  Product: '<S287>/Product1'
       *  Product: '<S287>/Product2'
       *  Sqrt: '<S286>/Sqrt'
       *  Sum: '<S287>/Add'
       */
      rtb_Gain1_c = sqrt(GRM_HIL_P.Constant_Value_g4[0] *
                         GRM_HIL_P.Constant_Value_g4[0] +
                         GRM_HIL_P.Constant_Value_g4[1] *
                         GRM_HIL_P.Constant_Value_g4[1]);

      /* Product: '<S287>/Product' incorporates:
       *  Constant: '<S285>/c_flat'
       *  Constant: '<S285>/c_rsma'
       *  Constant: '<S287>/Constant'
       *  Sum: '<S287>/Subtract'
       */
      rtb_Cy = (GRM_HIL_P.Constant_Value_e - GRM_HIL_P.c_flat_Value_c) *
        GRM_HIL_P.c_rsma_Value_m;

      /* Trigonometry: '<S287>/Trigonometric Function' incorporates:
       *  Constant: '<S284>/Constant'
       *  Constant: '<S285>/c_rsma'
       *  Product: '<S287>/Divide1'
       *  Product: '<S287>/Product6'
       *  Product: '<S287>/Product7'
       *  Sqrt: '<S287>/Sqrt'
       */
      rtb_Switch1 = atan(GRM_HIL_P.Constant_Value_g4[2] *
                         GRM_HIL_P.c_rsma_Value_m / (rtb_Gain1_c * rtb_Cy));

      /* Trigonometry: '<S287>/Trigonometric Function3' */
      rtb_Subtract_ju = cos(rtb_Switch1);

      /* Product: '<S287>/Product9' */
      rtb_Subtract_cl = rtb_Subtract_ju * rtb_Subtract_ju * rtb_Subtract_ju;

      /* Trigonometry: '<S287>/Trigonometric Function2' */
      rtb_Switch1 = sin(rtb_Switch1);

      /* Product: '<S287>/Product5' */
      rtb_Subtract_ju = rtb_Cy * rtb_Cy;

      /* Product: '<S287>/Product10' incorporates:
       *  Constant: '<S285>/c_rsma'
       *  Product: '<S287>/Divide'
       *  Product: '<S287>/Product4'
       *  Product: '<S287>/Product8'
       *  Sum: '<S287>/Subtract2'
       */
      rtb_Cy = (GRM_HIL_P.c_rsma_Value_m * GRM_HIL_P.c_rsma_Value_m -
                rtb_Subtract_ju) / rtb_Subtract_ju * rtb_Cy * (rtb_Switch1 *
        rtb_Switch1 * rtb_Switch1);

      /* Sum: '<S287>/Add1' incorporates:
       *  Constant: '<S284>/Constant'
       */
      rtb_Cy += GRM_HIL_P.Constant_Value_g4[2];

      /* Product: '<S287>/Product3' incorporates:
       *  Constant: '<S285>/c_flat'
       *  Product: '<S286>/Product3'
       */
      rtb_Cx = GRM_HIL_P.c_flat_Value_c * GRM_HIL_P.c_flat_Value_c;

      /* Trigonometry: '<S287>/Trigonometric Function1' incorporates:
       *  Constant: '<S285>/c_flat'
       *  Constant: '<S285>/c_rsma'
       *  Gain: '<S287>/Gain'
       *  Product: '<S287>/Divide2'
       *  Product: '<S287>/Product11'
       *  Product: '<S287>/Product3'
       *  Sqrt: '<S287>/Sqrt'
       *  Sum: '<S287>/Subtract1'
       *  Sum: '<S287>/Subtract3'
       */
      rtb_Subtract_ju = atan(rtb_Cy / (rtb_Gain1_c - (GRM_HIL_P.Gain_Gain_j *
        GRM_HIL_P.c_flat_Value_c - rtb_Cx) * GRM_HIL_P.c_rsma_Value_m *
        rtb_Subtract_cl));

      /* Trigonometry: '<S286>/Trigonometric Function' */
      rtb_Switch1 = sin(rtb_Subtract_ju);
      GRM_HIL_B.hBE_0_l = rtb_Gain1_c / cos(rtb_Subtract_ju) -
        GRM_HIL_P.c_rsma_Value_m / sqrt(GRM_HIL_P.Constant_Value_o -
        (GRM_HIL_P.Gain_Gain_l * GRM_HIL_P.c_flat_Value_c - rtb_Cx) *
        (rtb_Switch1 * rtb_Switch1));
    }

    /* End of Switch: '<S284>/Switch1' */

    /* SignalConversion generated from: '<S283>/Vector Concatenate' incorporates:
     *  Constant: '<S283>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[0] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S283>/Vector Concatenate' incorporates:
     *  Constant: '<S283>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[1] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S283>/Vector Concatenate' incorporates:
     *  Constant: '<S283>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[2] = GRM_HIL_P.Constant3_Value_j;
  }

  /* Switch: '<S283>/Switch' incorporates:
   *  Constant: '<S283>/Constant1'
   *  Sum: '<S283>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_mm) - GRM_HIL_B.hBE_0_l >
      GRM_HIL_P.Switch_Threshold_gn) {
    /* Sqrt: '<S256>/Sqrt' incorporates:
     *  DotProduct: '<S256>/Dot Product'
     */
    rtb_Product_i[2] = sqrt((frac[0] * frac[0] + frac[1] * frac[1]) + frac[2] *
      frac[2]);

    /* SignalConversion generated from: '<S256>/Vector Concatenate' incorporates:
     *  Constant: '<S256>/Constant1'
     */
    rtb_Product_i[1] = GRM_HIL_P.Constant1_Value_cj;

    /* SignalConversion generated from: '<S256>/Vector Concatenate' incorporates:
     *  Constant: '<S256>/Constant1'
     */
    rtb_Product_i[0] = GRM_HIL_P.Constant1_Value_cj;
  } else {
    rtb_Product_i[0] = GRM_HIL_B.VectorConcatenate_f[0];
    rtb_Product_i[1] = GRM_HIL_B.VectorConcatenate_f[1];
    rtb_Product_i[2] = GRM_HIL_B.VectorConcatenate_f[2];
  }

  /* End of Switch: '<S283>/Switch' */

  /* Sum: '<S209>/Subtract' */
  rtb_Cy = rtb_q_conj_e;

  /* Switch: '<S361>/Switch' incorporates:
   *  Constant: '<S361>/Constant'
   */
  if (!(rtb_q_conj_e > GRM_HIL_P.Switch_Threshold_fo)) {
    rtb_Cy = GRM_HIL_P.Constant_Value_k;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Switch: '<S361>/Switch1' incorporates:
   *  Lookup_n-D: '<S361>/1-D Lookup Table'
   */
  if (rtb_Cy > GRM_HIL_P.Switch1_Threshold_fz) {
    /* Saturate: '<S361>/Saturation' */
    if (rtb_Cy > GRM_HIL_P.Saturation_UpperSat_c) {
      rtb_Cy = GRM_HIL_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Cy < GRM_HIL_P.Saturation_LowerSat_h) {
        rtb_Cy = GRM_HIL_P.Saturation_LowerSat_h;
      }
    }

    /* End of Saturate: '<S361>/Saturation' */
    rtb_Cy = look1_binlcapw(rtb_Cy, GRM_HIL_P.uDLookupTable_bp01Data,
      GRM_HIL_P.uDLookupTable_tableData, 16U);
  }

  /* End of Switch: '<S361>/Switch1' */

  /* Sum: '<S362>/Add' incorporates:
   *  Constant: '<S361>/Constant1'
   *  Constant: '<S361>/Constant2'
   *  Constant: '<S362>/Constant'
   *  Constant: '<S362>/Constant1'
   *  Product: '<S362>/Product'
   *  Sum: '<S361>/Subtract1'
   */
  rtb_Subtract_ju = ((GRM_HIL_P.Constant1_Value_iw - rtb_Cy) +
                     GRM_HIL_P.Constant2_Value_p) * GRM_HIL_P.Constant1_Value_mo
    + GRM_HIL_P.Constant_Value_bs;

  /* Product: '<S201>/Product' */
  rtb_Product_i[0] *= rtb_Subtract_ju;
  rtb_Product_i[1] *= rtb_Subtract_ju;
  rtb_Cx = rtb_Product_i[2] * rtb_Subtract_ju;

  /* Product: '<S200>/Product' incorporates:
   *  Math: '<S200>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac_0[i] = rtb_vBEB_a_tmp[i + 6] * rtb_Cx + (rtb_vBEB_a_tmp[i + 3] *
      rtb_Product_i[1] + rtb_vBEB_a_tmp[i] * rtb_Product_i[0]);
  }

  /* End of Product: '<S200>/Product' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S315>/Multiport Switch2' incorporates:
     *  Constant: '<S315>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3) {
     case 1:
      /* Trigonometry: '<S323>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/thrust_rot_x'
       *  Trigonometry: '<S323>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S323>/Trigonometric Function3' incorporates:
       *  Constant: '<S314>/thrust_rot_x'
       *  Trigonometry: '<S323>/Trigonometric Function'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S323>/Matrix Concatenate' incorporates:
       *  Constant: '<S323>/Constant7'
       *  Trigonometry: '<S323>/Trigonometric Function1'
       *  Trigonometry: '<S323>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_k;
      rtb_MultiportSwitch[7] = rtb_Gain1_c;
      rtb_MultiportSwitch[8] = rtb_Subtract_cl;

      /* SignalConversion generated from: '<S323>/Matrix Concatenate' incorporates:
       *  Constant: '<S323>/Constant8'
       *  Gain: '<S323>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_a;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_h * rtb_Gain1_c;

      /* SignalConversion generated from: '<S323>/Matrix Concatenate' incorporates:
       *  Constant: '<S323>/Constant'
       *  Constant: '<S323>/Constant1'
       *  Constant: '<S323>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_d;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_j;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_j;
      break;

     case 2:
      /* Trigonometry: '<S324>/Trigonometric Function3' incorporates:
       *  Constant: '<S314>/thrust_rot_x'
       *  Trigonometry: '<S324>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S324>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/thrust_rot_x'
       *  Trigonometry: '<S324>/Trigonometric Function2'
       */
      rtb_Subtract_cl = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S324>/Matrix Concatenate' incorporates:
       *  Constant: '<S324>/Constant7'
       *  Gain: '<S324>/Gain1'
       *  Trigonometry: '<S324>/Trigonometric Function1'
       *  Trigonometry: '<S324>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_d * rtb_Subtract_cl;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_a;
      rtb_MultiportSwitch[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S324>/Matrix Concatenate' incorporates:
       *  Constant: '<S324>/Constant'
       *  Constant: '<S324>/Constant1'
       *  Constant: '<S324>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ek;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value;

      /* SignalConversion generated from: '<S324>/Matrix Concatenate' incorporates:
       *  Constant: '<S324>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_Gain1_c;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_k;
      rtb_MultiportSwitch[2] = rtb_Subtract_cl;
      break;

     default:
      /* SignalConversion generated from: '<S325>/Matrix Concatenate' incorporates:
       *  Constant: '<S325>/Constant10'
       *  Constant: '<S325>/Constant11'
       *  Constant: '<S325>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_o;

      /* Trigonometry: '<S325>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/thrust_rot_x'
       *  Trigonometry: '<S325>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S325>/Trigonometric Function' incorporates:
       *  Constant: '<S314>/thrust_rot_x'
       *  Trigonometry: '<S325>/Trigonometric Function3'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S325>/Matrix Concatenate' incorporates:
       *  Constant: '<S325>/Constant7'
       *  Trigonometry: '<S325>/Trigonometric Function'
       *  Trigonometry: '<S325>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_Gain1_c;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_is;

      /* SignalConversion generated from: '<S325>/Matrix Concatenate' incorporates:
       *  Constant: '<S325>/Constant8'
       *  Gain: '<S325>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Subtract_cl;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_e * rtb_Gain1_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_d;
      break;
    }

    /* End of MultiPortSwitch: '<S315>/Multiport Switch2' */

    /* MultiPortSwitch: '<S315>/Multiport Switch1' incorporates:
     *  Constant: '<S315>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2) {
     case 1:
      /* Trigonometry: '<S320>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/thrust_rot_y'
       *  Trigonometry: '<S320>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S320>/Trigonometric Function3' incorporates:
       *  Constant: '<S314>/thrust_rot_y'
       *  Trigonometry: '<S320>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S320>/Matrix Concatenate' incorporates:
       *  Constant: '<S320>/Constant7'
       *  Trigonometry: '<S320>/Trigonometric Function1'
       *  Trigonometry: '<S320>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_f;
      rtb_MultiportSwitch1[7] = rtb_Gain1_c;
      rtb_MultiportSwitch1[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S320>/Matrix Concatenate' incorporates:
       *  Constant: '<S320>/Constant8'
       *  Gain: '<S320>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_e;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_jq * rtb_Gain1_c;

      /* SignalConversion generated from: '<S320>/Matrix Concatenate' incorporates:
       *  Constant: '<S320>/Constant'
       *  Constant: '<S320>/Constant1'
       *  Constant: '<S320>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_a;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_n;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_e;
      break;

     case 2:
      /* Trigonometry: '<S321>/Trigonometric Function3' incorporates:
       *  Constant: '<S314>/thrust_rot_y'
       *  Trigonometry: '<S321>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S321>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/thrust_rot_y'
       *  Trigonometry: '<S321>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S321>/Matrix Concatenate' incorporates:
       *  Constant: '<S321>/Constant7'
       *  Gain: '<S321>/Gain1'
       *  Trigonometry: '<S321>/Trigonometric Function1'
       *  Trigonometry: '<S321>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_h * rtb_Switch1;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_ib;
      rtb_MultiportSwitch1[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S321>/Matrix Concatenate' incorporates:
       *  Constant: '<S321>/Constant'
       *  Constant: '<S321>/Constant1'
       *  Constant: '<S321>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_dk;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_l;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_m;

      /* SignalConversion generated from: '<S321>/Matrix Concatenate' incorporates:
       *  Constant: '<S321>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_Gain1_c;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_b;
      rtb_MultiportSwitch1[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S322>/Matrix Concatenate' incorporates:
       *  Constant: '<S322>/Constant10'
       *  Constant: '<S322>/Constant11'
       *  Constant: '<S322>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_h;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_f;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_p;

      /* Trigonometry: '<S322>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/thrust_rot_y'
       *  Trigonometry: '<S322>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S322>/Trigonometric Function' incorporates:
       *  Constant: '<S314>/thrust_rot_y'
       *  Trigonometry: '<S322>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S322>/Matrix Concatenate' incorporates:
       *  Constant: '<S322>/Constant7'
       *  Trigonometry: '<S322>/Trigonometric Function'
       *  Trigonometry: '<S322>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_Gain1_c;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_d;

      /* SignalConversion generated from: '<S322>/Matrix Concatenate' incorporates:
       *  Constant: '<S322>/Constant8'
       *  Gain: '<S322>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Switch1;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_hf * rtb_Gain1_c;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_o;
      break;
    }

    /* End of MultiPortSwitch: '<S315>/Multiport Switch1' */

    /* MultiPortSwitch: '<S315>/Multiport Switch' incorporates:
     *  Constant: '<S315>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_m) {
     case 1:
      /* Trigonometry: '<S317>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/Thrust_rot_z'
       *  Trigonometry: '<S317>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S317>/Trigonometric Function3' incorporates:
       *  Constant: '<S314>/Thrust_rot_z'
       *  Trigonometry: '<S317>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S317>/Matrix Concatenate' incorporates:
       *  Constant: '<S317>/Constant7'
       *  Trigonometry: '<S317>/Trigonometric Function1'
       *  Trigonometry: '<S317>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_b;
      rtb_MultiportSwitch2[7] = rtb_Gain1_c;
      rtb_MultiportSwitch2[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S317>/Matrix Concatenate' incorporates:
       *  Constant: '<S317>/Constant8'
       *  Gain: '<S317>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_ks;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_lj * rtb_Gain1_c;

      /* SignalConversion generated from: '<S317>/Matrix Concatenate' incorporates:
       *  Constant: '<S317>/Constant'
       *  Constant: '<S317>/Constant1'
       *  Constant: '<S317>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_l;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_o;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_f;
      break;

     case 2:
      /* Trigonometry: '<S318>/Trigonometric Function3' incorporates:
       *  Constant: '<S314>/Thrust_rot_z'
       *  Trigonometry: '<S318>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S318>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/Thrust_rot_z'
       *  Trigonometry: '<S318>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S318>/Matrix Concatenate' incorporates:
       *  Constant: '<S318>/Constant7'
       *  Gain: '<S318>/Gain1'
       *  Trigonometry: '<S318>/Trigonometric Function1'
       *  Trigonometry: '<S318>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_hx * rtb_Switch1;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_f2;
      rtb_MultiportSwitch2[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S318>/Matrix Concatenate' incorporates:
       *  Constant: '<S318>/Constant'
       *  Constant: '<S318>/Constant1'
       *  Constant: '<S318>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_n;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_b;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_d;

      /* SignalConversion generated from: '<S318>/Matrix Concatenate' incorporates:
       *  Constant: '<S318>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_Gain1_c;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_g;
      rtb_MultiportSwitch2[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S319>/Matrix Concatenate' incorporates:
       *  Constant: '<S319>/Constant10'
       *  Constant: '<S319>/Constant11'
       *  Constant: '<S319>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_l;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_l;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_l;

      /* Trigonometry: '<S319>/Trigonometric Function1' incorporates:
       *  Constant: '<S314>/Thrust_rot_z'
       *  Trigonometry: '<S319>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S319>/Trigonometric Function' incorporates:
       *  Constant: '<S314>/Thrust_rot_z'
       *  Trigonometry: '<S319>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S319>/Matrix Concatenate' incorporates:
       *  Constant: '<S319>/Constant7'
       *  Trigonometry: '<S319>/Trigonometric Function'
       *  Trigonometry: '<S319>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_Gain1_c;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_c;

      /* SignalConversion generated from: '<S319>/Matrix Concatenate' incorporates:
       *  Constant: '<S319>/Constant8'
       *  Gain: '<S319>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Switch1;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_k * rtb_Gain1_c;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_f;
      break;
    }

    /* End of MultiPortSwitch: '<S315>/Multiport Switch' */

    /* Product: '<S315>/3. Rotation' */
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        packet_size_idx_1_tmp = idx + 3 * i;
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] = 0.0;
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] += rtb_MultiportSwitch2[3 * i] *
          rtb_MultiportSwitch1[idx];
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] += rtb_MultiportSwitch2[3 * i + 1]
          * rtb_MultiportSwitch1[idx + 3];
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] += rtb_MultiportSwitch2[3 * i + 2]
          * rtb_MultiportSwitch1[idx + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        packet_size_idx_1_tmp = idx + 3 * i;
        GRM_HIL_B.T12[packet_size_idx_1_tmp] = 0.0;
        GRM_HIL_B.T12[packet_size_idx_1_tmp] += rtb_vBEB_a_tmp[3 * i] *
          rtb_MultiportSwitch[idx];
        GRM_HIL_B.T12[packet_size_idx_1_tmp] += rtb_vBEB_a_tmp[3 * i + 1] *
          rtb_MultiportSwitch[idx + 3];
        GRM_HIL_B.T12[packet_size_idx_1_tmp] += rtb_vBEB_a_tmp[3 * i + 2] *
          rtb_MultiportSwitch[idx + 6];
      }
    }

    /* End of Product: '<S315>/3. Rotation' */
  }

  /* Switch: '<S313>/Switch' incorporates:
   *  Constant: '<S313>/Constant'
   */
  if (rtb_q_conj_e > GRM_HIL_P.Switch_Threshold_n) {
    rtb_Gain1_c = rtb_q_conj_e;
  } else {
    rtb_Gain1_c = GRM_HIL_P.Constant_Value_a0;
  }

  /* End of Switch: '<S313>/Switch' */

  /* Switch: '<S313>/Switch1' incorporates:
   *  Lookup_n-D: '<S313>/thrust_lookup'
   */
  if (rtb_Gain1_c > GRM_HIL_P.Switch1_Threshold_a2) {
    /* Saturate: '<S313>/Saturation' */
    if (rtb_Gain1_c > GRM_HIL_P.Saturation_UpperSat) {
      rtb_Gain1_c = GRM_HIL_P.Saturation_UpperSat;
    } else {
      if (rtb_Gain1_c < GRM_HIL_P.Saturation_LowerSat) {
        rtb_Gain1_c = GRM_HIL_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S313>/Saturation' */
    rtb_Product_i[0] = look1_binlcapw(rtb_Gain1_c,
      GRM_HIL_P.thrust_lookup_bp01Data, GRM_HIL_P.thrust_lookup_tableData, 11U);
  } else {
    rtb_Product_i[0] = rtb_Gain1_c;
  }

  /* End of Switch: '<S313>/Switch1' */

  /* Product: '<S314>/Product1' incorporates:
   *  Constant: '<S313>/Constant1'
   *  Constant: '<S314>/uncert_thrust'
   */
  rtb_Product_i[0] *= GRM_HIL_P.uncert_thrust_Value;
  rtb_Switch1 = GRM_HIL_P.Constant1_Value_h * GRM_HIL_P.uncert_thrust_Value;

  /* Product: '<S314>/Product' incorporates:
   *  Product: '<S314>/Product1'
   */
  for (i = 0; i < 3; i++) {
    frac[i] = GRM_HIL_B.T12[i + 6] * rtb_Switch1 + (GRM_HIL_B.T12[i + 3] *
      rtb_Switch1 + GRM_HIL_B.T12[i] * rtb_Product_i[0]);
  }

  /* End of Product: '<S314>/Product' */

  /* Step: '<Root>/Step' incorporates:
   *  Sin: '<Root>/Sine Wave'
   *  Step: '<Root>/External Force'
   *  Step: '<Root>/External Moment'
   *  Step: '<Root>/Step1'
   */
  rtb_q_conj_e = GRM_HIL_M->Timing.t[0];
  if (rtb_q_conj_e < GRM_HIL_P.Step_Time) {
    rtb_Gain2_dm = GRM_HIL_P.Step_Y0;
  } else {
    rtb_Gain2_dm = GRM_HIL_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Step: '<Root>/External Force' */
  if (rtb_q_conj_e < GRM_HIL_P.ExternalForce_Time) {
    rtb_Switch1 = GRM_HIL_P.ExternalForce_Y0;
  } else {
    rtb_Switch1 = GRM_HIL_P.ExternalForce_YFinal;
  }

  /* Sum: '<S200>/Add' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  frac_2[0] = ((rtb_ZeroOrderHold[0] + frac_0[0]) + frac[0]) + (rtb_Switch1 +
    rtb_Gain2_dm) * GRM_HIL_P.Gain_Gain_pd;
  frac_2[1] = ((rtb_ZeroOrderHold[1] + frac_0[1]) + frac[1]) +
    GRM_HIL_P.Constant1_Value_fp;
  frac_2[2] = ((rtb_ZeroOrderHold[2] + frac_0[2]) + frac[2]) +
    GRM_HIL_P.Constant1_Value_fp;

  /* Switch: '<S333>/Switch' incorporates:
   *  Constant: '<S333>/Constant'
   *  Product: '<S333>/Product2'
   */
  if (GRM_HIL_P.Rigid_Body_EOM_6_DOF_flag_Kraft > GRM_HIL_P.Switch_Threshold_j)
  {
    frac_0[0] = frac_2[0];
    frac_0[1] = frac_2[1];
    frac_0[2] = frac_2[2];
  } else {
    /* Sum: '<S335>/Add7' */
    rtb_MathFunction2[8] = (rtb_TBG_tmp_8 - rtb_Gain2_dm_tmp) + rtb_TBG_tmp_3;

    /* Sum: '<S335>/Add8' incorporates:
     *  Gain: '<S335>/Gain11'
     *  Gain: '<S335>/Gain12'
     */
    rtb_MathFunction2[7] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain11_Gain + rtb_TBG_tmp_7
      * GRM_HIL_P.Gain12_Gain;

    /* Sum: '<S335>/Add3' incorporates:
     *  Gain: '<S335>/Gain5'
     *  Gain: '<S335>/Gain6'
     */
    rtb_MathFunction2[6] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain5_Gain - rtb_TBG_tmp_5 *
      GRM_HIL_P.Gain6_Gain;

    /* Sum: '<S335>/Add2' incorporates:
     *  Gain: '<S335>/Gain3'
     *  Gain: '<S335>/Gain4'
     */
    rtb_MathFunction2[5] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain3_Gain_i -
      rtb_TBG_tmp_7 * GRM_HIL_P.Gain4_Gain;

    /* Sum: '<S335>/Add6' */
    rtb_MathFunction2[4] = ((rtb_Gain2_dm_tmp - rtb_TBG_tmp_1) - rtb_TBG_tmp_2)
      + rtb_TBG_tmp_3;

    /* Sum: '<S335>/Add4' incorporates:
     *  Gain: '<S335>/Gain7'
     *  Gain: '<S335>/Gain8'
     */
    rtb_MathFunction2[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain + rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain8_Gain;

    /* Sum: '<S335>/Add5' incorporates:
     *  Gain: '<S335>/Gain10'
     *  Gain: '<S335>/Gain9'
     */
    rtb_MathFunction2[2] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain9_Gain + rtb_TBG_tmp_5 *
      GRM_HIL_P.Gain10_Gain;

    /* Sum: '<S335>/Add1' incorporates:
     *  Gain: '<S335>/Gain1'
     *  Gain: '<S335>/Gain2'
     */
    rtb_MathFunction2[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_m - rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain2_Gain_i;

    /* Sum: '<S335>/Add' incorporates:
     *  Math: '<S335>/Math Function'
     *  Math: '<S335>/Math Function1'
     *  Math: '<S335>/Math Function2'
     *  Math: '<S335>/Math Function3'
     */
    rtb_MathFunction2[0] = ((rtb_Product_idx_0 * rtb_Product_idx_0 -
      rtb_Product_idx_1 * rtb_Product_idx_1) - rtb_Product_idx_2 *
      rtb_Product_idx_2) + rtb_Product_idx_3 * rtb_Product_idx_3;

    /* Math: '<S333>/Math Function2' */
    for (i = 0; i < 3; i++) {
      rtb_TBG[3 * i] = rtb_MathFunction2[i];
      rtb_TBG[3 * i + 1] = rtb_MathFunction2[i + 3];
      rtb_TBG[3 * i + 2] = rtb_MathFunction2[i + 6];
    }

    memcpy(&rtb_MathFunction2[0], &rtb_TBG[0], 9U * sizeof(real_T));

    /* End of Math: '<S333>/Math Function2' */
    for (i = 0; i < 3; i++) {
      frac_0[i] = rtb_MathFunction2[i + 6] * frac_2[2] + (rtb_MathFunction2[i +
        3] * frac_2[1] + rtb_MathFunction2[i] * frac_2[0]);
    }
  }

  /* Saturate: '<S336>/Saturation' */
  if (rtb_Subtract_ju > GRM_HIL_P.Saturation_UpperSat_m) {
    rtb_Gain1_c = GRM_HIL_P.Saturation_UpperSat_m;
  } else if (rtb_Subtract_ju < GRM_HIL_P.Saturation_LowerSat_a) {
    rtb_Gain1_c = GRM_HIL_P.Saturation_LowerSat_a;
  } else {
    rtb_Gain1_c = rtb_Subtract_ju;
  }

  /* End of Saturate: '<S336>/Saturation' */

  /* Product: '<S336>/Divide' */
  frac_0[0] /= rtb_Gain1_c;
  frac_0[1] /= rtb_Gain1_c;

  /* SignalConversion generated from: '<S340>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[0] = frac_0[0];

  /* SignalConversion generated from: '<S340>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[1] = frac_0[1];

  /* SignalConversion generated from: '<S340>/Vector Concatenate' incorporates:
   *  Product: '<S336>/Divide'
   */
  GRM_HIL_B.VectorConcatenate_b[2] = frac_0[2] / rtb_Gain1_c;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S340>/Constant' */
    GRM_HIL_B.VectorConcatenate_b[3] = GRM_HIL_P.Constant_Value_eq;
  }

  /* Sum: '<S340>/Add' incorporates:
   *  Constant: '<S340>/Q_1'
   *  Constant: '<S340>/Q_2'
   *  Constant: '<S340>/Q_3'
   *  Constant: '<S340>/Q_4'
   *  Product: '<S340>/Product'
   *  Product: '<S340>/Product1'
   *  Product: '<S340>/Product2'
   *  Product: '<S340>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_i[i] * rtb_Product_idx_0 +
               GRM_HIL_P.Q_2_Value_n[i] * rtb_Product_idx_1) +
              GRM_HIL_P.Q_3_Value_m[i] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value_f[i] * rtb_Product_idx_3;
  }

  /* End of Sum: '<S340>/Add' */

  /* Product: '<S340>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Switch1 = tmp[i + 12] * GRM_HIL_B.VectorConcatenate_b[3] + (tmp[i + 8] *
      GRM_HIL_B.VectorConcatenate_b[2] + (tmp[i + 4] *
      GRM_HIL_B.VectorConcatenate_b[1] + tmp[i] * GRM_HIL_B.VectorConcatenate_b
      [0]));
    rtb_d_qGE[i] = rtb_Switch1;
  }

  /* Sum: '<S340>/Add1' incorporates:
   *  Constant: '<S340>/Q~_1'
   *  Constant: '<S340>/Q~_2'
   *  Constant: '<S340>/Q~_3'
   *  Constant: '<S340>/Q~_4'
   *  Product: '<S340>/Product4'
   *  Product: '<S340>/Product5'
   *  Product: '<S340>/Product6'
   *  Product: '<S340>/Product7'
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

  /* End of Sum: '<S340>/Add1' */

  /* Product: '<S340>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Subtract_cl = tmp[i + 12] * rtb_d_qGE[3] + (tmp[i + 8] * rtb_d_qGE[2] +
      (tmp[i + 4] * rtb_d_qGE[1] + tmp[i] * rtb_d_qGE[0]));
    rtb_Product4_n[i] = rtb_Subtract_cl;
  }

  /* Product: '<S326>/Product' incorporates:
   *  Math: '<S326>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac_0[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_Product4_n[2] +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_Product4_n[1] +
       rtb_MatrixMultiply_tmp[i] * rtb_Product4_n[0]);
  }

  /* End of Product: '<S326>/Product' */

  /* Gain: '<S194>/Gain3' */
  GRM_HIL_B.ACC_x_B_mDs2 = GRM_HIL_P.Gain3_Gain_df * frac_0[0];

  /* Gain: '<S194>/Gain4' */
  GRM_HIL_B.ACC_y_B_mDs2 = GRM_HIL_P.Gain4_Gain_g * frac_0[1];

  /* Gain: '<S194>/Gain5' */
  GRM_HIL_B.ACC_z_B_mDs2 = GRM_HIL_P.Gain5_Gain_n * frac_0[2];

  /* Gain: '<S194>/Gain6' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.w_x_K_IB_B_radDs = GRM_HIL_P.Gain6_Gain_a *
    GRM_HIL_X.integration_eom_CSTATE[10];

  /* Gain: '<S194>/Gain7' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.w_y_K_IB_B_radDs = GRM_HIL_P.Gain7_Gain_ia *
    GRM_HIL_X.integration_eom_CSTATE[11];

  /* Gain: '<S194>/Gain8' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.w_z_K_IB_B_radDs = GRM_HIL_P.Gain8_Gain_l1 *
    GRM_HIL_X.integration_eom_CSTATE[12];

  /* Gain: '<S194>/Gain23' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.w_x_dot_radDs2 = GRM_HIL_P.Gain23_Gain *
    GRM_HIL_X.integration_eom_CSTATE[10];

  /* Gain: '<S194>/Gain24' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.w_y_dot_radDs2 = GRM_HIL_P.Gain24_Gain *
    GRM_HIL_X.integration_eom_CSTATE[11];

  /* Gain: '<S194>/Gain25' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.w_z_dot_radDs2 = GRM_HIL_P.Gain25_Gain *
    GRM_HIL_X.integration_eom_CSTATE[12];

  /* Gain: '<S210>/1//2' */
  frac_0[0] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Phi_rad;
  frac_0[1] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Theta_rad;
  frac_0[2] = GRM_HIL_P.u2_Gain_f * GRM_HIL_B.ATT_Psi_rad;

  /* Trigonometry: '<S210>/sincos' */
  rtb_ZeroOrderHold[0] = cos(frac_0[0]);
  frac_0[0] = sin(frac_0[0]);
  rtb_ZeroOrderHold[1] = cos(frac_0[1]);
  frac_0[1] = sin(frac_0[1]);
  rtb_ZeroOrderHold[2] = cos(frac_0[2]);
  rtb_Gain2_dm_tmp = sin(frac_0[2]);

  /* Fcn: '<S210>/q0' incorporates:
   *  Fcn: '<S210>/q1'
   */
  rtb_TBG_tmp_1 = rtb_ZeroOrderHold[0] * rtb_ZeroOrderHold[1];
  rtb_TBG_tmp_2 = frac_0[0] * frac_0[1];
  GRM_HIL_B.q0_a = rtb_TBG_tmp_1 * rtb_ZeroOrderHold[2] + rtb_TBG_tmp_2 *
    rtb_Gain2_dm_tmp;

  /* Fcn: '<S210>/q1' */
  GRM_HIL_B.q1_j = rtb_TBG_tmp_1 * rtb_Gain2_dm_tmp - rtb_TBG_tmp_2 *
    rtb_ZeroOrderHold[2];

  /* Fcn: '<S210>/q2' incorporates:
   *  Fcn: '<S210>/q3'
   */
  rtb_TBG_tmp_1 = frac_0[0] * rtb_ZeroOrderHold[1];
  rtb_TBG_tmp_2 = rtb_ZeroOrderHold[0] * frac_0[1];
  GRM_HIL_B.q2_f = rtb_TBG_tmp_2 * rtb_ZeroOrderHold[2] + rtb_TBG_tmp_1 *
    rtb_Gain2_dm_tmp;

  /* Fcn: '<S210>/q3' */
  GRM_HIL_B.q3_j = rtb_TBG_tmp_1 * rtb_ZeroOrderHold[2] - rtb_TBG_tmp_2 *
    rtb_Gain2_dm_tmp;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S194>/Gain12' incorporates:
     *  Constant: '<S193>/Constant5'
     */
    GRM_HIL_B.POS_lambda_WGS84_rad = GRM_HIL_P.Gain12_Gain_b *
      GRM_HIL_P.Constant5_Value_k;

    /* Gain: '<S194>/Gain13' incorporates:
     *  Constant: '<S193>/Constant4'
     */
    GRM_HIL_B.POS_mue_WGS84_rad = GRM_HIL_P.Gain13_Gain *
      GRM_HIL_P.Constant4_Value_d;

    /* Gain: '<S194>/Gain18' incorporates:
     *  Constant: '<S193>/Constant7'
     */
    GRM_HIL_B.motor_state_perc = GRM_HIL_P.Gain18_Gain *
      GRM_HIL_P.Constant7_Value_l;
  }

  /* Gain: '<S194>/Gain14' */
  GRM_HIL_B.POS_h_WGS84_m = GRM_HIL_P.Gain14_Gain * GRM_HIL_B.Switch[2];

  /* Gain: '<S194>/Gain15' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.POS_x_NED_m = GRM_HIL_P.Gain15_Gain *
    GRM_HIL_X.integration_eom_CSTATE[0];

  /* Gain: '<S194>/Gain16' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.POS_y_NED_m = GRM_HIL_P.Gain16_Gain *
    GRM_HIL_X.integration_eom_CSTATE[1];

  /* Gain: '<S194>/Gain22' */
  GRM_HIL_B.mass_kg = GRM_HIL_P.Gain22_Gain * rtb_Subtract_ju;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S194>/Gain19' incorporates:
     *  Constant: '<S193>/Constant3'
     */
    GRM_HIL_B.VEL_u_Wind_A_E_O_mDs = GRM_HIL_P.Gain19_Gain *
      GRM_HIL_P.Constant3_Value_i;

    /* Gain: '<S194>/Gain20' incorporates:
     *  Constant: '<S193>/Constant2'
     */
    GRM_HIL_B.VEL_v_Wind_A_E_O_mDs = GRM_HIL_P.Gain20_Gain *
      GRM_HIL_P.Constant2_Value_pm;

    /* Gain: '<S194>/Gain21' incorporates:
     *  Constant: '<S193>/Constant1'
     */
    GRM_HIL_B.VEL_w_Wind_A_E_O_mDs = GRM_HIL_P.Gain21_Gain *
      GRM_HIL_P.Constant1_Value_ay;

    /* ToAsyncQueueBlock generated from: '<Root>/Simulation' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1287033222U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(152349803U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3727675641U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_x_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1120039989U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_y_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(661038555U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_z_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(597447160U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_x_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1734883718U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_y_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2367144326U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_z_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1276640874U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_x_dot_radDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3895289340U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_y_dot_radDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2066199556U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_z_dot_radDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4205680335U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(522730590U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3092216102U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4188492723U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0_a;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(193847979U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1_j;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1824299271U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2_f;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2907518382U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3_j;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2404931514U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_lambda_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3714020394U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_mue_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2740487818U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_h_WGS84_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3980315156U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_x_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2315970546U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_y_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2298037004U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_z_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2543975020U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.motor_state_perc;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(252484842U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.mass_kg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1884870U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2113530626U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1212837408U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2362669800U, time, pData, size);
      }
    }

    /* Product: '<S15>/Divide' incorporates:
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S16>/Constant1'
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S18>/Constant1'
     *  Product: '<S16>/Divide'
     *  Product: '<S17>/Divide'
     *  Product: '<S18>/Divide'
     */
    rtb_Gain2_dm_tmp = GRM_HIL_P.Servo_PWM.Pulswidth_cmd_max_ms -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms;

    /* Product: '<S15>/Multiply' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S15>/Constant2'
     *  DataTypeConversion: '<S20>/Cast To Double2'
     *  Product: '<S15>/Divide'
     *  Sum: '<S15>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[0] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Gain2_dm_tmp *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S15>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_o = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_o = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_o = u0;
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* Product: '<S16>/Multiply' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant2'
     *  DataTypeConversion: '<S20>/Cast To Double2'
     *  Product: '<S16>/Divide'
     *  Sum: '<S16>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[1] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Gain2_dm_tmp *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S16>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_c = u0;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Product: '<S17>/Multiply' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant2'
     *  DataTypeConversion: '<S20>/Cast To Double2'
     *  Product: '<S17>/Divide'
     *  Sum: '<S17>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[2] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Gain2_dm_tmp *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S17>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_j = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_j = u0;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* Product: '<S18>/Multiply' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S18>/Constant2'
     *  DataTypeConversion: '<S20>/Cast To Double2'
     *  Product: '<S18>/Divide'
     *  Sum: '<S18>/Add'
     */
    u0 = (GRM_HIL_B.ServoCMD_update[3] -
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_Gain2_dm_tmp *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S18>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_a = u0;
    }

    /* End of Saturate: '<S18>/Saturation' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator1' */
    rtb_Switch1 = (GRM_HIL_DW.clockTickCounter < GRM_HIL_P.PulseGenerator1_Duty)
      && (GRM_HIL_DW.clockTickCounter >= 0) ? GRM_HIL_P.PulseGenerator1_Amp :
      0.0;
    if (GRM_HIL_DW.clockTickCounter >= GRM_HIL_P.PulseGenerator1_Period - 1.0) {
      GRM_HIL_DW.clockTickCounter = 0;
    } else {
      GRM_HIL_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator1' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator' */
    rtb_Gain1_c = (GRM_HIL_DW.clockTickCounter_d < GRM_HIL_P.PulseGenerator_Duty)
      && (GRM_HIL_DW.clockTickCounter_d >= 0) ?
      GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.pulse.ampl_rad :
      0.0;
    if (GRM_HIL_DW.clockTickCounter_d >= GRM_HIL_P.PulseGenerator_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_d = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_d++;
    }

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator' */

    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S19>/Constant2'
     *  Product: '<S19>/Multiply'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.pulse_cmd_flg >
        GRM_HIL_P.Switch1_Threshold_mq) {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S19>/Constant12'
       *  Constant: '<S19>/Constant6'
       *  Constant: '<S19>/Constant7'
       *  Sum: '<S19>/Add'
       */
      if (GRM_HIL_P.Constant6_Value_b) {
        rtb_Switch1 += GRM_HIL_P.Constant12_Value;
      } else {
        rtb_Switch1 = GRM_HIL_P.Constant7_Value;
      }

      /* End of Switch: '<S19>/Switch3' */
      rtb_Switch1 *= rtb_Gain1_c;
    } else {
      rtb_Switch1 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.constant.phi_rad;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator4' */
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

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator4' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator3' */
    rtb_Gain1_c = (GRM_HIL_DW.clockTickCounter_e <
                   GRM_HIL_P.PulseGenerator3_Duty) &&
      (GRM_HIL_DW.clockTickCounter_e >= 0) ?
      GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.pulse.ampl_mDs2 :
      0.0;
    if (GRM_HIL_DW.clockTickCounter_e >= GRM_HIL_P.PulseGenerator3_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_e = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_e++;
    }

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator3' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant3'
     *  Product: '<S19>/Multiply1'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.pulse_cmd_flg >
        GRM_HIL_P.Switch_Threshold_p) {
      /* Switch: '<S19>/Switch4' incorporates:
       *  Constant: '<S19>/Constant13'
       *  Constant: '<S19>/Constant8'
       *  Constant: '<S19>/Constant9'
       *  Sum: '<S19>/Add1'
       */
      if (GRM_HIL_P.Constant8_Value_ej) {
        rtb_Subtract_cl += GRM_HIL_P.Constant13_Value;
      } else {
        rtb_Subtract_cl = GRM_HIL_P.Constant9_Value;
      }

      /* End of Switch: '<S19>/Switch4' */
      rtb_Gain1_c *= rtb_Subtract_cl;
    } else {
      rtb_Gain1_c =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.constant.acc_z_mDs2;
    }

    /* End of Switch: '<S19>/Switch' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator7' */
    rtb_Cx = (GRM_HIL_DW.clockTickCounter_o < GRM_HIL_P.PulseGenerator7_Duty) &&
      (GRM_HIL_DW.clockTickCounter_o >= 0) ? GRM_HIL_P.PulseGenerator7_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter_o >= GRM_HIL_P.PulseGenerator7_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_o = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_o++;
    }

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator7' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator6' */
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

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator6' */

    /* Switch: '<S19>/Switch2' incorporates:
     *  Constant: '<S19>/Constant4'
     *  Constant: '<S19>/Constant5'
     *  Product: '<S19>/Multiply2'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.pulse_cmd_flg >
        GRM_HIL_P.Switch2_Threshold_e) {
      /* Switch: '<S19>/Switch5' incorporates:
       *  Constant: '<S19>/Constant10'
       *  Constant: '<S19>/Constant11'
       *  Constant: '<S19>/Constant14'
       *  Sum: '<S19>/Add2'
       */
      if (GRM_HIL_P.Constant10_Value_ca) {
        rtb_Cx += GRM_HIL_P.Constant14_Value;
      } else {
        rtb_Cx = GRM_HIL_P.Constant11_Value;
      }

      /* End of Switch: '<S19>/Switch5' */
      rtb_Subtract_cl *= rtb_Cx;
    } else {
      rtb_Subtract_cl =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.constant.acc_y_mDs2;
    }

    /* End of Switch: '<S19>/Switch2' */

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S28>/Constant2'
     *  Constant: '<S8>/Constant10'
     *  Product: '<S28>/Divide'
     *  Product: '<S28>/Divide1'
     */
    rtb_Cx = GRM_HIL_P.Constant1_Value_bx / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant10_Value_ly - GRM_HIL_P.Constant2_Value_d1;

    /* MATLAB Function: '<S28>/Counter_with_external_limit' incorporates:
     *  Memory: '<S28>/Memory'
     */
    if (GRM_HIL_DW.Memory_PreviousInput < rtb_Cx) {
      GRM_HIL_B.value = GRM_HIL_DW.Memory_PreviousInput + 1.0;
    } else {
      GRM_HIL_B.value = 0.0;
    }

    /* End of MATLAB Function: '<S28>/Counter_with_external_limit' */

    /* Logic: '<S28>/OR' incorporates:
     *  Constant: '<S8>/Constant9'
     *  RelationalOperator: '<S28>/Equal'
     */
    GRM_HIL_B.OR = ((rtb_Cx == GRM_HIL_B.value) || GRM_HIL_P.Constant9_Value_b);

    /* DataTypeConversion: '<S22>/Data Type Conversion3' */
    GRM_HIL_B.DataTypeConversion3 = (real32_T)rtb_Switch1;

    /* DataTypeConversion: '<S22>/Data Type Conversion1' */
    GRM_HIL_B.DataTypeConversion1 = (real32_T)rtb_Subtract_cl;

    /* DataTypeConversion: '<S22>/Data Type Conversion2' */
    GRM_HIL_B.DataTypeConversion2 = (real32_T)rtb_Gain1_c;

    /* UnitDelay: '<S384>/Output' */
    rtb_FixPtSum1 = GRM_HIL_DW.Output_DSTATE;

    /* DataTypeConversion: '<S383>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S384>/Output'
     */
    GRM_HIL_B.DataTypeConversion1_p = GRM_HIL_DW.Output_DSTATE;

    /* Outputs for Enabled SubSystem: '<S22>/send_to_pix' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      if (GRM_HIL_B.OR) {
        GRM_HIL_DW.send_to_pix_MODE = true;
      } else {
        if (GRM_HIL_DW.send_to_pix_MODE) {
          /* Disable for Enabled SubSystem: '<S30>/no_CRC' */
          GRM_HIL_DW.no_CRC_MODE = false;

          /* End of Disable for SubSystem: '<S30>/no_CRC' */

          /* Disable for Enabled SubSystem: '<S30>/Send_ExternalMode' */
          GRM_HIL_DW.Send_ExternalMode_MODE = false;

          /* End of Disable for SubSystem: '<S30>/Send_ExternalMode' */
          GRM_HIL_DW.send_to_pix_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S22>/send_to_pix' */
  }

  /* MATLAB Function: '<S22>/CreateVector' incorporates:
   *  DataTypeConversion: '<S22>/Data Type Conversion10'
   *  DataTypeConversion: '<S22>/Data Type Conversion11'
   *  DataTypeConversion: '<S22>/Data Type Conversion12'
   *  DataTypeConversion: '<S22>/Data Type Conversion13'
   *  DataTypeConversion: '<S22>/Data Type Conversion5'
   *  DataTypeConversion: '<S22>/Data Type Conversion6'
   *  DataTypeConversion: '<S22>/Data Type Conversion7'
   *  DataTypeConversion: '<S22>/Data Type Conversion8'
   *  DataTypeConversion: '<S22>/Data Type Conversion9'
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

  /* Outputs for Enabled SubSystem: '<S22>/send_to_pix' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  if (GRM_HIL_DW.send_to_pix_MODE) {
    /* MATLAB Function: '<S30>/MessageAssembly' incorporates:
     *  Constant: '<S20>/Constant6'
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S30>/Constant'
     *  MATLAB Function: '<S22>/CreateVector'
     */
    if (GRM_HIL_P.Constant_Value == 1.0) {
      memcpy((void *)&x_0[0], (void *)&GRM_HIL_B.DataTypeConversion1_p,
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
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
      package[3] = GRM_HIL_P.Constant1_Value_e;
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
        GRM_HIL_B.MessageToSend[i] = 0U;
      }

      GRM_HIL_B.MessageToSend[5] = 7U;
      GRM_HIL_B.MessageToSend[6] = 7U;
      GRM_HIL_B.MessageToSend[63] = 7U;
      GRM_HIL_B.MessageToSend[64] = 7U;
      for (i = 0; i < 56; i++) {
        GRM_HIL_B.MessageToSend[i + 7] = package[i];
        GRM_HIL_B.MessageToSend[i + 65] = package[i];
      }

      GRM_HIL_B.MessageToSend[121] = 7U;
      GRM_HIL_B.MessageToSend[122] = 7U;
      for (i = 0; i < 5; i++) {
        GRM_HIL_B.MessageToSend[i + 123] = 0U;
      }
    } else {
      memset(&GRM_HIL_B.MessageToSend[0], 0, sizeof(uint8_T) << 7U);
    }

    /* End of MATLAB Function: '<S30>/MessageAssembly' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Logic: '<S30>/NOT' incorporates:
       *  Constant: '<S8>/Constant12'
       */
      GRM_HIL_B.NOT = !GRM_HIL_P.Constant12_Value_e;

      /* Outputs for Enabled SubSystem: '<S30>/no_CRC' incorporates:
       *  EnablePort: '<S34>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        GRM_HIL_DW.no_CRC_MODE = GRM_HIL_B.NOT;
      }

      /* End of Outputs for SubSystem: '<S30>/no_CRC' */
    }

    /* Outputs for Enabled SubSystem: '<S30>/no_CRC' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    if (GRM_HIL_DW.no_CRC_MODE) {
      /* Inport: '<S34>/message' */
      memcpy(&GRM_HIL_B.message[0], &GRM_HIL_B.MessageToSend[0], sizeof(uint8_T)
             << 7U);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.no_CRC_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S30>/no_CRC' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S30>/One' */
      GRM_HIL_B.One = GRM_HIL_P.One_Value;

      /* Outputs for Enabled SubSystem: '<S30>/Send_ExternalMode' incorporates:
       *  EnablePort: '<S33>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        if (GRM_HIL_B.One > 0.0) {
          if (!GRM_HIL_DW.Send_ExternalMode_MODE) {
            /* Enable for Sin: '<S33>/Sine Wave' */
            GRM_HIL_DW.systemEnable = 1;
            GRM_HIL_DW.Send_ExternalMode_MODE = true;
          }
        } else {
          GRM_HIL_DW.Send_ExternalMode_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S30>/Send_ExternalMode' */
    }

    /* Outputs for Enabled SubSystem: '<S30>/Send_ExternalMode' incorporates:
     *  EnablePort: '<S33>/Enable'
     */
    if (GRM_HIL_DW.Send_ExternalMode_MODE) {
      if (rtmIsMajorTimeStep(GRM_HIL_M) &&
          GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
        /* ToAsyncQueueBlock generated from: '<S33>/Selector1' */
        if (rtmIsMajorTimeStep(GRM_HIL_M)) {
          {
            double time = GRM_HIL_M->Timing.t[1];
            void *pData = (void *)&GRM_HIL_B.message[7];
            int32_T size = 2*sizeof(uint8_T);
            sendToAsyncQueueTgtAppSvc(2879851527U, time, pData, size);
          }
        }

        /* ToAsyncQueueBlock generated from: '<S33>/message_to_send' */
        if (rtmIsMajorTimeStep(GRM_HIL_M)) {
          {
            double time = GRM_HIL_M->Timing.t[1];
            void *pData = (void *)&GRM_HIL_B.message[0];
            int32_T size = 128*sizeof(uint8_T);
            sendToAsyncQueueTgtAppSvc(1359870183U, time, pData, size);
          }
        }
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M) &&
          GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
        /* S-Function (sldrtpo): '<S33>/Packet Output' */
        /* S-Function Block: <S33>/Packet Output */
        {
          int status = RTBIO_DriverIO(0, STREAMOUTPUT, IOSTATUS, 128U, NULL,
            NULL, NULL);
          rtb_error = (status>>1) & 0x1;/* Data Error port */
        }
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M) &&
          GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
        /* Sin: '<S33>/Sine Wave' */
        if (GRM_HIL_DW.systemEnable != 0) {
          rtb_Gain2_dm_tmp = GRM_HIL_P.SineWave_Freq_c * GRM_HIL_M->Timing.t[1];
          GRM_HIL_DW.lastSin = sin(rtb_Gain2_dm_tmp);
          GRM_HIL_DW.lastCos = cos(rtb_Gain2_dm_tmp);
          GRM_HIL_DW.systemEnable = 0;
        }

        GRM_HIL_B.SineWave = ((GRM_HIL_DW.lastSin * GRM_HIL_P.SineWave_PCos_i +
          GRM_HIL_DW.lastCos * GRM_HIL_P.SineWave_PSin_i) *
                              GRM_HIL_P.SineWave_HCos_g + (GRM_HIL_DW.lastCos *
          GRM_HIL_P.SineWave_PCos_i - GRM_HIL_DW.lastSin *
          GRM_HIL_P.SineWave_PSin_i) * GRM_HIL_P.SineWave_Hsin_e) *
          GRM_HIL_P.SineWave_Amp_c + GRM_HIL_P.SineWave_Bias_b;

        /* End of Sin: '<S33>/Sine Wave' */
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Send_ExternalMode_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S30>/Send_ExternalMode' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* ToAsyncQueueBlock generated from: '<S30>/One' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.One;
          int32_T size = 1*sizeof(real_T);
          sendToAsyncQueueTgtAppSvc(1870408404U, time, pData, size);
        }
      }

      /* ToAsyncQueueBlock generated from: '<S30>/Selector1' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.message[7];
          int32_T size = 2*sizeof(uint8_T);
          sendToAsyncQueueTgtAppSvc(3754433230U, time, pData, size);
        }
      }

      /* ToAsyncQueueBlock generated from: '<S30>/Selector' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.MessageToSend[7];
          int32_T size = 2*sizeof(uint8_T);
          sendToAsyncQueueTgtAppSvc(3676730362U, time, pData, size);
        }
      }

      /* ToAsyncQueueBlock generated from: '<S30>/SimHeartbeat' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        {
          double time = GRM_HIL_M->Timing.t[1];
          void *pData = (void *)&GRM_HIL_B.DataTypeConversion1_p;
          int32_T size = 1*sizeof(uint16_T);
          sendToAsyncQueueTgtAppSvc(4163126211U, time, pData, size);
        }
      }
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.send_to_pix_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S22>/send_to_pix' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* ToAsyncQueueBlock generated from: '<S20>/Serial_Recieve_from_Pixhawk' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.SensorACC_update[0];
        int32_T size = 3*sizeof(real32_T);
        sendToAsyncQueueTgtAppSvc(3186272768U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<S20>/Serial_Recieve_from_Pixhawk' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.SensorROT_update[0];
        int32_T size = 3*sizeof(real32_T);
        sendToAsyncQueueTgtAppSvc(4127958108U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<S21>/Receive_ExternalMode' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.AND_h;
        int32_T size = 1*sizeof(boolean_T);
        sendToAsyncQueueTgtAppSvc(9729822U, time, pData, size);
      }
    }
  }

  /* Step: '<Root>/Step1' */
  if (rtb_q_conj_e < GRM_HIL_P.Step1_Time) {
    rtb_Gain2_dm = GRM_HIL_P.Step1_Y0;
  } else {
    rtb_Gain2_dm = GRM_HIL_P.Step1_YFinal;
  }

  /* Step: '<Root>/External Moment' */
  if (rtb_q_conj_e < GRM_HIL_P.ExternalMoment_Time) {
    rtb_Switch1 = GRM_HIL_P.ExternalMoment_Y0;
  } else {
    rtb_Switch1 = GRM_HIL_P.ExternalMoment_YFinal;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  rtb_Gain1_c = (rtb_Switch1 + rtb_Gain2_dm) * GRM_HIL_P.Gain1_Gain_j2;

  /* Sin: '<Root>/Sine Wave' */
  rtb_Gain2_dm = sin(GRM_HIL_P.SineWave_Freq_d * rtb_q_conj_e +
                     GRM_HIL_P.SineWave_Phase) * GRM_HIL_P.SineWave_Amp_o +
    GRM_HIL_P.SineWave_Bias_j;

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2_dm *= GRM_HIL_P.Gain2_Gain_i2;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S38>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant7'
     *  Gain: '<S43>/Gain'
     */
    GRM_HIL_B.cmd_pass_enable_flg = (GRM_HIL_P.Gain_Gain_ez *
      GRM_HIL_P.Constant7_Value_e != 0.0);

    /* DataTypeConversion: '<S38>/Data Type Conversion1' incorporates:
     *  Constant: '<S38>/Constant'
     */
    GRM_HIL_B.emergency_stop_flg = (GRM_HIL_P.Constant_Value_oe != 0.0);
  }

  /* If: '<S175>/If' incorporates:
   *  Constant: '<S175>/Constant'
   *  Constant: '<S175>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_Product2_m >
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV);
    GRM_HIL_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_b5,
      &GRM_HIL_B.IfActionSubsystem1_l);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1_l.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S175>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.yaw_deg, &GRM_HIL_B.IfActionSubsystem_k);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem_k.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S175>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S175>/If' */

  /* If: '<S173>/If' incorporates:
   *  Constant: '<S173>/Constant'
   *  Constant: '<S173>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_Add1_p >
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchMaxV);
    GRM_HIL_DW.If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem_l;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_mt,
      &GRM_HIL_B.IfActionSubsystem1);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S173>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.pitch_deg, &GRM_HIL_B.IfActionSubsystem);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S173>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S173>/If' */

  /* If: '<S174>/If' incorporates:
   *  Constant: '<S174>/Constant'
   *  Constant: '<S174>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_Sqrt_k > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollMaxV);
    GRM_HIL_DW.If_ActiveSubsystem_g = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem_g;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_ds,
      &GRM_HIL_B.IfActionSubsystem1_n);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1_n.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.roll_deg, &GRM_HIL_B.IfActionSubsystem_f);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem_f.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S174>/If' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S53>/SumI1' incorporates:
     *  Gain: '<S53>/Integral Gain'
     *  Gain: '<S53>/Kb'
     *  Sum: '<S53>/SumI2'
     */
    GRM_HIL_B.SumI1 = (GRM_HIL_B.Merge_p - rtb_Sum_m) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Integral_Gain *
      GRM_HIL_B.pitch_err;

    /* Sum: '<S62>/SumI1' incorporates:
     *  Gain: '<S62>/Integral Gain'
     *  Gain: '<S62>/Kb'
     *  Sum: '<S62>/SumI2'
     */
    GRM_HIL_B.SumI1_n = (GRM_HIL_B.Merge_a - rtb_Sum_g) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Integral_Gain *
      GRM_HIL_B.Roll_err;

    /* Sum: '<S72>/SumI1' incorporates:
     *  Gain: '<S72>/Integral Gain'
     *  Gain: '<S72>/Kb'
     *  Sum: '<S72>/SumI2'
     */
    GRM_HIL_B.SumI1_p = (GRM_HIL_B.Merge_l - rtb_Sum_a) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Integral_Gain *
      GRM_HIL_B.Yaw_err;

    /* Logic: '<S48>/Logical Operator1' incorporates:
     *  Constant: '<S8>/Constant'
     *  Logic: '<S48>/Logical Operator'
     *  Logic: '<S50>/Logical Operator'
     */
    rtb_LogicalOperator1_c = ((!(GRM_HIL_B.IfActionSubsystem1.In1 != 0.0)) &&
      (!(GRM_HIL_B.IfActionSubsystem1_n.In1 != 0.0)) &&
      (!(GRM_HIL_B.IfActionSubsystem1_l.In1 != 0.0)) &&
      GRM_HIL_P.Constant_Value_gt);

    /* DataTypeConversion: '<S48>/Data Type Conversion' */
    GRM_HIL_B.DataTypeConversion = rtb_LogicalOperator1_c;

    /* Constant: '<S44>/Samp_Freq' */
    GRM_HIL_B.Samp_freq = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.SampFreq;

    /* Gain: '<S211>/Gain1' incorporates:
     *  Constant: '<S196>/Constant1'
     */
    rtb_VectorConcatenate_hm[0] = GRM_HIL_P.Gain1_Gain_ps *
      GRM_HIL_P.Constant1_Value_ljg;

    /* Gain: '<S212>/Gain1' incorporates:
     *  Constant: '<S196>/Constant2'
     */
    rtb_VectorConcatenate_hm[1] = GRM_HIL_P.Gain1_Gain_n3 *
      GRM_HIL_P.Constant2_Value_ff;

    /* Gain: '<S213>/Gain1' incorporates:
     *  Constant: '<S196>/Constant3'
     */
    rtb_VectorConcatenate_hm[2] = GRM_HIL_P.Gain1_Gain_g *
      GRM_HIL_P.Constant3_Value_i5;

    /* Product: '<S214>/Product' incorporates:
     *  Constant: '<S214>/Constant7'
     */
    for (i = 0; i < 4; i++) {
      GRM_HIL_B.siB_cmd[i] = 0.0;
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i] *
        rtb_VectorConcatenate_hm[0];
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i + 4] *
        rtb_VectorConcatenate_hm[1];
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i + 8] *
        rtb_VectorConcatenate_hm[2];
    }

    /* End of Product: '<S214>/Product' */

    /* Product: '<S359>/Product' incorporates:
     *  Constant: '<S359>/Constant'
     *  Constant: '<S359>/Constant6'
     */
    GRM_HIL_B.Product_a = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant6_Value_d5;
  }

  /* Sum: '<S196>/Sum' incorporates:
   *  SignalConversion generated from: '<S196>/Vector Concatenate'
   */
  rtb_q_conj[0] = GRM_HIL_B.Fin_1_Pos_rad + GRM_HIL_B.siB_cmd[0];
  rtb_q_conj[1] = GRM_HIL_B.Fin_2_Pos_rad + GRM_HIL_B.siB_cmd[1];
  rtb_q_conj[2] = GRM_HIL_B.Fin_3_Pos_rad + GRM_HIL_B.siB_cmd[2];
  rtb_q_conj_e = GRM_HIL_B.Fin_4_Pos_rad + GRM_HIL_B.siB_cmd[3];

  /* Sum: '<S361>/Add' incorporates:
   *  Constant: '<S361>/Constant2'
   */
  rtb_Cy = GRM_HIL_P.Constant2_Value_p - rtb_Cy;

  /* Sum: '<S359>/Add4' incorporates:
   *  Constant: '<S359>/Constant3'
   *  Constant: '<S359>/Constant4'
   *  Product: '<S359>/Divide'
   *  Product: '<S359>/Product1'
   *  Sum: '<S359>/Add'
   */
  frac_2[0] = (rtb_Cy * GRM_HIL_P.Constant4_Value_p + GRM_HIL_B.Product_a) *
    (1.0 / rtb_Subtract_ju) + GRM_HIL_P.Constant3_Value_fn;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S359>/Product2' incorporates:
     *  Constant: '<S359>/Constant'
     *  Constant: '<S359>/Constant5'
     */
    GRM_HIL_B.Product2 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant5_Value_e;

    /* Product: '<S359>/Product4' incorporates:
     *  Constant: '<S359>/Constant'
     *  Constant: '<S359>/Constant8'
     */
    GRM_HIL_B.Product4 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant8_Value_l5;
  }

  /* Sum: '<S359>/Add3' incorporates:
   *  Constant: '<S359>/Constant1'
   *  Constant: '<S359>/Constant7'
   *  Product: '<S359>/Divide1'
   *  Product: '<S359>/Product3'
   *  Sum: '<S359>/Add1'
   */
  frac_2[1] = (rtb_Cy * GRM_HIL_P.Constant7_Value_jc + GRM_HIL_B.Product2) *
    (1.0 / rtb_Subtract_ju) + GRM_HIL_P.Constant1_Value_in;

  /* Sum: '<S359>/Add5' incorporates:
   *  Constant: '<S359>/Constant2'
   *  Constant: '<S359>/Constant9'
   *  Product: '<S359>/Divide2'
   *  Product: '<S359>/Product5'
   *  Sum: '<S359>/Add2'
   */
  frac_2[2] = (rtb_Cy * GRM_HIL_P.Constant9_Value_cx + GRM_HIL_B.Product4) *
    (1.0 / rtb_Subtract_ju) + GRM_HIL_P.Constant2_Value_mg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S225>/Vector Concatenate' incorporates:
     *  Constant: '<S225>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[0] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S225>/Vector Concatenate' incorporates:
     *  Constant: '<S225>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[1] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S225>/Vector Concatenate' incorporates:
     *  Constant: '<S225>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[2] = GRM_HIL_P.Constant3_Value_m;

    /* Switch: '<S230>/Switch1' incorporates:
     *  Constant: '<S230>/Constant'
     *  Constant: '<S230>/Constant2'
     *  Constant: '<S231>/c_flat'
     *  Constant: '<S231>/c_rsma'
     *  Constant: '<S232>/Constant'
     *  Gain: '<S230>/Gain'
     *  Gain: '<S232>/Gain'
     *  Product: '<S232>/Product'
     *  Product: '<S232>/Product4'
     *  Product: '<S232>/Product5'
     *  Sqrt: '<S232>/Sqrt1'
     *  Sum: '<S232>/Subtract'
     *  Sum: '<S232>/Subtract1'
     *  Sum: '<S232>/Sum'
     *  Trigonometry: '<S232>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_ad > GRM_HIL_P.Switch1_Threshold_n) {
      GRM_HIL_B.hBE_0_h = GRM_HIL_P.Gain_Gain_f * GRM_HIL_P.Constant_Value_iee[2];
    } else {
      /* Sqrt: '<S233>/Sqrt' incorporates:
       *  Constant: '<S230>/Constant'
       *  Product: '<S233>/Product1'
       *  Product: '<S233>/Product2'
       *  Sqrt: '<S232>/Sqrt'
       *  Sum: '<S233>/Add'
       */
      rtb_Product2_m = sqrt(GRM_HIL_P.Constant_Value_iee[0] *
                            GRM_HIL_P.Constant_Value_iee[0] +
                            GRM_HIL_P.Constant_Value_iee[1] *
                            GRM_HIL_P.Constant_Value_iee[1]);

      /* Product: '<S233>/Product' incorporates:
       *  Constant: '<S231>/c_flat'
       *  Constant: '<S231>/c_rsma'
       *  Constant: '<S233>/Constant'
       *  Sum: '<S233>/Subtract'
       */
      rtb_Add1_p = (GRM_HIL_P.Constant_Value_f - GRM_HIL_P.c_flat_Value_f) *
        GRM_HIL_P.c_rsma_Value_b;

      /* Trigonometry: '<S233>/Trigonometric Function' incorporates:
       *  Constant: '<S230>/Constant'
       *  Constant: '<S231>/c_rsma'
       *  Product: '<S233>/Divide1'
       *  Product: '<S233>/Product6'
       *  Product: '<S233>/Product7'
       *  Sqrt: '<S233>/Sqrt'
       */
      rtb_Sqrt_k = atan(GRM_HIL_P.Constant_Value_iee[2] *
                        GRM_HIL_P.c_rsma_Value_b / (rtb_Product2_m * rtb_Add1_p));

      /* Trigonometry: '<S233>/Trigonometric Function3' */
      rtb_Switch1 = cos(rtb_Sqrt_k);

      /* Product: '<S233>/Product9' */
      rtb_Subtract_ju = rtb_Switch1 * rtb_Switch1 * rtb_Switch1;

      /* Trigonometry: '<S233>/Trigonometric Function2' */
      rtb_Sqrt_k = sin(rtb_Sqrt_k);

      /* Product: '<S233>/Product5' */
      rtb_Switch1 = rtb_Add1_p * rtb_Add1_p;

      /* Product: '<S233>/Product10' incorporates:
       *  Constant: '<S231>/c_rsma'
       *  Product: '<S233>/Divide'
       *  Product: '<S233>/Product4'
       *  Product: '<S233>/Product8'
       *  Sum: '<S233>/Subtract2'
       */
      rtb_Add1_p = (GRM_HIL_P.c_rsma_Value_b * GRM_HIL_P.c_rsma_Value_b -
                    rtb_Switch1) / rtb_Switch1 * rtb_Add1_p * (rtb_Sqrt_k *
        rtb_Sqrt_k * rtb_Sqrt_k);

      /* Sum: '<S233>/Add1' incorporates:
       *  Constant: '<S230>/Constant'
       */
      rtb_Add1_p += GRM_HIL_P.Constant_Value_iee[2];

      /* Product: '<S233>/Product3' incorporates:
       *  Constant: '<S231>/c_flat'
       *  Product: '<S232>/Product3'
       */
      rtb_Product4_e = GRM_HIL_P.c_flat_Value_f * GRM_HIL_P.c_flat_Value_f;

      /* Trigonometry: '<S233>/Trigonometric Function1' incorporates:
       *  Constant: '<S231>/c_flat'
       *  Constant: '<S231>/c_rsma'
       *  Gain: '<S233>/Gain'
       *  Product: '<S233>/Divide2'
       *  Product: '<S233>/Product11'
       *  Product: '<S233>/Product3'
       *  Sqrt: '<S233>/Sqrt'
       *  Sum: '<S233>/Subtract1'
       *  Sum: '<S233>/Subtract3'
       */
      rtb_Switch1 = atan(rtb_Add1_p / (rtb_Product2_m - (GRM_HIL_P.Gain_Gain_o *
        GRM_HIL_P.c_flat_Value_f - rtb_Product4_e) * GRM_HIL_P.c_rsma_Value_b *
        rtb_Subtract_ju));

      /* Trigonometry: '<S232>/Trigonometric Function' */
      rtb_Sqrt_k = sin(rtb_Switch1);
      GRM_HIL_B.hBE_0_h = rtb_Product2_m / cos(rtb_Switch1) -
        GRM_HIL_P.c_rsma_Value_b / sqrt(GRM_HIL_P.Constant_Value_m -
        (GRM_HIL_P.Gain_Gain_a * GRM_HIL_P.c_flat_Value_f - rtb_Product4_e) *
        (rtb_Sqrt_k * rtb_Sqrt_k));
    }

    /* End of Switch: '<S230>/Switch1' */
  }

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S218>/Constant1'
   *  Constant: '<S225>/Constant1'
   *  Constant: '<S234>/Constant'
   *  Product: '<S218>/Product1'
   *  Product: '<S234>/Product'
   *  Sum: '<S217>/Add3'
   *  Sum: '<S218>/Add'
   *  Sum: '<S225>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_p) - GRM_HIL_B.hBE_0_h >
      GRM_HIL_P.Switch_Threshold_j0) {
    /* Interpolation_n-D: '<S236>/Cn_delta_n_Interpolation' */
    frac_n[0] = rtb_DerivativeGain_j0;
    frac_n[1] = rtb_ProportionalGain_l;
    frac_n[2] = rtb_DerivativeGain_e;
    bpIndex_n[0] = rtb_k_Mach;
    bpIndex_n[1] = rtb_k_alB;
    bpIndex_n[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_n, frac_n,
      GRM_HIL_P.Cn_delta_n_Interpolation_Table,
      GRM_HIL_P.Cn_delta_n_Interpolation_dimSize);

    /* Product: '<S217>/Product33' */
    rtb_Add1_p = rtb_Gain_nv * rtb_Product2_m;

    /* Interpolation_n-D: '<S236>/Cn_delta_m_Interpolation' */
    frac_o[0] = rtb_DerivativeGain_j0;
    frac_o[1] = rtb_ProportionalGain_l;
    frac_o[2] = rtb_DerivativeGain_e;
    bpIndex_o[0] = rtb_k_Mach;
    bpIndex_o[1] = rtb_k_alB;
    bpIndex_o[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_o, frac_o,
      GRM_HIL_P.Cn_delta_m_Interpolation_Table,
      GRM_HIL_P.Cn_delta_m_Interpolation_dimSize);

    /* Product: '<S217>/Product32' */
    rtb_Sqrt_k = rtb_Gain_pu * rtb_Product2_m;

    /* Interpolation_n-D: '<S236>/Cn_delta_l_Interpolation' */
    frac_p[0] = rtb_DerivativeGain_j0;
    frac_p[1] = rtb_ProportionalGain_l;
    frac_p[2] = rtb_DerivativeGain_e;
    bpIndex_p[0] = rtb_k_Mach;
    bpIndex_p[1] = rtb_k_alB;
    bpIndex_p[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_p, frac_p,
      GRM_HIL_P.Cn_delta_l_Interpolation_Table,
      GRM_HIL_P.Cn_delta_l_Interpolation_dimSize);

    /* Product: '<S217>/Product31' */
    rtb_Switch1 = rtb_Add1 * rtb_Product2_m;

    /* Interpolation_n-D: '<S236>/Cnr_Interpolation' */
    frac_q[0] = rtb_DerivativeGain_j0;
    frac_q[1] = rtb_ProportionalGain_l;
    frac_q[2] = rtb_DerivativeGain_e;
    bpIndex_q[0] = rtb_k_Mach;
    bpIndex_q[1] = rtb_k_alB;
    bpIndex_q[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_q, frac_q,
      GRM_HIL_P.Cnr_Interpolation_Table, GRM_HIL_P.Cnr_Interpolation_dimSize);

    /* Product: '<S217>/Product36' */
    rtb_Subtract_ju = rtb_DerivativeGain * rtb_Product2_m;

    /* Interpolation_n-D: '<S236>/Cnq_Interpolation' */
    frac_r[0] = rtb_DerivativeGain_j0;
    frac_r[1] = rtb_ProportionalGain_l;
    frac_r[2] = rtb_DerivativeGain_e;
    bpIndex_r[0] = rtb_k_Mach;
    bpIndex_r[1] = rtb_k_alB;
    bpIndex_r[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_r, frac_r,
      GRM_HIL_P.Cnq_Interpolation_Table, GRM_HIL_P.Cnq_Interpolation_dimSize);

    /* Product: '<S217>/Product35' */
    rtb_Subtract_cl = rtb_ProportionalGain * rtb_Product2_m;

    /* Interpolation_n-D: '<S236>/Cnp_Interpolation' */
    frac_s[0] = rtb_DerivativeGain_j0;
    frac_s[1] = rtb_ProportionalGain_l;
    frac_s[2] = rtb_DerivativeGain_e;
    bpIndex_s[0] = rtb_k_Mach;
    bpIndex_s[1] = rtb_k_alB;
    bpIndex_s[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_s, frac_s,
      GRM_HIL_P.Cnp_Interpolation_Table, GRM_HIL_P.Cnp_Interpolation_dimSize);

    /* Product: '<S217>/Product34' */
    rtb_Cx = rtb_Add3 * rtb_Product2_m;

    /* Interpolation_n-D: '<S236>/Cn_Interpolation' */
    frac_t[0] = rtb_DerivativeGain_j0;
    frac_t[1] = rtb_ProportionalGain_l;
    frac_t[2] = rtb_DerivativeGain_e;
    bpIndex_t[0] = rtb_k_Mach;
    bpIndex_t[1] = rtb_k_alB;
    bpIndex_t[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_t, frac_t,
      GRM_HIL_P.Cn_Interpolation_Table, GRM_HIL_P.Cn_Interpolation_dimSize);

    /* Sum: '<S217>/Add5' incorporates:
     *  Constant: '<S236>/Constant'
     *  Product: '<S236>/Product'
     */
    frac_0[2] = (((((GRM_HIL_P.Constant_Value_ml * rtb_Product2_m + rtb_Cx) +
                    rtb_Subtract_cl) + rtb_Subtract_ju) + rtb_Switch1) +
                 rtb_Sqrt_k) + rtb_Add1_p;

    /* Interpolation_n-D: '<S235>/Cm_delta_n_Interpolation' */
    frac_u[0] = rtb_DerivativeGain_j0;
    frac_u[1] = rtb_ProportionalGain_l;
    frac_u[2] = rtb_DerivativeGain_e;
    bpIndex_u[0] = rtb_k_Mach;
    bpIndex_u[1] = rtb_k_alB;
    bpIndex_u[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_u, frac_u,
      GRM_HIL_P.Cm_delta_n_Interpolation_Table,
      GRM_HIL_P.Cm_delta_n_Interpolation_dimSize);

    /* Product: '<S217>/Product27' */
    rtb_Add1_p = rtb_Gain_nv * rtb_Product2_m;

    /* Interpolation_n-D: '<S235>/Cm_delta_m_Interpolation' */
    frac_v[0] = rtb_DerivativeGain_j0;
    frac_v[1] = rtb_ProportionalGain_l;
    frac_v[2] = rtb_DerivativeGain_e;
    bpIndex_v[0] = rtb_k_Mach;
    bpIndex_v[1] = rtb_k_alB;
    bpIndex_v[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_v, frac_v,
      GRM_HIL_P.Cm_delta_m_Interpolation_Table,
      GRM_HIL_P.Cm_delta_m_Interpolation_dimSize);

    /* Product: '<S217>/Product26' */
    rtb_Sqrt_k = rtb_Gain_pu * rtb_Product2_m;

    /* Interpolation_n-D: '<S235>/Cm_delta_l_Interpolation' */
    frac_w[0] = rtb_DerivativeGain_j0;
    frac_w[1] = rtb_ProportionalGain_l;
    frac_w[2] = rtb_DerivativeGain_e;
    bpIndex_w[0] = rtb_k_Mach;
    bpIndex_w[1] = rtb_k_alB;
    bpIndex_w[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_w, frac_w,
      GRM_HIL_P.Cm_delta_l_Interpolation_Table,
      GRM_HIL_P.Cm_delta_l_Interpolation_dimSize);

    /* Product: '<S217>/Product25' */
    rtb_Switch1 = rtb_Add1 * rtb_Product2_m;

    /* Interpolation_n-D: '<S235>/Cmr_Interpolation' */
    frac_x[0] = rtb_DerivativeGain_j0;
    frac_x[1] = rtb_ProportionalGain_l;
    frac_x[2] = rtb_DerivativeGain_e;
    bpIndex_x[0] = rtb_k_Mach;
    bpIndex_x[1] = rtb_k_alB;
    bpIndex_x[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_x, frac_x,
      GRM_HIL_P.Cmr_Interpolation_Table, GRM_HIL_P.Cmr_Interpolation_dimSize);

    /* Product: '<S217>/Product30' */
    rtb_Subtract_ju = rtb_DerivativeGain * rtb_Product2_m;

    /* Interpolation_n-D: '<S235>/Cmq_Interpolation' */
    frac_y[0] = rtb_DerivativeGain_j0;
    frac_y[1] = rtb_ProportionalGain_l;
    frac_y[2] = rtb_DerivativeGain_e;
    bpIndex_y[0] = rtb_k_Mach;
    bpIndex_y[1] = rtb_k_alB;
    bpIndex_y[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_y, frac_y,
      GRM_HIL_P.Cmq_Interpolation_Table, GRM_HIL_P.Cmq_Interpolation_dimSize);

    /* Product: '<S217>/Product29' */
    rtb_Subtract_cl = rtb_ProportionalGain * rtb_Product2_m;

    /* Interpolation_n-D: '<S235>/Cmp_Interpolation' */
    frac_z[0] = rtb_DerivativeGain_j0;
    frac_z[1] = rtb_ProportionalGain_l;
    frac_z[2] = rtb_DerivativeGain_e;
    bpIndex_z[0] = rtb_k_Mach;
    bpIndex_z[1] = rtb_k_alB;
    bpIndex_z[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_z, frac_z,
      GRM_HIL_P.Cmp_Interpolation_Table, GRM_HIL_P.Cmp_Interpolation_dimSize);

    /* Product: '<S217>/Product28' */
    rtb_Cx = rtb_Add3 * rtb_Product2_m;

    /* Interpolation_n-D: '<S235>/Cm_Interpolation' */
    frac_10[0] = rtb_DerivativeGain_j0;
    frac_10[1] = rtb_ProportionalGain_l;
    frac_10[2] = rtb_DerivativeGain_e;
    bpIndex_10[0] = rtb_k_Mach;
    bpIndex_10[1] = rtb_k_alB;
    bpIndex_10[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_10, frac_10,
      GRM_HIL_P.Cm_Interpolation_Table, GRM_HIL_P.Cm_Interpolation_dimSize);

    /* Sum: '<S217>/Add4' incorporates:
     *  Constant: '<S235>/Constant'
     *  Product: '<S235>/Product'
     */
    frac_0[1] = (((((GRM_HIL_P.Constant_Value_jm * rtb_Product2_m + rtb_Cx) +
                    rtb_Subtract_cl) + rtb_Subtract_ju) + rtb_Switch1) +
                 rtb_Sqrt_k) + rtb_Add1_p;

    /* Interpolation_n-D: '<S234>/Cl_delta_n_Interpolation' */
    frac_11[0] = rtb_DerivativeGain_j0;
    frac_11[1] = rtb_ProportionalGain_l;
    frac_11[2] = rtb_DerivativeGain_e;
    bpIndex_11[0] = rtb_k_Mach;
    bpIndex_11[1] = rtb_k_alB;
    bpIndex_11[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_11, frac_11,
      GRM_HIL_P.Cl_delta_n_Interpolation_Table,
      GRM_HIL_P.Cl_delta_n_Interpolation_dimSize);

    /* Product: '<S217>/Product21' */
    rtb_Gain_nv *= rtb_Product2_m;

    /* Interpolation_n-D: '<S234>/Cl_delta_m_Interpolation' */
    frac_12[0] = rtb_DerivativeGain_j0;
    frac_12[1] = rtb_ProportionalGain_l;
    frac_12[2] = rtb_DerivativeGain_e;
    bpIndex_12[0] = rtb_k_Mach;
    bpIndex_12[1] = rtb_k_alB;
    bpIndex_12[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_12, frac_12,
      GRM_HIL_P.Cl_delta_m_Interpolation_Table,
      GRM_HIL_P.Cl_delta_m_Interpolation_dimSize);

    /* Product: '<S217>/Product20' */
    rtb_Gain_pu *= rtb_Product2_m;

    /* Interpolation_n-D: '<S234>/Cl_delta_l_Interpolation' */
    frac_13[0] = rtb_DerivativeGain_j0;
    frac_13[1] = rtb_ProportionalGain_l;
    frac_13[2] = rtb_DerivativeGain_e;
    bpIndex_13[0] = rtb_k_Mach;
    bpIndex_13[1] = rtb_k_alB;
    bpIndex_13[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_13, frac_13,
      GRM_HIL_P.Cl_delta_l_Interpolation_Table,
      GRM_HIL_P.Cl_delta_l_Interpolation_dimSize);

    /* Product: '<S217>/Product19' */
    rtb_Add1 *= rtb_Product2_m;

    /* Interpolation_n-D: '<S234>/Clr_Interpolation' */
    frac_14[0] = rtb_DerivativeGain_j0;
    frac_14[1] = rtb_ProportionalGain_l;
    frac_14[2] = rtb_DerivativeGain_e;
    bpIndex_14[0] = rtb_k_Mach;
    bpIndex_14[1] = rtb_k_alB;
    bpIndex_14[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_14, frac_14,
      GRM_HIL_P.Clr_Interpolation_Table, GRM_HIL_P.Clr_Interpolation_dimSize);

    /* Product: '<S217>/Product24' */
    rtb_DerivativeGain *= rtb_Product2_m;

    /* Interpolation_n-D: '<S234>/Clq_Interpolation' */
    frac_15[0] = rtb_DerivativeGain_j0;
    frac_15[1] = rtb_ProportionalGain_l;
    frac_15[2] = rtb_DerivativeGain_e;
    bpIndex_15[0] = rtb_k_Mach;
    bpIndex_15[1] = rtb_k_alB;
    bpIndex_15[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_15, frac_15,
      GRM_HIL_P.Clq_Interpolation_Table, GRM_HIL_P.Clq_Interpolation_dimSize);

    /* Product: '<S217>/Product23' */
    rtb_ProportionalGain *= rtb_Product2_m;

    /* Interpolation_n-D: '<S234>/Clp_Interpolation' */
    frac_16[0] = rtb_DerivativeGain_j0;
    frac_16[1] = rtb_ProportionalGain_l;
    frac_16[2] = rtb_DerivativeGain_e;
    bpIndex_16[0] = rtb_k_Mach;
    bpIndex_16[1] = rtb_k_alB;
    bpIndex_16[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_16, frac_16,
      GRM_HIL_P.Clp_Interpolation_Table, GRM_HIL_P.Clp_Interpolation_dimSize);

    /* Product: '<S217>/Product22' */
    rtb_Add3 *= rtb_Product2_m;

    /* Interpolation_n-D: '<S234>/Cl_Interpolation' */
    frac_17[0] = rtb_DerivativeGain_j0;
    frac_17[1] = rtb_ProportionalGain_l;
    frac_17[2] = rtb_DerivativeGain_e;
    bpIndex_17[0] = rtb_k_Mach;
    bpIndex_17[1] = rtb_k_alB;
    bpIndex_17[2] = rtb_k_beB;
    rtb_Product2_m = intrp3d_l_pw(bpIndex_17, frac_17,
      GRM_HIL_P.Cl_Interpolation_Table, GRM_HIL_P.Cl_Interpolation_dimSize);

    /* Product: '<S218>/Product1' incorporates:
     *  Constant: '<S218>/Constant1'
     */
    rtb_ZeroOrderHold[1] = rtb_Abs_n * frac_0[1] * GRM_HIL_P.Constant1_Value_bk;
    rtb_ZeroOrderHold[2] = rtb_Abs_n * frac_0[2] * GRM_HIL_P.Constant1_Value_bk;

    /* Sum: '<S223>/Sum2' incorporates:
     *  Product: '<S223>/Product6'
     *  Product: '<S223>/Product7'
     */
    frac_0[2] = frac_2[0] * frac_1[1] - frac_2[1] * frac_1[0];

    /* Sum: '<S223>/Sum1' incorporates:
     *  Product: '<S223>/Product4'
     *  Product: '<S223>/Product5'
     */
    frac_0[1] = frac_2[2] * frac_1[0] - frac_2[0] * frac_1[2];

    /* Sum: '<S223>/Sum' incorporates:
     *  Product: '<S223>/Product2'
     *  Product: '<S223>/Product3'
     */
    frac_0[0] = frac_2[1] * frac_1[2] - frac_2[2] * frac_1[1];
    frac_0[0] += ((((((GRM_HIL_P.Constant_Value_e0 * rtb_Product2_m + rtb_Add3)
                      + rtb_ProportionalGain) + rtb_DerivativeGain) + rtb_Add1)
                   + rtb_Gain_pu) + rtb_Gain_nv) * rtb_Abs_n *
      GRM_HIL_P.Constant1_Value_bk;
    frac_0[1] += rtb_ZeroOrderHold[1];
    frac_0[2] += rtb_ZeroOrderHold[2];
  } else {
    frac_0[0] = GRM_HIL_B.VectorConcatenate_e[0];
    frac_0[1] = GRM_HIL_B.VectorConcatenate_e[1];
    frac_0[2] = GRM_HIL_B.VectorConcatenate_e[2];
  }

  /* End of Switch: '<S225>/Switch' */

  /* RelationalOperator: '<S257>/Compare' incorporates:
   *  Constant: '<S257>/Constant'
   */
  GRM_HIL_B.Compare_k = (rtb_jxk >= GRM_HIL_P.CompareToConstant_const_i);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S254>/Assertion' */
    utAssert(GRM_HIL_B.Compare_k);
  }

  /* Logic: '<S258>/AND' incorporates:
   *  Constant: '<S258>/Lower Limit'
   *  Constant: '<S258>/Upper Limit'
   *  RelationalOperator: '<S258>/Lower Test'
   *  RelationalOperator: '<S258>/Upper Test'
   */
  GRM_HIL_B.AND = ((GRM_HIL_P.IntervalTest_lowlimit <= GRM_HIL_B.Switch[0]) &&
                   (GRM_HIL_B.Switch[0] <= GRM_HIL_P.IntervalTest_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S254>/Assertion1' */
    utAssert(GRM_HIL_B.AND);
  }

  /* Logic: '<S259>/AND' incorporates:
   *  Constant: '<S259>/Lower Limit'
   *  Constant: '<S259>/Upper Limit'
   *  RelationalOperator: '<S259>/Lower Test'
   *  RelationalOperator: '<S259>/Upper Test'
   */
  GRM_HIL_B.AND_i = ((GRM_HIL_P.IntervalTest1_lowlimit <= GRM_HIL_B.Switch[1]) &&
                     (GRM_HIL_B.Switch[1] <= GRM_HIL_P.IntervalTest1_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S254>/Assertion2' */
    utAssert(GRM_HIL_B.AND_i);
  }

  /* Integrator: '<S270>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE,
                       (GRM_HIL_B.sat));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_h = GRM_HIL_P.Rudder_d_siB_0;
    }
  }

  rtb_d_siB = GRM_HIL_X.Integrator_CSTATE_h;

  /* End of Integrator: '<S270>/Integrator' */

  /* MATLAB Function: '<S270>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB, rtb_d_siB, &GRM_HIL_B.sf_Limiting_Rate,
                        GRM_HIL_P.Rudder_d_siB_max, GRM_HIL_P.Rudder_d_siB_min,
                        GRM_HIL_P.Rudder_siB_max, GRM_HIL_P.Rudder_siB_min);

  /* Integrator: '<S271>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h,
                       (GRM_HIL_B.sat_c));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_ep = GRM_HIL_P.Rudder1_d_siB_0;
    }
  }

  rtb_d_siB_l = GRM_HIL_X.Integrator_CSTATE_ep;

  /* End of Integrator: '<S271>/Integrator' */

  /* MATLAB Function: '<S271>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_d, rtb_d_siB_l, &GRM_HIL_B.sf_Limiting_Rate_o,
                        GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
                        GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Integrator: '<S272>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k,
                       (GRM_HIL_B.sat_a));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;
    }
  }

  rtb_d_siB_f = GRM_HIL_X.Integrator_CSTATE_f;

  /* End of Integrator: '<S272>/Integrator' */

  /* MATLAB Function: '<S272>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_i, rtb_d_siB_f, &GRM_HIL_B.sf_Limiting_Rate_g,
                        GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
                        GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Integrator: '<S273>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n,
                       (GRM_HIL_B.sat_o));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_gp = GRM_HIL_P.Rudder3_d_siB_0;
    }
  }

  rtb_d_siB_k = GRM_HIL_X.Integrator_CSTATE_gp;

  /* End of Integrator: '<S273>/Integrator' */

  /* MATLAB Function: '<S273>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_o, rtb_d_siB_k, &GRM_HIL_B.sf_Limiting_Rate_d,
                        GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
                        GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Saturate: '<S270>/Saturation' */
  if (rtb_q_conj[0] > GRM_HIL_P.Rudder_siB_max) {
    rtb_Product2_m = GRM_HIL_P.Rudder_siB_max;
  } else if (rtb_q_conj[0] < GRM_HIL_P.Rudder_siB_min) {
    rtb_Product2_m = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_Product2_m = rtb_q_conj[0];
  }

  /* End of Saturate: '<S270>/Saturation' */

  /* Sum: '<S270>/Add1' incorporates:
   *  Gain: '<S270>/Gain'
   *  Gain: '<S270>/Gain2'
   *  Integrator: '<S270>/Integrator1'
   *  Sum: '<S270>/Add'
   */
  rtb_dd_siB = (rtb_Product2_m - GRM_HIL_X.Integrator1_CSTATE) *
    GRM_HIL_P.Gain_Gain_oz - 2.0 * GRM_HIL_P.Rudder_dmp * GRM_HIL_P.Rudder_omega
    * rtb_d_siB;

  /* MATLAB Function: '<S270>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB, GRM_HIL_B.sf_Limiting_Rate.d_siB_l,
    rtb_dd_siB, &GRM_HIL_B.sf_Limiting_Acceleration, GRM_HIL_P.Rudder_d_siB_max,
    GRM_HIL_P.Rudder_d_siB_min, GRM_HIL_P.Rudder_dd_siB_max,
    GRM_HIL_P.Rudder_dd_siB_min, GRM_HIL_P.Rudder_siB_max,
    GRM_HIL_P.Rudder_siB_min);

  /* Saturate: '<S271>/Saturation' */
  if (rtb_q_conj[1] > GRM_HIL_P.Rudder1_siB_max) {
    rtb_Product2_m = GRM_HIL_P.Rudder1_siB_max;
  } else if (rtb_q_conj[1] < GRM_HIL_P.Rudder1_siB_min) {
    rtb_Product2_m = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_Product2_m = rtb_q_conj[1];
  }

  /* End of Saturate: '<S271>/Saturation' */

  /* Sum: '<S271>/Add1' incorporates:
   *  Gain: '<S271>/Gain'
   *  Gain: '<S271>/Gain2'
   *  Integrator: '<S271>/Integrator1'
   *  Sum: '<S271>/Add'
   */
  rtb_dd_siB_c = (rtb_Product2_m - GRM_HIL_X.Integrator1_CSTATE_g) *
    GRM_HIL_P.Gain_Gain_a3 - 2.0 * GRM_HIL_P.Rudder1_dmp *
    GRM_HIL_P.Rudder1_omega * rtb_d_siB_l;

  /* MATLAB Function: '<S271>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_d, GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l,
    rtb_dd_siB_c, &GRM_HIL_B.sf_Limiting_Acceleration_i,
    GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
    GRM_HIL_P.Rudder1_dd_siB_max, GRM_HIL_P.Rudder1_dd_siB_min,
    GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Saturate: '<S272>/Saturation' */
  if (rtb_q_conj[2] > GRM_HIL_P.Rudder2_siB_max) {
    rtb_Product2_m = GRM_HIL_P.Rudder2_siB_max;
  } else if (rtb_q_conj[2] < GRM_HIL_P.Rudder2_siB_min) {
    rtb_Product2_m = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_Product2_m = rtb_q_conj[2];
  }

  /* End of Saturate: '<S272>/Saturation' */

  /* Sum: '<S272>/Add1' incorporates:
   *  Gain: '<S272>/Gain'
   *  Gain: '<S272>/Gain2'
   *  Integrator: '<S272>/Integrator1'
   *  Sum: '<S272>/Add'
   */
  rtb_dd_siB_o = (rtb_Product2_m - GRM_HIL_X.Integrator1_CSTATE_a) *
    GRM_HIL_P.Gain_Gain_hm - 2.0 * GRM_HIL_P.Rudder2_dmp *
    GRM_HIL_P.Rudder2_omega * rtb_d_siB_f;

  /* MATLAB Function: '<S272>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_i, GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l,
    rtb_dd_siB_o, &GRM_HIL_B.sf_Limiting_Acceleration_p,
    GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
    GRM_HIL_P.Rudder2_dd_siB_max, GRM_HIL_P.Rudder2_dd_siB_min,
    GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Saturate: '<S273>/Saturation' */
  if (rtb_q_conj_e > GRM_HIL_P.Rudder3_siB_max) {
    rtb_q_conj_e = GRM_HIL_P.Rudder3_siB_max;
  } else {
    if (rtb_q_conj_e < GRM_HIL_P.Rudder3_siB_min) {
      rtb_q_conj_e = GRM_HIL_P.Rudder3_siB_min;
    }
  }

  /* End of Saturate: '<S273>/Saturation' */

  /* Sum: '<S273>/Add1' incorporates:
   *  Gain: '<S273>/Gain'
   *  Gain: '<S273>/Gain2'
   *  Integrator: '<S273>/Integrator1'
   *  Sum: '<S273>/Add'
   */
  rtb_dd_siB_od = (rtb_q_conj_e - GRM_HIL_X.Integrator1_CSTATE_i) *
    GRM_HIL_P.Gain_Gain_do - 2.0 * GRM_HIL_P.Rudder3_dmp *
    GRM_HIL_P.Rudder3_omega * rtb_d_siB_k;

  /* MATLAB Function: '<S273>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_o, GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l,
    rtb_dd_siB_od, &GRM_HIL_B.sf_Limiting_Acceleration_h,
    GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
    GRM_HIL_P.Rudder3_dd_siB_max, GRM_HIL_P.Rudder3_dd_siB_min,
    GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Sum: '<S314>/Subtract' incorporates:
   *  Constant: '<S314>/pNPB'
   */
  rtb_ZeroOrderHold[0] = frac_2[0] - GRM_HIL_P.pNPB_Value[0];
  rtb_ZeroOrderHold[1] = frac_2[1] - GRM_HIL_P.pNPB_Value[1];
  rtb_ZeroOrderHold[2] = frac_2[2] - GRM_HIL_P.pNPB_Value[2];

  /* Sum: '<S200>/Add1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Product: '<S316>/Product2'
   *  Product: '<S316>/Product3'
   *  Product: '<S316>/Product4'
   *  Product: '<S316>/Product5'
   *  Product: '<S316>/Product6'
   *  Product: '<S316>/Product7'
   *  Sum: '<S316>/Sum'
   *  Sum: '<S316>/Sum1'
   *  Sum: '<S316>/Sum2'
   */
  frac_0[0] = ((rtb_ZeroOrderHold[1] * frac[2] - rtb_ZeroOrderHold[2] * frac[1])
               + frac_0[0]) + rtb_Gain1_c;
  frac_0[1] = ((rtb_ZeroOrderHold[2] * frac[0] - rtb_ZeroOrderHold[0] * frac[2])
               + frac_0[1]) + GRM_HIL_P.Constant_Value_ko;
  frac_0[2] = ((rtb_ZeroOrderHold[0] * frac[1] - rtb_ZeroOrderHold[1] * frac[0])
               + frac_0[2]) + rtb_Gain2_dm;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S290>/Gain' */
    rtb_VectorConcatenate_hm[0] = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[0];
    rtb_VectorConcatenate_hm[1] = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[1];
    rtb_VectorConcatenate_hm[2] = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[2];

    /* Sum: '<S305>/Add' incorporates:
     *  Constant: '<S305>/Constant8'
     *  Constant: '<S305>/Q_1'
     *  Constant: '<S305>/Q_2'
     *  Constant: '<S305>/Q_3'
     *  Constant: '<S305>/Q_4'
     *  Product: '<S305>/Product1'
     *  Product: '<S305>/Product2'
     *  Product: '<S305>/Product3'
     *  Product: '<S305>/Product4'
     *  SignalConversion generated from: '<S305>/Vector Concatenate'
     */
    for (i = 0; i < 16; i++) {
      GRM_HIL_B.Add[i] = ((GRM_HIL_P.Q_1_Value_o[i] * rtb_VectorConcatenate_hm[0]
                           + GRM_HIL_P.Q_2_Value_b[i] *
                           rtb_VectorConcatenate_hm[1]) +
                          GRM_HIL_P.Q_3_Value_j[i] * rtb_VectorConcatenate_hm[2])
        + GRM_HIL_P.Q_4_Value_d[i] * GRM_HIL_P.Constant8_Value_h;
    }

    /* End of Sum: '<S305>/Add' */
  }

  /* Gain: '<S307>/Gain1' incorporates:
   *  Integrator: '<S302>/integration_eom'
   */
  rtb_d_qGE[0] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[0];
  rtb_d_qGE[1] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[1];
  rtb_d_qGE[2] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[2];
  for (i = 0; i < 4; i++) {
    /* Product: '<S305>/Product5' incorporates:
     *  Integrator: '<S302>/integration_eom'
     */
    rtb_q_conj_e = GRM_HIL_B.Add[i + 12] * GRM_HIL_X.integration_eom_CSTATE_b[3]
      + (GRM_HIL_B.Add[i + 8] * rtb_d_qGE[2] + (GRM_HIL_B.Add[i + 4] *
          rtb_d_qGE[1] + GRM_HIL_B.Add[i] * rtb_d_qGE[0]));

    /* Gain: '<S305>/Gain' */
    rtb_q_conj[i] = GRM_HIL_P.Gain_Gain_e4 * rtb_q_conj_e;
  }

  /* SignalConversion generated from: '<S308>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_m[3] = rtb_q_conj[3];

  /* Gain: '<S308>/Gain1' */
  GRM_HIL_B.VectorConcatenate_m[0] = GRM_HIL_P.Gain1_Gain_in * rtb_q_conj[0];
  GRM_HIL_B.VectorConcatenate_m[1] = GRM_HIL_P.Gain1_Gain_in * rtb_q_conj[1];
  GRM_HIL_B.VectorConcatenate_m[2] = GRM_HIL_P.Gain1_Gain_in * rtb_q_conj[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S304>/Vector Concatenate1' incorporates:
     *  Constant: '<S304>/Constant8'
     */
    GRM_HIL_B.wEGG[0] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S304>/Vector Concatenate1' incorporates:
     *  Constant: '<S304>/Constant8'
     */
    GRM_HIL_B.wEGG[1] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S304>/Vector Concatenate1' incorporates:
     *  Constant: '<S304>/Constant8'
     */
    GRM_HIL_B.wEGG[2] = GRM_HIL_P.Constant8_Value_ck;
  }

  /* Derivative: '<S304>/Derivative1' */
  if ((GRM_HIL_DW.TimeStampA >= rtb_ProportionalGain_a) &&
      (GRM_HIL_DW.TimeStampB >= rtb_ProportionalGain_a)) {
    rtb_jxk = 0.0;
  } else {
    rtb_DerivativeGain_j0 = GRM_HIL_DW.TimeStampA;
    lastU = &GRM_HIL_DW.LastUAtTimeA;
    if (GRM_HIL_DW.TimeStampA < GRM_HIL_DW.TimeStampB) {
      if (GRM_HIL_DW.TimeStampB < rtb_ProportionalGain_a) {
        rtb_DerivativeGain_j0 = GRM_HIL_DW.TimeStampB;
        lastU = &GRM_HIL_DW.LastUAtTimeB;
      }
    } else {
      if (GRM_HIL_DW.TimeStampA >= rtb_ProportionalGain_a) {
        rtb_DerivativeGain_j0 = GRM_HIL_DW.TimeStampB;
        lastU = &GRM_HIL_DW.LastUAtTimeB;
      }
    }

    rtb_jxk = (GRM_HIL_B.Switch[0] - *lastU) / (rtb_ProportionalGain_a -
      rtb_DerivativeGain_j0);
  }

  /* Derivative: '<S304>/Derivative' */
  if ((GRM_HIL_DW.TimeStampA_b >= rtb_ProportionalGain_a) &&
      (GRM_HIL_DW.TimeStampB_j >= rtb_ProportionalGain_a)) {
    rtb_ProportionalGain_a = 0.0;
  } else {
    rtb_DerivativeGain_j0 = GRM_HIL_DW.TimeStampA_b;
    lastU = &GRM_HIL_DW.LastUAtTimeA_b;
    if (GRM_HIL_DW.TimeStampA_b < GRM_HIL_DW.TimeStampB_j) {
      if (GRM_HIL_DW.TimeStampB_j < rtb_ProportionalGain_a) {
        rtb_DerivativeGain_j0 = GRM_HIL_DW.TimeStampB_j;
        lastU = &GRM_HIL_DW.LastUAtTimeB_p;
      }
    } else {
      if (GRM_HIL_DW.TimeStampA_b >= rtb_ProportionalGain_a) {
        rtb_DerivativeGain_j0 = GRM_HIL_DW.TimeStampB_j;
        lastU = &GRM_HIL_DW.LastUAtTimeB_p;
      }
    }

    rtb_ProportionalGain_a = (GRM_HIL_B.Switch[1] - *lastU) /
      (rtb_ProportionalGain_a - rtb_DerivativeGain_j0);
  }

  /* Switch: '<S304>/Switch' incorporates:
   *  Constant: '<S304>/Constant9'
   */
  if (GRM_HIL_P.Constant9_Value_l > GRM_HIL_P.Switch_Threshold_m) {
    frac[0] = GRM_HIL_B.wEGG[0];
    frac[1] = GRM_HIL_B.wEGG[1];
    frac[2] = GRM_HIL_B.wEGG[2];
  } else {
    /* Gain: '<S304>/Gain2' incorporates:
     *  Product: '<S304>/Product'
     */
    frac[2] = rtb_jxi * rtb_jxk * GRM_HIL_P.Gain2_Gain_k;

    /* Gain: '<S304>/Gain1' */
    frac[1] = GRM_HIL_P.Gain1_Gain * rtb_ProportionalGain_a;

    /* Product: '<S304>/Product1' */
    frac[0] = rtb_jxk * q0_tmp;
  }

  /* Gain: '<S290>/Gain1' */
  frac[0] *= GRM_HIL_P.Gain1_Gain_k;
  frac[1] *= GRM_HIL_P.Gain1_Gain_k;

  /* SignalConversion generated from: '<S309>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[0] = frac[0];

  /* SignalConversion generated from: '<S309>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[1] = frac[1];

  /* SignalConversion generated from: '<S309>/Vector Concatenate' incorporates:
   *  Gain: '<S290>/Gain1'
   */
  GRM_HIL_B.VectorConcatenate_a[2] = GRM_HIL_P.Gain1_Gain_k * frac[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S309>/Constant8' */
    GRM_HIL_B.VectorConcatenate_a[3] = GRM_HIL_P.Constant8_Value_p;
  }

  /* Gain: '<S311>/Gain1' incorporates:
   *  Integrator: '<S303>/integration_eom'
   */
  rtb_d_qBI[0] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[0];
  rtb_d_qBI[1] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[1];
  rtb_d_qBI[2] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[2];

  /* Sum: '<S309>/Add' incorporates:
   *  Constant: '<S309>/Q_1'
   *  Constant: '<S309>/Q_2'
   *  Constant: '<S309>/Q_3'
   *  Constant: '<S309>/Q_4'
   *  Product: '<S309>/Product1'
   *  Product: '<S309>/Product2'
   *  Product: '<S309>/Product3'
   *  Product: '<S309>/Product4'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_h[i] * GRM_HIL_B.VectorConcatenate_a[0] +
               GRM_HIL_P.Q_2_Value_g[i] * GRM_HIL_B.VectorConcatenate_a[1]) +
              GRM_HIL_P.Q_3_Value_oc[i] * GRM_HIL_B.VectorConcatenate_a[2]) +
      GRM_HIL_P.Q_4_Value_ea[i] * GRM_HIL_B.VectorConcatenate_a[3];
  }

  /* End of Sum: '<S309>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S309>/Product5' incorporates:
     *  Integrator: '<S303>/integration_eom'
     */
    rtb_q_conj_e = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] + (tmp[i
      + 8] * rtb_d_qBI[2] + (tmp[i + 4] * rtb_d_qBI[1] + tmp[i] * rtb_d_qBI[0]));

    /* Gain: '<S309>/Gain' */
    rtb_d_qGE[i] = GRM_HIL_P.Gain_Gain_ba * rtb_q_conj_e;
  }

  /* SignalConversion generated from: '<S312>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_k[3] = rtb_d_qGE[3];

  /* Gain: '<S312>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[0] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[0];

  /* SignalConversion generated from: '<S334>/Vector Concatenate' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.d_x[0] = GRM_HIL_X.integration_eom_CSTATE[3];

  /* SignalConversion generated from: '<S334>/Vector Concatenate' */
  GRM_HIL_B.d_x[3] = rtb_Product4_n[0];

  /* Gain: '<S312>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[1] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[1];

  /* SignalConversion generated from: '<S334>/Vector Concatenate' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.d_x[1] = GRM_HIL_X.integration_eom_CSTATE[4];

  /* SignalConversion generated from: '<S334>/Vector Concatenate' */
  GRM_HIL_B.d_x[4] = rtb_Product4_n[1];

  /* Gain: '<S312>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[2] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[2];

  /* SignalConversion generated from: '<S334>/Vector Concatenate' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.d_x[2] = GRM_HIL_X.integration_eom_CSTATE[5];

  /* SignalConversion generated from: '<S334>/Vector Concatenate' */
  GRM_HIL_B.d_x[5] = rtb_Product4_n[2];

  /* SignalConversion generated from: '<S338>/Vector Concatenate' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[0] = GRM_HIL_X.integration_eom_CSTATE[10];

  /* SignalConversion generated from: '<S338>/Vector Concatenate' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[1] = GRM_HIL_X.integration_eom_CSTATE[11];

  /* SignalConversion generated from: '<S338>/Vector Concatenate' incorporates:
   *  Integrator: '<S334>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[2] = GRM_HIL_X.integration_eom_CSTATE[12];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S338>/Constant' */
    GRM_HIL_B.VectorConcatenate_p[3] = GRM_HIL_P.Constant_Value_lp;
  }

  /* Gain: '<S341>/Gain1' */
  rtb_Product4_n[0] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_0;
  rtb_Product4_n[1] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_1;
  rtb_Product4_n[2] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_2;

  /* Sum: '<S338>/Add' incorporates:
   *  Constant: '<S338>/Q_1'
   *  Constant: '<S338>/Q_2'
   *  Constant: '<S338>/Q_3'
   *  Constant: '<S338>/Q_4'
   *  Product: '<S338>/Product2'
   *  Product: '<S338>/Product3'
   *  Product: '<S338>/Product4'
   *  Product: '<S338>/Product5'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_f[i] * GRM_HIL_B.VectorConcatenate_p[0] +
               GRM_HIL_P.Q_2_Value_n1[i] * GRM_HIL_B.VectorConcatenate_p[1]) +
              GRM_HIL_P.Q_3_Value_a[i] * GRM_HIL_B.VectorConcatenate_p[2]) +
      GRM_HIL_P.Q_4_Value_b[i] * GRM_HIL_B.VectorConcatenate_p[3];
  }

  /* End of Sum: '<S338>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S338>/Product6' incorporates:
     *  SignalConversion generated from: '<S341>/Vector Concatenate'
     */
    rtb_q_conj_e = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_Product4_n[2] + (tmp[i + 4] * rtb_Product4_n[1] + tmp[i] *
      rtb_Product4_n[0]));

    /* Gain: '<S338>/Gain' */
    rtb_d_qBI[i] = GRM_HIL_P.Gain_Gain_pq * rtb_q_conj_e;
  }

  /* SignalConversion generated from: '<S342>/Vector Concatenate' */
  GRM_HIL_B.d_x[9] = rtb_d_qBI[3];

  /* Gain: '<S342>/Gain1' */
  GRM_HIL_B.d_x[6] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[0];

  /* Sum: '<S368>/Subtract' incorporates:
   *  Constant: '<S368>/Constant17'
   */
  frac[0] = frac_2[0] - GRM_HIL_P.Constant17_Value[0];

  /* Gain: '<S342>/Gain1' */
  GRM_HIL_B.d_x[7] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[1];

  /* Sum: '<S368>/Subtract' incorporates:
   *  Constant: '<S368>/Constant17'
   */
  frac[1] = frac_2[1] - GRM_HIL_P.Constant17_Value[1];

  /* Gain: '<S342>/Gain1' */
  GRM_HIL_B.d_x[8] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[2];

  /* Sum: '<S368>/Subtract' incorporates:
   *  Constant: '<S368>/Constant17'
   */
  frac[2] = frac_2[2] - GRM_HIL_P.Constant17_Value[2];

  /* Product: '<S380>/Product1' */
  rtb_jxk = frac[1] * frac[1];

  /* Product: '<S380>/Product2' */
  rtb_ProportionalGain = frac[2] * frac[2];

  /* Sum: '<S380>/Add' */
  rtb_JBBB[0] = rtb_jxk + rtb_ProportionalGain;

  /* Gain: '<S380>/Gain' incorporates:
   *  Product: '<S380>/Product3'
   */
  rtb_DerivativeGain = frac[0] * frac[1] * GRM_HIL_P.Gain_Gain_ky;

  /* SignalConversion generated from: '<S380>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_DerivativeGain;

  /* Gain: '<S380>/Gain1' incorporates:
   *  Product: '<S380>/Product4'
   */
  rtb_Add1 = frac[0] * frac[2] * GRM_HIL_P.Gain1_Gain_oe;

  /* SignalConversion generated from: '<S380>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Add1;

  /* SignalConversion generated from: '<S380>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_DerivativeGain;

  /* Product: '<S380>/Product5' */
  rtb_DerivativeGain = frac[0] * frac[0];

  /* Sum: '<S380>/Add5' */
  rtb_JBBB[4] = rtb_jxk + rtb_DerivativeGain;

  /* Gain: '<S380>/Gain3' incorporates:
   *  Product: '<S380>/Product6'
   */
  rtb_jxk = frac[1] * frac[2] * GRM_HIL_P.Gain3_Gain_c;

  /* SignalConversion generated from: '<S380>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_jxk;

  /* SignalConversion generated from: '<S380>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Add1;

  /* SignalConversion generated from: '<S380>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_jxk;

  /* Sum: '<S380>/Add4' */
  rtb_JBBB[8] = rtb_ProportionalGain + rtb_DerivativeGain;

  /* Sum: '<S363>/Add5' incorporates:
   *  Constant: '<S363>/Constant15'
   *  Constant: '<S368>/Constant'
   *  Product: '<S368>/Product'
   */
  for (i = 0; i < 9; i++) {
    rtb_TBG[i] = GRM_HIL_P.Constant_Value_bk * rtb_JBBB[i] +
      GRM_HIL_P.Constant15_Value[i];
  }

  /* End of Sum: '<S363>/Add5' */

  /* Sum: '<S369>/Subtract4' incorporates:
   *  Constant: '<S369>/Constant16'
   */
  frac[0] = frac_2[0] - GRM_HIL_P.Constant16_Value[0];
  frac[1] = frac_2[1] - GRM_HIL_P.Constant16_Value[1];
  frac[2] = frac_2[2] - GRM_HIL_P.Constant16_Value[2];

  /* Product: '<S381>/Product1' */
  rtb_jxk = frac[1] * frac[1];

  /* Product: '<S381>/Product2' */
  rtb_ProportionalGain = frac[2] * frac[2];

  /* Sum: '<S381>/Add' */
  rtb_JBBB[0] = rtb_jxk + rtb_ProportionalGain;

  /* Gain: '<S381>/Gain' incorporates:
   *  Product: '<S381>/Product3'
   */
  rtb_DerivativeGain = frac[0] * frac[1] * GRM_HIL_P.Gain_Gain_lt;

  /* SignalConversion generated from: '<S381>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_DerivativeGain;

  /* Gain: '<S381>/Gain1' incorporates:
   *  Product: '<S381>/Product4'
   */
  rtb_Add1 = frac[0] * frac[2] * GRM_HIL_P.Gain1_Gain_iq;

  /* SignalConversion generated from: '<S381>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Add1;

  /* SignalConversion generated from: '<S381>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_DerivativeGain;

  /* Product: '<S381>/Product5' */
  rtb_DerivativeGain = frac[0] * frac[0];

  /* Sum: '<S381>/Add5' */
  rtb_JBBB[4] = rtb_jxk + rtb_DerivativeGain;

  /* Gain: '<S381>/Gain3' incorporates:
   *  Product: '<S381>/Product6'
   */
  rtb_jxk = frac[1] * frac[2] * GRM_HIL_P.Gain3_Gain_fm;

  /* SignalConversion generated from: '<S381>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_jxk;

  /* SignalConversion generated from: '<S381>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Add1;

  /* SignalConversion generated from: '<S381>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_jxk;

  /* Sum: '<S381>/Add4' */
  rtb_JBBB[8] = rtb_ProportionalGain + rtb_DerivativeGain;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S370>/Multiport Switch2' incorporates:
     *  Constant: '<S370>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3_m) {
     case 1:
      /* Trigonometry: '<S377>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/thrust_rot_x'
       *  Trigonometry: '<S377>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S377>/Trigonometric Function3' incorporates:
       *  Constant: '<S366>/thrust_rot_x'
       *  Trigonometry: '<S377>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S377>/Matrix Concatenate' incorporates:
       *  Constant: '<S377>/Constant7'
       *  Trigonometry: '<S377>/Trigonometric Function1'
       *  Trigonometry: '<S377>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_p;
      rtb_MultiportSwitch2[7] = rtb_Gain1_c;
      rtb_MultiportSwitch2[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S377>/Matrix Concatenate' incorporates:
       *  Constant: '<S377>/Constant8'
       *  Gain: '<S377>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_cs;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_pk * rtb_Gain1_c;

      /* SignalConversion generated from: '<S377>/Matrix Concatenate' incorporates:
       *  Constant: '<S377>/Constant'
       *  Constant: '<S377>/Constant1'
       *  Constant: '<S377>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_i;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_f;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_bt;
      break;

     case 2:
      /* Trigonometry: '<S378>/Trigonometric Function3' incorporates:
       *  Constant: '<S366>/thrust_rot_x'
       *  Trigonometry: '<S378>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S378>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/thrust_rot_x'
       *  Trigonometry: '<S378>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S378>/Matrix Concatenate' incorporates:
       *  Constant: '<S378>/Constant7'
       *  Gain: '<S378>/Gain1'
       *  Trigonometry: '<S378>/Trigonometric Function1'
       *  Trigonometry: '<S378>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_n * rtb_Switch1;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_jt;
      rtb_MultiportSwitch2[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S378>/Matrix Concatenate' incorporates:
       *  Constant: '<S378>/Constant'
       *  Constant: '<S378>/Constant1'
       *  Constant: '<S378>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_p;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_c4;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_jp;

      /* SignalConversion generated from: '<S378>/Matrix Concatenate' incorporates:
       *  Constant: '<S378>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_Gain1_c;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_c;
      rtb_MultiportSwitch2[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S379>/Matrix Concatenate' incorporates:
       *  Constant: '<S379>/Constant10'
       *  Constant: '<S379>/Constant11'
       *  Constant: '<S379>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_a;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_g;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_h;

      /* Trigonometry: '<S379>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/thrust_rot_x'
       *  Trigonometry: '<S379>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S379>/Trigonometric Function' incorporates:
       *  Constant: '<S366>/thrust_rot_x'
       *  Trigonometry: '<S379>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S379>/Matrix Concatenate' incorporates:
       *  Constant: '<S379>/Constant7'
       *  Trigonometry: '<S379>/Trigonometric Function'
       *  Trigonometry: '<S379>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_Gain1_c;
      rtb_MultiportSwitch2[4] = rtb_Switch1;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_cr;

      /* SignalConversion generated from: '<S379>/Matrix Concatenate' incorporates:
       *  Constant: '<S379>/Constant8'
       *  Gain: '<S379>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Switch1;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_ow * rtb_Gain1_c;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_os;
      break;
    }

    /* End of MultiPortSwitch: '<S370>/Multiport Switch2' */

    /* MultiPortSwitch: '<S370>/Multiport Switch1' incorporates:
     *  Constant: '<S370>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2_h) {
     case 1:
      /* Trigonometry: '<S374>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/thrust_rot_y'
       *  Trigonometry: '<S374>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S374>/Trigonometric Function3' incorporates:
       *  Constant: '<S366>/thrust_rot_y'
       *  Trigonometry: '<S374>/Trigonometric Function'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S374>/Matrix Concatenate' incorporates:
       *  Constant: '<S374>/Constant7'
       *  Trigonometry: '<S374>/Trigonometric Function1'
       *  Trigonometry: '<S374>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_n;
      rtb_MultiportSwitch1[7] = rtb_Gain1_c;
      rtb_MultiportSwitch1[8] = rtb_Switch1;

      /* SignalConversion generated from: '<S374>/Matrix Concatenate' incorporates:
       *  Constant: '<S374>/Constant8'
       *  Gain: '<S374>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_n;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_ax * rtb_Gain1_c;

      /* SignalConversion generated from: '<S374>/Matrix Concatenate' incorporates:
       *  Constant: '<S374>/Constant'
       *  Constant: '<S374>/Constant1'
       *  Constant: '<S374>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_lx;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_nq;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_c;
      break;

     case 2:
      /* Trigonometry: '<S375>/Trigonometric Function3' incorporates:
       *  Constant: '<S366>/thrust_rot_y'
       *  Trigonometry: '<S375>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S375>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/thrust_rot_y'
       *  Trigonometry: '<S375>/Trigonometric Function2'
       */
      rtb_Switch1 = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S375>/Matrix Concatenate' incorporates:
       *  Constant: '<S375>/Constant7'
       *  Gain: '<S375>/Gain1'
       *  Trigonometry: '<S375>/Trigonometric Function1'
       *  Trigonometry: '<S375>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_j0 * rtb_Switch1;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_fv;
      rtb_MultiportSwitch1[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S375>/Matrix Concatenate' incorporates:
       *  Constant: '<S375>/Constant'
       *  Constant: '<S375>/Constant1'
       *  Constant: '<S375>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_c;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_a;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_js;

      /* SignalConversion generated from: '<S375>/Matrix Concatenate' incorporates:
       *  Constant: '<S375>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_Gain1_c;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_dg;
      rtb_MultiportSwitch1[2] = rtb_Switch1;
      break;

     default:
      /* SignalConversion generated from: '<S376>/Matrix Concatenate' incorporates:
       *  Constant: '<S376>/Constant10'
       *  Constant: '<S376>/Constant11'
       *  Constant: '<S376>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_b;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_m;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_l2;

      /* Trigonometry: '<S376>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/thrust_rot_y'
       *  Trigonometry: '<S376>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S376>/Trigonometric Function' incorporates:
       *  Constant: '<S366>/thrust_rot_y'
       *  Trigonometry: '<S376>/Trigonometric Function3'
       */
      rtb_Switch1 = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S376>/Matrix Concatenate' incorporates:
       *  Constant: '<S376>/Constant7'
       *  Trigonometry: '<S376>/Trigonometric Function'
       *  Trigonometry: '<S376>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_Gain1_c;
      rtb_MultiportSwitch1[4] = rtb_Switch1;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_ch;

      /* SignalConversion generated from: '<S376>/Matrix Concatenate' incorporates:
       *  Constant: '<S376>/Constant8'
       *  Gain: '<S376>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Switch1;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_n * rtb_Gain1_c;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_ke;
      break;
    }

    /* End of MultiPortSwitch: '<S370>/Multiport Switch1' */

    /* MultiPortSwitch: '<S370>/Multiport Switch' incorporates:
     *  Constant: '<S370>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_md) {
     case 1:
      /* Trigonometry: '<S371>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/Thrust_rot_z'
       *  Trigonometry: '<S371>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S371>/Trigonometric Function3' incorporates:
       *  Constant: '<S366>/Thrust_rot_z'
       *  Trigonometry: '<S371>/Trigonometric Function'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S371>/Matrix Concatenate' incorporates:
       *  Constant: '<S371>/Constant7'
       *  Trigonometry: '<S371>/Trigonometric Function1'
       *  Trigonometry: '<S371>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_gi;
      rtb_MultiportSwitch[7] = rtb_Gain1_c;
      rtb_MultiportSwitch[8] = rtb_Subtract_cl;

      /* SignalConversion generated from: '<S371>/Matrix Concatenate' incorporates:
       *  Constant: '<S371>/Constant8'
       *  Gain: '<S371>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_j;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_cy * rtb_Gain1_c;

      /* SignalConversion generated from: '<S371>/Matrix Concatenate' incorporates:
       *  Constant: '<S371>/Constant'
       *  Constant: '<S371>/Constant1'
       *  Constant: '<S371>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_of;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_g;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_a;
      break;

     case 2:
      /* Trigonometry: '<S372>/Trigonometric Function3' incorporates:
       *  Constant: '<S366>/Thrust_rot_z'
       *  Trigonometry: '<S372>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S372>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/Thrust_rot_z'
       *  Trigonometry: '<S372>/Trigonometric Function2'
       */
      rtb_Subtract_cl = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S372>/Matrix Concatenate' incorporates:
       *  Constant: '<S372>/Constant7'
       *  Gain: '<S372>/Gain1'
       *  Trigonometry: '<S372>/Trigonometric Function1'
       *  Trigonometry: '<S372>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_hv * rtb_Subtract_cl;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_je;
      rtb_MultiportSwitch[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S372>/Matrix Concatenate' incorporates:
       *  Constant: '<S372>/Constant'
       *  Constant: '<S372>/Constant1'
       *  Constant: '<S372>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_hw;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_k;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_i;

      /* SignalConversion generated from: '<S372>/Matrix Concatenate' incorporates:
       *  Constant: '<S372>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_Gain1_c;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_l;
      rtb_MultiportSwitch[2] = rtb_Subtract_cl;
      break;

     default:
      /* SignalConversion generated from: '<S373>/Matrix Concatenate' incorporates:
       *  Constant: '<S373>/Constant10'
       *  Constant: '<S373>/Constant11'
       *  Constant: '<S373>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_l5;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_c;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_h1;

      /* Trigonometry: '<S373>/Trigonometric Function1' incorporates:
       *  Constant: '<S366>/Thrust_rot_z'
       *  Trigonometry: '<S373>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S373>/Trigonometric Function' incorporates:
       *  Constant: '<S366>/Thrust_rot_z'
       *  Trigonometry: '<S373>/Trigonometric Function3'
       */
      rtb_Subtract_cl = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S373>/Matrix Concatenate' incorporates:
       *  Constant: '<S373>/Constant7'
       *  Trigonometry: '<S373>/Trigonometric Function'
       *  Trigonometry: '<S373>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_Gain1_c;
      rtb_MultiportSwitch[4] = rtb_Subtract_cl;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_p5;

      /* SignalConversion generated from: '<S373>/Matrix Concatenate' incorporates:
       *  Constant: '<S373>/Constant8'
       *  Gain: '<S373>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Subtract_cl;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_f0 * rtb_Gain1_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gw;
      break;
    }

    /* End of MultiPortSwitch: '<S370>/Multiport Switch' */

    /* Product: '<S370>/3. Rotation' */
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        packet_size_idx_1_tmp = idx + 3 * i;
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] = 0.0;
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] += rtb_MultiportSwitch[3 * i] *
          rtb_MultiportSwitch1[idx];
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] += rtb_MultiportSwitch[3 * i + 1] *
          rtb_MultiportSwitch1[idx + 3];
        rtb_vBEB_a_tmp[packet_size_idx_1_tmp] += rtb_MultiportSwitch[3 * i + 2] *
          rtb_MultiportSwitch1[idx + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < 3; idx++) {
        packet_size_idx_1_tmp = idx + 3 * i;
        GRM_HIL_B.T12_o[packet_size_idx_1_tmp] = 0.0;
        GRM_HIL_B.T12_o[packet_size_idx_1_tmp] += rtb_vBEB_a_tmp[3 * i] *
          rtb_MultiportSwitch2[idx];
        GRM_HIL_B.T12_o[packet_size_idx_1_tmp] += rtb_vBEB_a_tmp[3 * i + 1] *
          rtb_MultiportSwitch2[idx + 3];
        GRM_HIL_B.T12_o[packet_size_idx_1_tmp] += rtb_vBEB_a_tmp[3 * i + 2] *
          rtb_MultiportSwitch2[idx + 6];
      }
    }

    /* End of Product: '<S370>/3. Rotation' */

    /* Sum: '<S365>/Subtract' incorporates:
     *  Constant: '<S365>/Constant16'
     *  Constant: '<S365>/Constant17'
     */
    for (i = 0; i < 9; i++) {
      GRM_HIL_B.Subtract_d[i] = GRM_HIL_P.Constant17_Value_j[i] -
        GRM_HIL_P.Constant16_Value_i[i];
    }

    /* End of Sum: '<S365>/Subtract' */

    /* Sum: '<S365>/Subtract4' incorporates:
     *  Constant: '<S365>/Constant18'
     *  Constant: '<S365>/Constant19'
     */
    GRM_HIL_B.Subtract4 = GRM_HIL_P.Constant19_Value -
      GRM_HIL_P.Constant18_Value;

    /* Math: '<S366>/Math Function' */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.MathFunction[3 * i] = GRM_HIL_B.T12_o[i];
      GRM_HIL_B.MathFunction[3 * i + 1] = GRM_HIL_B.T12_o[i + 3];
      GRM_HIL_B.MathFunction[3 * i + 2] = GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Math: '<S366>/Math Function' */
  }

  /* Sum: '<S365>/Subtract5' incorporates:
   *  Constant: '<S365>/Constant20'
   */
  rtb_jxk = rtb_Cy - GRM_HIL_P.Constant20_Value;

  /* Sum: '<S365>/Subtract6' incorporates:
   *  Constant: '<S365>/Constant21'
   *  Product: '<S365>/Divide'
   */
  for (i = 0; i < 9; i++) {
    rtb_MatrixMultiply_tmp[i] = rtb_jxk * GRM_HIL_B.Subtract_d[i] /
      GRM_HIL_B.Subtract4 + GRM_HIL_P.Constant21_Value[i];
  }

  /* End of Sum: '<S365>/Subtract6' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S366>/Matrix Multiply' */
    for (idx = 0; idx < 3; idx++) {
      packet_size_idx_1_tmp = i + 3 * idx;
      rtb_MultiportSwitch[packet_size_idx_1_tmp] = 0.0;
      rtb_MultiportSwitch[packet_size_idx_1_tmp] += rtb_MatrixMultiply_tmp[3 *
        idx] * GRM_HIL_B.T12_o[i];
      rtb_MultiportSwitch[packet_size_idx_1_tmp] += rtb_MatrixMultiply_tmp[3 *
        idx + 1] * GRM_HIL_B.T12_o[i + 3];
      rtb_MultiportSwitch[packet_size_idx_1_tmp] += rtb_MatrixMultiply_tmp[3 *
        idx + 2] * GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Product: '<S366>/Matrix Multiply' */

    /* Product: '<S336>/Product' incorporates:
     *  Constant: '<S327>/Constant9'
     */
    frac[i] = 0.0;

    /* Product: '<S336>/Product1' */
    rtb_ZeroOrderHold[i] = 0.0;
    for (idx = 0; idx < 3; idx++) {
      /* Sum: '<S367>/Add7' incorporates:
       *  Constant: '<S327>/Constant9'
       *  Constant: '<S367>/Constant16'
       *  Product: '<S336>/Product'
       *  Product: '<S336>/Product1'
       *  Product: '<S366>/Matrix Multiply1'
       *  Product: '<S369>/Product'
       *  Sum: '<S363>/Add'
       *  Sum: '<S363>/Add4'
       */
      packet_size_idx_1_tmp = 3 * idx + i;
      rtb_JBBB[packet_size_idx_1_tmp] = ((((GRM_HIL_B.MathFunction[3 * idx + 1] *
        rtb_MultiportSwitch[i + 3] + GRM_HIL_B.MathFunction[3 * idx] *
        rtb_MultiportSwitch[i]) + GRM_HIL_B.MathFunction[3 * idx + 2] *
        rtb_MultiportSwitch[i + 6]) + rtb_JBBB[packet_size_idx_1_tmp] * rtb_Cy)
        + rtb_TBG[packet_size_idx_1_tmp]) +
        GRM_HIL_P.Constant16_Value_c[packet_size_idx_1_tmp];

      /* Product: '<S336>/Product' incorporates:
       *  Constant: '<S327>/Constant9'
       *  Integrator: '<S334>/integration_eom'
       *  Product: '<S336>/Product1'
       */
      frac_tmp = GRM_HIL_X.integration_eom_CSTATE[idx + 10];
      frac[i] += GRM_HIL_P.Constant9_Value_cv[packet_size_idx_1_tmp] * frac_tmp;

      /* Product: '<S336>/Product1' */
      rtb_ZeroOrderHold[i] += rtb_JBBB[packet_size_idx_1_tmp] * frac_tmp;
    }
  }

  /* Sum: '<S336>/Subtract' incorporates:
   *  Integrator: '<S334>/integration_eom'
   *  Product: '<S339>/Product2'
   *  Product: '<S339>/Product3'
   *  Product: '<S339>/Product4'
   *  Product: '<S339>/Product5'
   *  Product: '<S339>/Product6'
   *  Product: '<S339>/Product7'
   *  Sum: '<S339>/Sum'
   *  Sum: '<S339>/Sum1'
   *  Sum: '<S339>/Sum2'
   */
  frac_0[0] = (frac_0[0] - frac[0]) - (GRM_HIL_X.integration_eom_CSTATE[11] *
    rtb_ZeroOrderHold[2] - GRM_HIL_X.integration_eom_CSTATE[12] *
    rtb_ZeroOrderHold[1]);
  frac_0[1] = (frac_0[1] - frac[1]) - (GRM_HIL_X.integration_eom_CSTATE[12] *
    rtb_ZeroOrderHold[0] - GRM_HIL_X.integration_eom_CSTATE[10] *
    rtb_ZeroOrderHold[2]);
  frac_0[2] = (frac_0[2] - frac[2]) - (GRM_HIL_X.integration_eom_CSTATE[10] *
    rtb_ZeroOrderHold[1] - GRM_HIL_X.integration_eom_CSTATE[11] *
    rtb_ZeroOrderHold[0]);

  /* Product: '<S336>/Divide1' */
  rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(rtb_JBBB, frac_0, &GRM_HIL_B.d_x[10]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S8>/Synchronize_to_realtime' incorporates:
     *  EnablePort: '<S382>/Enable'
     */
    /* Logic: '<S8>/Logical Operator2' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant3'
     *  Constant: '<S8>/Constant9'
     *  Logic: '<S8>/NOT'
     */
    if (GRM_HIL_P.Constant1_Value_c3 && (!GRM_HIL_P.Constant9_Value_b) &&
        GRM_HIL_P.Constant3_Value_it) {
      /* S-Function (sldrtsync): '<S382>/Real-Time Synchronization' */
      /* S-Function Block: <S382>/Real-Time Synchronization */
      {
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
      }
    }

    /* End of Logic: '<S8>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S8>/Synchronize_to_realtime' */

    /* Sum: '<S385>/FixPt Sum1' incorporates:
     *  Constant: '<S385>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)rtb_FixPtSum1 +
      GRM_HIL_P.FixPtConstant_Value);

    /* Switch: '<S386>/FixPt Switch' incorporates:
     *  Constant: '<S386>/Constant'
     */
    if (rtb_FixPtSum1 > GRM_HIL_P.WrapToZero_Threshold) {
      GRM_HIL_B.FixPtSwitch = GRM_HIL_P.Constant_Value_lk;
    } else {
      GRM_HIL_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S386>/FixPt Switch' */
  }

  /* SignalConversion generated from: '<S10>/Vector Concatenate2' */
  GRM_HIL_B.VectorConcatenate2[0] = GRM_HIL_B.w_x_dot_radDs2;

  /* SignalConversion generated from: '<S10>/Vector Concatenate2' */
  GRM_HIL_B.VectorConcatenate2[1] = GRM_HIL_B.w_y_dot_radDs2;

  /* SignalConversion generated from: '<S10>/Vector Concatenate2' */
  GRM_HIL_B.VectorConcatenate2[2] = GRM_HIL_B.w_z_dot_radDs2;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* ToAsyncQueueBlock generated from: '<S10>/Vector Concatenate2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VectorConcatenate2[0];
        int32_T size = 3*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1536843864U, time, pData, size);
      }
    }

    /* Gain: '<S392>/Gain' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S392>/wl_ins'
     *  Gain: '<S392>/Zero-Order Hold4'
     *  Sum: '<S392>/Sum7'
     */
    GRM_HIL_B.Gain_p[0] = (GRM_HIL_P.ZeroOrderHold4_Gain *
      GRM_HIL_P.Constant1_Value_i0[0] -
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_imu[0]) *
      GRM_HIL_P.Gain_Gain_il[0];
    GRM_HIL_B.Gain_p[1] = (GRM_HIL_P.ZeroOrderHold4_Gain *
      GRM_HIL_P.Constant1_Value_i0[1] -
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_imu[1]) *
      GRM_HIL_P.Gain_Gain_il[1];
    GRM_HIL_B.Gain_p[2] = (GRM_HIL_P.ZeroOrderHold4_Gain *
      GRM_HIL_P.Constant1_Value_i0[2] -
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_imu[2]) *
      GRM_HIL_P.Gain_Gain_il[2];
  }

  /* SignalConversion generated from: '<S10>/Vector Concatenate' */
  rtb_VectorConcatenate_hm[0] = GRM_HIL_B.ACC_x_B_mDs2;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' */
  rtb_VectorConcatenate_hm[1] = GRM_HIL_B.ACC_y_B_mDs2;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' */
  rtb_VectorConcatenate_hm[2] = GRM_HIL_B.ACC_z_B_mDs2;

  /* Trigonometry: '<S388>/sincos' incorporates:
   *  SignalConversion generated from: '<S10>/Vector Concatenate1'
   * */
  frac[0] = sin(GRM_HIL_B.ATT_Phi_rad);
  frac_0[0] = cos(GRM_HIL_B.ATT_Phi_rad);
  frac[1] = sin(GRM_HIL_B.ATT_Theta_rad);
  frac_0[1] = cos(GRM_HIL_B.ATT_Theta_rad);
  frac[2] = sin(GRM_HIL_B.ATT_Psi_rad);
  frac_0[2] = cos(GRM_HIL_B.ATT_Psi_rad);

  /* Fcn: '<S388>/Fcn11' */
  rtb_MultiportSwitch[0] = frac_0[1] * frac_0[2];

  /* Fcn: '<S388>/Fcn21' */
  rtb_MultiportSwitch[1] = -frac_0[1] * frac[2];

  /* Fcn: '<S388>/Fcn31' */
  rtb_MultiportSwitch[2] = frac[1];

  /* Fcn: '<S388>/Fcn12' */
  rtb_MultiportSwitch[3] = frac[0] * frac[1] * frac_0[2] + frac_0[0] * frac[2];

  /* Fcn: '<S388>/Fcn22' */
  rtb_MultiportSwitch[4] = -frac[0] * frac[1] * frac[2] + frac_0[0] * frac_0[2];

  /* Fcn: '<S388>/Fcn32' */
  rtb_MultiportSwitch[5] = -frac[0] * frac_0[1];

  /* Fcn: '<S388>/Fcn13' */
  rtb_MultiportSwitch[6] = -frac_0[0] * frac[1] * frac_0[2] + frac[0] * frac[2];

  /* Fcn: '<S388>/Fcn23' */
  rtb_MultiportSwitch[7] = frac_0[0] * frac[1] * frac[2] + frac[0] * frac_0[2];

  /* Fcn: '<S388>/Fcn33' */
  rtb_MultiportSwitch[8] = frac_0[0] * frac_0[1];

  /* SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited' */
  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  rtb_ZeroOrderHold[0] = GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[0];
  rtb_ZeroOrderHold[1] = GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[1];
  rtb_ZeroOrderHold[2] = GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[2];

  /* Gain: '<S399>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited'
   */
  rtb_jxk = 2.0 * GRM_HIL_P.ThreeaxisInertialMeasurementUnit_z_a *
    GRM_HIL_P.ThreeaxisInertialMeasurementUnit_w_a;
  frac_n[0] = rtb_jxk * GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[3];

  /* Gain: '<S392>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S10>/Vector Concatenate3'
   */
  frac[0] = GRM_HIL_P.ZeroOrderHold_Gain * GRM_HIL_B.w_x_K_IB_B_radDs;

  /* Gain: '<S399>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited'
   */
  frac_n[1] = rtb_jxk * GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[4];

  /* Gain: '<S392>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S10>/Vector Concatenate3'
   */
  frac[1] = GRM_HIL_P.ZeroOrderHold_Gain * GRM_HIL_B.w_y_K_IB_B_radDs;

  /* Gain: '<S399>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited'
   */
  frac_n[2] = rtb_jxk * GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[5];

  /* Gain: '<S392>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S10>/Vector Concatenate3'
   */
  frac[2] = GRM_HIL_P.ZeroOrderHold_Gain * GRM_HIL_B.w_z_K_IB_B_radDs;

  /* Sum: '<S401>/Sum' incorporates:
   *  Product: '<S404>/i x j'
   *  Product: '<S404>/j x k'
   *  Product: '<S404>/k x i'
   *  Product: '<S405>/i x k'
   *  Product: '<S405>/j x i'
   *  Product: '<S405>/k x j'
   */
  rtb_Product_i[0] = frac[1] * GRM_HIL_B.Gain_p[2] - frac[2] * GRM_HIL_B.Gain_p
    [1];
  rtb_Product_i[1] = frac[2] * GRM_HIL_B.Gain_p[0] - frac[0] * GRM_HIL_B.Gain_p
    [2];
  rtb_Product_i[2] = frac[0] * GRM_HIL_B.Gain_p[1] - frac[1] * GRM_HIL_B.Gain_p
    [0];

  /* Sum: '<S400>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S10>/Matrix Multiply'
   *  Product: '<S402>/i x j'
   *  Product: '<S402>/j x k'
   *  Product: '<S402>/k x i'
   *  Product: '<S403>/i x k'
   *  Product: '<S403>/j x i'
   *  Product: '<S403>/k x j'
   */
  rtb_vBEB_a[0] = frac[1] * rtb_Product_i[2];
  rtb_vBEB_a[1] = frac[2] * rtb_Product_i[0];
  rtb_vBEB_a[2] = frac[0] * rtb_Product_i[1];
  frac_0[0] = frac[2] * rtb_Product_i[1];
  frac_0[1] = frac[0] * rtb_Product_i[2];
  frac_0[2] = frac[1] * rtb_Product_i[0];
  for (i = 0; i < 3; i++) {
    frac[i] = rtb_vBEB_a[i] - frac_0[i];

    /* Gain: '<S392>/Zero-Order Hold3' */
    rtb_Product_i[i] = GRM_HIL_P.ZeroOrderHold3_Gain *
      GRM_HIL_B.VectorConcatenate2[i];
    frac_1[i] = rtb_MultiportSwitch[i + 6] * GRM_HIL_P.Constant_Value_ep[2] +
      (rtb_MultiportSwitch[i + 3] * GRM_HIL_P.Constant_Value_ep[1] +
       rtb_MultiportSwitch[i] * GRM_HIL_P.Constant_Value_ep[0]);
  }

  /* End of Sum: '<S400>/Sum' */

  /* Sum: '<S392>/Sum' incorporates:
   *  Gain: '<S392>/Zero-Order Hold1'
   *  Gain: '<S392>/Zero-Order Hold2'
   *  Product: '<S406>/i x j'
   *  Product: '<S406>/j x k'
   *  Product: '<S406>/k x i'
   *  Product: '<S407>/i x k'
   *  Product: '<S407>/j x i'
   *  Product: '<S407>/k x j'
   *  SignalConversion generated from: '<S10>/Vector Concatenate'
   *  Sum: '<S397>/Sum'
   * */
  frac[0] = ((GRM_HIL_P.ZeroOrderHold1_Gain * GRM_HIL_B.ACC_x_B_mDs2 -
              GRM_HIL_P.ZeroOrderHold2_Gain * frac_1[0]) + frac[0]) +
    (rtb_Product_i[1] * GRM_HIL_B.Gain_p[2] - rtb_Product_i[2] *
     GRM_HIL_B.Gain_p[1]);
  frac[1] = ((GRM_HIL_P.ZeroOrderHold1_Gain * GRM_HIL_B.ACC_y_B_mDs2 -
              GRM_HIL_P.ZeroOrderHold2_Gain * frac_1[1]) + frac[1]) +
    (rtb_Product_i[2] * GRM_HIL_B.Gain_p[0] - rtb_Product_i[0] *
     GRM_HIL_B.Gain_p[2]);
  rtb_Gain2_dm_tmp = ((GRM_HIL_P.ZeroOrderHold1_Gain * GRM_HIL_B.ACC_z_B_mDs2 -
                       GRM_HIL_P.ZeroOrderHold2_Gain * frac_1[2]) + frac[2]) +
    (rtb_Product_i[0] * GRM_HIL_B.Gain_p[1] - rtb_Product_i[1] *
     GRM_HIL_B.Gain_p[0]);

  /* Gain: '<S399>/wn^2' */
  rtb_jxk = GRM_HIL_P.ThreeaxisInertialMeasurementUnit_w_a *
    GRM_HIL_P.ThreeaxisInertialMeasurementUnit_w_a;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S399>/Sum2' incorporates:
     *  Constant: '<S392>/Measurement bias'
     *  Constant: '<S392>/Scale factors & Cross-coupling  errors'
     *  Gain: '<S399>/wn^2'
     *  Product: '<S392>/Product'
     *  Sum: '<S392>/Sum4'
     *  Sum: '<S399>/Sum3'
     */
    GRM_HIL_B.Sum2_b[i] =
      ((((GRM_HIL_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i + 3] * frac[1] +
          GRM_HIL_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i] * frac[0]) +
         GRM_HIL_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i + 6] *
         rtb_Gain2_dm_tmp) + GRM_HIL_P.ThreeaxisInertialMeasurementUnit_a_bias[i])
       - rtb_ZeroOrderHold[i]) * rtb_jxk - frac_n[i];
  }

  /* SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
  idx = 3;

  /* Gain: '<S411>/2*zeta * wn' */
  rtb_jxk = 2.0 * GRM_HIL_P.ThreeaxisInertialMeasurementUnit_z_g *
    GRM_HIL_P.ThreeaxisInertialMeasurementUnit_w_g;

  /* Gain: '<S411>/wn^2' */
  rtb_ProportionalGain_a = GRM_HIL_P.ThreeaxisInertialMeasurementUnit_w_g *
    GRM_HIL_P.ThreeaxisInertialMeasurementUnit_w_g;
  for (idx_0 = 0; idx_0 < 3; idx_0++) {
    /* SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
    rtb_Add1 = GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[idx];
    idx++;

    /* Sum: '<S411>/Sum2' incorporates:
     *  Constant: '<S393>/Measurement bias'
     *  Constant: '<S393>/Scale factors & Cross-coupling  errors '
     *  Constant: '<S393>/g-sensitive bias'
     *  Gain: '<S393>/Zero-Order Hold'
     *  Gain: '<S393>/Zero-Order Hold1'
     *  Gain: '<S411>/2*zeta * wn'
     *  Gain: '<S411>/wn^2'
     *  Product: '<S393>/Product'
     *  Product: '<S393>/Product1'
     *  SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited'
     *  SignalConversion generated from: '<S10>/Vector Concatenate3'
     *  Sum: '<S393>/Sum4'
     *  Sum: '<S411>/Sum3'
     *  UnitConversion: '<S391>/Unit Conversion'
     * */
    GRM_HIL_B.Sum2_i[idx_0] = (((((GRM_HIL_P.ZeroOrderHold_Gain_e *
      GRM_HIL_B.w_x_K_IB_B_radDs *
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_g_sf_cc[idx_0] +
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_g_sf_cc[idx_0 + 3] *
      (GRM_HIL_P.ZeroOrderHold_Gain_e * GRM_HIL_B.w_y_K_IB_B_radDs)) +
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_g_sf_cc[idx_0 + 6] *
      (GRM_HIL_P.ZeroOrderHold_Gain_e * GRM_HIL_B.w_z_K_IB_B_radDs)) +
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_g_bias[idx_0]) +
      0.10197162129779282 * rtb_VectorConcatenate_hm[idx_0] *
      GRM_HIL_P.ZeroOrderHold1_Gain_n *
      GRM_HIL_P.ThreeaxisInertialMeasurementUnit_g_sens[idx_0]) -
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[idx_0]) *
      rtb_ProportionalGain_a - rtb_jxk * rtb_Add1;
  }
}

/* Model update function */
void GRM_HIL_update(void)
{
  real_T *lastU;
  real_T HoldSine;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Enabled SubSystem: '<S21>/Receive_ExternalMode' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (GRM_HIL_DW.Receive_ExternalMode_MODE) {
      /* Update for Sin: '<S23>/Sine Wave' */
      HoldSine = GRM_HIL_DW.lastSin_h;
      GRM_HIL_DW.lastSin_h = GRM_HIL_DW.lastSin_h * GRM_HIL_P.SineWave_HCos +
        GRM_HIL_DW.lastCos_c * GRM_HIL_P.SineWave_Hsin;
      GRM_HIL_DW.lastCos_c = GRM_HIL_DW.lastCos_c * GRM_HIL_P.SineWave_HCos -
        HoldSine * GRM_HIL_P.SineWave_Hsin;
    }

    /* End of Update for SubSystem: '<S21>/Receive_ExternalMode' */

    /* Update for Memory generated from: '<S35>/Memory' */
    GRM_HIL_DW.Memory_1_PreviousInput = GRM_HIL_B.cmd_pass_enable_flg;

    /* Update for Memory generated from: '<S35>/Memory' */
    GRM_HIL_DW.Memory_2_PreviousInput = GRM_HIL_B.emergency_stop_flg;

    /* Update for Memory generated from: '<S35>/Memory1' */
    GRM_HIL_DW.Memory1_1_PreviousInput = GRM_HIL_B.Sum;
  }

  /* Update for Integrator: '<S334>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK = 0;

  /* Update for TransportDelay: '<S175>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK.Head <
        (GRM_HIL_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK.Head ==
        GRM_HIL_DW.TransportDelay_IWORK.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK.Head] = GRM_HIL_B.yaw_deg;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S35>/Memory1' */
    GRM_HIL_DW.Memory1_2_PreviousInput = GRM_HIL_B.Sum1;
  }

  /* Update for TransportDelay: '<S173>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_i.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_i.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK_p.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK_p.Head <
        (GRM_HIL_DW.TransportDelay_IWORK_p.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK_p.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK_p.Head ==
        GRM_HIL_DW.TransportDelay_IWORK_p.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK_p.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK_p.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK_p.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK_p.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK_p.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK_p.Head] = GRM_HIL_B.pitch_deg;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S35>/Memory1' */
    GRM_HIL_DW.Memory1_3_PreviousInput = GRM_HIL_B.Sum2;
  }

  /* Update for TransportDelay: '<S174>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_is.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_is.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK_f.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK_f.Head <
        (GRM_HIL_DW.TransportDelay_IWORK_f.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK_f.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK_f.Head ==
        GRM_HIL_DW.TransportDelay_IWORK_f.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK_f.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK_f.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK_f.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK_f.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK_f.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK_f.Head] = GRM_HIL_B.roll_deg;
  }

  /* Update for Integrator: '<S302>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_g = 0;

  /* Update for Integrator: '<S303>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_l = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S28>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_B.value;

    /* Update for UnitDelay: '<S384>/Output' */
    GRM_HIL_DW.Output_DSTATE = GRM_HIL_B.FixPtSwitch;
  }

  /* Update for Enabled SubSystem: '<S22>/send_to_pix' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  /* Update for Enabled SubSystem: '<S30>/Send_ExternalMode' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  if (GRM_HIL_DW.send_to_pix_MODE && GRM_HIL_DW.Send_ExternalMode_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for S-Function (sldrtpo): '<S33>/Packet Output' */

      /* S-Function Block: <S33>/Packet Output */
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

    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Sin: '<S33>/Sine Wave' */
      HoldSine = GRM_HIL_DW.lastSin;
      GRM_HIL_DW.lastSin = GRM_HIL_DW.lastSin * GRM_HIL_P.SineWave_HCos_g +
        GRM_HIL_DW.lastCos * GRM_HIL_P.SineWave_Hsin_e;
      GRM_HIL_DW.lastCos = GRM_HIL_DW.lastCos * GRM_HIL_P.SineWave_HCos_g -
        HoldSine * GRM_HIL_P.SineWave_Hsin_e;
    }
  }

  /* End of Update for SubSystem: '<S30>/Send_ExternalMode' */
  /* End of Update for SubSystem: '<S22>/send_to_pix' */

  /* Update for Derivative: '<S304>/Derivative1' */
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

  /* End of Update for Derivative: '<S304>/Derivative1' */

  /* Update for Derivative: '<S304>/Derivative' */
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

  /* End of Update for Derivative: '<S304>/Derivative' */
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
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
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
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
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
  int_T is;
  boolean_T lsat;
  boolean_T usat;
  real_T TransferFcn1_CSTATE_tmp;
  real_T TransferFcn1_CSTATE_tmp_0;
  XDot_GRM_HIL_T *_rtXdot;
  _rtXdot = ((XDot_GRM_HIL_T *) GRM_HIL_M->derivs);

  /* Derivatives for Integrator: '<S334>/integration_eom' */
  memcpy(&_rtXdot->integration_eom_CSTATE[0], &GRM_HIL_B.d_x[0], 13U * sizeof
         (real_T));

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn' */
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
  _rtXdot->TransferFcn_CSTATE[0] += GRM_HIL_B.Saturation_o;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn1' incorporates:
   *  TransferFcn: '<S13>/Transfer Fcn2'
   *  TransferFcn: '<S13>/Transfer Fcn3'
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

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] += GRM_HIL_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] += GRM_HIL_B.Saturation_j;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += GRM_HIL_B.Saturation_a;

  /* Derivatives for TransferFcn: '<S48>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_k[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE_k[0] += GRM_HIL_P.TransferFcn1_A[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_k[0];
  _rtXdot->TransferFcn1_CSTATE_k[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE_k[0] += GRM_HIL_P.TransferFcn1_A[1] *
    GRM_HIL_X.TransferFcn1_CSTATE_k[1];
  _rtXdot->TransferFcn1_CSTATE_k[1] += GRM_HIL_X.TransferFcn1_CSTATE_k[0];
  _rtXdot->TransferFcn1_CSTATE_k[0] += GRM_HIL_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S72>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.SumI1_p;

  /* Derivatives for Integrator: '<S72>/Filter' */
  _rtXdot->Filter_CSTATE = GRM_HIL_B.FilterCoefficient;

  /* Derivatives for Enabled SubSystem: '<S70>/Control_Limits' */
  if (GRM_HIL_DW.Control_Limits_MODE) {
    /* Derivatives for Integrator: '<S106>/Integrator' */
    _rtXdot->Integrator_CSTATE_l = GRM_HIL_B.SumI4;

    /* Derivatives for Integrator: '<S101>/Filter' */
    _rtXdot->Filter_CSTATE_l = GRM_HIL_B.FilterCoefficient_d;

    /* Derivatives for Integrator: '<S150>/Integrator' */
    _rtXdot->Integrator_CSTATE_i = GRM_HIL_B.SumI4_g;

    /* Derivatives for Integrator: '<S145>/Filter' */
    _rtXdot->Filter_CSTATE_b = GRM_HIL_B.FilterCoefficient_g;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_GRM_HIL_T *) GRM_HIL_M->derivs)->Integrator_CSTATE_l);
      for (i=0; i < 4; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S70>/Control_Limits' */

  /* Derivatives for Integrator: '<S53>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = GRM_HIL_B.SumI1;

  /* Derivatives for Integrator: '<S53>/Filter' */
  _rtXdot->Filter_CSTATE_h = GRM_HIL_B.FilterCoefficient_a;

  /* Derivatives for Integrator: '<S62>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = GRM_HIL_B.SumI1_n;

  /* Derivatives for Integrator: '<S62>/Filter' */
  _rtXdot->Filter_CSTATE_e = GRM_HIL_B.FilterCoefficient_l;

  /* Derivatives for TransferFcn: '<S38>/Phi2Motor -> Roll' */
  _rtXdot->Phi2MotorRoll_CSTATE[0] = 0.0;
  _rtXdot->Phi2MotorRoll_CSTATE[0] +=
    -GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[1] /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
    GRM_HIL_X.Phi2MotorRoll_CSTATE[0];
  _rtXdot->Phi2MotorRoll_CSTATE[1] = 0.0;
  _rtXdot->Phi2MotorRoll_CSTATE[0] +=
    -GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[2] /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
    GRM_HIL_X.Phi2MotorRoll_CSTATE[1];
  _rtXdot->Phi2MotorRoll_CSTATE[2] = 0.0;
  _rtXdot->Phi2MotorRoll_CSTATE[0] +=
    -GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[3] /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
    GRM_HIL_X.Phi2MotorRoll_CSTATE[2];
  _rtXdot->Phi2MotorRoll_CSTATE[1] += GRM_HIL_X.Phi2MotorRoll_CSTATE[0];
  _rtXdot->Phi2MotorRoll_CSTATE[2] += GRM_HIL_X.Phi2MotorRoll_CSTATE[1];
  _rtXdot->Phi2MotorRoll_CSTATE[0] += GRM_HIL_B.Merge2;

  /* Derivatives for TransferFcn: '<S38>/Theta2Motor -> Pitch' */
  for (is = 0; is < 5; is++) {
    _rtXdot->Theta2MotorPitch_CSTATE[is] = 0.0;
    _rtXdot->Theta2MotorPitch_CSTATE[0] +=
      -GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Pitch.Denom_Coef[is
      + 1] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Pitch.Denom_Coef[0] *
      GRM_HIL_X.Theta2MotorPitch_CSTATE[is];
  }

  _rtXdot->Theta2MotorPitch_CSTATE[1] += GRM_HIL_X.Theta2MotorPitch_CSTATE[0];
  _rtXdot->Theta2MotorPitch_CSTATE[2] += GRM_HIL_X.Theta2MotorPitch_CSTATE[1];
  _rtXdot->Theta2MotorPitch_CSTATE[3] += GRM_HIL_X.Theta2MotorPitch_CSTATE[2];
  _rtXdot->Theta2MotorPitch_CSTATE[4] += GRM_HIL_X.Theta2MotorPitch_CSTATE[3];
  _rtXdot->Theta2MotorPitch_CSTATE[0] += GRM_HIL_B.Merge1_f0;

  /* End of Derivatives for TransferFcn: '<S38>/Theta2Motor -> Pitch' */

  /* Derivatives for TransferFcn: '<S38>/Psi2Motor -> Yaw' */
  _rtXdot->Psi2MotorYaw_CSTATE[0] = 0.0;
  _rtXdot->Psi2MotorYaw_CSTATE[0] +=
    -GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[1] /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[0] *
    GRM_HIL_X.Psi2MotorYaw_CSTATE[0];
  _rtXdot->Psi2MotorYaw_CSTATE[1] = 0.0;
  _rtXdot->Psi2MotorYaw_CSTATE[0] +=
    -GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[2] /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[0] *
    GRM_HIL_X.Psi2MotorYaw_CSTATE[1];
  _rtXdot->Psi2MotorYaw_CSTATE[1] += GRM_HIL_X.Psi2MotorYaw_CSTATE[0];
  _rtXdot->Psi2MotorYaw_CSTATE[0] += GRM_HIL_B.Merge_b;

  /* Derivatives for Integrator: '<S302>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[0] = GRM_HIL_B.VectorConcatenate_m[0];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[0] = GRM_HIL_B.VectorConcatenate_k[0];

  /* Derivatives for Integrator: '<S302>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[1] = GRM_HIL_B.VectorConcatenate_m[1];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[1] = GRM_HIL_B.VectorConcatenate_k[1];

  /* Derivatives for Integrator: '<S302>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[2] = GRM_HIL_B.VectorConcatenate_m[2];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[2] = GRM_HIL_B.VectorConcatenate_k[2];

  /* Derivatives for Integrator: '<S302>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[3] = GRM_HIL_B.VectorConcatenate_m[3];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[3] = GRM_HIL_B.VectorConcatenate_k[3];

  /* Derivatives for Integrator: '<S270>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE <= GRM_HIL_P.Rudder_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE >= GRM_HIL_P.Rudder_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l > 0.0))
      || (usat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE = GRM_HIL_B.sf_Limiting_Rate.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S270>/Integrator1' */

  /* Derivatives for Integrator: '<S271>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_g <= GRM_HIL_P.Rudder1_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_g >= GRM_HIL_P.Rudder1_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_g = GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_g = 0.0;
  }

  /* End of Derivatives for Integrator: '<S271>/Integrator1' */

  /* Derivatives for Integrator: '<S272>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_a <= GRM_HIL_P.Rudder2_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_a >= GRM_HIL_P.Rudder2_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_a = GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_a = 0.0;
  }

  /* End of Derivatives for Integrator: '<S272>/Integrator1' */

  /* Derivatives for Integrator: '<S273>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_i <= GRM_HIL_P.Rudder3_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_i >= GRM_HIL_P.Rudder3_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_i = GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_i = 0.0;
  }

  /* End of Derivatives for Integrator: '<S273>/Integrator1' */

  /* Derivatives for Integrator: '<S270>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = GRM_HIL_B.sf_Limiting_Acceleration.dd_siB_l;

  /* Derivatives for Integrator: '<S271>/Integrator' */
  _rtXdot->Integrator_CSTATE_ep = GRM_HIL_B.sf_Limiting_Acceleration_i.dd_siB_l;

  /* Derivatives for Integrator: '<S272>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = GRM_HIL_B.sf_Limiting_Acceleration_p.dd_siB_l;

  /* Derivatives for Integrator: '<S273>/Integrator' */
  _rtXdot->Integrator_CSTATE_gp = GRM_HIL_B.sf_Limiting_Acceleration_h.dd_siB_l;

  /* Derivatives for SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited' */
  if (GRM_HIL_DW.IntegratorSecondOrderLimited_MODE[0] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[0] =
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[3];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[3] = GRM_HIL_B.Sum2_b[0];
  }

  if (GRM_HIL_DW.IntegratorSecondOrderLimited_MODE[1] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[1] =
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[4];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[4] = GRM_HIL_B.Sum2_b[1];
  }

  if (GRM_HIL_DW.IntegratorSecondOrderLimited_MODE[2] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[2] =
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[5];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[5] = GRM_HIL_B.Sum2_b[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
  if (GRM_HIL_DW.IntegratorSecondOrderLimited_MODE_i[0] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_a[0] =
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[3];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_a[3] = GRM_HIL_B.Sum2_i[0];
  }

  if (GRM_HIL_DW.IntegratorSecondOrderLimited_MODE_i[1] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_a[1] =
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[4];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_a[4] = GRM_HIL_B.Sum2_i[1];
  }

  if (GRM_HIL_DW.IntegratorSecondOrderLimited_MODE_i[2] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_a[2] =
      GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[5];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_a[5] = GRM_HIL_B.Sum2_i[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
  /* Start for Enabled SubSystem: '<S21>/Receive_ExternalMode' */
  GRM_HIL_DW.Receive_ExternalMode_MODE = false;

  /* Start for Constant: '<S327>/Constant' */
  memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
         (real_T));

  /* Start for TransportDelay: '<S175>/Transport Delay' */
  {
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for TransportDelay: '<S173>/Transport Delay' */
  {
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK_j.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK_p.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK_p.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK_p.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK_p.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput_m;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK_i.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK_i.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for TransportDelay: '<S174>/Transport Delay' */
  {
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK_i.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK_f.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK_f.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK_f.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK_f.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput_i;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK_is.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK_is.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for Enabled SubSystem: '<S71>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass_e);

  /* End of Start for SubSystem: '<S71>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S71>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE = false;

  /* End of Start for SubSystem: '<S71>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S70>/Control_Limits' */
  GRM_HIL_DW.Control_Limits_MODE = false;

  /* End of Start for SubSystem: '<S70>/Control_Limits' */

  /* Start for Enabled SubSystem: '<S52>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass);

  /* End of Start for SubSystem: '<S52>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S52>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE_l = false;

  /* End of Start for SubSystem: '<S52>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S61>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass_l);

  /* End of Start for SubSystem: '<S61>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S61>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE_g = false;

  /* End of Start for SubSystem: '<S61>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S44>/Voltage_Limitations' */
  GRM_HIL_DW.Voltage_Limitations_MODE = false;

  /* Start for If: '<S51>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_d = -1;

  /* Start for If: '<S51>/If1' */
  GRM_HIL_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S51>/If2' */
  GRM_HIL_DW.If2_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S44>/Voltage_Limitations' */

  /* Start for Enabled SubSystem: '<S44>/If Action Pass' */
  GRM_HIL_DW.IfActionPass_MODE = false;

  /* End of Start for SubSystem: '<S44>/If Action Pass' */
  /* Start for Constant: '<S302>/Constant8' */
  GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];

  /* Start for Constant: '<S302>/Constant8' */
  GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];

  /* Start for Constant: '<S302>/Constant8' */
  GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];

  /* Start for Constant: '<S302>/Constant8' */
  GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator1' */
  GRM_HIL_DW.clockTickCounter = -30000;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator' */
  GRM_HIL_DW.clockTickCounter_d = -10000;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator4' */
  GRM_HIL_DW.clockTickCounter_d3 = -40000;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator3' */
  GRM_HIL_DW.clockTickCounter_e = -10000;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator7' */
  GRM_HIL_DW.clockTickCounter_o = -40000;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator6' */
  GRM_HIL_DW.clockTickCounter_l = -10000;

  /* Start for Enabled SubSystem: '<S22>/send_to_pix' */
  GRM_HIL_DW.send_to_pix_MODE = false;

  /* Start for Enabled SubSystem: '<S30>/no_CRC' */
  GRM_HIL_DW.no_CRC_MODE = false;

  /* End of Start for SubSystem: '<S30>/no_CRC' */

  /* Start for Enabled SubSystem: '<S30>/Send_ExternalMode' */
  GRM_HIL_DW.Send_ExternalMode_MODE = false;

  /* Start for S-Function (sldrtpo): '<S33>/Packet Output' */

  /* S-Function Block: <S33>/Packet Output */
  /* no initial value should be set */

  /* End of Start for SubSystem: '<S30>/Send_ExternalMode' */
  /* Start for If: '<S175>/If' */
  GRM_HIL_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S173>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_l = -1;

  /* Start for If: '<S174>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_g = -1;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S334>/integration_eom' */
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
    }

    GRM_HIL_DW.integration_eom_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S334>/integration_eom' */

    /* InitializeConditions for Memory generated from: '<S35>/Memory' */
    GRM_HIL_DW.Memory_1_PreviousInput = GRM_HIL_P.Memory_1_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S35>/Memory' */
    GRM_HIL_DW.Memory_2_PreviousInput = GRM_HIL_P.Memory_2_InitialCondition;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn3' */
    GRM_HIL_X.TransferFcn3_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S48>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE_k[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn3' */
    GRM_HIL_X.TransferFcn3_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S48>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE_k[1] = 0.0;

    /* InitializeConditions for Memory generated from: '<S35>/Memory1' */
    GRM_HIL_DW.Memory1_1_PreviousInput = GRM_HIL_P.Memory1_1_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S35>/Memory1' */
    GRM_HIL_DW.Memory1_2_PreviousInput = GRM_HIL_P.Memory1_2_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S35>/Memory1' */
    GRM_HIL_DW.Memory1_3_PreviousInput = GRM_HIL_P.Memory1_3_InitialCondition;

    /* InitializeConditions for Integrator: '<S72>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE = GRM_HIL_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S72>/Filter' */
    GRM_HIL_X.Filter_CSTATE = GRM_HIL_P.Filter_IC;

    /* InitializeConditions for Integrator: '<S53>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Integrator_IC_k;

    /* InitializeConditions for Integrator: '<S53>/Filter' */
    GRM_HIL_X.Filter_CSTATE_h = GRM_HIL_P.Filter_IC_b;

    /* InitializeConditions for Integrator: '<S62>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Integrator_IC_j;

    /* InitializeConditions for Integrator: '<S62>/Filter' */
    GRM_HIL_X.Filter_CSTATE_e = GRM_HIL_P.Filter_IC_p;

    /* InitializeConditions for TransferFcn: '<S38>/Phi2Motor -> Roll' */
    GRM_HIL_X.Phi2MotorRoll_CSTATE[0] = 0.0;
    GRM_HIL_X.Phi2MotorRoll_CSTATE[1] = 0.0;
    GRM_HIL_X.Phi2MotorRoll_CSTATE[2] = 0.0;

    /* InitializeConditions for TransferFcn: '<S38>/Theta2Motor -> Pitch' */
    for (i = 0; i < 5; i++) {
      GRM_HIL_X.Theta2MotorPitch_CSTATE[i] = 0.0;
    }

    /* End of InitializeConditions for TransferFcn: '<S38>/Theta2Motor -> Pitch' */

    /* InitializeConditions for TransferFcn: '<S38>/Psi2Motor -> Yaw' */
    GRM_HIL_X.Psi2MotorYaw_CSTATE[0] = 0.0;
    GRM_HIL_X.Psi2MotorYaw_CSTATE[1] = 0.0;

    /* InitializeConditions for Integrator: '<S302>/integration_eom' incorporates:
     *  Integrator: '<S303>/integration_eom'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.integration_eom_CSTATE_b[0] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[1] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[2] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_b[3] = 1.0;
      GRM_HIL_X.integration_eom_CSTATE_f[0] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_f[1] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_f[2] = 0.0;
      GRM_HIL_X.integration_eom_CSTATE_f[3] = 1.0;
    }

    GRM_HIL_DW.integration_eom_IWORK_g = 1;

    /* End of InitializeConditions for Integrator: '<S302>/integration_eom' */

    /* InitializeConditions for Integrator: '<S303>/integration_eom' */
    GRM_HIL_DW.integration_eom_IWORK_l = 1;

    /* InitializeConditions for Integrator: '<S270>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_P.Rudder_siB_0;

    /* InitializeConditions for Integrator: '<S271>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE_g = GRM_HIL_P.Rudder1_siB_0;

    /* InitializeConditions for Integrator: '<S272>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE_a = GRM_HIL_P.Rudder2_siB_0;

    /* InitializeConditions for Integrator: '<S273>/Integrator1' */
    GRM_HIL_X.Integrator1_CSTATE_i = GRM_HIL_P.Rudder3_siB_0;

    /* InitializeConditions for Memory: '<S28>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S384>/Output' */
    GRM_HIL_DW.Output_DSTATE = GRM_HIL_P.Output_InitialCondition;

    /* InitializeConditions for Integrator: '<S270>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_h = GRM_HIL_P.Rudder_d_siB_0;

    /* InitializeConditions for Integrator: '<S271>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_ep = GRM_HIL_P.Rudder1_d_siB_0;

    /* InitializeConditions for Integrator: '<S272>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;

    /* InitializeConditions for Integrator: '<S273>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_gp = GRM_HIL_P.Rudder3_d_siB_0;

    /* InitializeConditions for Derivative: '<S304>/Derivative1' */
    GRM_HIL_DW.TimeStampA = (rtInf);
    GRM_HIL_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S304>/Derivative' */
    GRM_HIL_DW.TimeStampA_b = (rtInf);
    GRM_HIL_DW.TimeStampB_j = (rtInf);

    /* InitializeConditions for SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited' */
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[0] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICX;
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[1] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICX;
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[2] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICX;
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[3] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICDXDT;
    GRM_HIL_DW.IntegratorSecondOrderLimited_MODE[0] = 0;

    /* InitializeConditions for SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[0] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICX_g;

    /* InitializeConditions for SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited' */
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[4] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICDXDT;
    GRM_HIL_DW.IntegratorSecondOrderLimited_MODE[1] = 0;

    /* InitializeConditions for SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[1] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICX_g;

    /* InitializeConditions for SecondOrderIntegrator: '<S399>/Integrator, Second-Order Limited' */
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE[5] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICDXDT;
    GRM_HIL_DW.IntegratorSecondOrderLimited_MODE[2] = 0;

    /* InitializeConditions for SecondOrderIntegrator: '<S411>/Integrator, Second-Order Limited' */
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[2] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICX_g;
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[3] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICDXDT_b;
    GRM_HIL_DW.IntegratorSecondOrderLimited_MODE_i[0] = 0;
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[4] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICDXDT_b;
    GRM_HIL_DW.IntegratorSecondOrderLimited_MODE_i[1] = 0;
    GRM_HIL_X.IntegratorSecondOrderLimited_CSTATE_a[5] =
      GRM_HIL_P.IntegratorSecondOrderLimited_ICDXDT_b;
    GRM_HIL_DW.IntegratorSecondOrderLimited_MODE_i[2] = 0;

    /* SystemInitialize for Enabled SubSystem: '<S21>/Receive_ExternalMode' */
    /* SystemInitialize for Outport: '<S23>/Status' */
    GRM_HIL_B.AND_h = GRM_HIL_P.Status_Y0;

    /* SystemInitialize for Outport: '<S23>/Data' */
    for (i = 0; i < 78; i++) {
      GRM_HIL_B.PacketInput_o1[i] = GRM_HIL_P.Data_Y0;
    }

    /* End of SystemInitialize for Outport: '<S23>/Data' */
    /* End of SystemInitialize for SubSystem: '<S21>/Receive_ExternalMode' */

    /* SystemInitialize for Enabled SubSystem: '<S21>/input_hold' */
    /* SystemInitialize for Enabled SubSystem: '<S24>/hold' */
    /* SystemInitialize for Outport: '<S27>/ServoCMD' */
    GRM_HIL_B.ServoCMD_update[0] = GRM_HIL_P.ServoCMD_Y0;
    GRM_HIL_B.ServoCMD_update[1] = GRM_HIL_P.ServoCMD_Y0;
    GRM_HIL_B.ServoCMD_update[2] = GRM_HIL_P.ServoCMD_Y0;
    GRM_HIL_B.ServoCMD_update[3] = GRM_HIL_P.ServoCMD_Y0;

    /* SystemInitialize for Outport: '<S27>/SensorACC' */
    GRM_HIL_B.SensorACC_update[0] = GRM_HIL_P.SensorACC_Y0;

    /* SystemInitialize for Outport: '<S27>/SensorROT' */
    GRM_HIL_B.SensorROT_update[0] = GRM_HIL_P.SensorROT_Y0;

    /* SystemInitialize for Outport: '<S27>/SensorACC' */
    GRM_HIL_B.SensorACC_update[1] = GRM_HIL_P.SensorACC_Y0;

    /* SystemInitialize for Outport: '<S27>/SensorROT' */
    GRM_HIL_B.SensorROT_update[1] = GRM_HIL_P.SensorROT_Y0;

    /* SystemInitialize for Outport: '<S27>/SensorACC' */
    GRM_HIL_B.SensorACC_update[2] = GRM_HIL_P.SensorACC_Y0;

    /* SystemInitialize for Outport: '<S27>/SensorROT' */
    GRM_HIL_B.SensorROT_update[2] = GRM_HIL_P.SensorROT_Y0;

    /* End of SystemInitialize for SubSystem: '<S24>/hold' */
    /* End of SystemInitialize for SubSystem: '<S21>/input_hold' */

    /* SystemInitialize for Merge: '<S72>/Merge' */
    GRM_HIL_B.Merge_l = GRM_HIL_P.Merge_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S70>/Control_Limits' */
    /* InitializeConditions for Integrator: '<S106>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_l =
      GRM_HIL_P.PIDController_InitialConditionForIntegrator;

    /* InitializeConditions for Integrator: '<S101>/Filter' */
    GRM_HIL_X.Filter_CSTATE_l =
      GRM_HIL_P.PIDController_InitialConditionForFilter;

    /* InitializeConditions for Integrator: '<S150>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_i =
      GRM_HIL_P.PIDController1_InitialConditionForIntegrator;

    /* InitializeConditions for Integrator: '<S145>/Filter' */
    GRM_HIL_X.Filter_CSTATE_b =
      GRM_HIL_P.PIDController1_InitialConditionForFilter;

    /* End of SystemInitialize for SubSystem: '<S70>/Control_Limits' */

    /* SystemInitialize for Merge: '<S70>/Merge' */
    GRM_HIL_B.Merge_f = GRM_HIL_P.Merge_InitialOutput_e;

    /* SystemInitialize for Merge: '<S53>/Merge' */
    GRM_HIL_B.Merge_p = GRM_HIL_P.Merge_InitialOutput_h;

    /* SystemInitialize for Merge: '<S62>/Merge' */
    GRM_HIL_B.Merge_a = GRM_HIL_P.Merge_InitialOutput_d;

    /* SystemInitialize for Merge: '<S44>/Merge' */
    GRM_HIL_B.Merge_b = GRM_HIL_P.Merge_InitialOutput_g;

    /* SystemInitialize for Merge: '<S44>/Merge1' */
    GRM_HIL_B.Merge1_f0 = GRM_HIL_P.Merge1_InitialOutput;

    /* SystemInitialize for Merge: '<S44>/Merge2' */
    GRM_HIL_B.Merge2 = GRM_HIL_P.Merge2_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S22>/send_to_pix' */
    /* SystemInitialize for Enabled SubSystem: '<S30>/no_CRC' */
    /* SystemInitialize for Outport: '<S34>/message_pass' */
    for (i = 0; i < 128; i++) {
      GRM_HIL_B.message[i] = GRM_HIL_P.message_pass_Y0;
    }

    /* End of SystemInitialize for Outport: '<S34>/message_pass' */
    /* End of SystemInitialize for SubSystem: '<S30>/no_CRC' */
    /* End of SystemInitialize for SubSystem: '<S22>/send_to_pix' */

    /* SystemInitialize for IfAction SubSystem: '<S175>/If Action Subsystem1' */
    GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1_l,
      &GRM_HIL_P.IfActionSubsystem1_l);

    /* End of SystemInitialize for SubSystem: '<S175>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S175>/If Action Subsystem' */
    GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem_k,
      &GRM_HIL_P.IfActionSubsystem_k);

    /* End of SystemInitialize for SubSystem: '<S175>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S173>/If Action Subsystem1' */
    GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1,
      &GRM_HIL_P.IfActionSubsystem1);

    /* End of SystemInitialize for SubSystem: '<S173>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S173>/If Action Subsystem' */
    GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem,
      &GRM_HIL_P.IfActionSubsystem);

    /* End of SystemInitialize for SubSystem: '<S173>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S174>/If Action Subsystem1' */
    GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1_n,
      &GRM_HIL_P.IfActionSubsystem1_n);

    /* End of SystemInitialize for SubSystem: '<S174>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S174>/If Action Subsystem' */
    GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem_f,
      &GRM_HIL_P.IfActionSubsystem_f);

    /* End of SystemInitialize for SubSystem: '<S174>/If Action Subsystem' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      rtmSetFirstInitCond(GRM_HIL_M, 0);
    }
  }
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<S33>/Packet Output' */

  /* S-Function Block: <S33>/Packet Output */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S30>/Send_ExternalMode' */
  /* End of Terminate for SubSystem: '<S22>/send_to_pix' */
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
  GRM_HIL_P.Constant2_Value_k = rtInf;
  GRM_HIL_P.Constant2_Value_gu = rtInf;
  GRM_HIL_P.Constant2_Value_n = rtInf;
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
    GRM_HIL_M->Timing.sampleTimes[2] = (0.05);
    GRM_HIL_M->Timing.sampleTimes[3] = (0.1);

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
  GRM_HIL_M->Timing.stepSize2 = 0.05;
  GRM_HIL_M->Timing.stepSize3 = 0.1;
  rtmSetFirstInitCond(GRM_HIL_M, 1);

  /* External mode info */
  GRM_HIL_M->Sizes.checksums[0] = (2623358458U);
  GRM_HIL_M->Sizes.checksums[1] = (3566981983U);
  GRM_HIL_M->Sizes.checksums[2] = (2857640668U);
  GRM_HIL_M->Sizes.checksums[3] = (3835257173U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[110];
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
    systemRan[25] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC_e;
    systemRan[26] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass.Enabledpass_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&GRM_HIL_DW.Saturation.Saturation_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&GRM_HIL_DW.Saturation.Saturation_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&GRM_HIL_DW.pass.pass_SubsysRanBC;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC_d;
    systemRan[32] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass_l.Enabledpass_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_h.Saturation_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_h.Saturation_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&GRM_HIL_DW.pass_c.pass_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&GRM_HIL_DW.Control_Limits_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&GRM_HIL_DW.pass_SubsysRanBC;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass_e.Enabledpass_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_h4.Saturation_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_h4.Saturation_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&GRM_HIL_DW.pass_k.pass_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&GRM_HIL_DW.IfActionPass_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem_f.IfActionSubsystem_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1_n.IfActionSubsystem1_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem_k.IfActionSubsystem_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1_l.IfActionSubsystem1_SubsysRanBC;
    systemRan[51] = (sysRanDType *)&GRM_HIL_DW.IfActionlimit_pitch_SubsysRanBC;
    systemRan[52] = (sysRanDType *)&GRM_HIL_DW.IfActionlimit_roll_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&GRM_HIL_DW.IfActionlimit_yaw_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &GRM_HIL_DW.IfActionpass_roll.IfActionpass_yaw_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC;
    systemRan[57] = (sysRanDType *)&GRM_HIL_DW.Voltage_Limitations_SubsysRanBC;
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
    systemRan[76] = &rtAlwaysEnabled;
    systemRan[77] = &rtAlwaysEnabled;
    systemRan[78] = &rtAlwaysEnabled;
    systemRan[79] = &rtAlwaysEnabled;
    systemRan[80] = &rtAlwaysEnabled;
    systemRan[81] = &rtAlwaysEnabled;
    systemRan[82] = &rtAlwaysEnabled;
    systemRan[83] = &rtAlwaysEnabled;
    systemRan[84] = &rtAlwaysEnabled;
    systemRan[85] = &rtAlwaysEnabled;
    systemRan[86] = &rtAlwaysEnabled;
    systemRan[87] = &rtAlwaysEnabled;
    systemRan[88] = &rtAlwaysEnabled;
    systemRan[89] = &rtAlwaysEnabled;
    systemRan[90] = &rtAlwaysEnabled;
    systemRan[91] = &rtAlwaysEnabled;
    systemRan[92] = &rtAlwaysEnabled;
    systemRan[93] = &rtAlwaysEnabled;
    systemRan[94] = &rtAlwaysEnabled;
    systemRan[95] = &rtAlwaysEnabled;
    systemRan[96] = &rtAlwaysEnabled;
    systemRan[97] = &rtAlwaysEnabled;
    systemRan[98] = &rtAlwaysEnabled;
    systemRan[99] = &rtAlwaysEnabled;
    systemRan[100] = &rtAlwaysEnabled;
    systemRan[101] = &rtAlwaysEnabled;
    systemRan[102] = &rtAlwaysEnabled;
    systemRan[103] = &rtAlwaysEnabled;
    systemRan[104] = &rtAlwaysEnabled;
    systemRan[105] = &rtAlwaysEnabled;
    systemRan[106] = &rtAlwaysEnabled;
    systemRan[107] = &rtAlwaysEnabled;
    systemRan[108] = (sysRanDType *)
      &GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC;
    systemRan[109] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 91;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_M->Sizes.numContStates = (71);/* Number of continuous states */
  GRM_HIL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (4); /* Number of sample times */
  GRM_HIL_M->Sizes.numBlocks = (2377); /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (249); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (117967);/* Sum of parameter "widths" */
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

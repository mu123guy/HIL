/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.56
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Nov 26 15:53:25 2019
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
  15.0,
  0.0,
  2.0,
  2.0,
  2.0,
  2.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6353", 4294967295U, 7, SLDRTBoardOptions0 },
};

const Gimbal_Cmd_Bus GRM_HIL_rtZGimbal_Cmd_Bus = {
  0.0,                                 /* Gimbal_Phi_Cmd_deg */
  0.0,                                 /* Gimbal_Theta_Cmd_deg */
  0.0                                  /* Gimbal_Psi_Cmd_deg */
} ;                                    /* Gimbal_Cmd_Bus ground */

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
  if ((GRM_HIL_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    GRM_HIL_M->Timing.TaskCounters.TID[2] = 0;
  }

  GRM_HIL_M->Timing.sampleHits[2] = (GRM_HIL_M->Timing.TaskCounters.TID[2] == 0);
  (GRM_HIL_M->Timing.TaskCounters.TID[3])++;
  if ((GRM_HIL_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.02s, 0.0s] */
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
  int_T nXc = 51;
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
 *    '<S53>/Enabled pass'
 *    '<S62>/Enabled pass'
 *    '<S72>/Enabled pass'
 */
void GRM_HIL_Enabledpass_Disable(DW_Enabledpass_GRM_HIL_T *localDW)
{
  localDW->Enabledpass_MODE = false;
}

/*
 * Start for enable system:
 *    '<S53>/Enabled pass'
 *    '<S62>/Enabled pass'
 *    '<S72>/Enabled pass'
 */
void GRM_HIL_Enabledpass_Start(DW_Enabledpass_GRM_HIL_T *localDW)
{
  localDW->Enabledpass_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S53>/Enabled pass'
 *    '<S62>/Enabled pass'
 *    '<S72>/Enabled pass'
 */
void GRM_HIL_Enabledpass(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_upper_limit, real_T rtu_lower_limit, real_T
  *rty_upper_limit_pass, real_T *rty_lower_limit_pass, DW_Enabledpass_GRM_HIL_T *
  localDW)
{
  /* Outputs for Enabled SubSystem: '<S53>/Enabled pass' incorporates:
   *  EnablePort: '<S58>/Enable'
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
      /* Inport: '<S58>/upper_limit' */
      *rty_upper_limit_pass = rtu_upper_limit;

      /* Inport: '<S58>/lower_limit' */
      *rty_lower_limit_pass = rtu_lower_limit;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(localDW->Enabledpass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S53>/Enabled pass' */
}

/*
 * Output and update for enable system:
 *    '<S54>/Saturation'
 *    '<S63>/Saturation'
 *    '<S73>/Saturation'
 */
void GRM_HIL_Saturation(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_upper_limit, real_T rtu_lower_limit, real_T rtu_in,
  real_T *rty_out, DW_Saturation_GRM_HIL_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S54>/Saturation' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (rtu_Enable) {
    /* Switch: '<S61>/Switch2' incorporates:
     *  RelationalOperator: '<S61>/LowerRelop1'
     *  RelationalOperator: '<S61>/UpperRelop'
     *  Switch: '<S61>/Switch'
     */
    if (rtu_in > rtu_upper_limit) {
      /* SignalConversion generated from: '<S59>/out' */
      *rty_out = rtu_upper_limit;
    } else if (rtu_in < rtu_lower_limit) {
      /* Switch: '<S61>/Switch' incorporates:
       *  SignalConversion generated from: '<S59>/out'
       */
      *rty_out = rtu_lower_limit;
    } else {
      /* SignalConversion generated from: '<S59>/out' incorporates:
       *  Switch: '<S61>/Switch'
       */
      *rty_out = rtu_in;
    }

    /* End of Switch: '<S61>/Switch2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(localDW->Saturation_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S54>/Saturation' */
}

/*
 * Output and update for enable system:
 *    '<S54>/pass'
 *    '<S63>/pass'
 *    '<S73>/pass'
 */
void GRM_HIL_pass(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T rtu_Enable,
                  real_T rtu_in, real_T *rty_out, DW_pass_GRM_HIL_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S54>/pass' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (rtu_Enable) {
    /* Inport: '<S60>/in' */
    *rty_out = rtu_in;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(localDW->pass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S54>/pass' */
}

/*
 * System initialize for action system:
 *    '<S174>/If Action Subsystem1'
 *    '<S175>/If Action Subsystem1'
 *    '<S176>/If Action Subsystem1'
 */
void GRM_HIL_IfActionSubsystem1_Init(B_IfActionSubsystem1_GRM_HIL_T *localB,
  P_IfActionSubsystem1_GRM_HIL_T *localP)
{
  /* SystemInitialize for Outport: '<S178>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S174>/If Action Subsystem1'
 *    '<S175>/If Action Subsystem1'
 *    '<S176>/If Action Subsystem1'
 */
void GRM_HIL_IfActionSubsystem1(real_T rtu_In1, B_IfActionSubsystem1_GRM_HIL_T
  *localB)
{
  if (1) {
    /* Inport: '<S178>/In1' */
    localB->In1 = rtu_In1;
  }
}

/*
 * System initialize for action system:
 *    '<S174>/If Action Subsystem'
 *    '<S175>/If Action Subsystem'
 *    '<S176>/If Action Subsystem'
 */
void GRM_HIL_IfActionSubsystem_Init(B_IfActionSubsystem_GRM_HIL_T *localB,
  P_IfActionSubsystem_GRM_HIL_T *localP)
{
  /* SystemInitialize for Outport: '<S177>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S174>/If Action Subsystem'
 *    '<S175>/If Action Subsystem'
 *    '<S176>/If Action Subsystem'
 */
void GRM_HIL_IfActionSubsystem(real_T rtu_In1, B_IfActionSubsystem_GRM_HIL_T
  *localB)
{
  /* Inport: '<S177>/In1' */
  localB->In1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S52>/If Action pass_yaw'
 *    '<S52>/If Action pass_pitch'
 *    '<S52>/If Action pass_roll'
 */
void GRM_HIL_IfActionpass_yaw(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S188>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S271>/Limiting_Acceleration'
 *    '<S272>/Limiting_Acceleration'
 *    '<S273>/Limiting_Acceleration'
 *    '<S274>/Limiting_Acceleration'
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
 *    '<S271>/Limiting_Rate'
 *    '<S272>/Limiting_Rate'
 *    '<S273>/Limiting_Rate'
 *    '<S274>/Limiting_Rate'
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
  real_T rtb_Abs_iw;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_i;
  boolean_T rtb_Compare_n;
  real_T rtb_Sum_e;
  real_T rtb_Sum_l;
  real_T rtb_Sum_n;
  real_T rtb_Gain2_kf;
  real_T rtb_VectorConcatenate_f[3];
  real_T rtb_Gain1_l;
  ZCEventType zcEvent;
  real_T *lastU;
  real_T rtb_Divide1_h;
  real_T rtb_Divide_h;
  real_T rtb_Gain1_c;
  real_T rtb_VectorConcatenate_a[3];
  real_T rtb_siB_h[4];
  real_T rtb_Product4_n[4];
  uint32_T rtb_k_Mach;
  uint32_T rtb_k_alB;
  real_T rtb_Subtract_e;
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
  real_T rtb_PulseGenerator4;
  real_T rtb_PulseGenerator7;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator1;
  boolean_T rtb_RelationalOperator2;
  real_T rtb_ProportionalGain;
  real_T rtb_DerivativeGain;
  real_T rtb_ProportionalGain_n;
  real_T rtb_DerivativeGain_h;
  real_T rtb_ProportionalGain_d;
  real_T rtb_DerivativeGain_oe;
  real_T rtb_d_qBI[4];
  real_T rtb_JBBB[9];
  real_T rtb_Add;
  int8_T rtAction;
  real_T rtb_pBEE[3];
  real_T rtb_Sqrt_j;
  real_T rtb_lat;
  real_T rtb_vBEB_a[3];
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
  real_T rtb_MultiportSwitch[9];
  real_T rtb_MultiportSwitch1[9];
  real_T rtb_MultiportSwitch2[9];
  real_T rtb_MatrixMultiply_tmp[9];
  real_T rtb_vBEB_a_tmp[9];
  real_T rtb_gamma_R_tmp;
  int32_T i;
  real_T tmp[16];
  real_T rtb_MatrixMultiply_tmp_0[3];
  int32_T i_0;
  real_T rtb_Product_idx_2;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_0;
  real_T rtb_Product_idx_3;
  real_T u0;
  real_T rtb_TBG_tmp;
  real_T rtb_TBG_tmp_0;
  real_T rtb_Abs_iw_tmp;
  real_T rtb_TBG_tmp_1;
  real_T rtb_TBG_tmp_2;
  real_T rtb_TBG_tmp_3;
  real_T rtb_TBG_tmp_4;
  real_T rtb_TBG_tmp_5;
  real_T rtb_TBG_tmp_6;
  real_T rtb_TBG_tmp_7;
  real_T rtb_Divide_jq_tmp;
  real_T rtb_Gain1_n4_tmp;
  real_T rtb_Subtract_a_tmp;
  real_T rtb_Subtract_a_tmp_0;
  real_T rtb_pBEE_tmp;
  real_T rtb_pBEE_tmp_0;
  real_T rtb_Product_c_tmp;
  real_T rtb_TBG_tmp_8;
  int32_T rtb_MultiportSwitch1_tmp;
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
  srClearBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Enabledpass.Enabledpass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Saturation.Saturation_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.pass.pass_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_o);

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
    /* Constant: '<S328>/Constant' */
    memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
           (real_T));
  }

  /* Integrator: '<S335>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK != 0) {
    memcpy(&GRM_HIL_X.integration_eom_CSTATE[0], &GRM_HIL_B.Constant[0], 13U *
           sizeof(real_T));
  }

  /* Gain: '<S195>/Gain17' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.POS_z_NED_m = GRM_HIL_P.Gain17_Gain *
    GRM_HIL_X.integration_eom_CSTATE[2];

  /* RelationalOperator: '<S388>/Compare' incorporates:
   *  Constant: '<S388>/Constant'
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
    GRM_HIL_B.Z_d = GRM_HIL_P.Constant5_Value;

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
        sendToAsyncQueueTgtAppSvc(690494803U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_2_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(451397876U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_3_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3759103194U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Fin_4_Pos_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2408874624U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(186134014U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(382491858U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3466872641U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_i;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2488529621U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1515092553U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_d;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2457344120U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1859097487U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_c;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3184170427U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2684109832U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.A_f;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2645675160U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.B_n;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1499544645U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Z_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4048591736U, time, pData, size);
      }
    }
  }

  /* Product: '<S338>/Product3' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Abs_iw = GRM_HIL_X.integration_eom_CSTATE[8] *
    GRM_HIL_X.integration_eom_CSTATE[8];

  /* Sum: '<S338>/Add' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S338>/Product1'
   *  Product: '<S338>/Product2'
   *  Product: '<S338>/Product4'
   */
  rtb_Divide1_h = ((GRM_HIL_X.integration_eom_CSTATE[6] *
                    GRM_HIL_X.integration_eom_CSTATE[6] +
                    GRM_HIL_X.integration_eom_CSTATE[7] *
                    GRM_HIL_X.integration_eom_CSTATE[7]) + rtb_Abs_iw) +
    GRM_HIL_X.integration_eom_CSTATE[9] * GRM_HIL_X.integration_eom_CSTATE[9];

  /* Math: '<S338>/Math Function'
   *
   * About '<S338>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Divide1_h < 0.0) {
    rtb_Divide1_h = -sqrt(fabs(rtb_Divide1_h));
  } else {
    rtb_Divide1_h = sqrt(rtb_Divide1_h);
  }

  /* End of Math: '<S338>/Math Function' */

  /* Product: '<S338>/Product' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Product_idx_0 = GRM_HIL_X.integration_eom_CSTATE[6] / rtb_Divide1_h;
  rtb_Product_idx_1 = GRM_HIL_X.integration_eom_CSTATE[7] / rtb_Divide1_h;
  rtb_Product_idx_2 = GRM_HIL_X.integration_eom_CSTATE[8] / rtb_Divide1_h;
  rtb_Product_idx_3 = GRM_HIL_X.integration_eom_CSTATE[9] / rtb_Divide1_h;

  /* Math: '<S293>/Math Function1' incorporates:
   *  Math: '<S293>/Math Function5'
   *  Math: '<S293>/Math Function9'
   *  Math: '<S336>/Math Function5'
   *  Math: '<S336>/Math Function9'
   *  Switch: '<S334>/Switch'
   */
  rtb_Abs_iw_tmp = rtb_Product_idx_1 * rtb_Product_idx_1;
  rtb_Abs_iw = rtb_Abs_iw_tmp;

  /* Math: '<S293>/Math Function' incorporates:
   *  Math: '<S293>/Math Function4'
   *  Math: '<S293>/Math Function8'
   *  Math: '<S336>/Math Function4'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_1 = rtb_Product_idx_0 * rtb_Product_idx_0;

  /* Math: '<S293>/Math Function2' incorporates:
   *  Math: '<S293>/Math Function10'
   *  Math: '<S293>/Math Function6'
   *  Math: '<S336>/Math Function6'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_2 = rtb_Product_idx_2 * rtb_Product_idx_2;

  /* Math: '<S293>/Math Function3' incorporates:
   *  Math: '<S293>/Math Function11'
   *  Math: '<S293>/Math Function7'
   *  Math: '<S336>/Math Function11'
   *  Math: '<S336>/Math Function7'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_3 = rtb_Product_idx_3 * rtb_Product_idx_3;

  /* Sum: '<S293>/Add' incorporates:
   *  Math: '<S293>/Math Function'
   *  Math: '<S293>/Math Function2'
   *  Math: '<S293>/Math Function3'
   */
  rtb_TBG[0] = ((rtb_TBG_tmp_1 - rtb_Abs_iw) - rtb_TBG_tmp_2) + rtb_TBG_tmp_3;

  /* Product: '<S293>/Product' incorporates:
   *  Product: '<S293>/Product6'
   *  Product: '<S336>/Product'
   *  Product: '<S336>/Product6'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp = rtb_Product_idx_0 * rtb_Product_idx_1;

  /* Product: '<S293>/Product1' incorporates:
   *  Product: '<S293>/Product7'
   *  Product: '<S336>/Product1'
   *  Product: '<S336>/Product7'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_0 = rtb_Product_idx_2 * rtb_Product_idx_3;

  /* Sum: '<S293>/Add1' incorporates:
   *  Gain: '<S293>/Gain1'
   *  Gain: '<S293>/Gain2'
   *  Product: '<S293>/Product'
   *  Product: '<S293>/Product1'
   */
  rtb_TBG[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_c - rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain2_Gain_c;

  /* Product: '<S293>/Product8' incorporates:
   *  Product: '<S293>/Product4'
   *  Product: '<S336>/Product4'
   *  Product: '<S336>/Product8'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_4 = rtb_Product_idx_0 * rtb_Product_idx_2;

  /* Product: '<S293>/Product9' incorporates:
   *  Product: '<S293>/Product5'
   *  Product: '<S336>/Product5'
   *  Product: '<S336>/Product9'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_5 = rtb_Product_idx_1 * rtb_Product_idx_3;

  /* Sum: '<S293>/Add5' incorporates:
   *  Gain: '<S293>/Gain10'
   *  Gain: '<S293>/Gain9'
   *  Product: '<S293>/Product8'
   *  Product: '<S293>/Product9'
   */
  rtb_TBG[2] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain9_Gain_c + rtb_TBG_tmp_5 *
    GRM_HIL_P.Gain10_Gain_g;

  /* Sum: '<S293>/Add4' incorporates:
   *  Gain: '<S293>/Gain7'
   *  Gain: '<S293>/Gain8'
   */
  rtb_TBG[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain_c + rtb_TBG_tmp_0 *
    GRM_HIL_P.Gain8_Gain_b;

  /* Math: '<S293>/Math Function5' */
  rtb_Abs_iw = rtb_Abs_iw_tmp;

  /* Sum: '<S293>/Add6' */
  rtb_TBG[4] = ((rtb_Abs_iw - rtb_TBG_tmp_1) - rtb_TBG_tmp_2) + rtb_TBG_tmp_3;

  /* Product: '<S293>/Product2' incorporates:
   *  Product: '<S293>/Product10'
   *  Product: '<S336>/Product10'
   *  Product: '<S336>/Product2'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_6 = rtb_Product_idx_1 * rtb_Product_idx_2;

  /* Product: '<S293>/Product3' incorporates:
   *  Product: '<S293>/Product11'
   *  Product: '<S336>/Product11'
   *  Product: '<S336>/Product3'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_7 = rtb_Product_idx_0 * rtb_Product_idx_3;

  /* Sum: '<S293>/Add2' incorporates:
   *  Gain: '<S293>/Gain3'
   *  Gain: '<S293>/Gain4'
   *  Product: '<S293>/Product2'
   *  Product: '<S293>/Product3'
   */
  rtb_TBG[5] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain3_Gain_p - rtb_TBG_tmp_7 *
    GRM_HIL_P.Gain4_Gain_o;

  /* Sum: '<S293>/Add3' incorporates:
   *  Gain: '<S293>/Gain5'
   *  Gain: '<S293>/Gain6'
   */
  rtb_TBG[6] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain5_Gain_l - rtb_TBG_tmp_5 *
    GRM_HIL_P.Gain6_Gain_p;

  /* Sum: '<S293>/Add8' incorporates:
   *  Gain: '<S293>/Gain11'
   *  Gain: '<S293>/Gain12'
   */
  rtb_TBG[7] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain11_Gain_d + rtb_TBG_tmp_7 *
    GRM_HIL_P.Gain12_Gain_g;

  /* Math: '<S293>/Math Function9' */
  rtb_Abs_iw = rtb_Abs_iw_tmp;

  /* Sum: '<S293>/Add7' incorporates:
   *  Sum: '<S336>/Add7'
   *  Switch: '<S334>/Switch'
   */
  rtb_TBG_tmp_8 = rtb_TBG_tmp_2 - rtb_TBG_tmp_1;
  rtb_TBG[8] = (rtb_TBG_tmp_8 - rtb_Abs_iw) + rtb_TBG_tmp_3;
  for (i = 0; i < 3; i++) {
    /* Math: '<S327>/Math Function' incorporates:
     *  Math: '<S344>/Math Function'
     */
    rtb_MatrixMultiply_tmp[3 * i] = rtb_TBG[i];
    rtb_MatrixMultiply_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_MatrixMultiply_tmp[3 * i + 2] = rtb_TBG[i + 6];
  }

  /* Product: '<S327>/Product1' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Math: '<S327>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_a[i] = rtb_MatrixMultiply_tmp[i + 6] *
      GRM_HIL_X.integration_eom_CSTATE[5] + (rtb_MatrixMultiply_tmp[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[4] + rtb_MatrixMultiply_tmp[i] *
      GRM_HIL_X.integration_eom_CSTATE[3]);
  }

  /* End of Product: '<S327>/Product1' */

  /* Gain: '<S195>/Gain' */
  GRM_HIL_B.VEL_u_K_R_E_B_mDs = GRM_HIL_P.Gain_Gain_k1 *
    rtb_VectorConcatenate_a[0];

  /* Gain: '<S195>/Gain1' */
  GRM_HIL_B.VEL_v_K_R_E_B_mDs = GRM_HIL_P.Gain1_Gain_mm *
    rtb_VectorConcatenate_a[1];

  /* Gain: '<S195>/Gain2' */
  GRM_HIL_B.VEL_w_K_R_E_B_mDs = GRM_HIL_P.Gain2_Gain_e *
    rtb_VectorConcatenate_a[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S303>/Constant8' */
    GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];
    GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];
    GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];
    GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];
  }

  /* Integrator: '<S303>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_g != 0) {
    GRM_HIL_X.integration_eom_CSTATE_b[0] = GRM_HIL_B.Constant8[0];
    GRM_HIL_X.integration_eom_CSTATE_b[1] = GRM_HIL_B.Constant8[1];
    GRM_HIL_X.integration_eom_CSTATE_b[2] = GRM_HIL_B.Constant8[2];
    GRM_HIL_X.integration_eom_CSTATE_b[3] = GRM_HIL_B.Constant8[3];
  }

  /* Math: '<S307>/Math Function1' incorporates:
   *  Integrator: '<S303>/integration_eom'
   */
  rtb_Abs_iw = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];

  /* Sum: '<S307>/Add' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Math: '<S307>/Math Function'
   *  Math: '<S307>/Math Function2'
   *  Math: '<S307>/Math Function3'
   */
  rtb_VectorConcatenate3[0] = ((GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0] - rtb_Abs_iw) -
    GRM_HIL_X.integration_eom_CSTATE_b[2] * GRM_HIL_X.integration_eom_CSTATE_b[2])
    + GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Product: '<S307>/Product' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S307>/Product6'
   */
  rtb_lat = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];

  /* Product: '<S307>/Product1' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S307>/Product7'
   */
  rtb_Cx = GRM_HIL_X.integration_eom_CSTATE_b[2] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S307>/Add1' incorporates:
   *  Gain: '<S307>/Gain1'
   *  Gain: '<S307>/Gain2'
   *  Product: '<S307>/Product'
   *  Product: '<S307>/Product1'
   */
  rtb_VectorConcatenate3[1] = rtb_lat * GRM_HIL_P.Gain1_Gain_i - rtb_Cx *
    GRM_HIL_P.Gain2_Gain_iy;

  /* Product: '<S307>/Product8' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S307>/Product4'
   */
  rtb_Add = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S307>/Product9' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S307>/Product5'
   */
  rtb_Sqrt_j = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S307>/Add5' incorporates:
   *  Gain: '<S307>/Gain10'
   *  Gain: '<S307>/Gain9'
   *  Product: '<S307>/Product8'
   *  Product: '<S307>/Product9'
   */
  rtb_VectorConcatenate3[2] = rtb_Add * GRM_HIL_P.Gain9_Gain_g + rtb_Sqrt_j *
    GRM_HIL_P.Gain10_Gain_h;

  /* Sum: '<S307>/Add4' incorporates:
   *  Gain: '<S307>/Gain7'
   *  Gain: '<S307>/Gain8'
   */
  rtb_VectorConcatenate3[3] = rtb_lat * GRM_HIL_P.Gain7_Gain_i + rtb_Cx *
    GRM_HIL_P.Gain8_Gain_d;

  /* Math: '<S307>/Math Function5' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Math: '<S307>/Math Function9'
   */
  rtb_Product4_e = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[1];
  rtb_Abs_iw = rtb_Product4_e;

  /* Math: '<S307>/Math Function6' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Math: '<S307>/Math Function10'
   */
  rtb_lat = GRM_HIL_X.integration_eom_CSTATE_b[2] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Math: '<S307>/Math Function4' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Math: '<S307>/Math Function8'
   */
  rtb_Cx = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[0];

  /* Math: '<S307>/Math Function7' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Math: '<S307>/Math Function11'
   */
  rtb_f_beB = GRM_HIL_X.integration_eom_CSTATE_b[3] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S307>/Add6' incorporates:
   *  Math: '<S307>/Math Function4'
   *  Math: '<S307>/Math Function6'
   *  Math: '<S307>/Math Function7'
   */
  rtb_VectorConcatenate3[4] = ((rtb_Abs_iw - rtb_Cx) - rtb_lat) + rtb_f_beB;

  /* Product: '<S307>/Product2' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S307>/Product10'
   */
  rtb_siB_c5 = GRM_HIL_X.integration_eom_CSTATE_b[1] *
    GRM_HIL_X.integration_eom_CSTATE_b[2];

  /* Product: '<S307>/Product3' incorporates:
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S307>/Product11'
   */
  rtb_Gain_g = GRM_HIL_X.integration_eom_CSTATE_b[0] *
    GRM_HIL_X.integration_eom_CSTATE_b[3];

  /* Sum: '<S307>/Add2' incorporates:
   *  Gain: '<S307>/Gain3'
   *  Gain: '<S307>/Gain4'
   *  Product: '<S307>/Product2'
   *  Product: '<S307>/Product3'
   */
  rtb_VectorConcatenate3[5] = rtb_siB_c5 * GRM_HIL_P.Gain3_Gain_if - rtb_Gain_g *
    GRM_HIL_P.Gain4_Gain_f;

  /* Sum: '<S307>/Add3' incorporates:
   *  Gain: '<S307>/Gain5'
   *  Gain: '<S307>/Gain6'
   */
  rtb_VectorConcatenate3[6] = rtb_Add * GRM_HIL_P.Gain5_Gain_i - rtb_Sqrt_j *
    GRM_HIL_P.Gain6_Gain_n;

  /* Sum: '<S307>/Add8' incorporates:
   *  Gain: '<S307>/Gain11'
   *  Gain: '<S307>/Gain12'
   */
  rtb_VectorConcatenate3[7] = rtb_siB_c5 * GRM_HIL_P.Gain11_Gain_n + rtb_Gain_g *
    GRM_HIL_P.Gain12_Gain_h;

  /* Math: '<S307>/Math Function9' */
  rtb_Abs_iw = rtb_Product4_e;

  /* Sum: '<S307>/Add7' */
  rtb_VectorConcatenate3[8] = ((rtb_lat - rtb_Cx) - rtb_Abs_iw) + rtb_f_beB;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S302>/Switch' incorporates:
     *  Constant: '<S302>/Constant7'
     *  Constant: '<S302>/Constant9'
     */
    if (GRM_HIL_P.Constant9_Value_p > GRM_HIL_P.Switch_Threshold) {
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant7_Value_i;

      /* SignalConversion generated from: '<S302>/Vector Concatenate' incorporates:
       *  Constant: '<S302>/Constant6'
       *  Constant: '<S302>/Constant7'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant6_Value;

      /* SignalConversion generated from: '<S302>/Vector Concatenate' incorporates:
       *  Constant: '<S302>/Constant6'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant6_Value;
    } else {
      /* SignalConversion generated from: '<S302>/Vector Concatenate1' incorporates:
       *  Constant: '<S302>/Constant8'
       */
      GRM_HIL_B.wIEE[2] = GRM_HIL_P.Constant8_Value;

      /* SignalConversion generated from: '<S302>/Vector Concatenate1' incorporates:
       *  Constant: '<S302>/Constant8'
       */
      GRM_HIL_B.wIEE[1] = GRM_HIL_P.Constant8_Value;

      /* SignalConversion generated from: '<S302>/Vector Concatenate1' incorporates:
       *  Constant: '<S302>/Constant8'
       */
      GRM_HIL_B.wIEE[0] = GRM_HIL_P.Constant8_Value;
    }

    /* End of Switch: '<S302>/Switch' */
  }

  /* Product: '<S346>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate3[i + 6] * GRM_HIL_B.wIEE
      [2] + (rtb_VectorConcatenate3[i + 3] * GRM_HIL_B.wIEE[1] +
             rtb_VectorConcatenate3[i] * GRM_HIL_B.wIEE[0]);
  }

  /* End of Product: '<S346>/Product' */

  /* Product: '<S351>/Product3' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Abs_iw = rtb_VectorConcatenate_a[2] * GRM_HIL_X.integration_eom_CSTATE[1];

  /* Sum: '<S351>/Sum' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S351>/Product2'
   */
  rtb_Product1_m[0] = rtb_VectorConcatenate_a[1] *
    GRM_HIL_X.integration_eom_CSTATE[2] - rtb_Abs_iw;

  /* Product: '<S351>/Product5' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Abs_iw = rtb_VectorConcatenate_a[0] * GRM_HIL_X.integration_eom_CSTATE[2];

  /* Sum: '<S351>/Sum1' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S351>/Product4'
   */
  rtb_Product1_m[1] = rtb_VectorConcatenate_a[2] *
    GRM_HIL_X.integration_eom_CSTATE[0] - rtb_Abs_iw;

  /* Product: '<S351>/Product7' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Abs_iw = rtb_VectorConcatenate_a[1] * GRM_HIL_X.integration_eom_CSTATE[0];

  /* Sum: '<S346>/Add' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S351>/Product6'
   *  Sum: '<S351>/Sum2'
   */
  rtb_Product1_m[0] = GRM_HIL_X.integration_eom_CSTATE[3] - rtb_Product1_m[0];
  rtb_Product1_m[1] = GRM_HIL_X.integration_eom_CSTATE[4] - rtb_Product1_m[1];
  rtb_Gain_fl = GRM_HIL_X.integration_eom_CSTATE[5] - (rtb_VectorConcatenate_a[0]
    * GRM_HIL_X.integration_eom_CSTATE[1] - rtb_Abs_iw);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S304>/Constant8' */
    GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];
    GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];
    GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];
    GRM_HIL_B.Constant8_h[3] = GRM_HIL_P.Constant8_Value_oz[3];
  }

  /* Integrator: '<S304>/integration_eom' */
  if (GRM_HIL_DW.integration_eom_IWORK_l != 0) {
    GRM_HIL_X.integration_eom_CSTATE_f[0] = GRM_HIL_B.Constant8_h[0];
    GRM_HIL_X.integration_eom_CSTATE_f[1] = GRM_HIL_B.Constant8_h[1];
    GRM_HIL_X.integration_eom_CSTATE_f[2] = GRM_HIL_B.Constant8_h[2];
    GRM_HIL_X.integration_eom_CSTATE_f[3] = GRM_HIL_B.Constant8_h[3];
  }

  /* Sum: '<S298>/Add' incorporates:
   *  Constant: '<S298>/Q_1'
   *  Constant: '<S298>/Q_2'
   *  Constant: '<S298>/Q_3'
   *  Constant: '<S298>/Q_4'
   *  Integrator: '<S303>/integration_eom'
   *  Product: '<S298>/Product'
   *  Product: '<S298>/Product1'
   *  Product: '<S298>/Product2'
   *  Product: '<S298>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_d[i] * GRM_HIL_X.integration_eom_CSTATE_b[0]
               + GRM_HIL_P.Q_2_Value_nt[i] * GRM_HIL_X.integration_eom_CSTATE_b
               [1]) + GRM_HIL_P.Q_3_Value_o[i] *
              GRM_HIL_X.integration_eom_CSTATE_b[2]) + GRM_HIL_P.Q_4_Value_n[i] *
      GRM_HIL_X.integration_eom_CSTATE_b[3];
  }

  /* End of Sum: '<S298>/Add' */

  /* Product: '<S298>/Product8' incorporates:
   *  Integrator: '<S304>/integration_eom'
   */
  for (i = 0; i < 4; i++) {
    rtb_Divide1_h = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] + (tmp[i
      + 8] * GRM_HIL_X.integration_eom_CSTATE_f[2] + (tmp[i + 4] *
      GRM_HIL_X.integration_eom_CSTATE_f[1] + tmp[i] *
      GRM_HIL_X.integration_eom_CSTATE_f[0]));
    rtb_siB_h[i] = rtb_Divide1_h;
  }

  /* End of Product: '<S298>/Product8' */

  /* Product: '<S301>/Product2' */
  rtb_Abs_iw = rtb_siB_h[1] * rtb_siB_h[1];

  /* Sum: '<S301>/Add' incorporates:
   *  Product: '<S301>/Product1'
   *  Product: '<S301>/Product3'
   *  Product: '<S301>/Product4'
   */
  rtb_Gain1_c = ((rtb_siB_h[0] * rtb_siB_h[0] + rtb_Abs_iw) + rtb_siB_h[2] *
                 rtb_siB_h[2]) + rtb_siB_h[3] * rtb_siB_h[3];

  /* Math: '<S301>/Math Function'
   *
   * About '<S301>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Gain1_c < 0.0) {
    rtb_Gain1_c = -sqrt(fabs(rtb_Gain1_c));
  } else {
    rtb_Gain1_c = sqrt(rtb_Gain1_c);
  }

  /* End of Math: '<S301>/Math Function' */

  /* Product: '<S301>/Product' */
  rtb_siB_h[0] /= rtb_Gain1_c;
  rtb_siB_h[1] /= rtb_Gain1_c;
  rtb_siB_h[2] /= rtb_Gain1_c;
  rtb_Divide1_h = rtb_siB_h[3] / rtb_Gain1_c;

  /* Switch: '<S298>/Switch' incorporates:
   *  Constant: '<S298>/Constant'
   *  Constant: '<S298>/Constant1'
   */
  if (rtb_Divide1_h >= GRM_HIL_P.Switch_Threshold_g) {
    rtb_Gain1_c = GRM_HIL_P.Constant_Value_gc;
  } else {
    rtb_Gain1_c = GRM_HIL_P.Constant1_Value_ja;
  }

  /* End of Switch: '<S298>/Switch' */

  /* Product: '<S298>/Product4' */
  rtb_siB_h[0] *= rtb_Gain1_c;
  rtb_siB_h[1] *= rtb_Gain1_c;
  rtb_siB_h[2] *= rtb_Gain1_c;
  rtb_Divide1_h *= rtb_Gain1_c;

  /* Gain: '<S295>/Gain1' */
  rtb_Product4_n[0] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[0];
  rtb_Product4_n[1] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[1];
  rtb_Product4_n[2] = GRM_HIL_P.Gain1_Gain_p * rtb_siB_h[2];

  /* Sum: '<S296>/Add' incorporates:
   *  Constant: '<S296>/Q_1'
   *  Constant: '<S296>/Q_2'
   *  Constant: '<S296>/Q_3'
   *  Constant: '<S296>/Q_4'
   *  Product: '<S296>/Product'
   *  Product: '<S296>/Product1'
   *  Product: '<S296>/Product2'
   *  Product: '<S296>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_k[i] * rtb_Product4_n[0] +
               GRM_HIL_P.Q_2_Value_c[i] * rtb_Product4_n[1]) +
              GRM_HIL_P.Q_3_Value_f[i] * rtb_Product4_n[2]) +
      GRM_HIL_P.Q_4_Value_e[i] * rtb_Divide1_h;
  }

  /* End of Sum: '<S296>/Add' */

  /* Product: '<S296>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Divide1_h = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] *
      rtb_Product_idx_2 + (tmp[i + 4] * rtb_Product_idx_1 + tmp[i] *
      rtb_Product_idx_0));
    rtb_Product4_n[i] = rtb_Divide1_h;
  }

  /* End of Product: '<S296>/Product8' */

  /* Product: '<S299>/Product2' */
  rtb_Abs_iw = rtb_Product4_n[1] * rtb_Product4_n[1];

  /* Sum: '<S299>/Add' incorporates:
   *  Product: '<S299>/Product1'
   *  Product: '<S299>/Product3'
   *  Product: '<S299>/Product4'
   */
  rtb_Gain1_c = ((rtb_Product4_n[0] * rtb_Product4_n[0] + rtb_Abs_iw) +
                 rtb_Product4_n[2] * rtb_Product4_n[2]) + rtb_Product4_n[3] *
    rtb_Product4_n[3];

  /* Math: '<S299>/Math Function'
   *
   * About '<S299>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Gain1_c < 0.0) {
    rtb_Gain1_c = -sqrt(fabs(rtb_Gain1_c));
  } else {
    rtb_Gain1_c = sqrt(rtb_Gain1_c);
  }

  /* End of Math: '<S299>/Math Function' */

  /* Product: '<S299>/Product' */
  rtb_Product4_n[0] /= rtb_Gain1_c;
  rtb_Product4_n[1] /= rtb_Gain1_c;
  rtb_Product4_n[2] /= rtb_Gain1_c;
  rtb_Divide1_h = rtb_Product4_n[3] / rtb_Gain1_c;

  /* Switch: '<S296>/Switch' incorporates:
   *  Constant: '<S296>/Constant'
   *  Constant: '<S296>/Constant1'
   */
  if (rtb_Divide1_h >= GRM_HIL_P.Switch_Threshold_h) {
    rtb_Gain1_c = GRM_HIL_P.Constant_Value_ie;
  } else {
    rtb_Gain1_c = GRM_HIL_P.Constant1_Value_m;
  }

  /* End of Switch: '<S296>/Switch' */

  /* Product: '<S296>/Product4' */
  rtb_Product4_n[0] *= rtb_Gain1_c;
  rtb_Product4_n[1] *= rtb_Gain1_c;
  rtb_Product4_n[2] *= rtb_Gain1_c;
  rtb_Divide1_h *= rtb_Gain1_c;

  /* Math: '<S294>/Math Function1' incorporates:
   *  Math: '<S294>/Math Function5'
   *  Math: '<S294>/Math Function9'
   */
  rtb_Product4_e = rtb_Product4_n[1] * rtb_Product4_n[1];
  rtb_Abs_iw = rtb_Product4_e;

  /* Math: '<S294>/Math Function' incorporates:
   *  Math: '<S294>/Math Function4'
   *  Math: '<S294>/Math Function8'
   */
  rtb_lat = rtb_Product4_n[0] * rtb_Product4_n[0];

  /* Math: '<S294>/Math Function2' incorporates:
   *  Math: '<S294>/Math Function10'
   *  Math: '<S294>/Math Function6'
   */
  rtb_Cx = rtb_Product4_n[2] * rtb_Product4_n[2];

  /* Math: '<S294>/Math Function3' incorporates:
   *  Math: '<S294>/Math Function11'
   *  Math: '<S294>/Math Function7'
   */
  rtb_Add = rtb_Divide1_h * rtb_Divide1_h;

  /* Sum: '<S294>/Add' incorporates:
   *  Math: '<S294>/Math Function'
   *  Math: '<S294>/Math Function2'
   *  Math: '<S294>/Math Function3'
   */
  rtb_TBG[0] = ((rtb_lat - rtb_Abs_iw) - rtb_Cx) + rtb_Add;

  /* Product: '<S294>/Product' incorporates:
   *  Product: '<S294>/Product6'
   */
  rtb_Sqrt_j = rtb_Product4_n[0] * rtb_Product4_n[1];

  /* Product: '<S294>/Product1' incorporates:
   *  Product: '<S294>/Product7'
   */
  rtb_f_beB = rtb_Product4_n[2] * rtb_Divide1_h;

  /* Sum: '<S294>/Add1' incorporates:
   *  Gain: '<S294>/Gain1'
   *  Gain: '<S294>/Gain2'
   *  Product: '<S294>/Product'
   *  Product: '<S294>/Product1'
   */
  rtb_TBG[1] = rtb_Sqrt_j * GRM_HIL_P.Gain1_Gain_e - rtb_f_beB *
    GRM_HIL_P.Gain2_Gain_j;

  /* Product: '<S294>/Product8' incorporates:
   *  Product: '<S294>/Product4'
   */
  rtb_siB_c5 = rtb_Product4_n[0] * rtb_Product4_n[2];

  /* Product: '<S294>/Product9' incorporates:
   *  Product: '<S294>/Product5'
   */
  rtb_Gain_g = rtb_Product4_n[1] * rtb_Divide1_h;

  /* Sum: '<S294>/Add5' incorporates:
   *  Gain: '<S294>/Gain10'
   *  Gain: '<S294>/Gain9'
   *  Product: '<S294>/Product8'
   *  Product: '<S294>/Product9'
   */
  rtb_TBG[2] = rtb_siB_c5 * GRM_HIL_P.Gain9_Gain_m + rtb_Gain_g *
    GRM_HIL_P.Gain10_Gain_d;

  /* Sum: '<S294>/Add4' incorporates:
   *  Gain: '<S294>/Gain7'
   *  Gain: '<S294>/Gain8'
   */
  rtb_TBG[3] = rtb_Sqrt_j * GRM_HIL_P.Gain7_Gain_h + rtb_f_beB *
    GRM_HIL_P.Gain8_Gain_l;

  /* Math: '<S294>/Math Function5' */
  rtb_Abs_iw = rtb_Product4_e;

  /* Sum: '<S294>/Add6' */
  rtb_TBG[4] = ((rtb_Abs_iw - rtb_lat) - rtb_Cx) + rtb_Add;

  /* Product: '<S294>/Product2' incorporates:
   *  Product: '<S294>/Product10'
   */
  rtb_Sqrt_j = rtb_Product4_n[1] * rtb_Product4_n[2];

  /* Product: '<S294>/Product3' incorporates:
   *  Product: '<S294>/Product11'
   */
  rtb_f_beB = rtb_Product4_n[0] * rtb_Divide1_h;

  /* Sum: '<S294>/Add2' incorporates:
   *  Gain: '<S294>/Gain3'
   *  Gain: '<S294>/Gain4'
   *  Product: '<S294>/Product2'
   *  Product: '<S294>/Product3'
   */
  rtb_TBG[5] = rtb_Sqrt_j * GRM_HIL_P.Gain3_Gain_e - rtb_f_beB *
    GRM_HIL_P.Gain4_Gain_c;

  /* Sum: '<S294>/Add3' incorporates:
   *  Gain: '<S294>/Gain5'
   *  Gain: '<S294>/Gain6'
   */
  rtb_TBG[6] = rtb_siB_c5 * GRM_HIL_P.Gain5_Gain_c - rtb_Gain_g *
    GRM_HIL_P.Gain6_Gain_b;

  /* Sum: '<S294>/Add8' incorporates:
   *  Gain: '<S294>/Gain11'
   *  Gain: '<S294>/Gain12'
   */
  rtb_TBG[7] = rtb_Sqrt_j * GRM_HIL_P.Gain11_Gain_g + rtb_f_beB *
    GRM_HIL_P.Gain12_Gain_j;

  /* Math: '<S294>/Math Function9' */
  rtb_Abs_iw = rtb_Product4_e;

  /* Sum: '<S294>/Add7' */
  rtb_TBG[8] = ((rtb_Cx - rtb_lat) - rtb_Abs_iw) + rtb_Add;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S354>/Add' incorporates:
     *  Constant: '<S354>/course_angle_uncertainty'
     *  Constant: '<S354>/course_angle_wind'
     */
    rtb_Add = GRM_HIL_P.course_angle_wind_Value +
      GRM_HIL_P.course_angle_uncertainty_Value;

    /* MultiPortSwitch: '<S356>/Multiport Switch' incorporates:
     *  Constant: '<S356>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1) {
     case 1:
      /* Trigonometry: '<S357>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S357>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(rtb_Add);

      /* Trigonometry: '<S357>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S357>/Trigonometric Function'
       */
      rtb_Divide_h = cos(rtb_Add);

      /* SignalConversion generated from: '<S357>/Matrix Concatenate' incorporates:
       *  Constant: '<S357>/Constant7'
       *  Trigonometry: '<S357>/Trigonometric Function1'
       *  Trigonometry: '<S357>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_j;
      rtb_MultiportSwitch[7] = rtb_Gain1_c;
      rtb_MultiportSwitch[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S357>/Matrix Concatenate' incorporates:
       *  Constant: '<S357>/Constant8'
       *  Gain: '<S357>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_af;
      rtb_MultiportSwitch[4] = rtb_Divide_h;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_kj * rtb_Gain1_c;

      /* SignalConversion generated from: '<S357>/Matrix Concatenate' incorporates:
       *  Constant: '<S357>/Constant'
       *  Constant: '<S357>/Constant1'
       *  Constant: '<S357>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_b;
      break;

     case 2:
      /* Trigonometry: '<S358>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S358>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(rtb_Add);

      /* Trigonometry: '<S358>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S358>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(rtb_Add);

      /* SignalConversion generated from: '<S358>/Matrix Concatenate' incorporates:
       *  Constant: '<S358>/Constant7'
       *  Gain: '<S358>/Gain1'
       *  Trigonometry: '<S358>/Trigonometric Function1'
       *  Trigonometry: '<S358>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_j * rtb_Divide_h;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_d1;
      rtb_MultiportSwitch[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S358>/Matrix Concatenate' incorporates:
       *  Constant: '<S358>/Constant'
       *  Constant: '<S358>/Constant1'
       *  Constant: '<S358>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ob;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_i;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_g;

      /* SignalConversion generated from: '<S358>/Matrix Concatenate' incorporates:
       *  Constant: '<S358>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_Gain1_c;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_ky;
      rtb_MultiportSwitch[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S359>/Matrix Concatenate' incorporates:
       *  Constant: '<S359>/Constant10'
       *  Constant: '<S359>/Constant11'
       *  Constant: '<S359>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_o;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_d;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_a;

      /* Trigonometry: '<S359>/Trigonometric Function1' incorporates:
       *  Trigonometry: '<S359>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(rtb_Add);

      /* Trigonometry: '<S359>/Trigonometric Function' incorporates:
       *  Trigonometry: '<S359>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(rtb_Add);

      /* SignalConversion generated from: '<S359>/Matrix Concatenate' incorporates:
       *  Constant: '<S359>/Constant7'
       *  Trigonometry: '<S359>/Trigonometric Function'
       *  Trigonometry: '<S359>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_Gain1_c;
      rtb_MultiportSwitch[4] = rtb_Divide_h;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_g;

      /* SignalConversion generated from: '<S359>/Matrix Concatenate' incorporates:
       *  Constant: '<S359>/Constant8'
       *  Gain: '<S359>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Divide_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_jn * rtb_Gain1_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gg;
      break;
    }

    /* End of MultiPortSwitch: '<S356>/Multiport Switch' */

    /* Sum: '<S354>/Add1' incorporates:
     *  Constant: '<S354>/vWW'
     *  Constant: '<S354>/vWW_uncertainty'
     */
    rtb_VectorConcatenate_f[0] = GRM_HIL_P.vWW_uncertainty_Value +
      GRM_HIL_P.vWW_Value;

    /* SignalConversion generated from: '<S354>/Vector Concatenate' incorporates:
     *  Constant: '<S354>/Constant1'
     */
    rtb_VectorConcatenate_f[1] = GRM_HIL_P.Constant1_Value_fr;

    /* SignalConversion generated from: '<S354>/Vector Concatenate' incorporates:
     *  Constant: '<S354>/Constant1'
     */
    rtb_VectorConcatenate_f[2] = GRM_HIL_P.Constant1_Value_fr;

    /* Product: '<S355>/Product' */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.vec2[i] = 0.0;
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i] * rtb_VectorConcatenate_f[0];
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i + 3] * rtb_VectorConcatenate_f
        [1];
      GRM_HIL_B.vec2[i] += rtb_MultiportSwitch[i + 6] * rtb_VectorConcatenate_f
        [2];
    }

    /* End of Product: '<S355>/Product' */
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S344>/Math Function1' incorporates:
     *  Math: '<S201>/Math Function'
     */
    rtb_vBEB_a_tmp[3 * i] = rtb_TBG[i];
    rtb_vBEB_a_tmp[3 * i + 1] = rtb_TBG[i + 3];
    rtb_vBEB_a_tmp[3 * i + 2] = rtb_TBG[i + 6];

    /* Product: '<S344>/Product' */
    rtb_MatrixMultiply_tmp_0[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_Gain_fl +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_Product1_m[1] +
       rtb_MatrixMultiply_tmp[i] * rtb_Product1_m[0]);
  }

  /* DotProduct: '<S349>/Dot Product1' */
  rtb_Product4_e = 0.0;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S345>/Subtract' incorporates:
     *  Math: '<S344>/Math Function1'
     *  Product: '<S344>/Product1'
     */
    rtb_lat = rtb_MatrixMultiply_tmp_0[i] - (rtb_vBEB_a_tmp[i + 6] *
      GRM_HIL_B.vec2[2] + (rtb_vBEB_a_tmp[i + 3] * GRM_HIL_B.vec2[1] +
      rtb_vBEB_a_tmp[i] * GRM_HIL_B.vec2[0]));

    /* DotProduct: '<S349>/Dot Product1' */
    rtb_Product4_e += rtb_lat * rtb_lat;

    /* Sum: '<S345>/Subtract' */
    rtb_vBEB_a[i] = rtb_lat;
  }

  /* Math: '<S349>/Math Function1' incorporates:
   *  DotProduct: '<S349>/Dot Product1'
   *
   * About '<S349>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product4_e < 0.0) {
    rtb_Gain1_c = -sqrt(fabs(rtb_Product4_e));
  } else {
    rtb_Gain1_c = sqrt(rtb_Product4_e);
  }

  /* End of Math: '<S349>/Math Function1' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S268>/Subtract1' incorporates:
     *  Constant: '<S268>/Tmp_norm_msl'
     *  Constant: '<S353>/deviation_Tmp'
     */
    GRM_HIL_B.Tmp_ref = GRM_HIL_P.deviation_Tmp_Value +
      GRM_HIL_P.Tmp_norm_msl_Value;

    /* Constant: '<S329>/Constant' */
    GRM_HIL_B.VectorConcatenate1[0] = GRM_HIL_P.Constant_Value_b;

    /* Constant: '<S329>/Constant2' */
    GRM_HIL_B.VectorConcatenate1[1] = GRM_HIL_P.Constant2_Value_e5;

    /* Product: '<S333>/Product' incorporates:
     *  Constant: '<S331>/c_flat'
     *  Constant: '<S331>/c_rsma'
     *  Constant: '<S333>/Constant'
     *  Sum: '<S333>/Subtract'
     */
    GRM_HIL_B.Product = (GRM_HIL_P.Constant_Value_ne - GRM_HIL_P.c_flat_Value_e)
      * GRM_HIL_P.c_rsma_Value_j;

    /* Product: '<S333>/Product5' */
    rtb_Gain1_l = GRM_HIL_B.Product * GRM_HIL_B.Product;

    /* Product: '<S333>/Divide' incorporates:
     *  Constant: '<S331>/c_rsma'
     *  Product: '<S333>/Product4'
     *  Sum: '<S333>/Subtract2'
     */
    GRM_HIL_B.Divide = (GRM_HIL_P.c_rsma_Value_j * GRM_HIL_P.c_rsma_Value_j -
                        rtb_Gain1_l) / rtb_Gain1_l;

    /* Product: '<S333>/Product3' incorporates:
     *  Constant: '<S331>/c_flat'
     *  Product: '<S332>/Product3'
     */
    rtb_Product4_e = GRM_HIL_P.c_flat_Value_e * GRM_HIL_P.c_flat_Value_e;

    /* Sum: '<S333>/Subtract1' incorporates:
     *  Constant: '<S331>/c_flat'
     *  Gain: '<S333>/Gain'
     *  Product: '<S333>/Product3'
     */
    GRM_HIL_B.Subtract1 = GRM_HIL_P.Gain_Gain_le * GRM_HIL_P.c_flat_Value_e -
      rtb_Product4_e;

    /* Sum: '<S332>/Subtract' incorporates:
     *  Constant: '<S331>/c_flat'
     *  Gain: '<S332>/Gain'
     */
    GRM_HIL_B.Subtract = GRM_HIL_P.Gain_Gain_iy * GRM_HIL_P.c_flat_Value_e -
      rtb_Product4_e;
  }

  /* Switch: '<S329>/Switch' incorporates:
   *  Constant: '<S329>/Constant1'
   */
  if (GRM_HIL_P.Constant1_Value_bt > GRM_HIL_P.Switch_Threshold_c) {
    /* Gain: '<S329>/Gain' incorporates:
     *  Integrator: '<S335>/integration_eom'
     */
    GRM_HIL_B.VectorConcatenate1[2] = GRM_HIL_P.Gain_Gain_p *
      GRM_HIL_X.integration_eom_CSTATE[2];
    GRM_HIL_B.Switch[0] = GRM_HIL_B.VectorConcatenate1[0];
    GRM_HIL_B.Switch[1] = GRM_HIL_B.VectorConcatenate1[1];
    GRM_HIL_B.Switch[2] = GRM_HIL_B.VectorConcatenate1[2];
  } else {
    /* Product: '<S329>/Product' incorporates:
     *  Integrator: '<S335>/integration_eom'
     *  Math: '<S329>/Math Function'
     */
    for (i = 0; i < 3; i++) {
      rtb_pBEE[i] = rtb_VectorConcatenate3[3 * i + 2] *
        GRM_HIL_X.integration_eom_CSTATE[2] + (rtb_VectorConcatenate3[3 * i + 1]
        * GRM_HIL_X.integration_eom_CSTATE[1] + rtb_VectorConcatenate3[3 * i] *
        GRM_HIL_X.integration_eom_CSTATE[0]);
    }

    /* End of Product: '<S329>/Product' */

    /* Sqrt: '<S333>/Sqrt' incorporates:
     *  Product: '<S333>/Product1'
     *  Product: '<S333>/Product2'
     *  Sqrt: '<S332>/Sqrt'
     *  Sum: '<S333>/Add'
     */
    rtb_Add = sqrt(rtb_pBEE[0] * rtb_pBEE[0] + rtb_pBEE[1] * rtb_pBEE[1]);

    /* Trigonometry: '<S333>/Trigonometric Function' incorporates:
     *  Constant: '<S331>/c_rsma'
     *  Product: '<S333>/Divide1'
     *  Product: '<S333>/Product6'
     *  Product: '<S333>/Product7'
     *  Sqrt: '<S333>/Sqrt'
     */
    rtb_Sqrt_j = atan(rtb_pBEE[2] * GRM_HIL_P.c_rsma_Value_j / (rtb_Add *
      GRM_HIL_B.Product));

    /* Trigonometry: '<S333>/Trigonometric Function3' */
    rtb_lat = cos(rtb_Sqrt_j);

    /* Trigonometry: '<S333>/Trigonometric Function2' */
    rtb_Sqrt_j = sin(rtb_Sqrt_j);

    /* Trigonometry: '<S333>/Trigonometric Function1' incorporates:
     *  Constant: '<S331>/c_rsma'
     *  Product: '<S333>/Divide2'
     *  Product: '<S333>/Product10'
     *  Product: '<S333>/Product11'
     *  Product: '<S333>/Product8'
     *  Product: '<S333>/Product9'
     *  Sqrt: '<S333>/Sqrt'
     *  Sum: '<S333>/Add1'
     *  Sum: '<S333>/Subtract3'
     */
    rtb_lat = atan((rtb_Sqrt_j * rtb_Sqrt_j * rtb_Sqrt_j * (GRM_HIL_B.Divide *
      GRM_HIL_B.Product) + rtb_pBEE[2]) / (rtb_Add - rtb_lat * rtb_lat * rtb_lat
      * (GRM_HIL_B.Subtract1 * GRM_HIL_P.c_rsma_Value_j)));

    /* Trigonometry: '<S332>/Trigonometric Function' */
    rtb_Sqrt_j = sin(rtb_lat);

    /* Sqrt: '<S332>/Sqrt1' incorporates:
     *  Constant: '<S332>/Constant'
     *  Product: '<S332>/Product5'
     *  Sum: '<S332>/Subtract1'
     */
    rtb_Sqrt_j = sqrt(GRM_HIL_P.Constant_Value_nr - rtb_Sqrt_j * rtb_Sqrt_j *
                      GRM_HIL_B.Subtract);

    /* Sum: '<S332>/Sum' incorporates:
     *  Constant: '<S331>/c_rsma'
     *  Product: '<S332>/Product'
     *  Product: '<S332>/Product4'
     *  Trigonometry: '<S332>/cos(latGD)'
     */
    GRM_HIL_B.Switch[2] = rtb_Add / cos(rtb_lat) - GRM_HIL_P.c_rsma_Value_j /
      rtb_Sqrt_j;

    /* SignalConversion generated from: '<S329>/Vector Concatenate' */
    GRM_HIL_B.Switch[1] = rtb_lat;

    /* Trigonometry: '<S331>/Trigonometric Function1' */
    GRM_HIL_B.Switch[0] = rt_atan2d_snf(rtb_pBEE[1], rtb_pBEE[0]);
  }

  /* End of Switch: '<S329>/Switch' */

  /* Sum: '<S266>/Add' incorporates:
   *  Constant: '<S266>/mean_earth_radius'
   */
  rtb_Abs_iw = GRM_HIL_B.Switch[2] + GRM_HIL_P.geopot_height_mean_earth_radius;

  /* Product: '<S266>/Divide' incorporates:
   *  Constant: '<S266>/mean_earth_radius'
   */
  rtb_Abs_iw = GRM_HIL_B.Switch[2] / rtb_Abs_iw *
    GRM_HIL_P.geopot_height_mean_earth_radius;

  /* Saturate: '<S256>/Saturation' */
  if (rtb_Abs_iw > GRM_HIL_P.Saturation_UpperSat_h) {
    rtb_Abs_iw = GRM_HIL_P.Saturation_UpperSat_h;
  } else {
    if (rtb_Abs_iw < GRM_HIL_P.Saturation_LowerSat_k) {
      rtb_Abs_iw = GRM_HIL_P.Saturation_LowerSat_k;
    }
  }

  /* End of Saturate: '<S256>/Saturation' */

  /* Sum: '<S269>/Subtract' incorporates:
   *  Constant: '<S268>/geopotential_height_ref'
   *  Sum: '<S270>/Subtract'
   */
  rtb_Divide_jq_tmp = rtb_Abs_iw - GRM_HIL_P.geopotential_height_ref_Value;

  /* Sum: '<S269>/Add' incorporates:
   *  Constant: '<S269>/Tmp_gradient_tropo'
   *  Product: '<S269>/Product'
   *  Sum: '<S269>/Subtract'
   */
  rtb_Divide_h = rtb_Divide_jq_tmp * GRM_HIL_P.Tmp_gradient_tropo_Value +
    GRM_HIL_B.Tmp_ref;

  /* PreLookup: '<S241>/Prelookup_Mach' incorporates:
   *  Constant: '<S267>/heat_capacity_ratio'
   *  Constant: '<S267>/specific_gas_constant'
   *  Product: '<S267>/Product'
   *  Product: '<S345>/Divide'
   *  Sqrt: '<S267>/Sqrt'
   */
  rtb_k_Mach = plook_binc(rtb_Gain1_c / sqrt
    (GRM_HIL_P.specific_gas_constant_Value * GRM_HIL_P.heat_capacity_ratio_Value
     * rtb_Divide_h), GRM_HIL_P.Prelookup_Mach_BreakpointsData, 8U, &rtb_lat);

  /* DotProduct: '<S350>/Dot Product1' */
  rtb_Product4_e = (rtb_vBEB_a[0] * rtb_vBEB_a[0] + rtb_vBEB_a[1] * rtb_vBEB_a[1])
    + rtb_vBEB_a[2] * rtb_vBEB_a[2];

  /* Math: '<S350>/Math Function1' incorporates:
   *  DotProduct: '<S350>/Dot Product1'
   *
   * About '<S350>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product4_e < 0.0) {
    rtb_Add = -sqrt(fabs(rtb_Product4_e));
  } else {
    rtb_Add = sqrt(rtb_Product4_e);
  }

  /* End of Math: '<S350>/Math Function1' */

  /* Switch: '<S347>/Switch' incorporates:
   *  Constant: '<S347>/Constant'
   */
  if (rtb_Add != 0.0) {
    /* SignalConversion generated from: '<S347>/Vector Concatenate' */
    rtb_siB_h[3] = rtb_Add;

    /* SignalConversion generated from: '<S347>/Vector Concatenate' */
    rtb_siB_h[2] = rtb_vBEB_a[2];

    /* SignalConversion generated from: '<S347>/Vector Concatenate' */
    rtb_siB_h[1] = rtb_vBEB_a[1];

    /* SignalConversion generated from: '<S347>/Vector Concatenate' */
    rtb_siB_h[0] = rtb_vBEB_a[0];
  } else {
    rtb_siB_h[0] = GRM_HIL_P.Constant_Value_jc[0];
    rtb_siB_h[1] = GRM_HIL_P.Constant_Value_jc[1];
    rtb_siB_h[2] = GRM_HIL_P.Constant_Value_jc[2];
    rtb_siB_h[3] = GRM_HIL_P.Constant_Value_jc[3];
  }

  /* End of Switch: '<S347>/Switch' */

  /* Gain: '<S246>/Gain' incorporates:
   *  Trigonometry: '<S347>/Trigonometric Function'
   */
  rtb_Divide1_h = GRM_HIL_P.Gain_Gain_nn * rt_atan2d_snf(rtb_siB_h[2],
    rtb_siB_h[0]);

  /* PreLookup: '<S241>/Prelookup_alB' */
  rtb_k_alB = plook_binc(rtb_Divide1_h, GRM_HIL_P.Prelookup_alB_BreakpointsData,
    16U, &rtb_Sqrt_j);

  /* Product: '<S347>/Divide' */
  u0 = rtb_siB_h[1] / rtb_siB_h[3];

  /* Trigonometry: '<S347>/Trigonometric Function1' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Gain: '<S247>/Gain' incorporates:
   *  Trigonometry: '<S347>/Trigonometric Function1'
   */
  rtb_Subtract_e = GRM_HIL_P.Gain_Gain_kz * asin(u0);

  /* PreLookup: '<S241>/Prelookup_beB' */
  rtb_k_beB = plook_binc(rtb_Subtract_e, GRM_HIL_P.Prelookup_beB_BreakpointsData,
    16U, &rtb_f_beB);

  /* Interpolation_n-D: '<S238>/Cx_Interpolation' */
  frac[0] = rtb_lat;
  frac[1] = rtb_Sqrt_j;
  frac[2] = rtb_f_beB;
  bpIndex[0] = rtb_k_Mach;
  bpIndex[1] = rtb_k_alB;
  bpIndex[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex, frac, GRM_HIL_P.Cx_Interpolation_Table,
    GRM_HIL_P.Cx_Interpolation_dimSize);

  /* Product: '<S238>/Product' incorporates:
   *  Constant: '<S238>/Constant'
   */
  rtb_Cx = GRM_HIL_P.Constant_Value_i3 * rtb_siB_c5;

  /* Saturate: '<S348>/Saturation1' */
  if (rtb_Gain1_c > GRM_HIL_P.Saturation1_UpperSat) {
    rtb_Product4_e = GRM_HIL_P.Saturation1_UpperSat;
  } else if (rtb_Gain1_c < GRM_HIL_P.Saturation1_LowerSat) {
    rtb_Product4_e = GRM_HIL_P.Saturation1_LowerSat;
  } else {
    rtb_Product4_e = rtb_Gain1_c;
  }

  /* End of Saturate: '<S348>/Saturation1' */

  /* Product: '<S348>/Divide1' incorporates:
   *  Constant: '<S348>/Constant1'
   */
  rtb_siB_c5 = 1.0 / rtb_Product4_e * GRM_HIL_P.Constant1_Value_is;

  /* Product: '<S348>/Product3' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Product1_m[1] = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[11];

  /* Product: '<S348>/Product4' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  rtb_Product1_m[2] = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[12];

  /* Gain: '<S251>/Gain' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S348>/Product2'
   */
  rtb_Gain_g = rtb_siB_c5 * GRM_HIL_X.integration_eom_CSTATE[10] *
    GRM_HIL_P.Gain_Gain_b;

  /* Interpolation_n-D: '<S238>/Cxp_Interpolation' */
  frac_0[0] = rtb_lat;
  frac_0[1] = rtb_Sqrt_j;
  frac_0[2] = rtb_f_beB;
  bpIndex_0[0] = rtb_k_Mach;
  bpIndex_0[1] = rtb_k_alB;
  bpIndex_0[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_0, frac_0, GRM_HIL_P.Cxp_Interpolation_Table,
    GRM_HIL_P.Cxp_Interpolation_dimSize);

  /* Product: '<S218>/Product' */
  rtb_Product_l = rtb_Gain_g * rtb_siB_c5;

  /* Gain: '<S252>/Gain' */
  rtb_Gain_lt = GRM_HIL_P.Gain_Gain_hp * rtb_Product1_m[1];

  /* Interpolation_n-D: '<S238>/Cxq_Interpolation' */
  frac_1[0] = rtb_lat;
  frac_1[1] = rtb_Sqrt_j;
  frac_1[2] = rtb_f_beB;
  bpIndex_1[0] = rtb_k_Mach;
  bpIndex_1[1] = rtb_k_alB;
  bpIndex_1[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_1, frac_1, GRM_HIL_P.Cxq_Interpolation_Table,
    GRM_HIL_P.Cxq_Interpolation_dimSize);

  /* Product: '<S218>/Product1' */
  rtb_Product1 = rtb_Gain_lt * rtb_siB_c5;

  /* Gain: '<S253>/Gain' */
  rtb_Gain_af = GRM_HIL_P.Gain_Gain_bz * rtb_Product1_m[2];

  /* Interpolation_n-D: '<S238>/Cxr_Interpolation' */
  frac_2[0] = rtb_lat;
  frac_2[1] = rtb_Sqrt_j;
  frac_2[2] = rtb_f_beB;
  bpIndex_2[0] = rtb_k_Mach;
  bpIndex_2[1] = rtb_k_alB;
  bpIndex_2[2] = rtb_k_beB;
  rtb_siB_c5 = intrp3d_l_pw(bpIndex_2, frac_2, GRM_HIL_P.Cxr_Interpolation_Table,
    GRM_HIL_P.Cxr_Interpolation_dimSize);

  /* Integrator: '<S271>/Integrator1' */
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
    /* Signum: '<S271>/Sign' incorporates:
     *  Constant: '<S200>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Product3_hu = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Product3_hu = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Product3_hu = 0.0;
    } else {
      rtb_Product3_hu = (rtNaN);
    }

    /* End of Signum: '<S271>/Sign' */

    /* Gain: '<S271>/Gain3' */
    GRM_HIL_B.Gain3 = GRM_HIL_P.Rudder_unc_bl * rtb_Product3_hu;
  }

  /* Sum: '<S271>/Add2' incorporates:
   *  Constant: '<S271>/Constant'
   *  Gain: '<S271>/Gain1'
   *  Integrator: '<S271>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder_unc_scale * GRM_HIL_X.Integrator1_CSTATE +
        GRM_HIL_P.Rudder_unc_off) + GRM_HIL_B.Gain3;

  /* Saturate: '<S271>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder_siB_max) {
    rtb_siB = GRM_HIL_P.Rudder_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder_siB_min) {
    rtb_siB = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_siB = u0;
  }

  /* End of Saturate: '<S271>/Saturation1' */

  /* Integrator: '<S272>/Integrator1' */
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
    /* Signum: '<S272>/Sign' incorporates:
     *  Constant: '<S200>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Product3_hu = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Product3_hu = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Product3_hu = 0.0;
    } else {
      rtb_Product3_hu = (rtNaN);
    }

    /* End of Signum: '<S272>/Sign' */

    /* Gain: '<S272>/Gain3' */
    GRM_HIL_B.Gain3_m = GRM_HIL_P.Rudder1_unc_bl * rtb_Product3_hu;
  }

  /* Sum: '<S272>/Add2' incorporates:
   *  Constant: '<S272>/Constant'
   *  Gain: '<S272>/Gain1'
   *  Integrator: '<S272>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder1_unc_scale * GRM_HIL_X.Integrator1_CSTATE_g +
        GRM_HIL_P.Rudder1_unc_off) + GRM_HIL_B.Gain3_m;

  /* Saturate: '<S272>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder1_siB_max) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder1_siB_min) {
    rtb_siB_d = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_siB_d = u0;
  }

  /* End of Saturate: '<S272>/Saturation1' */

  /* Integrator: '<S273>/Integrator1' */
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
    /* Signum: '<S273>/Sign' incorporates:
     *  Constant: '<S200>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Product3_hu = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Product3_hu = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Product3_hu = 0.0;
    } else {
      rtb_Product3_hu = (rtNaN);
    }

    /* End of Signum: '<S273>/Sign' */

    /* Gain: '<S273>/Gain3' */
    GRM_HIL_B.Gain3_b = GRM_HIL_P.Rudder2_unc_bl * rtb_Product3_hu;
  }

  /* Sum: '<S273>/Add2' incorporates:
   *  Constant: '<S273>/Constant'
   *  Gain: '<S273>/Gain1'
   *  Integrator: '<S273>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder2_unc_scale * GRM_HIL_X.Integrator1_CSTATE_a +
        GRM_HIL_P.Rudder2_unc_off) + GRM_HIL_B.Gain3_b;

  /* Saturate: '<S273>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder2_siB_max) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder2_siB_min) {
    rtb_siB_i = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_siB_i = u0;
  }

  /* End of Saturate: '<S273>/Saturation1' */

  /* Integrator: '<S274>/Integrator1' */
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
    /* Signum: '<S274>/Sign' incorporates:
     *  Constant: '<S200>/Constant7'
     */
    if (GRM_HIL_P.Constant7_Value_dr < 0.0) {
      rtb_Product3_hu = -1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr > 0.0) {
      rtb_Product3_hu = 1.0;
    } else if (GRM_HIL_P.Constant7_Value_dr == 0.0) {
      rtb_Product3_hu = 0.0;
    } else {
      rtb_Product3_hu = (rtNaN);
    }

    /* End of Signum: '<S274>/Sign' */

    /* Gain: '<S274>/Gain3' */
    GRM_HIL_B.Gain3_h = GRM_HIL_P.Rudder3_unc_bl * rtb_Product3_hu;
  }

  /* Sum: '<S274>/Add2' incorporates:
   *  Constant: '<S274>/Constant'
   *  Gain: '<S274>/Gain1'
   *  Integrator: '<S274>/Integrator1'
   */
  u0 = (GRM_HIL_P.Rudder3_unc_scale * GRM_HIL_X.Integrator1_CSTATE_i +
        GRM_HIL_P.Rudder3_unc_off) + GRM_HIL_B.Gain3_h;

  /* Saturate: '<S274>/Saturation1' */
  if (u0 > GRM_HIL_P.Rudder3_siB_max) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_max;
  } else if (u0 < GRM_HIL_P.Rudder3_siB_min) {
    rtb_siB_o = GRM_HIL_P.Rudder3_siB_min;
  } else {
    rtb_siB_o = u0;
  }

  /* End of Saturate: '<S274>/Saturation1' */

  /* Product: '<S275>/Product' incorporates:
   *  Constant: '<S275>/Constant8'
   *  SignalConversion generated from: '<S200>/Vector Concatenate1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain_fl = GRM_HIL_P.Constant8_Value_g2[i + 9] * rtb_siB_o +
      (GRM_HIL_P.Constant8_Value_g2[i + 6] * rtb_siB_i +
       (GRM_HIL_P.Constant8_Value_g2[i + 3] * rtb_siB_d +
        GRM_HIL_P.Constant8_Value_g2[i] * rtb_siB));
    rtb_Product1_m[i] = rtb_Gain_fl;
  }

  /* End of Product: '<S275>/Product' */

  /* Gain: '<S248>/Gain' */
  rtb_Gain_fl = GRM_HIL_P.Gain_Gain_aj * rtb_Product1_m[0];

  /* Interpolation_n-D: '<S238>/Cx_delta_l_Interpolation' */
  frac_3[0] = rtb_lat;
  frac_3[1] = rtb_Sqrt_j;
  frac_3[2] = rtb_f_beB;
  bpIndex_3[0] = rtb_k_Mach;
  bpIndex_3[1] = rtb_k_alB;
  bpIndex_3[2] = rtb_k_beB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_3, frac_3,
    GRM_HIL_P.Cx_delta_l_Interpolation_Table,
    GRM_HIL_P.Cx_delta_l_Interpolation_dimSize);

  /* Product: '<S218>/Product3' */
  rtb_Product3_hu = rtb_Gain_fl * rtb_Product7_ma;

  /* Gain: '<S249>/Gain' */
  rtb_Gain_nk = GRM_HIL_P.Gain_Gain_l4 * rtb_Product1_m[1];

  /* Interpolation_n-D: '<S238>/Cx_delta_m_Interpolation' */
  frac_4[0] = rtb_lat;
  frac_4[1] = rtb_Sqrt_j;
  frac_4[2] = rtb_f_beB;
  bpIndex_4[0] = rtb_k_Mach;
  bpIndex_4[1] = rtb_k_alB;
  bpIndex_4[2] = rtb_k_beB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_4, frac_4,
    GRM_HIL_P.Cx_delta_m_Interpolation_Table,
    GRM_HIL_P.Cx_delta_m_Interpolation_dimSize);

  /* Product: '<S218>/Product4' */
  rtb_Product4_e = rtb_Gain_nk * rtb_Product7_ma;

  /* Gain: '<S250>/Gain' */
  rtb_Gain_n = GRM_HIL_P.Gain_Gain_pr * rtb_Product1_m[2];

  /* Interpolation_n-D: '<S238>/Cx_delta_n_Interpolation' */
  frac_5[0] = rtb_lat;
  frac_5[1] = rtb_Sqrt_j;
  frac_5[2] = rtb_f_beB;
  bpIndex_5[0] = rtb_k_Mach;
  bpIndex_5[1] = rtb_k_alB;
  bpIndex_5[2] = rtb_k_beB;
  rtb_Product7_ma = intrp3d_l_pw(bpIndex_5, frac_5,
    GRM_HIL_P.Cx_delta_n_Interpolation_Table,
    GRM_HIL_P.Cx_delta_n_Interpolation_dimSize);

  /* Product: '<S218>/Product5' */
  rtb_Product5 = rtb_Gain_n * rtb_Product7_ma;

  /* Interpolation_n-D: '<S238>/Cx_alt_Interpolation' incorporates:
   *  PreLookup: '<S238>/Prelookup_altitude'
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
    /* Sqrt: '<S242>/Sqrt' incorporates:
     *  Constant: '<S242>/Constant3'
     */
    GRM_HIL_B.Sqrt = sqrt(GRM_HIL_P.Constant3_Value_f);
  }

  /* Gain: '<S245>/Gain' incorporates:
   *  Gain: '<S243>/Gain1'
   *  Gain: '<S244>/Gain1'
   *  Product: '<S242>/Product1'
   *  Trigonometry: '<S242>/Trigonometric Function'
   *  Trigonometry: '<S242>/Trigonometric Function1'
   *  Trigonometry: '<S242>/Trigonometric Function2'
   */
  u0 = acos(cos(GRM_HIL_P.Gain1_Gain_b * rtb_Divide1_h) * cos
            (GRM_HIL_P.Gain1_Gain_e2 * rtb_Subtract_e)) * GRM_HIL_P.Gain_Gain_if;

  /* Saturate: '<S242>/Saturation' */
  if (u0 > GRM_HIL_P.Saturation_UpperSat_f) {
    u0 = GRM_HIL_P.Saturation_UpperSat_f;
  } else {
    if (u0 < GRM_HIL_P.Saturation_LowerSat_g) {
      u0 = GRM_HIL_P.Saturation_LowerSat_g;
    }
  }

  /* End of Saturate: '<S242>/Saturation' */

  /* Abs: '<S242>/Abs2' incorporates:
   *  Abs: '<S242>/Abs'
   *  Abs: '<S242>/Abs1'
   *  Product: '<S242>/Divide2'
   *  Product: '<S242>/Product6'
   *  Product: '<S242>/Product7'
   *  Sum: '<S242>/Add'
   */
  rtb_Product6_n4 = fabs((fabs(rtb_Divide1_h) * rtb_Gain_nk + fabs
    (rtb_Subtract_e) * rtb_Gain_n) * GRM_HIL_B.Sqrt / u0);

  /* Interpolation_n-D: '<S238>/Cx_delta_t_Interpolation' incorporates:
   *  PreLookup: '<S238>/Prelookup_delta_t'
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

  /* Interpolation_n-D: '<S238>/Cx_base_Interpolation' */
  frac_8[0] = rtb_lat;
  frac_8[1] = rtb_Sqrt_j;
  frac_8[2] = rtb_f_beB;
  bpIndex_8[0] = rtb_k_Mach;
  bpIndex_8[1] = rtb_k_alB;
  bpIndex_8[2] = rtb_k_beB;
  rtb_Subtract_e = intrp3d_l_pw(bpIndex_8, frac_8,
    GRM_HIL_P.Cx_base_Interpolation_Table,
    GRM_HIL_P.Cx_base_Interpolation_dimSize);

  /* Clock: '<S352>/Clock' incorporates:
   *  Derivative: '<S305>/Derivative'
   *  Derivative: '<S305>/Derivative1'
   */
  rtb_Add = GRM_HIL_M->Timing.t[0];

  /* Sum: '<S217>/Subtract' incorporates:
   *  Clock: '<S352>/Clock'
   *  Constant: '<S352>/Constant6'
   *  Sum: '<S210>/Subtract'
   *  Sum: '<S314>/Subtract'
   */
  u0 = rtb_Add - GRM_HIL_P.Constant6_Value_i;

  /* Sum: '<S218>/Add' incorporates:
   *  Constant: '<S217>/Constant'
   *  MATLAB Function: '<S217>/MATLAB Function'
   *  Product: '<S218>/Product2'
   *  Product: '<S218>/Product8'
   *  Sum: '<S217>/Subtract'
   */
  rtb_Product1_m[0] = ((((((((rtb_Cx + rtb_Product_l) + rtb_Product1) +
    rtb_Gain_af * rtb_siB_c5) + rtb_Product3_hu) + rtb_Product4_e) +
    rtb_Product5) + rtb_Product7_ma) + rtb_Product6_n4) + (real_T)((!(u0 >= 0.0))
    || (!(u0 <= GRM_HIL_P.Constant_Value_ok))) * rtb_Subtract_e;

  /* Interpolation_n-D: '<S239>/Cy_Interpolation' */
  frac_9[0] = rtb_lat;
  frac_9[1] = rtb_Sqrt_j;
  frac_9[2] = rtb_f_beB;
  bpIndex_9[0] = rtb_k_Mach;
  bpIndex_9[1] = rtb_k_alB;
  bpIndex_9[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_9, frac_9,
    GRM_HIL_P.Cy_Interpolation_Table, GRM_HIL_P.Cy_Interpolation_dimSize);

  /* Product: '<S239>/Product' incorporates:
   *  Constant: '<S239>/Constant'
   */
  rtb_siB_c5 = GRM_HIL_P.Constant_Value_oz * rtb_Product6_n4;

  /* Interpolation_n-D: '<S239>/Cyp_Interpolation' */
  frac_a[0] = rtb_lat;
  frac_a[1] = rtb_Sqrt_j;
  frac_a[2] = rtb_f_beB;
  bpIndex_a[0] = rtb_k_Mach;
  bpIndex_a[1] = rtb_k_alB;
  bpIndex_a[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_a, frac_a,
    GRM_HIL_P.Cyp_Interpolation_Table, GRM_HIL_P.Cyp_Interpolation_dimSize);

  /* Product: '<S218>/Product6' */
  rtb_Cx = rtb_Gain_g * rtb_Product6_n4;

  /* Interpolation_n-D: '<S239>/Cyq_Interpolation' */
  frac_b[0] = rtb_lat;
  frac_b[1] = rtb_Sqrt_j;
  frac_b[2] = rtb_f_beB;
  bpIndex_b[0] = rtb_k_Mach;
  bpIndex_b[1] = rtb_k_alB;
  bpIndex_b[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_b, frac_b,
    GRM_HIL_P.Cyq_Interpolation_Table, GRM_HIL_P.Cyq_Interpolation_dimSize);

  /* Product: '<S218>/Product7' */
  rtb_Product7_ma = rtb_Gain_lt * rtb_Product6_n4;

  /* Interpolation_n-D: '<S239>/Cyr_Interpolation' */
  frac_c[0] = rtb_lat;
  frac_c[1] = rtb_Sqrt_j;
  frac_c[2] = rtb_f_beB;
  bpIndex_c[0] = rtb_k_Mach;
  bpIndex_c[1] = rtb_k_alB;
  bpIndex_c[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_c, frac_c,
    GRM_HIL_P.Cyr_Interpolation_Table, GRM_HIL_P.Cyr_Interpolation_dimSize);

  /* Product: '<S218>/Product9' */
  rtb_Subtract_e = rtb_Gain_af * rtb_Product6_n4;

  /* Interpolation_n-D: '<S239>/Cy_delta_l_Interpolation' */
  frac_d[0] = rtb_lat;
  frac_d[1] = rtb_Sqrt_j;
  frac_d[2] = rtb_f_beB;
  bpIndex_d[0] = rtb_k_Mach;
  bpIndex_d[1] = rtb_k_alB;
  bpIndex_d[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_d, frac_d,
    GRM_HIL_P.Cy_delta_l_Interpolation_Table,
    GRM_HIL_P.Cy_delta_l_Interpolation_dimSize);

  /* Product: '<S218>/Product10' */
  rtb_Divide1_h = rtb_Gain_fl * rtb_Product6_n4;

  /* Interpolation_n-D: '<S239>/Cy_delta_m_Interpolation' */
  frac_e[0] = rtb_lat;
  frac_e[1] = rtb_Sqrt_j;
  frac_e[2] = rtb_f_beB;
  bpIndex_e[0] = rtb_k_Mach;
  bpIndex_e[1] = rtb_k_alB;
  bpIndex_e[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_e, frac_e,
    GRM_HIL_P.Cy_delta_m_Interpolation_Table,
    GRM_HIL_P.Cy_delta_m_Interpolation_dimSize);

  /* Product: '<S218>/Product11' */
  rtb_Product_l = rtb_Gain_nk * rtb_Product6_n4;

  /* Interpolation_n-D: '<S239>/Cy_delta_n_Interpolation' */
  frac_f[0] = rtb_lat;
  frac_f[1] = rtb_Sqrt_j;
  frac_f[2] = rtb_f_beB;
  bpIndex_f[0] = rtb_k_Mach;
  bpIndex_f[1] = rtb_k_alB;
  bpIndex_f[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_f, frac_f,
    GRM_HIL_P.Cy_delta_n_Interpolation_Table,
    GRM_HIL_P.Cy_delta_n_Interpolation_dimSize);

  /* Sum: '<S218>/Add1' incorporates:
   *  Product: '<S218>/Product12'
   */
  rtb_Product1_m[1] = (((((rtb_siB_c5 + rtb_Cx) + rtb_Product7_ma) +
    rtb_Subtract_e) + rtb_Divide1_h) + rtb_Product_l) + rtb_Gain_n *
    rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Cz_Interpolation' */
  frac_g[0] = rtb_lat;
  frac_g[1] = rtb_Sqrt_j;
  frac_g[2] = rtb_f_beB;
  bpIndex_g[0] = rtb_k_Mach;
  bpIndex_g[1] = rtb_k_alB;
  bpIndex_g[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_g, frac_g,
    GRM_HIL_P.Cz_Interpolation_Table, GRM_HIL_P.Cz_Interpolation_dimSize);

  /* Product: '<S240>/Product' incorporates:
   *  Constant: '<S240>/Constant'
   */
  rtb_siB_c5 = GRM_HIL_P.Constant_Value_gw * rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Czp_Interpolation' */
  frac_h[0] = rtb_lat;
  frac_h[1] = rtb_Sqrt_j;
  frac_h[2] = rtb_f_beB;
  bpIndex_h[0] = rtb_k_Mach;
  bpIndex_h[1] = rtb_k_alB;
  bpIndex_h[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_h, frac_h,
    GRM_HIL_P.Czp_Interpolation_Table, GRM_HIL_P.Czp_Interpolation_dimSize);

  /* Product: '<S218>/Product16' */
  rtb_Cx = rtb_Gain_g * rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Czq_Interpolation' */
  frac_i[0] = rtb_lat;
  frac_i[1] = rtb_Sqrt_j;
  frac_i[2] = rtb_f_beB;
  bpIndex_i[0] = rtb_k_Mach;
  bpIndex_i[1] = rtb_k_alB;
  bpIndex_i[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_i, frac_i,
    GRM_HIL_P.Czq_Interpolation_Table, GRM_HIL_P.Czq_Interpolation_dimSize);

  /* Product: '<S218>/Product17' */
  rtb_Product7_ma = rtb_Gain_lt * rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Czr_Interpolation' */
  frac_j[0] = rtb_lat;
  frac_j[1] = rtb_Sqrt_j;
  frac_j[2] = rtb_f_beB;
  bpIndex_j[0] = rtb_k_Mach;
  bpIndex_j[1] = rtb_k_alB;
  bpIndex_j[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_j, frac_j,
    GRM_HIL_P.Czr_Interpolation_Table, GRM_HIL_P.Czr_Interpolation_dimSize);

  /* Product: '<S218>/Product18' */
  rtb_Subtract_e = rtb_Gain_af * rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Cz_delta_l_Interpolation' */
  frac_k[0] = rtb_lat;
  frac_k[1] = rtb_Sqrt_j;
  frac_k[2] = rtb_f_beB;
  bpIndex_k[0] = rtb_k_Mach;
  bpIndex_k[1] = rtb_k_alB;
  bpIndex_k[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_k, frac_k,
    GRM_HIL_P.Cz_delta_l_Interpolation_Table,
    GRM_HIL_P.Cz_delta_l_Interpolation_dimSize);

  /* Product: '<S218>/Product13' */
  rtb_Divide1_h = rtb_Gain_fl * rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Cz_delta_m_Interpolation' */
  frac_l[0] = rtb_lat;
  frac_l[1] = rtb_Sqrt_j;
  frac_l[2] = rtb_f_beB;
  bpIndex_l[0] = rtb_k_Mach;
  bpIndex_l[1] = rtb_k_alB;
  bpIndex_l[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_l, frac_l,
    GRM_HIL_P.Cz_delta_m_Interpolation_Table,
    GRM_HIL_P.Cz_delta_m_Interpolation_dimSize);

  /* Product: '<S218>/Product14' */
  rtb_Product_l = rtb_Gain_nk * rtb_Product6_n4;

  /* Interpolation_n-D: '<S240>/Cz_delta_n_Interpolation' */
  frac_m[0] = rtb_lat;
  frac_m[1] = rtb_Sqrt_j;
  frac_m[2] = rtb_f_beB;
  bpIndex_m[0] = rtb_k_Mach;
  bpIndex_m[1] = rtb_k_alB;
  bpIndex_m[2] = rtb_k_beB;
  rtb_Product6_n4 = intrp3d_l_pw(bpIndex_m, frac_m,
    GRM_HIL_P.Cz_delta_n_Interpolation_Table,
    GRM_HIL_P.Cz_delta_n_Interpolation_dimSize);

  /* Sum: '<S218>/Add2' incorporates:
   *  Product: '<S218>/Product15'
   */
  rtb_Product1_m[2] = (((((rtb_siB_c5 + rtb_Cx) + rtb_Product7_ma) +
    rtb_Subtract_e) + rtb_Divide1_h) + rtb_Product_l) + rtb_Gain_n *
    rtb_Product6_n4;

  /* Sum: '<S270>/Add' incorporates:
   *  Constant: '<S270>/Constant1'
   *  Constant: '<S270>/Tmp_gradient_tropo'
   *  Product: '<S270>/Divide'
   */
  rtb_Product6_n4 = rtb_Divide_jq_tmp / GRM_HIL_B.Tmp_ref *
    GRM_HIL_P.Tmp_gradient_tropo_Value_l + GRM_HIL_P.Constant1_Value_mh;

  /* Math: '<S270>/Math Function' incorporates:
   *  Constant: '<S270>/pressure_exponent'
   */
  if ((rtb_Product6_n4 < 0.0) && (GRM_HIL_P.pressure_exponent_Value > floor
       (GRM_HIL_P.pressure_exponent_Value))) {
    rtb_Product6_n4 = -rt_powd_snf(-rtb_Product6_n4,
      GRM_HIL_P.pressure_exponent_Value);
  } else {
    rtb_Product6_n4 = rt_powd_snf(rtb_Product6_n4,
      GRM_HIL_P.pressure_exponent_Value);
  }

  /* End of Math: '<S270>/Math Function' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S268>/Subtract2' incorporates:
     *  Constant: '<S268>/pa_norm_msl'
     *  Constant: '<S353>/deviation_pa_QFH'
     */
    GRM_HIL_B.pa_ref = GRM_HIL_P.deviation_pa_QFH_Value +
      GRM_HIL_P.pa_norm_msl_Value;
  }

  /* Product: '<S219>/Product2' incorporates:
   *  Constant: '<S219>/Constant2'
   *  Constant: '<S265>/specific_gas_constant'
   *  Constant: '<S345>/Constant'
   *  Math: '<S345>/Math Function1'
   *  Product: '<S265>/Divide'
   *  Product: '<S270>/Product'
   *  Product: '<S345>/Product1'
   */
  rtb_siB_c5 = 1.0 / rtb_Divide_h * (rtb_Product6_n4 * GRM_HIL_B.pa_ref) /
    GRM_HIL_P.specific_gas_constant_Value_c * (rtb_Gain1_c * rtb_Gain1_c *
    GRM_HIL_P.Constant_Value_ii) * GRM_HIL_P.Constant2_Value_a2;

  /* Product: '<S219>/Product' */
  rtb_vBEB_a[0] = rtb_Product1_m[0] * rtb_siB_c5;
  rtb_vBEB_a[1] = rtb_Product1_m[1] * rtb_siB_c5;
  rtb_vBEB_a[2] = rtb_Product1_m[2] * rtb_siB_c5;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S227>/Switch1' incorporates:
     *  Constant: '<S227>/Constant'
     *  Constant: '<S227>/Constant2'
     *  Constant: '<S228>/c_flat'
     *  Constant: '<S228>/c_rsma'
     *  Constant: '<S229>/Constant'
     *  Gain: '<S227>/Gain'
     *  Gain: '<S229>/Gain'
     *  Product: '<S229>/Product'
     *  Product: '<S229>/Product4'
     *  Product: '<S229>/Product5'
     *  Sqrt: '<S229>/Sqrt1'
     *  Sum: '<S229>/Subtract'
     *  Sum: '<S229>/Subtract1'
     *  Sum: '<S229>/Sum'
     *  Trigonometry: '<S229>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_o > GRM_HIL_P.Switch1_Threshold) {
      GRM_HIL_B.hBE_0 = GRM_HIL_P.Gain_Gain_i * GRM_HIL_P.Constant_Value_iu[2];
    } else {
      /* Sqrt: '<S230>/Sqrt' incorporates:
       *  Constant: '<S227>/Constant'
       *  Product: '<S230>/Product1'
       *  Product: '<S230>/Product2'
       *  Sqrt: '<S229>/Sqrt'
       *  Sum: '<S230>/Add'
       */
      rtb_Product6_n4 = sqrt(GRM_HIL_P.Constant_Value_iu[0] *
        GRM_HIL_P.Constant_Value_iu[0] + GRM_HIL_P.Constant_Value_iu[1] *
        GRM_HIL_P.Constant_Value_iu[1]);

      /* Product: '<S230>/Product' incorporates:
       *  Constant: '<S228>/c_flat'
       *  Constant: '<S228>/c_rsma'
       *  Constant: '<S230>/Constant'
       *  Sum: '<S230>/Subtract'
       */
      rtb_Cx = (GRM_HIL_P.Constant_Value_g - GRM_HIL_P.c_flat_Value) *
        GRM_HIL_P.c_rsma_Value;

      /* Trigonometry: '<S230>/Trigonometric Function' incorporates:
       *  Constant: '<S227>/Constant'
       *  Constant: '<S228>/c_rsma'
       *  Product: '<S230>/Divide1'
       *  Product: '<S230>/Product6'
       *  Product: '<S230>/Product7'
       *  Sqrt: '<S230>/Sqrt'
       */
      rtb_Product7_ma = atan(GRM_HIL_P.Constant_Value_iu[2] *
        GRM_HIL_P.c_rsma_Value / (rtb_Product6_n4 * rtb_Cx));

      /* Trigonometry: '<S230>/Trigonometric Function3' */
      rtb_Gain1_c = cos(rtb_Product7_ma);

      /* Product: '<S230>/Product9' */
      rtb_Subtract_e = rtb_Gain1_c * rtb_Gain1_c * rtb_Gain1_c;

      /* Trigonometry: '<S230>/Trigonometric Function2' */
      rtb_Product7_ma = sin(rtb_Product7_ma);

      /* Product: '<S230>/Product5' */
      rtb_Gain1_c = rtb_Cx * rtb_Cx;

      /* Product: '<S230>/Product10' incorporates:
       *  Constant: '<S228>/c_rsma'
       *  Product: '<S230>/Divide'
       *  Product: '<S230>/Product4'
       *  Product: '<S230>/Product8'
       *  Sum: '<S230>/Subtract2'
       */
      rtb_Cx = (GRM_HIL_P.c_rsma_Value * GRM_HIL_P.c_rsma_Value - rtb_Gain1_c) /
        rtb_Gain1_c * rtb_Cx * (rtb_Product7_ma * rtb_Product7_ma *
        rtb_Product7_ma);

      /* Sum: '<S230>/Add1' incorporates:
       *  Constant: '<S227>/Constant'
       */
      rtb_Cx += GRM_HIL_P.Constant_Value_iu[2];

      /* Product: '<S230>/Product3' incorporates:
       *  Constant: '<S228>/c_flat'
       *  Product: '<S229>/Product3'
       */
      rtb_Divide_jq_tmp = GRM_HIL_P.c_flat_Value * GRM_HIL_P.c_flat_Value;

      /* Trigonometry: '<S230>/Trigonometric Function1' incorporates:
       *  Constant: '<S228>/c_flat'
       *  Constant: '<S228>/c_rsma'
       *  Gain: '<S230>/Gain'
       *  Product: '<S230>/Divide2'
       *  Product: '<S230>/Product11'
       *  Product: '<S230>/Product3'
       *  Sqrt: '<S230>/Sqrt'
       *  Sum: '<S230>/Subtract1'
       *  Sum: '<S230>/Subtract3'
       */
      rtb_Gain1_c = atan(rtb_Cx / (rtb_Product6_n4 - (GRM_HIL_P.Gain_Gain_c *
        GRM_HIL_P.c_flat_Value - rtb_Divide_jq_tmp) * GRM_HIL_P.c_rsma_Value *
        rtb_Subtract_e));

      /* Trigonometry: '<S229>/Trigonometric Function' */
      rtb_Product7_ma = sin(rtb_Gain1_c);
      GRM_HIL_B.hBE_0 = rtb_Product6_n4 / cos(rtb_Gain1_c) -
        GRM_HIL_P.c_rsma_Value / sqrt(GRM_HIL_P.Constant_Value_j -
        (GRM_HIL_P.Gain_Gain * GRM_HIL_P.c_flat_Value - rtb_Divide_jq_tmp) *
        (rtb_Product7_ma * rtb_Product7_ma));
    }

    /* End of Switch: '<S227>/Switch1' */

    /* SignalConversion generated from: '<S225>/Vector Concatenate' incorporates:
     *  Constant: '<S225>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[0] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S225>/Vector Concatenate' incorporates:
     *  Constant: '<S225>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[1] = GRM_HIL_P.Constant3_Value_f4;

    /* SignalConversion generated from: '<S225>/Vector Concatenate' incorporates:
     *  Constant: '<S225>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate[2] = GRM_HIL_P.Constant3_Value_f4;
  }

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/Constant1'
   *  Sum: '<S225>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_lx) - GRM_HIL_B.hBE_0 >
      GRM_HIL_P.Switch_Threshold_f) {
    rtb_Product1_m[0] = rtb_vBEB_a[0];
    rtb_Product1_m[1] = rtb_vBEB_a[1];
    rtb_Product1_m[2] = rtb_vBEB_a[2];
  } else {
    rtb_Product1_m[0] = GRM_HIL_B.VectorConcatenate[0];
    rtb_Product1_m[1] = GRM_HIL_B.VectorConcatenate[1];
    rtb_Product1_m[2] = GRM_HIL_B.VectorConcatenate[2];
  }

  /* End of Switch: '<S225>/Switch' */

  /* Saturate: '<S199>/Saturation' */
  if (GRM_HIL_B.Switch[2] > GRM_HIL_P.Saturation_UpperSat_d) {
    rtb_Product6_n4 = GRM_HIL_P.Saturation_UpperSat_d;
  } else if (GRM_HIL_B.Switch[2] < GRM_HIL_P.Saturation_LowerSat_j) {
    rtb_Product6_n4 = GRM_HIL_P.Saturation_LowerSat_j;
  } else {
    rtb_Product6_n4 = GRM_HIL_B.Switch[2];
  }

  /* End of Saturate: '<S199>/Saturation' */

  /* Trigonometry: '<S263>/Trigonometric Function' incorporates:
   *  Switch: '<S305>/Switch'
   *  Trigonometry: '<S261>/Trigonometric Function2'
   *  Trigonometry: '<S305>/Trigonometric Function'
   */
  rtb_Cx = sin(GRM_HIL_B.Switch[1]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S264>/Divide' incorporates:
     *  Constant: '<S263>/WGS84 Semi-major Axis, [m]'
     *  Constant: '<S263>/WGS84 Semi-minor Axis, [m]'
     *  Sum: '<S264>/Add'
     */
    rtb_Gain1_l = (GRM_HIL_P.WGS84SemimajorAxism_Value -
                   GRM_HIL_P.WGS84SemiminorAxism_Value) /
      GRM_HIL_P.WGS84SemimajorAxism_Value;

    /* Product: '<S264>/Divide1' incorporates:
     *  Constant: '<S264>/a2'
     *  Sum: '<S264>/Add1'
     */
    rtb_Gain1_l *= GRM_HIL_P.a2_Value - rtb_Gain1_l;

    /* Sqrt: '<S264>/Sqrt' */
    rtb_Gain1_l = sqrt(rtb_Gain1_l);

    /* Product: '<S263>/Divide' */
    GRM_HIL_B.e2 = rtb_Gain1_l * rtb_Gain1_l;

    /* Sum: '<S261>/Add1' incorporates:
     *  Constant: '<S261>/Constant'
     *  Product: '<S261>/Divide2'
     */
    GRM_HIL_B.Add1 = GRM_HIL_P.Constant_Value_ov - rtb_Gain1_l * rtb_Gain1_l;
  }

  /* Product: '<S263>/Divide3' incorporates:
   *  Constant: '<S263>/WGS84 Semi-major Axis, [m]'
   *  Constant: '<S263>/a3'
   *  Product: '<S263>/Divide1'
   *  Product: '<S263>/Divide2'
   *  Sqrt: '<S263>/Sqrt'
   *  Sum: '<S263>/Add2'
   *  Trigonometry: '<S263>/Trigonometric Function'
   */
  rtb_Product7_ma = 1.0 / sqrt(GRM_HIL_P.a3_Value - rtb_Cx * rtb_Cx *
    GRM_HIL_B.e2) * GRM_HIL_P.WGS84SemimajorAxism_Value;

  /* Sum: '<S261>/Add3' */
  rtb_Subtract_e = rtb_Product6_n4 + rtb_Product7_ma;

  /* Trigonometry: '<S261>/Trigonometric Function3' incorporates:
   *  Switch: '<S305>/Switch'
   *  Trigonometry: '<S305>/Trigonometric Function1'
   */
  rtb_Product4_e = cos(GRM_HIL_B.Switch[1]);
  rtb_Abs_iw = rtb_Product4_e;

  /* Trigonometry: '<S261>/Trigonometric Function1' incorporates:
   *  MATLAB Function: '<S255>/WGS84_Gravity_Implementation'
   */
  rtb_pBEE_tmp = cos(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S262>/ SFunction ' incorporates:
   *  MATLAB Function: '<S255>/WGS84_Gravity_Implementation'
   *  Product: '<S261>/Divide'
   *  Trigonometry: '<S261>/Trigonometric Function1'
   */
  rtb_pBEE[0] = rtb_Subtract_e * rtb_pBEE_tmp * rtb_Abs_iw;

  /* Trigonometry: '<S261>/Trigonometric Function' incorporates:
   *  MATLAB Function: '<S255>/WGS84_Gravity_Implementation'
   */
  rtb_pBEE_tmp_0 = sin(GRM_HIL_B.Switch[0]);

  /* SignalConversion generated from: '<S262>/ SFunction ' incorporates:
   *  MATLAB Function: '<S255>/WGS84_Gravity_Implementation'
   *  Product: '<S261>/Divide1'
   *  Product: '<S261>/Divide3'
   *  Product: '<S261>/Divide4'
   *  Sum: '<S261>/Add2'
   *  Trigonometry: '<S261>/Trigonometric Function'
   */
  rtb_pBEE[1] = rtb_Subtract_e * rtb_pBEE_tmp_0 * rtb_Abs_iw;
  rtb_pBEE[2] = (rtb_Product7_ma * GRM_HIL_B.Add1 + rtb_Product6_n4) * rtb_Cx;

  /* MATLAB Function: '<S255>/WGS84_Gravity_Implementation' */
  rtb_Product1 = GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS;
  rtb_Product5 = GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rsma;
  rtb_Product7_ma = sqrt(rtb_Product5 - rtb_Product1);
  rtb_Divide_jq_tmp = rtb_Product7_ma * rtb_Product7_ma;
  rtb_Gain1_n4_tmp = rtb_pBEE[2] * rtb_pBEE[2];
  rtb_Divide1_h = rtb_pBEE[0] * rtb_pBEE[0] + rtb_pBEE[1] * rtb_pBEE[1];
  rtb_Subtract_e = (rtb_Divide1_h + rtb_Gain1_n4_tmp) - rtb_Divide_jq_tmp;
  rtb_Gain1_c = sqrt((sqrt(rtb_Divide_jq_tmp * 4.0 * rtb_Gain1_n4_tmp /
    (rtb_Subtract_e * rtb_Subtract_e) + 1.0) + 1.0) * (rtb_Subtract_e * 0.5));
  rtb_Subtract_a_tmp = rtb_Gain1_c * rtb_Gain1_c;
  rtb_Subtract_a_tmp_0 = rtb_Subtract_a_tmp + rtb_Divide_jq_tmp;
  rtb_Subtract_e = sqrt(rtb_Subtract_a_tmp_0);
  rtb_Divide_h = rt_atan2d_snf(rtb_pBEE[2] * rtb_Subtract_e, sqrt(rtb_Divide1_h)
    * rtb_Gain1_c);
  rtb_Divide1_h = sin(rtb_Divide_h);
  rtb_Product_c_tmp = rtb_Divide1_h * rtb_Divide1_h;
  rtb_Product_l = sqrt((rtb_Divide_jq_tmp * rtb_Product_c_tmp +
                        rtb_Subtract_a_tmp) / rtb_Subtract_a_tmp_0);
  rtb_Product1 = ((rtb_Product1 * 3.0 / rtb_Divide_jq_tmp + 1.0) * rt_atan2d_snf
                  (rtb_Product7_ma,
                   GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS) - 3.0 *
                  GRM_HIL_P.WGS84_Gravity_Implementation_c_b_WGS /
                  rtb_Product7_ma) * 0.5;
  rtb_Product3_hu = cos(rtb_Divide_h);
  rtb_gamma_R_tmp = rt_atan2d_snf(rtb_Product7_ma, rtb_Gain1_c);
  rtb_TBG[0] = rtb_Gain1_c / (rtb_Product_l * rtb_Subtract_e) * rtb_Product3_hu *
    rtb_pBEE_tmp;
  rtb_TBG[3] = -1.0 / rtb_Product_l * rtb_Divide1_h * rtb_pBEE_tmp;
  rtb_TBG[6] = -rtb_pBEE_tmp_0;
  rtb_Gain1_n4_tmp = rtb_Gain1_c / (sqrt(rtb_Gain1_c * rtb_Gain1_c +
    rtb_Product7_ma * rtb_Product7_ma) * rtb_Product_l) * cos(rtb_Divide_h);
  rtb_TBG[1] = rtb_Gain1_n4_tmp * rtb_pBEE_tmp_0;
  rtb_TBG[4] = -1.0 / rtb_Product_l * sin(rtb_Divide_h) * rtb_pBEE_tmp_0;
  rtb_TBG[7] = rtb_pBEE_tmp;
  rtb_TBG[2] = 1.0 / rtb_Product_l * rtb_Divide1_h;
  rtb_TBG[5] = rtb_Gain1_n4_tmp;
  rtb_TBG[8] = 0.0;
  rtb_Divide_h = GRM_HIL_P.WGS84_Gravity_Implementation_c_rot *
    GRM_HIL_P.WGS84_Gravity_Implementation_c_rot;
  rtb_pBEE_tmp = GRM_HIL_P.WGS84_Gravitation_flg_omega_enabled / rtb_Product_l *
    rtb_Divide_h;
  rtb_pBEE_tmp_0 = (((rtb_Subtract_a_tmp / rtb_Divide_jq_tmp + 1.0) * 3.0 * (1.0
    - rtb_Gain1_c / rtb_Product7_ma * rtb_gamma_R_tmp) - 1.0) * (rtb_Divide_h *
    rtb_Product5 * rtb_Product7_ma / rtb_Subtract_a_tmp_0) / rtb_Product1 *
                    (rtb_Product_c_tmp * 0.5 - 0.16666666666666666) +
                    GRM_HIL_P.WGS84_Gravity_Implementation_c_grav /
                    rtb_Subtract_a_tmp_0) * (-1.0 / rtb_Product_l) +
    rtb_pBEE_tmp * rtb_Gain1_c * (rtb_Product3_hu * rtb_Product3_hu);
  rtb_Product7_ma = ((rtb_Subtract_a_tmp * 3.0 / rtb_Divide_jq_tmp + 1.0) *
                     rtb_gamma_R_tmp - 3.0 * rtb_Gain1_c / rtb_Product7_ma) *
    0.5 * (1.0 / rtb_Product_l * rtb_Divide_h * rtb_Product5 /
           rtb_Subtract_a_tmp_0) / rtb_Product1 * rtb_Divide1_h *
    rtb_Product3_hu - rtb_pBEE_tmp * rtb_Subtract_e * rtb_Divide1_h *
    rtb_Product3_hu;
  for (i = 0; i < 3; i++) {
    rtb_pBEE[i] = rtb_TBG[i + 6] * 0.0 + (rtb_TBG[i + 3] * rtb_Product7_ma +
      rtb_TBG[i] * rtb_pBEE_tmp_0);
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S285>/Switch1' incorporates:
     *  Constant: '<S285>/Constant'
     *  Constant: '<S285>/Constant2'
     *  Constant: '<S286>/c_flat'
     *  Constant: '<S286>/c_rsma'
     *  Constant: '<S287>/Constant'
     *  Gain: '<S285>/Gain'
     *  Gain: '<S287>/Gain'
     *  Product: '<S287>/Product'
     *  Product: '<S287>/Product4'
     *  Product: '<S287>/Product5'
     *  Sqrt: '<S287>/Sqrt1'
     *  Sum: '<S287>/Subtract'
     *  Sum: '<S287>/Subtract1'
     *  Sum: '<S287>/Sum'
     *  Trigonometry: '<S287>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_id > GRM_HIL_P.Switch1_Threshold_d) {
      GRM_HIL_B.hBE_0_l = GRM_HIL_P.Gain_Gain_g * GRM_HIL_P.Constant_Value_g4[2];
    } else {
      /* Sqrt: '<S288>/Sqrt' incorporates:
       *  Constant: '<S285>/Constant'
       *  Product: '<S288>/Product1'
       *  Product: '<S288>/Product2'
       *  Sqrt: '<S287>/Sqrt'
       *  Sum: '<S288>/Add'
       */
      rtb_Product7_ma = sqrt(GRM_HIL_P.Constant_Value_g4[0] *
        GRM_HIL_P.Constant_Value_g4[0] + GRM_HIL_P.Constant_Value_g4[1] *
        GRM_HIL_P.Constant_Value_g4[1]);

      /* Product: '<S288>/Product' incorporates:
       *  Constant: '<S286>/c_flat'
       *  Constant: '<S286>/c_rsma'
       *  Constant: '<S288>/Constant'
       *  Sum: '<S288>/Subtract'
       */
      rtb_Gain1_c = (GRM_HIL_P.Constant_Value_e - GRM_HIL_P.c_flat_Value_c) *
        GRM_HIL_P.c_rsma_Value_m;

      /* Trigonometry: '<S288>/Trigonometric Function' incorporates:
       *  Constant: '<S285>/Constant'
       *  Constant: '<S286>/c_rsma'
       *  Product: '<S288>/Divide1'
       *  Product: '<S288>/Product6'
       *  Product: '<S288>/Product7'
       *  Sqrt: '<S288>/Sqrt'
       */
      rtb_Subtract_e = atan(GRM_HIL_P.Constant_Value_g4[2] *
                            GRM_HIL_P.c_rsma_Value_m / (rtb_Product7_ma *
        rtb_Gain1_c));

      /* Trigonometry: '<S288>/Trigonometric Function3' */
      rtb_Divide_h = cos(rtb_Subtract_e);

      /* Product: '<S288>/Product9' */
      rtb_Divide1_h = rtb_Divide_h * rtb_Divide_h * rtb_Divide_h;

      /* Trigonometry: '<S288>/Trigonometric Function2' */
      rtb_Subtract_e = sin(rtb_Subtract_e);

      /* Product: '<S288>/Product5' */
      rtb_Divide_h = rtb_Gain1_c * rtb_Gain1_c;

      /* Product: '<S288>/Product10' incorporates:
       *  Constant: '<S286>/c_rsma'
       *  Product: '<S288>/Divide'
       *  Product: '<S288>/Product4'
       *  Product: '<S288>/Product8'
       *  Sum: '<S288>/Subtract2'
       */
      rtb_Gain1_c = (GRM_HIL_P.c_rsma_Value_m * GRM_HIL_P.c_rsma_Value_m -
                     rtb_Divide_h) / rtb_Divide_h * rtb_Gain1_c *
        (rtb_Subtract_e * rtb_Subtract_e * rtb_Subtract_e);

      /* Sum: '<S288>/Add1' incorporates:
       *  Constant: '<S285>/Constant'
       */
      rtb_Gain1_c += GRM_HIL_P.Constant_Value_g4[2];

      /* Product: '<S288>/Product3' incorporates:
       *  Constant: '<S286>/c_flat'
       *  Product: '<S287>/Product3'
       */
      rtb_Divide_jq_tmp = GRM_HIL_P.c_flat_Value_c * GRM_HIL_P.c_flat_Value_c;

      /* Trigonometry: '<S288>/Trigonometric Function1' incorporates:
       *  Constant: '<S286>/c_flat'
       *  Constant: '<S286>/c_rsma'
       *  Gain: '<S288>/Gain'
       *  Product: '<S288>/Divide2'
       *  Product: '<S288>/Product11'
       *  Product: '<S288>/Product3'
       *  Sqrt: '<S288>/Sqrt'
       *  Sum: '<S288>/Subtract1'
       *  Sum: '<S288>/Subtract3'
       */
      rtb_Divide_h = atan(rtb_Gain1_c / (rtb_Product7_ma -
        (GRM_HIL_P.Gain_Gain_j * GRM_HIL_P.c_flat_Value_c - rtb_Divide_jq_tmp) *
        GRM_HIL_P.c_rsma_Value_m * rtb_Divide1_h));

      /* Trigonometry: '<S287>/Trigonometric Function' */
      rtb_Subtract_e = sin(rtb_Divide_h);
      GRM_HIL_B.hBE_0_l = rtb_Product7_ma / cos(rtb_Divide_h) -
        GRM_HIL_P.c_rsma_Value_m / sqrt(GRM_HIL_P.Constant_Value_o -
        (GRM_HIL_P.Gain_Gain_l * GRM_HIL_P.c_flat_Value_c - rtb_Divide_jq_tmp) *
        (rtb_Subtract_e * rtb_Subtract_e));
    }

    /* End of Switch: '<S285>/Switch1' */

    /* SignalConversion generated from: '<S284>/Vector Concatenate' incorporates:
     *  Constant: '<S284>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[0] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S284>/Vector Concatenate' incorporates:
     *  Constant: '<S284>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[1] = GRM_HIL_P.Constant3_Value_j;

    /* SignalConversion generated from: '<S284>/Vector Concatenate' incorporates:
     *  Constant: '<S284>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_f[2] = GRM_HIL_P.Constant3_Value_j;
  }

  /* Switch: '<S284>/Switch' incorporates:
   *  Constant: '<S284>/Constant1'
   *  Sum: '<S284>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_mm) - GRM_HIL_B.hBE_0_l >
      GRM_HIL_P.Switch_Threshold_gn) {
    /* Sqrt: '<S257>/Sqrt' incorporates:
     *  DotProduct: '<S257>/Dot Product'
     */
    rtb_VectorConcatenate_a[2] = sqrt((rtb_pBEE[0] * rtb_pBEE[0] + rtb_pBEE[1] *
      rtb_pBEE[1]) + rtb_pBEE[2] * rtb_pBEE[2]);

    /* SignalConversion generated from: '<S257>/Vector Concatenate' incorporates:
     *  Constant: '<S257>/Constant1'
     */
    rtb_VectorConcatenate_a[1] = GRM_HIL_P.Constant1_Value_cj;

    /* SignalConversion generated from: '<S257>/Vector Concatenate' incorporates:
     *  Constant: '<S257>/Constant1'
     */
    rtb_VectorConcatenate_a[0] = GRM_HIL_P.Constant1_Value_cj;
  } else {
    rtb_VectorConcatenate_a[0] = GRM_HIL_B.VectorConcatenate_f[0];
    rtb_VectorConcatenate_a[1] = GRM_HIL_B.VectorConcatenate_f[1];
    rtb_VectorConcatenate_a[2] = GRM_HIL_B.VectorConcatenate_f[2];
  }

  /* End of Switch: '<S284>/Switch' */

  /* Sum: '<S210>/Subtract' */
  rtb_Product7_ma = u0;

  /* Switch: '<S362>/Switch' incorporates:
   *  Constant: '<S362>/Constant'
   */
  if (!(u0 > GRM_HIL_P.Switch_Threshold_fo)) {
    rtb_Product7_ma = GRM_HIL_P.Constant_Value_k;
  }

  /* End of Switch: '<S362>/Switch' */

  /* Switch: '<S362>/Switch1' incorporates:
   *  Lookup_n-D: '<S362>/1-D Lookup Table'
   */
  if (rtb_Product7_ma > GRM_HIL_P.Switch1_Threshold_f) {
    /* Saturate: '<S362>/Saturation' */
    if (rtb_Product7_ma > GRM_HIL_P.Saturation_UpperSat_c) {
      rtb_Product7_ma = GRM_HIL_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Product7_ma < GRM_HIL_P.Saturation_LowerSat_h) {
        rtb_Product7_ma = GRM_HIL_P.Saturation_LowerSat_h;
      }
    }

    /* End of Saturate: '<S362>/Saturation' */
    rtb_Product7_ma = look1_binlcapw(rtb_Product7_ma,
      GRM_HIL_P.uDLookupTable_bp01Data, GRM_HIL_P.uDLookupTable_tableData, 16U);
  }

  /* End of Switch: '<S362>/Switch1' */

  /* Sum: '<S363>/Add' incorporates:
   *  Constant: '<S362>/Constant1'
   *  Constant: '<S362>/Constant2'
   *  Constant: '<S363>/Constant'
   *  Constant: '<S363>/Constant1'
   *  Product: '<S363>/Product'
   *  Sum: '<S362>/Subtract1'
   */
  rtb_Subtract_e = ((GRM_HIL_P.Constant1_Value_iw - rtb_Product7_ma) +
                    GRM_HIL_P.Constant2_Value_p) * GRM_HIL_P.Constant1_Value_mo
    + GRM_HIL_P.Constant_Value_bs;

  /* Product: '<S202>/Product' */
  rtb_VectorConcatenate_a[0] *= rtb_Subtract_e;
  rtb_VectorConcatenate_a[1] *= rtb_Subtract_e;
  rtb_Gain1_c = rtb_VectorConcatenate_a[2] * rtb_Subtract_e;

  /* Product: '<S201>/Product' incorporates:
   *  Math: '<S201>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac[i] = rtb_vBEB_a_tmp[i + 6] * rtb_Gain1_c + (rtb_vBEB_a_tmp[i + 3] *
      rtb_VectorConcatenate_a[1] + rtb_vBEB_a_tmp[i] * rtb_VectorConcatenate_a[0]);
  }

  /* End of Product: '<S201>/Product' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S316>/Multiport Switch2' incorporates:
     *  Constant: '<S316>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3) {
     case 1:
      /* Trigonometry: '<S324>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/thrust_rot_x'
       *  Trigonometry: '<S324>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S324>/Trigonometric Function3' incorporates:
       *  Constant: '<S315>/thrust_rot_x'
       *  Trigonometry: '<S324>/Trigonometric Function'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S324>/Matrix Concatenate' incorporates:
       *  Constant: '<S324>/Constant7'
       *  Trigonometry: '<S324>/Trigonometric Function1'
       *  Trigonometry: '<S324>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_k;
      rtb_MultiportSwitch[7] = rtb_Gain1_c;
      rtb_MultiportSwitch[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S324>/Matrix Concatenate' incorporates:
       *  Constant: '<S324>/Constant8'
       *  Gain: '<S324>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_a;
      rtb_MultiportSwitch[4] = rtb_Divide_h;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_h * rtb_Gain1_c;

      /* SignalConversion generated from: '<S324>/Matrix Concatenate' incorporates:
       *  Constant: '<S324>/Constant'
       *  Constant: '<S324>/Constant1'
       *  Constant: '<S324>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_d;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_j;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_j;
      break;

     case 2:
      /* Trigonometry: '<S325>/Trigonometric Function3' incorporates:
       *  Constant: '<S315>/thrust_rot_x'
       *  Trigonometry: '<S325>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S325>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/thrust_rot_x'
       *  Trigonometry: '<S325>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S325>/Matrix Concatenate' incorporates:
       *  Constant: '<S325>/Constant7'
       *  Gain: '<S325>/Gain1'
       *  Trigonometry: '<S325>/Trigonometric Function1'
       *  Trigonometry: '<S325>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_d * rtb_Divide_h;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_a;
      rtb_MultiportSwitch[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S325>/Matrix Concatenate' incorporates:
       *  Constant: '<S325>/Constant'
       *  Constant: '<S325>/Constant1'
       *  Constant: '<S325>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_ek;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value;

      /* SignalConversion generated from: '<S325>/Matrix Concatenate' incorporates:
       *  Constant: '<S325>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_Gain1_c;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_k;
      rtb_MultiportSwitch[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S326>/Matrix Concatenate' incorporates:
       *  Constant: '<S326>/Constant10'
       *  Constant: '<S326>/Constant11'
       *  Constant: '<S326>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_o;

      /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/thrust_rot_x'
       *  Trigonometry: '<S326>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value);

      /* Trigonometry: '<S326>/Trigonometric Function' incorporates:
       *  Constant: '<S315>/thrust_rot_x'
       *  Trigonometry: '<S326>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_x_Value);

      /* SignalConversion generated from: '<S326>/Matrix Concatenate' incorporates:
       *  Constant: '<S326>/Constant7'
       *  Trigonometry: '<S326>/Trigonometric Function'
       *  Trigonometry: '<S326>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_Gain1_c;
      rtb_MultiportSwitch[4] = rtb_Divide_h;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_is;

      /* SignalConversion generated from: '<S326>/Matrix Concatenate' incorporates:
       *  Constant: '<S326>/Constant8'
       *  Gain: '<S326>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Divide_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_e * rtb_Gain1_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_d;
      break;
    }

    /* End of MultiPortSwitch: '<S316>/Multiport Switch2' */

    /* MultiPortSwitch: '<S316>/Multiport Switch1' incorporates:
     *  Constant: '<S316>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2) {
     case 1:
      /* Trigonometry: '<S321>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/thrust_rot_y'
       *  Trigonometry: '<S321>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S321>/Trigonometric Function3' incorporates:
       *  Constant: '<S315>/thrust_rot_y'
       *  Trigonometry: '<S321>/Trigonometric Function'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S321>/Matrix Concatenate' incorporates:
       *  Constant: '<S321>/Constant7'
       *  Trigonometry: '<S321>/Trigonometric Function1'
       *  Trigonometry: '<S321>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_f;
      rtb_MultiportSwitch1[7] = rtb_Gain1_c;
      rtb_MultiportSwitch1[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S321>/Matrix Concatenate' incorporates:
       *  Constant: '<S321>/Constant8'
       *  Gain: '<S321>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_e;
      rtb_MultiportSwitch1[4] = rtb_Divide_h;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_jq * rtb_Gain1_c;

      /* SignalConversion generated from: '<S321>/Matrix Concatenate' incorporates:
       *  Constant: '<S321>/Constant'
       *  Constant: '<S321>/Constant1'
       *  Constant: '<S321>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_a;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_n;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_e;
      break;

     case 2:
      /* Trigonometry: '<S322>/Trigonometric Function3' incorporates:
       *  Constant: '<S315>/thrust_rot_y'
       *  Trigonometry: '<S322>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S322>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/thrust_rot_y'
       *  Trigonometry: '<S322>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S322>/Matrix Concatenate' incorporates:
       *  Constant: '<S322>/Constant7'
       *  Gain: '<S322>/Gain1'
       *  Trigonometry: '<S322>/Trigonometric Function1'
       *  Trigonometry: '<S322>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_h * rtb_Divide_h;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_ib;
      rtb_MultiportSwitch1[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S322>/Matrix Concatenate' incorporates:
       *  Constant: '<S322>/Constant'
       *  Constant: '<S322>/Constant1'
       *  Constant: '<S322>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_dk;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_l;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_m;

      /* SignalConversion generated from: '<S322>/Matrix Concatenate' incorporates:
       *  Constant: '<S322>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_Gain1_c;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_b;
      rtb_MultiportSwitch1[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S323>/Matrix Concatenate' incorporates:
       *  Constant: '<S323>/Constant10'
       *  Constant: '<S323>/Constant11'
       *  Constant: '<S323>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_h;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_f;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_p;

      /* Trigonometry: '<S323>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/thrust_rot_y'
       *  Trigonometry: '<S323>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value);

      /* Trigonometry: '<S323>/Trigonometric Function' incorporates:
       *  Constant: '<S315>/thrust_rot_y'
       *  Trigonometry: '<S323>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_y_Value);

      /* SignalConversion generated from: '<S323>/Matrix Concatenate' incorporates:
       *  Constant: '<S323>/Constant7'
       *  Trigonometry: '<S323>/Trigonometric Function'
       *  Trigonometry: '<S323>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_Gain1_c;
      rtb_MultiportSwitch1[4] = rtb_Divide_h;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_d;

      /* SignalConversion generated from: '<S323>/Matrix Concatenate' incorporates:
       *  Constant: '<S323>/Constant8'
       *  Gain: '<S323>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Divide_h;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_hf * rtb_Gain1_c;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_o;
      break;
    }

    /* End of MultiPortSwitch: '<S316>/Multiport Switch1' */

    /* MultiPortSwitch: '<S316>/Multiport Switch' incorporates:
     *  Constant: '<S316>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_m) {
     case 1:
      /* Trigonometry: '<S318>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/Thrust_rot_z'
       *  Trigonometry: '<S318>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S318>/Trigonometric Function3' incorporates:
       *  Constant: '<S315>/Thrust_rot_z'
       *  Trigonometry: '<S318>/Trigonometric Function'
       */
      rtb_Divide_h = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S318>/Matrix Concatenate' incorporates:
       *  Constant: '<S318>/Constant7'
       *  Trigonometry: '<S318>/Trigonometric Function1'
       *  Trigonometry: '<S318>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_b;
      rtb_MultiportSwitch2[7] = rtb_Gain1_c;
      rtb_MultiportSwitch2[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S318>/Matrix Concatenate' incorporates:
       *  Constant: '<S318>/Constant8'
       *  Gain: '<S318>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_ks;
      rtb_MultiportSwitch2[4] = rtb_Divide_h;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_lj * rtb_Gain1_c;

      /* SignalConversion generated from: '<S318>/Matrix Concatenate' incorporates:
       *  Constant: '<S318>/Constant'
       *  Constant: '<S318>/Constant1'
       *  Constant: '<S318>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_l;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_o;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_f;
      break;

     case 2:
      /* Trigonometry: '<S319>/Trigonometric Function3' incorporates:
       *  Constant: '<S315>/Thrust_rot_z'
       *  Trigonometry: '<S319>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S319>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/Thrust_rot_z'
       *  Trigonometry: '<S319>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S319>/Matrix Concatenate' incorporates:
       *  Constant: '<S319>/Constant7'
       *  Gain: '<S319>/Gain1'
       *  Trigonometry: '<S319>/Trigonometric Function1'
       *  Trigonometry: '<S319>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_hx * rtb_Divide_h;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_f2;
      rtb_MultiportSwitch2[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S319>/Matrix Concatenate' incorporates:
       *  Constant: '<S319>/Constant'
       *  Constant: '<S319>/Constant1'
       *  Constant: '<S319>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_n;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_b;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_d;

      /* SignalConversion generated from: '<S319>/Matrix Concatenate' incorporates:
       *  Constant: '<S319>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_Gain1_c;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_g;
      rtb_MultiportSwitch2[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S320>/Matrix Concatenate' incorporates:
       *  Constant: '<S320>/Constant10'
       *  Constant: '<S320>/Constant11'
       *  Constant: '<S320>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_l;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_l;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_l;

      /* Trigonometry: '<S320>/Trigonometric Function1' incorporates:
       *  Constant: '<S315>/Thrust_rot_z'
       *  Trigonometry: '<S320>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value);

      /* Trigonometry: '<S320>/Trigonometric Function' incorporates:
       *  Constant: '<S315>/Thrust_rot_z'
       *  Trigonometry: '<S320>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(GRM_HIL_P.Thrust_rot_z_Value);

      /* SignalConversion generated from: '<S320>/Matrix Concatenate' incorporates:
       *  Constant: '<S320>/Constant7'
       *  Trigonometry: '<S320>/Trigonometric Function'
       *  Trigonometry: '<S320>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_Gain1_c;
      rtb_MultiportSwitch2[4] = rtb_Divide_h;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_c;

      /* SignalConversion generated from: '<S320>/Matrix Concatenate' incorporates:
       *  Constant: '<S320>/Constant8'
       *  Gain: '<S320>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Divide_h;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_k * rtb_Gain1_c;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_f;
      break;
    }

    /* End of MultiPortSwitch: '<S316>/Multiport Switch' */

    /* Product: '<S316>/3. Rotation' */
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

    /* End of Product: '<S316>/3. Rotation' */
  }

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S314>/Constant'
   */
  if (u0 > GRM_HIL_P.Switch_Threshold_n) {
    rtb_Gain1_c = u0;
  } else {
    rtb_Gain1_c = GRM_HIL_P.Constant_Value_a0;
  }

  /* End of Switch: '<S314>/Switch' */

  /* Switch: '<S314>/Switch1' incorporates:
   *  Lookup_n-D: '<S314>/thrust_lookup'
   */
  if (rtb_Gain1_c > GRM_HIL_P.Switch1_Threshold_a) {
    /* Saturate: '<S314>/Saturation' */
    if (rtb_Gain1_c > GRM_HIL_P.Saturation_UpperSat) {
      rtb_Gain1_c = GRM_HIL_P.Saturation_UpperSat;
    } else {
      if (rtb_Gain1_c < GRM_HIL_P.Saturation_LowerSat) {
        rtb_Gain1_c = GRM_HIL_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S314>/Saturation' */
    rtb_VectorConcatenate_a[0] = look1_binlcapw(rtb_Gain1_c,
      GRM_HIL_P.thrust_lookup_bp01Data, GRM_HIL_P.thrust_lookup_tableData, 11U);
  } else {
    rtb_VectorConcatenate_a[0] = rtb_Gain1_c;
  }

  /* End of Switch: '<S314>/Switch1' */

  /* Product: '<S315>/Product1' incorporates:
   *  Constant: '<S314>/Constant1'
   *  Constant: '<S315>/uncert_thrust'
   */
  rtb_VectorConcatenate_a[0] *= GRM_HIL_P.uncert_thrust_Value;
  rtb_Gain1_c = GRM_HIL_P.Constant1_Value_h * GRM_HIL_P.uncert_thrust_Value;

  /* Product: '<S315>/Product' incorporates:
   *  Product: '<S315>/Product1'
   */
  for (i = 0; i < 3; i++) {
    rtb_pBEE[i] = GRM_HIL_B.T12[i + 6] * rtb_Gain1_c + (GRM_HIL_B.T12[i + 3] *
      rtb_Gain1_c + GRM_HIL_B.T12[i] * rtb_VectorConcatenate_a[0]);
  }

  /* End of Product: '<S315>/Product' */

  /* Step: '<Root>/Step' incorporates:
   *  Step: '<Root>/External Force'
   *  Step: '<Root>/External Moment'
   *  Step: '<Root>/Step1'
   */
  rtb_Product3_hu = GRM_HIL_M->Timing.t[0];
  if (rtb_Product3_hu < GRM_HIL_P.Step_Time) {
    rtb_Abs_iw = GRM_HIL_P.Step_Y0;
  } else {
    rtb_Abs_iw = GRM_HIL_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Step: '<Root>/External Force' */
  if (rtb_Product3_hu < GRM_HIL_P.ExternalForce_Time) {
    rtb_Gain1_c = GRM_HIL_P.ExternalForce_Y0;
  } else {
    rtb_Gain1_c = GRM_HIL_P.ExternalForce_YFinal;
  }

  /* Sum: '<S201>/Add' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  frac_0[0] = ((rtb_Product1_m[0] + frac[0]) + rtb_pBEE[0]) + (rtb_Gain1_c +
    rtb_Abs_iw) * GRM_HIL_P.Gain_Gain_pd;
  frac_0[1] = ((rtb_Product1_m[1] + frac[1]) + rtb_pBEE[1]) +
    GRM_HIL_P.Constant1_Value_fp;
  frac_0[2] = ((rtb_Product1_m[2] + frac[2]) + rtb_pBEE[2]) +
    GRM_HIL_P.Constant1_Value_fp;

  /* Switch: '<S334>/Switch' incorporates:
   *  Constant: '<S334>/Constant'
   *  Product: '<S334>/Product2'
   */
  if (GRM_HIL_P.Rigid_Body_EOM_6_DOF_flag_Kraft > GRM_HIL_P.Switch_Threshold_j)
  {
    frac[0] = frac_0[0];
    frac[1] = frac_0[1];
    frac[2] = frac_0[2];
  } else {
    /* Sum: '<S336>/Add7' */
    rtb_MathFunction2[8] = (rtb_TBG_tmp_8 - rtb_Abs_iw_tmp) + rtb_TBG_tmp_3;

    /* Sum: '<S336>/Add8' incorporates:
     *  Gain: '<S336>/Gain11'
     *  Gain: '<S336>/Gain12'
     */
    rtb_MathFunction2[7] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain11_Gain + rtb_TBG_tmp_7
      * GRM_HIL_P.Gain12_Gain;

    /* Sum: '<S336>/Add3' incorporates:
     *  Gain: '<S336>/Gain5'
     *  Gain: '<S336>/Gain6'
     */
    rtb_MathFunction2[6] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain5_Gain - rtb_TBG_tmp_5 *
      GRM_HIL_P.Gain6_Gain;

    /* Sum: '<S336>/Add2' incorporates:
     *  Gain: '<S336>/Gain3'
     *  Gain: '<S336>/Gain4'
     */
    rtb_MathFunction2[5] = rtb_TBG_tmp_6 * GRM_HIL_P.Gain3_Gain_i -
      rtb_TBG_tmp_7 * GRM_HIL_P.Gain4_Gain;

    /* Sum: '<S336>/Add6' */
    rtb_MathFunction2[4] = ((rtb_Abs_iw_tmp - rtb_TBG_tmp_1) - rtb_TBG_tmp_2) +
      rtb_TBG_tmp_3;

    /* Sum: '<S336>/Add4' incorporates:
     *  Gain: '<S336>/Gain7'
     *  Gain: '<S336>/Gain8'
     */
    rtb_MathFunction2[3] = rtb_TBG_tmp * GRM_HIL_P.Gain7_Gain + rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain8_Gain;

    /* Sum: '<S336>/Add5' incorporates:
     *  Gain: '<S336>/Gain10'
     *  Gain: '<S336>/Gain9'
     */
    rtb_MathFunction2[2] = rtb_TBG_tmp_4 * GRM_HIL_P.Gain9_Gain + rtb_TBG_tmp_5 *
      GRM_HIL_P.Gain10_Gain;

    /* Sum: '<S336>/Add1' incorporates:
     *  Gain: '<S336>/Gain1'
     *  Gain: '<S336>/Gain2'
     */
    rtb_MathFunction2[1] = rtb_TBG_tmp * GRM_HIL_P.Gain1_Gain_m - rtb_TBG_tmp_0 *
      GRM_HIL_P.Gain2_Gain_i;

    /* Sum: '<S336>/Add' incorporates:
     *  Math: '<S336>/Math Function'
     *  Math: '<S336>/Math Function1'
     *  Math: '<S336>/Math Function2'
     *  Math: '<S336>/Math Function3'
     */
    rtb_MathFunction2[0] = ((rtb_Product_idx_0 * rtb_Product_idx_0 -
      rtb_Product_idx_1 * rtb_Product_idx_1) - rtb_Product_idx_2 *
      rtb_Product_idx_2) + rtb_Product_idx_3 * rtb_Product_idx_3;

    /* Math: '<S334>/Math Function2' */
    for (i = 0; i < 3; i++) {
      rtb_TBG[3 * i] = rtb_MathFunction2[i];
      rtb_TBG[3 * i + 1] = rtb_MathFunction2[i + 3];
      rtb_TBG[3 * i + 2] = rtb_MathFunction2[i + 6];
    }

    memcpy(&rtb_MathFunction2[0], &rtb_TBG[0], 9U * sizeof(real_T));

    /* End of Math: '<S334>/Math Function2' */
    for (i = 0; i < 3; i++) {
      frac[i] = rtb_MathFunction2[i + 6] * frac_0[2] + (rtb_MathFunction2[i + 3]
        * frac_0[1] + rtb_MathFunction2[i] * frac_0[0]);
    }
  }

  /* Saturate: '<S337>/Saturation' */
  if (rtb_Subtract_e > GRM_HIL_P.Saturation_UpperSat_m) {
    rtb_Gain1_c = GRM_HIL_P.Saturation_UpperSat_m;
  } else if (rtb_Subtract_e < GRM_HIL_P.Saturation_LowerSat_a) {
    rtb_Gain1_c = GRM_HIL_P.Saturation_LowerSat_a;
  } else {
    rtb_Gain1_c = rtb_Subtract_e;
  }

  /* End of Saturate: '<S337>/Saturation' */

  /* Product: '<S337>/Divide' */
  frac[0] /= rtb_Gain1_c;
  frac[1] /= rtb_Gain1_c;

  /* SignalConversion generated from: '<S341>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[0] = frac[0];

  /* SignalConversion generated from: '<S341>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_b[1] = frac[1];

  /* SignalConversion generated from: '<S341>/Vector Concatenate' incorporates:
   *  Product: '<S337>/Divide'
   */
  GRM_HIL_B.VectorConcatenate_b[2] = frac[2] / rtb_Gain1_c;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S341>/Constant' */
    GRM_HIL_B.VectorConcatenate_b[3] = GRM_HIL_P.Constant_Value_eq;
  }

  /* Sum: '<S341>/Add' incorporates:
   *  Constant: '<S341>/Q_1'
   *  Constant: '<S341>/Q_2'
   *  Constant: '<S341>/Q_3'
   *  Constant: '<S341>/Q_4'
   *  Product: '<S341>/Product'
   *  Product: '<S341>/Product1'
   *  Product: '<S341>/Product2'
   *  Product: '<S341>/Product3'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_i[i] * rtb_Product_idx_0 +
               GRM_HIL_P.Q_2_Value_n[i] * rtb_Product_idx_1) +
              GRM_HIL_P.Q_3_Value_m[i] * rtb_Product_idx_2) +
      GRM_HIL_P.Q_4_Value_f[i] * rtb_Product_idx_3;
  }

  /* End of Sum: '<S341>/Add' */

  /* Product: '<S341>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Gain1_c = tmp[i + 12] * GRM_HIL_B.VectorConcatenate_b[3] + (tmp[i + 8] *
      GRM_HIL_B.VectorConcatenate_b[2] + (tmp[i + 4] *
      GRM_HIL_B.VectorConcatenate_b[1] + tmp[i] * GRM_HIL_B.VectorConcatenate_b
      [0]));
    rtb_d_qGE[i] = rtb_Gain1_c;
  }

  /* Sum: '<S341>/Add1' incorporates:
   *  Constant: '<S341>/Q~_1'
   *  Constant: '<S341>/Q~_2'
   *  Constant: '<S341>/Q~_3'
   *  Constant: '<S341>/Q~_4'
   *  Product: '<S341>/Product4'
   *  Product: '<S341>/Product5'
   *  Product: '<S341>/Product6'
   *  Product: '<S341>/Product7'
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

  /* End of Sum: '<S341>/Add1' */

  /* Product: '<S341>/Product8' */
  for (i = 0; i < 4; i++) {
    rtb_Divide1_h = tmp[i + 12] * rtb_d_qGE[3] + (tmp[i + 8] * rtb_d_qGE[2] +
      (tmp[i + 4] * rtb_d_qGE[1] + tmp[i] * rtb_d_qGE[0]));
    rtb_siB_h[i] = rtb_Divide1_h;
  }

  /* Product: '<S327>/Product' incorporates:
   *  Math: '<S327>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    frac[i] = rtb_MatrixMultiply_tmp[i + 6] * rtb_siB_h[2] +
      (rtb_MatrixMultiply_tmp[i + 3] * rtb_siB_h[1] + rtb_MatrixMultiply_tmp[i] *
       rtb_siB_h[0]);
  }

  /* End of Product: '<S327>/Product' */

  /* Gain: '<S195>/Gain3' */
  GRM_HIL_B.ACC_x_B_mDs2 = GRM_HIL_P.Gain3_Gain_df * frac[0];

  /* Gain: '<S195>/Gain4' */
  GRM_HIL_B.ACC_y_B_mDs2 = GRM_HIL_P.Gain4_Gain_g * frac[1];

  /* Gain: '<S195>/Gain5' */
  GRM_HIL_B.ACC_z_B_mDs2 = GRM_HIL_P.Gain5_Gain_n * frac[2];

  /* Gain: '<S195>/Gain6' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.w_x_K_IB_B_radDs = GRM_HIL_P.Gain6_Gain_a *
    GRM_HIL_X.integration_eom_CSTATE[10];

  /* Gain: '<S195>/Gain7' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.w_y_K_IB_B_radDs = GRM_HIL_P.Gain7_Gain_ia *
    GRM_HIL_X.integration_eom_CSTATE[11];

  /* Gain: '<S195>/Gain8' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.w_z_K_IB_B_radDs = GRM_HIL_P.Gain8_Gain_l1 *
    GRM_HIL_X.integration_eom_CSTATE[12];

  /* Product: '<S206>/Product1' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   */
  rtb_Abs_iw = -rtb_Product_idx_1 * -rtb_Product_idx_2;

  /* Sum: '<S206>/Add' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   *  Product: '<S206>/Product'
   */
  rtb_Divide_h = -rtb_Product_idx_0 * rtb_Product_idx_3 + rtb_Abs_iw;

  /* Product: '<S206>/Product3' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   *  Product: '<S206>/Product8'
   */
  rtb_Abs_iw_tmp = -rtb_Product_idx_1 * -rtb_Product_idx_1;
  rtb_Abs_iw = rtb_Abs_iw_tmp;

  /* Sum: '<S206>/Add1' incorporates:
   *  Constant: '<S206>/Constant'
   *  MATLAB Function: '<S194>/MATLAB Function'
   *  Product: '<S206>/Product2'
   */
  rtb_Divide1_h = (GRM_HIL_P.Constant_Value_pf - -rtb_Product_idx_0 *
                   -rtb_Product_idx_0) - rtb_Abs_iw;

  /* Product: '<S206>/Product5' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   */
  rtb_Abs_iw = -rtb_Product_idx_0 * -rtb_Product_idx_2;

  /* Gain: '<S206>/Gain' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   *  Product: '<S206>/Product4'
   *  Sum: '<S206>/Add2'
   */
  rtb_Gain1_c = (-rtb_Product_idx_1 * rtb_Product_idx_3 - rtb_Abs_iw) *
    GRM_HIL_P.Gain_Gain_m;

  /* Saturate: '<S206>/Saturation' */
  if (rtb_Gain1_c > GRM_HIL_P.Saturation_UpperSat_g) {
    rtb_Gain1_c = GRM_HIL_P.Saturation_UpperSat_g;
  } else {
    if (rtb_Gain1_c < GRM_HIL_P.Saturation_LowerSat_ku) {
      rtb_Gain1_c = GRM_HIL_P.Saturation_LowerSat_ku;
    }
  }

  /* End of Saturate: '<S206>/Saturation' */

  /* Product: '<S206>/Product7' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   */
  rtb_Abs_iw = -rtb_Product_idx_2 * rtb_Product_idx_3;

  /* Sum: '<S206>/Add3' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   *  Product: '<S206>/Product6'
   */
  rtb_Product_l = -rtb_Product_idx_0 * -rtb_Product_idx_1 + rtb_Abs_iw;

  /* Product: '<S206>/Product9' incorporates:
   *  MATLAB Function: '<S194>/MATLAB Function'
   */
  rtb_Abs_iw = -rtb_Product_idx_2 * -rtb_Product_idx_2;

  /* Gain: '<S195>/Gain9' incorporates:
   *  Trigonometry: '<S206>/Trigonometric Function'
   */
  GRM_HIL_B.ATT_Phi_rad = GRM_HIL_P.Gain9_Gain_f * rt_atan2d_snf(rtb_Divide_h,
    rtb_Divide1_h);

  /* Trigonometry: '<S206>/Trigonometric Function1' */
  if (rtb_Gain1_c > 1.0) {
    rtb_Gain1_c = 1.0;
  } else {
    if (rtb_Gain1_c < -1.0) {
      rtb_Gain1_c = -1.0;
    }
  }

  /* Gain: '<S195>/Gain10' incorporates:
   *  Trigonometry: '<S206>/Trigonometric Function1'
   */
  GRM_HIL_B.ATT_Theta_rad = GRM_HIL_P.Gain10_Gain_k * asin(rtb_Gain1_c);

  /* Gain: '<S195>/Gain11' incorporates:
   *  Constant: '<S206>/Constant1'
   *  Sum: '<S206>/Add4'
   *  Trigonometry: '<S206>/Trigonometric Function2'
   */
  GRM_HIL_B.ATT_Psi_rad = rt_atan2d_snf(rtb_Product_l,
    (GRM_HIL_P.Constant1_Value_jl - rtb_Abs_iw_tmp) - rtb_Abs_iw) *
    GRM_HIL_P.Gain11_Gain_o;

  /* Gain: '<S211>/1//2' */
  frac[0] = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Phi_rad;
  frac[1] = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Theta_rad;
  frac[2] = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Psi_rad;

  /* Trigonometry: '<S211>/sincos' */
  rtb_Product1_m[0] = cos(frac[0]);
  frac[0] = sin(frac[0]);
  rtb_Product1_m[1] = cos(frac[1]);
  frac[1] = sin(frac[1]);
  rtb_Product1_m[2] = cos(frac[2]);
  rtb_Abs_iw_tmp = sin(frac[2]);

  /* Fcn: '<S211>/q0' incorporates:
   *  Fcn: '<S211>/q1'
   */
  rtb_TBG_tmp_1 = rtb_Product1_m[0] * rtb_Product1_m[1];
  rtb_TBG_tmp_2 = frac[0] * frac[1];
  GRM_HIL_B.q0 = rtb_TBG_tmp_1 * rtb_Product1_m[2] + rtb_TBG_tmp_2 *
    rtb_Abs_iw_tmp;

  /* Fcn: '<S211>/q1' */
  GRM_HIL_B.q1 = rtb_TBG_tmp_1 * rtb_Abs_iw_tmp - rtb_TBG_tmp_2 *
    rtb_Product1_m[2];

  /* Fcn: '<S211>/q2' incorporates:
   *  Fcn: '<S211>/q3'
   */
  rtb_TBG_tmp_1 = frac[0] * rtb_Product1_m[1];
  rtb_TBG_tmp_2 = rtb_Product1_m[0] * frac[1];
  GRM_HIL_B.q2 = rtb_TBG_tmp_2 * rtb_Product1_m[2] + rtb_TBG_tmp_1 *
    rtb_Abs_iw_tmp;

  /* Fcn: '<S211>/q3' */
  GRM_HIL_B.q3 = rtb_TBG_tmp_1 * rtb_Product1_m[2] - rtb_TBG_tmp_2 *
    rtb_Abs_iw_tmp;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S195>/Gain12' incorporates:
     *  Constant: '<S194>/Constant5'
     */
    GRM_HIL_B.POS_lambda_WGS84_rad = GRM_HIL_P.Gain12_Gain_b *
      GRM_HIL_P.Constant5_Value_k;

    /* Gain: '<S195>/Gain13' incorporates:
     *  Constant: '<S194>/Constant4'
     */
    GRM_HIL_B.POS_mue_WGS84_rad = GRM_HIL_P.Gain13_Gain *
      GRM_HIL_P.Constant4_Value_d;

    /* Gain: '<S195>/Gain18' incorporates:
     *  Constant: '<S194>/Constant7'
     */
    GRM_HIL_B.motor_state_perc = GRM_HIL_P.Gain18_Gain *
      GRM_HIL_P.Constant7_Value_l;
  }

  /* Gain: '<S195>/Gain14' */
  GRM_HIL_B.POS_h_WGS84_m = GRM_HIL_P.Gain14_Gain * GRM_HIL_B.Switch[2];

  /* Gain: '<S195>/Gain15' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.POS_x_NED_m = GRM_HIL_P.Gain15_Gain *
    GRM_HIL_X.integration_eom_CSTATE[0];

  /* Gain: '<S195>/Gain16' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.POS_y_NED_m = GRM_HIL_P.Gain16_Gain *
    GRM_HIL_X.integration_eom_CSTATE[1];

  /* Gain: '<S195>/Gain22' */
  GRM_HIL_B.mass_kg = GRM_HIL_P.Gain22_Gain * rtb_Subtract_e;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S195>/Gain19' incorporates:
     *  Constant: '<S194>/Constant3'
     */
    GRM_HIL_B.VEL_u_Wind_A_E_O_mDs = GRM_HIL_P.Gain19_Gain *
      GRM_HIL_P.Constant3_Value_i;

    /* Gain: '<S195>/Gain20' incorporates:
     *  Constant: '<S194>/Constant2'
     */
    GRM_HIL_B.VEL_v_Wind_A_E_O_mDs = GRM_HIL_P.Gain20_Gain *
      GRM_HIL_P.Constant2_Value_pm;

    /* Gain: '<S195>/Gain21' incorporates:
     *  Constant: '<S194>/Constant1'
     */
    GRM_HIL_B.VEL_w_Wind_A_E_O_mDs = GRM_HIL_P.Gain21_Gain *
      GRM_HIL_P.Constant1_Value_ay;

    /* ToAsyncQueueBlock generated from: '<Root>/Simulation' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4060665685U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3172620125U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_K_R_E_B_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(894065522U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_x_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2604031480U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_y_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1586093025U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ACC_z_B_mDs2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2824862884U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_x_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1179289942U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_y_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2840647369U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.w_z_K_IB_B_radDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1986075989U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Phi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3432632990U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Theta_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3020867623U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.ATT_Psi_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(317358904U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q0;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4185667930U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(472769218U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3886489147U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.q3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1814497057U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_lambda_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3030768749U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_mue_WGS84_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1437056495U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_h_WGS84_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2149510826U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_x_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1589702041U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_y_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1491186420U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.POS_z_NED_m;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(97513310U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.motor_state_perc;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3311156711U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.mass_kg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3058342806U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_u_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(793465964U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_v_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(159314027U, time, pData, size);
      }

      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.VEL_w_Wind_A_E_O_mDs;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2387294131U, time, pData, size);
      }
    }

    /* DiscretePulseGenerator: '<S17>/Pulse Generator1' */
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
      rtb_PulseGenerator1 *= rtb_Gain1_c;
    } else {
      rtb_PulseGenerator1 =
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
      rtb_PulseGenerator4 *= rtb_Gain1_c;
    } else {
      rtb_PulseGenerator4 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.constant.acc_z_mDs2;
    }

    /* End of Switch: '<S17>/Switch' */

    /* DiscretePulseGenerator: '<S17>/Pulse Generator7' */
    rtb_PulseGenerator7 = (GRM_HIL_DW.clockTickCounter_o <
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
    rtb_Gain1_c = (GRM_HIL_DW.clockTickCounter_l <
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
        rtb_PulseGenerator7 += GRM_HIL_P.Constant14_Value;
      } else {
        rtb_PulseGenerator7 = GRM_HIL_P.Constant11_Value;
      }

      /* End of Switch: '<S17>/Switch5' */
      rtb_PulseGenerator7 *= rtb_Gain1_c;
    } else {
      rtb_PulseGenerator7 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.constant.acc_y_mDs2;
    }

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
    if (GRM_HIL_B.Memory < GRM_HIL_B.Add) {
      GRM_HIL_B.value = GRM_HIL_B.Memory + 1.0;
    } else {
      GRM_HIL_B.value = 0.0;
    }

    /* End of MATLAB Function: '<S19>/Counter_with_external_limit' */

    /* RelationalOperator: '<S19>/Equal' */
    GRM_HIL_B.Equal = (GRM_HIL_B.Add == GRM_HIL_B.value);

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
      GRM_HIL_B.CMD_phi_rad = rtb_PulseGenerator1;

      /* SignalConversion generated from: '<S20>/External_Inputs_hold' */
      GRM_HIL_B.CMD_acc_z_mDs2 = rtb_PulseGenerator4;

      /* SignalConversion generated from: '<S20>/External_Inputs_hold' */
      GRM_HIL_B.CMD_acc_y_mDs2 = rtb_PulseGenerator7;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Com_to_FCC_emul_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S18>/Com_to_FCC_emul' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S26>/Gain2' */
    GRM_HIL_B.phi_rad = GRM_HIL_P.Gain2_Gain_b * GRM_HIL_B.CMD_phi_rad;
  }

  /* Sum: '<S25>/Sum' */
  GRM_HIL_B.error_phi = GRM_HIL_B.phi_rad - GRM_HIL_B.ATT_Phi_rad_f;

  /* DataTypeConversion: '<S25>/Cast To Double' incorporates:
   *  Gain: '<S25>/Gain5'
   *  Gain: '<S25>/Gain6'
   *  Gain: '<S25>/Gain7'
   *  Sum: '<S25>/Sum7'
   */
  GRM_HIL_B.Phi_Cmd_rad = (GRM_HIL_P.Gain6_Gain_at * GRM_HIL_B.error_phi -
    GRM_HIL_B.w_x_K_IB_B_radDs_f) * GRM_HIL_P.Gain5_Gain_m *
    GRM_HIL_P.Gain7_Gain_b;

  /* Saturate: '<S24>/Limit2maxDeflection' */
  if (GRM_HIL_B.Phi_Cmd_rad >
      GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_Gain1_c = GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else if (GRM_HIL_B.Phi_Cmd_rad <
             -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_Gain1_c = -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else {
    rtb_Gain1_c = GRM_HIL_B.Phi_Cmd_rad;
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

  /* TransferFcn: '<S25>/Transfer Fcn2' */
  rtb_Abs_iw = 0.0;
  rtb_Abs_iw += GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Num /
    GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn2_CSTATE_e;

  /* Gain: '<S25>/Gain2' incorporates:
   *  Gain: '<S25>/Gain4'
   *  Sum: '<S25>/Sum4'
   *  Sum: '<S25>/Sum6'
   */
  GRM_HIL_B.Psi_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.PropGain * GRM_HIL_B.Sum3 +
      rtb_Abs_iw) - GRM_HIL_B.w_z_K_IB_B_radDs_n) *
    GRM_HIL_P.FlightController_FCC.Yaw.innerLoop.PropGain;

  /* Sum: '<S25>/Sum1' */
  GRM_HIL_B.Sum1 = GRM_HIL_B.acc_z_mDs2 - GRM_HIL_B.ACC_z_B_mDs2_e;

  /* TransferFcn: '<S25>/Transfer Fcn1' */
  rtb_Abs_iw = 0.0;
  rtb_Abs_iw += GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Num /
    GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_e;

  /* Gain: '<S25>/Gain1' incorporates:
   *  Gain: '<S25>/Gain3'
   *  Sum: '<S25>/Sum2'
   *  Sum: '<S25>/Sum5'
   */
  GRM_HIL_B.Theta_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.PropGain * GRM_HIL_B.Sum1 +
      rtb_Abs_iw) - GRM_HIL_B.w_y_K_IB_B_radDs_e) *
    GRM_HIL_P.FlightController_FCC.Pitch.innerLoop.PropGain;

  /* Sum: '<S24>/Add4' incorporates:
   *  Constant: '<S24>/Constant'
   *  Sum: '<S24>/Add5'
   */
  rtb_PulseGenerator1 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f1_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add' incorporates:
   *  Fcn: '<S24>/Fcn'
   *  Fcn: '<S24>/Fcn1'
   *  Product: '<S24>/Multiply'
   *  Product: '<S24>/Multiply1'
   *  Sum: '<S24>/Add4'
   */
  rtb_PulseGenerator4 = -cos(rtb_PulseGenerator1) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_PulseGenerator1) * GRM_HIL_B.Theta_Cmd_rad;

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
  rtb_PulseGenerator7 = -cos(rtb_PulseGenerator1) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_PulseGenerator1) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S24>/Add8' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Sum: '<S24>/Add9'
   */
  rtb_Divide_jq_tmp = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f3_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add2' incorporates:
   *  Fcn: '<S24>/Fcn4'
   *  Fcn: '<S24>/Fcn5'
   *  Product: '<S24>/Multiply4'
   *  Product: '<S24>/Multiply5'
   *  Sum: '<S24>/Add8'
   */
  rtb_Divide_h = -cos(rtb_Divide_jq_tmp) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_Divide_jq_tmp) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S24>/Add10' incorporates:
   *  Constant: '<S24>/Constant3'
   *  Sum: '<S24>/Add11'
   */
  u0 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f4_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S24>/Add3' incorporates:
   *  Fcn: '<S24>/Fcn6'
   *  Fcn: '<S24>/Fcn7'
   *  Product: '<S24>/Multiply6'
   *  Product: '<S24>/Multiply7'
   *  Sum: '<S24>/Add10'
   */
  rtb_Divide1_h = -cos(u0) * GRM_HIL_B.Psi_Cmd_rad + sin(u0) *
    GRM_HIL_B.Theta_Cmd_rad;

  /* Abs: '<S30>/Abs' */
  rtb_Abs_iw = fabs(rtb_PulseGenerator4);

  /* Sum: '<S24>/Add16' incorporates:
   *  Abs: '<S24>/Abs'
   *  Constant: '<S24>/Constant4'
   */
  rtb_Product_l = GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad -
    fabs(rtb_Gain1_c);

  /* RelationalOperator: '<S30>/Relational Operator' */
  rtb_RelationalOperator = (rtb_Abs_iw > rtb_Product_l);

  /* Abs: '<S30>/Abs1' */
  rtb_Abs_iw = fabs(rtb_PulseGenerator7);

  /* RelationalOperator: '<S30>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_Abs_iw > rtb_Product_l);

  /* Abs: '<S30>/Abs2' */
  rtb_Abs_iw = fabs(rtb_Divide_h);

  /* RelationalOperator: '<S30>/Relational Operator2' */
  rtb_RelationalOperator2 = (rtb_Abs_iw > rtb_Product_l);

  /* Abs: '<S30>/Abs3' */
  rtb_Abs_iw = fabs(rtb_Divide1_h);

  /* Logic: '<S30>/OR' incorporates:
   *  RelationalOperator: '<S30>/Relational Operator3'
   */
  GRM_HIL_B.OR = (rtb_RelationalOperator || rtb_RelationalOperator1 ||
                  rtb_RelationalOperator2 || (rtb_Abs_iw > rtb_Product_l));

  /* Logic: '<S29>/Logical Operator' */
  GRM_HIL_B.LogicalOperator = !GRM_HIL_B.OR;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S31>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4 = GRM_HIL_B.LogicalOperator;

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
    GRM_HIL_B.Merge = rtb_PulseGenerator4;

    /* Inport: '<S31>/Fin_2_Cmd_rad' */
    GRM_HIL_B.Merge1 = rtb_PulseGenerator7;

    /* Inport: '<S31>/Fin_3_Cmd_rad' */
    GRM_HIL_B.Merge2 = rtb_Divide_h;

    /* Inport: '<S31>/Fin_4_Cmd_rad' */
    GRM_HIL_B.Merge3 = rtb_Divide1_h;
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
    rtb_PulseGenerator1 = fabs(fmax(fmax(fmax(rtb_PulseGenerator4,
      rtb_PulseGenerator7), rtb_Divide_h), rtb_Divide1_h));

    /* Product: '<S32>/Multiply' incorporates:
     *  Product: '<S32>/Divide'
     */
    GRM_HIL_B.Merge = rtb_PulseGenerator4 / rtb_PulseGenerator1 * rtb_Product_l;

    /* Product: '<S32>/Multiply1' incorporates:
     *  Product: '<S32>/Divide1'
     */
    GRM_HIL_B.Merge1 = rtb_PulseGenerator7 / rtb_PulseGenerator1 * rtb_Product_l;

    /* Product: '<S32>/Multiply2' incorporates:
     *  Product: '<S32>/Divide4'
     */
    GRM_HIL_B.Merge2 = rtb_Divide_h / rtb_PulseGenerator1 * rtb_Product_l;

    /* Product: '<S32>/Multiply3' incorporates:
     *  Product: '<S32>/Divide2'
     */
    GRM_HIL_B.Merge3 = rtb_Divide1_h / rtb_PulseGenerator1 * rtb_Product_l;
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
  rtb_Abs_iw_tmp = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms -
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant6'
   *  Product: '<S36>/Divide'
   *  Product: '<S36>/Product'
   *  Sum: '<S24>/Add14'
   */
  rtb_Abs_iw = (rtb_Gain1_c + GRM_HIL_B.Merge3) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_Abs_iw_tmp +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Abs_iw > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_Abs_iw < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms = rtb_Abs_iw;
  }

  /* End of Saturate: '<S36>/Saturation' */

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S35>/Constant2'
   *  Product: '<S35>/Divide'
   *  Product: '<S35>/Product'
   *  Sum: '<S24>/Add13'
   */
  rtb_Abs_iw = (rtb_Gain1_c + GRM_HIL_B.Merge2) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_Abs_iw_tmp +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Abs_iw > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_Abs_iw < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_e = rtb_Abs_iw;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S34>/Constant2'
   *  Product: '<S34>/Divide'
   *  Product: '<S34>/Product'
   *  Sum: '<S24>/Add12'
   */
  rtb_Abs_iw = (rtb_Gain1_c + GRM_HIL_B.Merge1) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_Abs_iw_tmp +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S34>/Saturation' */
  if (rtb_Abs_iw > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_Abs_iw < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_c = rtb_Abs_iw;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S33>/Add' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S33>/Constant2'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Product'
   *  Sum: '<S24>/Add15'
   */
  u0 = (rtb_Gain1_c + GRM_HIL_B.Merge) /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad * rtb_Abs_iw_tmp +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

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
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
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
    rtb_PulseGenerator1 = GRM_HIL_P.Servo_PWM.Pulswidth_cmd_max_ms -
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
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator1
      * GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator1' */

    /* Saturate: '<S13>/Saturation' */
    if (u0 > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_o = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (u0 < -GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_o = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_o = u0;
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
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator1
      * GRM_HIL_P.Servo_PWM.max_deflection_rad;

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
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator1
      * GRM_HIL_P.Servo_PWM.max_deflection_rad;

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
          GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_PulseGenerator1
      * GRM_HIL_P.Servo_PWM.max_deflection_rad;

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
    /* ToAsyncQueueBlock generated from: '<S25>/Cast To Double' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.Phi_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2374608575U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<S25>/Sum' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      {
        double time = GRM_HIL_M->Timing.t[1];
        void *pData = (void *)&GRM_HIL_B.error_phi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(413736318U, time, pData, size);
      }
    }
  }

  /* Step: '<Root>/Step1' */
  if (rtb_Product3_hu < GRM_HIL_P.Step1_Time) {
    rtb_Abs_iw = GRM_HIL_P.Step1_Y0;
  } else {
    rtb_Abs_iw = GRM_HIL_P.Step1_YFinal;
  }

  /* Step: '<Root>/External Moment' */
  if (rtb_Product3_hu < GRM_HIL_P.ExternalMoment_Time) {
    rtb_Product3_hu = GRM_HIL_P.ExternalMoment_Y0;
  } else {
    rtb_Product3_hu = GRM_HIL_P.ExternalMoment_YFinal;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  rtb_Gain1_c = (rtb_Product3_hu + rtb_Abs_iw) * GRM_HIL_P.Gain1_Gain_j2;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtei): '<S38>/Encoder Input3' */
    /* S-Function Block: <S38>/Encoder Input3 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = GRM_HIL_P.EncoderInput3_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 3,
                     GRM_HIL_P.EncoderInput3_Channels, &rtb_VectorConcatenate_f
                     [0], &parm);
    }

    /* S-Function (sldrtdi): '<S38>/Digital Input' */
    /* S-Function Block: <S38>/Digital Input */
    {
      RTBIO_DriverIO(0, DIGITALINPUT, IOREAD, 4, GRM_HIL_P.DigitalInput_Channels,
                     &GRM_HIL_B.DigitalInput[0], &GRM_HIL_P.DigitalInput_BitMode);
    }

    /* Gain: '<S45>/Shaft2degYaw' */
    GRM_HIL_B.yaw_deg = GRM_HIL_P.Shaft2degYaw_Gain * rtb_VectorConcatenate_f[0];
  }

  /* TransportDelay: '<S176>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Abs_iw = rt_TDelayInterpolate(
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

  /* Gain: '<S176>/Gain' incorporates:
   *  Sum: '<S176>/Sum'
   */
  GRM_HIL_B.Gain = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.yaw_deg - rtb_Abs_iw);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S45>/Shaft2degPitch' */
    GRM_HIL_B.pitch_deg = GRM_HIL_P.Shaft2degPitch_Gain *
      rtb_VectorConcatenate_f[1];
  }

  /* TransportDelay: '<S174>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_f.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_f.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Abs_iw = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK_m.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK_m.Last,
      GRM_HIL_DW.TransportDelay_IWORK_m.Tail,
      GRM_HIL_DW.TransportDelay_IWORK_m.Head,
      GRM_HIL_P.TransportDelay_InitOutput_d,
      1,
      0);
  }

  /* Gain: '<S174>/Gain' incorporates:
   *  Sum: '<S174>/Sum'
   */
  GRM_HIL_B.Gain_p = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.pitch_deg - rtb_Abs_iw);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S45>/Shaft2degRoll' */
    GRM_HIL_B.roll_deg = GRM_HIL_P.Shaft2degRoll_Gain * rtb_VectorConcatenate_f
      [2];
  }

  /* TransportDelay: '<S175>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_a.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_a.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Abs_iw = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK_c.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK_c.Last,
      GRM_HIL_DW.TransportDelay_IWORK_c.Tail,
      GRM_HIL_DW.TransportDelay_IWORK_c.Head,
      GRM_HIL_P.TransportDelay_InitOutput_c,
      1,
      0);
  }

  /* Gain: '<S175>/Gain' incorporates:
   *  Sum: '<S175>/Sum'
   */
  GRM_HIL_B.Gain_m = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.roll_deg - rtb_Abs_iw);

  /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  /* Abs: '<S72>/Abs' incorporates:
   *  Abs: '<S176>/Abs'
   *  Abs: '<S52>/Abs'
   */
  rtb_PulseGenerator7 = fabs(GRM_HIL_B.Gain);

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */

  /* RelationalOperator: '<S167>/Compare' incorporates:
   *  Abs: '<S72>/Abs'
   *  Constant: '<S167>/Constant'
   */
  rtb_Compare = (rtb_PulseGenerator7 >=
                 GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S72>/Enabled pass' */
  /* Constant: '<S72>/const_upper_limit' incorporates:
   *  Constant: '<S72>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMinVolt,
                      &GRM_HIL_B.Merge_d, &GRM_HIL_B.Merge1_m,
                      &GRM_HIL_DW.Enabledpass_d);

  /* End of Outputs for SubSystem: '<S72>/Enabled pass' */

  /* Logic: '<S72>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_l = !rtb_Compare;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S168>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3 =
      GRM_HIL_B.LogicalOperator_l;

    /* Outputs for Enabled SubSystem: '<S72>/Enabled adapt' incorporates:
     *  EnablePort: '<S168>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3;
    }

    /* End of Outputs for SubSystem: '<S72>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S72>/Enabled adapt' incorporates:
   *  EnablePort: '<S168>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S168>/Abs' incorporates:
       *  Constant: '<S168>/Constant'
       */
      GRM_HIL_B.Abs = fabs(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_hard_limit_vel);
    }

    /* Sum: '<S168>/Add' incorporates:
     *  Abs: '<S72>/Abs'
     *  Constant: '<S168>/Constant1'
     *  Gain: '<S168>/Gain'
     *  Product: '<S168>/Divide'
     */
    rtb_Abs_iw = GRM_HIL_B.Abs / rtb_PulseGenerator7 *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_limit_adaption_coef - 1.0);

    /* Product: '<S168>/Product' incorporates:
     *  Constant: '<S72>/const_upper_limit'
     */
    GRM_HIL_B.Merge_d = rtb_Abs_iw *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;

    /* Product: '<S168>/Product1' incorporates:
     *  Constant: '<S72>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_m = rtb_Abs_iw *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S72>/Enabled adapt' */

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S72>/Constant2'
   */
  if (GRM_HIL_B.Gain > GRM_HIL_P.Switch2_Threshold_o) {
    GRM_HIL_B.Switch2 = GRM_HIL_B.Merge_d;
  } else {
    GRM_HIL_B.Switch2 = GRM_HIL_P.Constant2_Value_k;
  }

  /* End of Switch: '<S72>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S72>/Gain' incorporates:
     *  Constant: '<S72>/Constant2'
     */
    GRM_HIL_B.Gain_j = GRM_HIL_P.Gain_Gain_eu1 * GRM_HIL_P.Constant2_Value_k;
  }

  /* Switch: '<S72>/Switch1' */
  if (GRM_HIL_B.Gain > GRM_HIL_P.Switch1_Threshold_e) {
    GRM_HIL_B.Switch1 = GRM_HIL_B.Gain_j;
  } else {
    GRM_HIL_B.Switch1 = GRM_HIL_B.Merge1_m;
  }

  /* End of Switch: '<S72>/Switch1' */

  /* TransferFcn: '<S49>/Transfer Fcn1' */
  rtb_Abs_iw = 0.0;
  rtb_Abs_iw += GRM_HIL_P.TransferFcn1_C[0] * GRM_HIL_X.TransferFcn1_CSTATE_l[0];
  rtb_Abs_iw += GRM_HIL_P.TransferFcn1_C[1] * GRM_HIL_X.TransferFcn1_CSTATE_l[1];

  /* Product: '<S48>/Product' */
  GRM_HIL_B.Product_k = rtb_Abs_iw *
    GRM_HIL_rtZGimbal_Cmd_Bus.Gimbal_Phi_Cmd_deg;

  /* Sum: '<S48>/Sum' */
  GRM_HIL_B.Yaw_err = GRM_HIL_B.Product_k - GRM_HIL_B.yaw_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S73>/Proportional Gain' */
    rtb_ProportionalGain =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Proportional_Gain *
      GRM_HIL_B.Yaw_err;

    /* Gain: '<S73>/Derivative Gain' */
    rtb_DerivativeGain =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Derivative_Gain *
      GRM_HIL_B.Yaw_err;
  }

  /* Integrator: '<S73>/Integrator' */
  GRM_HIL_B.Integrator = GRM_HIL_X.Integrator_CSTATE;

  /* Integrator: '<S73>/Filter' */
  GRM_HIL_B.Filter = GRM_HIL_X.Filter_CSTATE;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S73>/Filter Coefficient' incorporates:
     *  Sum: '<S73>/SumD'
     */
    GRM_HIL_B.FilterCoefficient = (rtb_DerivativeGain - GRM_HIL_B.Filter) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Filter_Coefficient;

    /* Sum: '<S73>/Sum' */
    rtb_Sum_e = (rtb_ProportionalGain + GRM_HIL_B.Integrator) +
      GRM_HIL_B.FilterCoefficient;

    /* Logic: '<S72>/Logical Operator1' incorporates:
     *  Constant: '<S72>/Constant'
     */
    GRM_HIL_B.LogicalOperator1 =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S72>/Switch' incorporates:
   *  Abs: '<S72>/Abs'
   *  Constant: '<S166>/Constant'
   *  Constant: '<S72>/Constant1'
   *  RelationalOperator: '<S166>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1) {
    GRM_HIL_B.Switch_h = GRM_HIL_P.Constant1_Value_fh;
  } else {
    GRM_HIL_B.Switch_h = (rtb_PulseGenerator7 >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_soft_limit_vel);
  }

  /* End of Switch: '<S72>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S170>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3 = GRM_HIL_B.Switch_h;

    /* Outputs for Enabled SubSystem: '<S73>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3,
                       GRM_HIL_B.Switch2, GRM_HIL_B.Switch1, rtb_Sum_e,
                       &GRM_HIL_B.Merge_b, &GRM_HIL_DW.Saturation_n);

    /* End of Outputs for SubSystem: '<S73>/Saturation' */

    /* Logic: '<S73>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_k = !GRM_HIL_B.Switch_h;

    /* Outputs for Enabled SubSystem: '<S73>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_k, rtb_Sum_e,
                 &GRM_HIL_B.Merge_b, &GRM_HIL_DW.pass_e);

    /* End of Outputs for SubSystem: '<S73>/pass' */

    /* Outputs for Enabled SubSystem: '<S71>/pass' incorporates:
     *  EnablePort: '<S75>/Enable'
     */
    /* Logic: '<S71>/Logical Operator' incorporates:
     *  Constant: '<S71>/Constant'
     *  Inport: '<S75>/Controller_Cmd'
     */
    if (!(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Limit_Controllers != 0.0)) {
      GRM_HIL_B.Merge_m = GRM_HIL_B.Merge_b;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.pass_SubsysRanBC);
      }
    }

    /* End of Logic: '<S71>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S71>/pass' */

    /* Outputs for Enabled SubSystem: '<S71>/Control_Limits' incorporates:
     *  EnablePort: '<S74>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S71>/Constant' */
      GRM_HIL_DW.Control_Limits_MODE =
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Limit_Controllers > 0.0);
    }

    /* End of Outputs for SubSystem: '<S71>/Control_Limits' */
  }

  /* Outputs for Enabled SubSystem: '<S71>/Control_Limits' incorporates:
   *  EnablePort: '<S74>/Enable'
   */
  if (GRM_HIL_DW.Control_Limits_MODE) {
    /* Product: '<S74>/Divide' incorporates:
     *  Constant: '<S74>/Constant'
     *  Constant: '<S74>/Constant1'
     *  Gain: '<S74>/Gain2'
     *  Sum: '<S74>/Subtract'
     */
    rtb_Divide_h = GRM_HIL_P.Constant_Value /
      ((GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV - GRM_HIL_B.Gain) *
       GRM_HIL_P.Gain2_Gain);

    /* Product: '<S74>/Divide1' incorporates:
     *  Constant: '<S74>/Constant2'
     *  Constant: '<S74>/Constant3'
     *  Gain: '<S74>/Gain3'
     *  Sum: '<S74>/Subtract1'
     */
    rtb_Divide1_h = GRM_HIL_P.Constant3_Value / ((GRM_HIL_B.Gain -
      (-GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV)) * GRM_HIL_P.Gain3_Gain);

    /* Gain: '<S110>/Filter Coefficient' incorporates:
     *  Gain: '<S101>/Derivative Gain'
     *  Integrator: '<S102>/Filter'
     *  Sum: '<S102>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_h =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Derivative_Gain * rtb_Divide_h -
       GRM_HIL_X.Filter_CSTATE_j) * GRM_HIL_P.PIDController_N;

    /* Sum: '<S116>/Sum' incorporates:
     *  Gain: '<S112>/Proportional Gain'
     *  Integrator: '<S107>/Integrator'
     */
    rtb_ProportionalGain =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Proportional_Gain * rtb_Divide_h
       + GRM_HIL_X.Integrator_CSTATE_f5) + GRM_HIL_B.FilterCoefficient_h;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_ProportionalGain > GRM_HIL_P.PIDController_UpperSaturationLimit) {
      rtb_DerivativeGain = GRM_HIL_P.PIDController_UpperSaturationLimit;
    } else if (rtb_ProportionalGain <
               GRM_HIL_P.PIDController_LowerSaturationLimit) {
      rtb_DerivativeGain = GRM_HIL_P.PIDController_LowerSaturationLimit;
    } else {
      rtb_DerivativeGain = rtb_ProportionalGain;
    }

    /* End of Saturate: '<S114>/Saturation' */

    /* Gain: '<S154>/Filter Coefficient' incorporates:
     *  Gain: '<S145>/Derivative Gain'
     *  Integrator: '<S146>/Filter'
     *  Sum: '<S146>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_b =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Derivative_Gain * rtb_Divide1_h
       - GRM_HIL_X.Filter_CSTATE_b) * GRM_HIL_P.PIDController1_N;

    /* Sum: '<S160>/Sum' incorporates:
     *  Gain: '<S156>/Proportional Gain'
     *  Integrator: '<S151>/Integrator'
     */
    rtb_PulseGenerator4 =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Proportional_Gain *
       rtb_Divide1_h + GRM_HIL_X.Integrator_CSTATE_i) +
      GRM_HIL_B.FilterCoefficient_b;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_PulseGenerator4 > GRM_HIL_P.PIDController1_UpperSaturationLimit) {
      rtb_PulseGenerator1 = GRM_HIL_P.PIDController1_UpperSaturationLimit;
    } else if (rtb_PulseGenerator4 <
               GRM_HIL_P.PIDController1_LowerSaturationLimit) {
      rtb_PulseGenerator1 = GRM_HIL_P.PIDController1_LowerSaturationLimit;
    } else {
      rtb_PulseGenerator1 = rtb_PulseGenerator4;
    }

    /* End of Saturate: '<S158>/Saturation' */

    /* Sum: '<S100>/SumI4' incorporates:
     *  Gain: '<S100>/Kb'
     *  Gain: '<S104>/Integral Gain'
     *  Sum: '<S100>/SumI2'
     */
    GRM_HIL_B.SumI4 = (rtb_DerivativeGain - rtb_ProportionalGain) *
      GRM_HIL_P.PIDController_Kb +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Integral_Gain * rtb_Divide_h;

    /* Sum: '<S144>/SumI4' incorporates:
     *  Gain: '<S144>/Kb'
     *  Gain: '<S148>/Integral Gain'
     *  Sum: '<S144>/SumI2'
     */
    GRM_HIL_B.SumI4_e = (rtb_PulseGenerator1 - rtb_PulseGenerator4) *
      GRM_HIL_P.PIDController1_Kb +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Integral_Gain * rtb_Divide1_h;

    /* Sum: '<S74>/Sum' incorporates:
     *  Gain: '<S74>/Gain'
     *  Gain: '<S74>/Gain1'
     */
    GRM_HIL_B.Merge_m = (GRM_HIL_B.Merge_b -
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Weighting *
                         rtb_DerivativeGain) +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Weighting * rtb_PulseGenerator1;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Control_Limits_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S71>/Control_Limits' */

  /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  /* Abs: '<S53>/Abs' incorporates:
   *  Abs: '<S174>/Abs'
   *  Abs: '<S52>/Abs2'
   */
  rtb_ProportionalGain = fabs(GRM_HIL_B.Gain_p);

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */

  /* RelationalOperator: '<S56>/Compare' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S56>/Constant'
   */
  rtb_Compare_i = (rtb_ProportionalGain >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S53>/Enabled pass' */
  /* Constant: '<S53>/const_upper_limit' incorporates:
   *  Constant: '<S53>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_i,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMinVolt,
                      &GRM_HIL_B.Merge_o, &GRM_HIL_B.Merge1_n,
                      &GRM_HIL_DW.Enabledpass);

  /* End of Outputs for SubSystem: '<S53>/Enabled pass' */

  /* Logic: '<S53>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_d = !rtb_Compare_i;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S57>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_c =
      GRM_HIL_B.LogicalOperator_d;

    /* Outputs for Enabled SubSystem: '<S53>/Enabled adapt' incorporates:
     *  EnablePort: '<S57>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE_l =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_c;
    }

    /* End of Outputs for SubSystem: '<S53>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S53>/Enabled adapt' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE_l) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S57>/Abs' incorporates:
       *  Constant: '<S57>/Constant'
       */
      GRM_HIL_B.Abs_j = fabs
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_hard_limit_vel);
    }

    /* Sum: '<S57>/Add' incorporates:
     *  Abs: '<S53>/Abs'
     *  Constant: '<S57>/Constant1'
     *  Gain: '<S57>/Gain'
     *  Product: '<S57>/Divide'
     */
    rtb_PulseGenerator1 = GRM_HIL_B.Abs_j / rtb_ProportionalGain *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_limit_adaption_coef - 1.0);

    /* Product: '<S57>/Product' incorporates:
     *  Constant: '<S53>/const_upper_limit'
     */
    GRM_HIL_B.Merge_o = rtb_PulseGenerator1 *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;

    /* Product: '<S57>/Product1' incorporates:
     *  Constant: '<S53>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_n = rtb_PulseGenerator1 *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_g);
    }
  }

  /* End of Outputs for SubSystem: '<S53>/Enabled adapt' */

  /* Switch: '<S53>/Switch2' incorporates:
   *  Constant: '<S53>/Constant2'
   */
  if (GRM_HIL_B.Gain_p > GRM_HIL_P.Switch2_Threshold_o1) {
    GRM_HIL_B.Switch2_i = GRM_HIL_B.Merge_o;
  } else {
    GRM_HIL_B.Switch2_i = GRM_HIL_P.Constant2_Value_ee;
  }

  /* End of Switch: '<S53>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S53>/Gain' incorporates:
     *  Constant: '<S53>/Constant2'
     */
    GRM_HIL_B.Gain_h = GRM_HIL_P.Gain_Gain_k2 * GRM_HIL_P.Constant2_Value_ee;
  }

  /* Switch: '<S53>/Switch1' */
  if (GRM_HIL_B.Gain_p > GRM_HIL_P.Switch1_Threshold_mt) {
    GRM_HIL_B.Switch1_b = GRM_HIL_B.Gain_h;
  } else {
    GRM_HIL_B.Switch1_b = GRM_HIL_B.Merge1_n;
  }

  /* End of Switch: '<S53>/Switch1' */

  /* Product: '<S46>/Product' */
  GRM_HIL_B.pitch_cmd = rtb_Abs_iw *
    GRM_HIL_rtZGimbal_Cmd_Bus.Gimbal_Theta_Cmd_deg;

  /* Sum: '<S46>/Sum2' */
  GRM_HIL_B.pitch_err = GRM_HIL_B.pitch_cmd - GRM_HIL_B.pitch_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S54>/Proportional Gain' */
    rtb_ProportionalGain_n =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Proportional_Gain *
      GRM_HIL_B.pitch_err;

    /* Gain: '<S54>/Derivative Gain' */
    rtb_DerivativeGain_h =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Derivative_Gain *
      GRM_HIL_B.pitch_err;
  }

  /* Integrator: '<S54>/Integrator' */
  GRM_HIL_B.Integrator_p = GRM_HIL_X.Integrator_CSTATE_k;

  /* Integrator: '<S54>/Filter' */
  GRM_HIL_B.Filter_c = GRM_HIL_X.Filter_CSTATE_f;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S54>/Filter Coefficient' incorporates:
     *  Sum: '<S54>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_c = (rtb_DerivativeGain_h - GRM_HIL_B.Filter_c) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Filter_Coefficient;

    /* Sum: '<S54>/Sum' */
    rtb_Sum_l = (rtb_ProportionalGain_n + GRM_HIL_B.Integrator_p) +
      GRM_HIL_B.FilterCoefficient_c;

    /* Logic: '<S53>/Logical Operator1' incorporates:
     *  Constant: '<S53>/Constant'
     */
    GRM_HIL_B.LogicalOperator1_i =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S53>/Switch' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S53>/Constant1'
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S55>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1_i) {
    GRM_HIL_B.Switch_p = GRM_HIL_P.Constant1_Value_fj;
  } else {
    GRM_HIL_B.Switch_p = (rtb_ProportionalGain >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_soft_limit_vel);
  }

  /* End of Switch: '<S53>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S59>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_o =
      GRM_HIL_B.Switch_p;

    /* Outputs for Enabled SubSystem: '<S54>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_o,
                       GRM_HIL_B.Switch2_i, GRM_HIL_B.Switch1_b, rtb_Sum_l,
                       &GRM_HIL_B.Merge_l, &GRM_HIL_DW.Saturation);

    /* End of Outputs for SubSystem: '<S54>/Saturation' */

    /* Logic: '<S54>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_p = !GRM_HIL_B.Switch_p;

    /* Outputs for Enabled SubSystem: '<S54>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_p, rtb_Sum_l,
                 &GRM_HIL_B.Merge_l, &GRM_HIL_DW.pass);

    /* End of Outputs for SubSystem: '<S54>/pass' */
  }

  /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  /* Abs: '<S62>/Abs' incorporates:
   *  Abs: '<S175>/Abs'
   *  Abs: '<S52>/Abs4'
   */
  rtb_ProportionalGain_n = fabs(GRM_HIL_B.Gain_m);

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */

  /* RelationalOperator: '<S65>/Compare' incorporates:
   *  Abs: '<S62>/Abs'
   *  Constant: '<S65>/Constant'
   */
  rtb_Compare_n = (rtb_ProportionalGain_n >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S62>/Enabled pass' */
  /* Constant: '<S62>/const_upper_limit' incorporates:
   *  Constant: '<S62>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_n,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMinVolt,
                      &GRM_HIL_B.Merge_e, &GRM_HIL_B.Merge1_h,
                      &GRM_HIL_DW.Enabledpass_k);

  /* End of Outputs for SubSystem: '<S62>/Enabled pass' */

  /* Logic: '<S62>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_dh = !rtb_Compare_n;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S66>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_cx =
      GRM_HIL_B.LogicalOperator_dh;

    /* Outputs for Enabled SubSystem: '<S62>/Enabled adapt' incorporates:
     *  EnablePort: '<S66>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE_p =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_cx;
    }

    /* End of Outputs for SubSystem: '<S62>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S62>/Enabled adapt' incorporates:
   *  EnablePort: '<S66>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE_p) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S66>/Abs' incorporates:
       *  Constant: '<S66>/Constant'
       */
      GRM_HIL_B.Abs_h = fabs
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_hard_limit_vel);
    }

    /* Sum: '<S66>/Add' incorporates:
     *  Abs: '<S62>/Abs'
     *  Constant: '<S66>/Constant1'
     *  Gain: '<S66>/Gain'
     *  Product: '<S66>/Divide'
     */
    rtb_PulseGenerator1 = GRM_HIL_B.Abs_h / rtb_ProportionalGain_n *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_limit_adaption_coef - 1.0);

    /* Product: '<S66>/Product' incorporates:
     *  Constant: '<S62>/const_upper_limit'
     */
    GRM_HIL_B.Merge_e = rtb_PulseGenerator1 *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;

    /* Product: '<S66>/Product1' incorporates:
     *  Constant: '<S62>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_h = rtb_PulseGenerator1 *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_o);
    }
  }

  /* End of Outputs for SubSystem: '<S62>/Enabled adapt' */

  /* Switch: '<S62>/Switch2' incorporates:
   *  Constant: '<S62>/Constant2'
   */
  if (GRM_HIL_B.Gain_m > GRM_HIL_P.Switch2_Threshold_b) {
    GRM_HIL_B.Switch2_b = GRM_HIL_B.Merge_e;
  } else {
    GRM_HIL_B.Switch2_b = GRM_HIL_P.Constant2_Value_go;
  }

  /* End of Switch: '<S62>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S62>/Gain' incorporates:
     *  Constant: '<S62>/Constant2'
     */
    GRM_HIL_B.Gain_d = GRM_HIL_P.Gain_Gain_hk * GRM_HIL_P.Constant2_Value_go;
  }

  /* Switch: '<S62>/Switch1' */
  if (GRM_HIL_B.Gain_m > GRM_HIL_P.Switch1_Threshold_i) {
    GRM_HIL_B.Switch1_c = GRM_HIL_B.Gain_d;
  } else {
    GRM_HIL_B.Switch1_c = GRM_HIL_B.Merge1_h;
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Product: '<S47>/Product1' */
  GRM_HIL_B.Product1 = rtb_Abs_iw * GRM_HIL_rtZGimbal_Cmd_Bus.Gimbal_Psi_Cmd_deg;

  /* Sum: '<S47>/Sum1' */
  GRM_HIL_B.Roll_err = GRM_HIL_B.Product1 - GRM_HIL_B.roll_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S63>/Proportional Gain' */
    rtb_ProportionalGain_d =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Proportional_Gain *
      GRM_HIL_B.Roll_err;

    /* Gain: '<S63>/Derivative Gain' */
    rtb_DerivativeGain_oe =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Derivative_Gain *
      GRM_HIL_B.Roll_err;
  }

  /* Integrator: '<S63>/Integrator' */
  GRM_HIL_B.Integrator_o = GRM_HIL_X.Integrator_CSTATE_p;

  /* Integrator: '<S63>/Filter' */
  GRM_HIL_B.Filter_k = GRM_HIL_X.Filter_CSTATE_k;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S63>/Filter Coefficient' incorporates:
     *  Sum: '<S63>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_j = (rtb_DerivativeGain_oe - GRM_HIL_B.Filter_k)
      * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Filter_Coefficient;

    /* Sum: '<S63>/Sum' */
    rtb_Sum_n = (rtb_ProportionalGain_d + GRM_HIL_B.Integrator_o) +
      GRM_HIL_B.FilterCoefficient_j;

    /* Logic: '<S62>/Logical Operator1' incorporates:
     *  Constant: '<S62>/Constant'
     */
    GRM_HIL_B.LogicalOperator1_p =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S62>/Switch' incorporates:
   *  Abs: '<S62>/Abs'
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S64>/Constant'
   *  RelationalOperator: '<S64>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1_p) {
    GRM_HIL_B.Switch_pb = GRM_HIL_P.Constant1_Value_o4;
  } else {
    GRM_HIL_B.Switch_pb = (rtb_ProportionalGain_n >=
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_soft_limit_vel);
  }

  /* End of Switch: '<S62>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S68>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_ol =
      GRM_HIL_B.Switch_pb;

    /* Outputs for Enabled SubSystem: '<S63>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_ol,
                       GRM_HIL_B.Switch2_b, GRM_HIL_B.Switch1_c, rtb_Sum_n,
                       &GRM_HIL_B.Merge_lu, &GRM_HIL_DW.Saturation_l);

    /* End of Outputs for SubSystem: '<S63>/Saturation' */

    /* Logic: '<S63>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_b = !GRM_HIL_B.Switch_pb;

    /* Outputs for Enabled SubSystem: '<S63>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_b, rtb_Sum_n,
                 &GRM_HIL_B.Merge_lu, &GRM_HIL_DW.pass_p);

    /* End of Outputs for SubSystem: '<S63>/pass' */

    /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
     *  EnablePort: '<S52>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S45>/Constant2' */
      if (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atOutput > 0.0)
      {
        GRM_HIL_DW.Voltage_Limitations_MODE = true;
      } else {
        if (GRM_HIL_DW.Voltage_Limitations_MODE) {
          /* Disable for If: '<S52>/If' */
          GRM_HIL_DW.If_ActiveSubsystem_m = -1;

          /* Disable for If: '<S52>/If1' */
          GRM_HIL_DW.If1_ActiveSubsystem = -1;

          /* Disable for If: '<S52>/If2' */
          GRM_HIL_DW.If2_ActiveSubsystem = -1;
          GRM_HIL_DW.Voltage_Limitations_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */
  }

  /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  if (GRM_HIL_DW.Voltage_Limitations_MODE) {
    /* Abs: '<S52>/Abs' */
    rtb_Abs_iw = rtb_PulseGenerator7;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S52>/Abs1' incorporates:
       *  Constant: '<S52>/max_vel_yaw'
       */
      GRM_HIL_B.Abs1 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV);
    }

    /* If: '<S52>/If' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_Abs_iw >= GRM_HIL_B.Abs1);
      GRM_HIL_DW.If_ActiveSubsystem_m = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If_ActiveSubsystem_m;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S52>/If Action limit_yaw' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      /* Saturate: '<S185>/Limit_Voltage_Yaw' */
      if (GRM_HIL_B.Merge_m > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt) {
        GRM_HIL_B.Merge_mx = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_m <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt) {
        GRM_HIL_B.Merge_mx = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge_mx = GRM_HIL_B.Merge_m;
      }

      /* End of Saturate: '<S185>/Limit_Voltage_Yaw' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionlimit_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action limit_yaw' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S52>/If Action pass_yaw' incorporates:
       *  ActionPort: '<S188>/Action Port'
       */
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_m, &GRM_HIL_B.Merge_mx);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action pass_yaw' */
      break;
    }

    /* End of If: '<S52>/If' */

    /* Abs: '<S52>/Abs2' */
    rtb_Abs_iw = rtb_ProportionalGain;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S52>/Abs3' incorporates:
       *  Constant: '<S52>/max_vel_pitch'
       */
      GRM_HIL_B.Abs3 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchMaxV);
    }

    /* If: '<S52>/If1' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_Abs_iw >= GRM_HIL_B.Abs3);
      GRM_HIL_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If1_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S52>/If Action limit_pitch' incorporates:
       *  ActionPort: '<S183>/Action Port'
       */
      /* Saturate: '<S183>/Limit_Voltage_Pitch' */
      if (GRM_HIL_B.Merge_l > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt)
      {
        GRM_HIL_B.Merge1_c = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_l <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt) {
        GRM_HIL_B.Merge1_c = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge1_c = GRM_HIL_B.Merge_l;
      }

      /* End of Saturate: '<S183>/Limit_Voltage_Pitch' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionlimit_pitch_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action limit_pitch' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S52>/If Action pass_pitch' incorporates:
       *  ActionPort: '<S186>/Action Port'
       */
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_l, &GRM_HIL_B.Merge1_c);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action pass_pitch' */
      break;
    }

    /* End of If: '<S52>/If1' */

    /* Abs: '<S52>/Abs4' */
    rtb_Abs_iw = rtb_ProportionalGain_n;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S52>/Abs5' incorporates:
       *  Constant: '<S52>/max_vel_roll'
       */
      GRM_HIL_B.Abs5 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollMaxV);
    }

    /* If: '<S52>/If2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_Abs_iw >= GRM_HIL_B.Abs5);
      GRM_HIL_DW.If2_ActiveSubsystem = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If2_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S52>/If Action limit_roll' incorporates:
       *  ActionPort: '<S184>/Action Port'
       */
      /* Saturate: '<S184>/Limit_Voltage_Roll' */
      if (GRM_HIL_B.Merge_lu > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt)
      {
        GRM_HIL_B.Merge2_d = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_lu <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt) {
        GRM_HIL_B.Merge2_d = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge2_d = GRM_HIL_B.Merge_lu;
      }

      /* End of Saturate: '<S184>/Limit_Voltage_Roll' */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionlimit_roll_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action limit_roll' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S52>/If Action pass_roll' incorporates:
       *  ActionPort: '<S187>/Action Port'
       */
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_lu, &GRM_HIL_B.Merge2_d);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_roll.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action pass_roll' */
      break;
    }

    /* End of If: '<S52>/If2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Voltage_Limitations_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Logic: '<S45>/Logical Operator' incorporates:
     *  Constant: '<S45>/Constant2'
     */
    GRM_HIL_B.LogicalOperator_by =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atOutput != 0.0);

    /* Outputs for Enabled SubSystem: '<S45>/If Action Pass' incorporates:
     *  EnablePort: '<S50>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.IfActionPass_MODE = GRM_HIL_B.LogicalOperator_by;
    }

    /* End of Outputs for SubSystem: '<S45>/If Action Pass' */
  }

  /* Outputs for Enabled SubSystem: '<S45>/If Action Pass' incorporates:
   *  EnablePort: '<S50>/Enable'
   */
  if (GRM_HIL_DW.IfActionPass_MODE) {
    /* Inport: '<S50>/yaw' */
    GRM_HIL_B.Merge_mx = GRM_HIL_B.Merge_m;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Inport: '<S50>/pitch' */
      GRM_HIL_B.Merge1_c = GRM_HIL_B.Merge_l;

      /* Inport: '<S50>/roll' */
      GRM_HIL_B.Merge2_d = GRM_HIL_B.Merge_lu;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionPass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S45>/If Action Pass' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S38>/Gain1' incorporates:
     *  Constant: '<S7>/Constant7'
     *  Gain: '<S44>/Gain'
     */
    rtb_Gain1_l = GRM_HIL_P.Gain_Gain_m2 * GRM_HIL_P.Constant7_Value_e *
      GRM_HIL_P.Gain1_Gain_cy;

    /* Gain: '<S38>/Gain2' incorporates:
     *  Constant: '<S7>/Constant8'
     *  Gain: '<S44>/Gain1'
     */
    rtb_Gain2_kf = GRM_HIL_P.Gain1_Gain_pi * GRM_HIL_P.Constant8_Value_lr *
      GRM_HIL_P.Gain2_Gain_o;

    /* S-Function (sldrtao): '<S38>/Analog Output   3 Motors Yaw Pitch Roll' */
    /* S-Function Block: <S38>/Analog Output   3 Motors Yaw Pitch Roll */
    {
      double aoval[3];
      double* aovalp = aoval;
      *aovalp++ = (double) GRM_HIL_B.Merge_mx;
      *aovalp++ = (double) GRM_HIL_B.Merge1_c;
      *aovalp++ = (double) GRM_HIL_B.Merge2_d;

      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_RangeMode;
        parm.rangeidx = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 3,
                       GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_Channels, aoval,
                       &parm);
      }
    }

    /* S-Function (sldrtdo): '<S38>/Digital Output' */
    /* S-Function Block: <S38>/Digital Output */
    {
      double doval[4];
      double* dovalp = doval;
      *dovalp++ = (double) rtb_Gain1_l;
      *dovalp++ = (double) rtb_Gain2_kf;
      *dovalp++ = (double) 0.0;
      *dovalp++ = (double) 0.0;
      RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 4,
                     GRM_HIL_P.DigitalOutput_Channels, doval,
                     &GRM_HIL_P.DigitalOutput_BitMode);
    }
  }

  /* Abs: '<S176>/Abs' */
  rtb_Abs_iw = rtb_PulseGenerator7;

  /* If: '<S176>/If' incorporates:
   *  Constant: '<S176>/Constant'
   *  Constant: '<S176>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_Abs_iw > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV);
    GRM_HIL_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S176>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_ey,
      &GRM_HIL_B.IfActionSubsystem1_f);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S176>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S176>/If Action Subsystem' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.yaw_deg, &GRM_HIL_B.IfActionSubsystem_d);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S176>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S176>/If' */

  /* Abs: '<S174>/Abs' */
  rtb_Abs_iw = rtb_ProportionalGain;

  /* If: '<S174>/If' incorporates:
   *  Constant: '<S174>/Constant'
   *  Constant: '<S174>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_Abs_iw >
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchMaxV);
    GRM_HIL_DW.If_ActiveSubsystem_h = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem_h;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_i4,
      &GRM_HIL_B.IfActionSubsystem1);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.pitch_deg, &GRM_HIL_B.IfActionSubsystem);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S174>/If' */

  /* Abs: '<S175>/Abs' */
  rtb_Abs_iw = rtb_ProportionalGain_n;

  /* If: '<S175>/If' incorporates:
   *  Constant: '<S175>/Constant'
   *  Constant: '<S175>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_Abs_iw > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollMaxV);
    GRM_HIL_DW.If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem_l;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_an,
      &GRM_HIL_B.IfActionSubsystem1_i);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S175>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.roll_deg, &GRM_HIL_B.IfActionSubsystem_k);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem_k.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S175>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S175>/If' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S54>/SumI1' incorporates:
     *  Gain: '<S54>/Integral Gain'
     *  Gain: '<S54>/Kb'
     *  Sum: '<S54>/SumI2'
     */
    GRM_HIL_B.SumI1 = (GRM_HIL_B.Merge_l - rtb_Sum_l) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Integral_Gain *
      GRM_HIL_B.pitch_err;

    /* Sum: '<S63>/SumI1' incorporates:
     *  Gain: '<S63>/Integral Gain'
     *  Gain: '<S63>/Kb'
     *  Sum: '<S63>/SumI2'
     */
    GRM_HIL_B.SumI1_b = (GRM_HIL_B.Merge_lu - rtb_Sum_n) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Integral_Gain *
      GRM_HIL_B.Roll_err;

    /* Sum: '<S73>/SumI1' incorporates:
     *  Gain: '<S73>/Integral Gain'
     *  Gain: '<S73>/Kb'
     *  Sum: '<S73>/SumI2'
     */
    GRM_HIL_B.SumI1_k = (GRM_HIL_B.Merge_b - rtb_Sum_e) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Yaw_Integral_Gain *
      GRM_HIL_B.Yaw_err;

    /* DataTypeConversion: '<S49>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     *  Logic: '<S49>/Logical Operator'
     *  Logic: '<S49>/Logical Operator1'
     *  Logic: '<S51>/Logical Operator'
     */
    GRM_HIL_B.DataTypeConversion = ((!(GRM_HIL_B.IfActionSubsystem1.In1 != 0.0))
      && (!(GRM_HIL_B.IfActionSubsystem1_i.In1 != 0.0)) &&
      (!(GRM_HIL_B.IfActionSubsystem1_f.In1 != 0.0)) &&
      GRM_HIL_P.Constant_Value_gt);

    /* Constant: '<S45>/Samp_Freq' */
    GRM_HIL_B.Samp_freq = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.SampFreq;

    /* Gain: '<S212>/Gain1' incorporates:
     *  Constant: '<S197>/Constant1'
     */
    rtb_VectorConcatenate_f[0] = GRM_HIL_P.Gain1_Gain_ps *
      GRM_HIL_P.Constant1_Value_lj;

    /* Gain: '<S213>/Gain1' incorporates:
     *  Constant: '<S197>/Constant2'
     */
    rtb_VectorConcatenate_f[1] = GRM_HIL_P.Gain1_Gain_n3 *
      GRM_HIL_P.Constant2_Value_ff;

    /* Gain: '<S214>/Gain1' incorporates:
     *  Constant: '<S197>/Constant3'
     */
    rtb_VectorConcatenate_f[2] = GRM_HIL_P.Gain1_Gain_g *
      GRM_HIL_P.Constant3_Value_i5;

    /* Product: '<S215>/Product' incorporates:
     *  Constant: '<S215>/Constant7'
     */
    for (i = 0; i < 4; i++) {
      GRM_HIL_B.siB_cmd[i] = 0.0;
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i] *
        rtb_VectorConcatenate_f[0];
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i + 4] *
        rtb_VectorConcatenate_f[1];
      GRM_HIL_B.siB_cmd[i] += GRM_HIL_P.Constant7_Value_aa[i + 8] *
        rtb_VectorConcatenate_f[2];
    }

    /* End of Product: '<S215>/Product' */

    /* Product: '<S360>/Product' incorporates:
     *  Constant: '<S360>/Constant'
     *  Constant: '<S360>/Constant6'
     */
    GRM_HIL_B.Product_a = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant6_Value_d5;
  }

  /* Sum: '<S197>/Sum' incorporates:
   *  SignalConversion generated from: '<S197>/Vector Concatenate'
   */
  rtb_Product4_n[0] = GRM_HIL_B.Fin_1_Pos_rad + GRM_HIL_B.siB_cmd[0];
  rtb_Product4_n[1] = GRM_HIL_B.Fin_2_Pos_rad + GRM_HIL_B.siB_cmd[1];
  rtb_Product4_n[2] = GRM_HIL_B.Fin_3_Pos_rad + GRM_HIL_B.siB_cmd[2];
  rtb_Divide1_h = GRM_HIL_B.Fin_4_Pos_rad + GRM_HIL_B.siB_cmd[3];

  /* Sum: '<S362>/Add' incorporates:
   *  Constant: '<S362>/Constant2'
   */
  rtb_Product7_ma = GRM_HIL_P.Constant2_Value_p - rtb_Product7_ma;

  /* Sum: '<S360>/Add4' incorporates:
   *  Constant: '<S360>/Constant3'
   *  Constant: '<S360>/Constant4'
   *  Product: '<S360>/Divide'
   *  Product: '<S360>/Product1'
   *  Sum: '<S360>/Add'
   */
  frac_0[0] = (rtb_Product7_ma * GRM_HIL_P.Constant4_Value_p +
               GRM_HIL_B.Product_a) * (1.0 / rtb_Subtract_e) +
    GRM_HIL_P.Constant3_Value_fn;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S360>/Product2' incorporates:
     *  Constant: '<S360>/Constant'
     *  Constant: '<S360>/Constant5'
     */
    GRM_HIL_B.Product2 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant5_Value_e;

    /* Product: '<S360>/Product4' incorporates:
     *  Constant: '<S360>/Constant'
     *  Constant: '<S360>/Constant8'
     */
    GRM_HIL_B.Product4 = GRM_HIL_P.Constant_Value_l1 *
      GRM_HIL_P.Constant8_Value_l5;
  }

  /* Sum: '<S360>/Add3' incorporates:
   *  Constant: '<S360>/Constant1'
   *  Constant: '<S360>/Constant7'
   *  Product: '<S360>/Divide1'
   *  Product: '<S360>/Product3'
   *  Sum: '<S360>/Add1'
   */
  frac_0[1] = (rtb_Product7_ma * GRM_HIL_P.Constant7_Value_jc +
               GRM_HIL_B.Product2) * (1.0 / rtb_Subtract_e) +
    GRM_HIL_P.Constant1_Value_in;

  /* Sum: '<S360>/Add5' incorporates:
   *  Constant: '<S360>/Constant2'
   *  Constant: '<S360>/Constant9'
   *  Product: '<S360>/Divide2'
   *  Product: '<S360>/Product5'
   *  Sum: '<S360>/Add2'
   */
  frac_0[2] = (rtb_Product7_ma * GRM_HIL_P.Constant9_Value_c +
               GRM_HIL_B.Product4) * (1.0 / rtb_Subtract_e) +
    GRM_HIL_P.Constant2_Value_mg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S226>/Vector Concatenate' incorporates:
     *  Constant: '<S226>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[0] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S226>/Vector Concatenate' incorporates:
     *  Constant: '<S226>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[1] = GRM_HIL_P.Constant3_Value_m;

    /* SignalConversion generated from: '<S226>/Vector Concatenate' incorporates:
     *  Constant: '<S226>/Constant3'
     */
    GRM_HIL_B.VectorConcatenate_e[2] = GRM_HIL_P.Constant3_Value_m;

    /* Switch: '<S231>/Switch1' incorporates:
     *  Constant: '<S231>/Constant'
     *  Constant: '<S231>/Constant2'
     *  Constant: '<S232>/c_flat'
     *  Constant: '<S232>/c_rsma'
     *  Constant: '<S233>/Constant'
     *  Gain: '<S231>/Gain'
     *  Gain: '<S233>/Gain'
     *  Product: '<S233>/Product'
     *  Product: '<S233>/Product4'
     *  Product: '<S233>/Product5'
     *  Sqrt: '<S233>/Sqrt1'
     *  Sum: '<S233>/Subtract'
     *  Sum: '<S233>/Subtract1'
     *  Sum: '<S233>/Sum'
     *  Trigonometry: '<S233>/cos(latGD)'
     */
    if (GRM_HIL_P.Constant2_Value_ad > GRM_HIL_P.Switch1_Threshold_n) {
      GRM_HIL_B.hBE_0_h = GRM_HIL_P.Gain_Gain_f * GRM_HIL_P.Constant_Value_iee[2];
    } else {
      /* Sqrt: '<S234>/Sqrt' incorporates:
       *  Constant: '<S231>/Constant'
       *  Product: '<S234>/Product1'
       *  Product: '<S234>/Product2'
       *  Sqrt: '<S233>/Sqrt'
       *  Sum: '<S234>/Add'
       */
      rtb_ProportionalGain_d = sqrt(GRM_HIL_P.Constant_Value_iee[0] *
        GRM_HIL_P.Constant_Value_iee[0] + GRM_HIL_P.Constant_Value_iee[1] *
        GRM_HIL_P.Constant_Value_iee[1]);

      /* Product: '<S234>/Product' incorporates:
       *  Constant: '<S232>/c_flat'
       *  Constant: '<S232>/c_rsma'
       *  Constant: '<S234>/Constant'
       *  Sum: '<S234>/Subtract'
       */
      rtb_DerivativeGain_oe = (GRM_HIL_P.Constant_Value_f -
        GRM_HIL_P.c_flat_Value_f) * GRM_HIL_P.c_rsma_Value_b;

      /* Trigonometry: '<S234>/Trigonometric Function' incorporates:
       *  Constant: '<S231>/Constant'
       *  Constant: '<S232>/c_rsma'
       *  Product: '<S234>/Divide1'
       *  Product: '<S234>/Product6'
       *  Product: '<S234>/Product7'
       *  Sqrt: '<S234>/Sqrt'
       */
      rtb_ProportionalGain_n = atan(GRM_HIL_P.Constant_Value_iee[2] *
        GRM_HIL_P.c_rsma_Value_b / (rtb_ProportionalGain_d *
        rtb_DerivativeGain_oe));

      /* Trigonometry: '<S234>/Trigonometric Function3' */
      rtb_DerivativeGain_h = cos(rtb_ProportionalGain_n);

      /* Product: '<S234>/Product9' */
      rtb_ProportionalGain = rtb_DerivativeGain_h * rtb_DerivativeGain_h *
        rtb_DerivativeGain_h;

      /* Trigonometry: '<S234>/Trigonometric Function2' */
      rtb_ProportionalGain_n = sin(rtb_ProportionalGain_n);

      /* Product: '<S234>/Product5' */
      rtb_DerivativeGain_h = rtb_DerivativeGain_oe * rtb_DerivativeGain_oe;

      /* Product: '<S234>/Product10' incorporates:
       *  Constant: '<S232>/c_rsma'
       *  Product: '<S234>/Divide'
       *  Product: '<S234>/Product4'
       *  Product: '<S234>/Product8'
       *  Sum: '<S234>/Subtract2'
       */
      rtb_DerivativeGain_oe = (GRM_HIL_P.c_rsma_Value_b *
        GRM_HIL_P.c_rsma_Value_b - rtb_DerivativeGain_h) / rtb_DerivativeGain_h *
        rtb_DerivativeGain_oe * (rtb_ProportionalGain_n * rtb_ProportionalGain_n
        * rtb_ProportionalGain_n);

      /* Sum: '<S234>/Add1' incorporates:
       *  Constant: '<S231>/Constant'
       */
      rtb_DerivativeGain_oe += GRM_HIL_P.Constant_Value_iee[2];

      /* Product: '<S234>/Product3' incorporates:
       *  Constant: '<S232>/c_flat'
       *  Product: '<S233>/Product3'
       */
      rtb_DerivativeGain = GRM_HIL_P.c_flat_Value_f * GRM_HIL_P.c_flat_Value_f;

      /* Trigonometry: '<S234>/Trigonometric Function1' incorporates:
       *  Constant: '<S232>/c_flat'
       *  Constant: '<S232>/c_rsma'
       *  Gain: '<S234>/Gain'
       *  Product: '<S234>/Divide2'
       *  Product: '<S234>/Product11'
       *  Product: '<S234>/Product3'
       *  Sqrt: '<S234>/Sqrt'
       *  Sum: '<S234>/Subtract1'
       *  Sum: '<S234>/Subtract3'
       */
      rtb_DerivativeGain_h = atan(rtb_DerivativeGain_oe /
        (rtb_ProportionalGain_d - (GRM_HIL_P.Gain_Gain_o *
        GRM_HIL_P.c_flat_Value_f - rtb_DerivativeGain) *
         GRM_HIL_P.c_rsma_Value_b * rtb_ProportionalGain));

      /* Trigonometry: '<S233>/Trigonometric Function' */
      rtb_ProportionalGain_n = sin(rtb_DerivativeGain_h);
      GRM_HIL_B.hBE_0_h = rtb_ProportionalGain_d / cos(rtb_DerivativeGain_h) -
        GRM_HIL_P.c_rsma_Value_b / sqrt(GRM_HIL_P.Constant_Value_m -
        (GRM_HIL_P.Gain_Gain_a * GRM_HIL_P.c_flat_Value_f - rtb_DerivativeGain) *
        (rtb_ProportionalGain_n * rtb_ProportionalGain_n));
    }

    /* End of Switch: '<S231>/Switch1' */
  }

  /* Switch: '<S226>/Switch' incorporates:
   *  Constant: '<S219>/Constant1'
   *  Constant: '<S226>/Constant1'
   *  Constant: '<S235>/Constant'
   *  Product: '<S219>/Product1'
   *  Product: '<S235>/Product'
   *  Sum: '<S218>/Add3'
   *  Sum: '<S219>/Add'
   *  Sum: '<S226>/Subtract'
   */
  if ((GRM_HIL_B.Switch[2] + GRM_HIL_P.Constant1_Value_p) - GRM_HIL_B.hBE_0_h >
      GRM_HIL_P.Switch_Threshold_j0) {
    /* Interpolation_n-D: '<S237>/Cn_delta_n_Interpolation' */
    frac_n[0] = rtb_lat;
    frac_n[1] = rtb_Sqrt_j;
    frac_n[2] = rtb_f_beB;
    bpIndex_n[0] = rtb_k_Mach;
    bpIndex_n[1] = rtb_k_alB;
    bpIndex_n[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_n, frac_n,
      GRM_HIL_P.Cn_delta_n_Interpolation_Table,
      GRM_HIL_P.Cn_delta_n_Interpolation_dimSize);

    /* Product: '<S218>/Product33' */
    rtb_DerivativeGain_oe = rtb_Gain_n * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S237>/Cn_delta_m_Interpolation' */
    frac_o[0] = rtb_lat;
    frac_o[1] = rtb_Sqrt_j;
    frac_o[2] = rtb_f_beB;
    bpIndex_o[0] = rtb_k_Mach;
    bpIndex_o[1] = rtb_k_alB;
    bpIndex_o[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_o, frac_o,
      GRM_HIL_P.Cn_delta_m_Interpolation_Table,
      GRM_HIL_P.Cn_delta_m_Interpolation_dimSize);

    /* Product: '<S218>/Product32' */
    rtb_ProportionalGain_n = rtb_Gain_nk * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S237>/Cn_delta_l_Interpolation' */
    frac_p[0] = rtb_lat;
    frac_p[1] = rtb_Sqrt_j;
    frac_p[2] = rtb_f_beB;
    bpIndex_p[0] = rtb_k_Mach;
    bpIndex_p[1] = rtb_k_alB;
    bpIndex_p[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_p, frac_p,
      GRM_HIL_P.Cn_delta_l_Interpolation_Table,
      GRM_HIL_P.Cn_delta_l_Interpolation_dimSize);

    /* Product: '<S218>/Product31' */
    rtb_DerivativeGain_h = rtb_Gain_fl * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S237>/Cnr_Interpolation' */
    frac_q[0] = rtb_lat;
    frac_q[1] = rtb_Sqrt_j;
    frac_q[2] = rtb_f_beB;
    bpIndex_q[0] = rtb_k_Mach;
    bpIndex_q[1] = rtb_k_alB;
    bpIndex_q[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_q, frac_q,
      GRM_HIL_P.Cnr_Interpolation_Table, GRM_HIL_P.Cnr_Interpolation_dimSize);

    /* Product: '<S218>/Product36' */
    rtb_ProportionalGain = rtb_Gain_af * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S237>/Cnq_Interpolation' */
    frac_r[0] = rtb_lat;
    frac_r[1] = rtb_Sqrt_j;
    frac_r[2] = rtb_f_beB;
    bpIndex_r[0] = rtb_k_Mach;
    bpIndex_r[1] = rtb_k_alB;
    bpIndex_r[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_r, frac_r,
      GRM_HIL_P.Cnq_Interpolation_Table, GRM_HIL_P.Cnq_Interpolation_dimSize);

    /* Product: '<S218>/Product35' */
    rtb_DerivativeGain = rtb_Gain_lt * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S237>/Cnp_Interpolation' */
    frac_s[0] = rtb_lat;
    frac_s[1] = rtb_Sqrt_j;
    frac_s[2] = rtb_f_beB;
    bpIndex_s[0] = rtb_k_Mach;
    bpIndex_s[1] = rtb_k_alB;
    bpIndex_s[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_s, frac_s,
      GRM_HIL_P.Cnp_Interpolation_Table, GRM_HIL_P.Cnp_Interpolation_dimSize);

    /* Product: '<S218>/Product34' */
    rtb_PulseGenerator1 = rtb_Gain_g * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S237>/Cn_Interpolation' */
    frac_t[0] = rtb_lat;
    frac_t[1] = rtb_Sqrt_j;
    frac_t[2] = rtb_f_beB;
    bpIndex_t[0] = rtb_k_Mach;
    bpIndex_t[1] = rtb_k_alB;
    bpIndex_t[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_t, frac_t,
      GRM_HIL_P.Cn_Interpolation_Table, GRM_HIL_P.Cn_Interpolation_dimSize);

    /* Sum: '<S218>/Add5' incorporates:
     *  Constant: '<S237>/Constant'
     *  Product: '<S237>/Product'
     */
    frac[2] = (((((GRM_HIL_P.Constant_Value_ml * rtb_ProportionalGain_d +
                   rtb_PulseGenerator1) + rtb_DerivativeGain) +
                 rtb_ProportionalGain) + rtb_DerivativeGain_h) +
               rtb_ProportionalGain_n) + rtb_DerivativeGain_oe;

    /* Interpolation_n-D: '<S236>/Cm_delta_n_Interpolation' */
    frac_u[0] = rtb_lat;
    frac_u[1] = rtb_Sqrt_j;
    frac_u[2] = rtb_f_beB;
    bpIndex_u[0] = rtb_k_Mach;
    bpIndex_u[1] = rtb_k_alB;
    bpIndex_u[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_u, frac_u,
      GRM_HIL_P.Cm_delta_n_Interpolation_Table,
      GRM_HIL_P.Cm_delta_n_Interpolation_dimSize);

    /* Product: '<S218>/Product27' */
    rtb_DerivativeGain_oe = rtb_Gain_n * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S236>/Cm_delta_m_Interpolation' */
    frac_v[0] = rtb_lat;
    frac_v[1] = rtb_Sqrt_j;
    frac_v[2] = rtb_f_beB;
    bpIndex_v[0] = rtb_k_Mach;
    bpIndex_v[1] = rtb_k_alB;
    bpIndex_v[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_v, frac_v,
      GRM_HIL_P.Cm_delta_m_Interpolation_Table,
      GRM_HIL_P.Cm_delta_m_Interpolation_dimSize);

    /* Product: '<S218>/Product26' */
    rtb_ProportionalGain_n = rtb_Gain_nk * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S236>/Cm_delta_l_Interpolation' */
    frac_w[0] = rtb_lat;
    frac_w[1] = rtb_Sqrt_j;
    frac_w[2] = rtb_f_beB;
    bpIndex_w[0] = rtb_k_Mach;
    bpIndex_w[1] = rtb_k_alB;
    bpIndex_w[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_w, frac_w,
      GRM_HIL_P.Cm_delta_l_Interpolation_Table,
      GRM_HIL_P.Cm_delta_l_Interpolation_dimSize);

    /* Product: '<S218>/Product25' */
    rtb_DerivativeGain_h = rtb_Gain_fl * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S236>/Cmr_Interpolation' */
    frac_x[0] = rtb_lat;
    frac_x[1] = rtb_Sqrt_j;
    frac_x[2] = rtb_f_beB;
    bpIndex_x[0] = rtb_k_Mach;
    bpIndex_x[1] = rtb_k_alB;
    bpIndex_x[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_x, frac_x,
      GRM_HIL_P.Cmr_Interpolation_Table, GRM_HIL_P.Cmr_Interpolation_dimSize);

    /* Product: '<S218>/Product30' */
    rtb_ProportionalGain = rtb_Gain_af * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S236>/Cmq_Interpolation' */
    frac_y[0] = rtb_lat;
    frac_y[1] = rtb_Sqrt_j;
    frac_y[2] = rtb_f_beB;
    bpIndex_y[0] = rtb_k_Mach;
    bpIndex_y[1] = rtb_k_alB;
    bpIndex_y[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_y, frac_y,
      GRM_HIL_P.Cmq_Interpolation_Table, GRM_HIL_P.Cmq_Interpolation_dimSize);

    /* Product: '<S218>/Product29' */
    rtb_DerivativeGain = rtb_Gain_lt * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S236>/Cmp_Interpolation' */
    frac_z[0] = rtb_lat;
    frac_z[1] = rtb_Sqrt_j;
    frac_z[2] = rtb_f_beB;
    bpIndex_z[0] = rtb_k_Mach;
    bpIndex_z[1] = rtb_k_alB;
    bpIndex_z[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_z, frac_z,
      GRM_HIL_P.Cmp_Interpolation_Table, GRM_HIL_P.Cmp_Interpolation_dimSize);

    /* Product: '<S218>/Product28' */
    rtb_PulseGenerator1 = rtb_Gain_g * rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S236>/Cm_Interpolation' */
    frac_10[0] = rtb_lat;
    frac_10[1] = rtb_Sqrt_j;
    frac_10[2] = rtb_f_beB;
    bpIndex_10[0] = rtb_k_Mach;
    bpIndex_10[1] = rtb_k_alB;
    bpIndex_10[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_10, frac_10,
      GRM_HIL_P.Cm_Interpolation_Table, GRM_HIL_P.Cm_Interpolation_dimSize);

    /* Sum: '<S218>/Add4' incorporates:
     *  Constant: '<S236>/Constant'
     *  Product: '<S236>/Product'
     */
    frac[1] = (((((GRM_HIL_P.Constant_Value_jm * rtb_ProportionalGain_d +
                   rtb_PulseGenerator1) + rtb_DerivativeGain) +
                 rtb_ProportionalGain) + rtb_DerivativeGain_h) +
               rtb_ProportionalGain_n) + rtb_DerivativeGain_oe;

    /* Interpolation_n-D: '<S235>/Cl_delta_n_Interpolation' */
    frac_11[0] = rtb_lat;
    frac_11[1] = rtb_Sqrt_j;
    frac_11[2] = rtb_f_beB;
    bpIndex_11[0] = rtb_k_Mach;
    bpIndex_11[1] = rtb_k_alB;
    bpIndex_11[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_11, frac_11,
      GRM_HIL_P.Cl_delta_n_Interpolation_Table,
      GRM_HIL_P.Cl_delta_n_Interpolation_dimSize);

    /* Product: '<S218>/Product21' */
    rtb_Gain_n *= rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S235>/Cl_delta_m_Interpolation' */
    frac_12[0] = rtb_lat;
    frac_12[1] = rtb_Sqrt_j;
    frac_12[2] = rtb_f_beB;
    bpIndex_12[0] = rtb_k_Mach;
    bpIndex_12[1] = rtb_k_alB;
    bpIndex_12[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_12, frac_12,
      GRM_HIL_P.Cl_delta_m_Interpolation_Table,
      GRM_HIL_P.Cl_delta_m_Interpolation_dimSize);

    /* Product: '<S218>/Product20' */
    rtb_Gain_nk *= rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S235>/Cl_delta_l_Interpolation' */
    frac_13[0] = rtb_lat;
    frac_13[1] = rtb_Sqrt_j;
    frac_13[2] = rtb_f_beB;
    bpIndex_13[0] = rtb_k_Mach;
    bpIndex_13[1] = rtb_k_alB;
    bpIndex_13[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_13, frac_13,
      GRM_HIL_P.Cl_delta_l_Interpolation_Table,
      GRM_HIL_P.Cl_delta_l_Interpolation_dimSize);

    /* Product: '<S218>/Product19' */
    rtb_Gain_fl *= rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S235>/Clr_Interpolation' */
    frac_14[0] = rtb_lat;
    frac_14[1] = rtb_Sqrt_j;
    frac_14[2] = rtb_f_beB;
    bpIndex_14[0] = rtb_k_Mach;
    bpIndex_14[1] = rtb_k_alB;
    bpIndex_14[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_14, frac_14,
      GRM_HIL_P.Clr_Interpolation_Table, GRM_HIL_P.Clr_Interpolation_dimSize);

    /* Product: '<S218>/Product24' */
    rtb_Gain_af *= rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S235>/Clq_Interpolation' */
    frac_15[0] = rtb_lat;
    frac_15[1] = rtb_Sqrt_j;
    frac_15[2] = rtb_f_beB;
    bpIndex_15[0] = rtb_k_Mach;
    bpIndex_15[1] = rtb_k_alB;
    bpIndex_15[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_15, frac_15,
      GRM_HIL_P.Clq_Interpolation_Table, GRM_HIL_P.Clq_Interpolation_dimSize);

    /* Product: '<S218>/Product23' */
    rtb_Gain_lt *= rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S235>/Clp_Interpolation' */
    frac_16[0] = rtb_lat;
    frac_16[1] = rtb_Sqrt_j;
    frac_16[2] = rtb_f_beB;
    bpIndex_16[0] = rtb_k_Mach;
    bpIndex_16[1] = rtb_k_alB;
    bpIndex_16[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_16, frac_16,
      GRM_HIL_P.Clp_Interpolation_Table, GRM_HIL_P.Clp_Interpolation_dimSize);

    /* Product: '<S218>/Product22' */
    rtb_Gain_g *= rtb_ProportionalGain_d;

    /* Interpolation_n-D: '<S235>/Cl_Interpolation' */
    frac_17[0] = rtb_lat;
    frac_17[1] = rtb_Sqrt_j;
    frac_17[2] = rtb_f_beB;
    bpIndex_17[0] = rtb_k_Mach;
    bpIndex_17[1] = rtb_k_alB;
    bpIndex_17[2] = rtb_k_beB;
    rtb_ProportionalGain_d = intrp3d_l_pw(bpIndex_17, frac_17,
      GRM_HIL_P.Cl_Interpolation_Table, GRM_HIL_P.Cl_Interpolation_dimSize);

    /* Product: '<S219>/Product1' incorporates:
     *  Constant: '<S219>/Constant1'
     */
    rtb_Product1_m[1] = rtb_siB_c5 * frac[1] * GRM_HIL_P.Constant1_Value_bk;
    rtb_Product1_m[2] = rtb_siB_c5 * frac[2] * GRM_HIL_P.Constant1_Value_bk;

    /* Sum: '<S224>/Sum2' incorporates:
     *  Product: '<S224>/Product6'
     *  Product: '<S224>/Product7'
     */
    frac[2] = frac_0[0] * rtb_vBEB_a[1] - frac_0[1] * rtb_vBEB_a[0];

    /* Sum: '<S224>/Sum1' incorporates:
     *  Product: '<S224>/Product4'
     *  Product: '<S224>/Product5'
     */
    frac[1] = frac_0[2] * rtb_vBEB_a[0] - frac_0[0] * rtb_vBEB_a[2];

    /* Sum: '<S224>/Sum' incorporates:
     *  Product: '<S224>/Product2'
     *  Product: '<S224>/Product3'
     */
    frac[0] = frac_0[1] * rtb_vBEB_a[2] - frac_0[2] * rtb_vBEB_a[1];
    frac[0] += ((((((GRM_HIL_P.Constant_Value_e0 * rtb_ProportionalGain_d +
                     rtb_Gain_g) + rtb_Gain_lt) + rtb_Gain_af) + rtb_Gain_fl) +
                 rtb_Gain_nk) + rtb_Gain_n) * rtb_siB_c5 *
      GRM_HIL_P.Constant1_Value_bk;
    frac[1] += rtb_Product1_m[1];
    frac[2] += rtb_Product1_m[2];
  } else {
    frac[0] = GRM_HIL_B.VectorConcatenate_e[0];
    frac[1] = GRM_HIL_B.VectorConcatenate_e[1];
    frac[2] = GRM_HIL_B.VectorConcatenate_e[2];
  }

  /* End of Switch: '<S226>/Switch' */

  /* RelationalOperator: '<S258>/Compare' incorporates:
   *  Constant: '<S258>/Constant'
   */
  GRM_HIL_B.Compare_k = (rtb_Product6_n4 >= GRM_HIL_P.CompareToConstant_const_i);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S255>/Assertion' */
    utAssert(GRM_HIL_B.Compare_k);
  }

  /* Logic: '<S259>/AND' incorporates:
   *  Constant: '<S259>/Lower Limit'
   *  Constant: '<S259>/Upper Limit'
   *  RelationalOperator: '<S259>/Lower Test'
   *  RelationalOperator: '<S259>/Upper Test'
   */
  GRM_HIL_B.AND = ((GRM_HIL_P.IntervalTest_lowlimit <= GRM_HIL_B.Switch[0]) &&
                   (GRM_HIL_B.Switch[0] <= GRM_HIL_P.IntervalTest_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S255>/Assertion1' */
    utAssert(GRM_HIL_B.AND);
  }

  /* Logic: '<S260>/AND' incorporates:
   *  Constant: '<S260>/Lower Limit'
   *  Constant: '<S260>/Upper Limit'
   *  RelationalOperator: '<S260>/Lower Test'
   *  RelationalOperator: '<S260>/Upper Test'
   */
  GRM_HIL_B.AND_i = ((GRM_HIL_P.IntervalTest1_lowlimit <= GRM_HIL_B.Switch[1]) &&
                     (GRM_HIL_B.Switch[1] <= GRM_HIL_P.IntervalTest1_uplimit));
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Assertion: '<S255>/Assertion2' */
    utAssert(GRM_HIL_B.AND_i);
  }

  /* Integrator: '<S271>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE,
                       (GRM_HIL_B.sat));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_h = GRM_HIL_P.Rudder_d_siB_0;
    }
  }

  rtb_d_siB = GRM_HIL_X.Integrator_CSTATE_h;

  /* End of Integrator: '<S271>/Integrator' */

  /* MATLAB Function: '<S271>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB, rtb_d_siB, &GRM_HIL_B.sf_Limiting_Rate,
                        GRM_HIL_P.Rudder_d_siB_max, GRM_HIL_P.Rudder_d_siB_min,
                        GRM_HIL_P.Rudder_siB_max, GRM_HIL_P.Rudder_siB_min);

  /* Integrator: '<S272>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h,
                       (GRM_HIL_B.sat_c));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Rudder1_d_siB_0;
    }
  }

  rtb_d_siB_l = GRM_HIL_X.Integrator_CSTATE_e;

  /* End of Integrator: '<S272>/Integrator' */

  /* MATLAB Function: '<S272>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_d, rtb_d_siB_l, &GRM_HIL_B.sf_Limiting_Rate_o,
                        GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
                        GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Integrator: '<S273>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k,
                       (GRM_HIL_B.sat_a));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;
    }
  }

  rtb_d_siB_f = GRM_HIL_X.Integrator_CSTATE_f;

  /* End of Integrator: '<S273>/Integrator' */

  /* MATLAB Function: '<S273>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_i, rtb_d_siB_f, &GRM_HIL_B.sf_Limiting_Rate_g,
                        GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
                        GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Integrator: '<S274>/Integrator' */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n,
                       (GRM_HIL_B.sat_o));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Rudder3_d_siB_0;
    }
  }

  rtb_d_siB_k = GRM_HIL_X.Integrator_CSTATE_g;

  /* End of Integrator: '<S274>/Integrator' */

  /* MATLAB Function: '<S274>/Limiting_Rate' */
  GRM_HIL_Limiting_Rate(rtb_siB_o, rtb_d_siB_k, &GRM_HIL_B.sf_Limiting_Rate_d,
                        GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
                        GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Saturate: '<S271>/Saturation' */
  if (rtb_Product4_n[0] > GRM_HIL_P.Rudder_siB_max) {
    rtb_ProportionalGain_d = GRM_HIL_P.Rudder_siB_max;
  } else if (rtb_Product4_n[0] < GRM_HIL_P.Rudder_siB_min) {
    rtb_ProportionalGain_d = GRM_HIL_P.Rudder_siB_min;
  } else {
    rtb_ProportionalGain_d = rtb_Product4_n[0];
  }

  /* End of Saturate: '<S271>/Saturation' */

  /* Sum: '<S271>/Add1' incorporates:
   *  Gain: '<S271>/Gain'
   *  Gain: '<S271>/Gain2'
   *  Integrator: '<S271>/Integrator1'
   *  Sum: '<S271>/Add'
   */
  rtb_dd_siB = (rtb_ProportionalGain_d - GRM_HIL_X.Integrator1_CSTATE) *
    GRM_HIL_P.Gain_Gain_oz - 2.0 * GRM_HIL_P.Rudder_dmp * GRM_HIL_P.Rudder_omega
    * rtb_d_siB;

  /* MATLAB Function: '<S271>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB, GRM_HIL_B.sf_Limiting_Rate.d_siB_l,
    rtb_dd_siB, &GRM_HIL_B.sf_Limiting_Acceleration, GRM_HIL_P.Rudder_d_siB_max,
    GRM_HIL_P.Rudder_d_siB_min, GRM_HIL_P.Rudder_dd_siB_max,
    GRM_HIL_P.Rudder_dd_siB_min, GRM_HIL_P.Rudder_siB_max,
    GRM_HIL_P.Rudder_siB_min);

  /* Saturate: '<S272>/Saturation' */
  if (rtb_Product4_n[1] > GRM_HIL_P.Rudder1_siB_max) {
    rtb_ProportionalGain_d = GRM_HIL_P.Rudder1_siB_max;
  } else if (rtb_Product4_n[1] < GRM_HIL_P.Rudder1_siB_min) {
    rtb_ProportionalGain_d = GRM_HIL_P.Rudder1_siB_min;
  } else {
    rtb_ProportionalGain_d = rtb_Product4_n[1];
  }

  /* End of Saturate: '<S272>/Saturation' */

  /* Sum: '<S272>/Add1' incorporates:
   *  Gain: '<S272>/Gain'
   *  Gain: '<S272>/Gain2'
   *  Integrator: '<S272>/Integrator1'
   *  Sum: '<S272>/Add'
   */
  rtb_dd_siB_c = (rtb_ProportionalGain_d - GRM_HIL_X.Integrator1_CSTATE_g) *
    GRM_HIL_P.Gain_Gain_a3 - 2.0 * GRM_HIL_P.Rudder1_dmp *
    GRM_HIL_P.Rudder1_omega * rtb_d_siB_l;

  /* MATLAB Function: '<S272>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_d, GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l,
    rtb_dd_siB_c, &GRM_HIL_B.sf_Limiting_Acceleration_i,
    GRM_HIL_P.Rudder1_d_siB_max, GRM_HIL_P.Rudder1_d_siB_min,
    GRM_HIL_P.Rudder1_dd_siB_max, GRM_HIL_P.Rudder1_dd_siB_min,
    GRM_HIL_P.Rudder1_siB_max, GRM_HIL_P.Rudder1_siB_min);

  /* Saturate: '<S273>/Saturation' */
  if (rtb_Product4_n[2] > GRM_HIL_P.Rudder2_siB_max) {
    rtb_ProportionalGain_d = GRM_HIL_P.Rudder2_siB_max;
  } else if (rtb_Product4_n[2] < GRM_HIL_P.Rudder2_siB_min) {
    rtb_ProportionalGain_d = GRM_HIL_P.Rudder2_siB_min;
  } else {
    rtb_ProportionalGain_d = rtb_Product4_n[2];
  }

  /* End of Saturate: '<S273>/Saturation' */

  /* Sum: '<S273>/Add1' incorporates:
   *  Gain: '<S273>/Gain'
   *  Gain: '<S273>/Gain2'
   *  Integrator: '<S273>/Integrator1'
   *  Sum: '<S273>/Add'
   */
  rtb_dd_siB_o = (rtb_ProportionalGain_d - GRM_HIL_X.Integrator1_CSTATE_a) *
    GRM_HIL_P.Gain_Gain_hm - 2.0 * GRM_HIL_P.Rudder2_dmp *
    GRM_HIL_P.Rudder2_omega * rtb_d_siB_f;

  /* MATLAB Function: '<S273>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_i, GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l,
    rtb_dd_siB_o, &GRM_HIL_B.sf_Limiting_Acceleration_p,
    GRM_HIL_P.Rudder2_d_siB_max, GRM_HIL_P.Rudder2_d_siB_min,
    GRM_HIL_P.Rudder2_dd_siB_max, GRM_HIL_P.Rudder2_dd_siB_min,
    GRM_HIL_P.Rudder2_siB_max, GRM_HIL_P.Rudder2_siB_min);

  /* Saturate: '<S274>/Saturation' */
  if (rtb_Divide1_h > GRM_HIL_P.Rudder3_siB_max) {
    rtb_Divide1_h = GRM_HIL_P.Rudder3_siB_max;
  } else {
    if (rtb_Divide1_h < GRM_HIL_P.Rudder3_siB_min) {
      rtb_Divide1_h = GRM_HIL_P.Rudder3_siB_min;
    }
  }

  /* End of Saturate: '<S274>/Saturation' */

  /* Sum: '<S274>/Add1' incorporates:
   *  Gain: '<S274>/Gain'
   *  Gain: '<S274>/Gain2'
   *  Integrator: '<S274>/Integrator1'
   *  Sum: '<S274>/Add'
   */
  rtb_dd_siB_od = (rtb_Divide1_h - GRM_HIL_X.Integrator1_CSTATE_i) *
    GRM_HIL_P.Gain_Gain_d - 2.0 * GRM_HIL_P.Rudder3_dmp *
    GRM_HIL_P.Rudder3_omega * rtb_d_siB_k;

  /* MATLAB Function: '<S274>/Limiting_Acceleration' */
  GRM_HIL_Limiting_Acceleration(rtb_siB_o, GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l,
    rtb_dd_siB_od, &GRM_HIL_B.sf_Limiting_Acceleration_h,
    GRM_HIL_P.Rudder3_d_siB_max, GRM_HIL_P.Rudder3_d_siB_min,
    GRM_HIL_P.Rudder3_dd_siB_max, GRM_HIL_P.Rudder3_dd_siB_min,
    GRM_HIL_P.Rudder3_siB_max, GRM_HIL_P.Rudder3_siB_min);

  /* Sum: '<S315>/Subtract' incorporates:
   *  Constant: '<S315>/pNPB'
   */
  rtb_Product1_m[0] = frac_0[0] - GRM_HIL_P.pNPB_Value[0];
  rtb_Product1_m[1] = frac_0[1] - GRM_HIL_P.pNPB_Value[1];
  rtb_Product1_m[2] = frac_0[2] - GRM_HIL_P.pNPB_Value[2];

  /* Sum: '<S201>/Add1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Product: '<S317>/Product2'
   *  Product: '<S317>/Product3'
   *  Product: '<S317>/Product4'
   *  Product: '<S317>/Product5'
   *  Product: '<S317>/Product6'
   *  Product: '<S317>/Product7'
   *  Sum: '<S317>/Sum'
   *  Sum: '<S317>/Sum1'
   *  Sum: '<S317>/Sum2'
   */
  frac[0] = ((rtb_Product1_m[1] * rtb_pBEE[2] - rtb_Product1_m[2] * rtb_pBEE[1])
             + frac[0]) + rtb_Gain1_c;
  frac[1] = ((rtb_Product1_m[2] * rtb_pBEE[0] - rtb_Product1_m[0] * rtb_pBEE[2])
             + frac[1]) + GRM_HIL_P.Constant_Value_ko;
  frac[2] = ((rtb_Product1_m[0] * rtb_pBEE[1] - rtb_Product1_m[1] * rtb_pBEE[0])
             + frac[2]) + GRM_HIL_P.Constant_Value_ko;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S291>/Gain' */
    rtb_VectorConcatenate_f[0] = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[0];
    rtb_VectorConcatenate_f[1] = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[1];
    rtb_VectorConcatenate_f[2] = GRM_HIL_P.Gain_Gain_jo * GRM_HIL_B.wIEE[2];

    /* Sum: '<S306>/Add' incorporates:
     *  Constant: '<S306>/Constant8'
     *  Constant: '<S306>/Q_1'
     *  Constant: '<S306>/Q_2'
     *  Constant: '<S306>/Q_3'
     *  Constant: '<S306>/Q_4'
     *  Product: '<S306>/Product1'
     *  Product: '<S306>/Product2'
     *  Product: '<S306>/Product3'
     *  Product: '<S306>/Product4'
     *  SignalConversion generated from: '<S306>/Vector Concatenate'
     */
    for (i = 0; i < 16; i++) {
      GRM_HIL_B.Add_f[i] = ((GRM_HIL_P.Q_1_Value_o[i] * rtb_VectorConcatenate_f
        [0] + GRM_HIL_P.Q_2_Value_b[i] * rtb_VectorConcatenate_f[1]) +
                            GRM_HIL_P.Q_3_Value_j[i] * rtb_VectorConcatenate_f[2])
        + GRM_HIL_P.Q_4_Value_d[i] * GRM_HIL_P.Constant8_Value_h;
    }

    /* End of Sum: '<S306>/Add' */
  }

  /* Gain: '<S308>/Gain1' incorporates:
   *  Integrator: '<S303>/integration_eom'
   */
  rtb_d_qGE[0] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[0];
  rtb_d_qGE[1] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[1];
  rtb_d_qGE[2] = GRM_HIL_P.Gain1_Gain_c5 * GRM_HIL_X.integration_eom_CSTATE_b[2];
  for (i = 0; i < 4; i++) {
    /* Product: '<S306>/Product5' incorporates:
     *  Integrator: '<S303>/integration_eom'
     */
    rtb_Product3_hu = GRM_HIL_B.Add_f[i + 12] *
      GRM_HIL_X.integration_eom_CSTATE_b[3] + (GRM_HIL_B.Add_f[i + 8] *
      rtb_d_qGE[2] + (GRM_HIL_B.Add_f[i + 4] * rtb_d_qGE[1] + GRM_HIL_B.Add_f[i]
                      * rtb_d_qGE[0]));

    /* Gain: '<S306>/Gain' */
    rtb_Product4_n[i] = GRM_HIL_P.Gain_Gain_e4 * rtb_Product3_hu;
  }

  /* SignalConversion generated from: '<S309>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_m[3] = rtb_Product4_n[3];

  /* Gain: '<S309>/Gain1' */
  GRM_HIL_B.VectorConcatenate_m[0] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[0];
  GRM_HIL_B.VectorConcatenate_m[1] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[1];
  GRM_HIL_B.VectorConcatenate_m[2] = GRM_HIL_P.Gain1_Gain_in * rtb_Product4_n[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S305>/Vector Concatenate1' incorporates:
     *  Constant: '<S305>/Constant8'
     */
    GRM_HIL_B.wEGG[0] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S305>/Vector Concatenate1' incorporates:
     *  Constant: '<S305>/Constant8'
     */
    GRM_HIL_B.wEGG[1] = GRM_HIL_P.Constant8_Value_ck;

    /* SignalConversion generated from: '<S305>/Vector Concatenate1' incorporates:
     *  Constant: '<S305>/Constant8'
     */
    GRM_HIL_B.wEGG[2] = GRM_HIL_P.Constant8_Value_ck;
  }

  /* Derivative: '<S305>/Derivative1' */
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

  /* Derivative: '<S305>/Derivative' */
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

  /* Switch: '<S305>/Switch' incorporates:
   *  Constant: '<S305>/Constant9'
   */
  if (GRM_HIL_P.Constant9_Value_l > GRM_HIL_P.Switch_Threshold_m) {
    rtb_pBEE[0] = GRM_HIL_B.wEGG[0];
    rtb_pBEE[1] = GRM_HIL_B.wEGG[1];
    rtb_pBEE[2] = GRM_HIL_B.wEGG[2];
  } else {
    /* Gain: '<S305>/Gain2' incorporates:
     *  Product: '<S305>/Product'
     */
    rtb_pBEE[2] = rtb_Cx * rtb_lat * GRM_HIL_P.Gain2_Gain_k;

    /* Gain: '<S305>/Gain1' */
    rtb_pBEE[1] = GRM_HIL_P.Gain1_Gain * rtb_Add;

    /* Product: '<S305>/Product1' */
    rtb_pBEE[0] = rtb_lat * rtb_Product4_e;
  }

  /* Gain: '<S291>/Gain1' */
  rtb_pBEE[0] *= GRM_HIL_P.Gain1_Gain_k;
  rtb_pBEE[1] *= GRM_HIL_P.Gain1_Gain_k;

  /* SignalConversion generated from: '<S310>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[0] = rtb_pBEE[0];

  /* SignalConversion generated from: '<S310>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_a[1] = rtb_pBEE[1];

  /* SignalConversion generated from: '<S310>/Vector Concatenate' incorporates:
   *  Gain: '<S291>/Gain1'
   */
  GRM_HIL_B.VectorConcatenate_a[2] = GRM_HIL_P.Gain1_Gain_k * rtb_pBEE[2];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S310>/Constant8' */
    GRM_HIL_B.VectorConcatenate_a[3] = GRM_HIL_P.Constant8_Value_p;
  }

  /* Gain: '<S312>/Gain1' incorporates:
   *  Integrator: '<S304>/integration_eom'
   */
  rtb_d_qBI[0] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[0];
  rtb_d_qBI[1] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[1];
  rtb_d_qBI[2] = GRM_HIL_P.Gain1_Gain_a * GRM_HIL_X.integration_eom_CSTATE_f[2];

  /* Sum: '<S310>/Add' incorporates:
   *  Constant: '<S310>/Q_1'
   *  Constant: '<S310>/Q_2'
   *  Constant: '<S310>/Q_3'
   *  Constant: '<S310>/Q_4'
   *  Product: '<S310>/Product1'
   *  Product: '<S310>/Product2'
   *  Product: '<S310>/Product3'
   *  Product: '<S310>/Product4'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_h[i] * GRM_HIL_B.VectorConcatenate_a[0] +
               GRM_HIL_P.Q_2_Value_g[i] * GRM_HIL_B.VectorConcatenate_a[1]) +
              GRM_HIL_P.Q_3_Value_oc[i] * GRM_HIL_B.VectorConcatenate_a[2]) +
      GRM_HIL_P.Q_4_Value_ea[i] * GRM_HIL_B.VectorConcatenate_a[3];
  }

  /* End of Sum: '<S310>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S310>/Product5' incorporates:
     *  Integrator: '<S304>/integration_eom'
     */
    rtb_Product3_hu = tmp[i + 12] * GRM_HIL_X.integration_eom_CSTATE_f[3] +
      (tmp[i + 8] * rtb_d_qBI[2] + (tmp[i + 4] * rtb_d_qBI[1] + tmp[i] *
        rtb_d_qBI[0]));

    /* Gain: '<S310>/Gain' */
    rtb_d_qGE[i] = GRM_HIL_P.Gain_Gain_ba * rtb_Product3_hu;
  }

  /* SignalConversion generated from: '<S313>/Vector Concatenate' */
  GRM_HIL_B.VectorConcatenate_k[3] = rtb_d_qGE[3];

  /* Gain: '<S313>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[0] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[0];

  /* SignalConversion generated from: '<S335>/Vector Concatenate' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.d_x[0] = GRM_HIL_X.integration_eom_CSTATE[3];

  /* SignalConversion generated from: '<S335>/Vector Concatenate' */
  GRM_HIL_B.d_x[3] = rtb_siB_h[0];

  /* Gain: '<S313>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[1] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[1];

  /* SignalConversion generated from: '<S335>/Vector Concatenate' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.d_x[1] = GRM_HIL_X.integration_eom_CSTATE[4];

  /* SignalConversion generated from: '<S335>/Vector Concatenate' */
  GRM_HIL_B.d_x[4] = rtb_siB_h[1];

  /* Gain: '<S313>/Gain1' */
  GRM_HIL_B.VectorConcatenate_k[2] = GRM_HIL_P.Gain1_Gain_mc * rtb_d_qGE[2];

  /* SignalConversion generated from: '<S335>/Vector Concatenate' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.d_x[2] = GRM_HIL_X.integration_eom_CSTATE[5];

  /* SignalConversion generated from: '<S335>/Vector Concatenate' */
  GRM_HIL_B.d_x[5] = rtb_siB_h[2];

  /* SignalConversion generated from: '<S339>/Vector Concatenate' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[0] = GRM_HIL_X.integration_eom_CSTATE[10];

  /* SignalConversion generated from: '<S339>/Vector Concatenate' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[1] = GRM_HIL_X.integration_eom_CSTATE[11];

  /* SignalConversion generated from: '<S339>/Vector Concatenate' incorporates:
   *  Integrator: '<S335>/integration_eom'
   */
  GRM_HIL_B.VectorConcatenate_p[2] = GRM_HIL_X.integration_eom_CSTATE[12];
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S339>/Constant' */
    GRM_HIL_B.VectorConcatenate_p[3] = GRM_HIL_P.Constant_Value_lp;
  }

  /* Gain: '<S342>/Gain1' */
  rtb_siB_h[0] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_0;
  rtb_siB_h[1] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_1;
  rtb_siB_h[2] = GRM_HIL_P.Gain1_Gain_o * rtb_Product_idx_2;

  /* Sum: '<S339>/Add' incorporates:
   *  Constant: '<S339>/Q_1'
   *  Constant: '<S339>/Q_2'
   *  Constant: '<S339>/Q_3'
   *  Constant: '<S339>/Q_4'
   *  Product: '<S339>/Product2'
   *  Product: '<S339>/Product3'
   *  Product: '<S339>/Product4'
   *  Product: '<S339>/Product5'
   */
  for (i = 0; i < 16; i++) {
    tmp[i] = ((GRM_HIL_P.Q_1_Value_f[i] * GRM_HIL_B.VectorConcatenate_p[0] +
               GRM_HIL_P.Q_2_Value_n1[i] * GRM_HIL_B.VectorConcatenate_p[1]) +
              GRM_HIL_P.Q_3_Value_a[i] * GRM_HIL_B.VectorConcatenate_p[2]) +
      GRM_HIL_P.Q_4_Value_b[i] * GRM_HIL_B.VectorConcatenate_p[3];
  }

  /* End of Sum: '<S339>/Add' */
  for (i = 0; i < 4; i++) {
    /* Product: '<S339>/Product6' incorporates:
     *  SignalConversion generated from: '<S342>/Vector Concatenate'
     */
    rtb_Product3_hu = tmp[i + 12] * rtb_Product_idx_3 + (tmp[i + 8] * rtb_siB_h
      [2] + (tmp[i + 4] * rtb_siB_h[1] + tmp[i] * rtb_siB_h[0]));

    /* Gain: '<S339>/Gain' */
    rtb_d_qBI[i] = GRM_HIL_P.Gain_Gain_pq * rtb_Product3_hu;
  }

  /* SignalConversion generated from: '<S343>/Vector Concatenate' */
  GRM_HIL_B.d_x[9] = rtb_d_qBI[3];

  /* Gain: '<S343>/Gain1' */
  GRM_HIL_B.d_x[6] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[0];

  /* Sum: '<S369>/Subtract' incorporates:
   *  Constant: '<S369>/Constant17'
   */
  rtb_pBEE[0] = frac_0[0] - GRM_HIL_P.Constant17_Value[0];

  /* Gain: '<S343>/Gain1' */
  GRM_HIL_B.d_x[7] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[1];

  /* Sum: '<S369>/Subtract' incorporates:
   *  Constant: '<S369>/Constant17'
   */
  rtb_pBEE[1] = frac_0[1] - GRM_HIL_P.Constant17_Value[1];

  /* Gain: '<S343>/Gain1' */
  GRM_HIL_B.d_x[8] = GRM_HIL_P.Gain1_Gain_jq * rtb_d_qBI[2];

  /* Sum: '<S369>/Subtract' incorporates:
   *  Constant: '<S369>/Constant17'
   */
  rtb_pBEE[2] = frac_0[2] - GRM_HIL_P.Constant17_Value[2];

  /* Product: '<S381>/Product1' */
  rtb_Product6_n4 = rtb_pBEE[1] * rtb_pBEE[1];

  /* Product: '<S381>/Product2' */
  rtb_Add = rtb_pBEE[2] * rtb_pBEE[2];

  /* Sum: '<S381>/Add' */
  rtb_JBBB[0] = rtb_Product6_n4 + rtb_Add;

  /* Gain: '<S381>/Gain' incorporates:
   *  Product: '<S381>/Product3'
   */
  rtb_lat = rtb_pBEE[0] * rtb_pBEE[1] * GRM_HIL_P.Gain_Gain_ky;

  /* SignalConversion generated from: '<S381>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_lat;

  /* Gain: '<S381>/Gain1' incorporates:
   *  Product: '<S381>/Product4'
   */
  rtb_Sqrt_j = rtb_pBEE[0] * rtb_pBEE[2] * GRM_HIL_P.Gain1_Gain_oe;

  /* SignalConversion generated from: '<S381>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S381>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_lat;

  /* Product: '<S381>/Product5' */
  rtb_lat = rtb_pBEE[0] * rtb_pBEE[0];

  /* Sum: '<S381>/Add5' */
  rtb_JBBB[4] = rtb_Product6_n4 + rtb_lat;

  /* Gain: '<S381>/Gain3' incorporates:
   *  Product: '<S381>/Product6'
   */
  rtb_Product6_n4 = rtb_pBEE[1] * rtb_pBEE[2] * GRM_HIL_P.Gain3_Gain_c;

  /* SignalConversion generated from: '<S381>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_Product6_n4;

  /* SignalConversion generated from: '<S381>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S381>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_Product6_n4;

  /* Sum: '<S381>/Add4' */
  rtb_JBBB[8] = rtb_Add + rtb_lat;

  /* Sum: '<S364>/Add5' incorporates:
   *  Constant: '<S364>/Constant15'
   *  Constant: '<S369>/Constant'
   *  Product: '<S369>/Product'
   */
  for (i = 0; i < 9; i++) {
    rtb_TBG[i] = GRM_HIL_P.Constant_Value_bk * rtb_JBBB[i] +
      GRM_HIL_P.Constant15_Value[i];
  }

  /* End of Sum: '<S364>/Add5' */

  /* Sum: '<S370>/Subtract4' incorporates:
   *  Constant: '<S370>/Constant16'
   */
  rtb_pBEE[0] = frac_0[0] - GRM_HIL_P.Constant16_Value[0];
  rtb_pBEE[1] = frac_0[1] - GRM_HIL_P.Constant16_Value[1];
  rtb_pBEE[2] = frac_0[2] - GRM_HIL_P.Constant16_Value[2];

  /* Product: '<S382>/Product1' */
  rtb_Product6_n4 = rtb_pBEE[1] * rtb_pBEE[1];

  /* Product: '<S382>/Product2' */
  rtb_Add = rtb_pBEE[2] * rtb_pBEE[2];

  /* Sum: '<S382>/Add' */
  rtb_JBBB[0] = rtb_Product6_n4 + rtb_Add;

  /* Gain: '<S382>/Gain' incorporates:
   *  Product: '<S382>/Product3'
   */
  rtb_lat = rtb_pBEE[0] * rtb_pBEE[1] * GRM_HIL_P.Gain_Gain_lt;

  /* SignalConversion generated from: '<S382>/Vector Concatenate6' */
  rtb_JBBB[1] = rtb_lat;

  /* Gain: '<S382>/Gain1' incorporates:
   *  Product: '<S382>/Product4'
   */
  rtb_Sqrt_j = rtb_pBEE[0] * rtb_pBEE[2] * GRM_HIL_P.Gain1_Gain_iq;

  /* SignalConversion generated from: '<S382>/Vector Concatenate6' */
  rtb_JBBB[2] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S382>/Vector Concatenate7' */
  rtb_JBBB[3] = rtb_lat;

  /* Product: '<S382>/Product5' */
  rtb_lat = rtb_pBEE[0] * rtb_pBEE[0];

  /* Sum: '<S382>/Add5' */
  rtb_JBBB[4] = rtb_Product6_n4 + rtb_lat;

  /* Gain: '<S382>/Gain3' incorporates:
   *  Product: '<S382>/Product6'
   */
  rtb_Product6_n4 = rtb_pBEE[1] * rtb_pBEE[2] * GRM_HIL_P.Gain3_Gain_fm;

  /* SignalConversion generated from: '<S382>/Vector Concatenate7' */
  rtb_JBBB[5] = rtb_Product6_n4;

  /* SignalConversion generated from: '<S382>/Vector Concatenate8' */
  rtb_JBBB[6] = rtb_Sqrt_j;

  /* SignalConversion generated from: '<S382>/Vector Concatenate8' */
  rtb_JBBB[7] = rtb_Product6_n4;

  /* Sum: '<S382>/Add4' */
  rtb_JBBB[8] = rtb_Add + rtb_lat;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S371>/Multiport Switch2' incorporates:
     *  Constant: '<S371>/Constant2'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_3_m) {
     case 1:
      /* Trigonometry: '<S378>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/thrust_rot_x'
       *  Trigonometry: '<S378>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S378>/Trigonometric Function3' incorporates:
       *  Constant: '<S367>/thrust_rot_x'
       *  Trigonometry: '<S378>/Trigonometric Function'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S378>/Matrix Concatenate' incorporates:
       *  Constant: '<S378>/Constant7'
       *  Trigonometry: '<S378>/Trigonometric Function1'
       *  Trigonometry: '<S378>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant7_Value_p;
      rtb_MultiportSwitch2[7] = rtb_Gain1_c;
      rtb_MultiportSwitch2[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S378>/Matrix Concatenate' incorporates:
       *  Constant: '<S378>/Constant8'
       *  Gain: '<S378>/Gain'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant8_Value_cs;
      rtb_MultiportSwitch2[4] = rtb_Divide_h;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Gain_Gain_pk * rtb_Gain1_c;

      /* SignalConversion generated from: '<S378>/Matrix Concatenate' incorporates:
       *  Constant: '<S378>/Constant'
       *  Constant: '<S378>/Constant1'
       *  Constant: '<S378>/Constant2'
       */
      rtb_MultiportSwitch2[0] = GRM_HIL_P.Constant_Value_i;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant1_Value_f;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant2_Value_bt;
      break;

     case 2:
      /* Trigonometry: '<S379>/Trigonometric Function3' incorporates:
       *  Constant: '<S367>/thrust_rot_x'
       *  Trigonometry: '<S379>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S379>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/thrust_rot_x'
       *  Trigonometry: '<S379>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S379>/Matrix Concatenate' incorporates:
       *  Constant: '<S379>/Constant7'
       *  Gain: '<S379>/Gain1'
       *  Trigonometry: '<S379>/Trigonometric Function1'
       *  Trigonometry: '<S379>/Trigonometric Function3'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Gain1_Gain_n * rtb_Divide_h;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant7_Value_jt;
      rtb_MultiportSwitch2[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S379>/Matrix Concatenate' incorporates:
       *  Constant: '<S379>/Constant'
       *  Constant: '<S379>/Constant1'
       *  Constant: '<S379>/Constant2'
       */
      rtb_MultiportSwitch2[3] = GRM_HIL_P.Constant_Value_p;
      rtb_MultiportSwitch2[4] = GRM_HIL_P.Constant1_Value_c4;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant2_Value_jp;

      /* SignalConversion generated from: '<S379>/Matrix Concatenate' incorporates:
       *  Constant: '<S379>/Constant8'
       */
      rtb_MultiportSwitch2[0] = rtb_Gain1_c;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Constant8_Value_c;
      rtb_MultiportSwitch2[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S380>/Matrix Concatenate' incorporates:
       *  Constant: '<S380>/Constant10'
       *  Constant: '<S380>/Constant11'
       *  Constant: '<S380>/Constant4'
       */
      rtb_MultiportSwitch2[6] = GRM_HIL_P.Constant4_Value_a;
      rtb_MultiportSwitch2[7] = GRM_HIL_P.Constant10_Value_g;
      rtb_MultiportSwitch2[8] = GRM_HIL_P.Constant11_Value_h;

      /* Trigonometry: '<S380>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/thrust_rot_x'
       *  Trigonometry: '<S380>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_x_Value_b);

      /* Trigonometry: '<S380>/Trigonometric Function' incorporates:
       *  Constant: '<S367>/thrust_rot_x'
       *  Trigonometry: '<S380>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_x_Value_b);

      /* SignalConversion generated from: '<S380>/Matrix Concatenate' incorporates:
       *  Constant: '<S380>/Constant7'
       *  Trigonometry: '<S380>/Trigonometric Function'
       *  Trigonometry: '<S380>/Trigonometric Function1'
       */
      rtb_MultiportSwitch2[3] = rtb_Gain1_c;
      rtb_MultiportSwitch2[4] = rtb_Divide_h;
      rtb_MultiportSwitch2[5] = GRM_HIL_P.Constant7_Value_cr;

      /* SignalConversion generated from: '<S380>/Matrix Concatenate' incorporates:
       *  Constant: '<S380>/Constant8'
       *  Gain: '<S380>/Gain'
       */
      rtb_MultiportSwitch2[0] = rtb_Divide_h;
      rtb_MultiportSwitch2[1] = GRM_HIL_P.Gain_Gain_ow * rtb_Gain1_c;
      rtb_MultiportSwitch2[2] = GRM_HIL_P.Constant8_Value_os;
      break;
    }

    /* End of MultiPortSwitch: '<S371>/Multiport Switch2' */

    /* MultiPortSwitch: '<S371>/Multiport Switch1' incorporates:
     *  Constant: '<S371>/Constant1'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_2_h) {
     case 1:
      /* Trigonometry: '<S375>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/thrust_rot_y'
       *  Trigonometry: '<S375>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S375>/Trigonometric Function3' incorporates:
       *  Constant: '<S367>/thrust_rot_y'
       *  Trigonometry: '<S375>/Trigonometric Function'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S375>/Matrix Concatenate' incorporates:
       *  Constant: '<S375>/Constant7'
       *  Trigonometry: '<S375>/Trigonometric Function1'
       *  Trigonometry: '<S375>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant7_Value_n;
      rtb_MultiportSwitch1[7] = rtb_Gain1_c;
      rtb_MultiportSwitch1[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S375>/Matrix Concatenate' incorporates:
       *  Constant: '<S375>/Constant8'
       *  Gain: '<S375>/Gain'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant8_Value_n;
      rtb_MultiportSwitch1[4] = rtb_Divide_h;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Gain_Gain_ax * rtb_Gain1_c;

      /* SignalConversion generated from: '<S375>/Matrix Concatenate' incorporates:
       *  Constant: '<S375>/Constant'
       *  Constant: '<S375>/Constant1'
       *  Constant: '<S375>/Constant2'
       */
      rtb_MultiportSwitch1[0] = GRM_HIL_P.Constant_Value_lx;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant1_Value_nq;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant2_Value_c;
      break;

     case 2:
      /* Trigonometry: '<S376>/Trigonometric Function3' incorporates:
       *  Constant: '<S367>/thrust_rot_y'
       *  Trigonometry: '<S376>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S376>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/thrust_rot_y'
       *  Trigonometry: '<S376>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S376>/Matrix Concatenate' incorporates:
       *  Constant: '<S376>/Constant7'
       *  Gain: '<S376>/Gain1'
       *  Trigonometry: '<S376>/Trigonometric Function1'
       *  Trigonometry: '<S376>/Trigonometric Function3'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Gain1_Gain_j0 * rtb_Divide_h;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant7_Value_fv;
      rtb_MultiportSwitch1[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S376>/Matrix Concatenate' incorporates:
       *  Constant: '<S376>/Constant'
       *  Constant: '<S376>/Constant1'
       *  Constant: '<S376>/Constant2'
       */
      rtb_MultiportSwitch1[3] = GRM_HIL_P.Constant_Value_c;
      rtb_MultiportSwitch1[4] = GRM_HIL_P.Constant1_Value_a;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant2_Value_js;

      /* SignalConversion generated from: '<S376>/Matrix Concatenate' incorporates:
       *  Constant: '<S376>/Constant8'
       */
      rtb_MultiportSwitch1[0] = rtb_Gain1_c;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Constant8_Value_dg;
      rtb_MultiportSwitch1[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S377>/Matrix Concatenate' incorporates:
       *  Constant: '<S377>/Constant10'
       *  Constant: '<S377>/Constant11'
       *  Constant: '<S377>/Constant4'
       */
      rtb_MultiportSwitch1[6] = GRM_HIL_P.Constant4_Value_b;
      rtb_MultiportSwitch1[7] = GRM_HIL_P.Constant10_Value_m;
      rtb_MultiportSwitch1[8] = GRM_HIL_P.Constant11_Value_l2;

      /* Trigonometry: '<S377>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/thrust_rot_y'
       *  Trigonometry: '<S377>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.thrust_rot_y_Value_j);

      /* Trigonometry: '<S377>/Trigonometric Function' incorporates:
       *  Constant: '<S367>/thrust_rot_y'
       *  Trigonometry: '<S377>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(GRM_HIL_P.thrust_rot_y_Value_j);

      /* SignalConversion generated from: '<S377>/Matrix Concatenate' incorporates:
       *  Constant: '<S377>/Constant7'
       *  Trigonometry: '<S377>/Trigonometric Function'
       *  Trigonometry: '<S377>/Trigonometric Function1'
       */
      rtb_MultiportSwitch1[3] = rtb_Gain1_c;
      rtb_MultiportSwitch1[4] = rtb_Divide_h;
      rtb_MultiportSwitch1[5] = GRM_HIL_P.Constant7_Value_ch;

      /* SignalConversion generated from: '<S377>/Matrix Concatenate' incorporates:
       *  Constant: '<S377>/Constant8'
       *  Gain: '<S377>/Gain'
       */
      rtb_MultiportSwitch1[0] = rtb_Divide_h;
      rtb_MultiportSwitch1[1] = GRM_HIL_P.Gain_Gain_n * rtb_Gain1_c;
      rtb_MultiportSwitch1[2] = GRM_HIL_P.Constant8_Value_ke;
      break;
    }

    /* End of MultiPortSwitch: '<S371>/Multiport Switch1' */

    /* MultiPortSwitch: '<S371>/Multiport Switch' incorporates:
     *  Constant: '<S371>/Constant'
     */
    switch ((int32_T)GRM_HIL_P.u_rot_mat_rot_1_md) {
     case 1:
      /* Trigonometry: '<S372>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/Thrust_rot_z'
       *  Trigonometry: '<S372>/Trigonometric Function2'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S372>/Trigonometric Function3' incorporates:
       *  Constant: '<S367>/Thrust_rot_z'
       *  Trigonometry: '<S372>/Trigonometric Function'
       */
      rtb_Divide_h = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S372>/Matrix Concatenate' incorporates:
       *  Constant: '<S372>/Constant7'
       *  Trigonometry: '<S372>/Trigonometric Function1'
       *  Trigonometry: '<S372>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant7_Value_gi;
      rtb_MultiportSwitch[7] = rtb_Gain1_c;
      rtb_MultiportSwitch[8] = rtb_Divide_h;

      /* SignalConversion generated from: '<S372>/Matrix Concatenate' incorporates:
       *  Constant: '<S372>/Constant8'
       *  Gain: '<S372>/Gain'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant8_Value_j;
      rtb_MultiportSwitch[4] = rtb_Divide_h;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Gain_Gain_cy * rtb_Gain1_c;

      /* SignalConversion generated from: '<S372>/Matrix Concatenate' incorporates:
       *  Constant: '<S372>/Constant'
       *  Constant: '<S372>/Constant1'
       *  Constant: '<S372>/Constant2'
       */
      rtb_MultiportSwitch[0] = GRM_HIL_P.Constant_Value_of;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant1_Value_g;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant2_Value_a;
      break;

     case 2:
      /* Trigonometry: '<S373>/Trigonometric Function3' incorporates:
       *  Constant: '<S367>/Thrust_rot_z'
       *  Trigonometry: '<S373>/Trigonometric Function'
       */
      rtb_Gain1_c = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S373>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/Thrust_rot_z'
       *  Trigonometry: '<S373>/Trigonometric Function2'
       */
      rtb_Divide_h = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S373>/Matrix Concatenate' incorporates:
       *  Constant: '<S373>/Constant7'
       *  Gain: '<S373>/Gain1'
       *  Trigonometry: '<S373>/Trigonometric Function1'
       *  Trigonometry: '<S373>/Trigonometric Function3'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Gain1_Gain_hv * rtb_Divide_h;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant7_Value_je;
      rtb_MultiportSwitch[8] = rtb_Gain1_c;

      /* SignalConversion generated from: '<S373>/Matrix Concatenate' incorporates:
       *  Constant: '<S373>/Constant'
       *  Constant: '<S373>/Constant1'
       *  Constant: '<S373>/Constant2'
       */
      rtb_MultiportSwitch[3] = GRM_HIL_P.Constant_Value_hw;
      rtb_MultiportSwitch[4] = GRM_HIL_P.Constant1_Value_k;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant2_Value_i;

      /* SignalConversion generated from: '<S373>/Matrix Concatenate' incorporates:
       *  Constant: '<S373>/Constant8'
       */
      rtb_MultiportSwitch[0] = rtb_Gain1_c;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Constant8_Value_l;
      rtb_MultiportSwitch[2] = rtb_Divide_h;
      break;

     default:
      /* SignalConversion generated from: '<S374>/Matrix Concatenate' incorporates:
       *  Constant: '<S374>/Constant10'
       *  Constant: '<S374>/Constant11'
       *  Constant: '<S374>/Constant4'
       */
      rtb_MultiportSwitch[6] = GRM_HIL_P.Constant4_Value_l5;
      rtb_MultiportSwitch[7] = GRM_HIL_P.Constant10_Value_c;
      rtb_MultiportSwitch[8] = GRM_HIL_P.Constant11_Value_h1;

      /* Trigonometry: '<S374>/Trigonometric Function1' incorporates:
       *  Constant: '<S367>/Thrust_rot_z'
       *  Trigonometry: '<S374>/Trigonometric Function4'
       */
      rtb_Gain1_c = sin(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* Trigonometry: '<S374>/Trigonometric Function' incorporates:
       *  Constant: '<S367>/Thrust_rot_z'
       *  Trigonometry: '<S374>/Trigonometric Function3'
       */
      rtb_Divide_h = cos(GRM_HIL_P.Thrust_rot_z_Value_l);

      /* SignalConversion generated from: '<S374>/Matrix Concatenate' incorporates:
       *  Constant: '<S374>/Constant7'
       *  Trigonometry: '<S374>/Trigonometric Function'
       *  Trigonometry: '<S374>/Trigonometric Function1'
       */
      rtb_MultiportSwitch[3] = rtb_Gain1_c;
      rtb_MultiportSwitch[4] = rtb_Divide_h;
      rtb_MultiportSwitch[5] = GRM_HIL_P.Constant7_Value_p5;

      /* SignalConversion generated from: '<S374>/Matrix Concatenate' incorporates:
       *  Constant: '<S374>/Constant8'
       *  Gain: '<S374>/Gain'
       */
      rtb_MultiportSwitch[0] = rtb_Divide_h;
      rtb_MultiportSwitch[1] = GRM_HIL_P.Gain_Gain_f0 * rtb_Gain1_c;
      rtb_MultiportSwitch[2] = GRM_HIL_P.Constant8_Value_gw;
      break;
    }

    /* End of MultiPortSwitch: '<S371>/Multiport Switch' */

    /* Product: '<S371>/3. Rotation' */
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
    }

    /* End of Product: '<S371>/3. Rotation' */

    /* Sum: '<S366>/Subtract' incorporates:
     *  Constant: '<S366>/Constant16'
     *  Constant: '<S366>/Constant17'
     */
    for (i = 0; i < 9; i++) {
      GRM_HIL_B.Subtract_d[i] = GRM_HIL_P.Constant17_Value_j[i] -
        GRM_HIL_P.Constant16_Value_i[i];
    }

    /* End of Sum: '<S366>/Subtract' */

    /* Sum: '<S366>/Subtract4' incorporates:
     *  Constant: '<S366>/Constant18'
     *  Constant: '<S366>/Constant19'
     */
    GRM_HIL_B.Subtract4 = GRM_HIL_P.Constant19_Value -
      GRM_HIL_P.Constant18_Value;

    /* Math: '<S367>/Math Function' */
    for (i = 0; i < 3; i++) {
      GRM_HIL_B.MathFunction[3 * i] = GRM_HIL_B.T12_o[i];
      GRM_HIL_B.MathFunction[3 * i + 1] = GRM_HIL_B.T12_o[i + 3];
      GRM_HIL_B.MathFunction[3 * i + 2] = GRM_HIL_B.T12_o[i + 6];
    }

    /* End of Math: '<S367>/Math Function' */
  }

  /* Sum: '<S366>/Subtract5' incorporates:
   *  Constant: '<S366>/Constant20'
   */
  rtb_Add = rtb_Product7_ma - GRM_HIL_P.Constant20_Value;

  /* Sum: '<S366>/Subtract6' incorporates:
   *  Constant: '<S366>/Constant21'
   *  Product: '<S366>/Divide'
   */
  for (i = 0; i < 9; i++) {
    rtb_MatrixMultiply_tmp[i] = rtb_Add * GRM_HIL_B.Subtract_d[i] /
      GRM_HIL_B.Subtract4 + GRM_HIL_P.Constant21_Value[i];
  }

  /* End of Sum: '<S366>/Subtract6' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S367>/Matrix Multiply' */
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

    /* End of Product: '<S367>/Matrix Multiply' */

    /* Product: '<S337>/Product1' */
    rtb_Product1_m[i] = 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* Sum: '<S368>/Add7' incorporates:
       *  Constant: '<S368>/Constant16'
       *  Product: '<S337>/Product1'
       *  Product: '<S367>/Matrix Multiply1'
       *  Product: '<S370>/Product'
       *  Sum: '<S364>/Add'
       *  Sum: '<S364>/Add4'
       */
      rtb_MultiportSwitch1_tmp = 3 * i_0 + i;
      rtb_JBBB[rtb_MultiportSwitch1_tmp] = ((((GRM_HIL_B.MathFunction[3 * i_0 +
        1] * rtb_MultiportSwitch[i + 3] + GRM_HIL_B.MathFunction[3 * i_0] *
        rtb_MultiportSwitch[i]) + GRM_HIL_B.MathFunction[3 * i_0 + 2] *
        rtb_MultiportSwitch[i + 6]) + rtb_JBBB[rtb_MultiportSwitch1_tmp] *
        rtb_Product7_ma) + rtb_TBG[rtb_MultiportSwitch1_tmp]) +
        GRM_HIL_P.Constant16_Value_c[rtb_MultiportSwitch1_tmp];

      /* Product: '<S337>/Product1' incorporates:
       *  Integrator: '<S335>/integration_eom'
       */
      rtb_Product1_m[i] += rtb_JBBB[rtb_MultiportSwitch1_tmp] *
        GRM_HIL_X.integration_eom_CSTATE[i_0 + 10];
    }
  }

  /* Sum: '<S340>/Sum' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S340>/Product2'
   *  Product: '<S340>/Product3'
   */
  rtb_VectorConcatenate_a[0] = GRM_HIL_X.integration_eom_CSTATE[11] *
    rtb_Product1_m[2] - GRM_HIL_X.integration_eom_CSTATE[12] * rtb_Product1_m[1];

  /* Sum: '<S340>/Sum1' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S340>/Product4'
   *  Product: '<S340>/Product5'
   */
  rtb_VectorConcatenate_a[1] = GRM_HIL_X.integration_eom_CSTATE[12] *
    rtb_Product1_m[0] - GRM_HIL_X.integration_eom_CSTATE[10] * rtb_Product1_m[2];

  /* Sum: '<S340>/Sum2' incorporates:
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S340>/Product6'
   *  Product: '<S340>/Product7'
   */
  rtb_VectorConcatenate_a[2] = GRM_HIL_X.integration_eom_CSTATE[10] *
    rtb_Product1_m[1] - GRM_HIL_X.integration_eom_CSTATE[11] * rtb_Product1_m[0];

  /* Sum: '<S337>/Subtract' incorporates:
   *  Constant: '<S328>/Constant9'
   *  Integrator: '<S335>/integration_eom'
   *  Product: '<S337>/Product'
   */
  for (i = 0; i < 3; i++) {
    frac[i] = (frac[i] - ((GRM_HIL_P.Constant9_Value_cv[i + 3] *
      GRM_HIL_X.integration_eom_CSTATE[11] + GRM_HIL_P.Constant9_Value_cv[i] *
      GRM_HIL_X.integration_eom_CSTATE[10]) + GRM_HIL_P.Constant9_Value_cv[i + 6]
                          * GRM_HIL_X.integration_eom_CSTATE[12])) -
      rtb_VectorConcatenate_a[i];
  }

  /* End of Sum: '<S337>/Subtract' */

  /* Product: '<S337>/Divide1' */
  rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(rtb_JBBB, frac, &GRM_HIL_B.d_x[10]);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S361>/Divide' incorporates:
     *  Constant: '<S361>/Constant'
     *  Constant: '<S361>/Constant5'
     */
    rtb_VectorConcatenate_f[2] = GRM_HIL_P.Constant_Value_et /
      GRM_HIL_P.Constant5_Value_p;

    /* Product: '<S361>/Divide1' incorporates:
     *  Constant: '<S361>/Constant2'
     *  Constant: '<S361>/Constant5'
     */
    rtb_VectorConcatenate_f[1] = GRM_HIL_P.Constant2_Value_j2 /
      GRM_HIL_P.Constant5_Value_p;

    /* Product: '<S361>/Divide2' incorporates:
     *  Constant: '<S361>/Constant1'
     *  Constant: '<S361>/Constant5'
     */
    rtb_VectorConcatenate_f[0] = GRM_HIL_P.Constant1_Value_lm /
      GRM_HIL_P.Constant5_Value_p;

    /* Outputs for Enabled SubSystem: '<S7>/Synchronize_to_realtime' incorporates:
     *  EnablePort: '<S383>/Enable'
     */
    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant9'
     *  Logic: '<S7>/NOT'
     */
    if (GRM_HIL_P.Constant1_Value_c3 && (!GRM_HIL_P.Constant9_Value_b) &&
        GRM_HIL_P.Constant3_Value_it) {
      /* S-Function (sldrtsync): '<S383>/Real-Time Synchronization' */
      /* S-Function Block: <S383>/Real-Time Synchronization */
      {
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
      }
    }

    /* End of Logic: '<S7>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S7>/Synchronize_to_realtime' */
  }
}

/* Model update function */
void GRM_HIL_update(void)
{
  real_T *lastU;

  /* Update for Integrator: '<S335>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK = 0;

  /* Update for Integrator: '<S303>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_g = 0;

  /* Update for Integrator: '<S304>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_l = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S19>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_B.value;
  }

  /* Update for TransportDelay: '<S176>/Transport Delay' */
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

  /* Update for TransportDelay: '<S174>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_f.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_f.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK_m.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK_m.Head <
        (GRM_HIL_DW.TransportDelay_IWORK_m.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK_m.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK_m.Head ==
        GRM_HIL_DW.TransportDelay_IWORK_m.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK_m.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK_m.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK_m.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK_m.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK_m.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK_m.Head] = GRM_HIL_B.pitch_deg;
  }

  /* Update for TransportDelay: '<S175>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_a.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_a.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK_c.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK_c.Head <
        (GRM_HIL_DW.TransportDelay_IWORK_c.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK_c.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK_c.Head ==
        GRM_HIL_DW.TransportDelay_IWORK_c.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK_c.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK_c.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK_c.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK_c.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK_c.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK_c.Head] = GRM_HIL_B.roll_deg;
  }

  /* Update for Derivative: '<S305>/Derivative1' */
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

  /* End of Update for Derivative: '<S305>/Derivative1' */

  /* Update for Derivative: '<S305>/Derivative' */
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

  /* End of Update for Derivative: '<S305>/Derivative' */
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
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
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
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
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

  /* Derivatives for Integrator: '<S335>/integration_eom' */
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
  _rtXdot->TransferFcn_CSTATE[0] += GRM_HIL_B.Saturation_o;

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

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[0] = GRM_HIL_B.VectorConcatenate_m[0];

  /* Derivatives for Integrator: '<S304>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[0] = GRM_HIL_B.VectorConcatenate_k[0];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[1] = GRM_HIL_B.VectorConcatenate_m[1];

  /* Derivatives for Integrator: '<S304>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[1] = GRM_HIL_B.VectorConcatenate_k[1];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[2] = GRM_HIL_B.VectorConcatenate_m[2];

  /* Derivatives for Integrator: '<S304>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[2] = GRM_HIL_B.VectorConcatenate_k[2];

  /* Derivatives for Integrator: '<S303>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_b[3] = GRM_HIL_B.VectorConcatenate_m[3];

  /* Derivatives for Integrator: '<S304>/integration_eom' */
  _rtXdot->integration_eom_CSTATE_f[3] = GRM_HIL_B.VectorConcatenate_k[3];

  /* Derivatives for Integrator: '<S271>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE <= GRM_HIL_P.Rudder_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE >= GRM_HIL_P.Rudder_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l > 0.0))
      || (usat && (GRM_HIL_B.sf_Limiting_Rate.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE = GRM_HIL_B.sf_Limiting_Rate.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S271>/Integrator1' */

  /* Derivatives for Integrator: '<S272>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_g <= GRM_HIL_P.Rudder1_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_g >= GRM_HIL_P.Rudder1_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_g = GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_g = 0.0;
  }

  /* End of Derivatives for Integrator: '<S272>/Integrator1' */

  /* Derivatives for Integrator: '<S273>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_a <= GRM_HIL_P.Rudder2_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_a >= GRM_HIL_P.Rudder2_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_a = GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_a = 0.0;
  }

  /* End of Derivatives for Integrator: '<S273>/Integrator1' */

  /* Derivatives for Integrator: '<S274>/Integrator1' */
  lsat = (GRM_HIL_X.Integrator1_CSTATE_i <= GRM_HIL_P.Rudder3_siB_min);
  usat = (GRM_HIL_X.Integrator1_CSTATE_i >= GRM_HIL_P.Rudder3_siB_max);
  if (((!lsat) && (!usat)) || (lsat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l >
        0.0)) || (usat && (GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_i = GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_i = 0.0;
  }

  /* End of Derivatives for Integrator: '<S274>/Integrator1' */

  /* Derivatives for TransferFcn: '<S25>/Transfer Fcn2' */
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

  /* Derivatives for TransferFcn: '<S49>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_l[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE_l[0] += GRM_HIL_P.TransferFcn1_A[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_l[0];
  _rtXdot->TransferFcn1_CSTATE_l[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE_l[0] += GRM_HIL_P.TransferFcn1_A[1] *
    GRM_HIL_X.TransferFcn1_CSTATE_l[1];
  _rtXdot->TransferFcn1_CSTATE_l[1] += GRM_HIL_X.TransferFcn1_CSTATE_l[0];
  _rtXdot->TransferFcn1_CSTATE_l[0] += GRM_HIL_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S73>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.SumI1_k;

  /* Derivatives for Integrator: '<S73>/Filter' */
  _rtXdot->Filter_CSTATE = GRM_HIL_B.FilterCoefficient;

  /* Derivatives for Enabled SubSystem: '<S71>/Control_Limits' */
  if (GRM_HIL_DW.Control_Limits_MODE) {
    /* Derivatives for Integrator: '<S107>/Integrator' */
    _rtXdot->Integrator_CSTATE_f5 = GRM_HIL_B.SumI4;

    /* Derivatives for Integrator: '<S102>/Filter' */
    _rtXdot->Filter_CSTATE_j = GRM_HIL_B.FilterCoefficient_h;

    /* Derivatives for Integrator: '<S151>/Integrator' */
    _rtXdot->Integrator_CSTATE_i = GRM_HIL_B.SumI4_e;

    /* Derivatives for Integrator: '<S146>/Filter' */
    _rtXdot->Filter_CSTATE_b = GRM_HIL_B.FilterCoefficient_b;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_GRM_HIL_T *) GRM_HIL_M->derivs)->Integrator_CSTATE_f5);
      for (i=0; i < 4; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S71>/Control_Limits' */

  /* Derivatives for Integrator: '<S54>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = GRM_HIL_B.SumI1;

  /* Derivatives for Integrator: '<S54>/Filter' */
  _rtXdot->Filter_CSTATE_f = GRM_HIL_B.FilterCoefficient_c;

  /* Derivatives for Integrator: '<S63>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = GRM_HIL_B.SumI1_b;

  /* Derivatives for Integrator: '<S63>/Filter' */
  _rtXdot->Filter_CSTATE_k = GRM_HIL_B.FilterCoefficient_j;

  /* Derivatives for Integrator: '<S271>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = GRM_HIL_B.sf_Limiting_Acceleration.dd_siB_l;

  /* Derivatives for Integrator: '<S272>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = GRM_HIL_B.sf_Limiting_Acceleration_i.dd_siB_l;

  /* Derivatives for Integrator: '<S273>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = GRM_HIL_B.sf_Limiting_Acceleration_p.dd_siB_l;

  /* Derivatives for Integrator: '<S274>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = GRM_HIL_B.sf_Limiting_Acceleration_h.dd_siB_l;
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
  /* Start for Constant: '<S328>/Constant' */
  memcpy(&GRM_HIL_B.Constant[0], &GRM_HIL_P.Constant_Value_pl[0], 13U * sizeof
         (real_T));

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8[0] = GRM_HIL_P.Constant8_Value_i[0];

  /* Start for Constant: '<S304>/Constant8' */
  GRM_HIL_B.Constant8_h[0] = GRM_HIL_P.Constant8_Value_oz[0];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8[1] = GRM_HIL_P.Constant8_Value_i[1];

  /* Start for Constant: '<S304>/Constant8' */
  GRM_HIL_B.Constant8_h[1] = GRM_HIL_P.Constant8_Value_oz[1];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8[2] = GRM_HIL_P.Constant8_Value_i[2];

  /* Start for Constant: '<S304>/Constant8' */
  GRM_HIL_B.Constant8_h[2] = GRM_HIL_P.Constant8_Value_oz[2];

  /* Start for Constant: '<S303>/Constant8' */
  GRM_HIL_B.Constant8[3] = GRM_HIL_P.Constant8_Value_i[3];

  /* Start for Constant: '<S304>/Constant8' */
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

  /* Start for Enabled SubSystem: '<S18>/Com_to_FCC_emul' */
  GRM_HIL_DW.Com_to_FCC_emul_MODE = false;

  /* End of Start for SubSystem: '<S18>/Com_to_FCC_emul' */

  /* Start for Enabled SubSystem: '<S29>/Pass' */
  GRM_HIL_DW.Pass_MODE = false;

  /* End of Start for SubSystem: '<S29>/Pass' */

  /* Start for Enabled SubSystem: '<S29>/Saturate' */
  GRM_HIL_DW.Saturate_MODE = false;

  /* End of Start for SubSystem: '<S29>/Saturate' */
  /* Start for TransportDelay: '<S176>/Transport Delay' */
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

  /* Start for TransportDelay: '<S174>/Transport Delay' */
  {
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK_m.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK_m.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK_m.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK_m.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK_m.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput_d;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK_f.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK_f.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for TransportDelay: '<S175>/Transport Delay' */
  {
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK_a.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK_c.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK_c.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK_c.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK_c.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput_c;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK_a.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK_a.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for Enabled SubSystem: '<S72>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass_d);

  /* End of Start for SubSystem: '<S72>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S72>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE = false;

  /* End of Start for SubSystem: '<S72>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S71>/Control_Limits' */
  GRM_HIL_DW.Control_Limits_MODE = false;

  /* End of Start for SubSystem: '<S71>/Control_Limits' */

  /* Start for Enabled SubSystem: '<S53>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass);

  /* End of Start for SubSystem: '<S53>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S53>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE_l = false;

  /* End of Start for SubSystem: '<S53>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S62>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass_k);

  /* End of Start for SubSystem: '<S62>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S62>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE_p = false;

  /* End of Start for SubSystem: '<S62>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S45>/Voltage_Limitations' */
  GRM_HIL_DW.Voltage_Limitations_MODE = false;

  /* Start for If: '<S52>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_m = -1;

  /* Start for If: '<S52>/If1' */
  GRM_HIL_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S52>/If2' */
  GRM_HIL_DW.If2_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S45>/Voltage_Limitations' */

  /* Start for Enabled SubSystem: '<S45>/If Action Pass' */
  GRM_HIL_DW.IfActionPass_MODE = false;

  /* End of Start for SubSystem: '<S45>/If Action Pass' */

  /* Start for S-Function (sldrtao): '<S38>/Analog Output   3 Motors Yaw Pitch Roll' */

  /* S-Function Block: <S38>/Analog Output   3 Motors Yaw Pitch Roll */
  {
    double aoval[3];
    double* aovalp = aoval;
    *aovalp++ = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_InitialValue;
    *aovalp++ = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_InitialValue;
    *aovalp++ = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_InitialValue;

    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_RangeMode;
      parm.rangeidx = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 3,
                     GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_Channels, aoval,
                     &parm);
    }
  }

  /* Start for S-Function (sldrtdo): '<S38>/Digital Output' */

  /* S-Function Block: <S38>/Digital Output */

  /* no initial value should be set */

  /* Start for If: '<S176>/If' */
  GRM_HIL_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S174>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_h = -1;

  /* Start for If: '<S175>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_l = -1;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  GRM_HIL_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S335>/integration_eom' incorporates:
   *  Integrator: '<S303>/integration_eom'
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

  /* End of InitializeConditions for Integrator: '<S335>/integration_eom' */

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

  /* InitializeConditions for Integrator: '<S303>/integration_eom' */
  GRM_HIL_DW.integration_eom_IWORK_g = 1;

  /* InitializeConditions for Integrator: '<S304>/integration_eom' */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    GRM_HIL_X.integration_eom_CSTATE_f[0] = 0.0;
    GRM_HIL_X.integration_eom_CSTATE_f[1] = 0.0;
    GRM_HIL_X.integration_eom_CSTATE_f[2] = 0.0;
    GRM_HIL_X.integration_eom_CSTATE_f[3] = 1.0;
  }

  GRM_HIL_DW.integration_eom_IWORK_l = 1;

  /* End of InitializeConditions for Integrator: '<S304>/integration_eom' */

  /* InitializeConditions for Integrator: '<S271>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_P.Rudder_siB_0;

  /* InitializeConditions for Integrator: '<S272>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE_g = GRM_HIL_P.Rudder1_siB_0;

  /* InitializeConditions for Integrator: '<S273>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE_a = GRM_HIL_P.Rudder2_siB_0;

  /* InitializeConditions for Integrator: '<S274>/Integrator1' */
  GRM_HIL_X.Integrator1_CSTATE_i = GRM_HIL_P.Rudder3_siB_0;

  /* InitializeConditions for Memory: '<S19>/Memory' */
  GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_P.Memory_InitialCondition;

  /* InitializeConditions for TransferFcn: '<S25>/Transfer Fcn2' */
  GRM_HIL_X.TransferFcn2_CSTATE_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S25>/Transfer Fcn1' */
  GRM_HIL_X.TransferFcn1_CSTATE_e = 0.0;

  /* InitializeConditions for S-Function (sldrtei): '<S38>/Encoder Input3' */

  /* S-Function Block: <S38>/Encoder Input3 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = GRM_HIL_P.EncoderInput3_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 3, GRM_HIL_P.EncoderInput3_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S49>/Transfer Fcn1' */
  GRM_HIL_X.TransferFcn1_CSTATE_l[0] = 0.0;
  GRM_HIL_X.TransferFcn1_CSTATE_l[1] = 0.0;

  /* InitializeConditions for Integrator: '<S73>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE = GRM_HIL_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S73>/Filter' */
  GRM_HIL_X.Filter_CSTATE = GRM_HIL_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S54>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_k = GRM_HIL_P.Integrator_IC_n;

  /* InitializeConditions for Integrator: '<S54>/Filter' */
  GRM_HIL_X.Filter_CSTATE_f = GRM_HIL_P.Filter_IC_l;

  /* InitializeConditions for Integrator: '<S63>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_p = GRM_HIL_P.Integrator_IC_k;

  /* InitializeConditions for Integrator: '<S63>/Filter' */
  GRM_HIL_X.Filter_CSTATE_k = GRM_HIL_P.Filter_IC_p;

  /* InitializeConditions for Integrator: '<S271>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_h = GRM_HIL_P.Rudder_d_siB_0;

  /* InitializeConditions for Integrator: '<S272>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_e = GRM_HIL_P.Rudder1_d_siB_0;

  /* InitializeConditions for Integrator: '<S273>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Rudder2_d_siB_0;

  /* InitializeConditions for Integrator: '<S274>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_g = GRM_HIL_P.Rudder3_d_siB_0;

  /* InitializeConditions for Derivative: '<S305>/Derivative1' */
  GRM_HIL_DW.TimeStampA = (rtInf);
  GRM_HIL_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S305>/Derivative' */
  GRM_HIL_DW.TimeStampA_b = (rtInf);
  GRM_HIL_DW.TimeStampB_j = (rtInf);

  /* SystemInitialize for Enabled SubSystem: '<S18>/Com_to_FCC_emul' */
  /* SystemInitialize for Outport: '<S20>/States_hold' */
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

  /* SystemInitialize for Outport: '<S20>/External_Inputs_hold' */
  GRM_HIL_B.CMD_phi_rad =
    GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_phi_rad;
  GRM_HIL_B.CMD_acc_z_mDs2 =
    GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_acc_z_mDs2;
  GRM_HIL_B.CMD_acc_y_mDs2 =
    GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_acc_y_mDs2;

  /* End of SystemInitialize for SubSystem: '<S18>/Com_to_FCC_emul' */

  /* SystemInitialize for Merge: '<S73>/Merge' */
  GRM_HIL_B.Merge_b = GRM_HIL_P.Merge_InitialOutput;

  /* SystemInitialize for Enabled SubSystem: '<S71>/Control_Limits' */
  /* InitializeConditions for Integrator: '<S107>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_f5 =
    GRM_HIL_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S102>/Filter' */
  GRM_HIL_X.Filter_CSTATE_j = GRM_HIL_P.PIDController_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S151>/Integrator' */
  GRM_HIL_X.Integrator_CSTATE_i =
    GRM_HIL_P.PIDController1_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S146>/Filter' */
  GRM_HIL_X.Filter_CSTATE_b = GRM_HIL_P.PIDController1_InitialConditionForFilter;

  /* End of SystemInitialize for SubSystem: '<S71>/Control_Limits' */

  /* SystemInitialize for Merge: '<S71>/Merge' */
  GRM_HIL_B.Merge_m = GRM_HIL_P.Merge_InitialOutput_p;

  /* SystemInitialize for Merge: '<S54>/Merge' */
  GRM_HIL_B.Merge_l = GRM_HIL_P.Merge_InitialOutput_n;

  /* SystemInitialize for Merge: '<S63>/Merge' */
  GRM_HIL_B.Merge_lu = GRM_HIL_P.Merge_InitialOutput_h;

  /* SystemInitialize for Merge: '<S45>/Merge' */
  GRM_HIL_B.Merge_mx = GRM_HIL_P.Merge_InitialOutput_e;

  /* SystemInitialize for Merge: '<S45>/Merge1' */
  GRM_HIL_B.Merge1_c = GRM_HIL_P.Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S45>/Merge2' */
  GRM_HIL_B.Merge2_d = GRM_HIL_P.Merge2_InitialOutput;

  /* SystemInitialize for IfAction SubSystem: '<S176>/If Action Subsystem1' */
  GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1_f,
    &GRM_HIL_P.IfActionSubsystem1_f);

  /* End of SystemInitialize for SubSystem: '<S176>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S176>/If Action Subsystem' */
  GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem_d,
    &GRM_HIL_P.IfActionSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S176>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S174>/If Action Subsystem1' */
  GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1,
    &GRM_HIL_P.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S174>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S174>/If Action Subsystem' */
  GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem,
    &GRM_HIL_P.IfActionSubsystem);

  /* End of SystemInitialize for SubSystem: '<S174>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S175>/If Action Subsystem1' */
  GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1_i,
    &GRM_HIL_P.IfActionSubsystem1_i);

  /* End of SystemInitialize for SubSystem: '<S175>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S175>/If Action Subsystem' */
  GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem_k,
    &GRM_HIL_P.IfActionSubsystem_k);

  /* End of SystemInitialize for SubSystem: '<S175>/If Action Subsystem' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    rtmSetFirstInitCond(GRM_HIL_M, 0);
  }
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S38>/Analog Output   3 Motors Yaw Pitch Roll' */

  /* S-Function Block: <S38>/Analog Output   3 Motors Yaw Pitch Roll */
  {
    double aoval[3];
    double* aovalp = aoval;
    *aovalp++ = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_FinalValue;
    *aovalp++ = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_FinalValue;
    *aovalp++ = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_FinalValue;

    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_RangeMode;
      parm.rangeidx = GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 3,
                     GRM_HIL_P.AnalogOutput3MotorsYawPitchRoll_Channels, aoval,
                     &parm);
    }
  }

  /* Terminate for S-Function (sldrtdo): '<S38>/Digital Output' */

  /* S-Function Block: <S38>/Digital Output */

  /* no final value should be set */
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
  GRM_HIL_P.EncoderInput3_InputFilter = rtInf;
  GRM_HIL_P.Saturation1_UpperSat = rtInf;
  GRM_HIL_P.Saturation_UpperSat_f = rtInf;
  GRM_HIL_P.Saturation_UpperSat_d = rtInf;
  GRM_HIL_P.Saturation_UpperSat_m = rtInf;
  GRM_HIL_P.Constant2_Value_k = rtInf;
  GRM_HIL_P.Constant2_Value_ee = rtInf;
  GRM_HIL_P.Constant2_Value_go = rtInf;

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
    GRM_HIL_M->Timing.sampleTimes[2] = (0.01);
    GRM_HIL_M->Timing.sampleTimes[3] = (0.02);

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
  GRM_HIL_M->Timing.stepSize2 = 0.01;
  GRM_HIL_M->Timing.stepSize3 = 0.02;
  rtmSetFirstInitCond(GRM_HIL_M, 1);

  /* External mode info */
  GRM_HIL_M->Sizes.checksums[0] = (570376731U);
  GRM_HIL_M->Sizes.checksums[1] = (3218908344U);
  GRM_HIL_M->Sizes.checksums[2] = (2362734571U);
  GRM_HIL_M->Sizes.checksums[3] = (746257819U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[102];
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
    systemRan[19] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC_g;
    systemRan[20] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass.Enabledpass_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&GRM_HIL_DW.Saturation.Saturation_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&GRM_HIL_DW.Saturation.Saturation_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&GRM_HIL_DW.pass.pass_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC_o;
    systemRan[26] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass_k.Enabledpass_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_l.Saturation_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_l.Saturation_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&GRM_HIL_DW.pass_p.pass_SubsysRanBC;
    systemRan[30] = (sysRanDType *)&GRM_HIL_DW.Control_Limits_SubsysRanBC;
    systemRan[31] = (sysRanDType *)&GRM_HIL_DW.pass_SubsysRanBC;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass_d.Enabledpass_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_n.Saturation_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_n.Saturation_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&GRM_HIL_DW.pass_e.pass_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&GRM_HIL_DW.IfActionPass_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem_k.IfActionSubsystem_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC;
    systemRan[45] = (sysRanDType *)&GRM_HIL_DW.IfActionlimit_pitch_SubsysRanBC;
    systemRan[46] = (sysRanDType *)&GRM_HIL_DW.IfActionlimit_roll_SubsysRanBC;
    systemRan[47] = (sysRanDType *)&GRM_HIL_DW.IfActionlimit_yaw_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &GRM_HIL_DW.IfActionpass_roll.IfActionpass_yaw_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC;
    systemRan[51] = (sysRanDType *)&GRM_HIL_DW.Voltage_Limitations_SubsysRanBC;
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
    systemRan[101] = (sysRanDType *)
      &GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC;
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
    dtInfo.numDataTypes = 121;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_M->Sizes.numContStates = (51);/* Number of continuous states */
  GRM_HIL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (4); /* Number of sample times */
  GRM_HIL_M->Sizes.numBlocks = (2303); /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (232); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (117876);/* Sum of parameter "widths" */
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

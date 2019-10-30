/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.42
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Oct 30 19:55:07 2019
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

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
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
  int_T nXc = 55;
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

/* Model output function */
void GRM_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_Add_pi;
  boolean_T rtb_Compare_i;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Compare_k;
  real_T rtb_Sum_dr;
  real_T rtb_Sum_i;
  real_T rtb_Sum_o;
  int_T cj;
  real_T rtb_Fin_1_Pos_rad;
  real_T rtb_Fin_2_Pos_rad;
  real_T rtb_Fin_3_Pos_rad;
  real_T rtb_Fin_4_Pos_rad;
  real_T rtb_Abs_lo;
  real_T rtb_q_B_radDs;
  real_T rtb_r_B_radDs;
  real_T rtb_ACC_y_B_mDs2;
  real_T rtb_ACC_z_B_mDs2;
  real_T rtb_PulseGenerator1;
  real_T rtb_PulseGenerator;
  real_T rtb_p_B_radDs;
  real_T rtb_ProportionalGain;
  real_T rtb_DerivativeGain;
  real_T rtb_ProportionalGain_nx;
  real_T rtb_DerivativeGain_a;
  real_T rtb_ProportionalGain_c;
  real_T rtb_DerivativeGain_f;
  real_T rtb_Abs_i;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator1;
  boolean_T rtb_RelationalOperator2;
  real_T rtb_Add_g;
  real_T rtb_Sum_p3;
  int8_T rtAction;
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
  srClearBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_b);

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
  srClearBC(GRM_HIL_DW.Drag_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Gravity_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Subsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.hold_time_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Propulsion_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);

  /* Outputs for Enabled SubSystem: '<S197>/Propulsion' incorporates:
   *  EnablePort: '<S203>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S7>/Constant4' */
    if (GRM_HIL_P.Constant4_Value_g) {
      GRM_HIL_DW.Propulsion_MODE = true;
    } else {
      if (GRM_HIL_DW.Propulsion_MODE) {
        /* Disable for Enabled SubSystem: '<S203>/hold_time' */
        GRM_HIL_DW.hold_time_MODE = false;

        /* End of Disable for SubSystem: '<S203>/hold_time' */

        /* Disable for Enabled SubSystem: '<S203>/Subsystem' */
        if (GRM_HIL_DW.Subsystem_MODE) {
          /* Disable for Outport: '<S210>/thrust' */
          GRM_HIL_B.OutportBufferForthrust = GRM_HIL_P.thrust_Y0;
          GRM_HIL_DW.Subsystem_MODE = false;
        }

        /* End of Disable for SubSystem: '<S203>/Subsystem' */

        /* Disable for Outport: '<S203>/motor_state_perc_dot' */
        GRM_HIL_B.OutportBufferFormotor_state_perc_dot =
          GRM_HIL_P.motor_state_perc_dot_Y0;
        GRM_HIL_DW.Propulsion_MODE = false;
      }
    }

    /* End of Constant: '<S7>/Constant4' */
  }

  if (GRM_HIL_DW.Propulsion_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S203>/lock' */
      GRM_HIL_B.lock = GRM_HIL_DW.lock_PreviousInput;
    }

    /* Step: '<S2>/Step' */
    if (GRM_HIL_M->Timing.t[0] <
        GRM_HIL_P.External_Inputs_External_Inputs.FDM.Motor_Ignition_time_s) {
      rtb_Add_g = GRM_HIL_P.Step_Y0;
    } else {
      rtb_Add_g = GRM_HIL_P.Step_YFinal;
    }

    /* End of Step: '<S2>/Step' */

    /* Logic: '<S203>/Logical Operator1' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    GRM_HIL_B.LogicalOperator1_ii = ((rtb_Add_g != 0.0) || GRM_HIL_B.lock);

    /* Logic: '<S203>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_h = !GRM_HIL_B.LogicalOperator1_ii;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S211>/Enable' */
      GRM_HIL_B.HiddenBuf_InsertedFor_hold_time_at_inport_0 =
        GRM_HIL_B.LogicalOperator_h;

      /* Outputs for Enabled SubSystem: '<S203>/hold_time' incorporates:
       *  EnablePort: '<S211>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        GRM_HIL_DW.hold_time_MODE =
          GRM_HIL_B.HiddenBuf_InsertedFor_hold_time_at_inport_0;
      }

      /* End of Outputs for SubSystem: '<S203>/hold_time' */
    }

    /* Outputs for Enabled SubSystem: '<S203>/hold_time' incorporates:
     *  EnablePort: '<S211>/Enable'
     */
    if (GRM_HIL_DW.hold_time_MODE) {
      /* Clock: '<S211>/Clock' */
      GRM_HIL_B.Clock = GRM_HIL_M->Timing.t[0];
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.hold_time_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S203>/hold_time' */

    /* Sum: '<S203>/Add' incorporates:
     *  Clock: '<S203>/Clock'
     */
    rtb_Add_g = GRM_HIL_M->Timing.t[0] - GRM_HIL_B.Clock;

    /* Logic: '<S203>/Logical Operator2' incorporates:
     *  Constant: '<S209>/Constant'
     *  RelationalOperator: '<S209>/Compare'
     */
    GRM_HIL_B.LogicalOperator2_m = (GRM_HIL_B.LogicalOperator1_ii && (rtb_Add_g <
      GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.Propulsion.burntime_s));
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S210>/Enable' */
      GRM_HIL_B.HiddenBuf_InsertedFor_Subsystem_at_inport_1 =
        GRM_HIL_B.LogicalOperator2_m;

      /* Outputs for Enabled SubSystem: '<S203>/Subsystem' incorporates:
       *  EnablePort: '<S210>/Enable'
       */
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        if (GRM_HIL_B.HiddenBuf_InsertedFor_Subsystem_at_inport_1) {
          GRM_HIL_DW.Subsystem_MODE = true;
        } else {
          if (GRM_HIL_DW.Subsystem_MODE) {
            /* Disable for Outport: '<S210>/thrust' */
            GRM_HIL_B.OutportBufferForthrust = GRM_HIL_P.thrust_Y0;
            GRM_HIL_DW.Subsystem_MODE = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S203>/Subsystem' */
    }

    /* Outputs for Enabled SubSystem: '<S203>/Subsystem' incorporates:
     *  EnablePort: '<S210>/Enable'
     */
    if (GRM_HIL_DW.Subsystem_MODE) {
      if (rtmIsMajorTimeStep(GRM_HIL_M) &&
          GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
        /* SignalConversion generated from: '<S210>/thrust' incorporates:
         *  Constant: '<S210>/Constant'
         */
        GRM_HIL_B.OutportBufferForthrust =
          GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.Propulsion.thrust_avg_N;
      }

      /* Sum: '<S210>/Add1' incorporates:
       *  Constant: '<S210>/Constant1'
       *  Constant: '<S210>/Constant2'
       *  Product: '<S210>/Divide'
       */
      GRM_HIL_B.Add1 = GRM_HIL_P.Constant2_Value_d - rtb_Add_g /
        GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.Propulsion.burntime_s;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Subsystem_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S203>/Subsystem' */

    /* SignalConversion generated from: '<S203>/motor_state_perc_dot' */
    GRM_HIL_B.OutportBufferFormotor_state_perc_dot = GRM_HIL_B.Add1;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Propulsion_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S197>/Propulsion' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S189>/Gain18' incorporates:
     *  Constant: '<S5>/Constant18'
     */
    GRM_HIL_B.motor_state_perc = GRM_HIL_P.Gain18_Gain *
      GRM_HIL_P.Initial_States_Airframe.motor_state_perc;

    /* Gain: '<S189>/Gain9' incorporates:
     *  Constant: '<S5>/Constant9'
     */
    GRM_HIL_B.ATT_Phi_rad = GRM_HIL_P.Gain9_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Att.ATT_Phi_rad;
  }

  /* Integrator: '<S217>/Integrator' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator_Reset_ZCE != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator_IWORK != 0)) {
      GRM_HIL_X.Integrator_CSTATE = GRM_HIL_B.motor_state_perc;
    }
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S189>/Gain10' incorporates:
     *  Constant: '<S5>/Constant10'
     */
    GRM_HIL_B.ATT_Theta_rad = GRM_HIL_P.Gain10_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Att.ATT_Theta_rad;
  }

  /* Integrator: '<S215>/Integrator' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_f != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_f = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator_IWORK_i != 0)) {
      GRM_HIL_X.Integrator_CSTATE_k = GRM_HIL_B.ATT_Phi_rad;
    }
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S189>/Gain11' incorporates:
     *  Constant: '<S5>/Constant11'
     */
    GRM_HIL_B.ATT_Psi_rad = GRM_HIL_P.Gain11_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Att.ATT_Psi_rad;
  }

  /* Integrator: '<S215>/Integrator1' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Integrator: '<S215>/Integrator2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator1_IWORK != 0)) {
      GRM_HIL_X.Integrator1_CSTATE = GRM_HIL_B.ATT_Theta_rad;
    }

    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator2_IWORK != 0)) {
      GRM_HIL_X.Integrator2_CSTATE = GRM_HIL_B.ATT_Psi_rad;
    }
  }

  /* Outputs for Enabled SubSystem: '<S197>/Gravity' incorporates:
   *  EnablePort: '<S201>/Enable'
   */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (GRM_HIL_M)) {
    /* Constant: '<S7>/Constant6' */
    if (GRM_HIL_P.Constant6_Value_k) {
      GRM_HIL_DW.Gravity_MODE = true;
    } else {
      if (GRM_HIL_DW.Gravity_MODE) {
        /* Disable for Outport: '<S201>/acc_x_grav_mDs' */
        GRM_HIL_B.acc_x = GRM_HIL_P.acc_x_grav_mDs_Y0;

        /* Disable for Outport: '<S201>/acc_y_grav_mDs' */
        GRM_HIL_B.acc_y = GRM_HIL_P.acc_y_grav_mDs_Y0;

        /* Disable for Outport: '<S201>/acc_z_grav_mDs' */
        GRM_HIL_B.acc_z = GRM_HIL_P.acc_z_grav_mDs_Y0;
        GRM_HIL_DW.Gravity_MODE = false;
      }
    }

    /* End of Constant: '<S7>/Constant6' */
  }

  if (GRM_HIL_DW.Gravity_MODE) {
    /* MATLAB Function: '<S201>/MATLAB Function' incorporates:
     *  Constant: '<S201>/Constant1'
     *  Integrator: '<S215>/Integrator'
     *  Integrator: '<S215>/Integrator1'
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

  /* End of Outputs for SubSystem: '<S197>/Gravity' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S197>/Drag' incorporates:
     *  EnablePort: '<S200>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      /* Constant: '<S7>/Constant5' */
      if (GRM_HIL_P.Constant5_Value_k) {
        GRM_HIL_DW.Drag_MODE = true;
      } else {
        if (GRM_HIL_DW.Drag_MODE) {
          /* Disable for Outport: '<S200>/acc_x_drag_mDs2' */
          GRM_HIL_B.OutportBufferForacc_x_drag_mDs2 =
            GRM_HIL_P.acc_x_drag_mDs2_Y0;

          /* Disable for Outport: '<S200>/acc_y_drag_mDs2' */
          GRM_HIL_B.OutportBufferForacc_y_drag_mDs2 =
            GRM_HIL_P.acc_y_drag_mDs2_Y0;

          /* Disable for Outport: '<S200>/acc_z_drag_mDs2' */
          GRM_HIL_B.OutportBufferForacc_z_drag_mDs2 =
            GRM_HIL_P.acc_z_drag_mDs2_Y0;
          GRM_HIL_DW.Drag_MODE = false;
        }
      }

      /* End of Constant: '<S7>/Constant5' */
    }

    if (GRM_HIL_DW.Drag_MODE) {
      /* SignalConversion generated from: '<S200>/acc_x_drag_mDs2' incorporates:
       *  Constant: '<S200>/Constant'
       */
      GRM_HIL_B.OutportBufferForacc_x_drag_mDs2 = GRM_HIL_P.Constant_Value_d;

      /* SignalConversion generated from: '<S200>/acc_y_drag_mDs2' incorporates:
       *  Constant: '<S200>/Constant1'
       */
      GRM_HIL_B.OutportBufferForacc_y_drag_mDs2 = GRM_HIL_P.Constant1_Value;

      /* SignalConversion generated from: '<S200>/acc_z_drag_mDs2' incorporates:
       *  Constant: '<S200>/Constant2'
       */
      GRM_HIL_B.OutportBufferForacc_z_drag_mDs2 = GRM_HIL_P.Constant2_Value;
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Drag_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S197>/Drag' */
  }

  /* Sum: '<S197>/Add' incorporates:
   *  Constant: '<S216>/Constant'
   *  Constant: '<S216>/Constant1'
   *  Integrator: '<S217>/Integrator'
   *  Product: '<S197>/Divide'
   *  Product: '<S216>/Multiply'
   *  Sum: '<S216>/Add'
   */
  rtb_Add_g = (GRM_HIL_B.OutportBufferForthrust /
               ((GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.mass_preburn_kg -
                 GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.mass_kg) *
                GRM_HIL_X.Integrator_CSTATE +
                GRM_HIL_P.FDM_Linear_FDM.Configuration_Data.mass_kg) +
               GRM_HIL_B.acc_x) + GRM_HIL_B.OutportBufferForacc_x_drag_mDs2;

  /* Gain: '<S195>/Gain3' */
  GRM_HIL_B.ACC_x_B_mDs2 = GRM_HIL_P.Gain3_Gain_n * rtb_Add_g;

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
    GRM_HIL_P.Gain2_Gain_g;

  /* Gain: '<S11>/Gain3' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn3'
   */
  rtb_Fin_4_Pos_rad = (rtb_Fin_4_Pos_rad * GRM_HIL_X.TransferFcn3_CSTATE[1] +
                       0.0 * GRM_HIL_X.TransferFcn3_CSTATE[0]) *
    GRM_HIL_P.Gain3_Gain_d;

  /* Sum: '<S204>/Add18' incorporates:
   *  Constant: '<S204>/Constant4'
   *  Integrator: '<S215>/Integrator'
   *  Sum: '<S204>/Add13'
   */
  rtb_ACC_z_B_mDs2 = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f1_rad;

  /* Sum: '<S204>/Add20' incorporates:
   *  Constant: '<S204>/Constant5'
   *  Integrator: '<S215>/Integrator'
   *  Sum: '<S204>/Add14'
   */
  rtb_p_B_radDs = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f2_rad;

  /* Sum: '<S204>/Add23' incorporates:
   *  Constant: '<S204>/Constant6'
   *  Integrator: '<S215>/Integrator'
   *  Sum: '<S204>/Add15'
   */
  rtb_q_B_radDs = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f3_rad;

  /* Sum: '<S204>/Add22' incorporates:
   *  Constant: '<S204>/Constant7'
   *  Integrator: '<S215>/Integrator'
   *  Sum: '<S204>/Add16'
   */
  rtb_r_B_radDs = GRM_HIL_X.Integrator_CSTATE_k +
    GRM_HIL_P.ReverseFinDeflection_Control_Surfaces.phi_f4_rad;

  /* Gain: '<S204>/Gain2' incorporates:
   *  Fcn: '<S204>/Fcn12'
   *  Fcn: '<S204>/Fcn13'
   *  Fcn: '<S204>/Fcn15'
   *  Fcn: '<S204>/Fcn16'
   *  Product: '<S204>/Multiply12'
   *  Product: '<S204>/Multiply13'
   *  Product: '<S204>/Multiply14'
   *  Product: '<S204>/Multiply15'
   *  Sum: '<S204>/Add18'
   *  Sum: '<S204>/Add19'
   *  Sum: '<S204>/Add20'
   *  Sum: '<S204>/Add22'
   *  Sum: '<S204>/Add23'
   */
  GRM_HIL_B.Gain2 = (((-cos(rtb_ACC_z_B_mDs2) * rtb_Fin_1_Pos_rad + -cos
                       (rtb_p_B_radDs) * rtb_Fin_2_Pos_rad) + -cos(rtb_q_B_radDs)
                      * rtb_Fin_3_Pos_rad) + -cos(rtb_r_B_radDs) *
                     rtb_Fin_4_Pos_rad) * GRM_HIL_P.Gain2_Gain_a;

  /* TransferFcn: '<S197>/dy2ay' */
  rtb_ACC_y_B_mDs2 = GRM_HIL_P.FDM_Linear_TF.dy2ay.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0];

  /* Sum: '<S197>/Add1' incorporates:
   *  TransferFcn: '<S197>/dy2ay'
   */
  rtb_ACC_y_B_mDs2 = ((((GRM_HIL_P.FDM_Linear_TF.dy2ay.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] - rtb_ACC_y_B_mDs2 *
    (GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[1] /
     GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0])) * GRM_HIL_X.dy2ay_CSTATE[0] +
                        GRM_HIL_P.FDM_Linear_TF.dy2ay.num[0] /
                        GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] * GRM_HIL_B.Gain2)
                       + (GRM_HIL_P.FDM_Linear_TF.dy2ay.num[2] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] - rtb_ACC_y_B_mDs2 *
    (GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[2] /
     GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0])) * GRM_HIL_X.dy2ay_CSTATE[1]) +
                      GRM_HIL_B.acc_y) +
    GRM_HIL_B.OutportBufferForacc_y_drag_mDs2;

  /* Gain: '<S195>/Gain4' */
  GRM_HIL_B.ACC_y_B_mDs2 = GRM_HIL_P.Gain4_Gain * rtb_ACC_y_B_mDs2;

  /* Gain: '<S204>/Gain1' incorporates:
   *  Fcn: '<S204>/Fcn10'
   *  Fcn: '<S204>/Fcn11'
   *  Fcn: '<S204>/Fcn8'
   *  Fcn: '<S204>/Fcn9'
   *  Product: '<S204>/Multiply10'
   *  Product: '<S204>/Multiply11'
   *  Product: '<S204>/Multiply8'
   *  Product: '<S204>/Multiply9'
   *  Sum: '<S204>/Add17'
   */
  GRM_HIL_B.Gain1 = (((sin(rtb_ACC_z_B_mDs2) * rtb_Fin_1_Pos_rad + sin
                       (rtb_p_B_radDs) * rtb_Fin_2_Pos_rad) + sin(rtb_q_B_radDs)
                      * rtb_Fin_3_Pos_rad) + sin(rtb_r_B_radDs) *
                     rtb_Fin_4_Pos_rad) * GRM_HIL_P.Gain1_Gain_n;

  /* TransferFcn: '<S197>/dp2az' */
  rtb_ACC_z_B_mDs2 = GRM_HIL_P.FDM_Linear_TF.dp2az.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0];

  /* Sum: '<S197>/Add2' incorporates:
   *  TransferFcn: '<S197>/dp2az'
   */
  rtb_ACC_z_B_mDs2 = ((((GRM_HIL_P.FDM_Linear_TF.dp2az.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] - rtb_ACC_z_B_mDs2 *
    (GRM_HIL_P.FDM_Linear_TF.dp2az.denom[1] /
     GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0])) * GRM_HIL_X.dp2az_CSTATE[0] +
                        GRM_HIL_P.FDM_Linear_TF.dp2az.num[0] /
                        GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] * GRM_HIL_B.Gain1)
                       + (GRM_HIL_P.FDM_Linear_TF.dp2az.num[2] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] - rtb_ACC_z_B_mDs2 *
    (GRM_HIL_P.FDM_Linear_TF.dp2az.denom[2] /
     GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0])) * GRM_HIL_X.dp2az_CSTATE[1]) +
                      GRM_HIL_B.acc_z) +
    GRM_HIL_B.OutportBufferForacc_z_drag_mDs2;

  /* Gain: '<S195>/Gain5' */
  GRM_HIL_B.ACC_z_B_mDs2 = GRM_HIL_P.Gain5_Gain * rtb_ACC_z_B_mDs2;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S195>/Gain9' incorporates:
   *  Integrator: '<S215>/Integrator'
   */
  GRM_HIL_B.ATT_Phi_rad_l = GRM_HIL_P.Gain9_Gain_b *
    GRM_HIL_X.Integrator_CSTATE_k;

  /* Gain: '<S195>/Gain10' incorporates:
   *  Integrator: '<S215>/Integrator1'
   */
  GRM_HIL_B.ATT_Theta_rad_k = GRM_HIL_P.Gain10_Gain_f *
    GRM_HIL_X.Integrator1_CSTATE;

  /* Gain: '<S195>/Gain11' incorporates:
   *  Integrator: '<S215>/Integrator2'
   */
  GRM_HIL_B.ATT_Psi_rad_j = GRM_HIL_P.Gain11_Gain_d *
    GRM_HIL_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscretePulseGenerator: '<S16>/Pulse Generator1' */
    rtb_PulseGenerator1 = (GRM_HIL_DW.clockTickCounter <
      GRM_HIL_P.PulseGenerator1_Duty) && (GRM_HIL_DW.clockTickCounter >= 0) ?
      GRM_HIL_P.PulseGenerator1_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter >= GRM_HIL_P.PulseGenerator1_Period - 1.0) {
      GRM_HIL_DW.clockTickCounter = 0;
    } else {
      GRM_HIL_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S16>/Pulse Generator1' */

    /* DiscretePulseGenerator: '<S16>/Pulse Generator' */
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

    /* End of DiscretePulseGenerator: '<S16>/Pulse Generator' */

    /* Switch: '<S16>/Switch1' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant2'
     *  Product: '<S16>/Multiply'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.pulse_cmd_flg >
        GRM_HIL_P.Switch1_Threshold) {
      /* Switch: '<S16>/Switch3' incorporates:
       *  Constant: '<S16>/Constant12'
       *  Constant: '<S16>/Constant6'
       *  Constant: '<S16>/Constant7'
       *  Sum: '<S16>/Add'
       */
      if (GRM_HIL_P.Constant6_Value_b) {
        rtb_PulseGenerator1 += GRM_HIL_P.Constant12_Value;
      } else {
        rtb_PulseGenerator1 = GRM_HIL_P.Constant7_Value;
      }

      /* End of Switch: '<S16>/Switch3' */
      GRM_HIL_B.Switch1 = rtb_PulseGenerator1 * rtb_PulseGenerator;
    } else {
      GRM_HIL_B.Switch1 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.roll.constant.phi_rad;
    }

    /* End of Switch: '<S16>/Switch1' */

    /* DiscretePulseGenerator: '<S16>/Pulse Generator4' */
    rtb_PulseGenerator1 = (GRM_HIL_DW.clockTickCounter_d3 <
      GRM_HIL_P.PulseGenerator4_Duty) && (GRM_HIL_DW.clockTickCounter_d3 >= 0) ?
      GRM_HIL_P.PulseGenerator4_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter_d3 >= GRM_HIL_P.PulseGenerator4_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_d3 = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_d3++;
    }

    /* End of DiscretePulseGenerator: '<S16>/Pulse Generator4' */

    /* DiscretePulseGenerator: '<S16>/Pulse Generator3' */
    rtb_PulseGenerator = (GRM_HIL_DW.clockTickCounter_e <
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

    /* End of DiscretePulseGenerator: '<S16>/Pulse Generator3' */

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  Constant: '<S16>/Constant3'
     *  Product: '<S16>/Multiply1'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.pulse_cmd_flg >
        GRM_HIL_P.Switch_Threshold) {
      /* Switch: '<S16>/Switch4' incorporates:
       *  Constant: '<S16>/Constant13'
       *  Constant: '<S16>/Constant8'
       *  Constant: '<S16>/Constant9'
       *  Sum: '<S16>/Add1'
       */
      if (GRM_HIL_P.Constant8_Value_e) {
        rtb_PulseGenerator1 += GRM_HIL_P.Constant13_Value;
      } else {
        rtb_PulseGenerator1 = GRM_HIL_P.Constant9_Value;
      }

      /* End of Switch: '<S16>/Switch4' */
      GRM_HIL_B.Switch = rtb_PulseGenerator1 * rtb_PulseGenerator;
    } else {
      GRM_HIL_B.Switch =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.pitch.constant.acc_z_mDs2;
    }

    /* End of Switch: '<S16>/Switch' */

    /* DiscretePulseGenerator: '<S16>/Pulse Generator7' */
    rtb_PulseGenerator1 = (GRM_HIL_DW.clockTickCounter_o <
      GRM_HIL_P.PulseGenerator7_Duty) && (GRM_HIL_DW.clockTickCounter_o >= 0) ?
      GRM_HIL_P.PulseGenerator7_Amp : 0.0;
    if (GRM_HIL_DW.clockTickCounter_o >= GRM_HIL_P.PulseGenerator7_Period - 1.0)
    {
      GRM_HIL_DW.clockTickCounter_o = 0;
    } else {
      GRM_HIL_DW.clockTickCounter_o++;
    }

    /* End of DiscretePulseGenerator: '<S16>/Pulse Generator7' */

    /* DiscretePulseGenerator: '<S16>/Pulse Generator6' */
    rtb_PulseGenerator = (GRM_HIL_DW.clockTickCounter_l <
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

    /* End of DiscretePulseGenerator: '<S16>/Pulse Generator6' */

    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S16>/Constant4'
     *  Constant: '<S16>/Constant5'
     *  Product: '<S16>/Multiply2'
     */
    if (GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.pulse_cmd_flg >
        GRM_HIL_P.Switch2_Threshold) {
      /* Switch: '<S16>/Switch5' incorporates:
       *  Constant: '<S16>/Constant10'
       *  Constant: '<S16>/Constant11'
       *  Constant: '<S16>/Constant14'
       *  Sum: '<S16>/Add2'
       */
      if (GRM_HIL_P.Constant10_Value_c) {
        rtb_PulseGenerator1 += GRM_HIL_P.Constant14_Value;
      } else {
        rtb_PulseGenerator1 = GRM_HIL_P.Constant11_Value;
      }

      /* End of Switch: '<S16>/Switch5' */
      GRM_HIL_B.Switch2 = rtb_PulseGenerator1 * rtb_PulseGenerator;
    } else {
      GRM_HIL_B.Switch2 =
        GRM_HIL_P.External_Inputs_External_Inputs.FCC.CMD.yaw.constant.acc_y_mDs2;
    }

    /* End of Switch: '<S16>/Switch2' */
  }

  /* TransferFcn: '<S197>/dr2roll' */
  rtb_p_B_radDs = GRM_HIL_P.FDM_Linear_TF.dr2roll.num /
    GRM_HIL_P.FDM_Linear_TF.dr2roll.denom[0] * GRM_HIL_X.dr2roll_CSTATE;

  /* Gain: '<S195>/Gain6' */
  GRM_HIL_B.w_x_K_IB_B_radDs = GRM_HIL_P.Gain6_Gain * rtb_p_B_radDs;

  /* TransferFcn: '<S197>/dp2pitch' */
  rtb_q_B_radDs = GRM_HIL_P.FDM_Linear_TF.dp2pitch.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[0] +
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[1];

  /* Gain: '<S195>/Gain7' */
  GRM_HIL_B.w_y_K_IB_B_radDs = GRM_HIL_P.Gain7_Gain * rtb_q_B_radDs;

  /* TransferFcn: '<S197>/dy2yaw' */
  rtb_r_B_radDs = GRM_HIL_P.FDM_Linear_TF.dy2yaw.num[0] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[0] +
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.num[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[1];

  /* Gain: '<S195>/Gain8' */
  GRM_HIL_B.w_z_K_IB_B_radDs = GRM_HIL_P.Gain8_Gain * rtb_r_B_radDs;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S38>/Data Type Conversion1' incorporates:
     *  Logic: '<S38>/Logical Operator2'
     *  Logic: '<S38>/Logical Operator3'
     *  Memory generated from: '<S36>/Memory'
     */
    GRM_HIL_B.Gimbal_operational_flg = (GRM_HIL_DW.Memory_1_PreviousInput &&
      (!GRM_HIL_DW.Memory_2_PreviousInput));

    /* Constant: '<S38>/Constant1' */
    GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_P.Constant1_Value_b;

    /* Constant: '<S38>/Constant2' */
    GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_P.Constant2_Value_c;

    /* Gain: '<S45>/Shaft2degYaw' incorporates:
     *  Memory generated from: '<S36>/Memory1'
     */
    GRM_HIL_B.yaw_deg = GRM_HIL_P.Shaft2degYaw_Gain *
      GRM_HIL_DW.Memory1_1_PreviousInput;
  }

  /* TransferFcn: '<S49>/Transfer Fcn1' */
  rtb_Abs_lo = GRM_HIL_P.TransferFcn1_C[0] * GRM_HIL_X.TransferFcn1_CSTATE_d[0]
    + GRM_HIL_P.TransferFcn1_C[1] * GRM_HIL_X.TransferFcn1_CSTATE_d[1];

  /* Sum: '<S49>/Subtract' incorporates:
   *  Constant: '<S49>/Constant2'
   */
  rtb_Add_pi = rtb_Abs_lo - GRM_HIL_P.Constant2_Value_h;

  /* Abs: '<S49>/Abs' */
  rtb_Add_pi = fabs(rtb_Add_pi);

  /* DataTypeConversion: '<S38>/Data Type Conversion' incorporates:
   *  Constant: '<S173>/Constant'
   *  Logic: '<S38>/Logical Operator'
   *  RelationalOperator: '<S173>/Compare'
   */
  GRM_HIL_B.Gimbal_Ramp_flg = !(rtb_Add_pi < GRM_HIL_P.CompareToConstant_const);

  /* TransportDelay: '<S176>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Add_pi = rt_TDelayInterpolate(
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
    (GRM_HIL_B.yaw_deg - rtb_Add_pi);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S45>/Shaft2degPitch' incorporates:
     *  Memory generated from: '<S36>/Memory1'
     */
    GRM_HIL_B.pitch_deg = GRM_HIL_P.Shaft2degPitch_Gain *
      GRM_HIL_DW.Memory1_2_PreviousInput;
  }

  /* TransportDelay: '<S174>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Add_pi = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK_i.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK_i.Last,
      GRM_HIL_DW.TransportDelay_IWORK_i.Tail,
      GRM_HIL_DW.TransportDelay_IWORK_i.Head,
      GRM_HIL_P.TransportDelay_InitOutput_j,
      1,
      0);
  }

  /* Gain: '<S174>/Gain' incorporates:
   *  Sum: '<S174>/Sum'
   */
  GRM_HIL_B.Gain_h = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.pitch_deg - rtb_Add_pi);
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S45>/Shaft2degRoll' incorporates:
     *  Memory generated from: '<S36>/Memory1'
     */
    GRM_HIL_B.roll_deg = GRM_HIL_P.Shaft2degRoll_Gain *
      GRM_HIL_DW.Memory1_3_PreviousInput;
  }

  /* TransportDelay: '<S175>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    real_T tMinusDelay = simTime - (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck);
    rtb_Add_pi = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      GRM_HIL_DW.TransportDelay_IWORK_k.CircularBufSize,
      &GRM_HIL_DW.TransportDelay_IWORK_k.Last,
      GRM_HIL_DW.TransportDelay_IWORK_k.Tail,
      GRM_HIL_DW.TransportDelay_IWORK_k.Head,
      GRM_HIL_P.TransportDelay_InitOutput_g,
      1,
      0);
  }

  /* Gain: '<S175>/Gain' incorporates:
   *  Sum: '<S175>/Sum'
   */
  GRM_HIL_B.Gain_j = 1.0 / GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.MaxCheck *
    (GRM_HIL_B.roll_deg - rtb_Add_pi);

  /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  /* Abs: '<S72>/Abs' incorporates:
   *  Abs: '<S176>/Abs'
   *  Abs: '<S52>/Abs'
   */
  rtb_PulseGenerator = fabs(GRM_HIL_B.Gain);

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */

  /* RelationalOperator: '<S167>/Compare' incorporates:
   *  Abs: '<S72>/Abs'
   *  Constant: '<S167>/Constant'
   */
  rtb_Compare_i = (rtb_PulseGenerator >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S72>/Enabled pass' */
  /* Constant: '<S72>/const_upper_limit' incorporates:
   *  Constant: '<S72>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_i,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMinVolt,
                      &GRM_HIL_B.Merge, &GRM_HIL_B.Merge1,
                      &GRM_HIL_DW.Enabledpass_a);

  /* End of Outputs for SubSystem: '<S72>/Enabled pass' */

  /* Logic: '<S72>/Logical Operator' */
  GRM_HIL_B.LogicalOperator = !rtb_Compare_i;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S168>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3 =
      GRM_HIL_B.LogicalOperator;

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
    rtb_Abs_i = GRM_HIL_B.Abs / rtb_PulseGenerator *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_limit_adaption_coef - 1.0);

    /* Product: '<S168>/Product' incorporates:
     *  Constant: '<S72>/const_upper_limit'
     */
    GRM_HIL_B.Merge = rtb_Abs_i *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;

    /* Product: '<S168>/Product1' incorporates:
     *  Constant: '<S72>/const_lower_limit'
     */
    GRM_HIL_B.Merge1 = rtb_Abs_i *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S72>/Enabled adapt' */

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S72>/Constant2'
   */
  if (GRM_HIL_B.Gain > GRM_HIL_P.Switch2_Threshold_l) {
    GRM_HIL_B.Switch2_p = GRM_HIL_B.Merge;
  } else {
    GRM_HIL_B.Switch2_p = GRM_HIL_P.Constant2_Value_o;
  }

  /* End of Switch: '<S72>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S72>/Gain' incorporates:
     *  Constant: '<S72>/Constant2'
     */
    GRM_HIL_B.Gain_e = GRM_HIL_P.Gain_Gain_a * GRM_HIL_P.Constant2_Value_o;
  }

  /* Switch: '<S72>/Switch1' */
  if (GRM_HIL_B.Gain > GRM_HIL_P.Switch1_Threshold_k) {
    GRM_HIL_B.Switch1_h = GRM_HIL_B.Gain_e;
  } else {
    GRM_HIL_B.Switch1_h = GRM_HIL_B.Merge1;
  }

  /* End of Switch: '<S72>/Switch1' */

  /* Gain: '<S192>/rad2deg' */
  GRM_HIL_B.Gimbal_Phi_Cmd_deg = GRM_HIL_P.rad2deg_Gain *
    GRM_HIL_B.ATT_Phi_rad_l;

  /* Product: '<S48>/Product' */
  GRM_HIL_B.Product = rtb_Abs_lo * GRM_HIL_B.Gimbal_Phi_Cmd_deg;

  /* Sum: '<S48>/Sum' */
  GRM_HIL_B.Yaw_err = GRM_HIL_B.Product - GRM_HIL_B.yaw_deg;
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
  GRM_HIL_B.Integrator = GRM_HIL_X.Integrator_CSTATE_c;

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
    rtb_Sum_dr = (rtb_ProportionalGain + GRM_HIL_B.Integrator) +
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
    GRM_HIL_B.Switch_g = GRM_HIL_P.Constant1_Value_f;
  } else {
    GRM_HIL_B.Switch_g = (rtb_PulseGenerator >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_soft_limit_vel);
  }

  /* End of Switch: '<S72>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S170>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3 = GRM_HIL_B.Switch_g;

    /* Outputs for Enabled SubSystem: '<S73>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3,
                       GRM_HIL_B.Switch2_p, GRM_HIL_B.Switch1_h, rtb_Sum_dr,
                       &GRM_HIL_B.Merge_f, &GRM_HIL_DW.Saturation_e);

    /* End of Outputs for SubSystem: '<S73>/Saturation' */

    /* Logic: '<S73>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_o = !GRM_HIL_B.Switch_g;

    /* Outputs for Enabled SubSystem: '<S73>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_o, rtb_Sum_dr,
                 &GRM_HIL_B.Merge_f, &GRM_HIL_DW.pass_l);

    /* End of Outputs for SubSystem: '<S73>/pass' */

    /* Outputs for Enabled SubSystem: '<S71>/pass' incorporates:
     *  EnablePort: '<S75>/Enable'
     */
    /* Logic: '<S71>/Logical Operator' incorporates:
     *  Constant: '<S71>/Constant'
     *  Inport: '<S75>/Controller_Cmd'
     */
    if (!(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Limit_Controllers != 0.0)) {
      GRM_HIL_B.Merge_a = GRM_HIL_B.Merge_f;
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
    rtb_Abs_i = GRM_HIL_P.Constant_Value /
      ((GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV - GRM_HIL_B.Gain) *
       GRM_HIL_P.Gain2_Gain);

    /* Product: '<S74>/Divide1' incorporates:
     *  Constant: '<S74>/Constant2'
     *  Constant: '<S74>/Constant3'
     *  Gain: '<S74>/Gain3'
     *  Sum: '<S74>/Subtract1'
     */
    rtb_Add_pi = GRM_HIL_P.Constant3_Value / ((GRM_HIL_B.Gain -
      (-GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV)) * GRM_HIL_P.Gain3_Gain);

    /* Gain: '<S110>/Filter Coefficient' incorporates:
     *  Gain: '<S101>/Derivative Gain'
     *  Integrator: '<S102>/Filter'
     *  Sum: '<S102>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_f =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Derivative_Gain * rtb_Abs_i -
       GRM_HIL_X.Filter_CSTATE_p) * GRM_HIL_P.PIDController_N;

    /* Sum: '<S116>/Sum' incorporates:
     *  Gain: '<S112>/Proportional Gain'
     *  Integrator: '<S107>/Integrator'
     */
    rtb_DerivativeGain =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Proportional_Gain * rtb_Abs_i +
       GRM_HIL_X.Integrator_CSTATE_i) + GRM_HIL_B.FilterCoefficient_f;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_DerivativeGain > GRM_HIL_P.PIDController_UpperSaturationLimit) {
      rtb_PulseGenerator1 = GRM_HIL_P.PIDController_UpperSaturationLimit;
    } else if (rtb_DerivativeGain < GRM_HIL_P.PIDController_LowerSaturationLimit)
    {
      rtb_PulseGenerator1 = GRM_HIL_P.PIDController_LowerSaturationLimit;
    } else {
      rtb_PulseGenerator1 = rtb_DerivativeGain;
    }

    /* End of Saturate: '<S114>/Saturation' */

    /* Gain: '<S154>/Filter Coefficient' incorporates:
     *  Gain: '<S145>/Derivative Gain'
     *  Integrator: '<S146>/Filter'
     *  Sum: '<S146>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_j =
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Derivative_Gain * rtb_Add_pi -
       GRM_HIL_X.Filter_CSTATE_k) * GRM_HIL_P.PIDController1_N;

    /* Sum: '<S160>/Sum' incorporates:
     *  Gain: '<S156>/Proportional Gain'
     *  Integrator: '<S151>/Integrator'
     */
    rtb_Sum_p3 = (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Proportional_Gain *
                  rtb_Add_pi + GRM_HIL_X.Integrator_CSTATE_fq) +
      GRM_HIL_B.FilterCoefficient_j;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_Sum_p3 > GRM_HIL_P.PIDController1_UpperSaturationLimit) {
      rtb_ProportionalGain = GRM_HIL_P.PIDController1_UpperSaturationLimit;
    } else if (rtb_Sum_p3 < GRM_HIL_P.PIDController1_LowerSaturationLimit) {
      rtb_ProportionalGain = GRM_HIL_P.PIDController1_LowerSaturationLimit;
    } else {
      rtb_ProportionalGain = rtb_Sum_p3;
    }

    /* End of Saturate: '<S158>/Saturation' */

    /* Sum: '<S100>/SumI4' incorporates:
     *  Gain: '<S100>/Kb'
     *  Gain: '<S104>/Integral Gain'
     *  Sum: '<S100>/SumI2'
     */
    GRM_HIL_B.SumI4 = (rtb_PulseGenerator1 - rtb_DerivativeGain) *
      GRM_HIL_P.PIDController_Kb +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Integral_Gain * rtb_Abs_i;

    /* Sum: '<S144>/SumI4' incorporates:
     *  Gain: '<S144>/Kb'
     *  Gain: '<S148>/Integral Gain'
     *  Sum: '<S144>/SumI2'
     */
    GRM_HIL_B.SumI4_c = (rtb_ProportionalGain - rtb_Sum_p3) *
      GRM_HIL_P.PIDController1_Kb +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Integral_Gain * rtb_Add_pi;

    /* Sum: '<S74>/Sum' incorporates:
     *  Gain: '<S74>/Gain'
     *  Gain: '<S74>/Gain1'
     */
    GRM_HIL_B.Merge_a = (GRM_HIL_B.Merge_f -
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Weighting *
                         rtb_PulseGenerator1) +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Yaw_LC_Weighting * rtb_ProportionalGain;
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
  rtb_DerivativeGain = fabs(GRM_HIL_B.Gain_h);

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */

  /* RelationalOperator: '<S56>/Compare' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S56>/Constant'
   */
  rtb_Compare_o = (rtb_DerivativeGain >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S53>/Enabled pass' */
  /* Constant: '<S53>/const_upper_limit' incorporates:
   *  Constant: '<S53>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_o,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMinVolt,
                      &GRM_HIL_B.Merge_m, &GRM_HIL_B.Merge1_j,
                      &GRM_HIL_DW.Enabledpass);

  /* End of Outputs for SubSystem: '<S53>/Enabled pass' */

  /* Logic: '<S53>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_a = !rtb_Compare_o;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S57>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_h =
      GRM_HIL_B.LogicalOperator_a;

    /* Outputs for Enabled SubSystem: '<S53>/Enabled adapt' incorporates:
     *  EnablePort: '<S57>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE_n =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_h;
    }

    /* End of Outputs for SubSystem: '<S53>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S53>/Enabled adapt' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE_n) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S57>/Abs' incorporates:
       *  Constant: '<S57>/Constant'
       */
      GRM_HIL_B.Abs_b = fabs
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_hard_limit_vel);
    }

    /* Sum: '<S57>/Add' incorporates:
     *  Abs: '<S53>/Abs'
     *  Constant: '<S57>/Constant1'
     *  Gain: '<S57>/Gain'
     *  Product: '<S57>/Divide'
     */
    rtb_ProportionalGain = GRM_HIL_B.Abs_b / rtb_DerivativeGain *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_limit_adaption_coef - 1.0);

    /* Product: '<S57>/Product' incorporates:
     *  Constant: '<S53>/const_upper_limit'
     */
    GRM_HIL_B.Merge_m = rtb_ProportionalGain *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;

    /* Product: '<S57>/Product1' incorporates:
     *  Constant: '<S53>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_j = rtb_ProportionalGain *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_g);
    }
  }

  /* End of Outputs for SubSystem: '<S53>/Enabled adapt' */

  /* Switch: '<S53>/Switch2' incorporates:
   *  Constant: '<S53>/Constant2'
   */
  if (GRM_HIL_B.Gain_h > GRM_HIL_P.Switch2_Threshold_k) {
    GRM_HIL_B.Switch2_h = GRM_HIL_B.Merge_m;
  } else {
    GRM_HIL_B.Switch2_h = GRM_HIL_P.Constant2_Value_h5;
  }

  /* End of Switch: '<S53>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S53>/Gain' incorporates:
     *  Constant: '<S53>/Constant2'
     */
    GRM_HIL_B.Gain_hi = GRM_HIL_P.Gain_Gain_g * GRM_HIL_P.Constant2_Value_h5;
  }

  /* Switch: '<S53>/Switch1' */
  if (GRM_HIL_B.Gain_h > GRM_HIL_P.Switch1_Threshold_g) {
    GRM_HIL_B.Switch1_f = GRM_HIL_B.Gain_hi;
  } else {
    GRM_HIL_B.Switch1_f = GRM_HIL_B.Merge1_j;
  }

  /* End of Switch: '<S53>/Switch1' */

  /* Gain: '<S192>/rad2deg1' */
  GRM_HIL_B.Gimbal_Theta_Cmd_deg = GRM_HIL_P.rad2deg1_Gain *
    GRM_HIL_B.ATT_Theta_rad_k;

  /* Product: '<S46>/Product' */
  GRM_HIL_B.pitch_cmd = rtb_Abs_lo * GRM_HIL_B.Gimbal_Theta_Cmd_deg;

  /* Sum: '<S46>/Sum2' */
  GRM_HIL_B.pitch_err = GRM_HIL_B.pitch_cmd - GRM_HIL_B.pitch_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S54>/Proportional Gain' */
    rtb_ProportionalGain_nx =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Proportional_Gain *
      GRM_HIL_B.pitch_err;

    /* Gain: '<S54>/Derivative Gain' */
    rtb_DerivativeGain_a =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Derivative_Gain *
      GRM_HIL_B.pitch_err;
  }

  /* Integrator: '<S54>/Integrator' */
  GRM_HIL_B.Integrator_o = GRM_HIL_X.Integrator_CSTATE_n;

  /* Integrator: '<S54>/Filter' */
  GRM_HIL_B.Filter_m = GRM_HIL_X.Filter_CSTATE_i;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S54>/Filter Coefficient' incorporates:
     *  Sum: '<S54>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_a = (rtb_DerivativeGain_a - GRM_HIL_B.Filter_m) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Filter_Coefficient;

    /* Sum: '<S54>/Sum' */
    rtb_Sum_i = (rtb_ProportionalGain_nx + GRM_HIL_B.Integrator_o) +
      GRM_HIL_B.FilterCoefficient_a;

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
    GRM_HIL_B.Switch_a = GRM_HIL_P.Constant1_Value_m;
  } else {
    GRM_HIL_B.Switch_a = (rtb_DerivativeGain >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Pitch_soft_limit_vel);
  }

  /* End of Switch: '<S53>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S59>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_k =
      GRM_HIL_B.Switch_a;

    /* Outputs for Enabled SubSystem: '<S54>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_k,
                       GRM_HIL_B.Switch2_h, GRM_HIL_B.Switch1_f, rtb_Sum_i,
                       &GRM_HIL_B.Merge_fu, &GRM_HIL_DW.Saturation);

    /* End of Outputs for SubSystem: '<S54>/Saturation' */

    /* Logic: '<S54>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_n = !GRM_HIL_B.Switch_a;

    /* Outputs for Enabled SubSystem: '<S54>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_n, rtb_Sum_i,
                 &GRM_HIL_B.Merge_fu, &GRM_HIL_DW.pass);

    /* End of Outputs for SubSystem: '<S54>/pass' */
  }

  /* Outputs for Enabled SubSystem: '<S45>/Voltage_Limitations' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  /* Abs: '<S62>/Abs' incorporates:
   *  Abs: '<S175>/Abs'
   *  Abs: '<S52>/Abs4'
   */
  rtb_ProportionalGain_nx = fabs(GRM_HIL_B.Gain_j);

  /* End of Outputs for SubSystem: '<S45>/Voltage_Limitations' */

  /* RelationalOperator: '<S65>/Compare' incorporates:
   *  Abs: '<S62>/Abs'
   *  Constant: '<S65>/Constant'
   */
  rtb_Compare_k = (rtb_ProportionalGain_nx >=
                   GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_hard_limit_vel);

  /* Outputs for Enabled SubSystem: '<S62>/Enabled pass' */
  /* Constant: '<S62>/const_upper_limit' incorporates:
   *  Constant: '<S62>/const_lower_limit'
   */
  GRM_HIL_Enabledpass(GRM_HIL_M, rtb_Compare_k,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt,
                      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMinVolt,
                      &GRM_HIL_B.Merge_h, &GRM_HIL_B.Merge1_k,
                      &GRM_HIL_DW.Enabledpass_j);

  /* End of Outputs for SubSystem: '<S62>/Enabled pass' */

  /* Logic: '<S62>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_b = !rtb_Compare_k;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S66>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_hn =
      GRM_HIL_B.LogicalOperator_b;

    /* Outputs for Enabled SubSystem: '<S62>/Enabled adapt' incorporates:
     *  EnablePort: '<S66>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Enabledadapt_MODE_h =
        GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_hn;
    }

    /* End of Outputs for SubSystem: '<S62>/Enabled adapt' */
  }

  /* Outputs for Enabled SubSystem: '<S62>/Enabled adapt' incorporates:
   *  EnablePort: '<S66>/Enable'
   */
  if (GRM_HIL_DW.Enabledadapt_MODE_h) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S66>/Abs' incorporates:
       *  Constant: '<S66>/Constant'
       */
      GRM_HIL_B.Abs_j = fabs
        (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_hard_limit_vel);
    }

    /* Sum: '<S66>/Add' incorporates:
     *  Abs: '<S62>/Abs'
     *  Constant: '<S66>/Constant1'
     *  Gain: '<S66>/Gain'
     *  Product: '<S66>/Divide'
     */
    rtb_ProportionalGain = GRM_HIL_B.Abs_j / rtb_ProportionalGain_nx *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_limit_adaption_coef -
      (GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_limit_adaption_coef - 1.0);

    /* Product: '<S66>/Product' incorporates:
     *  Constant: '<S62>/const_upper_limit'
     */
    GRM_HIL_B.Merge_h = rtb_ProportionalGain *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;

    /* Product: '<S66>/Product1' incorporates:
     *  Constant: '<S62>/const_lower_limit'
     */
    GRM_HIL_B.Merge1_k = rtb_ProportionalGain *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMinVolt;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Enabledadapt_SubsysRanBC_b);
    }
  }

  /* End of Outputs for SubSystem: '<S62>/Enabled adapt' */

  /* Switch: '<S62>/Switch2' incorporates:
   *  Constant: '<S62>/Constant2'
   */
  if (GRM_HIL_B.Gain_j > GRM_HIL_P.Switch2_Threshold_i) {
    GRM_HIL_B.Switch2_i = GRM_HIL_B.Merge_h;
  } else {
    GRM_HIL_B.Switch2_i = GRM_HIL_P.Constant2_Value_ht;
  }

  /* End of Switch: '<S62>/Switch2' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S62>/Gain' incorporates:
     *  Constant: '<S62>/Constant2'
     */
    GRM_HIL_B.Gain_l = GRM_HIL_P.Gain_Gain_p * GRM_HIL_P.Constant2_Value_ht;
  }

  /* Switch: '<S62>/Switch1' */
  if (GRM_HIL_B.Gain_j > GRM_HIL_P.Switch1_Threshold_m) {
    GRM_HIL_B.Switch1_l = GRM_HIL_B.Gain_l;
  } else {
    GRM_HIL_B.Switch1_l = GRM_HIL_B.Merge1_k;
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Gain: '<S192>/rad2deg2' */
  GRM_HIL_B.Gimbal_Psi_Cmd_deg = GRM_HIL_P.rad2deg2_Gain *
    GRM_HIL_B.ATT_Psi_rad_j;

  /* Product: '<S47>/Product1' */
  GRM_HIL_B.Product1 = rtb_Abs_lo * GRM_HIL_B.Gimbal_Psi_Cmd_deg;

  /* Sum: '<S47>/Sum1' */
  GRM_HIL_B.Roll_err = GRM_HIL_B.Product1 - GRM_HIL_B.roll_deg;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S63>/Proportional Gain' */
    rtb_ProportionalGain_c =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Proportional_Gain *
      GRM_HIL_B.Roll_err;

    /* Gain: '<S63>/Derivative Gain' */
    rtb_DerivativeGain_f =
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Derivative_Gain *
      GRM_HIL_B.Roll_err;
  }

  /* Integrator: '<S63>/Integrator' */
  GRM_HIL_B.Integrator_a = GRM_HIL_X.Integrator_CSTATE_f;

  /* Integrator: '<S63>/Filter' */
  GRM_HIL_B.Filter_n = GRM_HIL_X.Filter_CSTATE_n;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S63>/Filter Coefficient' incorporates:
     *  Sum: '<S63>/SumD'
     */
    GRM_HIL_B.FilterCoefficient_l = (rtb_DerivativeGain_f - GRM_HIL_B.Filter_n) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Filter_Coefficient;

    /* Sum: '<S63>/Sum' */
    rtb_Sum_o = (rtb_ProportionalGain_c + GRM_HIL_B.Integrator_a) +
      GRM_HIL_B.FilterCoefficient_l;

    /* Logic: '<S62>/Logical Operator1' incorporates:
     *  Constant: '<S62>/Constant'
     */
    GRM_HIL_B.LogicalOperator1_k =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atController !=
        0.0);
  }

  /* Switch: '<S62>/Switch' incorporates:
   *  Abs: '<S62>/Abs'
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S64>/Constant'
   *  RelationalOperator: '<S64>/Compare'
   */
  if (GRM_HIL_B.LogicalOperator1_k) {
    GRM_HIL_B.Switch_p = GRM_HIL_P.Constant1_Value_j;
  } else {
    GRM_HIL_B.Switch_p = (rtb_ProportionalGain_nx >=
                          GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Roll_soft_limit_vel);
  }

  /* End of Switch: '<S62>/Switch' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S68>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_kk =
      GRM_HIL_B.Switch_p;

    /* Outputs for Enabled SubSystem: '<S63>/Saturation' */
    GRM_HIL_Saturation(GRM_HIL_M,
                       GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_kk,
                       GRM_HIL_B.Switch2_i, GRM_HIL_B.Switch1_l, rtb_Sum_o,
                       &GRM_HIL_B.Merge_c, &GRM_HIL_DW.Saturation_j);

    /* End of Outputs for SubSystem: '<S63>/Saturation' */

    /* Logic: '<S63>/Logical Operator' */
    GRM_HIL_B.LogicalOperator_p = !GRM_HIL_B.Switch_p;

    /* Outputs for Enabled SubSystem: '<S63>/pass' */
    GRM_HIL_pass(GRM_HIL_M, GRM_HIL_B.LogicalOperator_p, rtb_Sum_o,
                 &GRM_HIL_B.Merge_c, &GRM_HIL_DW.pass_c);

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
          GRM_HIL_DW.If_ActiveSubsystem_a = -1;

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
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S52>/Abs1' incorporates:
       *  Constant: '<S52>/max_vel_yaw'
       */
      GRM_HIL_B.Abs1 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV);
    }

    /* If: '<S52>/If' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_PulseGenerator >= GRM_HIL_B.Abs1);
      GRM_HIL_DW.If_ActiveSubsystem_a = rtAction;
    } else {
      rtAction = GRM_HIL_DW.If_ActiveSubsystem_a;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S52>/If Action limit_yaw' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      /* Saturate: '<S185>/Limit_Voltage_Yaw' */
      if (GRM_HIL_B.Merge_a > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt) {
        GRM_HIL_B.Merge_o = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_a <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt) {
        GRM_HIL_B.Merge_o = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge_o = GRM_HIL_B.Merge_a;
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
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_a, &GRM_HIL_B.Merge_o);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action pass_yaw' */
      break;
    }

    /* End of If: '<S52>/If' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S52>/Abs3' incorporates:
       *  Constant: '<S52>/max_vel_pitch'
       */
      GRM_HIL_B.Abs3 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchMaxV);
    }

    /* If: '<S52>/If1' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_DerivativeGain >= GRM_HIL_B.Abs3);
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
      if (GRM_HIL_B.Merge_fu > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt)
      {
        GRM_HIL_B.Merge1_o = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_fu <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt) {
        GRM_HIL_B.Merge1_o = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge1_o = GRM_HIL_B.Merge_fu;
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
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_fu, &GRM_HIL_B.Merge1_o);
      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S52>/If Action pass_pitch' */
      break;
    }

    /* End of If: '<S52>/If1' */
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Abs: '<S52>/Abs5' incorporates:
       *  Constant: '<S52>/max_vel_roll'
       */
      GRM_HIL_B.Abs5 = fabs(0.8 * GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollMaxV);
    }

    /* If: '<S52>/If2' */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      rtAction = (int8_T)!(rtb_ProportionalGain_nx >= GRM_HIL_B.Abs5);
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
      if (GRM_HIL_B.Merge_c > GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt)
      {
        GRM_HIL_B.Merge2 = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;
      } else if (GRM_HIL_B.Merge_c <
                 -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt) {
        GRM_HIL_B.Merge2 = -GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollCmdMaxVolt;
      } else {
        GRM_HIL_B.Merge2 = GRM_HIL_B.Merge_c;
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
      GRM_HIL_IfActionpass_yaw(GRM_HIL_B.Merge_c, &GRM_HIL_B.Merge2);
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
    GRM_HIL_B.LogicalOperator_c =
      !(GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.Enable_Voltage_Limits_atOutput != 0.0);

    /* Outputs for Enabled SubSystem: '<S45>/If Action Pass' incorporates:
     *  EnablePort: '<S50>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.IfActionPass_MODE = GRM_HIL_B.LogicalOperator_c;
    }

    /* End of Outputs for SubSystem: '<S45>/If Action Pass' */
  }

  /* Outputs for Enabled SubSystem: '<S45>/If Action Pass' incorporates:
   *  EnablePort: '<S50>/Enable'
   */
  if (GRM_HIL_DW.IfActionPass_MODE) {
    /* Inport: '<S50>/yaw' */
    GRM_HIL_B.Merge_o = GRM_HIL_B.Merge_a;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Inport: '<S50>/pitch' */
      GRM_HIL_B.Merge1_o = GRM_HIL_B.Merge_fu;

      /* Inport: '<S50>/roll' */
      GRM_HIL_B.Merge2 = GRM_HIL_B.Merge_c;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionPass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S45>/If Action Pass' */

  /* TransferFcn: '<S39>/Psi2Motor -> Roll' */
  rtb_Add_pi = 0.0;
  rtb_Add_pi += GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Roll.Num_Coef
    / GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Roll.Denom_Coef *
    GRM_HIL_B.Merge_o;

  /* Sum: '<S39>/Sum2' incorporates:
   *  TransferFcn: '<S39>/Phi2Motor -> Roll'
   *  TransferFcn: '<S39>/Theta2Motor -> Roll'
   */
  GRM_HIL_B.Sum2 =
    ((GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Num_Coef[0] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
      GRM_HIL_X.Phi2MotorRoll_CSTATE[0] +
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Num_Coef[1] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
      GRM_HIL_X.Phi2MotorRoll_CSTATE[1]) +
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Num_Coef[2] /
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Roll.Denom_Coef[0] *
     GRM_HIL_X.Phi2MotorRoll_CSTATE[2]) +
    (GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Roll.Num_Coef /
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Roll.Denom_Coef *
     GRM_HIL_B.Merge1_o + rtb_Add_pi);

  /* Gain: '<S40>/Shaft2radRoll' */
  GRM_HIL_B.ATT_Phi_rad_a = GRM_HIL_P.Shaft2radRoll_Gain * GRM_HIL_B.Sum2;

  /* TransferFcn: '<S39>/Theta2Motor -> Pitch' */
  rtb_Add_pi = 0.0;
  for (cj = 0; cj < 5; cj++) {
    rtb_Add_pi +=
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Pitch.Num_Coef[cj] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Pitch.Denom_Coef[0] *
      GRM_HIL_X.Theta2MotorPitch_CSTATE[cj];
  }

  /* End of TransferFcn: '<S39>/Theta2Motor -> Pitch' */

  /* Sum: '<S39>/Sum1' incorporates:
   *  TransferFcn: '<S39>/Phi2Motor -> Pitch'
   *  TransferFcn: '<S39>/Psi2Motor -> Pitch'
   */
  GRM_HIL_B.Sum1 =
    (GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Pitch.Num_Coef /
     GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Pitch.Denom_Coef *
     GRM_HIL_B.Merge_o + rtb_Add_pi) +
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Pitch.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Pitch.Denom_Coef *
    GRM_HIL_B.Merge2;

  /* Gain: '<S40>/Shaft2radPitch' */
  GRM_HIL_B.ATT_Theta_rad_i = GRM_HIL_P.Shaft2radPitch_Gain * GRM_HIL_B.Sum1;

  /* TransferFcn: '<S39>/Theta2Motor -> Yaw' */
  rtb_Add_pi = 0.0;
  rtb_Add_pi +=
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Yaw.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Theta2Motor_to_Yaw.Denom_Coef *
    GRM_HIL_B.Merge1_o;

  /* Sum: '<S39>/Sum' incorporates:
   *  TransferFcn: '<S39>/Phi2Motor -> Yaw'
   *  TransferFcn: '<S39>/Psi2Motor -> Yaw'
   */
  GRM_HIL_B.Sum =
    ((GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Num_Coef[0] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[0] *
      GRM_HIL_X.Psi2MotorYaw_CSTATE[0] +
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Num_Coef[1] /
      GRM_HIL_P.Gimbal_TransferFunctions_TF.Psi2Motor_to_Yaw.Denom_Coef[0] *
      GRM_HIL_X.Psi2MotorYaw_CSTATE[1]) + rtb_Add_pi) +
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Yaw.Num_Coef /
    GRM_HIL_P.Gimbal_TransferFunctions_TF.Phi2Motor_to_Yaw.Denom_Coef *
    GRM_HIL_B.Merge2;

  /* Gain: '<S40>/Shaft2radYaw' */
  GRM_HIL_B.ATT_Psi_rad_g = GRM_HIL_P.Shaft2radYaw_Gain * GRM_HIL_B.Sum;

  /* Gain: '<S43>/1//2' */
  rtb_DerivativeGain_f = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Psi_rad_g;
  rtb_PulseGenerator1 = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Theta_rad_i;
  rtb_DerivativeGain_a = GRM_HIL_P.u2_Gain * GRM_HIL_B.ATT_Phi_rad_a;

  /* Trigonometry: '<S43>/sincos' */
  rtb_Sum_p3 = cos(rtb_DerivativeGain_f);
  rtb_DerivativeGain_f = sin(rtb_DerivativeGain_f);
  rtb_ProportionalGain = cos(rtb_PulseGenerator1);
  rtb_PulseGenerator1 = sin(rtb_PulseGenerator1);
  rtb_ProportionalGain_c = cos(rtb_DerivativeGain_a);
  rtb_DerivativeGain_a = sin(rtb_DerivativeGain_a);

  /* Fcn: '<S43>/q0' incorporates:
   *  Fcn: '<S43>/q3'
   */
  rtb_Abs_i = rtb_Sum_p3 * rtb_ProportionalGain;
  rtb_Abs_lo = rtb_DerivativeGain_f * rtb_PulseGenerator1;
  GRM_HIL_B.q0 = rtb_Abs_i * rtb_ProportionalGain_c - rtb_Abs_lo *
    rtb_DerivativeGain_a;

  /* Fcn: '<S43>/q1' incorporates:
   *  Fcn: '<S43>/q2'
   */
  rtb_PulseGenerator1 *= rtb_Sum_p3;
  rtb_DerivativeGain_f *= rtb_ProportionalGain;
  GRM_HIL_B.q1 = rtb_PulseGenerator1 * rtb_DerivativeGain_a +
    rtb_DerivativeGain_f * rtb_ProportionalGain_c;

  /* Fcn: '<S43>/q2' */
  GRM_HIL_B.q2 = rtb_PulseGenerator1 * rtb_ProportionalGain_c -
    rtb_DerivativeGain_f * rtb_DerivativeGain_a;

  /* Fcn: '<S43>/q3' */
  GRM_HIL_B.q3 = rtb_Abs_i * rtb_DerivativeGain_a + rtb_Abs_lo *
    rtb_ProportionalGain_c;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S41>/Constant' */
    GRM_HIL_B.Data_plus = GRM_HIL_P.Constant_Value_k;

    /* Constant: '<S41>/Constant1' */
    GRM_HIL_B.Data_minus = GRM_HIL_P.Constant1_Value_h;

    /* Constant: '<S41>/Constant2' */
    GRM_HIL_B.Clock_plus = GRM_HIL_P.Constant2_Value_e;

    /* Constant: '<S41>/Constant3' */
    GRM_HIL_B.Clock_minus = GRM_HIL_P.Constant3_Value_p;

    /* Constant: '<S41>/Constant4' */
    GRM_HIL_B.Data_plus_a = GRM_HIL_P.Constant4_Value;

    /* Constant: '<S41>/Constant5' */
    GRM_HIL_B.Data_minus_k = GRM_HIL_P.Constant5_Value;

    /* Constant: '<S41>/Constant6' */
    GRM_HIL_B.Clock_plus_c = GRM_HIL_P.Constant6_Value;

    /* Constant: '<S41>/Constant7' */
    GRM_HIL_B.Clock_minus_i = GRM_HIL_P.Constant7_Value_e;

    /* Constant: '<S41>/Constant8' */
    GRM_HIL_B.Data_plus_k = GRM_HIL_P.Constant8_Value;

    /* Constant: '<S41>/Constant9' */
    GRM_HIL_B.Data_minus_kw = GRM_HIL_P.Constant9_Value_g;

    /* Constant: '<S41>/Constant10' */
    GRM_HIL_B.Clock_plus_b = GRM_HIL_P.Constant10_Value;

    /* Constant: '<S41>/Constant11' */
    GRM_HIL_B.Clock_minus_g = GRM_HIL_P.Constant11_Value_c;

    /* Sum: '<S18>/Add' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S18>/Constant1'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S7>/Constant10'
     *  Product: '<S18>/Divide'
     *  Product: '<S18>/Divide1'
     */
    rtb_Abs_i = GRM_HIL_P.Constant1_Value_a / GRM_HIL_P.HIL_Sample_Time /
      GRM_HIL_P.Constant10_Value_l - GRM_HIL_P.Constant2_Value_a;

    /* MATLAB Function: '<S18>/Counter_with_external_limit' incorporates:
     *  Memory: '<S18>/Memory'
     */
    if (GRM_HIL_DW.Memory_PreviousInput < rtb_Abs_i) {
      GRM_HIL_B.value = GRM_HIL_DW.Memory_PreviousInput + 1.0;
    } else {
      GRM_HIL_B.value = 0.0;
    }

    /* End of MATLAB Function: '<S18>/Counter_with_external_limit' */

    /* RelationalOperator: '<S18>/Equal' */
    GRM_HIL_B.Equal = (rtb_Abs_i == GRM_HIL_B.value);

    /* Outputs for Enabled SubSystem: '<S17>/Com_to_FCC_emul' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Com_to_FCC_emul_MODE = GRM_HIL_B.Equal;
    }

    /* End of Outputs for SubSystem: '<S17>/Com_to_FCC_emul' */
  }

  /* Outputs for Enabled SubSystem: '<S17>/Com_to_FCC_emul' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (GRM_HIL_DW.Com_to_FCC_emul_MODE) {
    /* SignalConversion generated from: '<S19>/States_hold' */
    GRM_HIL_B.ATT_Phi_rad_f = GRM_HIL_B.ATT_Phi_rad_l;

    /* SignalConversion generated from: '<S19>/States_hold' */
    GRM_HIL_B.ACC_y_B_mDs2_o = GRM_HIL_B.ACC_y_B_mDs2;

    /* SignalConversion generated from: '<S19>/States_hold' */
    GRM_HIL_B.ACC_z_B_mDs2_e = GRM_HIL_B.ACC_z_B_mDs2;

    /* SignalConversion generated from: '<S19>/States_hold' */
    GRM_HIL_B.w_x_K_IB_B_radDs_f = GRM_HIL_B.w_x_K_IB_B_radDs;

    /* SignalConversion generated from: '<S19>/States_hold' */
    GRM_HIL_B.w_y_K_IB_B_radDs_e = GRM_HIL_B.w_y_K_IB_B_radDs;

    /* SignalConversion generated from: '<S19>/States_hold' */
    GRM_HIL_B.w_z_K_IB_B_radDs_n = GRM_HIL_B.w_z_K_IB_B_radDs;
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S19>/External_Inputs_hold' */
      GRM_HIL_B.CMD_phi_rad = GRM_HIL_B.Switch1;

      /* SignalConversion generated from: '<S19>/External_Inputs_hold' */
      GRM_HIL_B.CMD_acc_z_mDs2 = GRM_HIL_B.Switch;

      /* SignalConversion generated from: '<S19>/External_Inputs_hold' */
      GRM_HIL_B.CMD_acc_y_mDs2 = GRM_HIL_B.Switch2;
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Com_to_FCC_emul_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S17>/Com_to_FCC_emul' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S25>/Gain2' */
    GRM_HIL_B.phi_rad = GRM_HIL_P.Gain2_Gain_b * GRM_HIL_B.CMD_phi_rad;
  }

  /* Gain: '<S24>/Gain' incorporates:
   *  Sum: '<S24>/Sum'
   */
  GRM_HIL_B.Gain_a = (GRM_HIL_B.phi_rad - GRM_HIL_B.w_x_K_IB_B_radDs_f) *
    GRM_HIL_P.FlightController_FCC.Roll.Gain;

  /* TransferFcn: '<S24>/Transfer Fcn' */
  GRM_HIL_B.Phi_Cmd_rad = 0.0;
  rtb_ProportionalGain_c = GRM_HIL_P.FlightController_FCC.Roll.Lead.Num[0] /
    GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0];
  GRM_HIL_B.Phi_Cmd_rad += rtb_ProportionalGain_c * GRM_HIL_B.Gain_a;
  GRM_HIL_B.Phi_Cmd_rad += (GRM_HIL_P.FlightController_FCC.Roll.Lead.Num[1] /
    GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0] - rtb_ProportionalGain_c *
    (GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[1] /
     GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0])) *
    GRM_HIL_X.TransferFcn_CSTATE_j;

  /* Saturate: '<S23>/Limit2maxDeflection' */
  if (GRM_HIL_B.Phi_Cmd_rad >
      GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_Abs_i = GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else if (GRM_HIL_B.Phi_Cmd_rad <
             -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad) {
    rtb_Abs_i = -GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad;
  } else {
    rtb_Abs_i = GRM_HIL_B.Phi_Cmd_rad;
  }

  /* End of Saturate: '<S23>/Limit2maxDeflection' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S25>/Gain' */
    GRM_HIL_B.acc_y_mDs2 = GRM_HIL_P.Gain_Gain_e * GRM_HIL_B.CMD_acc_y_mDs2;

    /* Gain: '<S25>/Gain1' */
    GRM_HIL_B.acc_z_mDs2 = GRM_HIL_P.Gain1_Gain_c * GRM_HIL_B.CMD_acc_z_mDs2;
  }

  /* Sum: '<S24>/Sum3' */
  GRM_HIL_B.Sum3 = GRM_HIL_B.acc_y_mDs2 - GRM_HIL_B.ACC_y_B_mDs2_o;

  /* TransferFcn: '<S24>/Transfer Fcn2' */
  rtb_Add_pi = 0.0;
  rtb_Add_pi += GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Num /
    GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn2_CSTATE_e;

  /* Gain: '<S24>/Gain2' incorporates:
   *  Gain: '<S24>/Gain4'
   *  Sum: '<S24>/Sum4'
   *  Sum: '<S24>/Sum6'
   */
  GRM_HIL_B.Psi_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.PropGain * GRM_HIL_B.Sum3 +
      rtb_Add_pi) - GRM_HIL_B.w_z_K_IB_B_radDs_n) *
    GRM_HIL_P.FlightController_FCC.Yaw.innerLoop.PropGain;

  /* Sum: '<S24>/Sum1' */
  GRM_HIL_B.Sum1_d = GRM_HIL_B.acc_z_mDs2 - GRM_HIL_B.ACC_z_B_mDs2_e;

  /* TransferFcn: '<S24>/Transfer Fcn1' */
  rtb_Add_pi = 0.0;
  rtb_Add_pi += GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Num /
    GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_e;

  /* Gain: '<S24>/Gain1' incorporates:
   *  Gain: '<S24>/Gain3'
   *  Sum: '<S24>/Sum2'
   *  Sum: '<S24>/Sum5'
   */
  GRM_HIL_B.Theta_Cmd_rad =
    ((GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.PropGain * GRM_HIL_B.Sum1_d
      + rtb_Add_pi) - GRM_HIL_B.w_y_K_IB_B_radDs_e) *
    GRM_HIL_P.FlightController_FCC.Pitch.innerLoop.PropGain;

  /* Sum: '<S23>/Add4' incorporates:
   *  Constant: '<S23>/Constant'
   *  Sum: '<S23>/Add5'
   */
  rtb_ProportionalGain_c = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f1_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add' incorporates:
   *  Fcn: '<S23>/Fcn'
   *  Fcn: '<S23>/Fcn1'
   *  Product: '<S23>/Multiply'
   *  Product: '<S23>/Multiply1'
   *  Sum: '<S23>/Add4'
   */
  rtb_Abs_lo = -cos(rtb_ProportionalGain_c) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_ProportionalGain_c) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add6' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Sum: '<S23>/Add7'
   */
  rtb_ProportionalGain_c = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f2_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add1' incorporates:
   *  Fcn: '<S23>/Fcn2'
   *  Fcn: '<S23>/Fcn3'
   *  Product: '<S23>/Multiply2'
   *  Product: '<S23>/Multiply3'
   *  Sum: '<S23>/Add6'
   */
  rtb_ProportionalGain_c = -cos(rtb_ProportionalGain_c) * GRM_HIL_B.Psi_Cmd_rad
    + sin(rtb_ProportionalGain_c) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add8' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Sum: '<S23>/Add9'
   */
  rtb_DerivativeGain_f = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f3_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add2' incorporates:
   *  Fcn: '<S23>/Fcn4'
   *  Fcn: '<S23>/Fcn5'
   *  Product: '<S23>/Multiply4'
   *  Product: '<S23>/Multiply5'
   *  Sum: '<S23>/Add8'
   */
  rtb_DerivativeGain_f = -cos(rtb_DerivativeGain_f) * GRM_HIL_B.Psi_Cmd_rad +
    sin(rtb_DerivativeGain_f) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add10' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Sum: '<S23>/Add11'
   */
  rtb_ProportionalGain = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f4_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add3' incorporates:
   *  Fcn: '<S23>/Fcn6'
   *  Fcn: '<S23>/Fcn7'
   *  Product: '<S23>/Multiply6'
   *  Product: '<S23>/Multiply7'
   *  Sum: '<S23>/Add10'
   */
  rtb_DerivativeGain_a = -cos(rtb_ProportionalGain) * GRM_HIL_B.Psi_Cmd_rad +
    sin(rtb_ProportionalGain) * GRM_HIL_B.Theta_Cmd_rad;

  /* Abs: '<S29>/Abs' */
  rtb_Add_pi = fabs(rtb_Abs_lo);

  /* Sum: '<S23>/Add16' incorporates:
   *  Abs: '<S23>/Abs'
   *  Constant: '<S23>/Constant4'
   */
  rtb_PulseGenerator1 =
    GRM_HIL_P.FinDeflection_Control_Surfaces.max_deflection_rad - fabs(rtb_Abs_i);

  /* RelationalOperator: '<S29>/Relational Operator' */
  rtb_RelationalOperator = (rtb_Add_pi > rtb_PulseGenerator1);

  /* Abs: '<S29>/Abs1' */
  rtb_Add_pi = fabs(rtb_ProportionalGain_c);

  /* RelationalOperator: '<S29>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_Add_pi > rtb_PulseGenerator1);

  /* Abs: '<S29>/Abs2' */
  rtb_Add_pi = fabs(rtb_DerivativeGain_f);

  /* RelationalOperator: '<S29>/Relational Operator2' */
  rtb_RelationalOperator2 = (rtb_Add_pi > rtb_PulseGenerator1);

  /* Abs: '<S29>/Abs3' */
  rtb_Add_pi = fabs(rtb_DerivativeGain_a);

  /* Logic: '<S29>/OR' incorporates:
   *  RelationalOperator: '<S29>/Relational Operator3'
   */
  GRM_HIL_B.OR = (rtb_RelationalOperator || rtb_RelationalOperator1 ||
                  rtb_RelationalOperator2 || (rtb_Add_pi > rtb_PulseGenerator1));

  /* Logic: '<S28>/Logical Operator' */
  GRM_HIL_B.LogicalOperator_at = !GRM_HIL_B.OR;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S30>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4 =
      GRM_HIL_B.LogicalOperator_at;

    /* Outputs for Enabled SubSystem: '<S28>/Pass' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Pass_MODE = GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4;
    }

    /* End of Outputs for SubSystem: '<S28>/Pass' */
  }

  /* Outputs for Enabled SubSystem: '<S28>/Pass' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  if (GRM_HIL_DW.Pass_MODE) {
    /* Inport: '<S30>/Fin_1_Cmd_rad' */
    GRM_HIL_B.Merge_n = rtb_Abs_lo;

    /* Inport: '<S30>/Fin_2_Cmd_rad' */
    GRM_HIL_B.Merge1_n = rtb_ProportionalGain_c;

    /* Inport: '<S30>/Fin_3_Cmd_rad' */
    GRM_HIL_B.Merge2_i = rtb_DerivativeGain_f;

    /* Inport: '<S30>/Fin_4_Cmd_rad' */
    GRM_HIL_B.Merge3 = rtb_DerivativeGain_a;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Pass_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S28>/Pass' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S31>/Enable' */
    GRM_HIL_B.HiddenBuf_InsertedFor_Saturate_at_inport_5 = GRM_HIL_B.OR;

    /* Outputs for Enabled SubSystem: '<S28>/Saturate' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      GRM_HIL_DW.Saturate_MODE =
        GRM_HIL_B.HiddenBuf_InsertedFor_Saturate_at_inport_5;
    }

    /* End of Outputs for SubSystem: '<S28>/Saturate' */
  }

  /* Outputs for Enabled SubSystem: '<S28>/Saturate' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (GRM_HIL_DW.Saturate_MODE) {
    /* Abs: '<S31>/Abs1' incorporates:
     *  MinMax: '<S31>/Max'
     */
    rtb_ProportionalGain = fabs(fmax(fmax(fmax(rtb_Abs_lo,
      rtb_ProportionalGain_c), rtb_DerivativeGain_f), rtb_DerivativeGain_a));

    /* Product: '<S31>/Multiply' incorporates:
     *  Product: '<S31>/Divide'
     */
    GRM_HIL_B.Merge_n = rtb_Abs_lo / rtb_ProportionalGain * rtb_PulseGenerator1;

    /* Product: '<S31>/Multiply1' incorporates:
     *  Product: '<S31>/Divide1'
     */
    GRM_HIL_B.Merge1_n = rtb_ProportionalGain_c / rtb_ProportionalGain *
      rtb_PulseGenerator1;

    /* Product: '<S31>/Multiply2' incorporates:
     *  Product: '<S31>/Divide4'
     */
    GRM_HIL_B.Merge2_i = rtb_DerivativeGain_f / rtb_ProportionalGain *
      rtb_PulseGenerator1;

    /* Product: '<S31>/Multiply3' incorporates:
     *  Product: '<S31>/Divide2'
     */
    GRM_HIL_B.Merge3 = rtb_DerivativeGain_a / rtb_ProportionalGain *
      rtb_PulseGenerator1;
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Saturate_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S28>/Saturate' */

  /* Sum: '<S23>/Add14' */
  GRM_HIL_B.Fin_4_Cmd_rad = rtb_Abs_i + GRM_HIL_B.Merge3;

  /* Product: '<S35>/Product' incorporates:
   *  Constant: '<S32>/Constant6'
   *  Constant: '<S33>/Constant6'
   *  Constant: '<S34>/Constant6'
   *  Constant: '<S35>/Constant6'
   *  Product: '<S32>/Product'
   *  Product: '<S33>/Product'
   *  Product: '<S34>/Product'
   */
  rtb_ProportionalGain_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms -
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S35>/Constant2'
   *  Constant: '<S35>/Constant6'
   *  Product: '<S35>/Divide'
   *  Product: '<S35>/Product'
   */
  rtb_Add_pi = rtb_ProportionalGain_c * (GRM_HIL_B.Fin_4_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Add_pi > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_Add_pi < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms = rtb_Add_pi;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Sum: '<S23>/Add13' */
  GRM_HIL_B.Fin_3_Cmd_rad = rtb_Abs_i + GRM_HIL_B.Merge2_i;

  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S34>/Constant2'
   *  Product: '<S34>/Divide'
   *  Product: '<S34>/Product'
   */
  rtb_Add_pi = rtb_ProportionalGain_c * (GRM_HIL_B.Fin_3_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S34>/Saturation' */
  if (rtb_Add_pi > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_Add_pi < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_e = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_e = rtb_Add_pi;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S23>/Add12' */
  GRM_HIL_B.Fin_2_Cmd_rad = rtb_Abs_i + GRM_HIL_B.Merge1_n;

  /* Sum: '<S33>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S33>/Constant2'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Product'
   */
  rtb_Add_pi = rtb_ProportionalGain_c * (GRM_HIL_B.Fin_2_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S33>/Saturation' */
  if (rtb_Add_pi > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_Add_pi < GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_c = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_c = rtb_Add_pi;
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Sum: '<S23>/Add15' */
  GRM_HIL_B.Fin_1_Cmd_rad = rtb_Abs_i + GRM_HIL_B.Merge_n;

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S32>/Constant2'
   *  Product: '<S32>/Divide'
   *  Product: '<S32>/Product'
   */
  rtb_ProportionalGain_c = rtb_ProportionalGain_c * (GRM_HIL_B.Fin_1_Cmd_rad /
    GRM_HIL_P.Servo_Cmd_Control_Surfaces.max_deflection_rad) +
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Saturate: '<S32>/Saturation' */
  if (rtb_ProportionalGain_c > GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms) {
    GRM_HIL_B.pulse_width_ms_p = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms;
  } else if (rtb_ProportionalGain_c <
             GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms) {
    GRM_HIL_B.pulse_width_ms_p = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_min_ms;
  } else {
    GRM_HIL_B.pulse_width_ms_p = rtb_ProportionalGain_c;
  }

  /* End of Saturate: '<S32>/Saturation' */
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (fcncallgen): '<S17>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S17>/FB_Com_freq_emul'
     */
    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.Fin_3_Cmd_rad_o = GRM_HIL_B.Fin_3_Cmd_rad;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.Fin_4_Cmd_rad_c = GRM_HIL_B.Fin_4_Cmd_rad;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.pulse_width_ms_p2 = GRM_HIL_B.pulse_width_ms_p;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.pulse_width_ms_p2d = GRM_HIL_B.pulse_width_ms_c;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.pulse_width_ms_p2de = GRM_HIL_B.pulse_width_ms_e;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.pulse_width_ms_p2dee = GRM_HIL_B.pulse_width_ms;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.Fin_1_Cmd_rad_l = GRM_HIL_B.Fin_1_Cmd_rad;

    /* SignalConversion generated from: '<S20>/hold' */
    GRM_HIL_B.Fin_2_Cmd_rad_e = GRM_HIL_B.Fin_2_Cmd_rad;
    GRM_HIL_DW.FB_Com_freq_emul_SubsysRanBC = 4;

    /* End of Outputs for S-Function (fcncallgen): '<S17>/Function-Call Generator1' */
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S189>/Gain' incorporates:
     *  Constant: '<S5>/Constant'
     */
    GRM_HIL_B.VEL_u_K_R_E_B_mDs = GRM_HIL_P.Gain_Gain_d *
      GRM_HIL_P.Initial_States_Rigid_Body.Transl.VEL_u_K_R_E_B_mDs;
  }

  /* Integrator: '<S220>/Integrator' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_i != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_i = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator_IWORK_ic != 0)) {
      GRM_HIL_X.Integrator_CSTATE_j = GRM_HIL_B.VEL_u_K_R_E_B_mDs;
    }
  }

  /* Gain: '<S195>/Gain' incorporates:
   *  Integrator: '<S220>/Integrator'
   */
  GRM_HIL_B.VEL_u_K_R_E_B_mDs_e = GRM_HIL_P.Gain_Gain_k *
    GRM_HIL_X.Integrator_CSTATE_j;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S189>/Gain1' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    GRM_HIL_B.VEL_v_K_R_E_B_mDs = GRM_HIL_P.Gain1_Gain_i *
      GRM_HIL_P.Initial_States_Rigid_Body.Transl.VEL_v_K_R_E_B_mDs;
  }

  /* Integrator: '<S220>/Integrator1' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_p != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_p = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator1_IWORK_g != 0)) {
      GRM_HIL_X.Integrator1_CSTATE_p = GRM_HIL_B.VEL_v_K_R_E_B_mDs;
    }
  }

  /* Gain: '<S195>/Gain1' incorporates:
   *  Integrator: '<S220>/Integrator1'
   */
  GRM_HIL_B.VEL_v_K_R_E_B_mDs_e = GRM_HIL_P.Gain1_Gain_b *
    GRM_HIL_X.Integrator1_CSTATE_p;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S189>/Gain2' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    GRM_HIL_B.VEL_w_K_R_E_B_mDs = GRM_HIL_P.Gain2_Gain_l *
      GRM_HIL_P.Initial_States_Rigid_Body.Transl.VEL_w_K_R_E_B_mDs;
  }

  /* Integrator: '<S220>/Integrator2' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_f != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_f = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator2_IWORK_m != 0)) {
      GRM_HIL_X.Integrator2_CSTATE_a = GRM_HIL_B.VEL_w_K_R_E_B_mDs;
    }
  }

  /* Gain: '<S195>/Gain2' incorporates:
   *  Integrator: '<S220>/Integrator2'
   */
  GRM_HIL_B.VEL_w_K_R_E_B_mDs_d = GRM_HIL_P.Gain2_Gain_e *
    GRM_HIL_X.Integrator2_CSTATE_a;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[3] == 0) {
    /* Product: '<S12>/Divide' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S15>/Constant1'
     *  Product: '<S13>/Divide'
     *  Product: '<S14>/Divide'
     *  Product: '<S15>/Divide'
     */
    rtb_DerivativeGain_f = GRM_HIL_P.Servo_PWM.Pulswidth_cmd_max_ms -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms;

    /* Product: '<S12>/Multiply' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S12>/Constant2'
     *  Product: '<S12>/Divide'
     *  Sum: '<S12>/Add'
     */
    rtb_ProportionalGain_c = (GRM_HIL_B.pulse_width_ms_p2 -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_DerivativeGain_f *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S12>/Saturation' */
    if (rtb_ProportionalGain_c > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_o = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_ProportionalGain_c < -GRM_HIL_P.Servo_PWM.max_deflection_rad)
    {
      GRM_HIL_B.Saturation_o = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_o = rtb_ProportionalGain_c;
    }

    /* End of Saturate: '<S12>/Saturation' */

    /* Product: '<S13>/Multiply' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant2'
     *  Product: '<S13>/Divide'
     *  Sum: '<S13>/Add'
     */
    rtb_ProportionalGain_c = (GRM_HIL_B.pulse_width_ms_p2d -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_DerivativeGain_f *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S13>/Saturation' */
    if (rtb_ProportionalGain_c > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_c = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_ProportionalGain_c < -GRM_HIL_P.Servo_PWM.max_deflection_rad)
    {
      GRM_HIL_B.Saturation_c = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_c = rtb_ProportionalGain_c;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant2'
     *  Product: '<S14>/Divide'
     *  Sum: '<S14>/Add'
     */
    rtb_ProportionalGain_c = (GRM_HIL_B.pulse_width_ms_p2de -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_DerivativeGain_f *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S14>/Saturation' */
    if (rtb_ProportionalGain_c > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_jy = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_ProportionalGain_c < -GRM_HIL_P.Servo_PWM.max_deflection_rad)
    {
      GRM_HIL_B.Saturation_jy = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_jy = rtb_ProportionalGain_c;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* Product: '<S15>/Multiply' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant2'
     *  Product: '<S15>/Divide'
     *  Sum: '<S15>/Add'
     */
    rtb_ProportionalGain_c = (GRM_HIL_B.pulse_width_ms_p2dee -
      GRM_HIL_P.Servo_PWM.Pulswidth_cmd_middle_pos_ms) / rtb_DerivativeGain_f *
      GRM_HIL_P.Servo_PWM.max_deflection_rad;

    /* Saturate: '<S15>/Saturation' */
    if (rtb_ProportionalGain_c > GRM_HIL_P.Servo_PWM.max_deflection_rad) {
      GRM_HIL_B.Saturation_a = GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else if (rtb_ProportionalGain_c < -GRM_HIL_P.Servo_PWM.max_deflection_rad)
    {
      GRM_HIL_B.Saturation_a = -GRM_HIL_P.Servo_PWM.max_deflection_rad;
    } else {
      GRM_HIL_B.Saturation_a = rtb_ProportionalGain_c;
    }

    /* End of Saturate: '<S15>/Saturation' */
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S39>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant7'
     *  Gain: '<S44>/Gain'
     */
    GRM_HIL_B.cmd_pass_enable_flg = (GRM_HIL_P.Gain_Gain_o *
      GRM_HIL_P.Constant7_Value_e5 != 0.0);

    /* DataTypeConversion: '<S39>/Data Type Conversion1' incorporates:
     *  Constant: '<S39>/Constant'
     */
    GRM_HIL_B.emergency_stop_flg = (GRM_HIL_P.Constant_Value_n != 0.0);
  }

  /* If: '<S176>/If' incorporates:
   *  Constant: '<S176>/Constant'
   *  Constant: '<S176>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_PulseGenerator >
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.YawMaxV);
    GRM_HIL_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S176>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_p,
      &GRM_HIL_B.IfActionSubsystem1_e);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S176>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S176>/If Action Subsystem' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.yaw_deg, &GRM_HIL_B.IfActionSubsystem_m);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S176>/If Action Subsystem' */
    break;
  }

  /* End of If: '<S176>/If' */

  /* If: '<S174>/If' incorporates:
   *  Constant: '<S174>/Constant'
   *  Constant: '<S174>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_DerivativeGain >
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PitchMaxV);
    GRM_HIL_DW.If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem_l;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_l,
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

  /* If: '<S175>/If' incorporates:
   *  Constant: '<S175>/Constant'
   *  Constant: '<S175>/Constant1'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtAction = (int8_T)!(rtb_ProportionalGain_nx >
                         GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.RollMaxV);
    GRM_HIL_DW.If_ActiveSubsystem_g = rtAction;
  } else {
    rtAction = GRM_HIL_DW.If_ActiveSubsystem_g;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    GRM_HIL_IfActionSubsystem1(GRM_HIL_P.Constant_Value_lt,
      &GRM_HIL_B.IfActionSubsystem1_j);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S175>/If Action Subsystem1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    GRM_HIL_IfActionSubsystem(GRM_HIL_B.roll_deg, &GRM_HIL_B.IfActionSubsystem_p);
    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC);
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
    GRM_HIL_B.SumI1 = (GRM_HIL_B.Merge_fu - rtb_Sum_i) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Pitch_Integral_Gain *
      GRM_HIL_B.pitch_err;

    /* Sum: '<S63>/SumI1' incorporates:
     *  Gain: '<S63>/Integral Gain'
     *  Gain: '<S63>/Kb'
     *  Sum: '<S63>/SumI2'
     */
    GRM_HIL_B.SumI1_n = (GRM_HIL_B.Merge_c - rtb_Sum_o) *
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_BackCalculation_Coefficient +
      GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.PID_Roll_Integral_Gain *
      GRM_HIL_B.Roll_err;

    /* Sum: '<S73>/SumI1' incorporates:
     *  Gain: '<S73>/Integral Gain'
     *  Gain: '<S73>/Kb'
     *  Sum: '<S73>/SumI2'
     */
    GRM_HIL_B.SumI1_i = (GRM_HIL_B.Merge_f - rtb_Sum_dr) *
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
      && (!(GRM_HIL_B.IfActionSubsystem1_j.In1 != 0.0)) &&
      (!(GRM_HIL_B.IfActionSubsystem1_e.In1 != 0.0)) &&
      GRM_HIL_P.Constant_Value_g);

    /* Constant: '<S45>/Samp_Freq' */
    GRM_HIL_B.Samp_freq = GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl.SampFreq;

    /* Gain: '<S189>/Gain12' incorporates:
     *  Constant: '<S5>/Constant12'
     */
    GRM_HIL_B.POS_lambda_WGS84_rad = GRM_HIL_P.Gain12_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_lambda_WGS84_rad;

    /* Gain: '<S189>/Gain13' incorporates:
     *  Constant: '<S5>/Constant13'
     */
    GRM_HIL_B.POS_mue_WGS84_rad = GRM_HIL_P.Gain13_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_mue_WGS84_rad;

    /* Gain: '<S189>/Gain14' incorporates:
     *  Constant: '<S5>/Constant14'
     */
    GRM_HIL_B.POS_h_WGS84_m = GRM_HIL_P.Gain14_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_h_WGS84_m;

    /* Gain: '<S189>/Gain15' incorporates:
     *  Constant: '<S5>/Constant15'
     */
    GRM_HIL_B.POS_x_NED_m = GRM_HIL_P.Gain15_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_x_NED_m;

    /* Gain: '<S189>/Gain16' incorporates:
     *  Constant: '<S5>/Constant16'
     */
    GRM_HIL_B.POS_y_NED_m = GRM_HIL_P.Gain16_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_y_NED_m;

    /* Gain: '<S189>/Gain17' incorporates:
     *  Constant: '<S5>/Constant17'
     */
    GRM_HIL_B.POS_z_NED_m = GRM_HIL_P.Gain17_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_z_NED_m;
  }

  /* MATLAB Function: '<S206>/MATLAB Function' incorporates:
   *  Fcn: '<S205>/Fcn1'
   *  Fcn: '<S205>/Fcn10'
   *  Fcn: '<S205>/Fcn11'
   *  Fcn: '<S205>/Fcn12'
   *  Fcn: '<S205>/Fcn4'
   *  Fcn: '<S205>/Fcn6'
   *  Fcn: '<S205>/Fcn8'
   *  Fcn: '<S205>/Fcn9'
   *  Integrator: '<S215>/Integrator'
   *  Integrator: '<S215>/Integrator1'
   *  Integrator: '<S215>/Integrator2'
   *  Integrator: '<S220>/Integrator'
   *  Integrator: '<S220>/Integrator1'
   *  Integrator: '<S220>/Integrator2'
   *  MATLAB Function: '<S206>/MATLAB Function1'
   *  MATLAB Function: '<S206>/MATLAB Function2'
   */
  rtb_ProportionalGain_nx = cos(GRM_HIL_X.Integrator2_CSTATE);
  rtb_PulseGenerator = sin(GRM_HIL_X.Integrator2_CSTATE);
  rtb_Abs_i = sin(GRM_HIL_X.Integrator_CSTATE_k);
  rtb_DerivativeGain_a = sin(GRM_HIL_X.Integrator1_CSTATE);
  rtb_Abs_lo = cos(GRM_HIL_X.Integrator1_CSTATE);
  rtb_ProportionalGain_c = cos(GRM_HIL_X.Integrator_CSTATE_k);
  rtb_DerivativeGain_f = ((rtb_ProportionalGain_nx * rtb_DerivativeGain_a *
    rtb_Abs_i - rtb_PulseGenerator * rtb_ProportionalGain_c) *
    GRM_HIL_X.Integrator1_CSTATE_p + GRM_HIL_X.Integrator_CSTATE_j *
    rtb_ProportionalGain_nx * rtb_Abs_lo) + (rtb_ProportionalGain_nx *
    rtb_ProportionalGain_nx * rtb_DerivativeGain_a + rtb_PulseGenerator *
    rtb_Abs_i) * GRM_HIL_X.Integrator2_CSTATE_a;

  /* MATLAB Function: '<S206>/MATLAB Function1' incorporates:
   *  Integrator: '<S220>/Integrator'
   *  Integrator: '<S220>/Integrator1'
   *  Integrator: '<S220>/Integrator2'
   */
  rtb_ProportionalGain_nx = ((rtb_Abs_i * rtb_DerivativeGain_a *
    rtb_PulseGenerator + rtb_ProportionalGain_nx * rtb_ProportionalGain_c) *
    GRM_HIL_X.Integrator1_CSTATE_p + GRM_HIL_X.Integrator_CSTATE_j *
    rtb_PulseGenerator * rtb_Abs_lo) + (rtb_DerivativeGain_a *
    rtb_PulseGenerator * rtb_ProportionalGain_c - rtb_ProportionalGain_nx *
    rtb_Abs_i) * GRM_HIL_X.Integrator2_CSTATE_a;

  /* MATLAB Function: '<S206>/MATLAB Function2' incorporates:
   *  Integrator: '<S220>/Integrator'
   *  Integrator: '<S220>/Integrator1'
   *  Integrator: '<S220>/Integrator2'
   */
  rtb_DerivativeGain_a = (GRM_HIL_X.Integrator1_CSTATE_p * rtb_Abs_lo *
    rtb_Abs_i + -GRM_HIL_X.Integrator_CSTATE_j * rtb_DerivativeGain_a) +
    GRM_HIL_X.Integrator2_CSTATE_a * rtb_Abs_lo * rtb_ProportionalGain_c;

  /* Integrator: '<S219>/Integrator1' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Integrator: '<S219>/Integrator2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_d != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_d = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator1_IWORK_n != 0)) {
      GRM_HIL_X.Integrator1_CSTATE_e = GRM_HIL_B.POS_mue_WGS84_rad;
    }

    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_g != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_g = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator2_IWORK_e != 0)) {
      GRM_HIL_X.Integrator2_CSTATE_d = GRM_HIL_B.POS_h_WGS84_m;
    }
  }

  /* MATLAB Function: '<S202>/MATLAB Function' incorporates:
   *  Integrator: '<S219>/Integrator1'
   */
  rtb_PulseGenerator = sin(GRM_HIL_X.Integrator1_CSTATE_e);
  rtb_DerivativeGain = 1.0 - rtb_PulseGenerator * rtb_PulseGenerator *
    0.0066943800042608363;
  rtb_ProportionalGain = 6.378137E+6 / sqrt(rtb_DerivativeGain);

  /* Gain: '<S204>/Gain' incorporates:
   *  Sum: '<S204>/Add12'
   */
  GRM_HIL_B.Gain_o = (((rtb_Fin_1_Pos_rad + rtb_Fin_2_Pos_rad) +
                       rtb_Fin_3_Pos_rad) + rtb_Fin_4_Pos_rad) *
    GRM_HIL_P.Gain_Gain_kk;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S215>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     */
    GRM_HIL_B.DataTypeConversion_i = GRM_HIL_P.Constant_Value_g;

    /* DataTypeConversion: '<S217>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     */
    GRM_HIL_B.DataTypeConversion_d = GRM_HIL_P.Constant_Value_g;
  }

  /* Fcn: '<S205>/Fcn5' incorporates:
   *  Fcn: '<S205>/Fcn7'
   *  Integrator: '<S215>/Integrator1'
   */
  rtb_Fin_1_Pos_rad = tan(GRM_HIL_X.Integrator1_CSTATE);

  /* Product: '<S215>/Product' incorporates:
   *  Fcn: '<S205>/Fcn5'
   *  Product: '<S205>/Multiply'
   *  Product: '<S205>/Multiply1'
   *  Product: '<S205>/Multiply2'
   *  Product: '<S205>/Multiply3'
   *  Sum: '<S205>/Add'
   */
  GRM_HIL_B.Product_f = ((rtb_Abs_i * rtb_Fin_1_Pos_rad * rtb_q_B_radDs +
    rtb_p_B_radDs) + rtb_ProportionalGain_c * rtb_Fin_1_Pos_rad * rtb_r_B_radDs)
    * GRM_HIL_B.DataTypeConversion_i;

  /* Product: '<S215>/Product1' incorporates:
   *  Fcn: '<S205>/Fcn1'
   *  Product: '<S205>/Multiply4'
   *  Product: '<S205>/Multiply5'
   *  Sum: '<S205>/Add1'
   */
  GRM_HIL_B.Product1_j = (rtb_ProportionalGain_c * rtb_q_B_radDs + -rtb_Abs_i *
    rtb_r_B_radDs) * GRM_HIL_B.DataTypeConversion_i;

  /* Product: '<S215>/Product2' incorporates:
   *  Product: '<S205>/Divide'
   *  Product: '<S205>/Divide1'
   *  Product: '<S205>/Multiply6'
   *  Product: '<S205>/Multiply7'
   *  Sum: '<S205>/Add2'
   */
  GRM_HIL_B.Product2 = (rtb_Abs_i / rtb_Abs_lo * rtb_q_B_radDs +
                        rtb_ProportionalGain_c / rtb_Abs_lo * rtb_r_B_radDs) *
    GRM_HIL_B.DataTypeConversion_i;

  /* Product: '<S217>/Multiply' */
  GRM_HIL_B.Multiply = GRM_HIL_B.OutportBufferFormotor_state_perc_dot *
    GRM_HIL_B.DataTypeConversion_d;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S218>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     */
    GRM_HIL_B.DataTypeConversion_n = GRM_HIL_P.Constant_Value_g;
  }

  /* Integrator: '<S218>/Integrator' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Integrator: '<S218>/Integrator1'
   *  Integrator: '<S218>/Integrator2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_k = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator_IWORK_m != 0)) {
      GRM_HIL_X.Integrator_CSTATE_d = GRM_HIL_B.POS_x_NED_m;
    }

    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_i != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator1_Reset_ZCE_i = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator1_IWORK_m != 0)) {
      GRM_HIL_X.Integrator1_CSTATE_eg = GRM_HIL_B.POS_y_NED_m;
    }

    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_m != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator2_Reset_ZCE_m = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator2_IWORK_c != 0)) {
      GRM_HIL_X.Integrator2_CSTATE_e = GRM_HIL_B.POS_z_NED_m;
    }
  }

  /* End of Integrator: '<S218>/Integrator' */

  /* Product: '<S218>/Product' */
  GRM_HIL_B.Product_b = rtb_DerivativeGain_f * GRM_HIL_B.DataTypeConversion_n;

  /* Product: '<S218>/Product1' */
  GRM_HIL_B.Product1_f = rtb_ProportionalGain_nx *
    GRM_HIL_B.DataTypeConversion_n;

  /* Product: '<S218>/Product2' */
  GRM_HIL_B.Product2_d = rtb_DerivativeGain_a * GRM_HIL_B.DataTypeConversion_n;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S219>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     */
    GRM_HIL_B.DataTypeConversion_k = GRM_HIL_P.Constant_Value_g;
  }

  /* Integrator: '<S219>/Integrator' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  if (rtmIsMajorTimeStep(GRM_HIL_M)) {
    rtb_RelationalOperator = (GRM_HIL_P.Constant2_Value_f &&
      (GRM_HIL_PrevZCX.Integrator_Reset_ZCE_ff != POS_ZCSIG));
    GRM_HIL_PrevZCX.Integrator_Reset_ZCE_ff = GRM_HIL_P.Constant2_Value_f;

    /* evaluate zero-crossings */
    if (rtb_RelationalOperator || (GRM_HIL_DW.Integrator_IWORK_l != 0)) {
      GRM_HIL_X.Integrator_CSTATE_jz = GRM_HIL_B.POS_lambda_WGS84_rad;
    }
  }

  /* End of Integrator: '<S219>/Integrator' */

  /* Product: '<S219>/Product' incorporates:
   *  Integrator: '<S219>/Integrator1'
   *  Integrator: '<S219>/Integrator2'
   *  MATLAB Function: '<S202>/MATLAB Function'
   */
  GRM_HIL_B.Product_g = rtb_ProportionalGain_nx / ((rtb_ProportionalGain +
    GRM_HIL_X.Integrator2_CSTATE_d) * cos(GRM_HIL_X.Integrator1_CSTATE_e)) *
    GRM_HIL_B.DataTypeConversion_k;

  /* Product: '<S219>/Product1' incorporates:
   *  Integrator: '<S219>/Integrator2'
   *  MATLAB Function: '<S202>/MATLAB Function'
   */
  GRM_HIL_B.Product1_g = rtb_DerivativeGain_f / (rtb_ProportionalGain *
    0.99330561999573919 / rtb_DerivativeGain + GRM_HIL_X.Integrator2_CSTATE_d) *
    GRM_HIL_B.DataTypeConversion_k;

  /* Product: '<S219>/Product2' incorporates:
   *  MATLAB Function: '<S202>/MATLAB Function'
   */
  GRM_HIL_B.Product2_d1 = -rtb_DerivativeGain_a * GRM_HIL_B.DataTypeConversion_k;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S220>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     */
    GRM_HIL_B.DataTypeConversion_e = GRM_HIL_P.Constant_Value_g;

    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant9'
     *  Logic: '<S7>/NOT'
     */
    GRM_HIL_B.LogicalOperator2 = (GRM_HIL_P.Constant1_Value_c &&
      (!GRM_HIL_P.Constant9_Value_b) && GRM_HIL_P.Constant3_Value_i);
  }

  /* Product: '<S220>/Product' */
  GRM_HIL_B.Product_p = rtb_Add_g * GRM_HIL_B.DataTypeConversion_e;

  /* Product: '<S220>/Product1' */
  GRM_HIL_B.Product1_o = rtb_ACC_y_B_mDs2 * GRM_HIL_B.DataTypeConversion_e;

  /* Product: '<S220>/Product2' */
  GRM_HIL_B.Product2_n = rtb_ACC_z_B_mDs2 * GRM_HIL_B.DataTypeConversion_e;

  /* Outputs for Enabled SubSystem: '<S7>/Synchronize_to_realtime' incorporates:
   *  EnablePort: '<S221>/Enable'
   */
  /* SignalConversion generated from: '<S221>/Enable' */
  if ((rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[2] == 0) && GRM_HIL_B.LogicalOperator2)
  {
    /* S-Function (sldrtsync): '<S221>/Real-Time Synchronization' */
    /* S-Function Block: <S221>/Real-Time Synchronization */
    {
    }

    if (rtmIsMajorTimeStep(GRM_HIL_M)) {
      srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
    }
  }

  /* End of SignalConversion generated from: '<S221>/Enable' */
  /* End of Outputs for SubSystem: '<S7>/Synchronize_to_realtime' */
}

/* Model update function */
void GRM_HIL_update(void)
{
  /* Update for Enabled SubSystem: '<S197>/Propulsion' incorporates:
   *  EnablePort: '<S203>/Enable'
   */
  if (GRM_HIL_DW.Propulsion_MODE && (rtmIsMajorTimeStep(GRM_HIL_M) &&
       GRM_HIL_M->Timing.TaskCounters.TID[1] == 0)) {
    /* Update for Memory: '<S203>/lock' */
    GRM_HIL_DW.lock_PreviousInput = GRM_HIL_B.LogicalOperator1_ii;
  }

  /* End of Update for SubSystem: '<S197>/Propulsion' */

  /* Update for Integrator: '<S217>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK = 0;

  /* Update for Integrator: '<S215>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_i = 0;

  /* Update for Integrator: '<S215>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S215>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK = 0;
  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S36>/Memory' */
    GRM_HIL_DW.Memory_1_PreviousInput = GRM_HIL_B.cmd_pass_enable_flg;

    /* Update for Memory generated from: '<S36>/Memory' */
    GRM_HIL_DW.Memory_2_PreviousInput = GRM_HIL_B.emergency_stop_flg;

    /* Update for Memory generated from: '<S36>/Memory1' */
    GRM_HIL_DW.Memory1_1_PreviousInput = GRM_HIL_B.Sum;
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

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S36>/Memory1' */
    GRM_HIL_DW.Memory1_2_PreviousInput = GRM_HIL_B.Sum1;
  }

  /* Update for TransportDelay: '<S174>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK_i.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK_i.Head <
        (GRM_HIL_DW.TransportDelay_IWORK_i.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK_i.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK_i.Head ==
        GRM_HIL_DW.TransportDelay_IWORK_i.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK_i.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK_i.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK_i.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK_i.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK_i.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK_i.Head] = GRM_HIL_B.pitch_deg;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S36>/Memory1' */
    GRM_HIL_DW.Memory1_3_PreviousInput = GRM_HIL_B.Sum2;
  }

  /* Update for TransportDelay: '<S175>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs[1];
    real_T simTime = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_IWORK_k.Head =
      ((GRM_HIL_DW.TransportDelay_IWORK_k.Head <
        (GRM_HIL_DW.TransportDelay_IWORK_k.CircularBufSize-1)) ?
       (GRM_HIL_DW.TransportDelay_IWORK_k.Head+1) : 0);
    if (GRM_HIL_DW.TransportDelay_IWORK_k.Head ==
        GRM_HIL_DW.TransportDelay_IWORK_k.Tail) {
      GRM_HIL_DW.TransportDelay_IWORK_k.Tail =
        ((GRM_HIL_DW.TransportDelay_IWORK_k.Tail <
          (GRM_HIL_DW.TransportDelay_IWORK_k.CircularBufSize-1)) ?
         (GRM_HIL_DW.TransportDelay_IWORK_k.Tail+1) : 0);
    }

    (*tBuffer)[GRM_HIL_DW.TransportDelay_IWORK_k.Head] = simTime;
    (*uBuffer)[GRM_HIL_DW.TransportDelay_IWORK_k.Head] = GRM_HIL_B.roll_deg;
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
      GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S18>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_B.value;
  }

  /* Update for Integrator: '<S220>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_ic = 0;

  /* Update for Integrator: '<S220>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_g = 0;

  /* Update for Integrator: '<S220>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_m = 0;

  /* Update for Integrator: '<S219>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_n = 0;

  /* Update for Integrator: '<S219>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_e = 0;

  /* Update for Integrator: '<S218>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_m = 0;

  /* Update for Integrator: '<S218>/Integrator1' */
  GRM_HIL_DW.Integrator1_IWORK_m = 0;

  /* Update for Integrator: '<S218>/Integrator2' */
  GRM_HIL_DW.Integrator2_IWORK_c = 0;

  /* Update for Integrator: '<S219>/Integrator' */
  GRM_HIL_DW.Integrator_IWORK_l = 0;
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
  int_T is;
  real_T TransferFcn1_CSTATE_tmp;
  real_T TransferFcn1_CSTATE_tmp_0;
  XDot_GRM_HIL_T *_rtXdot;
  _rtXdot = ((XDot_GRM_HIL_T *) GRM_HIL_M->derivs);

  /* Derivatives for Integrator: '<S217>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.Multiply;

  /* Derivatives for Integrator: '<S215>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = GRM_HIL_B.Product_f;

  /* Derivatives for Integrator: '<S215>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = GRM_HIL_B.Product1_j;

  /* Derivatives for Integrator: '<S215>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = GRM_HIL_B.Product2;

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn' */
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

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn1' incorporates:
   *  TransferFcn: '<S10>/Transfer Fcn2'
   *  TransferFcn: '<S10>/Transfer Fcn3'
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

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] += GRM_HIL_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] += GRM_HIL_B.Saturation_jy;

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += GRM_HIL_B.Saturation_a;

  /* Derivatives for TransferFcn: '<S197>/dy2ay' */
  _rtXdot->dy2ay_CSTATE[0] = 0.0;
  _rtXdot->dy2ay_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] * GRM_HIL_X.dy2ay_CSTATE[0];
  _rtXdot->dy2ay_CSTATE[1] = 0.0;
  _rtXdot->dy2ay_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dy2ay.denom[0] * GRM_HIL_X.dy2ay_CSTATE[1];
  _rtXdot->dy2ay_CSTATE[1] += GRM_HIL_X.dy2ay_CSTATE[0];
  _rtXdot->dy2ay_CSTATE[0] += GRM_HIL_B.Gain2;

  /* Derivatives for TransferFcn: '<S197>/dp2az' */
  _rtXdot->dp2az_CSTATE[0] = 0.0;
  _rtXdot->dp2az_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2az.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] * GRM_HIL_X.dp2az_CSTATE[0];
  _rtXdot->dp2az_CSTATE[1] = 0.0;
  _rtXdot->dp2az_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2az.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dp2az.denom[0] * GRM_HIL_X.dp2az_CSTATE[1];
  _rtXdot->dp2az_CSTATE[1] += GRM_HIL_X.dp2az_CSTATE[0];
  _rtXdot->dp2az_CSTATE[0] += GRM_HIL_B.Gain1;

  /* Derivatives for TransferFcn: '<S197>/dr2roll' */
  _rtXdot->dr2roll_CSTATE = 0.0;
  _rtXdot->dr2roll_CSTATE += -GRM_HIL_P.FDM_Linear_TF.dr2roll.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dr2roll.denom[0] * GRM_HIL_X.dr2roll_CSTATE;
  _rtXdot->dr2roll_CSTATE += GRM_HIL_B.Gain_o;

  /* Derivatives for TransferFcn: '<S197>/dp2pitch' */
  _rtXdot->dp2pitch_CSTATE[0] = 0.0;
  _rtXdot->dp2pitch_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[0];
  _rtXdot->dp2pitch_CSTATE[1] = 0.0;
  _rtXdot->dp2pitch_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dp2pitch.denom[0] * GRM_HIL_X.dp2pitch_CSTATE[1];
  _rtXdot->dp2pitch_CSTATE[1] += GRM_HIL_X.dp2pitch_CSTATE[0];
  _rtXdot->dp2pitch_CSTATE[0] += GRM_HIL_B.Gain1;

  /* Derivatives for TransferFcn: '<S197>/dy2yaw' */
  _rtXdot->dy2yaw_CSTATE[0] = 0.0;
  _rtXdot->dy2yaw_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[1] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[0];
  _rtXdot->dy2yaw_CSTATE[1] = 0.0;
  _rtXdot->dy2yaw_CSTATE[0] += -GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[2] /
    GRM_HIL_P.FDM_Linear_TF.dy2yaw.denom[0] * GRM_HIL_X.dy2yaw_CSTATE[1];
  _rtXdot->dy2yaw_CSTATE[1] += GRM_HIL_X.dy2yaw_CSTATE[0];
  _rtXdot->dy2yaw_CSTATE[0] += GRM_HIL_B.Gain2;

  /* Derivatives for TransferFcn: '<S49>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_d[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE_d[0] += GRM_HIL_P.TransferFcn1_A[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_d[0];
  _rtXdot->TransferFcn1_CSTATE_d[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE_d[0] += GRM_HIL_P.TransferFcn1_A[1] *
    GRM_HIL_X.TransferFcn1_CSTATE_d[1];
  _rtXdot->TransferFcn1_CSTATE_d[1] += GRM_HIL_X.TransferFcn1_CSTATE_d[0];
  _rtXdot->TransferFcn1_CSTATE_d[0] += GRM_HIL_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S73>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = GRM_HIL_B.SumI1_i;

  /* Derivatives for Integrator: '<S73>/Filter' */
  _rtXdot->Filter_CSTATE = GRM_HIL_B.FilterCoefficient;

  /* Derivatives for Enabled SubSystem: '<S71>/Control_Limits' */
  if (GRM_HIL_DW.Control_Limits_MODE) {
    /* Derivatives for Integrator: '<S107>/Integrator' */
    _rtXdot->Integrator_CSTATE_i = GRM_HIL_B.SumI4;

    /* Derivatives for Integrator: '<S102>/Filter' */
    _rtXdot->Filter_CSTATE_p = GRM_HIL_B.FilterCoefficient_f;

    /* Derivatives for Integrator: '<S151>/Integrator' */
    _rtXdot->Integrator_CSTATE_fq = GRM_HIL_B.SumI4_c;

    /* Derivatives for Integrator: '<S146>/Filter' */
    _rtXdot->Filter_CSTATE_k = GRM_HIL_B.FilterCoefficient_j;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_GRM_HIL_T *) GRM_HIL_M->derivs)->Integrator_CSTATE_i);
      for (i=0; i < 4; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S71>/Control_Limits' */

  /* Derivatives for Integrator: '<S54>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = GRM_HIL_B.SumI1;

  /* Derivatives for Integrator: '<S54>/Filter' */
  _rtXdot->Filter_CSTATE_i = GRM_HIL_B.FilterCoefficient_a;

  /* Derivatives for Integrator: '<S63>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = GRM_HIL_B.SumI1_n;

  /* Derivatives for Integrator: '<S63>/Filter' */
  _rtXdot->Filter_CSTATE_n = GRM_HIL_B.FilterCoefficient_l;

  /* Derivatives for TransferFcn: '<S39>/Phi2Motor -> Roll' */
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

  /* Derivatives for TransferFcn: '<S39>/Theta2Motor -> Pitch' */
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
  _rtXdot->Theta2MotorPitch_CSTATE[0] += GRM_HIL_B.Merge1_o;

  /* End of Derivatives for TransferFcn: '<S39>/Theta2Motor -> Pitch' */

  /* Derivatives for TransferFcn: '<S39>/Psi2Motor -> Yaw' */
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
  _rtXdot->Psi2MotorYaw_CSTATE[0] += GRM_HIL_B.Merge_o;

  /* Derivatives for TransferFcn: '<S24>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_j = 0.0;
  _rtXdot->TransferFcn_CSTATE_j +=
    -GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[1] /
    GRM_HIL_P.FlightController_FCC.Roll.Lead.Denom[0] *
    GRM_HIL_X.TransferFcn_CSTATE_j;
  _rtXdot->TransferFcn_CSTATE_j += GRM_HIL_B.Gain_a;

  /* Derivatives for TransferFcn: '<S24>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE_e = 0.0;
  _rtXdot->TransferFcn2_CSTATE_e +=
    -GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[1] /
    GRM_HIL_P.FlightController_FCC.Yaw.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn2_CSTATE_e;
  _rtXdot->TransferFcn2_CSTATE_e += GRM_HIL_B.Sum3;

  /* Derivatives for TransferFcn: '<S24>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_e = 0.0;
  _rtXdot->TransferFcn1_CSTATE_e +=
    -GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[1] /
    GRM_HIL_P.FlightController_FCC.Pitch.outerLoop.IntGain.Denom[0] *
    GRM_HIL_X.TransferFcn1_CSTATE_e;
  _rtXdot->TransferFcn1_CSTATE_e += GRM_HIL_B.Sum1_d;

  /* Derivatives for Integrator: '<S220>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = GRM_HIL_B.Product_p;

  /* Derivatives for Integrator: '<S220>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = GRM_HIL_B.Product1_o;

  /* Derivatives for Integrator: '<S220>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = GRM_HIL_B.Product2_n;

  /* Derivatives for Integrator: '<S219>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = GRM_HIL_B.Product1_g;

  /* Derivatives for Integrator: '<S219>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_d = GRM_HIL_B.Product2_d1;

  /* Derivatives for Integrator: '<S218>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = GRM_HIL_B.Product_b;

  /* Derivatives for Integrator: '<S218>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_eg = GRM_HIL_B.Product1_f;

  /* Derivatives for Integrator: '<S218>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = GRM_HIL_B.Product2_d;

  /* Derivatives for Integrator: '<S219>/Integrator' */
  _rtXdot->Integrator_CSTATE_jz = GRM_HIL_B.Product_g;
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
  /* Start for Enabled SubSystem: '<S197>/Propulsion' */
  GRM_HIL_DW.Propulsion_MODE = false;

  /* Start for Enabled SubSystem: '<S203>/hold_time' */
  GRM_HIL_DW.hold_time_MODE = false;

  /* End of Start for SubSystem: '<S203>/hold_time' */

  /* Start for Enabled SubSystem: '<S203>/Subsystem' */
  GRM_HIL_DW.Subsystem_MODE = false;

  /* End of Start for SubSystem: '<S203>/Subsystem' */
  /* End of Start for SubSystem: '<S197>/Propulsion' */

  /* Start for Enabled SubSystem: '<S197>/Gravity' */
  GRM_HIL_DW.Gravity_MODE = false;

  /* End of Start for SubSystem: '<S197>/Gravity' */

  /* Start for Enabled SubSystem: '<S197>/Drag' */
  GRM_HIL_DW.Drag_MODE = false;

  /* End of Start for SubSystem: '<S197>/Drag' */

  /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator1' */
  GRM_HIL_DW.clockTickCounter = -30000;

  /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator' */
  GRM_HIL_DW.clockTickCounter_d = -10000;

  /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator4' */
  GRM_HIL_DW.clockTickCounter_d3 = -40000;

  /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator3' */
  GRM_HIL_DW.clockTickCounter_e = -10000;

  /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator7' */
  GRM_HIL_DW.clockTickCounter_o = -40000;

  /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator6' */
  GRM_HIL_DW.clockTickCounter_l = -10000;

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
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK_l.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK_i.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK_i.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK_i.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK_i.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput_j;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for TransportDelay: '<S175>/Transport Delay' */
  {
    real_T *pBuffer = &GRM_HIL_DW.TransportDelay_RWORK_b.TUbufferArea[0];
    GRM_HIL_DW.TransportDelay_IWORK_k.Tail = 0;
    GRM_HIL_DW.TransportDelay_IWORK_k.Head = 0;
    GRM_HIL_DW.TransportDelay_IWORK_k.Last = 0;
    GRM_HIL_DW.TransportDelay_IWORK_k.CircularBufSize = 1024;
    pBuffer[0] = GRM_HIL_P.TransportDelay_InitOutput_g;
    pBuffer[1024] = GRM_HIL_M->Timing.t[0];
    GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs[0] = (void *) &pBuffer[0];
    GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs[1] = (void *) &pBuffer[1024];
  }

  /* Start for Enabled SubSystem: '<S72>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass_a);

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
  GRM_HIL_DW.Enabledadapt_MODE_n = false;

  /* End of Start for SubSystem: '<S53>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S62>/Enabled pass' */
  GRM_HIL_Enabledpass_Start(&GRM_HIL_DW.Enabledpass_j);

  /* End of Start for SubSystem: '<S62>/Enabled pass' */

  /* Start for Enabled SubSystem: '<S62>/Enabled adapt' */
  GRM_HIL_DW.Enabledadapt_MODE_h = false;

  /* End of Start for SubSystem: '<S62>/Enabled adapt' */

  /* Start for Enabled SubSystem: '<S45>/Voltage_Limitations' */
  GRM_HIL_DW.Voltage_Limitations_MODE = false;

  /* Start for If: '<S52>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_a = -1;

  /* Start for If: '<S52>/If1' */
  GRM_HIL_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S52>/If2' */
  GRM_HIL_DW.If2_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S45>/Voltage_Limitations' */

  /* Start for Enabled SubSystem: '<S45>/If Action Pass' */
  GRM_HIL_DW.IfActionPass_MODE = false;

  /* End of Start for SubSystem: '<S45>/If Action Pass' */

  /* Start for Enabled SubSystem: '<S17>/Com_to_FCC_emul' */
  GRM_HIL_DW.Com_to_FCC_emul_MODE = false;

  /* End of Start for SubSystem: '<S17>/Com_to_FCC_emul' */

  /* Start for Enabled SubSystem: '<S28>/Pass' */
  GRM_HIL_DW.Pass_MODE = false;

  /* End of Start for SubSystem: '<S28>/Pass' */

  /* Start for Enabled SubSystem: '<S28>/Saturate' */
  GRM_HIL_DW.Saturate_MODE = false;

  /* End of Start for SubSystem: '<S28>/Saturate' */

  /* Start for If: '<S176>/If' */
  GRM_HIL_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S174>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_l = -1;

  /* Start for If: '<S175>/If' */
  GRM_HIL_DW.If_ActiveSubsystem_g = -1;
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

  {
    int_T is;

    /* InitializeConditions for Integrator: '<S217>/Integrator' incorporates:
     *  Integrator: '<S215>/Integrator'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator_CSTATE = 0.0;
      GRM_HIL_X.Integrator_CSTATE_k = 0.0;
    }

    GRM_HIL_DW.Integrator_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S217>/Integrator' */

    /* InitializeConditions for Integrator: '<S215>/Integrator' */
    GRM_HIL_DW.Integrator_IWORK_i = 1;

    /* InitializeConditions for Integrator: '<S215>/Integrator1' incorporates:
     *  Integrator: '<S215>/Integrator2'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator1_CSTATE = 0.0;
      GRM_HIL_X.Integrator2_CSTATE = 0.0;
    }

    GRM_HIL_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S215>/Integrator1' */

    /* InitializeConditions for Integrator: '<S215>/Integrator2' */
    GRM_HIL_DW.Integrator2_IWORK = 1;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn3' */
    GRM_HIL_X.TransferFcn3_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dy2ay' */
    GRM_HIL_X.dy2ay_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dp2az' */
    GRM_HIL_X.dp2az_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn3' */
    GRM_HIL_X.TransferFcn3_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dy2ay' */
    GRM_HIL_X.dy2ay_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dp2az' */
    GRM_HIL_X.dp2az_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dr2roll' */
    GRM_HIL_X.dr2roll_CSTATE = 0.0;

    /* InitializeConditions for Memory generated from: '<S36>/Memory' */
    GRM_HIL_DW.Memory_1_PreviousInput = GRM_HIL_P.Memory_1_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S36>/Memory' */
    GRM_HIL_DW.Memory_2_PreviousInput = GRM_HIL_P.Memory_2_InitialCondition;

    /* InitializeConditions for TransferFcn: '<S197>/dp2pitch' */
    GRM_HIL_X.dp2pitch_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dy2yaw' */
    GRM_HIL_X.dy2yaw_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S49>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE_d[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dp2pitch' */
    GRM_HIL_X.dp2pitch_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S197>/dy2yaw' */
    GRM_HIL_X.dy2yaw_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S49>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE_d[1] = 0.0;

    /* InitializeConditions for Memory generated from: '<S36>/Memory1' */
    GRM_HIL_DW.Memory1_1_PreviousInput = GRM_HIL_P.Memory1_1_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S36>/Memory1' */
    GRM_HIL_DW.Memory1_2_PreviousInput = GRM_HIL_P.Memory1_2_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S36>/Memory1' */
    GRM_HIL_DW.Memory1_3_PreviousInput = GRM_HIL_P.Memory1_3_InitialCondition;

    /* InitializeConditions for Integrator: '<S73>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_c = GRM_HIL_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S73>/Filter' */
    GRM_HIL_X.Filter_CSTATE = GRM_HIL_P.Filter_IC;

    /* InitializeConditions for Integrator: '<S54>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_n = GRM_HIL_P.Integrator_IC_c;

    /* InitializeConditions for Integrator: '<S54>/Filter' */
    GRM_HIL_X.Filter_CSTATE_i = GRM_HIL_P.Filter_IC_c;

    /* InitializeConditions for Integrator: '<S63>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_f = GRM_HIL_P.Integrator_IC_m;

    /* InitializeConditions for Integrator: '<S63>/Filter' */
    GRM_HIL_X.Filter_CSTATE_n = GRM_HIL_P.Filter_IC_d;

    /* InitializeConditions for TransferFcn: '<S39>/Phi2Motor -> Roll' */
    GRM_HIL_X.Phi2MotorRoll_CSTATE[0] = 0.0;
    GRM_HIL_X.Phi2MotorRoll_CSTATE[1] = 0.0;
    GRM_HIL_X.Phi2MotorRoll_CSTATE[2] = 0.0;

    /* InitializeConditions for TransferFcn: '<S39>/Theta2Motor -> Pitch' */
    for (is = 0; is < 5; is++) {
      GRM_HIL_X.Theta2MotorPitch_CSTATE[is] = 0.0;
    }

    /* End of InitializeConditions for TransferFcn: '<S39>/Theta2Motor -> Pitch' */

    /* InitializeConditions for TransferFcn: '<S39>/Psi2Motor -> Yaw' */
    GRM_HIL_X.Psi2MotorYaw_CSTATE[0] = 0.0;
    GRM_HIL_X.Psi2MotorYaw_CSTATE[1] = 0.0;

    /* InitializeConditions for Memory: '<S18>/Memory' */
    GRM_HIL_DW.Memory_PreviousInput = GRM_HIL_P.Memory_InitialCondition;

    /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn' */
    GRM_HIL_X.TransferFcn_CSTATE_j = 0.0;

    /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn2' */
    GRM_HIL_X.TransferFcn2_CSTATE_e = 0.0;

    /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn1' */
    GRM_HIL_X.TransferFcn1_CSTATE_e = 0.0;

    /* InitializeConditions for Integrator: '<S220>/Integrator' incorporates:
     *  Integrator: '<S220>/Integrator1'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator_CSTATE_j = 0.0;
      GRM_HIL_X.Integrator1_CSTATE_p = 0.0;
    }

    GRM_HIL_DW.Integrator_IWORK_ic = 1;

    /* End of InitializeConditions for Integrator: '<S220>/Integrator' */

    /* InitializeConditions for Integrator: '<S220>/Integrator1' */
    GRM_HIL_DW.Integrator1_IWORK_g = 1;

    /* InitializeConditions for Integrator: '<S220>/Integrator2' incorporates:
     *  Integrator: '<S219>/Integrator1'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator2_CSTATE_a = 0.0;
      GRM_HIL_X.Integrator1_CSTATE_e = 0.0;
    }

    GRM_HIL_DW.Integrator2_IWORK_m = 1;

    /* End of InitializeConditions for Integrator: '<S220>/Integrator2' */

    /* InitializeConditions for Integrator: '<S219>/Integrator1' */
    GRM_HIL_DW.Integrator1_IWORK_n = 1;

    /* InitializeConditions for Integrator: '<S219>/Integrator2' incorporates:
     *  Integrator: '<S218>/Integrator'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator2_CSTATE_d = 0.0;
      GRM_HIL_X.Integrator_CSTATE_d = 0.0;
    }

    GRM_HIL_DW.Integrator2_IWORK_e = 1;

    /* End of InitializeConditions for Integrator: '<S219>/Integrator2' */

    /* InitializeConditions for Integrator: '<S218>/Integrator' */
    GRM_HIL_DW.Integrator_IWORK_m = 1;

    /* InitializeConditions for Integrator: '<S218>/Integrator1' incorporates:
     *  Integrator: '<S218>/Integrator2'
     */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator1_CSTATE_eg = 0.0;
      GRM_HIL_X.Integrator2_CSTATE_e = 0.0;
    }

    GRM_HIL_DW.Integrator1_IWORK_m = 1;

    /* End of InitializeConditions for Integrator: '<S218>/Integrator1' */

    /* InitializeConditions for Integrator: '<S218>/Integrator2' */
    GRM_HIL_DW.Integrator2_IWORK_c = 1;

    /* InitializeConditions for Integrator: '<S219>/Integrator' */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      GRM_HIL_X.Integrator_CSTATE_jz = 0.0;
    }

    GRM_HIL_DW.Integrator_IWORK_l = 1;

    /* End of InitializeConditions for Integrator: '<S219>/Integrator' */

    /* SystemInitialize for Enabled SubSystem: '<S197>/Propulsion' */
    /* InitializeConditions for Memory: '<S203>/lock' */
    GRM_HIL_DW.lock_PreviousInput = GRM_HIL_P.lock_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S203>/hold_time' */
    /* SystemInitialize for Outport: '<S211>/exec_time_hold_s' */
    GRM_HIL_B.Clock = GRM_HIL_P.exec_time_hold_s_Y0;

    /* End of SystemInitialize for SubSystem: '<S203>/hold_time' */

    /* SystemInitialize for Enabled SubSystem: '<S203>/Subsystem' */
    /* SystemInitialize for Outport: '<S210>/thrust' */
    GRM_HIL_B.OutportBufferForthrust = GRM_HIL_P.thrust_Y0;

    /* SystemInitialize for Outport: '<S210>/state_percentage_change' */
    GRM_HIL_B.Add1 = GRM_HIL_P.state_percentage_change_Y0;

    /* End of SystemInitialize for SubSystem: '<S203>/Subsystem' */

    /* SystemInitialize for Outport: '<S203>/motor_state_perc_dot' */
    GRM_HIL_B.OutportBufferFormotor_state_perc_dot =
      GRM_HIL_P.motor_state_perc_dot_Y0;

    /* End of SystemInitialize for SubSystem: '<S197>/Propulsion' */

    /* SystemInitialize for Enabled SubSystem: '<S197>/Gravity' */
    /* SystemInitialize for Outport: '<S201>/acc_x_grav_mDs' */
    GRM_HIL_B.acc_x = GRM_HIL_P.acc_x_grav_mDs_Y0;

    /* SystemInitialize for Outport: '<S201>/acc_y_grav_mDs' */
    GRM_HIL_B.acc_y = GRM_HIL_P.acc_y_grav_mDs_Y0;

    /* SystemInitialize for Outport: '<S201>/acc_z_grav_mDs' */
    GRM_HIL_B.acc_z = GRM_HIL_P.acc_z_grav_mDs_Y0;

    /* End of SystemInitialize for SubSystem: '<S197>/Gravity' */

    /* SystemInitialize for Enabled SubSystem: '<S197>/Drag' */
    /* SystemInitialize for Outport: '<S200>/acc_x_drag_mDs2' */
    GRM_HIL_B.OutportBufferForacc_x_drag_mDs2 = GRM_HIL_P.acc_x_drag_mDs2_Y0;

    /* SystemInitialize for Outport: '<S200>/acc_y_drag_mDs2' */
    GRM_HIL_B.OutportBufferForacc_y_drag_mDs2 = GRM_HIL_P.acc_y_drag_mDs2_Y0;

    /* SystemInitialize for Outport: '<S200>/acc_z_drag_mDs2' */
    GRM_HIL_B.OutportBufferForacc_z_drag_mDs2 = GRM_HIL_P.acc_z_drag_mDs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S197>/Drag' */

    /* SystemInitialize for Merge: '<S73>/Merge' */
    GRM_HIL_B.Merge_f = GRM_HIL_P.Merge_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S71>/Control_Limits' */
    /* InitializeConditions for Integrator: '<S107>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_i =
      GRM_HIL_P.PIDController_InitialConditionForIntegrator;

    /* InitializeConditions for Integrator: '<S102>/Filter' */
    GRM_HIL_X.Filter_CSTATE_p =
      GRM_HIL_P.PIDController_InitialConditionForFilter;

    /* InitializeConditions for Integrator: '<S151>/Integrator' */
    GRM_HIL_X.Integrator_CSTATE_fq =
      GRM_HIL_P.PIDController1_InitialConditionForIntegrator;

    /* InitializeConditions for Integrator: '<S146>/Filter' */
    GRM_HIL_X.Filter_CSTATE_k =
      GRM_HIL_P.PIDController1_InitialConditionForFilter;

    /* End of SystemInitialize for SubSystem: '<S71>/Control_Limits' */

    /* SystemInitialize for Merge: '<S71>/Merge' */
    GRM_HIL_B.Merge_a = GRM_HIL_P.Merge_InitialOutput_d;

    /* SystemInitialize for Merge: '<S54>/Merge' */
    GRM_HIL_B.Merge_fu = GRM_HIL_P.Merge_InitialOutput_a;

    /* SystemInitialize for Merge: '<S63>/Merge' */
    GRM_HIL_B.Merge_c = GRM_HIL_P.Merge_InitialOutput_j;

    /* SystemInitialize for Merge: '<S45>/Merge' */
    GRM_HIL_B.Merge_o = GRM_HIL_P.Merge_InitialOutput_a0;

    /* SystemInitialize for Merge: '<S45>/Merge1' */
    GRM_HIL_B.Merge1_o = GRM_HIL_P.Merge1_InitialOutput;

    /* SystemInitialize for Merge: '<S45>/Merge2' */
    GRM_HIL_B.Merge2 = GRM_HIL_P.Merge2_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S17>/Com_to_FCC_emul' */
    /* SystemInitialize for Outport: '<S19>/States_hold' */
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

    /* SystemInitialize for Outport: '<S19>/External_Inputs_hold' */
    GRM_HIL_B.CMD_phi_rad =
      GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_phi_rad;
    GRM_HIL_B.CMD_acc_z_mDs2 =
      GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_acc_z_mDs2;
    GRM_HIL_B.CMD_acc_y_mDs2 =
      GRM_HIL_P.External_Inputs_hold_Y0.FCC_External_Inputs_Bus.CMD_acc_y_mDs2;

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

    /* SystemInitialize for IfAction SubSystem: '<S176>/If Action Subsystem1' */
    GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1_e,
      &GRM_HIL_P.IfActionSubsystem1_e);

    /* End of SystemInitialize for SubSystem: '<S176>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S176>/If Action Subsystem' */
    GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem_m,
      &GRM_HIL_P.IfActionSubsystem_m);

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
    GRM_HIL_IfActionSubsystem1_Init(&GRM_HIL_B.IfActionSubsystem1_j,
      &GRM_HIL_P.IfActionSubsystem1_j);

    /* End of SystemInitialize for SubSystem: '<S175>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S175>/If Action Subsystem' */
    GRM_HIL_IfActionSubsystem_Init(&GRM_HIL_B.IfActionSubsystem_p,
      &GRM_HIL_P.IfActionSubsystem_p);

    /* End of SystemInitialize for SubSystem: '<S175>/If Action Subsystem' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(GRM_HIL_M)) {
      rtmSetFirstInitCond(GRM_HIL_M, 0);
    }
  }
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
  /* (no terminate code required) */
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
  GRM_HIL_P.Constant2_Value_o = rtInf;
  GRM_HIL_P.Constant2_Value_h5 = rtInf;
  GRM_HIL_P.Constant2_Value_ht = rtInf;

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

  rtmSetTFinal(GRM_HIL_M, -1);
  GRM_HIL_M->Timing.stepSize0 = 0.001;
  GRM_HIL_M->Timing.stepSize1 = 0.001;
  GRM_HIL_M->Timing.stepSize2 = 0.01;
  GRM_HIL_M->Timing.stepSize3 = 0.02;
  rtmSetFirstInitCond(GRM_HIL_M, 1);

  /* External mode info */
  GRM_HIL_M->Sizes.checksums[0] = (143544100U);
  GRM_HIL_M->Sizes.checksums[1] = (3447471112U);
  GRM_HIL_M->Sizes.checksums[2] = (588967388U);
  GRM_HIL_M->Sizes.checksums[3] = (529766825U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[63];
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
    systemRan[25] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC_b;
    systemRan[26] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass_j.Enabledpass_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_j.Saturation_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_j.Saturation_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&GRM_HIL_DW.pass_c.pass_SubsysRanBC;
    systemRan[30] = (sysRanDType *)&GRM_HIL_DW.Control_Limits_SubsysRanBC;
    systemRan[31] = (sysRanDType *)&GRM_HIL_DW.pass_SubsysRanBC;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = (sysRanDType *)&GRM_HIL_DW.Enabledadapt_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &GRM_HIL_DW.Enabledpass_a.Enabledpass_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_e.Saturation_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &GRM_HIL_DW.Saturation_e.Saturation_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&GRM_HIL_DW.pass_l.pass_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&GRM_HIL_DW.IfActionPass_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &GRM_HIL_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC;
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
    systemRan[52] = (sysRanDType *)&GRM_HIL_DW.Drag_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&GRM_HIL_DW.Gravity_SubsysRanBC;
    systemRan[54] = (sysRanDType *)&GRM_HIL_DW.Gravity_SubsysRanBC;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = (sysRanDType *)&GRM_HIL_DW.Subsystem_SubsysRanBC;
    systemRan[57] = (sysRanDType *)&GRM_HIL_DW.hold_time_SubsysRanBC;
    systemRan[58] = (sysRanDType *)&GRM_HIL_DW.Propulsion_SubsysRanBC;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = (sysRanDType *)
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
    dtInfo.numDataTypes = 144;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_M->Sizes.numContStates = (55);/* Number of continuous states */
  GRM_HIL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (4); /* Number of sample times */
  GRM_HIL_M->Sizes.numBlocks = (770);  /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (230); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (213);/* Sum of parameter "widths" */
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

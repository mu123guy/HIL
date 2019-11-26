/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.44
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Nov  8 10:21:14 2019
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
  57.0,
  50.0,
  46.0,
  49.0,
  54.0,
  56.0,
  46.0,
  49.0,
  46.0,
  49.0,
  53.0,
  54.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
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
  int_T nXc = 33;
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
}

/* Model output function */
void GRM_HIL_output(void)
{
  /* local block i/o variables */
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

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Send_to_FTHWICC_SubsysRanBC);

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
      }
    }

    /* End of Constant: '<S7>/Constant4' */
  }

  if (GRM_HIL_DW.Propulsion_MODE) {
    if (rtmIsMajorTimeStep(GRM_HIL_M) &&
        GRM_HIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S60>/lock' */
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
      }
    }

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
    }
  }

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
     */
    GRM_HIL_B.ATT_Phi_rad = GRM_HIL_P.Gain9_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Att.ATT_Phi_rad;
  }

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
      }
    }

    /* End of Constant: '<S7>/Constant6' */
  }

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
      }

      /* End of Constant: '<S7>/Constant5' */
    }

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
      }
    }

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
    }

    /* End of Outputs for SubSystem: '<S17>/Com_to_FCC_emul' */
  }

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
    }

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

  /* Sum: '<S23>/Add2' incorporates:
   *  Fcn: '<S23>/Fcn4'
   *  Fcn: '<S23>/Fcn5'
   *  Product: '<S23>/Multiply4'
   *  Product: '<S23>/Multiply5'
   *  Sum: '<S23>/Add8'
   */
  rtb_sincos_o1_idx_2 = -cos(rtb_sincos_o1_idx_2) * GRM_HIL_B.Psi_Cmd_rad + sin
    (rtb_sincos_o1_idx_2) * GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add10' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Sum: '<S23>/Add11'
   */
  rtb_Add3 = GRM_HIL_P.FinDeflection_Control_Surfaces.phi_f4_rad +
    GRM_HIL_B.ATT_Phi_rad_f;

  /* Sum: '<S23>/Add3' incorporates:
   *  Fcn: '<S23>/Fcn6'
   *  Fcn: '<S23>/Fcn7'
   *  Product: '<S23>/Multiply6'
   *  Product: '<S23>/Multiply7'
   *  Sum: '<S23>/Add10'
   */
  rtb_Add3 = -cos(rtb_Add3) * GRM_HIL_B.Psi_Cmd_rad + sin(rtb_Add3) *
    GRM_HIL_B.Theta_Cmd_rad;

  /* Sum: '<S23>/Add16' incorporates:
   *  Abs: '<S23>/Abs'
   *  Constant: '<S23>/Constant4'
   */
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
    rtb_sincos_o1_idx_1 = fabs(fmax(fmax(fmax(rtb_sincos_o1_idx_0,
      rtb_PulseGenerator1), rtb_sincos_o1_idx_2), rtb_Add3));

    /* Product: '<S31>/Multiply' incorporates:
     *  Product: '<S31>/Divide'
     */
    GRM_HIL_B.Merge = rtb_sincos_o1_idx_0 / rtb_sincos_o1_idx_1 * rtb_Add16_j;

    /* Product: '<S31>/Multiply1' incorporates:
     *  Product: '<S31>/Divide1'
     */
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
  }

  /* End of Outputs for SubSystem: '<S28>/Saturate' */

  /* Sum: '<S23>/Add14' */
  GRM_HIL_B.Fin_4_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge3;

  /* Product: '<S35>/Product' incorporates:
   *  Constant: '<S32>/Constant6'
   *  Constant: '<S33>/Constant6'
   *  Constant: '<S34>/Constant6'
   *  Constant: '<S35>/Constant6'
   *  Product: '<S32>/Product'
   *  Product: '<S33>/Product'
   *  Product: '<S34>/Product'
   */
  rtb_sincos_o1_idx_0 = GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_max_ms -
    GRM_HIL_P.Servo_Cmd_PWM.Pulswidth_cmd_middle_pos_ms;

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S35>/Constant2'
   *  Constant: '<S35>/Constant6'
   *  Product: '<S35>/Divide'
   *  Product: '<S35>/Product'
   */
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
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Sum: '<S23>/Add13' */
  GRM_HIL_B.Fin_3_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge2;

  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S34>/Constant2'
   *  Product: '<S34>/Divide'
   *  Product: '<S34>/Product'
   */
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

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S23>/Add12' */
  GRM_HIL_B.Fin_2_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge1;

  /* Sum: '<S33>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S33>/Constant2'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Product'
   */
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

  /* End of Saturate: '<S33>/Saturation' */

  /* Sum: '<S23>/Add15' */
  GRM_HIL_B.Fin_1_Cmd_rad = rtb_PulseGenerator + GRM_HIL_B.Merge;

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S32>/Constant2'
   *  Product: '<S32>/Divide'
   *  Product: '<S32>/Product'
   */
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

    /* End of Saturate: '<S12>/Saturation' */

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

    /* End of Saturate: '<S13>/Saturation' */

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

    /* End of Saturate: '<S14>/Saturation' */

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

    /* End of Saturate: '<S15>/Saturation' */
  }

  if (rtmIsMajorTimeStep(GRM_HIL_M) &&
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
     */
    GRM_HIL_B.POS_y_NED_m = GRM_HIL_P.Gain16_Gain *
      GRM_HIL_P.Initial_States_Rigid_Body.Pos.POS_y_NED_m;

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
    }
  }

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

    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant9'
     *  Logic: '<S7>/NOT'
     */
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
      {
      }

      if (rtmIsMajorTimeStep(GRM_HIL_M)) {
        srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
      }
    }

    /* End of SignalConversion generated from: '<S78>/Enable' */
    /* End of Outputs for SubSystem: '<S7>/Synchronize_to_realtime' */

    /* Sum: '<S81>/FixPt Sum1' incorporates:
     *  Constant: '<S81>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)rtb_FixPtSum1 +
      GRM_HIL_P.FixPtConstant_Value);

    /* Switch: '<S82>/FixPt Switch' incorporates:
     *  Constant: '<S82>/Constant'
     */
    if (rtb_FixPtSum1 > GRM_HIL_P.WrapToZero_Threshold) {
      GRM_HIL_B.FixPtSwitch = GRM_HIL_P.Constant_Value_l;
    } else {
      GRM_HIL_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S82>/FixPt Switch' */
  }
}

/* Model update function */
void GRM_HIL_update(void)
{
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
  real_T TransferFcn1_CSTATE_tmp;
  real_T TransferFcn1_CSTATE_tmp_0;
  XDot_GRM_HIL_T *_rtXdot;
  _rtXdot = ((XDot_GRM_HIL_T *) GRM_HIL_M->derivs);

  /* Derivatives for Integrator: '<S74>/Integrator' */
  _rtXdot->Integrator_CSTATE = GRM_HIL_B.Multiply;

  /* Derivatives for Integrator: '<S72>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = GRM_HIL_B.Product;

  /* Derivatives for Integrator: '<S72>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = GRM_HIL_B.Product1;

  /* Derivatives for Integrator: '<S72>/Integrator2' */
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
  _rtXdot->TransferFcn_CSTATE[0] += GRM_HIL_B.Saturation;

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
  _rtXdot->TransferFcn2_CSTATE[0] += GRM_HIL_B.Saturation_j;

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp *
    GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += TransferFcn1_CSTATE_tmp_0 *
    GRM_HIL_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += GRM_HIL_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += GRM_HIL_B.Saturation_a;

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
  _rtXdot->TransferFcn1_CSTATE_e += GRM_HIL_B.Sum1;

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
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
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

  /* Start for Enabled SubSystem: '<S17>/Com_to_FCC_emul' */
  GRM_HIL_DW.Com_to_FCC_emul_MODE = false;

  /* End of Start for SubSystem: '<S17>/Com_to_FCC_emul' */

  /* Start for Enabled SubSystem: '<S28>/Pass' */
  GRM_HIL_DW.Pass_MODE = false;

  /* End of Start for SubSystem: '<S28>/Pass' */

  /* Start for Enabled SubSystem: '<S28>/Saturate' */
  GRM_HIL_DW.Saturate_MODE = false;

  /* End of Start for SubSystem: '<S28>/Saturate' */

  /* Start for Constant: '<S7>/Constant' */
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
  GRM_HIL_B.Gimbal_operational_flg =
    GRM_HIL_P.Gimbal_Status_Y0.Gimbal_operational_flg;
  GRM_HIL_B.Gimbal_Ramp_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_Ramp_flg;
  GRM_HIL_B.Gimbal_Limit_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_Limit_flg;
  GRM_HIL_B.Gimbal_StopSim_flg = GRM_HIL_P.Gimbal_Status_Y0.Gimbal_StopSim_flg;

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
  GRM_HIL_B.Gimbal_yaw_sns =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_yaw_sns;
  GRM_HIL_B.Gimbal_pitch_sns =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_pitch_sns;
  GRM_HIL_B.Gimbal_roll_sns =
    GRM_HIL_P.Gimbal_Pos_Encoder_Y0.Encoder_Resolved.Gimbal_roll_sns;
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

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(GRM_HIL_M)) {
    rtmSetFirstInitCond(GRM_HIL_M, 0);
  }
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S37>/Send_to_FTHWICC' */

  /* Terminate for S-Function (sldrtpo): '<S40>/Send_to_FTHWICC' */

  /* S-Function Block: <S40>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S37>/Send_to_FTHWICC' */
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

  rtmSetTFinal(GRM_HIL_M, -1);
  GRM_HIL_M->Timing.stepSize0 = 0.001;
  GRM_HIL_M->Timing.stepSize1 = 0.001;
  GRM_HIL_M->Timing.stepSize2 = 0.002;
  GRM_HIL_M->Timing.stepSize3 = 0.01;
  GRM_HIL_M->Timing.stepSize4 = 0.02;
  rtmSetFirstInitCond(GRM_HIL_M, 1);

  /* External mode info */
  GRM_HIL_M->Sizes.checksums[0] = (3149021053U);
  GRM_HIL_M->Sizes.checksums[1] = (2131411835U);
  GRM_HIL_M->Sizes.checksums[2] = (2724286297U);
  GRM_HIL_M->Sizes.checksums[3] = (1645203036U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[33];
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
    dtInfo.numDataTypes = 137;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_M->Sizes.numContStates = (33);/* Number of continuous states */
  GRM_HIL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (5); /* Number of sample times */
  GRM_HIL_M->Sizes.numBlocks = (528);  /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (174); /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (165);/* Sum of parameter "widths" */
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

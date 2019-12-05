/*
 * untitled.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Nov 27 12:02:27 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

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
  0.0001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/UDP_Protocol", 36864U, 256, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
  (untitled_M->Timing.TaskCounters.TID[2])++;
  if ((untitled_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.001s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[2] = 0;
  }

  untitled_M->Timing.sampleHits[2] = (untitled_M->Timing.TaskCounters.TID[2] ==
    0);
  (untitled_M->Timing.TaskCounters.TID[3])++;
  if ((untitled_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [0.01s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[3] = 0;
  }

  untitled_M->Timing.sampleHits[3] = (untitled_M->Timing.TaskCounters.TID[3] ==
    0);
}

/* Model output function */
void untitled_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_Receive_from_FTHWICC_o10;
  boolean_T rtb_Receive_from_FTHWICC_o11;
  uint16_T rtb_FixPtSum1;
  real_T Output_tmp;
  real_T tmp;
  real_T tmp_0;
  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (sldrtpi): '<Root>/Receive_from_FTHWICC' */
    /* S-Function Block: <Root>/Receive_from_FTHWICC */
    {
      uint8_T indata[66U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 66U,
        &untitled_P.Receive_from_FTHWICC_PacketID, (double*) indata, NULL);
      untitled_B.Receive_from_FTHWICC_o12 = 0;/* Missed Ticks value is always zero */
      rtb_Receive_from_FTHWICC_o11 = (status>>1) & 0x1;/* Data Error port */
      rtb_Receive_from_FTHWICC_o10 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;
        untitled_B.Receive_from_FTHWICC_o1 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o2 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o3 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o4 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o5 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o6 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o7 = *indp.p_real_T++;
        untitled_B.Receive_from_FTHWICC_o8 = *indp.p_uint16_T++;
        untitled_B.Receive_from_FTHWICC_o9 = *indp.p_real_T++;
      }
    }
  }

  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtpo): '<Root>/Send_to_FTHWICC' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Zero'
     *  Constant: '<Root>/Zero1'
     */
    /* S-Function Block: <Root>/Send_to_FTHWICC */
    untitled_B.Send_to_FTHWICC = 0;    /* Missed Ticks value is always zero */

    /* no code required */
  }

  /* Clock: '<S6>/Clock' incorporates:
   *  Clock: '<S5>/Clock'
   *  Clock: '<S7>/Clock'
   */
  Output_tmp = untitled_M->Timing.t[0];

  /* Step: '<S6>/Step' incorporates:
   *  Step: '<S5>/Step'
   *  Step: '<S7>/Step'
   */
  tmp_0 = untitled_M->Timing.t[0];
  if (tmp_0 < untitled_P.Ramp1_start) {
    tmp = untitled_P.Step_Y0;
  } else {
    tmp = untitled_P.Ramp1_slope;
  }

  /* End of Step: '<S6>/Step' */

  /* Sum: '<S6>/Output' incorporates:
   *  Clock: '<S6>/Clock'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Product: '<S6>/Product'
   *  Sum: '<S6>/Sum'
   */
  untitled_B.Output = (Output_tmp - untitled_P.Ramp1_start) * tmp +
    untitled_P.Ramp1_InitialOutput;
  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S3>/Gain' incorporates:
     *  Gain: '<Root>/Shaft2radPitch'
     */
    untitled_B.Gain = untitled_P.Shaft2radPitch_Gain *
      untitled_B.Receive_from_FTHWICC_o6 * untitled_P.Gain_Gain;
  }

  /* Step: '<S7>/Step' */
  if (tmp_0 < untitled_P.Ramp2_start) {
    tmp = untitled_P.Step_Y0_l;
  } else {
    tmp = untitled_P.Ramp2_slope;
  }

  /* Sum: '<S7>/Output' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Product: '<S7>/Product'
   *  Sum: '<S7>/Sum'
   */
  untitled_B.Output_k = (Output_tmp - untitled_P.Ramp2_start) * tmp +
    untitled_P.Ramp2_InitialOutput;
  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S4>/Gain' incorporates:
     *  Gain: '<Root>/Shaft2radYaw1'
     */
    untitled_B.Gain_d = untitled_P.Shaft2radYaw1_Gain *
      untitled_B.Receive_from_FTHWICC_o5 * untitled_P.Gain_Gain_b;
  }

  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* UnitDelay: '<S1>/Output' */
    untitled_B.Output_o = untitled_DW.Output_DSTATE;
  }

  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
  }

  /* Step: '<S5>/Step' */
  if (tmp_0 < untitled_P.Ramp_start) {
    tmp_0 = untitled_P.Step_Y0_a;
  } else {
    tmp_0 = untitled_P.Ramp_slope;
  }

  /* Sum: '<S5>/Output' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Product: '<S5>/Product'
   *  Sum: '<S5>/Sum'
   */
  untitled_B.Output_d = (Output_tmp - untitled_P.Ramp_start) * tmp_0 +
    untitled_P.Ramp_InitialOutput;
  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<Root>/Shaft2radRoll1'
     */
    untitled_B.Gain_o = untitled_P.Shaft2radRoll1_Gain *
      untitled_B.Receive_from_FTHWICC_o7 * untitled_P.Gain_Gain_j;
  }

  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Cast To Boolean' incorporates:
     *  Constant: '<Root>/Constant'
     */
    untitled_B.CastToBoolean = (untitled_P.Constant_Value != 0.0);

    /* Sum: '<S8>/FixPt Sum1' incorporates:
     *  Constant: '<S8>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)untitled_B.Output_o +
      untitled_P.FixPtConstant_Value);

    /* Switch: '<S9>/FixPt Switch' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if (rtb_FixPtSum1 > untitled_P.WrapToZero_Threshold) {
      untitled_B.FixPtSwitch = untitled_P.Constant_Value_b;
    } else {
      untitled_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S9>/FixPt Switch' */

    /* Logic: '<Root>/NOT' */
    untitled_B.NOT = !untitled_B.CastToBoolean;
  }

  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (sldrtsync): '<Root>/Real-Time Synchronization' */
    /* S-Function Block: <Root>/Real-Time Synchronization */
    {
    }
  }
}

/* Model update function */
void untitled_update(void)
{
  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for S-Function (sldrtpo): '<Root>/Send_to_FTHWICC' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Zero'
     *  Constant: '<Root>/Zero1'
     */

    /* S-Function Block: <Root>/Send_to_FTHWICC */
    {
      uint8_T outdata[52U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        boolean_T pktout = untitled_B.CastToBoolean;
        *outdp.p_boolean_T++ = pktout;
      }

      {
        boolean_T pktout = untitled_B.NOT;
        *outdp.p_boolean_T++ = pktout;
      }

      {
        real_T pktout = untitled_P.Constant_Value;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = untitled_P.Zero_Value;
        *outdp.p_real_T++ = pktout;
      }

      {
        uint16_T pktout = untitled_B.Output_o;
        *outdp.p_uint16_T++ = pktout;
      }

      {
        real_T pktout = untitled_B.Output_d;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = untitled_B.Output;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = untitled_B.Output_k;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = untitled_P.Zero1_Value;
        *outdp.p_real_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 52U,
                     &untitled_P.Send_to_FTHWICC_PacketID, (double*) outdata,
                     NULL);
    }

    /* Update for UnitDelay: '<S1>/Output' */
    untitled_DW.Output_DSTATE = untitled_B.FixPtSwitch;
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
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.t[0] = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++untitled_M->Timing.clockTick1)) {
      ++untitled_M->Timing.clockTickH1;
    }

    untitled_M->Timing.t[1] = untitled_M->Timing.clockTick1 *
      untitled_M->Timing.stepSize1 + untitled_M->Timing.clockTickH1 *
      untitled_M->Timing.stepSize1 * 4294967296.0;
  }

  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++untitled_M->Timing.clockTick2)) {
      ++untitled_M->Timing.clockTickH2;
    }

    untitled_M->Timing.t[2] = untitled_M->Timing.clockTick2 *
      untitled_M->Timing.stepSize2 + untitled_M->Timing.clockTickH2 *
      untitled_M->Timing.stepSize2 * 4294967296.0;
  }

  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++untitled_M->Timing.clockTick3)) {
      ++untitled_M->Timing.clockTickH3;
    }

    untitled_M->Timing.t[3] = untitled_M->Timing.clockTick3 *
      untitled_M->Timing.stepSize3 + untitled_M->Timing.clockTickH3 *
      untitled_M->Timing.stepSize3 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (sldrtpo): '<Root>/Send_to_FTHWICC' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Zero'
   *  Constant: '<Root>/Zero1'
   */

  /* S-Function Block: <Root>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  untitled_DW.Output_DSTATE = untitled_P.Output_InitialCondition;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<Root>/Send_to_FTHWICC' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Zero'
   *  Constant: '<Root>/Zero1'
   */

  /* S-Function Block: <Root>/Send_to_FTHWICC */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  untitled_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  untitled_update();
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
  untitled_initialize();
}

void MdlTerminate(void)
{
  untitled_terminate();
}

/* Registration function */
RT_MODEL_untitled_T *untitled(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = untitled_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    untitled_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    untitled_M->Timing.sampleTimes = (&untitled_M->Timing.sampleTimesArray[0]);
    untitled_M->Timing.offsetTimes = (&untitled_M->Timing.offsetTimesArray[0]);

    /* task periods */
    untitled_M->Timing.sampleTimes[0] = (0.0);
    untitled_M->Timing.sampleTimes[1] = (0.0001);
    untitled_M->Timing.sampleTimes[2] = (0.001);
    untitled_M->Timing.sampleTimes[3] = (0.01);

    /* task offsets */
    untitled_M->Timing.offsetTimes[0] = (0.0);
    untitled_M->Timing.offsetTimes[1] = (0.0);
    untitled_M->Timing.offsetTimes[2] = (0.0);
    untitled_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = untitled_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    mdlSampleHits[3] = 1;
    untitled_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.0001;
  untitled_M->Timing.stepSize1 = 0.0001;
  untitled_M->Timing.stepSize2 = 0.001;
  untitled_M->Timing.stepSize3 = 0.01;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1722486940U);
  untitled_M->Sizes.checksums[1] = (1529124782U);
  untitled_M->Sizes.checksums[2] = (1081057874U);
  untitled_M->Sizes.checksums[3] = (748924235U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);
  untitled_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&untitled_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&untitled_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  untitled_M->blockIO = ((void *) &untitled_B);
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* parameters */
  untitled_M->defaultParam = ((real_T *)&untitled_P);

  /* states (dwork) */
  untitled_M->dwork = ((void *) &untitled_DW);
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  untitled_M->Sizes.numContStates = (0);/* Number of continuous states */
  untitled_M->Sizes.numY = (0);        /* Number of model outputs */
  untitled_M->Sizes.numU = (0);        /* Number of model inputs */
  untitled_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  untitled_M->Sizes.numSampTimes = (4);/* Number of sample times */
  untitled_M->Sizes.numBlocks = (52);  /* Number of blocks */
  untitled_M->Sizes.numBlockIO = (21); /* Number of block outputs */
  untitled_M->Sizes.numBlockPrms = (33);/* Sum of parameter "widths" */
  return untitled_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

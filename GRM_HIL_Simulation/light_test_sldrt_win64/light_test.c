/*
 * light_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "light_test".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Nov 27 14:44:26 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "light_test.h"
#include "light_test_private.h"
#include "light_test_dt.h"

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
B_light_test_T light_test_B;

/* Block states (default storage) */
DW_light_test_T light_test_DW;

/* Real-time model */
RT_MODEL_light_test_T light_test_M_;
RT_MODEL_light_test_T *const light_test_M = &light_test_M_;
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
  (light_test_M->Timing.TaskCounters.TID[2])++;
  if ((light_test_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    light_test_M->Timing.TaskCounters.TID[2] = 0;
  }

  light_test_M->Timing.sampleHits[2] = (light_test_M->Timing.TaskCounters.TID[2]
    == 0);
}

/* Model output function */
void light_test_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_Receive_from_FTHWICC_o10;
  boolean_T rtb_Receive_from_FTHWICC_o11;
  uint16_T rtb_FixPtSum1;
  real_T CastToDouble1_tmp;
  real_T tmp;
  real_T tmp_0;
  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtpi): '<Root>/Receive_from_FTHWICC' */
    /* S-Function Block: <Root>/Receive_from_FTHWICC */
    {
      uint8_T indata[66U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 66U,
        &light_test_P.Receive_from_FTHWICC_PacketID, (double*) indata, NULL);
      light_test_B.Receive_from_FTHWICC_o12 = 0;/* Missed Ticks value is always zero */
      rtb_Receive_from_FTHWICC_o11 = (status>>1) & 0x1;/* Data Error port */
      rtb_Receive_from_FTHWICC_o10 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;
        light_test_B.Receive_from_FTHWICC_o1 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o2 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o3 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o4 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o5 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o6 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o7 = *indp.p_real_T++;
        light_test_B.Receive_from_FTHWICC_o8 = *indp.p_uint16_T++;
        light_test_B.Receive_from_FTHWICC_o9 = *indp.p_real_T++;
      }
    }

    /* S-Function (sldrtpo): '<Root>/Send_to_FTHWICC' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Zero'
     *  Constant: '<Root>/Zero1'
     */
    /* S-Function Block: <Root>/Send_to_FTHWICC */
    light_test_B.Send_to_FTHWICC = 0;  /* Missed Ticks value is always zero */

    /* no code required */
  }

  /* Clock: '<S6>/Clock' incorporates:
   *  Clock: '<S5>/Clock'
   *  Clock: '<S7>/Clock'
   */
  CastToDouble1_tmp = light_test_M->Timing.t[0];

  /* Step: '<S6>/Step' incorporates:
   *  Step: '<S5>/Step'
   *  Step: '<S7>/Step'
   */
  tmp_0 = light_test_M->Timing.t[0];
  if (tmp_0 < light_test_P.Ramp1_start) {
    tmp = light_test_P.Step_Y0;
  } else {
    tmp = light_test_P.Ramp1_slope;
  }

  /* End of Step: '<S6>/Step' */

  /* DataTypeConversion: '<Root>/Cast To Double1' incorporates:
   *  Clock: '<S6>/Clock'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Product: '<S6>/Product'
   *  Sum: '<S6>/Output'
   *  Sum: '<S6>/Sum'
   */
  light_test_B.CastToDouble1 = (CastToDouble1_tmp - light_test_P.Ramp1_start) *
    tmp + light_test_P.Ramp1_InitialOutput;
  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S3>/Gain' incorporates:
     *  Gain: '<Root>/Shaft2radPitch'
     */
    light_test_B.Gain = light_test_P.Shaft2radPitch_Gain *
      light_test_B.Receive_from_FTHWICC_o6 * light_test_P.Gain_Gain;
  }

  /* Step: '<S7>/Step' */
  if (tmp_0 < light_test_P.Ramp2_start) {
    tmp = light_test_P.Step_Y0_l;
  } else {
    tmp = light_test_P.Ramp2_slope;
  }

  /* DataTypeConversion: '<Root>/Cast To Double2' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Product: '<S7>/Product'
   *  Sum: '<S7>/Output'
   *  Sum: '<S7>/Sum'
   */
  light_test_B.CastToDouble2 = (CastToDouble1_tmp - light_test_P.Ramp2_start) *
    tmp + light_test_P.Ramp2_InitialOutput;
  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S4>/Gain' incorporates:
     *  Gain: '<Root>/Shaft2radYaw1'
     */
    light_test_B.Gain_d = light_test_P.Shaft2radYaw1_Gain *
      light_test_B.Receive_from_FTHWICC_o5 * light_test_P.Gain_Gain_b;
  }

  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* UnitDelay: '<S1>/Output' */
    light_test_B.Output = light_test_DW.Output_DSTATE;
  }

  /* Step: '<S5>/Step' */
  if (tmp_0 < light_test_P.Ramp_start) {
    tmp_0 = light_test_P.Step_Y0_a;
  } else {
    tmp_0 = light_test_P.Ramp_slope;
  }

  /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Product: '<S5>/Product'
   *  Sum: '<S5>/Output'
   *  Sum: '<S5>/Sum'
   */
  light_test_B.CastToDouble = (CastToDouble1_tmp - light_test_P.Ramp_start) *
    tmp_0 + light_test_P.Ramp_InitialOutput;
  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<Root>/Shaft2radRoll1'
     */
    light_test_B.Gain_o = light_test_P.Shaft2radRoll1_Gain *
      light_test_B.Receive_from_FTHWICC_o7 * light_test_P.Gain_Gain_j;
  }

  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Cast To Boolean' incorporates:
     *  Constant: '<Root>/Constant'
     */
    light_test_B.CastToBoolean = (light_test_P.Constant_Value != 0.0);

    /* Sum: '<S8>/FixPt Sum1' incorporates:
     *  Constant: '<S8>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)light_test_B.Output +
      light_test_P.FixPtConstant_Value);

    /* Switch: '<S9>/FixPt Switch' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if (rtb_FixPtSum1 > light_test_P.WrapToZero_Threshold) {
      light_test_B.FixPtSwitch = light_test_P.Constant_Value_b;
    } else {
      light_test_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S9>/FixPt Switch' */

    /* Logic: '<Root>/NOT' */
    light_test_B.NOT = !light_test_B.CastToBoolean;

    /* S-Function (sldrtsync): '<Root>/Real-Time Synchronization' */
    /* S-Function Block: <Root>/Real-Time Synchronization */
    {
      light_test_B.RealTimeSynchronization = 0;/* Missed Ticks value is always zero */
    }
  }
}

/* Model update function */
void light_test_update(void)
{
  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
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
        boolean_T pktout = light_test_B.CastToBoolean;
        *outdp.p_boolean_T++ = pktout;
      }

      {
        boolean_T pktout = light_test_B.NOT;
        *outdp.p_boolean_T++ = pktout;
      }

      {
        real_T pktout = light_test_P.Constant_Value;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = light_test_P.Zero_Value;
        *outdp.p_real_T++ = pktout;
      }

      {
        uint16_T pktout = light_test_B.Output;
        *outdp.p_uint16_T++ = pktout;
      }

      {
        real_T pktout = light_test_B.CastToDouble;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = light_test_B.CastToDouble1;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = light_test_B.CastToDouble2;
        *outdp.p_real_T++ = pktout;
      }

      {
        real_T pktout = light_test_P.Zero1_Value;
        *outdp.p_real_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 52U,
                     &light_test_P.Send_to_FTHWICC_PacketID, (double*) outdata,
                     NULL);
    }

    /* Update for UnitDelay: '<S1>/Output' */
    light_test_DW.Output_DSTATE = light_test_B.FixPtSwitch;
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
  if (!(++light_test_M->Timing.clockTick0)) {
    ++light_test_M->Timing.clockTickH0;
  }

  light_test_M->Timing.t[0] = light_test_M->Timing.clockTick0 *
    light_test_M->Timing.stepSize0 + light_test_M->Timing.clockTickH0 *
    light_test_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++light_test_M->Timing.clockTick1)) {
      ++light_test_M->Timing.clockTickH1;
    }

    light_test_M->Timing.t[1] = light_test_M->Timing.clockTick1 *
      light_test_M->Timing.stepSize1 + light_test_M->Timing.clockTickH1 *
      light_test_M->Timing.stepSize1 * 4294967296.0;
  }

  if (light_test_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++light_test_M->Timing.clockTick2)) {
      ++light_test_M->Timing.clockTickH2;
    }

    light_test_M->Timing.t[2] = light_test_M->Timing.clockTick2 *
      light_test_M->Timing.stepSize2 + light_test_M->Timing.clockTickH2 *
      light_test_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void light_test_initialize(void)
{
  /* Start for S-Function (sldrtpo): '<Root>/Send_to_FTHWICC' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Zero'
   *  Constant: '<Root>/Zero1'
   */

  /* S-Function Block: <Root>/Send_to_FTHWICC */
  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  light_test_DW.Output_DSTATE = light_test_P.Output_InitialCondition;
}

/* Model terminate function */
void light_test_terminate(void)
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
  light_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  light_test_update();
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
  light_test_initialize();
}

void MdlTerminate(void)
{
  light_test_terminate();
}

/* Registration function */
RT_MODEL_light_test_T *light_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)light_test_M, 0,
                sizeof(RT_MODEL_light_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&light_test_M->solverInfo,
                          &light_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&light_test_M->solverInfo, &rtmGetTPtr(light_test_M));
    rtsiSetStepSizePtr(&light_test_M->solverInfo,
                       &light_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&light_test_M->solverInfo, (&rtmGetErrorStatus
      (light_test_M)));
    rtsiSetRTModelPtr(&light_test_M->solverInfo, light_test_M);
  }

  rtsiSetSimTimeStep(&light_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&light_test_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = light_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    light_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    light_test_M->Timing.sampleTimes = (&light_test_M->Timing.sampleTimesArray[0]);
    light_test_M->Timing.offsetTimes = (&light_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    light_test_M->Timing.sampleTimes[0] = (0.0);
    light_test_M->Timing.sampleTimes[1] = (0.001);
    light_test_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    light_test_M->Timing.offsetTimes[0] = (0.0);
    light_test_M->Timing.offsetTimes[1] = (0.0);
    light_test_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(light_test_M, &light_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = light_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    light_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(light_test_M, -1);
  light_test_M->Timing.stepSize0 = 0.001;
  light_test_M->Timing.stepSize1 = 0.001;
  light_test_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  light_test_M->Sizes.checksums[0] = (1187337891U);
  light_test_M->Sizes.checksums[1] = (1598118462U);
  light_test_M->Sizes.checksums[2] = (1050237216U);
  light_test_M->Sizes.checksums[3] = (3807657381U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    light_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(light_test_M->extModeInfo,
      &light_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(light_test_M->extModeInfo, light_test_M->Sizes.checksums);
    rteiSetTPtr(light_test_M->extModeInfo, rtmGetTPtr(light_test_M));
  }

  light_test_M->solverInfoPtr = (&light_test_M->solverInfo);
  light_test_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&light_test_M->solverInfo, 0.001);
  rtsiSetSolverMode(&light_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  light_test_M->blockIO = ((void *) &light_test_B);
  (void) memset(((void *) &light_test_B), 0,
                sizeof(B_light_test_T));

  /* parameters */
  light_test_M->defaultParam = ((real_T *)&light_test_P);

  /* states (dwork) */
  light_test_M->dwork = ((void *) &light_test_DW);
  (void) memset((void *)&light_test_DW, 0,
                sizeof(DW_light_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    light_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  light_test_M->Sizes.numContStates = (0);/* Number of continuous states */
  light_test_M->Sizes.numY = (0);      /* Number of model outputs */
  light_test_M->Sizes.numU = (0);      /* Number of model inputs */
  light_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  light_test_M->Sizes.numSampTimes = (3);/* Number of sample times */
  light_test_M->Sizes.numBlocks = (56);/* Number of blocks */
  light_test_M->Sizes.numBlockIO = (22);/* Number of block outputs */
  light_test_M->Sizes.numBlockPrms = (33);/* Sum of parameter "widths" */
  return light_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

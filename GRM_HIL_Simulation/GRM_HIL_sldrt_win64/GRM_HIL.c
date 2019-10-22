/*
 * GRM_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.39
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Oct 17 20:07:41 2019
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

/* Block states (default storage) */
DW_GRM_HIL_T GRM_HIL_DW;

/* Real-time model */
RT_MODEL_GRM_HIL_T GRM_HIL_M_;
RT_MODEL_GRM_HIL_T *const GRM_HIL_M = &GRM_HIL_M_;

/* Model output function */
void GRM_HIL_output(void)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);

  /* Outputs for Enabled SubSystem: '<S1>/Synchronize_to_realtime' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Logic: '<S1>/Logical Operator2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant9'
   *  Logic: '<S1>/NOT'
   */
  if (GRM_HIL_P.Constant1_Value && (!GRM_HIL_P.Constant9_Value) &&
      GRM_HIL_P.Constant3_Value) {
    /* S-Function (sldrtsync): '<S2>/Real-Time Synchronization' */
    /* S-Function Block: <S2>/Real-Time Synchronization */
    {
    }

    srUpdateBC(GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC);
  }

  /* End of Logic: '<S1>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S1>/Synchronize_to_realtime' */
}

/* Model update function */
void GRM_HIL_update(void)
{
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

  GRM_HIL_M->Timing.t[0] = GRM_HIL_M->Timing.clockTick0 *
    GRM_HIL_M->Timing.stepSize0 + GRM_HIL_M->Timing.clockTickH0 *
    GRM_HIL_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void GRM_HIL_initialize(void)
{
}

/* Model terminate function */
void GRM_HIL_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
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

  /* Initialize timing info */
  {
    int_T *mdlTsMap = GRM_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    GRM_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GRM_HIL_M->Timing.sampleTimes = (&GRM_HIL_M->Timing.sampleTimesArray[0]);
    GRM_HIL_M->Timing.offsetTimes = (&GRM_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GRM_HIL_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    GRM_HIL_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(GRM_HIL_M, &GRM_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GRM_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    GRM_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GRM_HIL_M, -1);
  GRM_HIL_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  GRM_HIL_M->Sizes.checksums[0] = (4031674080U);
  GRM_HIL_M->Sizes.checksums[1] = (650090427U);
  GRM_HIL_M->Sizes.checksums[2] = (2887872186U);
  GRM_HIL_M->Sizes.checksums[3] = (1361016414U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    GRM_HIL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
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

  /* parameters */
  GRM_HIL_M->defaultParam = ((real_T *)&GRM_HIL_P);

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
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_M->Sizes.numContStates = (0);/* Number of continuous states */
  GRM_HIL_M->Sizes.numY = (0);         /* Number of model outputs */
  GRM_HIL_M->Sizes.numU = (0);         /* Number of model inputs */
  GRM_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_M->Sizes.numSampTimes = (1); /* Number of sample times */
  GRM_HIL_M->Sizes.numBlocks = (7);    /* Number of blocks */
  GRM_HIL_M->Sizes.numBlockIO = (1);   /* Number of block outputs */
  GRM_HIL_M->Sizes.numBlockPrms = (5); /* Sum of parameter "widths" */
  return GRM_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

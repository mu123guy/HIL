/*
 * UDPcomTest_Host.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UDPcomTest_Host".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Oct 29 22:11:33 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UDPcomTest_Host.h"
#include "UDPcomTest_Host_private.h"
#include "UDPcomTest_Host_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_UDPcomTest_Host_T UDPcomTest_Host_B;

/* Block states (default storage) */
DW_UDPcomTest_Host_T UDPcomTest_Host_DW;

/* Real-time model */
RT_MODEL_UDPcomTest_Host_T UDPcomTest_Host_M_;
RT_MODEL_UDPcomTest_Host_T *const UDPcomTest_Host_M = &UDPcomTest_Host_M_;

/* Model output function */
void UDPcomTest_Host_output(void)
{
  real_T tmp;

  /* S-Function (slrtIPConfig): '<Root>/UDP Configure' */

  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = UDPcomTest_Host_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* DataTypeConversion: '<Root>/Cast To Boolean' incorporates:
   *  Constant: '<Root>/Constant'
   */
  UDPcomTest_Host_B.CastToBoolean = (UDPcomTest_Host_P.Constant_Value != 0.0);

  /* DataTypeConversion: '<Root>/Cast To Boolean1' incorporates:
   *  Constant: '<Root>/Zero'
   */
  UDPcomTest_Host_B.CastToBoolean1 = (UDPcomTest_Host_P.Zero_Value != 0.0);

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(UDPcomTest_Host_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  UDPcomTest_Host_B.Cast = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<Root>/Cast' */

  /* SignalGenerator: '<Root>/Signal Generator' */
  UDPcomTest_Host_B.SignalGenerator = sin(6.2831853071795862 *
    UDPcomTest_Host_M->Timing.t[0] * UDPcomTest_Host_P.SignalGenerator_Frequency)
    * UDPcomTest_Host_P.SignalGenerator_Amplitude;

  /* S-Function (xpcbytepacking): '<Root>/Byte Packing ' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Zero'
   */

  /* Byte Packing: <Root>/Byte Packing  */
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 0, (uint8_T*)
               &UDPcomTest_Host_B.CastToBoolean, 1);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 1, (uint8_T*)
               &UDPcomTest_Host_B.CastToBoolean1, 1);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 2, (uint8_T*)
               &UDPcomTest_Host_P.Constant_Value, 8);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 10, (uint8_T*)
               &UDPcomTest_Host_P.Zero_Value, 8);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 18, (uint8_T*)
               &UDPcomTest_Host_B.Cast, 2);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 20, (uint8_T*)
               &UDPcomTest_Host_B.SignalGenerator, 8);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 28, (uint8_T*)
               &UDPcomTest_Host_P.Constant_Value, 8);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 36, (uint8_T*)
               &UDPcomTest_Host_P.Constant_Value, 8);
  (void)memcpy((uint8_T*)&UDPcomTest_Host_B.BytePacking[0] + 44, (uint8_T*)
               &UDPcomTest_Host_P.Constant_Value, 8);

  /* S-Function (slrtUDPSend): '<Root>/UDP Send2' */

  /* Level2 S-Function Block: '<Root>/UDP Send2' (slrtUDPSend) */
  {
    SimStruct *rts = UDPcomTest_Host_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* S-Function (sldrtsync): '<Root>/Real-Time Synchronization' */
  /* S-Function Block: <Root>/Real-Time Synchronization */
  {
  }
}

/* Model update function */
void UDPcomTest_Host_update(void)
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
  if (!(++UDPcomTest_Host_M->Timing.clockTick0)) {
    ++UDPcomTest_Host_M->Timing.clockTickH0;
  }

  UDPcomTest_Host_M->Timing.t[0] = UDPcomTest_Host_M->Timing.clockTick0 *
    UDPcomTest_Host_M->Timing.stepSize0 + UDPcomTest_Host_M->Timing.clockTickH0 *
    UDPcomTest_Host_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++UDPcomTest_Host_M->Timing.clockTick1)) {
      ++UDPcomTest_Host_M->Timing.clockTickH1;
    }

    UDPcomTest_Host_M->Timing.t[1] = UDPcomTest_Host_M->Timing.clockTick1 *
      UDPcomTest_Host_M->Timing.stepSize1 +
      UDPcomTest_Host_M->Timing.clockTickH1 *
      UDPcomTest_Host_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void UDPcomTest_Host_initialize(void)
{
  /* Start for S-Function (slrtIPConfig): '<Root>/UDP Configure' */
  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = UDPcomTest_Host_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (slrtUDPSend): '<Root>/UDP Send2' */
  /* Level2 S-Function Block: '<Root>/UDP Send2' (slrtUDPSend) */
  {
    SimStruct *rts = UDPcomTest_Host_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void UDPcomTest_Host_terminate(void)
{
  /* Terminate for S-Function (slrtIPConfig): '<Root>/UDP Configure' */
  /* Level2 S-Function Block: '<Root>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = UDPcomTest_Host_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPSend): '<Root>/UDP Send2' */
  /* Level2 S-Function Block: '<Root>/UDP Send2' (slrtUDPSend) */
  {
    SimStruct *rts = UDPcomTest_Host_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  UDPcomTest_Host_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  UDPcomTest_Host_update();
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
  UDPcomTest_Host_initialize();
}

void MdlTerminate(void)
{
  UDPcomTest_Host_terminate();
}

/* Registration function */
RT_MODEL_UDPcomTest_Host_T *UDPcomTest_Host(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)UDPcomTest_Host_M, 0,
                sizeof(RT_MODEL_UDPcomTest_Host_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&UDPcomTest_Host_M->solverInfo,
                          &UDPcomTest_Host_M->Timing.simTimeStep);
    rtsiSetTPtr(&UDPcomTest_Host_M->solverInfo, &rtmGetTPtr(UDPcomTest_Host_M));
    rtsiSetStepSizePtr(&UDPcomTest_Host_M->solverInfo,
                       &UDPcomTest_Host_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&UDPcomTest_Host_M->solverInfo, (&rtmGetErrorStatus
      (UDPcomTest_Host_M)));
    rtsiSetRTModelPtr(&UDPcomTest_Host_M->solverInfo, UDPcomTest_Host_M);
  }

  rtsiSetSimTimeStep(&UDPcomTest_Host_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&UDPcomTest_Host_M->solverInfo,"FixedStepDiscrete");
  UDPcomTest_Host_M->solverInfoPtr = (&UDPcomTest_Host_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = UDPcomTest_Host_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    UDPcomTest_Host_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    UDPcomTest_Host_M->Timing.sampleTimes =
      (&UDPcomTest_Host_M->Timing.sampleTimesArray[0]);
    UDPcomTest_Host_M->Timing.offsetTimes =
      (&UDPcomTest_Host_M->Timing.offsetTimesArray[0]);

    /* task periods */
    UDPcomTest_Host_M->Timing.sampleTimes[0] = (0.0);
    UDPcomTest_Host_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    UDPcomTest_Host_M->Timing.offsetTimes[0] = (0.0);
    UDPcomTest_Host_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(UDPcomTest_Host_M, &UDPcomTest_Host_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = UDPcomTest_Host_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    UDPcomTest_Host_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(UDPcomTest_Host_M, -1);
  UDPcomTest_Host_M->Timing.stepSize0 = 0.01;
  UDPcomTest_Host_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  UDPcomTest_Host_M->Sizes.checksums[0] = (459204029U);
  UDPcomTest_Host_M->Sizes.checksums[1] = (1669563769U);
  UDPcomTest_Host_M->Sizes.checksums[2] = (351877745U);
  UDPcomTest_Host_M->Sizes.checksums[3] = (3211230390U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    UDPcomTest_Host_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(UDPcomTest_Host_M->extModeInfo,
      &UDPcomTest_Host_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(UDPcomTest_Host_M->extModeInfo,
                        UDPcomTest_Host_M->Sizes.checksums);
    rteiSetTPtr(UDPcomTest_Host_M->extModeInfo, rtmGetTPtr(UDPcomTest_Host_M));
  }

  UDPcomTest_Host_M->solverInfoPtr = (&UDPcomTest_Host_M->solverInfo);
  UDPcomTest_Host_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&UDPcomTest_Host_M->solverInfo, 0.01);
  rtsiSetSolverMode(&UDPcomTest_Host_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  UDPcomTest_Host_M->blockIO = ((void *) &UDPcomTest_Host_B);
  (void) memset(((void *) &UDPcomTest_Host_B), 0,
                sizeof(B_UDPcomTest_Host_T));

  /* parameters */
  UDPcomTest_Host_M->defaultParam = ((real_T *)&UDPcomTest_Host_P);

  /* states (dwork) */
  UDPcomTest_Host_M->dwork = ((void *) &UDPcomTest_Host_DW);
  (void) memset((void *)&UDPcomTest_Host_DW, 0,
                sizeof(DW_UDPcomTest_Host_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    UDPcomTest_Host_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &UDPcomTest_Host_M->NonInlinedSFcns.sfcnInfo;
    UDPcomTest_Host_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(UDPcomTest_Host_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &UDPcomTest_Host_M->Sizes.numSampTimes);
    UDPcomTest_Host_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (UDPcomTest_Host_M)[0]);
    UDPcomTest_Host_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (UDPcomTest_Host_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,UDPcomTest_Host_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(UDPcomTest_Host_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(UDPcomTest_Host_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (UDPcomTest_Host_M));
    rtssSetStepSizePtr(sfcnInfo, &UDPcomTest_Host_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(UDPcomTest_Host_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &UDPcomTest_Host_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &UDPcomTest_Host_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &UDPcomTest_Host_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &UDPcomTest_Host_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &UDPcomTest_Host_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &UDPcomTest_Host_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &UDPcomTest_Host_M->solverInfoPtr);
  }

  UDPcomTest_Host_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&UDPcomTest_Host_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    UDPcomTest_Host_M->childSfunctions =
      (&UDPcomTest_Host_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    UDPcomTest_Host_M->childSfunctions[0] =
      (&UDPcomTest_Host_M->NonInlinedSFcns.childSFunctions[0]);
    UDPcomTest_Host_M->childSfunctions[1] =
      (&UDPcomTest_Host_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: UDPcomTest_Host/<Root>/UDP Configure (slrtIPConfig) */
    {
      SimStruct *rts = UDPcomTest_Host_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = UDPcomTest_Host_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = UDPcomTest_Host_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = UDPcomTest_Host_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &UDPcomTest_Host_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &UDPcomTest_Host_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, UDPcomTest_Host_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &UDPcomTest_Host_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &UDPcomTest_Host_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &UDPcomTest_Host_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &UDPcomTest_Host_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &UDPcomTest_Host_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "UDP Configure");
      ssSetPath(rts, "UDPcomTest_Host/UDP Configure");
      ssSetRTModel(rts,UDPcomTest_Host_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)UDPcomTest_Host_P.UDPConfigure_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       UDPcomTest_Host_P.UDPConfigure_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       UDPcomTest_Host_P.UDPConfigure_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &UDPcomTest_Host_DW.UDPConfigure_IWORK[0]);
      ssSetPWork(rts, (void **) &UDPcomTest_Host_DW.UDPConfigure_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &UDPcomTest_Host_DW.UDPConfigure_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &UDPcomTest_Host_DW.UDPConfigure_PWORK[0]);
      }

      /* registration */
      slrtIPConfig(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: UDPcomTest_Host/<Root>/UDP Send2 (slrtUDPSend) */
    {
      SimStruct *rts = UDPcomTest_Host_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &UDPcomTest_Host_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &UDPcomTest_Host_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, UDPcomTest_Host_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &UDPcomTest_Host_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &UDPcomTest_Host_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &UDPcomTest_Host_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &UDPcomTest_Host_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &UDPcomTest_Host_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, UDPcomTest_Host_B.BytePacking);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 52);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, (real_T*)&UDPcomTest_Host_ConstB.Width);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Send2");
      ssSetPath(rts, "UDPcomTest_Host/UDP Send2");
      ssSetRTModel(rts,UDPcomTest_Host_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)UDPcomTest_Host_P.UDPSend2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)UDPcomTest_Host_P.UDPSend2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)UDPcomTest_Host_P.UDPSend2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)UDPcomTest_Host_P.UDPSend2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)UDPcomTest_Host_P.UDPSend2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)UDPcomTest_Host_P.UDPSend2_P6_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &UDPcomTest_Host_DW.UDPSend2_IWORK[0]);
      ssSetPWork(rts, (void **) &UDPcomTest_Host_DW.UDPSend2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &UDPcomTest_Host_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &UDPcomTest_Host_DW.UDPSend2_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &UDPcomTest_Host_DW.UDPSend2_PWORK);
      }

      /* registration */
      slrtUDPSend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 52);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  UDPcomTest_Host_M->Sizes.numContStates = (0);/* Number of continuous states */
  UDPcomTest_Host_M->Sizes.numY = (0); /* Number of model outputs */
  UDPcomTest_Host_M->Sizes.numU = (0); /* Number of model inputs */
  UDPcomTest_Host_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  UDPcomTest_Host_M->Sizes.numSampTimes = (2);/* Number of sample times */
  UDPcomTest_Host_M->Sizes.numBlocks = (12);/* Number of blocks */
  UDPcomTest_Host_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  UDPcomTest_Host_M->Sizes.numBlockPrms = (103);/* Sum of parameter "widths" */
  return UDPcomTest_Host_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

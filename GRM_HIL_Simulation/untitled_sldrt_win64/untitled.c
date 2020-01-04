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
 * C source code generated on : Mon Dec 30 20:31:29 2019
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
  { "Standard_Devices/Serial_Port", 11U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_nullAssignment(real_T x_data[], int32_T x_size[2], const
  boolean_T idx_data[], const int32_T idx_size[2]);

/* Function for MATLAB Function: '<Root>/ExtractMessage' */
static void untitled_nullAssignment(real_T x_data[], int32_T x_size[2], const
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

/* Model output function */
void untitled_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_PacketInput_o2;
  boolean_T rtb_PacketInput_o3;
  real_T start_data[78];
  boolean_T p;
  int32_T idx;
  uint16_T PixHeartbeat;
  real32_T ServoCMD1;
  uint8_T x[2];
  uint8_T b_x[4];
  boolean_T start_data_0[78];
  int32_T loop_ub;
  int32_T start_size[2];
  int32_T tmp_size[2];
  int32_T start_size_0[2];
  real_T tmp;
  boolean_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(untitled_DW.hold_SubsysRanBC);

  /* S-Function (sldrtpi): '<Root>/Packet Input' */
  /* S-Function Block: <Root>/Packet Input */
  {
    uint8_T indata[78U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 78U,
      &untitled_P.PacketInput_PacketID, (double*) indata, NULL);
    rtb_PacketInput_o3 = (status>>1) & 0x1;/* Data Error port */
    rtb_PacketInput_o2 = status & 0x1; /* Data Ready port */
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;

      {
        int_T i1;
        uint8_T *y0 = &untitled_B.PacketInput_o1[0];
        for (i1=0; i1 < 78; i1++) {
          y0[i1] = *indp.p_uint8_T++;
        }
      }
    }
  }

  /* Logic: '<Root>/AND' incorporates:
   *  Logic: '<Root>/NOT'
   */
  untitled_B.AND = (rtb_PacketInput_o2 && (!rtb_PacketInput_o3));

  /* Outport: '<Root>/Status' */
  untitled_Y.Status = untitled_B.AND;

  /* ToAsyncQueueBlock generated from: '<Root>/AND' */
  {
    {
      double time = untitled_M->Timing.t[0];
      void *pData = (void *)&untitled_B.AND;
      int32_T size = 1*sizeof(boolean_T);
      sendToAsyncQueueTgtAppSvc(1090703980U, time, pData, size);
    }
  }

  /* MATLAB Function: '<Root>/ExtractMessage' incorporates:
   *  SignalConversion generated from: '<S2>/ SFunction '
   */
  untitled_DW.SFunction_DIMS2[1] = 64;
  untitled_B.packetfound = false;
  start_size[0] = 1;
  start_size[1] = 0;
  start_size_0[0] = 1;
  start_size_0[1] = 0;
  untitled_nullAssignment(start_data, start_size, start_data_0, start_size_0);
  tmp_size[0] = 1;
  tmp_size[1] = start_size[1];
  loop_ub = start_size[0] * start_size[1];
  for (idx = 0; idx < loop_ub; idx++) {
    start_data_0[idx] = true;
  }

  untitled_nullAssignment(start_data, start_size, start_data_0, tmp_size);
  if (start_size[1] != 0) {
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= start_size[1] - 2)) {
      p = false;
      tmp = start_data[loop_ub + 1];
      if (tmp - start_data[loop_ub] == 66.0) {
        p = true;
      }

      if (p) {
        if (start_data[loop_ub] + 2.0 > tmp - 1.0) {
          idx = -1;
          loop_ub = -2;
        } else {
          idx = (int32_T)(start_data[loop_ub] + 2.0) - 2;
          loop_ub = (int32_T)(start_data[loop_ub + 1] - 1.0) - 2;
        }

        untitled_DW.SFunction_DIMS2[1] = (loop_ub - idx) + 1;
        untitled_B.packetfound = true;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }

  untitled_DW.SFunction_DIMS2[0] = 1;

  /* End of MATLAB Function: '<Root>/ExtractMessage' */
  /* MATLAB Function: '<Root>/ByteUnpack' */
  x[0] = 0U;
  x[1] = 0U;
  memcpy((void *)&PixHeartbeat, (void *)&x[0], (uint32_T)((size_t)1 * sizeof
          (uint16_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = 0U;
  b_x[1] = 0U;
  b_x[2] = 0U;
  b_x[3] = 0U;
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));

  /* Outputs for Enabled SubSystem: '<Root>/hold' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (untitled_B.packetfound) {
    srUpdateBC(untitled_DW.hold_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/hold' */
}

/* Model update function */
void untitled_update(void)
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
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.t[0] = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void untitled_initialize(void)
{
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
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

  /* Initialize timing info */
  {
    int_T *mdlTsMap = untitled_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    untitled_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    untitled_M->Timing.sampleTimes = (&untitled_M->Timing.sampleTimesArray[0]);
    untitled_M->Timing.offsetTimes = (&untitled_M->Timing.offsetTimesArray[0]);

    /* task periods */
    untitled_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    untitled_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = untitled_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    untitled_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1700691872U);
  untitled_M->Sizes.checksums[1] = (3920744144U);
  untitled_M->Sizes.checksums[2] = (1044725010U);
  untitled_M->Sizes.checksums[3] = (2977772078U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&untitled_DW.hold_SubsysRanBC;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);
  untitled_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&untitled_M->solverInfo, 0.001);
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

  /* external outputs */
  untitled_M->outputs = (&untitled_Y);
  untitled_Y.Status = false;

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
  untitled_M->Sizes.numY = (1);        /* Number of model outputs */
  untitled_M->Sizes.numU = (0);        /* Number of model inputs */
  untitled_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  untitled_M->Sizes.numSampTimes = (1);/* Number of sample times */
  untitled_M->Sizes.numBlocks = (20);  /* Number of blocks */
  untitled_M->Sizes.numBlockIO = (3);  /* Number of block outputs */
  untitled_M->Sizes.numBlockPrms = (11);/* Sum of parameter "widths" */
  return untitled_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

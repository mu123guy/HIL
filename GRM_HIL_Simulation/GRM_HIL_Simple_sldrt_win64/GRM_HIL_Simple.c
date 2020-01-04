/*
 * GRM_HIL_Simple.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL_Simple".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Dec 30 21:11:00 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GRM_HIL_Simple.h"
#include "GRM_HIL_Simple_private.h"
#include "GRM_HIL_Simple_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  1.0,
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
B_GRM_HIL_Simple_T GRM_HIL_Simple_B;

/* Block states (default storage) */
DW_GRM_HIL_Simple_T GRM_HIL_Simple_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_GRM_HIL_Simple_T GRM_HIL_Simple_Y;

/* Real-time model */
RT_MODEL_GRM_HIL_Simple_T GRM_HIL_Simple_M_;
RT_MODEL_GRM_HIL_Simple_T *const GRM_HIL_Simple_M = &GRM_HIL_Simple_M_;

/* Forward declaration for local functions */
static void GRM_HIL_Simple_nullAssignment(real_T x_data[], int32_T x_size[2],
  const boolean_T idx_data[], const int32_T idx_size[2]);

/* Function for MATLAB Function: '<Root>/ExtractMessage' */
static void GRM_HIL_Simple_nullAssignment(real_T x_data[], int32_T x_size[2],
  const boolean_T idx_data[], const int32_T idx_size[2])
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
void GRM_HIL_Simple_output(void)
{
  uint8_T packet_data[77];
  real_T start_data[78];
  boolean_T x[78];
  int8_T ii_data[78];
  boolean_T p;
  int32_T idx;
  int32_T b_ii;
  uint16_T PixHeartbeat;
  real32_T ServoCMD1;
  uint8_T x_0[2];
  uint8_T b_x[4];
  uint8_T rtb_message[64];
  int32_T loop_ub;
  int32_T start_size[2];
  int32_T tmp_size[2];
  int32_T start_size_0[2];
  real_T tmp;
  int32_T packet_size_idx_1_tmp;
  boolean_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(GRM_HIL_Simple_DW.hold_SubsysRanBC);

  /* S-Function (sldrtpi): '<Root>/Packet Input' */
  /* S-Function Block: <Root>/Packet Input */
  {
    uint8_T indata[78U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 78U,
      &GRM_HIL_Simple_P.PacketInput_PacketID, (double*) indata, NULL);
    GRM_HIL_Simple_B.PacketInput_o3 = (status>>1) & 0x1;/* Data Error port */
    GRM_HIL_Simple_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;

      {
        int_T i1;
        uint8_T *y0 = &GRM_HIL_Simple_B.PacketInput_o1[0];
        for (i1=0; i1 < 78; i1++) {
          y0[i1] = *indp.p_uint8_T++;
        }
      }
    }
  }

  /* Logic: '<Root>/AND' incorporates:
   *  Logic: '<Root>/NOT'
   */
  GRM_HIL_Simple_B.AND = (GRM_HIL_Simple_B.PacketInput_o2 &&
    (!GRM_HIL_Simple_B.PacketInput_o3));

  /* Outport: '<Root>/Status' */
  GRM_HIL_Simple_Y.Status = GRM_HIL_Simple_B.AND;

  /* MATLAB Function: '<Root>/ExtractMessage' */
  packet_size_idx_1_tmp = 64;
  memset(&packet_data[0], 0, sizeof(uint8_T) << 6U);
  GRM_HIL_Simple_B.packetfound = false;
  for (b_ii = 0; b_ii < 78; b_ii++) {
    x[b_ii] = (GRM_HIL_Simple_B.PacketInput_o1[b_ii] == 5);
  }

  idx = 0;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 78)) {
    if (x[b_ii]) {
      idx++;
      ii_data[idx - 1] = (int8_T)(b_ii + 1);
      if (idx >= 78) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  start_size[0] = 1;
  start_size[1] = idx;
  loop_ub = idx - 1;
  for (b_ii = 0; b_ii <= loop_ub; b_ii++) {
    start_data[b_ii] = ii_data[b_ii];
  }

  start_size_0[0] = 1;
  start_size_0[1] = idx;
  for (b_ii = 0; b_ii < idx; b_ii++) {
    x[b_ii] = ((start_data[b_ii] + 2.0) - 1.0 > 78.0);
  }

  GRM_HIL_Simple_nullAssignment(start_data, start_size, x, start_size_0);
  tmp_size[0] = 1;
  tmp_size[1] = start_size[1];
  loop_ub = start_size[0] * start_size[1];
  for (b_ii = 0; b_ii < loop_ub; b_ii++) {
    x[b_ii] = (GRM_HIL_Simple_B.PacketInput_o1[(int32_T)((start_data[b_ii] + 2.0)
                - 1.0) - 1] != 5);
  }

  GRM_HIL_Simple_nullAssignment(start_data, start_size, x, tmp_size);
  if (start_size[1] != 0) {
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= start_size[1] - 2)) {
      p = false;
      tmp = start_data[b_ii + 1];
      if (tmp - start_data[b_ii] == 66.0) {
        p = true;
      }

      if (p) {
        if (start_data[b_ii] + 2.0 > tmp - 1.0) {
          idx = 0;
          b_ii = 0;
        } else {
          idx = (int32_T)(start_data[b_ii] + 2.0) - 1;
          b_ii = (int32_T)(start_data[b_ii + 1] - 1.0);
        }

        packet_size_idx_1_tmp = b_ii - idx;
        for (b_ii = 0; b_ii < packet_size_idx_1_tmp; b_ii++) {
          packet_data[b_ii] = GRM_HIL_Simple_B.PacketInput_o1[idx + b_ii];
        }

        GRM_HIL_Simple_B.packetfound = true;
        exitg1 = true;
      } else {
        b_ii++;
      }
    }
  }

  GRM_HIL_Simple_DW.SFunction_DIMS2[0] = 1;
  GRM_HIL_Simple_DW.SFunction_DIMS2[1] = packet_size_idx_1_tmp;
  if (0 <= packet_size_idx_1_tmp - 1) {
    memcpy(&rtb_message[0], &packet_data[0], packet_size_idx_1_tmp * sizeof
           (uint8_T));
  }

  /* End of MATLAB Function: '<Root>/ExtractMessage' */
  /* ToAsyncQueueBlock generated from: '<Root>/AND' */
  {
    {
      double time = GRM_HIL_Simple_M->Timing.t[0];
      void *pData = (void *)&GRM_HIL_Simple_B.AND;
      int32_T size = 1*sizeof(boolean_T);
      sendToAsyncQueueTgtAppSvc(966686786U, time, pData, size);
    }
  }

  /* MATLAB Function: '<Root>/ByteUnpack' */
  x_0[0] = rtb_message[0];
  x_0[1] = rtb_message[1];
  memcpy((void *)&PixHeartbeat, (void *)&x_0[0], (uint32_T)((size_t)1 * sizeof
          (uint16_T)));
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
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[12];
  b_x[1] = rtb_message[13];
  b_x[2] = rtb_message[14];
  b_x[3] = rtb_message[15];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[16];
  b_x[1] = rtb_message[17];
  b_x[2] = rtb_message[18];
  b_x[3] = rtb_message[19];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[20];
  b_x[1] = rtb_message[21];
  b_x[2] = rtb_message[22];
  b_x[3] = rtb_message[23];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[24];
  b_x[1] = rtb_message[25];
  b_x[2] = rtb_message[26];
  b_x[3] = rtb_message[27];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[28];
  b_x[1] = rtb_message[29];
  b_x[2] = rtb_message[30];
  b_x[3] = rtb_message[31];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[32];
  b_x[1] = rtb_message[33];
  b_x[2] = rtb_message[34];
  b_x[3] = rtb_message[35];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[36];
  b_x[1] = rtb_message[37];
  b_x[2] = rtb_message[38];
  b_x[3] = rtb_message[39];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[40];
  b_x[1] = rtb_message[41];
  b_x[2] = rtb_message[42];
  b_x[3] = rtb_message[43];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[44];
  b_x[1] = rtb_message[45];
  b_x[2] = rtb_message[46];
  b_x[3] = rtb_message[47];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[48];
  b_x[1] = rtb_message[49];
  b_x[2] = rtb_message[50];
  b_x[3] = rtb_message[51];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[52];
  b_x[1] = rtb_message[53];
  b_x[2] = rtb_message[54];
  b_x[3] = rtb_message[55];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[56];
  b_x[1] = rtb_message[57];
  b_x[2] = rtb_message[58];
  b_x[3] = rtb_message[59];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));
  b_x[0] = rtb_message[60];
  b_x[1] = rtb_message[61];
  b_x[2] = rtb_message[62];
  b_x[3] = rtb_message[63];
  memcpy((void *)&ServoCMD1, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
          (real32_T)));

  /* Outputs for Enabled SubSystem: '<Root>/hold' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (GRM_HIL_Simple_B.packetfound) {
    srUpdateBC(GRM_HIL_Simple_DW.hold_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/hold' */
}

/* Model update function */
void GRM_HIL_Simple_update(void)
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
  if (!(++GRM_HIL_Simple_M->Timing.clockTick0)) {
    ++GRM_HIL_Simple_M->Timing.clockTickH0;
  }

  GRM_HIL_Simple_M->Timing.t[0] = GRM_HIL_Simple_M->Timing.clockTick0 *
    GRM_HIL_Simple_M->Timing.stepSize0 + GRM_HIL_Simple_M->Timing.clockTickH0 *
    GRM_HIL_Simple_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void GRM_HIL_Simple_initialize(void)
{
}

/* Model terminate function */
void GRM_HIL_Simple_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  GRM_HIL_Simple_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  GRM_HIL_Simple_update();
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
  GRM_HIL_Simple_initialize();
}

void MdlTerminate(void)
{
  GRM_HIL_Simple_terminate();
}

/* Registration function */
RT_MODEL_GRM_HIL_Simple_T *GRM_HIL_Simple(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)GRM_HIL_Simple_M, 0,
                sizeof(RT_MODEL_GRM_HIL_Simple_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = GRM_HIL_Simple_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    GRM_HIL_Simple_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GRM_HIL_Simple_M->Timing.sampleTimes =
      (&GRM_HIL_Simple_M->Timing.sampleTimesArray[0]);
    GRM_HIL_Simple_M->Timing.offsetTimes =
      (&GRM_HIL_Simple_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GRM_HIL_Simple_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    GRM_HIL_Simple_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(GRM_HIL_Simple_M, &GRM_HIL_Simple_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GRM_HIL_Simple_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    GRM_HIL_Simple_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GRM_HIL_Simple_M, 10.0);
  GRM_HIL_Simple_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  GRM_HIL_Simple_M->Sizes.checksums[0] = (1896975005U);
  GRM_HIL_Simple_M->Sizes.checksums[1] = (3232359973U);
  GRM_HIL_Simple_M->Sizes.checksums[2] = (726661743U);
  GRM_HIL_Simple_M->Sizes.checksums[3] = (4000478750U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    GRM_HIL_Simple_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&GRM_HIL_Simple_DW.hold_SubsysRanBC;
    rteiSetModelMappingInfoPtr(GRM_HIL_Simple_M->extModeInfo,
      &GRM_HIL_Simple_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GRM_HIL_Simple_M->extModeInfo,
                        GRM_HIL_Simple_M->Sizes.checksums);
    rteiSetTPtr(GRM_HIL_Simple_M->extModeInfo, rtmGetTPtr(GRM_HIL_Simple_M));
  }

  GRM_HIL_Simple_M->solverInfoPtr = (&GRM_HIL_Simple_M->solverInfo);
  GRM_HIL_Simple_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&GRM_HIL_Simple_M->solverInfo, 0.001);
  rtsiSetSolverMode(&GRM_HIL_Simple_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  GRM_HIL_Simple_M->blockIO = ((void *) &GRM_HIL_Simple_B);
  (void) memset(((void *) &GRM_HIL_Simple_B), 0,
                sizeof(B_GRM_HIL_Simple_T));

  /* parameters */
  GRM_HIL_Simple_M->defaultParam = ((real_T *)&GRM_HIL_Simple_P);

  /* states (dwork) */
  GRM_HIL_Simple_M->dwork = ((void *) &GRM_HIL_Simple_DW);
  (void) memset((void *)&GRM_HIL_Simple_DW, 0,
                sizeof(DW_GRM_HIL_Simple_T));

  /* external outputs */
  GRM_HIL_Simple_M->outputs = (&GRM_HIL_Simple_Y);
  GRM_HIL_Simple_Y.Status = false;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GRM_HIL_Simple_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  GRM_HIL_Simple_M->Sizes.numContStates = (0);/* Number of continuous states */
  GRM_HIL_Simple_M->Sizes.numY = (1);  /* Number of model outputs */
  GRM_HIL_Simple_M->Sizes.numU = (0);  /* Number of model inputs */
  GRM_HIL_Simple_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GRM_HIL_Simple_M->Sizes.numSampTimes = (1);/* Number of sample times */
  GRM_HIL_Simple_M->Sizes.numBlocks = (20);/* Number of blocks */
  GRM_HIL_Simple_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  GRM_HIL_Simple_M->Sizes.numBlockPrms = (11);/* Sum of parameter "widths" */
  return GRM_HIL_Simple_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

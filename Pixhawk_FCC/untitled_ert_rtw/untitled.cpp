//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled.cpp
//
// Code generated for Simulink model 'untitled'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Jan  1 16:31:42 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

// Block signals (default storage)
B_untitled_T untitled_B;

// Block states (default storage)
DW_untitled_T untitled_DW;

// Real-time model
RT_MODEL_untitled_T untitled_M_ = RT_MODEL_untitled_T();
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

// Forward declaration for local functions
static void untitled_SystemCore_release_b(const px4_internal_block_PX4SCIWrit_T *
  obj);
static void untitled_SystemCore_delete_b(const px4_internal_block_PX4SCIWrit_T
  *obj);
static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PX4SCIWrit_T *obj);
static void untitled_SystemCore_release(const px4_internal_block_PX4SCIRead_T
  *obj);
static void untitled_SystemCore_delete(const px4_internal_block_PX4SCIRead_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIRead_T *obj);
static void untitled_SystemCore_setup_b(px4_internal_block_PX4SCIWrit_T *obj);
static void untitled_SystemCore_setup(px4_internal_block_PX4SCIRead_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(untitled_M, 1));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (untitled_M->Timing.TaskCounters.TID[1])++;
  if ((untitled_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [0.1s, 0.0s] 
    untitled_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void untitled_SystemCore_release_b(const px4_internal_block_PX4SCIWrit_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void untitled_SystemCore_delete_b(const px4_internal_block_PX4SCIWrit_T
  *obj)
{
  untitled_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PX4SCIWrit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete_b(obj);
  }
}

static void untitled_SystemCore_release(const px4_internal_block_PX4SCIRead_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void untitled_SystemCore_delete(const px4_internal_block_PX4SCIRead_T
  *obj)
{
  untitled_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIRead_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete(obj);
  }
}

static void untitled_SystemCore_setup_b(px4_internal_block_PX4SCIWrit_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  char_T SCIModuleLoc[11];
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '6' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 10; i++) {
    SCIModuleLoc[i] = tmp[i];
  }

  SCIModuleLoc[10] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleLoc, true, RxPinLoc, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void untitled_SystemCore_setup(px4_internal_block_PX4SCIRead_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  char_T SCIModuleLoc[11];
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_HardwareFlowControl_Type HardwareFlowControlValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '6' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 10; i++) {
    SCIModuleLoc[i] = tmp[i];
  }

  SCIModuleLoc[10] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleLoc, true, RxPinLoc, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  HardwareFlowControlValue = MW_SCI_FLOWCONTROL_RTS_CTS;
  MW_SCI_ConfigureHardwareFlowControl(obj->MW_SCIHANDLE,
    HardwareFlowControlValue, RxPinLoc, TxPinLoc);
  obj->isSetupComplete = true;
}

// Model step function for TID0
void untitled_step0(void)              // Sample time: [0.01s, 0.0s]
{
  {                                    // Sample time: [0.01s, 0.0s]
    rate_monotonic_scheduler();
  }

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.01s, 0.0s]
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
}

// Model step function for TID1
void untitled_step1(void)              // Sample time: [0.1s, 0.0s]
{
  uint8_T TxDataLocChar[18];
  uint8_T sizeptr;
  int32_T i;

  // MATLABSystem: '<Root>/Serial Transmit' incorporates:
  //   Constant: '<Root>/Constant'

  memcpy((void *)&TxDataLocChar[0], (void *)&untitled_P.Constant_Value[0],
         (uint32_T)((size_t)18 * sizeof(uint8_T)));
  MW_SCI_Transmit(untitled_DW.obj_l.MW_SCIHANDLE, TxDataLocChar, 18U);

  // MATLABSystem: '<Root>/Serial Receive'
  if (untitled_DW.obj.SampleTime != untitled_P.SerialReceive_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.SerialReceive_SampleTime;
  }

  MW_SCI_GetDataBytesAvailable(untitled_DW.obj.MW_SCIHANDLE, false, &sizeptr, 5);
  if (sizeptr >= 18U) {
    MW_SCI_Receive(untitled_DW.obj.MW_SCIHANDLE, TxDataLocChar, 18U);
    memcpy((void *)&untitled_B.SerialReceive_o1[0], (void *)&TxDataLocChar[0],
           (uint32_T)((size_t)18 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 18; i++) {
      untitled_B.SerialReceive_o1[i] = 0U;
    }
  }

  // End of MATLABSystem: '<Root>/Serial Receive'
  rtExtModeUpload(1, (real_T)((untitled_M->Timing.clockTick1) * 0.1));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.1, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  untitled_M->Timing.clockTick1++;
}

// Model step wrapper function for compatibility with a static main program
void untitled_step(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled_step0();
    break;

   case 1 :
    untitled_step1();
    break;

   default :
    break;
  }
}

// Model initialize function
void untitled_initialize(void)
{
  // Registration code
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.01;

  // External mode info
  untitled_M->Sizes.checksums[0] = (3591994115U);
  untitled_M->Sizes.checksums[1] = (809155978U);
  untitled_M->Sizes.checksums[2] = (165403441U);
  untitled_M->Sizes.checksums[3] = (50094668U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for MATLABSystem: '<Root>/Serial Transmit'
  untitled_DW.obj_l.isInitialized = 0;
  untitled_DW.obj_l.matlabCodegenIsDeleted = false;
  untitled_SystemCore_setup_b(&untitled_DW.obj_l);

  // Start for MATLABSystem: '<Root>/Serial Receive'
  untitled_DW.obj.isInitialized = 0;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.SerialReceive_SampleTime;
  untitled_SystemCore_setup(&untitled_DW.obj);
}

// Model terminate function
void untitled_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Serial Transmit'
  matlabCodegenHandle_matlabCod_b(&untitled_DW.obj_l);

  // Terminate for MATLABSystem: '<Root>/Serial Receive'
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj);
}

//
// File trailer for generated code.
//
// [EOF]
//

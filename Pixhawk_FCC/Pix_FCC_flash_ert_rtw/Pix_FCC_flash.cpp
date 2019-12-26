//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash.cpp
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.322
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Dec 12 14:42:20 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Pix_FCC_flash.h"
#include "Pix_FCC_flash_private.h"

// Block signals (default storage)
B_Pix_FCC_flash_T Pix_FCC_flash_B;

// Block states (default storage)
DW_Pix_FCC_flash_T Pix_FCC_flash_DW;

// Real-time model
RT_MODEL_Pix_FCC_flash_T Pix_FCC_flash_M_ = RT_MODEL_Pix_FCC_flash_T();
RT_MODEL_Pix_FCC_flash_T *const Pix_FCC_flash_M = &Pix_FCC_flash_M_;

// Forward declaration for local functions
static void Pix_FCC_flash_SystemCore_setup(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_flas_SystemCore_release(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_flash_SystemCore_delete(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIWrit_T *obj);

// Forward declaration for local functions
static void Pix_FCC_flas_SystemCore_setup_e(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fl_SystemCore_release_d(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fla_SystemCore_delete_h(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void matlabCodegenHandle_matlabCod_a(px4_internal_block_PX4SCIWrit_T *obj);

// Forward declaration for local functions
static void Pix_FCC_flash_nullAssignment(real_T x_data[], int32_T x_size[2],
  const boolean_T idx_data[], const int32_T idx_size[2]);
static void Pix_F_SystemCore_release_b2qa4v(const
  px4_internal_block_Subscriber_T *obj);
static void Pix_FC_SystemCore_delete_b2qa4v(const
  px4_internal_block_Subscriber_T *obj);
static void matlabCodegenHandle_matl_b2qa4v(px4_internal_block_Subscriber_T *obj);
static void Pix_FCC_SystemCore_release_b2qa(px4_internal_block_PWM_Pix_FC_T *obj);
static void Pix_FCC__SystemCore_delete_b2qa(px4_internal_block_PWM_Pix_FC_T *obj);
static void matlabCodegenHandle_matlab_b2qa(px4_internal_block_PWM_Pix_FC_T *obj);
static void Pix_FCC_f_SystemCore_release_b2(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fl_SystemCore_delete_b2(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void matlabCodegenHandle_matlabCo_b2(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fl_SystemCore_release_b(const
  px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_fla_SystemCore_delete_b(const
  px4_internal_block_PX4SCIRead_T *obj);
static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_f_SystemCore_setup_b2qa(px4_internal_block_PWM_Pix_FC_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void Pix_FCC_fla_SystemCore_setup_b2(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_flas_SystemCore_setup_b(px4_internal_block_PX4SCIRead_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void Pix_FCC_flash_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(Pix_FCC_flash_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Pix_FCC_flash_M, 2));
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

  (Pix_FCC_flash_M->Timing.TaskCounters.TID[1])++;
  if ((Pix_FCC_flash_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.004s, 0.0s] 
    Pix_FCC_flash_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Pix_FCC_flash_M->Timing.TaskCounters.TID[2])++;
  if ((Pix_FCC_flash_M->Timing.TaskCounters.TID[2]) > 4) {// Sample time: [0.01s, 0.0s] 
    Pix_FCC_flash_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void Pix_FCC_flash_SystemCore_setup(px4_internal_block_PX4SCIWrit_T *obj)
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

static void Pix_FCC_flas_SystemCore_release(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pix_FCC_flash_SystemCore_delete(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  Pix_FCC_flas_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIWrit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_flash_SystemCore_delete(obj);
  }
}

//
// Start for function-call system:
//    '<S9>/Send WhiteNoise Beginning'
//    '<S9>/Send WhiteNoise End'
//    '<S39>/Send WhiteNoise Beginning'
//    '<S39>/Send WhiteNoise End'
//
void SendWhiteNoiseBeginni_Start(DW_SendWhiteNoiseBeginning_Pi_T *localDW)
{
  // Start for MATLABSystem: '<S15>/Serial Transmit'
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  Pix_FCC_flash_SystemCore_setup(&localDW->obj);
}

//
// Output and update for function-call system:
//    '<S9>/Send WhiteNoise Beginning'
//    '<S9>/Send WhiteNoise End'
//    '<S39>/Send WhiteNoise Beginning'
//    '<S39>/Send WhiteNoise End'
//
void Pix_SendWhiteNoiseBeginning(DW_SendWhiteNoiseBeginning_Pi_T *localDW,
  P_SendWhiteNoiseBeginning_Pix_T *localP)
{
  uint8_T TxDataLocChar[5];

  // MATLABSystem: '<S15>/Serial Transmit' incorporates:
  //   Constant: '<S15>/Header'

  memcpy((void *)&TxDataLocChar[0], (void *)&localP->Header_Value[0], (uint32_T)
         ((size_t)5 * sizeof(uint8_T)));
  MW_SCI_Transmit(localDW->obj.MW_SCIHANDLE, TxDataLocChar, 5U);
}

//
// Termination for function-call system:
//    '<S9>/Send WhiteNoise Beginning'
//    '<S9>/Send WhiteNoise End'
//    '<S39>/Send WhiteNoise Beginning'
//    '<S39>/Send WhiteNoise End'
//
void SendWhiteNoiseBeginnin_Term(DW_SendWhiteNoiseBeginning_Pi_T *localDW)
{
  // Terminate for MATLABSystem: '<S15>/Serial Transmit'
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static void Pix_FCC_flas_SystemCore_setup_e(px4_internal_block_PX4SCIWrit_T *obj)
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

static void Pix_FCC_fl_SystemCore_release_d(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pix_FCC_fla_SystemCore_delete_h(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  Pix_FCC_fl_SystemCore_release_d(obj);
}

static void matlabCodegenHandle_matlabCod_a(px4_internal_block_PX4SCIWrit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_fla_SystemCore_delete_h(obj);
  }
}

//
// Start for function-call system:
//    '<S9>/Send Header'
//    '<S9>/Send Terminator'
//    '<S39>/Send Header'
//    '<S39>/Send Terminator'
//
void Pix_FCC_fl_SendHeader_Start(DW_SendHeader_Pix_FCC_flash_T *localDW)
{
  // Start for MATLABSystem: '<S12>/Serial Transmit'
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  Pix_FCC_flas_SystemCore_setup_e(&localDW->obj);
}

//
// Output and update for function-call system:
//    '<S9>/Send Header'
//    '<S9>/Send Terminator'
//    '<S39>/Send Header'
//    '<S39>/Send Terminator'
//
void Pix_FCC_flash_SendHeader(DW_SendHeader_Pix_FCC_flash_T *localDW,
  P_SendHeader_Pix_FCC_flash_T *localP)
{
  uint8_T TxDataLocChar[2];

  // MATLABSystem: '<S12>/Serial Transmit' incorporates:
  //   Constant: '<S12>/Header'

  memcpy((void *)&TxDataLocChar[0], (void *)&localP->Header_Value[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_SCI_Transmit(localDW->obj.MW_SCIHANDLE, TxDataLocChar, 2U);
}

//
// Termination for function-call system:
//    '<S9>/Send Header'
//    '<S9>/Send Terminator'
//    '<S39>/Send Header'
//    '<S39>/Send Terminator'
//
void Pix_FCC_fla_SendHeader_Term(DW_SendHeader_Pix_FCC_flash_T *localDW)
{
  // Terminate for MATLABSystem: '<S12>/Serial Transmit'
  matlabCodegenHandle_matlabCod_a(&localDW->obj);
}

// Function for MATLAB Function: '<S6>/DecodeCommand'
static void Pix_FCC_flash_nullAssignment(real_T x_data[], int32_T x_size[2],
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

static void Pix_F_SystemCore_release_b2qa4v(const
  px4_internal_block_Subscriber_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_read_terminate(&obj->eventStructObj);
  }
}

static void Pix_FC_SystemCore_delete_b2qa4v(const
  px4_internal_block_Subscriber_T *obj)
{
  Pix_F_SystemCore_release_b2qa4v(obj);
}

static void matlabCodegenHandle_matl_b2qa4v(px4_internal_block_Subscriber_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FC_SystemCore_delete_b2qa4v(obj);
  }
}

static void Pix_FCC_SystemCore_release_b2qa(px4_internal_block_PWM_Pix_FC_T *obj)
{
  uint16_T status;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    status = pwm_disarm(&obj->pwmDevHandler);
    obj->errorStatus = static_cast<uint16_T>((obj->errorStatus | status));
    status = pwm_resetServo(&obj->pwmDevHandler, obj->servoCount,
      obj->channelMask, obj->isMain);
    obj->errorStatus = static_cast<uint16_T>((obj->errorStatus | status));
    status = pwm_close(&obj->pwmDevHandler);
    obj->errorStatus = static_cast<uint16_T>((obj->errorStatus | status));
  }
}

static void Pix_FCC__SystemCore_delete_b2qa(px4_internal_block_PWM_Pix_FC_T *obj)
{
  Pix_FCC_SystemCore_release_b2qa(obj);
}

static void matlabCodegenHandle_matlab_b2qa(px4_internal_block_PWM_Pix_FC_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC__SystemCore_delete_b2qa(obj);
  }
}

static void Pix_FCC_f_SystemCore_release_b2(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pix_FCC_fl_SystemCore_delete_b2(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  Pix_FCC_f_SystemCore_release_b2(obj);
}

static void matlabCodegenHandle_matlabCo_b2(px4_internal_block_PX4SCIWrit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_fl_SystemCore_delete_b2(obj);
  }
}

static void Pix_FCC_fl_SystemCore_release_b(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pix_FCC_fla_SystemCore_delete_b(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  Pix_FCC_fl_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PX4SCIRead_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_fla_SystemCore_delete_b(obj);
  }
}

static void Pix_FCC_f_SystemCore_setup_b2qa(px4_internal_block_PWM_Pix_FC_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  uint16_T varargin_1_0;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler);
    obj->isArmed = false;
  }

  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  obj->channelMask = 63;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, varargin_2);
    varargin_1_0 = obj->errorStatus;
    obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, false);
    varargin_1_0 = obj->errorStatus;
    obj->errorStatus = static_cast<uint16_T>((varargin_1_0 | status));
  }

  obj->isSetupComplete = true;
}

static void Pix_FCC_fla_SystemCore_setup_b2(px4_internal_block_PX4SCIWrit_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '6' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pix_FCC_flash_B.RxPinLoc_b = MW_UNDEFINED_VALUE;
  Pix_FCC_flash_B.TxPinLoc_p = MW_UNDEFINED_VALUE;
  for (i = 0; i < 10; i++) {
    Pix_FCC_flash_B.SCIModuleLoc_c[i] = tmp[i];
  }

  Pix_FCC_flash_B.SCIModuleLoc_c[10] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(Pix_FCC_flash_B.SCIModuleLoc_c, true,
    Pix_FCC_flash_B.RxPinLoc_b, Pix_FCC_flash_B.TxPinLoc_p);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  Pix_FCC_flash_B.StopBitsValue_c = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        Pix_FCC_flash_B.StopBitsValue_c);
  obj->isSetupComplete = true;
}

static void Pix_FCC_flas_SystemCore_setup_b(px4_internal_block_PX4SCIRead_T *obj)
{
  MW_SCI_HardwareFlowControl_Type HardwareFlowControlValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '6' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pix_FCC_flash_B.RxPinLoc = MW_UNDEFINED_VALUE;
  Pix_FCC_flash_B.TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 10; i++) {
    Pix_FCC_flash_B.SCIModuleLoc[i] = tmp[i];
  }

  Pix_FCC_flash_B.SCIModuleLoc[10] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(Pix_FCC_flash_B.SCIModuleLoc, true,
    Pix_FCC_flash_B.RxPinLoc, Pix_FCC_flash_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  Pix_FCC_flash_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Pix_FCC_flash_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, Pix_FCC_flash_B.ParityValue,
                        Pix_FCC_flash_B.StopBitsValue);
  Pix_FCC_flash_B.RxPinLoc = MW_UNDEFINED_VALUE;
  Pix_FCC_flash_B.TxPinLoc = MW_UNDEFINED_VALUE;
  HardwareFlowControlValue = MW_SCI_FLOWCONTROL_RTS_CTS;
  MW_SCI_ConfigureHardwareFlowControl(obj->MW_SCIHANDLE,
    HardwareFlowControlValue, Pix_FCC_flash_B.RxPinLoc, Pix_FCC_flash_B.TxPinLoc);
  obj->isSetupComplete = true;
}

// Model step function for TID0
void Pix_FCC_flash_step0(void)         // Sample time: [0.002s, 0.0s]
{
  {                                    // Sample time: [0.002s, 0.0s]
    rate_monotonic_scheduler();
  }
}

// Model step function for TID1
void Pix_FCC_flash_step1(void)         // Sample time: [0.004s, 0.0s]
{
  boolean_T b_varargout_1;
  px4_Bus_vehicle_attitude b_varargout_2;

  // MATLABSystem: '<S58>/SourceBlock' incorporates:
  //   Inport: '<S59>/In1'

  b_varargout_1 = uORB_read_step(Pix_FCC_flash_DW.obj_d.orbMetadataObj,
    &Pix_FCC_flash_DW.obj_d.eventStructObj, &Pix_FCC_flash_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S58>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S59>/Enable'

  if (b_varargout_1) {
    Pix_FCC_flash_B.In1_j = Pix_FCC_flash_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S58>/SourceBlock'
  // End of Outputs for SubSystem: '<S58>/Enabled Subsystem'

  // MATLABSystem: '<S60>/SourceBlock' incorporates:
  //   Inport: '<S61>/In1'

  b_varargout_1 = uORB_read_step(Pix_FCC_flash_DW.obj_f.orbMetadataObj,
    &Pix_FCC_flash_DW.obj_f.eventStructObj, &Pix_FCC_flash_B.b_varargout_2_k,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S60>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S61>/Enable'

  if (b_varargout_1) {
    Pix_FCC_flash_B.In1 = Pix_FCC_flash_B.b_varargout_2_k;
  }

  // End of MATLABSystem: '<S60>/SourceBlock'
  // End of Outputs for SubSystem: '<S60>/Enabled Subsystem'

  // MATLABSystem: '<S62>/SourceBlock' incorporates:
  //   Inport: '<S63>/In1'

  b_varargout_1 = uORB_read_step(Pix_FCC_flash_DW.obj_c.orbMetadataObj,
    &Pix_FCC_flash_DW.obj_c.eventStructObj, &b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S62>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S63>/Enable'

  if (b_varargout_1) {
    Pix_FCC_flash_B.In1_c = b_varargout_2;
  }

  // End of MATLABSystem: '<S62>/SourceBlock'
  // End of Outputs for SubSystem: '<S62>/Enabled Subsystem'

  // RateTransition generated from: '<Root>/ExecutionCycle'
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B
    [(Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10] =
    Pix_FCC_flash_B.In1_j.x;
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[1 +
    (Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10] =
    Pix_FCC_flash_B.In1_j.y;
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[2 +
    (Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10] =
    Pix_FCC_flash_B.In1_j.z;
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[3 +
    (Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10] =
    Pix_FCC_flash_B.In1.x;
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[4 +
    (Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10] =
    Pix_FCC_flash_B.In1.y;
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[5 +
    (Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10] =
    Pix_FCC_flash_B.In1.z;
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B
    [(Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10 + 6] =
    Pix_FCC_flash_B.In1_c.q[0];
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B
    [(Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10 + 7] =
    Pix_FCC_flash_B.In1_c.q[1];
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B
    [(Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10 + 8] =
    Pix_FCC_flash_B.In1_c.q[2];
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B
    [(Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0) * 10 + 9] =
    Pix_FCC_flash_B.In1_c.q[3];
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_A = static_cast<int8_T>
    ((Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s == 0));
}

// Model step function for TID2
void Pix_FCC_flash_step2(void)         // Sample time: [0.01s, 0.0s]
{
  uint8_T sizeptr;
  real32_T ROT1;
  real32_T ROT2;
  real32_T ROT3;
  real32_T ATT_phi;
  real32_T ATT_theta;
  real32_T ATT_psi;
  uint8_T x[2];
  uint16_T status;
  uint8_T TxDataLocChar;
  int32_T rtb_mode;
  boolean_T rtb_Compare_a;
  int32_T rtb_enable_execution;
  uint16_T Output;
  int32_T loop_ub;
  boolean_T exitg1;

  // MATLABSystem: '<Root>/Receive Data' incorporates:
  //   MATLAB Function: '<S6>/DecodeCommand'

  if (Pix_FCC_flash_DW.obj.SampleTime != Pix_FCC_flash_P.ReceiveData_SampleTime)
  {
    Pix_FCC_flash_DW.obj.SampleTime = Pix_FCC_flash_P.ReceiveData_SampleTime;
  }

  MW_SCI_GetDataBytesAvailable(Pix_FCC_flash_DW.obj.MW_SCIHANDLE, false,
    &sizeptr, 5);
  if (sizeptr >= 128U) {
    MW_SCI_Receive(Pix_FCC_flash_DW.obj.MW_SCIHANDLE,
                   Pix_FCC_flash_B.RxDataLocChar, 128U);
    memcpy((void *)&Pix_FCC_flash_B.RxData[0], (void *)
           &Pix_FCC_flash_B.RxDataLocChar[0], (uint32_T)((size_t)128 * sizeof
            (uint8_T)));
    sizeptr = 0U;

    // Outputs for Enabled SubSystem: '<S1>/DecodeCommand' incorporates:
    //   EnablePort: '<S6>/Enable'

    // MATLAB Function: '<S6>/DecodeCommand'
    rtb_enable_execution = 4;
    Pix_FCC_flash_B.packet_data[0] = 0U;
    Pix_FCC_flash_B.packet_data[1] = 0U;
    Pix_FCC_flash_B.packet_data[2] = 0U;
    Pix_FCC_flash_B.packet_data[3] = 0U;
    Pix_FCC_flash_B.cmd_found_flg = false;
    for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < 128;
         Pix_FCC_flash_B.b_ii++) {
      Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
        (Pix_FCC_flash_B.RxData[Pix_FCC_flash_B.b_ii] == 8);
    }

    Pix_FCC_flash_B.idx = 0;
    Pix_FCC_flash_B.b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (Pix_FCC_flash_B.b_ii < 128)) {
      if (Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii]) {
        Pix_FCC_flash_B.idx++;
        Pix_FCC_flash_B.RxDataLocChar[Pix_FCC_flash_B.idx - 1] =
          static_cast<uint8_T>((Pix_FCC_flash_B.b_ii + 1));
        if (Pix_FCC_flash_B.idx >= 128) {
          exitg1 = true;
        } else {
          Pix_FCC_flash_B.b_ii++;
        }
      } else {
        Pix_FCC_flash_B.b_ii++;
      }
    }

    if (1 > Pix_FCC_flash_B.idx) {
      Pix_FCC_flash_B.idx = 0;
    }

    Pix_FCC_flash_B.start_size[0] = 1;
    Pix_FCC_flash_B.start_size[1] = Pix_FCC_flash_B.idx;
    loop_ub = Pix_FCC_flash_B.idx - 1;
    for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <= loop_ub;
         Pix_FCC_flash_B.b_ii++) {
      Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] =
        Pix_FCC_flash_B.RxDataLocChar[Pix_FCC_flash_B.b_ii];
    }

    Pix_FCC_flash_B.start_size_m[0] = 1;
    Pix_FCC_flash_B.start_size_m[1] = Pix_FCC_flash_B.idx;
    for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < Pix_FCC_flash_B.idx;
         Pix_FCC_flash_B.b_ii++) {
      Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
        ((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] + 2.0) - 1.0 > 128.0);
    }

    Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data,
      Pix_FCC_flash_B.start_size, Pix_FCC_flash_B.x,
      Pix_FCC_flash_B.start_size_m);
    Pix_FCC_flash_B.tmp_size_g[0] = 1;
    Pix_FCC_flash_B.tmp_size_g[1] = Pix_FCC_flash_B.start_size[1];
    loop_ub = Pix_FCC_flash_B.start_size[0] * Pix_FCC_flash_B.start_size[1];
    for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < loop_ub;
         Pix_FCC_flash_B.b_ii++) {
      Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] = (Pix_FCC_flash_B.RxData[
        static_cast<int32_T>(((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii]
        + 2.0) - 1.0)) - 1] != 8);
    }

    Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data,
      Pix_FCC_flash_B.start_size, Pix_FCC_flash_B.x, Pix_FCC_flash_B.tmp_size_g);
    if (Pix_FCC_flash_B.start_size[1] != 0) {
      Pix_FCC_flash_B.b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (Pix_FCC_flash_B.b_ii <= Pix_FCC_flash_B.start_size[1]
                           - 2)) {
        rtb_Compare_a = false;
        Pix_FCC_flash_B.Add = Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii +
          1];
        if (Pix_FCC_flash_B.Add -
            Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] == 6.0) {
          rtb_Compare_a = true;
        }

        if (rtb_Compare_a) {
          if (Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] + 2.0 >
              Pix_FCC_flash_B.Add - 1.0) {
            Pix_FCC_flash_B.idx = 0;
            Pix_FCC_flash_B.b_ii = 0;
          } else {
            Pix_FCC_flash_B.idx = static_cast<int32_T>
              ((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] + 2.0)) - 1;
            Pix_FCC_flash_B.b_ii = static_cast<int32_T>
              ((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii + 1] - 1.0));
          }

          rtb_enable_execution = Pix_FCC_flash_B.b_ii - Pix_FCC_flash_B.idx;
          for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <
               rtb_enable_execution; Pix_FCC_flash_B.b_ii++) {
            Pix_FCC_flash_B.packet_data[Pix_FCC_flash_B.b_ii] =
              Pix_FCC_flash_B.RxData[Pix_FCC_flash_B.idx + Pix_FCC_flash_B.b_ii];
          }

          Pix_FCC_flash_B.cmd_found_flg = true;
          exitg1 = true;
        } else {
          Pix_FCC_flash_B.b_ii++;
        }
      }
    } else {
      Pix_FCC_flash_B.packet_data[0] = 0U;
      Pix_FCC_flash_B.packet_data[1] = 0U;
      Pix_FCC_flash_B.packet_data[2] = 0U;
      Pix_FCC_flash_B.packet_data[3] = 0U;
    }

    Pix_FCC_flash_DW.SFunction_DIMS2_f[0] = 1;
    Pix_FCC_flash_DW.SFunction_DIMS2_f[1] = rtb_enable_execution;
    if (0 <= rtb_enable_execution - 1) {
      memcpy(&Pix_FCC_flash_B.cmd[0], &Pix_FCC_flash_B.packet_data[0],
             rtb_enable_execution * sizeof(uint8_T));
    }

    // Outputs for Enabled SubSystem: '<S6>/ConfirmCommand' incorporates:
    //   EnablePort: '<S9>/Enable'

    if (Pix_FCC_flash_B.cmd_found_flg) {
      // MATLAB Function: '<S9>/pack'
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.cmd[0];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.cmd[1];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.cmd[2];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.cmd[3];
      memcpy((void *)&Pix_FCC_flash_B.CMD1, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send WhiteNoise Beginning'

      Pix_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning,
        &Pix_FCC_flash_P.SendWhiteNoiseBeginning);

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send Header'

      Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendHeader,
        &Pix_FCC_flash_P.SendHeader);

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send RC Confrimation'

      // MATLABSystem: '<S13>/Serial Transmit' incorporates:
      //   Constant: '<S13>/Header'

      memcpy((void *)&TxDataLocChar, (void *)&Pix_FCC_flash_P.Header_Value,
             (uint32_T)((size_t)1 * sizeof(uint8_T)));
      MW_SCI_Transmit(Pix_FCC_flash_DW.obj_k.MW_SCIHANDLE, &TxDataLocChar, 1U);

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send Data'

      // MATLABSystem: '<S11>/Serial Transmit' incorporates:
      //   MATLAB Function: '<S9>/pack'

      memcpy((void *)&Pix_FCC_flash_B.pack[0], (void *)&Pix_FCC_flash_B.CMD1,
             (uint32_T)((size_t)4 * sizeof(uint8_T)));
      MW_SCI_Transmit(Pix_FCC_flash_DW.obj_b.MW_SCIHANDLE, Pix_FCC_flash_B.pack,
                      4U);

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send Terminator'

      Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendTerminator,
        &Pix_FCC_flash_P.SendTerminator);

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send WhiteNoise End'

      Pix_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseEnd,
        &Pix_FCC_flash_P.SendWhiteNoiseEnd);

      // End of Outputs for S-Function (fcncallgen): '<S9>/Function-Call Generator1' 
    }

    // End of Outputs for SubSystem: '<S6>/ConfirmCommand'
    // End of Outputs for SubSystem: '<S1>/DecodeCommand'
  } else {
    memset(&Pix_FCC_flash_B.RxData[0], 0, sizeof(uint8_T) << 7U);
    sizeptr = 1U;
  }

  // Outputs for Enabled SubSystem: '<S1>/memory' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (Pix_FCC_flash_B.cmd_found_flg) {
    // Inport: '<S8>/update'
    Pix_FCC_flash_DW.update_DIMS1[0] = Pix_FCC_flash_DW.SFunction_DIMS2_f[0];
    Pix_FCC_flash_DW.update_DIMS1[1] = Pix_FCC_flash_DW.SFunction_DIMS2_f[1];
    loop_ub = Pix_FCC_flash_DW.SFunction_DIMS2_f[0] *
      Pix_FCC_flash_DW.SFunction_DIMS2_f[1];
    if (0 <= loop_ub - 1) {
      memcpy(&Pix_FCC_flash_B.update[0], &Pix_FCC_flash_B.cmd[0], loop_ub *
             sizeof(uint8_T));
    }

    // End of Inport: '<S8>/update'
  }

  // End of Outputs for SubSystem: '<S1>/memory'

  // MATLAB Function: '<S1>/SetMode' incorporates:
  //   Constant: '<S3>/Constant'

  rtb_mode = 1;
  if (Pix_FCC_flash_P.Constant_Value_i) {
    switch (Pix_FCC_flash_B.update[0]) {
     case 1:
      rtb_mode = 2;
      break;

     case 2:
      rtb_mode = 3;
      break;

     case 3:
      rtb_mode = 4;
      break;
    }
  }

  // End of MATLAB Function: '<S1>/SetMode'

  // MATLAB Function: '<S5>/ControlExecution' incorporates:
  //   Logic: '<S5>/NOT'
  //   MATLABSystem: '<Root>/Receive Data'

  switch (rtb_mode) {
   case 1:
    rtb_enable_execution = 1;
    break;

   case 2:
    rtb_enable_execution = (sizeptr == 0);
    break;

   case 3:
    rtb_enable_execution = 1;
    break;

   default:
    rtb_enable_execution = 1;
    break;
  }

  // End of MATLAB Function: '<S5>/ControlExecution'

  // RateTransition generated from: '<Root>/ExecutionCycle'
  Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s =
    Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_A;
  Pix_FCC_flash_B.b_ii = Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_s * 10;
  for (Pix_FCC_flash_B.idx = 0; Pix_FCC_flash_B.idx < 10; Pix_FCC_flash_B.idx++)
  {
    Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[Pix_FCC_flash_B.idx] =
      Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[Pix_FCC_flash_B.idx +
      Pix_FCC_flash_B.b_ii];
  }

  // End of RateTransition generated from: '<Root>/ExecutionCycle'

  // Outputs for Enabled SubSystem: '<Root>/ExecutionCycle' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (rtb_enable_execution > 0) {
    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/heartbeat'

    // UnitDelay: '<S48>/Output'
    Output = Pix_FCC_flash_DW.Output_DSTATE;

    // Sum: '<S49>/FixPt Sum1' incorporates:
    //   Constant: '<S49>/FixPt Constant'
    //   UnitDelay: '<S48>/Output'

    Pix_FCC_flash_DW.Output_DSTATE = static_cast<uint16_T>((static_cast<uint32_T>
      (Pix_FCC_flash_DW.Output_DSTATE) + Pix_FCC_flash_P.FixPtConstant_Value));

    // Switch: '<S50>/FixPt Switch' incorporates:
    //   Constant: '<S50>/Constant'
    //   UnitDelay: '<S48>/Output'

    if (Pix_FCC_flash_DW.Output_DSTATE > Pix_FCC_flash_P.WrapToZero_Threshold) {
      Pix_FCC_flash_DW.Output_DSTATE = Pix_FCC_flash_P.Constant_Value_p;
    }

    // End of Switch: '<S50>/FixPt Switch'

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/process_received_data'

    // Outputs for Enabled SubSystem: '<S21>/input_hold' incorporates:
    //   EnablePort: '<S51>/Enable'

    // Logic: '<S2>/NOT' incorporates:
    //   Inport: '<S54>/ACC_update'
    //   Inport: '<S54>/ATT_update'
    //   Inport: '<S54>/CMD_update'
    //   Inport: '<S54>/ROT_update'
    //   Inport: '<S54>/TestSignal_update'
    //   MATLAB Function: '<S51>/ByteUnpack'
    //   MATLAB Function: '<S51>/ExtractMessage'
    //   MATLABSystem: '<Root>/Receive Data'

    if (sizeptr == 0) {
      // MATLAB Function: '<S51>/ExtractMessage'
      rtb_enable_execution = 56;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < 56;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.packet_data_c[Pix_FCC_flash_B.b_ii] = 0U;
      }

      Pix_FCC_flash_B.packetfound = false;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < 128;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
          (Pix_FCC_flash_B.RxData[Pix_FCC_flash_B.b_ii] == 7);
      }

      Pix_FCC_flash_B.idx = 0;
      Pix_FCC_flash_B.b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (Pix_FCC_flash_B.b_ii < 128)) {
        if (Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii]) {
          Pix_FCC_flash_B.idx++;
          Pix_FCC_flash_B.RxDataLocChar[Pix_FCC_flash_B.idx - 1] =
            static_cast<uint8_T>((Pix_FCC_flash_B.b_ii + 1));
          if (Pix_FCC_flash_B.idx >= 128) {
            exitg1 = true;
          } else {
            Pix_FCC_flash_B.b_ii++;
          }
        } else {
          Pix_FCC_flash_B.b_ii++;
        }
      }

      if (1 > Pix_FCC_flash_B.idx) {
        Pix_FCC_flash_B.idx = 0;
      }

      Pix_FCC_flash_B.start_size_f[0] = 1;
      Pix_FCC_flash_B.start_size_f[1] = Pix_FCC_flash_B.idx;
      loop_ub = Pix_FCC_flash_B.idx - 1;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <= loop_ub;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] =
          Pix_FCC_flash_B.RxDataLocChar[Pix_FCC_flash_B.b_ii];
      }

      Pix_FCC_flash_B.start_size_g[0] = 1;
      Pix_FCC_flash_B.start_size_g[1] = Pix_FCC_flash_B.idx;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < Pix_FCC_flash_B.idx;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
          ((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0) - 1.0 >
           128.0);
      }

      Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data_m,
        Pix_FCC_flash_B.start_size_f, Pix_FCC_flash_B.x,
        Pix_FCC_flash_B.start_size_g);
      Pix_FCC_flash_B.tmp_size[0] = 1;
      Pix_FCC_flash_B.tmp_size[1] = Pix_FCC_flash_B.start_size_f[1];
      loop_ub = Pix_FCC_flash_B.start_size_f[0] * Pix_FCC_flash_B.start_size_f[1];
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < loop_ub;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] = (Pix_FCC_flash_B.RxData[
          static_cast<int32_T>
          (((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0) - 1.0)) -
          1] != 7);
      }

      Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data_m,
        Pix_FCC_flash_B.start_size_f, Pix_FCC_flash_B.x,
        Pix_FCC_flash_B.tmp_size);
      if (Pix_FCC_flash_B.start_size_f[1] != 0) {
        Pix_FCC_flash_B.b_ii = 0;
        exitg1 = false;
        while ((!exitg1) && (Pix_FCC_flash_B.b_ii <=
                             Pix_FCC_flash_B.start_size_f[1] - 2)) {
          rtb_Compare_a = false;
          Pix_FCC_flash_B.Add =
            Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii + 1];
          if (Pix_FCC_flash_B.Add -
              Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] == 58.0) {
            rtb_Compare_a = true;
          }

          if (rtb_Compare_a) {
            if (Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0 >
                Pix_FCC_flash_B.Add - 1.0) {
              Pix_FCC_flash_B.idx = 0;
              Pix_FCC_flash_B.b_ii = 0;
            } else {
              Pix_FCC_flash_B.idx = static_cast<int32_T>
                ((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0)) - 1;
              Pix_FCC_flash_B.b_ii = static_cast<int32_T>
                ((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii + 1] - 1.0));
            }

            rtb_enable_execution = Pix_FCC_flash_B.b_ii - Pix_FCC_flash_B.idx;
            for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <
                 rtb_enable_execution; Pix_FCC_flash_B.b_ii++) {
              Pix_FCC_flash_B.packet_data_c[Pix_FCC_flash_B.b_ii] =
                Pix_FCC_flash_B.RxData[Pix_FCC_flash_B.idx +
                Pix_FCC_flash_B.b_ii];
            }

            Pix_FCC_flash_B.packetfound = true;
            exitg1 = true;
          } else {
            Pix_FCC_flash_B.b_ii++;
          }
        }
      }

      Pix_FCC_flash_DW.SFunction_DIMS2[0] = 1;
      Pix_FCC_flash_DW.SFunction_DIMS2[1] = rtb_enable_execution;
      if (0 <= rtb_enable_execution - 1) {
        memcpy(&Pix_FCC_flash_B.message[0], &Pix_FCC_flash_B.packet_data_c[0],
               rtb_enable_execution * sizeof(uint8_T));
      }

      // MATLAB Function: '<S51>/ByteUnpack' incorporates:
      //   MATLAB Function: '<S51>/ExtractMessage'

      x[0] = Pix_FCC_flash_B.message[0];
      x[1] = Pix_FCC_flash_B.message[1];
      memcpy((void *)&status, (void *)&x[0], (uint32_T)((size_t)1 * sizeof
              (uint16_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[4];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[5];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[6];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[7];
      memcpy((void *)&Pix_FCC_flash_B.CMD1, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[8];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[9];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[10];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[11];
      memcpy((void *)&Pix_FCC_flash_B.CMD2, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[12];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[13];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[14];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[15];
      memcpy((void *)&Pix_FCC_flash_B.CMD3, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[16];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[17];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[18];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[19];
      memcpy((void *)&Pix_FCC_flash_B.ACC1, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[20];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[21];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[22];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[23];
      memcpy((void *)&Pix_FCC_flash_B.ACC2, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[24];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[25];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[26];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[27];
      memcpy((void *)&Pix_FCC_flash_B.ACC3, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[28];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[29];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[30];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[31];
      memcpy((void *)&ROT1, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)((size_t)
              1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[32];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[33];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[34];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[35];
      memcpy((void *)&ROT2, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)((size_t)
              1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[36];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[37];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[38];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[39];
      memcpy((void *)&ROT3, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)((size_t)
              1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[40];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[41];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[42];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[43];
      memcpy((void *)&ATT_phi, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)
             ((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[44];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[45];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[46];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[47];
      memcpy((void *)&ATT_theta, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)
             ((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[48];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[49];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[50];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[51];
      memcpy((void *)&ATT_psi, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)
             ((size_t)1 * sizeof(real32_T)));
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.message[52];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.message[53];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.message[54];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.message[55];
      memcpy((void *)&Pix_FCC_flash_B.TestSignal, (void *)&Pix_FCC_flash_B.pack
             [0], (uint32_T)((size_t)1 * sizeof(real32_T)));

      // Outputs for Enabled SubSystem: '<S51>/hold' incorporates:
      //   EnablePort: '<S54>/Enable'

      if (Pix_FCC_flash_B.packetfound) {
        Pix_FCC_flash_B.CMD_update[0] = Pix_FCC_flash_B.CMD1;
        Pix_FCC_flash_B.CMD_update[1] = Pix_FCC_flash_B.CMD2;
        Pix_FCC_flash_B.CMD_update[2] = Pix_FCC_flash_B.CMD3;
        Pix_FCC_flash_B.ACC_update[0] = Pix_FCC_flash_B.ACC1;
        Pix_FCC_flash_B.ACC_update[1] = Pix_FCC_flash_B.ACC2;
        Pix_FCC_flash_B.ACC_update[2] = Pix_FCC_flash_B.ACC3;
        Pix_FCC_flash_B.ROT_update[0] = ROT1;
        Pix_FCC_flash_B.ROT_update[1] = ROT2;
        Pix_FCC_flash_B.ROT_update[2] = ROT3;
        Pix_FCC_flash_B.ATT_update[0] = ATT_phi;
        Pix_FCC_flash_B.ATT_update[1] = ATT_theta;
        Pix_FCC_flash_B.ATT_update[2] = ATT_psi;
        Pix_FCC_flash_B.TestSignal_update = Pix_FCC_flash_B.TestSignal;
      }

      // End of Outputs for SubSystem: '<S51>/hold'
    }

    // End of Logic: '<S2>/NOT'
    // End of Outputs for SubSystem: '<S21>/input_hold'

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // RelationalOperator: '<S22>/Compare' incorporates:
    //   Constant: '<S22>/Constant'

    rtb_Compare_a = (rtb_mode != Pix_FCC_flash_P.CompareToConstant_const);

    // Switch: '<S18>/Switch1' incorporates:
    //   Inport: '<S18>/SensorData'

    if (rtb_Compare_a) {
      Pix_FCC_flash_B.ACC3 = Pix_FCC_flash_B.ROT_update[0];
    } else {
      Pix_FCC_flash_B.ACC3 = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[3];
    }

    // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S23>/Gain'
    //   Sum: '<S23>/Sum'

    Pix_FCC_flash_B.CMD1 = ((Pix_FCC_flash_B.CMD_update[0] -
      Pix_FCC_flash_B.ACC3) * Pix_FCC_flash_P.Gain_Gain -
      Pix_FCC_flash_P.DiscreteTransferFcn_DenCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn_states) /
      Pix_FCC_flash_P.DiscreteTransferFcn_DenCoef[0];
    Pix_FCC_flash_B.ACC2 = Pix_FCC_flash_P.DiscreteTransferFcn_NumCoef[0] *
      Pix_FCC_flash_B.CMD1 + Pix_FCC_flash_P.DiscreteTransferFcn_NumCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn_states;

    // Switch: '<S18>/Switch' incorporates:
    //   Constant: '<S3>/Constant'
    //   Inport: '<S18>/SensorData'

    if (Pix_FCC_flash_P.Constant_Value_i) {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.ACC_update[2];
    } else {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[2];
    }

    // Sum: '<S23>/Sum1'
    Pix_FCC_flash_B.CMD3 = Pix_FCC_flash_B.CMD_update[1] - Pix_FCC_flash_B.CMD2;

    // Switch: '<S18>/Switch1' incorporates:
    //   Inport: '<S18>/SensorData'

    if (rtb_Compare_a) {
      Pix_FCC_flash_B.ACC3 = Pix_FCC_flash_B.ROT_update[1];
    } else {
      Pix_FCC_flash_B.ACC3 = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[4];
    }

    // Gain: '<S23>/Gain1' incorporates:
    //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
    //   Gain: '<S23>/Gain3'
    //   Sum: '<S23>/Sum2'
    //   Sum: '<S23>/Sum5'

    Pix_FCC_flash_B.ACC1 = ((Pix_FCC_flash_P.Gain3_Gain * Pix_FCC_flash_B.CMD3 +
      Pix_FCC_flash_P.DiscreteTransferFcn1_NumCoef *
      Pix_FCC_flash_DW.DiscreteTransferFcn1_states) - Pix_FCC_flash_B.ACC3) *
      Pix_FCC_flash_P.Gain1_Gain;

    // Switch: '<S18>/Switch' incorporates:
    //   Constant: '<S3>/Constant'
    //   Inport: '<S18>/SensorData'

    if (Pix_FCC_flash_P.Constant_Value_i) {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.ACC_update[1];
    } else {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[1];
    }

    // Sum: '<S23>/Sum3'
    Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.CMD_update[2] - Pix_FCC_flash_B.CMD2;

    // Switch: '<S18>/Switch1' incorporates:
    //   Inport: '<S18>/SensorData'

    if (rtb_Compare_a) {
      Pix_FCC_flash_B.ACC3 = Pix_FCC_flash_B.ROT_update[2];
    } else {
      Pix_FCC_flash_B.ACC3 = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[5];
    }

    // Gain: '<S23>/Gain2' incorporates:
    //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
    //   Gain: '<S23>/Gain4'
    //   Sum: '<S23>/Sum4'
    //   Sum: '<S23>/Sum6'

    Pix_FCC_flash_B.ACC3 = ((Pix_FCC_flash_P.Gain4_Gain * Pix_FCC_flash_B.CMD2 +
      Pix_FCC_flash_P.DiscreteTransferFcn2_NumCoef *
      Pix_FCC_flash_DW.DiscreteTransferFcn2_states) - Pix_FCC_flash_B.ACC3) *
      Pix_FCC_flash_P.Gain2_Gain;

    // Saturate: '<S26>/Limit2maxDeflection' incorporates:
    //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'

    if (Pix_FCC_flash_B.ACC2 > Pix_FCC_flash_P.Limit2maxDeflection_UpperSat) {
      Pix_FCC_flash_B.ACC2 = Pix_FCC_flash_P.Limit2maxDeflection_UpperSat;
    } else {
      if (Pix_FCC_flash_B.ACC2 < Pix_FCC_flash_P.Limit2maxDeflection_LowerSat) {
        Pix_FCC_flash_B.ACC2 = Pix_FCC_flash_P.Limit2maxDeflection_LowerSat;
      }
    }

    // End of Saturate: '<S26>/Limit2maxDeflection'

    // Sum: '<S26>/Add4' incorporates:
    //   Constant: '<S26>/Constant'
    //   Sum: '<S26>/Add5'

    Pix_FCC_flash_B.Add =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f1_rad +
      Pix_FCC_flash_B.ATT_update[0];

    // Sum: '<S26>/Add' incorporates:
    //   Fcn: '<S26>/Fcn'
    //   Fcn: '<S26>/Fcn1'
    //   Product: '<S26>/Multiply'
    //   Product: '<S26>/Multiply1'
    //   Sum: '<S26>/Add4'

    Pix_FCC_flash_B.Add = -cos(Pix_FCC_flash_B.Add) * Pix_FCC_flash_B.ACC3 + sin
      (Pix_FCC_flash_B.Add) * Pix_FCC_flash_B.ACC1;

    // Sum: '<S26>/Add6' incorporates:
    //   Constant: '<S26>/Constant1'
    //   Sum: '<S26>/Add7'

    Pix_FCC_flash_B.Add1 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f2_rad +
      Pix_FCC_flash_B.ATT_update[0];

    // Sum: '<S26>/Add1' incorporates:
    //   Fcn: '<S26>/Fcn2'
    //   Fcn: '<S26>/Fcn3'
    //   Product: '<S26>/Multiply2'
    //   Product: '<S26>/Multiply3'
    //   Sum: '<S26>/Add6'

    Pix_FCC_flash_B.Add1 = -cos(Pix_FCC_flash_B.Add1) * Pix_FCC_flash_B.ACC3 +
      sin(Pix_FCC_flash_B.Add1) * Pix_FCC_flash_B.ACC1;

    // Sum: '<S26>/Add8' incorporates:
    //   Constant: '<S26>/Constant2'
    //   Sum: '<S26>/Add9'

    Pix_FCC_flash_B.Add2 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f3_rad +
      Pix_FCC_flash_B.ATT_update[0];

    // Sum: '<S26>/Add2' incorporates:
    //   Fcn: '<S26>/Fcn4'
    //   Fcn: '<S26>/Fcn5'
    //   Product: '<S26>/Multiply4'
    //   Product: '<S26>/Multiply5'
    //   Sum: '<S26>/Add8'

    Pix_FCC_flash_B.Add2 = -cos(Pix_FCC_flash_B.Add2) * Pix_FCC_flash_B.ACC3 +
      sin(Pix_FCC_flash_B.Add2) * Pix_FCC_flash_B.ACC1;

    // Sum: '<S26>/Add10' incorporates:
    //   Constant: '<S26>/Constant3'
    //   Sum: '<S26>/Add11'

    Pix_FCC_flash_B.Add3 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f4_rad +
      Pix_FCC_flash_B.ATT_update[0];

    // Sum: '<S26>/Add3' incorporates:
    //   Fcn: '<S26>/Fcn6'
    //   Fcn: '<S26>/Fcn7'
    //   Product: '<S26>/Multiply6'
    //   Product: '<S26>/Multiply7'
    //   Sum: '<S26>/Add10'

    Pix_FCC_flash_B.Add3 = -cos(Pix_FCC_flash_B.Add3) * Pix_FCC_flash_B.ACC3 +
      sin(Pix_FCC_flash_B.Add3) * Pix_FCC_flash_B.ACC1;

    // Sum: '<S26>/Add16' incorporates:
    //   Abs: '<S26>/Abs'
    //   Constant: '<S26>/Constant4'

    Pix_FCC_flash_B.Add16 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad -
      static_cast<real32_T>(fabs(static_cast<real_T>(Pix_FCC_flash_B.ACC2)));

    // Outputs for Enabled SubSystem: '<S28>/Pass' incorporates:
    //   EnablePort: '<S30>/Enable'

    // Outputs for Enabled SubSystem: '<S28>/Saturate' incorporates:
    //   EnablePort: '<S31>/Enable'

    // Logic: '<S28>/Logical Operator' incorporates:
    //   Abs: '<S29>/Abs'
    //   Abs: '<S29>/Abs1'
    //   Abs: '<S29>/Abs2'
    //   Abs: '<S29>/Abs3'
    //   Logic: '<S29>/OR'
    //   RelationalOperator: '<S29>/Relational Operator'
    //   RelationalOperator: '<S29>/Relational Operator1'
    //   RelationalOperator: '<S29>/Relational Operator2'
    //   RelationalOperator: '<S29>/Relational Operator3'

    if ((fabs(Pix_FCC_flash_B.Add) > Pix_FCC_flash_B.Add16) || (fabs
         (Pix_FCC_flash_B.Add1) > Pix_FCC_flash_B.Add16) || (fabs
         (Pix_FCC_flash_B.Add2) > Pix_FCC_flash_B.Add16) || (fabs
         (Pix_FCC_flash_B.Add3) > Pix_FCC_flash_B.Add16)) {
      // MinMax: '<S31>/Max'
      if ((Pix_FCC_flash_B.Add > Pix_FCC_flash_B.Add1) || rtIsNaN
          (Pix_FCC_flash_B.Add1)) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add;
      } else {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add1;
      }

      if ((!(Pix_FCC_flash_B.Abs1 > Pix_FCC_flash_B.Add2)) && (!rtIsNaN
           (Pix_FCC_flash_B.Add2))) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add2;
      }

      if ((!(Pix_FCC_flash_B.Abs1 > Pix_FCC_flash_B.Add3)) && (!rtIsNaN
           (Pix_FCC_flash_B.Add3))) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add3;
      }

      // End of MinMax: '<S31>/Max'

      // Abs: '<S31>/Abs1'
      Pix_FCC_flash_B.Abs1 = fabs(Pix_FCC_flash_B.Abs1);

      // Product: '<S31>/Multiply' incorporates:
      //   Product: '<S31>/Divide'

      Pix_FCC_flash_B.Add = Pix_FCC_flash_B.Add / Pix_FCC_flash_B.Abs1 *
        Pix_FCC_flash_B.Add16;

      // Product: '<S31>/Multiply1' incorporates:
      //   Product: '<S31>/Divide1'

      Pix_FCC_flash_B.Add1 = Pix_FCC_flash_B.Add1 / Pix_FCC_flash_B.Abs1 *
        Pix_FCC_flash_B.Add16;

      // Product: '<S31>/Multiply3' incorporates:
      //   Product: '<S31>/Divide2'

      Pix_FCC_flash_B.Add3 = Pix_FCC_flash_B.Add3 / Pix_FCC_flash_B.Abs1 *
        Pix_FCC_flash_B.Add16;

      // Product: '<S31>/Multiply2' incorporates:
      //   Product: '<S31>/Divide4'

      Pix_FCC_flash_B.Add2 = Pix_FCC_flash_B.Add2 / Pix_FCC_flash_B.Abs1 *
        Pix_FCC_flash_B.Add16;
    }

    // End of Logic: '<S28>/Logical Operator'
    // End of Outputs for SubSystem: '<S28>/Saturate'
    // End of Outputs for SubSystem: '<S28>/Pass'

    // Product: '<S32>/Product' incorporates:
    //   Constant: '<S32>/Constant6'
    //   Constant: '<S33>/Constant6'
    //   Constant: '<S34>/Constant6'
    //   Constant: '<S35>/Constant6'
    //   Product: '<S33>/Product'
    //   Product: '<S34>/Product'
    //   Product: '<S35>/Product'

    Pix_FCC_flash_B.Add16 =
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms -
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Sum: '<S32>/Add' incorporates:
    //   Constant: '<S27>/Constant'
    //   Constant: '<S32>/Constant2'
    //   Constant: '<S32>/Constant6'
    //   Product: '<S32>/Divide'
    //   Product: '<S32>/Product'
    //   Sum: '<S26>/Add15'

    Pix_FCC_flash_B.Add = (Pix_FCC_flash_B.ACC2 + Pix_FCC_flash_B.Add) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S32>/Saturation'
    if (Pix_FCC_flash_B.Add >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.Add =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.Add <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.Add =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S32>/Saturation'

    // Sum: '<S33>/Add' incorporates:
    //   Constant: '<S27>/Constant'
    //   Constant: '<S33>/Constant2'
    //   Product: '<S33>/Divide'
    //   Product: '<S33>/Product'
    //   Sum: '<S26>/Add12'

    Pix_FCC_flash_B.Add1 = (Pix_FCC_flash_B.ACC2 + Pix_FCC_flash_B.Add1) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S33>/Saturation'
    if (Pix_FCC_flash_B.Add1 >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.Add1 =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.Add1 <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.Add1 =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S33>/Saturation'

    // Sum: '<S34>/Add' incorporates:
    //   Constant: '<S27>/Constant'
    //   Constant: '<S34>/Constant2'
    //   Product: '<S34>/Divide'
    //   Product: '<S34>/Product'
    //   Sum: '<S26>/Add13'

    Pix_FCC_flash_B.Add2 = (Pix_FCC_flash_B.ACC2 + Pix_FCC_flash_B.Add2) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S34>/Saturation'
    if (Pix_FCC_flash_B.Add2 >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.Add2 =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.Add2 <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.Add2 =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S34>/Saturation'

    // Sum: '<S35>/Add' incorporates:
    //   Constant: '<S27>/Constant'
    //   Constant: '<S35>/Constant2'
    //   Product: '<S35>/Divide'
    //   Product: '<S35>/Product'
    //   Sum: '<S26>/Add14'

    Pix_FCC_flash_B.Add3 = (Pix_FCC_flash_B.ACC2 + Pix_FCC_flash_B.Add3) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S35>/Saturation'
    if (Pix_FCC_flash_B.Add3 >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.Add3 =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.Add3 <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.Add3 =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S35>/Saturation'

    // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
    Pix_FCC_flash_DW.DiscreteTransferFcn_states = Pix_FCC_flash_B.CMD1;

    // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
    Pix_FCC_flash_DW.DiscreteTransferFcn1_states = (Pix_FCC_flash_B.CMD3 -
      Pix_FCC_flash_P.DiscreteTransferFcn1_DenCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn1_states) /
      Pix_FCC_flash_P.DiscreteTransferFcn1_DenCoef[0];

    // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
    Pix_FCC_flash_DW.DiscreteTransferFcn2_states = (Pix_FCC_flash_B.CMD2 -
      Pix_FCC_flash_P.DiscreteTransferFcn2_DenCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn2_states) /
      Pix_FCC_flash_P.DiscreteTransferFcn2_DenCoef[0];

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/OUTPUT'

    // DataTypeConversion: '<S19>/Data Type Conversion3' incorporates:
    //   DataTypeConversion: '<S18>/Data Type Conversion'

    Pix_FCC_flash_B.CMD2 = static_cast<real32_T>(floor(static_cast<real_T>(
      static_cast<real32_T>(Pix_FCC_flash_B.Add))));
    if (rtIsNaNF(Pix_FCC_flash_B.CMD2) || rtIsInfF(Pix_FCC_flash_B.CMD2)) {
      Pix_FCC_flash_B.CMD2 = 0.0F;
    } else {
      Pix_FCC_flash_B.CMD2 = static_cast<real32_T>(fmod(static_cast<real_T>
        (Pix_FCC_flash_B.CMD2), 65536.0));
    }

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    Pix_FCC_flash_B.CMD1 = static_cast<real32_T>(floor(static_cast<real_T>(
      static_cast<real32_T>(Pix_FCC_flash_B.Add1))));
    if (rtIsNaNF(Pix_FCC_flash_B.CMD1) || rtIsInfF(Pix_FCC_flash_B.CMD1)) {
      Pix_FCC_flash_B.CMD1 = 0.0F;
    } else {
      Pix_FCC_flash_B.CMD1 = static_cast<real32_T>(fmod(static_cast<real_T>
        (Pix_FCC_flash_B.CMD1), 65536.0));
    }

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    Pix_FCC_flash_B.CMD3 = static_cast<real32_T>(floor(static_cast<real_T>(
      static_cast<real32_T>(Pix_FCC_flash_B.Add2))));
    if (rtIsNaNF(Pix_FCC_flash_B.CMD3) || rtIsInfF(Pix_FCC_flash_B.CMD3)) {
      Pix_FCC_flash_B.CMD3 = 0.0F;
    } else {
      Pix_FCC_flash_B.CMD3 = static_cast<real32_T>(fmod(static_cast<real_T>
        (Pix_FCC_flash_B.CMD3), 65536.0));
    }

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    Pix_FCC_flash_B.ACC1 = static_cast<real32_T>(floor(static_cast<real_T>(
      static_cast<real32_T>(Pix_FCC_flash_B.Add3))));
    if (rtIsNaNF(Pix_FCC_flash_B.ACC1) || rtIsInfF(Pix_FCC_flash_B.ACC1)) {
      Pix_FCC_flash_B.ACC1 = 0.0F;
    } else {
      Pix_FCC_flash_B.ACC1 = static_cast<real32_T>(fmod(static_cast<real_T>
        (Pix_FCC_flash_B.ACC1), 65536.0));
    }

    // MATLABSystem: '<S38>/PX4 PWM Output' incorporates:
    //   Constant: '<S19>/HIL_detect_flg'
    //   Constant: '<S19>/PWM_arm_flg'
    //   Constant: '<S19>/Recovery_activation_flg'
    //   DataTypeConversion: '<S19>/Data Type Conversion3'
    //   Gain: '<S38>/ms2us_1'
    //   Gain: '<S38>/ms2us_2'
    //   Gain: '<S38>/ms2us_3'
    //   Gain: '<S38>/ms2us_4'

    if (Pix_FCC_flash_P.PWM_arm_flg_Value) {
      if (!Pix_FCC_flash_DW.obj_j.isArmed) {
        Pix_FCC_flash_DW.obj_j.isArmed = true;
        status = pwm_arm(&Pix_FCC_flash_DW.obj_j.pwmDevHandler);
        Pix_FCC_flash_DW.obj_j.errorStatus = static_cast<uint16_T>
          ((Pix_FCC_flash_DW.obj_j.errorStatus | status));
      }

      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < 8;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.pwmValue[Pix_FCC_flash_B.b_ii] = 0U;
      }

      Pix_FCC_flash_B.pwmValue[0] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((Pix_FCC_flash_B.CMD2 < 0.0F ?
        static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-Pix_FCC_flash_B.CMD2)))) : static_cast<int32_T>(
        static_cast<uint16_T>(Pix_FCC_flash_B.CMD2))))) *
        Pix_FCC_flash_P.ms2us_1_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[1] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((Pix_FCC_flash_B.CMD1 < 0.0F ?
        static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-Pix_FCC_flash_B.CMD1)))) : static_cast<int32_T>(
        static_cast<uint16_T>(Pix_FCC_flash_B.CMD1))))) *
        Pix_FCC_flash_P.ms2us_2_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[2] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((Pix_FCC_flash_B.CMD3 < 0.0F ?
        static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-Pix_FCC_flash_B.CMD3)))) : static_cast<int32_T>(
        static_cast<uint16_T>(Pix_FCC_flash_B.CMD3))))) *
        Pix_FCC_flash_P.ms2us_3_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[3] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((Pix_FCC_flash_B.ACC1 < 0.0F ?
        static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-Pix_FCC_flash_B.ACC1)))) : static_cast<int32_T>(
        static_cast<uint16_T>(Pix_FCC_flash_B.ACC1))))) *
        Pix_FCC_flash_P.ms2us_4_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[4] =
        Pix_FCC_flash_P.Recovery_activation_flg_Value;
      Pix_FCC_flash_B.pwmValue[5] = Pix_FCC_flash_P.HIL_detect_flg_Value;
      status = pwm_setServo(&Pix_FCC_flash_DW.obj_j.pwmDevHandler,
                            Pix_FCC_flash_DW.obj_j.servoCount,
                            Pix_FCC_flash_DW.obj_j.channelMask,
                            Pix_FCC_flash_B.pwmValue);
      Pix_FCC_flash_DW.obj_j.errorStatus = static_cast<uint16_T>
        ((Pix_FCC_flash_DW.obj_j.errorStatus | status));
    } else {
      status = pwm_disarm(&Pix_FCC_flash_DW.obj_j.pwmDevHandler);
      Pix_FCC_flash_DW.obj_j.errorStatus = static_cast<uint16_T>
        ((Pix_FCC_flash_DW.obj_j.errorStatus | status));
      Pix_FCC_flash_DW.obj_j.isArmed = false;
      status = pwm_resetServo(&Pix_FCC_flash_DW.obj_j.pwmDevHandler,
        Pix_FCC_flash_DW.obj_j.servoCount, Pix_FCC_flash_DW.obj_j.channelMask,
        Pix_FCC_flash_DW.obj_j.isMain);
      Pix_FCC_flash_DW.obj_j.errorStatus = static_cast<uint16_T>
        ((Pix_FCC_flash_DW.obj_j.errorStatus | status));
    }

    if (Pix_FCC_flash_DW.obj_j.isMain) {
      status = pwm_forceFailsafe(&Pix_FCC_flash_DW.obj_j.pwmDevHandler,
        Pix_FCC_flash_P.PWM_arm_flg_Value);
      Pix_FCC_flash_DW.obj_j.errorStatus = static_cast<uint16_T>
        ((Pix_FCC_flash_DW.obj_j.errorStatus | status));
    }

    // End of MATLABSystem: '<S38>/PX4 PWM Output'

    // Outputs for Enabled SubSystem: '<S19>/serial send' incorporates:
    //   EnablePort: '<S39>/Enable'

    // RelationalOperator: '<S36>/Compare' incorporates:
    //   Constant: '<S36>/Constant'
    //   UnitDelay: '<S37>/Output'

    if (Pix_FCC_flash_DW.Output_DSTATE_o ==
        Pix_FCC_flash_P.CompareToConstant_const_h) {
      // MATLAB Function: '<S39>/MessageAssembly' incorporates:
      //   Constant: '<S39>/Constant'
      //   MATLAB Function: '<S18>/DefineRCStatus'
      //   MATLAB Function: '<S18>/DefineStatus'
      //   MATLABSystem: '<S43>/Serial Transmit'

      if (Pix_FCC_flash_P.Constant_Value_h == 1.0) {
        memcpy((void *)&x[0], (void *)&Output, (uint32_T)((size_t)2 * sizeof
                (uint8_T)));
        Pix_FCC_flash_B.pack[0] = x[0];
        Pix_FCC_flash_B.pack[1] = x[1];

        // Outputs for Function Call SubSystem: '<S2>/ACTION'
        Pix_FCC_flash_B.pack[2] = static_cast<uint8_T>(rtb_mode);
        Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.packetfound;

        // End of Outputs for SubSystem: '<S2>/ACTION'

        // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
        //   SubSystem: '<S39>/Send Data'

        memcpy((void *)&Pix_FCC_flash_B.u0[0], (void *)&Pix_FCC_flash_B.pack[0],
               (uint32_T)((size_t)1 * sizeof(real32_T)));

        // End of Outputs for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 
      } else {
        // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
        //   SubSystem: '<S39>/Send Data'

        // MATLABSystem: '<S43>/Serial Transmit'
        Pix_FCC_flash_B.u0[0] = 0.0F;

        // End of Outputs for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 
      }

      // End of MATLAB Function: '<S39>/MessageAssembly'

      // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S39>/Send WhiteNoise Beginning'

      Pix_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p,
        &Pix_FCC_flash_P.SendWhiteNoiseBeginning_p);

      // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S39>/Send Header'

      Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendHeader_k,
        &Pix_FCC_flash_P.SendHeader_k);

      // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S39>/Send Data'

      // Outputs for Function Call SubSystem: '<S2>/ACTION'
      // MATLABSystem: '<S43>/Serial Transmit' incorporates:
      //   DataTypeConversion: '<S18>/Data Type Conversion'
      //   Inport: '<S18>/SensorData'
      //   Inport: '<S18>/TestSignal'
      //   SignalConversion generated from: '<S18>/SensorACC'
      //   SignalConversion generated from: '<S18>/SensorROT'
      //   SignalConversion generated from: '<S43>/Serial Transmit'

      Pix_FCC_flash_B.u0[1] = static_cast<real32_T>(Pix_FCC_flash_B.Add);
      Pix_FCC_flash_B.u0[2] = static_cast<real32_T>(Pix_FCC_flash_B.Add1);
      Pix_FCC_flash_B.u0[3] = static_cast<real32_T>(Pix_FCC_flash_B.Add2);
      Pix_FCC_flash_B.u0[4] = static_cast<real32_T>(Pix_FCC_flash_B.Add3);
      Pix_FCC_flash_B.u0[5] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[0];
      Pix_FCC_flash_B.u0[8] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[3];
      Pix_FCC_flash_B.u0[6] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[1];
      Pix_FCC_flash_B.u0[9] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[4];
      Pix_FCC_flash_B.u0[7] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[2];
      Pix_FCC_flash_B.u0[10] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[5];
      Pix_FCC_flash_B.u0[11] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[6];
      Pix_FCC_flash_B.u0[12] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[7];
      Pix_FCC_flash_B.u0[13] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[8];
      Pix_FCC_flash_B.u0[14] = Pix_FCC_flash_B.TmpRTBAtExecutionCycleInpor[9];
      Pix_FCC_flash_B.u0[15] = Pix_FCC_flash_B.TestSignal_update;

      // End of Outputs for SubSystem: '<S2>/ACTION'
      memcpy((void *)&Pix_FCC_flash_B.TxDataLocChar[0], (void *)
             &Pix_FCC_flash_B.u0[0], (uint32_T)((size_t)64 * sizeof(uint8_T)));
      MW_SCI_Transmit(Pix_FCC_flash_DW.obj_h.MW_SCIHANDLE,
                      Pix_FCC_flash_B.TxDataLocChar, 64U);

      // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S39>/Send Terminator'

      Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendTerminator_g,
        &Pix_FCC_flash_P.SendTerminator_g);

      // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S39>/Send WhiteNoise End'

      Pix_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a,
        &Pix_FCC_flash_P.SendWhiteNoiseEnd_a);

      // End of Outputs for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 
    }

    // End of RelationalOperator: '<S36>/Compare'
    // End of Outputs for SubSystem: '<S19>/serial send'

    // Sum: '<S40>/FixPt Sum1' incorporates:
    //   Constant: '<S40>/FixPt Constant'
    //   UnitDelay: '<S37>/Output'

    Pix_FCC_flash_DW.Output_DSTATE_o = static_cast<uint8_T>
      ((static_cast<uint32_T>(Pix_FCC_flash_DW.Output_DSTATE_o) +
        Pix_FCC_flash_P.FixPtConstant_Value_m));

    // Switch: '<S41>/FixPt Switch' incorporates:
    //   Constant: '<S41>/Constant'
    //   UnitDelay: '<S37>/Output'

    if (Pix_FCC_flash_DW.Output_DSTATE_o >
        Pix_FCC_flash_P.CounterLimited_uplimit) {
      Pix_FCC_flash_DW.Output_DSTATE_o = Pix_FCC_flash_P.Constant_Value_b;
    }

    // End of Switch: '<S41>/FixPt Switch'
    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  }

  // End of Outputs for SubSystem: '<Root>/ExecutionCycle'
}

// Model step wrapper function for compatibility with a static main program
void Pix_FCC_flash_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Pix_FCC_flash_step0();
    break;

   case 1 :
    Pix_FCC_flash_step1();
    break;

   case 2 :
    Pix_FCC_flash_step2();
    break;

   default :
    break;
  }
}

// Model initialize function
void Pix_FCC_flash_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // block I/O
  (void) memset((static_cast<void *>(&Pix_FCC_flash_B)), 0,
                sizeof(B_Pix_FCC_flash_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&Pix_FCC_flash_DW), 0,
                sizeof(DW_Pix_FCC_flash_T));

  {
    int32_T i;

    // Start for MATLABSystem: '<S58>/SourceBlock'
    Pix_FCC_flash_DW.obj_d.matlabCodegenIsDeleted = false;
    Pix_FCC_flash_DW.obj_d.isSetupComplete = false;
    Pix_FCC_flash_DW.obj_d.isInitialized = 1;
    Pix_FCC_flash_DW.obj_d.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(Pix_FCC_flash_DW.obj_d.orbMetadataObj,
                         &Pix_FCC_flash_DW.obj_d.eventStructObj);
    Pix_FCC_flash_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S60>/SourceBlock'
    Pix_FCC_flash_DW.obj_f.matlabCodegenIsDeleted = false;
    Pix_FCC_flash_DW.obj_f.isSetupComplete = false;
    Pix_FCC_flash_DW.obj_f.isInitialized = 1;
    Pix_FCC_flash_DW.obj_f.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(Pix_FCC_flash_DW.obj_f.orbMetadataObj,
                         &Pix_FCC_flash_DW.obj_f.eventStructObj);
    Pix_FCC_flash_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S62>/SourceBlock'
    Pix_FCC_flash_DW.obj_c.matlabCodegenIsDeleted = false;
    Pix_FCC_flash_DW.obj_c.isSetupComplete = false;
    Pix_FCC_flash_DW.obj_c.isInitialized = 1;
    Pix_FCC_flash_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(Pix_FCC_flash_DW.obj_c.orbMetadataObj,
                         &Pix_FCC_flash_DW.obj_c.eventStructObj);
    Pix_FCC_flash_DW.obj_c.isSetupComplete = true;

    // Start for Enabled SubSystem: '<Root>/ExecutionCycle'
    // Start for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/OUTPUT'

    // Start for MATLABSystem: '<S38>/PX4 PWM Output' incorporates:
    //   Constant: '<S19>/PWM_arm_flg'

    Pix_FCC_flash_DW.obj_j.errorStatus = 0U;
    Pix_FCC_flash_DW.obj_j.isInitialized = 0;
    Pix_FCC_flash_DW.obj_j.matlabCodegenIsDeleted = false;
    Pix_FCC_f_SystemCore_setup_b2qa(&Pix_FCC_flash_DW.obj_j,
      Pix_FCC_flash_P.PWM_arm_flg_Value, Pix_FCC_flash_P.PWM_arm_flg_Value);

    // Start for Enabled SubSystem: '<S19>/serial send'
    // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send WhiteNoise Beginning'

    SendWhiteNoiseBeginni_Start(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p);

    // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send Header'

    Pix_FCC_fl_SendHeader_Start(&Pix_FCC_flash_DW.SendHeader_k);

    // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send Data'

    // Start for MATLABSystem: '<S43>/Serial Transmit'
    Pix_FCC_flash_DW.obj_h.isInitialized = 0;
    Pix_FCC_flash_DW.obj_h.matlabCodegenIsDeleted = false;
    Pix_FCC_fla_SystemCore_setup_b2(&Pix_FCC_flash_DW.obj_h);

    // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send Terminator'

    Pix_FCC_fl_SendHeader_Start(&Pix_FCC_flash_DW.SendTerminator_g);

    // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send WhiteNoise End'

    SendWhiteNoiseBeginni_Start(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a);

    // End of Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 
    // End of Start for SubSystem: '<S19>/serial send'
    // End of Start for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
    // End of Start for SubSystem: '<Root>/ExecutionCycle'

    // Start for MATLABSystem: '<Root>/Receive Data'
    Pix_FCC_flash_DW.obj.isInitialized = 0;
    Pix_FCC_flash_DW.obj.matlabCodegenIsDeleted = false;
    Pix_FCC_flash_DW.obj.SampleTime = Pix_FCC_flash_P.ReceiveData_SampleTime;
    Pix_FCC_flas_SystemCore_setup_b(&Pix_FCC_flash_DW.obj);

    // Start for Enabled SubSystem: '<S1>/DecodeCommand'
    // Start for Enabled SubSystem: '<S6>/ConfirmCommand'
    // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S9>/Send WhiteNoise Beginning'

    SendWhiteNoiseBeginni_Start(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning);

    // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S9>/Send Header'

    Pix_FCC_fl_SendHeader_Start(&Pix_FCC_flash_DW.SendHeader);

    // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S9>/Send RC Confrimation'

    // Start for MATLABSystem: '<S13>/Serial Transmit'
    Pix_FCC_flash_DW.obj_k.isInitialized = 0;
    Pix_FCC_flash_DW.obj_k.matlabCodegenIsDeleted = false;
    Pix_FCC_fla_SystemCore_setup_b2(&Pix_FCC_flash_DW.obj_k);

    // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S9>/Send Data'

    // Start for MATLABSystem: '<S11>/Serial Transmit'
    Pix_FCC_flash_DW.obj_b.isInitialized = 0;
    Pix_FCC_flash_DW.obj_b.matlabCodegenIsDeleted = false;
    Pix_FCC_fla_SystemCore_setup_b2(&Pix_FCC_flash_DW.obj_b);

    // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S9>/Send Terminator'

    Pix_FCC_fl_SendHeader_Start(&Pix_FCC_flash_DW.SendTerminator);

    // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S9>/Send WhiteNoise End'

    SendWhiteNoiseBeginni_Start(&Pix_FCC_flash_DW.SendWhiteNoiseEnd);

    // End of Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' 
    // End of Start for SubSystem: '<S6>/ConfirmCommand'
    // End of Start for SubSystem: '<S1>/DecodeCommand'

    // InitializeConditions for RateTransition generated from: '<Root>/ExecutionCycle' 
    for (i = 0; i < 10; i++) {
      Pix_FCC_flash_DW.TmpRTBAtExecutionCycleInport6_B[i] =
        Pix_FCC_flash_P.TmpRTBAtExecutionCycleInport6_I;
    }

    // End of InitializeConditions for RateTransition generated from: '<Root>/ExecutionCycle' 

    // SystemInitialize for Enabled SubSystem: '<Root>/ExecutionCycle'
    // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/heartbeat'

    // InitializeConditions for UnitDelay: '<S48>/Output'
    Pix_FCC_flash_DW.Output_DSTATE = Pix_FCC_flash_P.Output_InitialCondition;

    // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/process_received_data'

    // SystemInitialize for Enabled SubSystem: '<S21>/input_hold'
    // SystemInitialize for Enabled SubSystem: '<S51>/hold'
    // SystemInitialize for Outport: '<S54>/CMD'
    Pix_FCC_flash_B.CMD_update[0] = Pix_FCC_flash_P.CMD_Y0;

    // SystemInitialize for Outport: '<S54>/ACC'
    Pix_FCC_flash_B.ACC_update[0] = Pix_FCC_flash_P.ACC_Y0;

    // SystemInitialize for Outport: '<S54>/ROT'
    Pix_FCC_flash_B.ROT_update[0] = Pix_FCC_flash_P.ROT_Y0;

    // SystemInitialize for Outport: '<S54>/ATT'
    Pix_FCC_flash_B.ATT_update[0] = Pix_FCC_flash_P.ATT_Y0;

    // SystemInitialize for Outport: '<S54>/CMD'
    Pix_FCC_flash_B.CMD_update[1] = Pix_FCC_flash_P.CMD_Y0;

    // SystemInitialize for Outport: '<S54>/ACC'
    Pix_FCC_flash_B.ACC_update[1] = Pix_FCC_flash_P.ACC_Y0;

    // SystemInitialize for Outport: '<S54>/ROT'
    Pix_FCC_flash_B.ROT_update[1] = Pix_FCC_flash_P.ROT_Y0;

    // SystemInitialize for Outport: '<S54>/ATT'
    Pix_FCC_flash_B.ATT_update[1] = Pix_FCC_flash_P.ATT_Y0;

    // SystemInitialize for Outport: '<S54>/CMD'
    Pix_FCC_flash_B.CMD_update[2] = Pix_FCC_flash_P.CMD_Y0;

    // SystemInitialize for Outport: '<S54>/ACC'
    Pix_FCC_flash_B.ACC_update[2] = Pix_FCC_flash_P.ACC_Y0;

    // SystemInitialize for Outport: '<S54>/ROT'
    Pix_FCC_flash_B.ROT_update[2] = Pix_FCC_flash_P.ROT_Y0;

    // SystemInitialize for Outport: '<S54>/ATT'
    Pix_FCC_flash_B.ATT_update[2] = Pix_FCC_flash_P.ATT_Y0;

    // SystemInitialize for Outport: '<S54>/TestSignal'
    Pix_FCC_flash_B.TestSignal_update = Pix_FCC_flash_P.TestSignal_Y0;

    // End of SystemInitialize for SubSystem: '<S51>/hold'

    // SystemInitialize for Outport: '<S51>/packetfound_flg'
    Pix_FCC_flash_B.packetfound = Pix_FCC_flash_P.packetfound_flg_Y0;

    // End of SystemInitialize for SubSystem: '<S21>/input_hold'

    // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' 
    Pix_FCC_flash_DW.DiscreteTransferFcn_states =
      Pix_FCC_flash_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' 
    Pix_FCC_flash_DW.DiscreteTransferFcn1_states =
      Pix_FCC_flash_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' 
    Pix_FCC_flash_DW.DiscreteTransferFcn2_states =
      Pix_FCC_flash_P.DiscreteTransferFcn2_InitialSta;

    // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/OUTPUT'

    // InitializeConditions for UnitDelay: '<S37>/Output'
    Pix_FCC_flash_DW.Output_DSTATE_o = Pix_FCC_flash_P.Output_InitialCondition_n;

    // End of SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
    // End of SystemInitialize for SubSystem: '<Root>/ExecutionCycle'

    // SystemInitialize for Enabled SubSystem: '<S1>/DecodeCommand'
    // SystemInitialize for Outport: '<S6>/cmd_found_flg'
    Pix_FCC_flash_B.cmd_found_flg = Pix_FCC_flash_P.cmd_found_flg_Y0;

    // SystemInitialize for Outport: '<S6>/cmd'
    Pix_FCC_flash_DW.SFunction_DIMS2_f[0] = 0;

    // End of SystemInitialize for SubSystem: '<S1>/DecodeCommand'

    // SystemInitialize for Enabled SubSystem: '<S1>/memory'
    // SystemInitialize for Outport: '<S8>/standing_cmd'
    Pix_FCC_flash_DW.update_DIMS1[0] = 0;

    // End of SystemInitialize for SubSystem: '<S1>/memory'

    // SystemInitialize for Enabled SubSystem: '<S1>/DecodeCommand'
    // SystemInitialize for Outport: '<S6>/cmd'
    Pix_FCC_flash_DW.SFunction_DIMS2_f[1] = 0;

    // End of SystemInitialize for SubSystem: '<S1>/DecodeCommand'

    // SystemInitialize for Enabled SubSystem: '<S1>/memory'
    // SystemInitialize for Outport: '<S8>/standing_cmd'
    Pix_FCC_flash_DW.update_DIMS1[1] = 0;

    // End of SystemInitialize for SubSystem: '<S1>/memory'

    // SystemInitialize for Enabled SubSystem: '<S58>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S59>/Out1'
    Pix_FCC_flash_B.In1_j = Pix_FCC_flash_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S58>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S60>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S61>/Out1'
    Pix_FCC_flash_B.In1 = Pix_FCC_flash_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S60>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S62>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S63>/Out1'
    Pix_FCC_flash_B.In1_c = Pix_FCC_flash_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S62>/Enabled Subsystem'
  }
}

// Model terminate function
void Pix_FCC_flash_terminate(void)
{
  // Terminate for MATLABSystem: '<S58>/SourceBlock'
  matlabCodegenHandle_matl_b2qa4v(&Pix_FCC_flash_DW.obj_d);

  // Terminate for MATLABSystem: '<S60>/SourceBlock'
  matlabCodegenHandle_matl_b2qa4v(&Pix_FCC_flash_DW.obj_f);

  // Terminate for MATLABSystem: '<S62>/SourceBlock'
  matlabCodegenHandle_matl_b2qa4v(&Pix_FCC_flash_DW.obj_c);

  // Terminate for Enabled SubSystem: '<Root>/ExecutionCycle'
  // Terminate for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
  //   SubSystem: '<S2>/OUTPUT'

  // Terminate for MATLABSystem: '<S38>/PX4 PWM Output'
  matlabCodegenHandle_matlab_b2qa(&Pix_FCC_flash_DW.obj_j);

  // Terminate for Enabled SubSystem: '<S19>/serial send'
  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send WhiteNoise Beginning'

  SendWhiteNoiseBeginnin_Term(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Header'

  Pix_FCC_fla_SendHeader_Term(&Pix_FCC_flash_DW.SendHeader_k);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Data'

  // Terminate for MATLABSystem: '<S43>/Serial Transmit'
  matlabCodegenHandle_matlabCo_b2(&Pix_FCC_flash_DW.obj_h);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Terminator'

  Pix_FCC_fla_SendHeader_Term(&Pix_FCC_flash_DW.SendTerminator_g);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send WhiteNoise End'

  SendWhiteNoiseBeginnin_Term(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a);

  // End of Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 
  // End of Terminate for SubSystem: '<S19>/serial send'
  // End of Terminate for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  // End of Terminate for SubSystem: '<Root>/ExecutionCycle'

  // Terminate for MATLABSystem: '<Root>/Receive Data'
  matlabCodegenHandle_matlabCod_b(&Pix_FCC_flash_DW.obj);

  // Terminate for Enabled SubSystem: '<S1>/DecodeCommand'
  // Terminate for Enabled SubSystem: '<S6>/ConfirmCommand'
  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send WhiteNoise Beginning'

  SendWhiteNoiseBeginnin_Term(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send Header'

  Pix_FCC_fla_SendHeader_Term(&Pix_FCC_flash_DW.SendHeader);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send RC Confrimation'

  // Terminate for MATLABSystem: '<S13>/Serial Transmit'
  matlabCodegenHandle_matlabCo_b2(&Pix_FCC_flash_DW.obj_k);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send Data'

  // Terminate for MATLABSystem: '<S11>/Serial Transmit'
  matlabCodegenHandle_matlabCo_b2(&Pix_FCC_flash_DW.obj_b);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send Terminator'

  Pix_FCC_fla_SendHeader_Term(&Pix_FCC_flash_DW.SendTerminator);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send WhiteNoise End'

  SendWhiteNoiseBeginnin_Term(&Pix_FCC_flash_DW.SendWhiteNoiseEnd);

  // End of Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' 
  // End of Terminate for SubSystem: '<S6>/ConfirmCommand'
  // End of Terminate for SubSystem: '<S1>/DecodeCommand'
}

//
// File trailer for generated code.
//
// [EOF]
//

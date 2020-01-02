//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash.cpp
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.333
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Jan  2 22:43:22 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Pix_FCC_flash.h"
#include "Pix_FCC_flash_private.h"
#include "Pix_FCC_flash_dt.h"

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
static void Pix_FCC_fl_SystemCore_release_b(const
  px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_fla_SystemCore_delete_b(const
  px4_internal_block_PX4SCIRead_T *obj);
static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_f_SystemCore_release_b2(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fl_SystemCore_delete_b2(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void matlabCodegenHandle_matlabCo_b2(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_F_SystemCore_release_b2qa4v(const
  px4_internal_block_Subscriber_T *obj);
static void Pix_FC_SystemCore_delete_b2qa4v(const
  px4_internal_block_Subscriber_T *obj);
static void matlabCodegenHandle_matl_b2qa4v(px4_internal_block_Subscriber_T *obj);
static void Pix_FCC_SystemCore_release_b2qa(px4_internal_block_PWM_Pix_FC_T *obj);
static void Pix_FCC__SystemCore_delete_b2qa(px4_internal_block_PWM_Pix_FC_T *obj);
static void matlabCodegenHandle_matlab_b2qa(px4_internal_block_PWM_Pix_FC_T *obj);
static void Pix_FCC_flas_SystemCore_setup_b(px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_fla_SystemCore_setup_b2(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_f_SystemCore_setup_b2qa(px4_internal_block_PWM_Pix_FC_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
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
void P_SendWhiteNoiseBeginning_Start(DW_SendWhiteNoiseBeginning_Pi_T *localDW)
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
void Pix_FCC_SendWhiteNoiseBeginning(DW_SendWhiteNoiseBeginning_Pi_T *localDW,
  P_SendWhiteNoiseBeginning_Pix_T *localP)
{
  uint8_T TxDataLocChar[5];

  // MATLABSystem: '<S15>/Serial Transmit' incorporates:
  //   Constant: '<S15>/Header'

  memcpy((void *)&TxDataLocChar[0], (void *)&localP->Header_Value[0], (uint32_T)
         ((size_t)5 * sizeof(uint8_T)));
  MW_SCI_Transmit(localDW->obj.MW_SCIHANDLE, TxDataLocChar, 5U);
  localDW->SendWhiteNoiseBeginning_SubsysR = 4;
}

//
// Termination for function-call system:
//    '<S9>/Send WhiteNoise Beginning'
//    '<S9>/Send WhiteNoise End'
//    '<S39>/Send WhiteNoise Beginning'
//    '<S39>/Send WhiteNoise End'
//
void Pi_SendWhiteNoiseBeginning_Term(DW_SendWhiteNoiseBeginning_Pi_T *localDW)
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
void Pix_FCC_flash_SendHeader_Start(DW_SendHeader_Pix_FCC_flash_T *localDW)
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
  localDW->SendHeader_SubsysRanBC = 4;
}

//
// Termination for function-call system:
//    '<S9>/Send Header'
//    '<S9>/Send Terminator'
//    '<S39>/Send Header'
//    '<S39>/Send Terminator'
//
void Pix_FCC_flash_SendHeader_Term(DW_SendHeader_Pix_FCC_flash_T *localDW)
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

static void Pix_FCC_fla_SystemCore_setup_b2(px4_internal_block_PX4SCIWrit_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '6' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pix_FCC_flash_B.RxPinLoc_p = MW_UNDEFINED_VALUE;
  Pix_FCC_flash_B.TxPinLoc_c = MW_UNDEFINED_VALUE;
  for (i = 0; i < 10; i++) {
    Pix_FCC_flash_B.SCIModuleLoc_b[i] = tmp[i];
  }

  Pix_FCC_flash_B.SCIModuleLoc_b[10] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(Pix_FCC_flash_B.SCIModuleLoc_b, true,
    Pix_FCC_flash_B.RxPinLoc_p, Pix_FCC_flash_B.TxPinLoc_c);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  Pix_FCC_flash_B.StopBitsValue_f = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        Pix_FCC_flash_B.StopBitsValue_f);
  obj->isSetupComplete = true;
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

// Model step function
void Pix_FCC_flash_step(void)
{
  uint8_T sizeptr;
  real32_T ACC3;
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
  boolean_T rtb_Compare;
  int32_T rtb_enable_execution;
  int32_T loop_ub;
  boolean_T exitg1;

  // Reset subsysRan breadcrumbs
  srClearBC
    (Pix_FCC_flash_DW.SendWhiteNoiseBeginning.SendWhiteNoiseBeginning_SubsysR);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.SendHeader.SendHeader_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.SendRCConfrimation_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.SendData_SubsysRanBC_b);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.ConfirmCommand_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.DecodeCommand_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.memory_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.heartbeat_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.hold_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.input_hold_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.process_received_data_SubsysRan);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.Pass_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.Saturate_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.ACTION_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.SendData_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.OUTPUT_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.ExecutionCycle_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_o);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_a);

  // Reset subsysRan breadcrumbs
  srClearBC(Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<Root>/Receive Data'
  if (Pix_FCC_flash_DW.obj.SampleTime != Pix_FCC_flash_P.ReceiveData_SampleTime)
  {
    Pix_FCC_flash_DW.obj.SampleTime = Pix_FCC_flash_P.ReceiveData_SampleTime;
  }

  MW_SCI_GetDataBytesAvailable(Pix_FCC_flash_DW.obj.MW_SCIHANDLE, false,
    &sizeptr, 5);
  if (sizeptr >= 128U) {
    MW_SCI_Receive(Pix_FCC_flash_DW.obj.MW_SCIHANDLE,
                   Pix_FCC_flash_B.RxDataLocChar, 128U);
    memcpy((void *)&Pix_FCC_flash_B.ReceiveData_o1[0], (void *)
           &Pix_FCC_flash_B.RxDataLocChar[0], (uint32_T)((size_t)128 * sizeof
            (uint8_T)));
    sizeptr = 0U;
  } else {
    memset(&Pix_FCC_flash_B.ReceiveData_o1[0], 0, sizeof(uint8_T) << 7U);
    sizeptr = 1U;
  }

  // Outputs for Enabled SubSystem: '<S1>/DecodeCommand' incorporates:
  //   EnablePort: '<S6>/Enable'

  // Logic: '<S1>/NOT' incorporates:
  //   MATLAB Function: '<S6>/DecodeCommand'
  //   MATLABSystem: '<Root>/Receive Data'

  if (sizeptr == 0) {
    Pix_FCC_flash_DW.DecodeCommand_MODE = true;

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
        (Pix_FCC_flash_B.ReceiveData_o1[Pix_FCC_flash_B.b_ii] == 8);
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

    Pix_FCC_flash_B.start_size_n[0] = 1;
    Pix_FCC_flash_B.start_size_n[1] = Pix_FCC_flash_B.idx;
    for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < Pix_FCC_flash_B.idx;
         Pix_FCC_flash_B.b_ii++) {
      Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
        ((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] + 2.0) - 1.0 > 128.0);
    }

    Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data,
      Pix_FCC_flash_B.start_size, Pix_FCC_flash_B.x,
      Pix_FCC_flash_B.start_size_n);
    Pix_FCC_flash_B.tmp_size_m[0] = 1;
    Pix_FCC_flash_B.tmp_size_m[1] = Pix_FCC_flash_B.start_size[1];
    loop_ub = Pix_FCC_flash_B.start_size[0] * Pix_FCC_flash_B.start_size[1];
    for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < loop_ub;
         Pix_FCC_flash_B.b_ii++) {
      Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] = (Pix_FCC_flash_B.ReceiveData_o1[
        static_cast<int32_T>(((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii]
        + 2.0) - 1.0)) - 1] != 8);
    }

    Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data,
      Pix_FCC_flash_B.start_size, Pix_FCC_flash_B.x, Pix_FCC_flash_B.tmp_size_m);
    if (Pix_FCC_flash_B.start_size[1] != 0) {
      Pix_FCC_flash_B.b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (Pix_FCC_flash_B.b_ii <= Pix_FCC_flash_B.start_size[1]
                           - 2)) {
        rtb_Compare = false;
        Pix_FCC_flash_B.Add = Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii +
          1];
        if (Pix_FCC_flash_B.Add -
            Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] == 6.0) {
          rtb_Compare = true;
        }

        if (rtb_Compare) {
          if (Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] + 2.0 >
              Pix_FCC_flash_B.Add - 1.0) {
            Pix_FCC_flash_B.idx = 0;
            rtb_enable_execution = 0;
          } else {
            Pix_FCC_flash_B.idx = static_cast<int32_T>
              ((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii] + 2.0)) - 1;
            rtb_enable_execution = static_cast<int32_T>
              ((Pix_FCC_flash_B.start_data[Pix_FCC_flash_B.b_ii + 1] - 1.0));
          }

          rtb_enable_execution -= Pix_FCC_flash_B.idx;
          for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <
               rtb_enable_execution; Pix_FCC_flash_B.b_ii++) {
            Pix_FCC_flash_B.packet_data[Pix_FCC_flash_B.b_ii] =
              Pix_FCC_flash_B.ReceiveData_o1[Pix_FCC_flash_B.idx +
              Pix_FCC_flash_B.b_ii];
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
      if (!Pix_FCC_flash_DW.ConfirmCommand_MODE) {
        // Enable for Sin: '<S9>/Sine Wave'
        Pix_FCC_flash_DW.systemEnable = 1;
        Pix_FCC_flash_DW.ConfirmCommand_MODE = true;
      }

      // MATLAB Function: '<S9>/pack'
      Pix_FCC_flash_B.pack[0] = Pix_FCC_flash_B.cmd[0];
      Pix_FCC_flash_B.pack[1] = Pix_FCC_flash_B.cmd[1];
      Pix_FCC_flash_B.pack[2] = Pix_FCC_flash_B.cmd[2];
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.cmd[3];
      memcpy((void *)&Pix_FCC_flash_B.CMD1, (void *)&Pix_FCC_flash_B.pack[0],
             (uint32_T)((size_t)1 * sizeof(real32_T)));

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send WhiteNoise Beginning'

      Pix_FCC_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning,
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
      Pix_FCC_flash_DW.SendRCConfrimation_SubsysRanBC = 4;

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send Data'

      // MATLABSystem: '<S11>/Serial Transmit' incorporates:
      //   MATLAB Function: '<S9>/pack'

      memcpy((void *)&Pix_FCC_flash_B.pack[0], (void *)&Pix_FCC_flash_B.CMD1,
             (uint32_T)((size_t)4 * sizeof(uint8_T)));
      MW_SCI_Transmit(Pix_FCC_flash_DW.obj_b.MW_SCIHANDLE, Pix_FCC_flash_B.pack,
                      4U);
      Pix_FCC_flash_DW.SendData_SubsysRanBC_b = 4;

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send Terminator'

      Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendTerminator,
        &Pix_FCC_flash_P.SendTerminator);

      // S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S9>/Send WhiteNoise End'

      Pix_FCC_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseEnd,
        &Pix_FCC_flash_P.SendWhiteNoiseEnd);

      // End of Outputs for S-Function (fcncallgen): '<S9>/Function-Call Generator1' 

      // Sin: '<S9>/Sine Wave'
      if (Pix_FCC_flash_DW.systemEnable != 0) {
        Pix_FCC_flash_B.Add = Pix_FCC_flash_P.SineWave_Freq *
          Pix_FCC_flash_M->Timing.taskTime0;
        Pix_FCC_flash_DW.lastSin = sin(Pix_FCC_flash_B.Add);
        Pix_FCC_flash_DW.lastCos = cos(Pix_FCC_flash_B.Add);
        Pix_FCC_flash_DW.systemEnable = 0;
      }

      Pix_FCC_flash_B.SineWave_j = ((Pix_FCC_flash_DW.lastSin *
        Pix_FCC_flash_P.SineWave_PCos + Pix_FCC_flash_DW.lastCos *
        Pix_FCC_flash_P.SineWave_PSin) * Pix_FCC_flash_P.SineWave_HCos +
        (Pix_FCC_flash_DW.lastCos * Pix_FCC_flash_P.SineWave_PCos -
         Pix_FCC_flash_DW.lastSin * Pix_FCC_flash_P.SineWave_PSin) *
        Pix_FCC_flash_P.SineWave_Hsin) * Pix_FCC_flash_P.SineWave_Amp +
        Pix_FCC_flash_P.SineWave_Bias;

      // End of Sin: '<S9>/Sine Wave'
      // Update for Sin: '<S9>/Sine Wave'
      Pix_FCC_flash_B.Add = Pix_FCC_flash_DW.lastSin;
      Pix_FCC_flash_DW.lastSin = Pix_FCC_flash_DW.lastSin *
        Pix_FCC_flash_P.SineWave_HCos + Pix_FCC_flash_DW.lastCos *
        Pix_FCC_flash_P.SineWave_Hsin;
      Pix_FCC_flash_DW.lastCos = Pix_FCC_flash_DW.lastCos *
        Pix_FCC_flash_P.SineWave_HCos - Pix_FCC_flash_B.Add *
        Pix_FCC_flash_P.SineWave_Hsin;
      srUpdateBC(Pix_FCC_flash_DW.ConfirmCommand_SubsysRanBC);
    } else {
      Pix_FCC_flash_DW.ConfirmCommand_MODE = false;
    }

    // End of Outputs for SubSystem: '<S6>/ConfirmCommand'
    srUpdateBC(Pix_FCC_flash_DW.DecodeCommand_SubsysRanBC);
  } else {
    if (Pix_FCC_flash_DW.DecodeCommand_MODE) {
      // Disable for Enabled SubSystem: '<S6>/ConfirmCommand'
      Pix_FCC_flash_DW.ConfirmCommand_MODE = false;

      // End of Disable for SubSystem: '<S6>/ConfirmCommand'
      Pix_FCC_flash_DW.DecodeCommand_MODE = false;
    }
  }

  // End of Logic: '<S1>/NOT'
  // End of Outputs for SubSystem: '<S1>/DecodeCommand'

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
    srUpdateBC(Pix_FCC_flash_DW.memory_SubsysRanBC);
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

  // MATLABSystem: '<S59>/SourceBlock' incorporates:
  //   Inport: '<S60>/In1'

  rtb_Compare = uORB_read_step(Pix_FCC_flash_DW.obj_d.orbMetadataObj,
    &Pix_FCC_flash_DW.obj_d.eventStructObj, &Pix_FCC_flash_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S59>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S60>/Enable'

  if (rtb_Compare) {
    Pix_FCC_flash_B.In1_j = Pix_FCC_flash_B.b_varargout_2;
    srUpdateBC(Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_o);
  }

  // End of MATLABSystem: '<S59>/SourceBlock'
  // End of Outputs for SubSystem: '<S59>/Enabled Subsystem'

  // MATLABSystem: '<S61>/SourceBlock' incorporates:
  //   Inport: '<S62>/In1'

  rtb_Compare = uORB_read_step(Pix_FCC_flash_DW.obj_f.orbMetadataObj,
    &Pix_FCC_flash_DW.obj_f.eventStructObj, &Pix_FCC_flash_B.b_varargout_2_k,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S61>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S62>/Enable'

  if (rtb_Compare) {
    Pix_FCC_flash_B.In1 = Pix_FCC_flash_B.b_varargout_2_k;
    srUpdateBC(Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_a);
  }

  // End of MATLABSystem: '<S61>/SourceBlock'
  // End of Outputs for SubSystem: '<S61>/Enabled Subsystem'

  // MATLABSystem: '<S63>/SourceBlock' incorporates:
  //   Inport: '<S64>/In1'

  rtb_Compare = uORB_read_step(Pix_FCC_flash_DW.obj_c.orbMetadataObj,
    &Pix_FCC_flash_DW.obj_c.eventStructObj, &Pix_FCC_flash_B.b_varargout_2_c,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S63>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S64>/Enable'

  if (rtb_Compare) {
    Pix_FCC_flash_B.In1_c = Pix_FCC_flash_B.b_varargout_2_c;
    srUpdateBC(Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S63>/SourceBlock'
  // End of Outputs for SubSystem: '<S63>/Enabled Subsystem'

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

  // Outputs for Enabled SubSystem: '<Root>/ExecutionCycle' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (rtb_enable_execution > 0) {
    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/process_received_data'

    // Outputs for Enabled SubSystem: '<S21>/input_hold' incorporates:
    //   EnablePort: '<S52>/Enable'

    // Logic: '<S2>/NOT' incorporates:
    //   Inport: '<S55>/ACC_update'
    //   Inport: '<S55>/ATT_update'
    //   Inport: '<S55>/CMD_update'
    //   Inport: '<S55>/ROT_update'
    //   Inport: '<S55>/SimHeartbeat_update'
    //   Inport: '<S55>/TestSignal_update'
    //   MATLAB Function: '<S52>/ByteUnpack'
    //   MATLAB Function: '<S52>/ExtractMessage'
    //   MATLABSystem: '<Root>/Receive Data'

    if (sizeptr == 0) {
      // MATLAB Function: '<S52>/ExtractMessage'
      rtb_enable_execution = 56;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < 56;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.packet_data_c[Pix_FCC_flash_B.b_ii] = 0U;
      }

      Pix_FCC_flash_B.packetfound = false;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < 128;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
          (Pix_FCC_flash_B.ReceiveData_o1[Pix_FCC_flash_B.b_ii] == 7);
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

      Pix_FCC_flash_B.start_size_g[0] = 1;
      Pix_FCC_flash_B.start_size_g[1] = Pix_FCC_flash_B.idx;
      loop_ub = Pix_FCC_flash_B.idx - 1;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <= loop_ub;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] =
          Pix_FCC_flash_B.RxDataLocChar[Pix_FCC_flash_B.b_ii];
      }

      Pix_FCC_flash_B.start_size_g1[0] = 1;
      Pix_FCC_flash_B.start_size_g1[1] = Pix_FCC_flash_B.idx;
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < Pix_FCC_flash_B.idx;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
          ((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0) - 1.0 >
           128.0);
      }

      Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data_m,
        Pix_FCC_flash_B.start_size_g, Pix_FCC_flash_B.x,
        Pix_FCC_flash_B.start_size_g1);
      Pix_FCC_flash_B.tmp_size[0] = 1;
      Pix_FCC_flash_B.tmp_size[1] = Pix_FCC_flash_B.start_size_g[1];
      loop_ub = Pix_FCC_flash_B.start_size_g[0] * Pix_FCC_flash_B.start_size_g[1];
      for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii < loop_ub;
           Pix_FCC_flash_B.b_ii++) {
        Pix_FCC_flash_B.x[Pix_FCC_flash_B.b_ii] =
          (Pix_FCC_flash_B.ReceiveData_o1[static_cast<int32_T>
           (((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0) - 1.0))
           - 1] != 7);
      }

      Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data_m,
        Pix_FCC_flash_B.start_size_g, Pix_FCC_flash_B.x,
        Pix_FCC_flash_B.tmp_size);
      if (Pix_FCC_flash_B.start_size_g[1] != 0) {
        Pix_FCC_flash_B.b_ii = 0;
        exitg1 = false;
        while ((!exitg1) && (Pix_FCC_flash_B.b_ii <=
                             Pix_FCC_flash_B.start_size_g[1] - 2)) {
          rtb_Compare = false;
          Pix_FCC_flash_B.Add =
            Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii + 1];
          if (Pix_FCC_flash_B.Add -
              Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] == 58.0) {
            rtb_Compare = true;
          }

          if (rtb_Compare) {
            if (Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0 >
                Pix_FCC_flash_B.Add - 1.0) {
              Pix_FCC_flash_B.idx = 0;
              rtb_enable_execution = 0;
            } else {
              Pix_FCC_flash_B.idx = static_cast<int32_T>
                ((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii] + 2.0)) - 1;
              rtb_enable_execution = static_cast<int32_T>
                ((Pix_FCC_flash_B.start_data_m[Pix_FCC_flash_B.b_ii + 1] - 1.0));
            }

            rtb_enable_execution -= Pix_FCC_flash_B.idx;
            for (Pix_FCC_flash_B.b_ii = 0; Pix_FCC_flash_B.b_ii <
                 rtb_enable_execution; Pix_FCC_flash_B.b_ii++) {
              Pix_FCC_flash_B.packet_data_c[Pix_FCC_flash_B.b_ii] =
                Pix_FCC_flash_B.ReceiveData_o1[Pix_FCC_flash_B.idx +
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

      // MATLAB Function: '<S52>/ByteUnpack' incorporates:
      //   MATLAB Function: '<S52>/ExtractMessage'

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
      memcpy((void *)&ACC3, (void *)&Pix_FCC_flash_B.pack[0], (uint32_T)((size_t)
              1 * sizeof(real32_T)));
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

      // Outputs for Enabled SubSystem: '<S52>/hold' incorporates:
      //   EnablePort: '<S55>/Enable'

      if (Pix_FCC_flash_B.packetfound) {
        Pix_FCC_flash_B.CMD_update[0] = Pix_FCC_flash_B.CMD1;
        Pix_FCC_flash_B.CMD_update[1] = Pix_FCC_flash_B.CMD2;
        Pix_FCC_flash_B.CMD_update[2] = Pix_FCC_flash_B.CMD3;
        Pix_FCC_flash_B.ACC_update[0] = Pix_FCC_flash_B.ACC1;
        Pix_FCC_flash_B.ACC_update[1] = Pix_FCC_flash_B.ACC2;
        Pix_FCC_flash_B.ACC_update[2] = ACC3;
        Pix_FCC_flash_B.ROT_update[0] = ROT1;
        Pix_FCC_flash_B.ROT_update[1] = ROT2;
        Pix_FCC_flash_B.ROT_update[2] = ROT3;
        Pix_FCC_flash_B.ATT_update[0] = ATT_phi;
        Pix_FCC_flash_B.ATT_update[1] = ATT_theta;
        Pix_FCC_flash_B.ATT_update[2] = ATT_psi;
        Pix_FCC_flash_B.SimHeartbeat_update = status;
        Pix_FCC_flash_B.TestSignal_update = Pix_FCC_flash_B.TestSignal;
        Pix_FCC_flash_DW.hold_SubsysRanBC = 4;
      }

      // End of Outputs for SubSystem: '<S52>/hold'
      Pix_FCC_flash_DW.input_hold_SubsysRanBC = 4;
    }

    // End of Logic: '<S2>/NOT'
    // End of Outputs for SubSystem: '<S21>/input_hold'
    Pix_FCC_flash_DW.process_received_data_SubsysRan = 4;

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // RelationalOperator: '<S22>/Compare' incorporates:
    //   Constant: '<S22>/Constant'

    rtb_Compare = (rtb_mode != Pix_FCC_flash_P.CompareToConstant_const);

    // Switch: '<S18>/Switch' incorporates:
    //   Constant: '<S3>/Constant'
    //   Inport: '<S18>/SensorData'

    if (Pix_FCC_flash_P.Constant_Value_i) {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.ACC_update[1];
    } else {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.In1_j.y;
    }

    // Sum: '<S23>/Sum3'
    Pix_FCC_flash_B.CMD1 = Pix_FCC_flash_B.CMD_update[2] - Pix_FCC_flash_B.CMD2;

    // Switch: '<S18>/Switch1' incorporates:
    //   Inport: '<S18>/SensorData'

    if (rtb_Compare) {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_B.ROT_update[2];
    } else {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_B.In1.z;
    }

    // Gain: '<S23>/Gain2' incorporates:
    //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
    //   Gain: '<S23>/Gain4'
    //   Sum: '<S23>/Sum4'
    //   Sum: '<S23>/Sum6'

    Pix_FCC_flash_B.CMD3 = ((Pix_FCC_flash_P.Gain4_Gain * Pix_FCC_flash_B.CMD1 +
      Pix_FCC_flash_P.DiscreteTransferFcn2_NumCoef *
      Pix_FCC_flash_DW.DiscreteTransferFcn2_states) - Pix_FCC_flash_B.ACC1) *
      Pix_FCC_flash_P.Gain2_Gain;

    // Switch: '<S18>/Switch' incorporates:
    //   Constant: '<S3>/Constant'
    //   Inport: '<S18>/SensorData'

    if (Pix_FCC_flash_P.Constant_Value_i) {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.ACC_update[2];
    } else {
      Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.In1_j.z;
    }

    // Sum: '<S23>/Sum1'
    Pix_FCC_flash_B.CMD2 = Pix_FCC_flash_B.CMD_update[1] - Pix_FCC_flash_B.CMD2;

    // Switch: '<S18>/Switch1' incorporates:
    //   Inport: '<S18>/SensorData'

    if (rtb_Compare) {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_B.ROT_update[1];
    } else {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_B.In1.y;
    }

    // Gain: '<S23>/Gain1' incorporates:
    //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
    //   Gain: '<S23>/Gain3'
    //   Sum: '<S23>/Sum2'
    //   Sum: '<S23>/Sum5'

    Pix_FCC_flash_B.ACC1 = ((Pix_FCC_flash_P.Gain3_Gain * Pix_FCC_flash_B.CMD2 +
      Pix_FCC_flash_P.DiscreteTransferFcn1_NumCoef *
      Pix_FCC_flash_DW.DiscreteTransferFcn1_states) - Pix_FCC_flash_B.ACC1) *
      Pix_FCC_flash_P.Gain1_Gain;

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

    Pix_FCC_flash_B.Add = -cos(Pix_FCC_flash_B.Add) * Pix_FCC_flash_B.CMD3 + sin
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

    Pix_FCC_flash_B.Add1 = -cos(Pix_FCC_flash_B.Add1) * Pix_FCC_flash_B.CMD3 +
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

    Pix_FCC_flash_B.Add2 = -cos(Pix_FCC_flash_B.Add2) * Pix_FCC_flash_B.CMD3 +
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

    Pix_FCC_flash_B.Add3 = -cos(Pix_FCC_flash_B.Add3) * Pix_FCC_flash_B.CMD3 +
      sin(Pix_FCC_flash_B.Add3) * Pix_FCC_flash_B.ACC1;

    // Switch: '<S18>/Switch1' incorporates:
    //   Inport: '<S18>/SensorData'

    if (rtb_Compare) {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_B.ROT_update[0];
    } else {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_B.In1.x;
    }

    // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S23>/Gain'
    //   Sum: '<S23>/Sum'

    Pix_FCC_flash_B.CMD3 = ((Pix_FCC_flash_B.CMD_update[0] -
      Pix_FCC_flash_B.ACC1) * Pix_FCC_flash_P.Gain_Gain -
      Pix_FCC_flash_P.DiscreteTransferFcn_DenCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn_states) /
      Pix_FCC_flash_P.DiscreteTransferFcn_DenCoef[0];
    Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_P.DiscreteTransferFcn_NumCoef[0] *
      Pix_FCC_flash_B.CMD3 + Pix_FCC_flash_P.DiscreteTransferFcn_NumCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn_states;

    // Saturate: '<S26>/Limit2maxDeflection' incorporates:
    //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'

    if (Pix_FCC_flash_B.ACC1 > Pix_FCC_flash_P.Limit2maxDeflection_UpperSat) {
      Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_P.Limit2maxDeflection_UpperSat;
    } else {
      if (Pix_FCC_flash_B.ACC1 < Pix_FCC_flash_P.Limit2maxDeflection_LowerSat) {
        Pix_FCC_flash_B.ACC1 = Pix_FCC_flash_P.Limit2maxDeflection_LowerSat;
      }
    }

    // End of Saturate: '<S26>/Limit2maxDeflection'

    // Sum: '<S26>/Add16' incorporates:
    //   Abs: '<S26>/Abs'
    //   Constant: '<S26>/Constant4'

    Pix_FCC_flash_B.Add16 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad -
      static_cast<real32_T>(fabs(static_cast<real_T>(Pix_FCC_flash_B.ACC1)));

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
    //   MinMax: '<S31>/Max'
    //   RelationalOperator: '<S29>/Relational Operator'
    //   RelationalOperator: '<S29>/Relational Operator1'
    //   RelationalOperator: '<S29>/Relational Operator2'
    //   RelationalOperator: '<S29>/Relational Operator3'

    if ((!(fabs(Pix_FCC_flash_B.Add) > Pix_FCC_flash_B.Add16)) && (!(fabs
          (Pix_FCC_flash_B.Add1) > Pix_FCC_flash_B.Add16)) && (!(fabs
          (Pix_FCC_flash_B.Add2) > Pix_FCC_flash_B.Add16)) && (!(fabs
          (Pix_FCC_flash_B.Add3) > Pix_FCC_flash_B.Add16))) {
      Pix_FCC_flash_DW.Pass_SubsysRanBC = 4;
    } else {
      if ((Pix_FCC_flash_B.Add > Pix_FCC_flash_B.Add1) || rtIsNaN
          (Pix_FCC_flash_B.Add1)) {
        // MinMax: '<S31>/Max'
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add;
      } else {
        // MinMax: '<S31>/Max'
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add1;
      }

      // MinMax: '<S31>/Max'
      if ((!(Pix_FCC_flash_B.Abs1 > Pix_FCC_flash_B.Add2)) && (!rtIsNaN
           (Pix_FCC_flash_B.Add2))) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add2;
      }

      if ((!(Pix_FCC_flash_B.Abs1 > Pix_FCC_flash_B.Add3)) && (!rtIsNaN
           (Pix_FCC_flash_B.Add3))) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Add3;
      }

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
      Pix_FCC_flash_DW.Saturate_SubsysRanBC = 4;
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

    Pix_FCC_flash_B.Add = (Pix_FCC_flash_B.ACC1 + Pix_FCC_flash_B.Add) /
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

    Pix_FCC_flash_B.Add1 = (Pix_FCC_flash_B.ACC1 + Pix_FCC_flash_B.Add1) /
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

    Pix_FCC_flash_B.Add2 = (Pix_FCC_flash_B.ACC1 + Pix_FCC_flash_B.Add2) /
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

    Pix_FCC_flash_B.Add3 = (Pix_FCC_flash_B.ACC1 + Pix_FCC_flash_B.Add3) /
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

    // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
    Pix_FCC_flash_DW.DiscreteTransferFcn2_states = (Pix_FCC_flash_B.CMD1 -
      Pix_FCC_flash_P.DiscreteTransferFcn2_DenCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn2_states) /
      Pix_FCC_flash_P.DiscreteTransferFcn2_DenCoef[0];

    // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
    Pix_FCC_flash_DW.DiscreteTransferFcn1_states = (Pix_FCC_flash_B.CMD2 -
      Pix_FCC_flash_P.DiscreteTransferFcn1_DenCoef[1] *
      Pix_FCC_flash_DW.DiscreteTransferFcn1_states) /
      Pix_FCC_flash_P.DiscreteTransferFcn1_DenCoef[0];

    // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
    Pix_FCC_flash_DW.DiscreteTransferFcn_states = Pix_FCC_flash_B.CMD3;
    Pix_FCC_flash_DW.ACTION_SubsysRanBC = 4;

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/OUTPUT'

    // MATLAB Function: '<S39>/MessageAssembly' incorporates:
    //   Constant: '<S39>/Constant'
    //   MATLAB Function: '<S18>/DefineRCStatus'
    //   MATLAB Function: '<S18>/DefineStatus'
    //   MATLAB Function: '<S39>/convert2uint8'
    //   SignalConversion generated from: '<S48>/ SFunction '

    if (Pix_FCC_flash_P.Constant_Value_h == 1.0) {
      memcpy((void *)&x[0], (void *)&Pix_FCC_flash_B.SimHeartbeat_update,
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      Pix_FCC_flash_B.pack[0] = x[0];
      Pix_FCC_flash_B.pack[1] = x[1];

      // Outputs for Function Call SubSystem: '<S2>/ACTION'
      Pix_FCC_flash_B.pack[2] = static_cast<uint8_T>(rtb_mode);
      Pix_FCC_flash_B.pack[3] = Pix_FCC_flash_B.packetfound;

      // End of Outputs for SubSystem: '<S2>/ACTION'
      memcpy((void *)&Pix_FCC_flash_B.TmpSignalConversionAtSFunct[0], (void *)
             &Pix_FCC_flash_B.pack[0], (uint32_T)((size_t)1 * sizeof(real32_T)));
    } else {
      // SignalConversion generated from: '<S48>/ SFunction ' incorporates:
      //   MATLAB Function: '<S39>/convert2uint8'

      Pix_FCC_flash_B.TmpSignalConversionAtSFunct[0] = 0.0F;
    }

    // End of MATLAB Function: '<S39>/MessageAssembly'

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // SignalConversion generated from: '<S48>/ SFunction ' incorporates:
    //   DataTypeConversion: '<S18>/Data Type Conversion'
    //   Inport: '<S18>/SensorData'
    //   Inport: '<S18>/TestSignal'
    //   MATLAB Function: '<S39>/convert2uint8'

    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[1] = static_cast<real32_T>
      (Pix_FCC_flash_B.Add);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[2] = static_cast<real32_T>
      (Pix_FCC_flash_B.Add1);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[3] = static_cast<real32_T>
      (Pix_FCC_flash_B.Add2);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[4] = static_cast<real32_T>
      (Pix_FCC_flash_B.Add3);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[5] = Pix_FCC_flash_B.In1_j.x;
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[8] = Pix_FCC_flash_B.In1.x;
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[6] = Pix_FCC_flash_B.In1_j.y;
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[9] = Pix_FCC_flash_B.In1.y;
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[7] = Pix_FCC_flash_B.In1_j.z;
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[10] = Pix_FCC_flash_B.In1.z;
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[11] = Pix_FCC_flash_B.In1_c.q[0];
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[12] = Pix_FCC_flash_B.In1_c.q[1];
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[13] = Pix_FCC_flash_B.In1_c.q[2];
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[14] = Pix_FCC_flash_B.In1_c.q[3];
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[15] =
      Pix_FCC_flash_B.TestSignal_update;

    // MATLAB Function: '<S39>/convert2uint8'
    memcpy((void *)&Pix_FCC_flash_B.msgOut[0], (void *)
           &Pix_FCC_flash_B.TmpSignalConversionAtSFunct[0], (uint32_T)((size_t)
            64 * sizeof(uint8_T)));

    // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send WhiteNoise Beginning'

    Pix_FCC_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p,
      &Pix_FCC_flash_P.SendWhiteNoiseBeginning_p);

    // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send Header'

    Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendHeader_k,
      &Pix_FCC_flash_P.SendHeader_k);

    // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send Data'

    // DataTypeConversion: '<S43>/Cast1'
    Pix_FCC_flash_B.Cast1[0] = Pix_FCC_flash_B.msgOut[20];
    Pix_FCC_flash_B.Cast1[1] = Pix_FCC_flash_B.msgOut[21];
    Pix_FCC_flash_B.Cast1[2] = Pix_FCC_flash_B.msgOut[22];
    Pix_FCC_flash_B.Cast1[3] = Pix_FCC_flash_B.msgOut[23];

    // DataTypeConversion: '<S43>/Cast'
    Pix_FCC_flash_B.Cast[0] = Pix_FCC_flash_B.msgOut[0];
    Pix_FCC_flash_B.Cast[1] = Pix_FCC_flash_B.msgOut[1];

    // Sin: '<S43>/Sine Wave'
    Pix_FCC_flash_B.SineWave = sin(Pix_FCC_flash_P.SineWave_Freq_j *
      Pix_FCC_flash_M->Timing.taskTime0 + Pix_FCC_flash_P.SineWave_Phase) *
      Pix_FCC_flash_P.SineWave_Amp_e + Pix_FCC_flash_P.SineWave_Bias_o;

    // MATLABSystem: '<S43>/Serial Transmit'
    memcpy((void *)&Pix_FCC_flash_B.TxDataLocChar[0], (void *)
           &Pix_FCC_flash_B.msgOut[0], (uint32_T)((size_t)64 * sizeof(uint8_T)));
    MW_SCI_Transmit(Pix_FCC_flash_DW.obj_h.MW_SCIHANDLE,
                    Pix_FCC_flash_B.TxDataLocChar, 64U);
    Pix_FCC_flash_DW.SendData_SubsysRanBC = 4;

    // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send Terminator'

    Pix_FCC_flash_SendHeader(&Pix_FCC_flash_DW.SendTerminator_g,
      &Pix_FCC_flash_P.SendTerminator_g);

    // S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
    //   SubSystem: '<S39>/Send WhiteNoise End'

    Pix_FCC_SendWhiteNoiseBeginning(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a,
      &Pix_FCC_flash_P.SendWhiteNoiseEnd_a);

    // End of Outputs for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

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
    Pix_FCC_flash_DW.OUTPUT_SubsysRanBC = 4;

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
    srUpdateBC(Pix_FCC_flash_DW.ExecutionCycle_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<Root>/ExecutionCycle'

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.01s, 0.0s]
    rtExtModeUpload(0, (real_T)Pix_FCC_flash_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.01s, 0.0s]
    if ((rtmGetTFinal(Pix_FCC_flash_M)!=-1) &&
        !((rtmGetTFinal(Pix_FCC_flash_M)-Pix_FCC_flash_M->Timing.taskTime0) >
          Pix_FCC_flash_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Pix_FCC_flash_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Pix_FCC_flash_M)) {
      rtmSetErrorStatus(Pix_FCC_flash_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  Pix_FCC_flash_M->Timing.taskTime0 =
    (++Pix_FCC_flash_M->Timing.clockTick0) * Pix_FCC_flash_M->Timing.stepSize0;
}

// Model initialize function
void Pix_FCC_flash_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Pix_FCC_flash_M, -1);
  Pix_FCC_flash_M->Timing.stepSize0 = 0.01;

  // External mode info
  Pix_FCC_flash_M->Sizes.checksums[0] = (3795466782U);
  Pix_FCC_flash_M->Sizes.checksums[1] = (423616159U);
  Pix_FCC_flash_M->Sizes.checksums[2] = (402338265U);
  Pix_FCC_flash_M->Sizes.checksums[3] = (4240942605U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[53];
    Pix_FCC_flash_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&Pix_FCC_flash_DW.SendData_SubsysRanBC_b;
    systemRan[3] = (sysRanDType *)&Pix_FCC_flash_DW.SendData_SubsysRanBC_b;
    systemRan[4] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendHeader.SendHeader_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendHeader.SendHeader_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendRCConfrimation_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendRCConfrimation_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendTerminator.SendHeader_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendTerminator.SendHeader_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseBeginning.SendWhiteNoiseBeginning_SubsysR;
    systemRan[11] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseBeginning.SendWhiteNoiseBeginning_SubsysR;
    systemRan[12] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseEnd.SendWhiteNoiseBeginning_SubsysR;
    systemRan[13] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseEnd.SendWhiteNoiseBeginning_SubsysR;
    systemRan[14] = (sysRanDType *)&Pix_FCC_flash_DW.ConfirmCommand_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&Pix_FCC_flash_DW.ConfirmCommand_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&Pix_FCC_flash_DW.DecodeCommand_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&Pix_FCC_flash_DW.DecodeCommand_SubsysRanBC;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)&Pix_FCC_flash_DW.memory_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&Pix_FCC_flash_DW.ACTION_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&Pix_FCC_flash_DW.ACTION_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&Pix_FCC_flash_DW.Pass_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&Pix_FCC_flash_DW.Saturate_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&Pix_FCC_flash_DW.ACTION_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&Pix_FCC_flash_DW.OUTPUT_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&Pix_FCC_flash_DW.OUTPUT_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&Pix_FCC_flash_DW.SendData_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&Pix_FCC_flash_DW.SendData_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendHeader_k.SendHeader_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendHeader_k.SendHeader_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendTerminator_g.SendHeader_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendTerminator_g.SendHeader_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.SendWhiteNoiseBeginning_SubsysR;
    systemRan[34] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.SendWhiteNoiseBeginning_SubsysR;
    systemRan[35] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.SendWhiteNoiseBeginning_SubsysR;
    systemRan[36] = (sysRanDType *)
      &Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.SendWhiteNoiseBeginning_SubsysR;
    systemRan[37] = (sysRanDType *)&Pix_FCC_flash_DW.OUTPUT_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&Pix_FCC_flash_DW.OUTPUT_SubsysRanBC;
    systemRan[39] = (sysRanDType *)&Pix_FCC_flash_DW.heartbeat_SubsysRanBC;
    systemRan[40] = (sysRanDType *)&Pix_FCC_flash_DW.input_hold_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&Pix_FCC_flash_DW.input_hold_SubsysRanBC;
    systemRan[42] = (sysRanDType *)&Pix_FCC_flash_DW.hold_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&Pix_FCC_flash_DW.input_hold_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &Pix_FCC_flash_DW.process_received_data_SubsysRan;
    systemRan[45] = (sysRanDType *)&Pix_FCC_flash_DW.ExecutionCycle_SubsysRanBC;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = (sysRanDType *)
      &Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_o;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = (sysRanDType *)
      &Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_a;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = (sysRanDType *)
      &Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[52] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Pix_FCC_flash_M->extModeInfo,
      &Pix_FCC_flash_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Pix_FCC_flash_M->extModeInfo,
                        Pix_FCC_flash_M->Sizes.checksums);
    rteiSetTPtr(Pix_FCC_flash_M->extModeInfo, rtmGetTPtr(Pix_FCC_flash_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&Pix_FCC_flash_B)), 0,
                sizeof(B_Pix_FCC_flash_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&Pix_FCC_flash_DW), 0,
                sizeof(DW_Pix_FCC_flash_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    Pix_FCC_flash_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 36;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for MATLABSystem: '<Root>/Receive Data'
  Pix_FCC_flash_DW.obj.isInitialized = 0;
  Pix_FCC_flash_DW.obj.matlabCodegenIsDeleted = false;
  Pix_FCC_flash_DW.obj.SampleTime = Pix_FCC_flash_P.ReceiveData_SampleTime;
  Pix_FCC_flas_SystemCore_setup_b(&Pix_FCC_flash_DW.obj);

  // Start for Enabled SubSystem: '<S1>/DecodeCommand'
  // Start for Enabled SubSystem: '<S6>/ConfirmCommand'
  // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send WhiteNoise Beginning'

  P_SendWhiteNoiseBeginning_Start(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning);

  // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send Header'

  Pix_FCC_flash_SendHeader_Start(&Pix_FCC_flash_DW.SendHeader);

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

  Pix_FCC_flash_SendHeader_Start(&Pix_FCC_flash_DW.SendTerminator);

  // Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send WhiteNoise End'

  P_SendWhiteNoiseBeginning_Start(&Pix_FCC_flash_DW.SendWhiteNoiseEnd);

  // End of Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1'
  // End of Start for SubSystem: '<S6>/ConfirmCommand'
  // End of Start for SubSystem: '<S1>/DecodeCommand'

  // Start for MATLABSystem: '<S59>/SourceBlock'
  Pix_FCC_flash_DW.obj_d.matlabCodegenIsDeleted = false;
  Pix_FCC_flash_DW.obj_d.isSetupComplete = false;
  Pix_FCC_flash_DW.obj_d.isInitialized = 1;
  Pix_FCC_flash_DW.obj_d.orbMetadataObj = ORB_ID(sensor_accel);
  uORB_read_initialize(Pix_FCC_flash_DW.obj_d.orbMetadataObj,
                       &Pix_FCC_flash_DW.obj_d.eventStructObj);
  Pix_FCC_flash_DW.obj_d.isSetupComplete = true;

  // Start for MATLABSystem: '<S61>/SourceBlock'
  Pix_FCC_flash_DW.obj_f.matlabCodegenIsDeleted = false;
  Pix_FCC_flash_DW.obj_f.isSetupComplete = false;
  Pix_FCC_flash_DW.obj_f.isInitialized = 1;
  Pix_FCC_flash_DW.obj_f.orbMetadataObj = ORB_ID(sensor_gyro);
  uORB_read_initialize(Pix_FCC_flash_DW.obj_f.orbMetadataObj,
                       &Pix_FCC_flash_DW.obj_f.eventStructObj);
  Pix_FCC_flash_DW.obj_f.isSetupComplete = true;

  // Start for MATLABSystem: '<S63>/SourceBlock'
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

  // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send WhiteNoise Beginning'

  P_SendWhiteNoiseBeginning_Start(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p);

  // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Header'

  Pix_FCC_flash_SendHeader_Start(&Pix_FCC_flash_DW.SendHeader_k);

  // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Data'

  // Start for MATLABSystem: '<S43>/Serial Transmit'
  Pix_FCC_flash_DW.obj_h.isInitialized = 0;
  Pix_FCC_flash_DW.obj_h.matlabCodegenIsDeleted = false;
  Pix_FCC_fla_SystemCore_setup_b2(&Pix_FCC_flash_DW.obj_h);

  // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Terminator'

  Pix_FCC_flash_SendHeader_Start(&Pix_FCC_flash_DW.SendTerminator_g);

  // Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send WhiteNoise End'

  P_SendWhiteNoiseBeginning_Start(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a);

  // End of Start for S-Function (fcncallgen): '<S39>/Function-Call Generator1'

  // Start for MATLABSystem: '<S38>/PX4 PWM Output' incorporates:
  //   Constant: '<S19>/PWM_arm_flg'

  Pix_FCC_flash_DW.obj_j.errorStatus = 0U;
  Pix_FCC_flash_DW.obj_j.isInitialized = 0;
  Pix_FCC_flash_DW.obj_j.matlabCodegenIsDeleted = false;
  Pix_FCC_f_SystemCore_setup_b2qa(&Pix_FCC_flash_DW.obj_j,
    Pix_FCC_flash_P.PWM_arm_flg_Value, Pix_FCC_flash_P.PWM_arm_flg_Value);

  // End of Start for S-Function (fcncallgen): '<S2>/Function-Call Generator2'
  // End of Start for SubSystem: '<Root>/ExecutionCycle'

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

  // SystemInitialize for Enabled SubSystem: '<S59>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S60>/Out1'
  Pix_FCC_flash_B.In1_j = Pix_FCC_flash_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S59>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S61>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S62>/Out1'
  Pix_FCC_flash_B.In1 = Pix_FCC_flash_P.Out1_Y0_f;

  // End of SystemInitialize for SubSystem: '<S61>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S63>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S64>/Out1'
  Pix_FCC_flash_B.In1_c = Pix_FCC_flash_P.Out1_Y0_a;

  // End of SystemInitialize for SubSystem: '<S63>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<Root>/ExecutionCycle'
  // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
  //   SubSystem: '<S2>/process_received_data'

  // SystemInitialize for Enabled SubSystem: '<S21>/input_hold'
  // SystemInitialize for Enabled SubSystem: '<S52>/hold'
  // SystemInitialize for Outport: '<S55>/SimHeartbeat'
  Pix_FCC_flash_B.SimHeartbeat_update = Pix_FCC_flash_P.SimHeartbeat_Y0;

  // SystemInitialize for Outport: '<S55>/CMD'
  Pix_FCC_flash_B.CMD_update[0] = Pix_FCC_flash_P.CMD_Y0;

  // SystemInitialize for Outport: '<S55>/ACC'
  Pix_FCC_flash_B.ACC_update[0] = Pix_FCC_flash_P.ACC_Y0;

  // SystemInitialize for Outport: '<S55>/ROT'
  Pix_FCC_flash_B.ROT_update[0] = Pix_FCC_flash_P.ROT_Y0;

  // SystemInitialize for Outport: '<S55>/ATT'
  Pix_FCC_flash_B.ATT_update[0] = Pix_FCC_flash_P.ATT_Y0;

  // SystemInitialize for Outport: '<S55>/CMD'
  Pix_FCC_flash_B.CMD_update[1] = Pix_FCC_flash_P.CMD_Y0;

  // SystemInitialize for Outport: '<S55>/ACC'
  Pix_FCC_flash_B.ACC_update[1] = Pix_FCC_flash_P.ACC_Y0;

  // SystemInitialize for Outport: '<S55>/ROT'
  Pix_FCC_flash_B.ROT_update[1] = Pix_FCC_flash_P.ROT_Y0;

  // SystemInitialize for Outport: '<S55>/ATT'
  Pix_FCC_flash_B.ATT_update[1] = Pix_FCC_flash_P.ATT_Y0;

  // SystemInitialize for Outport: '<S55>/CMD'
  Pix_FCC_flash_B.CMD_update[2] = Pix_FCC_flash_P.CMD_Y0;

  // SystemInitialize for Outport: '<S55>/ACC'
  Pix_FCC_flash_B.ACC_update[2] = Pix_FCC_flash_P.ACC_Y0;

  // SystemInitialize for Outport: '<S55>/ROT'
  Pix_FCC_flash_B.ROT_update[2] = Pix_FCC_flash_P.ROT_Y0;

  // SystemInitialize for Outport: '<S55>/ATT'
  Pix_FCC_flash_B.ATT_update[2] = Pix_FCC_flash_P.ATT_Y0;

  // SystemInitialize for Outport: '<S55>/TestSignal'
  Pix_FCC_flash_B.TestSignal_update = Pix_FCC_flash_P.TestSignal_Y0;

  // End of SystemInitialize for SubSystem: '<S52>/hold'

  // SystemInitialize for Outport: '<S52>/packetfound_flg'
  Pix_FCC_flash_B.packetfound = Pix_FCC_flash_P.packetfound_flg_Y0;

  // End of SystemInitialize for SubSystem: '<S21>/input_hold'

  // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
  //   SubSystem: '<S2>/ACTION'

  // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' 
  Pix_FCC_flash_DW.DiscreteTransferFcn2_states =
    Pix_FCC_flash_P.DiscreteTransferFcn2_InitialSta;

  // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' 
  Pix_FCC_flash_DW.DiscreteTransferFcn1_states =
    Pix_FCC_flash_P.DiscreteTransferFcn1_InitialSta;

  // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' 
  Pix_FCC_flash_DW.DiscreteTransferFcn_states =
    Pix_FCC_flash_P.DiscreteTransferFcn_InitialStat;

  // End of SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  // End of SystemInitialize for SubSystem: '<Root>/ExecutionCycle'
}

// Model terminate function
void Pix_FCC_flash_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Receive Data'
  matlabCodegenHandle_matlabCod_b(&Pix_FCC_flash_DW.obj);

  // Terminate for Enabled SubSystem: '<S1>/DecodeCommand'
  // Terminate for Enabled SubSystem: '<S6>/ConfirmCommand'
  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send WhiteNoise Beginning'

  Pi_SendWhiteNoiseBeginning_Term(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send Header'

  Pix_FCC_flash_SendHeader_Term(&Pix_FCC_flash_DW.SendHeader);

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

  Pix_FCC_flash_SendHeader_Term(&Pix_FCC_flash_DW.SendTerminator);

  // Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S9>/Send WhiteNoise End'

  Pi_SendWhiteNoiseBeginning_Term(&Pix_FCC_flash_DW.SendWhiteNoiseEnd);

  // End of Terminate for S-Function (fcncallgen): '<S9>/Function-Call Generator1' 
  // End of Terminate for SubSystem: '<S6>/ConfirmCommand'
  // End of Terminate for SubSystem: '<S1>/DecodeCommand'

  // Terminate for MATLABSystem: '<S59>/SourceBlock'
  matlabCodegenHandle_matl_b2qa4v(&Pix_FCC_flash_DW.obj_d);

  // Terminate for MATLABSystem: '<S61>/SourceBlock'
  matlabCodegenHandle_matl_b2qa4v(&Pix_FCC_flash_DW.obj_f);

  // Terminate for MATLABSystem: '<S63>/SourceBlock'
  matlabCodegenHandle_matl_b2qa4v(&Pix_FCC_flash_DW.obj_c);

  // Terminate for Enabled SubSystem: '<Root>/ExecutionCycle'
  // Terminate for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
  //   SubSystem: '<S2>/OUTPUT'

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send WhiteNoise Beginning'

  Pi_SendWhiteNoiseBeginning_Term(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Header'

  Pix_FCC_flash_SendHeader_Term(&Pix_FCC_flash_DW.SendHeader_k);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Data'

  // Terminate for MATLABSystem: '<S43>/Serial Transmit'
  matlabCodegenHandle_matlabCo_b2(&Pix_FCC_flash_DW.obj_h);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send Terminator'

  Pix_FCC_flash_SendHeader_Term(&Pix_FCC_flash_DW.SendTerminator_g);

  // Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S39>/Send WhiteNoise End'

  Pi_SendWhiteNoiseBeginning_Term(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a);

  // End of Terminate for S-Function (fcncallgen): '<S39>/Function-Call Generator1' 

  // Terminate for MATLABSystem: '<S38>/PX4 PWM Output'
  matlabCodegenHandle_matlab_b2qa(&Pix_FCC_flash_DW.obj_j);

  // End of Terminate for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  // End of Terminate for SubSystem: '<Root>/ExecutionCycle'
}

//
// File trailer for generated code.
//
// [EOF]
//

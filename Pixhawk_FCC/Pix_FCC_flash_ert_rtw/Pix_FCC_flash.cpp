//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash.cpp
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.342
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Jan 16 20:05:28 2020
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
static void Pix_FCC_flash_nullAssignment(real_T x_data[], int32_T x_size[2],
  const boolean_T idx_data[], const int32_T idx_size[2]);
static void Pix_FCC_flas_SystemCore_release(const
  px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_flash_SystemCore_delete(const
  px4_internal_block_PX4SCIRead_T *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC__SystemCore_release_b2q(const
  px4_internal_block_Subscriber_T *obj);
static void Pix_FCC_f_SystemCore_delete_b2q(const
  px4_internal_block_Subscriber_T *obj);
static void matlabCodegenHandle_matlabC_b2q(px4_internal_block_Subscriber_T *obj);
static void Pix_FCC_f_SystemCore_release_b2(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fl_SystemCore_delete_b2(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void matlabCodegenHandle_matlabCo_b2(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_fl_SystemCore_release_b(px4_internal_block_PWM_Pix_FC_T *obj);
static void Pix_FCC_fla_SystemCore_delete_b(px4_internal_block_PWM_Pix_FC_T *obj);
static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PWM_Pix_FC_T *obj);
static void Pix_FCC_flash_SystemCore_setup(px4_internal_block_PX4SCIRead_T *obj);
static void Pix_FCC_fla_SystemCore_setup_b2(px4_internal_block_PX4SCIWrit_T *obj);
static void Pix_FCC_flas_SystemCore_setup_b(px4_internal_block_PWM_Pix_FC_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void Pix_FCC_flas_SystemCore_release(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pix_FCC_flash_SystemCore_delete(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  Pix_FCC_flas_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIRead_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_flash_SystemCore_delete(obj);
  }
}

static void Pix_FCC__SystemCore_release_b2q(const
  px4_internal_block_Subscriber_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_read_terminate(&obj->eventStructObj);
  }
}

static void Pix_FCC_f_SystemCore_delete_b2q(const
  px4_internal_block_Subscriber_T *obj)
{
  Pix_FCC__SystemCore_release_b2q(obj);
}

static void matlabCodegenHandle_matlabC_b2q(px4_internal_block_Subscriber_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_f_SystemCore_delete_b2q(obj);
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

static void Pix_FCC_fl_SystemCore_release_b(px4_internal_block_PWM_Pix_FC_T *obj)
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

static void Pix_FCC_fla_SystemCore_delete_b(px4_internal_block_PWM_Pix_FC_T *obj)
{
  Pix_FCC_fl_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlabCod_b(px4_internal_block_PWM_Pix_FC_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pix_FCC_fla_SystemCore_delete_b(obj);
  }
}

static void Pix_FCC_flash_SystemCore_setup(px4_internal_block_PX4SCIRead_T *obj)
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

static void Pix_FCC_fla_SystemCore_setup_b2(px4_internal_block_PX4SCIWrit_T *obj)
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

static void Pix_FCC_flas_SystemCore_setup_b(px4_internal_block_PWM_Pix_FC_T *obj,
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
  boolean_T p;
  int32_T b_ii;
  uint8_T package[4];
  int32_T idx;
  real32_T CMD1;
  real32_T CMD2;
  real32_T CMD3;
  real32_T ACC1;
  uint8_T x[2];
  uint16_T status;
  int32_T rtb_mode;
  int32_T rtb_enable_execution;
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
    for (b_ii = 0; b_ii < 128; b_ii++) {
      Pix_FCC_flash_B.x[b_ii] = (Pix_FCC_flash_B.RxData[b_ii] == 8);
    }

    idx = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 128)) {
      if (Pix_FCC_flash_B.x[b_ii]) {
        idx++;
        Pix_FCC_flash_B.RxDataLocChar[idx - 1] = static_cast<uint8_T>((b_ii + 1));
        if (idx >= 128) {
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

    Pix_FCC_flash_B.start_size[0] = 1;
    Pix_FCC_flash_B.start_size[1] = idx;
    loop_ub = idx - 1;
    for (b_ii = 0; b_ii <= loop_ub; b_ii++) {
      Pix_FCC_flash_B.start_data[b_ii] = Pix_FCC_flash_B.RxDataLocChar[b_ii];
    }

    Pix_FCC_flash_B.start_size_f[0] = 1;
    Pix_FCC_flash_B.start_size_f[1] = idx;
    for (b_ii = 0; b_ii < idx; b_ii++) {
      Pix_FCC_flash_B.x[b_ii] = ((Pix_FCC_flash_B.start_data[b_ii] + 2.0) - 1.0 >
        128.0);
    }

    Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data,
      Pix_FCC_flash_B.start_size, Pix_FCC_flash_B.x,
      Pix_FCC_flash_B.start_size_f);
    Pix_FCC_flash_B.tmp_size_c[0] = 1;
    Pix_FCC_flash_B.tmp_size_c[1] = Pix_FCC_flash_B.start_size[1];
    loop_ub = Pix_FCC_flash_B.start_size[0] * Pix_FCC_flash_B.start_size[1];
    for (b_ii = 0; b_ii < loop_ub; b_ii++) {
      Pix_FCC_flash_B.x[b_ii] = (Pix_FCC_flash_B.RxData[static_cast<int32_T>
        (((Pix_FCC_flash_B.start_data[b_ii] + 2.0) - 1.0)) - 1] != 8);
    }

    Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data,
      Pix_FCC_flash_B.start_size, Pix_FCC_flash_B.x, Pix_FCC_flash_B.tmp_size_c);
    if (Pix_FCC_flash_B.start_size[1] != 0) {
      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= Pix_FCC_flash_B.start_size[1] - 2)) {
        p = false;
        Pix_FCC_flash_B.pulse_width_ms_k = Pix_FCC_flash_B.start_data[b_ii + 1];
        if (Pix_FCC_flash_B.pulse_width_ms_k - Pix_FCC_flash_B.start_data[b_ii] ==
            6.0) {
          p = true;
        }

        if (p) {
          if (Pix_FCC_flash_B.start_data[b_ii] + 2.0 >
              Pix_FCC_flash_B.pulse_width_ms_k - 1.0) {
            idx = 0;
            rtb_enable_execution = 0;
          } else {
            idx = static_cast<int32_T>((Pix_FCC_flash_B.start_data[b_ii] + 2.0))
              - 1;
            rtb_enable_execution = static_cast<int32_T>
              ((Pix_FCC_flash_B.start_data[b_ii + 1] - 1.0));
          }

          rtb_enable_execution -= idx;
          for (b_ii = 0; b_ii < rtb_enable_execution; b_ii++) {
            Pix_FCC_flash_B.packet_data[b_ii] = Pix_FCC_flash_B.RxData[idx +
              b_ii];
          }

          Pix_FCC_flash_B.cmd_found_flg = true;
          exitg1 = true;
        } else {
          b_ii++;
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

  // MATLABSystem: '<S55>/SourceBlock' incorporates:
  //   Inport: '<S56>/In1'

  p = uORB_read_step(Pix_FCC_flash_DW.obj_d.orbMetadataObj,
                     &Pix_FCC_flash_DW.obj_d.eventStructObj,
                     &Pix_FCC_flash_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S56>/Enable'

  if (p) {
    Pix_FCC_flash_B.In1_j = Pix_FCC_flash_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S55>/SourceBlock'
  // End of Outputs for SubSystem: '<S55>/Enabled Subsystem'

  // MATLABSystem: '<S57>/SourceBlock' incorporates:
  //   Inport: '<S58>/In1'

  p = uORB_read_step(Pix_FCC_flash_DW.obj_f.orbMetadataObj,
                     &Pix_FCC_flash_DW.obj_f.eventStructObj,
                     &Pix_FCC_flash_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S57>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  if (p) {
    Pix_FCC_flash_B.In1 = Pix_FCC_flash_B.b_varargout_2_k;
  }

  // End of MATLABSystem: '<S57>/SourceBlock'
  // End of Outputs for SubSystem: '<S57>/Enabled Subsystem'

  // MATLABSystem: '<S59>/SourceBlock' incorporates:
  //   Inport: '<S60>/In1'

  p = uORB_read_step(Pix_FCC_flash_DW.obj_c.orbMetadataObj,
                     &Pix_FCC_flash_DW.obj_c.eventStructObj,
                     &Pix_FCC_flash_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S59>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S60>/Enable'

  if (p) {
    Pix_FCC_flash_B.In1_c = Pix_FCC_flash_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S59>/SourceBlock'
  // End of Outputs for SubSystem: '<S59>/Enabled Subsystem'

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

    // Outputs for Enabled SubSystem: '<S13>/input_hold' incorporates:
    //   EnablePort: '<S48>/Enable'

    // Logic: '<S2>/NOT' incorporates:
    //   Inport: '<S51>/CMD_update'
    //   Inport: '<S51>/SimHeartbeat_update'
    //   Inport: '<S51>/TestSignal_update'
    //   MATLAB Function: '<S48>/ByteUnpack'
    //   MATLAB Function: '<S48>/ExtractMessage'
    //   MATLABSystem: '<Root>/Receive Data'

    if (sizeptr == 0) {
      // MATLAB Function: '<S48>/ExtractMessage'
      rtb_enable_execution = 56;
      for (b_ii = 0; b_ii < 56; b_ii++) {
        Pix_FCC_flash_B.packet_data_c[b_ii] = 0U;
      }

      Pix_FCC_flash_B.packetfound = false;
      for (b_ii = 0; b_ii < 128; b_ii++) {
        Pix_FCC_flash_B.x[b_ii] = (Pix_FCC_flash_B.RxData[b_ii] == 7);
      }

      idx = 0;
      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii < 128)) {
        if (Pix_FCC_flash_B.x[b_ii]) {
          idx++;
          Pix_FCC_flash_B.RxDataLocChar[idx - 1] = static_cast<uint8_T>((b_ii +
            1));
          if (idx >= 128) {
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

      Pix_FCC_flash_B.start_size_b[0] = 1;
      Pix_FCC_flash_B.start_size_b[1] = idx;
      loop_ub = idx - 1;
      for (b_ii = 0; b_ii <= loop_ub; b_ii++) {
        Pix_FCC_flash_B.start_data_m[b_ii] = Pix_FCC_flash_B.RxDataLocChar[b_ii];
      }

      Pix_FCC_flash_B.start_size_p[0] = 1;
      Pix_FCC_flash_B.start_size_p[1] = idx;
      for (b_ii = 0; b_ii < idx; b_ii++) {
        Pix_FCC_flash_B.x[b_ii] = ((Pix_FCC_flash_B.start_data_m[b_ii] + 2.0) -
          1.0 > 128.0);
      }

      Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data_m,
        Pix_FCC_flash_B.start_size_b, Pix_FCC_flash_B.x,
        Pix_FCC_flash_B.start_size_p);
      Pix_FCC_flash_B.tmp_size[0] = 1;
      Pix_FCC_flash_B.tmp_size[1] = Pix_FCC_flash_B.start_size_b[1];
      loop_ub = Pix_FCC_flash_B.start_size_b[0] * Pix_FCC_flash_B.start_size_b[1];
      for (b_ii = 0; b_ii < loop_ub; b_ii++) {
        Pix_FCC_flash_B.x[b_ii] = (Pix_FCC_flash_B.RxData[static_cast<int32_T>
          (((Pix_FCC_flash_B.start_data_m[b_ii] + 2.0) - 1.0)) - 1] != 7);
      }

      Pix_FCC_flash_nullAssignment(Pix_FCC_flash_B.start_data_m,
        Pix_FCC_flash_B.start_size_b, Pix_FCC_flash_B.x,
        Pix_FCC_flash_B.tmp_size);
      if (Pix_FCC_flash_B.start_size_b[1] != 0) {
        b_ii = 0;
        exitg1 = false;
        while ((!exitg1) && (b_ii <= Pix_FCC_flash_B.start_size_b[1] - 2)) {
          p = false;
          Pix_FCC_flash_B.pulse_width_ms_k = Pix_FCC_flash_B.start_data_m[b_ii +
            1];
          if (Pix_FCC_flash_B.pulse_width_ms_k -
              Pix_FCC_flash_B.start_data_m[b_ii] == 58.0) {
            p = true;
          }

          if (p) {
            if (Pix_FCC_flash_B.start_data_m[b_ii] + 2.0 >
                Pix_FCC_flash_B.pulse_width_ms_k - 1.0) {
              idx = 0;
              rtb_enable_execution = 0;
            } else {
              idx = static_cast<int32_T>((Pix_FCC_flash_B.start_data_m[b_ii] +
                2.0)) - 1;
              rtb_enable_execution = static_cast<int32_T>
                ((Pix_FCC_flash_B.start_data_m[b_ii + 1] - 1.0));
            }

            rtb_enable_execution -= idx;
            for (b_ii = 0; b_ii < rtb_enable_execution; b_ii++) {
              Pix_FCC_flash_B.packet_data_c[b_ii] = Pix_FCC_flash_B.RxData[idx +
                b_ii];
            }

            Pix_FCC_flash_B.packetfound = true;
            exitg1 = true;
          } else {
            b_ii++;
          }
        }
      }

      Pix_FCC_flash_DW.SFunction_DIMS2[0] = 1;
      Pix_FCC_flash_DW.SFunction_DIMS2[1] = rtb_enable_execution;
      if (0 <= rtb_enable_execution - 1) {
        memcpy(&Pix_FCC_flash_B.message[0], &Pix_FCC_flash_B.packet_data_c[0],
               rtb_enable_execution * sizeof(uint8_T));
      }

      // MATLAB Function: '<S48>/ByteUnpack' incorporates:
      //   MATLAB Function: '<S48>/ExtractMessage'

      x[0] = Pix_FCC_flash_B.message[0];
      x[1] = Pix_FCC_flash_B.message[1];
      memcpy((void *)&status, (void *)&x[0], (uint32_T)((size_t)1 * sizeof
              (uint16_T)));
      package[0] = Pix_FCC_flash_B.message[4];
      package[1] = Pix_FCC_flash_B.message[5];
      package[2] = Pix_FCC_flash_B.message[6];
      package[3] = Pix_FCC_flash_B.message[7];
      memcpy((void *)&CMD1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[8];
      package[1] = Pix_FCC_flash_B.message[9];
      package[2] = Pix_FCC_flash_B.message[10];
      package[3] = Pix_FCC_flash_B.message[11];
      memcpy((void *)&CMD2, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[12];
      package[1] = Pix_FCC_flash_B.message[13];
      package[2] = Pix_FCC_flash_B.message[14];
      package[3] = Pix_FCC_flash_B.message[15];
      memcpy((void *)&CMD3, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[16];
      package[1] = Pix_FCC_flash_B.message[17];
      package[2] = Pix_FCC_flash_B.message[18];
      package[3] = Pix_FCC_flash_B.message[19];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[20];
      package[1] = Pix_FCC_flash_B.message[21];
      package[2] = Pix_FCC_flash_B.message[22];
      package[3] = Pix_FCC_flash_B.message[23];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[24];
      package[1] = Pix_FCC_flash_B.message[25];
      package[2] = Pix_FCC_flash_B.message[26];
      package[3] = Pix_FCC_flash_B.message[27];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[28];
      package[1] = Pix_FCC_flash_B.message[29];
      package[2] = Pix_FCC_flash_B.message[30];
      package[3] = Pix_FCC_flash_B.message[31];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[32];
      package[1] = Pix_FCC_flash_B.message[33];
      package[2] = Pix_FCC_flash_B.message[34];
      package[3] = Pix_FCC_flash_B.message[35];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[36];
      package[1] = Pix_FCC_flash_B.message[37];
      package[2] = Pix_FCC_flash_B.message[38];
      package[3] = Pix_FCC_flash_B.message[39];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[40];
      package[1] = Pix_FCC_flash_B.message[41];
      package[2] = Pix_FCC_flash_B.message[42];
      package[3] = Pix_FCC_flash_B.message[43];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[44];
      package[1] = Pix_FCC_flash_B.message[45];
      package[2] = Pix_FCC_flash_B.message[46];
      package[3] = Pix_FCC_flash_B.message[47];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[48];
      package[1] = Pix_FCC_flash_B.message[49];
      package[2] = Pix_FCC_flash_B.message[50];
      package[3] = Pix_FCC_flash_B.message[51];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));
      package[0] = Pix_FCC_flash_B.message[52];
      package[1] = Pix_FCC_flash_B.message[53];
      package[2] = Pix_FCC_flash_B.message[54];
      package[3] = Pix_FCC_flash_B.message[55];
      memcpy((void *)&ACC1, (void *)&package[0], (uint32_T)((size_t)1 * sizeof
              (real32_T)));

      // Outputs for Enabled SubSystem: '<S48>/hold' incorporates:
      //   EnablePort: '<S51>/Enable'

      if (Pix_FCC_flash_B.packetfound) {
        Pix_FCC_flash_B.CMD_update[0] = CMD1;
        Pix_FCC_flash_B.CMD_update[1] = CMD2;
        Pix_FCC_flash_B.CMD_update[2] = CMD3;
        Pix_FCC_flash_B.SimHeartbeat_update = status;
        Pix_FCC_flash_B.TestSignal_update = ACC1;
      }

      // End of Outputs for SubSystem: '<S48>/hold'
    }

    // End of Logic: '<S2>/NOT'
    // End of Outputs for SubSystem: '<S13>/input_hold'

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // Sqrt: '<S31>/sqrt' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'
    //   Inport: '<S10>/Estimator'
    //   Product: '<S32>/Product'
    //   Product: '<S32>/Product1'
    //   Product: '<S32>/Product2'
    //   Product: '<S32>/Product3'
    //   Sum: '<S32>/Sum'

    Pix_FCC_flash_B.Product3 = sqrt(((static_cast<real_T>
      (Pix_FCC_flash_B.In1_c.q[0]) * Pix_FCC_flash_B.In1_c.q[0] +
      static_cast<real_T>(Pix_FCC_flash_B.In1_c.q[1]) * Pix_FCC_flash_B.In1_c.q
      [1]) + static_cast<real_T>(Pix_FCC_flash_B.In1_c.q[2]) *
      Pix_FCC_flash_B.In1_c.q[2]) + static_cast<real_T>(Pix_FCC_flash_B.In1_c.q
      [3]) * Pix_FCC_flash_B.In1_c.q[3]);

    // Product: '<S26>/Product' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'
    //   Inport: '<S10>/Estimator'

    Pix_FCC_flash_B.pulse_width_ms_k = Pix_FCC_flash_B.In1_c.q[0] /
      Pix_FCC_flash_B.Product3;

    // Product: '<S26>/Product1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'
    //   Inport: '<S10>/Estimator'

    Pix_FCC_flash_B.pulse_width_ms = Pix_FCC_flash_B.In1_c.q[1] /
      Pix_FCC_flash_B.Product3;

    // Product: '<S26>/Product2' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'
    //   Inport: '<S10>/Estimator'

    Pix_FCC_flash_B.Product2 = Pix_FCC_flash_B.In1_c.q[2] /
      Pix_FCC_flash_B.Product3;

    // Product: '<S26>/Product3' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'
    //   Inport: '<S10>/Estimator'

    Pix_FCC_flash_B.Product3 = Pix_FCC_flash_B.In1_c.q[3] /
      Pix_FCC_flash_B.Product3;

    // Fcn: '<S19>/fcn4'
    Pix_FCC_flash_B.pulse_width_ms_o = (Pix_FCC_flash_B.Product2 *
      Pix_FCC_flash_B.Product3 + Pix_FCC_flash_B.pulse_width_ms_k *
      Pix_FCC_flash_B.pulse_width_ms) * 2.0;

    // Fcn: '<S19>/fcn5'
    Pix_FCC_flash_B.pulse_width_ms_k = ((Pix_FCC_flash_B.pulse_width_ms_k *
      Pix_FCC_flash_B.pulse_width_ms_k - Pix_FCC_flash_B.pulse_width_ms *
      Pix_FCC_flash_B.pulse_width_ms) - Pix_FCC_flash_B.Product2 *
      Pix_FCC_flash_B.Product2) + Pix_FCC_flash_B.Product3 *
      Pix_FCC_flash_B.Product3;

    // Trigonometry: '<S25>/Trigonometric Function3'
    Pix_FCC_flash_B.pulse_width_ms_k = rt_atan2d_snf
      (Pix_FCC_flash_B.pulse_width_ms_o, Pix_FCC_flash_B.pulse_width_ms_k);

    // Sum: '<S18>/Add4' incorporates:
    //   Constant: '<S18>/Constant'
    //   Sum: '<S18>/Add5'

    Pix_FCC_flash_B.Product3 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f1_rad +
      Pix_FCC_flash_B.pulse_width_ms_k;

    // Sum: '<S18>/Add' incorporates:
    //   Constant: '<S15>/Zero'
    //   Fcn: '<S18>/Fcn'
    //   Fcn: '<S18>/Fcn1'
    //   Product: '<S18>/Multiply'
    //   Product: '<S18>/Multiply1'
    //   Sum: '<S18>/Add4'

    Pix_FCC_flash_B.Product3 = -cos(Pix_FCC_flash_B.Product3) *
      Pix_FCC_flash_P.Zero_Value + sin(Pix_FCC_flash_B.Product3) *
      Pix_FCC_flash_P.Zero_Value;

    // Sum: '<S18>/Add6' incorporates:
    //   Constant: '<S18>/Constant1'
    //   Sum: '<S18>/Add7'

    Pix_FCC_flash_B.pulse_width_ms =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f2_rad +
      Pix_FCC_flash_B.pulse_width_ms_k;

    // Sum: '<S18>/Add1' incorporates:
    //   Constant: '<S15>/Zero'
    //   Fcn: '<S18>/Fcn2'
    //   Fcn: '<S18>/Fcn3'
    //   Product: '<S18>/Multiply2'
    //   Product: '<S18>/Multiply3'
    //   Sum: '<S18>/Add6'

    Pix_FCC_flash_B.pulse_width_ms = -cos(Pix_FCC_flash_B.pulse_width_ms) *
      Pix_FCC_flash_P.Zero_Value + sin(Pix_FCC_flash_B.pulse_width_ms) *
      Pix_FCC_flash_P.Zero_Value;

    // Sum: '<S18>/Add8' incorporates:
    //   Constant: '<S18>/Constant2'
    //   Sum: '<S18>/Add9'

    Pix_FCC_flash_B.Product2 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f3_rad +
      Pix_FCC_flash_B.pulse_width_ms_k;

    // Sum: '<S18>/Add2' incorporates:
    //   Constant: '<S15>/Zero'
    //   Fcn: '<S18>/Fcn4'
    //   Fcn: '<S18>/Fcn5'
    //   Product: '<S18>/Multiply4'
    //   Product: '<S18>/Multiply5'
    //   Sum: '<S18>/Add8'

    Pix_FCC_flash_B.Product2 = -cos(Pix_FCC_flash_B.Product2) *
      Pix_FCC_flash_P.Zero_Value + sin(Pix_FCC_flash_B.Product2) *
      Pix_FCC_flash_P.Zero_Value;

    // Sum: '<S18>/Add10' incorporates:
    //   Constant: '<S18>/Constant3'
    //   Sum: '<S18>/Add11'

    Pix_FCC_flash_B.pulse_width_ms_o =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.phi_f4_rad +
      Pix_FCC_flash_B.pulse_width_ms_k;

    // Sum: '<S18>/Add3' incorporates:
    //   Constant: '<S15>/Zero'
    //   Fcn: '<S18>/Fcn6'
    //   Fcn: '<S18>/Fcn7'
    //   Product: '<S18>/Multiply6'
    //   Product: '<S18>/Multiply7'
    //   Sum: '<S18>/Add10'

    Pix_FCC_flash_B.pulse_width_ms_o = -cos(Pix_FCC_flash_B.pulse_width_ms_o) *
      Pix_FCC_flash_P.Zero_Value + sin(Pix_FCC_flash_B.pulse_width_ms_o) *
      Pix_FCC_flash_P.Zero_Value;

    // Gain: '<S15>/Gain5' incorporates:
    //   Gain: '<S15>/Kp'
    //   Inport: '<S10>/Estimator'
    //   Sum: '<S15>/Sum'
    //   Sum: '<S15>/Sum7'

    Pix_FCC_flash_B.pulse_width_ms_k = ((Pix_FCC_flash_B.CMD_update[0] -
      Pix_FCC_flash_B.pulse_width_ms_k) * Pix_FCC_flash_P.Kp_Gain -
      Pix_FCC_flash_B.In1_c.rollspeed) * Pix_FCC_flash_P.Gain5_Gain;

    // Saturate: '<S18>/Limit2maxDeflection'
    if (Pix_FCC_flash_B.pulse_width_ms_k >
        Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad) {
      Pix_FCC_flash_B.pulse_width_ms_k =
        Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad;
    } else {
      if (Pix_FCC_flash_B.pulse_width_ms_k <
          -Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad) {
        Pix_FCC_flash_B.pulse_width_ms_k =
          -Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad;
      }
    }

    // End of Saturate: '<S18>/Limit2maxDeflection'

    // Sum: '<S18>/Add16' incorporates:
    //   Abs: '<S18>/Abs'
    //   Constant: '<S18>/Constant4'

    Pix_FCC_flash_B.Add16 =
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad - fabs
      (Pix_FCC_flash_B.pulse_width_ms_k);

    // Outputs for Enabled SubSystem: '<S21>/Pass' incorporates:
    //   EnablePort: '<S23>/Enable'

    // Outputs for Enabled SubSystem: '<S21>/Saturate' incorporates:
    //   EnablePort: '<S24>/Enable'

    // Logic: '<S21>/Logical Operator' incorporates:
    //   Abs: '<S22>/Abs'
    //   Abs: '<S22>/Abs1'
    //   Abs: '<S22>/Abs2'
    //   Abs: '<S22>/Abs3'
    //   Logic: '<S22>/OR'
    //   RelationalOperator: '<S22>/Relational Operator'
    //   RelationalOperator: '<S22>/Relational Operator1'
    //   RelationalOperator: '<S22>/Relational Operator2'
    //   RelationalOperator: '<S22>/Relational Operator3'

    if ((fabs(Pix_FCC_flash_B.Product3) > Pix_FCC_flash_B.Add16) || (fabs
         (Pix_FCC_flash_B.pulse_width_ms) > Pix_FCC_flash_B.Add16) || (fabs
         (Pix_FCC_flash_B.Product2) > Pix_FCC_flash_B.Add16) || (fabs
         (Pix_FCC_flash_B.pulse_width_ms_o) > Pix_FCC_flash_B.Add16)) {
      // MinMax: '<S24>/Max'
      if ((Pix_FCC_flash_B.Product3 > Pix_FCC_flash_B.pulse_width_ms) || rtIsNaN
          (Pix_FCC_flash_B.pulse_width_ms)) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Product3;
      } else {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.pulse_width_ms;
      }

      if ((!(Pix_FCC_flash_B.Abs1 > Pix_FCC_flash_B.Product2)) && (!rtIsNaN
           (Pix_FCC_flash_B.Product2))) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.Product2;
      }

      if ((!(Pix_FCC_flash_B.Abs1 > Pix_FCC_flash_B.pulse_width_ms_o)) &&
          (!rtIsNaN(Pix_FCC_flash_B.pulse_width_ms_o))) {
        Pix_FCC_flash_B.Abs1 = Pix_FCC_flash_B.pulse_width_ms_o;
      }

      // End of MinMax: '<S24>/Max'

      // Abs: '<S24>/Abs1'
      Pix_FCC_flash_B.Abs1 = fabs(Pix_FCC_flash_B.Abs1);

      // Product: '<S24>/Multiply' incorporates:
      //   Product: '<S24>/Divide'

      Pix_FCC_flash_B.Product3 = Pix_FCC_flash_B.Product3 / Pix_FCC_flash_B.Abs1
        * Pix_FCC_flash_B.Add16;

      // Product: '<S24>/Multiply1' incorporates:
      //   Product: '<S24>/Divide1'

      Pix_FCC_flash_B.pulse_width_ms = Pix_FCC_flash_B.pulse_width_ms /
        Pix_FCC_flash_B.Abs1 * Pix_FCC_flash_B.Add16;

      // Product: '<S24>/Multiply3' incorporates:
      //   Product: '<S24>/Divide2'

      Pix_FCC_flash_B.pulse_width_ms_o = Pix_FCC_flash_B.pulse_width_ms_o /
        Pix_FCC_flash_B.Abs1 * Pix_FCC_flash_B.Add16;

      // Product: '<S24>/Multiply2' incorporates:
      //   Product: '<S24>/Divide4'

      Pix_FCC_flash_B.Product2 = Pix_FCC_flash_B.Product2 / Pix_FCC_flash_B.Abs1
        * Pix_FCC_flash_B.Add16;
    }

    // End of Logic: '<S21>/Logical Operator'
    // End of Outputs for SubSystem: '<S21>/Saturate'
    // End of Outputs for SubSystem: '<S21>/Pass'

    // Product: '<S33>/Product' incorporates:
    //   Constant: '<S33>/Constant6'
    //   Constant: '<S34>/Constant6'
    //   Constant: '<S35>/Constant6'
    //   Constant: '<S36>/Constant6'
    //   Product: '<S34>/Product'
    //   Product: '<S35>/Product'
    //   Product: '<S36>/Product'

    Pix_FCC_flash_B.Add16 =
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms -
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Sum: '<S33>/Add' incorporates:
    //   Constant: '<S20>/Constant'
    //   Constant: '<S33>/Constant2'
    //   Constant: '<S33>/Constant6'
    //   Product: '<S33>/Divide'
    //   Product: '<S33>/Product'
    //   Sum: '<S18>/Add15'

    Pix_FCC_flash_B.Product3 = (Pix_FCC_flash_B.pulse_width_ms_k +
      Pix_FCC_flash_B.Product3) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S33>/Saturation'
    if (Pix_FCC_flash_B.Product3 >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.Product3 =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.Product3 <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.Product3 =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S33>/Saturation'

    // Sum: '<S34>/Add' incorporates:
    //   Constant: '<S20>/Constant'
    //   Constant: '<S34>/Constant2'
    //   Product: '<S34>/Divide'
    //   Product: '<S34>/Product'
    //   Sum: '<S18>/Add12'

    Pix_FCC_flash_B.pulse_width_ms = (Pix_FCC_flash_B.pulse_width_ms_k +
      Pix_FCC_flash_B.pulse_width_ms) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S34>/Saturation'
    if (Pix_FCC_flash_B.pulse_width_ms >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.pulse_width_ms =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.pulse_width_ms <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.pulse_width_ms =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S34>/Saturation'

    // Sum: '<S35>/Add' incorporates:
    //   Constant: '<S20>/Constant'
    //   Constant: '<S35>/Constant2'
    //   Product: '<S35>/Divide'
    //   Product: '<S35>/Product'
    //   Sum: '<S18>/Add13'

    Pix_FCC_flash_B.Product2 = (Pix_FCC_flash_B.pulse_width_ms_k +
      Pix_FCC_flash_B.Product2) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S35>/Saturation'
    if (Pix_FCC_flash_B.Product2 >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.Product2 =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.Product2 <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.Product2 =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S35>/Saturation'

    // Sum: '<S36>/Add' incorporates:
    //   Constant: '<S20>/Constant'
    //   Constant: '<S36>/Constant2'
    //   Product: '<S36>/Divide'
    //   Product: '<S36>/Product'
    //   Sum: '<S18>/Add14'

    Pix_FCC_flash_B.pulse_width_ms_k = (Pix_FCC_flash_B.pulse_width_ms_k +
      Pix_FCC_flash_B.pulse_width_ms_o) /
      Pix_FCC_flash_P.FCC_PIX_Data.Control_Surfaces.max_deflection_rad *
      Pix_FCC_flash_B.Add16 +
      Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_middle_pos_ms;

    // Saturate: '<S36>/Saturation'
    if (Pix_FCC_flash_B.pulse_width_ms_k >
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms) {
      Pix_FCC_flash_B.pulse_width_ms_k =
        Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_max_ms;
    } else {
      if (Pix_FCC_flash_B.pulse_width_ms_k <
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms) {
        Pix_FCC_flash_B.pulse_width_ms_k =
          Pix_FCC_flash_P.FCC_PIX_Data.Servo.PWM.Pulswidth_cmd_min_ms;
      }
    }

    // End of Saturate: '<S36>/Saturation'

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/OUTPUT'

    // MATLAB Function: '<S40>/MessageAssembly' incorporates:
    //   Constant: '<S40>/Constant'
    //   MATLAB Function: '<S10>/DefineRCStatus'
    //   MATLAB Function: '<S10>/DefineStatus'
    //   MATLAB Function: '<S40>/convert2uint8'
    //   SignalConversion generated from: '<S44>/ SFunction '

    if (Pix_FCC_flash_P.Constant_Value_h == 1.0) {
      memcpy((void *)&x[0], (void *)&Pix_FCC_flash_B.SimHeartbeat_update,
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      package[0] = x[0];
      package[1] = x[1];

      // Outputs for Function Call SubSystem: '<S2>/ACTION'
      package[2] = static_cast<uint8_T>(rtb_mode);
      package[3] = Pix_FCC_flash_B.packetfound;

      // End of Outputs for SubSystem: '<S2>/ACTION'
      memcpy((void *)&Pix_FCC_flash_B.TmpSignalConversionAtSFunct[0], (void *)
             &package[0], (uint32_T)((size_t)1 * sizeof(real32_T)));
    } else {
      // SignalConversion generated from: '<S44>/ SFunction ' incorporates:
      //   MATLAB Function: '<S40>/convert2uint8'

      Pix_FCC_flash_B.TmpSignalConversionAtSFunct[0] = 0.0F;
    }

    // End of MATLAB Function: '<S40>/MessageAssembly'

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // SignalConversion generated from: '<S44>/ SFunction ' incorporates:
    //   DataTypeConversion: '<S10>/Data Type Conversion'
    //   Inport: '<S10>/Estimator'
    //   Inport: '<S10>/SensorData'
    //   Inport: '<S10>/TestSignal'
    //   MATLAB Function: '<S40>/convert2uint8'

    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[1] = static_cast<real32_T>
      (Pix_FCC_flash_B.Product3);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[2] = static_cast<real32_T>
      (Pix_FCC_flash_B.pulse_width_ms);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[3] = static_cast<real32_T>
      (Pix_FCC_flash_B.Product2);
    Pix_FCC_flash_B.TmpSignalConversionAtSFunct[4] = static_cast<real32_T>
      (Pix_FCC_flash_B.pulse_width_ms_k);
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

    // MATLAB Function: '<S40>/convert2uint8'
    memcpy((void *)&Pix_FCC_flash_B.msgOut[0], (void *)
           &Pix_FCC_flash_B.TmpSignalConversionAtSFunct[0], (uint32_T)((size_t)
            64 * sizeof(uint8_T)));

    // SignalConversion generated from: '<S40>/Serial Transmit' incorporates:
    //   Constant: '<S40>/Header'
    //   Constant: '<S40>/Header1'

    Pix_FCC_flash_B.TmpSignalConversionAtSerial[0] =
      Pix_FCC_flash_P.Header_Value[0];
    Pix_FCC_flash_B.TmpSignalConversionAtSerial[1] =
      Pix_FCC_flash_P.Header_Value[1];
    Pix_FCC_flash_B.TmpSignalConversionAtSerial[2] =
      Pix_FCC_flash_P.Header_Value[2];
    Pix_FCC_flash_B.TmpSignalConversionAtSerial[67] =
      Pix_FCC_flash_P.Header1_Value[0];
    Pix_FCC_flash_B.TmpSignalConversionAtSerial[68] =
      Pix_FCC_flash_P.Header1_Value[1];
    Pix_FCC_flash_B.TmpSignalConversionAtSerial[69] =
      Pix_FCC_flash_P.Header1_Value[2];
    for (b_ii = 0; b_ii < 64; b_ii++) {
      Pix_FCC_flash_B.TmpSignalConversionAtSerial[b_ii + 3] =
        Pix_FCC_flash_B.msgOut[b_ii];
      Pix_FCC_flash_B.TmpSignalConversionAtSerial[b_ii + 70] =
        Pix_FCC_flash_B.msgOut[b_ii];
    }

    // End of SignalConversion generated from: '<S40>/Serial Transmit'

    // MATLABSystem: '<S40>/Serial Transmit'
    memcpy((void *)&Pix_FCC_flash_B.TxDataLocChar[0], (void *)
           &Pix_FCC_flash_B.TmpSignalConversionAtSerial[0], (uint32_T)((size_t)
            134 * sizeof(uint8_T)));
    MW_SCI_Transmit(Pix_FCC_flash_DW.obj_i.MW_SCIHANDLE,
                    Pix_FCC_flash_B.TxDataLocChar, 134U);

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    // DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
    //   DataTypeConversion: '<S10>/Data Type Conversion'

    CMD1 = static_cast<real32_T>(floor(static_cast<real_T>(static_cast<real32_T>
      (Pix_FCC_flash_B.Product3))));
    if (rtIsNaNF(CMD1) || rtIsInfF(CMD1)) {
      CMD1 = 0.0F;
    } else {
      CMD1 = static_cast<real32_T>(fmod(static_cast<real_T>(CMD1), 65536.0));
    }

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    CMD2 = static_cast<real32_T>(floor(static_cast<real_T>(static_cast<real32_T>
      (Pix_FCC_flash_B.pulse_width_ms))));
    if (rtIsNaNF(CMD2) || rtIsInfF(CMD2)) {
      CMD2 = 0.0F;
    } else {
      CMD2 = static_cast<real32_T>(fmod(static_cast<real_T>(CMD2), 65536.0));
    }

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    CMD3 = static_cast<real32_T>(floor(static_cast<real_T>(static_cast<real32_T>
      (Pix_FCC_flash_B.Product2))));
    if (rtIsNaNF(CMD3) || rtIsInfF(CMD3)) {
      CMD3 = 0.0F;
    } else {
      CMD3 = static_cast<real32_T>(fmod(static_cast<real_T>(CMD3), 65536.0));
    }

    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 

    // S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
    //   SubSystem: '<S2>/ACTION'

    ACC1 = static_cast<real32_T>(floor(static_cast<real_T>(static_cast<real32_T>
      (Pix_FCC_flash_B.pulse_width_ms_k))));
    if (rtIsNaNF(ACC1) || rtIsInfF(ACC1)) {
      ACC1 = 0.0F;
    } else {
      ACC1 = static_cast<real32_T>(fmod(static_cast<real_T>(ACC1), 65536.0));
    }

    // MATLABSystem: '<S39>/PX4 PWM Output' incorporates:
    //   Constant: '<S11>/HIL_detect_flg'
    //   Constant: '<S11>/PWM_arm_flg'
    //   Constant: '<S11>/Recovery_activation_flg'
    //   DataTypeConversion: '<S11>/Data Type Conversion3'
    //   Gain: '<S39>/ms2us_1'
    //   Gain: '<S39>/ms2us_2'
    //   Gain: '<S39>/ms2us_3'
    //   Gain: '<S39>/ms2us_4'

    if (Pix_FCC_flash_P.PWM_arm_flg_Value) {
      if (!Pix_FCC_flash_DW.obj_j.isArmed) {
        Pix_FCC_flash_DW.obj_j.isArmed = true;
        status = pwm_arm(&Pix_FCC_flash_DW.obj_j.pwmDevHandler);
        Pix_FCC_flash_DW.obj_j.errorStatus = static_cast<uint16_T>
          ((Pix_FCC_flash_DW.obj_j.errorStatus | status));
      }

      for (b_ii = 0; b_ii < 8; b_ii++) {
        Pix_FCC_flash_B.pwmValue[b_ii] = 0U;
      }

      Pix_FCC_flash_B.pwmValue[0] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((CMD1 < 0.0F ? static_cast<int32_T>
        (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-CMD1))))
        : static_cast<int32_T>(static_cast<uint16_T>(CMD1))))) *
        Pix_FCC_flash_P.ms2us_1_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[1] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((CMD2 < 0.0F ? static_cast<int32_T>
        (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-CMD2))))
        : static_cast<int32_T>(static_cast<uint16_T>(CMD2))))) *
        Pix_FCC_flash_P.ms2us_2_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[2] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((CMD3 < 0.0F ? static_cast<int32_T>
        (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-CMD3))))
        : static_cast<int32_T>(static_cast<uint16_T>(CMD3))))) *
        Pix_FCC_flash_P.ms2us_3_Gain) >> 6));
      Pix_FCC_flash_B.pwmValue[3] = static_cast<uint16_T>(((static_cast<uint32_T>
        (static_cast<uint16_T>((ACC1 < 0.0F ? static_cast<int32_T>
        (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-ACC1))))
        : static_cast<int32_T>(static_cast<uint16_T>(ACC1))))) *
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

    // End of MATLABSystem: '<S39>/PX4 PWM Output'
    // End of Outputs for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  }

  // End of Outputs for SubSystem: '<Root>/ExecutionCycle'
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

  // Start for MATLABSystem: '<Root>/Receive Data'
  Pix_FCC_flash_DW.obj.isInitialized = 0;
  Pix_FCC_flash_DW.obj.matlabCodegenIsDeleted = false;
  Pix_FCC_flash_DW.obj.SampleTime = Pix_FCC_flash_P.ReceiveData_SampleTime;
  Pix_FCC_flash_SystemCore_setup(&Pix_FCC_flash_DW.obj);

  // Start for MATLABSystem: '<S55>/SourceBlock'
  Pix_FCC_flash_DW.obj_d.matlabCodegenIsDeleted = false;
  Pix_FCC_flash_DW.obj_d.isSetupComplete = false;
  Pix_FCC_flash_DW.obj_d.isInitialized = 1;
  Pix_FCC_flash_DW.obj_d.orbMetadataObj = ORB_ID(sensor_accel);
  uORB_read_initialize(Pix_FCC_flash_DW.obj_d.orbMetadataObj,
                       &Pix_FCC_flash_DW.obj_d.eventStructObj);
  Pix_FCC_flash_DW.obj_d.isSetupComplete = true;

  // Start for MATLABSystem: '<S57>/SourceBlock'
  Pix_FCC_flash_DW.obj_f.matlabCodegenIsDeleted = false;
  Pix_FCC_flash_DW.obj_f.isSetupComplete = false;
  Pix_FCC_flash_DW.obj_f.isInitialized = 1;
  Pix_FCC_flash_DW.obj_f.orbMetadataObj = ORB_ID(sensor_gyro);
  uORB_read_initialize(Pix_FCC_flash_DW.obj_f.orbMetadataObj,
                       &Pix_FCC_flash_DW.obj_f.eventStructObj);
  Pix_FCC_flash_DW.obj_f.isSetupComplete = true;

  // Start for MATLABSystem: '<S59>/SourceBlock'
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

  // Start for MATLABSystem: '<S40>/Serial Transmit'
  Pix_FCC_flash_DW.obj_i.isInitialized = 0;
  Pix_FCC_flash_DW.obj_i.matlabCodegenIsDeleted = false;
  Pix_FCC_fla_SystemCore_setup_b2(&Pix_FCC_flash_DW.obj_i);

  // Start for MATLABSystem: '<S39>/PX4 PWM Output' incorporates:
  //   Constant: '<S11>/PWM_arm_flg'

  Pix_FCC_flash_DW.obj_j.errorStatus = 0U;
  Pix_FCC_flash_DW.obj_j.isInitialized = 0;
  Pix_FCC_flash_DW.obj_j.matlabCodegenIsDeleted = false;
  Pix_FCC_flas_SystemCore_setup_b(&Pix_FCC_flash_DW.obj_j,
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

  // SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S56>/Out1'
  Pix_FCC_flash_B.In1_j = Pix_FCC_flash_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S57>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S58>/Out1'
  Pix_FCC_flash_B.In1 = Pix_FCC_flash_P.Out1_Y0_f;

  // End of SystemInitialize for SubSystem: '<S57>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S59>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S60>/Out1'
  Pix_FCC_flash_B.In1_c = Pix_FCC_flash_P.Out1_Y0_a;

  // End of SystemInitialize for SubSystem: '<S59>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<Root>/ExecutionCycle'
  // SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
  //   SubSystem: '<S2>/process_received_data'

  // SystemInitialize for Enabled SubSystem: '<S13>/input_hold'
  // SystemInitialize for Enabled SubSystem: '<S48>/hold'
  // SystemInitialize for Outport: '<S51>/SimHeartbeat'
  Pix_FCC_flash_B.SimHeartbeat_update = Pix_FCC_flash_P.SimHeartbeat_Y0;

  // SystemInitialize for Outport: '<S51>/CMD'
  Pix_FCC_flash_B.CMD_update[0] = Pix_FCC_flash_P.CMD_Y0;
  Pix_FCC_flash_B.CMD_update[1] = Pix_FCC_flash_P.CMD_Y0;
  Pix_FCC_flash_B.CMD_update[2] = Pix_FCC_flash_P.CMD_Y0;

  // SystemInitialize for Outport: '<S51>/TestSignal'
  Pix_FCC_flash_B.TestSignal_update = Pix_FCC_flash_P.TestSignal_Y0;

  // End of SystemInitialize for SubSystem: '<S48>/hold'

  // SystemInitialize for Outport: '<S48>/packetfound_flg'
  Pix_FCC_flash_B.packetfound = Pix_FCC_flash_P.packetfound_flg_Y0;

  // End of SystemInitialize for SubSystem: '<S13>/input_hold'
  // End of SystemInitialize for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  // End of SystemInitialize for SubSystem: '<Root>/ExecutionCycle'
}

// Model terminate function
void Pix_FCC_flash_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Receive Data'
  matlabCodegenHandle_matlabCodeg(&Pix_FCC_flash_DW.obj);

  // Terminate for MATLABSystem: '<S55>/SourceBlock'
  matlabCodegenHandle_matlabC_b2q(&Pix_FCC_flash_DW.obj_d);

  // Terminate for MATLABSystem: '<S57>/SourceBlock'
  matlabCodegenHandle_matlabC_b2q(&Pix_FCC_flash_DW.obj_f);

  // Terminate for MATLABSystem: '<S59>/SourceBlock'
  matlabCodegenHandle_matlabC_b2q(&Pix_FCC_flash_DW.obj_c);

  // Terminate for Enabled SubSystem: '<Root>/ExecutionCycle'
  // Terminate for S-Function (fcncallgen): '<S2>/Function-Call Generator2' incorporates:
  //   SubSystem: '<S2>/OUTPUT'

  // Terminate for MATLABSystem: '<S40>/Serial Transmit'
  matlabCodegenHandle_matlabCo_b2(&Pix_FCC_flash_DW.obj_i);

  // Terminate for MATLABSystem: '<S39>/PX4 PWM Output'
  matlabCodegenHandle_matlabCod_b(&Pix_FCC_flash_DW.obj_j);

  // End of Terminate for S-Function (fcncallgen): '<S2>/Function-Call Generator2' 
  // End of Terminate for SubSystem: '<Root>/ExecutionCycle'
}

//
// File trailer for generated code.
//
// [EOF]
//

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_serial.cpp
//
// Code generated for Simulink model 'px4demo_serial'.
//
// Model version                  : 1.139
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Jan  1 16:26:42 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4demo_serial.h"
#include "px4demo_serial_private.h"

// Block signals (default storage)
B_px4demo_serial_T px4demo_serial_B;

// Block states (default storage)
DW_px4demo_serial_T px4demo_serial_DW;

// Real-time model
RT_MODEL_px4demo_serial_T px4demo_serial_M_ = RT_MODEL_px4demo_serial_T();
RT_MODEL_px4demo_serial_T *const px4demo_serial_M = &px4demo_serial_M_;

// Forward declaration for local functions
static void px4demo_serial_nullAssignment(real_T x_data[], int32_T x_size[2],
  const boolean_T idx_data[], const int32_T idx_size[2]);
static void px4demo_seri_SystemCore_release(const
  px4_internal_block_PX4SCIRead_T *obj);
static void px4demo_seria_SystemCore_delete(const
  px4_internal_block_PX4SCIRead_T *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIRead_T *obj);
static void px4demo_se_SystemCore_release_i(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void px4demo_ser_SystemCore_delete_i(const
  px4_internal_block_PX4SCIWrit_T *obj);
static void matlabCodegenHandle_matlabCod_i(px4_internal_block_PX4SCIWrit_T *obj);
static void px4demo__SystemCore_release_i3i(const
  px4_internal_block_Subscriber_T *obj);
static void px4demo_s_SystemCore_delete_i3i(const
  px4_internal_block_Subscriber_T *obj);
static void matlabCodegenHandle_matlabC_i3i(px4_internal_block_Subscriber_T *obj);
static void px4demo_serial_SystemCore_setup(px4_internal_block_PX4SCIRead_T *obj);
static void px4demo_seri_SystemCore_setup_i(px4_internal_block_PX4SCIWrit_T *obj);

// Function for MATLAB Function: '<S1>/MATLAB Function'
static void px4demo_serial_nullAssignment(real_T x_data[], int32_T x_size[2],
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

static void px4demo_seri_SystemCore_release(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void px4demo_seria_SystemCore_delete(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  px4demo_seri_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIRead_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    px4demo_seria_SystemCore_delete(obj);
  }
}

static void px4demo_se_SystemCore_release_i(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void px4demo_ser_SystemCore_delete_i(const
  px4_internal_block_PX4SCIWrit_T *obj)
{
  px4demo_se_SystemCore_release_i(obj);
}

static void matlabCodegenHandle_matlabCod_i(px4_internal_block_PX4SCIWrit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    px4demo_ser_SystemCore_delete_i(obj);
  }
}

static void px4demo__SystemCore_release_i3i(const
  px4_internal_block_Subscriber_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_read_terminate(&obj->eventStructObj);
  }
}

static void px4demo_s_SystemCore_delete_i3i(const
  px4_internal_block_Subscriber_T *obj)
{
  px4demo__SystemCore_release_i3i(obj);
}

static void matlabCodegenHandle_matlabC_i3i(px4_internal_block_Subscriber_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    px4demo_s_SystemCore_delete_i3i(obj);
  }
}

static void px4demo_serial_SystemCore_setup(px4_internal_block_PX4SCIRead_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  char_T SCIModuleLoc[11];
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_HardwareFlowControl_Type HardwareFlowControlValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '3' };

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

static void px4demo_seri_SystemCore_setup_i(px4_internal_block_PX4SCIWrit_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  char_T SCIModuleLoc[11];
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  int32_T i;
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '3' };

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

// Model step function
void px4demo_serial_step(void)
{
  uint8_T sizeptr;
  boolean_T packetfound;
  boolean_T b_p;
  int32_T idx;
  int32_T b_ii;
  uint8_T TxDataLocChar[2];
  int32_T rtb_en;
  int32_T loop_ub;
  int32_T tmp_size[2];
  int32_T start_size[2];
  real_T tmp;
  boolean_T exitg1;

  // MATLABSystem: '<Root>/Serial Receive1' incorporates:
  //   DataTypeConversion: '<S1>/Data Type Conversion'
  //   Inport: '<S8>/In1'
  //   MATLABSystem: '<S7>/SourceBlock'

  if (px4demo_serial_DW.obj.SampleTime !=
      px4demo_serial_P.SerialReceive1_SampleTime) {
    px4demo_serial_DW.obj.SampleTime =
      px4demo_serial_P.SerialReceive1_SampleTime;
  }

  MW_SCI_GetDataBytesAvailable(px4demo_serial_DW.obj.MW_SCIHANDLE, false,
    &sizeptr, 5);
  if (sizeptr >= 10U) {
    MW_SCI_Receive(px4demo_serial_DW.obj.MW_SCIHANDLE,
                   px4demo_serial_B.RxDataLocChar, 10U);
    memcpy((void *)&px4demo_serial_B.RxData[0], (void *)
           &px4demo_serial_B.RxDataLocChar[0], (uint32_T)((size_t)10 * sizeof
            (uint8_T)));

    // Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
    //   EnablePort: '<S1>/Enable'

    // MATLAB Function: '<S1>/MATLAB Function'
    rtb_en = 3;
    px4demo_serial_B.packet_data[0] = 0U;
    px4demo_serial_B.packet_data[1] = 0U;
    px4demo_serial_B.packet_data[2] = 0U;
    packetfound = false;
    for (b_ii = 0; b_ii < 10; b_ii++) {
      px4demo_serial_B.x[b_ii] = (px4demo_serial_B.RxData[b_ii] == 7);
    }

    idx = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 10)) {
      if (px4demo_serial_B.x[b_ii]) {
        idx++;
        px4demo_serial_B.ii_data[idx - 1] = static_cast<int8_T>((b_ii + 1));
        if (idx >= 10) {
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

    px4demo_serial_B.start_size[0] = 1;
    px4demo_serial_B.start_size[1] = idx;
    loop_ub = idx - 1;
    for (b_ii = 0; b_ii <= loop_ub; b_ii++) {
      px4demo_serial_B.start_data[b_ii] = px4demo_serial_B.ii_data[b_ii];
    }

    start_size[0] = 1;
    start_size[1] = idx;
    for (b_ii = 0; b_ii < idx; b_ii++) {
      px4demo_serial_B.x[b_ii] = ((px4demo_serial_B.start_data[b_ii] + 2.0) -
        1.0 > 10.0);
    }

    px4demo_serial_nullAssignment(px4demo_serial_B.start_data,
      px4demo_serial_B.start_size, px4demo_serial_B.x, start_size);
    tmp_size[0] = 1;
    tmp_size[1] = px4demo_serial_B.start_size[1];
    loop_ub = px4demo_serial_B.start_size[0] * px4demo_serial_B.start_size[1];
    for (b_ii = 0; b_ii < loop_ub; b_ii++) {
      px4demo_serial_B.x[b_ii] = (px4demo_serial_B.RxData[static_cast<int32_T>
        (((px4demo_serial_B.start_data[b_ii] + 2.0) - 1.0)) - 1] != 7);
    }

    px4demo_serial_nullAssignment(px4demo_serial_B.start_data,
      px4demo_serial_B.start_size, px4demo_serial_B.x, tmp_size);
    if (px4demo_serial_B.start_size[1] != 0) {
      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= px4demo_serial_B.start_size[1] - 1)) {
        b_p = false;
        tmp = px4demo_serial_B.start_data[b_ii + 1];
        if (tmp - px4demo_serial_B.start_data[b_ii] == 5.0) {
          b_p = true;
        }

        if (b_p) {
          if (px4demo_serial_B.start_data[b_ii] + 2.0 > tmp - 1.0) {
            idx = 0;
            rtb_en = 0;
          } else {
            idx = static_cast<int32_T>((px4demo_serial_B.start_data[b_ii] + 2.0))
              - 1;
            rtb_en = static_cast<int32_T>((px4demo_serial_B.start_data[b_ii + 1]
              - 1.0));
          }

          rtb_en -= idx;
          for (b_ii = 0; b_ii < rtb_en; b_ii++) {
            px4demo_serial_B.packet_data[b_ii] = px4demo_serial_B.RxData[idx +
              b_ii];
          }

          packetfound = true;
          exitg1 = true;
        } else {
          b_ii++;
        }
      }
    }

    if (packetfound) {
      packetfound = false;
      b_p = false;
      if (rtb_en == 3) {
        b_p = true;
      }

      if (b_p && (rtb_en != 0)) {
        rtb_en = 0;
        exitg1 = false;
        while ((!exitg1) && (rtb_en < 3)) {
          if (px4demo_serial_B.packet_data[rtb_en] != 9) {
            b_p = false;
            exitg1 = true;
          } else {
            rtb_en++;
          }
        }
      }

      if (b_p) {
        packetfound = true;
      }

      rtb_en = packetfound;
    } else {
      rtb_en = 0;
    }

    // End of MATLAB Function: '<S1>/MATLAB Function'

    // Outputs for Enabled SubSystem: '<S1>/Send Accelerometer Data' incorporates:
    //   EnablePort: '<S3>/Enable'

    if (rtb_en > 0) {
      // S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S3>/Send Header Subsystem'

      // MATLABSystem: '<S5>/Serial Transmit' incorporates:
      //   Constant: '<S5>/Header'

      memcpy((void *)&TxDataLocChar[0], (void *)&px4demo_serial_P.Header_Value[0],
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      MW_SCI_Transmit(px4demo_serial_DW.obj_l.MW_SCIHANDLE, TxDataLocChar, 2U);

      // S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
      //   SubSystem: '<S3>/Send Accel Data - Subsystem'

      // MATLABSystem: '<S7>/SourceBlock'
      packetfound = uORB_read_step(px4demo_serial_DW.obj_g.orbMetadataObj,
        &px4demo_serial_DW.obj_g.eventStructObj, &px4demo_serial_B.b_varargout_2,
        false, 1.0);

      // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S8>/Enable'

      if (packetfound) {
        px4demo_serial_B.In1 = px4demo_serial_B.b_varargout_2;
      }

      // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

      // SignalConversion generated from: '<S4>/Serial Transmit' incorporates:
      //   Inport: '<S8>/In1'
      //   MATLABSystem: '<S7>/SourceBlock'

      px4demo_serial_B.TmpSignalConversionAtSerial[0] = px4demo_serial_B.In1.x;
      px4demo_serial_B.TmpSignalConversionAtSerial[1] = px4demo_serial_B.In1.y;
      px4demo_serial_B.TmpSignalConversionAtSerial[2] = px4demo_serial_B.In1.z;

      // MATLABSystem: '<S4>/Serial Transmit'
      memcpy((void *)&px4demo_serial_B.TxDataLocChar[0], (void *)
             &px4demo_serial_B.TmpSignalConversionAtSerial[0], (uint32_T)
             ((size_t)12 * sizeof(uint8_T)));
      MW_SCI_Transmit(px4demo_serial_DW.obj_e.MW_SCIHANDLE,
                      px4demo_serial_B.TxDataLocChar, 12U);

      // End of Outputs for S-Function (fcncallgen): '<S3>/Function-Call Generator1' 
    }

    // End of Outputs for SubSystem: '<S1>/Send Accelerometer Data'
    // End of Outputs for SubSystem: '<Root>/Subsystem'
  }

  // End of MATLABSystem: '<Root>/Serial Receive1'
}

// Model initialize function
void px4demo_serial_initialize(void)
{
  // Start for MATLABSystem: '<Root>/Serial Receive1'
  px4demo_serial_DW.obj.isInitialized = 0;
  px4demo_serial_DW.obj.matlabCodegenIsDeleted = false;
  px4demo_serial_DW.obj.SampleTime = px4demo_serial_P.SerialReceive1_SampleTime;
  px4demo_serial_SystemCore_setup(&px4demo_serial_DW.obj);

  // Start for Enabled SubSystem: '<Root>/Subsystem'
  // Start for Enabled SubSystem: '<S1>/Send Accelerometer Data'
  // Start for S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S3>/Send Header Subsystem'

  // Start for MATLABSystem: '<S5>/Serial Transmit'
  px4demo_serial_DW.obj_l.isInitialized = 0;
  px4demo_serial_DW.obj_l.matlabCodegenIsDeleted = false;
  px4demo_seri_SystemCore_setup_i(&px4demo_serial_DW.obj_l);

  // Start for S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S3>/Send Accel Data - Subsystem'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  px4demo_serial_DW.obj_g.matlabCodegenIsDeleted = false;
  px4demo_serial_DW.obj_g.isSetupComplete = false;
  px4demo_serial_DW.obj_g.isInitialized = 1;
  px4demo_serial_DW.obj_g.orbMetadataObj = ORB_ID(sensor_accel);
  uORB_read_initialize(px4demo_serial_DW.obj_g.orbMetadataObj,
                       &px4demo_serial_DW.obj_g.eventStructObj);
  px4demo_serial_DW.obj_g.isSetupComplete = true;

  // Start for MATLABSystem: '<S4>/Serial Transmit'
  px4demo_serial_DW.obj_e.isInitialized = 0;
  px4demo_serial_DW.obj_e.matlabCodegenIsDeleted = false;
  px4demo_seri_SystemCore_setup_i(&px4demo_serial_DW.obj_e);

  // End of Start for S-Function (fcncallgen): '<S3>/Function-Call Generator1'
  // End of Start for SubSystem: '<S1>/Send Accelerometer Data'
  // End of Start for SubSystem: '<Root>/Subsystem'

  // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem'
  // SystemInitialize for Enabled SubSystem: '<S1>/Send Accelerometer Data'
  // SystemInitialize for S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S3>/Send Accel Data - Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S8>/Out1'
  px4demo_serial_B.In1 = px4demo_serial_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'
  // End of SystemInitialize for S-Function (fcncallgen): '<S3>/Function-Call Generator1' 
  // End of SystemInitialize for SubSystem: '<S1>/Send Accelerometer Data'
  // End of SystemInitialize for SubSystem: '<Root>/Subsystem'
}

// Model terminate function
void px4demo_serial_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Serial Receive1'
  matlabCodegenHandle_matlabCodeg(&px4demo_serial_DW.obj);

  // Terminate for Enabled SubSystem: '<Root>/Subsystem'
  // Terminate for Enabled SubSystem: '<S1>/Send Accelerometer Data'
  // Terminate for S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S3>/Send Header Subsystem'

  // Terminate for MATLABSystem: '<S5>/Serial Transmit'
  matlabCodegenHandle_matlabCod_i(&px4demo_serial_DW.obj_l);

  // Terminate for S-Function (fcncallgen): '<S3>/Function-Call Generator1' incorporates:
  //   SubSystem: '<S3>/Send Accel Data - Subsystem'

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  matlabCodegenHandle_matlabC_i3i(&px4demo_serial_DW.obj_g);

  // Terminate for MATLABSystem: '<S4>/Serial Transmit'
  matlabCodegenHandle_matlabCod_i(&px4demo_serial_DW.obj_e);

  // End of Terminate for S-Function (fcncallgen): '<S3>/Function-Call Generator1' 
  // End of Terminate for SubSystem: '<S1>/Send Accelerometer Data'
  // End of Terminate for SubSystem: '<Root>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//

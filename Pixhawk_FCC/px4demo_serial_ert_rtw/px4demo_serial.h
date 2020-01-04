//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_serial.h
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
#ifndef RTW_HEADER_px4demo_serial_h_
#define RTW_HEADER_px4demo_serial_h_
#include <string.h>
#include <stddef.h>
#ifndef px4demo_serial_COMMON_INCLUDES_
# define px4demo_serial_COMMON_INCLUDES_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_PX4_SCI.h"
#include "MW_SCI.h"
#include "MW_uORB_Read.h"
#endif                                 // px4demo_serial_COMMON_INCLUDES_

#include "px4demo_serial_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real_T start_data[10];
  px4_Bus_sensor_accel In1;            // '<S8>/In1'
  px4_Bus_sensor_accel b_varargout_2;
  uint8_T TxDataLocChar[12];
  real32_T TmpSignalConversionAtSerial[3];
  boolean_T x[10];
  int8_T ii_data[10];
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];
  uint8_T packet_data[9];
  int32_T start_size[2];
} B_px4demo_serial_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_PX4SCIRead_T obj; // '<Root>/Serial Receive1'
  px4_internal_block_Subscriber_T obj_g;// '<S7>/SourceBlock'
  px4_internal_block_PX4SCIWrit_T obj_e;// '<S4>/Serial Transmit'
  px4_internal_block_PX4SCIWrit_T obj_l;// '<S5>/Serial Transmit'
} DW_px4demo_serial_T;

// Parameters (default storage)
struct P_px4demo_serial_T_ {
  px4_Bus_sensor_accel Out1_Y0;        // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S8>/Out1'

  px4_Bus_sensor_accel Constant_Value; // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S7>/Constant'

  real_T SerialReceive1_SampleTime;    // Expression: 0.1
                                          //  Referenced by: '<Root>/Serial Receive1'

  uint8_T Header_Value[2];             // Computed Parameter: Header_Value
                                          //  Referenced by: '<S5>/Header'

};

// Real-time Model Data Structure
struct tag_RTM_px4demo_serial_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_px4demo_serial_T px4demo_serial_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_px4demo_serial_T px4demo_serial_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_px4demo_serial_T px4demo_serial_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px4demo_serial_initialize(void);
  extern void px4demo_serial_step(void);
  extern void px4demo_serial_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px4demo_serial_T *const px4demo_serial_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/NOT' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'px4demo_serial'
//  '<S1>'   : 'px4demo_serial/Subsystem'
//  '<S2>'   : 'px4demo_serial/Subsystem/MATLAB Function'
//  '<S3>'   : 'px4demo_serial/Subsystem/Send Accelerometer Data'
//  '<S4>'   : 'px4demo_serial/Subsystem/Send Accelerometer Data/Send Accel Data - Subsystem'
//  '<S5>'   : 'px4demo_serial/Subsystem/Send Accelerometer Data/Send Header Subsystem'
//  '<S6>'   : 'px4demo_serial/Subsystem/Send Accelerometer Data/Send Accel Data - Subsystem/Accelerometer'
//  '<S7>'   : 'px4demo_serial/Subsystem/Send Accelerometer Data/Send Accel Data - Subsystem/Accelerometer/PX4 uORB Read'
//  '<S8>'   : 'px4demo_serial/Subsystem/Send Accelerometer Data/Send Accel Data - Subsystem/Accelerometer/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_px4demo_serial_h_

//
// File trailer for generated code.
//
// [EOF]
//

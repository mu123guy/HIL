//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash.h
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
#ifndef RTW_HEADER_Pix_FCC_flash_h_
#define RTW_HEADER_Pix_FCC_flash_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Pix_FCC_flash_COMMON_INCLUDES_
# define Pix_FCC_flash_COMMON_INCLUDES_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_PX4_SCI.h"
#include "MW_SCI.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#endif                                 // Pix_FCC_flash_COMMON_INCLUDES_

#include "Pix_FCC_flash_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real_T start_data[128];
  real_T start_data_m[128];
  uint8_T TxDataLocChar[134];
  uint8_T TmpSignalConversionAtSerial[134];
  boolean_T x[128];
  uint8_T RxData[128];
  uint8_T RxDataLocChar[128];
  uint8_T packet_data[127];
  uint8_T packet_data_c[127];
  px4_Bus_sensor_accel In1_j;          // '<S56>/In1'
  px4_Bus_sensor_accel b_varargout_2;
  px4_Bus_sensor_gyro In1;             // '<S58>/In1'
  px4_Bus_sensor_gyro b_varargout_2_k;
  uint8_T msgOut[64];                  // '<S40>/convert2uint8'
  real32_T TmpSignalConversionAtSFunct[16];// '<S40>/convert2uint8'
  px4_Bus_vehicle_attitude In1_c;      // '<S60>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_c;
  uint8_T message[56];                 // '<S48>/ExtractMessage'
  uint16_T pwmValue[8];
  real32_T CMD_update[3];              // '<S51>/CMD_update'
  real_T pulse_width_ms_k;             // '<S36>/Saturation'
  real_T pulse_width_ms;               // '<S35>/Saturation'
  real_T pulse_width_ms_o;             // '<S33>/Saturation'
  real_T Product3;                     // '<S26>/Product3'
  real_T Product2;                     // '<S26>/Product2'
  real_T Add16;                        // '<S18>/Add16'
  real_T Abs1;                         // '<S24>/Abs1'
  int32_T start_size[2];
  int32_T start_size_b[2];
  int32_T tmp_size[2];
  int32_T start_size_p[2];
  int32_T tmp_size_c[2];
  int32_T start_size_f[2];
  real32_T TestSignal_update;          // '<S51>/TestSignal_update'
  uint16_T SimHeartbeat_update;        // '<S51>/SimHeartbeat_update'
  uint8_T update[4];                   // '<S8>/update'
  uint8_T cmd[4];                      // '<S6>/DecodeCommand'
  boolean_T packetfound;               // '<S48>/ExtractMessage'
  boolean_T cmd_found_flg;             // '<S6>/DecodeCommand'
} B_Pix_FCC_flash_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_PX4SCIRead_T obj; // '<Root>/Receive Data'
  px4_internal_block_PWM_Pix_FC_T obj_j;// '<S39>/PX4 PWM Output'
  px4_internal_block_PX4SCIWrit_T obj_i;// '<S40>/Serial Transmit'
  px4_internal_block_Subscriber_T obj_c;// '<S59>/SourceBlock'
  px4_internal_block_Subscriber_T obj_f;// '<S57>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S55>/SourceBlock'
  int32_T SFunction_DIMS2[2];          // '<S48>/ExtractMessage'
  int32_T update_DIMS1[2];             // '<S8>/update'
  int32_T SFunction_DIMS2_f[2];        // '<S6>/DecodeCommand'
} DW_Pix_FCC_flash_T;

// Parameters (default storage)
struct P_Pix_FCC_flash_T_ {
  struct_kDC9SqVquJgNZQDtb5tZbG FCC_PIX_Data;// Variable: FCC_PIX_Data
                                                //  Referenced by:
                                                //    '<S18>/Constant'
                                                //    '<S18>/Constant1'
                                                //    '<S18>/Constant2'
                                                //    '<S18>/Constant3'
                                                //    '<S18>/Constant4'
                                                //    '<S18>/Limit2maxDeflection'
                                                //    '<S20>/Constant'
                                                //    '<S33>/Constant2'
                                                //    '<S33>/Constant6'
                                                //    '<S33>/Saturation'
                                                //    '<S34>/Constant2'
                                                //    '<S34>/Constant6'
                                                //    '<S34>/Saturation'
                                                //    '<S35>/Constant2'
                                                //    '<S35>/Constant6'
                                                //    '<S35>/Saturation'
                                                //    '<S36>/Constant2'
                                                //    '<S36>/Constant6'
                                                //    '<S36>/Saturation'

  px4_Bus_sensor_accel Out1_Y0;        // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S56>/Out1'

  px4_Bus_sensor_accel Constant_Value; // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S55>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_f;       // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S58>/Out1'

  px4_Bus_sensor_gyro Constant_Value_e;// Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S57>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_a;  // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S60>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S59>/Constant'

  real_T ReceiveData_SampleTime;       // Expression: 0.01
                                          //  Referenced by: '<Root>/Receive Data'

  real_T Constant_Value_n;             // Expression: 1
                                          //  Referenced by: '<S28>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S29>/Constant'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S15>/Zero'

  real_T Kp_Gain;                      // Expression: 12
                                          //  Referenced by: '<S15>/Kp'

  real_T Gain5_Gain;                   // Expression: -0.1
                                          //  Referenced by: '<S15>/Gain5'

  real_T Constant_Value_h;             // Expression: 1
                                          //  Referenced by: '<S40>/Constant'

  real32_T CMD_Y0;                     // Computed Parameter: CMD_Y0
                                          //  Referenced by: '<S51>/CMD'

  real32_T ACC_Y0;                     // Computed Parameter: ACC_Y0
                                          //  Referenced by: '<S51>/ACC'

  real32_T ROT_Y0;                     // Computed Parameter: ROT_Y0
                                          //  Referenced by: '<S51>/ROT'

  real32_T ATT_Y0;                     // Computed Parameter: ATT_Y0
                                          //  Referenced by: '<S51>/ATT'

  real32_T TestSignal_Y0;              // Computed Parameter: TestSignal_Y0
                                          //  Referenced by: '<S51>/TestSignal'

  real32_T ServoCMD_Y0;                // Computed Parameter: ServoCMD_Y0
                                          //  Referenced by: '<S10>/ServoCMD'

  real32_T SensorACC_Y0;               // Computed Parameter: SensorACC_Y0
                                          //  Referenced by: '<S10>/SensorACC'

  real32_T SensorROT_Y0;               // Computed Parameter: SensorROT_Y0
                                          //  Referenced by: '<S10>/SensorROT'

  real32_T quaternion_Y0;              // Computed Parameter: quaternion_Y0
                                          //  Referenced by: '<S10>/quaternion'

  real32_T TestSignal_feedback_Y0; // Computed Parameter: TestSignal_feedback_Y0
                                      //  Referenced by: '<S10>/TestSignal_feedback'

  uint16_T ms2us_1_Gain;               // Computed Parameter: ms2us_1_Gain
                                          //  Referenced by: '<S39>/ms2us_1'

  uint16_T ms2us_2_Gain;               // Computed Parameter: ms2us_2_Gain
                                          //  Referenced by: '<S39>/ms2us_2'

  uint16_T ms2us_3_Gain;               // Computed Parameter: ms2us_3_Gain
                                          //  Referenced by: '<S39>/ms2us_3'

  uint16_T ms2us_4_Gain;               // Computed Parameter: ms2us_4_Gain
                                          //  Referenced by: '<S39>/ms2us_4'

  uint16_T heartbeat_Y0;               // Computed Parameter: heartbeat_Y0
                                          //  Referenced by: '<S12>/heartbeat'

  uint16_T SimHeartbeat_Y0;            // Computed Parameter: SimHeartbeat_Y0
                                          //  Referenced by: '<S51>/SimHeartbeat'

  uint16_T Recovery_activation_flg_Value;
                            // Computed Parameter: Recovery_activation_flg_Value
                               //  Referenced by: '<S11>/Recovery_activation_flg'

  uint16_T HIL_detect_flg_Value;     // Computed Parameter: HIL_detect_flg_Value
                                        //  Referenced by: '<S11>/HIL_detect_flg'

  boolean_T cmd_found_flg_Y0;          // Computed Parameter: cmd_found_flg_Y0
                                          //  Referenced by: '<S6>/cmd_found_flg'

  boolean_T packetfound_flg_Y0;        // Computed Parameter: packetfound_flg_Y0
                                          //  Referenced by: '<S48>/packetfound_flg'

  boolean_T PWM_arm_flg_Value;         // Computed Parameter: PWM_arm_flg_Value
                                          //  Referenced by: '<S11>/PWM_arm_flg'

  boolean_T Constant_Value_i;          // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S3>/Constant'

  uint8_T SimStatus_Y0;                // Computed Parameter: SimStatus_Y0
                                          //  Referenced by: '<S51>/SimStatus'

  uint8_T SimRCStatus_Y0;              // Computed Parameter: SimRCStatus_Y0
                                          //  Referenced by: '<S51>/SimRCStatus'

  uint8_T PixStatus_Y0;                // Computed Parameter: PixStatus_Y0
                                          //  Referenced by: '<S10>/PixStatus'

  uint8_T RCStatus_Y0;                 // Computed Parameter: RCStatus_Y0
                                          //  Referenced by: '<S10>/RCStatus'

  uint8_T Header_Value[3];             // Computed Parameter: Header_Value
                                          //  Referenced by: '<S40>/Header'

  uint8_T Header1_Value[3];            // Computed Parameter: Header1_Value
                                          //  Referenced by: '<S40>/Header1'

};

// Real-time Model Data Structure
struct tag_RTM_Pix_FCC_flash_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Pix_FCC_flash_T Pix_FCC_flash_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_Pix_FCC_flash_T Pix_FCC_flash_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_Pix_FCC_flash_T Pix_FCC_flash_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Pix_FCC_flash_initialize(void);
  extern void Pix_FCC_flash_step(void);
  extern void Pix_FCC_flash_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Pix_FCC_flash_T *const Pix_FCC_flash_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Cmd' : Unused code path elimination
//  Block '<S6>/Message found' : Unused code path elimination
//  Block '<S14>/Compare' : Unused code path elimination
//  Block '<S14>/Constant' : Unused code path elimination
//  Block '<S15>/Ki' : Unused code path elimination
//  Block '<S20>/Constant1' : Unused code path elimination
//  Block '<S20>/Constant5' : Unused code path elimination
//  Block '<S10>/Switch' : Unused code path elimination
//  Block '<S10>/Switch1' : Unused code path elimination
//  Block '<S37>/Compare' : Unused code path elimination
//  Block '<S37>/Constant' : Unused code path elimination
//  Block '<S38>/Data Type Propagation' : Unused code path elimination
//  Block '<S41>/FixPt Constant' : Unused code path elimination
//  Block '<S41>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S41>/FixPt Sum1' : Unused code path elimination
//  Block '<S38>/Output' : Unused code path elimination
//  Block '<S42>/Constant' : Unused code path elimination
//  Block '<S42>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S42>/FixPt Switch' : Unused code path elimination
//  Block '<S45>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S46>/FixPt Constant' : Unused code path elimination
//  Block '<S46>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S46>/FixPt Sum1' : Unused code path elimination
//  Block '<S45>/Output' : Unused code path elimination
//  Block '<S47>/Constant' : Unused code path elimination
//  Block '<S47>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S47>/FixPt Switch' : Unused code path elimination
//  Block '<S13>/Scope' : Unused code path elimination
//  Block '<S13>/Scope1' : Unused code path elimination
//  Block '<S55>/NOT' : Unused code path elimination
//  Block '<S57>/NOT' : Unused code path elimination
//  Block '<S59>/NOT' : Unused code path elimination
//  Block '<S5>/Constant' : Unused code path elimination
//  Block '<Root>/To Workspace' : Unused code path elimination
//  Block '<S15>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion6' : Eliminate redundant data type conversion


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
//  '<Root>' : 'Pix_FCC_flash'
//  '<S1>'   : 'Pix_FCC_flash/Command_Chain'
//  '<S2>'   : 'Pix_FCC_flash/ExecutionCycle'
//  '<S3>'   : 'Pix_FCC_flash/HIL_Switch'
//  '<S4>'   : 'Pix_FCC_flash/Sensor Input'
//  '<S5>'   : 'Pix_FCC_flash/Synchronisation'
//  '<S6>'   : 'Pix_FCC_flash/Command_Chain/DecodeCommand'
//  '<S7>'   : 'Pix_FCC_flash/Command_Chain/SetMode'
//  '<S8>'   : 'Pix_FCC_flash/Command_Chain/memory'
//  '<S9>'   : 'Pix_FCC_flash/Command_Chain/DecodeCommand/DecodeCommand'
//  '<S10>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION'
//  '<S11>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT'
//  '<S12>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat'
//  '<S13>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data'
//  '<S14>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Compare To Constant'
//  '<S15>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Controller_PIX'
//  '<S16>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/DefineRCStatus'
//  '<S17>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/DefineStatus'
//  '<S18>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX'
//  '<S19>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles'
//  '<S20>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX'
//  '<S21>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation'
//  '<S22>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation/Check_Limit_exceeding'
//  '<S23>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation/Pass'
//  '<S24>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation/Saturate'
//  '<S25>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Angle Calculation'
//  '<S26>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S27>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S28>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S29>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S30>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S31>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S32>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S33>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_1'
//  '<S34>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_2'
//  '<S35>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_3'
//  '<S36>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_4'
//  '<S37>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Compare To Constant'
//  '<S38>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Counter Limited'
//  '<S39>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/PWM output'
//  '<S40>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send'
//  '<S41>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Counter Limited/Increment Real World'
//  '<S42>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Counter Limited/Wrap To Zero'
//  '<S43>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/MessageAssembly'
//  '<S44>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/convert2uint8'
//  '<S45>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat/Counter Free-Running'
//  '<S46>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat/Counter Free-Running/Increment Real World'
//  '<S47>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat/Counter Free-Running/Wrap To Zero'
//  '<S48>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold'
//  '<S49>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold/ByteUnpack'
//  '<S50>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold/ExtractMessage'
//  '<S51>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold/hold'
//  '<S52>'  : 'Pix_FCC_flash/Sensor Input/Accelerometer'
//  '<S53>'  : 'Pix_FCC_flash/Sensor Input/Gyroscope'
//  '<S54>'  : 'Pix_FCC_flash/Sensor Input/Vehicle Attitude'
//  '<S55>'  : 'Pix_FCC_flash/Sensor Input/Accelerometer/PX4 uORB Read'
//  '<S56>'  : 'Pix_FCC_flash/Sensor Input/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S57>'  : 'Pix_FCC_flash/Sensor Input/Gyroscope/PX4 uORB Read'
//  '<S58>'  : 'Pix_FCC_flash/Sensor Input/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S59>'  : 'Pix_FCC_flash/Sensor Input/Vehicle Attitude/PX4 uORB Read'
//  '<S60>'  : 'Pix_FCC_flash/Sensor Input/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S61>'  : 'Pix_FCC_flash/Synchronisation/ControlExecution'

#endif                                 // RTW_HEADER_Pix_FCC_flash_h_

//
// File trailer for generated code.
//
// [EOF]
//

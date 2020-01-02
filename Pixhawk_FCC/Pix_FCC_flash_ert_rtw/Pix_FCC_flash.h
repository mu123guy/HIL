//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash.h
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.333
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Jan  2 23:39:39 2020
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
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<S9>/Send WhiteNoise Beginning'
typedef struct {
  px4_internal_block_PX4SCIWrit_T obj; // '<S15>/Serial Transmit'
  boolean_T objisempty;                // '<S15>/Serial Transmit'
} DW_SendWhiteNoiseBeginning_Pi_T;

// Block states (default storage) for system '<S9>/Send Header'
typedef struct {
  px4_internal_block_PX4SCIWrit_T obj; // '<S12>/Serial Transmit'
  boolean_T objisempty;                // '<S12>/Serial Transmit'
} DW_SendHeader_Pix_FCC_flash_T;

// Block signals (default storage)
typedef struct {
  real_T start_data[128];
  real_T start_data_m[128];
  boolean_T x[128];
  uint8_T RxData[128];
  uint8_T RxDataLocChar[128];
  uint8_T packet_data[127];
  uint8_T packet_data_c[127];
  px4_Bus_sensor_accel b_varargout_2;
  px4_Bus_sensor_gyro In1;             // '<S62>/In1'
  px4_Bus_sensor_accel In1_j;          // '<S60>/In1'
  px4_Bus_sensor_gyro b_varargout_2_k;
  uint8_T TxDataLocChar[64];
  uint8_T msgOut[64];                  // '<S39>/convert2uint8'
  real32_T TmpSignalConversionAtSFunct[16];// '<S39>/convert2uint8'
  px4_Bus_vehicle_attitude In1_c;      // '<S64>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_c;
  uint8_T message[56];                 // '<S52>/ExtractMessage'
  uint16_T pwmValue[8];
  real32_T CMD_update[3];              // '<S55>/CMD_update'
  real32_T ACC_update[3];              // '<S55>/ACC_update'
  real32_T ROT_update[3];              // '<S55>/ROT_update'
  real32_T ATT_update[3];              // '<S55>/ATT_update'
  char_T SCIModuleLoc[11];
  char_T SCIModuleLoc_b[11];
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  uint32_T RxPinLoc_p;
  uint32_T TxPinLoc_c;
  MW_SCI_StopBits_Type StopBitsValue_f;
  real_T Add16;                        // '<S26>/Add16'
  real_T Add3;                         // '<S26>/Add3'
  real_T Add2;                         // '<S26>/Add2'
  real_T Add1;                         // '<S26>/Add1'
  real_T Add;                          // '<S26>/Add'
  real_T Abs1;                         // '<S31>/Abs1'
  int32_T start_size[2];
  int32_T start_size_g[2];
  int32_T tmp_size[2];
  int32_T start_size_g1[2];
  int32_T tmp_size_m[2];
  int32_T start_size_n[2];
  real32_T TestSignal_update;          // '<S55>/TestSignal_update'
  real32_T TestSignal;
  real32_T CMD1;
  real32_T CMD2;
  real32_T CMD3;
  real32_T ACC1;
  real32_T ACC2;
  int32_T b_ii;
  int32_T idx;
  uint8_T update[4];                   // '<S8>/update'
  uint8_T cmd[4];                      // '<S6>/DecodeCommand'
  uint8_T pack[4];
  uint16_T SimHeartbeat_update;        // '<S55>/SimHeartbeat_update'
  boolean_T packetfound;               // '<S52>/ExtractMessage'
  boolean_T cmd_found_flg;             // '<S6>/DecodeCommand'
} B_Pix_FCC_flash_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_PX4SCIRead_T obj; // '<Root>/Receive Data'
  px4_internal_block_PX4SCIWrit_T obj_h;// '<S43>/Serial Transmit'
  px4_internal_block_PX4SCIWrit_T obj_b;// '<S11>/Serial Transmit'
  px4_internal_block_PX4SCIWrit_T obj_k;// '<S13>/Serial Transmit'
  px4_internal_block_PWM_Pix_FC_T obj_j;// '<S38>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_c;// '<S63>/SourceBlock'
  px4_internal_block_Subscriber_T obj_f;// '<S61>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S59>/SourceBlock'
  real32_T DiscreteTransferFcn2_states;// '<S23>/Discrete Transfer Fcn2'
  real32_T DiscreteTransferFcn1_states;// '<S23>/Discrete Transfer Fcn1'
  real32_T DiscreteTransferFcn_states; // '<S23>/Discrete Transfer Fcn'
  int32_T SFunction_DIMS2[2];          // '<S52>/ExtractMessage'
  int32_T update_DIMS1[2];             // '<S8>/update'
  int32_T SFunction_DIMS2_f[2];        // '<S6>/DecodeCommand'
  DW_SendWhiteNoiseBeginning_Pi_T SendWhiteNoiseEnd_a;// '<S39>/Send WhiteNoise End' 
  DW_SendHeader_Pix_FCC_flash_T SendTerminator_g;// '<S39>/Send Terminator'
  DW_SendHeader_Pix_FCC_flash_T SendHeader_k;// '<S39>/Send Header'
  DW_SendWhiteNoiseBeginning_Pi_T SendWhiteNoiseBeginning_p;// '<S39>/Send WhiteNoise Beginning' 
  DW_SendWhiteNoiseBeginning_Pi_T SendWhiteNoiseEnd;// '<S9>/Send WhiteNoise End' 
  DW_SendHeader_Pix_FCC_flash_T SendTerminator;// '<S9>/Send Terminator'
  DW_SendHeader_Pix_FCC_flash_T SendHeader;// '<S9>/Send Header'
  DW_SendWhiteNoiseBeginning_Pi_T SendWhiteNoiseBeginning;// '<S9>/Send WhiteNoise Beginning' 
} DW_Pix_FCC_flash_T;

// Parameters for system: '<S9>/Send WhiteNoise Beginning'
struct P_SendWhiteNoiseBeginning_Pix_T_ {
  uint8_T Header_Value[5];             // Computed Parameter: Header_Value
                                          //  Referenced by: '<S15>/Header'

};

// Parameters for system: '<S9>/Send Header'
struct P_SendHeader_Pix_FCC_flash_T_ {
  uint8_T Header_Value[2];             // Computed Parameter: Header_Value
                                          //  Referenced by: '<S12>/Header'

};

// Parameters (default storage)
struct P_Pix_FCC_flash_T_ {
  struct_kDC9SqVquJgNZQDtb5tZbG FCC_PIX_Data;// Variable: FCC_PIX_Data
                                                //  Referenced by:
                                                //    '<S26>/Constant'
                                                //    '<S26>/Constant1'
                                                //    '<S26>/Constant2'
                                                //    '<S26>/Constant3'
                                                //    '<S26>/Constant4'
                                                //    '<S27>/Constant'
                                                //    '<S32>/Constant2'
                                                //    '<S32>/Constant6'
                                                //    '<S32>/Saturation'
                                                //    '<S33>/Constant2'
                                                //    '<S33>/Constant6'
                                                //    '<S33>/Saturation'
                                                //    '<S34>/Constant2'
                                                //    '<S34>/Constant6'
                                                //    '<S34>/Saturation'
                                                //    '<S35>/Constant2'
                                                //    '<S35>/Constant6'
                                                //    '<S35>/Saturation'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S22>/Constant'

  px4_Bus_sensor_accel Out1_Y0;        // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S60>/Out1'

  px4_Bus_sensor_accel Constant_Value; // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S59>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_f;       // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S62>/Out1'

  px4_Bus_sensor_gyro Constant_Value_e;// Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S61>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_a;  // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S64>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S63>/Constant'

  real_T ReceiveData_SampleTime;       // Expression: 0.01
                                          //  Referenced by: '<Root>/Receive Data'

  real_T Constant_Value_h;             // Expression: 1
                                          //  Referenced by: '<S39>/Constant'

  real32_T CMD_Y0;                     // Computed Parameter: CMD_Y0
                                          //  Referenced by: '<S55>/CMD'

  real32_T ACC_Y0;                     // Computed Parameter: ACC_Y0
                                          //  Referenced by: '<S55>/ACC'

  real32_T ROT_Y0;                     // Computed Parameter: ROT_Y0
                                          //  Referenced by: '<S55>/ROT'

  real32_T ATT_Y0;                     // Computed Parameter: ATT_Y0
                                          //  Referenced by: '<S55>/ATT'

  real32_T TestSignal_Y0;              // Computed Parameter: TestSignal_Y0
                                          //  Referenced by: '<S55>/TestSignal'

  real32_T ServoCMD_Y0;                // Computed Parameter: ServoCMD_Y0
                                          //  Referenced by: '<S18>/ServoCMD'

  real32_T SensorACC_Y0;               // Computed Parameter: SensorACC_Y0
                                          //  Referenced by: '<S18>/SensorACC'

  real32_T SensorROT_Y0;               // Computed Parameter: SensorROT_Y0
                                          //  Referenced by: '<S18>/SensorROT'

  real32_T quaternion_Y0;              // Computed Parameter: quaternion_Y0
                                          //  Referenced by: '<S18>/quaternion'

  real32_T TestSignal_feedback_Y0; // Computed Parameter: TestSignal_feedback_Y0
                                      //  Referenced by: '<S18>/TestSignal_feedback'

  real32_T DiscreteTransferFcn2_NumCoef;
                // Expression: FCC_PIX_Data.Controller.Yaw.outerLoop.IntGain.Num
                   //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real32_T DiscreteTransferFcn2_DenCoef[2];
              // Expression: FCC_PIX_Data.Controller.Yaw.outerLoop.IntGain.Denom
                 //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real32_T DiscreteTransferFcn2_InitialSta;
                          // Computed Parameter: DiscreteTransferFcn2_InitialSta
                             //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real32_T Gain4_Gain;
                   // Expression: FCC_PIX_Data.Controller.Yaw.outerLoop.PropGain
                      //  Referenced by: '<S23>/Gain4'

  real32_T Gain2_Gain;
                   // Expression: FCC_PIX_Data.Controller.Yaw.innerLoop.PropGain
                      //  Referenced by: '<S23>/Gain2'

  real32_T DiscreteTransferFcn1_NumCoef;
              // Expression: FCC_PIX_Data.Controller.Pitch.outerLoop.IntGain.Num
                 //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real32_T DiscreteTransferFcn1_DenCoef[2];
            // Expression: FCC_PIX_Data.Controller.Pitch.outerLoop.IntGain.Denom
               //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real32_T DiscreteTransferFcn1_InitialSta;
                          // Computed Parameter: DiscreteTransferFcn1_InitialSta
                             //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real32_T Gain3_Gain;
                 // Expression: FCC_PIX_Data.Controller.Pitch.outerLoop.PropGain
                    //  Referenced by: '<S23>/Gain3'

  real32_T Gain1_Gain;
                 // Expression: FCC_PIX_Data.Controller.Pitch.innerLoop.PropGain
                    //  Referenced by: '<S23>/Gain1'

  real32_T Gain_Gain;           // Expression: FCC_PIX_Data.Controller.Roll.Gain
                                   //  Referenced by: '<S23>/Gain'

  real32_T DiscreteTransferFcn_NumCoef[2];
                            // Expression: FCC_PIX_Data.Controller.Roll.Lead.Num
                               //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_DenCoef[2];
                          // Expression: FCC_PIX_Data.Controller.Roll.Lead.Denom
                             //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_InitialStat;
                          // Computed Parameter: DiscreteTransferFcn_InitialStat
                             //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real32_T Limit2maxDeflection_UpperSat;
                 // Expression: FCC_PIX_Data.Control_Surfaces.max_deflection_rad
                    //  Referenced by: '<S26>/Limit2maxDeflection'

  real32_T Limit2maxDeflection_LowerSat;
                             // Computed Parameter: Limit2maxDeflection_LowerSat
                                //  Referenced by: '<S26>/Limit2maxDeflection'

  uint16_T ms2us_1_Gain;               // Computed Parameter: ms2us_1_Gain
                                          //  Referenced by: '<S38>/ms2us_1'

  uint16_T ms2us_2_Gain;               // Computed Parameter: ms2us_2_Gain
                                          //  Referenced by: '<S38>/ms2us_2'

  uint16_T ms2us_3_Gain;               // Computed Parameter: ms2us_3_Gain
                                          //  Referenced by: '<S38>/ms2us_3'

  uint16_T ms2us_4_Gain;               // Computed Parameter: ms2us_4_Gain
                                          //  Referenced by: '<S38>/ms2us_4'

  uint16_T heartbeat_Y0;               // Computed Parameter: heartbeat_Y0
                                          //  Referenced by: '<S20>/heartbeat'

  uint16_T SimHeartbeat_Y0;            // Computed Parameter: SimHeartbeat_Y0
                                          //  Referenced by: '<S55>/SimHeartbeat'

  uint16_T Recovery_activation_flg_Value;
                            // Computed Parameter: Recovery_activation_flg_Value
                               //  Referenced by: '<S19>/Recovery_activation_flg'

  uint16_T HIL_detect_flg_Value;     // Computed Parameter: HIL_detect_flg_Value
                                        //  Referenced by: '<S19>/HIL_detect_flg'

  boolean_T cmd_found_flg_Y0;          // Computed Parameter: cmd_found_flg_Y0
                                          //  Referenced by: '<S6>/cmd_found_flg'

  boolean_T packetfound_flg_Y0;        // Computed Parameter: packetfound_flg_Y0
                                          //  Referenced by: '<S52>/packetfound_flg'

  boolean_T PWM_arm_flg_Value;         // Computed Parameter: PWM_arm_flg_Value
                                          //  Referenced by: '<S19>/PWM_arm_flg'

  boolean_T Constant_Value_i;          // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S3>/Constant'

  uint8_T Header_Value;                // Computed Parameter: Header_Value
                                          //  Referenced by: '<S13>/Header'

  uint8_T SimStatus_Y0;                // Computed Parameter: SimStatus_Y0
                                          //  Referenced by: '<S55>/SimStatus'

  uint8_T SimRCStatus_Y0;              // Computed Parameter: SimRCStatus_Y0
                                          //  Referenced by: '<S55>/SimRCStatus'

  uint8_T PixStatus_Y0;                // Computed Parameter: PixStatus_Y0
                                          //  Referenced by: '<S18>/PixStatus'

  uint8_T RCStatus_Y0;                 // Computed Parameter: RCStatus_Y0
                                          //  Referenced by: '<S18>/RCStatus'

  P_SendWhiteNoiseBeginning_Pix_T SendWhiteNoiseEnd_a;// '<S39>/Send WhiteNoise End' 
  P_SendHeader_Pix_FCC_flash_T SendTerminator_g;// '<S39>/Send Terminator'
  P_SendHeader_Pix_FCC_flash_T SendHeader_k;// '<S39>/Send Header'
  P_SendWhiteNoiseBeginning_Pix_T SendWhiteNoiseBeginning_p;// '<S39>/Send WhiteNoise Beginning' 
  P_SendWhiteNoiseBeginning_Pix_T SendWhiteNoiseEnd;// '<S9>/Send WhiteNoise End' 
  P_SendHeader_Pix_FCC_flash_T SendTerminator;// '<S9>/Send Terminator'
  P_SendHeader_Pix_FCC_flash_T SendHeader;// '<S9>/Send Header'
  P_SendWhiteNoiseBeginning_Pix_T SendWhiteNoiseBeginning;// '<S9>/Send WhiteNoise Beginning' 
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
//  Block '<S27>/Constant1' : Unused code path elimination
//  Block '<S27>/Constant5' : Unused code path elimination
//  Block '<S36>/Compare' : Unused code path elimination
//  Block '<S36>/Constant' : Unused code path elimination
//  Block '<S37>/Data Type Propagation' : Unused code path elimination
//  Block '<S40>/FixPt Constant' : Unused code path elimination
//  Block '<S40>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S40>/FixPt Sum1' : Unused code path elimination
//  Block '<S37>/Output' : Unused code path elimination
//  Block '<S41>/Constant' : Unused code path elimination
//  Block '<S41>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S41>/FixPt Switch' : Unused code path elimination
//  Block '<S43>/Constant' : Unused code path elimination
//  Block '<S43>/Scope' : Unused code path elimination
//  Block '<S43>/Scope1' : Unused code path elimination
//  Block '<S43>/Sine Wave' : Unused code path elimination
//  Block '<S49>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S50>/FixPt Constant' : Unused code path elimination
//  Block '<S50>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S50>/FixPt Sum1' : Unused code path elimination
//  Block '<S49>/Output' : Unused code path elimination
//  Block '<S51>/Constant' : Unused code path elimination
//  Block '<S51>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S51>/FixPt Switch' : Unused code path elimination
//  Block '<S21>/Scope' : Unused code path elimination
//  Block '<S21>/Scope1' : Unused code path elimination
//  Block '<S59>/NOT' : Unused code path elimination
//  Block '<S61>/NOT' : Unused code path elimination
//  Block '<S63>/NOT' : Unused code path elimination
//  Block '<S5>/Constant' : Unused code path elimination
//  Block '<Root>/To Workspace' : Unused code path elimination
//  Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S19>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S19>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S19>/Data Type Conversion6' : Eliminate redundant data type conversion


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
//  '<S9>'   : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand'
//  '<S10>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/DecodeCommand'
//  '<S11>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/Send Data'
//  '<S12>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/Send Header'
//  '<S13>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/Send RC Confrimation'
//  '<S14>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/Send Terminator'
//  '<S15>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/Send WhiteNoise Beginning'
//  '<S16>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/Send WhiteNoise End'
//  '<S17>'  : 'Pix_FCC_flash/Command_Chain/DecodeCommand/ConfirmCommand/pack'
//  '<S18>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION'
//  '<S19>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT'
//  '<S20>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat'
//  '<S21>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data'
//  '<S22>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Compare To Constant'
//  '<S23>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Controller_PIX'
//  '<S24>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/DefineRCStatus'
//  '<S25>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/DefineStatus'
//  '<S26>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX'
//  '<S27>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX'
//  '<S28>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation'
//  '<S29>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation/Check_Limit_exceeding'
//  '<S30>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation/Pass'
//  '<S31>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Fin_Deflection_PIX/Saturation/Saturate'
//  '<S32>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_1'
//  '<S33>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_2'
//  '<S34>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_3'
//  '<S35>'  : 'Pix_FCC_flash/ExecutionCycle/ACTION/Servo_Cmd_PIX/Servo_4'
//  '<S36>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Compare To Constant'
//  '<S37>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Counter Limited'
//  '<S38>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/PWM output'
//  '<S39>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send'
//  '<S40>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Counter Limited/Increment Real World'
//  '<S41>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/Counter Limited/Wrap To Zero'
//  '<S42>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/MessageAssembly'
//  '<S43>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/Send Data'
//  '<S44>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/Send Header'
//  '<S45>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/Send Terminator'
//  '<S46>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/Send WhiteNoise Beginning'
//  '<S47>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/Send WhiteNoise End'
//  '<S48>'  : 'Pix_FCC_flash/ExecutionCycle/OUTPUT/serial send/convert2uint8'
//  '<S49>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat/Counter Free-Running'
//  '<S50>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat/Counter Free-Running/Increment Real World'
//  '<S51>'  : 'Pix_FCC_flash/ExecutionCycle/heartbeat/Counter Free-Running/Wrap To Zero'
//  '<S52>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold'
//  '<S53>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold/ByteUnpack'
//  '<S54>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold/ExtractMessage'
//  '<S55>'  : 'Pix_FCC_flash/ExecutionCycle/process_received_data/input_hold/hold'
//  '<S56>'  : 'Pix_FCC_flash/Sensor Input/Accelerometer'
//  '<S57>'  : 'Pix_FCC_flash/Sensor Input/Gyroscope'
//  '<S58>'  : 'Pix_FCC_flash/Sensor Input/Vehicle Attitude'
//  '<S59>'  : 'Pix_FCC_flash/Sensor Input/Accelerometer/PX4 uORB Read'
//  '<S60>'  : 'Pix_FCC_flash/Sensor Input/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S61>'  : 'Pix_FCC_flash/Sensor Input/Gyroscope/PX4 uORB Read'
//  '<S62>'  : 'Pix_FCC_flash/Sensor Input/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S63>'  : 'Pix_FCC_flash/Sensor Input/Vehicle Attitude/PX4 uORB Read'
//  '<S64>'  : 'Pix_FCC_flash/Sensor Input/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S65>'  : 'Pix_FCC_flash/Synchronisation/ControlExecution'

#endif                                 // RTW_HEADER_Pix_FCC_flash_h_

//
// File trailer for generated code.
//
// [EOF]
//

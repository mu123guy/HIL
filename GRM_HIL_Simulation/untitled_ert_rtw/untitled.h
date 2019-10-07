//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled.h
//
// Code generated for Simulink model 'untitled'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Oct  6 19:40:43 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <float.h>
#include <stddef.h>
#ifndef untitled_COMMON_INCLUDES_
# define untitled_COMMON_INCLUDES_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_uORB_Read.h"
#endif                                 // untitled_COMMON_INCLUDES_

#include "untitled_types.h"

// Shared type includes
#include "multiword_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
typedef struct {
  px4_Bus_sensor_mag In1;              // '<S4>/In1'
  px4_Bus_sensor_mag b_varargout_2;
  real32_T x;
  real32_T y;
  real32_T z;
} B_untitled_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_Subscriber_T obj; // '<S5>/SourceBlock'
  px4_internal_block_Subscriber_T obj_g;// '<S3>/SourceBlock'
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       // '<Root>/Scope'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S5>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_p;// '<S3>/Enabled Subsystem'
} DW_untitled_T;

// Parameters (default storage)
struct P_untitled_T_ {
  px4_Bus_sensor_mag Out1_Y0;          // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S4>/Out1'

  px4_Bus_sensor_mag Constant_Value;   // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S3>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_i;  // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S6>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_p;// Computed Parameter: Constant_Value_p
                                               //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_untitled_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_untitled_T untitled_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_untitled_T untitled_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_untitled_T untitled_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void untitled_initialize(void);
  extern void untitled_step(void);
  extern void untitled_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_untitled_T *const untitled_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/NOT' : Unused code path elimination
//  Block '<S5>/NOT' : Unused code path elimination


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
//  '<Root>' : 'untitled'
//  '<S1>'   : 'untitled/Magnetometer'
//  '<S2>'   : 'untitled/Vehicle Attitude'
//  '<S3>'   : 'untitled/Magnetometer/PX4 uORB Read'
//  '<S4>'   : 'untitled/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S5>'   : 'untitled/Vehicle Attitude/PX4 uORB Read'
//  '<S6>'   : 'untitled/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_untitled_h_

//
// File trailer for generated code.
//
// [EOF]
//

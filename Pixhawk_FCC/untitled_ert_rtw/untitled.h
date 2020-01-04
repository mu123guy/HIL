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
// C/C++ source code generated on : Wed Jan  1 16:31:42 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef untitled_COMMON_INCLUDES_
# define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_PX4_SCI.h"
#include "MW_SCI.h"
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

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
typedef struct {
  uint8_T SerialReceive_o1[18];        // '<Root>/Serial Receive'
} B_untitled_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_PX4SCIRead_T obj; // '<Root>/Serial Receive'
  px4_internal_block_PX4SCIWrit_T obj_l;// '<Root>/Serial Transmit'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'
} DW_untitled_T;

// Parameters (default storage)
struct P_untitled_T_ {
  real_T SerialReceive_SampleTime;     // Expression: 0.1
                                          //  Referenced by: '<Root>/Serial Receive'

  uint8_T Constant_Value[18];          // Computed Parameter: Constant_Value
                                          //  Referenced by: '<Root>/Constant'

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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

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

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void untitled_initialize(void);
  extern void untitled_step(int_T tid);
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

#endif                                 // RTW_HEADER_untitled_h_

//
// File trailer for generated code.
//
// [EOF]
//

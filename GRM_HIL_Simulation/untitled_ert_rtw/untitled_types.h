//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled_types.h
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
#ifndef RTW_HEADER_untitled_types_h_
#define RTW_HEADER_untitled_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include <uORB/topics/sensor_mag.h>
#include <uORB/topics/vehicle_attitude.h>
#ifndef typedef_d_px4_internal_block_SampleTi_T
#define typedef_d_px4_internal_block_SampleTi_T

typedef struct {
  int32_T __dummy;
} d_px4_internal_block_SampleTi_T;

#endif                                 //typedef_d_px4_internal_block_SampleTi_T

#ifndef typedef_px4_internal_block_Subscriber_T
#define typedef_px4_internal_block_Subscriber_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
} px4_internal_block_Subscriber_T;

#endif                                 //typedef_px4_internal_block_Subscriber_T

// Parameters (default storage)
typedef struct P_untitled_T_ P_untitled_T;

// Forward declaration for rtModel
typedef struct tag_RTM_untitled_T RT_MODEL_untitled_T;

#endif                                 // RTW_HEADER_untitled_types_h_

//
// File trailer for generated code.
//
// [EOF]
//

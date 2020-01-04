//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_serial_types.h
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
#ifndef RTW_HEADER_px4demo_serial_types_h_
#define RTW_HEADER_px4demo_serial_types_h_
#include "rtwtypes.h"
#include <uORB/topics/sensor_accel.h>

// Custom Type definition for MATLABSystem: '<S4>/Serial Transmit'
#include "MW_SVD.h"
#ifndef typedef_px4_internal_block_Hardware_p_T
#define typedef_px4_internal_block_Hardware_p_T

typedef struct {
  int32_T __dummy;
} px4_internal_block_Hardware_p_T;

#endif                                 //typedef_px4_internal_block_Hardware_p_T

#ifndef typedef_px4_internal_block_PX4SCIRead_T
#define typedef_px4_internal_block_PX4SCIRead_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_p_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
} px4_internal_block_PX4SCIRead_T;

#endif                                 //typedef_px4_internal_block_PX4SCIRead_T

#ifndef typedef_px4_internal_block_PX4SCIWrit_T
#define typedef_px4_internal_block_PX4SCIWrit_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_p_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
} px4_internal_block_PX4SCIWrit_T;

#endif                                 //typedef_px4_internal_block_PX4SCIWrit_T

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

#ifndef typedef_struct_T_px4demo_serial_T
#define typedef_struct_T_px4demo_serial_T

typedef struct {
  char_T Value[10];
} struct_T_px4demo_serial_T;

#endif                                 //typedef_struct_T_px4demo_serial_T

// Parameters (default storage)
typedef struct P_px4demo_serial_T_ P_px4demo_serial_T;

// Forward declaration for rtModel
typedef struct tag_RTM_px4demo_serial_T RT_MODEL_px4demo_serial_T;

#endif                                 // RTW_HEADER_px4demo_serial_types_h_

//
// File trailer for generated code.
//
// [EOF]
//

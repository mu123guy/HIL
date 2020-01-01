//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash_types.h
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.324
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Mon Dec 30 19:52:54 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Pix_FCC_flash_types_h_
#define RTW_HEADER_Pix_FCC_flash_types_h_
#include "rtwtypes.h"
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/vehicle_attitude.h>
#ifndef DEFINED_TYPEDEF_FOR_struct_QhvhhqDV0L2yxKLWicNneD_
#define DEFINED_TYPEDEF_FOR_struct_QhvhhqDV0L2yxKLWicNneD_

typedef struct {
  real_T Num[2];
  real_T Denom[2];
} struct_QhvhhqDV0L2yxKLWicNneD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NXU1FRSfNm9MZqPmiPj5nG_
#define DEFINED_TYPEDEF_FOR_struct_NXU1FRSfNm9MZqPmiPj5nG_

typedef struct {
  real_T PreGain;
  real_T Gain;
  struct_QhvhhqDV0L2yxKLWicNneD Lead;
} struct_NXU1FRSfNm9MZqPmiPj5nG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NKNq6gj8dL8ticSV3dO1LF_
#define DEFINED_TYPEDEF_FOR_struct_NKNq6gj8dL8ticSV3dO1LF_

typedef struct {
  real_T PropGain;
} struct_NKNq6gj8dL8ticSV3dO1LF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6DMhF3HgatZ0SVFTbVEXUB_
#define DEFINED_TYPEDEF_FOR_struct_6DMhF3HgatZ0SVFTbVEXUB_

typedef struct {
  real_T Num;
  real_T Denom[2];
} struct_6DMhF3HgatZ0SVFTbVEXUB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_0bCECObDp9cpwUujjacDoB_
#define DEFINED_TYPEDEF_FOR_struct_0bCECObDp9cpwUujjacDoB_

typedef struct {
  real_T PropGain;
  struct_6DMhF3HgatZ0SVFTbVEXUB IntGain;
} struct_0bCECObDp9cpwUujjacDoB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mvMpa6roJ3cC08QEKeHpUD_
#define DEFINED_TYPEDEF_FOR_struct_mvMpa6roJ3cC08QEKeHpUD_

typedef struct {
  struct_NKNq6gj8dL8ticSV3dO1LF innerLoop;
  struct_0bCECObDp9cpwUujjacDoB outerLoop;
} struct_mvMpa6roJ3cC08QEKeHpUD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SpfmErt2JG4vKmjTJRH6OB_
#define DEFINED_TYPEDEF_FOR_struct_SpfmErt2JG4vKmjTJRH6OB_

typedef struct {
  struct_NXU1FRSfNm9MZqPmiPj5nG Roll;
  struct_mvMpa6roJ3cC08QEKeHpUD Pitch;
  struct_mvMpa6roJ3cC08QEKeHpUD Yaw;
} struct_SpfmErt2JG4vKmjTJRH6OB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_skgRGNdg4uikkiJBtrraoB_
#define DEFINED_TYPEDEF_FOR_struct_skgRGNdg4uikkiJBtrraoB_

typedef struct {
  real_T phi_f1_rad;
  real_T phi_f2_rad;
  real_T phi_f3_rad;
  real_T phi_f4_rad;
  real_T max_deflection_rad;
} struct_skgRGNdg4uikkiJBtrraoB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_7SrGNOW0Gr039ZOMvXVVTD_
#define DEFINED_TYPEDEF_FOR_struct_7SrGNOW0Gr039ZOMvXVVTD_

typedef struct {
  real_T Update_rate_Hz;
  real_T periode_ms;
  real_T Pulswidth_cmd_middle_pos_ms;
  real_T Pulswidth_cmd_max_ms;
  real_T Pulswidth_cmd_min_ms;
  real_T Voltage_level_V;
  real_T max_deflection_rad;
} struct_7SrGNOW0Gr039ZOMvXVVTD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_5yp7NkUa494t53XXuhQozD_
#define DEFINED_TYPEDEF_FOR_struct_5yp7NkUa494t53XXuhQozD_

typedef struct {
  struct_7SrGNOW0Gr039ZOMvXVVTD PWM;
} struct_5yp7NkUa494t53XXuhQozD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_kDC9SqVquJgNZQDtb5tZbG_
#define DEFINED_TYPEDEF_FOR_struct_kDC9SqVquJgNZQDtb5tZbG_

typedef struct {
  struct_SpfmErt2JG4vKmjTJRH6OB Controller;
  struct_skgRGNdg4uikkiJBtrraoB Control_Surfaces;
  struct_5yp7NkUa494t53XXuhQozD Servo;
} struct_kDC9SqVquJgNZQDtb5tZbG;

#endif

// Custom Type definition for MATLABSystem: '<S15>/Serial Transmit'
#include "MW_SVD.h"
#ifndef typedef_px4_internal_block_Hardware_P_T
#define typedef_px4_internal_block_Hardware_P_T

typedef struct {
  int32_T __dummy;
} px4_internal_block_Hardware_P_T;

#endif                                 //typedef_px4_internal_block_Hardware_P_T

#ifndef typedef_px4_internal_block_PX4SCIWrit_T
#define typedef_px4_internal_block_PX4SCIWrit_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_P_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
} px4_internal_block_PX4SCIWrit_T;

#endif                                 //typedef_px4_internal_block_PX4SCIWrit_T

#ifndef typedef_struct_T_Pix_FCC_flash_T
#define typedef_struct_T_Pix_FCC_flash_T

typedef struct {
  char_T Value[10];
} struct_T_Pix_FCC_flash_T;

#endif                                 //typedef_struct_T_Pix_FCC_flash_T

#ifndef typedef_px4_internal_block_PWM_Pix_FC_T
#define typedef_px4_internal_block_PWM_Pix_FC_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int pwmDevHandler;
  const char * pwmDevObj;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  uint16_T errorStatus;
  boolean_T isArmed;
} px4_internal_block_PWM_Pix_FC_T;

#endif                                 //typedef_px4_internal_block_PWM_Pix_FC_T

#ifndef struct_emxArray_uint8_T_4x1
#define struct_emxArray_uint8_T_4x1

struct emxArray_uint8_T_4x1
{
  uint8_T data[4];
  int32_T size[2];
};

#endif                                 //struct_emxArray_uint8_T_4x1

#ifndef typedef_emxArray_uint8_T_4x1_Pix_FCC__T
#define typedef_emxArray_uint8_T_4x1_Pix_FCC__T

typedef struct emxArray_uint8_T_4x1 emxArray_uint8_T_4x1_Pix_FCC__T;

#endif                                 //typedef_emxArray_uint8_T_4x1_Pix_FCC__T

#ifndef struct_emxArray_uint8_T_1x56
#define struct_emxArray_uint8_T_1x56

struct emxArray_uint8_T_1x56
{
  uint8_T data[56];
  int32_T size[2];
};

#endif                                 //struct_emxArray_uint8_T_1x56

#ifndef typedef_emxArray_uint8_T_1x56_Pix_FCC_T
#define typedef_emxArray_uint8_T_1x56_Pix_FCC_T

typedef struct emxArray_uint8_T_1x56 emxArray_uint8_T_1x56_Pix_FCC_T;

#endif                                 //typedef_emxArray_uint8_T_1x56_Pix_FCC_T

#ifndef struct_tag_szZFJqmKnebQAQ37SIlrwwB
#define struct_tag_szZFJqmKnebQAQ37SIlrwwB

struct tag_szZFJqmKnebQAQ37SIlrwwB
{
  char_T AllowPropagation[9];
  char_T AlternatePropagation[9];
  char_T Disallow[9];
  char_T ErrorOnPropagation[9];
  char_T Type[9];
};

#endif                                 //struct_tag_szZFJqmKnebQAQ37SIlrwwB

#ifndef typedef_szZFJqmKnebQAQ37SIlrwwB_Pix_F_T
#define typedef_szZFJqmKnebQAQ37SIlrwwB_Pix_F_T

typedef struct tag_szZFJqmKnebQAQ37SIlrwwB szZFJqmKnebQAQ37SIlrwwB_Pix_F_T;

#endif                                 //typedef_szZFJqmKnebQAQ37SIlrwwB_Pix_F_T

#ifndef typedef_struct_T_Pix_FCC_flash_b_T
#define typedef_struct_T_Pix_FCC_flash_b_T

typedef struct {
  char_T Value[20];
} struct_T_Pix_FCC_flash_b_T;

#endif                                 //typedef_struct_T_Pix_FCC_flash_b_T

#ifndef typedef_b_struct_T_Pix_FCC_flash_T
#define typedef_b_struct_T_Pix_FCC_flash_T

typedef struct {
  char_T Value[8];
} b_struct_T_Pix_FCC_flash_T;

#endif                                 //typedef_b_struct_T_Pix_FCC_flash_T

#ifndef typedef_c_struct_T_Pix_FCC_flash_T
#define typedef_c_struct_T_Pix_FCC_flash_T

typedef struct {
  char_T Value[9];
} c_struct_T_Pix_FCC_flash_T;

#endif                                 //typedef_c_struct_T_Pix_FCC_flash_T

#ifndef typedef_px4_internal_block_PX4SCIRead_T
#define typedef_px4_internal_block_PX4SCIRead_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_P_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
} px4_internal_block_PX4SCIRead_T;

#endif                                 //typedef_px4_internal_block_PX4SCIRead_T

#ifndef typedef_px4_internal_block_Subscriber_T
#define typedef_px4_internal_block_Subscriber_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_P_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
} px4_internal_block_Subscriber_T;

#endif                                 //typedef_px4_internal_block_Subscriber_T

// Parameters for system: '<S9>/Send WhiteNoise Beginning'
typedef struct P_SendWhiteNoiseBeginning_Pix_T_ P_SendWhiteNoiseBeginning_Pix_T;

// Parameters for system: '<S9>/Send Header'
typedef struct P_SendHeader_Pix_FCC_flash_T_ P_SendHeader_Pix_FCC_flash_T;

// Parameters (default storage)
typedef struct P_Pix_FCC_flash_T_ P_Pix_FCC_flash_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Pix_FCC_flash_T RT_MODEL_Pix_FCC_flash_T;

#endif                                 // RTW_HEADER_Pix_FCC_flash_types_h_

//
// File trailer for generated code.
//
// [EOF]
//

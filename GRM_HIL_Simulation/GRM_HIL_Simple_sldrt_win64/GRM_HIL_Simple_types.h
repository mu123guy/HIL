/*
 * GRM_HIL_Simple_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL_Simple".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Dec 30 21:11:00 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GRM_HIL_Simple_types_h_
#define RTW_HEADER_GRM_HIL_Simple_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef struct_emxArray_uint8_T_1x64
#define struct_emxArray_uint8_T_1x64

struct emxArray_uint8_T_1x64
{
  uint8_T data[64];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_uint8_T_1x64*/

#ifndef typedef_emxArray_uint8_T_1x64_GRM_HIL_Simple_T
#define typedef_emxArray_uint8_T_1x64_GRM_HIL_Simple_T

typedef struct emxArray_uint8_T_1x64 emxArray_uint8_T_1x64_GRM_HIL_Simple_T;

#endif                        /*typedef_emxArray_uint8_T_1x64_GRM_HIL_Simple_T*/

/* Parameters (default storage) */
typedef struct P_GRM_HIL_Simple_T_ P_GRM_HIL_Simple_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_GRM_HIL_Simple_T RT_MODEL_GRM_HIL_Simple_T;

#endif                                 /* RTW_HEADER_GRM_HIL_Simple_types_h_ */

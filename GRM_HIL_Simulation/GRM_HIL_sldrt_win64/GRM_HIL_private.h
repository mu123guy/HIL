/*
 * GRM_HIL_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.44
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Nov  8 10:21:14 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GRM_HIL_private_h_
#define RTW_HEADER_GRM_HIL_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "GRM_HIL.h"

extern void GRM_HIL_Counter_with_external_limit(real_T rtu_limit, real_T
  rtu_last_value, B_Counter_with_external_limit_GRM_HIL_T *localB);

/* private model entry point functions */
extern void GRM_HIL_derivatives(void);

#endif                                 /* RTW_HEADER_GRM_HIL_private_h_ */

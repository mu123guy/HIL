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
 * C source code generated on : Sun Nov 17 18:40:04 2019
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

real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;
extern void GRM_HIL_Enabledpass_Start(DW_Enabledpass_GRM_HIL_T *localDW);
extern void GRM_HIL_Enabledpass_Disable(DW_Enabledpass_GRM_HIL_T *localDW);
extern void GRM_HIL_Enabledpass(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_upper_limit, real_T rtu_lower_limit, real_T
  *rty_upper_limit_pass, real_T *rty_lower_limit_pass, DW_Enabledpass_GRM_HIL_T *
  localDW);
extern void GRM_HIL_Saturation(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_upper_limit, real_T rtu_lower_limit, real_T rtu_in,
  real_T *rty_out, DW_Saturation_GRM_HIL_T *localDW);
extern void GRM_HIL_pass(RT_MODEL_GRM_HIL_T * const GRM_HIL_M, boolean_T
  rtu_Enable, real_T rtu_in, real_T *rty_out, DW_pass_GRM_HIL_T *localDW);
extern void GRM_HIL_IfActionSubsystem1_Init(B_IfActionSubsystem1_GRM_HIL_T
  *localB, P_IfActionSubsystem1_GRM_HIL_T *localP);
extern void GRM_HIL_IfActionSubsystem1(real_T rtu_In1,
  B_IfActionSubsystem1_GRM_HIL_T *localB);
extern void GRM_HIL_IfActionSubsystem_Init(B_IfActionSubsystem_GRM_HIL_T *localB,
  P_IfActionSubsystem_GRM_HIL_T *localP);
extern void GRM_HIL_IfActionSubsystem(real_T rtu_In1,
  B_IfActionSubsystem_GRM_HIL_T *localB);
extern void GRM_HIL_IfActionpass_yaw(real_T rtu_In1, real_T *rty_Out1);

/* private model entry point functions */
extern void GRM_HIL_derivatives(void);

#endif                                 /* RTW_HEADER_GRM_HIL_private_h_ */

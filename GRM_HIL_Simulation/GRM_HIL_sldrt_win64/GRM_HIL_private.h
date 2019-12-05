/*
 * GRM_HIL_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.66
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Nov 27 14:53:03 2019
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

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(const real_T u0[9], const real_T
  u1[3], real_T y[3]);
extern uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
extern real_T intrp3d_l_pw(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride[]);
extern real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
extern void GRM_HIL_Counter_with_external_limit(real_T rtu_limit, real_T
  rtu_last_value, B_Counter_with_external_limit_GRM_HIL_T *localB);
extern void GRM_HIL_Limiting_Acceleration(real_T rtu_siB, real_T rtu_d_siB,
  real_T rtu_dd_siB, B_Limiting_Acceleration_GRM_HIL_T *localB, real_T
  rtp_d_siB_max, real_T rtp_d_siB_min, real_T rtp_dd_siB_max, real_T
  rtp_dd_siB_min, real_T rtp_siB_max, real_T rtp_siB_min);
extern void GRM_HIL_Limiting_Rate(real_T rtu_siB, real_T rtu_d_siB,
  B_Limiting_Rate_GRM_HIL_T *localB, real_T rtp_d_siB_max, real_T rtp_d_siB_min,
  real_T rtp_siB_max, real_T rtp_siB_min);

/* private model entry point functions */
extern void GRM_HIL_derivatives(void);

#endif                                 /* RTW_HEADER_GRM_HIL_private_h_ */

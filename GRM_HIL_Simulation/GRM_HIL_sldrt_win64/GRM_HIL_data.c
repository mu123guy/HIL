/*
 * GRM_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.39
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Oct 17 20:07:41 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GRM_HIL.h"
#include "GRM_HIL_private.h"

/* Block parameters (default storage) */
P_GRM_HIL_T GRM_HIL_P = {
  /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
   * Referenced by: '<S2>/Real-Time Synchronization'
   */
  10.0,

  /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
   * Referenced by: '<S2>/Real-Time Synchronization'
   */
  0.0,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S1>/Constant1'
   */
  1,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S1>/Constant9'
   */
  0,

  /* Expression: HIL_Data.Simulation_Ctrl.offline_flg
   * Referenced by: '<S1>/Constant3'
   */
  1
};

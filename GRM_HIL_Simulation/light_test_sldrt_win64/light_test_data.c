/*
 * light_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "light_test".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Nov 27 14:44:26 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "light_test.h"
#include "light_test_private.h"

/* Block parameters (default storage) */
P_light_test_T light_test_P = {
  /* Mask Parameter: Ramp1_InitialOutput
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Mask Parameter: Ramp2_InitialOutput
   * Referenced by: '<S7>/Constant1'
   */
  0.0,

  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S5>/Constant1'
   */
  0.0,

  /* Mask Parameter: Receive_from_FTHWICC_MaxMissedTicks
   * Referenced by: '<Root>/Receive_from_FTHWICC'
   */
  1000.0,

  /* Mask Parameter: Send_to_FTHWICC_MaxMissedTicks
   * Referenced by: '<Root>/Send_to_FTHWICC'
   */
  1000.0,

  /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
   * Referenced by: '<Root>/Real-Time Synchronization'
   */
  100.0,

  /* Mask Parameter: Receive_from_FTHWICC_YieldWhenWaiting
   * Referenced by: '<Root>/Receive_from_FTHWICC'
   */
  1.0,

  /* Mask Parameter: Send_to_FTHWICC_YieldWhenWaiting
   * Referenced by: '<Root>/Send_to_FTHWICC'
   */
  1.0,

  /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
   * Referenced by: '<Root>/Real-Time Synchronization'
   */
  0.0,

  /* Mask Parameter: Ramp1_slope
   * Referenced by: '<S6>/Step'
   */
  0.0,

  /* Mask Parameter: Ramp2_slope
   * Referenced by: '<S7>/Step'
   */
  0.0,

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S5>/Step'
   */
  45.0,

  /* Mask Parameter: Ramp1_start
   * Referenced by:
   *   '<S6>/Constant'
   *   '<S6>/Step'
   */
  0.0,

  /* Mask Parameter: Ramp2_start
   * Referenced by:
   *   '<S7>/Constant'
   *   '<S7>/Step'
   */
  0.0,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S5>/Step'
   */
  0.0,

  /* Mask Parameter: Receive_from_FTHWICC_PacketID
   * Referenced by: '<Root>/Receive_from_FTHWICC'
   */
  1,

  /* Mask Parameter: Send_to_FTHWICC_PacketID
   * Referenced by: '<Root>/Send_to_FTHWICC'
   */
  1,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S9>/FixPt Switch'
   */
  65535U,

  /* Expression: 0
   * Referenced by: '<S6>/Step'
   */
  0.0,

  /* Expression: -(2*pi)/(65536)
   * Referenced by: '<Root>/Shaft2radPitch'
   */
  -9.5873799242852573E-5,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S7>/Step'
   */
  0.0,

  /* Expression: (2*pi)/(65536)
   * Referenced by: '<Root>/Shaft2radYaw1'
   */
  9.5873799242852573E-5,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S5>/Step'
   */
  0.0,

  /* Expression: -(2*pi)/(65536)
   * Referenced by: '<Root>/Shaft2radRoll1'
   */
  -9.5873799242852573E-5,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Zero'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Zero1'
   */
  1.0,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S9>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S1>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S8>/FixPt Constant'
   */
  1U
};

/*
 * GRM_HIL_Simple_data.c
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

#include "GRM_HIL_Simple.h"
#include "GRM_HIL_Simple_private.h"

/* Block parameters (default storage) */
P_GRM_HIL_Simple_T GRM_HIL_Simple_P = {
  /* Mask Parameter: PacketInput_MaxMissedTicks
   * Referenced by: '<Root>/Packet Input'
   */
  100.0,

  /* Mask Parameter: PacketInput_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Input'
   */
  1.0,

  /* Mask Parameter: PacketInput_PacketID
   * Referenced by: '<Root>/Packet Input'
   */
  1,

  /* Computed Parameter: ServoCMD_Y0
   * Referenced by: '<S3>/ServoCMD'
   */
  0.0F,

  /* Computed Parameter: SensorACC_Y0
   * Referenced by: '<S3>/SensorACC'
   */
  0.0F,

  /* Computed Parameter: SensorROT_Y0
   * Referenced by: '<S3>/SensorROT'
   */
  0.0F,

  /* Computed Parameter: quaternion_Y0
   * Referenced by: '<S3>/quaternion'
   */
  0.0F,

  /* Computed Parameter: TestSignal_Y0
   * Referenced by: '<S3>/TestSignal'
   */
  0.0F,

  /* Computed Parameter: PixHeartbeat_Y0
   * Referenced by: '<S3>/PixHeartbeat'
   */
  0U,

  /* Computed Parameter: PixStatus_Y0
   * Referenced by: '<S3>/PixStatus'
   */
  0U,

  /* Computed Parameter: PixRCStatus_Y0
   * Referenced by: '<S3>/PixRCStatus'
   */
  0U
};

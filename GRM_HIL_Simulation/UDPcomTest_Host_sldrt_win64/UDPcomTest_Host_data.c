/*
 * UDPcomTest_Host_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UDPcomTest_Host".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Oct 29 22:11:33 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UDPcomTest_Host.h"
#include "UDPcomTest_Host_private.h"

/* Invariant block signals (default storage) */
const ConstB_UDPcomTest_Host_T UDPcomTest_Host_ConstB = {
  52.0                                 /* '<Root>/Width' */
};

/* Block parameters (default storage) */
P_UDPcomTest_Host_T UDPcomTest_Host_P = {
  /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
   * Referenced by: '<Root>/Real-Time Synchronization'
   */
  10.0,

  /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
   * Referenced by: '<Root>/Real-Time Synchronization'
   */
  1.0,

  /* Computed Parameter: UDPConfigure_P1_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: ipAdd
   * Referenced by: '<Root>/UDP Configure'
   */
  { 192.0, 168.0, 1.0, 127.0 },

  /* Computed Parameter: UDPConfigure_P2_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: snMask
   * Referenced by: '<Root>/UDP Configure'
   */
  { 255.0, 255.0, 255.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P3_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: gwAdd
   * Referenced by: '<Root>/UDP Configure'
   */
  { 192.0, 168.0, 1.0, 1.0 },

  /* Computed Parameter: UDPConfigure_P4_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P5_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: enableMulticast
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P6_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P7_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P8_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciBus
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P9_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciSlot
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P10_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciFunction
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P11_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: tune
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P12_Size
   * Referenced by: '<Root>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: disable
   * Referenced by: '<Root>/UDP Configure'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Zero'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/Signal Generator'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<Root>/Signal Generator'
   */
  1.0,

  /* Computed Parameter: UDPSend2_P1_Size
   * Referenced by: '<Root>/UDP Send2'
   */
  { 1.0, 26.0 },

  /* Computed Parameter: UDPSend2_P1
   * Referenced by: '<Root>/UDP Send2'
   */
  { 85.0, 115.0, 101.0, 32.0, 104.0, 111.0, 115.0, 116.0, 45.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 32.0, 99.0, 111.0, 110.0, 110.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0 },

  /* Computed Parameter: UDPSend2_P2_Size
   * Referenced by: '<Root>/UDP Send2'
   */
  { 1.0, 1.0 },

  /* Expression: localPort
   * Referenced by: '<Root>/UDP Send2'
   */
  36864.0,

  /* Computed Parameter: UDPSend2_P3_Size
   * Referenced by: '<Root>/UDP Send2'
   */
  { 1.0, 13.0 },

  /* Computed Parameter: UDPSend2_P3
   * Referenced by: '<Root>/UDP Send2'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 49.0, 46.0, 49.0, 53.0, 54.0
  },

  /* Computed Parameter: UDPSend2_P4_Size
   * Referenced by: '<Root>/UDP Send2'
   */
  { 1.0, 1.0 },

  /* Expression: toPort
   * Referenced by: '<Root>/UDP Send2'
   */
  36880.0,

  /* Computed Parameter: UDPSend2_P5_Size
   * Referenced by: '<Root>/UDP Send2'
   */
  { 1.0, 1.0 },

  /* Expression: useHostTargetComm
   * Referenced by: '<Root>/UDP Send2'
   */
  1.0,

  /* Computed Parameter: UDPSend2_P6_Size
   * Referenced by: '<Root>/UDP Send2'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/UDP Send2'
   */
  -1.0
};

/*
 * UDPcomTest_Host_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&UDPcomTest_Host_B.SignalGenerator), 0, 0, 1 },

  { (char_T *)(&UDPcomTest_Host_B.Cast), 5, 0, 1 },

  { (char_T *)(&UDPcomTest_Host_B.BytePacking[0]), 3, 0, 52 },

  { (char_T *)(&UDPcomTest_Host_B.CastToBoolean), 8, 0, 2 }
  ,

  { (char_T *)(&UDPcomTest_Host_DW.UDPConfigure_PWORK[0]), 11, 0, 8 },

  { (char_T *)(&UDPcomTest_Host_DW.UDPConfigure_IWORK[0]), 10, 0, 27 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&UDPcomTest_Host_P.RealTimeSynchronization_MaxMissedTicks), 0, 0,
    103 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] UDPcomTest_Host_dt.h */

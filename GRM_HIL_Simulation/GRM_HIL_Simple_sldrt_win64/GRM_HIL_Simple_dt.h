/*
 * GRM_HIL_Simple_dt.h
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
  { (char_T *)(&GRM_HIL_Simple_B.PacketInput_o1[0]), 3, 0, 78 },

  { (char_T *)(&GRM_HIL_Simple_B.PacketInput_o2), 8, 0, 4 }
  ,

  { (char_T *)(&GRM_HIL_Simple_DW.PacketInput_PWORK), 11, 0, 5 },

  { (char_T *)(&GRM_HIL_Simple_DW.SFunction_DIMS2[0]), 6, 0, 2 },

  { (char_T *)(&GRM_HIL_Simple_DW.hold_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&GRM_HIL_Simple_P.PacketInput_MaxMissedTicks), 0, 0, 2 },

  { (char_T *)(&GRM_HIL_Simple_P.PacketInput_PacketID), 6, 0, 1 },

  { (char_T *)(&GRM_HIL_Simple_P.ServoCMD_Y0), 1, 0, 5 },

  { (char_T *)(&GRM_HIL_Simple_P.PixHeartbeat_Y0), 5, 0, 1 },

  { (char_T *)(&GRM_HIL_Simple_P.PixStatus_Y0), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] GRM_HIL_Simple_dt.h */

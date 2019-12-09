/*
 * untitled_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Nov 27 12:02:27 2019
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
  { (char_T *)(&untitled_B.Receive_from_FTHWICC_o1), 0, 0, 14 },

  { (char_T *)(&untitled_B.Receive_from_FTHWICC_o12), 6, 0, 2 },

  { (char_T *)(&untitled_B.Receive_from_FTHWICC_o8), 5, 0, 3 },

  { (char_T *)(&untitled_B.CastToBoolean), 8, 0, 2 }
  ,

  { (char_T *)(&untitled_DW.Receive_from_FTHWICC_PWORK), 11, 0, 12 },

  { (char_T *)(&untitled_DW.Output_DSTATE), 5, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled_P.Ramp1_InitialOutput), 0, 0, 15 },

  { (char_T *)(&untitled_P.Receive_from_FTHWICC_PacketID), 6, 0, 2 },

  { (char_T *)(&untitled_P.WrapToZero_Threshold), 5, 0, 1 },

  { (char_T *)(&untitled_P.Step_Y0), 0, 0, 12 },

  { (char_T *)(&untitled_P.Constant_Value_b), 5, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] untitled_dt.h */

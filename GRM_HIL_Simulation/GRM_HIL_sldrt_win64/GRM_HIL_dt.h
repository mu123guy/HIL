/*
 * GRM_HIL_dt.h
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
  2*sizeof(uint32_T),
  sizeof(FDM_Ctrl_Bus),
  sizeof(HW_Ctrl_Bus),
  sizeof(FCC_Ctrl_Bus),
  sizeof(COM_Ctrl_Bus),
  sizeof(Simulation_Ctrl_Bus),
  sizeof(struct_ox3hNlE5f9EVkxBowKM3IG)
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
  "timer_uint32_pair_T",
  "FDM_Ctrl_Bus",
  "HW_Ctrl_Bus",
  "FCC_Ctrl_Bus",
  "COM_Ctrl_Bus",
  "Simulation_Ctrl_Bus",
  "struct_ox3hNlE5f9EVkxBowKM3IG"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&GRM_HIL_DW.RealTimeSynchronization_PWORK), 11, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&GRM_HIL_P.RealTimeSynchronization_MaxMissedTicks), 0, 0, 2 },

  { (char_T *)(&GRM_HIL_P.Constant1_Value), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] GRM_HIL_dt.h */

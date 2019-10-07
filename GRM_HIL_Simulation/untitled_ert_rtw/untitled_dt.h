//
//  untitled_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "untitled".
//
//  Model version              : 1.0
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Sun Oct  6 19:40:43 2019
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
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
  sizeof(uint64_T),
  sizeof(px4_Bus_sensor_mag),
  sizeof(px4_Bus_vehicle_attitude),
  sizeof(px4_internal_block_Subscriber_T),
  sizeof(int64_T),
  sizeof(uint64_T)
};

// data type name table
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
  "uint64_T",
  "px4_Bus_sensor_mag",
  "px4_Bus_vehicle_attitude",
  "px4_internal_block_Subscriber_T",
  "int64_T",
  "uint64_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&untitled_B.In1), 15, 0, 1 },

  { (char_T *)(&untitled_B.x), 1, 0, 3 }
  ,

  { (char_T *)(&untitled_DW.obj), 17, 0, 2 },

  { (char_T *)(&untitled_DW.Scope_PWORK.LoggedData[0]), 11, 0, 3 },

  { (char_T *)(&untitled_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 2 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled_P.Out1_Y0), 15, 0, 1 },

  { (char_T *)(&untitled_P.Constant_Value), 15, 0, 1 },

  { (char_T *)(&untitled_P.Out1_Y0_i), 16, 0, 1 },

  { (char_T *)(&untitled_P.Constant_Value_p), 16, 0, 1 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

// [EOF] untitled_dt.h

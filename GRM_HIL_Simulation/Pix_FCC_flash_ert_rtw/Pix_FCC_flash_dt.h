//
//  Pix_FCC_flash_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Pix_FCC_flash".
//
//  Model version              : 1.333
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Thu Jan  2 22:43:22 2020
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
  sizeof(struct_QhvhhqDV0L2yxKLWicNneD),
  sizeof(struct_NXU1FRSfNm9MZqPmiPj5nG),
  sizeof(struct_NKNq6gj8dL8ticSV3dO1LF),
  sizeof(struct_6DMhF3HgatZ0SVFTbVEXUB),
  sizeof(struct_0bCECObDp9cpwUujjacDoB),
  sizeof(struct_mvMpa6roJ3cC08QEKeHpUD),
  sizeof(struct_SpfmErt2JG4vKmjTJRH6OB),
  sizeof(struct_skgRGNdg4uikkiJBtrraoB),
  sizeof(struct_7SrGNOW0Gr039ZOMvXVVTD),
  sizeof(struct_5yp7NkUa494t53XXuhQozD),
  sizeof(struct_kDC9SqVquJgNZQDtb5tZbG),
  sizeof(uint64_T),
  sizeof(px4_Bus_sensor_accel),
  sizeof(px4_Bus_sensor_gyro),
  sizeof(px4_Bus_vehicle_attitude),
  sizeof(uint16_T),
  sizeof(px4_internal_block_PX4SCIWrit_T),
  sizeof(px4_internal_block_PWM_Pix_FC_T),
  sizeof(px4_internal_block_PX4SCIRead_T),
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
  "struct_QhvhhqDV0L2yxKLWicNneD",
  "struct_NXU1FRSfNm9MZqPmiPj5nG",
  "struct_NKNq6gj8dL8ticSV3dO1LF",
  "struct_6DMhF3HgatZ0SVFTbVEXUB",
  "struct_0bCECObDp9cpwUujjacDoB",
  "struct_mvMpa6roJ3cC08QEKeHpUD",
  "struct_SpfmErt2JG4vKmjTJRH6OB",
  "struct_skgRGNdg4uikkiJBtrraoB",
  "struct_7SrGNOW0Gr039ZOMvXVVTD",
  "struct_5yp7NkUa494t53XXuhQozD",
  "struct_kDC9SqVquJgNZQDtb5tZbG",
  "uint64_T",
  "px4_Bus_sensor_accel",
  "px4_Bus_sensor_gyro",
  "px4_Bus_vehicle_attitude",
  "uint16_T",
  "px4_internal_block_PX4SCIWrit_T",
  "px4_internal_block_PWM_Pix_FC_T",
  "px4_internal_block_PX4SCIRead_T",
  "px4_internal_block_Subscriber_T",
  "int64_T",
  "uint64_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Pix_FCC_flash_B.In1), 27, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_B.In1_j), 26, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_B.In1_c), 28, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_B.Cast1[0]), 1, 0, 16 },

  { (char_T *)(&Pix_FCC_flash_B.msgOut[0]), 3, 0, 64 },

  { (char_T *)(&Pix_FCC_flash_B.SineWave), 0, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_B.TestSignal_update), 1, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_B.Cast[0]), 5, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_B.update[0]), 3, 0, 136 },

  { (char_T *)(&Pix_FCC_flash_B.SimHeartbeat_update), 5, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_B.packetfound), 8, 0, 2 }
  ,

  { (char_T *)(&Pix_FCC_flash_DW.obj), 32, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.obj_h), 30, 0, 3 },

  { (char_T *)(&Pix_FCC_flash_DW.obj_j), 31, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.obj_c), 33, 0, 3 },

  { (char_T *)(&Pix_FCC_flash_DW.lastSin), 0, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_DW.ToWorkspace_PWORK.LoggedData), 11, 0, 10 },

  { (char_T *)(&Pix_FCC_flash_DW.DiscreteTransferFcn2_states), 1, 0, 3 },

  { (char_T *)(&Pix_FCC_flash_DW.SFunction_DIMS2[0]), 6, 0, 7 },

  { (char_T *)(&Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 18 },

  { (char_T *)(&Pix_FCC_flash_DW.DecodeCommand_MODE), 8, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.obj), 30, 0, 1 },

  { (char_T *)
    (&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.SendWhiteNoiseBeginning_SubsysR), 2,
    0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.objisempty), 8, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendTerminator_g.obj), 30, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendTerminator_g.SendHeader_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendTerminator_g.objisempty), 8, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendHeader_k.obj), 30, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendHeader_k.SendHeader_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendHeader_k.objisempty), 8, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.obj), 30, 0, 1 },

  { (char_T *)
    (&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.SendWhiteNoiseBeginning_SubsysR),
    2, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.objisempty), 8, 0, 1
  },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseEnd.obj), 30, 0, 1 },

  { (char_T *)
    (&Pix_FCC_flash_DW.SendWhiteNoiseEnd.SendWhiteNoiseBeginning_SubsysR), 2, 0,
    1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseEnd.objisempty), 8, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendTerminator.obj), 30, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendTerminator.SendHeader_SubsysRanBC), 2, 0, 1
  },

  { (char_T *)(&Pix_FCC_flash_DW.SendTerminator.objisempty), 8, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendHeader.obj), 30, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendHeader.SendHeader_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendHeader.objisempty), 8, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning.obj), 30, 0, 1 },

  { (char_T *)
    (&Pix_FCC_flash_DW.SendWhiteNoiseBeginning.SendWhiteNoiseBeginning_SubsysR),
    2, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_DW.SendWhiteNoiseBeginning.objisempty), 8, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  45U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Pix_FCC_flash_P.FCC_PIX_Data), 24, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.CompareToConstant_const), 0, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.Out1_Y0), 26, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.Constant_Value), 26, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.Out1_Y0_f), 27, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.Constant_Value_e), 27, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.Out1_Y0_a), 28, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.Constant_Value_l), 28, 0, 1 },

  { (char_T *)(&Pix_FCC_flash_P.ReceiveData_SampleTime), 0, 0, 13 },

  { (char_T *)(&Pix_FCC_flash_P.CMD_Y0), 1, 0, 30 },

  { (char_T *)(&Pix_FCC_flash_P.ms2us_1_Gain), 29, 0, 8 },

  { (char_T *)(&Pix_FCC_flash_P.cmd_found_flg_Y0), 8, 0, 4 },

  { (char_T *)(&Pix_FCC_flash_P.Header_Value), 3, 0, 5 },

  { (char_T *)(&Pix_FCC_flash_P.SendWhiteNoiseEnd_a.Header_Value[0]), 3, 0, 5 },

  { (char_T *)(&Pix_FCC_flash_P.SendTerminator_g.Header_Value[0]), 3, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_P.SendHeader_k.Header_Value[0]), 3, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_P.SendWhiteNoiseBeginning_p.Header_Value[0]), 3, 0,
    5 },

  { (char_T *)(&Pix_FCC_flash_P.SendWhiteNoiseEnd.Header_Value[0]), 3, 0, 5 },

  { (char_T *)(&Pix_FCC_flash_P.SendTerminator.Header_Value[0]), 3, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_P.SendHeader.Header_Value[0]), 3, 0, 2 },

  { (char_T *)(&Pix_FCC_flash_P.SendWhiteNoiseBeginning.Header_Value[0]), 3, 0,
    5 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  21U,
  rtPTransitions
};

// [EOF] Pix_FCC_flash_dt.h

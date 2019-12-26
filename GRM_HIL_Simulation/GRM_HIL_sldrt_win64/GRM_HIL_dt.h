/*
 * GRM_HIL_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.72
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Dec 12 16:42:59 2019
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
  sizeof(Guidance_Cmd_Bus),
  sizeof(Controller_Cmd_Bus),
  sizeof(ATT_Cmd_Bus),
  sizeof(Control_Surface_Cmd_Bus),
  sizeof(PWM_Cmd_Bus),
  sizeof(Servo_Cmd_Bus),
  sizeof(Airframe_Cmd_Bus),
  sizeof(FCC_Commands_Bus),
  sizeof(Control_Surface_Deflections_Bus),
  sizeof(Inc_Encoder_Signal_Bus),
  sizeof(Control_Surface_Encoder_Bus),
  sizeof(Control_Surface_Bus),
  sizeof(Servo_Positions_Bus),
  sizeof(Servo_State_Bus),
  sizeof(struct_fqhbejXln8QRylaPqhUyTF),
  sizeof(struct_7SrGNOW0Gr039ZOMvXVVTD),
  sizeof(Disturbances_Bus),
  sizeof(struct_JmsfHiggjss7x7dzfcXt9F),
  sizeof(struct_BTftwrJbWeM670O1XPTZ1C),
  sizeof(struct_E9xfJrDS8wEcyfYN6eOlYG),
  sizeof(struct_78MT3wT9fhi8ylbZWwPhqH),
  sizeof(struct_ZjOGsVCdaOvRjDkE3POHEH),
  sizeof(struct_Dnn86pR2ImcbhyRO1T2RoG),
  sizeof(struct_sxk43YQUkK2Dy1nZBRwOqG),
  sizeof(struct_DDaxnFjCqgRTmNKEA8BdXD),
  sizeof(struct_aIthSv6eARLciQWCxnpfcH),
  sizeof(struct_IESddi9utHoLtu4Ib32CTE),
  sizeof(struct_7WkwfrLVv4fBDn3BNGhavG),
  sizeof(struct_Y7PS1rxhiw1TKkxrPVqWqG),
  sizeof(FDM_External_Inputs_Bus),
  sizeof(FCC_External_Inputs_Bus),
  sizeof(External_Inputs_Bus),
  sizeof(Translation_States_Bus),
  sizeof(Translation_States_Dot_Bus),
  sizeof(Rotation_States_Bus),
  sizeof(ATT_Euler_Bus),
  sizeof(ATT_Quaternions_Bus),
  sizeof(Attitude_States_Bus),
  sizeof(POS_WGS84_Bus),
  sizeof(POS_NED_Bus),
  sizeof(Position_States_Bus),
  sizeof(Rigid_Body_States_Bus),
  sizeof(Airframe_States_Bus),
  sizeof(Atm_States_Bus),
  sizeof(States_Bus),
  sizeof(Gimbal_Status_Bus),
  sizeof(Gimbal_Attitude_Bus),
  sizeof(Encoder_Resolved_Bus),
  sizeof(Encoder_Signal_Bus),
  sizeof(Gimbal_Encoder_Bus),
  sizeof(Gimbal_State_Bus),
  sizeof(struct_fPSpQec4CK6Ld2LdBMMAbH),
  sizeof(struct_o6lBeR5a4wCQZKjH0CEd8D),
  sizeof(Gimbal_Cmd_Bus),
  sizeof(struct_RIcaXENoLMkyG3vAzx3LrF),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_mYoNNcm8zkJZX9FXsF2g2F),
  sizeof(struct_FhGLidBATzAyVEgGPUcCPB),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_ox3hNlE5f9EVkxBowKM3IG),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_mYS1N2caX135AIcTArxUzD),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_VkUZsEuPLDWiHwBdN4zERD)
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
  "Guidance_Cmd_Bus",
  "Controller_Cmd_Bus",
  "ATT_Cmd_Bus",
  "Control_Surface_Cmd_Bus",
  "PWM_Cmd_Bus",
  "Servo_Cmd_Bus",
  "Airframe_Cmd_Bus",
  "FCC_Commands_Bus",
  "Control_Surface_Deflections_Bus",
  "Inc_Encoder_Signal_Bus",
  "Control_Surface_Encoder_Bus",
  "Control_Surface_Bus",
  "Servo_Positions_Bus",
  "Servo_State_Bus",
  "struct_fqhbejXln8QRylaPqhUyTF",
  "struct_7SrGNOW0Gr039ZOMvXVVTD",
  "Disturbances_Bus",
  "struct_JmsfHiggjss7x7dzfcXt9F",
  "struct_BTftwrJbWeM670O1XPTZ1C",
  "struct_E9xfJrDS8wEcyfYN6eOlYG",
  "struct_78MT3wT9fhi8ylbZWwPhqH",
  "struct_ZjOGsVCdaOvRjDkE3POHEH",
  "struct_Dnn86pR2ImcbhyRO1T2RoG",
  "struct_sxk43YQUkK2Dy1nZBRwOqG",
  "struct_DDaxnFjCqgRTmNKEA8BdXD",
  "struct_aIthSv6eARLciQWCxnpfcH",
  "struct_IESddi9utHoLtu4Ib32CTE",
  "struct_7WkwfrLVv4fBDn3BNGhavG",
  "struct_Y7PS1rxhiw1TKkxrPVqWqG",
  "FDM_External_Inputs_Bus",
  "FCC_External_Inputs_Bus",
  "External_Inputs_Bus",
  "Translation_States_Bus",
  "Translation_States_Dot_Bus",
  "Rotation_States_Bus",
  "ATT_Euler_Bus",
  "ATT_Quaternions_Bus",
  "Attitude_States_Bus",
  "POS_WGS84_Bus",
  "POS_NED_Bus",
  "Position_States_Bus",
  "Rigid_Body_States_Bus",
  "Airframe_States_Bus",
  "Atm_States_Bus",
  "States_Bus",
  "Gimbal_Status_Bus",
  "Gimbal_Attitude_Bus",
  "Encoder_Resolved_Bus",
  "Encoder_Signal_Bus",
  "Gimbal_Encoder_Bus",
  "Gimbal_State_Bus",
  "struct_fPSpQec4CK6Ld2LdBMMAbH",
  "struct_o6lBeR5a4wCQZKjH0CEd8D",
  "Gimbal_Cmd_Bus",
  "struct_RIcaXENoLMkyG3vAzx3LrF",
  "struct_6JYiwTdRKKhxfBKN0w9nVE",
  "struct_uhaEMcJIylUFFasxlVDbdB",
  "struct_i6UKurBLXspNOGF6VmsztG",
  "struct_tHPoLpLgpUwbYSQlsiT9z",
  "struct_mYoNNcm8zkJZX9FXsF2g2F",
  "struct_FhGLidBATzAyVEgGPUcCPB",
  "struct_sFIRz83TC31UH8oSne9u9B",
  "struct_PMY2MVbokF6bomnXxgdnTE",
  "struct_ox3hNlE5f9EVkxBowKM3IG",
  "struct_iVfILTItcdAMASpwpYoPC",
  "struct_0NRBZ13rBacCjb5oc2qc9B",
  "struct_mYS1N2caX135AIcTArxUzD",
  "struct_0Ybs33XGG556qmFMMPfasF",
  "struct_RypLSVNConU9zljTETvwAE",
  "struct_VkUZsEuPLDWiHwBdN4zERD"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&GRM_HIL_B.Constant[0]), 0, 0, 257 },

  { (char_T *)(&GRM_HIL_B.DataTypeConversion3), 1, 0, 17 },

  { (char_T *)(&GRM_HIL_B.Receive_from_FTHWICC_o8), 5, 0, 3 },

  { (char_T *)(&GRM_HIL_B.message[0]), 3, 0, 206 },

  { (char_T *)(&GRM_HIL_B.Compare), 8, 0, 9 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Rate_d.d_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Acceleration_h.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Rate_g.d_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Acceleration_p.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Rate_o.d_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Acceleration_i.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Rate.d_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Limiting_Acceleration.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Counter_with_external_limit_j.value), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.sf_Counter_with_external_limit.value), 0, 0, 1 }
  ,

  { (char_T *)(&GRM_HIL_DW.Memory_PreviousInput), 0, 0, 10 },

  { (char_T *)
    (&GRM_HIL_DW.TAQSigLogging_InsertedFor_Actuators_at_outport_0_1_PWORK.AQHandles
     [0]), 11, 0, 87 },

  { (char_T *)(&GRM_HIL_DW.clockTickCounter), 6, 0, 8 },

  { (char_T *)(&GRM_HIL_DW.integration_eom_IWORK), 10, 0, 3 },

  { (char_T *)(&GRM_HIL_DW.Output_DSTATE), 5, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC), 2, 0, 9 },

  { (char_T *)(&GRM_HIL_DW.Send_to_FTHWICC_MODE), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  22U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&GRM_HIL_P.HIL_Sample_Time), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.External_Inputs_External_Inputs), 47, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Servo_TF), 33, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Servo_PWM), 34, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Serial_Recieve_from_Pixhawk_Serial), 71, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Serial_Send_to_Pixhawk_Serial), 71, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Communication_FT_HWI_ControlComputer_HW), 73, 0, 1 },

  { (char_T *)(&GRM_HIL_P.RealTimeSynchronization_MaxMissedTicks), 0, 0, 74 },

  { (char_T *)(&GRM_HIL_P.PacketInput_PacketID), 6, 0, 4 },

  { (char_T *)(&GRM_HIL_P.WrapToZero_Threshold), 5, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Gimbal_Pos_Encoder_Y0), 88, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Gimbal_Pos_Y0), 85, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Gimbal_Status_Y0), 64, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Constant11_Value), 0, 0, 117584 },

  { (char_T *)(&GRM_HIL_P.ServoCMD_Y0), 1, 0, 6 },

  { (char_T *)(&GRM_HIL_P.Cn_delta_n_Interpolation_dimSize[0]), 7, 0, 135 },

  { (char_T *)(&GRM_HIL_P.PixHeartbeat_Y0), 5, 0, 6 },

  { (char_T *)(&GRM_HIL_P.Constant10_Value_ca), 8, 0, 12 },

  { (char_T *)(&GRM_HIL_P.Data_Y0), 3, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  19U,
  rtPTransitions
};

/* [EOF] GRM_HIL_dt.h */

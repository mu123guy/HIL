/*
 * GRM_HIL_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.41
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Oct 22 17:22:55 2019
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
  sizeof(struct_skgRGNdg4uikkiJBtrraoB),
  sizeof(struct_QhvhhqDV0L2yxKLWicNneD),
  sizeof(struct_NXU1FRSfNm9MZqPmiPj5nG),
  sizeof(struct_NKNq6gj8dL8ticSV3dO1LF),
  sizeof(struct_6DMhF3HgatZ0SVFTbVEXUB),
  sizeof(struct_0bCECObDp9cpwUujjacDoB),
  sizeof(struct_mvMpa6roJ3cC08QEKeHpUD),
  sizeof(struct_SpfmErt2JG4vKmjTJRH6OB),
  sizeof(Gimbal_Cmd_Bus),
  sizeof(Gimbal_Ctrl_Bus),
  sizeof(struct_2rU9DLCenxPBMI086Phyx),
  sizeof(struct_u9tuPjUAEO3XkpAUDGTraG),
  sizeof(struct_3GFOl0CrpEtPiCeQKu5bZE),
  sizeof(struct_1jtd4lthR1rS618lzimrEB),
  sizeof(struct_X0z48mq1MJmnXMBjrHYvYC),
  sizeof(Gimbal_Monitor_Bus),
  sizeof(struct_t5lid3aqguggysQaotuOhC),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_mYoNNcm8zkJZX9FXsF2g2F),
  sizeof(struct_FhGLidBATzAyVEgGPUcCPB),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_errdMCbHz1cMJbppgk8LIB),
  sizeof(struct_gVgWE69OTiTtzAMsR3MJsC),
  sizeof(struct_gVSI4amxfkcy305kW5mKdH),
  sizeof(struct_wyEKKkcd8BACb1iLAvhQk),
  sizeof(struct_xafWrx5dwrT8wEsj34nY2B),
  sizeof(struct_VJfvuolwvM7SfBw5IatJHB),
  sizeof(struct_6yieiUosI8n55HFNH6sc1E),
  sizeof(struct_rbGXZIRavRMiH1t6AwY3XC),
  sizeof(struct_1C0BjtB5SsjK4VFo76IvTB),
  sizeof(struct_fe7TJqA5KkvdSuJ9ACOEtE),
  sizeof(struct_QYQbPonDnj8SpvphQIjHLE),
  sizeof(struct_0kz5Xf5aDCvwuRhz9h36UB),
  sizeof(FDM_States_Bus),
  sizeof(ATT_Euler_Dot_Bus),
  sizeof(POS_WGS84_Dot_Bus),
  sizeof(POS_NED_Dot_Bus),
  sizeof(Position_States_Dot_Bus),
  sizeof(Airframe_States_Dot_Bus),
  sizeof(FDM_States_Dot_Bus),
  sizeof(FDM_Rot_Body_Bus),
  sizeof(struct_ox3hNlE5f9EVkxBowKM3IG),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_8dn0WBFJAEipy0bhP7ue2G),
  sizeof(struct_4BEF1wwN52Uf7px5A1b9LF),
  sizeof(int32_T),
  sizeof(struct_mYS1N2caX135AIcTArxUzD),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_VkUZsEuPLDWiHwBdN4zERD),
  sizeof(struct_naMSiPeANZdxK1BVj547qE),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_lQamzfSfua9vI4k5KcpdyB),
  sizeof(struct_biIcle9l5pPUJAEhBiubME),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(struct_HOsjcyeSDQ7kNiQxBq2HXH),
  sizeof(struct_F8un5srqOha4P4SBfdUeHD)
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
  "struct_skgRGNdg4uikkiJBtrraoB",
  "struct_QhvhhqDV0L2yxKLWicNneD",
  "struct_NXU1FRSfNm9MZqPmiPj5nG",
  "struct_NKNq6gj8dL8ticSV3dO1LF",
  "struct_6DMhF3HgatZ0SVFTbVEXUB",
  "struct_0bCECObDp9cpwUujjacDoB",
  "struct_mvMpa6roJ3cC08QEKeHpUD",
  "struct_SpfmErt2JG4vKmjTJRH6OB",
  "Gimbal_Cmd_Bus",
  "Gimbal_Ctrl_Bus",
  "struct_2rU9DLCenxPBMI086Phyx",
  "struct_u9tuPjUAEO3XkpAUDGTraG",
  "struct_3GFOl0CrpEtPiCeQKu5bZE",
  "struct_1jtd4lthR1rS618lzimrEB",
  "struct_X0z48mq1MJmnXMBjrHYvYC",
  "Gimbal_Monitor_Bus",
  "struct_t5lid3aqguggysQaotuOhC",
  "struct_6JYiwTdRKKhxfBKN0w9nVE",
  "struct_uhaEMcJIylUFFasxlVDbdB",
  "struct_i6UKurBLXspNOGF6VmsztG",
  "struct_tHPoLpLgpUwbYSQlsiT9z",
  "struct_mYoNNcm8zkJZX9FXsF2g2F",
  "struct_FhGLidBATzAyVEgGPUcCPB",
  "struct_sFIRz83TC31UH8oSne9u9B",
  "struct_PMY2MVbokF6bomnXxgdnTE",
  "struct_errdMCbHz1cMJbppgk8LIB",
  "struct_gVgWE69OTiTtzAMsR3MJsC",
  "struct_gVSI4amxfkcy305kW5mKdH",
  "struct_wyEKKkcd8BACb1iLAvhQk",
  "struct_xafWrx5dwrT8wEsj34nY2B",
  "struct_VJfvuolwvM7SfBw5IatJHB",
  "struct_6yieiUosI8n55HFNH6sc1E",
  "struct_rbGXZIRavRMiH1t6AwY3XC",
  "struct_1C0BjtB5SsjK4VFo76IvTB",
  "struct_fe7TJqA5KkvdSuJ9ACOEtE",
  "struct_QYQbPonDnj8SpvphQIjHLE",
  "struct_0kz5Xf5aDCvwuRhz9h36UB",
  "FDM_States_Bus",
  "ATT_Euler_Dot_Bus",
  "POS_WGS84_Dot_Bus",
  "POS_NED_Dot_Bus",
  "Position_States_Dot_Bus",
  "Airframe_States_Dot_Bus",
  "FDM_States_Dot_Bus",
  "FDM_Rot_Body_Bus",
  "struct_ox3hNlE5f9EVkxBowKM3IG",
  "struct_vJMoFPSH9NALCP1mHITHrG",
  "struct_ZudztpyQGtxOgMLSxGNmCG",
  "struct_bVdv2ZSjU8Gsc487I7DwfB",
  "struct_M0NYTmdgUyy4iYfKd92SN",
  "struct_uW0pADlVZ53DtScI11SOAD",
  "struct_0NRBZ13rBacCjb5oc2qc9B",
  "struct_tvjV6s09j6tJWl6vhEIiv",
  "struct_b5bV3m2pbJeNECCAT0pZkB",
  "struct_Tvr8NhakFinFbdhQqtcySF",
  "struct_GqpaI653QCVFqyscAlJs7F",
  "struct_8dn0WBFJAEipy0bhP7ue2G",
  "struct_4BEF1wwN52Uf7px5A1b9LF",
  "struct_iVfILTItcdAMASpwpYoPC",
  "struct_mYS1N2caX135AIcTArxUzD",
  "struct_0Ybs33XGG556qmFMMPfasF",
  "struct_RypLSVNConU9zljTETvwAE",
  "struct_VkUZsEuPLDWiHwBdN4zERD",
  "struct_naMSiPeANZdxK1BVj547qE",
  "struct_h6u9GKWEdHHv63vdLURSfF",
  "struct_JtK879baWFBLS8W1MIdCuF",
  "struct_lQamzfSfua9vI4k5KcpdyB",
  "struct_biIcle9l5pPUJAEhBiubME",
  "struct_naAGVLIRZexd0Cf2GFXscC",
  "struct_jpExsmCK6rgZqQumzT3j3D",
  "struct_VVhaihDhHy5oT5WqtkJGhD",
  "struct_Lh0M8667hlt1EnYL2Mmz5C",
  "struct_ji72VK66eiPQtRblg6iKIE",
  "struct_HOsjcyeSDQ7kNiQxBq2HXH",
  "struct_F8un5srqOha4P4SBfdUeHD"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&GRM_HIL_B.motor_state_perc), 0, 0, 148 },

  { (char_T *)(&GRM_HIL_B.Equal), 8, 0, 31 },

  { (char_T *)(&GRM_HIL_B.IfActionSubsystem_m.In1), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.IfActionSubsystem1_e.In1), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.IfActionSubsystem_p.In1), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.IfActionSubsystem1_j.In1), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.IfActionSubsystem.In1), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_B.IfActionSubsystem1.In1), 0, 0, 1 }
  ,

  { (char_T *)(&GRM_HIL_DW.Memory_PreviousInput), 0, 0, 7 },

  { (char_T *)(&GRM_HIL_DW.ACC_PWORK.LoggedData[0]), 11, 0, 29 },

  { (char_T *)(&GRM_HIL_DW.clockTickCounter), 6, 0, 6 },

  { (char_T *)(&GRM_HIL_DW.Integrator_IWORK), 10, 0, 16 },

  { (char_T *)(&GRM_HIL_DW.If_ActiveSubsystem), 2, 0, 26 },

  { (char_T *)(&GRM_HIL_DW.lock_PreviousInput), 8, 0, 15 },

  { (char_T *)(&GRM_HIL_DW.IfActionpass_roll.IfActionpass_yaw_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&GRM_HIL_DW.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&GRM_HIL_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&GRM_HIL_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&GRM_HIL_DW.pass_l.pass_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Saturation_e.Saturation_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Enabledpass_a.Enabledpass_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Enabledpass_a.Enabledpass_MODE), 8, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.pass_c.pass_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Saturation_j.Saturation_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Enabledpass_j.Enabledpass_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Enabledpass_j.Enabledpass_MODE), 8, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.pass.pass_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Saturation.Saturation_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Enabledpass.Enabledpass_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&GRM_HIL_DW.Enabledpass.Enabledpass_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  35U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&GRM_HIL_P.HIL_Sample_Time), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.FDM_Linear_FDM), 105, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl), 85, 0, 1 },

  { (char_T *)(&GRM_HIL_P.FDM_Linear_TF), 98, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Gimbal_TransferFunctions_TF), 83, 0, 1 },

  { (char_T *)(&GRM_HIL_P.External_Inputs_External_Inputs), 46, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Initial_States_Rigid_Body), 91, 0, 1 },

  { (char_T *)(&GRM_HIL_P.FlightController_FCC), 76, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Servo_TF), 33, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Servo_Cmd_PWM), 34, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Servo_PWM), 34, 0, 1 },

  { (char_T *)(&GRM_HIL_P.ReverseFinDeflection_Control_Surfaces), 69, 0, 1 },

  { (char_T *)(&GRM_HIL_P.FinDeflection_Control_Surfaces), 69, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Servo_Cmd_Control_Surfaces), 69, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Initial_States_Airframe), 60, 0, 1 },

  { (char_T *)(&GRM_HIL_P.PIDController_InitialConditionForFilter), 0, 0, 14 },

  { (char_T *)(&GRM_HIL_P.States_hold_Y0), 126, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Gimbal_State_hold_Y0), 132, 0, 1 },

  { (char_T *)(&GRM_HIL_P.hold_Y0), 143, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Simulation_Control_hold_Y0), 18, 0, 1 },

  { (char_T *)(&GRM_HIL_P.External_Inputs_hold_Y0), 135, 0, 1 },

  { (char_T *)(&GRM_HIL_P.Constant11_Value), 0, 0, 133 },

  { (char_T *)(&GRM_HIL_P.Constant10_Value_c), 8, 0, 15 },

  { (char_T *)(&GRM_HIL_P.IfActionSubsystem_m.Out1_Y0), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.IfActionSubsystem1_e.Out1_Y0), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.IfActionSubsystem_p.Out1_Y0), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.IfActionSubsystem1_j.Out1_Y0), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.IfActionSubsystem.Out1_Y0), 0, 0, 1 },

  { (char_T *)(&GRM_HIL_P.IfActionSubsystem1.Out1_Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  29U,
  rtPTransitions
};

/* [EOF] GRM_HIL_dt.h */

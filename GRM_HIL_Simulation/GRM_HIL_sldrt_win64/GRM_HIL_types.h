/*
 * GRM_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.56
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Nov 26 15:53:25 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GRM_HIL_types_h_
#define RTW_HEADER_GRM_HIL_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_FDM_Ctrl_Bus_
#define DEFINED_TYPEDEF_FOR_FDM_Ctrl_Bus_

typedef struct {
  boolean_T enable_propulsion_flg;
  boolean_T enable_drag_flg;
  boolean_T enable_gravity_flg;
} FDM_Ctrl_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HW_Ctrl_Bus_
#define DEFINED_TYPEDEF_FOR_HW_Ctrl_Bus_

typedef struct {
  real_T enable_gimbal_ctrl_flg;
  real_T stop_gimbal_flg;
} HW_Ctrl_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCC_Ctrl_Bus_
#define DEFINED_TYPEDEF_FOR_FCC_Ctrl_Bus_

typedef struct {
  real_T FCC_SampTime;
  boolean_T DiscreteCtrlTF_flg;
  real_T ComFB_SampTime;
} FCC_Ctrl_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_COM_Ctrl_Bus_
#define DEFINED_TYPEDEF_FOR_COM_Ctrl_Bus_

typedef struct {
  real_T Pix_Com_freq_Hz;
  boolean_T Pix_Com_CRC_flg;
  real_T FT_Com_freq_Hz;
} COM_Ctrl_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Simulation_Ctrl_Bus_
#define DEFINED_TYPEDEF_FOR_Simulation_Ctrl_Bus_

typedef struct {
  boolean_T run;
  boolean_T reset;
  FDM_Ctrl_Bus FDM_Ctrl;
  HW_Ctrl_Bus HW_Ctrl;
  FCC_Ctrl_Bus FCC_Ctrl;
  COM_Ctrl_Bus COM_Ctrl;
  boolean_T realtime;
  boolean_T external;
  uint16_T heartbeat;
} Simulation_Ctrl_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Guidance_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Guidance_Cmd_Bus_

typedef struct {
  real_T tbd;
} Guidance_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Controller_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Controller_Cmd_Bus_

typedef struct {
  real_T acc_y_mDs2;
  real_T acc_z_mDs2;
  real_T phi_rad;
} Controller_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ATT_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_ATT_Cmd_Bus_

typedef struct {
  real_T Phi_Cmd_rad;
  real_T Theta_Cmd_rad;
  real_T Psi_Cmd_rad;
} ATT_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Surface_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Surface_Cmd_Bus_

typedef struct {
  real_T Fin_1_Cmd_rad;
  real_T Fin_2_Cmd_rad;
  real_T Fin_3_Cmd_rad;
  real_T Fin_4_Cmd_rad;
} Control_Surface_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PWM_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_PWM_Cmd_Bus_

typedef struct {
  real_T pulse_width_ms;
  real_T periode_ms;
  real_T voltage_level_V;
} PWM_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Servo_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Servo_Cmd_Bus_

typedef struct {
  PWM_Cmd_Bus Servo_1_Cmd_PWM;
  PWM_Cmd_Bus Servo_2_Cmd_PWM;
  PWM_Cmd_Bus Servo_3_Cmd_PWM;
  PWM_Cmd_Bus Servo_4_Cmd_PWM;
} Servo_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Airframe_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Airframe_Cmd_Bus_

typedef struct {
  Guidance_Cmd_Bus Guidance_Cmd;
  Controller_Cmd_Bus Controller_Cmd;
  ATT_Cmd_Bus ATT_Cmd;
  Control_Surface_Cmd_Bus Control_Surface_Cmd;
  Servo_Cmd_Bus Servo_Cmd;
} Airframe_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCC_Commands_Bus_
#define DEFINED_TYPEDEF_FOR_FCC_Commands_Bus_

typedef struct {
  Airframe_Cmd_Bus Airframe_Cmd;
} FCC_Commands_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Surface_Deflections_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Surface_Deflections_Bus_

typedef struct {
  real_T Fin_1_Pos_rad;
  real_T Fin_2_Pos_rad;
  real_T Fin_3_Pos_rad;
  real_T Fin_4_Pos_rad;
} Control_Surface_Deflections_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Inc_Encoder_Signal_Bus_
#define DEFINED_TYPEDEF_FOR_Inc_Encoder_Signal_Bus_

typedef struct {
  real_T A;
  real_T B;
  real_T Z;
} Inc_Encoder_Signal_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Surface_Encoder_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Surface_Encoder_Bus_

typedef struct {
  Inc_Encoder_Signal_Bus Fin_1_Encoder;
  Inc_Encoder_Signal_Bus Fin_2_Encoder;
  Inc_Encoder_Signal_Bus Fin_3_Encoder;
  Inc_Encoder_Signal_Bus Fin_4_Encoder;
} Control_Surface_Encoder_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Surface_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Surface_Bus_

typedef struct {
  Control_Surface_Deflections_Bus Control_Surface_Deflections;
  Control_Surface_Encoder_Bus Control_Surface_Encoder;
} Control_Surface_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Servo_Positions_Bus_
#define DEFINED_TYPEDEF_FOR_Servo_Positions_Bus_

typedef struct {
  real_T Servo_1_Pos_rad;
  real_T Servo_2_Pos_rad;
  real_T Servo_3_Pos_rad;
  real_T Servo_4_Pos_rad;
} Servo_Positions_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Servo_State_Bus_
#define DEFINED_TYPEDEF_FOR_Servo_State_Bus_

typedef struct {
  Servo_Positions_Bus Servo_Positions;
} Servo_State_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Disturbances_Bus_
#define DEFINED_TYPEDEF_FOR_Disturbances_Bus_

typedef struct {
  real_T Disturbance_Force_N[3];
  real_T Disturbance_Moment_Nm[3];
} Disturbances_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FDM_External_Inputs_Bus_
#define DEFINED_TYPEDEF_FOR_FDM_External_Inputs_Bus_

typedef struct {
  boolean_T Motor_Ignition_flg;
} FDM_External_Inputs_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCC_External_Inputs_Bus_
#define DEFINED_TYPEDEF_FOR_FCC_External_Inputs_Bus_

typedef struct {
  boolean_T Flight_Termination_flg;
  real_T CMD_phi_rad;
  real_T CMD_acc_z_mDs2;
  real_T CMD_acc_y_mDs2;
} FCC_External_Inputs_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_External_Inputs_Bus_
#define DEFINED_TYPEDEF_FOR_External_Inputs_Bus_

typedef struct {
  FDM_External_Inputs_Bus FDM_External_Inputs;
  FCC_External_Inputs_Bus FCC_External_Inputs;
} External_Inputs_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Translation_States_Bus_
#define DEFINED_TYPEDEF_FOR_Translation_States_Bus_

typedef struct {
  real_T VEL_u_K_R_E_B_mDs;
  real_T VEL_v_K_R_E_B_mDs;
  real_T VEL_w_K_R_E_B_mDs;
} Translation_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Translation_States_Dot_Bus_
#define DEFINED_TYPEDEF_FOR_Translation_States_Dot_Bus_

typedef struct {
  real_T ACC_x_B_mDs2;
  real_T ACC_y_B_mDs2;
  real_T ACC_z_B_mDs2;
} Translation_States_Dot_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rotation_States_Bus_
#define DEFINED_TYPEDEF_FOR_Rotation_States_Bus_

typedef struct {
  real_T w_x_K_IB_B_radDs;
  real_T w_y_K_IB_B_radDs;
  real_T w_z_K_IB_B_radDs;
} Rotation_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ATT_Euler_Bus_
#define DEFINED_TYPEDEF_FOR_ATT_Euler_Bus_

typedef struct {
  real_T ATT_Phi_rad;
  real_T ATT_Theta_rad;
  real_T ATT_Psi_rad;
} ATT_Euler_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ATT_Quaternions_Bus_
#define DEFINED_TYPEDEF_FOR_ATT_Quaternions_Bus_

typedef struct {
  real_T ATT_q_0;
  real_T ATT_q_1;
  real_T ATT_q_2;
  real_T ATT_q_3;
} ATT_Quaternions_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Attitude_States_Bus_
#define DEFINED_TYPEDEF_FOR_Attitude_States_Bus_

typedef struct {
  ATT_Euler_Bus ATT_Euler;
  ATT_Quaternions_Bus ATT_Quaternions;
} Attitude_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_POS_WGS84_Bus_
#define DEFINED_TYPEDEF_FOR_POS_WGS84_Bus_

typedef struct {
  real_T POS_lambda_WGS84_rad;
  real_T POS_mue_WGS84_rad;
  real_T POS_h_WGS84_m;
} POS_WGS84_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_POS_NED_Bus_
#define DEFINED_TYPEDEF_FOR_POS_NED_Bus_

typedef struct {
  real_T POS_x_NED_m;
  real_T POS_y_NED_m;
  real_T POS_z_NED_m;
} POS_NED_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Position_States_Bus_
#define DEFINED_TYPEDEF_FOR_Position_States_Bus_

typedef struct {
  POS_WGS84_Bus POS_WGS84;
  POS_NED_Bus POS_NED;
} Position_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rigid_Body_States_Bus_
#define DEFINED_TYPEDEF_FOR_Rigid_Body_States_Bus_

typedef struct {
  Translation_States_Bus Translation_States;
  Translation_States_Dot_Bus Acceleration_States;
  Rotation_States_Bus Rotation_States;
  Attitude_States_Bus Attitude_States;
  Position_States_Bus Position_States;
} Rigid_Body_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Airframe_States_Bus_
#define DEFINED_TYPEDEF_FOR_Airframe_States_Bus_

typedef struct {
  real_T motor_state_perc;
  real_T mass_kg;
} Airframe_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Atm_States_Bus_
#define DEFINED_TYPEDEF_FOR_Atm_States_Bus_

typedef struct {
  real_T VEL_u_Wind_A_E_O_mDs;
  real_T VEL_v_Wind_A_E_O_mDs;
  real_T VEL_w_Wind_A_E_O_mDs;
} Atm_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_States_Bus_
#define DEFINED_TYPEDEF_FOR_States_Bus_

typedef struct {
  Rigid_Body_States_Bus Rigid_Body_States;
  Airframe_States_Bus Airframe_States;
  Atm_States_Bus Atm_States;
} States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_Status_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_Status_Bus_

typedef struct {
  real_T Gimbal_operational_flg;
  real_T Gimbal_Ramp_flg;
  real_T Gimbal_Limit_flg;
  real_T Gimbal_StopSim_flg;
} Gimbal_Status_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_Attitude_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_Attitude_Bus_

typedef struct {
  ATT_Euler_Bus ATT_Euler;
  ATT_Quaternions_Bus ATT_Quaternions;
} Gimbal_Attitude_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Encoder_Resolved_Bus_
#define DEFINED_TYPEDEF_FOR_Encoder_Resolved_Bus_

typedef struct {
  real_T Gimbal_yaw_sns;
  real_T Gimbal_pitch_sns;
  real_T Gimbal_roll_sns;
} Encoder_Resolved_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Encoder_Signal_Bus_
#define DEFINED_TYPEDEF_FOR_Encoder_Signal_Bus_

typedef struct {
  real_T Data_plus;
  real_T Data_minus;
  real_T Clock_plus;
  real_T Clock_minus;
} Encoder_Signal_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_Encoder_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_Encoder_Bus_

typedef struct {
  Encoder_Resolved_Bus ATT_Gimbal;
  Encoder_Signal_Bus Pos_Yaw_Encoder;
  Encoder_Signal_Bus Pos_Pitch_Encoder;
  Encoder_Signal_Bus Pos_Roll_Encoder;
} Gimbal_Encoder_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_State_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_State_Bus_

typedef struct {
  Gimbal_Status_Bus Gimbal_Status;
  Gimbal_Attitude_Bus Gimbal_Attitude;
  Gimbal_Encoder_Bus Gimbal_Encoder_Signals;
} Gimbal_State_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_Cmd_Bus_

typedef struct {
  real_T Gimbal_Phi_Cmd_deg;
  real_T Gimbal_Theta_Cmd_deg;
  real_T Gimbal_Psi_Cmd_deg;
} Gimbal_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_Ctrl_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_Ctrl_Bus_

typedef struct {
  real_T enable_gimbal_ctrl_flg;
  real_T stop_gimbal_flg;
  real_T Gimbal_Phi2Motor;
  real_T Gimbal_Theta2Motor;
  real_T Gimbal_Psi2Motor;
} Gimbal_Ctrl_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gimbal_Monitor_Bus_
#define DEFINED_TYPEDEF_FOR_Gimbal_Monitor_Bus_

typedef struct {
  boolean_T cmd_pass_enable_flg;
  boolean_T emergency_stop_flg;
} Gimbal_Monitor_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_fqhbejXln8QRylaPqhUyTF_
#define DEFINED_TYPEDEF_FOR_struct_fqhbejXln8QRylaPqhUyTF_

typedef struct {
  real_T Servo1_Numerator_Coefs;
  real_T Servo1_Denominator_Coefs[3];
  real_T Servo2_Numerator_Coefs;
  real_T Servo2_Denominator_Coefs[3];
  real_T Servo3_Numerator_Coefs;
  real_T Servo3_Denominator_Coefs[3];
  real_T Servo4_Numerator_Coefs;
  real_T Servo4_Denominator_Coefs[3];
} struct_fqhbejXln8QRylaPqhUyTF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_7SrGNOW0Gr039ZOMvXVVTD_
#define DEFINED_TYPEDEF_FOR_struct_7SrGNOW0Gr039ZOMvXVVTD_

typedef struct {
  real_T Update_rate_Hz;
  real_T periode_ms;
  real_T Pulswidth_cmd_middle_pos_ms;
  real_T Pulswidth_cmd_max_ms;
  real_T Pulswidth_cmd_min_ms;
  real_T Voltage_level_V;
  real_T max_deflection_rad;
} struct_7SrGNOW0Gr039ZOMvXVVTD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JmsfHiggjss7x7dzfcXt9F_
#define DEFINED_TYPEDEF_FOR_struct_JmsfHiggjss7x7dzfcXt9F_

typedef struct {
  real_T Motor_Ignition_time_s;
} struct_JmsfHiggjss7x7dzfcXt9F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BTftwrJbWeM670O1XPTZ1C_
#define DEFINED_TYPEDEF_FOR_struct_BTftwrJbWeM670O1XPTZ1C_

typedef struct {
  real_T phi_rad;
} struct_BTftwrJbWeM670O1XPTZ1C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_E9xfJrDS8wEcyfYN6eOlYG_
#define DEFINED_TYPEDEF_FOR_struct_E9xfJrDS8wEcyfYN6eOlYG_

typedef struct {
  real_T alternating_flg;
  real_T ampl_rad;
  real_T period_s;
  real_T pulse_width_perc;
  real_T delay_s;
} struct_E9xfJrDS8wEcyfYN6eOlYG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_78MT3wT9fhi8ylbZWwPhqH_
#define DEFINED_TYPEDEF_FOR_struct_78MT3wT9fhi8ylbZWwPhqH_

typedef struct {
  real_T pulse_cmd_flg;
  struct_BTftwrJbWeM670O1XPTZ1C constant;
  struct_E9xfJrDS8wEcyfYN6eOlYG pulse;
} struct_78MT3wT9fhi8ylbZWwPhqH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZjOGsVCdaOvRjDkE3POHEH_
#define DEFINED_TYPEDEF_FOR_struct_ZjOGsVCdaOvRjDkE3POHEH_

typedef struct {
  real_T acc_z_mDs2;
} struct_ZjOGsVCdaOvRjDkE3POHEH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Dnn86pR2ImcbhyRO1T2RoG_
#define DEFINED_TYPEDEF_FOR_struct_Dnn86pR2ImcbhyRO1T2RoG_

typedef struct {
  real_T alternating_flg;
  real_T ampl_mDs2;
  real_T period_s;
  real_T pulse_width_perc;
  real_T delay_s;
} struct_Dnn86pR2ImcbhyRO1T2RoG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_sxk43YQUkK2Dy1nZBRwOqG_
#define DEFINED_TYPEDEF_FOR_struct_sxk43YQUkK2Dy1nZBRwOqG_

typedef struct {
  real_T pulse_cmd_flg;
  struct_ZjOGsVCdaOvRjDkE3POHEH constant;
  struct_Dnn86pR2ImcbhyRO1T2RoG pulse;
} struct_sxk43YQUkK2Dy1nZBRwOqG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DDaxnFjCqgRTmNKEA8BdXD_
#define DEFINED_TYPEDEF_FOR_struct_DDaxnFjCqgRTmNKEA8BdXD_

typedef struct {
  real_T acc_y_mDs2;
} struct_DDaxnFjCqgRTmNKEA8BdXD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_aIthSv6eARLciQWCxnpfcH_
#define DEFINED_TYPEDEF_FOR_struct_aIthSv6eARLciQWCxnpfcH_

typedef struct {
  real_T pulse_cmd_flg;
  struct_DDaxnFjCqgRTmNKEA8BdXD constant;
  struct_Dnn86pR2ImcbhyRO1T2RoG pulse;
} struct_aIthSv6eARLciQWCxnpfcH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_IESddi9utHoLtu4Ib32CTE_
#define DEFINED_TYPEDEF_FOR_struct_IESddi9utHoLtu4Ib32CTE_

typedef struct {
  struct_78MT3wT9fhi8ylbZWwPhqH roll;
  struct_sxk43YQUkK2Dy1nZBRwOqG pitch;
  struct_aIthSv6eARLciQWCxnpfcH yaw;
} struct_IESddi9utHoLtu4Ib32CTE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_7WkwfrLVv4fBDn3BNGhavG_
#define DEFINED_TYPEDEF_FOR_struct_7WkwfrLVv4fBDn3BNGhavG_

typedef struct {
  real_T Flight_Termination_flg;
  struct_IESddi9utHoLtu4Ib32CTE CMD;
} struct_7WkwfrLVv4fBDn3BNGhavG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Y7PS1rxhiw1TKkxrPVqWqG_
#define DEFINED_TYPEDEF_FOR_struct_Y7PS1rxhiw1TKkxrPVqWqG_

typedef struct {
  struct_JmsfHiggjss7x7dzfcXt9F FDM;
  struct_7WkwfrLVv4fBDn3BNGhavG FCC;
} struct_Y7PS1rxhiw1TKkxrPVqWqG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_skgRGNdg4uikkiJBtrraoB_
#define DEFINED_TYPEDEF_FOR_struct_skgRGNdg4uikkiJBtrraoB_

typedef struct {
  real_T phi_f1_rad;
  real_T phi_f2_rad;
  real_T phi_f3_rad;
  real_T phi_f4_rad;
  real_T max_deflection_rad;
} struct_skgRGNdg4uikkiJBtrraoB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_QhvhhqDV0L2yxKLWicNneD_
#define DEFINED_TYPEDEF_FOR_struct_QhvhhqDV0L2yxKLWicNneD_

typedef struct {
  real_T Num[2];
  real_T Denom[2];
} struct_QhvhhqDV0L2yxKLWicNneD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NXU1FRSfNm9MZqPmiPj5nG_
#define DEFINED_TYPEDEF_FOR_struct_NXU1FRSfNm9MZqPmiPj5nG_

typedef struct {
  real_T PreGain;
  real_T Gain;
  struct_QhvhhqDV0L2yxKLWicNneD Lead;
} struct_NXU1FRSfNm9MZqPmiPj5nG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NKNq6gj8dL8ticSV3dO1LF_
#define DEFINED_TYPEDEF_FOR_struct_NKNq6gj8dL8ticSV3dO1LF_

typedef struct {
  real_T PropGain;
} struct_NKNq6gj8dL8ticSV3dO1LF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6DMhF3HgatZ0SVFTbVEXUB_
#define DEFINED_TYPEDEF_FOR_struct_6DMhF3HgatZ0SVFTbVEXUB_

typedef struct {
  real_T Num;
  real_T Denom[2];
} struct_6DMhF3HgatZ0SVFTbVEXUB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_0bCECObDp9cpwUujjacDoB_
#define DEFINED_TYPEDEF_FOR_struct_0bCECObDp9cpwUujjacDoB_

typedef struct {
  real_T PropGain;
  struct_6DMhF3HgatZ0SVFTbVEXUB IntGain;
} struct_0bCECObDp9cpwUujjacDoB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mvMpa6roJ3cC08QEKeHpUD_
#define DEFINED_TYPEDEF_FOR_struct_mvMpa6roJ3cC08QEKeHpUD_

typedef struct {
  struct_NKNq6gj8dL8ticSV3dO1LF innerLoop;
  struct_0bCECObDp9cpwUujjacDoB outerLoop;
} struct_mvMpa6roJ3cC08QEKeHpUD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SpfmErt2JG4vKmjTJRH6OB_
#define DEFINED_TYPEDEF_FOR_struct_SpfmErt2JG4vKmjTJRH6OB_

typedef struct {
  struct_NXU1FRSfNm9MZqPmiPj5nG Roll;
  struct_mvMpa6roJ3cC08QEKeHpUD Pitch;
  struct_mvMpa6roJ3cC08QEKeHpUD Yaw;
} struct_SpfmErt2JG4vKmjTJRH6OB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_RIcaXENoLMkyG3vAzx3LrF_
#define DEFINED_TYPEDEF_FOR_struct_RIcaXENoLMkyG3vAzx3LrF_

typedef struct {
  real_T SampTime;
  real_T MaxMissTick;
} struct_RIcaXENoLMkyG3vAzx3LrF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_t5lid3aqguggysQaotuOhC_
#define DEFINED_TYPEDEF_FOR_struct_t5lid3aqguggysQaotuOhC_

typedef struct {
  real_T SampFreq;
  real_T SampTime;
  real_T MaxMissTick;
  real_T MaxCheck;
  real_T YawMaxV;
  real_T PitchMaxV;
  real_T RollMaxV;
  real_T Enable_Voltage_Limits_atOutput;
  real_T Enable_Voltage_Limits_atController;
  real_T YawCmdMaxVolt;
  real_T YawCmdMinVolt;
  real_T PitchCmdMaxVolt;
  real_T PitchCmdMinVolt;
  real_T RollCmdMaxVolt;
  real_T RollCmdMinVolt;
  real_T Yaw_soft_limit_vel;
  real_T Yaw_hard_limit_vel;
  real_T Yaw_limit_adaption_coef;
  real_T Pitch_soft_limit_vel;
  real_T Pitch_hard_limit_vel;
  real_T Pitch_limit_adaption_coef;
  real_T Roll_soft_limit_vel;
  real_T Roll_hard_limit_vel;
  real_T Roll_limit_adaption_coef;
  real_T PID_Yaw_Proportional_Gain;
  real_T PID_Yaw_Integral_Gain;
  real_T PID_Yaw_Derivative_Gain;
  real_T PID_Yaw_Filter_Coefficient;
  real_T PID_Yaw_BackCalculation_Coefficient;
  real_T PID_Pitch_Proportional_Gain;
  real_T PID_Pitch_Integral_Gain;
  real_T PID_Pitch_Derivative_Gain;
  real_T PID_Pitch_Filter_Coefficient;
  real_T PID_Pitch_BackCalculation_Coefficient;
  real_T PID_Roll_Proportional_Gain;
  real_T PID_Roll_Integral_Gain;
  real_T PID_Roll_Derivative_Gain;
  real_T PID_Roll_Filter_Coefficient;
  real_T PID_Roll_BackCalculation_Coefficient;
  real_T Enable_Limit_Controllers;
  real_T Yaw_LC_Proportional_Gain;
  real_T Yaw_LC_Integral_Gain;
  real_T Yaw_LC_Derivative_Gain;
  real_T Yaw_LC_Weighting;
  real_T Pitch_LC_Proportional_Gain;
  real_T Pitch_LC_Integral_Gain;
  real_T Pitch_LC_Derivative_Gain;
  real_T Pitch_LC_Weighting;
  real_T Roll_LC_Proportional_Gain;
  real_T Roll_LC_Integral_Gain;
  real_T Roll_LC_Derivative_Gain;
  real_T Roll_LC_Weighting;
} struct_t5lid3aqguggysQaotuOhC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mYoNNcm8zkJZX9FXsF2g2F_
#define DEFINED_TYPEDEF_FOR_struct_mYoNNcm8zkJZX9FXsF2g2F_

typedef struct {
  real_T POS_lambda_WGS84_rad;
  real_T POS_mue_WGS84_rad;
  real_T POS_h_WGS84_m;
  real_T POS_x_NED_m;
  real_T POS_y_NED_m;
  real_T POS_z_NED_m;
} struct_mYoNNcm8zkJZX9FXsF2g2F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_FhGLidBATzAyVEgGPUcCPB_
#define DEFINED_TYPEDEF_FOR_struct_FhGLidBATzAyVEgGPUcCPB_

typedef struct {
  Translation_States_Bus Transl;
  Translation_States_Dot_Bus Transl_Dot;
  Rotation_States_Bus Rot;
  ATT_Euler_Bus Att;
  struct_mYoNNcm8zkJZX9FXsF2g2F Pos;
} struct_FhGLidBATzAyVEgGPUcCPB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ox3hNlE5f9EVkxBowKM3IG_
#define DEFINED_TYPEDEF_FOR_struct_ox3hNlE5f9EVkxBowKM3IG_

typedef struct {
  real_T range;
} struct_ox3hNlE5f9EVkxBowKM3IG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8dn0WBFJAEipy0bhP7ue2G_
#define DEFINED_TYPEDEF_FOR_struct_8dn0WBFJAEipy0bhP7ue2G_

typedef struct {
  Translation_States_Bus Translation_States;
  Translation_States_Dot_Bus Translation_States_Dot;
  Rotation_States_Bus Rotation_States;
  Attitude_States_Bus Attitude_States;
  Position_States_Bus Position_States;
} struct_8dn0WBFJAEipy0bhP7ue2G;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4BEF1wwN52Uf7px5A1b9LF_
#define DEFINED_TYPEDEF_FOR_struct_4BEF1wwN52Uf7px5A1b9LF_

typedef struct {
  struct_8dn0WBFJAEipy0bhP7ue2G Rigid_Body_States;
  Airframe_States_Bus Airframe_States;
  Atm_States_Bus Atm_States;
} struct_4BEF1wwN52Uf7px5A1b9LF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mYS1N2caX135AIcTArxUzD_
#define DEFINED_TYPEDEF_FOR_struct_mYS1N2caX135AIcTArxUzD_

typedef struct {
  ATT_Euler_Bus ATT_Euler_Bus;
  ATT_Quaternions_Bus ATT_Quaternions_Bus;
} struct_mYS1N2caX135AIcTArxUzD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_VkUZsEuPLDWiHwBdN4zERD_
#define DEFINED_TYPEDEF_FOR_struct_VkUZsEuPLDWiHwBdN4zERD_

typedef struct {
  Encoder_Resolved_Bus Encoder_Resolved;
  Encoder_Signal_Bus Pos_Yaw_Encoder;
  Encoder_Signal_Bus Pos_Pitch_Encoder;
  Encoder_Signal_Bus Pos_Roll_Encoder;
} struct_VkUZsEuPLDWiHwBdN4zERD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_naMSiPeANZdxK1BVj547qE_
#define DEFINED_TYPEDEF_FOR_struct_naMSiPeANZdxK1BVj547qE_

typedef struct {
  Gimbal_Status_Bus Gimbal_Status_Bus;
  struct_mYS1N2caX135AIcTArxUzD Gimbal_Attitude_Bus;
  struct_VkUZsEuPLDWiHwBdN4zERD Gimbal_Encoder_Bus;
} struct_naMSiPeANZdxK1BVj547qE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lQamzfSfua9vI4k5KcpdyB_
#define DEFINED_TYPEDEF_FOR_struct_lQamzfSfua9vI4k5KcpdyB_

typedef struct {
  FDM_External_Inputs_Bus FDM_External_Inputs_Bus;
  FCC_External_Inputs_Bus FCC_External_Inputs_Bus;
} struct_lQamzfSfua9vI4k5KcpdyB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_biIcle9l5pPUJAEhBiubME_
#define DEFINED_TYPEDEF_FOR_struct_biIcle9l5pPUJAEhBiubME_

typedef struct {
  real_T signal1;
} struct_biIcle9l5pPUJAEhBiubME;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_HOsjcyeSDQ7kNiQxBq2HXH_
#define DEFINED_TYPEDEF_FOR_struct_HOsjcyeSDQ7kNiQxBq2HXH_

typedef struct {
  struct_biIcle9l5pPUJAEhBiubME Guidance_Cmd;
  Controller_Cmd_Bus Controller_Cmd;
  ATT_Cmd_Bus ATT_Cmd;
  Control_Surface_Cmd_Bus Control_Surface_Cmd;
  Servo_Cmd_Bus Servo_Cmd;
} struct_HOsjcyeSDQ7kNiQxBq2HXH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_F8un5srqOha4P4SBfdUeHD_
#define DEFINED_TYPEDEF_FOR_struct_F8un5srqOha4P4SBfdUeHD_

typedef struct {
  struct_HOsjcyeSDQ7kNiQxBq2HXH Airframe_Cmd;
} struct_F8un5srqOha4P4SBfdUeHD;

#endif

/* Parameters for system: '<S174>/If Action Subsystem1' */
typedef struct P_IfActionSubsystem1_GRM_HIL_T_ P_IfActionSubsystem1_GRM_HIL_T;

/* Parameters for system: '<S174>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_GRM_HIL_T_ P_IfActionSubsystem_GRM_HIL_T;

/* Parameters (default storage) */
typedef struct P_GRM_HIL_T_ P_GRM_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_GRM_HIL_T RT_MODEL_GRM_HIL_T;

#endif                                 /* RTW_HEADER_GRM_HIL_types_h_ */

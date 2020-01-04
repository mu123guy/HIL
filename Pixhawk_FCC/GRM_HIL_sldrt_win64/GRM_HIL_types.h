/*
 * GRM_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.88
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Jan  3 00:07:39 2020
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

#ifndef DEFINED_TYPEDEF_FOR_Rotation_States_Dot_Bus_
#define DEFINED_TYPEDEF_FOR_Rotation_States_Dot_Bus_

typedef struct {
  real_T w_x_dot_radDs2;
  real_T w_y_dot_radDs2;
  real_T w_z_dot_radDs2;
} Rotation_States_Dot_Bus;

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
  Translation_States_Dot_Bus Translation_States_Dot;
  Rotation_States_Bus Rotation_States;
  Rotation_States_Dot_Bus Rotation_States_Dot;
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

#ifndef DEFINED_TYPEDEF_FOR_struct_fPSpQec4CK6Ld2LdBMMAbH_
#define DEFINED_TYPEDEF_FOR_struct_fPSpQec4CK6Ld2LdBMMAbH_

typedef struct {
  real_T MaxMissedTicks;
} struct_fPSpQec4CK6Ld2LdBMMAbH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_o6lBeR5a4wCQZKjH0CEd8D_
#define DEFINED_TYPEDEF_FOR_struct_o6lBeR5a4wCQZKjH0CEd8D_

typedef struct {
  real_T param1;
  struct_fPSpQec4CK6Ld2LdBMMAbH Send;
  struct_fPSpQec4CK6Ld2LdBMMAbH Receive;
} struct_o6lBeR5a4wCQZKjH0CEd8D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_2rU9DLCenxPBMI086Phyx_
#define DEFINED_TYPEDEF_FOR_struct_2rU9DLCenxPBMI086Phyx_

typedef struct {
  real_T Num_Coef[2];
  real_T Denom_Coef[3];
} struct_2rU9DLCenxPBMI086Phyx;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_u9tuPjUAEO3XkpAUDGTraG_
#define DEFINED_TYPEDEF_FOR_struct_u9tuPjUAEO3XkpAUDGTraG_

typedef struct {
  real_T Num_Coef;
  real_T Denom_Coef;
} struct_u9tuPjUAEO3XkpAUDGTraG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_3GFOl0CrpEtPiCeQKu5bZE_
#define DEFINED_TYPEDEF_FOR_struct_3GFOl0CrpEtPiCeQKu5bZE_

typedef struct {
  real_T Num_Coef[5];
  real_T Denom_Coef[6];
} struct_3GFOl0CrpEtPiCeQKu5bZE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_1jtd4lthR1rS618lzimrEB_
#define DEFINED_TYPEDEF_FOR_struct_1jtd4lthR1rS618lzimrEB_

typedef struct {
  real_T Num_Coef[3];
  real_T Denom_Coef[4];
} struct_1jtd4lthR1rS618lzimrEB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_X0z48mq1MJmnXMBjrHYvYC_
#define DEFINED_TYPEDEF_FOR_struct_X0z48mq1MJmnXMBjrHYvYC_

typedef struct {
  struct_2rU9DLCenxPBMI086Phyx Psi2Motor_to_Yaw;
  struct_u9tuPjUAEO3XkpAUDGTraG Theta2Motor_to_Yaw;
  struct_u9tuPjUAEO3XkpAUDGTraG Phi2Motor_to_Yaw;
  struct_u9tuPjUAEO3XkpAUDGTraG Psi2Motor_to_Pitch;
  struct_3GFOl0CrpEtPiCeQKu5bZE Theta2Motor_to_Pitch;
  struct_u9tuPjUAEO3XkpAUDGTraG Phi2Motor_to_Pitch;
  struct_u9tuPjUAEO3XkpAUDGTraG Psi2Motor_to_Roll;
  struct_u9tuPjUAEO3XkpAUDGTraG Theta2Motor_to_Roll;
  struct_1jtd4lthR1rS618lzimrEB Phi2Motor_to_Roll;
} struct_X0z48mq1MJmnXMBjrHYvYC;

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

#ifndef struct_emxArray_uint8_T_1x64
#define struct_emxArray_uint8_T_1x64

struct emxArray_uint8_T_1x64
{
  uint8_T data[64];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_uint8_T_1x64*/

#ifndef typedef_emxArray_uint8_T_1x64_GRM_HIL_T
#define typedef_emxArray_uint8_T_1x64_GRM_HIL_T

typedef struct emxArray_uint8_T_1x64 emxArray_uint8_T_1x64_GRM_HIL_T;

#endif                               /*typedef_emxArray_uint8_T_1x64_GRM_HIL_T*/

/* Parameters for system: '<S173>/If Action Subsystem1' */
typedef struct P_IfActionSubsystem1_GRM_HIL_T_ P_IfActionSubsystem1_GRM_HIL_T;

/* Parameters for system: '<S173>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_GRM_HIL_T_ P_IfActionSubsystem_GRM_HIL_T;

/* Parameters (default storage) */
typedef struct P_GRM_HIL_T_ P_GRM_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_GRM_HIL_T RT_MODEL_GRM_HIL_T;

#endif                                 /* RTW_HEADER_GRM_HIL_types_h_ */

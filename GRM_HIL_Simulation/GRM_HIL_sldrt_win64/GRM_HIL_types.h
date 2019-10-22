/*
 * GRM_HIL_types.h
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

#ifndef DEFINED_TYPEDEF_FOR_struct_ox3hNlE5f9EVkxBowKM3IG_
#define DEFINED_TYPEDEF_FOR_struct_ox3hNlE5f9EVkxBowKM3IG_

typedef struct {
  real_T range;
} struct_ox3hNlE5f9EVkxBowKM3IG;

#endif

/* Parameters (default storage) */
typedef struct P_GRM_HIL_T_ P_GRM_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_GRM_HIL_T RT_MODEL_GRM_HIL_T;

#endif                                 /* RTW_HEADER_GRM_HIL_types_h_ */

/*
 * GRM_HIL_data.c
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

#include "GRM_HIL.h"
#include "GRM_HIL_private.h"

/* Block parameters (default storage) */
P_GRM_HIL_T GRM_HIL_P = {
  /* Variable: HIL_Sample_Time
   * Referenced by: '<S18>/Constant'
   */
  0.01,

  /* Mask Parameter: FDM_Linear_FDM
   * Referenced by:
   *   '<S201>/Constant1'
   *   '<S216>/Constant'
   *   '<S216>/Constant1'
   *   '<S209>/Constant'
   *   '<S210>/Constant'
   *   '<S210>/Constant1'
   */
  {
    {
      -1.0,

      {
        1000.0,
        80.0,
        0.15,
        1.225,
        49.0
      },

      {
        {
          3.9123,

          { 0.0065, 0.0147 }
        },

        {
          { 96.0992, 148.7807 },

          { 1.0, 3.2255, 166.199 }
        },

        {
          { 96.0992, 148.7807 },

          { 1.0, 3.2255, 166.199 }
        },

        {
          { 26.5678, 29.5185, -11902.0 },

          { 1.0, 3.2255, 166.199 }
        },

        {
          { 26.5678, 29.5185, -11902.0 },

          { 1.0, 3.2255, 166.199 }
        },

        {
          { -26.5678, -29.5185, -11902.0 },

          { 1.0, 3.2255, 166.199 }
        },

        {
          { -26.5678, -29.5185, -11902.0 },

          { 1.0, 3.2255, 166.199 }
        }
      }
    },

    {
      1.0
    },

    {
      0.09,
      0.0064,
      0.05,
      4.171,
      4.19,
      0.0037,
      0.4319,
      0.4319,
      0.0042,
      0.4319,
      0.4319,

      {
        3.5,
        455.0
      }
    },

    {
      3.9123,
      -18.384,
      -28.2919,
      4.4436,
      -31.5283,
      18.4916,
      -380.077,
      -28.2919,
      -4.4436,
      -31.5283,
      18.4916,
      -380.077
    },

    {
      9.81
    }
  },

  /* Mask Parameter: Gimbel_Ctrl_Gimbal_Ctrl
   * Referenced by:
   *   '<S45>/Constant2'
   *   '<S45>/Samp_Freq'
   *   '<S52>/max_vel_pitch'
   *   '<S52>/max_vel_roll'
   *   '<S52>/max_vel_yaw'
   *   '<S53>/Constant'
   *   '<S53>/const_lower_limit'
   *   '<S53>/const_upper_limit'
   *   '<S54>/Derivative Gain'
   *   '<S54>/Filter Coefficient'
   *   '<S54>/Integral Gain'
   *   '<S54>/Kb'
   *   '<S54>/Proportional Gain'
   *   '<S62>/Constant'
   *   '<S62>/const_lower_limit'
   *   '<S62>/const_upper_limit'
   *   '<S63>/Derivative Gain'
   *   '<S63>/Filter Coefficient'
   *   '<S63>/Integral Gain'
   *   '<S63>/Kb'
   *   '<S63>/Proportional Gain'
   *   '<S71>/Constant'
   *   '<S72>/Constant'
   *   '<S72>/const_lower_limit'
   *   '<S72>/const_upper_limit'
   *   '<S73>/Derivative Gain'
   *   '<S73>/Filter Coefficient'
   *   '<S73>/Integral Gain'
   *   '<S73>/Kb'
   *   '<S73>/Proportional Gain'
   *   '<S174>/Constant1'
   *   '<S174>/Gain'
   *   '<S174>/Transport Delay'
   *   '<S175>/Constant1'
   *   '<S175>/Gain'
   *   '<S175>/Transport Delay'
   *   '<S176>/Constant1'
   *   '<S176>/Gain'
   *   '<S176>/Transport Delay'
   *   '<S183>/Limit_Voltage_Pitch'
   *   '<S184>/Limit_Voltage_Roll'
   *   '<S185>/Limit_Voltage_Yaw'
   *   '<S55>/Constant'
   *   '<S56>/Constant'
   *   '<S57>/Constant'
   *   '<S57>/Constant1'
   *   '<S57>/Gain'
   *   '<S64>/Constant'
   *   '<S65>/Constant'
   *   '<S66>/Constant'
   *   '<S66>/Constant1'
   *   '<S66>/Gain'
   *   '<S74>/Constant1'
   *   '<S74>/Constant2'
   *   '<S74>/Gain'
   *   '<S74>/Gain1'
   *   '<S166>/Constant'
   *   '<S167>/Constant'
   *   '<S168>/Constant'
   *   '<S168>/Constant1'
   *   '<S168>/Gain'
   *   '<S101>/Derivative Gain'
   *   '<S104>/Integral Gain'
   *   '<S112>/Proportional Gain'
   *   '<S145>/Derivative Gain'
   *   '<S148>/Integral Gain'
   *   '<S156>/Proportional Gain'
   */
  {
    1000.0,
    0.001,
    10.0,
    0.005,
    100.0,
    150.0,
    480.0,
    0.0,
    0.0,
    0.8,
    -0.8,
    1.0,
    -0.2,
    1.1,
    1.1,
    50.0,
    90.0,
    10.0,
    75.0,
    135.0,
    10.0,
    240.0,
    432.0,
    10.0,
    3.0,
    0.1,
    0.4,
    100.0,
    0.2,
    20.0,
    0.0,
    0.4,
    100.0,
    0.0,
    8.0,
    0.2,
    0.35,
    100.0,
    0.264575131106459,
    0.0,
    3.0,
    0.0,
    0.4,
    1.0,
    20.0,
    0.0,
    0.4,
    1.0,
    8.0,
    0.0,
    0.4,
    1.0
  },

  /* Mask Parameter: FDM_Linear_TF
   * Referenced by:
   *   '<S197>/dp2az'
   *   '<S197>/dp2pitch'
   *   '<S197>/dr2roll'
   *   '<S197>/dy2ay'
   *   '<S197>/dy2yaw'
   */
  {
    {
      3.9123,

      { 0.0065, 0.0147 }
    },

    {
      { 96.0992, 148.7807 },

      { 1.0, 3.2255, 166.199 }
    },

    {
      { 96.0992, 148.7807 },

      { 1.0, 3.2255, 166.199 }
    },

    {
      { 26.5678, 29.5185, -11902.0 },

      { 1.0, 3.2255, 166.199 }
    },

    {
      { 26.5678, 29.5185, -11902.0 },

      { 1.0, 3.2255, 166.199 }
    },

    {
      { -26.5678, -29.5185, -11902.0 },

      { 1.0, 3.2255, 166.199 }
    },

    {
      { -26.5678, -29.5185, -11902.0 },

      { 1.0, 3.2255, 166.199 }
    }
  },

  /* Mask Parameter: Gimbal_TransferFunctions_TF
   * Referenced by:
   *   '<S39>/Phi2Motor -> Pitch'
   *   '<S39>/Phi2Motor -> Roll'
   *   '<S39>/Phi2Motor -> Yaw'
   *   '<S39>/Psi2Motor -> Pitch'
   *   '<S39>/Psi2Motor -> Roll'
   *   '<S39>/Psi2Motor -> Yaw'
   *   '<S39>/Theta2Motor -> Pitch'
   *   '<S39>/Theta2Motor -> Roll'
   *   '<S39>/Theta2Motor -> Yaw'
   */
  {
    {
      { 4.207, 368.2 },

      { 1.0, 18.62, 365.1 }
    },

    {
      0.0,
      1.0
    },

    {
      0.0,
      1.0
    },

    {
      0.0,
      1.0
    },

    {
      { -0.1691, 6.862, 80.36, 1063.0, -95.88 },

      { 1.0, 26.16, 229.7, 1734.0, 2366.0, 1787.0 }
    },

    {
      0.0,
      1.0
    },

    {
      0.0,
      1.0
    },

    {
      0.0,
      1.0
    },

    {
      { -0.3003, 128.8, 6.16 },

      { 1.0, 12.34, 201.8, 184.5 }
    }
  },

  /* Mask Parameter: External_Inputs_External_Inputs
   * Referenced by:
   *   '<S2>/Step'
   *   '<S16>/Constant'
   *   '<S16>/Constant1'
   *   '<S16>/Constant2'
   *   '<S16>/Constant3'
   *   '<S16>/Constant4'
   *   '<S16>/Constant5'
   *   '<S16>/Pulse Generator'
   *   '<S16>/Pulse Generator3'
   *   '<S16>/Pulse Generator6'
   */
  {
    {
      10.0
    },

    {
      0.0,

      {
        {
          0.0,

          {
            0.0
          },

          {
            1.0,
            2.0,
            20.0,
            50.0,
            10.0
          }
        },

        {
          1.0,

          {
            0.0
          },

          {
            1.0,
            5.0,
            30.0,
            30.0,
            10.0
          }
        },

        {
          0.0,

          {
            0.0
          },

          {
            1.0,
            5.0,
            30.0,
            30.0,
            10.0
          }
        }
      }
    }
  },

  /* Mask Parameter: Initial_States_Rigid_Body
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S5>/Constant1'
   *   '<S5>/Constant10'
   *   '<S5>/Constant11'
   *   '<S5>/Constant12'
   *   '<S5>/Constant13'
   *   '<S5>/Constant14'
   *   '<S5>/Constant15'
   *   '<S5>/Constant16'
   *   '<S5>/Constant17'
   *   '<S5>/Constant2'
   *   '<S5>/Constant9'
   */
  {
    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0
    }
  },

  /* Mask Parameter: FlightController_FCC
   * Referenced by:
   *   '<S24>/Gain'
   *   '<S24>/Gain1'
   *   '<S24>/Gain2'
   *   '<S24>/Gain3'
   *   '<S24>/Gain4'
   *   '<S24>/Transfer Fcn'
   *   '<S24>/Transfer Fcn1'
   *   '<S24>/Transfer Fcn2'
   */
  {
    {
      315.5,
      0.001,

      {
        { 1.0, 2.3 },

        { 1.0, 40.0 }
      }
    },

    {
      {
        0.7231
      },

      {
        -0.01779,

        {
          -0.58935,

          { 1.0, 0.0 }
        }
      }
    },

    {
      {
        0.7231
      },

      {
        -0.01779,

        {
          -0.58935,

          { 1.0, 0.0 }
        }
      }
    }
  },

  /* Mask Parameter: Servo_TF
   * Referenced by:
   *   '<S10>/Transfer Fcn'
   *   '<S10>/Transfer Fcn1'
   *   '<S10>/Transfer Fcn2'
   *   '<S10>/Transfer Fcn3'
   */
  {
    746.4,

    { 1.0, 75.77, 3591.0 },
    746.4,

    { 1.0, 75.77, 3591.0 },
    746.4,

    { 1.0, 75.77, 3591.0 },
    746.4,

    { 1.0, 75.77, 3591.0 }
  },

  /* Mask Parameter: Servo_Cmd_PWM
   * Referenced by:
   *   '<S32>/Constant2'
   *   '<S32>/Constant6'
   *   '<S32>/Saturation'
   *   '<S33>/Constant2'
   *   '<S33>/Constant6'
   *   '<S33>/Saturation'
   *   '<S34>/Constant2'
   *   '<S34>/Constant6'
   *   '<S34>/Saturation'
   *   '<S35>/Constant2'
   *   '<S35>/Constant6'
   *   '<S35>/Saturation'
   */
  {
    250.0,
    4.0e-6,
    1.5,
    2.0,
    1.0,
    5.0,
    0.3490658503988659
  },

  /* Mask Parameter: Servo_PWM
   * Referenced by:
   *   '<S12>/Constant'
   *   '<S12>/Constant1'
   *   '<S12>/Constant2'
   *   '<S12>/Saturation'
   *   '<S13>/Constant'
   *   '<S13>/Constant1'
   *   '<S13>/Constant2'
   *   '<S13>/Saturation'
   *   '<S14>/Constant'
   *   '<S14>/Constant1'
   *   '<S14>/Constant2'
   *   '<S14>/Saturation'
   *   '<S15>/Constant'
   *   '<S15>/Constant1'
   *   '<S15>/Constant2'
   *   '<S15>/Saturation'
   */
  {
    250.0,
    4.0e-6,
    1.5,
    2.0,
    1.0,
    5.0,
    0.3490658503988659
  },

  /* Mask Parameter: ReverseFinDeflection_Control_Surfaces
   * Referenced by:
   *   '<S204>/Constant4'
   *   '<S204>/Constant5'
   *   '<S204>/Constant6'
   *   '<S204>/Constant7'
   */
  {
    -1.5707963267948966,
    1.5707963267948966,
    4.71238898038469,
    -4.71238898038469,
    0.3490658503988659
  },

  /* Mask Parameter: FinDeflection_Control_Surfaces
   * Referenced by:
   *   '<S23>/Constant'
   *   '<S23>/Constant1'
   *   '<S23>/Constant2'
   *   '<S23>/Constant3'
   *   '<S23>/Constant4'
   *   '<S23>/Limit2maxDeflection'
   */
  {
    -1.5707963267948966,
    1.5707963267948966,
    4.71238898038469,
    -4.71238898038469,
    0.3490658503988659
  },

  /* Mask Parameter: Servo_Cmd_Control_Surfaces
   * Referenced by: '<S27>/Constant'
   */
  {
    -1.5707963267948966,
    1.5707963267948966,
    4.71238898038469,
    -4.71238898038469,
    0.3490658503988659
  },

  /* Mask Parameter: Initial_States_Airframe
   * Referenced by: '<S5>/Constant18'
   */
  {
    0.0,
    4.171
  },

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S102>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditionForFilter
   * Referenced by: '<S146>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S107>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditionForIntegrator
   * Referenced by: '<S151>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S100>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController1_Kb
   * Referenced by: '<S144>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by: '<S114>/Saturation'
   */
  -20.0,

  /* Mask Parameter: PIDController1_LowerSaturationLimit
   * Referenced by: '<S158>/Saturation'
   */
  -20.0,

  /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
   * Referenced by: '<S221>/Real-Time Synchronization'
   */
  1000.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S110>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S154>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by: '<S114>/Saturation'
   */
  20.0,

  /* Mask Parameter: PIDController1_UpperSaturationLimit
   * Referenced by: '<S158>/Saturation'
   */
  20.0,

  /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
   * Referenced by: '<S221>/Real-Time Synchronization'
   */
  0.0,

  /* Computed Parameter: States_hold_Y0
   * Referenced by: '<S19>/States_hold'
   */
  {
    {
      {
        0.0,                           /* VEL_u_K_R_E_B_mDs */
        0.0,                           /* VEL_v_K_R_E_B_mDs */
        0.0                            /* VEL_w_K_R_E_B_mDs */
      },                               /* Translation_States */

      {
        0.0,                           /* ACC_x_B_mDs2 */
        0.0,                           /* ACC_y_B_mDs2 */
        0.0                            /* ACC_z_B_mDs2 */
      },                               /* Translation_States_Dot */

      {
        0.0,                           /* w_x_K_IB_B_radDs */
        0.0,                           /* w_y_K_IB_B_radDs */
        0.0                            /* w_z_K_IB_B_radDs */
      },                               /* Rotation_States */

      {
        {
          0.0,                         /* ATT_Phi_rad */
          0.0,                         /* ATT_Theta_rad */
          0.0                          /* ATT_Psi_rad */
        },                             /* ATT_Euler */

        {
          0.0,                         /* ATT_q_0 */
          0.0,                         /* ATT_q_1 */
          0.0,                         /* ATT_q_2 */
          0.0                          /* ATT_q_3 */
        }                              /* ATT_Quaternions */
      },                               /* Attitude_States */

      {
        {
          0.0,                         /* POS_lambda_WGS84_rad */
          0.0,                         /* POS_mue_WGS84_rad */
          0.0                          /* POS_h_WGS84_m */
        },                             /* POS_WGS84 */

        {
          0.0,                         /* POS_x_NED_m */
          0.0,                         /* POS_y_NED_m */
          0.0                          /* POS_z_NED_m */
        }                              /* POS_NED */
      }                                /* Position_States */
    },                                 /* Rigid_Body_States */

    {
      0.0,                             /* motor_state_perc */
      0.0                              /* mass_kg */
    },                                 /* Airframe_States */

    {
      0.0,                             /* VEL_u_Wind_A_E_O_mDs */
      0.0,                             /* VEL_v_Wind_A_E_O_mDs */
      0.0                              /* VEL_w_Wind_A_E_O_mDs */
    }                                  /* Atm_States */
  },

  /* Computed Parameter: Gimbal_State_hold_Y0
   * Referenced by: '<S19>/Gimbal_State_hold'
   */
  {
    {
      0.0,                             /* Gimbal_operational_flg */
      0.0,                             /* Gimbal_Ramp_flg */
      0.0,                             /* Gimbal_Limit_flg */
      0.0                              /* Gimbal_StopSim_flg */
    },                                 /* Gimbal_Status_Bus */

    {
      {
        0.0,                           /* ATT_Phi_rad */
        0.0,                           /* ATT_Theta_rad */
        0.0                            /* ATT_Psi_rad */
      },                               /* ATT_Euler_Bus */

      {
        0.0,                           /* ATT_q_0 */
        0.0,                           /* ATT_q_1 */
        0.0,                           /* ATT_q_2 */
        0.0                            /* ATT_q_3 */
      }                                /* ATT_Quaternions_Bus */
    },                                 /* Gimbal_Attitude_Bus */

    {
      {
        0.0,                           /* Gimbal_yaw_sns */
        0.0,                           /* Gimbal_pitch_sns */
        0.0                            /* Gimbal_roll_sns */
      },                               /* Encoder_Resolved */

      {
        0.0,                           /* Data_plus */
        0.0,                           /* Data_minus */
        0.0,                           /* Clock_plus */
        0.0                            /* Clock_minus */
      },                               /* Pos_Yaw_Encoder */

      {
        0.0,                           /* Data_plus */
        0.0,                           /* Data_minus */
        0.0,                           /* Clock_plus */
        0.0                            /* Clock_minus */
      },                               /* Pos_Pitch_Encoder */

      {
        0.0,                           /* Data_plus */
        0.0,                           /* Data_minus */
        0.0,                           /* Clock_plus */
        0.0                            /* Clock_minus */
      }                                /* Pos_Roll_Encoder */
    }                                  /* Gimbal_Encoder_Bus */
  },

  /* Computed Parameter: hold_Y0
   * Referenced by: '<S20>/hold'
   */
  {
    {
      {
        0.0                            /* signal1 */
      },                               /* Guidance_Cmd */

      {
        0.0,                           /* acc_y_mDs2 */
        0.0,                           /* acc_z_mDs2 */
        0.0                            /* phi_rad */
      },                               /* Controller_Cmd */

      {
        0.0,                           /* Phi_Cmd_rad */
        0.0,                           /* Theta_Cmd_rad */
        0.0                            /* Psi_Cmd_rad */
      },                               /* ATT_Cmd */

      {
        0.0,                           /* Fin_1_Cmd_rad */
        0.0,                           /* Fin_2_Cmd_rad */
        0.0,                           /* Fin_3_Cmd_rad */
        0.0                            /* Fin_4_Cmd_rad */
      },                               /* Control_Surface_Cmd */

      {
        {
          0.0,                         /* pulse_width_ms */
          0.0,                         /* periode_ms */
          0.0                          /* voltage_level_V */
        },                             /* Servo_1_Cmd_PWM */

        {
          0.0,                         /* pulse_width_ms */
          0.0,                         /* periode_ms */
          0.0                          /* voltage_level_V */
        },                             /* Servo_2_Cmd_PWM */

        {
          0.0,                         /* pulse_width_ms */
          0.0,                         /* periode_ms */
          0.0                          /* voltage_level_V */
        },                             /* Servo_3_Cmd_PWM */

        {
          0.0,                         /* pulse_width_ms */
          0.0,                         /* periode_ms */
          0.0                          /* voltage_level_V */
        }                              /* Servo_4_Cmd_PWM */
      }                                /* Servo_Cmd */
    }                                  /* Airframe_Cmd */
  },

  /* Computed Parameter: Simulation_Control_hold_Y0
   * Referenced by: '<S19>/Simulation_Control_hold'
   */
  {
    false,                             /* run */
    false,                             /* reset */

    {
      false,                           /* enable_propulsion_flg */
      false,                           /* enable_drag_flg */
      false                            /* enable_gravity_flg */
    },                                 /* FDM_Ctrl */

    {
      0.0,                             /* enable_gimbal_ctrl_flg */
      0.0                              /* stop_gimbal_flg */
    },                                 /* HW_Ctrl */

    {
      0.0,                             /* FCC_SampTime */
      false,                           /* DiscreteCtrlTF_flg */
      0.0                              /* ComFB_SampTime */
    },                                 /* FCC_Ctrl */

    {
      0.0,                             /* Pix_Com_freq_Hz */
      false,                           /* Pix_Com_CRC_flg */
      0.0                              /* FT_Com_freq_Hz */
    },                                 /* COM_Ctrl */
    false,                             /* realtime */
    false,                             /* external */
    0U                                 /* heartbeat */
  },

  /* Computed Parameter: External_Inputs_hold_Y0
   * Referenced by: '<S19>/External_Inputs_hold'
   */
  {
    {
      false                            /* Motor_Ignition_flg */
    },                                 /* FDM_External_Inputs_Bus */

    {
      false,                           /* Flight_Termination_flg */
      0.0,                             /* CMD_phi_rad */
      0.0,                             /* CMD_acc_z_mDs2 */
      0.0                              /* CMD_acc_y_mDs2 */
    }                                  /* FCC_External_Inputs_Bus */
  },

  /* Expression: 1
   * Referenced by: '<S16>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant14'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant7'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant12'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant9'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant13'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S74>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S74>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S74>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S74>/Gain3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S200>/acc_x_drag_mDs2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S200>/acc_y_drag_mDs2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S200>/acc_z_drag_mDs2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S200>/Constant'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S200>/Constant1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S200>/Constant2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S201>/acc_x_grav_mDs'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S201>/acc_y_grav_mDs'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S201>/acc_z_grav_mDs'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S210>/thrust'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S210>/state_percentage_change'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S210>/Constant2'
   */
  1.0,

  /* Computed Parameter: exec_time_hold_s_Y0
   * Referenced by: '<S211>/exec_time_hold_s'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S203>/motor_state_perc_dot'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain18'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain9'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain10'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gain3'
   */
  1.0,

  /* Expression: 1/4
   * Referenced by: '<S204>/Gain2'
   */
  0.25,

  /* Expression: 1
   * Referenced by: '<S195>/Gain4'
   */
  1.0,

  /* Expression: 1/4
   * Referenced by: '<S204>/Gain1'
   */
  0.25,

  /* Expression: 1
   * Referenced by: '<S195>/Gain5'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain9'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain10'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain11'
   */
  1.0,

  /* Expression: -2
   * Referenced by: '<S16>/Pulse Generator1'
   */
  -2.0,

  /* Computed Parameter: PulseGenerator1_Period
   * Referenced by: '<S16>/Pulse Generator1'
   */
  40000.0,

  /* Computed Parameter: PulseGenerator1_Duty
   * Referenced by: '<S16>/Pulse Generator1'
   */
  20000.0,

  /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s+External_Inputs.FCC.CMD.roll.pulse.period_s
   * Referenced by: '<S16>/Pulse Generator1'
   */
  30.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S16>/Pulse Generator'
   */
  20000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S16>/Pulse Generator'
   */
  10000.0,

  /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s
   * Referenced by: '<S16>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S16>/Switch1'
   */
  0.0,

  /* Expression: -2
   * Referenced by: '<S16>/Pulse Generator4'
   */
  -2.0,

  /* Computed Parameter: PulseGenerator4_Period
   * Referenced by: '<S16>/Pulse Generator4'
   */
  60000.0,

  /* Computed Parameter: PulseGenerator4_Duty
   * Referenced by: '<S16>/Pulse Generator4'
   */
  18000.0,

  /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s+External_Inputs.FCC.CMD.pitch.pulse.period_s
   * Referenced by: '<S16>/Pulse Generator4'
   */
  40.0,

  /* Computed Parameter: PulseGenerator3_Period
   * Referenced by: '<S16>/Pulse Generator3'
   */
  30000.0,

  /* Computed Parameter: PulseGenerator3_Duty
   * Referenced by: '<S16>/Pulse Generator3'
   */
  9000.0,

  /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s
   * Referenced by: '<S16>/Pulse Generator3'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S16>/Switch'
   */
  0.0,

  /* Expression: -2
   * Referenced by: '<S16>/Pulse Generator7'
   */
  -2.0,

  /* Computed Parameter: PulseGenerator7_Period
   * Referenced by: '<S16>/Pulse Generator7'
   */
  60000.0,

  /* Computed Parameter: PulseGenerator7_Duty
   * Referenced by: '<S16>/Pulse Generator7'
   */
  18000.0,

  /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s+External_Inputs.FCC.CMD.yaw.pulse.period_s
   * Referenced by: '<S16>/Pulse Generator7'
   */
  40.0,

  /* Computed Parameter: PulseGenerator6_Period
   * Referenced by: '<S16>/Pulse Generator6'
   */
  30000.0,

  /* Computed Parameter: PulseGenerator6_Duty
   * Referenced by: '<S16>/Pulse Generator6'
   */
  9000.0,

  /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s
   * Referenced by: '<S16>/Pulse Generator6'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S16>/Switch2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain6'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain7'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain8'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S195>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant1'
   */
  1.0,

  /* Expression: HIL_Data.Simulation_Ctrl.Com_Ctrl.Pix.Com_freq_Hz
   * Referenced by: '<S7>/Constant10'
   */
  200.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant2'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S18>/Memory'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S25>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S25>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S25>/Gain1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S36>/Memory1'
   */
  0.0,

  /* Expression: 360/(65536)
   * Referenced by: '<S45>/Shaft2degYaw'
   */
  0.0054931640625,

  /* Expression: 0
   * Referenced by: '<S176>/Transport Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Memory1'
   */
  0.0,

  /* Expression: -360/(65536)
   * Referenced by: '<S45>/Shaft2degPitch'
   */
  -0.0054931640625,

  /* Expression: 0
   * Referenced by: '<S174>/Transport Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Memory1'
   */
  0.0,

  /* Expression: -360/(65536)
   * Referenced by: '<S45>/Shaft2degRoll'
   */
  -0.0054931640625,

  /* Expression: 0
   * Referenced by: '<S175>/Transport Delay'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S72>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S72>/Switch2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S72>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S72>/Switch1'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S49>/Transfer Fcn1'
   */
  { -1.0, -0.25 },

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S49>/Transfer Fcn1'
   */
  { 0.0, 0.25 },

  /* Expression: 360/(2*pi)
   * Referenced by: '<S192>/rad2deg'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S73>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S73>/Filter'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S73>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_d
   * Referenced by: '<S71>/Merge'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S53>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S53>/Switch2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S53>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S53>/Switch1'
   */
  0.0,

  /* Expression: 360/(2*pi)
   * Referenced by: '<S192>/rad2deg1'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S54>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S54>/Filter'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_a
   * Referenced by: '<S54>/Merge'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S62>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S62>/Switch2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S62>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S62>/Switch1'
   */
  0.0,

  /* Expression: 360/(2*pi)
   * Referenced by: '<S192>/rad2deg2'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S63>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S63>/Filter'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_j
   * Referenced by: '<S63>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S45>/Merge2'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_a0
   * Referenced by: '<S45>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S45>/Merge1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S176>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S174>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S175>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain12'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain13'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain14'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain15'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain16'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S189>/Gain17'
   */
  1.0,

  /* Expression: 1/4
   * Referenced by: '<S204>/Gain'
   */
  0.25,

  /* Expression: External_Inputs.FCC.CMD.yaw.pulse.alternating_flg
   * Referenced by: '<S16>/Constant10'
   */
  1,

  /* Expression: External_Inputs.FCC.CMD.roll.pulse.alternating_flg
   * Referenced by: '<S16>/Constant6'
   */
  1,

  /* Expression: External_Inputs.FCC.CMD.pitch.pulse.alternating_flg
   * Referenced by: '<S16>/Constant8'
   */
  1,

  /* Computed Parameter: lock_InitialCondition
   * Referenced by: '<S203>/lock'
   */
  0,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S7>/Constant4'
   */
  0,

  /* Computed Parameter: Constant2_Value_f
   * Referenced by: '<S7>/Constant2'
   */
  0,

  /* Computed Parameter: Constant6_Value_k
   * Referenced by: '<S7>/Constant6'
   */
  0,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S7>/Constant5'
   */
  0,

  /* Computed Parameter: Constant1_Value_f
   * Referenced by: '<S72>/Constant1'
   */
  0,

  /* Computed Parameter: Constant1_Value_m
   * Referenced by: '<S53>/Constant1'
   */
  0,

  /* Computed Parameter: Constant1_Value_j
   * Referenced by: '<S62>/Constant1'
   */
  0,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S7>/Constant'
   */
  1,

  /* Computed Parameter: Constant1_Value_c
   * Referenced by: '<S7>/Constant1'
   */
  1,

  /* Computed Parameter: Constant9_Value_b
   * Referenced by: '<S7>/Constant9'
   */
  1,

  /* Expression: HIL_Data.Simulation_Ctrl.offline_flg
   * Referenced by: '<S7>/Constant3'
   */
  1,

  /* Start of '<S176>/If Action Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S181>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S176>/If Action Subsystem' */

  /* Start of '<S176>/If Action Subsystem1' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S182>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S176>/If Action Subsystem1' */

  /* Start of '<S175>/If Action Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S179>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S175>/If Action Subsystem' */

  /* Start of '<S175>/If Action Subsystem1' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S180>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S175>/If Action Subsystem1' */

  /* Start of '<S174>/If Action Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S177>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S174>/If Action Subsystem' */

  /* Start of '<S174>/If Action Subsystem1' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S178>/Out1'
     */
    0.0
  }
  /* End of '<S174>/If Action Subsystem1' */
};

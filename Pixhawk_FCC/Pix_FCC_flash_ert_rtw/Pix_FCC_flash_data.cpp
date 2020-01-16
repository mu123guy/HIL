//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash_data.cpp
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.342
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Jan 16 20:05:28 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Pix_FCC_flash.h"
#include "Pix_FCC_flash_private.h"

// Block parameters (default storage)
P_Pix_FCC_flash_T Pix_FCC_flash_P = {
  // Variable: FCC_PIX_Data
  //  Referenced by:
  //    '<S18>/Constant'
  //    '<S18>/Constant1'
  //    '<S18>/Constant2'
  //    '<S18>/Constant3'
  //    '<S18>/Constant4'
  //    '<S18>/Limit2maxDeflection'
  //    '<S20>/Constant'
  //    '<S33>/Constant2'
  //    '<S33>/Constant6'
  //    '<S33>/Saturation'
  //    '<S34>/Constant2'
  //    '<S34>/Constant6'
  //    '<S34>/Saturation'
  //    '<S35>/Constant2'
  //    '<S35>/Constant6'
  //    '<S35>/Saturation'
  //    '<S36>/Constant2'
  //    '<S36>/Constant6'
  //    '<S36>/Saturation'

  {
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

    {
      -1.5707963267948966,
      1.5707963267948966,
      4.71238898038469,
      -4.71238898038469,
      0.3490658503988659
    },

    {
      {
        250.0,
        4.0e-6,
        1.5,
        2.0,
        1.0,
        5.0,
        0.3490658503988659
      }
    }
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S56>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // integral_dt
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_m_s2
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S55>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // integral_dt
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_m_s2
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S58>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // integral_dt
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_rad_s
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S57>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // integral_dt
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_rad_s
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S60>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S59>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Expression: 0.01
  //  Referenced by: '<Root>/Receive Data'

  0.01,

  // Expression: 1
  //  Referenced by: '<S28>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S29>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S15>/Zero'

  0.0,

  // Expression: 12
  //  Referenced by: '<S15>/Kp'

  12.0,

  // Expression: -0.1
  //  Referenced by: '<S15>/Gain5'

  -0.1,

  // Expression: 1
  //  Referenced by: '<S40>/Constant'

  1.0,

  // Computed Parameter: CMD_Y0
  //  Referenced by: '<S51>/CMD'

  0.0F,

  // Computed Parameter: ACC_Y0
  //  Referenced by: '<S51>/ACC'

  0.0F,

  // Computed Parameter: ROT_Y0
  //  Referenced by: '<S51>/ROT'

  0.0F,

  // Computed Parameter: ATT_Y0
  //  Referenced by: '<S51>/ATT'

  0.0F,

  // Computed Parameter: TestSignal_Y0
  //  Referenced by: '<S51>/TestSignal'

  0.0F,

  // Computed Parameter: ServoCMD_Y0
  //  Referenced by: '<S10>/ServoCMD'

  0.0F,

  // Computed Parameter: SensorACC_Y0
  //  Referenced by: '<S10>/SensorACC'

  0.0F,

  // Computed Parameter: SensorROT_Y0
  //  Referenced by: '<S10>/SensorROT'

  0.0F,

  // Computed Parameter: quaternion_Y0
  //  Referenced by: '<S10>/quaternion'

  0.0F,

  // Computed Parameter: TestSignal_feedback_Y0
  //  Referenced by: '<S10>/TestSignal_feedback'

  0.0F,

  // Computed Parameter: ms2us_1_Gain
  //  Referenced by: '<S39>/ms2us_1'

  64000U,

  // Computed Parameter: ms2us_2_Gain
  //  Referenced by: '<S39>/ms2us_2'

  64000U,

  // Computed Parameter: ms2us_3_Gain
  //  Referenced by: '<S39>/ms2us_3'

  64000U,

  // Computed Parameter: ms2us_4_Gain
  //  Referenced by: '<S39>/ms2us_4'

  64000U,

  // Computed Parameter: heartbeat_Y0
  //  Referenced by: '<S12>/heartbeat'

  0U,

  // Computed Parameter: SimHeartbeat_Y0
  //  Referenced by: '<S51>/SimHeartbeat'

  0U,

  // Computed Parameter: Recovery_activation_flg_Value
  //  Referenced by: '<S11>/Recovery_activation_flg'

  0U,

  // Computed Parameter: HIL_detect_flg_Value
  //  Referenced by: '<S11>/HIL_detect_flg'

  4000U,

  // Computed Parameter: cmd_found_flg_Y0
  //  Referenced by: '<S6>/cmd_found_flg'

  0,

  // Computed Parameter: packetfound_flg_Y0
  //  Referenced by: '<S48>/packetfound_flg'

  0,

  // Computed Parameter: PWM_arm_flg_Value
  //  Referenced by: '<S11>/PWM_arm_flg'

  0,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S3>/Constant'

  1,

  // Computed Parameter: SimStatus_Y0
  //  Referenced by: '<S51>/SimStatus'

  0U,

  // Computed Parameter: SimRCStatus_Y0
  //  Referenced by: '<S51>/SimRCStatus'

  0U,

  // Computed Parameter: PixStatus_Y0
  //  Referenced by: '<S10>/PixStatus'

  0U,

  // Computed Parameter: RCStatus_Y0
  //  Referenced by: '<S10>/RCStatus'

  0U,

  // Computed Parameter: Header_Value
  //  Referenced by: '<S40>/Header'

  { 5U, 5U, 5U },

  // Computed Parameter: Header1_Value
  //  Referenced by: '<S40>/Header1'

  { 5U, 5U, 5U }
};

//
// File trailer for generated code.
//
// [EOF]
//

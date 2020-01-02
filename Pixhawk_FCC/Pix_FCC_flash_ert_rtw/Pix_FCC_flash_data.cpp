//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash_data.cpp
//
// Code generated for Simulink model 'Pix_FCC_flash'.
//
// Model version                  : 1.333
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Jan  2 23:39:39 2020
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
  //    '<S26>/Constant'
  //    '<S26>/Constant1'
  //    '<S26>/Constant2'
  //    '<S26>/Constant3'
  //    '<S26>/Constant4'
  //    '<S27>/Constant'
  //    '<S32>/Constant2'
  //    '<S32>/Constant6'
  //    '<S32>/Saturation'
  //    '<S33>/Constant2'
  //    '<S33>/Constant6'
  //    '<S33>/Saturation'
  //    '<S34>/Constant2'
  //    '<S34>/Constant6'
  //    '<S34>/Saturation'
  //    '<S35>/Constant2'
  //    '<S35>/Constant6'
  //    '<S35>/Saturation'

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

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S22>/Constant'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S60>/Out1'

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
  //  Referenced by: '<S59>/Constant'

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
  //  Referenced by: '<S62>/Out1'

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
  //  Referenced by: '<S61>/Constant'

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
  //  Referenced by: '<S64>/Out1'

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
  //  Referenced by: '<S63>/Constant'

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
  //  Referenced by: '<S39>/Constant'

  1.0,

  // Computed Parameter: CMD_Y0
  //  Referenced by: '<S55>/CMD'

  0.0F,

  // Computed Parameter: ACC_Y0
  //  Referenced by: '<S55>/ACC'

  0.0F,

  // Computed Parameter: ROT_Y0
  //  Referenced by: '<S55>/ROT'

  0.0F,

  // Computed Parameter: ATT_Y0
  //  Referenced by: '<S55>/ATT'

  0.0F,

  // Computed Parameter: TestSignal_Y0
  //  Referenced by: '<S55>/TestSignal'

  0.0F,

  // Computed Parameter: ServoCMD_Y0
  //  Referenced by: '<S18>/ServoCMD'

  0.0F,

  // Computed Parameter: SensorACC_Y0
  //  Referenced by: '<S18>/SensorACC'

  0.0F,

  // Computed Parameter: SensorROT_Y0
  //  Referenced by: '<S18>/SensorROT'

  0.0F,

  // Computed Parameter: quaternion_Y0
  //  Referenced by: '<S18>/quaternion'

  0.0F,

  // Computed Parameter: TestSignal_feedback_Y0
  //  Referenced by: '<S18>/TestSignal_feedback'

  0.0F,

  // Expression: FCC_PIX_Data.Controller.Yaw.outerLoop.IntGain.Num
  //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  -0.58935F,

  // Expression: FCC_PIX_Data.Controller.Yaw.outerLoop.IntGain.Denom
  //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  { 1.0F, 0.0F },

  // Computed Parameter: DiscreteTransferFcn2_InitialSta
  //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  0.0F,

  // Expression: FCC_PIX_Data.Controller.Yaw.outerLoop.PropGain
  //  Referenced by: '<S23>/Gain4'

  -0.01779F,

  // Expression: FCC_PIX_Data.Controller.Yaw.innerLoop.PropGain
  //  Referenced by: '<S23>/Gain2'

  0.7231F,

  // Expression: FCC_PIX_Data.Controller.Pitch.outerLoop.IntGain.Num
  //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  -0.58935F,

  // Expression: FCC_PIX_Data.Controller.Pitch.outerLoop.IntGain.Denom
  //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  { 1.0F, 0.0F },

  // Computed Parameter: DiscreteTransferFcn1_InitialSta
  //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  0.0F,

  // Expression: FCC_PIX_Data.Controller.Pitch.outerLoop.PropGain
  //  Referenced by: '<S23>/Gain3'

  -0.01779F,

  // Expression: FCC_PIX_Data.Controller.Pitch.innerLoop.PropGain
  //  Referenced by: '<S23>/Gain1'

  0.7231F,

  // Expression: FCC_PIX_Data.Controller.Roll.Gain
  //  Referenced by: '<S23>/Gain'

  0.001F,

  // Expression: FCC_PIX_Data.Controller.Roll.Lead.Num
  //  Referenced by: '<S23>/Discrete Transfer Fcn'

  { 1.0F, 2.3F },

  // Expression: FCC_PIX_Data.Controller.Roll.Lead.Denom
  //  Referenced by: '<S23>/Discrete Transfer Fcn'

  { 1.0F, 40.0F },

  // Computed Parameter: DiscreteTransferFcn_InitialStat
  //  Referenced by: '<S23>/Discrete Transfer Fcn'

  0.0F,

  // Expression: FCC_PIX_Data.Control_Surfaces.max_deflection_rad
  //  Referenced by: '<S26>/Limit2maxDeflection'

  0.34906584F,

  // Computed Parameter: Limit2maxDeflection_LowerSat
  //  Referenced by: '<S26>/Limit2maxDeflection'

  -0.34906584F,

  // Computed Parameter: ms2us_1_Gain
  //  Referenced by: '<S38>/ms2us_1'

  64000U,

  // Computed Parameter: ms2us_2_Gain
  //  Referenced by: '<S38>/ms2us_2'

  64000U,

  // Computed Parameter: ms2us_3_Gain
  //  Referenced by: '<S38>/ms2us_3'

  64000U,

  // Computed Parameter: ms2us_4_Gain
  //  Referenced by: '<S38>/ms2us_4'

  64000U,

  // Computed Parameter: heartbeat_Y0
  //  Referenced by: '<S20>/heartbeat'

  0U,

  // Computed Parameter: SimHeartbeat_Y0
  //  Referenced by: '<S55>/SimHeartbeat'

  0U,

  // Computed Parameter: Recovery_activation_flg_Value
  //  Referenced by: '<S19>/Recovery_activation_flg'

  0U,

  // Computed Parameter: HIL_detect_flg_Value
  //  Referenced by: '<S19>/HIL_detect_flg'

  4000U,

  // Computed Parameter: cmd_found_flg_Y0
  //  Referenced by: '<S6>/cmd_found_flg'

  0,

  // Computed Parameter: packetfound_flg_Y0
  //  Referenced by: '<S52>/packetfound_flg'

  0,

  // Computed Parameter: PWM_arm_flg_Value
  //  Referenced by: '<S19>/PWM_arm_flg'

  0,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S3>/Constant'

  1,

  // Computed Parameter: Header_Value
  //  Referenced by: '<S13>/Header'

  1U,

  // Computed Parameter: SimStatus_Y0
  //  Referenced by: '<S55>/SimStatus'

  0U,

  // Computed Parameter: SimRCStatus_Y0
  //  Referenced by: '<S55>/SimRCStatus'

  0U,

  // Computed Parameter: PixStatus_Y0
  //  Referenced by: '<S18>/PixStatus'

  0U,

  // Computed Parameter: RCStatus_Y0
  //  Referenced by: '<S18>/RCStatus'

  0U,

  // Start of '<S39>/Send WhiteNoise End'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S47>/Header'

    { 0U, 0U, 0U, 0U, 0U }
  }
  ,

  // End of '<S39>/Send WhiteNoise End'

  // Start of '<S39>/Send Terminator'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S45>/Header'

    { 5U, 5U }
  }
  ,

  // End of '<S39>/Send Terminator'

  // Start of '<S39>/Send Header'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S44>/Header'

    { 5U, 5U }
  }
  ,

  // End of '<S39>/Send Header'

  // Start of '<S39>/Send WhiteNoise Beginning'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S46>/Header'

    { 0U, 0U, 0U, 0U, 0U }
  }
  ,

  // End of '<S39>/Send WhiteNoise Beginning'

  // Start of '<S9>/Send WhiteNoise End'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S16>/Header'

    { 0U, 0U, 0U, 0U, 0U }
  }
  ,

  // End of '<S9>/Send WhiteNoise End'

  // Start of '<S9>/Send Terminator'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S14>/Header'

    { 9U, 9U }
  }
  ,

  // End of '<S9>/Send Terminator'

  // Start of '<S9>/Send Header'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S12>/Header'

    { 9U, 9U }
  }
  ,

  // End of '<S9>/Send Header'

  // Start of '<S9>/Send WhiteNoise Beginning'
  {
    // Computed Parameter: Header_Value
    //  Referenced by: '<S15>/Header'

    { 0U, 0U, 0U, 0U, 0U }
  }
  // End of '<S9>/Send WhiteNoise Beginning'
};

//
// File trailer for generated code.
//
// [EOF]
//

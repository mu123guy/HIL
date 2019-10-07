//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled_data.cpp
//
// Code generated for Simulink model 'untitled'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Oct  6 19:40:43 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "untitled.h"
#include "untitled_private.h"

// Block parameters (default storage)
P_untitled_T untitled_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S4>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // range_ga
    0.0F,                              // scaling
    0.0F,                              // temperature
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S3>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // range_ga
    0.0F,                              // scaling
    0.0F,                              // temperature
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S6>/Out1'

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

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S5>/Constant'

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
  }
};

//
// File trailer for generated code.
//
// [EOF]
//

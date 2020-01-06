//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_serial_data.cpp
//
// Code generated for Simulink model 'px4demo_serial'.
//
// Model version                  : 1.139
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Jan  1 16:26:42 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4demo_serial.h"
#include "px4demo_serial_private.h"

// Block parameters (default storage)
P_px4demo_serial_T px4demo_serial_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S8>/Out1'

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
  //  Referenced by: '<S7>/Constant'

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

  // Expression: 0.1
  //  Referenced by: '<Root>/Serial Receive1'

  0.1,

  // Computed Parameter: Header_Value
  //  Referenced by: '<S5>/Header'

  { 5U, 5U }
};

//
// File trailer for generated code.
//
// [EOF]
//

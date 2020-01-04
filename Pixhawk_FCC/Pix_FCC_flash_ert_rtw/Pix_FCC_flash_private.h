//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pix_FCC_flash_private.h
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
#ifndef RTW_HEADER_Pix_FCC_flash_private_h_
#define RTW_HEADER_Pix_FCC_flash_private_h_
#include "rtwtypes.h"
#include "Pix_FCC_flash.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

// Skipping ulong_long/long_long check: insufficient preprocessor integer range. 
extern void P_SendWhiteNoiseBeginning_Start(DW_SendWhiteNoiseBeginning_Pi_T
  *localDW);
extern void Pix_FCC_SendWhiteNoiseBeginning(DW_SendWhiteNoiseBeginning_Pi_T
  *localDW, P_SendWhiteNoiseBeginning_Pix_T *localP);
extern void Pix_FCC_flash_SendHeader_Start(DW_SendHeader_Pix_FCC_flash_T
  *localDW);
extern void Pix_FCC_flash_SendHeader(DW_SendHeader_Pix_FCC_flash_T *localDW,
  P_SendHeader_Pix_FCC_flash_T *localP);
extern void Pi_SendWhiteNoiseBeginning_Term(DW_SendWhiteNoiseBeginning_Pi_T
  *localDW);
extern void Pix_FCC_flash_SendHeader_Term(DW_SendHeader_Pix_FCC_flash_T *localDW);

#endif                                 // RTW_HEADER_Pix_FCC_flash_private_h_

//
// File trailer for generated code.
//
// [EOF]
//

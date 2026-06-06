/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: plook_u32s16u32n32_lincpa_f.c
 *
 * Code generated for Simulink model 'FrictionComp_Study_1'.
 *
 * Model version                  : 9.58
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jun  4 11:01:02 2024
 */

#include "plook_u32s16u32n32_lincpa_f.h"
#include "linsearch_u32s16.h"
#include "rtwtypes.h"

UInt32 plook_u32s16u32n32_lincpa_f(Int16 u, const Int16 bp[], UInt32
  maxIndex, UInt32 *fraction, UInt32 *prevIndex)
{
  UInt32 bpIndex;
  Int16 bpLeftVar;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'floor'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = linsearch_u32s16(u, bp, *prevIndex);
    bpLeftVar = bp[bpIndex];
    *fraction = (UInt32)((uint64_T)((((uint64_T)((UInt16)((Int32)
      (((Int32)u) - ((Int32)bpLeftVar))))) << 32ULL) / ((uint64_T)((UInt16)
      ((Int32)(((Int32)bp[bpIndex + 1U]) - ((Int32)bpLeftVar)))))));
  } else {
    bpIndex = maxIndex;
    *fraction = 0U;
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

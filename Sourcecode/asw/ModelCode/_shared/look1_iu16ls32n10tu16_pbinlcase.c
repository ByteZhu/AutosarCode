/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look1_iu16ls32n10tu16_pbinlcase.c
 *
 * Code generated for Simulink model 'SBWCode'.
 *
 * Model version                  : 247
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Sep  9 00:35:38 2023
 */

#include "rtwtypes.h"
//#include "asr_s32.h"
#include "look1_iu16ls32n10tu16_pbinlcase.h"

Int32 asr_s32_2(Int32 u, UInt32 n)
{
  Int32 y;
  if (u >= 0) {
    y = (Int32)((UInt32)(((UInt32)u) >> n));
  } else {
    y = (-((Int32)((UInt32)(((UInt32)((Int32)(-1 - u))) >> n)))) - 1;
  }

  return y;
}

UInt16 look1_iu16ls32n10tu16_pbinlcase(UInt16 u0, const UInt16 bp0[],
  const UInt16 table[], UInt32 prevIndex[], UInt32 maxIndex)
{
  Int32 frac;
  UInt32 bpIdx;
  UInt32 found;
  UInt32 iLeft;
  UInt32 iRght;
  UInt16 bpLeftVar;
  UInt16 y;
  UInt16 yL_0d0;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = (((bpIdx + iLeft) - 1U) >> 1U);
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = (((bpIdx + iRght) + 1U) >> 1U);
      }
    }

    bpLeftVar = bp0[bpIdx];
    frac = (Int32)((UInt32)((((UInt32)((UInt16)(((UInt32)u0) -
      ((UInt32)bpLeftVar)))) << 10U) / ((UInt32)((UInt16)(((UInt32)
      bp0[bpIdx + 1U]) - ((UInt32)bpLeftVar))))));
  } else {
    bpIdx = maxIndex;
    frac = 0;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    bpLeftVar = table[bpIdx + 1U];
    yL_0d0 = table[bpIdx];
    if (bpLeftVar >= yL_0d0) {
      y = (UInt16)(((UInt32)((UInt16)asr_s32_2(((Int32)((UInt16)
        (((UInt32)bpLeftVar) - ((UInt32)yL_0d0)))) * frac, 10U))) +
                     ((UInt32)yL_0d0));
    } else {
      y = (UInt16)(((UInt32)yL_0d0) - ((UInt32)((UInt16)asr_s32_2
        (((Int32)((UInt16)(((UInt32)yL_0d0) - ((UInt32)bpLeftVar)))) *
         frac, 10U))));
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

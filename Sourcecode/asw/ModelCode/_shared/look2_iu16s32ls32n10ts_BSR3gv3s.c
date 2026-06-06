/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look2_iu16s32ls32n10ts_BSR3gv3s.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 9.136
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Jun 20 17:04:50 2024
 */

#include "look2_iu16s32ls32n10ts_BSR3gv3s.h"
#include "asr_s32.h"
#include "rtwtypes.h"

Int16 look2_iu16s32ls32n10ts_BSR3gv3s(UInt16 u0, Int32 u1, const UInt16
  bp0[], const Int32 bp1[], const Int16 table[], UInt32 prevIndex[], const
  UInt32 maxIndex[], UInt32 stride)
{
  Int32 fractions[2];
  Int32 frac;
  UInt32 bpIndices[2];
  UInt32 bpIdx;
  UInt32 offset_1d;
  Int16 y;
  Int16 yL_0d0;
  UInt16 bpLeftVar;

  /* Column-major Lookup 2-D
     Canonical function name: look2_iu16s32ls32n10ts16Ds32ds32_plinlcas
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    bpLeftVar = bp0[bpIdx];
    frac = (Int32)((UInt32)((((UInt32)((UInt16)(((UInt32)u0) -
      ((UInt32)bpLeftVar)))) << 10ULL) / ((UInt32)((UInt16)(((UInt32)
      bp0[bpIdx + 1U]) - ((UInt32)bpLeftVar))))));
  } else {
    bpIdx = maxIndex[0U];
    frac = 0;
  }

  prevIndex[0U] = bpIdx;
  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[1U]; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = bp1[bpIdx];
    frac = (Int32)((uint64_T)((((uint64_T)((UInt32)(((UInt32)u1) -
      ((UInt32)frac)))) << 10ULL) / ((uint64_T)((UInt32)(((UInt32)
      bp1[bpIdx + 1U]) - ((UInt32)frac))))));
  } else {
    bpIdx = maxIndex[1U];
    frac = 0;
  }

  prevIndex[1U] = bpIdx;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  offset_1d = (bpIdx * stride) + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    yL_0d0 = table[offset_1d];
    y = (Int16)(((Int16)asr_s32((((Int32)table[offset_1d + 1U]) -
      ((Int32)yL_0d0)) * fractions[0U], 10U)) + yL_0d0);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (Int16)asr_s32((((Int32)table[bpIdx + 1U]) - ((Int32)
        yL_0d0)) * fractions[0U], 10U);
    }

    y += (Int16)asr_s32((((Int32)yL_0d0) - ((Int32)y)) * frac, 10U);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

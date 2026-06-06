/*
 * File: look2_is16u16ls32n10ts_TlwpcxFz.c
 *
 * Code generated for Simulink model 'LoadCloseloop'.
 *
 * Model version                  : 1.1143
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:53:21 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look2_is16u16ls32n10ts_TlwpcxFz.h"

Int16 look2_is16u16ls32n10ts_TlwpcxFz(Int16 u0, UInt16 u1, const Int16
  bp0[], const UInt16 bp1[], const Int16 table[], UInt32 prevIndex[],
  const UInt32 maxIndex[], UInt32 stride)
{
  Int16 y;
  Int32 frac;
  UInt32 bpIndices[2];
  Int32 fractions[2];
  Int16 yR_1d;
  UInt32 offset_1d;
  UInt32 bpIdx;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16u16ls32n10ts16Ds32ds32_plinlcas
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

    frac = (Int32)((UInt32)((((UInt32)((UInt16)((Int32)(((Int32)u0)
      - ((Int32)bp0[bpIdx]))))) << 10) / ((UInt32)((UInt16)((Int32)
      (((Int32)bp0[bpIdx + 1U]) - ((Int32)bp0[bpIdx])))))));
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

    frac = (Int32)((UInt32)((((UInt32)((UInt16)(((UInt32)u1) -
      ((UInt32)bp1[bpIdx])))) << 10) / ((UInt32)((UInt16)(((UInt32)
      bp1[bpIdx + 1U]) - ((UInt32)bp1[bpIdx]))))));
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
    y = (Int16)(((Int16)asr_s32((((Int32)table[offset_1d + 1U]) -
      ((Int32)table[offset_1d])) * fractions[0U], 10U)) + table[offset_1d]);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (Int16)(((Int16)asr_s32((((Int32)table[bpIdx + 1U]) -
        ((Int32)table[bpIdx])) * fractions[0U], 10U)) + table[bpIdx]);
    }

    y += (Int16)asr_s32((((Int32)yR_1d) - ((Int32)y)) * frac, 10U);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: look2_is16u16ls32n10tu_gntPemx1.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.1390
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:02:58 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look2_is16u16ls32n10tu_gntPemx1.h"

UInt16 look2_is16u16ls32n10tu_gntPemx1(Int16 u0, UInt16 u1, const Int16
  bp0[], const UInt16 bp1[], const UInt16 table[], UInt32 prevIndex[],
  const UInt32 maxIndex[], UInt32 stride)
{
  UInt16 y;
  Int32 frac;
  UInt32 bpIndices[2];
  Int32 fractions[2];
  UInt32 offset_1d;
  UInt16 yR_0d0;
  UInt32 bpIdx;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16u16ls32n10tu16_plinlcase
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
    yR_0d0 = table[offset_1d + 1U];
    if (yR_0d0 >= table[offset_1d]) {
      y = (UInt16)(((UInt32)((UInt16)asr_s32(((Int32)((UInt16)
        (((UInt32)yR_0d0) - ((UInt32)table[offset_1d])))) * fractions[0U],
        10U))) + ((UInt32)table[offset_1d]));
    } else {
      y = (UInt16)(((UInt32)table[offset_1d]) - ((UInt32)((UInt16)
        asr_s32(((Int32)((UInt16)(((UInt32)table[offset_1d]) - ((UInt32)
        yR_0d0)))) * fractions[0U], 10U))));
    }
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_0d0 = table[bpIdx];
    } else {
      yR_0d0 = table[bpIdx + 1U];
      if (yR_0d0 >= table[bpIdx]) {
        yR_0d0 = (UInt16)(((UInt32)((UInt16)asr_s32(((Int32)((UInt16)
          (((UInt32)yR_0d0) - ((UInt32)table[bpIdx])))) * fractions[0U], 10U)))
                            + ((UInt32)table[bpIdx]));
      } else {
        yR_0d0 = (UInt16)(((UInt32)table[bpIdx]) - ((UInt32)((UInt16)
          asr_s32(((Int32)((UInt16)(((UInt32)table[bpIdx]) - ((UInt32)
          yR_0d0)))) * fractions[0U], 10U))));
      }
    }

    if (yR_0d0 >= y) {
      y = (UInt16)(((UInt32)((UInt16)asr_s32(((Int32)((UInt16)
        (((UInt32)yR_0d0) - ((UInt32)y)))) * frac, 10U))) + ((UInt32)y));
    } else {
      y = (UInt16)(((UInt32)y) - ((UInt32)((UInt16)asr_s32(((Int32)
        ((UInt16)(((UInt32)y) - ((UInt32)yR_0d0)))) * frac, 10U))));
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

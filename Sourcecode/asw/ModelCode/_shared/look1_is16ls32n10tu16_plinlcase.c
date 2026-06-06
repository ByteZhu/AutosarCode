/*
 * File: look1_is16ls32n10tu16_plinlcase.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.1390
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:02:58 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look1_is16ls32n10tu16_plinlcase.h"

UInt16 look1_is16ls32n10tu16_plinlcase(Int16 u0, const Int16 bp0[], const
  UInt16 table[], UInt32 prevIndex[], UInt32 maxIndex)
{
  UInt16 y;
  Int32 frac;
  UInt16 yR_0d0;
  UInt32 bpIdx;

  /* Column-major Lookup 1-D
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
  } else if (u0 < bp0[maxIndex]) {
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
    yR_0d0 = table[bpIdx + 1U];
    if (yR_0d0 >= table[bpIdx]) {
      y = (UInt16)(((UInt32)((UInt16)asr_s32(((Int32)((UInt16)
        (((UInt32)yR_0d0) - ((UInt32)table[bpIdx])))) * frac, 10U))) +
                     ((UInt32)table[bpIdx]));
    } else {
      y = (UInt16)(((UInt32)table[bpIdx]) - ((UInt32)((UInt16)asr_s32
        (((Int32)((UInt16)(((UInt32)table[bpIdx]) - ((UInt32)yR_0d0)))) *
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

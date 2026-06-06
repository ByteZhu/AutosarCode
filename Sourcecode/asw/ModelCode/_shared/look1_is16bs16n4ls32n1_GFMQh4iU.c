/*
 * File: look1_is16bs16n4ls32n1_GFMQh4iU.c
 *
 * Code generated for Simulink model 'Variant_LimitPIDparam'.
 *
 * Model version                  : 1.1140
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Sep 14 09:12:26 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look1_is16bs16n4ls32n1_GFMQh4iU.h"

UInt16 look1_is16bs16n4ls32n1_GFMQh4iU(Int16 u0, const Int16 bp0[], const
  UInt16 table[], UInt32 prevIndex[], UInt32 maxIndex)
{
  UInt16 y;
  Int32 frac;
  UInt16 yR_0d0;
  UInt32 bpIdx;
  Int16 uCast;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16bs16n4ls32n10tu16_plinlcase
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
  if (u0 > 2047) {
    uCast = MAX_int16_T;
  } else if (u0 <= -2048) {
    uCast = MIN_int16_T;
  } else {
    uCast = (Int16)(u0 * 16);
  }

  if ((u0 * 16) < bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (uCast < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; uCast < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (Int32)((uint64_T)((((uint64_T)((UInt32)((((UInt32)u0) << 4) -
      ((UInt32)bp0[bpIdx])))) << 10) / ((uint64_T)((UInt16)((Int32)
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

/*
 * File: look1_is16ls32n10ts16D_XHvi1f4d.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Sep  6 14:33:06 2023
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look1_is16ls32n10ts16D_XHvi1f4d.h"

Int16 look1_is16ls32n10ts16D_XHvi1f4d(Int16 u0, const Int16 bp0[], const
  Int16 table[], UInt32 prevIndex[], UInt32 maxIndex)
{
  Int16 y;
  Int32 frac;
  UInt32 bpIdx;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16ls32n10ts16Ds32_plinlags
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Linear Search */
  bpIdx = prevIndex[0U];
  while ((u0 < bp0[bpIdx]) && (bpIdx > 0U)) {
    bpIdx--;
  }

  while ((bpIdx < maxIndex) && (u0 >= bp0[bpIdx + 1U])) {
    bpIdx++;
  }

  prevIndex[0U] = bpIdx;
  frac = (Int32)((UInt32)((((UInt32)((UInt16)((Int32)(((Int32)u0) -
    ((Int32)bp0[bpIdx]))))) << 10) / ((UInt32)((UInt16)((Int32)
    (((Int32)bp0[bpIdx + 1U]) - ((Int32)bp0[bpIdx])))))));

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (Int16)(((Int16)asr_s32((((Int32)table[bpIdx + 1U]) - ((Int32)
      table[bpIdx])) * frac, 10U)) + table[bpIdx]);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

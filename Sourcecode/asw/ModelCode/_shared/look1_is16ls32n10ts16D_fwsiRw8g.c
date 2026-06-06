/*
 * File: look1_is16ls32n10ts16D_fwsiRw8g.c
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.599
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 30 10:22:14 2020
 */

#include "Common.h"
#include "asr_s32.h"
//#include "asr_s64.h"


Int16 look1_is16ls32n10ts16D_fwsiRw8g(Int16 u0, const Int16 bp0[], const
  Int16 table[], UInt32 maxIndex)
{
  Int16 y;
  Int32 frac;
  UInt32 bpIdx;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16ls32n10ts16Ds32_linlcas
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = (maxIndex >> 1U); u0 < bp0[bpIdx]; bpIdx--) {
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

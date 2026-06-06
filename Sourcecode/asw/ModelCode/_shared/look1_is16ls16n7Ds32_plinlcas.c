/*
 * File: look1_is16ls16n7Ds32_plinlcas.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.1559
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Oct 25 16:56:56 2023
 */

#include "rtwtypes.h"
//#include "asr_s32.h"
#include "look1_is16ls16n7Ds32_plinlcas.h"

#define asr_s32(X,Y)  ((X) >> (Y))

Int16 look1_is16ls16n7Ds32_plinlcas(Int16 u0, const Int16 bp0[], const
  Int16 table[], UInt32 prevIndex[], UInt32 maxIndex)
{
  Int16 y;
  Int16 frac;
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

    frac = (Int16)((UInt32)((((UInt32)((UInt16)((Int32)(((Int32)u0)
      - ((Int32)bp0[bpIdx]))))) << 7) / ((UInt32)((UInt16)((Int32)
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
    y = (Int16)(((Int16)asr_s32((((Int32)table[bpIdx + 1U]) - ((Int32)
      table[bpIdx])) * ((Int32)frac), 7U)) + table[bpIdx]);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

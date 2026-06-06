/*
 * File: look2_iu16s16bs16n2s16_kvzwx0z5.c
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 5.17
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 23 14:28:40 2023
 */

#include "rtwtypes.h"
#include "look2_iu16s16bs16n2s16_kvzwx0z5.h"

#define asr_s32(X,Y)  ((X) >> (Y))

Int16 look2_iu16s16bs16n2s16_kvzwx0z5(UInt16 u0, Int16 u1, const Int16
  bp0[], const Int16 bp1[], const Int16 table[], UInt32 prevIndex[], const
  UInt32 maxIndex[], UInt32 stride)
{
  Int32 fractions[2];
  Int32 frac;
  UInt32 bpIndices[2];
  UInt32 bpIdx;
  UInt32 offset_1d;
  Int16 uCast;
  Int16 y;

  /* Column-major Lookup 2-D
     Canonical function name: look2_iu16s16bs16n2s16ls32n10ts16Ds32ds32_plinlcas
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
  if (((Int32)u0) > 8191) {
    uCast = MAX_int16_T;
  } else {
    uCast = (Int16)(((Int16)u0) * 4);
  }

  if (((Int32)((UInt32)(((UInt32)u0) << 2ULL))) < ((Int32)bp0[0U])) {
    bpIdx = 0U;
    frac = 0;
  } else if (uCast < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; uCast < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (Int32)((uint64_T)((((uint64_T)((UInt32)((((UInt32)u0) << 2ULL)
      - ((UInt32)bp0[bpIdx])))) << 10ULL) / ((uint64_T)((UInt16)((Int32)
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

    uCast = bp1[bpIdx];
    frac = (Int32)((UInt32)((((UInt32)((UInt16)((Int32)(((Int32)u1)
      - ((Int32)uCast))))) << 10ULL) / ((UInt32)((UInt16)((Int32)
      (((Int32)bp1[bpIdx + 1U]) - ((Int32)uCast)))))));
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
    uCast = table[offset_1d];
    y = (Int16)(((Int16)asr_s32((((Int32)table[offset_1d + 1U]) -
      ((Int32)uCast)) * fractions[0U], 10U)) + uCast);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      uCast = table[bpIdx];
    } else {
      uCast = table[bpIdx];
      uCast += (Int16)asr_s32((((Int32)table[bpIdx + 1U]) - ((Int32)uCast))
        * fractions[0U], 10U);
    }

    y += (Int16)asr_s32((((Int32)uCast) - ((Int32)y)) * frac, 10U);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

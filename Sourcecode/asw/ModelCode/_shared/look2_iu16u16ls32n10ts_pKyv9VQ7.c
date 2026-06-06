/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look2_iu16u16ls32n10ts_pKyv9VQ7.c
 *
 * Code generated for Simulink model 'TAS_DataConv'.
 *
 * Model version                  : 9.3
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed May 31 09:19:37 2023
 */

#include "look2_iu16u16ls32n10ts_pKyv9VQ7.h"
#include "rtwtypes.h"

sint16 look2_iu16u16ls32n10ts_pKyv9VQ7(uint16 u0, uint16 u1, const uint16
  bp0[], const uint16 bp1[], const sint16 table[], uint32 prevIndex[],
  const uint32 maxIndex[], uint32 stride)
{
  sint32 fractions[2];
  sint32 frac;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 offset_1d;
  sint16 y;
  sint16 yL_0d0;
  uint16 bpLeftVar;

  /* Column-major Lookup 2-D
     Canonical function name: look2_iu16u16ls32n10ts16Ds32ds32_plinlcas
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
    frac = (sint32)(((uint32)(uint16)((uint32)u0 - bpLeftVar) << 10) /
                     (uint16)((uint32)bp0[bpIdx + 1U] - bpLeftVar));
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

    bpLeftVar = bp1[bpIdx];
    frac = (sint32)(((uint32)(uint16)((uint32)u1 - bpLeftVar) << 10) /
                     (uint16)((uint32)bp1[bpIdx + 1U] - bpLeftVar));
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
  offset_1d = bpIdx * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    yL_0d0 = table[offset_1d];
    y = (sint16)((sint16)(((table[offset_1d + 1U] - yL_0d0) * fractions[0U]) >>
      10) + yL_0d0);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (sint16)(((table[bpIdx + 1U] - yL_0d0) * fractions[0U]) >> 10);
    }

    y += (sint16)(((yL_0d0 - y) * frac) >> 10);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

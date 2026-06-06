
/*  File: look2_is16u16bu16n2s16_xGSEINzy.c

  Code generated for Simulink model 'BSS_BasicAssist'.

  Model version                  : 9.17
  Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
  C/C++ source code generated on : Tue May 30 16:33:22 2023
 */

#include "look2_is16u16bu16n2s16_xGSEINzy.h"
#include "rtwtypes.h"

sint16 look2_is16u16bu16n2s16_xGSEINzy(sint16 u0, uint16 u1, const uint16
  bp0[], const sint16 bp1[], const sint16 table[], uint32 prevIndex[], const
  uint32 maxIndex[], uint32 stride)
{
  sint32 fractions[2];
  sint32 frac;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 offset_1d;
  sint16 uCast;
  sint16 y;
  uint16 uCast_0;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16u16bu16n2s16p2ls32n10ts16Ds32ds32_plinlcas
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
  if (u0 <= 0) {
    uCast_0 = 0U;
  } else if (u0 > 16383) {
    uCast_0 = MAX_uint16_T;
  } else {
    uCast_0 = (uint16)((uint16)u0 << 2);
  }

  if ((u0 << 2) < bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (uCast_0 < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; uCast_0 < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast_0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (sint32)(((uint64)(((uint32)u0 << 2) - bp0[bpIdx]) << 10) /
                     (uint16)((uint32)bp0[bpIdx + 1U] - bp0[bpIdx]));
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
  uCast = (sint16)((uint32)u1 >> 2);
  if (u1 < (bp1[0U] << 2)) {
    bpIdx = 0U;
    frac = 0;
  } else if (uCast < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[1U]; uCast < bp1[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (sint32)(((uint64)(u1 - ((uint32)bp1[bpIdx] << 2)) << 8) /
                     (uint16)(bp1[bpIdx + 1U] - bp1[bpIdx]));
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
    uCast = table[offset_1d];
    y = (sint16)((sint16)(((table[offset_1d + 1U] - uCast) * fractions[0U]) >>
      10) + uCast);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      uCast = table[bpIdx];
    } else {
      uCast = table[bpIdx];
      uCast += (sint16)(((table[bpIdx + 1U] - uCast) * fractions[0U]) >> 10);
    }

    y += (sint16)(((uCast - y) * frac) >> 10);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

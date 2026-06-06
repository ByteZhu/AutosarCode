/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look1_is16bs16p3ls32n1_oF6TzIsr.c
 *
 * Code generated for Simulink model 'BSS_BasicAssist'.
 *
 * Model version                  : 9.17
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue May 30 16:33:22 2023
 */

#include "look1_is16bs16p3ls32n1_oF6TzIsr.h"
#include "rtwtypes.h"

sint16 look1_is16bs16p3ls32n1_oF6TzIsr(sint16 u0, const sint16 bp0[], const
  sint16 table[], uint32 prevIndex[], uint32 maxIndex)
{
  sint32 frac;
  uint32 bpIdx;
  sint16 uCast;
  sint16 y;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16bs16p3ls32n10Ds32_plinlcas
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
  uCast = (sint16)(u0 >> 3);
  if (u0 < (bp0[0U] << 3)) {
    bpIdx = 0U;
    frac = 0;
  } else if (uCast < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; uCast < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (sint32)(((uint64)((uint32)u0 - ((uint32)bp0[bpIdx] << 3)) <<
                      7) / (uint16)(bp0[bpIdx + 1U] - bp0[bpIdx]));
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
    uCast = table[bpIdx];
    y = (sint16)((sint16)(((table[bpIdx + 1U] - uCast) * frac) >> 10) + uCast);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

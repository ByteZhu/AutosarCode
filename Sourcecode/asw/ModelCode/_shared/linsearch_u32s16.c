/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: linsearch_u32s16.c
 *
 * Code generated for Simulink model 'FrictionComp_Study_1'.
 *
 * Model version                  : 9.58
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jun  4 11:01:02 2024
 */

#include "linsearch_u32s16.h"
#include "rtwtypes.h"

UInt32 linsearch_u32s16(Int16 u, const Int16 bp[], UInt32 startIndex)
{
  UInt32 bpIndex;

  /* Linear Search */
  for (bpIndex = startIndex; u < bp[bpIndex]; bpIndex--) {
  }

  while (u >= bp[bpIndex + 1U]) {
    bpIndex++;
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

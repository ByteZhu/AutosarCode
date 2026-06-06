/*
 * File: asr_s32.c
 *
 * Code generated for Simulink model 'AngleOffsetComp'.
 *
 * Model version                  : 1.1150
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:52:33 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"

Int32 asr_s32(Int32 u, UInt32 n)
{
  Int32 y;
  if (u >= 0) {
    y = (Int32)((UInt32)(((UInt32)u) >> n));
  } else {
    y = (-((Int32)((UInt32)(((UInt32)((Int32)(-1 - u))) >> n)))) - 1;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

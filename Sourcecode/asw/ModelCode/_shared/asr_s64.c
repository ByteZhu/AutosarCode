/*
 * File: asr_s64.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.1420
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Oct 20 16:25:13 2022
 */

#include "rtwtypes.h"
#include "asr_s64.h"

int64_T asr_s64(int64_T u, UInt32 n)
{
  int64_T y;
  if (u >= 0LL) {
    y = (int64_T)((uint64_T)(((uint64_T)u) >> n));
  } else {
    y = (-((int64_T)((uint64_T)(((uint64_T)((int64_T)(-1LL - u))) >> n)))) - 1LL;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

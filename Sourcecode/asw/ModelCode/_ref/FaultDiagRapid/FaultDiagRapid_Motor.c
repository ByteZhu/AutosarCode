/*
 * File: FaultDiagRapid_Motor.c
 *
 * Code generated for Simulink model 'FaultDiagRapid'.
 *
 * Model version                  : 1.1294
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:32:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FaultDiagRapid_Motor.h"

/* Include model header file for global data */
#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"

/* Named constants for Chart: '<S119>/OutputCurrentDiag1' */
#define FaultDi_IN_NO_ACTIVE_CHILD_ocrs ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_jswk    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_lqgy   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_pk4t  ((UInt8)2U)
#define FaultDiagRapid_IN_Wait_para    ((UInt8)2U)

/* Named constants for Chart: '<S119>/OutputCurrentDiag2' */
#define FaultDi_IN_NO_ACTIVE_CHILD_fxrs ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_harp    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_jbo0   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_oidg  ((UInt8)2U)
#define FaultDiagRapid_IN_Wait_px5y    ((UInt8)2U)

/* Named constants for Chart: '<S130>/OverCurrentDiag1' */
#define FaultDi_IN_NO_ACTIVE_CHILD_hnew ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_mgbi    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_ikdb   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_bn4k  ((UInt8)2U)
#define FaultDiagRapid_IN_Wait_hb3p    ((UInt8)2U)

/* Named constants for Chart: '<S130>/OverCurrentDiag2' */
#define FaultDi_IN_NO_ACTIVE_CHILD_cddj ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_epdr    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_k1qc   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_a2rq  ((UInt8)2U)
#define FaultDiagRapid_IN_Wait_f3sb    ((UInt8)2U)

/* Named constants for Chart: '<S159>/PredriverDiag1' */
#define FaultDi_IN_NO_ACTIVE_CHILD_flmt ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_cw0s    ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_i0yc    ((UInt8)2U)

/* Named constants for Chart: '<S159>/PredriverDiag2' */
#define FaultDi_IN_NO_ACTIVE_CHILD_pxgv ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_di2b    ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_bnwi    ((UInt8)2U)

/* System reset for atomic system: '<S119>/OutputCurrentDiag1' */
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

void FaultD_OutputCurrentDiag1_Reset(void)
{
  uint8 i = 0;
  FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag_cepr =
    FaultDi_IN_NO_ACTIVE_CHILD_ocrs;
  FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_active_c13_FaultDiagRapid
    = 0;
  FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c13_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_ocrs;
  FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin_iksw = 0U;

#if 0
  memset(&FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[0], 0, 25U *
         (sizeof(Int32)));
  memset(&FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[0], 0, 25U *
         (sizeof(Int32)));
#else
  for(i = 0; i < 25; i++)
  {
    FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[i] = 0;
    FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[i] = 0;
  }
#endif
}

#endif

/* Output and update for atomic system: '<S119>/OutputCurrentDiag1' */
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

void FaultDiagRap_OutputCurrentDiag1(void)
{
  UInt16 MOC_TimeWin;
  Int32 record_sum1;
  Int32 record_sum2;
  Int32 record_diff1_bnq3_tmp;

  /* Chart: '<S119>/OutputCurrentDiag1' incorporates:
   *  DataStoreRead: '<S125>/Data Store Read'
   *  DataStoreRead: '<S126>/Data Store Read'
   *  DataTypeConversion: '<S125>/Data Type Conversion2'
   *  Product: '<S125>/Product'
   *  Selector: '<S125>/Selector'
   *  Selector: '<S126>/Selector'
   */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1 */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1 */
  if (((UInt32)
       FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_active_c13_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1 */
    FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_active_c13_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1 */
    /* Transition: '<S123>:1378' */
    FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c13_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_para;
  } else if (((UInt32)
              FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c13_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_jswk) {
    /* During 'Diag': '<S123>:1360' */
    if ((!FaultDiagRapidrtDW.precondover1) || (!Fv_SystemTransferState)) {
      /* Transition: '<S123>:1376' */
      /* Exit Internal 'Diag': '<S123>:1360' */
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag_cepr =
        FaultDi_IN_NO_ACTIVE_CHILD_ocrs;
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c13_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_para;
    } else {
      /* Transition: '<S123>:1429' */
      /* Transition: '<S123>:1431' */
      MOC_TimeWin = (UInt16)((Int32)(((Int32)((UInt16)MACRO_MOTOR_CHECKTIME)) -
        1));
      record_sum1 = 0;
      record_sum2 = 0;
      while (((Int32)MOC_TimeWin) > 0) {
        /* Transition: '<S123>:1433' */
        /* Transition: '<S123>:1435' */
        record_diff1_bnq3_tmp = ((Int32)MOC_TimeWin) - 1;
        FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[MOC_TimeWin] =
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[record_diff1_bnq3_tmp];
        record_sum1 +=
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[MOC_TimeWin];
        FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[MOC_TimeWin] =
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[record_diff1_bnq3_tmp];
        record_sum2 +=
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[MOC_TimeWin];
        MOC_TimeWin = (UInt16)record_diff1_bnq3_tmp;

        /* Transition: '<S123>:1437' */
        /* Transition: '<S123>:1440' */
      }

      /* Transition: '<S123>:1439' */
      /* Transition: '<S123>:1442' */
      FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[0] =
        FaultDiagRapidrtDW.OutputCurrentCheck.qdiff1;
      record_sum1 += FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1_bnq3[0];
      FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[0] =
        FaultDiagRapidrtDW.OutputCurrentCheck.ddiff1;
      record_sum2 += FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2_muqi[0];
      record_sum1 /= (Int32)((UInt16)MACRO_MOTOR_CHECKTIME);
      record_sum2 /= (Int32)((UInt16)MACRO_MOTOR_CHECKTIME);
      if (record_sum1 < 0) {
        /* Transition: '<S123>:1444' */
        /* Transition: '<S123>:1446' */
        record_sum1 = -record_sum1;

        /* Transition: '<S123>:1449' */
      } else {
        /* Transition: '<S123>:1448' */
      }

      /* Transition: '<S123>:1451' */
      if (record_sum2 < 0) {
        /* Transition: '<S123>:1458' */
        /* Transition: '<S123>:1453' */
        record_sum2 = -record_sum2;

        /* Transition: '<S123>:1456' */
      } else {
        /* Transition: '<S123>:1455' */
      }

      if (((UInt32)
           FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag_cepr) ==
          FaultDiagRapid_IN_Fault_lqgy) {
        /* During 'Fault': '<S123>:1364' */
        if ((record_sum1 <= FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis1) &&
            (record_sum2 <= FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis1)) {
          /* Transition: '<S123>:1363' */
          FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag_cepr =
            FaultDiagRapid_IN_Normal_pk4t;
        } else {
          /* Transition: '<S123>:1385' */
          if (((Int32)FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin_iksw) >
              0) {
            /* Transition: '<S123>:1386' */
            /* Transition: '<S123>:1389' */
            FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin_iksw = (UInt16)
              ((Int32)(((Int32)
                        FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin_iksw)
                       - 1));

            /* Transition: '<S123>:1391' */
          } else {
            /* Outputs for Function Call SubSystem: '<S123>/DTC_Ctrl_Enabled' */
            /* Selector: '<S125>/Selector' */
            /* Transition: '<S123>:1387' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S123>:1489' */
            record_sum2 = DTC_MOTORcheck_Output;
            Fv_ErrDiagStatus[(record_sum2)] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[record_sum2].
              Enabled) * ((UInt32)FailureDiag_RegErr));

            /* End of Outputs for SubSystem: '<S123>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S123>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S123>:1485' */
            Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 4,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MOTORcheck_Output].Enabled);

            /* End of Outputs for SubSystem: '<S123>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S123>:1370' */
        if ((record_sum1 > FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis1) ||
            (record_sum2 > FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis1)) {
          /* Transition: '<S123>:1362' */
          FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag_cepr =
            FaultDiagRapid_IN_Fault_lqgy;

          /* Entry 'Fault': '<S123>:1364' */
          FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin_iksw = ((UInt16)
            MACRO_MOTOR_DIFFTIME);
        }
      }
    }
  } else {
    /* During 'Wait': '<S123>:1359' */
    if ((FaultDiagRapidrtDW.precondover1) && (Fv_SystemTransferState)) {
      /* Transition: '<S123>:1377' */
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c13_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_jswk;

      /* Entry Internal 'Diag': '<S123>:1360' */
      /* Transition: '<S123>:1361' */
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag_cepr =
        FaultDiagRapid_IN_Normal_pk4t;
    }
  }

  /* End of Chart: '<S119>/OutputCurrentDiag1' */
}

#endif

/* System reset for atomic system: '<S119>/OutputCurrentDiag2' */
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

void FaultD_OutputCurrentDiag2_Reset(void)
{
  uint8 i = 0;
  FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag =
    FaultDi_IN_NO_ACTIVE_CHILD_fxrs;
  FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_active_c14_FaultDiagRapid
    = 0;
  FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c14_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_fxrs;
  FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin = 0U;
#if 0
  memset(&FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[0], 0, 25U *
         (sizeof(Int32)));
  memset(&FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[0], 0, 25U *
         (sizeof(Int32)));
#else
  for(i = 0; i < 25; i++)
  {
    FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[i] = 0;
    FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[i] = 0;
  }
#endif
}

#endif

/* Output and update for atomic system: '<S119>/OutputCurrentDiag2' */
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

void FaultDiagRap_OutputCurrentDiag2(void)
{
  UInt16 MOC_TimeWin;
  Int32 record_sum1;
  Int32 record_sum2;
  Int32 record_diff1_tmp;

  /* Chart: '<S119>/OutputCurrentDiag2' incorporates:
   *  DataStoreRead: '<S127>/Data Store Read'
   *  DataStoreRead: '<S128>/Data Store Read'
   *  DataTypeConversion: '<S127>/Data Type Conversion2'
   *  Product: '<S127>/Product'
   *  Selector: '<S127>/Selector'
   *  Selector: '<S128>/Selector'
   */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2 */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2 */
  if (((UInt32)
       FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_active_c14_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2 */
    FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_active_c14_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2 */
    /* Transition: '<S124>:1378' */
    FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c14_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_px5y;
  } else if (((UInt32)
              FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c14_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_harp) {
    /* During 'Diag': '<S124>:1360' */
    if ((!FaultDiagRapidrtDW.precondover2) || (!Fv_SystemTransferState)) {
      /* Transition: '<S124>:1376' */
      /* Exit Internal 'Diag': '<S124>:1360' */
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag =
        FaultDi_IN_NO_ACTIVE_CHILD_fxrs;
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c14_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_px5y;
    } else {
      /* Transition: '<S124>:1429' */
      /* Transition: '<S124>:1431' */
      MOC_TimeWin = (UInt16)((Int32)(((Int32)((UInt16)MACRO_MOTOR_CHECKTIME)) -
        1));
      record_sum1 = 0;
      record_sum2 = 0;
      while (((Int32)MOC_TimeWin) > 0) {
        /* Transition: '<S124>:1433' */
        /* Transition: '<S124>:1435' */
        record_diff1_tmp = ((Int32)MOC_TimeWin) - 1;
        FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[MOC_TimeWin] =
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[record_diff1_tmp];
        record_sum1 +=
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[MOC_TimeWin];
        FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[MOC_TimeWin] =
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[record_diff1_tmp];
        record_sum2 +=
          FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[MOC_TimeWin];
        MOC_TimeWin = (UInt16)record_diff1_tmp;

        /* Transition: '<S124>:1437' */
        /* Transition: '<S124>:1440' */
      }

      /* Transition: '<S124>:1439' */
      /* Transition: '<S124>:1442' */
      FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[0] =
        FaultDiagRapidrtDW.OutputCurrentCheck.qdiff2;
      record_sum1 += FaultDiagRapidrtDW.OutputCurrentCheck.record_diff1[0];
      FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[0] =
        FaultDiagRapidrtDW.OutputCurrentCheck.ddiff2;
      record_sum2 += FaultDiagRapidrtDW.OutputCurrentCheck.record_diff2[0];
      record_sum1 /= (Int32)((UInt16)MACRO_MOTOR_CHECKTIME);
      record_sum2 /= (Int32)((UInt16)MACRO_MOTOR_CHECKTIME);
      if (record_sum1 < 0) {
        /* Transition: '<S124>:1444' */
        /* Transition: '<S124>:1446' */
        record_sum1 = -record_sum1;

        /* Transition: '<S124>:1449' */
      } else {
        /* Transition: '<S124>:1448' */
      }

      /* Transition: '<S124>:1451' */
      if (record_sum2 < 0) {
        /* Transition: '<S124>:1458' */
        /* Transition: '<S124>:1453' */
        record_sum2 = -record_sum2;

        /* Transition: '<S124>:1456' */
      } else {
        /* Transition: '<S124>:1455' */
      }

      if (((UInt32)FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag) ==
          FaultDiagRapid_IN_Fault_jbo0) {
        /* During 'Fault': '<S124>:1364' */
        if ((record_sum1 <= FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis2) &&
            (record_sum2 <= FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis2)) {
          /* Transition: '<S124>:1363' */
          FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Normal_oidg;
        } else {
          /* Transition: '<S124>:1385' */
          if (((Int32)FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin) > 0) {
            /* Transition: '<S124>:1386' */
            /* Transition: '<S124>:1389' */
            FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin = (UInt16)((Int32)
              (((Int32)FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin) - 1));

            /* Transition: '<S124>:1391' */
          } else {
            /* Outputs for Function Call SubSystem: '<S124>/DTC_Ctrl_Enabled' */
            /* Selector: '<S127>/Selector' */
            /* Transition: '<S124>:1387' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S124>:1489' */
            record_sum2 = DTC_MOTORcheck_Output;
            Fv_ErrDiagStatus[(record_sum2)] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[record_sum2].
              Enabled) * ((UInt32)FailureDiag_RegErr));

            /* End of Outputs for SubSystem: '<S124>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S124>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S124>:1485' */
            Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 5,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MOTORcheck_Output].Enabled);

            /* End of Outputs for SubSystem: '<S124>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S124>:1370' */
        if ((record_sum1 > FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis2) ||
            (record_sum2 > FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis2)) {
          /* Transition: '<S124>:1362' */
          FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Fault_jbo0;

          /* Entry 'Fault': '<S124>:1364' */
          FaultDiagRapidrtDW.OutputCurrentCheck.MOO_TimeWin = ((UInt16)
            MACRO_MOTOR_DIFFTIME);
        }
      }
    }
  } else {
    /* During 'Wait': '<S124>:1359' */
    if ((FaultDiagRapidrtDW.precondover2) && (Fv_SystemTransferState)) {
      /* Transition: '<S124>:1377' */
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_c14_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_harp;

      /* Entry Internal 'Diag': '<S124>:1360' */
      /* Transition: '<S124>:1361' */
      FaultDiagRapidrtDW.OutputCurrentCheck.bitsForTID0.is_Diag =
        FaultDiagRapid_IN_Normal_oidg;
    }
  }

  /* End of Chart: '<S119>/OutputCurrentDiag2' */
}

#endif

/* System reset for atomic system: '<S85>/MotorCheck_OutputCurrent' */
void MotorCheck_OutputCurrent_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S115>/DiagRapid_MotorOutputCurrent_Check' */
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

  /* Reset conditions for atomic system: '<S118>/OutputCurrentCheck' */

  /* SystemReset for Chart: '<S119>/OutputCurrentDiag1' */
  FaultD_OutputCurrentDiag1_Reset();

  /* SystemReset for Chart: '<S119>/OutputCurrentDiag2' */
  FaultD_OutputCurrentDiag2_Reset();

#endif

  /* End of SystemReset for SubSystem: '<S115>/DiagRapid_MotorOutputCurrent_Check' */
}

/* Output and update for atomic system: '<S85>/MotorCheck_OutputCurrent' */
void FaultD_MotorCheck_OutputCurrent(void)
{
  /* Outputs for Atomic SubSystem: '<S115>/DiagRapid_MotorOutputCurrent_Check' */
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

  /* Output and update for atomic system: '<S118>/OutputCurrentCheck' */
  {
    Int32 rtb_Subtract1;
    UInt16 tmp_a;

    /* Outputs for Atomic SubSystem: '<S119>/OutputCurrentCond1' */
    /* Abs: '<S121>/Abs5' incorporates:
     *  DataStoreRead: '<S121>/Data Store Read12'
     */
    if (Fv_MotorCurrent_Qaim1 < 0) {
      tmp_a = (UInt16)((Int32)(-Fv_MotorCurrent_Qaim1));
    } else {
      tmp_a = (UInt16)Fv_MotorCurrent_Qaim1;
    }

    /* End of Abs: '<S121>/Abs5' */

    /* Product: '<S121>/Product' incorporates:
     *  Constant: '<S121>/Constant'
     */
    rtb_Subtract1 = (Int32)((UInt32)((((UInt32)((UInt16)MACRO_MOTOR_OUTPUTPER)) *
      ((UInt32)tmp_a)) >> 7));

    /* MinMax: '<S121>/MinMax' incorporates:
     *  Constant: '<S121>/Constant2'
     */
    if (MACRO_MOTOR_OUTPUTMAX > rtb_Subtract1) {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis1 = MACRO_MOTOR_OUTPUTMAX;
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis1 = rtb_Subtract1;
    }

    /* End of MinMax: '<S121>/MinMax' */

    /* Sum: '<S121>/Subtract' incorporates:
     *  DataStoreRead: '<S121>/Data Store Read12'
     *  DataStoreRead: '<S121>/Data Store Read13'
     */
    rtb_Subtract1 = Fv_MotorCurrent_Qaim1 - Fv_MotorCurrent_Qact1;

    /* Saturate: '<S121>/Saturation1' */
    if (rtb_Subtract1 > 12800) {
      FaultDiagRapidrtDW.OutputCurrentCheck.qdiff1 = 12800;
    } else if (rtb_Subtract1 < (-12800)) {
      FaultDiagRapidrtDW.OutputCurrentCheck.qdiff1 = (-12800);
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.qdiff1 = rtb_Subtract1;
    }

    /* End of Saturate: '<S121>/Saturation1' */

    /* Abs: '<S121>/Abs3' incorporates:
     *  DataStoreRead: '<S121>/Data Store Read14'
     */
    if (Fv_MotorCurrent_Daim1 < 0) {
      tmp_a = (UInt16)((Int32)(-Fv_MotorCurrent_Daim1));
    } else {
      tmp_a = (UInt16)Fv_MotorCurrent_Daim1;
    }

    /* End of Abs: '<S121>/Abs3' */

    /* Product: '<S121>/Product1' incorporates:
     *  Constant: '<S121>/Constant1'
     */
    rtb_Subtract1 = (Int32)((UInt32)((((UInt32)((UInt16)MACRO_MOTOR_OUTPUTPER)) *
      ((UInt32)tmp_a)) >> 7));

    /* MinMax: '<S121>/MinMax1' incorporates:
     *  Constant: '<S121>/Constant3'
     */
    if (MACRO_MOTOR_OUTPUTMAX > rtb_Subtract1) {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis1 = MACRO_MOTOR_OUTPUTMAX;
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis1 = rtb_Subtract1;
    }

    /* End of MinMax: '<S121>/MinMax1' */

    /* Sum: '<S121>/Subtract1' incorporates:
     *  DataStoreRead: '<S121>/Data Store Read14'
     *  DataStoreRead: '<S121>/Data Store Read15'
     */
    rtb_Subtract1 = Fv_MotorCurrent_Daim1 - Fv_MotorCurrent_Dact1;

    /* Saturate: '<S121>/Saturation' */
    if (rtb_Subtract1 > 12800) {
      FaultDiagRapidrtDW.OutputCurrentCheck.ddiff1 = 12800;
    } else if (rtb_Subtract1 < (-12800)) {
      FaultDiagRapidrtDW.OutputCurrentCheck.ddiff1 = (-12800);
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.ddiff1 = rtb_Subtract1;
    }

    /* End of Saturate: '<S121>/Saturation' */
    /* End of Outputs for SubSystem: '<S119>/OutputCurrentCond1' */

    /* Chart: '<S119>/OutputCurrentDiag1' */
    FaultDiagRap_OutputCurrentDiag1();

    /* Outputs for Atomic SubSystem: '<S119>/OutputCurrentCond2' */
    /* Abs: '<S122>/Abs5' incorporates:
     *  DataStoreRead: '<S122>/Data Store Read12'
     */
    if (Fv_MotorCurrent_Qaim2 < 0) {
      tmp_a = (UInt16)((Int32)(-Fv_MotorCurrent_Qaim2));
    } else {
      tmp_a = (UInt16)Fv_MotorCurrent_Qaim2;
    }

    /* End of Abs: '<S122>/Abs5' */

    /* Product: '<S122>/Product' incorporates:
     *  Constant: '<S122>/Constant'
     */
    rtb_Subtract1 = (Int32)((UInt32)((((UInt32)((UInt16)MACRO_MOTOR_OUTPUTPER)) *
      ((UInt32)tmp_a)) >> 7));

    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S122>/Constant2'
     */
    if (MACRO_MOTOR_OUTPUTMAX > rtb_Subtract1) {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis2 = MACRO_MOTOR_OUTPUTMAX;
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_qaxis2 = rtb_Subtract1;
    }

    /* End of MinMax: '<S122>/MinMax' */

    /* Sum: '<S122>/Subtract' incorporates:
     *  DataStoreRead: '<S122>/Data Store Read12'
     *  DataStoreRead: '<S122>/Data Store Read13'
     */
    rtb_Subtract1 = Fv_MotorCurrent_Qaim2 - Fv_MotorCurrent_Qact2;

    /* Saturate: '<S122>/Saturation1' */
    if (rtb_Subtract1 > 12800) {
      FaultDiagRapidrtDW.OutputCurrentCheck.qdiff2 = 12800;
    } else if (rtb_Subtract1 < (-12800)) {
      FaultDiagRapidrtDW.OutputCurrentCheck.qdiff2 = (-12800);
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.qdiff2 = rtb_Subtract1;
    }

    /* End of Saturate: '<S122>/Saturation1' */

    /* Abs: '<S122>/Abs3' incorporates:
     *  DataStoreRead: '<S122>/Data Store Read14'
     */
    if (Fv_MotorCurrent_Daim2 < 0) {
      tmp_a = (UInt16)((Int32)(-Fv_MotorCurrent_Daim2));
    } else {
      tmp_a = (UInt16)Fv_MotorCurrent_Daim2;
    }

    /* End of Abs: '<S122>/Abs3' */

    /* Product: '<S122>/Product1' incorporates:
     *  Constant: '<S122>/Constant1'
     */
    rtb_Subtract1 = (Int32)((UInt32)((((UInt32)((UInt16)MACRO_MOTOR_OUTPUTPER)) *
      ((UInt32)tmp_a)) >> 7));

    /* MinMax: '<S122>/MinMax1' incorporates:
     *  Constant: '<S122>/Constant3'
     */
    if (MACRO_MOTOR_OUTPUTMAX > rtb_Subtract1) {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis2 = MACRO_MOTOR_OUTPUTMAX;
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.max_daxis2 = rtb_Subtract1;
    }

    /* End of MinMax: '<S122>/MinMax1' */

    /* Sum: '<S122>/Subtract1' incorporates:
     *  DataStoreRead: '<S122>/Data Store Read14'
     *  DataStoreRead: '<S122>/Data Store Read15'
     */
    rtb_Subtract1 = Fv_MotorCurrent_Daim2 - Fv_MotorCurrent_Dact2;

    /* Saturate: '<S122>/Saturation' */
    if (rtb_Subtract1 > 12800) {
      FaultDiagRapidrtDW.OutputCurrentCheck.ddiff2 = 12800;
    } else if (rtb_Subtract1 < (-12800)) {
      FaultDiagRapidrtDW.OutputCurrentCheck.ddiff2 = (-12800);
    } else {
      FaultDiagRapidrtDW.OutputCurrentCheck.ddiff2 = rtb_Subtract1;
    }

    /* End of Saturate: '<S122>/Saturation' */
    /* End of Outputs for SubSystem: '<S119>/OutputCurrentCond2' */

    /* Chart: '<S119>/OutputCurrentDiag2' */
    FaultDiagRap_OutputCurrentDiag2();
  }

#endif

  /* End of Outputs for SubSystem: '<S115>/DiagRapid_MotorOutputCurrent_Check' */
}

/* System reset for atomic system: '<S130>/OverCurrentDiag1' */
#if DIAGDIS_MOTOROVERCURRENTREG == 0

void FaultDia_OverCurrentDiag1_Reset(void)
{
  FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag_g0ku =
    FaultDi_IN_NO_ACTIVE_CHILD_hnew;
  FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_active_c11_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c11_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_hnew;
  FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin_dhmt = 0U;
}

#endif

/* Output and update for atomic system: '<S130>/OverCurrentDiag1' */
#if DIAGDIS_MOTOROVERCURRENTREG == 0

void FaultDiagRapid_OverCurrentDiag1(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S130>/OverCurrentDiag1' incorporates:
   *  DataStoreRead: '<S148>/Data Store Read'
   *  DataStoreRead: '<S149>/Data Store Read'
   *  DataTypeConversion: '<S148>/Data Type Conversion2'
   *  Product: '<S148>/Product'
   *  Selector: '<S148>/Selector'
   *  Selector: '<S149>/Selector'
   */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1 */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1 */
  if (((UInt32)
       FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_active_c11_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1 */
    FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_active_c11_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1 */
    /* Transition: '<S134>:1378' */
    FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c11_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_hb3p;
  } else if (((UInt32)
              FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c11_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_mgbi) {
    /* During 'Diag': '<S134>:1360' */
    if (!FaultDiagRapidrtDW.precondover1) {
      /* Transition: '<S134>:1376' */
      /* Exit Internal 'Diag': '<S134>:1360' */
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag_g0ku =
        FaultDi_IN_NO_ACTIVE_CHILD_hnew;
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c11_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_hb3p;
    } else if (((UInt32)
                FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag_g0ku) ==
               FaultDiagRapid_IN_Fault_ikdb) {
      /* During 'Fault': '<S134>:1364' */
      if (!FaultDiagRapidrtDW.OverCurrentCheck.overcurrent2) {
        /* Transition: '<S134>:1363' */
        FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag_g0ku =
          FaultDiagRapid_IN_Normal_bn4k;
      } else {
        /* Transition: '<S134>:1385' */
        if (((Int32)FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin_dhmt) > 0) {
          /* Transition: '<S134>:1386' */
          /* Transition: '<S134>:1389' */
          FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin_dhmt = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin_dhmt) - 1));

          /* Transition: '<S134>:1391' */
        } else {
          /* Outputs for Function Call SubSystem: '<S134>/DTC_Ctrl_Enabled' */
          /* Selector: '<S148>/Selector' */
          /* Transition: '<S134>:1387' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S134>:1410' */
          Fv_ErrDiagStatus_tmp = DTC_MOTORcheck_OverCurrent;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S134>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S134>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S134>:1406' */
          Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 2,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_MOTORcheck_OverCurrent].Enabled);

          /* End of Outputs for SubSystem: '<S134>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S134>:1370' */
      if (FaultDiagRapidrtDW.OverCurrentCheck.overcurrent2) {
        /* Transition: '<S134>:1362' */
        FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag_g0ku =
          FaultDiagRapid_IN_Fault_ikdb;

        /* Entry 'Fault': '<S134>:1364' */
        FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin_dhmt = ((UInt16)
          MACRO_MOTOR_OVERCURRENT_CHECKTIME);
      }
    }
  } else {
    /* During 'Wait': '<S134>:1359' */
    if (FaultDiagRapidrtDW.precondover1) {
      /* Transition: '<S134>:1377' */
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c11_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_mgbi;

      /* Entry Internal 'Diag': '<S134>:1360' */
      /* Transition: '<S134>:1361' */
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag_g0ku =
        FaultDiagRapid_IN_Normal_bn4k;
    }
  }

  /* End of Chart: '<S130>/OverCurrentDiag1' */
}

#endif

/* System reset for atomic system: '<S130>/OverCurrentDiag2' */
#if DIAGDIS_MOTOROVERCURRENTREG == 0

void FaultDia_OverCurrentDiag2_Reset(void)
{
  FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag =
    FaultDi_IN_NO_ACTIVE_CHILD_cddj;
  FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_active_c12_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c12_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_cddj;
  FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin = 0U;
}

#endif

/* Output and update for atomic system: '<S130>/OverCurrentDiag2' */
#if DIAGDIS_MOTOROVERCURRENTREG == 0

void FaultDiagRapid_OverCurrentDiag2(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S130>/OverCurrentDiag2' incorporates:
   *  DataStoreRead: '<S150>/Data Store Read'
   *  DataStoreRead: '<S151>/Data Store Read'
   *  DataTypeConversion: '<S150>/Data Type Conversion2'
   *  Product: '<S150>/Product'
   *  Selector: '<S150>/Selector'
   *  Selector: '<S151>/Selector'
   */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2 */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2 */
  if (((UInt32)
       FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_active_c12_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2 */
    FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_active_c12_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2 */
    /* Transition: '<S135>:1378' */
    FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c12_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_f3sb;
  } else if (((UInt32)
              FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c12_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_epdr) {
    /* During 'Diag': '<S135>:1360' */
    if (!FaultDiagRapidrtDW.precondover2) {
      /* Transition: '<S135>:1376' */
      /* Exit Internal 'Diag': '<S135>:1360' */
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag =
        FaultDi_IN_NO_ACTIVE_CHILD_cddj;
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c12_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_f3sb;
    } else if (((UInt32)FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag)
               == FaultDiagRapid_IN_Fault_k1qc) {
      /* During 'Fault': '<S135>:1364' */
      if (!FaultDiagRapidrtDW.OverCurrentCheck.overcurrent2) {
        /* Transition: '<S135>:1363' */
        FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag =
          FaultDiagRapid_IN_Normal_a2rq;
      } else {
        /* Transition: '<S135>:1385' */
        if (((Int32)FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin) > 0) {
          /* Transition: '<S135>:1386' */
          /* Transition: '<S135>:1389' */
          FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin) - 1));

          /* Transition: '<S135>:1391' */
        } else {
          /* Outputs for Function Call SubSystem: '<S135>/DTC_Ctrl_Enabled' */
          /* Selector: '<S150>/Selector' */
          /* Transition: '<S135>:1387' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S135>:1410' */
          Fv_ErrDiagStatus_tmp = DTC_MOTORcheck_OverCurrent;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S135>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S135>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S135>:1406' */
          Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 3,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_MOTORcheck_OverCurrent].Enabled);

          /* End of Outputs for SubSystem: '<S135>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S135>:1370' */
      if (FaultDiagRapidrtDW.OverCurrentCheck.overcurrent2) {
        /* Transition: '<S135>:1362' */
        FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag =
          FaultDiagRapid_IN_Fault_k1qc;

        /* Entry 'Fault': '<S135>:1364' */
        FaultDiagRapidrtDW.OverCurrentCheck.MIA_TimeWin = ((UInt16)
          MACRO_MOTOR_OVERCURRENT_CHECKTIME);
      }
    }
  } else {
    /* During 'Wait': '<S135>:1359' */
    if (FaultDiagRapidrtDW.precondover2) {
      /* Transition: '<S135>:1377' */
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_c12_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_epdr;

      /* Entry Internal 'Diag': '<S135>:1360' */
      /* Transition: '<S135>:1361' */
      FaultDiagRapidrtDW.OverCurrentCheck.bitsForTID0.is_Diag =
        FaultDiagRapid_IN_Normal_a2rq;
    }
  }

  /* End of Chart: '<S130>/OverCurrentDiag2' */
}

#endif

/* System reset for atomic system: '<S85>/MotorCheck_OverCurrent' */
void Fa_MotorCheck_OverCurrent_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S116>/DiagRapid_MotorOverCurrent_Check' */
#if DIAGDIS_MOTOROVERCURRENTREG == 0

  /* Reset conditions for atomic system: '<S129>/OverCurrentCheck' */

  /* SystemReset for Chart: '<S130>/OverCurrentDiag1' */
  FaultDia_OverCurrentDiag1_Reset();

  /* SystemReset for Chart: '<S130>/OverCurrentDiag2' */
  FaultDia_OverCurrentDiag2_Reset();

#endif

  /* End of SystemReset for SubSystem: '<S116>/DiagRapid_MotorOverCurrent_Check' */
}

/* Output and update for atomic system: '<S85>/MotorCheck_OverCurrent' */
void FaultDia_MotorCheck_OverCurrent(void)
{
  /* Outputs for Atomic SubSystem: '<S116>/DiagRapid_MotorOverCurrent_Check' */
#if DIAGDIS_MOTOROVERCURRENTREG == 0

  /* Output and update for atomic system: '<S129>/OverCurrentCheck' */
  {
    Int32 tmp_d;
    Int32 tmp_emj4;
    Int32 tmp_nelo;

    /* Outputs for Atomic SubSystem: '<S130>/OverCurrentCond1' */
    /* Logic: '<S132>/Logical Operator2' incorporates:
     *  Constant: '<S136>/Constant'
     *  Constant: '<S137>/Constant'
     *  Constant: '<S138>/Constant'
     *  DataStoreRead: '<S132>/Data Store Read6'
     *  DataStoreRead: '<S132>/Data Store Read7'
     *  DataStoreRead: '<S132>/Data Store Read8'
     *  Inport: '<Root>/IO_PredriverState2'
     *  RelationalOperator: '<S136>/Compare'
     *  RelationalOperator: '<S137>/Compare'
     *  RelationalOperator: '<S138>/Compare'
     */
    FaultDiagRapidrtDW.precondover1 = (((((IO_PredriverState2) &&
      (SysTaskPreDriverPending1)) && (Fv_SysPowerRelay >= ((Int16)
      MACRO_TP_BRIDGEWORK))) && (Fv_I2D5RefADVol1 >= ((UInt16)
      MACRO_CURRENT_MIDMIN))) && (Fv_I2D5RefADVol1 <= ((UInt16)
      MACRO_CURRENT_MIDMAX)));

    /* Abs: '<S132>/Abs' incorporates:
     *  DataStoreRead: '<S132>/Data Store Read9'
     */
    if (Fv_MotorCurrent_U1 < 0) {
      tmp_d = -Fv_MotorCurrent_U1;
    } else {
      tmp_d = Fv_MotorCurrent_U1;
    }

    /* End of Abs: '<S132>/Abs' */

    /* Abs: '<S132>/Abs1' incorporates:
     *  DataStoreRead: '<S132>/Data Store Read10'
     */
    if (Fv_MotorCurrent_V1 < 0) {
      tmp_emj4 = -Fv_MotorCurrent_V1;
    } else {
      tmp_emj4 = Fv_MotorCurrent_V1;
    }

    /* End of Abs: '<S132>/Abs1' */

    /* Abs: '<S132>/Abs2' incorporates:
     *  DataStoreRead: '<S132>/Data Store Read11'
     */
    if (Fv_MotorCurrent_W1 < 0) {
      tmp_nelo = -Fv_MotorCurrent_W1;
    } else {
      tmp_nelo = Fv_MotorCurrent_W1;
    }

    /* End of Abs: '<S132>/Abs2' */

    /* Logic: '<S132>/Logical Operator3' incorporates:
     *  Constant: '<S139>/Constant'
     *  Constant: '<S140>/Constant'
     *  Constant: '<S141>/Constant'
     *  RelationalOperator: '<S139>/Compare'
     *  RelationalOperator: '<S140>/Compare'
     *  RelationalOperator: '<S141>/Compare'
     */
    FaultDiagRapidrtDW.OverCurrentCheck.overcurrent2 = (((tmp_d >=
      MACRO_MOTOR_CURRENTMAX) || (tmp_emj4 >= MACRO_MOTOR_CURRENTMAX)) ||
      (tmp_nelo >= MACRO_MOTOR_CURRENTMAX));

    /* End of Outputs for SubSystem: '<S130>/OverCurrentCond1' */

    /* Chart: '<S130>/OverCurrentDiag1' */
    FaultDiagRapid_OverCurrentDiag1();

    /* Outputs for Atomic SubSystem: '<S130>/OverCurrentCond2' */
    /* Logic: '<S133>/Logical Operator2' incorporates:
     *  Constant: '<S142>/Constant'
     *  Constant: '<S143>/Constant'
     *  Constant: '<S144>/Constant'
     *  DataStoreRead: '<S133>/Data Store Read6'
     *  DataStoreRead: '<S133>/Data Store Read7'
     *  DataStoreRead: '<S133>/Data Store Read8'
     *  Inport: '<Root>/IO_PredriverState1'
     *  RelationalOperator: '<S142>/Compare'
     *  RelationalOperator: '<S143>/Compare'
     *  RelationalOperator: '<S144>/Compare'
     */
    FaultDiagRapidrtDW.precondover2 = (((((IO_PredriverState1) &&
      (SysTaskPreDriverPending1)) && (Fv_SysPowerRelay >= ((Int16)
      MACRO_TP_BRIDGEWORK))) && (Fv_I2D5RefADVol2 >= ((UInt16)
      MACRO_CURRENT_MIDMIN))) && (Fv_I2D5RefADVol2 <= ((UInt16)
      MACRO_CURRENT_MIDMAX)));

    /* Abs: '<S133>/Abs' incorporates:
     *  DataStoreRead: '<S133>/Data Store Read9'
     */
    if (Fv_MotorCurrent_U2 < 0) {
      tmp_d = -Fv_MotorCurrent_U2;
    } else {
      tmp_d = Fv_MotorCurrent_U2;
    }

    /* End of Abs: '<S133>/Abs' */

    /* Abs: '<S133>/Abs1' incorporates:
     *  DataStoreRead: '<S133>/Data Store Read10'
     */
    if (Fv_MotorCurrent_V2 < 0) {
      tmp_emj4 = -Fv_MotorCurrent_V2;
    } else {
      tmp_emj4 = Fv_MotorCurrent_V2;
    }

    /* End of Abs: '<S133>/Abs1' */

    /* Abs: '<S133>/Abs2' incorporates:
     *  DataStoreRead: '<S133>/Data Store Read11'
     */
    if (Fv_MotorCurrent_W2 < 0) {
      tmp_nelo = -Fv_MotorCurrent_W2;
    } else {
      tmp_nelo = Fv_MotorCurrent_W2;
    }

    /* End of Abs: '<S133>/Abs2' */

    /* Logic: '<S133>/Logical Operator3' incorporates:
     *  Constant: '<S145>/Constant'
     *  Constant: '<S146>/Constant'
     *  Constant: '<S147>/Constant'
     *  RelationalOperator: '<S145>/Compare'
     *  RelationalOperator: '<S146>/Compare'
     *  RelationalOperator: '<S147>/Compare'
     */
    FaultDiagRapidrtDW.OverCurrentCheck.overcurrent2 = (((tmp_d >=
      MACRO_MOTOR_CURRENTMAX) || (tmp_emj4 >= MACRO_MOTOR_CURRENTMAX)) ||
      (tmp_nelo >= MACRO_MOTOR_CURRENTMAX));

    /* End of Outputs for SubSystem: '<S130>/OverCurrentCond2' */

    /* Chart: '<S130>/OverCurrentDiag2' */
    FaultDiagRapid_OverCurrentDiag2();
  }

#elif DIAGDIS_MOTOROVERCURRENTREG == 1

  /* Output and update for atomic system: '<S129>/OverCurrentCheckDis' */

  /* Logic: '<S131>/AND1' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S155>/Constant'
   *  Constant: '<S156>/Constant'
   *  DataStoreRead: '<S131>/Data Store Read6'
   *  DataStoreRead: '<S131>/Data Store Read7'
   *  DataStoreRead: '<S131>/Data Store Read8'
   *  Inport: '<Root>/IO_PredriverState2'
   *  RelationalOperator: '<S154>/Compare'
   *  RelationalOperator: '<S155>/Compare'
   *  RelationalOperator: '<S156>/Compare'
   */
  FaultDiagRapidrtDW.precondover1 = (((((Fv_SysPowerRelay >= ((Int16)
    MACRO_TP_BRIDGEWORK)) && (Fv_I2D5RefADVol1 >= ((UInt16)MACRO_CURRENT_MIDMIN)))
    && (Fv_I2D5RefADVol1 <= ((UInt16)MACRO_CURRENT_MIDMAX))) &&
    (SysTaskPreDriverPending1)) && (IO_PredriverState2));

  /* Logic: '<S131>/AND2' incorporates:
   *  Constant: '<S152>/Constant'
   *  Constant: '<S153>/Constant'
   *  Constant: '<S157>/Constant'
   *  DataStoreRead: '<S131>/Data Store Read1'
   *  DataStoreRead: '<S131>/Data Store Read2'
   *  DataStoreRead: '<S131>/Data Store Read3'
   *  Inport: '<Root>/IO_PredriverState1'
   *  RelationalOperator: '<S152>/Compare'
   *  RelationalOperator: '<S153>/Compare'
   *  RelationalOperator: '<S157>/Compare'
   */
  FaultDiagRapidrtDW.precondover2 = (((((Fv_SysPowerRelay >= ((Int16)
    MACRO_TP_BRIDGEWORK)) && (Fv_I2D5RefADVol2 >= ((UInt16)MACRO_CURRENT_MIDMIN)))
    && (Fv_I2D5RefADVol2 <= ((UInt16)MACRO_CURRENT_MIDMAX))) &&
    (SysTaskPreDriverPending2)) && (IO_PredriverState1));

#endif

  /* End of Outputs for SubSystem: '<S116>/DiagRapid_MotorOverCurrent_Check' */
}

/* System reset for atomic system: '<S159>/PredriverDiag1' */
#if DIAGDIS_MOTORPREDRIVERREG == 0

void FaultDiagR_PredriverDiag1_Reset(void)
{
  FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_active_c3_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c3_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_flmt;
  FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll = 0U;
}

#endif

/* Output and update for atomic system: '<S159>/PredriverDiag1' */
#if DIAGDIS_MOTORPREDRIVERREG == 0

void FaultDiagRapid_PredriverDiag1(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S159>/PredriverDiag1' incorporates:
   *  DataStoreRead: '<S169>/Data Store Read'
   *  DataStoreRead: '<S170>/Data Store Read'
   *  DataTypeConversion: '<S169>/Data Type Conversion2'
   *  Inport: '<Root>/IO_PredriverState1'
   *  Product: '<S169>/Product'
   *  Selector: '<S169>/Selector'
   *  Selector: '<S170>/Selector'
   */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1 */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1 */
  if (((UInt32)
       FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_active_c3_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1 */
    FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_active_c3_FaultDiagRapid =
      1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1 */
    /* Transition: '<S163>:1307' */
    FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c3_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_i0yc;
  } else if (((UInt32)
              FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c3_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_cw0s) {
    /* During 'Diag': '<S163>:1290' */
    if (FaultDiagRapidrtDW.PredriverCheck.preconddiag2) {
      /* Transition: '<S163>:1289' */
      FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c3_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_i0yc;
    } else {
      /* Transition: '<S163>:1339' */
      if (!IO_PredriverState1) {
        /* Transition: '<S163>:1341' */
        if (FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll < ((UInt16)
             MACRO_MOTOR_PASSTIME)) {
          /* Transition: '<S163>:1343' */
          /* Transition: '<S163>:1345' */
          FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll) + 1));
        } else {
          /* Outputs for Function Call SubSystem: '<S163>/DTC_Ctrl_Enabled' */
          /* Selector: '<S169>/Selector' */
          /* Transition: '<S163>:1347' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S163>:1373' */
          Fv_ErrDiagStatus_tmp = DTC_MOTORcheck_Predriver;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S163>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S163>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S163>:1376' */
          Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 0,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_MOTORcheck_Predriver].Enabled);

          /* End of Outputs for SubSystem: '<S163>/getDTCEnabled' */
          /* Transition: '<S163>:1348' */
        }
      } else {
        /* Transition: '<S163>:1350' */
        if (((Int32)FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll) > 0) {
          /* Transition: '<S163>:1352' */
          /* Transition: '<S163>:1354' */
          FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll) - 1));
        } else {
          /* Transition: '<S163>:1356' */
          /* Transition: '<S163>:1357' */
        }

        /* Transition: '<S163>:1358' */
        /* Transition: '<S163>:1348' */
      }
    }
  } else {
    /* During 'Wait': '<S163>:1306' */
    if (FaultDiagRapidrtDW.PredriverCheck.precondwait2) {
      /* Transition: '<S163>:1308' */
      FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c3_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_cw0s;

      /* Entry 'Diag': '<S163>:1290' */
      FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin_c1ll = 0U;
    }
  }

  /* End of Chart: '<S159>/PredriverDiag1' */
}

#endif

/* System reset for atomic system: '<S159>/PredriverDiag2' */
#if DIAGDIS_MOTORPREDRIVERREG == 0

void FaultDiagR_PredriverDiag2_Reset(void)
{
  FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_active_c8_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c8_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_pxgv;
  FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin = 0U;
}

#endif

/* Output and update for atomic system: '<S159>/PredriverDiag2' */
#if DIAGDIS_MOTORPREDRIVERREG == 0

void FaultDiagRapid_PredriverDiag2(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S159>/PredriverDiag2' incorporates:
   *  DataStoreRead: '<S171>/Data Store Read'
   *  DataStoreRead: '<S172>/Data Store Read'
   *  DataTypeConversion: '<S171>/Data Type Conversion2'
   *  Inport: '<Root>/IO_PredriverState2'
   *  Product: '<S171>/Product'
   *  Selector: '<S171>/Selector'
   *  Selector: '<S172>/Selector'
   */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2 */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2 */
  if (((UInt32)
       FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_active_c8_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2 */
    FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_active_c8_FaultDiagRapid =
      1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2 */
    /* Transition: '<S164>:1307' */
    FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c8_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_bnwi;
  } else if (((UInt32)
              FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c8_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_di2b) {
    /* During 'Diag': '<S164>:1290' */
    if (FaultDiagRapidrtDW.PredriverCheck.precondwait2) {
      /* Transition: '<S164>:1289' */
      FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c8_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_bnwi;
    } else {
      /* Transition: '<S164>:1339' */
      if (!IO_PredriverState2) {
        /* Transition: '<S164>:1341' */
        if (FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin < ((UInt16)
             MACRO_MOTOR_PASSTIME)) {
          /* Transition: '<S164>:1343' */
          /* Transition: '<S164>:1345' */
          FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin) + 1));
        } else {
          /* Outputs for Function Call SubSystem: '<S164>/DTC_Ctrl_Enabled' */
          /* Selector: '<S171>/Selector' */
          /* Transition: '<S164>:1347' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S164>:1373' */
          Fv_ErrDiagStatus_tmp = DTC_MOTORcheck_Predriver;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S164>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S164>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S164>:1376' */
          Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 1,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_MOTORcheck_Predriver].Enabled);

          /* End of Outputs for SubSystem: '<S164>/getDTCEnabled' */
          /* Transition: '<S164>:1348' */
        }
      } else {
        /* Transition: '<S164>:1350' */
        if (((Int32)FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin) > 0) {
          /* Transition: '<S164>:1352' */
          /* Transition: '<S164>:1354' */
          FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin) - 1));
        } else {
          /* Transition: '<S164>:1356' */
          /* Transition: '<S164>:1357' */
        }

        /* Transition: '<S164>:1358' */
        /* Transition: '<S164>:1348' */
      }
    }
  } else {
    /* During 'Wait': '<S164>:1306' */
    if (FaultDiagRapidrtDW.PredriverCheck.preconddiag2) {
      /* Transition: '<S164>:1308' */
      FaultDiagRapidrtDW.PredriverCheck.bitsForTID0.is_c8_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_di2b;

      /* Entry 'Diag': '<S164>:1290' */
      FaultDiagRapidrtDW.PredriverCheck.MP_TimeWin = 0U;
    }
  }

  /* End of Chart: '<S159>/PredriverDiag2' */
}

#endif

/* System reset for atomic system: '<S85>/MotorCheck_Predriver' */
void Faul_MotorCheck_Predriver_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S117>/DiagRapid_MotorPredriver_Check' */
#if DIAGDIS_MOTORPREDRIVERREG == 0

  /* Reset conditions for atomic system: '<S158>/PredriverCheck' */

  /* SystemReset for Chart: '<S159>/PredriverDiag1' */
  FaultDiagR_PredriverDiag1_Reset();

  /* SystemReset for Chart: '<S159>/PredriverDiag2' */
  FaultDiagR_PredriverDiag2_Reset();

#endif

  /* End of SystemReset for SubSystem: '<S117>/DiagRapid_MotorPredriver_Check' */
}

/* Output and update for atomic system: '<S85>/MotorCheck_Predriver' */
void FaultDiagR_MotorCheck_Predriver(void)
{
  /* Outputs for Atomic SubSystem: '<S117>/DiagRapid_MotorPredriver_Check' */
#if DIAGDIS_MOTORPREDRIVERREG == 0

  /* Output and update for atomic system: '<S158>/PredriverCheck' */
  {
    Bool rtb_preconddiag;

    /* Outputs for Atomic SubSystem: '<S159>/PredriverCond1' */
    /* Logic: '<S161>/Logical Operator6' incorporates:
     *  DataStoreRead: '<S161>/Data Store Read2'
     *  DataStoreRead: '<S161>/Data Store Read3'
     *  DataStoreRead: '<S161>/Data Store Read4'
     *  Logic: '<S161>/Logical Operator4'
     *  Logic: '<S161>/Logical Operator5'
     */
    rtb_preconddiag = (((!SysTaskViceShutDriverPending) &&
                        (SysTaskPreDriverPending1)) && (!Arg82800V5cOkFlag));

    /* Logic: '<S161>/Logical Operator8' incorporates:
     *  Constant: '<S165>/Constant'
     *  DataStoreRead: '<S161>/Data Store Read5'
     *  Logic: '<S161>/Logical Operator1'
     *  RelationalOperator: '<S165>/Compare'
     */
    FaultDiagRapidrtDW.PredriverCheck.preconddiag2 = ((!rtb_preconddiag) ||
      (Fv_SysPowerRelay < ((Int16)MACRO_TP_BRIDGESHUT)));

    /* Logic: '<S161>/Logical Operator7' incorporates:
     *  Constant: '<S166>/Constant'
     *  DataStoreRead: '<S161>/Data Store Read1'
     *  RelationalOperator: '<S166>/Compare'
     */
    FaultDiagRapidrtDW.PredriverCheck.precondwait2 = ((Fv_SysPowerRelay >=
      ((Int16)MACRO_TP_BRIDGEWORK)) && rtb_preconddiag);

    /* End of Outputs for SubSystem: '<S159>/PredriverCond1' */

    /* Chart: '<S159>/PredriverDiag1' */
    FaultDiagRapid_PredriverDiag1();

    /* Outputs for Atomic SubSystem: '<S159>/PredriverCond2' */
    /* Logic: '<S162>/Logical Operator6' incorporates:
     *  DataStoreRead: '<S162>/Data Store Read2'
     *  DataStoreRead: '<S162>/Data Store Read3'
     *  DataStoreRead: '<S162>/Data Store Read4'
     *  Logic: '<S162>/Logical Operator4'
     *  Logic: '<S162>/Logical Operator5'
     */
    rtb_preconddiag = (((!SysTaskViceShutDriverPending) &&
                        (SysTaskPreDriverPending2)) && (!Arg82800V5cOkFlag));

    /* Logic: '<S162>/Logical Operator8' incorporates:
     *  Constant: '<S167>/Constant'
     *  DataStoreRead: '<S162>/Data Store Read5'
     *  Logic: '<S162>/Logical Operator1'
     *  RelationalOperator: '<S167>/Compare'
     */
    FaultDiagRapidrtDW.PredriverCheck.precondwait2 = ((!rtb_preconddiag) ||
      (Fv_SysPowerRelay < ((Int16)MACRO_TP_BRIDGESHUT)));

    /* Logic: '<S162>/Logical Operator7' incorporates:
     *  Constant: '<S168>/Constant'
     *  DataStoreRead: '<S162>/Data Store Read1'
     *  RelationalOperator: '<S168>/Compare'
     */
    FaultDiagRapidrtDW.PredriverCheck.preconddiag2 = ((Fv_SysPowerRelay >=
      ((Int16)MACRO_TP_BRIDGEWORK)) && rtb_preconddiag);

    /* End of Outputs for SubSystem: '<S159>/PredriverCond2' */

    /* Chart: '<S159>/PredriverDiag2' */
    FaultDiagRapid_PredriverDiag2();
  }

#endif

  /* End of Outputs for SubSystem: '<S117>/DiagRapid_MotorPredriver_Check' */
}

/* System reset for atomic system: '<S83>/DiagRapid_MotoCheck' */
void Fault_DiagRapid_MotoCheck_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S85>/MotorCheck_OverCurrent' */
  Fa_MotorCheck_OverCurrent_Reset();

  /* End of SystemReset for SubSystem: '<S85>/MotorCheck_OverCurrent' */

  /* SystemReset for Atomic SubSystem: '<S85>/MotorCheck_OutputCurrent' */
  MotorCheck_OutputCurrent_Reset();

  /* End of SystemReset for SubSystem: '<S85>/MotorCheck_OutputCurrent' */

  /* SystemReset for Atomic SubSystem: '<S85>/MotorCheck_Predriver' */
  Faul_MotorCheck_Predriver_Reset();

  /* End of SystemReset for SubSystem: '<S85>/MotorCheck_Predriver' */
}

/* Output and update for atomic system: '<S83>/DiagRapid_MotoCheck' */
void FaultDiagRa_DiagRapid_MotoCheck(void)
{
  /* Outputs for Atomic SubSystem: '<S85>/MotorCheck_OverCurrent' */
  FaultDia_MotorCheck_OverCurrent();

  /* End of Outputs for SubSystem: '<S85>/MotorCheck_OverCurrent' */

  /* Outputs for Atomic SubSystem: '<S85>/MotorCheck_OutputCurrent' */
  FaultD_MotorCheck_OutputCurrent();

  /* End of Outputs for SubSystem: '<S85>/MotorCheck_OutputCurrent' */

  /* Outputs for Atomic SubSystem: '<S85>/MotorCheck_Predriver' */
  FaultDiagR_MotorCheck_Predriver();

  /* End of Outputs for SubSystem: '<S85>/MotorCheck_Predriver' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

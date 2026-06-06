/*
 * File: TemperatureCheck.c
 *
 * Code generated for Simulink model 'TemperatureCheck'.
 *
 * Model version                  : 1.1126
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:37:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TemperatureCheck.h"
#include "TemperatureCheck_private.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"

/* Named constants for Chart: '<S11>/TempManagement' */
#define TemperatureCheck_IN_Low        ((UInt8)1U)
#define TemperatureCheck_IN_Normal     ((UInt8)2U)
#define TemperatureCheck_IN_Over       ((UInt8)3U)
#define TemperatureCheck_IN_Wait       ((UInt8)4U)

/* Named constants for Chart: '<S16>/TempSignalCheck' */
#define TemperatureCheck_IN_Fault      ((UInt8)1U)
#define TemperatureCheck_IN_Normal_mq4x ((UInt8)2U)

/* Block states (default storage) */
TemperatureCheck_DW_fwu4 TemperatureCheckrtDW;

/* Output and update for atomic system: '<S4>/TemperatureCheck_Calc_Atomic' */
#if MACRO_TEMP_DP_ENABLE == 0

void Te_TemperatureCheck_Calc_Atomic(void)
{
  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/AD_TempSys'
   */
  TemperatureCheckrtDW.Fv_TempVol_morp = (UInt16)((((UInt32)AD_TempSys) *
    ((UInt32)((UInt16)MACRO_AV_AD2VOL))) >> 6);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S7>/Constant'
   *  DataStoreRead: '<S6>/Data Store Read'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (Fv_LimitFailFlag == 0) {
    /* Lookup_n-D: '<S6>/temptable' */
    TemperatureCheckrtDW.Fv_TempSysCel_ibrv = look1_iu16ls32n10ts16D_QWHCuzIb
      (TemperatureCheckrtDW.Fv_TempVol_morp, ((const UInt16 *)
        &(Cal_AV_TempScale_X[0])), ((const Int16 *)&(Cal_AV_TempScale_Y[0])),
       &TemperatureCheckrtDW.TemperatureCheck_Calc_CP.m_bpIndex, 35U);
  } else {
    TemperatureCheckrtDW.Fv_TempSysCel_ibrv = 0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* DataStoreWrite: '<S6>/Data Store Write1' */
  Fv_TempSysCel = TemperatureCheckrtDW.Fv_TempSysCel_ibrv;

  /* DataStoreWrite: '<S6>/Data Store Write' */
  Fv_TempVol = TemperatureCheckrtDW.Fv_TempVol_morp;
}

#endif

/* Output and update for atomic system: '<S5>/TemperatureCheck_Calc_Atomic' */
#if MACRO_TEMP_DP_ENABLE == 1

void TemperatureCheck_Calc_Atom_ahhn(void)
{
  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/AD_TempSys'
   */
  TemperatureCheckrtDW.Fv_TempVol_morp = (UInt16)((((UInt32)AD_TempSys) *
    ((UInt32)((UInt16)MACRO_AV_AD2VOL))) >> 6);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<S8>/Data Store Read'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (Fv_LimitFailFlag == 0) {
    /* Lookup_n-D: '<S8>/temptable' */
    TemperatureCheckrtDW.Fv_TempSysCel_ibrv = look1_iu16ls32n10ts16D_QWHCuzIb
      (TemperatureCheckrtDW.Fv_TempVol_morp, ((const UInt16 *)
        &(Cal_TDK_TempScale_X[0])), ((const Int16 *)&(Cal_TDK_TempScale_Y[0])),
       &TemperatureCheckrtDW.TemperatureCheck_Calc_DP.m_bpIndex, 38U);
  } else {
    TemperatureCheckrtDW.Fv_TempSysCel_ibrv = 0;
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataStoreWrite: '<S8>/Data Store Write1' */
  Fv_TempSysCel = TemperatureCheckrtDW.Fv_TempSysCel_ibrv;

  /* DataStoreWrite: '<S8>/Data Store Write' */
  Fv_TempVol = TemperatureCheckrtDW.Fv_TempVol_morp;
}

#endif

/* Output and update for atomic system: '<Root>/TemperatureCheck_Level' */
void Temperat_TemperatureCheck_Level(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/TempLevelCheck' */
#if DIAGDIS_TEMPLEVEL == 0

  /* Output and update for atomic system: '<S10>/TempLevelCheck' */
  {
    Int32 tmp_m;

    /* Chart: '<S11>/TempManagement' incorporates:
     *  DataStoreRead: '<S14>/Data Store Read'
     *  Selector: '<S14>/Selector'
     */
    /* Gateway: TemperatureCheck_Level/TempLevelCheck/TempLevelCheck/TempManagement */
    /* During: TemperatureCheck_Level/TempLevelCheck/TempLevelCheck/TempManagement */
    if (((UInt32)
         TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_active_c77_TemperatureCheck)
        == 0U) {
      /* Entry: TemperatureCheck_Level/TempLevelCheck/TempLevelCheck/TempManagement */
      TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_active_c77_TemperatureCheck
        = 1;

      /* Entry Internal: TemperatureCheck_Level/TempLevelCheck/TempLevelCheck/TempManagement */
      /* Transition: '<S13>:2230' */
      TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
        = TemperatureCheck_IN_Wait;
    } else {
      switch
        (TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck)
      {
       case TemperatureCheck_IN_Low:
        /* During 'Low': '<S13>:2236' */
        if (TemperatureCheckrtDW.Fv_TempSysCel_ibrv >= Cal_TempLow) {
          /* Transition: '<S13>:2239' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
            = TemperatureCheck_IN_Wait;
        } else {
          /* Transition: '<S13>:2261' */
          if (((Int32)TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimel) >
              0) {
            /* Transition: '<S13>:2263' */
            /* Transition: '<S13>:2266' */
            TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimel = (UInt16)
              ((Int32)(((Int32)
                        TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimel)
                       - 1));

            /* Transition: '<S13>:2259' */
            /* Transition: '<S13>:2296' */
          } else {
            /* Outputs for Function Call SubSystem: '<S13>/getDTCEnabled' */
            /* Selector: '<S14>/Selector' */
            /* Transition: '<S13>:2260' */
            /* Simulink Function 'getDTCEnabled': '<S13>:2289' */
            tmp_m = DTC_TEMPcheck_TempLimitAst;
            if (((Int32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[tmp_m].
                 Enabled) != 0) {
              /* Transition: '<S13>:2292' */
              /* Transition: '<S13>:2293' */
              Fv_TempLevel = TEMP_CEL_LOW;
              Fv_ErrDiagStatus[DTC_TEMPcheck_Over] = FailureDiag_OK;
              //Fv_ErrDiagStatus[(tmp_m)] = FailureDiag_Err;

              /* Transition: '<S13>:2296' */
            } else {
              /* Transition: '<S13>:2295' */
            }

            /* End of Outputs for SubSystem: '<S13>/getDTCEnabled' */
          }
        }
        break;

       case TemperatureCheck_IN_Normal:
        /* During 'Normal': '<S13>:2233' */
        if ((TemperatureCheckrtDW.Fv_TempSysCel_ibrv > Cal_TempOver) ||
            (TemperatureCheckrtDW.Fv_TempSysCel_ibrv < Cal_TempLow)) {
          /* Transition: '<S13>:2234' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
            = TemperatureCheck_IN_Wait;
        } else {
          /* Transition: '<S13>:2242' */
          if (((Int32)TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimen) >
              0) {
            /* Transition: '<S13>:2252' */
            /* Transition: '<S13>:2256' */
            TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimen = (UInt16)
              ((Int32)(((Int32)
                        TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimen)
                       - 1));

            /* Transition: '<S13>:2257' */
          } else {
            /* Transition: '<S13>:2228' */
            Fv_TempLevel = TEMP_CEL_NORMAL;
            Fv_ErrDiagStatus[DTC_TEMPcheck_Over] = FailureDiag_OK;
            //Fv_ErrDiagStatus[DTC_TEMPcheck_TempLimitAst] = FailureDiag_OK;
          }
        }
        break;

       case TemperatureCheck_IN_Over:
        /* During 'Over': '<S13>:2253' */
        if (TemperatureCheckrtDW.Fv_TempSysCel_ibrv <= Cal_TempOver) {
          /* Transition: '<S13>:2250' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
            = TemperatureCheck_IN_Wait;
        } else {
          /* Transition: '<S13>:2269' */
          if (((Int32)TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimeo) >
              0) {
            /* Transition: '<S13>:2273' */
            /* Transition: '<S13>:2268' */
            TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimeo = (UInt16)
              ((Int32)(((Int32)
                        TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimeo)
                       - 1));

            /* Transition: '<S13>:2275' */
            /* Transition: '<S13>:2303' */
          } else {
            /* Outputs for Function Call SubSystem: '<S13>/getDTCEnabled' */
            /* Transition: '<S13>:2274' */
            /* Simulink Function 'getDTCEnabled': '<S13>:2289' */
            if (((Int32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
                 [DTC_TEMPcheck_Over].Enabled) != 0) {
              /* Transition: '<S13>:2299' */
              /* Transition: '<S13>:2300' */
              Fv_TempLevel = TEMP_CEL_OVER;
              Fv_ErrDiagStatus[DTC_TEMPcheck_Over] = FailureDiag_Err;
              //Fv_ErrDiagStatus[DTC_TEMPcheck_TempLimitAst] = FailureDiag_OK;

              /* Transition: '<S13>:2303' */
            } else {
              /* Transition: '<S13>:2302' */
            }

            /* End of Outputs for SubSystem: '<S13>/getDTCEnabled' */
          }
        }
        break;

       default:
        /* During 'Wait': '<S13>:2246' */
        if ((TemperatureCheckrtDW.Fv_TempSysCel_ibrv <= Cal_TempOver) &&
            (TemperatureCheckrtDW.Fv_TempSysCel_ibrv >= Cal_TempLow)) {
          /* Transition: '<S13>:2226' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
            = TemperatureCheck_IN_Normal;

          /* Entry 'Normal': '<S13>:2233' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimen = ((UInt16)
            MACRO_TEMPR_CHECKTIME);
        } else if (TemperatureCheckrtDW.Fv_TempSysCel_ibrv > Cal_TempOver) {
          /* Transition: '<S13>:2238' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
            = TemperatureCheck_IN_Over;

          /* Entry 'Over': '<S13>:2253' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimeo = ((UInt16)
            MACRO_TEMPR_CHECKTIME);
        } else {
          /* Transition: '<S13>:2227' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.bitsForTID0.is_c77_TemperatureCheck
            = TemperatureCheck_IN_Low;

          /* Entry 'Low': '<S13>:2236' */
          TemperatureCheckrtDW.TempLevelCheck_po3n.TempCheckTimel = ((UInt16)
            MACRO_TEMPR_CHECKTIME);
        }
        break;
      }
    }

    /* End of Chart: '<S11>/TempManagement' */
  }

#elif DIAGDIS_TEMPLEVEL == 1

  /* Output and update for atomic system: '<S10>/TempLevelCheckDis' */

  /* DataStoreWrite: '<S12>/Data Store Write' incorporates:
   *  Constant: '<S12>/Constant'
   */
  Fv_TempLevel = TEMP_CEL_NORMAL;

#endif

  /* End of Outputs for SubSystem: '<S2>/TempLevelCheck' */
}

/* Output and update for atomic system: '<Root>/TemperatureCheck_Vol' */
void Temperatur_TemperatureCheck_Vol(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/TempVolCheck' */
#if DIAGDIS_TEMPVOL == 0

  /* Output and update for atomic system: '<S15>/TempVolCheck' */
  {
    Int32 Fv_ErrDiagStatus_tmp_o;

    /* Chart: '<S16>/TempSignalCheck' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read2'
     *  DataStoreRead: '<S16>/Data Store Read3'
     *  DataStoreRead: '<S19>/Data Store Read'
     *  DataTypeConversion: '<S19>/Data Type Conversion2'
     *  Product: '<S19>/Product'
     *  Selector: '<S19>/Selector'
     */
    /* Gateway: TemperatureCheck_Vol/TempVolCheck/TempVolCheck/TempSignalCheck */
    /* During: TemperatureCheck_Vol/TempVolCheck/TempVolCheck/TempSignalCheck */
    if (((UInt32)
         TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_active_c78_TemperatureCheck)
        == 0U) {
      /* Entry: TemperatureCheck_Vol/TempVolCheck/TempVolCheck/TempSignalCheck */
      TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_active_c78_TemperatureCheck
        = 1;

      /* Entry Internal: TemperatureCheck_Vol/TempVolCheck/TempVolCheck/TempSignalCheck */
      /* Entry 'TempSensorRangeCheck': '<S18>:2111' */
      TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWink = 0U;

      /* Entry Internal 'TempSensorRangeCheck': '<S18>:2111' */
      /* Transition: '<S18>:2113' */
      TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempSensorRangeCheck
        = TemperatureCheck_IN_Normal_mq4x;

      /* Entry 'Normal': '<S18>:2121' */
      TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWinj = ((UInt16)
        MACRO_TEMPR_CHECKTIME_2);

      /* Entry 'TempEstHeat': '<S18>:2194' */
      TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWink = 0U;

      /* Entry Internal 'TempEstHeat': '<S18>:2194' */
      /* Transition: '<S18>:2202' */
      TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempEstHeat =
        TemperatureCheck_IN_Normal_mq4x;

      /* Entry 'Normal': '<S18>:2203' */
      TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWinj = ((UInt16)
        MACRO_TEMPR_CHECKTIME);
    } else {
      /* During 'TempSensorRangeCheck': '<S18>:2111' */
      if (((UInt32)
           TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempSensorRangeCheck)
          == TemperatureCheck_IN_Fault) {
        /* During 'Fault': '<S18>:2115' */
        if ((TemperatureCheckrtDW.Fv_TempVol_morp >= ((UInt16)MACRO_TEMPR_RCVMIN))
            && (TemperatureCheckrtDW.Fv_TempVol_morp <= ((UInt16)
              MACRO_TEMPR_RCVMAX))) {
          /* Transition: '<S18>:2114' */
          TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempSensorRangeCheck
            = TemperatureCheck_IN_Normal_mq4x;

          /* Entry 'Normal': '<S18>:2121' */
          TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWinj = ((UInt16)
            MACRO_TEMPR_CHECKTIME_2);
        } else {
          /* Transition: '<S18>:2133' */
          if (((Int32)TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWink) > 0) {
            /* Transition: '<S18>:2135' */
            /* Transition: '<S18>:2132' */
            TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWink = (UInt16)((Int32)
              (((Int32)TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWink) - 1));

            /* Transition: '<S18>:2139' */
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/DTC_Ctrl_Enabled' */
            /* Transition: '<S18>:2137' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S18>:2228' */
            Fv_ErrDiagStatus[DTC_TEMPcheck_Range] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_TEMPcheck_Range].Enabled) * ((UInt32)FailureDiag_Err));

            /* End of Outputs for SubSystem: '<S18>/DTC_Ctrl_Enabled' */
          }
        }
      } else {
        /* During 'Normal': '<S18>:2121' */
        if ((TemperatureCheckrtDW.Fv_TempVol_morp < ((UInt16)MACRO_TEMPR_SIGMIN))
            || (TemperatureCheckrtDW.Fv_TempVol_morp > ((UInt16)
              MACRO_TEMPR_SIGMAX))) {
          /* Transition: '<S18>:2112' */
          TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempSensorRangeCheck
            = TemperatureCheck_IN_Fault;

          /* Entry 'Fault': '<S18>:2115' */
          TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWink = ((UInt16)
            MACRO_TEMPR_CHECKTIME_2);
        } else {
          /* Transition: '<S18>:2125' */
          if (((Int32)TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWinj) > 0) {
            /* Transition: '<S18>:2124' */
            /* Transition: '<S18>:2129' */
            TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWinj = (UInt16)((Int32)
              (((Int32)TemperatureCheckrtDW.TempVolCheck_bkta.TS_TimeWinj) - 1));

            /* Transition: '<S18>:2130' */
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/DTC_Ctrl_Enabled' */
            /* Selector: '<S19>/Selector' */
            /* Transition: '<S18>:2126' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S18>:2228' */
            Fv_ErrDiagStatus_tmp_o = DTC_TEMPcheck_Range;
            Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_o)] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [Fv_ErrDiagStatus_tmp_o].Enabled) * ((UInt32)FailureDiag_OK));

            /* End of Outputs for SubSystem: '<S18>/DTC_Ctrl_Enabled' */
          }
        }
      }

      /* During 'TempEstHeat': '<S18>:2194' */
      if (((UInt32)
           TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempEstHeat) ==
          TemperatureCheck_IN_Fault) {
        /* During 'Fault': '<S18>:2198' */
        if ((((Int32)Fv_StallCompCoef) == 0) && (((Int32)Fv_TempCompCoef) == 0))
        {
          /* Transition: '<S18>:2206' */
          TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempEstHeat =
            TemperatureCheck_IN_Normal_mq4x;

          /* Entry 'Normal': '<S18>:2203' */
          TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWinj = ((UInt16)
            MACRO_TEMPR_CHECKTIME);
        } else {
          /* Transition: '<S18>:2219' */
          if (((Int32)TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWink) > 0)
          {
            /* Transition: '<S18>:2217' */
            /* Transition: '<S18>:2212' */
            TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWink = (UInt16)
              ((Int32)(((Int32)
                        TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWink) - 1));

            /* Transition: '<S18>:2214' */
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/DTC_Ctrl_Enabled' */
            /* Transition: '<S18>:2218' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S18>:2228' */
            Fv_ErrDiagStatus[DTC_TEMPcheck_HeatShut] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_TEMPcheck_HeatShut].Enabled) * ((UInt32)FailureDiag_Err));

            /* End of Outputs for SubSystem: '<S18>/DTC_Ctrl_Enabled' */
          }
        }
      } else {
        /* During 'Normal': '<S18>:2203' */
        if ((((Int32)Fv_StallCompCoef) > 0) || (((Int32)Fv_TempCompCoef) == 4096))
        {
          /* Transition: '<S18>:2195' */
          TemperatureCheckrtDW.TempVolCheck_bkta.bitsForTID0.is_TempEstHeat =
            TemperatureCheck_IN_Fault;

          /* Entry 'Fault': '<S18>:2198' */
          TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWink = ((UInt16)
            MACRO_TEMPR_CHECKTIME);
        } else {
          /* Transition: '<S18>:2205' */
          if (((Int32)TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWinj) > 0)
          {
            /* Transition: '<S18>:2199' */
            /* Transition: '<S18>:2210' */
            TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWinj = (UInt16)
              ((Int32)(((Int32)
                        TemperatureCheckrtDW.TempVolCheck_bkta.TSE_TimeWinj) - 1));

            /* Transition: '<S18>:2211' */
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/DTC_Ctrl_Enabled' */
            /* Selector: '<S19>/Selector' */
            /* Transition: '<S18>:2191' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S18>:2228' */
            Fv_ErrDiagStatus_tmp_o = DTC_TEMPcheck_HeatShut;
            Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_o)] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [Fv_ErrDiagStatus_tmp_o].Enabled) * ((UInt32)FailureDiag_OK));

            /* End of Outputs for SubSystem: '<S18>/DTC_Ctrl_Enabled' */
          }
        }
      }
    }

    /* End of Chart: '<S16>/TempSignalCheck' */
  }

#endif

  /* End of Outputs for SubSystem: '<S3>/TempVolCheck' */
}

/* Output and update for referenced model: 'TemperatureCheck' */
void TemperatureCheck(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/TemperatureCheck_Calc' */
#if MACRO_TEMP_DP_ENABLE == 0

  /* Output and update for atomic system: '<S1>/TemperatureCheck_Calc_CP' */

  /* Outputs for Atomic SubSystem: '<S4>/TemperatureCheck_Calc_Atomic' */
  Te_TemperatureCheck_Calc_Atomic();

  /* End of Outputs for SubSystem: '<S4>/TemperatureCheck_Calc_Atomic' */
#elif MACRO_TEMP_DP_ENABLE == 1

  /* Output and update for atomic system: '<S1>/TemperatureCheck_Calc_DP' */

  /* Outputs for Atomic SubSystem: '<S5>/TemperatureCheck_Calc_Atomic' */
  TemperatureCheck_Calc_Atom_ahhn();

  /* End of Outputs for SubSystem: '<S5>/TemperatureCheck_Calc_Atomic' */
#endif

  /* End of Outputs for SubSystem: '<Root>/TemperatureCheck_Calc' */

  /* Outputs for Atomic SubSystem: '<Root>/TemperatureCheck_Level' */
  Temperat_TemperatureCheck_Level();

  /* End of Outputs for SubSystem: '<Root>/TemperatureCheck_Level' */

  /* Outputs for Atomic SubSystem: '<Root>/TemperatureCheck_Vol' */
  Temperatur_TemperatureCheck_Vol();

  /* End of Outputs for SubSystem: '<Root>/TemperatureCheck_Vol' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

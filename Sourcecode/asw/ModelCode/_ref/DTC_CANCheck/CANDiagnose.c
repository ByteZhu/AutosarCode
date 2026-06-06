/*
 * File: CANDiagnose.c
 *
 * Code generated for Simulink model 'DTC_CANCheck'.
 *
 * Model version                  : 1.1204
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 21 17:56:45 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CANDiagnose.h"

/* Include model header file for global data */
#include "DTC_CANCheck.h"
#include "DTC_CANCheck_private.h"

/* Includes for objects with custom storage classes. */
#include "DTC_CANCheck.h"

/* Named constants for Chart: '<S9>/CANBUSABSCheck' */
#define DTC_CANCheck_IN_Diag           ((UInt8)1U)
#define DTC_CANCheck_IN_LostPending    ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun        ((UInt8)2U)
#define DTC_CANCheck_IN_Wait           ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_c4gh ((UInt8)0U)

/* Named constants for Chart: '<S10>/CANBUSAPACheck' */
#define DTC_CANChec_IN_LostPending_ogzq ((UInt8)1U)
#define DTC_CANCheck_IN_Diag_fdw0      ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun_fkde   ((UInt8)2U)
#define DTC_CANCheck_IN_Wait_aah4      ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_mifu ((UInt8)0U)

/* Named constants for Chart: '<S11>/CANBUSBCM2Check' */
#define DTC_CANChec_IN_LostPending_azpo ((UInt8)1U)
#define DTC_CANCheck_IN_Diag_ga2w      ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun_onv0   ((UInt8)2U)
#define DTC_CANCheck_IN_Wait_a0vx      ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_nkoh ((UInt8)0U)

/* Named constants for Chart: '<S12>/CANBUSEMSCheck' */
#define DTC_CANChec_IN_LostPending_aql5 ((UInt8)1U)
#define DTC_CANCheck_IN_Diag_ojue      ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun_jsy5   ((UInt8)2U)
#define DTC_CANCheck_IN_Wait_obpa      ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_ggrd ((UInt8)0U)

/* Named constants for Chart: '<S13>/CANBUSIPBCheck' */
#define DTC_CANChec_IN_LostPending_dht2 ((UInt8)1U)
#define DTC_CANCheck_IN_Diag_fnrc      ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun_pzwt   ((UInt8)2U)
#define DTC_CANCheck_IN_Wait_k1we      ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_oely ((UInt8)0U)

/* Named constants for Chart: '<S14>/CANBUSMPCCheck' */
#define DTC_CANChec_IN_LostPending_puy2 ((UInt8)1U)
#define DTC_CANCheck_IN_Diag_ctnm      ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun_gqxl   ((UInt8)2U)
#define DTC_CANCheck_IN_Wait_o0r3      ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_asfw ((UInt8)0U)

/* Named constants for Chart: '<S15>/CANBUSSCUCheck' */
#define DTC_CANChec_IN_LostPending_ihcn ((UInt8)1U)
#define DTC_CANCheck_IN_Diag_cjh2      ((UInt8)1U)
#define DTC_CANCheck_IN_LostRun_o2p0   ((UInt8)2U)
#define DTC_CANCheck_IN_Wait_jxwy      ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_cvq3 ((UInt8)0U)

/* Named constants for Chart: '<S5>/CANNetManagement' */
#define DTC_CANCheck_IN_Delay          ((UInt8)1U)
#define DTC_CANCheck_IN_IGOFF          ((UInt8)1U)
#define DTC_CANCheck_IN_IGON           ((UInt8)2U)
#define DTC_CANCheck_IN_LowHigh        ((UInt8)1U)
#define DTC_CANCheck_IN_Normal         ((UInt8)2U)
#define DTC_CANCheck_IN_Psmanag        ((UInt8)2U)
#define DTC_CAN_IN_NO_ACTIVE_CHILD_omvo ((UInt8)0U)
#if DIAGDIS_CANABS == 0

/* Forward declaration for local functions */
static void DTC_CA_enter_atomic_LostPending(void);
static void DTC_CANCheck_LostRun(void);

#endif

#if DIAGDIS_CANAPA == 0

/* Forward declaration for local functions */
static void D_enter_atomic_LostPending_awjs(void);

#endif

#if DIAGDIS_CANIPB == 0

/* Forward declaration for local functions */
static void D_enter_atomic_LostPending_mjcq(void);
static void DTC_CANCheck_LostRun_n1yi(void);

#endif

#if DIAGDIS_CANMPC == 0

/* Forward declaration for local functions */
static void D_enter_atomic_LostPending_bnlk(void);

#endif

/* Output and update for atomic system: '<S3>/CANBUSOFFCheck' */
#if DIAGDIS_CANBUSOFF == 0

void DTC_CANCheck_CANBUSOFFCheck(void)
{
  /* Chart: '<S3>/CANBUSOFFCheck' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   *  DataStoreRead: '<S8>/Data Store Read'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Product: '<S7>/Product'
   *  Selector: '<S7>/Selector'
   *  Selector: '<S8>/Selector'
   */
  /* Gateway: CANCheck/CANCheck_BUSOFF/CANBUSOFFCheck */
  /* During: CANCheck/CANCheck_BUSOFF/CANBUSOFFCheck */
  /* Entry Internal: CANCheck/CANCheck_BUSOFF/CANBUSOFFCheck */
  /* Transition: '<S6>:1637' */
  if (SysTaskCANLostDiagPending) {
    /* Transition: '<S6>:1646' */
    if (SysTaskCANPending) {
      /* Transition: '<S6>:1620' */
      if ((((Int32)Fv_SystemCANReciveStatus[CANBUS_BUSOff]) > 0) ||
          (FLEXCAN_LostImpedance)) {
        /* Transition: '<S6>:1609' */
        /* Transition: '<S6>:1627' */
        SysTaskCANBusoffPending = true;
        if(((Int32)Fv_SystemCANReciveStatus[CANBUS_BUSOff]) == 0xAA)//BYD:8锟斤拷BUSOFF锟斤拷录锟斤拷锟斤拷锟斤拷
        {
          DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt = 0U;
          
          if (DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_errcnt < ((UInt16)
              MACRO_CAN_BUSOFFTIME)) {
            /* Transition: '<S6>:1612' */
            /* Transition: '<S6>:1615' */
            DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_errcnt = (UInt16)((Int32)
              (((Int32)DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_errcnt) + 1));
          } else {
            /* Outputs for Function Call SubSystem: '<S6>/DTC_Ctrl_Enabled' */
            /* Transition: '<S6>:1608' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S6>:1641' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_Busoff] = (FailureDiag)(((UInt32)
              DTC_Ctrl_Info_Tab[DTC_CANCOMMcheck_Busoff].Enabled) * ((UInt32)
              FailureDiag_Err));

            /* End of Outputs for SubSystem: '<S6>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S6>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S6>:1644' */
            Fv_FaultClass_CAN = (UInt16)SetU16Fault(Fv_FaultClass_CAN, 0,
              DTC_Ctrl_Info_Tab[DTC_CANCOMMcheck_Busoff].Enabled);

            /* End of Outputs for SubSystem: '<S6>/getDTCEnabled' */
            /* Transition: '<S6>:1619' */
          }
        }
        else
        {
          
        }
        /* Transition: '<S6>:1624' */
      } else {
        /* Transition: '<S6>:1628' */
        DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_errcnt = 0U;
        //BYD要锟斤拷busoff锟街革拷1s锟斤拷锟铰硷拷锟斤拷锟斤拷锟斤拷--TXY--20221125
        if (DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt1 < 50) {
          DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt1 = (UInt16)((Int32)
            (((Int32)DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt1) + 1));
        } else {
          SysTaskCANBusoffPending = false;
        }

        if (DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt < ((UInt16)
             MACRO_CAN_BUSOFFTIME)) {
          /* Transition: '<S6>:1632' */
          /* Transition: '<S6>:1634' */
          DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt = (UInt16)((Int32)
            (((Int32)DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt) + 1));

          /* Transition: '<S6>:1623' */
        } else {
          /* Outputs for Function Call SubSystem: '<S6>/DTC_Ctrl_Enabled' */
          /* Transition: '<S6>:1629' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S6>:1641' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_Busoff] = (FailureDiag)(((UInt32)
            DTC_Ctrl_Info_Tab[DTC_CANCOMMcheck_Busoff].Enabled) * ((UInt32)
            FailureDiag_OK));

          /* End of Outputs for SubSystem: '<S6>/DTC_Ctrl_Enabled' */
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 0);

          /* Transition: '<S6>:1633' */
          /* Transition: '<S6>:1623' */
        }
      }
    } else {
      /* Transition: '<S6>:1617' */
      DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_errcnt = 0U;
      DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt = 0U;
      SysTaskCANBusoffPending = false;

      /* Transition: '<S6>:1614' */
      /* Transition: '<S6>:1633' */
      /* Transition: '<S6>:1623' */
    }
  } else {
    /* Transition: '<S6>:1648' */
    DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_errcnt = 0U;
    DTC_CANCheckrtDW.sf_CANBUSOFFCheck.can_busoff_rcvcnt = 0U;
    Fv_ErrDiagStatus[DTC_CANCOMMcheck_Busoff] = FailureDiag_Default;
    Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 0);

    /* Transition: '<S6>:1649' */
    /* Transition: '<S6>:1614' */
    /* Transition: '<S6>:1633' */
    /* Transition: '<S6>:1623' */
  }

  /* End of Chart: '<S3>/CANBUSOFFCheck' */
}

#endif

/* Function for Chart: '<S9>/CANBUSABSCheck' */
#if DIAGDIS_CANABS == 0

static void DTC_CA_enter_atomic_LostPending(void)
{
  Int32 Fv_SystemCANErrrStatus_tmp;

  /* Entry 'LostPending': '<S20>:2339' */
  Fv_SystemCANErrrStatus_tmp = CANBUS_ABSVs;
  Fv_SystemCANErrrStatus[(Fv_SystemCANErrrStatus_tmp)] = FailureDiag_Default;
  Fv_SystemCANDiagStatus[(Fv_SystemCANErrrStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsLostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 1);
  Fv_SystemCANDataInvalidStatus[(Fv_SystemCANErrrStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsDataInvalid] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 2);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANErrrStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 3);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANErrrStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 4);
  Fv_SystemCANErrrStatus_tmp = CANBUS_ABSWs;
  Fv_SystemCANErrrStatus[(Fv_SystemCANErrrStatus_tmp)] = FailureDiag_Default;
  Fv_SystemCANDiagStatus[(Fv_SystemCANErrrStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsLostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 5);
  Fv_SystemCANDataInvalidStatus[(Fv_SystemCANErrrStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsDataInvalid] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 6);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANErrrStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 7);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANErrrStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 8);
}

#endif

/* Function for Chart: '<S9>/CANBUSABSCheck' */
#if DIAGDIS_CANABS == 0

static void DTC_CANCheck_LostRun(void)
{
  Bool b;
  UInt16 c;
  Int32 tmp;
  Int32 tmp_0;

  /* During 'LostRun': '<S20>:2340' */
  if (!SysTaskCANLostDiagPending) {
    /* Transition: '<S20>:2343' */
    /* Exit Internal 'LostRun': '<S20>:2340' */
    /* Exit Internal 'Diag': '<S20>:1641' */
    DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_LostRun =
      DTC_CAN_IN_NO_ACTIVE_CHILD_c4gh;
    DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_c7_DTC_CANCheck =
      DTC_CANCheck_IN_LostPending;
    DTC_CA_enter_atomic_LostPending();
  } else if (((UInt32)DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_LostRun)
             == DTC_CANCheck_IN_Diag) {
    /* During 'Diag': '<S20>:1641' */
    if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
      /* Transition: '<S20>:1638' */
      /* Exit Internal 'Diag': '<S20>:1641' */
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait;
      DTC_CA_enter_atomic_LostPending();  
    } else {
      /* During 'ABSVsLostComm': '<S20>:2047' */
      /* Transition: '<S20>:2314' */
      /* Transition: '<S20>:2315' */
      b = CAN_Vs_Lost;
      DTC_CANCheck_CANCheckLost(CANBUS_ABSVs, DTC_CANCOMMcheck_ABSVsLostComm,
        ((UInt16)MACRO_CAN_LOSTTIME_ABSVs), ((UInt16)MACRO_CAN_RECVTIME_ABSVs),
        &b);
      CAN_Vs_Lost = b;
      tmp = CANBUS_ABSVs;
      if (Fv_SystemCANDiagStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S20>:2050' */
        if (Fv_IGkeyEffect) {
          /* Transition: '<S20>:2190' */
          /* Transition: '<S20>:2110' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsLostComm] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 1);

          /* Transition: '<S20>:2112' */
        } else {
          /* Transition: '<S20>:2193' */
        }

        /* Transition: '<S20>:2192' */
      } else {
        /* Transition: '<S20>:2052' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsLostComm] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 1);
      }

      /* During 'ABSVsDataInvalid': '<S20>:2007' */
      /* Transition: '<S20>:2317' */
      /* Transition: '<S20>:2318' */
      c = DTC_CANCheckrtDW.VSI_Invalid_time;
      DTC_CANCheck_CANCheckInvalid(CANBUS_ABSVs,
        DTC_CANCOMMcheck_ABSVsDataInvalid, ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.VSI_Invalid_time = c;
      if (Fv_SystemCANDataInvalidStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S20>:2010' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsLostComm] < FailureDiag_Err)
        {
          /* Transition: '<S20>:2231' */
          /* Transition: '<S20>:2233' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsDataInvalid] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 2);

          /* Transition: '<S20>:2236' */
        } else {
          /* Transition: '<S20>:2235' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsDataInvalid] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 2);
        }

        /* Transition: '<S20>:2238' */
      } else {
        /* Transition: '<S20>:2012' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsDataInvalid] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 2);
      }

      /* During 'ABSWsLostComm': '<S20>:2356' */
      /* Transition: '<S20>:2364' */
      /* Transition: '<S20>:2365' */
      b = DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.can_lostws_flag;
      DTC_CANCheck_CANCheckLost(CANBUS_ABSWs, DTC_CANCOMMcheck_ABSWsLostComm,
        ((UInt16)MACRO_CAN_LOSTTIME_ABSWs), ((UInt16)MACRO_CAN_RECVTIME_ABSWs),
        &b);
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.can_lostws_flag = b;
      tmp_0 = CANBUS_ABSWs;
      if (Fv_SystemCANDiagStatus[(tmp_0)] == FailureDiag_Err) {
        /* Transition: '<S20>:2367' */
        if (Fv_IGkeyEffect) {
          /* Transition: '<S20>:2366' */
          /* Transition: '<S20>:2369' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsLostComm] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 5);

          /* Transition: '<S20>:2371' */
        } else {
          /* Transition: '<S20>:2368' */
        }

        /* Transition: '<S20>:2372' */
      } else {
        /* Transition: '<S20>:2370' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsLostComm] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 5);
      }
      b = CAN_Vs_Lost;
      DTC_CANCheck_CANCheckLost(CANBUS_IPB4, DTC_CANCOMMcheck_BrakeLostComm,
        ((UInt16)MACRO_CAN_LOSTTIME_IPB4), ((UInt16)MACRO_CAN_RECVTIME_IPB4),
        &b);
      CAN_Vs_Lost = b;
      if (Fv_SystemCANDiagStatus[(CANBUS_IPB4)] == FailureDiag_Err) {
        /* Transition: '<S20>:2050' */
        if (Fv_IGkeyEffect) {
          /* Transition: '<S20>:2190' */
          /* Transition: '<S20>:2110' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_BrakeLostComm] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 10);

          /* Transition: '<S20>:2112' */
        } else {
          /* Transition: '<S20>:2193' */
        }

        /* Transition: '<S20>:2192' */
      } else {
        /* Transition: '<S20>:2052' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_BrakeLostComm] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 10);
      }
      b = CAN_Vs_Lost;
      DTC_CANCheck_CANCheckLost(CANBUS_IPB7, DTC_CANCOMMcheck_IPB7LostComm,
        ((UInt16)MACRO_CAN_LOSTTIME_IPB7), ((UInt16)MACRO_CAN_RECVTIME_IPB7),
        &b);
      CAN_Vs_Lost = b;
      if (Fv_SystemCANDiagStatus[(CANBUS_IPB7)] == FailureDiag_Err) {
        /* Transition: '<S20>:2050' */
        if (Fv_IGkeyEffect) {
          /* Transition: '<S20>:2190' */
          /* Transition: '<S20>:2110' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB7LostComm] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 10);

          /* Transition: '<S20>:2112' */
        } else {
          /* Transition: '<S20>:2193' */
        }

        /* Transition: '<S20>:2192' */
      } else {
        /* Transition: '<S20>:2052' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB7LostComm] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 10);
      }
      /* During 'ABSWsInvalid': '<S20>:2374' */
      /* Transition: '<S20>:2382' */
      /* Transition: '<S20>:2383' */
      c = DTC_CANCheckrtDW.WSI_Invalid_time;
      DTC_CANCheck_CANCheckInvalid(CANBUS_ABSWs,
        DTC_CANCOMMcheck_ABSWsDataInvalid, ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.WSI_Invalid_time = c;
      if (Fv_SystemCANDataInvalidStatus[(tmp_0)] == FailureDiag_Err) {
        /* Transition: '<S20>:2384' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsLostComm] < FailureDiag_Err)
        {
          /* Transition: '<S20>:2385' */
          /* Transition: '<S20>:2387' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsDataInvalid] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 6);

          /* Transition: '<S20>:2390' */
        } else {
          /* Transition: '<S20>:2388' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsDataInvalid] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 6);
        }

        /* Transition: '<S20>:2389' */
      } else {
        /* Transition: '<S20>:2386' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsDataInvalid] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 6);
      }

      /* During 'ABSVsCRCError': '<S20>:2391' */
      /* Transition: '<S20>:2399' */
      /* Transition: '<S20>:2400' */
      c = DTC_CANCheckrtDW.VSI_CRC_time;
      DTC_CANCheck_CANCheckCrc(CANBUS_ABSVs, DTC_CANCOMMcheck_ABSVsCRCError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.VSI_CRC_time = c;
      if (Fv_SystemCANChecksumErrorStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S20>:2401' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsLostComm] < FailureDiag_Err)
        {
          /* Transition: '<S20>:2402' */
          /* Transition: '<S20>:2405' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCRCError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 3);

          /* Transition: '<S20>:2407' */
        } else {
          /* Transition: '<S20>:2404' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCRCError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 3);
        }

        /* Transition: '<S20>:2406' */
      } else {
        /* Transition: '<S20>:2403' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCRCError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 3);
      }

      /* During 'ABSVsCounterError': '<S20>:2410' */
      /* Transition: '<S20>:2418' */
      /* Transition: '<S20>:2419' */
      c = DTC_CANCheckrtDW.sf_CANBUSABSCheck.VSI_Counter_time;
      DTC_CANCheck_CANCheckCounter(CANBUS_ABSVs, DTC_CANCOMMcheck_ABSVsCounterError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.VSI_Counter_time = c;
      if (Fv_SystemCANCounterErrorStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S20>:2420' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsLostComm] < FailureDiag_Err)
        {
          /* Transition: '<S20>:2421' */
          /* Transition: '<S20>:2424' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCounterError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 4);

          /* Transition: '<S20>:2426' */
        } else {
          /* Transition: '<S20>:2423' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCounterError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 4);
        }

        /* Transition: '<S20>:2425' */
      } else {
        /* Transition: '<S20>:2422' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSVsCounterError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 4);
      }

      /* During 'ABSWsCRCError': '<S20>:2427' */
      /* Transition: '<S20>:2435' */
      /* Transition: '<S20>:2436' */
      c = DTC_CANCheckrtDW.WSI_CRC_time;
      DTC_CANCheck_CANCheckCrc(CANBUS_ABSWs, DTC_CANCOMMcheck_ABSWsCRCError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.WSI_CRC_time = c;
      if (Fv_SystemCANChecksumErrorStatus[(tmp_0)] == FailureDiag_Err) {
        /* Transition: '<S20>:2437' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsLostComm] < FailureDiag_Err)
        {
          /* Transition: '<S20>:2438' */
          /* Transition: '<S20>:2441' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCRCError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 7);

          /* Transition: '<S20>:2443' */
        } else {
          /* Transition: '<S20>:2440' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCRCError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 7);
        }

        /* Transition: '<S20>:2442' */
      } else {
        /* Transition: '<S20>:2439' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCRCError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 7);
      }

      /* During 'ABSWsCounterError': '<S20>:2444' */
      /* Transition: '<S20>:2452' */
      /* Transition: '<S20>:2453' */
      c = DTC_CANCheckrtDW.sf_CANBUSABSCheck.WSI_Counter_time;
      DTC_CANCheck_CANCheckCounter(CANBUS_ABSWs, DTC_CANCOMMcheck_ABSWsCounterError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.WSI_Counter_time = c;
      if (Fv_SystemCANCounterErrorStatus[(tmp_0)] == FailureDiag_Err) {
        /* Transition: '<S20>:2454' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsLostComm] < FailureDiag_Err)
        {
          /* Transition: '<S20>:2455' */
          /* Transition: '<S20>:2458' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCounterError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 8);

          /* Transition: '<S20>:2460' */
        } else {
          /* Transition: '<S20>:2457' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCounterError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 8);
        }

        /* Transition: '<S20>:2459' */
      } else {
        /* Transition: '<S20>:2456' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_ABSWsCounterError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 8);
      }

      /* During 'ABSVsMessageError': '<S20>:2479' */
      /* Transition: '<S20>:2496' */
      if (((Fv_SystemCANDataInvalidStatus[CANBUS_ABSVs] == FailureDiag_Err) ||
           (Fv_SystemCANChecksumErrorStatus[CANBUS_ABSVs] == FailureDiag_Err)) ||
          (Fv_SystemCANCounterErrorStatus[CANBUS_ABSVs] == FailureDiag_Err)) {
        /* Transition: '<S20>:2497' */
        /* Transition: '<S20>:2499' */
        Fv_SystemCANErrrStatus[(tmp)] = FailureDiag_Err;

        /* Transition: '<S20>:2500' */
      } else {
        /* Transition: '<S20>:2498' */
        Fv_SystemCANErrrStatus[(tmp)] = FailureDiag_OK;
      }

      /* Transition: '<S20>:2501' */
      /* During 'ABSWsMessageError': '<S20>:2507' */
      /* Transition: '<S20>:2513' */
      if (((Fv_SystemCANDataInvalidStatus[CANBUS_ABSWs] == FailureDiag_Err) ||
           (Fv_SystemCANChecksumErrorStatus[CANBUS_ABSWs] == FailureDiag_Err)) ||
          (Fv_SystemCANCounterErrorStatus[CANBUS_ABSWs] == FailureDiag_Err)) {
        /* Transition: '<S20>:2514' */
        /* Transition: '<S20>:2516' */
        Fv_SystemCANErrrStatus[(tmp_0)] = FailureDiag_Err;

        /* Transition: '<S20>:2517' */
      } else {
        /* Transition: '<S20>:2515' */
        Fv_SystemCANErrrStatus[(tmp_0)] = FailureDiag_OK;
      }

      /* Transition: '<S20>:2518' */
    }
  } else {
    /* During 'Wait': '<S20>:1640' */
    if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
      /* Transition: '<S20>:1639' */
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Diag;

      /* Entry Internal 'Diag': '<S20>:1641' */
    }
  }
}

#endif

/* System reset for atomic system: '<S9>/CANBUSABSCheck' */
#if DIAGDIS_CANABS == 0

void DTC_CANChe_CANBUSABSCheck_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_c4gh;
  DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_active_c7_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_c7_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_c4gh;
  DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.can_lostws_flag = false;
  DTC_CANCheckrtDW.sf_CANBUSABSCheck.WSI_Counter_time = 0U;
  DTC_CANCheckrtDW.sf_CANBUSABSCheck.VSI_Counter_time = 0U;
}

#endif

/* Output and update for atomic system: '<S9>/CANBUSABSCheck' */
#if DIAGDIS_CANABS == 0

void DTC_CANCheck_CANBUSABSCheck(void)
{
  /* Chart: '<S9>/CANBUSABSCheck' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_ABS/CANBUSABSCheck */
  /* During: CANCheck/CANCheck_Signals/CANCheck_ABS/CANBUSABSCheck */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_active_c7_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_ABS/CANBUSABSCheck */
    DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_active_c7_DTC_CANCheck = 1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_ABS/CANBUSABSCheck */
    /* Transition: '<S20>:2341' */
    DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_c7_DTC_CANCheck =
      DTC_CANCheck_IN_LostPending;
    DTC_CA_enter_atomic_LostPending();
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_c7_DTC_CANCheck)
             == DTC_CANCheck_IN_LostPending) {
    /* During 'LostPending': '<S20>:2339' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S20>:2342' */
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_c7_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun;

      /* Entry Internal 'LostRun': '<S20>:2340' */
      /* Transition: '<S20>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSABSCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait;
    }
  } else {
    DTC_CANCheck_LostRun();
  }

  /* End of Chart: '<S9>/CANBUSABSCheck' */
}

#endif

/* Function for Chart: '<S10>/CANBUSAPACheck' */
#if DIAGDIS_CANAPA == 0

static void D_enter_atomic_LostPending_awjs(void)
{
  Int32 Fv_SystemCANDiagStatus_tmp;

  /* Entry 'LostPending': '<S21>:2344' */
  Fv_SystemCANDiagStatus_tmp = CANBUS_APA;
  Fv_SystemCANDiagStatus[(Fv_SystemCANDiagStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 30);
  Fv_SystemCANDataInvalidStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APADataInvalid] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 31);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 32);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 33);
}

#endif

/* System reset for atomic system: '<S10>/CANBUSAPACheck' */
#if DIAGDIS_CANAPA == 0

void DTC_CANChe_CANBUSAPACheck_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_mifu;
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_active_c72_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_c72_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_mifu;
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_CRC_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_Counter_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_Invalid_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSAPACheck.CAN_APA_Lost = 0;
}

#endif

/* Output and update for atomic system: '<S10>/CANBUSAPACheck' */
#if DIAGDIS_CANAPA == 0

void DTC_CANCheck_CANBUSAPACheck(void)
{
  Bool b;
  UInt16 c;
  Int32 tmp;

  /* Chart: '<S10>/CANBUSAPACheck' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_APA/CANBUSAPACheck */
  /* During: CANCheck/CANCheck_Signals/CANCheck_APA/CANBUSAPACheck */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_active_c72_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_APA/CANBUSAPACheck */
    DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_active_c72_DTC_CANCheck =
      1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_APA/CANBUSAPACheck */
    /* Transition: '<S21>:2341' */
    DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_c72_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_ogzq;
    D_enter_atomic_LostPending_awjs();
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_c72_DTC_CANCheck)
             == DTC_CANChec_IN_LostPending_ogzq) {
    /* During 'LostPending': '<S21>:2344' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S21>:2343' */
      DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_c72_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun_fkde;

      /* Entry Internal 'LostRun': '<S21>:2345' */
      /* Transition: '<S21>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_aah4;
    }
  } else {
    /* During 'LostRun': '<S21>:2345' */
    if (!SysTaskCANLostDiagPending) {
      /* Transition: '<S21>:2342' */
      /* Exit Internal 'LostRun': '<S21>:2345' */
      /* Exit Internal 'Diag': '<S21>:2297' */
      DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_LostRun =
        DTC_CAN_IN_NO_ACTIVE_CHILD_mifu;
      DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_c72_DTC_CANCheck =
        DTC_CANChec_IN_LostPending_ogzq;
      D_enter_atomic_LostPending_awjs();
    } else if (((UInt32)
                DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_LostRun) ==
               DTC_CANCheck_IN_Diag_fdw0) {
      /* During 'Diag': '<S21>:2297' */
      if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S21>:1638' */
        /* Exit Internal 'Diag': '<S21>:2297' */
        DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Wait_aah4;
        D_enter_atomic_LostPending_awjs();  
      } else {
        /* During 'APALostComm': '<S21>:2351' */
        /* Transition: '<S21>:2359' */
        /* Transition: '<S21>:2360' */
        b = (DTC_CANCheckrtDW.sf_CANBUSAPACheck.CAN_APA_Lost != 0);
        DTC_CANCheck_CANCheckLost(CANBUS_APA, DTC_CANCOMMcheck_APALostComm,
          ((UInt16)MACRO_CAN_LOSTTIME_APA), ((UInt16)MACRO_CAN_RECVTIME_APA), &b);
        DTC_CANCheckrtDW.sf_CANBUSAPACheck.CAN_APA_Lost = b ? 1 : 0;
        tmp = CANBUS_APA;
        if (Fv_SystemCANDiagStatus[(tmp)] == FailureDiag_Err) {
          /* Transition: '<S21>:2362' */
          if (Fv_IGkeyEffect) {
            /* Transition: '<S21>:2361' */
            /* Transition: '<S21>:2363' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 30);

            /* Transition: '<S21>:2366' */
          } else {
            /* Transition: '<S21>:2364' */
          }

          /* Transition: '<S21>:2367' */
        } else {
          /* Transition: '<S21>:2365' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 30);
        }

        /* During 'APADataInvalid': '<S21>:2368' */
        /* Transition: '<S21>:2376' */
        /* Transition: '<S21>:2377' */
        c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_Invalid_time;
        DTC_CANCheck_CANCheckInvalid(CANBUS_APA, DTC_CANCOMMcheck_APADataInvalid,
          ((UInt16)MACRO_CAN_CHECKTIME), &c);
        DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_Invalid_time = (UInt16)c;
        if (Fv_SystemCANDataInvalidStatus[(tmp)] == FailureDiag_Err) {
          /* Transition: '<S21>:2378' */
          if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] < FailureDiag_Err)
          {
            /* Transition: '<S21>:2379' */
            /* Transition: '<S21>:2382' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APADataInvalid] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 31);

            /* Transition: '<S21>:2384' */
          } else {
            /* Transition: '<S21>:2381' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APADataInvalid] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 31);
          }

          /* Transition: '<S21>:2383' */
        } else {
          /* Transition: '<S21>:2380' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_APADataInvalid] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 31);
        }

        /* During 'APACRCError': '<S21>:2402' */
        /* Transition: '<S21>:2410' */
        /* Transition: '<S21>:2411' */
        c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_CRC_time;
        DTC_CANCheck_CANCheckCrc(CANBUS_APA, DTC_CANCOMMcheck_APACRCError,
          ((UInt16)MACRO_CAN_CHECKTIME), &c);
        DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_CRC_time = (UInt16)c;
        if (Fv_SystemCANChecksumErrorStatus[(tmp)] == FailureDiag_Err) {
          /* Transition: '<S21>:2412' */
          if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] < FailureDiag_Err)
          {
            /* Transition: '<S21>:2413' */
            /* Transition: '<S21>:2416' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACRCError] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 32);

            /* Transition: '<S21>:2418' */
          } else {
            /* Transition: '<S21>:2415' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACRCError] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 32);
          }

          /* Transition: '<S21>:2417' */
        } else {
          /* Transition: '<S21>:2414' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACRCError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 32);
        }

        /* During 'APACounterError': '<S21>:2385' */
        /* Transition: '<S21>:2393' */
        /* Transition: '<S21>:2394' */
        c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_Counter_time;
        DTC_CANCheck_CANCheckCounter(CANBUS_APA, DTC_CANCOMMcheck_APACounterError,
          ((UInt16)MACRO_CAN_CHECKTIME), &c);
        DTC_CANCheckrtDW.sf_CANBUSAPACheck.APA_Counter_time = (UInt16)c;
        if (Fv_SystemCANCounterErrorStatus[(tmp)] == FailureDiag_Err) {
          /* Transition: '<S21>:2395' */
          if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] < FailureDiag_Err)
          {
            /* Transition: '<S21>:2396' */
            /* Transition: '<S21>:2399' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACounterError] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 33);

            /* Transition: '<S21>:2401' */
          } else {
            /* Transition: '<S21>:2398' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACounterError] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 33);
          }

          /* Transition: '<S21>:2400' */
        } else {
          /* Transition: '<S21>:2397' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACounterError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 33);
        }
      }
    } else {
      /* During 'Wait': '<S21>:1640' */
      if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S21>:1639' */
        DTC_CANCheckrtDW.sf_CANBUSAPACheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Diag_fdw0;

        /* Entry Internal 'Diag': '<S21>:2297' */
      }
    }
  }

  /* End of Chart: '<S10>/CANBUSAPACheck' */
}

#endif

/* System reset for atomic system: '<S11>/CANBUSBCM2Check' */
#if DIAGDIS_CANBCM2 == 0

void DTC_CANChe_CANBUSBCM2Check_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_nkoh;
  DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_active_c70_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_c70_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_nkoh;
  DTC_CANCheckrtDW.sf_CANBUSBCM2Check.can_BCM2_flag = 0;
}

#endif

/* Output and update for atomic system: '<S11>/CANBUSBCM2Check' */
#if DIAGDIS_CANBCM2 == 0

void DTC_CANCheck_CANBUSBCM2Check(void)
{
  Bool b;

  /* Chart: '<S11>/CANBUSBCM2Check' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_BCM2/CANBUSBCM2Check */
  /* During: CANCheck/CANCheck_Signals/CANCheck_BCM2/CANBUSBCM2Check */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_active_c70_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_BCM2/CANBUSBCM2Check */
    DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_active_c70_DTC_CANCheck =
      1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_BCM2/CANBUSBCM2Check */
    /* Transition: '<S22>:2348' */
    DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_c70_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_azpo;

    /* Entry 'LostPending': '<S22>:2346' */
    Fv_SystemCANDiagStatus[CANBUS_BCM2] = FailureDiag_Default;
    Fv_ErrDiagStatus[DTC_CANCOMMcheck_BCM2LostComm] = FailureDiag_Default;
    Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 22);
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_c70_DTC_CANCheck)
             == DTC_CANChec_IN_LostPending_azpo) {
    /* During 'LostPending': '<S22>:2346' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S22>:2349' */
      DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_c70_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun_onv0;

      /* Entry Internal 'LostRun': '<S22>:2347' */
      /* Transition: '<S22>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_a0vx;
    }
  } else {
    /* During 'LostRun': '<S22>:2347' */
    if (!SysTaskCANLostDiagPending) {
      /* Transition: '<S22>:2350' */
      /* Exit Internal 'LostRun': '<S22>:2347' */
      /* Exit Internal 'Diag': '<S22>:2297' */
      DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_LostRun =
        DTC_CAN_IN_NO_ACTIVE_CHILD_nkoh;
      DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_c70_DTC_CANCheck =
        DTC_CANChec_IN_LostPending_azpo;

      /* Entry 'LostPending': '<S22>:2346' */
      Fv_SystemCANDiagStatus[CANBUS_BCM2] = FailureDiag_Default;
      Fv_ErrDiagStatus[DTC_CANCOMMcheck_BCM2LostComm] = FailureDiag_Default;
      Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 22);
    } else if (((UInt32)
                DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_LostRun) ==
               DTC_CANCheck_IN_Diag_ga2w) {
      /* During 'Diag': '<S22>:2297' */
      if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S22>:1638' */
        /* Exit Internal 'Diag': '<S22>:2297' */
        DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Wait_a0vx;
        Fv_SystemCANDiagStatus[CANBUS_BCM2] = FailureDiag_Default;
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_BCM2LostComm] = FailureDiag_Default;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 22);  
      } else {
        /* During 'LostComm': '<S22>:2305' */
        /* Transition: '<S22>:2313' */
        /* Transition: '<S22>:2314' */
        b = (DTC_CANCheckrtDW.sf_CANBUSBCM2Check.can_BCM2_flag != 0);
        DTC_CANCheck_CANCheckLost(CANBUS_BCM2, DTC_CANCOMMcheck_BCM2LostComm,
          ((UInt16)MACRO_CAN_LOSTTIME_BCM2), ((UInt16)MACRO_CAN_RECVTIME_BCM2), &b);
        DTC_CANCheckrtDW.sf_CANBUSBCM2Check.can_BCM2_flag = b ? 1 : 0;
        if (Fv_SystemCANDiagStatus[CANBUS_BCM2] == FailureDiag_Err) {
          /* Transition: '<S22>:2316' */
          if (Fv_IGkeyEffect) {
            /* Transition: '<S22>:2315' */
            /* Transition: '<S22>:2318' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_BCM2LostComm] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 22);

            /* Transition: '<S22>:2320' */
          } else {
            /* Transition: '<S22>:2317' */
          }

          /* Transition: '<S22>:2321' */
        } else {
          /* Transition: '<S22>:2319' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_BCM2LostComm] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 22);
        }
      }
    } else {
      /* During 'Wait': '<S22>:1640' */
      if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S22>:1639' */
        DTC_CANCheckrtDW.sf_CANBUSBCM2Check.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Diag_ga2w;

        /* Entry Internal 'Diag': '<S22>:2297' */
      }
    }
  }

  /* End of Chart: '<S11>/CANBUSBCM2Check' */
}

#endif

/* System reset for atomic system: '<S12>/CANBUSEMSCheck' */
#if DIAGDIS_CANEMS == 0

void DTC_CANChe_CANBUSEMSCheck_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_ggrd;
  DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_active_c71_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_c71_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_ggrd;
  DTC_CANCheckrtDW.sf_CANBUSEMSCheck.CAN_CCU2_Lost = 0;
  DTC_CANCheckrtDW.sf_CANBUSEMSCheck.CAN_VCU3_Lost = 0;
}

#endif

/* Output and update for atomic system: '<S12>/CANBUSEMSCheck' */
#if DIAGDIS_CANEMS == 0

void DTC_CANCheck_CANBUSEMSCheck(void)
{
  Bool b;
  Bool d;

  /* Chart: '<S12>/CANBUSEMSCheck' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_EMS/CANBUSEMSCheck */
  /* During: CANCheck/CANCheck_Signals/CANCheck_EMS/CANBUSEMSCheck */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_active_c71_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_EMS/CANBUSEMSCheck */
    DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_active_c71_DTC_CANCheck =
      1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_EMS/CANBUSEMSCheck */
    /* Transition: '<S23>:2377' */
    DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_c71_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_aql5;

    /* Entry 'LostPending': '<S23>:2375' */
    Fv_SystemCANDiagStatus[CANBUS_EMSEt] = FailureDiag_Default;
    Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU3LostComm] = FailureDiag_Default;
    Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 19);
    Fv_SystemCANDiagStatus[CANBUS_CCU2] = FailureDiag_Default;
    Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU2LostComm] = FailureDiag_Default;
    Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 20);
    Fv_SystemCANDiagStatus[CANBUS_VCU3] = FailureDiag_Default;
    Fv_ErrDiagStatus[DTC_CANCOMMcheck_VCU3LostComm] = FailureDiag_Default;
    Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 21);
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_c71_DTC_CANCheck)
             == DTC_CANChec_IN_LostPending_aql5) {
    /* During 'LostPending': '<S23>:2375' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S23>:2378' */
      DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_c71_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun_jsy5;

      /* Entry Internal 'LostRun': '<S23>:2376' */
      /* Transition: '<S23>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_obpa;
    }
  } else {
    /* During 'LostRun': '<S23>:2376' */
    if (!SysTaskCANLostDiagPending) {
      /* Transition: '<S23>:2379' */
      /* Exit Internal 'LostRun': '<S23>:2376' */
      /* Exit Internal 'Diag': '<S23>:2331' */
      DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_LostRun =
        DTC_CAN_IN_NO_ACTIVE_CHILD_ggrd;
      DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_c71_DTC_CANCheck =
        DTC_CANChec_IN_LostPending_aql5;

      /* Entry 'LostPending': '<S23>:2375' */
      Fv_SystemCANDiagStatus[CANBUS_EMSEt] = FailureDiag_Default;
      Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU3LostComm] = FailureDiag_Default;
      Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 19);
      Fv_SystemCANDiagStatus[CANBUS_CCU2] = FailureDiag_Default;
      Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU2LostComm] = FailureDiag_Default;
      Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 20);
      Fv_SystemCANDiagStatus[CANBUS_VCU3] = FailureDiag_Default;
      Fv_ErrDiagStatus[DTC_CANCOMMcheck_VCU3LostComm] = FailureDiag_Default;
      Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 21);
    } else if (((UInt32)
                DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_LostRun) ==
               DTC_CANCheck_IN_Diag_ojue) {
      /* During 'Diag': '<S23>:2331' */
      if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S23>:1638' */
        /* Exit Internal 'Diag': '<S23>:2331' */
        DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Wait_obpa;
        Fv_SystemCANDiagStatus[CANBUS_EMSEt] = FailureDiag_Default;
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU3LostComm] = FailureDiag_Default;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 19);
        Fv_SystemCANDiagStatus[CANBUS_CCU2] = FailureDiag_Default;
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU2LostComm] = FailureDiag_Default;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 20);
        Fv_SystemCANDiagStatus[CANBUS_VCU3] = FailureDiag_Default;
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_VCU3LostComm] = FailureDiag_Default;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 21);          
      } else {
        /* During 'CCU3LostComm': '<S23>:2339' */
        /* Transition: '<S23>:2347' */
        /* Transition: '<S23>:2348' */
        d = CAN_Es_Lost;
        DTC_CANCheck_CANCheckLost(CANBUS_EMSEt, DTC_CANCOMMcheck_CCU3LostComm,
          ((UInt16)MACRO_CAN_LOSTTIME_CCU3), ((UInt16)MACRO_CAN_RECVTIME_CCU3),
          &d);
        CAN_Es_Lost = d;
        if (Fv_SystemCANDiagStatus[CANBUS_EMSEt] == FailureDiag_Err) {
          /* Transition: '<S23>:2350' */
          if (Fv_IGkeyEffect) {
            /* Transition: '<S23>:2349' */
            /* Transition: '<S23>:2352' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU3LostComm] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 19);

            /* Transition: '<S23>:2354' */
          } else {
            /* Transition: '<S23>:2351' */
          }

          /* Transition: '<S23>:2355' */
        } else {
          /* Transition: '<S23>:2353' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU3LostComm] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 19);
        }
        /*RSC锟斤拷锟杰癸拷锟斤拷锟斤拷CCU2锟斤拷锟斤拷锟斤拷锟�--TXY--20230711*/
        if(fsRCSFuncCfg)
        {
          /* During 'CCU2LostComm': '<S23>:2389' */
          /* Transition: '<S23>:2397' */
          /* Transition: '<S23>:2398' */
          b = (DTC_CANCheckrtDW.sf_CANBUSEMSCheck.CAN_CCU2_Lost != 0);
          DTC_CANCheck_CANCheckLost(CANBUS_CCU2, DTC_CANCOMMcheck_CCU2LostComm,
            ((UInt16)MACRO_CAN_LOSTTIME_CCU2), ((UInt16)MACRO_CAN_RECVTIME_CCU2),
            &b);
          DTC_CANCheckrtDW.sf_CANBUSEMSCheck.CAN_CCU2_Lost = b ? 1 : 0;
          if (Fv_SystemCANDiagStatus[CANBUS_CCU2] == FailureDiag_Err) {
            /* Transition: '<S23>:2400' */
            if (Fv_IGkeyEffect) {
              /* Transition: '<S23>:2399' */
              /* Transition: '<S23>:2401' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU2LostComm] = FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 20);

              /* Transition: '<S23>:2404' */
            } else {
              /* Transition: '<S23>:2402' */
            }

            /* Transition: '<S23>:2405' */
          } else {
            /* Transition: '<S23>:2403' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU2LostComm] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 20);
          }
          
        }
        /* During 'VCU3LostComm': '<S23>:2406' */
        /* Transition: '<S23>:2414' */
        /* Transition: '<S23>:2415' */
        b = (DTC_CANCheckrtDW.sf_CANBUSEMSCheck.CAN_VCU3_Lost != 0);
        DTC_CANCheck_CANCheckLost(CANBUS_VCU3, DTC_CANCOMMcheck_VCU3LostComm,
          ((UInt16)MACRO_CAN_LOSTTIME_VCU3), ((UInt16)MACRO_CAN_RECVTIME_VCU3),
          &b);
        DTC_CANCheckrtDW.sf_CANBUSEMSCheck.CAN_VCU3_Lost = b ? 1 : 0;
        Fv_SystemCANDiagStatus[CANBUS_VCU3] = FailureDiag_OK;//SUEA 锟斤拷0x240锟斤拷锟侥ｏ拷锟斤拷锟斤拷锟斤拷乇锟�-WSY20230308
        if (Fv_SystemCANDiagStatus[CANBUS_VCU3] == FailureDiag_Err) {
          /* Transition: '<S23>:2417' */
          if (Fv_IGkeyEffect) {
            /* Transition: '<S23>:2416' */
            /* Transition: '<S23>:2418' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_VCU3LostComm] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 21);

            /* Transition: '<S23>:2421' */
          } else {
            /* Transition: '<S23>:2419' */
          }

          /* Transition: '<S23>:2422' */
        } else {
          /* Transition: '<S23>:2420' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_VCU3LostComm] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 21);
        }
      }
    } else {
      /* During 'Wait': '<S23>:1640' */
      if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S23>:1639' */
        DTC_CANCheckrtDW.sf_CANBUSEMSCheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Diag_ojue;

        /* Entry Internal 'Diag': '<S23>:2331' */
      }
    }
  }

  /* End of Chart: '<S12>/CANBUSEMSCheck' */
}

#endif

void DTC_CANCheck_CANBUSCCU1Check(void)
{
    Bool d;
    /* During 'CCU3LostComm': '<S23>:2339' */
	/* Transition: '<S23>:2347' */
	/* Transition: '<S23>:2348' */
	d = CAN_Es_Lost;
	DTC_CANCheck_CANCheckLost(CANBUS_CCU1, DTC_CANCOMMcheck_CCU1LostComm,
	  ((UInt16)MACRO_CAN_LOSTTIME_CCU1), ((UInt16)MACRO_CAN_RECVTIME_CCU1),
	  &d);
	CAN_Es_Lost = d;
	if(CAN_BCM2Message_Diag_Pending == TRUE)
	{
	  Fv_SystemCANDiagStatus[CANBUS_CCU1] = FailureDiag_OK;
	}
	if (Fv_SystemCANDiagStatus[CANBUS_CCU1] == FailureDiag_Err) {
	  /* Transition: '<S23>:2350' */
	  if (Fv_IGkeyEffect) {
		/* Transition: '<S23>:2349' */
		/* Transition: '<S23>:2352' */
		Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU1LostComm] = FailureDiag_Err;
		Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 19);

		/* Transition: '<S23>:2354' */
	  } else {
		/* Transition: '<S23>:2351' */
	  }

	  /* Transition: '<S23>:2355' */
	} else {
	  /* Transition: '<S23>:2353' */
	  Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU1LostComm] = FailureDiag_OK;
	  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 19);
	}
}
/* Function for Chart: '<S13>/CANBUSIPBCheck' */
#if DIAGDIS_CANIPB == 0

static void D_enter_atomic_LostPending_mjcq(void)
{
  Int32 Fv_SystemCANDiagStatus_tmp;

  /* Entry 'LostPending': '<S24>:2339' */
  Fv_SystemCANDiagStatus_tmp = CANBUS_IPB2;
  Fv_SystemCANDiagStatus[(Fv_SystemCANDiagStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2LostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 9);
  Fv_SystemCANDataInvalidStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2DataInvalid] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 10);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 11);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 12);
  Fv_SystemCANDiagStatus_tmp = CANBUS_IPB5;
  Fv_SystemCANDiagStatus[(Fv_SystemCANDiagStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5LostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 13);
  Fv_SystemCANDataInvalidStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5DataInvalid] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 14);
  Fv_SystemCANDiagStatus_tmp = CANBUS_IPB6;
  Fv_SystemCANDiagStatus[(Fv_SystemCANDiagStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6LostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 15);
  Fv_SystemCANDataInvalidStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6DataInvalid] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 16);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 17);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 18);
}

#endif

/* Function for Chart: '<S13>/CANBUSIPBCheck' */
#if DIAGDIS_CANIPB == 0

static void DTC_CANCheck_LostRun_n1yi(void)
{
  Bool b;
  UInt16 c;
  Int32 tmp;
  Int32 tmp_0;

  /* During 'LostRun': '<S24>:2340' */
  if (!SysTaskCANLostDiagPending) {
    /* Transition: '<S24>:2343' */
    /* Exit Internal 'LostRun': '<S24>:2340' */
    /* Exit Internal 'Diag': '<S24>:1641' */
    DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_LostRun =
      DTC_CAN_IN_NO_ACTIVE_CHILD_oely;
    DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_c69_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_dht2;
    D_enter_atomic_LostPending_mjcq();
  } else if (((UInt32)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_LostRun)
             == DTC_CANCheck_IN_Diag_fnrc) {
    /* During 'Diag': '<S24>:1641' */
    if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
      /* Transition: '<S24>:1638' */
      /* Exit Internal 'Diag': '<S24>:1641' */
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_k1we;
      D_enter_atomic_LostPending_mjcq();  
    } else {
      /* During 'IPB2LostComm': '<S24>:2047' */
      /* Transition: '<S24>:2314' */
      /* Transition: '<S24>:2315' */
      b = (DTC_CANCheckrtDW.sf_CANBUSIPBCheck.CAN_IPB2_Lost != 0);
      DTC_CANCheck_CANCheckLost(CANBUS_IPB2, DTC_CANCOMMcheck_IPB2LostComm,
        ((UInt16)MACRO_CAN_LOSTTIME_IPB2), ((UInt16)MACRO_CAN_RECVTIME_IPB2), &b);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.CAN_IPB2_Lost = b ? 1 : 0;
      tmp = CANBUS_IPB2;
      if (Fv_SystemCANDiagStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2050' */
        if (Fv_IGkeyEffect) {
          /* Transition: '<S24>:2190' */
          /* Transition: '<S24>:2110' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2LostComm] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 9);

          /* Transition: '<S24>:2112' */
        } else {
          /* Transition: '<S24>:2193' */
        }

        /* Transition: '<S24>:2192' */
      } else {
        /* Transition: '<S24>:2052' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2LostComm] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 9);
      }

      /* During 'IPB2DataInvalid': '<S24>:2007' */
      /* Transition: '<S24>:2317' */
      /* Transition: '<S24>:2318' */
      c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_Invalid_time;
      DTC_CANCheck_CANCheckInvalid(CANBUS_IPB2, DTC_CANCOMMcheck_IPB2DataInvalid,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_Invalid_time = (UInt16)c;
      if (Fv_SystemCANDataInvalidStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2010' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2LostComm] < FailureDiag_Err) {
          /* Transition: '<S24>:2231' */
          /* Transition: '<S24>:2233' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2DataInvalid] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 10);

          /* Transition: '<S24>:2236' */
        } else {
          /* Transition: '<S24>:2235' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2DataInvalid] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 10);
        }

        /* Transition: '<S24>:2238' */
      } else {
        /* Transition: '<S24>:2012' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2DataInvalid] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 10);
      }
      if(fsDSTFuncCfg == TRUE)   //0x10A鎶ユ枃鏃犻渶涓嶥ST閰嶇疆鍏宠仈
      {
        /* During 'IPB5LostComm': '<S24>:2356' */
        /* Transition: '<S24>:2364' */
        /* Transition: '<S24>:2365' */
        b = (DTC_CANCheckrtDW.sf_CANBUSIPBCheck.can_IPB5_flag != 0);
        DTC_CANCheck_CANCheckLost(CANBUS_IPB5, DTC_CANCOMMcheck_IPB5LostComm,
          ((UInt16)MACRO_CAN_LOSTTIME_IPB5), ((UInt16)MACRO_CAN_RECVTIME_IPB5), &b);
        DTC_CANCheckrtDW.sf_CANBUSIPBCheck.can_IPB5_flag = b ? 1 : 0;
        tmp_0 = CANBUS_IPB5;
        if (Fv_SystemCANDiagStatus[(tmp_0)] == FailureDiag_Err) {
          /* Transition: '<S24>:2367' */
          if (Fv_IGkeyEffect) {
            /* Transition: '<S24>:2366' */
            /* Transition: '<S24>:2369' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5LostComm] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 13);

            /* Transition: '<S24>:2371' */
          } else {
            /* Transition: '<S24>:2368' */
          }

          /* Transition: '<S24>:2372' */
        } else {
          /* Transition: '<S24>:2370' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5LostComm] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 13);
        }

        /* During 'IPB5Invalid': '<S24>:2374' */
        /* Transition: '<S24>:2382' */
        /* Transition: '<S24>:2383' */
        c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB5_Invalid_time;
        DTC_CANCheck_CANCheckInvalid(CANBUS_IPB5, DTC_CANCOMMcheck_IPB5DataInvalid,
          ((UInt16)MACRO_CAN_CHECKTIME), &c);
        DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB5_Invalid_time = (Float64)c;
        if (Fv_SystemCANDataInvalidStatus[(tmp_0)] == FailureDiag_Err) {
          /* Transition: '<S24>:2384' */
          if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5LostComm] < FailureDiag_Err) {
            /* Transition: '<S24>:2385' */
            /* Transition: '<S24>:2387' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5DataInvalid] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 14);

            /* Transition: '<S24>:2390' */
          } else {
            /* Transition: '<S24>:2388' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5DataInvalid] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 14);
          }

          /* Transition: '<S24>:2389' */
        } else {
          /* Transition: '<S24>:2386' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB5DataInvalid] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 14);
        }
      }
      /* During 'IPB2CRCError': '<S24>:2391' */
      /* Transition: '<S24>:2399' */
      /* Transition: '<S24>:2400' */
      c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_CRC_time;
      DTC_CANCheck_CANCheckCrc(CANBUS_IPB2, DTC_CANCOMMcheck_IPB2CRCError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_CRC_time = (UInt16)c;
      if (Fv_SystemCANChecksumErrorStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2401' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2LostComm] < FailureDiag_Err) {
          /* Transition: '<S24>:2402' */
          /* Transition: '<S24>:2405' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CRCError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 11);

          /* Transition: '<S24>:2407' */
        } else {
          /* Transition: '<S24>:2404' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CRCError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 11);
        }

        /* Transition: '<S24>:2406' */
      } else {
        /* Transition: '<S24>:2403' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CRCError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 11);
      }

      /* During 'IPB2CounterError': '<S24>:2410' */
      /* Transition: '<S24>:2418' */
      /* Transition: '<S24>:2419' */
      c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_Counter_time;
      DTC_CANCheck_CANCheckCounter(CANBUS_IPB2, DTC_CANCOMMcheck_IPB2CounterError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_Counter_time = (UInt16)c;
      if (Fv_SystemCANCounterErrorStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2420' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2LostComm] < FailureDiag_Err) {
          /* Transition: '<S24>:2421' */
          /* Transition: '<S24>:2424' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CounterError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 12);

          /* Transition: '<S24>:2426' */
        } else {
          /* Transition: '<S24>:2423' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CounterError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 12);
        }

        /* Transition: '<S24>:2425' */
      } else {
        /* Transition: '<S24>:2422' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB2CounterError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 12);
      }
#if 0
      /*IPB6锟斤拷锟斤拷锟斤拷瞎锟斤拷锟斤拷锟紻ST锟斤拷锟斤拷--TXY--20221124*/
      /* During 'IPB6LostComm': '<S24>:2464' */
      /* Transition: '<S24>:2472' */
      /* Transition: '<S24>:2473' */
      b = (DTC_CANCheckrtDW.sf_CANBUSIPBCheck.can_IPB6_flag != 0);
      DTC_CANCheck_CANCheckLost(CANBUS_IPB6, DTC_CANCOMMcheck_IPB6LostComm,
        ((UInt16)MACRO_CAN_LOSTTIME_IPB6), ((UInt16)MACRO_CAN_RECVTIME_IPB6), &b);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.can_IPB6_flag = b ? 1 : 0;
      tmp = CANBUS_IPB6;
      if (Fv_SystemCANDiagStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2475' */
        if (Fv_IGkeyEffect) {
          /* Transition: '<S24>:2474' */
          /* Transition: '<S24>:2476' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6LostComm] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 15);

          /* Transition: '<S24>:2479' */
        } else {
          /* Transition: '<S24>:2477' */
        }

        /* Transition: '<S24>:2480' */
      } else {
        /* Transition: '<S24>:2478' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6LostComm] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 15);
      }

      /* During 'IPB6Invalid': '<S24>:2481' */
      /* Transition: '<S24>:2489' */
      /* Transition: '<S24>:2490' */
      c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_Invalid_time;
      DTC_CANCheck_CANCheckInvalid(CANBUS_IPB6, DTC_CANCOMMcheck_IPB6DataInvalid,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_Invalid_time = (UInt16)c;
      if (Fv_SystemCANDataInvalidStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2491' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6LostComm] < FailureDiag_Err) {
          /* Transition: '<S24>:2492' */
          /* Transition: '<S24>:2495' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6DataInvalid] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 16);

          /* Transition: '<S24>:2497' */
        } else {
          /* Transition: '<S24>:2494' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6DataInvalid] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 16);
        }

        /* Transition: '<S24>:2496' */
      } else {
        /* Transition: '<S24>:2493' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6DataInvalid] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 16);
      }

      /* During 'IPB6CRCError': '<S24>:2498' */
      /* Transition: '<S24>:2506' */
      /* Transition: '<S24>:2507' */
      c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_CRC_time;
      DTC_CANCheck_CANCheckCrc(CANBUS_IPB6, DTC_CANCOMMcheck_IPB6CRCError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_CRC_time = (UInt16)c;
      if (Fv_SystemCANChecksumErrorStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2508' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6LostComm] < FailureDiag_Err) {
          /* Transition: '<S24>:2509' */
          /* Transition: '<S24>:2512' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CRCError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 17);

          /* Transition: '<S24>:2514' */
        } else {
          /* Transition: '<S24>:2511' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CRCError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 17);
        }

        /* Transition: '<S24>:2513' */
      } else {
        /* Transition: '<S24>:2510' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CRCError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 17);
      }

      /* During 'IPB6CounterError': '<S24>:2515' */
      /* Transition: '<S24>:2523' */
      /* Transition: '<S24>:2524' */
      c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_Counter_time;
      DTC_CANCheck_CANCheckCounter(CANBUS_IPB6, DTC_CANCOMMcheck_IPB6CounterError,
        ((UInt16)MACRO_CAN_CHECKTIME), &c);
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_Counter_time = (UInt16)c;
      if (Fv_SystemCANCounterErrorStatus[(tmp)] == FailureDiag_Err) {
        /* Transition: '<S24>:2525' */
        if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6LostComm] < FailureDiag_Err) {
          /* Transition: '<S24>:2526' */
          /* Transition: '<S24>:2529' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CounterError] = FailureDiag_Err;
          Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 18);

          /* Transition: '<S24>:2531' */
        } else {
          /* Transition: '<S24>:2528' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CounterError] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 18);
        }

        /* Transition: '<S24>:2530' */
      } else {
        /* Transition: '<S24>:2527' */
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_IPB6CounterError] = FailureDiag_OK;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 18);
      }
#endif
    }
  } else {
    /* During 'Wait': '<S24>:1640' */
    if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
      /* Transition: '<S24>:1639' */
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Diag_fnrc;

      /* Entry Internal 'Diag': '<S24>:1641' */
    }
  }
}

#endif

/* System reset for atomic system: '<S13>/CANBUSIPBCheck' */
#if DIAGDIS_CANIPB == 0

void DTC_CANChe_CANBUSIPBCheck_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_oely;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_active_c69_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_c69_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_oely;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.CAN_IPB2_Lost = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_CRC_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_Counter_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB2_Invalid_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB5_Invalid_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_CRC_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_Counter_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.IPB6_Invalid_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.can_IPB5_flag = 0;
  DTC_CANCheckrtDW.sf_CANBUSIPBCheck.can_IPB6_flag = 0;
}

#endif

/* Output and update for atomic system: '<S13>/CANBUSIPBCheck' */
#if DIAGDIS_CANIPB == 0

void DTC_CANCheck_CANBUSIPBCheck(void)
{
  /* Chart: '<S13>/CANBUSIPBCheck' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_IPB/CANBUSIPBCheck */
  /* During: CANCheck/CANCheck_Signals/CANCheck_IPB/CANBUSIPBCheck */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_active_c69_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_IPB/CANBUSIPBCheck */
    DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_active_c69_DTC_CANCheck =
      1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_IPB/CANBUSIPBCheck */
    /* Transition: '<S24>:2341' */
    DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_c69_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_dht2;
    D_enter_atomic_LostPending_mjcq();
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_c69_DTC_CANCheck)
             == DTC_CANChec_IN_LostPending_dht2) {
    /* During 'LostPending': '<S24>:2339' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S24>:2342' */
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_c69_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun_pzwt;

      /* Entry Internal 'LostRun': '<S24>:2340' */
      /* Transition: '<S24>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSIPBCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_k1we;
    }
  } else {
    DTC_CANCheck_LostRun_n1yi();
  }

  /* End of Chart: '<S13>/CANBUSIPBCheck' */
}

#endif

/* Function for Chart: '<S14>/CANBUSMPCCheck' */
#if DIAGDIS_CANMPC == 0

static void D_enter_atomic_LostPending_bnlk(void)
{
  Int32 Fv_SystemCANDiagStatus_tmp;

  /* Entry 'LostPending': '<S25>:2340' */
  Fv_SystemCANDiagStatus_tmp = CANBUS_ADS2;
  Fv_SystemCANDiagStatus[(Fv_SystemCANDiagStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2LostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 24);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 25);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 26);
  Fv_SystemCANDiagStatus_tmp = CANBUS_ADS1;
  Fv_SystemCANDiagStatus[(Fv_SystemCANDiagStatus_tmp)] = FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1LostComm] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 27);
  Fv_SystemCANChecksumErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CRCError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 28);
  Fv_SystemCANCounterErrorStatus[(Fv_SystemCANDiagStatus_tmp)] =
    FailureDiag_Default;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CounterError] = FailureDiag_Default;
  Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 29);
}

#endif

/* System reset for atomic system: '<S14>/CANBUSMPCCheck' */
#if DIAGDIS_CANMPC == 0

void DTC_CANChe_CANBUSMPCCheck_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_asfw;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_active_c2_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_c2_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_asfw;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS2_CRC_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS2_Counter_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS1_CRC_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS1_Counter_time = 0;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.can_ADS2_flag = 0;
  DTC_CANCheckrtDW.sf_CANBUSMPCCheck.can_ADS1_flag = 0;
}

#endif

/* Output and update for atomic system: '<S14>/CANBUSMPCCheck' */
#if DIAGDIS_CANMPC == 0

void DTC_CANCheck_CANBUSMPCCheck(void)
{
  Bool b;
  UInt16 c;
  Int32 tmp;

  /* Chart: '<S14>/CANBUSMPCCheck' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_MPC/CANBUSMPCCheck */
  /* During: CANCheck/CANCheck_Signals/CANCheck_MPC/CANBUSMPCCheck */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_active_c2_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_MPC/CANBUSMPCCheck */
    DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_active_c2_DTC_CANCheck = 1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_MPC/CANBUSMPCCheck */
    /* Transition: '<S25>:2338' */
    DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_c2_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_puy2;
    D_enter_atomic_LostPending_bnlk();
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_c2_DTC_CANCheck)
             == DTC_CANChec_IN_LostPending_puy2) {
    /* During 'LostPending': '<S25>:2340' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S25>:2339' */
      DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_c2_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun_gqxl;

      /* Entry Internal 'LostRun': '<S25>:2341' */
      /* Transition: '<S25>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_o0r3;
    }
  } else {
    /* During 'LostRun': '<S25>:2341' */
    if (!SysTaskCANLostDiagPending) {
      /* Transition: '<S25>:2337' */
      /* Exit Internal 'LostRun': '<S25>:2341' */
      /* Exit Internal 'Diag': '<S25>:2297' */
      DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_LostRun =
        DTC_CAN_IN_NO_ACTIVE_CHILD_asfw;
      DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_c2_DTC_CANCheck =
        DTC_CANChec_IN_LostPending_puy2;
      D_enter_atomic_LostPending_bnlk();
    } else if (((UInt32)
                DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_LostRun) ==
               DTC_CANCheck_IN_Diag_ctnm) {
      /* During 'Diag': '<S25>:2297' */
      if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S25>:1638' */
        /* Exit Internal 'Diag': '<S25>:2297' */
        DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Wait_o0r3;
        D_enter_atomic_LostPending_bnlk();  
      } else {
        /*ADS2锟斤拷锟斤拷锟斤拷瞎锟斤拷锟斤拷锟絃DW锟斤拷锟斤拷--TXY--20221124*/
        if(fsLDWFuncCfg == TRUE)
        {
          /* During 'ADS2LostComm': '<S25>:2302' */
          /* Transition: '<S25>:2310' */
          /* Transition: '<S25>:2311' */
          b = (DTC_CANCheckrtDW.sf_CANBUSMPCCheck.can_ADS2_flag != 0);
          DTC_CANCheck_CANCheckLost(CANBUS_ADS2, DTC_CANCOMMcheck_ADS2LostComm,
            ((UInt16)MACRO_CAN_LOSTTIME_ADS2), ((UInt16)MACRO_CAN_RECVTIME_ADS2),
            &b);
          DTC_CANCheckrtDW.sf_CANBUSMPCCheck.can_ADS2_flag = b ? 1 : 0;
          tmp = CANBUS_ADS2;
          if (Fv_SystemCANDiagStatus[(tmp)] == FailureDiag_Err) {
            /* Transition: '<S25>:2313' */
            if (Fv_IGkeyEffect) {
              /* Transition: '<S25>:2312' */
              /* Transition: '<S25>:2315' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2LostComm] = FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 24);

              /* Transition: '<S25>:2317' */
            } else {
              /* Transition: '<S25>:2314' */
            }

            /* Transition: '<S25>:2318' */
          } else {
            /* Transition: '<S25>:2316' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2LostComm] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 24);
          }

          /* During 'ADS2CRCError': '<S25>:2381' */
          /* Transition: '<S25>:2389' */
          /* Transition: '<S25>:2390' */
          c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS2_CRC_time;
          DTC_CANCheck_CANCheckCrc(CANBUS_ADS2, DTC_CANCOMMcheck_ADS2CRCError,
            ((UInt16)MACRO_CAN_CHECKTIME), &c);
          DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS2_CRC_time = (UInt16)c;
          if (Fv_SystemCANChecksumErrorStatus[(tmp)] == FailureDiag_Err) {
            /* Transition: '<S25>:2391' */
            if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2LostComm] < FailureDiag_Err)
            {
              /* Transition: '<S25>:2392' */
              /* Transition: '<S25>:2395' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CRCError] = FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 25);

              /* Transition: '<S25>:2397' */
            } else {
              /* Transition: '<S25>:2394' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CRCError] = FailureDiag_OK;
              Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 25);
            }

            /* Transition: '<S25>:2396' */
          } else {
            /* Transition: '<S25>:2393' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CRCError] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 25);
          }

          /* During 'ADS2CounterError': '<S25>:2364' */
          /* Transition: '<S25>:2372' */
          /* Transition: '<S25>:2373' */
          c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS2_Counter_time;
          DTC_CANCheck_CANCheckCounter(CANBUS_ADS2, DTC_CANCOMMcheck_ADS2CounterError,
            ((UInt16)MACRO_CAN_CHECKTIME), &c);
          DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS2_Counter_time = (UInt16)c;
          if (Fv_SystemCANCounterErrorStatus[(tmp)] == FailureDiag_Err) {
            /* Transition: '<S25>:2374' */
            if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2LostComm] < FailureDiag_Err)
            {
              /* Transition: '<S25>:2375' */
              /* Transition: '<S25>:2378' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CounterError] =
                FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 26);

              /* Transition: '<S25>:2380' */
            } else {
              /* Transition: '<S25>:2377' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CounterError] = FailureDiag_OK;
              Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 26);
            }

            /* Transition: '<S25>:2379' */
          } else {
            /* Transition: '<S25>:2376' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CounterError] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 26);
          }
        }
        /*ADS1锟斤拷锟斤拷锟斤拷瞎锟斤拷锟斤拷锟絃KA锟斤拷锟斤拷--TXY--20221124*/
        if(fsLKAACFuncCfg == TRUE)
        {
          /* During 'ADS1LostComm': '<S25>:2398' */
          /* Transition: '<S25>:2406' */
          /* Transition: '<S25>:2407' */
          b = (DTC_CANCheckrtDW.sf_CANBUSMPCCheck.can_ADS1_flag != 0);
          DTC_CANCheck_CANCheckLost(CANBUS_ADS1, DTC_CANCOMMcheck_ADS1LostComm,
            ((UInt16)MACRO_CAN_LOSTTIME_ADS1), ((UInt16)MACRO_CAN_RECVTIME_ADS1),
            &b);
          DTC_CANCheckrtDW.sf_CANBUSMPCCheck.can_ADS1_flag = b ? 1 : 0;
          tmp = CANBUS_ADS1;
          if (Fv_SystemCANDiagStatus[(tmp)] == FailureDiag_Err) {
            /* Transition: '<S25>:2409' */
            if (Fv_IGkeyEffect) {
              /* Transition: '<S25>:2408' */
              /* Transition: '<S25>:2410' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1LostComm] = FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 27);

              /* Transition: '<S25>:2413' */
            } else {
              /* Transition: '<S25>:2411' */
            }

            /* Transition: '<S25>:2414' */
          } else {
            /* Transition: '<S25>:2412' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1LostComm] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 27);
          }

          /* During 'ADS1CRCError': '<S25>:2415' */
          /* Transition: '<S25>:2423' */
          /* Transition: '<S25>:2424' */
          c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS1_CRC_time;
          DTC_CANCheck_CANCheckCrc(CANBUS_ADS1, DTC_CANCOMMcheck_ADS1CRCError,
            ((UInt16)MACRO_CAN_CHECKTIME), &c);
          DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS1_CRC_time = (UInt16)c;
          if (Fv_SystemCANChecksumErrorStatus[(tmp)] == FailureDiag_Err) {
            /* Transition: '<S25>:2425' */
            if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1LostComm] < FailureDiag_Err)
            {
              /* Transition: '<S25>:2426' */
              /* Transition: '<S25>:2429' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CRCError] = FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 28);

              /* Transition: '<S25>:2431' */
            } else {
              /* Transition: '<S25>:2428' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CRCError] = FailureDiag_OK;
              Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 28);
            }

            /* Transition: '<S25>:2430' */
          } else {
            /* Transition: '<S25>:2427' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CRCError] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 28);
          }

          /* During 'ADS1CounterError': '<S25>:2432' */
          /* Transition: '<S25>:2440' */
          /* Transition: '<S25>:2441' */
          c = (UInt16)DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS1_Counter_time;
          DTC_CANCheck_CANCheckCounter(CANBUS_ADS1, DTC_CANCOMMcheck_ADS1CounterError,
            ((UInt16)MACRO_CAN_CHECKTIME), &c);
          DTC_CANCheckrtDW.sf_CANBUSMPCCheck.ADS1_Counter_time = (UInt16)c;
          if (Fv_SystemCANCounterErrorStatus[(tmp)] == FailureDiag_Err) {
            /* Transition: '<S25>:2442' */
            if (Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1LostComm] < FailureDiag_Err)
            {
              /* Transition: '<S25>:2443' */
              /* Transition: '<S25>:2446' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CounterError] =
                FailureDiag_Err;
              Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 29);

              /* Transition: '<S25>:2448' */
            } else {
              /* Transition: '<S25>:2445' */
              Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CounterError] = FailureDiag_OK;
              Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 29);
            }

            /* Transition: '<S25>:2447' */
          } else {
            /* Transition: '<S25>:2444' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CounterError] = FailureDiag_OK;
            Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 29);
          }
        }
      }
    } else {
      /* During 'Wait': '<S25>:1640' */
      if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S25>:1639' */
        DTC_CANCheckrtDW.sf_CANBUSMPCCheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Diag_ctnm;

        /* Entry Internal 'Diag': '<S25>:2297' */
      }
    }
  }

  /* End of Chart: '<S14>/CANBUSMPCCheck' */
}

#endif

/* System reset for atomic system: '<S15>/CANBUSSCUCheck' */
#if DIAGDIS_CANSCU == 0

void DTC_CANChe_CANBUSSCUCheck_Reset(void)
{
  DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_LostRun =
    DTC_CAN_IN_NO_ACTIVE_CHILD_cvq3;
  DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_active_c1_DTC_CANCheck = 0;
  DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_c1_DTC_CANCheck =
    DTC_CAN_IN_NO_ACTIVE_CHILD_cvq3;
  DTC_CANCheckrtDW.sf_CANBUSSCUCheck.can_SCU_flag = 0;
}

#endif

/* Output and update for atomic system: '<S15>/CANBUSSCUCheck' */
#if DIAGDIS_CANSCU == 0

void DTC_CANCheck_CANBUSSCUCheck(void)
{
  Bool b;

  /* Chart: '<S15>/CANBUSSCUCheck' */
  /* Gateway: CANCheck/CANCheck_Signals/CANCheck_SCU/CANBUSSCUCheck */
  /* During: CANCheck/CANCheck_Signals/CANCheck_SCU/CANBUSSCUCheck */
  if (((UInt32)
       DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_active_c1_DTC_CANCheck)
      == 0U) {
    /* Entry: CANCheck/CANCheck_Signals/CANCheck_SCU/CANBUSSCUCheck */
    DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_active_c1_DTC_CANCheck = 1;

    /* Entry Internal: CANCheck/CANCheck_Signals/CANCheck_SCU/CANBUSSCUCheck */
    /* Transition: '<S26>:2337' */
    DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_c1_DTC_CANCheck =
      DTC_CANChec_IN_LostPending_ihcn;

    /* Entry 'LostPending': '<S26>:2340' */
    Fv_SystemCANDiagStatus[CANBUS_SCU] = FailureDiag_Default;
    Fv_ErrDiagStatus[DTC_CANCOMMcheck_SCULostComm] = FailureDiag_Default;
    Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 23);
  } else if (((UInt32)
              DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_c1_DTC_CANCheck)
             == DTC_CANChec_IN_LostPending_ihcn) {
    /* During 'LostPending': '<S26>:2340' */
    if (SysTaskCANLostDiagPending) {
      /* Transition: '<S26>:2339' */
      DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_c1_DTC_CANCheck =
        DTC_CANCheck_IN_LostRun_o2p0;

      /* Entry Internal 'LostRun': '<S26>:2341' */
      /* Transition: '<S26>:2006' */
      DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_LostRun =
        DTC_CANCheck_IN_Wait_jxwy;
    }
  } else {
    /* During 'LostRun': '<S26>:2341' */
    if (!SysTaskCANLostDiagPending) {
      /* Transition: '<S26>:2338' */
      /* Exit Internal 'LostRun': '<S26>:2341' */
      /* Exit Internal 'Diag': '<S26>:2297' */
      DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_LostRun =
        DTC_CAN_IN_NO_ACTIVE_CHILD_cvq3;
      DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_c1_DTC_CANCheck =
        DTC_CANChec_IN_LostPending_ihcn;

      /* Entry 'LostPending': '<S26>:2340' */
      Fv_SystemCANDiagStatus[CANBUS_SCU] = FailureDiag_Default;
      Fv_ErrDiagStatus[DTC_CANCOMMcheck_SCULostComm] = FailureDiag_Default;
      Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 23);
    } else if (((UInt32)
                DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_LostRun) ==
               DTC_CANCheck_IN_Diag_cjh2) {
      /* During 'Diag': '<S26>:2297' */
      if ((!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S26>:1638' */
        /* Exit Internal 'Diag': '<S26>:2297' */
        DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Wait_jxwy;
        Fv_SystemCANDiagStatus[CANBUS_SCU] = FailureDiag_Default;
        Fv_ErrDiagStatus[DTC_CANCOMMcheck_SCULostComm] = FailureDiag_Default;
        Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 23);          
      } else {
        /* During 'LostComm': '<S26>:2302' */
        /* Transition: '<S26>:2310' */
        /* Transition: '<S26>:2311' */
        b = (DTC_CANCheckrtDW.sf_CANBUSSCUCheck.can_SCU_flag != 0);
        DTC_CANCheck_CANCheckLost(CANBUS_SCU, DTC_CANCOMMcheck_SCULostComm,
          ((UInt16)MACRO_CAN_LOSTTIME_SCU), ((UInt16)MACRO_CAN_RECVTIME_SCU), &b);
        DTC_CANCheckrtDW.sf_CANBUSSCUCheck.can_SCU_flag = b ? 1 : 0;
        if (Fv_SystemCANDiagStatus[CANBUS_SCU] == FailureDiag_Err) {
          /* Transition: '<S26>:2313' */
          if (Fv_IGkeyEffect) {
            /* Transition: '<S26>:2312' */
            /* Transition: '<S26>:2314' */
            Fv_ErrDiagStatus[DTC_CANCOMMcheck_SCULostComm] = FailureDiag_Err;
            Fv_FaultClass_CAN = (UInt16)SetU16Varit(Fv_FaultClass_CAN, 23);

            /* Transition: '<S26>:2317' */
          } else {
            /* Transition: '<S26>:2315' */
          }

          /* Transition: '<S26>:2318' */
        } else {
          /* Transition: '<S26>:2316' */
          Fv_ErrDiagStatus[DTC_CANCOMMcheck_SCULostComm] = FailureDiag_OK;
          Fv_FaultClass_CAN = (UInt16)ClrU16Varit(Fv_FaultClass_CAN, 23);
        }
      }
    } else {
      /* During 'Wait': '<S26>:1640' */
      if ((SysTaskCANPending) && (!SysTaskCANBusoffPending) && (!CAN_BCM2Message_Diag_Pending)) {
        /* Transition: '<S26>:1639' */
        DTC_CANCheckrtDW.sf_CANBUSSCUCheck.bitsForTID0.is_LostRun =
          DTC_CANCheck_IN_Diag_cjh2;

        /* Entry Internal 'Diag': '<S26>:2297' */
      }
    }
  }

  /* End of Chart: '<S15>/CANBUSSCUCheck' */
}

#endif

/* Output and update for Simulink Function: '<S4>/Simulink Function' */
void DTC_CANCheck_CANCheckLost(CANBUS rtu_bussignal, DTC rtu_dtcindex, UInt16
  rtu_losttime, UInt16 rtu_rectime, Bool *rtuy_can_lost_flag)
{
  Bool rtb_can_lost_flag_i4og;
  Int32 tmp;

  /* Gateway: CANCheck/CANCheck_Signals/Simulink Function/CANCheck_Lost
   */
  /* During: CANCheck/CANCheck_Signals/Simulink Function/CANCheck_Lost
   */
  /* Entry Internal: CANCheck/CANCheck_Signals/Simulink Function/CANCheck_Lost
   */
  /* Transition: '<S27>:2321' */
  /* Transition: '<S27>:2376' */
  rtb_can_lost_flag_i4og = *rtuy_can_lost_flag;

  /* Chart: '<S16>/CANCheck_Lost ' incorporates:
   *  SubSystem: '<S27>/SetInerDTCErr'
   */
  /* Switch: '<S28>/Switch' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtbussignalOutport1'
   */
  tmp = rtu_bussignal;

  /* SignalConversion: '<S16>/TmpSignal ConversionAtlosttimeOutport1' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtrectimeOutport1'
   */
  if (Fv_SystemCANReciveTimer[(tmp)] >= rtu_losttime) {
    /* Transition: '<S27>:2320' */
    /* Transition: '<S27>:2323' */
    rtb_can_lost_flag_i4og = true;

    /* Transition: '<S27>:2328' */
    /* Transition: '<S27>:2327' */
  } else {
    /* Transition: '<S27>:2322' */
    if (Fv_SystemCANReciveTimer[(tmp)] < rtu_rectime) {
      /* Transition: '<S27>:2324' */
      /* Transition: '<S27>:2326' */
      rtb_can_lost_flag_i4og = false;

      /* Transition: '<S27>:2327' */
    } else {
      /* Transition: '<S27>:2325' */
    }
  }

  /* End of SignalConversion: '<S16>/TmpSignal ConversionAtlosttimeOutport1' */
  /* Transition: '<S27>:2329' */
  if (rtb_can_lost_flag_i4og) {
    /* Transition: '<S27>:2342' */
    /* Transition: '<S27>:2344' */
    CAN_LostRecCounter[(tmp)] = ((UInt16)MACRO_CAN_CHECKTIME);

    /* Outputs for Function Call SubSystem: '<S27>/SetInerDTCErr' */
    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S28>/Constant1'
     *  DataStoreRead: '<S28>/Data Store Read'
     *  DataTypeConversion: '<S28>/Data Type Conversion'
     *  Selector: '<S28>/Selector'
     *  SignalConversion: '<S16>/TmpSignal ConversionAtdtcindexOutport1'
     */
    /* Simulink Function 'SetInerDTCErr': '<S27>:2305' */
    if (DTC_Ctrl_Info_Tab[(UInt8)rtu_dtcindex].Enabled > ((UInt8)0U)) {
      Fv_SystemCANDiagStatus[(tmp)] = FailureDiag_Err;
    } else {
      Fv_SystemCANDiagStatus[(tmp)] = FailureDiag_Default;
    }

    /* End of Outputs for SubSystem: '<S27>/SetInerDTCErr' */
    /* Transition: '<S27>:2353' */
    /* Transition: '<S27>:2354' */
  } else {
    /* Transition: '<S27>:2346' */
    if (((Int32)CAN_LostRecCounter[(tmp)]) > 0) {
      /* Transition: '<S27>:2348' */
      /* Transition: '<S27>:2350' */
      CAN_LostRecCounter[(tmp)] = (UInt16)((Int32)(((Int32)CAN_LostRecCounter
        [(tmp)]) - 1));

      /* Transition: '<S27>:2354' */
    } else {
      /* Transition: '<S27>:2352' */
      Fv_SystemCANDiagStatus[(tmp)] = FailureDiag_OK;
    }
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtcan_lost_flag~Inport1' */
  /* Transition: '<S27>:2372' */
  *rtuy_can_lost_flag = rtb_can_lost_flag_i4og;
}

/* Output and update for Simulink Function: '<S4>/Simulink Function1' */
void DTC_CANCheck_CANCheckInvalid(CANBUS rtu_bussignal, DTC rtu_dtcindex, UInt16
  rtu_checktime, UInt16 *rtuy_vsl_cnt)
{
  Int32 tmp;

  /* Chart: '<S17>/CANCheck_Invalid ' incorporates:
   *  SubSystem: '<S29>/SetInerDTCErr'
   */
  /* Switch: '<S30>/Switch' incorporates:
   *  SignalConversion: '<S17>/TmpSignal ConversionAtbussignalOutport1'
   */
  /* Gateway: CANCheck/CANCheck_Signals/Simulink Function1/CANCheck_Invalid
   */
  /* During: CANCheck/CANCheck_Signals/Simulink Function1/CANCheck_Invalid
   */
  /* Entry Internal: CANCheck/CANCheck_Signals/Simulink Function1/CANCheck_Invalid
   */
  /* Transition: '<S29>:2424' */
  /* Transition: '<S29>:2401' */
  tmp = rtu_bussignal;
  if (!Fv_SystemCANValidStatus[(tmp)]) {
    /* SignalConversion: '<S17>/TmpSignal ConversionAtchecktimeOutport1' */
    /* Transition: '<S29>:2403' */
    /* Transition: '<S29>:2405' */
    if ((*rtuy_vsl_cnt) < rtu_checktime) {
      /* Transition: '<S29>:2407' */
      /* Transition: '<S29>:2409' */
      *rtuy_vsl_cnt = (UInt16)((Int32)(((Int32)(*rtuy_vsl_cnt)) + 1));

      /* Transition: '<S29>:2412' */
    } else {
      /* Outputs for Function Call SubSystem: '<S29>/SetInerDTCErr' */
      /* Switch: '<S30>/Switch' incorporates:
       *  Constant: '<S30>/Constant'
       *  Constant: '<S30>/Constant1'
       *  DataStoreRead: '<S30>/Data Store Read'
       *  DataTypeConversion: '<S30>/Data Type Conversion'
       *  Selector: '<S30>/Selector'
       *  SignalConversion: '<S17>/TmpSignal ConversionAtdtcindexOutport1'
       */
      /* Transition: '<S29>:2411' */
      /* Simulink Function 'SetInerDTCErr': '<S29>:2399' */
      if (DTC_Ctrl_Info_Tab[(UInt8)rtu_dtcindex].Enabled > ((UInt8)0U)) {
        Fv_SystemCANDataInvalidStatus[(tmp)] = FailureDiag_Err;
      } else {
        Fv_SystemCANDataInvalidStatus[(tmp)] = FailureDiag_Default;
      }

      /* End of Outputs for SubSystem: '<S29>/SetInerDTCErr' */
    }

    /* End of SignalConversion: '<S17>/TmpSignal ConversionAtchecktimeOutport1' */
    /* Transition: '<S29>:2422' */
    /* Transition: '<S29>:2421' */
  } else {
    /* Transition: '<S29>:2414' */
    if (((Int32)(*rtuy_vsl_cnt)) > 0) {
      /* Transition: '<S29>:2416' */
      /* Transition: '<S29>:2418' */
      *rtuy_vsl_cnt = (UInt16)((Int32)(((Int32)(*rtuy_vsl_cnt)) - 1));

      /* Transition: '<S29>:2421' */
    } else {
      /* Transition: '<S29>:2420' */
      Fv_SystemCANDataInvalidStatus[(tmp)] = FailureDiag_OK;
    }
  }
}

/* Output and update for Simulink Function: '<S4>/Simulink Function2' */
void DTC_CANCheck_CANCheckCrc(CANBUS rtu_bussignal, DTC rtu_dtcindex, UInt16
  rtu_checktime, UInt16 *rtuy_vsl_crc_cnt)
{
  Int32 tmp;

  /* Chart: '<S18>/CANCheck_Crc ' incorporates:
   *  SubSystem: '<S31>/SetInerDTCErr'
   */
  /* Switch: '<S32>/Switch' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtbussignalOutport1'
   */
  /* Gateway: CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc
   */
  /* During: CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc
   */
  /* Entry Internal: CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc
   */
  /* Transition: '<S31>:2424' */
  /* Transition: '<S31>:2401' */
  tmp = rtu_bussignal;
  if (!Fv_SystemCANCrcStatus[(tmp)]) {
    /* SignalConversion: '<S18>/TmpSignal ConversionAtchecktimeOutport1' */
    /* Transition: '<S31>:2403' */
    /* Transition: '<S31>:2405' */
    if ((*rtuy_vsl_crc_cnt) < rtu_checktime) {
      /* Transition: '<S31>:2407' */
      /* Transition: '<S31>:2409' */
      *rtuy_vsl_crc_cnt = (UInt16)((Int32)(((Int32)(*rtuy_vsl_crc_cnt)) + 1));

      /* Transition: '<S31>:2412' */
    } else {
      /* Outputs for Function Call SubSystem: '<S31>/SetInerDTCErr' */
      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S32>/Constant'
       *  Constant: '<S32>/Constant1'
       *  DataStoreRead: '<S32>/Data Store Read'
       *  DataTypeConversion: '<S32>/Data Type Conversion'
       *  Selector: '<S32>/Selector'
       *  SignalConversion: '<S18>/TmpSignal ConversionAtdtcindexOutport1'
       */
      /* Transition: '<S31>:2411' */
      /* Simulink Function 'SetInerDTCErr': '<S31>:2399' */
      if (DTC_Ctrl_Info_Tab[(UInt8)rtu_dtcindex].Enabled > ((UInt8)0U)) {
        Fv_SystemCANChecksumErrorStatus[(tmp)] = FailureDiag_Err;
      } else {
        Fv_SystemCANChecksumErrorStatus[(tmp)] = FailureDiag_Default;
      }

      /* End of Outputs for SubSystem: '<S31>/SetInerDTCErr' */
    }

    /* End of SignalConversion: '<S18>/TmpSignal ConversionAtchecktimeOutport1' */
    /* Transition: '<S31>:2422' */
    /* Transition: '<S31>:2421' */
  } else {
    /* Transition: '<S31>:2414' */
    if (((Int32)(*rtuy_vsl_crc_cnt)) > 0) {
      /* Transition: '<S31>:2416' */
      /* Transition: '<S31>:2418' */
      *rtuy_vsl_crc_cnt = (UInt16)((Int32)(((Int32)(*rtuy_vsl_crc_cnt)) - 1));

      /* Transition: '<S31>:2421' */
    } else {
      /* Transition: '<S31>:2420' */
      Fv_SystemCANChecksumErrorStatus[(tmp)] = FailureDiag_OK;
    }
  }
}

/* Output and update for Simulink Function: '<S4>/Simulink Function3' */
void DTC_CANCheck_CANCheckCounter(CANBUS rtu_bussignal, DTC rtu_dtcindex, UInt16
  rtu_checktime, UInt16 *rtuy_vsl_counter_cnt)
{
  Int32 tmp;

  /* Chart: '<S18>/CANCheck_Crc ' incorporates:
   *  SubSystem: '<S31>/SetInerDTCErr'
   */
  /* Switch: '<S32>/Switch' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtbussignalOutport1'
   */
  /* Gateway: CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc
   */
  /* During: CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc
   */
  /* Entry Internal: CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc
   */
  /* Transition: '<S31>:2424' */
  /* Transition: '<S31>:2401' */
  tmp = rtu_bussignal;
  if (!Fv_SystemCANCounterStatus[(tmp)]) {
    /* SignalConversion: '<S18>/TmpSignal ConversionAtchecktimeOutport1' */
    /* Transition: '<S31>:2403' */
    /* Transition: '<S31>:2405' */
    if ((*rtuy_vsl_counter_cnt) < rtu_checktime) {
      /* Transition: '<S31>:2407' */
      /* Transition: '<S31>:2409' */
      *rtuy_vsl_counter_cnt = (UInt16)((Int32)(((Int32)(*rtuy_vsl_counter_cnt)) + 1));

      /* Transition: '<S31>:2412' */
    } else {
      /* Outputs for Function Call SubSystem: '<S31>/SetInerDTCErr' */
      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S32>/Constant'
       *  Constant: '<S32>/Constant1'
       *  DataStoreRead: '<S32>/Data Store Read'
       *  DataTypeConversion: '<S32>/Data Type Conversion'
       *  Selector: '<S32>/Selector'
       *  SignalConversion: '<S18>/TmpSignal ConversionAtdtcindexOutport1'
       */
      /* Transition: '<S31>:2411' */
      /* Simulink Function 'SetInerDTCErr': '<S31>:2399' */
      if (DTC_Ctrl_Info_Tab[(UInt8)rtu_dtcindex].Enabled > ((UInt8)0U)) {
        Fv_SystemCANCounterErrorStatus[(tmp)] = FailureDiag_Err;
      } else {
        Fv_SystemCANCounterErrorStatus[(tmp)] = FailureDiag_Default;
      }

      /* End of Outputs for SubSystem: '<S31>/SetInerDTCErr' */
    }

    /* End of SignalConversion: '<S18>/TmpSignal ConversionAtchecktimeOutport1' */
    /* Transition: '<S31>:2422' */
    /* Transition: '<S31>:2421' */
  } else {
    /* Transition: '<S31>:2414' */
    if (((Int32)(*rtuy_vsl_counter_cnt)) > 0) {
      /* Transition: '<S31>:2416' */
      /* Transition: '<S31>:2418' */
      *rtuy_vsl_counter_cnt = (UInt16)((Int32)(((Int32)(*rtuy_vsl_counter_cnt)) - 1));

      /* Transition: '<S31>:2421' */
    } else {
      /* Transition: '<S31>:2420' */
      Fv_SystemCANCounterErrorStatus[(tmp)] = FailureDiag_OK;
    }
  }  
}

/* Output and update for atomic system: '<S1>/CANNetworkManagement' */
void DTC_CANChe_CANNetworkManagement(void)
{
#define DiagVol_Power_Low  (Int16)(832)    //6.5v
#define DiagVol_Power_High (Int16)(2240)  //18v

  Bool b_sf_internal_predicateOutput;
  Int16 rtb_Power_Low_Rec;
  Int16 rtb_Power_High_Rec;

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */
  //rtb_Power_Low_Rec = (Int16)(((Int16)MACRO_CAN_POWERNMWIN) + Cal_Power_Low);
  rtb_Power_Low_Rec = (Int16)(((Int16)MACRO_CAN_POWERNMWIN) + DiagVol_Power_Low);//锟斤拷系锟窖�6.5-18v--TXY-20221108
  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant2'
   */
  //rtb_Power_High_Rec = (Int16)(Cal_Power_High - ((Int16)MACRO_CAN_POWERNMWIN));
  rtb_Power_High_Rec = (Int16)(DiagVol_Power_High - ((Int16)MACRO_CAN_POWERNMWIN));//锟斤拷系锟窖�6.5-18v--TXY-20221108
  /* Chart: '<S5>/CANNetManagement' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant3'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S5>/Constant5'
   *  DataStoreRead: '<S5>/Data Store Read1'
   *  DataStoreRead: '<S5>/Data Store Read5'
   *  Sum: '<S5>/Add2'
   */
  /* Gateway: CANCheck/CANNetworkManagement/CANNetManagement */
  /* During: CANCheck/CANNetworkManagement/CANNetManagement */
  if (((UInt32)DTC_CANCheckrtDW.bitsForTID0.is_active_c95_DTC_CANCheck) == 0U) {
    /* Entry: CANCheck/CANNetworkManagement/CANNetManagement */
    DTC_CANCheckrtDW.bitsForTID0.is_active_c95_DTC_CANCheck = 1;

    /* Entry Internal: CANCheck/CANNetworkManagement/CANNetManagement */
    /* Entry 'CANNodeDiagStateNm': '<S35>:1558' */
    DTC_CANCheckrtDW.bitsForTID0.lastcanpending = false;

    /* Entry Internal 'CANNodePowerSupplyNm': '<S35>:1556' */
    /* Transition: '<S35>:1422' */
    DTC_CANCheckrtDW.bitsForTID0.is_CANNodePowerSupplyNm = DTC_CANCheck_IN_IGOFF;

    /* Entry 'IGOFF': '<S35>:1421' */
    /* '<S35>:1421:1' SysTaskCANLostDiagPending = false; */
    SysTaskCANLostDiagPending = false;
  } else {
    /* During 'CANNodeDiagStateNm': '<S35>:1558' */
    /* Transition: '<S35>:1560' */
    /* '<S35>:1562:1' sf_internal_predicateOutput = (Fv_SysPower < Power_LowReset_Lmt) ||... */
    /* '<S35>:1562:1' ( Fv_SysPower > Power_Over_Lmt); */
    if ((Fv_SysPower < Cal_Power_LowReset) || (Fv_SysPower > ((Int16)(((Int16)
            MACRO_CAN_POWEROVERWIN) + Cal_Power_Over)))) {
      /* Transition: '<S35>:1562' */
      /* Transition: '<S35>:1564' */
      /* '<S35>:1564:1' SysTaskCANPending=false; */
      SysTaskCANPending = false;

      /* Transition: '<S35>:1574' */
      /* Transition: '<S35>:1573' */
    } else {
      /* Transition: '<S35>:1566' */
      /* '<S35>:1568:1' sf_internal_predicateOutput = Fv_IGkeyEffect; */
      if (Fv_IGkeyEffect) {
        /* Transition: '<S35>:1568' */
        /* Transition: '<S35>:1570' */
        /* '<S35>:1570:1' SysTaskCANPending=true; */
        SysTaskCANPending = true;

        /* Transition: '<S35>:1573' */
      } else {
        /* Transition: '<S35>:1572' */
        /* '<S35>:1572:1' SysTaskCANPending=false; */
        SysTaskCANPending = false;
      }
    }

    /* Transition: '<S35>:1576' */
    /* '<S35>:1578:1' sf_internal_predicateOutput = (SysTaskCANPending)&&(~lastcanpending); */
    b_sf_internal_predicateOutput = ((SysTaskCANPending) &&
      (!DTC_CANCheckrtDW.bitsForTID0.lastcanpending));
    if (b_sf_internal_predicateOutput) {
      /* Transition: '<S35>:1578' */
      /* Transition: '<S35>:1580' */
      /* '<S35>:1580:1' SysTaskCANResetPending=true; */
      SysTaskCANResetPending = true;

      /* Transition: '<S35>:1583' */
    } else {
      /* Transition: '<S35>:1582' */
      /* '<S35>:1582:1' SysTaskCANResetPending=false; */
      SysTaskCANResetPending = false;
    }

    /* During 'CANNodePowerSupplyNm': '<S35>:1556' */
    if (((UInt32)DTC_CANCheckrtDW.bitsForTID0.is_CANNodePowerSupplyNm) ==
        DTC_CANCheck_IN_IGOFF) {
      /* During 'IGOFF': '<S35>:1421' */
      /* '<S35>:1424:1' sf_internal_predicateOutput = Fv_IGkeyEffect; */
      if (Fv_IGkeyEffect) {
        /* Transition: '<S35>:1424' */
        DTC_CANCheckrtDW.bitsForTID0.is_CANNodePowerSupplyNm =
          DTC_CANCheck_IN_IGON;

        /* Entry Internal 'IGON': '<S35>:1423' */
        /* Transition: '<S35>:1427' */
        DTC_CANCheckrtDW.bitsForTID0.is_IGON = DTC_CANCheck_IN_Delay;

        /* Entry 'Delay': '<S35>:1426' */
        /* '<S35>:1426:1' SysTaskCANLostDiagPending = false; */
        SysTaskCANLostDiagPending = false;

        /* '<S35>:1426:1' ps_lostcnt = MACRO_CAN_INITDIAGLOST_TIME; */
        DTC_CANCheckrtDW.ps_lostcnt = ((UInt16)MACRO_CAN_INITDIAGLOST_TIME);
      }
    } else {
      /* During 'IGON': '<S35>:1423' */
      /* '<S35>:1425:1' sf_internal_predicateOutput = ~Fv_IGkeyEffect; */
      if (!Fv_IGkeyEffect) {
        /* Transition: '<S35>:1425' */
        /* Exit Internal 'IGON': '<S35>:1423' */
        /* Exit Internal 'Psmanag': '<S35>:1437' */
        DTC_CANCheckrtDW.bitsForTID0.is_Psmanag =
          DTC_CAN_IN_NO_ACTIVE_CHILD_omvo;
        DTC_CANCheckrtDW.bitsForTID0.is_IGON = DTC_CAN_IN_NO_ACTIVE_CHILD_omvo;
        DTC_CANCheckrtDW.bitsForTID0.is_CANNodePowerSupplyNm =
          DTC_CANCheck_IN_IGOFF;

        /* Entry 'IGOFF': '<S35>:1421' */
        /* '<S35>:1421:1' SysTaskCANLostDiagPending = false; */
        SysTaskCANLostDiagPending = false;
      } else if (((UInt32)DTC_CANCheckrtDW.bitsForTID0.is_IGON) ==
                 DTC_CANCheck_IN_Delay) {
        /* During 'Delay': '<S35>:1426' */
        /* '<S35>:1438:1' sf_internal_predicateOutput = ps_lostcnt==0; */
        if (((Int32)DTC_CANCheckrtDW.ps_lostcnt) == 0) {
          /* Transition: '<S35>:1438' */
          DTC_CANCheckrtDW.bitsForTID0.is_IGON = DTC_CANCheck_IN_Psmanag;

          /* Entry 'Psmanag': '<S35>:1437' */
          /* Entry Internal 'Psmanag': '<S35>:1437' */
          /* Transition: '<S35>:1440' */
          DTC_CANCheckrtDW.bitsForTID0.is_Psmanag = DTC_CANCheck_IN_Normal;

          /* Entry 'Normal': '<S35>:1439' */
          /* '<S35>:1439:1' SysTaskCANLostDiagPending = true; */
          SysTaskCANLostDiagPending = true;
        } else {
          /* Transition: '<S35>:1429' */
          /* '<S35>:1431:1' sf_internal_predicateOutput = ps_lostcnt > 0; */
          if (((Int32)DTC_CANCheckrtDW.ps_lostcnt) > 0) {
            /* Transition: '<S35>:1431' */
            /* Transition: '<S35>:1433' */
            /* '<S35>:1433:1' ps_lostcnt = ps_lostcnt - 1; */
            DTC_CANCheckrtDW.ps_lostcnt = (UInt16)(((UInt32)
              DTC_CANCheckrtDW.ps_lostcnt) - 1U);

            /* Transition: '<S35>:1436' */
          } else {
            /* Transition: '<S35>:1435' */
          }
        }
      } else {
        /* During 'Psmanag': '<S35>:1437' */
        if (((UInt32)DTC_CANCheckrtDW.bitsForTID0.is_Psmanag) ==
            DTC_CANCheck_IN_LowHigh) {
          /* During 'LowHigh': '<S35>:1441' */
          /* '<S35>:1444:1' sf_internal_predicateOutput = (Fv_SysPower <Power_High_Rec) &&... */
          /* '<S35>:1444:1' (Fv_SysPower > Power_Low_Rec)&&... */
          /* '<S35>:1444:1' (ps_rcvcnt==0); */
          if (((Fv_SysPower < rtb_Power_High_Rec) && (Fv_SysPower >
                rtb_Power_Low_Rec)) && (((Int32)DTC_CANCheckrtDW.ps_rcvcnt) == 0))
          {
            /* Transition: '<S35>:1444' */
            DTC_CANCheckrtDW.bitsForTID0.is_Psmanag = DTC_CANCheck_IN_Normal;

            /* Entry 'Normal': '<S35>:1439' */
            /* '<S35>:1439:1' SysTaskCANLostDiagPending = true; */
            SysTaskCANLostDiagPending = true;
          } else {
            /* Transition: '<S35>:1530' */
            /* '<S35>:1532:1' sf_internal_predicateOutput = (Fv_SysPower <Power_High_Rec) &&... */
            /* '<S35>:1532:1' (Fv_SysPower > Power_Low_Rec); */
            if ((Fv_SysPower < rtb_Power_High_Rec) && (Fv_SysPower >
                 rtb_Power_Low_Rec)) {
              /* Transition: '<S35>:1532' */
              /* '<S35>:1537:1' sf_internal_predicateOutput = ps_rcvcnt > 0; */
              if (((Int32)DTC_CANCheckrtDW.ps_rcvcnt) > 0) {
                /* Transition: '<S35>:1537' */
                /* Transition: '<S35>:1529' */
                /* '<S35>:1529:1' ps_rcvcnt = ps_rcvcnt - 1; */
                DTC_CANCheckrtDW.ps_rcvcnt = (UInt16)(((UInt32)
                  DTC_CANCheckrtDW.ps_rcvcnt) - 1U);
              } else {
                /* Transition: '<S35>:1535' */
                /* Transition: '<S35>:1527' */
              }
            } else {
              /* Transition: '<S35>:1538' */
              /* '<S35>:1538:1' ps_rcvcnt = MACRO_CAN_RECORNMTIMEOUT; */
              DTC_CANCheckrtDW.ps_rcvcnt = ((UInt16)MACRO_CAN_RECORNMTIMEOUT);

              /* Transition: '<S35>:1534' */
              /* Transition: '<S35>:1527' */
            }
          }
        } else {
          /* During 'Normal': '<S35>:1439' */
          /* '<S35>:1443:1' sf_internal_predicateOutput = (Fv_SysPower < Power_Low_Lmt)||... */
          /* '<S35>:1443:1' (Fv_SysPower > Power_High_Lmt); */
          if ((Fv_SysPower < DiagVol_Power_Low) || (Fv_SysPower > DiagVol_Power_High)) {
            /* Transition: '<S35>:1443' */
            DTC_CANCheckrtDW.bitsForTID0.is_Psmanag = DTC_CANCheck_IN_LowHigh;

            /* Entry 'LowHigh': '<S35>:1441' */
            /* '<S35>:1441:1' SysTaskCANLostDiagPending=false; */
            SysTaskCANLostDiagPending = false;

            /* '<S35>:1441:1' ps_rcvcnt = MACRO_CAN_RECORNMTIMEOUT; */
            DTC_CANCheckrtDW.ps_rcvcnt = ((UInt16)MACRO_CAN_RECORNMTIMEOUT);
          }
        }
      }
    }
  }

  /* End of Chart: '<S5>/CANNetManagement' */
}
void DTC_CANCheck_CANBUSMPCDefualt()
{
  Fv_SystemCANDiagStatus[(CANBUS_ADS2)] = FailureDiag_OK;
  Fv_SystemCANDiagStatus[(CANBUS_ADS1)] = FailureDiag_OK;
  Fv_SystemCANChecksumErrorStatus[(CANBUS_ADS2)] = FailureDiag_OK;
  Fv_SystemCANChecksumErrorStatus[(CANBUS_ADS1)] = FailureDiag_OK;
  Fv_SystemCANCounterErrorStatus[(CANBUS_ADS2)] = FailureDiag_OK;
  Fv_SystemCANCounterErrorStatus[(CANBUS_ADS1)] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2LostComm] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CRCError] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS2CounterError] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1LostComm] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CRCError] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_ADS1CounterError] = FailureDiag_OK;
}
void DTC_CANCheck_CANBUSAPADefualt()
{
  Fv_SystemCANDiagStatus[(CANBUS_APA)] = FailureDiag_OK;
  Fv_SystemCANChecksumErrorStatus[(CANBUS_APA)] = FailureDiag_OK;
  Fv_SystemCANCounterErrorStatus[(CANBUS_APA)] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APALostComm] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APADataInvalid] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACRCError] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_APACounterError] = FailureDiag_OK;
}
void DTC_CANCheck_CANBUSCCU1Defualt()
{
  Fv_SystemCANDiagStatus[(CANBUS_CCU1)] = FailureDiag_OK;
  Fv_ErrDiagStatus[DTC_CANCOMMcheck_CCU1LostComm] = FailureDiag_OK;
}
/* Output and update for atomic system: '<Root>/CANCheck' */
void DTC_CANCheck_CANCheck(void)
{
  uint8 i = 0;
  /* Outputs for Atomic SubSystem: '<S1>/CANNetworkManagement' */
  DTC_CANChe_CANNetworkManagement();

  /* End of Outputs for SubSystem: '<S1>/CANNetworkManagement' */ 
  if ((!SysTaskCANLostDiagPending) || (!SysTaskCANPending) || (SysTaskCANBusoffPending) || (CAN_BCM2Message_Diag_Pending))  
  {
    for(i = 0; i < CANBUS_NUM; i++)
    {
      //if((i != CANBUS_ABSVs) && (i != CANBUS_IPB6))  //SUEA璇婃柇鍗忚鏈夎锛孊YD鍚庣画鏇存柊-wsy20230919
      {
        Fv_SystemCANCounterStatus[i] = TRUE;
        Fv_SystemCANCrcStatus[i] = TRUE;
        Fv_SystemCANValidStatus[i] = TRUE;
        Fv_SystemCANReciveTimer[i] = 0;
      }
    }
  }
  /* Outputs for Resettable SubSystem: '<S1>/CANCheck_Signals' incorporates:
   *  ResetPort: '<S4>/Reset'
   */
  if ((SysTaskCANResetPending) && (((UInt32)
        DTC_CANCheckrtPrevZCX.CANCheck_Signals_Reset_ZCE) != POS_ZCSIG)) {
     /* End of Outputs for SubSystem: '<S4>/CANCheck_APA' */

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_BCM2' */


    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_ABS' */
#if DIAGDIS_CANABS == 0

    DTC_CANChe_CANBUSABSCheck_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_ABS' */

    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_APA' */
#if DIAGDIS_CANAPA == 0

    DTC_CANChe_CANBUSAPACheck_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_APA' */

    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_BCM2' */
#if DIAGDIS_CANBCM2 == 0

    DTC_CANChe_CANBUSBCM2Check_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_BCM2' */

    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_EMS' */
#if DIAGDIS_CANEMS == 0

    DTC_CANChe_CANBUSEMSCheck_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_EMS' */

    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_IPB' */
#if DIAGDIS_CANIPB == 0

    DTC_CANChe_CANBUSIPBCheck_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_IPB' */

    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_MPC' */
#if DIAGDIS_CANMPC == 0

    DTC_CANChe_CANBUSMPCCheck_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_MPC' */

    /* SystemReset for Atomic SubSystem: '<S4>/CANCheck_SCU' */
#if DIAGDIS_CANSCU == 0

    DTC_CANChe_CANBUSSCUCheck_Reset();

#endif

    /* End of SystemReset for SubSystem: '<S4>/CANCheck_SCU' */
  }

  DTC_CANCheckrtPrevZCX.CANCheck_Signals_Reset_ZCE = SysTaskCANResetPending ?
    ((ZCSigState)1) : ((ZCSigState)0);

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_ABS' */
#if DIAGDIS_CANABS == 0

      DTC_CANCheck_CANBUSABSCheck();

#endif

  /* End of Outputs for SubSystem: '<S4>/CANCheck_ABS' */

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_APA' */
#if DIAGDIS_CANAPA == 0
/*APA锟斤拷锟斤拷锟斤拷瞎锟斤拷锟斤拷锟紸PA锟斤拷锟斤拷--TXY--20221124*/
  if(fsAPAFuncCfg == TRUE && Fv_EBL_Cmd == 0)
  {
    DTC_CANCheck_CANBUSAPACheck();
  }
  else
  {
    DTC_CANCheck_CANBUSAPADefualt();
  }
#endif


#if DIAGDIS_CANBCM2 == 0
  DTC_CANCheck_CANBUSBCM2Check();
#endif

  /* End of Outputs for SubSystem: '<S4>/CANCheck_BCM2' */

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_EMS' */
#if DIAGDIS_CANEMS == 0

  DTC_CANCheck_CANBUSEMSCheck();

#endif

  /* End of Outputs for SubSystem: '<S4>/CANCheck_EMS' */

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_IPB' */
#if DIAGDIS_CANIPB == 0

  DTC_CANCheck_CANBUSIPBCheck();

#endif

  /* End of Outputs for SubSystem: '<S4>/CANCheck_IPB' */

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_MPC' */
#if DIAGDIS_CANMPC == 0
if(Fv_EBL_Cmd == 0)
{
  DTC_CANCheck_CANBUSMPCCheck();
}
else
{
  DTC_CANCheck_CANBUSMPCDefualt();
}

#endif

  /* End of Outputs for SubSystem: '<S4>/CANCheck_MPC' */

  /* Outputs for Atomic SubSystem: '<S4>/CANCheck_SCU' */
#if DIAGDIS_CANSCU == 0

  DTC_CANCheck_CANBUSSCUCheck();

#endif
if(fsVOTFuncCfg == TRUE)
{
  //DTC_CANCheck_CANBUSCCU1Check();
}
else
{
  DTC_CANCheck_CANBUSCCU1Defualt();
}

  /* End of Outputs for SubSystem: '<S4>/CANCheck_SCU' */
  /* End of Outputs for SubSystem: '<S1>/CANCheck_Signals' */

  /* Outputs for Atomic SubSystem: '<S1>/CANCheck_BUSOFF' */
#if DIAGDIS_CANBUSOFF == 0

  DTC_CANCheck_CANBUSOFFCheck();

#endif

  /* End of Outputs for SubSystem: '<S1>/CANCheck_BUSOFF' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

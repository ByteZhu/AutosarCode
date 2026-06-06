/*
 * File: Failsafe.c
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

#include "Failsafe.h"

/* Include model header file for global data */
#include "DTC_CANCheck.h"
#include "DTC_CANCheck_private.h"

/* Forward declaration for local functions */
static UInt8 DTC_CANChe_DTC_State_TestFailed(DTC v);
static void DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC v, UInt8 w);
static Bool DTC_CANC_DTC_Ctrl_Info_ErrJudge(DTC v);
static void DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC v);
static void DTC_CANCh_DTC_Ctrl_ErrOccurring(DTC v, UInt8 w);
static void DTC_CANC_SUPPLY_EEPROM_TEMP_CAN(void);

/* Forward declaration for local functions */
static void DTC_CANChec_IgnitionOFFtoONTask(void);

/*
 * Function for Chart: '<S2>/DTC_Allow_Occur_Logic'
 * function y=DTC_State_TestFailed(v)
 */
static UInt8 DTC_CANChe_DTC_State_TestFailed(DTC v)
{
  /* MATLAB Function 'DTC_State_TestFailed': '<S36>:2242' */
  /* Graphical Function 'DTC_State_TestFailed': '<S36>:2242' */
  /* '<S36>:2243:1' y=DTC_State_Info_Tab(int32(v)+1).testFailed; */
  return DTC_State_Info_Tab[v].testFailed;
}

/*
 * Function for Chart: '<S2>/DTC_Allow_Occur_Logic'
 * function DTC_Ctrl_Info_AllowedSet(v,w)
 */
static void DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC v, UInt8 w)
{
  Int32 tmp;

  /* MATLAB Function 'DTC_Ctrl_Info_AllowedSet': '<S36>:2237' */
  /* Graphical Function 'DTC_Ctrl_Info_AllowedSet': '<S36>:2237' */
  /* '<S36>:2238:1' DTC_Ctrl_Info_Tab(int32(v)+1).MonitorAllowed = ... */
  /* '<S36>:2238:2' uint8((w==TRUE)&... */
  /* '<S36>:2238:2' (DTC_Ctrl_Info_Tab(int32(v)+1).Enabled==TRUE)); */
  tmp = v;
  DTC_Ctrl_Info_Tab[tmp].MonitorAllowed = (UInt8)(((w == ((UInt8)TRUE)) &&
    (DTC_Ctrl_Info_Tab[tmp].Enabled == ((UInt8)TRUE))) ? 1 : 0);
}

/*
 * Function for Chart: '<S2>/DTC_Allow_Occur_Logic'
 * function y=DTC_Ctrl_Info_ErrJudge(v)
 */
static Bool DTC_CANC_DTC_Ctrl_Info_ErrJudge(DTC v)
{
  Int32 y_tmp;

  /* MATLAB Function 'DTC_Ctrl_Info_ErrJudge': '<S36>:2222' */
  /* Graphical Function 'DTC_Ctrl_Info_ErrJudge': '<S36>:2222' */
  /* '<S36>:2214:1' y=(DTC_Ctrl_Info_Tab(int32(v)+1).MonitorAllowed) &&... */
  /* '<S36>:2214:2'  (Fv_ErrDiagStatus(int32(v)+1) > FailureDiag.RegOK); */
  y_tmp = v;
  return (((Int32)DTC_Ctrl_Info_Tab[y_tmp].MonitorAllowed) != 0) &&
    (Fv_ErrDiagStatus[(y_tmp)] > FailureDiag_RegOK);
}

/*
 * Function for Chart: '<S2>/DTC_Allow_Occur_Logic'
 * function DTC_Ctrl_Info_ErrOccurSet(v)
 */
static void DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC v)
{
  Bool sf_internal_predicateOutput;

  /* MATLAB Function 'DTC_Ctrl_Info_ErrOccurSet': '<S36>:2225' */
  /* Graphical Function 'DTC_Ctrl_Info_ErrOccurSet': '<S36>:2225' */
  /* '<S36>:2231:1' sf_internal_predicateOutput = DTC_Ctrl_Info_ErrJudge(v); */
  sf_internal_predicateOutput = DTC_CANC_DTC_Ctrl_Info_ErrJudge(v);
  if (sf_internal_predicateOutput) {
    /* '<S36>:2233:1' DTC_Ctrl_Info_Tab(int32(v)+1).ErrOccurring=TRUE; */
    DTC_Ctrl_Info_Tab[v].ErrOccurring = ((UInt8)TRUE);
  } else {
    /* '<S36>:2232:1' DTC_Ctrl_Info_Tab(int32(v)+1).ErrOccurring=FALSE; */
    DTC_Ctrl_Info_Tab[v].ErrOccurring = ((UInt8)FALSE);
  }
}

/*
 * Function for Chart: '<S2>/DTC_Allow_Occur_Logic'
 * function DTC_Ctrl_ErrOccurring(v,w)
 */
static void DTC_CANCh_DTC_Ctrl_ErrOccurring(DTC v, UInt8 w)
{
  /* MATLAB Function 'DTC_Ctrl_ErrOccurring': '<S36>:2431' */
  /* Graphical Function 'DTC_Ctrl_ErrOccurring': '<S36>:2431' */
  /* '<S36>:2435:1' DTC_Ctrl_Info_Tab(int32(v)+1).ErrOccurring=uint8(w); */
  DTC_Ctrl_Info_Tab[v].ErrOccurring = w;
}

/* Function for Chart: '<S2>/DTC_Allow_Occur_Logic' */
static void DTC_CANC_SUPPLY_EEPROM_TEMP_CAN(void)
{
  UInt8 Allowed;
  Bool errjudge;

  /* During 'SUPPLY_EEPROM_TEMP_CAN': '<S36>:2441' */
  /* During 'DTC_SHUTDOWN': '<S36>:2065' */
  /* Transition: '<S36>:2322' */
  /* '<S36>:2324:1' sf_internal_predicateOutput = temp==FALSE; */
  if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
    /* Transition: '<S36>:2324' */
    /* Transition: '<S36>:2318' */
    /* '<S36>:2318:1' Allowed=TRUE; */
    Allowed = ((UInt8)TRUE);

    /* Transition: '<S36>:2418' */
  } else {
    /* Transition: '<S36>:2316' */
    /* '<S36>:2316:1' Allowed=FALSE; */
    Allowed = ((UInt8)FALSE);
  }

  /* Transition: '<S36>:2317' */
  /* '<S36>:2317:1' DTC_Ctrl_Info_AllowedSet(DTC.SHUTDOWNcheck_MmosMelt,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_LKAFUNCcheck_AbnormalExit, Allowed);

  /* '<S36>:2317:2' DTC_Ctrl_Info_AllowedSet(DTC.SHUTDOWNcheck_MmosBreak,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_LKAFUNCcheck_ReqValueOverLimt, Allowed);

  /* '<S36>:2317:3' DTC_Ctrl_Info_AllowedSet(DTC.SHUTDOWNcheck_MonitorShut,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_APAFUNCcheck_AbnormalExit, Allowed);

  /* Transition: '<S36>:2321' */
  /* '<S36>:2321:1' DTC_Ctrl_Info_ErrOccurSet(DTC.SHUTDOWNcheck_MmosMelt); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_LKAFUNCcheck_AbnormalExit);

  /* '<S36>:2321:2' DTC_Ctrl_Info_ErrOccurSet(DTC.SHUTDOWNcheck_MmosBreak); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_LKAFUNCcheck_ReqValueOverLimt);

  /* '<S36>:2321:3' DTC_Ctrl_Info_ErrOccurSet(DTC.SHUTDOWNcheck_MonitorShut); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_APAFUNCcheck_AbnormalExit);

  /* During 'DTC_SUPPLY': '<S36>:2089' */
  /* Transition: '<S36>:2330' */
  /* '<S36>:2335:1' sf_internal_predicateOutput = ((localmode==POWER_MODE.PMON)||... */
  /* '<S36>:2335:1' (localmode==POWER_MODE.PMOFF)); */
  if ((DTC_CANCheckrtDW.localmode == POWER_MODE_PMON) ||
      (DTC_CANCheckrtDW.localmode == POWER_MODE_PMOFF)) {
    /* Transition: '<S36>:2335' */
    /* Transition: '<S36>:2332' */
    /* '<S36>:2332:1' Allowed=TRUE; */
    Allowed = ((UInt8)TRUE);

    /* Transition: '<S36>:2419' */
  } else {
    /* Transition: '<S36>:2325' */
    /* '<S36>:2325:1' Allowed=FALSE; */
    Allowed = ((UInt8)FALSE);
  }

  /* Transition: '<S36>:2326' */
  /* '<S36>:2326:1' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_Burned,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_Burned, Allowed);

  /* '<S36>:2326:2' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_LowReset,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_LowReset, Allowed);

  /* '<S36>:2326:3' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_OverShut,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_OverShut, Allowed);

  /* '<S36>:2326:4' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_LowShut,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_LowShut, Allowed);

  /* '<S36>:2326:5' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_Precharge,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_VolLimitAst, Allowed);

  /* '<S36>:2326:6' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_VBATdt,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_VBATdt, Allowed);

  /* '<S36>:2326:7' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_Hold,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_Hold, Allowed);

  /* '<S36>:2326:8' DTC_Ctrl_Info_AllowedSet(DTC.POWERcheck_IGkey,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_POWERcheck_IGkey, Allowed);

  /* Transition: '<S36>:2337' */
  /* '<S36>:2337:1' DTC_Ctrl_Info_ErrOccurSet(DTC.POWERcheck_Burned); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_Burned);

  /* '<S36>:2337:2' DTC_Ctrl_Info_ErrOccurSet(DTC.POWERcheck_OverShut); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_OverShut);

  /* '<S36>:2337:3' DTC_Ctrl_Info_ErrOccurSet(DTC.POWERcheck_Precharge); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_VolLimitAst);

  /* '<S36>:2337:4' DTC_Ctrl_Info_ErrOccurSet(DTC.POWERcheck_VBATdt); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_VBATdt);

  /* '<S36>:2337:5' DTC_Ctrl_Info_ErrOccurSet(DTC.POWERcheck_Hold); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_Hold);

  /* '<S36>:2337:6' DTC_Ctrl_Info_ErrOccurSet(DTC.POWERcheck_IGkey); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_IGkey);

  /* Inport: '<Root>/Fv_EngRun' */
  /* '<S36>:2339:1' sf_internal_predicateOutput = (Fv_EngRun==true)||... */
  /* '<S36>:2339:1' (Fv_EmsInvalidFlag==true); */
  if ((Fv_EngRun) || (Fv_EmsInvalidFlag)) {
    /* Transition: '<S36>:2339' */
    /* Transition: '<S36>:2341' */
    /* '<S36>:2341:1' DTC_Ctrl_Info_ErrOccurSet(... */
    /* '<S36>:2341:1' DTC.POWERcheck_LowReset); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_LowReset);

    /* '<S36>:2341:2' DTC_Ctrl_Info_ErrOccurSet(... */
    /* '<S36>:2341:3' DTC.POWERcheck_LowShut); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_POWERcheck_LowShut);

    /* Transition: '<S36>:2344' */
  } else {
    /* Transition: '<S36>:2343' */
  }

  /* End of Inport: '<Root>/Fv_EngRun' */
  /* During 'DTC_EEPROM': '<S36>:2185' */
  /* Transition: '<S36>:2358' */
  /* '<S36>:2360:1' sf_internal_predicateOutput = temp==FALSE; */
  if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
    /* Transition: '<S36>:2360' */
    /* Transition: '<S36>:2354' */
    /* '<S36>:2354:1' Allowed=TRUE; */
    Allowed = ((UInt8)TRUE);

    /* Transition: '<S36>:2420' */
  } else {
    /* Transition: '<S36>:2352' */
    /* '<S36>:2352:1' Allowed=FALSE; */
    Allowed = ((UInt8)FALSE);
  }

  /* Transition: '<S36>:2353' */
  /* '<S36>:2353:1' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_CommTimeout,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_CommTimeout, Allowed);

  /* '<S36>:2353:2' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_BootCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_BootCheck, Allowed);

  /* '<S36>:2353:3' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_ConfigCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_ConfigCheck, Allowed);

  /* '<S36>:2353:4' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_CalibCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_CalibCheck, Allowed);

  /* '<S36>:2353:5' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_AngleCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_AngleCheck, Allowed);

  /* '<S36>:2353:6' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_AngleCrrCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_AngleCrrCheck, Allowed);

  /* '<S36>:2353:7' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_FaultStoreCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ASTcheck_AstDegrade, Allowed);

  /* '<S36>:2353:8' DTC_Ctrl_Info_AllowedSet(DTC.EEPROMcheck_OtherCheck,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_EEPROMcheck_OtherCheck, Allowed);

  /* Transition: '<S36>:2357' */
  /* '<S36>:2357:1' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_CommTimeout); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_CommTimeout);

  /* '<S36>:2357:2' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_BootCheck); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_BootCheck);

  /* '<S36>:2357:3' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_ConfigCheck); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_ConfigCheck);

  /* '<S36>:2357:4' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_CalibCheck); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_CalibCheck);

  /* '<S36>:2357:5' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_AngleCheck); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_AngleCheck);

  /* '<S36>:2357:6' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_AngleCrrCheck); */
  //DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_AngleCrrCheck);

  /* '<S36>:2357:7' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_FaultStoreCheck); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ASTcheck_AstDegrade);

  /* '<S36>:2357:8' DTC_Ctrl_Info_ErrOccurSet(DTC.EEPROMcheck_OtherCheck); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_EEPROMcheck_OtherCheck);

  /* During 'DTC_TEMP': '<S36>:2128' */
  /* Transition: '<S36>:2383' */
  /* '<S36>:2384:1' sf_internal_predicateOutput = temp==FALSE; */
  if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
    /* Transition: '<S36>:2384' */
    /* Transition: '<S36>:2379' */
    /* '<S36>:2379:1' Allowed=TRUE; */
    Allowed = ((UInt8)TRUE);

    /* Transition: '<S36>:2421' */
  } else {
    /* Transition: '<S36>:2376' */
    /* '<S36>:2376:1' Allowed=FALSE; */
    Allowed = ((UInt8)FALSE);
  }

  /* Transition: '<S36>:2381' */
  /* '<S36>:2381:1' DTC_Ctrl_Info_AllowedSet(DTC.TEMPcheck_ADport,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TEMPcheck_ADport, Allowed);

  /* '<S36>:2381:2' DTC_Ctrl_Info_AllowedSet(DTC.TEMPcheck_Range,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TEMPcheck_Range, Allowed);

  /* '<S36>:2381:3' DTC_Ctrl_Info_AllowedSet(DTC.TEMPcheck_Over,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TEMPcheck_Over, Allowed);

  /* '<S36>:2381:4' DTC_Ctrl_Info_AllowedSet(DTC.TEMPcheck_Low,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TEMPcheck_TempLimitAst, Allowed);

  /* '<S36>:2381:5' DTC_Ctrl_Info_AllowedSet(DTC.TEMPcheck_HeatShut,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TEMPcheck_HeatShut, Allowed);

  /* Transition: '<S36>:2386' */
  /* '<S36>:2386:1' DTC_Ctrl_Info_ErrOccurSet(DTC.TEMPcheck_ADport); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TEMPcheck_ADport);

  /* '<S36>:2386:2' DTC_Ctrl_Info_ErrOccurSet(DTC.TEMPcheck_Range); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TEMPcheck_Range);

  /* '<S36>:2386:3' DTC_Ctrl_Info_ErrOccurSet(DTC.TEMPcheck_Over); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TEMPcheck_Over);

  /* '<S36>:2386:4' DTC_Ctrl_Info_ErrOccurSet(DTC.TEMPcheck_Low); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TEMPcheck_TempLimitAst);

  /* '<S36>:2386:5' DTC_Ctrl_Info_ErrOccurSet(DTC.TEMPcheck_HeatShut); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TEMPcheck_HeatShut);

  /* During 'DTC_CAN': '<S36>:2141' */
  /* '<S36>:2141:1' errjudge=DTC_Ctrl_Info_ErrJudge(DTC.CANCOMMcheck_Busoff); */
  errjudge = DTC_CANC_DTC_Ctrl_Info_ErrJudge(DTC_CANCOMMcheck_Busoff);

  /* Transition: '<S36>:2399' */
  /* '<S36>:2396:1' sf_internal_predicateOutput = SysTaskCANLostDiagPending; */
  if (SysTaskCANLostDiagPending) {
    /* Transition: '<S36>:2396' */
    /* Transition: '<S36>:2394' */
    /* '<S36>:2394:1' Allowed=TRUE; */
    Allowed = ((UInt8)TRUE);

    /* Transition: '<S36>:2422' */
  } else {
    /* Transition: '<S36>:2395' */
    /* '<S36>:2395:1' Allowed=FALSE; */
    Allowed = ((UInt8)FALSE);
  }

  /* Transition: '<S36>:2397' */
  /* '<S36>:2397:1' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_Busoff,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_Busoff, Allowed);

  /* '<S36>:2397:2' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSVsLostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSVsLostComm, Allowed);

  /* '<S36>:2397:3' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSVsDataInvalid,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSVsDataInvalid, Allowed);

  /* '<S36>:2397:4' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSVsCRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSVsCRCError, Allowed);

  /* '<S36>:2397:5' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSVsCounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSVsCounterError, Allowed);

  /* '<S36>:2397:6' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSWsLostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSWsLostComm, Allowed);

  /* '<S36>:2397:7' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSWsDataInvalid,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSWsDataInvalid, Allowed);

  /* '<S36>:2397:8' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSWsCRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSWsCRCError, Allowed);

  /* '<S36>:2397:9' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ABSWsCounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ABSWsCounterError, Allowed);

  /* '<S36>:2397:10' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB2LostComm, Allowed);

  /* '<S36>:2397:11' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB2DataInvalid,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB2DataInvalid, Allowed);

  /* '<S36>:2397:12' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB2CRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB2CRCError, Allowed);

  /* '<S36>:2397:13' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB2CounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB2CounterError, Allowed);

  /* '<S36>:2397:14' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB5LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB5LostComm, Allowed);

  /* '<S36>:2397:15' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB5DataInvalid,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB5DataInvalid, Allowed);

  /* '<S36>:2397:16' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB6LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB6LostComm, Allowed);

  /* '<S36>:2397:17' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB6DataInvalid,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB6DataInvalid, Allowed);

  /* '<S36>:2397:18' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB6CRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB6CRCError, Allowed);

  /* '<S36>:2397:19' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_IPB6CounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB6CounterError, Allowed);

  /* '<S36>:2397:20' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_SCULostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_CCU3LostComm, Allowed);

  /* '<S36>:2397:20' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_SCULostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_CCU2LostComm, Allowed);

  /* '<S36>:2397:20' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_SCULostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_VCU3LostComm, Allowed);

  /* '<S36>:2397:22' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ADS2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ADS2LostComm, Allowed);

  /* '<S36>:2397:23' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ADS2CRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ADS2CRCError, Allowed);

  /* '<S36>:2397:24' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ADS2CounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ADS2CounterError, Allowed);

  /* '<S36>:2397:25' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ADS1LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ADS1LostComm, Allowed);

  /* '<S36>:2397:26' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ADS1CRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ADS1CRCError, Allowed);

  /* '<S36>:2397:27' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_ADS1CounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_ADS1CounterError, Allowed);

  /* '<S36>:2397:28' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_APALostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_APALostComm, Allowed);

  /* '<S36>:2397:29' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_APADataInvalid,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_APADataInvalid, Allowed);

  /* '<S36>:2397:30' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_APACRCError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_APACRCError, Allowed);

  /* '<S36>:2397:31' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_APACounterError,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_APACounterError, Allowed);

  /* '<S36>:2397:20' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_SCULostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_SCULostComm, Allowed);

  /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_BCM2LostComm, Allowed);

   /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_CCU1LostComm, Allowed);

  /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_SCUInvalidDLC, Allowed);

  /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_RemoteInvalidDLC, Allowed);

  /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_BrakeInvalidDLC, Allowed);

  /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_BrakeLostComm, Allowed);
    /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB7LostComm, Allowed);
    /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_VCU1InvalidDLC, Allowed);
    /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_BCMInvalidData, Allowed);
    /* '<S36>:2397:21' DTC_Ctrl_Info_AllowedSet(DTC.CANCOMMcheck_BCM2LostComm,Allowed); */
  DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CANCOMMcheck_IPB7InvalidData, Allowed);
  /* '<S36>:2402:1' sf_internal_predicateOutput = errjudge==true; */
  if (errjudge) {
    /* Transition: '<S36>:2402' */
    /* Transition: '<S36>:2404' */
    /* '<S36>:2404:1' DTC_Ctrl_ErrOccurring(... */
    /* '<S36>:2404:1' DTC.CANCOMMcheck_Busoff,TRUE); */
    DTC_CANCh_DTC_Ctrl_ErrOccurring(DTC_CANCOMMcheck_Busoff, ((UInt8)TRUE));

    /* '<S36>:2404:2' CANBusoffRecoverDelay=... */
    /* '<S36>:2404:3' MACRO_CAN_RECORTIMEOUT; */
    DTC_CANCheckrtDW.CANBusoffRecoverDelay = ((UInt16)MACRO_CAN_RECORTIMEOUT);

    /* Transition: '<S36>:2413' */
    /* Transition: '<S36>:2412' */
  } else {
    /* Transition: '<S36>:2406' */
    /* '<S36>:2408:1' sf_internal_predicateOutput = CANBusoffRecoverDelay>... */
    /* '<S36>:2408:1' uint16(0); */
    if (((Int32)DTC_CANCheckrtDW.CANBusoffRecoverDelay) > 0) {
      /* Transition: '<S36>:2408' */
      /* Transition: '<S36>:2410' */
      /* '<S36>:2410:1' CANBusoffRecoverDelay=... */
      /* '<S36>:2410:1' CANBusoffRecoverDelay-1; */
      DTC_CANCheckrtDW.CANBusoffRecoverDelay = (UInt16)(((UInt32)
        DTC_CANCheckrtDW.CANBusoffRecoverDelay) - 1U);

      /* Transition: '<S36>:2412' */
    } else {
      /* Transition: '<S36>:2411' */
      /* '<S36>:2411:1' DTC_Ctrl_ErrOccurring(... */
      /* '<S36>:2411:1' DTC.CANCOMMcheck_Busoff,FALSE); */
      DTC_CANCh_DTC_Ctrl_ErrOccurring(DTC_CANCOMMcheck_Busoff, ((UInt8)FALSE));
    }
  }

  /* Transition: '<S36>:2391' */
  /* '<S36>:2391:1' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_Busoff); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_Busoff);

  /* '<S36>:2391:2' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSVsLostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSVsLostComm);

  /* '<S36>:2391:3' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSVsDataInvalid); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSVsDataInvalid);

  /* '<S36>:2391:4' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSVsCRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSVsCRCError);

  /* '<S36>:2391:5' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSVsCounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSVsCounterError);

  /* '<S36>:2391:6' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSWsLostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSWsLostComm);

  /* '<S36>:2391:7' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSWsDataInvalid); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSWsDataInvalid);

  /* '<S36>:2391:8' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSWsCRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSWsCRCError);

  /* '<S36>:2391:9' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ABSWsCounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ABSWsCounterError);

  /* '<S36>:2391:10' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB2LostComm);

  /* '<S36>:2391:11' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB2DataInvalid); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB2DataInvalid);

  /* '<S36>:2391:12' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB2CRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB2CRCError);

  /* '<S36>:2391:13' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB2CounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB2CounterError);

  /* '<S36>:2391:14' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB5LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB5LostComm);

  /* '<S36>:2391:15' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB5DataInvalid); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB5DataInvalid);

  /* '<S36>:2391:16' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB6LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB6LostComm);

  /* '<S36>:2391:17' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB6DataInvalid); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB6DataInvalid);

  /* '<S36>:2391:18' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB6CRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB6CRCError);

  /* '<S36>:2391:19' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_IPB6CounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB6CounterError);

  /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_CCU3LostComm);

  /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_CCU2LostComm);

  /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_VCU3LostComm);

  /* '<S36>:2391:22' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ADS2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ADS2LostComm);

  /* '<S36>:2391:23' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ADS2CRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ADS2CRCError);

  /* '<S36>:2391:24' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ADS2CounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ADS2CounterError);

  /* '<S36>:2391:25' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ADS1LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ADS1LostComm);

  /* '<S36>:2391:26' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ADS1CRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ADS1CRCError);

  /* '<S36>:2391:27' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_ADS1CounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_ADS1CounterError);

  /* '<S36>:2391:28' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_APALostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_APALostComm);

  /* '<S36>:2391:29' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_APADataInvalid); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_APADataInvalid);

  /* '<S36>:2391:30' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_APACRCError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_APACRCError);

  /* '<S36>:2391:31' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_APACounterError); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_APACounterError);

  /* '<S36>:2391:21' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_SCULostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_SCULostComm);  

  /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_BCM2LostComm);

    /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_CCU1LostComm);

      /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_SCUInvalidDLC);
      /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_RemoteInvalidDLC);
  /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_BrakeInvalidDLC);
  /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_BrakeLostComm);
    /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB7LostComm);
    /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_VCU1InvalidDLC);
    /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_BCMInvalidData);
    /* '<S36>:2391:20' DTC_Ctrl_Info_ErrOccurSet(DTC.CANCOMMcheck_BCM2LostComm); */
  DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB7InvalidData);
  //DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB5CRCError);
  //DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CANCOMMcheck_IPB5CounterError);
}

/* Output and update for atomic system: '<S2>/DTC_Allow_Occur_Logic' */
void DTC_CANCh_DTC_Allow_Occur_Logic(void)
{
  UInt8 Allowed;

  /* Chart: '<S2>/DTC_Allow_Occur_Logic' */
  /* Gateway: DTCLogic/DTC_Allow_Occur_Logic */
  /* During: DTCLogic/DTC_Allow_Occur_Logic */
  if (((UInt32)DTC_CANCheckrtDW.bitsForTID0.is_active_c74_DTC_CANCheck) == 0U) {
    /* Entry: DTCLogic/DTC_Allow_Occur_Logic */
    DTC_CANCheckrtDW.bitsForTID0.is_active_c74_DTC_CANCheck = 1;

    /* Entry Internal: DTCLogic/DTC_Allow_Occur_Logic */
    /* Entry 'DTC_Allow_Occur_Logic': '<S36>:2438' */
    /* Entry Internal 'DTC_Allow_Occur_Logic': '<S36>:2438' */
    /* Entry Internal 'MCU_SENSOR_MOTOR': '<S36>:2440' */
    /* Entry 'DTC_MCU': '<S36>:2077' */
    /* Entry 'DTC_TORQUE': '<S36>:2173' */
    /* Entry Internal 'SUPPLY_EEPROM_TEMP_CAN': '<S36>:2441' */
    /* Entry 'DTC_CAN': '<S36>:2141' */
  } else {
    /* During 'DTC_Allow_Occur_Logic': '<S36>:2438' */
    /* '<S36>:2438:1' temp=DTC_State_TestFailed(DTC.POWERcheck_LowReset); */
    DTC_CANCheckrtDW.temp = DTC_CANChe_DTC_State_TestFailed
      (DTC_POWERcheck_LowReset);

    /* During 'MCU_SENSOR_MOTOR': '<S36>:2440' */
    /* During 'DTC_MCU': '<S36>:2077' */
    /* Transition: '<S36>:2088' */
    /* '<S36>:2087:1' sf_internal_predicateOutput = temp==FALSE; */
    if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
      /* Transition: '<S36>:2087' */
      /* Transition: '<S36>:2083' */
      /* '<S36>:2083:1' Allowed=TRUE; */
      Allowed = ((UInt8)TRUE);

      /* Transition: '<S36>:2414' */
    } else {
      /* Transition: '<S36>:2086' */
      /* '<S36>:2086:1' Allowed=FALSE; */
      Allowed = ((UInt8)FALSE);
    }

    /* Transition: '<S36>:2201' */
    /* '<S36>:2201:1' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_RAM,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_RAM, Allowed);

    /* '<S36>:2201:2' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_ROM,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_ROM, Allowed);

    /* '<S36>:2201:3' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_PerOthers,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_PerOthers, Allowed);

    /* '<S36>:2201:4' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_UnexpReset,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_UnexpReset, Allowed);

    /* '<S36>:2201:5' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_ExtWatchDog,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_ExtWatchDog, Allowed);

    /* '<S36>:2201:6' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_MotorCtrl,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_MotorCtrl, Allowed);

    /* '<S36>:2201:7' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_AssistCtrl,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_AssistCtrl, Allowed);

    /* '<S36>:2201:8' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_CommTimeout,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_CommTimeout, Allowed);

    /* '<S36>:2201:9' DTC_Ctrl_Info_AllowedSet(DTC.MCUcheck_ViceMonitor,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MCUcheck_ViceMonitor, Allowed);

    /* Transition: '<S36>:2203' */
    /* '<S36>:2203:1' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_RAM); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_RAM);

    /* '<S36>:2203:2' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_ROM); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_ROM);

    /* '<S36>:2203:3' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_PerOthers); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_PerOthers);

    /* '<S36>:2203:4' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_UnexpReset); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_UnexpReset);

    /* '<S36>:2203:5' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_ExtWatchDog); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_ExtWatchDog);

    /* '<S36>:2203:6' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_MotorCtrl); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_MotorCtrl);

    /* '<S36>:2203:7' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_AssistCtrl); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_AssistCtrl);

    /* '<S36>:2203:8' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_CommTimeout); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_CommTimeout);

    /* '<S36>:2203:9' DTC_Ctrl_Info_ErrOccurSet(DTC.MCUcheck_ViceMonitor); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MCUcheck_ViceMonitor);

    /* During 'DTC_TORQUE': '<S36>:2173' */
    /* Transition: '<S36>:2251' */
    /* '<S36>:2250:1' sf_internal_predicateOutput = temp==FALSE; */
    if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
      /* Transition: '<S36>:2250' */
      /* Transition: '<S36>:2252' */
      /* '<S36>:2252:1' Allowed=TRUE; */
      Allowed = ((UInt8)TRUE);

      /* Transition: '<S36>:2415' */
    } else {
      /* Transition: '<S36>:2248' */
      /* '<S36>:2248:1' Allowed=FALSE; */
      Allowed = ((UInt8)FALSE);
    }

    /* Transition: '<S36>:2254' */
    /* '<S36>:2254:1' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_PowerSupply,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_PowerSupply, Allowed);

    /* '<S36>:2254:2' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_MainRange,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_MainRange, Allowed);

    /* '<S36>:2254:3' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_MainWave,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_MainWave, Allowed);

    /* '<S36>:2254:4' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_SubRange,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_SubRange, Allowed);

    /* '<S36>:2254:5' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_SubWave,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_SubWave, Allowed);

    /* '<S36>:2254:6' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_SumOfMS,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_SumOfMS, Allowed);

    /* '<S36>:2254:7' DTC_Ctrl_Info_AllowedSet(DTC.TORQUEcheck_Offset,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_TORQUEcheck_Offset, Allowed);

    /* Transition: '<S36>:2257' */
    /* '<S36>:2257:1' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_PowerSupply); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_PowerSupply);

    /* '<S36>:2257:2' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_MainRange); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_MainRange);

    /* '<S36>:2257:3' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_MainWave); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_MainWave);

    /* '<S36>:2257:4' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_SubRange); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_SubRange);

    /* '<S36>:2257:5' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_SubWave); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_SubWave);

    /* '<S36>:2257:6' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_SumOfMS); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_SumOfMS);

    /* '<S36>:2257:7' DTC_Ctrl_Info_ErrOccurSet(DTC.TORQUEcheck_Offset); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_TORQUEcheck_Offset);

    /* During 'DTC_ANGLE': '<S36>:2053' */
    /* Transition: '<S36>:2269' */
    /* '<S36>:2259:1' sf_internal_predicateOutput = temp==FALSE; */
    if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
      /* Transition: '<S36>:2259' */
      /* Transition: '<S36>:2261' */
      /* '<S36>:2261:1' Allowed=TRUE; */
      Allowed = ((UInt8)TRUE);

      /* Transition: '<S36>:2426' */
    } else {
      /* Transition: '<S36>:2264' */
      /* '<S36>:2264:1' Allowed=FALSE; */
      Allowed = ((UInt8)FALSE);
    }

    /* Transition: '<S36>:2271' */
    /* '<S36>:2271:1' DTC_Ctrl_Info_AllowedSet(DTC.ANGLEcheck_NoZeroCalib,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ANGLEcheck_NoZeroCalib, Allowed);

    /* '<S36>:2271:2' DTC_Ctrl_Info_AllowedSet(DTC.ANGLEcheck_Invalid,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ANGLEcheck_Invalid, Allowed);

    /* '<S36>:2271:3' DTC_Ctrl_Info_AllowedSet(DTC.ANGLEcheck_Unreal,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ANGLEcheck_Unreal, Allowed);

    /* '<S36>:2271:4' DTC_Ctrl_Info_AllowedSet(DTC.ANGLEcheck_NoEndLearn,Allowed); */
    //DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ANGLEcheck_NoEndLearn, Allowed);

    /* '<S36>:2271:5' DTC_Ctrl_Info_AllowedSet(DTC.ANGLEcheck_CheckRotor,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ANGLEcheck_CheckRotor, Allowed);

    /* Transition: '<S36>:2270' */
    /* '<S36>:2270:1' DTC_Ctrl_Info_ErrOccurSet(DTC.ANGLEcheck_NoZeroCalib); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ANGLEcheck_NoZeroCalib);

    /* '<S36>:2270:2' DTC_Ctrl_Info_ErrOccurSet(DTC.ANGLEcheck_Invalid); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ANGLEcheck_Invalid);

    /* '<S36>:2270:3' DTC_Ctrl_Info_ErrOccurSet(DTC.ANGLEcheck_Unreal); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ANGLEcheck_Unreal);

    /* '<S36>:2270:4' DTC_Ctrl_Info_ErrOccurSet(DTC.ANGLEcheck_NoEndLearn); */
    //DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ANGLEcheck_NoEndLearn);

    /* '<S36>:2270:5' DTC_Ctrl_Info_ErrOccurSet(DTC.ANGLEcheck_CheckRotor); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ANGLEcheck_CheckRotor);

    /* During 'DTC_RESOLVER': '<S36>:2104' */
    /* Transition: '<S36>:2277' */
    /* '<S36>:2282:1' sf_internal_predicateOutput = temp==FALSE; */
    if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
      /* Transition: '<S36>:2282' */
      /* Transition: '<S36>:2284' */
      /* '<S36>:2284:1' Allowed=TRUE; */
      Allowed = ((UInt8)TRUE);

      /* Transition: '<S36>:2416' */
    } else {
      /* Transition: '<S36>:2281' */
      /* '<S36>:2281:1' Allowed=FALSE; */
      Allowed = ((UInt8)FALSE);
    }

    /* Transition: '<S36>:2274' */
    /* '<S36>:2274:1' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_PowerSupply,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_PowerSupply, Allowed);

    /* '<S36>:2274:2' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_MiddSig,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_MiddSig, Allowed);

    /* '<S36>:2274:3' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_SinRange,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_SinRange, Allowed);

    /* '<S36>:2274:4' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_SinOffset,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_SinOffset, Allowed);

    /* '<S36>:2274:5' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_CosRange,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_CosRange, Allowed);

    /* '<S36>:2274:6' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_CosOffset,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_CosOffset, Allowed);

    /* '<S36>:2274:7' DTC_Ctrl_Info_AllowedSet(DTC.RESOLVERcheck_LotusWave,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_RESOLVERcheck_LotusWave, Allowed);

    /* Transition: '<S36>:2273' */
    /* '<S36>:2273:1' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_PowerSupply); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_PowerSupply);

    /* '<S36>:2273:2' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_MiddSig); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_MiddSig);

    /* '<S36>:2273:3' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_SinRange); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_SinRange);

    /* '<S36>:2273:4' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_SinOffset); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_SinOffset);

    /* '<S36>:2273:5' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_CosRange); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_CosRange);

    /* '<S36>:2273:6' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_CosOffset); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_CosOffset);

    /* '<S36>:2273:7' DTC_Ctrl_Info_ErrOccurSet(DTC.RESOLVERcheck_LotusWave); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_RESOLVERcheck_LotusWave);

    /* During 'DTC_CURRENT': '<S36>:2161' */
    /* Transition: '<S36>:2291' */
    /* '<S36>:2296:1' sf_internal_predicateOutput = temp==FALSE; */
    if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
      /* Transition: '<S36>:2296' */
      /* Transition: '<S36>:2294' */
      /* '<S36>:2294:1' Allowed=TRUE; */
      Allowed = ((UInt8)TRUE);

      /* Transition: '<S36>:2427' */
    } else {
      /* Transition: '<S36>:2295' */
      /* '<S36>:2295:1' Allowed=FALSE; */
      Allowed = ((UInt8)FALSE);
    }

    /* Transition: '<S36>:2287' */
    /* '<S36>:2287:1' DTC_Ctrl_Info_AllowedSet(DTC.CURRENTcheck_MiddSig,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CURRENTcheck_MiddSig, Allowed);

    /* '<S36>:2287:2' DTC_Ctrl_Info_AllowedSet(DTC.CURRENTcheck_3PhaseSum,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CURRENTcheck_3PhaseSum, Allowed);

    /* '<S36>:2287:3' DTC_Ctrl_Info_AllowedSet(DTC.CURRENTcheck_VsampInvalid,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_DSTFUNCcheck_ReqValueOverLimt, Allowed);

    /* '<S36>:2287:4' DTC_Ctrl_Info_AllowedSet(DTC.CURRENTcheck_IcalibInvalid,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_CURRENTcheck_IcalibInvalid, Allowed);

    /* Transition: '<S36>:2286' */
    /* '<S36>:2286:1' DTC_Ctrl_Info_ErrOccurSet(DTC.CURRENTcheck_MiddSig); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CURRENTcheck_MiddSig);

    /* '<S36>:2286:2' DTC_Ctrl_Info_ErrOccurSet(DTC.CURRENTcheck_3PhaseSum); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CURRENTcheck_3PhaseSum);

    /* '<S36>:2286:3' DTC_Ctrl_Info_ErrOccurSet(DTC.CURRENTcheck_VsampInvalid); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_DSTFUNCcheck_ReqValueOverLimt);

    /* '<S36>:2286:4' DTC_Ctrl_Info_ErrOccurSet(DTC.CURRENTcheck_IcalibInvalid); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_CURRENTcheck_IcalibInvalid);

    /* During 'DTC_MOTOR': '<S36>:2116' */
    /* Transition: '<S36>:2307' */
    /* '<S36>:2310:1' sf_internal_predicateOutput = temp==FALSE; */
    if (DTC_CANCheckrtDW.temp == ((UInt8)FALSE)) {
      /* Transition: '<S36>:2310' */
      /* Transition: '<S36>:2305' */
      /* '<S36>:2305:1' Allowed=TRUE; */
      Allowed = ((UInt8)TRUE);

      /* Transition: '<S36>:2417' */
    } else {
      /* Transition: '<S36>:2311' */
      /* '<S36>:2311:1' Allowed=FALSE; */
      Allowed = ((UInt8)FALSE);
    }

    /* Transition: '<S36>:2301' */
    /* '<S36>:2301:1' DTC_Ctrl_Info_AllowedSet(DTC.MOTORcheck_Predriver,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MOTORcheck_Predriver, Allowed);

    /* '<S36>:2301:2' DTC_Ctrl_Info_AllowedSet(DTC.MOTORcheck_Phase2PG,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_ANGLEcheck_ExtAngleErr, Allowed);

    /* '<S36>:2301:3' DTC_Ctrl_Info_AllowedSet(DTC.MOTORcheck_PhaseOpen,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MOTORcheck_PhaseOpen, Allowed);

    /* '<S36>:2301:4' DTC_Ctrl_Info_AllowedSet(DTC.MOTORcheck_OverCurrent,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MOTORcheck_OverCurrent, Allowed);

    /* '<S36>:2301:5' DTC_Ctrl_Info_AllowedSet(DTC.MOTORcheck_Output,Allowed); */
    DTC_CA_DTC_Ctrl_Info_AllowedSet(DTC_MOTORcheck_Output, Allowed);

    /* Transition: '<S36>:2299' */
    /* '<S36>:2299:1' DTC_Ctrl_Info_ErrOccurSet(DTC.MOTORcheck_Predriver); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MOTORcheck_Predriver);

    /* '<S36>:2299:2' DTC_Ctrl_Info_ErrOccurSet(DTC.MOTORcheck_Phase2PG); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_ANGLEcheck_ExtAngleErr);

    /* '<S36>:2299:3' DTC_Ctrl_Info_ErrOccurSet(DTC.MOTORcheck_PhaseOpen); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MOTORcheck_PhaseOpen);

    /* '<S36>:2299:4' DTC_Ctrl_Info_ErrOccurSet(DTC.MOTORcheck_OverCurrent); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MOTORcheck_OverCurrent);

    /* . */
    /* '<S36>:2299:5' DTC_Ctrl_Info_ErrOccurSet(DTC.MOTORcheck_Output); */
    DTC_C_DTC_Ctrl_Info_ErrOccurSet(DTC_MOTORcheck_Output);
    DTC_CANC_SUPPLY_EEPROM_TEMP_CAN();
  }

  /* End of Chart: '<S2>/DTC_Allow_Occur_Logic' */
}

/*
 * Function for Chart: '<S2>/DTC_Testfailed_Logic'
 * function IgnitionOFFtoONTask
 */
static void DTC_CANChec_IgnitionOFFtoONTask(void)
{
  UInt8 i;
  UInt8 tmp;

  /* MATLAB Function 'IgnitionOFFtoONTask': '<S37>:2063' */
  /* Graphical Function 'IgnitionOFFtoONTask': '<S37>:2063' */
  /* '<S37>:2080:1' i=0; */
  /* '<S37>:2081:1' sf_internal_predicateOutput = i<EPS_DTC_NUM_MAX; */
  for (i = 0U; ((Int32)i) < EPS_DTC_NUM_MAX; i = (UInt8)(((UInt32)i) + 1U)) {
    /* '<S37>:2083:1' sf_internal_predicateOutput = (DTC_State_Info_Tab(int32(i)+1).confirmedDTC)&&... */
    /* '<S37>:2083:1' (~DTC_State_Info_Tab(int32(i)+1).testFailed); */
    if ((((Int32)DTC_State_Info_Tab[i].confirmedDTC) != 0) && (((Int32)
          DTC_State_Info_Tab[i].testFailed) == 0)) {
      /* '<S37>:2086:1' tmp=Read_DTC_IgnitCycle_Tab(int32(i)+1); */
      tmp = (UInt8)(((UInt32)Read_DTC_IgnitCycle_Tab[(i)]) + 1U);

      /* '<S37>:2087:1' sf_internal_predicateOutput = tmp==uint8(255); */
      if (((Int32)Read_DTC_IgnitCycle_Tab[(i)]) == 255) {
        /* '<S37>:2089:1' tmp=0; */
        tmp = 1U;
      }

      /* '<S37>:2092:1' sf_internal_predicateOutput = ((tmp+1) >= DTC_CodeStrInfo(int32(i)+1).MaxIgnitCycle); */
      if (tmp >= DTC_CodeStrInfo[i].MaxIgnitCycle) {
        /* '<S37>:2094:1' DTC_State_Info_Tab(int32(i)+1).testFailed     					  = FALSE; */
        DTC_State_Info_Tab[i].testFailed = ((UInt8)FALSE);

        /* '<S37>:2094:2' DTC_State_Info_Tab(int32(i)+1).testFailedThisMonitoringCycle       = FALSE; */
        DTC_State_Info_Tab[i].testFailedThisMonitoringCycle = ((UInt8)FALSE);

        /* '<S37>:2094:3' DTC_State_Info_Tab(int32(i)+1).confirmedDTC     					  = FALSE; */
        DTC_State_Info_Tab[i].confirmedDTC = ((UInt8)FALSE);

        /* '<S37>:2094:4' DTC_State_Info_Tab(int32(i)+1).testNotCompletedThisMonitoringCycle = FALSE; */
        DTC_State_Info_Tab[i].testNotCompletedThisMonitoringCycle = ((UInt8)
          FALSE);

        /* '<S37>:2094:5' DTC_State_Info_Tab(int32(i)+1).warningIndicatorRequest             = FALSE; */
        DTC_State_Info_Tab[i].warningIndicatorRequest = ((UInt8)FALSE);

        /* '<S37>:2094:6' DTC_Ctrl_Info_Tab(int32(i)+1).StoreReq 		= TRUE; */
        DTC_Ctrl_Info_Tab[i].StoreReq = ((UInt8)TRUE);

        /* '<S37>:2094:7' DTC_Ctrl_Info_Tab(int32(i)+1).IgnitCycleReq 	= uint8(EPS_IGNIT.REQ_CLR); */
        DTC_Ctrl_Info_Tab[i].IgnitCycleReq = (UInt8)EPS_IGNIT_REQ_CLR;
      } else {
        /* '<S37>:2093:1' DTC_Ctrl_Info_Tab(int32(i)+1).IgnitCycleReq  = uint8(EPS_IGNIT.REQ_INC); */
        DTC_Ctrl_Info_Tab[i].IgnitCycleReq = (UInt8)EPS_IGNIT_REQ_INC;
		

      }
    }

    /* '<S37>:2084:1' i = i + 1; */
  }
}

/* System initialize for atomic system: '<S2>/DTC_Testfailed_Logic' */
void DTC_C_DTC_Testfailed_Logic_Init(void)
{
  DTC_CANCheckrtDW.localmode = POWER_MODE_PMOFF;
}

/* Output and update for atomic system: '<S2>/DTC_Testfailed_Logic' */
void DTC_CANChe_DTC_Testfailed_Logic(void)
{
  UInt8 i;
  Int32 exitg1;

  /* Chart: '<S2>/DTC_Testfailed_Logic' incorporates:
   *  Inport: '<Root>/PowerMode'
   */
  /* Gateway: DTCLogic/DTC_Testfailed_Logic */
  /* During: DTCLogic/DTC_Testfailed_Logic */
  /* Entry Internal: DTCLogic/DTC_Testfailed_Logic */
  /* Transition: '<S37>:1887' */
  /* '<S37>:1889:1' sf_internal_predicateOutput = localmode~=PowerMode; */
  if (DTC_CANCheckrtDW.localmode != PowerMode) {
    /* Transition: '<S37>:1889' */
    /* '<S37>:1891:1' sf_internal_predicateOutput = (localmode==POWER_MODE.PMOFF); */
    if (DTC_CANCheckrtDW.localmode == POWER_MODE_PMOFF) {
      /* Transition: '<S37>:1891' */
      /* Transition: '<S37>:1893' */
      /* '<S37>:1893:1' IgnitionOFFtoONTask(); */
      DTC_CANChec_IgnitionOFFtoONTask();

      /* Transition: '<S37>:1896' */
    } else {
      /* Transition: '<S37>:1895' */
    }

    /* Transition: '<S37>:1898' */
    /* '<S37>:1898:1' localmode=PowerMode; */
    DTC_CANCheckrtDW.localmode = PowerMode;

    /* Transition: '<S37>:1901' */
  } else {
    /* Transition: '<S37>:1900' */
  }

  /* Transition: '<S37>:1942' */
  /* '<S37>:1942:1' i=0; */
  i = 0U;
  do {
    exitg1 = 0;

    /* '<S37>:1944:1' sf_internal_predicateOutput = (SysTaskDisableDTCPending)|(SysTaskDevCtrlReqPending&(~SysTaskEnableDTCdurDevPending)); */
    if ((SysTaskDisableDTCPending) || ((SysTaskDevCtrlReqPending) &&
         (!SysTaskEnableDTCdurDevPending))) {
      /* Transition: '<S37>:1944' */
      /* Transition: '<S37>:1952' */
      exitg1 = 1;
    } else {
      /* Transition: '<S37>:1946' */
      /* '<S37>:1948:1' sf_internal_predicateOutput = DTC_Ctrl_Info_Tab(... */
      /* '<S37>:1948:1' int32(i)+1).MonitorAllowed==... */
      /* '<S37>:1948:1' TRUE; */
      if (DTC_Ctrl_Info_Tab[i].MonitorAllowed == ((UInt8)TRUE)) {
        /* Transition: '<S37>:1948' */
        /* '<S37>:1964:1' sf_internal_predicateOutput = DTC_Ctrl_Info_Tab(... */
        /* '<S37>:1964:1' int32(i)+1).ErrOccurring==TRUE; */
        if (DTC_Ctrl_Info_Tab[i].ErrOccurring == ((UInt8)TRUE)) {
          /* Transition: '<S37>:1964' */
          /* '<S37>:1985:1' sf_internal_predicateOutput = DTC_State_Info_Tab(... */
          /* '<S37>:1985:1' int32(i)+1).testFailed==FALSE; */
          if (DTC_State_Info_Tab[i].testFailed == ((UInt8)FALSE)) {
            /* Transition: '<S37>:1985' */
            /* Transition: '<S37>:1987' */
            /* '<S37>:2023:1' sf_internal_predicateOutput = (DTC_Ctrl_Info_Tab(... */
            /* '<S37>:2023:1' int32(i)+1).OnStarTrigEnabled==TRUE) &... */
            /* '<S37>:2023:1' (DTC_Ctrl_Info_Tab(... */
            /* '<S37>:2023:2' int32(i)+1).OnStarTrigReported==FALSE); */
            if ((DTC_Ctrl_Info_Tab[i].OnStarTrigEnabled == ((UInt8)TRUE)) &&
                (DTC_Ctrl_Info_Tab[i].OnStarTrigReported == ((UInt8)FALSE))) {
              /* Transition: '<S37>:2023' */
              /* Transition: '<S37>:2025' */
              /* '<S37>:2025:1' DTC_Ctrl_Info_Tab(... */
              /* '<S37>:2025:1' int32(i)+1).OnStarTrigQueued=TRUE; */
              DTC_Ctrl_Info_Tab[i].OnStarTrigQueued = ((UInt8)TRUE);

              /* Transition: '<S37>:2028' */
            } else {
              /* Transition: '<S37>:2027' */
            }

            /* Transition: '<S37>:2030' */
            /* '<S37>:2032:1' sf_internal_predicateOutput = DTC_State_Info_Tab(... */
            /* '<S37>:2032:1' int32(i)+1).confirmedDTC==TRUE; */
            if (DTC_State_Info_Tab[i].confirmedDTC == ((UInt8)TRUE)) {
              /* Transition: '<S37>:2032' */
              /* Transition: '<S37>:2034' */
              /* '<S37>:2034:1' DTC_Ctrl_Info_Tab(... */
              /* '<S37>:2034:1' int32(i)+1).IgnitCycleReq=uint8(EPS_IGNIT.REQ_CLR); */
              DTC_Ctrl_Info_Tab[i].IgnitCycleReq = (UInt8)EPS_IGNIT_REQ_CLR;

              /* '<S37>:2034:3' DTC_Ctrl_Info_Tab(... */
              /* '<S37>:2034:3' int32(i)+1).SnapShotIgClearStore=TRUE; */
              DTC_Ctrl_Info_Tab[i].SnapShotIgClearStore = ((UInt8)TRUE);

              /* Transition: '<S37>:2037' */
            } else {
              /* Transition: '<S37>:2036' */
            }

            /* Transition: '<S37>:2039' */
            /* '<S37>:2039:1' DTC_State_Info_Tab(int32(i)+1).testFailed=TRUE; */
            DTC_State_Info_Tab[i].testFailed = ((UInt8)TRUE);

            /* '<S37>:2039:2' DTC_State_Info_Tab(int32(i)+1).testFailedThisMonitoringCycle=TRUE; */
            DTC_State_Info_Tab[i].testFailedThisMonitoringCycle = ((UInt8)TRUE);

            /* '<S37>:2039:3' DTCErrDebounceTmrCnt(i+1) = DTCErrDebounceTmrCntCnstr(i+1); */
            DTCErrDebounceTmrCnt[(i)] = ((UInt8)DTCErrDebounceTmrCntCnstr[(i)]);

            /* Transition: '<S37>:2040' */
          } else {
            /* Transition: '<S37>:1999' */
            /* '<S37>:2001:1' sf_internal_predicateOutput = DTCErrDebounceTmrCnt(... */
            /* '<S37>:2001:1' int32(i)+1)==uint8(0); */
            if (((Int32)DTCErrDebounceTmrCnt[(i)]) == 0) {
              /* Transition: '<S37>:2001' */
              /* '<S37>:2005:1' sf_internal_predicateOutput = DTC_State_Info_Tab(... */
              /* '<S37>:2005:1' int32(i)+1).confirmedDTC==FALSE; */
              if (DTC_State_Info_Tab[i].confirmedDTC == ((UInt8)FALSE)) {
                /* Transition: '<S37>:2005' */
                /* Transition: '<S37>:2010' */
                /* '<S37>:2010:1' DTC_State_Info_Tab(... */
                /* '<S37>:2010:1' int32(i)+1).confirmedDTC=TRUE; */
                DTC_State_Info_Tab[i].confirmedDTC = ((UInt8)TRUE);

                /* '<S37>:2010:2' DTC_Ctrl_Info_Tab(... */
                /* '<S37>:2010:3' int32(i)+1).StoreReq=TRUE; */
                DTC_Ctrl_Info_Tab[i].StoreReq = ((UInt8)TRUE);

                /* '<S37>:2012:1' sf_internal_predicateOutput = Read_DTC_IgnitCycle_Tab(int32(i)+1)==... */
                /* '<S37>:2012:1' uint8(0); */
                if (((Int32)Read_DTC_IgnitCycle_Tab[(i)]) == 0) {
                  /* Transition: '<S37>:2012' */
                  /* Transition: '<S37>:2014' */
                  /* '<S37>:2014:1' DTC_Ctrl_Info_Tab(... */
                  /* '<S37>:2014:1' int32(i)+1).IgnitCycleReq=... */
                  /* '<S37>:2014:2' uint8(EPS_IGNIT.REQ_CLR); */
                  DTC_Ctrl_Info_Tab[i].IgnitCycleReq = (UInt8)EPS_IGNIT_REQ_CLR;

                  /* Transition: '<S37>:2017' */
                } else {
                  /* Transition: '<S37>:2016' */
                }

                /* Transition: '<S37>:2018' */
              } else {
                /* Transition: '<S37>:2007' */
              }

              /* Transition: '<S37>:2008' */
            } else {
              /* Transition: '<S37>:2003' */
            }

            /* Transition: '<S37>:2020' */
            /* '<S37>:2020:1' DTC_State_Info_Tab(... */
            /* '<S37>:2020:1' int32(i)+1).warningIndicatorRequest=... */
            /* '<S37>:2020:2' DTC_Ctrl_Info_Tab(... */
            /* '<S37>:2020:3' int32(i)+1).LightLampReq; */
            DTC_State_Info_Tab[i].warningIndicatorRequest = DTC_Ctrl_Info_Tab[i]
              .LightLampReq;
          }

          /* Transition: '<S37>:2042' */
          /* '<S37>:2044:1' sf_internal_predicateOutput = DTCErrDebounceTmrCnt(i+1) > uint8(0); */
          if (((Int32)DTCErrDebounceTmrCnt[(i)]) > 0) {
            /* Transition: '<S37>:2044' */
            /* Transition: '<S37>:2046' */
            /* '<S37>:2046:1' DTCErrDebounceTmrCnt(i+1)=... */
            /* '<S37>:2046:1' DTCErrDebounceTmrCnt(i+1)-1; */
            DTCErrDebounceTmrCnt[(i)] = (UInt8)(((UInt32)DTCErrDebounceTmrCnt[(i)])
              - 1U);

            /* Transition: '<S37>:2048' */
          } else {
            /* Transition: '<S37>:2049' */
          }

          /* Transition: '<S37>:1988' */
        } else {
          /* Transition: '<S37>:1991' */
          /* '<S37>:1993:1' sf_internal_predicateOutput = DTC_CodeStrInfo(... */
          /* '<S37>:1993:1' int32(i)+1).Priority <= uint8(2) &... */
          /* '<S37>:1993:1' (DTC_Ctrl_Info_Tab(... */
          /* '<S37>:1993:2' int32(i)+1).LightLampUnrecover==TRUE) &... */
          /* '<S37>:1993:2' (DTC_State_Info_Tab(... */
          /* '<S37>:1993:3' int32(i)+1).testFailedThisMonitoringCycle==TRUE) &... */
          /* '<S37>:1993:5' (DTC_State_Info_Tab(... */
          /* '<S37>:1993:5' int32(i)+1).warningIndicatorRequest==FALSE); */
          if ((((((Int32)DTC_CodeStrInfo[i].Priority) <= 1/*2*/) &&   /* ????????DTC??????2??????--TXY--20230130*/
                (DTC_Ctrl_Info_Tab[i].LightLampUnrecover == ((UInt8)TRUE))) &&
               (DTC_State_Info_Tab[i].testFailedThisMonitoringCycle == ((UInt8)
                 TRUE))) && (DTC_State_Info_Tab[i].warningIndicatorRequest ==
                             ((UInt8)FALSE))) {
            /* Transition: '<S37>:1993' */
            /* Transition: '<S37>:1995' */
            /* '<S37>:1995:1' DTC_State_Info_Tab(... */
            /* '<S37>:1995:1' int32(i)+1).warningIndicatorRequest=TRUE; */
            DTC_State_Info_Tab[i].warningIndicatorRequest = ((UInt8)TRUE);

            /* Transition: '<S37>:1996' */
          } else {

          }

          /* Transition: '<S37>:1972' */
          /* '<S37>:1972:1' DTC_State_Info_Tab(int32(i)+1).testFailed= FALSE; */
          DTC_State_Info_Tab[i].testFailed = ((UInt8)FALSE);

          /* '<S37>:1972:2' DTC_State_Info_Tab(int32(i)+1).warningIndicatorRequest=uint8(... */
          /* '<S37>:1972:3' (DTC_State_Info_Tab(int32(i)+1).warningIndicatorRequest) &... */
          /* '<S37>:1972:4' (DTC_Ctrl_Info_Tab(int32(i)+1).LightLampUnrecover)); */
          // DTC_State_Info_Tab[i].warningIndicatorRequest = (UInt8)(((((Int32)
          //   DTC_State_Info_Tab[i].warningIndicatorRequest) != 0) && (((Int32)
          //   DTC_Ctrl_Info_Tab[i].LightLampUnrecover) != 0)) ? 1 : 0);
            DTC_State_Info_Tab[i].warningIndicatorRequest = FALSE; // BYD SUEA??????????????08-WSY20230510
          /* '<S37>:1974:1' sf_internal_predicateOutput = DTC_Ctrl_Info_Tab(... */
          /* '<S37>:1974:1' int32(i)+1).OnStarTrigEnabled==... */
          /* '<S37>:1974:1' TRUE; */
          if (DTC_Ctrl_Info_Tab[i].OnStarTrigEnabled == ((UInt8)TRUE)) {
            /* Transition: '<S37>:1974' */
            /* Transition: '<S37>:1976' */
            /* '<S37>:1976:1' DTC_Ctrl_Info_Tab(... */
            /* '<S37>:1976:1' int32(i)+1).OnStarTrigEnabled=FALSE; */
            DTC_Ctrl_Info_Tab[i].OnStarTrigEnabled = ((UInt8)FALSE);

            /* Transition: '<S37>:1982' */
          } else {
            /* Transition: '<S37>:1978' */
          }

          /* Transition: '<S37>:1983' */
        }

        /* Transition: '<S37>:1965' */
      } else {
        /* Transition: '<S37>:1950' */
      }

      /* Transition: '<S37>:1955' */
      /* '<S37>:1955:1' i=i+1; */
      i = (UInt8)(((UInt32)i) + 1U);

      /* '<S37>:1957:1' sf_internal_predicateOutput = i<EPS_DTC_NUM_MAX; */
      if (((Int32)i) < EPS_DTC_NUM_MAX) {
        /* Transition: '<S37>:1957' */
        /* Transition: '<S37>:1960' */
        /* Transition: '<S37>:1961' */
      } else {
        /* Transition: '<S37>:1962' */
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);

  /* End of Chart: '<S2>/DTC_Testfailed_Logic' */
}

/* System initialize for atomic system: '<Root>/DTCLogic' */
void DTC_CANCheck_DTCLogic_Init(void)
{
  /* SystemInitialize for Chart: '<S2>/DTC_Testfailed_Logic' */
  DTC_C_DTC_Testfailed_Logic_Init();
}

/* Output and update for atomic system: '<Root>/DTCLogic' */
void DTC_CANCheck_DTCLogic(void)
{
  /* Chart: '<S2>/DTC_Testfailed_Logic' */
  DTC_CANChe_DTC_Testfailed_Logic();

  /* Chart: '<S2>/DTC_Allow_Occur_Logic' */
  DTC_CANCh_DTC_Allow_Occur_Logic();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

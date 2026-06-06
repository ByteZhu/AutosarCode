
#include "Ext_DataConv.h"
#include "GlobalVar.h"
#include "CalVar.h"
#include "CalVarExt.h"

ARID_DEF_CAN_DataConv_Ws_CAN_Da rtCAN_DataConv_Ws_ARID_DEF_CAN_;

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
/* Output and update for function-call system: '<Root>/CAN_DataConv_Ws' */
void Ext_DataConv_Ws(void)
{
  sint16 u0;

  /* Sum: '<S8>/ARSumFilter1' incorporates:
   *  Constant: '<S8>/FilterCoef1'
   *  Inport generated from: '<Root>/In Bus Element7'
   *  Product: '<S8>/ARProductFilter1'
   *  Sum: '<S8>/ARSubFilter1'
   *  UnitDelay: '<S8>/ARDelayFilter1'
   */
  u0 = (sint16)((uint32)(((sint16)
    (Fv_Ws_Flws_raw -
     rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter1_DSTATE) * Cal_WS_FilterCoef)
    >> 7) + rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter1_DSTATE);

  /* Saturate: '<S8>/Saturation' */
  if (u0 <= ((uint16)32768U)) {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter1_DSTATE = u0;
  } else {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter1_DSTATE = ((uint16)32768U);
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Sum: '<S8>/ARSumFilter2' incorporates:
   *  Constant: '<S8>/FilterCoef2'
   *  Inport generated from: '<Root>/In Bus Element10'
   *  Product: '<S8>/ARProductFilter2'
   *  Sum: '<S8>/ARSubFilter2'
   *  UnitDelay: '<S8>/ARDelayFilter2'
   */
  u0 = (sint16)((uint32)(((sint16)
    (Fv_Ws_Frws_raw -
     rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter2_DSTATE) * Cal_WS_FilterCoef)
    >> 7) + rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter2_DSTATE);

  /* Saturate: '<S8>/Saturation1' */
  if (u0 <= ((uint16)32768U)) {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter2_DSTATE = u0;
  } else {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter2_DSTATE = ((uint16)32768U);
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* Sum: '<S8>/ARSumFilter3' incorporates:
   *  Constant: '<S8>/FilterCoef3'
   *  Inport generated from: '<Root>/In Bus Element2'
   *  Product: '<S8>/ARProductFilter3'
   *  Sum: '<S8>/ARSubFilter3'
   *  UnitDelay: '<S8>/ARDelayFilter3'
   */
  u0 = (sint16)((uint32)(((sint16)
    (Fv_Ws_Rlws_raw -
     rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter3_DSTATE) * Cal_WS_FilterCoef)
    >> 7) + rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter3_DSTATE);

  /* Saturate: '<S8>/Saturation2' */
  if (u0 <= ((uint16)32768U)) {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter3_DSTATE = u0;
  } else {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter3_DSTATE = ((uint16)32768U);
  }

  /* End of Saturate: '<S8>/Saturation2' */

  /* Sum: '<S8>/ARSumFilter4' incorporates:
   *  Constant: '<S8>/FilterCoef4'
   *  Inport generated from: '<Root>/In Bus Element16'
   *  Product: '<S8>/ARProductFilter4'
   *  Sum: '<S8>/ARSubFilter4'
   *  UnitDelay: '<S8>/ARDelayFilter4'
   */
  u0 = (sint16)((uint32)(((sint16)
    (Fv_Ws_Rrws_raw -
     rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter4_DSTATE) * Cal_WS_FilterCoef)
    >> 7) + rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter4_DSTATE);

  /* Saturate: '<S8>/Saturation3' */
  if (u0 <= ((uint16)32768U)) {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter4_DSTATE = u0;
  } else {
    rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter4_DSTATE = ((uint16)32768U);
  }

  /* End of Saturate: '<S8>/Saturation3' */

    Fv_WheelSpeed_FL = rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter1_DSTATE;
    Fv_WheelSpeed_FL = (uint16)((sint32)Fv_WheelSpeed_FL * 32 * 391 * 36 / 10 / 100000);
    //WheelSpd Factor 0.00391m/s to kph

    Fv_WheelSpeed_FR = rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter2_DSTATE;
    Fv_WheelSpeed_FR = (uint16)((sint32)Fv_WheelSpeed_FR * 32 * 391 * 36 / 10 / 100000);

    Fv_WheelSpeed_RL = rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter3_DSTATE;
    Fv_WheelSpeed_RL = (uint16)((sint32)Fv_WheelSpeed_RL * 32 * 391 * 36 / 10 / 100000);

    Fv_WheelSpeed_RR = rtCAN_DataConv_Ws_ARID_DEF_CAN_.ARDelayFilter4_DSTATE;
    Fv_WheelSpeed_RR = (uint16)((sint32)Fv_WheelSpeed_RR * 32 * 391 * 36 / 10 / 100000);

    Fv_VechYawRate = (sint16)((sint32)Fv_YawRate_Raw / 4096);
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void Ext_DataConv_YawRate(void)
{
	if(fsAsyDataWithCmpSafeValid > 0)
	{
		Fv_YawRate_Raw = fsYawRateWithComp;
	}
	else
	{
		Fv_YawRate_Raw = fsYawRateCompensated;
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
#define MACRO_EXT_INTERNALSPD_DRIVEDOWN 213 /*3km/h*/
#define MACRO_EXT_INTERNALSPD_DEFAULT   5683/*80km/h*/
uint16 Ext_DataConv_InternalSpd(uint16 can_spd, uint8 spd_valid, uint8 spd_timeout, uint8 veh_mtn_s, uint8 five_min_rule)
{
  static uint8 ext_internalspd_state = 0;
  static uint16 ext_internalspd = 0;
  switch(ext_internalspd_state)
  {
    case MACRO_EXT_INTERNALSPD_STATE_ZERO:
      if((spd_valid > 0) && (spd_timeout == 0))
      {
        ext_internalspd_state = MACRO_EXT_INTERNALSPD_STATE_NORMAL;
      }
      else if((five_min_rule == 0) && ((spd_valid == 0) || ((veh_mtn_s < 1) || (veh_mtn_s > 3))))
      {
        ext_internalspd_state = MACRO_EXT_INTERNALSPD_STATE_DEFAULT;
      }
      else
      {
        /*in state*/
        ext_internalspd = 0;
      }
      CAN_Vs_Err = 0;
    break;
    case MACRO_EXT_INTERNALSPD_STATE_NORMAL:
      if((ext_internalspd <= MACRO_EXT_INTERNALSPD_DRIVEDOWN) && (spd_timeout > 0))
      {
        ext_internalspd_state = MACRO_EXT_INTERNALSPD_STATE_ZERO;
      }
      else if(((ext_internalspd > MACRO_EXT_INTERNALSPD_DRIVEDOWN) && (spd_timeout > 0)) || (spd_valid == 0))
      {
        ext_internalspd_state = MACRO_EXT_INTERNALSPD_STATE_DEFAULT;
      }
      else
      {
        
        ext_internalspd = can_spd;
      }
      CAN_Vs_Err = 0;
    break;
    default:
      if(five_min_rule > 0)
      {
        ext_internalspd_state = MACRO_EXT_INTERNALSPD_STATE_ZERO;
      }
      else if((spd_valid > 0) && (spd_timeout == 0))
      {
        ext_internalspd_state = MACRO_EXT_INTERNALSPD_STATE_NORMAL;
      }
      else
      {
        /*in state*/
        ext_internalspd = MACRO_EXT_INTERNALSPD_DEFAULT;
      }
      CAN_Vs_Err = 1;
    break;    
  }
  return ext_internalspd;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
#define MACRO_EXT_POWERMODE_SPD_DRIVEDOWN 213 /*3km/h*/
uint8 Ext_DataConv_PowerMode(uint8 can_pm, uint8 pm_valid, uint8 pm_timeout, uint16 internal_spd, uint8 nm)
{
  static uint8 ext_powermode_state = 0;
  static uint8 ext_internalpowermode = 0;
  switch(ext_powermode_state)
  {
    case MACRO_EXT_POWERMODE_STATE_IDLE:
      if((pm_valid > 0) && (pm_timeout == 0))
      {
        ext_powermode_state = MACRO_EXT_POWERMODE_STATE_NORMAL;
      }
      else if((nm > 0) || (internal_spd > MACRO_EXT_POWERMODE_SPD_DRIVEDOWN))
      {
        ext_powermode_state = MACRO_EXT_POWERMODE_STATE_DRIVING;
      }
      else
      {
        /*in state*/
        ext_internalpowermode = EXT_POWERMODE_IDLE;
      }
    break;
    case MACRO_EXT_POWERMODE_STATE_DRIVING:
      if((pm_valid > 0) && (pm_timeout == 0))
      {
        ext_powermode_state = MACRO_EXT_POWERMODE_STATE_NORMAL;
      }
      else if((nm == 0) && (internal_spd <= MACRO_EXT_POWERMODE_SPD_DRIVEDOWN))
      {
        ext_powermode_state = MACRO_EXT_POWERMODE_STATE_IDLE;
      }
      else
      {
        /*in state*/
        ext_internalpowermode = EXT_POWERMODE_DRIVING;
      }
    break;
    default://NORMAL
      if(((pm_valid == 0) || (pm_timeout > 0)) && (nm == 0) && (internal_spd <= MACRO_EXT_POWERMODE_SPD_DRIVEDOWN))
      {
        ext_powermode_state = MACRO_EXT_POWERMODE_STATE_IDLE;
      }
      else if(((pm_valid == 0) || (pm_timeout > 0)) && ((nm > 0) || (internal_spd > MACRO_EXT_POWERMODE_SPD_DRIVEDOWN)))
      {
        ext_powermode_state = MACRO_EXT_POWERMODE_STATE_DRIVING;
      }
      else
      {
        /*in state*/
        ext_internalpowermode = can_pm;
      }
    break;
  }
  return ext_internalpowermode;
}
uint8 Ext_DataConv_AssisReq(uint8 can_assreq, uint8 assreq_valid)
{
  static uint8 ext_internalassreq = 0;
  if(assreq_valid)
  {
    ext_internalassreq = can_assreq;
  }
  else
  {
    ext_internalassreq = EXT_ASSREQ_NOREQ;
  }
  return ext_internalassreq;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
#define MACRO_EXT_DRIVERMODE_SPD_DRIVEUP 213 /*3km/h*/
#define MACRO_EXT_DRIVERMODE_SPD_REDUCEMAX 0 /*0km/h*/
uint8 Ext_DataConv_DriverMode(uint16 internal_spd, uint8 internal_pm, uint8 internal_assreq, uint8 nm, uint8 el_pwrlvl)
{
  static uint8 ext_drivermode_state = 0;
  static uint8 ext_assistmode_state = 0;
  static uint8 ext_drivemode = 0;
  //debug_jing1 = ext_drivermode_state;
  switch(ext_drivermode_state)
  {
    case MACRO_EXT_DRIVERMODE_STATE_OFF:
      if(nm > 0)
      {
        ext_drivermode_state = MACRO_EXT_DRIVERMODE_STATE_DRIVEDOWN;
      }
      else
      {
        ext_drivemode = MACRO_EXT_DRIVERMODE_STATE_OFF;
      }
    break;
    case MACRO_EXT_DRIVERMODE_STATE_DRIVEDOWN:
      if(Fv_HighFailFlag)
      {
        ext_drivermode_state = MACRO_EXT_DRIVERMODE_STATE_ERRORMODE;
      }
      else if((internal_spd >= MACRO_EXT_DRIVERMODE_SPD_DRIVEUP) || (internal_pm == EXT_POWERMODE_DRIVING) || ((internal_assreq == EXT_ASSREQ_REQ) && (internal_pm == EXT_POWERMODE_ACTIVE)))
      {
        ext_drivermode_state = MACRO_EXT_DRIVERMODE_STATE_DRIVEUP;
        ext_assistmode_state = MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_FULL;
      }
      else
      {
        ext_drivemode = MACRO_EXT_DRIVERMODE_STATE_DRIVEDOWN;
      }
    break;
    case MACRO_EXT_DRIVERMODE_STATE_ERRORMODE:
    break;
    default://MACRO_EXT_DRIVERMODE_STATE_DRIVEUP
      if(Fv_HighFailFlag)
      {
        ext_drivermode_state = MACRO_EXT_DRIVERMODE_STATE_ERRORMODE;
      }
      else if((internal_spd < MACRO_EXT_DRIVERMODE_SPD_DRIVEUP) && (internal_pm != EXT_POWERMODE_DRIVING) && (internal_assreq == EXT_ASSREQ_NOREQ))
      {
        ext_drivermode_state = MACRO_EXT_DRIVERMODE_STATE_DRIVEDOWN;
      }
      else
      {
        switch (ext_assistmode_state)
        {
          case MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_FULL:
            if((internal_spd < MACRO_EXT_DRIVERMODE_SPD_REDUCEMAX) && (el_pwrlvl & 3 > 0))
            {
              ext_assistmode_state = MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_LIMIT;
            }
            else
            {
              ext_drivemode = MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_FULL;
            }
          break;        
          default://MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_LIMIT
            if((internal_spd >= MACRO_EXT_DRIVERMODE_SPD_REDUCEMAX) && (el_pwrlvl & 3 > 0))
            {
              ext_assistmode_state = MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_FULL;
            }
            else
            {
              ext_drivemode = MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_LIMIT;
            }
          break;
        }
        
      }
    break; 
  }
  return ext_drivemode;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
#define MACRO_EXT_FIVEMINRULE_TRQ_RAMPDOWN (3 * 1024)
uint8 Ext_DataConv_FiveMinusRule(sint16 strtrq)
{
  sint16 abstrq = 0;
  sint16 trqdiff = 0;
  static uint8 rule = 1;
  static uint32 ruleCnt = 300000;
  static sint16 lasttrq = 0;
  static uint16 startcnt = 0;
  if(strtrq < 0)
  {
    abstrq = -strtrq;
  }
  else
  {
    abstrq = strtrq;
  }

  trqdiff = strtrq - lasttrq;

  if(trqdiff < 0)
  {
	  trqdiff = - trqdiff;
  }
  if(startcnt < 200)
  {
	  startcnt ++;
	  trqdiff = 0;
  }
  else
  {

  }
  lasttrq = strtrq;
  if(rule)
  {
    if((abstrq >= MACRO_EXT_FIVEMINRULE_TRQ_RAMPDOWN) || (trqdiff > 128))
    {
      rule = 0;
      ruleCnt = 300000;
    }
  }
  else 
  {
    if((abstrq < MACRO_EXT_FIVEMINRULE_TRQ_RAMPDOWN) && (trqdiff < 128))
    {
      if(ruleCnt > 0)
      {
        ruleCnt--;
      }
      else
      {
        rule = 1;
      }       
    }
    else
    {
      ruleCnt = 300000;
    }
  }

  return rule;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void Ext_DataConv_SteeringMode(void)
{
	static uint16 switchcnt = 0;

	if((Fv_EXT_InternalPowerMode == EXT_POWERMODE_DRIVING) || (Fv_EXT_InternalPowerMode == EXT_POWERMODE_ACTIVE))
	{
		if(Fv_CMDAssistSelectMode != Fv_RUNAssistSelectMode)
		{
			if(((Fv_StrTrq0 < Cal_MapSwitchTorqueLimit) && (Fv_StrTrq0 > -Cal_MapSwitchTorqueLimit))
					|| (Fv_VehSpdNew < Cal_MapSwitchSpeedLimit))
			{
				if(switchcnt < Cal_MapSwitchTime)
				{
					switchcnt ++;
				}
				else
				{
					Fv_RUNAssistSelectMode = Fv_CMDAssistSelectMode;
					AssistModeStored();
				}
			}
			else
			{
				switchcnt = 0;
			}
		}
		else
		{
			switchcnt = 0;
		}
	}
	else
	{
		switchcnt = 0;
	}

	Fv_SteerAssistMode = Fv_RUNAssistSelectMode;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void Ext_DualPSCMFallBackWarning(void)
{
	static uint8 warningstart = 0;
	static uint16 pulsetime = 0;
	static uint16 pulsecnt = 0;
	static uint8 pulseinvalid = 0;

	/* half error, warning driver */
	if(((Fv_HighFailFlag1 == 0) && (Fv_HighFailFlag2 > 0))
		|| ((Fv_HighFailFlag2 == 0) && (Fv_HighFailFlag1 > 0)))
	{
		if((Fv_LKA_ControlSts == 2) || (Fv_APA_ControlSts == 2))
		{
			pulsecnt = Cal_DPFW_PulseCnt;
		}

		if(pulsecnt < Cal_DPFW_PulseCnt)
		{
			warningstart = 1;
		}
		else
		{
			pulsecnt = Cal_DPFW_PulseCnt;
			warningstart = 0;
		}


	}
	else
	{
		warningstart = 0;
		pulseinvalid = 0;
		pulsetime = 0;
	}

	if(warningstart == 1)
	{
		if(pulseinvalid == 0)
		{
			/* warning start request */
			Fv_DualPSCMFallBackWarningReq = 1;
			/* warning allowed time */
			if(pulsetime < Cal_DPFW_PulseValidTime)
			{
				pulsetime ++;
			}
			else
			{
				pulseinvalid = 1;
				pulsetime = 0;
				/* warning times added */
				pulsecnt ++;
			}
		}
		else
		{
			/* warning stop request */
			Fv_DualPSCMFallBackWarningReq = 0;
			/* warning stop time */
			if(pulsetime < Cal_DPFW_PulseInValidTime)
			{
				pulsetime ++;
			}
			else
			{
				pulseinvalid = 0;
				pulsetime = 0;
			}
		}
	}
	else
	{
		/* warning not allowed */
		Fv_DualPSCMFallBackWarningReq = 0;
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void Ext_DataConv_1ms_Task(void)
{
  static uint16 spdlostcnt = 0;
  static uint16 pmlostcnt = 0;

  if(Fv_EXT_SpdIndication == 0xAA)
  {
    Fv_EXT_SpdIndication = 0;
    Fv_EXT_SpdLostFlag = 0;
    spdlostcnt = 0;
  }
  else
  {
    if(spdlostcnt < 500)
    {
      spdlostcnt++;
    }
    else
    {
      Fv_EXT_SpdLostFlag = 1;
    }
  }

  if(Fv_EXT_PMIndication == 0xAA)
  {
    Fv_EXT_PMIndication = 0;
    Fv_EXT_PMLostFlag = 0;
    pmlostcnt = 0;
  }
  else
  {
    if(pmlostcnt < 500)
    {
      pmlostcnt++;
    }
    else
    {
      Fv_EXT_PMLostFlag = 1;
    }
  }
	
  if(Fv_EXT_InnerCanLostCnt < 200)
	{
		Fv_EXT_InnerCanLostCnt++;
    Fv_EXT_RE_InnerCanState = 1;
	}
  else
  {
    Fv_EXT_RE_InnerCanState = 0;
  }
  Fv_EXT_FiveMinRule = Ext_DataConv_FiveMinusRule(Fv_StrTrq0);
	Fv_EXT_InternalSpd = Ext_DataConv_InternalSpd(Fv_EXT_CanSpd, Fv_EXT_SpdValidFlag, Fv_EXT_SpdLostFlag, Fv_EXT_CanVehMtnS, Fv_EXT_FiveMinRule);
  //debug_jing1 = Fv_EXT_SpdValidFlag | Fv_EXT_SpdLostFlag<<1 |Fv_EXT_CanVehMtnS<<2|Fv_EXT_FiveMinRule<<3;
	Fv_EXT_InternalPowerMode = Ext_DataConv_PowerMode(Fv_EXT_CanPowerMode, Fv_EXT_PMValidFlag, Fv_EXT_PMLostFlag, Fv_EXT_InternalSpd, Fv_EXT_NMState);
	Fv_EXT_InternalAssReq = Ext_DataConv_AssisReq(Fv_EXT_CanAssReq, Fv_EXT_ASSReqValidFlag);
	if((Fv_EXT_InternalPowerMode == EXT_POWERMODE_DRIVING)  //todo liuyang at 241122 to delete active
			|| ((Fv_EXT_InternalPowerMode == EXT_POWERMODE_ACTIVE) && (Fv_EXT_InternalAssReq == EXT_ASSREQ_REQ)))
	{
		CAN_EngSpd = 4000;
	}
	else
	{
		CAN_EngSpd = 0;
	}

	CAN_Es_Err = 0;

	CAN_VehSpd = Fv_EXT_InternalSpd;

	Fv_ABSVSReciveTimer = 0;

	Fv_EMSVSReciveTimer = 0;

	Ext_DataConv_SteeringMode();
	Ext_DataConv_YawRate();

	Ext_DualPSCMFallBackWarning();
}


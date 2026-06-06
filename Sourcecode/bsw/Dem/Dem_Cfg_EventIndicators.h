
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_EVENTINDICATORS_H
#define DEM_CFG_EVENTINDICATORS_H

#define DEM_CFG_EVT_INDICATOR_OFF                0u
#define DEM_CFG_EVT_INDICATOR_ON                 1u
#define DEM_CFG_EVT_INDICATOR_PROJECTSPECIFIC    2u
#define DEM_CFG_EVT_INDICATOR                    DEM_CFG_EVT_INDICATOR_OFF
/*********************************Indicator*********************************************************************/
#define DEM_INDICATORID_INVALID                                      0u
#define DEM_INDICATORID_COUNT                                        0u
#define DEM_INDICATORID_ARRAYLENGTH                                  (DEM_INDICATORID_COUNT + 2u)
#define DEM_INDICATOR_ID_REQUIRED_BIT_SIZE                           1u



/*****************************Indicator Attributes*************************************************************/

#define DEM_INDICATOR_ATTRIBUTE_INVALID                              0u

#define DEM_CFG_EVTINDICATOR_IS_COMMON_FAILURETHRESHOLD_USED FALSE
#define DEM_CFG_EVTINDICATOR_IS_COMMON_HEALINGTHRESHOLD_USED FALSE
#define DEM_CFG_EVTINDICATOR_IS_COMMON_BEHAVIOUR_USED FALSE


#define DEM_INDICATOR_ATTRIBUTE_MAX_PER_EVENT              	0u
#define DEM_INDICATOR_ATTRIBUTE_COUNT            			(DEM_EVENTID_COUNT * DEM_INDICATOR_ATTRIBUTE_MAX_PER_EVENT)
#define DEM_INDICATOR_ATTRIBUTE_ARRAYLENGTH           		(DEM_INDICATOR_ATTRIBUTE_COUNT)

#define DEM_INDICATOR_FAILURE_THRESHOLD_REQUIRED_BIT_SIZE             0u
#define DEM_INDICATOR_HEALING_THRESHOLD_REQUIRED_BIT_SIZE             0u

#define DEM_CFG_DEFAULT_FAILURE_THRESHOLD                            0x00u


#define DEM_CFG_DEFAULT_HEALING_THRESHOLD                            0x00u

#define DEM_INDICATOR_ATTRIBUTE_REQUIRED_BIT_SIZE                    0x03u
#define DEM_ALL_INDICATORS_USING_SAME_BEHAVIOUR                      0x00u

/* --------------------------------------------------- */
/* DEM INDICATOR STATE BITPOSITION                         */
/* --------------------------------------------------- */

#define DEM_EVTINDICATOR_BP_PARAM_APICONTROL                 0u
#define DEM_EVTINDICATOR_PARAMINI_APICONTROL(X)              ((Dem_EvtIndicatorParamType)(X)<<DEM_EVTINDICATOR_BP_PARAM_APICONTROL)

#define DEM_EVTINDICATOR_BP_PARAM_BEHAVIOUR                  1u
#define DEM_EVTINDICATOR_PARAMINI_BEHAVIOUR(X)               ((Dem_EvtIndicatorParamType)(X)<<DEM_EVTINDICATOR_BP_PARAM_BEHAVIOUR)

#define DEM_EVTINDICATOR_PARAMINI_FAILTHRESHOLD(X)

#define DEM_EVTINDICATOR_PARAMINI_HEALTHRESHOLD(X)

#define DEM_EVTINDICATOR_BP_PARAM_INDICATORID                4u
#define DEM_EVTINDICATOR_PARAMINI_INDICATORID(X)             ((Dem_EvtIndicatorParamType)(X)<<DEM_EVTINDICATOR_BP_PARAM_INDICATORID)


typedef uint8 Dem_EvtIndicatorParamType;
#define DEM_EVTINDICATORPARAM_ISBITSET                        rba_DiagLib_Bit8IsBitSet
#define DEM_EVTINDICATORPARAM_GETBITS                         rba_DiagLib_Bit8GetBits


/*******************************************************/



/*                 BEHAVIOUR                     FAILURE_THRESHOLD             HEALING_THRESHOLD             INDICATOR_ID                                                                                        APICONTROL                     */
#define DEM_CFG_EVENT_INDICATOR_ATTRIBUTE_PARAMS \
{ \
}

#endif


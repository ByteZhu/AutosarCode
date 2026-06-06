#ifndef EXT_DataConv_h_
#define EXT_DataConv_h_
#include "rtwtypes.h"
#include "GlobalVar_EXT.h"

/* PublicStructure Variables for Internal Data, for system '<Root>/CAN_DataConv_Ws' */
typedef struct {
  uint16 ARDelayFilter1_DSTATE;        /* '<S8>/ARDelayFilter1' */
  uint16 ARDelayFilter2_DSTATE;        /* '<S8>/ARDelayFilter2' */
  uint16 ARDelayFilter3_DSTATE;        /* '<S8>/ARDelayFilter3' */
  uint16 ARDelayFilter4_DSTATE;        /* '<S8>/ARDelayFilter4' */
  boolean AND;                         /* '<S8>/AND' */
} ARID_DEF_CAN_DataConv_Ws_CAN_Da;


#define EXT_POWERMODE_IDLE    2
#define EXT_POWERMODE_ACTIVE  4
#define EXT_POWERMODE_DRIVING 8

#define EXT_POWERMODE_IDLE    2
#define EXT_POWERMODE_ACTIVE  4
#define EXT_POWERMODE_DRIVING 8

#define EXT_VehMntS_Ukwn        0
#define EXT_VehMntS_StandStill1 1
#define EXT_VehMntS_StandStill2 2
#define EXT_VehMntS_StandStill3 3
#define EXT_VehMntS_RollFwd1    4
#define EXT_VehMntS_RollFwd2    5
#define EXT_VehMntS_RollBackw1  6
#define EXT_VehMntS_RollBackw2  7

#define EXT_ASSREQ_NOREQ        0
#define EXT_ASSREQ_REQ          1


#define MACRO_EXT_INTERNALSPD_STATE_ZERO 0
#define MACRO_EXT_INTERNALSPD_STATE_NORMAL 1
#define MACRO_EXT_INTERNALSPD_STATE_DEFAULT 2


#define MACRO_EXT_POWERMODE_STATE_IDLE 0
#define MACRO_EXT_POWERMODE_STATE_DRIVING 1
#define MACRO_EXT_POWERMODE_STATE_NORMAL 2

#define MACRO_EXT_DRIVERMODE_STATE_OFF 0
#define MACRO_EXT_DRIVERMODE_STATE_DRIVEDOWN 1
#define MACRO_EXT_DRIVERMODE_STATE_ERRORMODE 2
#define MACRO_EXT_DRIVERMODE_STATE_DRIVEUP 3
#define MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_FULL 4
#define MACRO_EXT_DRIVERMODE_STATE_DRIVEUP_LIMIT 5


/* NC -> not Cal */
/* NO -> not Out */
#define MACRO_EXT_RESYS_STATUS_Init 0
#define MACRO_EXT_RESYS_STATUS_MCO_SO 1 /* MCO_SO */
#define MACRO_EXT_RESYS_STATUS_MCO_SX 2 /* MCO_SX */
#define MACRO_EXT_RESYS_STATUS_MC_SO 3 /* MC_SO */
#define MACRO_EXT_RESYS_STATUS_MX_SCO 4 /* MX_SCO */
#define MACRO_EXT_RESYS_STATUS_MO_SC 5 /* MO_SC */
#define MACRO_EXT_RESYS_STATUS_MO_SCO 6 /* MO_SCO */
#define MACRO_EXT_RESYS_STATUS_MCO_SCO 7 /* MCO_SCO/CanLost */
#define MACRO_EXT_RESYS_STATUS_MX_SX 8 /* MX_SX */

extern ARID_DEF_CAN_DataConv_Ws_CAN_Da rtCAN_DataConv_Ws_ARID_DEF_CAN_;
extern void Ext_DataConv_Ws(void);
extern uint16 Ext_DataConv_InternalSpd(uint16 can_spd, uint8 spd_valid, uint8 spd_timeout, uint8 veh_mtn_s, uint8 five_min_rule);
extern uint8 Ext_DataConv_PowerMode(uint8 can_pm, uint8 pm_valid, uint8 pm_timeout, uint16 internal_spd, uint8 nm);
extern uint8 Ext_DataConv_AssisReq(uint8 can_assreq, uint8 assreq_valid);
extern uint8 Ext_DataConv_DriverMode(uint16 internal_spd, uint8 internal_pm, uint8 internal_assreq, uint8 nm, uint8 el_pwrlvl);
extern uint8 Ext_DataConv_FiveMinusRule(sint16 strtrq);
extern void Ext_DataConv_ReOutCtrl(void);

extern void Ext_DataConv_1ms_Task(void);
#endif               

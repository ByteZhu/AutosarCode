
   

     
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: CanSM / AR45.2.0.0           Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1             Tool Version
 *

 </VersionHead>*/


  /*********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
 #include "CanSM_PBcfg.h"





/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"


/* CanSM Network Index for corresponding CAN Controller ID */
const uint8 CanSM_NetworktoCtrl_Config_acu8[] = 
{
0,
1,
2};




/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"

/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"

/* CAN Contollerid for each network */
static const uint8 CanSM_Ctrl_Can_Network_CANNODE_0_Config_au8[] = 
{  
   CanIfConf_CanIfCtrlCfg_Can_Network_CANNODE_0

};

static const uint8 CanSM_Ctrl_Can_Network_CANNODE_1_Config_au8[] = 
{  
   CanIfConf_CanIfCtrlCfg_Can_Network_CANNODE_1

};

static const uint8 CanSM_Ctrl_Can_Network_CANNODE_2_Config_au8[] = 
{  
   CanIfConf_CanIfCtrlCfg_Can_Network_CANNODE_2

};




/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"

/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"



const CanSM_NetworkConf_tst CanSM_Network_Config_acst[] = 
{
/* ControllerStartIndx      BorTimeL1    BorTimeL2       BorTimeTxEnsured   BusOffErrID    Trcv_Handle   SizeOfController   BorCounter_L1_L2            ComMChannelId                   canSMEnableBusOffDelay    PN enabled/disabled for Transceiver*/
{
CanSM_Ctrl_Can_Network_CANNODE_0_Config_au8,2u,         12000u, 200u, DemConf_DemEventParameter_DTC_DC1A88_Event,255, 
1, 31,                       0,           FALSE,    FALSE },
{
CanSM_Ctrl_Can_Network_CANNODE_1_Config_au8,2u,         12000u, 200u, DemConf_DemEventParameter_DTC_DC1A88_Event,255, 
1, 31,                       1,           FALSE,    FALSE },
{
CanSM_Ctrl_Can_Network_CANNODE_2_Config_au8,2u,         12000u, 200u, DemConf_DemEventParameter_DTC_DC1A88_Event,255, 
1, 31,                       2,           FALSE,    FALSE }

};


/* CanSM Configuration */
const CanSM_ConfigType CanSM_ConfigSet[] = 
{

    {
        CanSM_Network_Config_acst,   /* Network Configuration array */
        CanSM_NetworktoCtrl_Config_acu8, /* CanSm Network Index mapped to corresponding CAN controller */
        
        14, /*CanSMModeRequestRepetitionTime*/
        5, /*CanSMModeRequestRepetitionMax*/
        CANSM_NUM_CAN_NETWORKS,      /*Number of CANSM Networks configured*/
        0 /*Active configSet index*/

    }
};
/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"

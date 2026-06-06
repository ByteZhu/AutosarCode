
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static const Dcm_DsdServicePBConfigType_tst   **Dcm_DsdSidTablesPbCfg_pacst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
 */


#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

void Dcm_Dsd_Init(const Dcm_ConfigType* ConfigPtr)
{
    Dcm_DsdSidTablesPbCfg_pacst = &ConfigPtr->sidTablesPbCfg_pcast[0];
    Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);
    Dcm_SrvOpstatus_u8 = DCM_INITIAL;
    Dcm_ExtSrvOpStatus_u8 = DCM_INITIAL;
    Dcm_Prv_SetResponsebyDSD(FALSE);
}

void Dcm_Dsd_Main(void)
{
    Dcm_Dsd_Prv_StateMachine();
}


const Dcm_DsdServicePBConfigType_tst** Dcm_Dsd_Prv_GetPBServiceTable(void)
{
    return Dcm_DsdSidTablesPbCfg_pacst;
}

void Dcm_Dsd_Prv_ServiceInit(uint8 ServiceTableIndex_u8)
{

    uint8 idxIndex_u8;
    uint8 NumberOfServices_u8 = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ServiceTableIndex_u8].numOfServices_u8;

    /* Pointer to active service table */
    const Dcm_DsdServiceTableConfigType_tst *Dcm_DsdSrvTableCfg_pst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ServiceTableIndex_u8].srvTable_pcast;

    /* call the initialisations of all services in the service table */
    for(idxIndex_u8 = NumberOfServices_u8; idxIndex_u8 != 0x00u; idxIndex_u8--)
    {
        if(Dcm_DsdSrvTableCfg_pst->serviceInit_fp != NULL_PTR )
        {
            (*Dcm_DsdSrvTableCfg_pst->serviceInit_fp)();
        }
        Dcm_DsdSrvTableCfg_pst++;
    }
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

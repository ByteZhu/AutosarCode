#include "ASW_DEM_ComDiag.h"
#include "Rte_Dem.h"
#include "Dem.h"

/**
 * @brief Check deal fault permission
 * @param 
 * @param 
 * @return
 */
boolean ComDiag_CheckDealFaultPermission(void)
{
    return TRUE;
}



/**
 * @brief Deal com fault C12182
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_C12182(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_C12182_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C12182, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C12182, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault C15182
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_C15182(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_C15182_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C15182, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C15182, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault C15982
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_C15982(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_C15982_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C15982, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C15982, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault C16882
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_C16882(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_C16882_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C16882, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C16882, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault C29682
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_C29682(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_C29682_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C29682, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_C29682, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault D10382
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_D10382(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_D10382_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_D10382, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_D10382, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault D44D82
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_D44D82(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_D44D82_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_D44D82, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_D44D82, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault E71883
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_E71883(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_E71883_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E71883, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E71883, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault E72783
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_E72783(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_E72783_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E72783, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E72783, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault E7B182
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_E7B182(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_E7B182_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E7B182, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E7B182, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault E7B283
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_E7B283(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_E7B283_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E7B283, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E7B283, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault E7B383
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_E7B383(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_E7B383_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E7B383, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_E7B383, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED3283
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED3283(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED3283_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3283, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3283, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED3383
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED3383(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED3383_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3383, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3383, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED3683
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED3683(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED3683_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3683, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3683, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED3983
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED3983(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED3983_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3983, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED3983, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED4183
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED4183(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED4183_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED4183, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED4183, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED5A83
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED5A83(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED5A83_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED5A83, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED5A83, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED7983
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED7983(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED7983_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED7983, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED7983, DEM_EVENT_STATUS_PREPASSED);
    }
}

/**
 * @brief Deal com fault ED9683
 * @param fault
 * @param type
 * @return
 */
void ComDiag_DealFault_ED9683(uint16 fault, FaultDeal_t type)
{
    static uint16 faultCondRecord = 0;

    if (!ComDiag_CheckDealFaultPermission())
    {
        return;
    }

    if (FAULT_SET == type)
    {
        faultCondRecord |= fault;
    }
    else
    {
        faultCondRecord &= (~fault);
    }
    if (DTC_ED9683_FAULT_MASK & faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED9683, DEM_EVENT_STATUS_PREFAILED);
    }
    else if (!faultCondRecord)
    {
        Dem_SetEventStatus(DemConf_DemDTCClass_DemDTC_DTC_ED9683, DEM_EVENT_STATUS_PREPASSED);
    }
}



// use simple
#if 0
// set
ComDiag_DealFault_C12182(DTC_C12182_FAULT_VehSpdLgt_UB, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_LatCtrlReqSafe_UB, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_AbsCtrlActv_UB, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlFrnt_UB, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlRe_UB, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_BrkPedlPsd_UB, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_E0_Missing, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_190_Missing, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B1_Missing, FAULT_SET);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B7_Missing, FAULT_SET);
ComDiag_DealFault_C15182(DTC_C15182_FAULT_AgDataRawSafe_UB, FAULT_SET);
ComDiag_DealFault_C15182(DTC_C15182_FAULT_Msg_1B0_Missing, FAULT_SET);
ComDiag_DealFault_C15982(DTC_C15982_FAULT_PrkgPinionAgReqGroup_UB, FAULT_SET);
ComDiag_DealFault_C15982(DTC_C15982_FAULT_Msg_EB_Missing, FAULT_SET);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_AsyPinionAgReqSafe_UB, FAULT_SET);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqLowrLim_UB, FAULT_SET);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqUpprLim_UB, FAULT_SET);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_Msg_33_Missing, FAULT_SET);
ComDiag_DealFault_C29682(DTC_C29682_FAULT_CrabMovModSts_UB, FAULT_SET);
ComDiag_DealFault_C29682(DTC_C29682_FAULT_Msg_5B_Missing, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_VehSpdLgt_UB, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_LatCtrlReqSafe_UB, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_AbsCtrlActv_UB, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlFrnt_UB, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlRe_UB, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_BrkPedlPsd_UB, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_E0_Missing, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_190_Missing, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B1_Missing, FAULT_SET);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B7_Missing, FAULT_SET);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_DrvModReq_UB, FAULT_SET);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_SteerSetg_UB, FAULT_SET);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_2AE_Missing, FAULT_SET);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_463_Missing, FAULT_SET);
ComDiag_DealFault_E71883(DTC_E71883_FAULT_VehMtnSt_E2E, FAULT_SET);
ComDiag_DealFault_E72783(DTC_E72783_FAULT_AsyPinionAgReqSafeAsyPinionAgReq_E2E, FAULT_SET);
ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_UturnTrqRels_UB, FAULT_SET);
ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_Msg_EB_Missing, FAULT_SET);
ComDiag_DealFault_E7B283(DTC_E7B283_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_SET);
ComDiag_DealFault_E7B283(DTC_E7B283_FAULT_UturnTrqRels_E2E, FAULT_SET);
ComDiag_DealFault_E7B383(DTC_E7B383_FAULT_CrabMovModSts_E2E, FAULT_SET);
ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_BrkPedlPsd_E2E, FAULT_SET);
ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlRe_E2E, FAULT_SET);
ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlFrnt_E2E, FAULT_SET);
ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_LatCtrlReqSafe_E2E, FAULT_SET);
ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_AbsCtrlActv_E2E, FAULT_SET);
ComDiag_DealFault_ED3683(DTC_ED3683_FAULT_VehSpdLgt_E2E, FAULT_SET);
ComDiag_DealFault_ED3983(DTC_ED3983_FAULT_AgDataRawSafe_E2E, FAULT_SET);
ComDiag_DealFault_ED4183(DTC_ED4183_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_SET);
ComDiag_DealFault_ED5A83(DTC_ED5A83_FAULT_VehModMngtGlbSafe1_E2E, FAULT_SET);
ComDiag_DealFault_ED7983(DTC_ED7983_FAULT_PtTqAtWhlFrntAct_E2E, FAULT_SET);
ComDiag_DealFault_ED9683(DTC_ED9683_FAULT_AbsCtrActv_E2E, FAULT_SET);

// clear
ComDiag_DealFault_C12182(DTC_C12182_FAULT_VehSpdLgt_UB, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_LatCtrlReqSafe_UB, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_AbsCtrlActv_UB, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlFrnt_UB, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlRe_UB, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_BrkPedlPsd_UB, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_E0_Missing, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_190_Missing, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B1_Missing, FAULT_CLEAR);
ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B7_Missing, FAULT_CLEAR);
ComDiag_DealFault_C15182(DTC_C15182_FAULT_AgDataRawSafe_UB, FAULT_CLEAR);
ComDiag_DealFault_C15182(DTC_C15182_FAULT_Msg_1B0_Missing, FAULT_CLEAR);
ComDiag_DealFault_C15982(DTC_C15982_FAULT_PrkgPinionAgReqGroup_UB, FAULT_CLEAR);
ComDiag_DealFault_C15982(DTC_C15982_FAULT_Msg_EB_Missing, FAULT_CLEAR);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_AsyPinionAgReqSafe_UB, FAULT_CLEAR);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqLowrLim_UB, FAULT_CLEAR);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqUpprLim_UB, FAULT_CLEAR);
ComDiag_DealFault_C16882(DTC_C16882_FAULT_Msg_33_Missing, FAULT_CLEAR);
ComDiag_DealFault_C29682(DTC_C29682_FAULT_CrabMovModSts_UB, FAULT_CLEAR);
ComDiag_DealFault_C29682(DTC_C29682_FAULT_Msg_5B_Missing, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_VehSpdLgt_UB, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_LatCtrlReqSafe_UB, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_AbsCtrlActv_UB, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlFrnt_UB, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlRe_UB, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_BrkPedlPsd_UB, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_E0_Missing, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_190_Missing, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B1_Missing, FAULT_CLEAR);
ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B7_Missing, FAULT_CLEAR);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_DrvModReq_UB, FAULT_CLEAR);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_SteerSetg_UB, FAULT_CLEAR);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_2AE_Missing, FAULT_CLEAR);
ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_463_Missing, FAULT_CLEAR);
ComDiag_DealFault_E71883(DTC_E71883_FAULT_VehMtnSt_E2E, FAULT_CLEAR);
ComDiag_DealFault_E72783(DTC_E72783_FAULT_AsyPinionAgReqSafeAsyPinionAgReq_E2E, FAULT_CLEAR);
ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_UturnTrqRels_UB, FAULT_CLEAR);
ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_Msg_EB_Missing, FAULT_CLEAR);
ComDiag_DealFault_E7B283(DTC_E7B283_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_CLEAR);
ComDiag_DealFault_E7B283(DTC_E7B283_FAULT_UturnTrqRels_E2E, FAULT_CLEAR);
ComDiag_DealFault_E7B383(DTC_E7B383_FAULT_CrabMovModSts_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_BrkPedlPsd_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlRe_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlFrnt_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_LatCtrlReqSafe_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_AbsCtrlActv_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3683(DTC_ED3683_FAULT_VehSpdLgt_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED3983(DTC_ED3983_FAULT_AgDataRawSafe_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED4183(DTC_ED4183_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED5A83(DTC_ED5A83_FAULT_VehModMngtGlbSafe1_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED7983(DTC_ED7983_FAULT_PtTqAtWhlFrntAct_E2E, FAULT_CLEAR);
ComDiag_DealFault_ED9683(DTC_ED9683_FAULT_AbsCtrActv_E2E, FAULT_CLEAR);

#endif
/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Private source file providing post build configuration parameters for the SecOC module.
 * \addtogroup SecOC
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "SecOC_Types.h"
#include "SecOC_Prv.h"
#include "SecOC_Prv_PbCfg.h"
/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/* ********************************************************************************************************************
 *
 * SecOC_Prv_RxSecuredPduConfig_ast[]->pduConfig_pst->dataId_cst (precompile working pointer in processing c-code)
 *  ^
 *  |
 *  +-- SecOC_Prv_XYZ_Common_pcu16/8 <-- &SecOC_Prv_XYZ__KW_COMMON_acen/u32/u16/u8[0]      (precompile variant table)
 *  +-- SecOC_Prv_XYZ_Var_pcu16/8    <-- &SecOC_Prv_PbCfg_XYZ_en/u32/16/8[*idPbConfig_pcu16] (PBV loaded in SecOC_Init)
 *                                            ^
 *                                            |   (PBS variant tables)
 *                                            +-- &SecOC_Prv_XYZ_VPOSTBS_Variant_Master_4Cyl_acen/u32/u16/u8[0]
 *                                            +-- &SecOC_Prv_XYZ_VPOSTBS_Variant_Slave_4Cyl_acen/u32/u16/u8[0]
 *
 * Pseudo-code for Rx dataId_u16:
 * PduIdType idx_cuo = SecOC_Prv_RxSecuredPduConfig_ast[pdu_idx].pduConfig_pst->dataId_cst.idx_cuo;
 * uint16 dataId_u16 = (*SecOC_Prv_RxSecuredPduConfig_ast[pdu_idx].pduConfig_pst->dataId_cst.value_pacu16)[idx_cuo];
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CONST_16
#include "SecOC_MemMap.h"
const SecOC_ConfigType SecOC_Config = {0};
#define SECOC_STOP_SEC_CONST_16
#include "SecOC_MemMap.h"
/* Variant tables for SecOCDataId*/
#define SECOC_START_SEC_CONST_16
#include "SecOC_MemMap.h"
static const uint16 SecOC_Prv_RxDataId___KW_COMMON_acu16[4] =
{
    80U,     81U,     82U,     513U

};
#define SECOC_STOP_SEC_CONST_16
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
const uint16* SecOC_Prv_RxDataId_Common_pcu16 = &SecOC_Prv_RxDataId___KW_COMMON_acu16[0];
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
/* Variant tables for SecOCFreshnessValueId*/
#define SECOC_START_SEC_CONST_16
#include "SecOC_MemMap.h"
static const uint16 SecOC_Prv_RxFreshValId___KW_COMMON_acu16[4] =
{
    0U,     1U,     2U,     4U

};
#define SECOC_STOP_SEC_CONST_16
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
const uint16* SecOC_Prv_RxFreshValId_Common_pcu16 = &SecOC_Prv_RxFreshValId___KW_COMMON_acu16[0];
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
/* Variant tables for SecOCFreshnessValueLength*/
#define SECOC_START_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"
static uint8 SecOC_Prv_RxFreshValLen___KW_COMMON_acu8[4] =
{
    56U,     56U,     56U,     0U

};
#define SECOC_STOP_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
uint8* SecOC_Prv_RxFreshValLen_Common_pu8 = &SecOC_Prv_RxFreshValLen___KW_COMMON_acu8[0];
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
/* Variant tables for SecOCFreshnessValueTruncLength*/
#define SECOC_START_SEC_CONST_8
#include "SecOC_MemMap.h"
static const uint8 SecOC_Prv_RxFreshValTruncLen___KW_COMMON_acu8[4] =
{
    16U,     16U,     16U,     0U

};
#define SECOC_STOP_SEC_CONST_8
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
const uint8* SecOC_Prv_RxFreshValTruncLen_Common_pcu8 = &SecOC_Prv_RxFreshValTruncLen___KW_COMMON_acu8[0];
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
/* Variant tables for SecOCAuthInfoTruncLength*/
#define SECOC_START_SEC_CONST_16
#include "SecOC_MemMap.h"
static const uint16 SecOC_Prv_RxAuthTruncLen___KW_COMMON_acu16[4] =
{
    88U,     88U,     88U,     88U

};
#define SECOC_STOP_SEC_CONST_16
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
const uint16* SecOC_Prv_RxAuthTruncLen_Common_pcu16 = &SecOC_Prv_RxAuthTruncLen___KW_COMMON_acu16[0];
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
/* Variant tables for SecOCVerificationStatusPropagationMode*/
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
static const SecOC_Prv_VerifyPropType_en SecOC_Prv_RxPropMode___KW_COMMON_acen[4] =
{
    SECOC_BOTH_E,     SECOC_BOTH_E,     SECOC_BOTH_E,     SECOC_BOTH_E

};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
const SecOC_Prv_VerifyPropType_en* SecOC_Prv_RxPropMode_Common_pcen = &SecOC_Prv_RxPropMode___KW_COMMON_acen[0];
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
/* Variant tables for SecOCPduVerification*/
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
static const SecOC_Prv_CryptIf_en SecOC_Prv_RxVerifyCryIf___KW_COMMON_acen[4] =
{
    SECOC_CRYPTIF_CSM_CRYPTO,     SECOC_CRYPTIF_CSM_CRYPTO,     SECOC_CRYPTIF_CSM_CRYPTO,     SECOC_CRYPTIF_CSM_CRYPTO

};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
const SecOC_Prv_CryptIf_en* SecOC_Prv_RxVerifyCryIf_Common_pcen = &SecOC_Prv_RxVerifyCryIf___KW_COMMON_acen[0];
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
/* Lookup table for API SecOC_VerifyStatusOverride */
#define SECOC_START_SEC_CONST_16
#include "SecOC_MemMap.h"
static const uint16 SecOC_Prv_Rx_Lookup_ValueId_au16[SECOC_MAX_VERIFY_STATUS_OVERRIDE] =
{
    /* Rx_Lookup_ValueId with FreshnessIDs */
    0U,    1U,    2U,    4U};
#define SECOC_STOP_SEC_CONST_16
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_CONST_32
#include "SecOC_MemMap.h"
const uint16 * const SecOC_Prv_Rx_Lookup_ValueId_acpcu16[] =
{

    &SecOC_Prv_Rx_Lookup_ValueId_au16[0]
};
#define SECOC_STOP_SEC_CONST_32
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_CLEARED_32
#include "SecOC_MemMap.h"
const uint16* SecOC_Prv_Rx_Lookup_ValueId_pcu16;
#define SECOC_STOP_SEC_VAR_CLEARED_32
#include "SecOC_MemMap.h"

/* ********************************************************************************************************************
End PBS content
********************************************************************************************************************* */


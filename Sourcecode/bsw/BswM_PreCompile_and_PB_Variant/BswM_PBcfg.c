/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "BswM.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

#define BSWM_CFG_VERSION_INFO  {    /*Version details*/  \
                    6U, /*Vendor Id*/  \
                    42U, /*Module Id*/  \
                    2U, /*SW Major version*/  \
                    0U, /*SW Minor version*/  \
                    0U /*SW Patch version*/  \
               }

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define BSWM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED 
#include "BswM_MemMap.h"

/*MR12 RULE 5.5 VIOLATION:identifier name depends on the configured pre-defined variants hence the first 31 significant
 * characters of one macro may match macro name generated for another config set*/
static const BswM_Cfg_ActionListType_tst BswM_Cfg_AL_cast[30];

/* Definition for Rule Structures */

static const BswM_Cfg_RuleType_tst BswM_Cfg_Rule_cast[28] = { { /*   Rule Structure for the configuration container BswM_AR_CH0_ComControlDisabled    */
BSWM_TRUE, &BswM_Cfg_LE_BswM_LE_CH0_ComControlDisabled, &BswM_Cfg_AL_cast[8], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_CH0_ComControlEnabled    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_CH0_ComControlEnabled, &BswM_Cfg_AL_cast[9], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_DISABLE_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_DISABLE_NM, &BswM_Cfg_AL_cast[15], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_DISABLE_RX_ENABLE_TX_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NM,
		&BswM_Cfg_AL_cast[10], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_DISABLE_RX_ENABLE_TX_NORM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM,
		&BswM_Cfg_AL_cast[11], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_DISABLE_RX_ENABLE_TX_NORM_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM,
		&BswM_Cfg_AL_cast[12], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_DISABLE_RX_TX_NORM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM, &BswM_Cfg_AL_cast[13], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_DISABLE_RX_TX_NORM_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM_NM,
		&BswM_Cfg_AL_cast[14], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_ENABLE_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_ENABLE_NM, &BswM_Cfg_AL_cast[21], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_ENABLE_RX_DISABLE_TX_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NM,
		&BswM_Cfg_AL_cast[16], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_ENABLE_RX_DISABLE_TX_NORM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM,
		&BswM_Cfg_AL_cast[17], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_ENABLE_RX_DISABLE_TX_NORM_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM,
		&BswM_Cfg_AL_cast[18], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_ENABLE_RX_TX_NORM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM, &BswM_Cfg_AL_cast[19], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_DCM_ENABLE_RX_TX_NORM_NM    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM_NM,
		&BswM_Cfg_AL_cast[20], /* trueActionList */
		NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_Godown    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_Shutdown, &BswM_Cfg_AL_cast[3], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_NetworkRelease    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_NetworkRelease, &BswM_Cfg_AL_cast[22], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_NetworkRequest    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_NetworkRequest, &BswM_Cfg_AL_cast[23], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_PNC29_NoCom    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_PNC29_NoCom, &BswM_Cfg_AL_cast[24], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_PNC29_PrepareSleep    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_PNC29_PrepareSleep, &BswM_Cfg_AL_cast[25], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_PNC29_ReadySleep    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_PNC29_ReadySleep, &BswM_Cfg_AL_cast[26], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_PNC29_Requested    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_PNC29_Requested, &BswM_Cfg_AL_cast[27], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_PostRun2Run    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_PostRun2Run, &BswM_Cfg_AL_cast[28], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_Run    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_Run, &BswM_Cfg_AL_cast[1], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_Run2PostRun    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_Run2PostRun, &BswM_Cfg_AL_cast[29], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_Shutdown    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_PrepShutdown, &BswM_Cfg_AL_cast[6], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_StartupOne    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_StartupOne, &BswM_Cfg_AL_cast[7], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container BswM_AR_StartupTwo    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_StartupTwo, &BswM_Cfg_AL_cast[5], /* trueActionList */
NULL_PTR }, { /*   Rule Structure for the configuration container Bsw_AR_AppRun    */
BSWM_FALSE, &BswM_Cfg_LE_BswM_LE_AppRun, &BswM_Cfg_AL_cast[0], /* trueActionList */
NULL_PTR } };

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_ControllerStateIndication. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_ControllerStateIndication_cau16[] =
		{ 0, 1, 21, 23, 24, 27 };

/* ModeRequestPort structure for MRP BswM_MRP_ControllerStateIndication. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - NetworkID (idNetwork_u8)
 * - ModeInit Value (dataModeInitValue_en)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_CONTROLLERSTATEINDICATION { \
        FALSE,      \
        ComMConf_ComMChannel_Can_Network_0_Channel_Can_Network_0,       \
        CANSM_BSWM_NO_COMMUNICATION,        \
        BSWM_DEFERRED,      \
        6,       \
        &BswM_Cfg_ListOfRules_BswM_MRP_ControllerStateIndication_cau16[0]        \
}

/* Array of CanSM Indication MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_CANSMINDICATION_MRPS {   \
       BSWM_CFG_BSWM_MRP_CONTROLLERSTATEINDICATION,      \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_ComM_PNC29. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_ComM_PNC29_cau16[] = { 17, 18,
		19, 20 };

/* ModeRequestPort structure for MRP BswM_MRP_ComM_PNC29. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - PNCHandleType (idPnc_u8)
 * - ModeInit Value (dataModeInitValue_en)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_COMM_PNC29 { \
        FALSE,      \
        ComMConf_ComMPnc_ComMPnc,       \
        COMM_PNC_REQUESTED,        \
        BSWM_DEFERRED,      \
        4,       \
        &BswM_Cfg_ListOfRules_BswM_MRP_ComM_PNC29_cau16[0]        \
}

/* Array of ComM Pnc Request MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_COMMPNCREQ_MRPS {   \
       BSWM_CFG_BSWM_MRP_COMM_PNC29,      \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_DCM_ComModeRequest_ECAN. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_DCM_ComModeRequest_ECAN_cau16[] =
		{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

/* ModeRequestPort structure for MRP BswM_MRP_DCM_ComModeRequest_ECAN. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - NetworkHandleType (idNetwork_u8)
 * - ModeInit Value (dataModeInitValue_en)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_DCM_COMMODEREQUEST_ECAN { \
        FALSE,      \
        ComMConf_ComMChannel_Can_Network_0_Channel_Can_Network_0,       \
        DCM_ENABLE_RX_TX_NORM,        \
        BSWM_IMMEDIATE,      \
        12,       \
        &BswM_Cfg_ListOfRules_BswM_MRP_DCM_ComModeRequest_ECAN_cau16[0]        \
}

/* Array of Dcm Com Mode Request MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_DCMCOMMODEREQ_MRPS {   \
       BSWM_CFG_BSWM_MRP_DCM_COMMODEREQUEST_ECAN,      \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_WKSOURCE_CANMSG. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_WKSOURCE_CANMSG_cau16[] = {
		23, 24 };

/* ModeRequestPort structure for MRP BswM_MRP_WKSOURCE_CANMSG. Variant : __KW_COMMON
 * - Pointer to array containing indexes of associated rules 
 * - Number of rules referring to this MRP
 * - EcuM Wakeup Source reference 
 * - Configured/Default Mode Init Value 
 * - RequestProcessing Enum - Immediate/Deferred 
 * - Mode Init Value present flag
 */
#define BSWM_CFG_BSWM_MRP_WKSOURCE_CANMSG { \
    &BswM_Cfg_ListOfRules_BswM_MRP_WKSOURCE_CANMSG_cau16[0],  \
    2,          \
    EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_CANMSG,    \
    0,         \
    BSWM_IMMEDIATE,       \
    FALSE        \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_WKSOURCE_KL15. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_WKSOURCE_KL15_cau16[] = { 23,
		24 };

/* ModeRequestPort structure for MRP BswM_MRP_WKSOURCE_KL15. Variant : __KW_COMMON
 * - Pointer to array containing indexes of associated rules 
 * - Number of rules referring to this MRP
 * - EcuM Wakeup Source reference 
 * - Configured/Default Mode Init Value 
 * - RequestProcessing Enum - Immediate/Deferred 
 * - Mode Init Value present flag
 */
#define BSWM_CFG_BSWM_MRP_WKSOURCE_KL15 { \
    &BswM_Cfg_ListOfRules_BswM_MRP_WKSOURCE_KL15_cau16[0],  \
    2,          \
    EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_KL15,    \
    0,         \
    BSWM_IMMEDIATE,       \
    FALSE        \
}

/* Array of EcuM WakeupSource MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_ECUMWKPSRC_MRPS {   \
    BSWM_CFG_BSWM_MRP_WKSOURCE_CANMSG,      \
    BSWM_CFG_BSWM_MRP_WKSOURCE_KL15,      \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_BswM_MDG. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_BswM_MDG_cau16[] = { 14, 21,
		22, 23, 24, 25, 26, 27 };

/* ModeRequestPort structure for MRP BswM_MRP_BswM_MDG. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_BSWM_MDG { \
        FALSE,        \
        0,    \
        65535,                \
        0,         \
        BSWM_IMMEDIATE,    \
        8, \
        &BswM_Cfg_ListOfRules_BswM_MRP_BswM_MDG_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswMSwcModeRequest. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswMSwcModeRequest_cau16[] = { 24 };

/* ModeRequestPort structure for MRP BswMSwcModeRequest. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWMSWCMODEREQUEST { \
        FALSE,        \
        1,    \
        65535,                \
        0,         \
        BSWM_DEFERRED,    \
        1, \
        &BswM_Cfg_ListOfRules_BswMSwcModeRequest_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_SWC_Network. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_SWC_Network_cau16[] =
		{ 15, 16 };

/* ModeRequestPort structure for MRP BswM_MRP_SWC_Network. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_SWC_NETWORK { \
        FALSE,        \
        2,    \
        65535,                \
        0,         \
        BSWM_DEFERRED,    \
        2, \
        &BswM_Cfg_ListOfRules_BswM_MRP_SWC_Network_cau16[0]  \
}

/* Array of GenericRequest MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_GENERICREQ_MRPS {   \
    BSWM_CFG_BSWM_MRP_BSWM_MDG,      \
    BSWM_CFG_BSWMSWCMODEREQUEST,      \
    BSWM_CFG_BSWM_MRP_SWC_NETWORK,      \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_NvMReadAllComplete. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_NvMReadAllComplete_cau16[] = {
		26 };

/* ModeRequestPort structure for MRP BswM_MRP_NvMReadAllComplete. Variant : __KW_COMMON
 * - Mode Init Value present flag 
 * - Configured NvM Service
 * - Configured/Default Mode Init Value
 * - RequestProcessing Enum - Immediate/Deferred 
 * - Number of rules referring to this MRP 
 * - Pointer to array containing indexes of associated rules
 */
#define BSWM_CFG_BSWM_MRP_NVMREADALLCOMPLETE { \
    TRUE,        \
    BSWM_NVMREADALL,       \
    NVM_REQ_PENDING,         \
    BSWM_IMMEDIATE,       \
    1,          \
    &BswM_Cfg_ListOfRules_BswM_MRP_NvMReadAllComplete_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_NvMWriteAllComplete. Variant :  __KW_COMMON*/
static const uint16 BswM_Cfg_ListOfRules_BswM_MRP_NvMWriteAllComplete_cau16[] =
		{ 14 };

/* ModeRequestPort structure for MRP BswM_MRP_NvMWriteAllComplete. Variant : __KW_COMMON
 * - Mode Init Value present flag 
 * - Configured NvM Service
 * - Configured/Default Mode Init Value
 * - RequestProcessing Enum - Immediate/Deferred 
 * - Number of rules referring to this MRP 
 * - Pointer to array containing indexes of associated rules
 */
#define BSWM_CFG_BSWM_MRP_NVMWRITEALLCOMPLETE { \
    TRUE,        \
    BSWM_NVMWRITEALL,       \
    NVM_REQ_PENDING,         \
    BSWM_IMMEDIATE,       \
    1,          \
    &BswM_Cfg_ListOfRules_BswM_MRP_NvMWriteAllComplete_cau16[0]  \
}

/* Array of NvM BlockRequest MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_NVMJOBMODEIND_MRPS {   \
    BSWM_CFG_BSWM_MRP_NVMREADALLCOMPLETE,      \
    BSWM_CFG_BSWM_MRP_NVMWRITEALLCOMPLETE,      \
}

/* ModeRequestPort structure for MRP BswM_MRP_Timer. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b)
 * - ModeInit Value (dataModeInitValue_u8)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_TIMER { \
        FALSE,      \
        BSWM_TIMER_STOPPED,        \
        BSWM_DEFERRED,      \
        0,       \
        NULL_PTR      \
}

/* Array of BswM_BswMTimer MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_BSWMTIMER_MRPS {   \
       BSWM_CFG_BSWM_MRP_TIMER,      \
}

/* BswM_Cfg_MRPType_tst : Array of structures for different MRP types. Variant : __KW_COMMON
 */
#define BSWM_CFG_MODEREQPORT {       \
    BSWM_CFG_CANSMINDICATION_MRPS,      \
    BSWM_CFG_COMMPNCREQ_MRPS,      \
    BSWM_CFG_DCMCOMMODEREQ_MRPS,      \
    BSWM_CFG_ECUMWKPSRC_MRPS,      \
    BSWM_CFG_GENERICREQ_MRPS,      \
    BSWM_CFG_NVMJOBMODEIND_MRPS,      \
    BSWM_CFG_BSWMTIMER_MRPS,      \
            }

/* ModeArbitration Type structure  
 * - ModeRequestPortType structure (BswM_Cfg_MRPType_tst)
 * - Number of rules configured for the chosen variant 
 * - Pointer to base address of array of rules (BswM_Cfg_RuleType_tst)
 */
#define BSWM_CFG_MODEARBITRATION {      \
        BSWM_CFG_MODEREQPORT,     \
        28, \
        &BswM_Cfg_Rule_cast[0] \
}

/*
 **********************************************************************************************************************
 * Arrays of BswMPduGroupSwitch Group References for the variant  with contents: 
 *   # BswMPduEnableGroupSwitch Reference/References
 *   # BswMPduDisableGroupSwitch Reference/References
 **********************************************************************************************************************
 */

static const Com_IpduGroupIdType BswM_Cfg_AC_BswMAction_EnableRxPduGroup_BswMPduEnableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Rx };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswMAction_EnableTxPduGroup_BswMPduEnableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Tx };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_AI_EnableRxPduGroup_PNC29_BswMPduEnableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Rx_PNC29 };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_AI_EnableTxPduGroup_PNC29_BswMPduEnableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Tx_PNC29 };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_AI_StartPduGroup_All_BswMPduEnableGrpRef_cau16[2] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Rx,
				ComConf_ComIPduGroup_ComIPduGroup_Tx };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_Al_StartNMUserDataPduGroup_BswMPduEnableGrpRef_cau16[2] =
		{ ComConf_ComIPduGroup_ComIPduGroup_NM_User_Data_Tx,
				ComConf_ComIPduGroup_ComIPduGroup_NM_User_Data_Rx };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswMAction_DisableRxPduGroup_BswMPduDisableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Rx };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswMAction_DisableTxPduGroup_BswMPduDisableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Tx };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_AI_DisableRxPduGroup_PNC29_BswMPduDisableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Rx_PNC29 };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_AI_DisableTxPduGroup_PNC29_BswMPduDisableGrpRef_cau16[1] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Tx_PNC29 };

static const Com_IpduGroupIdType BswM_Cfg_AC_BswM_AI_StopPduGroup_All_BswMPduDisableGrpRef_cau16[2] =
		{ ComConf_ComIPduGroup_ComIPduGroup_Rx,
				ComConf_ComIPduGroup_ComIPduGroup_Tx };

/*
 **********************************************************************************************************************
 * Array of BswMPduRouterControl Action for the variant  with contents: 
 *   # Reinit 
 *   # No of EnabledPduGroupRef
 *   # No of DisabledPduGroupRef
 *   # Base Addr of EnabledPduGroupRef
 *   # Base Addr of DisabledPduGroupRef
 **********************************************************************************************************************
 */
/*MR12 RULE 5.5 VIOLATION:identifier name depends on the configured pre-defined variants hence the first 31 significant
 * characters of one macro may match macro name generated for another config set*/
static const BswM_Cfg_AC_PduGroupSwitchType_tst BswM_Cfg_AC_BswMPduGroupSwitch_cast[BSWM_NO_OF_AC_IPDUGROUPSWITCH] =
		{ {
		/* BswMAction_DisableRxPduGroup */
		FALSE, 0, 1,

		NULL_PTR,

		&BswM_Cfg_AC_BswMAction_DisableRxPduGroup_BswMPduDisableGrpRef_cau16[0]

		}, {
		/* BswMAction_DisableTxPduGroup */
		FALSE, 0, 1,

		NULL_PTR,

		&BswM_Cfg_AC_BswMAction_DisableTxPduGroup_BswMPduDisableGrpRef_cau16[0]

		}, {
		/* BswMAction_EnableRxPduGroup */
		FALSE, 1, 0,

		&BswM_Cfg_AC_BswMAction_EnableRxPduGroup_BswMPduEnableGrpRef_cau16[0],

		NULL_PTR

		}, {
		/* BswMAction_EnableTxPduGroup */
		FALSE, 1, 0,

		&BswM_Cfg_AC_BswMAction_EnableTxPduGroup_BswMPduEnableGrpRef_cau16[0],

		NULL_PTR

		},
				{
				/* BswM_AI_DisableRxPduGroup_PNC29 */
				FALSE, 0, 1,

				NULL_PTR,

						&BswM_Cfg_AC_BswM_AI_DisableRxPduGroup_PNC29_BswMPduDisableGrpRef_cau16[0]

				},
				{
				/* BswM_AI_DisableTxPduGroup_PNC29 */
				FALSE, 0, 1,

				NULL_PTR,

						&BswM_Cfg_AC_BswM_AI_DisableTxPduGroup_PNC29_BswMPduDisableGrpRef_cau16[0]

				},
				{
				/* BswM_AI_EnableRxPduGroup_PNC29 */
				FALSE, 1, 0,

						&BswM_Cfg_AC_BswM_AI_EnableRxPduGroup_PNC29_BswMPduEnableGrpRef_cau16[0],

						NULL_PTR

				},
				{
				/* BswM_AI_EnableTxPduGroup_PNC29 */
				FALSE, 1, 0,

						&BswM_Cfg_AC_BswM_AI_EnableTxPduGroup_PNC29_BswMPduEnableGrpRef_cau16[0],

						NULL_PTR

				},
				{
				/* BswM_AI_StartPduGroup_All */
				FALSE, 2, 0,

						&BswM_Cfg_AC_BswM_AI_StartPduGroup_All_BswMPduEnableGrpRef_cau16[0],

						NULL_PTR

				},
				{
				/* BswM_AI_StopPduGroup_All */
				FALSE, 0, 2,

				NULL_PTR,

						&BswM_Cfg_AC_BswM_AI_StopPduGroup_All_BswMPduDisableGrpRef_cau16[0]

				},
				{
				/* BswM_Al_StartNMUserDataPduGroup */
				FALSE, 2, 0,

						&BswM_Cfg_AC_BswM_Al_StartNMUserDataPduGroup_BswMPduEnableGrpRef_cau16[0],

						NULL_PTR

				} };

/*****************************************************************************************
 * Array of ActionListItems for __KW_COMMON with contents:
 * {
 *     AbortOnFailFlag,
 *     ActionListItemType,
 *     PointerToActionListItem
 * }
 *****************************************************************************************/

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMInAppRun_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswM_ALI_StartPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[8] /* BswM_AI_StartPduGroup_All */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchAppRun_Items_cast[6] =
		{ {
		/* ActionListItemName  :   BswM_ALI_AllowComm_Can0 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[0] /* BswM_AI_ComMCommAllowed_Can0 */
		}, {
		/* ActionListItemName  :   BswM_ALI_AllowComm_Can1 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[1] /* BswM_AI_ComMCommAllowed_Can1 */
		}, {
		/* ActionListItemName  :   BswM_ALI_AllowComm_Can2 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[2] /* BswM_AI_ComMCommAllowed_Can2 */
		}, {
		/* ActionListItemName  :   BswM_ALI_StartOperationCycle */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[26] /* BswM_AI_StartOperationCycle */
		}, {
		/* ActionListItemName  :   BswM_AI_StartNmPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[10] /* BswM_Al_StartNMUserDataPduGroup */
		}, {
		/* ActionListItemName  :   BswM_AI_SetNetStateNormal */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[24] /* BswM_AI_SetNetStateNormal */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchAppRun_WAKEUP_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswM_ALI_ComMReqFullComm_User0 */
		FALSE, BSWM_ACTION_COMM_MODE_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMModeSwitch_cast[0] /* BswM_AI_ComMReqFullComm_User0 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMReqFullComm_User1 */
		FALSE, BSWM_ACTION_COMM_MODE_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMModeSwitch_cast[1] /* BswM_AI_ComMReqFullComm_User1 */
		}, {
		/* ActionListItemName  :   BswM_ALI_BswMAppRun */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[1] /* BswM_AI_BswMSwitchAppRun */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchGoDown_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswM_ALI_GoDown */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[16] /* BswM_AI_GoDown */
		}, {
		/* ActionListItemName  :   BswMActionListItem_EcuM_InfinitLoopMainFunc */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[4] /* BswMAction_EcuM_LoopMainFunc */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchPrepShutdown_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswM_ALI_BswMPrepShutdown */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[3] /* BswM_AI_BswMSwitchPrepShutdown */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchRun_Items_cast[16] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_ALI_NVM_CRY_INIT */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[0] /* BswMAction_AI_NVM_CRY_INIT */
		}, {
		/* ActionListItemName  :   BswM_ALI_CDD_FVM_Init */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[1] /* BswMAction_CDD_FVM_Init */
		}, {
		/* ActionListItemName  :   BswM_ALI_CanIfInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[8] /* BswM_AI_CanIfInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_CanSmInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[10] /* BswM_AI_CanSmInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_PduRInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[21] /* BswM_AI_PduRInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[12] /* BswM_AI_ComInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[13] /* BswM_AI_ComMInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_BswMRun */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[4] /* BswM_AI_BswMSwitchRun */
		}, {
		/* ActionListItemName  :   BswMALI_DemInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[2] /* BswMAction_DemInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_DcmInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[14] /* BswM_AI_Dcm_Init */
		}, {
		/* ActionListItemName  :   BswM_ALI_CanTp_Init */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[11] /* BswM_AI_CanTp_Init */
		}, {
		/* ActionListItemName  :   BswM_ALI_WdgMInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[27] /* BswM_AI_WdgMInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_XcpInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[28] /* BswM_AI_XcpInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_RteTimerStart */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[23] /* BswM_AI_RteTimerStart */
		}, {
		/* ActionListItemName  :   BswM_ALI_Nm_Init */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[17] /* BswM_AI_Nm_Init */
		}, {
		/* ActionListItemName  :   BswM_ALI_CanNm_Init */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[9] /* BswM_AI_CanNm_Init */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchShutdown_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswM_ALI_RteStop */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[22] /* BswM_AI_RteStop */
		}, {
		/* ActionListItemName  :   BswM_ALI_WriteAll */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[20] /* BswM_AI_NvMWriteAll */
		}, {
		/* ActionListItemName  :   BswM_ALI_BswMShutdown */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[5] /* BswM_AI_BswMSwitchShutdown */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_BswMSwitchStartupTwo_Items_cast[5] =
		{ {
		/* ActionListItemName  :   BswM_ALI_BswMStartupTwo */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[6] /* BswM_AI_BswMSwitchStartupTwo */
		}, {
		/* ActionListItemName  :   BswM_ALI_FeeInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[15] /* BswM_AI_FeeInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_FeeRbEndInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[7] /* BswMAction_FeeRbEndInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_NvMInit */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[18] /* BswM_AI_NvMInit */
		}, {
		/* ActionListItemName  :   BswM_ALI_NvMReadAll */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[19] /* BswM_AI_NvMReadAll */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_CH0_ComControlOff_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_0 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[9] /* BswM_AI_StopPduGroup_All */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_CH0_ComControlOn_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_0 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[8] /* BswM_AI_StartPduGroup_All */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NM_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_EN_Tx_NM */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[0] /* BswMAction_NM_Start */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NORM_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_DisableRxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[0] /* BswMAction_DisableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_EnableTxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[3] /* BswMAction_EnableTxPduGroup */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NORM_NM_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_DIS_RX */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[0] /* BswMAction_DisableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_EN_TX_NORM */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[3] /* BswMAction_EnableTxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_EN_TX_NM */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[0] /* BswMAction_NM_Start */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_TX_NORM_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_DisableRxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[0] /* BswMAction_DisableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_DisableTxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[1] /* BswMAction_DisableTxPduGroup */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_TX_NORM_NM_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_Dis_RxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[0] /* BswMAction_DisableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_Dis_TxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[1] /* BswMAction_DisableTxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_BswMActionListItem_Dis_Rx_Tx_NM */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[1] /* BswMAction_NM_Stop */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_DISABLE_TX_RX_NM_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_Nm_Stop */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[1] /* BswMAction_NM_Stop */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NM_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_DIS_Tx_NM */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[1] /* BswMAction_NM_Stop */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NORM_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_EnableRxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[2] /* BswMAction_EnableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_DisableTxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[1] /* BswMAction_DisableTxPduGroup */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NORM_NM_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswMActionListItem__DISABLE_TX_NORM */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[1] /* BswMAction_DisableTxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_DISABLE_TX_NM */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[1] /* BswMAction_NM_Stop */
		}, {
		/* ActionListItemName  :   BswMActionListItem_EN_RX */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[2] /* BswMAction_EnableRxPduGroup */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_TX_NORM_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_EnableRxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[2] /* BswMAction_EnableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_EnableTxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[3] /* BswMAction_EnableTxPduGroup */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_TX_NORM_NM_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_En_RxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[2] /* BswMAction_EnableRxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_En_TxPduGroup */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[3] /* BswMAction_EnableTxPduGroup */
		}, {
		/* ActionListItemName  :   BswMActionListItem_En_Tx_Rx_NM */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[0] /* BswMAction_NM_Start */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_DCM_ENABLE_TX_RX_NM_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_Nm_Start */
		FALSE, BSWM_ACTION_NM_CNTRL,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMNMControl_cast[0] /* BswMAction_NM_Start */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_NetworkRelease_Items_cast[4] =
		{ {
		/* ActionListItemName  :   BswM_ALI_ComMCommNotAllowed_Can0 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[3] /* BswM_AI_ComMCommNotAllowed_Can0 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMReqNoComm_User0 */
		FALSE, BSWM_ACTION_COMM_MODE_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMModeSwitch_cast[3] /* BswM_AI_ComMReqNoComm_User0 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMCommNotAllowed_Can1 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[4] /* BswM_AI_ComMCommNotAllowed_Can1 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMReqNoComm_User1 */
		FALSE, BSWM_ACTION_COMM_MODE_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMModeSwitch_cast[4] /* BswM_AI_ComMReqNoComm_User1 */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_NetworkRequest_Items_cast[5] =
		{ {
		/* ActionListItemName  :   BswM_ALI_StartPduGroup_All */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[8] /* BswM_AI_StartPduGroup_All */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMReqFullComm_User0 */
		FALSE, BSWM_ACTION_COMM_MODE_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMModeSwitch_cast[0] /* BswM_AI_ComMReqFullComm_User0 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMCommAllowed_Can0 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[0] /* BswM_AI_ComMCommAllowed_Can0 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMCommAllowed_Can1 */
		FALSE, BSWM_ACTION_COMM_ALLOW_COM,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMAllowCom_cast[1] /* BswM_AI_ComMCommAllowed_Can1 */
		}, {
		/* ActionListItemName  :   BswM_ALI_ComMReqFullComm_User1 */
		FALSE, BSWM_ACTION_COMM_MODE_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMComMModeSwitch_cast[1] /* BswM_AI_ComMReqFullComm_User1 */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_PNC29_NoCom_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[6] /* BswM_AI_EnableRxPduGroup_PNC29 */
		}, {
		/* ActionListItemName  :   BswMActionListItem_0 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[4] /* BswM_AI_DisableRxPduGroup_PNC29 */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_PNC29_PrepareSleep_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_0 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[5] /* BswM_AI_DisableTxPduGroup_PNC29 */
		}, {
		/* ActionListItemName  :   BswMActionListItem_1 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[6] /* BswM_AI_EnableRxPduGroup_PNC29 */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_PNC29_ReadySleep_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_0 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[6] /* BswM_AI_EnableRxPduGroup_PNC29 */
		}, {
		/* ActionListItemName  :   BswMActionListItem_1 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[7] /* BswM_AI_EnableTxPduGroup_PNC29 */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_PNC29_Requested_Items_cast[2] =
		{ {
		/* ActionListItemName  :   BswMActionListItem_0 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[6] /* BswM_AI_EnableRxPduGroup_PNC29 */
		}, {
		/* ActionListItemName  :   BswMActionListItem_1 */
		FALSE, BSWM_ACTION_PDU_GRP_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMPduGroupSwitch_cast[7] /* BswM_AI_EnableTxPduGroup_PNC29 */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_PostRun2Run_Items_cast[1] =
		{ {
		/* ActionListItemName  :   BswMActionListItem */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[4] /* BswM_AI_BswMSwitchRun */
		} };

static const BswM_Cfg_ActionListItemType_tst BswM_Cfg_AL_BswM_AL_Run2PostRun_Items_cast[3] =
		{ {
		/* ActionListItemName  :   BswM_AI_TrcvSleep */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[29] /* BswM_Al_TrcvSleep */
		}, {
		/* ActionListItemName  :   BswM_AI_BswMSwitchPreShutdown */
		FALSE, BSWM_ACTION_SCHM_SWITCH,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMSchMSwitch_cast[3] /* BswM_AI_BswMSwitchPrepShutdown */
		}, {
		/* ActionListItemName  :   BswM_AI_SetNetStateSleep */
		FALSE, BSWM_ACTION_USR_CALLOUT,
		/*MR12 DIR 1.1 VIOLATION: BswM_Prv_Evaluate_Action expects a void pointer to actionlistitem which is then typecast back to the corresponding action type*/
		(const void*) &BswM_Cfg_AC_BswMUserCallout_cast[25] /* BswM_AI_SetNetStateSleep */
		} };

/*****************************************************************************************
 * Array of ActionLists for __KW_COMMON with contents:
 * {
 *     ExecutionType,
 *     NumberOfActionListItems,
 *     BaseAddressOfActionListItemArray,
 *     Unique Number for ActionList
 * }
 ****************************************************************************************/

static const BswM_Cfg_ActionListType_tst BswM_Cfg_AL_cast[30] = { {
/* ActionListName   :   BswM_AL_BswMInAppRun */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_BswMInAppRun_Items_cast[0], 0 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchAppRun */
BSWM_TRIGGER, 6, &BswM_Cfg_AL_BswM_AL_BswMSwitchAppRun_Items_cast[0], 1 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchAppRun_WAKEUP */
BSWM_TRIGGER, 3, &BswM_Cfg_AL_BswM_AL_BswMSwitchAppRun_WAKEUP_Items_cast[0], 2 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchGoDown */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_BswMSwitchGoDown_Items_cast[0], 3 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchPrepShutdown */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_BswMSwitchPrepShutdown_Items_cast[0], 4 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchRun */
BSWM_TRIGGER, 16, &BswM_Cfg_AL_BswM_AL_BswMSwitchRun_Items_cast[0], 5 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchShutdown */
BSWM_TRIGGER, 3, &BswM_Cfg_AL_BswM_AL_BswMSwitchShutdown_Items_cast[0], 6 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_BswMSwitchStartupTwo */
BSWM_CONDITION, 5, &BswM_Cfg_AL_BswM_AL_BswMSwitchStartupTwo_Items_cast[0], 7 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_CH0_ComControlOff */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_CH0_ComControlOff_Items_cast[0], 8 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_CH0_ComControlOn */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_CH0_ComControlOn_Items_cast[0], 9 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NM */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NM_Items_cast[0],
		10 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NORM */
BSWM_TRIGGER, 2,
		&BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NORM_Items_cast[0], 11 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NORM_NM */
BSWM_TRIGGER, 3,
		&BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_ENABLE_TX_NORM_NM_Items_cast[0], 12 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_DISABLE_RX_TX_NORM */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_TX_NORM_Items_cast[0], 13 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_DISABLE_RX_TX_NORM_NM */
BSWM_TRIGGER, 3, &BswM_Cfg_AL_BswM_AL_DCM_DISABLE_RX_TX_NORM_NM_Items_cast[0],
		14 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_DISABLE_TX_RX_NM */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_DCM_DISABLE_TX_RX_NM_Items_cast[0], 15 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NM */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NM_Items_cast[0],
		16 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NORM */
BSWM_TRIGGER, 2,
		&BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NORM_Items_cast[0], 17 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NORM_NM */
BSWM_TRIGGER, 3,
		&BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_DISABLE_TX_NORM_NM_Items_cast[0], 18 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_ENABLE_RX_TX_NORM */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_TX_NORM_Items_cast[0], 19 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_ENABLE_RX_TX_NORM_NM */
BSWM_TRIGGER, 3, &BswM_Cfg_AL_BswM_AL_DCM_ENABLE_RX_TX_NORM_NM_Items_cast[0], 20 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_DCM_ENABLE_TX_RX_NM */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_DCM_ENABLE_TX_RX_NM_Items_cast[0], 21 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_NetworkRelease */
BSWM_TRIGGER, 4, &BswM_Cfg_AL_BswM_AL_NetworkRelease_Items_cast[0], 22 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_NetworkRequest */
BSWM_TRIGGER, 5, &BswM_Cfg_AL_BswM_AL_NetworkRequest_Items_cast[0], 23 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_PNC29_NoCom */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_PNC29_NoCom_Items_cast[0], 24 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_PNC29_PrepareSleep */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_PNC29_PrepareSleep_Items_cast[0], 25 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_PNC29_ReadySleep */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_PNC29_ReadySleep_Items_cast[0], 26 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_PNC29_Requested */
BSWM_TRIGGER, 2, &BswM_Cfg_AL_BswM_AL_PNC29_Requested_Items_cast[0], 27 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_PostRun2Run */
BSWM_TRIGGER, 1, &BswM_Cfg_AL_BswM_AL_PostRun2Run_Items_cast[0], 28 /* Unique Number for ActionList */
}, {
/* ActionListName   :   BswM_AL_Run2PostRun */
BSWM_TRIGGER, 3, &BswM_Cfg_AL_BswM_AL_Run2PostRun_Items_cast[0], 29 /* Unique Number for ActionList */
} };

/* PBAction Type structure Variant : __KW_COMMON
 * - Pointer to base address of array of IPduGroupSwitchType ActionType structure (BswM_Cfg_AC_PduGroupSwitchType_tst)
 */
#define BSWM_CFG_PBACTION                {      \
                &BswM_Cfg_AC_BswMPduGroupSwitch_cast[0],     \
}

/* ModeControl Type structure  
 * - ActionType structure (BswM_Cfg_PBActionType_tst)
 * - Pointer to base address of array of actionlists (BswM_Cfg_ActionListType_tst) Currently NULL_PTR
 */
#define BSWM_CFG_MODECONTROL {      \
        BSWM_CFG_PBACTION,     \
        &BswM_Cfg_AL_cast[0]   \
}

/* BswM_ConfigType  :
 * - ModeArbitration structure (BswM_Cfg_ModeArbitrationType_tst)
 * - ModeControl structure (BswM_Cfg_ModeControlType_tst)
 * - Version info to compare during module initialization
 */
const BswM_ConfigType BswM_Config = {
BSWM_CFG_MODEARBITRATION,
BSWM_CFG_MODECONTROL,
BSWM_CFG_VERSION_INFO };

#define BSWM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED 
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA_POSTBUILD_32
#include "BswM_MemMap.h"

const BswM_ConfigType *const BswM_Configurations_capcst[BSWM_NO_OF_CONFIGSETS] =
		{ &BswM_Config };

#define BSWM_STOP_SEC_CONFIG_DATA_POSTBUILD_32
#include "BswM_MemMap.h"
/**********************************************************************************************************************
 *                                                                                                      
 **********************************************************************************************************************/

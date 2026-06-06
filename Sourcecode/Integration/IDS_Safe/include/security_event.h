/***************************************************************************************
 * File Name   : security_event.h                                                      *
 * Created by  : DengWei  2024/10/12                                                   *
 *                                                                                     *
 * Description : Provide external interfaces for IdsM                                  *
 *                                                                                     *
 * Modified Details (Modified Date/Modifier/ Modified Reason):                         *
 *  1: 2024/10/12    DengWei         initial                                           *
 *                                                                                     *
 ***************************************************************************************/
#ifndef __SECURITY_EVENT__
#define __SECURITY_EVENT__

#ifdef __cplusplus
extern "C"
{
#endif

    /****************Include  Section Begin*********************************************/

#include <stdint.h>
#include <stddef.h>

    /****************Include  Section  End**********************************************/

    /****************NameSpace  Section  Begin******************************************/

    /****************NameSpace  Section  End********************************************/

    /****************Marco Definition Section Begin*************************************/
    typedef uint64_t IdsMTimestampType;

    /**
     * @brief IDS EVENT ID LIST
     * @details
     *
     */
    typedef enum
    {
        IDS_COMPROMISE_SENSITIVE_DATA = 0xC02F,           ///< 735506 Detect Attempts to Compromise Sensitive Data
        IDS_SECOC_FRESHVAL_VERIFY_FAIL = 0x8020,          ///< 735507 SecOC Authenticated Freshness Value Verification Failure
        IDS_SECOC_PDUMAC_VERIFY_FAIL_SMALL = 0x8024,      ///< 735534 SecOC PDU MAC Verification Failure Counter Exceeds Threshold Limit - Small
        IDS_SECOC_PDUMAC_VERIFY_FAIL_MEDIUM = 0x8025,     ///< 735542 SecOC PDU MAC Verification Failure Counter Exceeds Threshold Limit - Medium
        IDS_SECOC_FRESHVAL_RESYNC = 0x8029,               ///< 735510 SecOC Freshness Value Resync
        IDS_SW_UPDATE_FAIL = 0xC00C,                      ///< 735516 ECU SW Update Failed
        IDS_BOOT_PROCESS_FAIL = 0xC00D,                   ///< 735517 ECU Boot Process Fail
        IDS_SECOC_KEY_DISTRIBUTION_UPD_SUCCESS = 0xC04B,  ///< 735536 SecOC Key Distribution/Update Successful
        IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL = 0xC04C,     ///< 735524 SecOC Key Distribution/Update Failure
        IDS_SECOC_KEY_RESET_SUCCESS = 0xC04D,             ///< 735537 SecOC Key Reset Successful
        IDS_SECOC_KEY_RESET_FAIL = 0xC04E,                ///< 735525 SecOC Key Reset Failed
        IDS_SECURITY_ACCESS_VALIDATION_FAIL = 0xBFFF,     ///< 735527 Security Access Validation Failure
        IDS_SECURITY_ACCESS_VALIDATION_SUCCESS = 0xC000,  ///< 735528 Security Access Validation Successful
        IDS_SECURITY_ACCESS_LEVEL_MISMATCH = 0xC001,      ///< 735529 Security Access Level Mismatch at Command Execution
        IDS_SAFETY_WATCHDOG_TIMEOUT = 0xC014,             ///< 735520 Safety Watchdog Timeout
    } IdsM_SecurityEventIdType;

    /****************Marco Definition Section End***************************************/

    /****************Struct Definition Section Begin************************************/

    /****************Struct Definition Section End**************************************/

    /****************SEV Struct Definition Section Begin********************************/

    // IDS_COMPROMISE_SENSITIVE_DATA
    typedef enum
    {
        IDS_SENSITIVE_DATE_UNKNOWN = 0x00,       ///< Unknown/Other
        IDS_SENSITIVE_DATE_SYMMETRIC = 0x03,     ///< Symmetric encryption keys
    } Ids_DateType_SensitiveData;

    typedef enum
    {
        IDS_SENSITIVE_OP_UNKNOWN = 0x00,         ///< Unknown/Other
        IDS_SENSITIVE_OP_READ = 0x01,            ///< Read
        IDS_SENSITIVE_OP_WRITE = 0x02,           ///< Write
    } Ids_DateType_SensitiveOp;

    typedef enum
    {
        IDS_SENSITIVE_OP_RES_UNKNOWN = 0x00,     ///< Unknown/Other
        IDS_SENSITIVE_OP_RES_SUCCESS = 0x01,     ///< Success
        IDS_SENSITIVE_OP_RES_FAIL = 0x02,        ///< Fail
    } Ids_DateType_SensitiveOpRes;
    
/*    typedef struct Ids_Evt_AuthFreshValVerifFail
    {
        uint16_t did;                                ///< DID (Fill 0xFF if not DID)//4
        Ids_DateType_SensitiveData sensitiveData;     ///< the index of sensitive data//4
        Ids_DateType_SensitiveOp sensitiveOp;         ///< the operation of sensitive data//4
        Ids_DateType_SensitiveOpRes sensitiveOpRes;   ///< Operation result//4
    } Ids_Evt_AuthFreshValVerifFail;*/
    typedef struct Ids_Evt_AuthFreshValVerifFail
    {
        uint16_t did;                                ///< DID (Fill 0xFF if not DID)//4
        uint8_t sensitiveData;     ///< the index of sensitive data//4
        uint8_t sensitiveOp;         ///< the operation of sensitive data//4
        uint8_t sensitiveOpRes;   ///< Operation result//4
    } Ids_Evt_AuthFreshValVerifFail;

    // IDS_SECURITY_ACCESS_VALIDATION_FAIL
    typedef struct Ids_Evt_SecurityAccessValiFail
    {
        uint8_t level;                                ///< The security access level
        uint8_t nrc;                                  ///< NRC (35/36/37)  
    } Ids_Evt_SecurityAccessValiFail;

    // IDS_SECURITY_ACCESS_LEVEL_MISMATCH
    typedef struct Ids_Evt_SecurityAccessMismatchCmdExc
    {
        uint8_t serviceId;                            ///< Service ID
        uint16_t subFunctionId;                       ///< Sub Function ID
    } Ids_Evt_SecurityAccessMismatchCmdExc;

    // IDS_SECURITY_ACCESS_VALIDATION_SUCCESS
    typedef uint8_t Ids_SecurityAccLvType;            ///< The security access level

    /****************SEV Struct Definition Section Begin********************************/

    /****************Class Declaration Section Begin************************************/

    /**************** Class Declaration Section End*************************************/

    /****************Function Prototype Declaration Section Begin***********************/

    /****************Function Prototype Declaration Section End*************************/

#ifdef __cplusplus
}
#endif

#endif /* __SECURITY_EVENT__ */

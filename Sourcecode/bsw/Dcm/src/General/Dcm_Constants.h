
#ifndef DCM_CONSTANTS_H
#define DCM_CONSTANTS_H

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
*/

/* API ID for read did in order to report development errors to DET module */

#define DCM_INIT_ID                   0x01u
#define DCM_GETVERSIONINFO_ID         0x24u
#define DCM_DEMTRIGGERONDTCSTATUS_ID  0x2Bu
#define DCM_GETVIN_ID                 0x07u
#define DCM_SETDEAUTHENTICATEDROLE_ID 0x79u
#define DCM_GETSECURITYLEVEL_ID       0x0Du
#define DCM_GETSESCTRLTYPE_ID         0x06u
#define DCM_GETACTIVEPROTOCOL_ID      0x0Fu
#define DCM_RESETTODEFAULTSESSION_ID  0x2Au
#define DCM_TRIGGERONEVENT_ID         0x2Du
#define DCM_SETACTIVEDIAGNOSTIC       0x56u
#define DCM_STARTOFRECEPTION_ID       0x46u
#define DCM_COPYRXDATA_ID             0x44u
#define DCM_TPRXINDICATION_ID         0x45u
#define DCM_COPYTXDATA_ID             0x43u
#define DCM_TPTXCONFIRMATION_ID       0x48u
#define DCM_TXCONFIRMATION_ID         0x40u

#define DCM_RDBI_ID         0x8Au
#define DCM_WARMSTART_ID        0x8Bu
#define DCM_BOOTLOADER_ID       0x8Cu
#define DCM_KWPTIMING_ID        0x8Eu
#define DCM_PAGEDBUFFER_ID      0x8Fu
#define DCM_RDPI_ID             0x90u
#define DCM_ROE_ID              0x91u
#define DCM_ROEPROCESS_ID       0x92u
#define DCM_SETSRVTABLE_ID      0x94u
#define DCM_SETSESSION_ID       0x95u
#define DCM_PROCESSINGDONE_ID   0x96u
#define DCM_CC_ID               0x97u
#define DCM_CDTCS_ID            0x98u
#define DCM_DDDI_ID             0x99u
#define DCM_DSC_ID              0x9Au
#define DCM_GETP2TIMINGS_ID     0x9Bu
#define DCM_ER_ID               0x9Cu
#define DCM_IOCBI_ID            0x9Du
#define DCM_WDBI_ID             0x9Eu
#define DCM_CHKUSEDCOREMAIN_ID  0xA0u
#define DCM_TRANSFERDATA_ID     0xA1u
#define DCM_TRANSFEREXIT_ID     0xA2u
#define DCM_SETSECURITYLEVEL    0xA6u
#define DCM_SETSESSIONLEVEL     0xA7u
#define DCM_RDTC_ID             0xA8u
#define DCM_SECURITYACCESS_ID   0xA9u
#define DCM_SUPPLIERNOTIFICATION_ID 0xABu
#define DCM_MANUFACTURENOTIFICATION_ID 0xACu
#define DCM_ROUTINE_CONTROL_SID             0x31u
#define DCM_ROE_SID             0x86u


/* error ids for DET API interfaces, OBD services report the development errors to DET module */
#define DCM_DEFAULTSESSION                        0x01u
#define DCM_E_INTERFACE_TIMEOUT                   0x01u
#define DCM_E_INTERFACE_RETURN_VALUE              0x02u
#define DCM_E_INTERFACE_BUFFER_OVERFLOW           0x03u
#define DCM_E_UNINIT                              0x05u
#define DCM_E_PARAM                               0x06u
#define DCM_E_PARAM_POINTER                       0x07u
#define DCM_E_INIT_FAILED                         0x08u
#define DCM_E_SET_PROG_CONDITIONS_FAIL            0x09u
#define DCM_E_MIXED_MODE                          0x0Au
#define DCM_E_WRONG_STATUSVALUE                   0x0Bu
#define DCM_E_PROTOCOL_NOT_FOUND                  0x0Cu
#define DCM_E_NVM_UPDATION_NOT_OK                 0x0Du
#define DCM_E_FULLCOMM_DISABLED                   0x0Eu
#define DCM_E_PROTOCOL_NOT_STARTED                0x10u
#define DCM_E_PSUEDO_RECEPTION                    0x11u
#define DCM_E_SERVICE_TABLE_NOT_SET               0x12u
#define DCM_E_SESSION_NOT_CONFIGURED              0x13u
#define DCM_E_SUBNET_NOT_SUPPORTED                0x14u
#define DCM_E_DDDI_NOT_CONFIGURED                 0x15u
#define DCM_E_EXCEEDED_MAX_RECORDS                0x16u
#define DCM_E_NOT_SUPPORTED_IN_CURRENT_SESSION    0x17u
#define DCM_E_INVALID_ADDRLENGTH_FORMAT           0x18u
#define DCM_E_CONTROL_FUNC_NOT_CONFIGURED         0x19u
#define DCM_E_INVALID_CONTROL_PARAM               0x1Au
#define DCM_E_NO_WRITE_ACCESS                     0x1Bu
#define DCM_E_RET_E_INFRASTRUCTURE_ERROR          0x1Cu
#define DCM_E_INVALID_CONTROL_DATA                0x1Du

#define DCM_E_RET_E_NOT_OK                        0x1Eu
#define DCM_E_DCMRXPDUID_RANGE_EXCEED             0x20u
#define DCM_E_DCMTXPDUID_RANGE_EXCEED             0x21u
#define DCM_E_NO_READ_ACCESS                      0x22u
#define DCM_E_SERVICE_TABLE_OUTOFBOUNDS           0x23u
#define DCM_E_SECURITYLEVEL_OUTOFBOUNDS           0x24u
#define DCM_E_RET_E_PENDING                       0x25u
#define DCM_E_INVALID_LENGTH                      0x26u
#define DCM_E_FORCE_RCRRP_IN_SILENT_COMM          0x27u
#define DCM_E_ENABLEDTCRECORD_FAILED              0x28U
#define DCM_E_SUBNODE_NOT_SUPPORTED               0x29u



#endif

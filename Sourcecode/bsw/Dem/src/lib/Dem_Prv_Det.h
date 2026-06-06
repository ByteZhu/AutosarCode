
#ifndef DEM_PRV_DET_H
#define DEM_PRV_DET_H

#include "Dem_Cfg_Main.h"
#include "Dem_Types.h"

extern Dem_EventIdType Dem_EventIdCausingLastDetError;

#if (DEM_CFG_BUILDTARGET == DEM_CFG_BUILDTARGET_DEMTESTSUITE)
    #include "rba_SimCUnit_C_Wrapper_Asserts.h"
    #include "DemTest_Det_C_Wrapper.h"
/* MR12 RULE 20.7 VIOLATION : Macro parameter may not be enclosed in (). */
    #define DEM_DET(APIID,ERRORID,EVENTID)   do {Dem_EventIdCausingLastDetError = EVENTID; DemTestDET_checkDetError(APIID,ERRORID);}while(0)
/* MR12 RULE 20.7 VIOLATION : Macro parameter may not be enclosed in (). */
    #define DEM_DET_RUNTIME_ERROR(APIID,ERRORID,EVENTID)   do {Dem_EventIdCausingLastDetError = EVENTID; DemTestDET_checkDetError(APIID,ERRORID);}while(0)
#else
    #if ((DEM_CFG_DEVERRORDETECT == DEM_CFG_DEVERRORDETECT_ON) || (DEM_CFG_RUNTIMEERRORDETECT == DEM_CFG_RUNTIMEERRORDETECT_ON) )
    #include "Det.h"
    #endif
#if(DEM_CFG_DEVERRORDETECT == DEM_CFG_DEVERRORDETECT_ON)
/* MR12 RULE 20.7 VIOLATION : Macro parameter may not be enclosed in (). */
    #define DEM_DET(APIID,ERRORID,EVENTID)    do {Dem_EventIdCausingLastDetError = EVENTID; Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,APIID,ERRORID);}while(0)
    #else
/* MR12 RULE 20.7 VIOLATION : Macro parameter may not be enclosed in (). */
    #define DEM_DET(APIID,ERRORID,EVENTID)   do { } while(0)
#endif
#if (DEM_CFG_RUNTIMEERRORDETECT == DEM_CFG_RUNTIMEERRORDETECT_ON)
/* MR12 RULE 20.7 VIOLATION : Macro parameter may not be enclosed in (). */
    #define DEM_DET_RUNTIME_ERROR(APIID,ERRORID,EVENTID)   do {Dem_EventIdCausingLastDetError = EVENTID; (void)Det_ReportRuntimeError(DEM_MODULE_ID,DEM_INSTANCE_ID,APIID,ERRORID);}while(0)
    #else
/* MR12 RULE 20.7 VIOLATION : Macro parameter may not be enclosed in (). */
    #define DEM_DET_RUNTIME_ERROR(APIID,ERRORID,EVENTID)   do { } while(0)
#endif
#endif

#ifdef QAC
    #define DEM_ASSERT(C,APIID,ERRORID)  (void)(C)
#elif (DEM_CFG_BUILDTARGET == DEM_CFG_BUILDTARGET_DEMTESTSUITE)
    #define DEM_ASSERT(C,APIID,ERRORID)  assertTrue_C(C)
#else
    #define DEM_ASSERT(C,APIID,ERRORID)   do { if (!(C)) { DEM_DET(APIID,ERRORID,0); } } while(0)
#endif


/**********************************************************************************************************************
 * Development Errors
 **********************************************************************************************************************/
#define DEM_E_WRONG_CONFIGURATION   0x10
#define DEM_E_PARAM_POINTER         0x11
#define DEM_E_PARAM_DATA            0x12
#define DEM_E_PARAM_LENGTH          0x13
#define DEM_E_UNINIT                0x20
#define DEM_E_WRONG_CONDITION       0x40
#define DEM_E_INTERNAL              0x50
#define DEM_E_OUTOFTIME             0x60


/**********************************************************************************************************************
 * Runtime Errors
 **********************************************************************************************************************/
#define DEM_E_UDS_STATUS_PROCESSING_FAILED      0x21
#define DEM_E_NODATAAVAILABLE       0x30u

/**********************************************************************************************************************
 * AUTOSAR Service IDs
 **********************************************************************************************************************/
#define DEM_DET_APIID_GETVERSIONINFO                            0x00u
#define DEM_DET_APIID_PREINIT                                   0x01u
#define DEM_DET_APIID_INIT                                      0x02u
#define DEM_DET_APIID_SHUTDOWN                                  0x03u
#define DEM_DET_APIID_SETEVENTSTATUS                            0x04u
#define DEM_DET_APIID_RESETEVENTSTATUS                          0x05u
#define DEM_DET_APIID_PRESTOREFREEZEFRAME                       0x06u
#define DEM_DET_APIID_DEM_CLEARPRESTOREDFREEZEFRAME             0x07u
#define DEM_DET_APIID_DEM_RESTARTOPERATIONCYCLE                 0x08u
#define DEM_DET_APIID_DEM_RESETEVENTDEBOUNCESTATUS              0x09u
#define DEM_DET_APIID_DEM_GETEVENTSTATUS                        0x0Au
#define DEM_DET_APIID_DEM_GETEVENTFAILED                        0x0Bu
#define DEM_DET_APIID_DEM_GETEVENTTESTED                        0x0Cu
#define DEM_DET_APIID_DEM_GETDTCOFEVENT                         0x0Du
#define DEM_DET_APIID_DEM_GETSEVERITYOFDTC                      0x0Eu
#define DEM_DET_APIID_REPORTERRORSTATUS                         0x0Fu
#define DEM_DET_APIID_SETDTCFILTER                              0x13u
#define DEM_DET_APIID_DEM_GETSTATUSOFDTC                        0x15u
#define DEM_DET_APIID_GETDTCSTATUSAVAILABILITYMASK              0x16u
#define DEM_DET_APIID_GETNUMBEROFFILTEREDDTC                    0x17u
#define DEM_DET_APIID_GETNEXTFILTEREDDTC                        0x18u
#define DEM_DET_APIID_GETDTCBYOCCURRENCETIME                    0x19u
#define DEM_DET_APIID_DISABLEDTCRECORDUPDATE                    0x1Au
#define DEM_DET_APIID_ENABLEDTCRECORDUPDATE                     0x1Bu
#define DEM_DET_APIID_GETFREEZEFRAMEDATABYRECORD                0x1Cu
#define DEM_DET_APIID_GETNEXTFREEZEFRAMEDATA                    0x1Du
#define DEM_DET_APIID_GETSIZEOFFREEZEFRAMESELECTION             0x1Fu
#define DEM_DET_APIID_GETNEXTEXTENDEDDATARECORD                 0x20u
#define DEM_DET_APIID_GETSIZEOFEXTENDEDDATARECORDSELECTION      0x21u
#define DEM_DET_APIID_CLEARDTC                                  0x23u
#define DEM_DET_APIID_DISABLEDTCSETTING                         0x24u
#define DEM_DET_APIID_ENABLEDTCSETTING                          0x25u
#define DEM_DET_APIID_DEM_GETINDICATORSTATUS                    0x29u
#define DEM_DET_APIID_DEM_GETCOMPONENTFAILED                    0x2Au
#define DEM_DET_APIID_DEM_SETCOMPONENTAVAILABLE                 0x2Bu
#define DEM_DET_APIID_GETEVENTEXTENDEDDATARECORD                0x30u
#define DEM_DET_APIID_GETEVENTFREEZEFRAMEDATA                   0x31u
#define DEM_DET_APIID_GETEVENTMEMORYOVERFLOW                    0x32u
#define DEM_DET_APIID_DEM_SETDTCSUPPRESSION                     0x33u
#define DEM_DET_APIID_DEM_GETFUNCTIONAlUNITOFDTC                0x34u
#define DEM_DET_APIID_DEM_EVMEMGETNUMBEROFEVENTENTRIES          0x35u
#define DEM_DET_APIID_DEM_SETEVENTAVAILABLE                     0x37u
#define DEM_DET_APIID_SETSTORAGECONDITION                       0x38u
#define DEM_DET_APIID_SETENABLECONDITION                        0x39u
#define DEM_DET_APIID_GETNEXTFILTEREDRECORD                     0x3Au
#define DEM_DET_APIID_GETNEXTFILTEREDDTCANDFDC                  0x3Bu
#define DEM_DET_APIID_GETTRANSLATIONTYPE                        0x3Cu
#define DEM_DET_APIID_GETNEXTFILTEREDDTCANDSEVERITY             0x3Du
#define DEM_DET_APIID_GETFAULTDETECTIONCOUNTER                  0x3Eu
#define DEM_DET_APIID_SETFREEZEFRAMERECORDFILTER                0x3Fu
#define DEM_DET_APIID_SETCYCLEQUALIFIED                         0x56u
#define DEM_DET_APIID_GETNUMBEROFFREEZEFRAMERECORDS             0x5Au
#define DEM_DET_APIID_DEM_GETEVENTEXTENDEDDATARECORDEX          0x6Du
#define DEM_DET_APIID_DEM_GETEVENTFREEZEFRAMEDATAEX             0x6Eu
#define DEM_DET_APIID_DEM_SETWIRSTATUS                          0x7Au
#define DEM_DET_APIID_DEM_J1939DCMSETDTCFILTER                  0x90
#define DEM_DET_APIID_DEM_J1939DCMGETNUMBEROFFILTEREDDTC        0x91
#define DEM_DET_APIID_DEM_J1939DCMGETNEXTFILTEREDDTC            0x92
#define DEM_DET_APIID_DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS        0x93
#define DEM_DET_APIID_DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS      0x94
#define DEM_DET_APIID_DEM_J1939DcmClearDTC                      0x95u
#define DEM_DET_APIID_DEM_J1939DCMSETFREEZEFRAMEFILTER          0x96u
#define DEM_DET_APIID_DEM_J1939DCMGETNEXTFREEZEFRAME            0x97u
#define DEM_DET_APIID_DEM_GETDEBOUNCINGOFEVENT                  0x9Fu
#define DEM_DET_APIID_GETCYCLEQUALIFIED                         0xABu
#define DEM_DET_APIID_GETIUMPRDENSTATUS                         0xAFu
#define DEM_DET_APIID_GETDTCSEVERITYAVAILABILITYMASK            0xB2u
#define DEM_DET_APIID_DEM_GETMONITORSTATUS                      0xB5u
#define DEM_DET_APIID_DEM_SELECTDTC                             0xB7u
#define DEM_DET_APIID_DEM_GETDTCSELECTIONRESULT                 0xB8u
#define DEM_DET_APIID_SELECTFREEZEFRAMEDATA                     0xB9u
#define DEM_DET_APIID_SELECTEXTENDEDDATARECORD                  0xBAu
#define DEM_DET_APIID_DEM_GETDTCSELECTIONRESULTFORCLEAR         0xBBu
#define DEM_DET_APIID_DEM_GETDTCSUPPRESSION                     0xBCu
#define DEM_DET_APIID_SETEVENTSTATUSWITHMONITORDATA             0xBDu

/**********************************************************************************************************************
 * Internal Service IDs 0xA0 - 0xFF
 **********************************************************************************************************************/
#define DEM_DET_APIID_DEBCALLFILTER                             0xA0u
#define DEM_DET_APIID_DEBMAINFUNCTION                           0xA1u
#define DEM_DET_APIID_ENVDARETRIEVE                             0xA2u
#define DEM_DET_APIID_ENVGETSIZEOFEDR                           0xA3u
#define DEM_DET_APIID_ENVGETSIZEOFEDR_ALLOROBDSTORED            0xA4u
#define DEM_DET_APIID_ENVRETRIEVEEDR                            0xA5u
#define DEM_DET_APIID_ENVRETRIEVEFF                             0xA6u
#define DEM_DET_APIID_ENVDACAPTURE                              0xA7u
#define DEM_DET_APIID_ENVDASKIP                                 0xA8u
#define DEM_DET_APIID_ENVDAUPDATE                               0xA9u
#define DEM_DET_APIID_ENVEDCOPYRAW                              0xAAu
#define DEM_DET_APIID_ENVCAPTUREED                              0xABu
#define DEM_DET_APIID_ENVCAPTUREFF                              0xACu
#define DEM_DET_APIID_ENVCOPYRAWFF                              0xADu
#define DEM_DET_APIID_ENVFFCOPYRAW                              0xAEu
#define DEM_DET_APIID_EVTSRESTOREFAILUREFROMPREVIOUSIC          0xB0u
#define DEM_DET_APIID_EVMEMERASEEVENTMEMORY                     0xB1u
#define DEM_DET_APIID_EVMEMSETEVENTFAILED                       0xFBu
#define DEM_DET_APIID_EVMEMGETEVENTMEMORYLOCIDOFEVENT           0xB6u
#define DEM_DET_APIID_ENVUPDATERAWED                            0xFDu
/* 0xB7, 0xB8, 0xB9, 0xBA, 0xBB and 0xBD shall not be used since it is used by AUTOSAR interface */
#define DEM_DET_APIID_EVMEMNVMREADEVENTMEMORYINIT               0xBCu
#define DEM_DET_APIID_EVMEMCOPYTOMIRRORMEMORY                   0xBEu
#define DEM_DET_APIID_EVMEMCLEARSHADOWMEMORY                    0xBFu
#define DEM_DET_APIID_EVMEMGETSHADOWMEMORYLOCIDOFDTC            0xC0u
#define DEM_DET_APIID_EVMEMGETEVENTMEMORYSTATUSOFEVENT          0xC1u
#define DEM_DET_APIID_DEM_EVMEMGETEVENTMEMID                    0xC2u
/* FC_VariationPoint_START */
#define DEM_DET_APIID_OBDENVCAPTUREFF                           0xC3u
#define DEM_DET_APIID_OBDENVFFCOPYRAW                           0xC4u
/* FC_VariationPoint_END */
#define DEM_DET_APIID_DTCGROUPIDIDLISTITERATOR                  0xC5u
#define DEM_DET_APIID_EVENTDEPENDENCY                           0xC6u
/* FC_VariationPoint_START */
#define DEM_DET_APIID_BFM                                       0xC7u
#define DEM_DET_APIID_BFM_BUFFER                                0xC8u
#define DEM_DET_APIID_BFM_RECORD                                0xC9u
/* FC_VariationPoint_END */
#define DEM_DET_APIID_DISTMEMORY                                0xCAu
#define DEM_DET_APIID_ENVGETINDEXFROMFFRECNUM                   0xCBu
#define DEM_DET_APIID_ENVGETFFRECNUMFROMINDEX                   0xCCu
#define DEM_DET_APIID_ENVGETINDEXOFCONFFFREC                    0xCDu
#define DEM_DET_APIID_GETHISTORYSTATUS                          0xCEu
#define DEM_DET_APIID_SERIALIZATION                             0xCFu
#define DEM_DET_APIID_EVMEMSETEVENTUNROBUST                     0xD0u
/* FC_VariationPoint_START */
#define DEM_DET_APIID_BFM_EXT_RECORD                            0xD1u
/* FC_VariationPoint_END */
#define DEM_DET_APIID_REPORERRORSTATUSQUEUE                     0xD2u
#define DEM_DET_APIID_NVMSTATEMACHINE                           0xD3u
#define DEM_DET_APIID_WWHOBDCAPTUREFF                           0xD4u
#define DEM_DET_APIID_WWHOBDFFCOPYRAW                           0xD5u
#define DEM_DET_APIID_WWHOBDRETRIEVEFF                          0xD6u
#define DEM_DET_APIID_EVENTDEPENDENCIES_ISCAUSAL                0xE1u
#define DEM_DET_APIID_EVENTDEPENDENCIES                         0xE2u
#define DEM_DET_APIID_EVMEMCLEAREVENT                           0xE3u
#define DEM_DET_APIID_EVMEMSETEVENTPASSED                       0xE5u
#define DEM_DET_APIID_J1939DCMSETDTCFILTER                      0xE6u
#define DEM_DET_APIID_J1939DCMGETNUMBEROFFILTEREDDTC            0xE7u
#define DEM_DET_APIID_J1939DCMGETNEXTFILTEREDDTC                0xE8u
#define DEM_DET_APIID_J1939ENVRETRIEVEFF                        0xE9u
#define DEM_DET_APIID_J1939ENVRETRIEVEEXPFF                     0xEAu
#define DEM_DET_APIID_J1939ENVCOPYRAWFF                         0xEBu
#define DEM_DET_APIID_J1939ENVCOPYRAWEXPFF                      0xECu
#define DEM_DET_APIID_J1939ENVFFCOPYRAW                         0xEDu
#define DEM_DET_APIID_J1939ENVCAPTUREFF                         0xEEu
#define DEM_DET_APIID_J1939ENVCAPTUREEXPFF                      0xEFu
#define DEM_DET_APIID_J1939DCMGETNEXTDTCWITHLAMPSTATUS          0xF0u
#define DEM_DET_APIID_CLIENT_OPERATION                          0xF1u
#define DEM_DET_APIID_EVMEMSTARTOPERATIONCYCLE                  0xF2u
#define DEM_DET_APIID_EVMEMGETNVMIDFROMLOCID                    0xF3u
#define DEM_DET_APIID_EVMEMSTARTAGINGCYCLE                      0xF4u
#define DEM_DET_APIID_EVMEMGETEVENTMEMORYSTATUSOFDTC            0xF5u
#define DEM_DET_APIID_GETENABLECONDITION                        0xF6u
#define DEM_DET_APIID_RESETCYCLEQUALIFIED                       0xF7u
#define DEM_DET_APIID_REPORTUNROBUSTQUEUEOVERFLOW               0xF8u
#define DEM_DET_APIID_EVENTDATANOTCAPTURED                      0xF9u
#define DEM_DET_APIID_CLIENTIDITERATOR                          0xFAu
#define DEM_DET_APIID_EVENTIDLISTITERATOR                       0xFBu
#define DEM_DET_APIID_EVENTSTATUSUPDATE                         0xFCu
#define DEM_DET_APIID_GETSTORAGECONDITION                       0xFEu
#endif /* DEM_PRV_DET_H */

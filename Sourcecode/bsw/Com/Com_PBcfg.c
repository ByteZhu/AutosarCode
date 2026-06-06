

 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/


/*
 * If COM_DontUseExternalSymbolicNames is defined before including Com_Cfg.h file, then external symbolic names will
 * not be visible.
 * Com_PBcfg.c file should not use external symbolic names.
 * This mechanism is used to prevent the accidental usage of external symbolic names in this file
 * This file should use only internal symbolic name defined in  Com_PBcfg_InternalSymbolicNames.h
 */
#define COM_DontUseExternalSymbolicNames
#include "Com_Prv.h"
#include "Com_Cbk.h"
#include "PduR_Com.h"
#include "Com_PBcfg_Common.h"
#include "Com_PBcfg_Variant.h"

/*
 * The file Com_PBcfg_InternalSymbolicNames.h defines internal symbolic names
 * These names should be used in the tables generated in this file
 * Regular symbolic names should not be used here
 */
#define COM_PBCFG_INCLUDE_INT_SYM_NAMES
#include "Com_PBcfg_InternalSymbolicNames.h"



/* START: Tx Signal Details  */

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_Prv_xTxSigCfg_tst Com_Prv_xTxSigCfg_acst[COM_NUM_TX_SIGNALS] =
{
        
    {  /* S_test_0x2A_checksum_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_test_0x2A_command_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_test_0x2A_counter_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_test_0x2A_current_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x06,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_FaultStatus_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        64,/*BitSize*/

#ifdef COM_TxFilters
        0x07,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT64
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x10                                               /*General*/

    },
        
    {  /* S_test_0x4A_checksum_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        200,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_test_0x4A_counter_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        192,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_test_0x4A_current1_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        64,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x08,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_current2_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        80,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x09,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_current3_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        96,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x0A,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_current4_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        112,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x0B,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_current5_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        128,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x0C,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_sensor1_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        144,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x0D,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_sensor2_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        160,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x0E,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_test_0x4A_sensor3_Can_Network_2_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        176,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x0F,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpADMo_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        24,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpChks_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpCntr_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpCtrl_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        26,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpData_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        12,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpDegr_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpLatC_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        27,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpQf_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        22,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkpSts_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        20,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsForCoDrvForBkp_UB_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        39,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpChks8_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpCntr4_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpDataID4_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        52,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpPin_0000_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        86,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpPin_0001_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        72,                                                /*BitPosition*/

        14,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x3                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpPin_0002_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        102,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpPinionSt_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        15,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x3                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpSte_0000_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        104,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkpSteerWhl_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        88,                                                /*BitPosition*/

        14,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x3                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupForBkp_UB_Can_Network_1_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        38,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsADMod_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsChks_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsCntr_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        24,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        22,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsDegraded_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        28,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsQf_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        18,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlStsSts_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        20,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_ADL3LatCtrlSts_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        23,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerActvChks_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerActvCntr_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        12,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerActvDrvrSteerActv_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        11,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerActv_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        10,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_FrntSteerFEstimd1_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x00,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_FrntSteerFEstimd1_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerStsToCrabMov_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerStsToCrabMov_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        60,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_UBoostReqBySteerFrnt_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        58,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_UBoostReqBySteerFrnt_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        57,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupChks_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupCntr_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        60,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupPinionSte_0000_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        14,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupPinionSte_0001_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        30,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupPinionSteerAg1_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        15,/*BitSize*/

#ifdef COM_TxFilters
        0x01,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupPinionSteerAgS_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        14,/*BitSize*/

#ifdef COM_TxFilters
        0x02,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupSteerWhlTqQf_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        58,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroupSteerWhlTq_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        14,/*BitSize*/

#ifdef COM_TxFilters
        0x03,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_PinionSteerAgGroup_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        57,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_LatCtrlModCfmdChks_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_LatCtrlModCfmdCntr_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        12,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_LatCtrlModCfmdLatCtrlMod_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_LatCtrlModCfmd_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        23,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerServoSts_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerServoSts_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        55,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerWhlTqAddl_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        42,                                                /*BitPosition*/

        14,/*BitSize*/

#ifdef COM_TxFilters
        0x05,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_SteerWhlTqAddl_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        41,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_TqAssAddl_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        14,/*BitSize*/

#ifdef COM_TxFilters
        0x06,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_TqAssAddl_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        54,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerWhlHldGroupDrvrSte_0000_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        2,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerWhlHldGroupDrvrSteerWhl_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        6,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_DrvrSteerWhlHldGroup_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        1,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerErrReq_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        44,                                                /*BitPosition*/

        3,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerErrReq_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        47,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsChks_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsCntr_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsDrvrSteerOvrd_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        52,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsExtFctLowerLimActi_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        53,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsExtFctRateLimActiv_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        54,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsExtFctUpperLimActi_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        55,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsExtSafeLimActive_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsLatAgReqNotInRange_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        41,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctStsLatCtrlReqNotInRan_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        42,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerExtFctSts_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        43,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerSftyLimrSts_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        12,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerSftyLimrSts_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        11,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerStsToParkAssi_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        13,                                                /*BitPosition*/

        3,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_SteerStsToParkAssi_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PinionSteerAgMax1_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x32,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        15,/*BitSize*/

#ifdef COM_TxFilters
        0x04,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = SINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x23                                               /*General*/

    },
        
    {  /* S_PinionSteerAgMax1_UB_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        55,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_CCP_Res_Data_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        64,/*BitSize*/

#ifdef COM_TxFilters
        0x00,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_CCP_Response_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT64
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x10                                               /*General*/

    },
        
    {  /* S_SAS_ResponseData_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        64,/*BitSize*/

#ifdef COM_TxFilters
        0x05,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT64
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x10                                               /*General*/

    },
        
    {  /* S_Debug_infor_1_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x01,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_Debug_infor_2_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x02,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_Debug_infor_3_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x03,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_Debug_infor_4_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = NEW_IS_WITHIN
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2A,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0x04,                                                  /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x2                                               /*General*/

    },
        
    {  /* S_NM_User_Data_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        1uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x52,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        4,/*BitSize = Length*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_NM_VCU_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8_N
            Endianess:1;  = OPAQUE
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x8                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0000_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0001_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0002_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        24,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0003_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0004_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0005_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1F_0006_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_PSCMdevelpsignalgroupresp1Functi_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* S_TestModeResponse0_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse1_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse2_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse3_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        24,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse4_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse5_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse6_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    },
        
    {  /* S_TestModeResponse7_Can_Network_0_Channel_CAN_Tx */
#ifdef COM_TxInvalid
        0x0uL,        /* DataInvalid_Val*/
#endif
#if !defined(COM_INITVALOPTIMIZATION)
        0x0uL,             /* Init_Val*/
#endif

        /*
        {
            TransProp       : 3;    = PENDING
            FilterAlgorithm : 4;    = ALWAYS
            DataInvalidType : 1;    = false
            TimeOutEnabled  : 1;    = false
        }Com_TxSigPropType;    */
        0x2,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        COM_MAX_U8_VALUE,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        COM_TOC_OLD_VALUE_INV_IDX,
                                            /*OldVal_Index*/
#endif

        (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,             /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                    /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1; = false
            Not_Used:1;
        }Com_GeneralType;*/
        0x0                                               /*General*/

    }

};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Tx Signal Details  */

/* START: Rx Signal Details  */

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_Prv_xRxSigCfg_tst Com_Prv_xRxSigCfg_acst[COM_NUM_RX_SIGNALS] =
{    
        
    {  /* S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       26,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       2,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       33,                         /*BitPosition*/
       3,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       36,                         /*BitPosition*/
       4,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       5,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       34,                         /*BitPosition*/
       6,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       7,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       50,                         /*BitPosition*/
       8,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       49,                         /*BitPosition*/
       9,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       10,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       52,                         /*BitPosition*/
       11,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       12,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0xf0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       14,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      9, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       13,                         /*BitPosition*/
       13,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0xf0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       51,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      9, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       50,                         /*BitPosition*/
       14,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x3a00uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       25,                         /*BitPosition*/
       2,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       15,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       44,                         /*BitPosition*/
       16,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       17,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      64, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CCP_Request_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT64
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x10,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       192,                         /*BitPosition*/
       18,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpChks8_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       168,                         /*BitPosition*/
       19,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       176,                         /*BitPosition*/
       20,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpCtrlSts_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       194,                         /*BitPosition*/
       21,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       180,                         /*BitPosition*/
       22,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpDegraded_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       184,                         /*BitPosition*/
       23,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpQf_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x3uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       188,                         /*BitPosition*/
       24,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkpSts_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x2uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       190,                         /*BitPosition*/
       25,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADL3FuncCtrlStsForBkp_UB_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       9,                         /*BitPosition*/
       26,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqForBkpADActiveReq_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       27,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqForBkpADDeactiveReq_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       34,                         /*BitPosition*/
       28,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       29,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       30,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       31,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyADModeReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       10,                         /*BitPosition*/
       32,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatCoDrvReqForBkpAsyLatCoDrvR_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       160,                         /*BitPosition*/
       33,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatCoDrvReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       144,                         /*BitPosition*/
       34,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatCoDrvReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       152,                         /*BitPosition*/
       35,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatCoDrvReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       156,                         /*BitPosition*/
       36,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatCoDrvReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       89,                         /*BitPosition*/
       37,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqForBkpAsyPinionAgR_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x3a00uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       248,                         /*BitPosition*/
       3,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       232,                         /*BitPosition*/
       38,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       240,                         /*BitPosition*/
       39,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       244,                         /*BitPosition*/
       40,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyPinionAgReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       41,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       336,                         /*BitPosition*/
       42,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatOvrdReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       320,                         /*BitPosition*/
       43,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatOvrdReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       328,                         /*BitPosition*/
       44,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatOvrdReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       332,                         /*BitPosition*/
       45,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyLatOvrdReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       209,                         /*BitPosition*/
       46,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      64, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT64
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x10,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       47,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       48,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       4,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       5,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       6,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       4,                         /*BitPosition*/
       49,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       50,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       51,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       52,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       53,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       54,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       55,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       56,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       57,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       58,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_NM_EIRA_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &ComM_EIRACallBack_COMM_BUS_TYPE_CAN,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       228,                /* Signal Buffer Index */
       
      4, /*BitSize = Length*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8_N
            Endianess:1;   = OPAQUE
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x8,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       96,                         /*BitPosition*/
       2,                /* Signal Buffer Index */
       
      64, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT64
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x10,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_checksum_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       59,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_counter_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       60,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_current1_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       7,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_current2_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       8,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_current3_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       9,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_current4_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       64,                         /*BitPosition*/
       10,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_current5_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       80,                         /*BitPosition*/
       11,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_sensor1_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       160,                         /*BitPosition*/
       12,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_sensor2_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       176,                         /*BitPosition*/
       13,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x4F_sensor3_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       192,                         /*BitPosition*/
       14,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       61,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x2F_command_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       62,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x2F_counter_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       63,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_test_0x2F_current_Can_Network_2_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       15,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       64,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       12,                         /*BitPosition*/
       65,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x3a00uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       25,                         /*BitPosition*/
       16,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       10,                         /*BitPosition*/
       66,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       67,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       68,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       60,                         /*BitPosition*/
       69,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       59,                         /*BitPosition*/
       70,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       58,                         /*BitPosition*/
       71,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       17,                /* Signal Buffer Index */
       
      14, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       18,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       72,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       44,                         /*BitPosition*/
       73,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       22,                         /*BitPosition*/
       74,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       75,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       76,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       77,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest2_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest2_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       78,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest3_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest3_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       79,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest4_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest4_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       80,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest5_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest5_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       81,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest6_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest6_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       82,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TestModeRequest7_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TestModeRequest7_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       83,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       6,                         /*BitPosition*/
       84,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       85,                /* Signal Buffer Index */
       
      5, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       86,                /* Signal Buffer Index */
       
      5, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       87,                /* Signal Buffer Index */
       
      6, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       88,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       89,                /* Signal Buffer Index */
       
      6, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       90,                /* Signal Buffer Index */
       
      7, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       91,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       92,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       93,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       52,                         /*BitPosition*/
       94,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       55,                         /*BitPosition*/
       95,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       96,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       57,                         /*BitPosition*/
       19,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       42,                         /*BitPosition*/
       97,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0xffuL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       98,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       44,                         /*BitPosition*/
       99,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       34,                         /*BitPosition*/
       20,                /* Signal Buffer Index */
       
      14, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       100,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       21,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       101,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       10,                         /*BitPosition*/
       102,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       25,                         /*BitPosition*/
       22,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       103,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       23,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       39,                         /*BitPosition*/
       104,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x483uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       57,                         /*BitPosition*/
       24,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0xffuL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       105,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       12,                         /*BitPosition*/
       106,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       107,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       108,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       12,                         /*BitPosition*/
       109,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       11,                         /*BitPosition*/
       110,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       10,                         /*BitPosition*/
       111,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0xffuL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       112,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       113,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       114,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       42,                         /*BitPosition*/
       25,                /* Signal Buffer Index */
       
      14, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       41,                         /*BitPosition*/
       115,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       116,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       26,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       117,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       60,                         /*BitPosition*/
       118,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       58,                         /*BitPosition*/
       119,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       39,                         /*BitPosition*/
       120,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       55,                         /*BitPosition*/
       121,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       54,                         /*BitPosition*/
       122,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       123,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       124,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       52,                         /*BitPosition*/
       125,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       126,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       127,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       128,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       26,                         /*BitPosition*/
       129,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       27,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       130,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       41,                         /*BitPosition*/
       28,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       131,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0xffuL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       132,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       44,                         /*BitPosition*/
       133,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       42,                         /*BitPosition*/
       134,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       29,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       135,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       30,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = SINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x23,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       49,                         /*BitPosition*/
       136,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       37,                         /*BitPosition*/
       137,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       34,                         /*BitPosition*/
       138,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       139,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       12,                         /*BitPosition*/
       140,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       141,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       142,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       33,                         /*BitPosition*/
       143,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       144,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       20,                         /*BitPosition*/
       145,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       146,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       147,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       148,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       60,                         /*BitPosition*/
       149,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       150,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       51,                         /*BitPosition*/
       151,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       31,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       152,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       153,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       4,                         /*BitPosition*/
       154,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       6,                         /*BitPosition*/
       155,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       156,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       157,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       158,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       159,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       160,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       161,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       162,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       163,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       164,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       165,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       166,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       167,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       168,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       169,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       170,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       171,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_DrvModReq_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_DrvModReq_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       58,                         /*BitPosition*/
       172,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       62,                         /*BitPosition*/
       173,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       174,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       175,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       4,                         /*BitPosition*/
       176,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       6,                         /*BitPosition*/
       177,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_EscStChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_EscStChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       178,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_EscStCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_EscStCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       179,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_EscStEscSt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_EscStEscSt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       36,                         /*BitPosition*/
       180,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_EscSt_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_EscSt_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       39,                         /*BitPosition*/
       181,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       20,                         /*BitPosition*/
       182,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       21,                         /*BitPosition*/
       183,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       184,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       185,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       186,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       187,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       188,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       189,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       5,                         /*BitPosition*/
       190,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       191,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       192,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       193,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       43,                         /*BitPosition*/
       194,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       195,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       3,                         /*BitPosition*/
       196,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       197,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       198,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CarTiGlb_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      32, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT32
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x24,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       57,                         /*BitPosition*/
       199,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       52,                         /*BitPosition*/
       200,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       51,                         /*BitPosition*/
       201,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       49,                         /*BitPosition*/
       202,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       203,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       204,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       205,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       54,                         /*BitPosition*/
       206,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       19,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      21, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT32
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x24,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       53,                         /*BitPosition*/
       207,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       208,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       54,                         /*BitPosition*/
       209,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       55,                         /*BitPosition*/
       210,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       47,                         /*BitPosition*/
       211,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       212,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       213,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       32,                /* Signal Buffer Index */
       
      12, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       4,                         /*BitPosition*/
       214,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       215,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       28,                         /*BitPosition*/
       216,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       26,                         /*BitPosition*/
       217,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       33,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x1uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       218,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       41,                         /*BitPosition*/
       34,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       7,                         /*BitPosition*/
       219,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       0,                         /*BitPosition*/
       220,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       8,                         /*BitPosition*/
       221,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       16,                         /*BitPosition*/
       222,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       24,                         /*BitPosition*/
       223,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       32,                         /*BitPosition*/
       224,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       40,                         /*BitPosition*/
       225,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       48,                         /*BitPosition*/
       226,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* S_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        &Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       0x0uL,              /* DataInvalid_Val */
#endif
#if !defined(COM_INITVALOPTIMIZATION)
       0x0uL,              /* Init_Val */
#endif

#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif
       56,                         /*BitPosition*/
       227,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        COM_MAX_U8_VALUE,                           /*Filter_Index*/
#endif

       (Com_IpduId_tuo)ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,                       /*Ipdu Reference*/
#ifdef COM_INITVALOPTIMIZATION
        0u,                   /* Init_Val_Index*/
#endif
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = false
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   = NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = false
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    

};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


#ifdef COM_PRV_ENABLECONFIGINTERFACES

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_RxSigConfigType_tst Com_Prv_RxSigCfg_acst[COM_NUM_RX_SIGNALS] =
{
    
        
    {
        /* S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx_u8,
        0,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx_u8,
        1,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx_u8,
        2,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx_u8,
        3,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx_u8,
        4,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx_u8,
        5,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx_u8,
        6,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx_u8,
        7,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx_u8,
        8,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx_u8,
        9,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx_u8,
        10,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx_u8,
        11,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx_u8,
        12,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx_u8,
        13,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx_u8,
        14,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx_u8,
        15,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx_u8,
        16,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx_u8,
        17,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx_u8,
        18,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx_u8,
        19,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        20,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx_u8,
        21,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx_u8,
        22,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpChks8_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8,
        23,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8,
        24,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpCtrlSts_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpCtrlSts_Can_Network_1_Channel_CAN_Rx_u8,
        25,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8,
        26,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpDegraded_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpDegraded_Can_Network_1_Channel_CAN_Rx_u8,
        27,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpQf_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpQf_Can_Network_1_Channel_CAN_Rx_u8,
        28,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkpSts_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpSts_Can_Network_1_Channel_CAN_Rx_u8,
        29,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADL3FuncCtrlStsForBkp_UB_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8,
        30,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqForBkpADActiveReq_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqForBkpADActiveReq_Can_Network_1_Channel_CAN_Rx_u8,
        31,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqForBkpADDeactiveReq_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqForBkpADDeactiveReq_Can_Network_1_Channel_CAN_Rx_u8,
        32,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8,
        33,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8,
        34,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8,
        35,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyADModeReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyADModeReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8,
        36,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatCoDrvReqForBkpAsyLatCoDrvR_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatCoDrvReqForBkpAsyLatCoDrvR_Can_Network_1_Channel_CAN_Rx_u8,
        37,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatCoDrvReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatCoDrvReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8,
        38,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatCoDrvReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatCoDrvReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8,
        39,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatCoDrvReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatCoDrvReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8,
        40,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatCoDrvReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatCoDrvReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8,
        41,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqForBkpAsyPinionAgR_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqForBkpAsyPinionAgR_Can_Network_1_Channel_CAN_Rx_u8,
        42,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8,
        43,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8,
        44,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8,
        45,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyPinionAgReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyPinionAgReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8,
        46,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx_u8,
        47,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatOvrdReqForBkpChks8_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatOvrdReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8,
        48,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatOvrdReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatOvrdReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8,
        49,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatOvrdReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatOvrdReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8,
        50,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyLatOvrdReqForBkp_UB_Can_Network_1_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyLatOvrdReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8,
        51,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SAS_RequestData_Can_Network_0_Channel_CAN_Rx_u8,
        52,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx_u8,
        53,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx_u8,
        54,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx_u8,
        55,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx_u8,
        56,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx_u8,
        57,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx_u8,
        58,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx_u8,
        59,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx_u8,
        60,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx_u8,
        61,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx_u8,
        62,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx_u8,
        63,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx_u8,
        64,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx_u8,
        65,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx_u8,
        66,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx_u8,
        67,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_NM_EIRA_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_NM_EIRA_Can_Network_0_Channel_CAN_Rx_u8,
        68,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx_u8,
        69,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_checksum_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_checksum_Can_Network_2_Channel_CAN_Rx_u8,
        70,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_counter_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_counter_Can_Network_2_Channel_CAN_Rx_u8,
        71,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_current1_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_current1_Can_Network_2_Channel_CAN_Rx_u8,
        72,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_current2_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_current2_Can_Network_2_Channel_CAN_Rx_u8,
        73,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_current3_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_current3_Can_Network_2_Channel_CAN_Rx_u8,
        74,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_current4_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_current4_Can_Network_2_Channel_CAN_Rx_u8,
        75,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_current5_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_current5_Can_Network_2_Channel_CAN_Rx_u8,
        76,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_sensor1_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_sensor1_Can_Network_2_Channel_CAN_Rx_u8,
        77,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_sensor2_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_sensor2_Can_Network_2_Channel_CAN_Rx_u8,
        78,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x4F_sensor3_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x4F_sensor3_Can_Network_2_Channel_CAN_Rx_u8,
        79,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx_u8,
        80,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x2F_command_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x2F_command_Can_Network_2_Channel_CAN_Rx_u8,
        81,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x2F_counter_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x2F_counter_Can_Network_2_Channel_CAN_Rx_u8,
        82,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_test_0x2F_current_Can_Network_2_Channel_CAN_Rx */
        &Com_Prv_RxSigS_test_0x2F_current_Can_Network_2_Channel_CAN_Rx_u8,
        83,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx_u8,
        84,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx_u8,
        85,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx_u8,
        86,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx_u8,
        87,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx_u8,
        88,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx_u8,
        89,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx_u8,
        90,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx_u8,
        91,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx_u8,
        92,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx_u8,
        93,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx_u8,
        94,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx_u8,
        95,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx_u8,
        96,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx_u8,
        97,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx_u8,
        98,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest0_Can_Network_0_Channel_CAN_Rx_u8,
        99,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest1_Can_Network_0_Channel_CAN_Rx_u8,
        100,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest2_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest2_Can_Network_0_Channel_CAN_Rx_u8,
        101,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest3_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest3_Can_Network_0_Channel_CAN_Rx_u8,
        102,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest4_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest4_Can_Network_0_Channel_CAN_Rx_u8,
        103,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest5_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest5_Can_Network_0_Channel_CAN_Rx_u8,
        104,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest6_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest6_Can_Network_0_Channel_CAN_Rx_u8,
        105,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TestModeRequest7_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TestModeRequest7_Can_Network_0_Channel_CAN_Rx_u8,
        106,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx_u8,
        107,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx_u8,
        108,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx_u8,
        109,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx_u8,
        110,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx_u8,
        111,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx_u8,
        112,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx_u8,
        113,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx_u8,
        114,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx_u8,
        115,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx_u8,
        116,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx_u8,
        117,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx_u8,
        118,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx_u8,
        119,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx_u8,
        120,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx_u8,
        121,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx_u8,
        122,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx_u8,
        123,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx_u8,
        124,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx_u8,
        125,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx_u8,
        126,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        127,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx_u8,
        128,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx_u8,
        129,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx_u8,
        130,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx_u8,
        131,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx_u8,
        132,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx_u8,
        133,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx_u8,
        134,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx_u8,
        135,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        136,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx_u8,
        137,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx_u8,
        138,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx_u8,
        139,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx_u8,
        140,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx_u8,
        141,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx_u8,
        142,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx_u8,
        143,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx_u8,
        144,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx_u8,
        145,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        146,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx_u8,
        147,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx_u8,
        148,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx_u8,
        149,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx_u8,
        150,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx_u8,
        151,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx_u8,
        152,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx_u8,
        153,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx_u8,
        154,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx_u8,
        155,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx_u8,
        156,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx_u8,
        157,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx_u8,
        158,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx_u8,
        159,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx_u8,
        160,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx_u8,
        161,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx_u8,
        162,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx_u8,
        163,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx_u8,
        164,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx_u8,
        165,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx_u8,
        166,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx_u8,
        167,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx_u8,
        168,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx_u8,
        169,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx_u8,
        170,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        171,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx_u8,
        172,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx_u8,
        173,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx_u8,
        174,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx_u8,
        175,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx_u8,
        176,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx_u8,
        177,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx_u8,
        178,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx_u8,
        179,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx_u8,
        180,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx_u8,
        181,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx_u8,
        182,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerSetgPen_Can_Network_0_Channel_CAN_Rx_u8,
        183,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx_u8,
        184,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx_u8,
        185,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx_u8,
        186,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx_u8,
        187,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx_u8,
        188,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx_u8,
        189,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx_u8,
        190,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        191,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx_u8,
        192,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx_u8,
        193,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx_u8,
        194,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx_u8,
        195,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx_u8,
        196,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx_u8,
        197,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx_u8,
        198,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx_u8,
        199,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx_u8,
        200,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx_u8,
        201,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx_u8,
        202,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx_u8,
        203,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx_u8,
        204,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx_u8,
        205,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx_u8,
        206,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx_u8,
        207,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_DrvModReq_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_DrvModReq_Can_Network_0_Channel_CAN_Rx_u8,
        208,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx_u8,
        209,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ULoWarnChks_Can_Network_0_Channel_CAN_Rx_u8,
        210,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx_u8,
        211,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx_u8,
        212,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx_u8,
        213,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_EscStChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_EscStChks_Can_Network_0_Channel_CAN_Rx_u8,
        214,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_EscStCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_EscStCntr_Can_Network_0_Channel_CAN_Rx_u8,
        215,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_EscStEscSt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_EscStEscSt_Can_Network_0_Channel_CAN_Rx_u8,
        216,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_EscSt_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_EscSt_UB_Can_Network_0_Channel_CAN_Rx_u8,
        217,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx_u8,
        218,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx_u8,
        219,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx_u8,
        220,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx_u8,
        221,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx_u8,
        222,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx_u8,
        223,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx_u8,
        224,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx_u8,
        225,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx_u8,
        226,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx_u8,
        227,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx_u8,
        228,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx_u8,
        229,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx_u8,
        230,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehMtnStChks_Can_Network_0_Channel_CAN_Rx_u8,
        231,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx_u8,
        232,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx_u8,
        233,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx_u8,
        234,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CarTiGlb_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CarTiGlb_Can_Network_0_Channel_CAN_Rx_u8,
        235,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx_u8,
        236,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ProfPenSts1_Can_Network_0_Channel_CAN_Rx_u8,
        237,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx_u8,
        238,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx_u8,
        239,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx_u8,
        240,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx_u8,
        241,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehBattUSysU_Can_Network_0_Channel_CAN_Rx_u8,
        242,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehBattU_UB_Can_Network_0_Channel_CAN_Rx_u8,
        243,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx_u8,
        244,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx_u8,
        245,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx_u8,
        246,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx_u8,
        247,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx_u8,
        248,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx_u8,
        249,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx_u8,
        250,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx_u8,
        251,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx_u8,
        252,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx_u8,
        253,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx_u8,
        254,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx_u8,
        255,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx_u8,
        256,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx_u8,
        257,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx_u8,
        258,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx_u8,
        259,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx_u8,
        260,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx_u8,
        261,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx_u8,
        262,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx_u8,
        263,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx_u8,
        264,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx_u8,
        265,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx_u8,
        266,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx_u8,
        267,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    ,
        
    {
        /* S_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx */
        &Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx_u8,
        268,            /*Handle Id*/
        /*
        {
            UpdBitConf:1;  = false
            Not_Used:7;
        }Com_RxSigGeneralType; */
        0x0       /*General*/
    }
    
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


#endif /* end of #ifdef COM_PRV_ENABLECONFIGINTERFACES */

/* END: Rx Signal Details  */





#ifdef COM_PRV_ENABLECONFIGINTERFACES

#endif /* end of #ifdef COM_PRV_ENABLECONFIGINTERFACES */







/* START: TMS Details  */


/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        1, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        1, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        5, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        5, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        10, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        10, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        10, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        10, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        10, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        10, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        15, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        15, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        25, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        25, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        400, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        400, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_CCP_Response_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_CCP_Response_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,      /* NumRepetitions */                
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,      /* NumRepetitions */                
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,      /* NumRepetitions */                
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"





/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,      /* NumRepetitions */                
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* IP_TestResponse_Can_Network_0_Channel_CAN_Tx has a TMS switch */
static const Com_TransModeInfo_tst Com_IP_TestResponse_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst[] =
{
    /* True Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */
    }
,
    /* False Mode configuration */
    {
        0, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,      /* NumRepetitions */                
#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_DIRECT, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_DIRECT /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* END: TMS Details  */











/* START: Tx IPDU Details  */

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_Prv_xTxIpduInfoCfg_tst Com_Prv_xTxIpduCfg_acst[COM_NUM_TX_IPDU] =
{
    {   /*Ipdu: IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx*/

        Com_dIP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        64                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        4,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PSCMTxCurrentAndCommand_0x2A_Com2PduR_Can_Network_2_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_test_0x2A_checksum_Can_Network_2_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx*/

        Com_dIP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        64                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        5,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        11,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PSCMTxCommonInfo_0x4A_Com2PduR_Can_Network_2_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_test_0x4A_FaultStatus_Can_Network_2_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx*/

        Com_dIP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        &Com_TxNotify_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        64                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        20,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PSCBHIPBCanFD7Frame01_Com2PduR_Can_Network_1_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_ADL3LatCtrlStsForCoDrvForBkpADMo_Can_Network_1_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_PscmChas1Fr01_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        &Rte_COMCbk_TxPdu_PscmChas1Fr01,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        18,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PscmChas1Fr01_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_ADL3LatCtrlStsADMod_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_PscmChas1Fr07_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        &Rte_COMCbk_TxPdu_PscmChas1Fr07,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        9,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PscmChas1Fr07_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_PinionSteerAgGroupChks_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_PscmChas1Fr02_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        &Rte_COMCbk_TxPdu_PscmChas1Fr02,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        15,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        10,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PscmChas1Fr02_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_LatCtrlModCfmdChks_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_PscmChas1Fr03_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        &Rte_COMCbk_TxPdu_PscmChas1Fr03,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        25,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        19,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PscmChas1Fr03_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_DrvrSteerWhlHldGroupDrvrSte_0000_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_PscmChas1Fr06_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        &Rte_COMCbk_TxPdu_PscmChas1Fr06,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        400,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        2,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PscmChas1Fr06_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_PinionSteerAgMax1_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_CCP_Response_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_CCP_Response_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_CCP_Response_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        0,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        1,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_CCP_Response_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_CCP_Res_Data_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        0,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        1,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_EPS_AngleCalibrateResponse_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_SAS_ResponseData_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_EPS_DebugMessage_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        0,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        4,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_EPS_DebugMessage_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_Debug_infor_1_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: IP_NM_VCU_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_NM_VCU_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        &Com_NONE_TransModeInfo_cst,

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        0,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        1,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_NM_VCU_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_NM_User_Data_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_INVALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = false
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1006,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_PscmDevelpFr_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        &Rte_COMCbk_TxPdu_PscmDevelpFr,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        0,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        8,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_PscmDevelpFr_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_PSCMdevelpsignalgroupresp1F_0000_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0x00               /*Padding Byte*/

    },
    {   /*Ipdu: IP_TestResponse_Can_Network_0_Channel_CAN_Tx*/

        Com_dIP_TestResponse_Can_Network_0_Channel_CAN_TxByte,              /*Pointer to the Ipdu Buffer*/

        Com_IP_TestResponse_Can_Network_0_Channel_CAN_Tx_TransModeInfo_acst,
        

        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif

        8                                      /*Size in Bytes*/,

        #ifdef COM_TxIPduTimeOut
        0,               /*Timeout Fact*/
        #endif
        0, /*MinDelay Time factor*/

        8,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        PduRConf_PduRSrcPdu_TestResponse_Com2PduR_Can_Network_0_Channel_CAN,              /* PduR Id */


        (Com_TxIntSignalId_tuo)ComSignal_Internal_S_TestModeResponse0_Can_Network_0_Channel_CAN_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif

        /*
        {
            Signal_Processing:1;          = IMMEDIATE
            TMSCalclation:2;              = MODE_VALID
            NoneModeTimeOut:1;            = COM_FALSE
            ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
            FilterEvalReq:1               = true
            IsDynPdu:1;                   = false
            IsGwDestPdu:1;                = false
            IsCalloutFrmTrigTrans:1;      = false
            isLargeDataPdu:1;             = false
            isCancelTransmitSupported:1;  = false
            ipduPartOfIpduGrp:1;          = true
            defaultTMSStatus:1;           = false
            Is_MetaDataPdu:1;             = false
            Not_Used:1;
        }Com_TxIpduFlagType;
        */
        0x1040,  /*Transmission Type*/


#if defined(COM_TxFilters) && defined(COM_IPDU_WITHOUT_IPDUGROUP_EXISTS)
        COM_MAX_TMS_COUNTER,                    /* Default TMS evaluation counter */
#endif
        
#ifdef COM_TX_IPDUCOUNTER
        COM_TXIPDU_CNTR_INV_IDX,      /* Index to TxIPduCounter */
#endif

        /* Com_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx,

        0xFF               /*Padding Byte*/

    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Tx IPDU Details  */

/* START : Time out information structure for signals with update-bits */
#ifdef COM_RxSigUpdateTimeout
#endif /* #ifdef COM_RxSigUpdateTimeout */
/* END : Time out information structure for signals with update-bits */

/* START : Time out information structure for signal groups with update-bits */
#ifdef COM_RxSigGrpUpdateTimeout
#endif /* #ifdef COM_RxSigGrpUpdateTimeout */
/* END : Time out information structure for signal groups with update-bits */



/* START: Rx IPDU Details  */

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


const Com_Prv_xRxIpduInfoCfg_tst Com_Prv_xRxIpduCfg_acst[COM_NUM_RX_IPDU] =
{
    {   /*Ipdu: IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_AsdmChas1Fr01,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        100,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        13,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_AsdmChas1Fr03,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        50,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_CCP_Request_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_CCP_Request_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0x8                 /* Reception Type */


    },
    {   /*Ipdu: IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx*/

        Com_dIP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        &ComNoti_Calback_0x1A0,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        64                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        25,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0x8                 /* Reception Type */


    },
    {   /*Ipdu: IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx*/

        Com_dIP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        &ComNoti_Calback_0x20,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        64                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0x8                 /* Reception Type */


    },
    {   /*Ipdu: IP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_EcmChas1Fr08_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_EcmChas1Fr08,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        250,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        7,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_EtcToPscmDevelFr,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        6                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_NM_EIRA_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx*/

        Com_dIP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        64                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        11,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0x8                 /* Reception Type */


    },
    {   /*Ipdu: IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx*/

        Com_dIP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        64                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0x8                 /* Reception Type */


    },
    {   /*Ipdu: IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_PasChas1Fr02_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_PasChas1Fr02,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        75,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        9,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_SasChas1Fr01_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_SasChas1Fr01,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        50,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        6,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_TestRequest_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_TestRequest_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VcuChas1Fr06_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VcuChas1Fr06,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        150,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VdcuIemChas1Fr01,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        50,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr01_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr01,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        50,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        9,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr03_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr03,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        75,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        9,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr04_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr04,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        100,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        10,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr05_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr05,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        100,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr10_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr10,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        50,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        13,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr14_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr14,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        150,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        7,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr19_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr19,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        350,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        11,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr22_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr22,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        850,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr24_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr24,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        100,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr30_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr30,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr33_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr33,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr41_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr41,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        600,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        6,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_DrvModReq_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr44_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr44,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        850,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_EscStChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr46_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr46,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        150,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        9,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr47_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr47,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        500,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr48_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr48,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        2100,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr49_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr49,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        400,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        6,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr50_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr50,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        2100,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        3,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr53_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr53,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        150,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        6,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr54_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr54,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        600,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        4,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_VddmChas1Fr55_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_VddmChas1Fr55,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        2500,        /* First time out value after IPDU group start */

        50,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        7,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    },
    {   /*Ipdu: IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx*/

        Com_dIP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_RxByte,              /*Pointer to the Local Ipdu Buffer*/
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        &Rte_COMCbk_RxPdu_ZcudChas1Fr02,
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,  /* Rx IPdu notification callback */
        #endif

        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Rx Ipdu Buffer */
        #endif

        8                                  /*Size in Bytes*/,

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /* Support Rx IPDU Timeout */
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/

        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalId_tuo)ComSignal_Internal_S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP
        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif

#ifdef COM_RX_IPDUCOUNTER
        COM_RXIPDU_CNTR_INV_IDX,      /* Index to RxIPduCounter */
#endif

        /* Com_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            ipduPartOfIpduGrp:1;  = true
            IS_TP_TYPE:1;         = false
            TP_INV_CFG:1;         = false
            Is_MetaDataPdu:1;     = false
            Not_Used:1;
        } Com_RxIpduFlagType;
        */
        0xA                 /* Reception Type */


    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Rx IPDU Details  */

#ifdef COM_PRV_ENABLECONFIGINTERFACES

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


const Com_RxIpduCfg_tst Com_RxIpduCfg_acst[COM_NUM_RX_IPDU] =
{
    {
        /*Ipdu: IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        13u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_CCP_Request_Can_Network_0_Channel_CAN_Rx*/

        1u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx*/

        25u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx*/

        5u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_Rx*/

        1u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx*/

        7u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_Rx*/

        1u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_NM_EIRA_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx*/

        11u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx*/

        9u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        6u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_TestRequest_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx*/

        9u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx*/

        9u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx*/

        10u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx*/

        5u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx*/

        13u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx*/

        7u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx*/

        11u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx*/

        5u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx*/

        6u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_DrvModReq_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_EscStChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx*/

        9u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx*/

        6u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx*/

        3u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx*/

        6u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx*/

        4u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx*/

        7u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    },
    {
        /*Ipdu: IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx*/

        8u,                /*No Of Signals present in the IPDU*/

        (uint16)ComSignal_Internal_S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx,   /*Index to First Signal within this Ipdu*/
        #ifdef COM_RX_SIGNALGROUP
        0u,           /*No of Signal Groups present in the IPDU*/

        0u,                            /*This IPDU does not contain any Signal Groups*/
        #endif
    }
};


/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


const Com_GlobalConfigType_tst Com_GlobalConfig_cst =
{
    (const Com_RxIpduCfg_tst *)               &Com_RxIpduCfg_acst[0],
    (const Com_RxSigConfigType_tst *)         &Com_Prv_RxSigCfg_acst[0],


    NULL_PTR,

    0u,
    0u,
    COM_NUM_RX_IPDU,
    COM_NUM_RX_SIGNALS    /* Total no.of ComRxSignals */
#ifdef COM_RX_SIGNALGROUP
    ,COM_NUM_RX_SIGNALGRP   /* Total no.of ComRxSignalGroups */
#endif
};


/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


#endif       /* end of #ifdef COM_PRV_ENABLECONFIGINTERFACES */



/* START: IPDU Group Details  */

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_Prv_xIpduGrpInfoCfg_tst Com_Prv_xIpduGrpCfg_acst[6] =
{
    /* "Index of First IPdu"               "No of Rx-Ipdus" */

    /* ComIPduGroup_NM_User_Data_Rx */
    { 0, 1 },
    /* ComIPduGroup_Rx */
    { 1, 20 },
    /* ComIPduGroup_Rx_PNC29 */
    { 21, 17 },
    /* ComIPduGroup_NM_User_Data_Tx */
    { 38, 0 },
    /* ComIPduGroup_Tx */
    { 39, 0 },
    /* ComIPduGroup_Tx_PNC29 */
    { 49, 0 }

};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/* END: IPDU Group Details  */


/* Reference to Ipdus belonging to the Ipdu Groups */

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


const Com_IpduId_tuo Com_Prv_xIPduGrp_IpduRefCfg_acuo[52] =
{

    /* ComIPduGroup_NM_User_Data_Rx */

    ComIPdu_Internal_IP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_Rx,
    /* ComIPduGroup_Rx */

    ComIPdu_Internal_IP_CCP_Request_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,
    ComIPdu_Internal_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,
    ComIPdu_Internal_IP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,
    ComIPdu_Internal_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx,
    ComIPdu_Internal_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,
    /* ComIPduGroup_Rx_PNC29 */

    ComIPdu_Internal_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,
    ComIPdu_Internal_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,
    /* ComIPduGroup_NM_User_Data_Tx */

    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_NM_VCU_Can_Network_0_Channel_CAN_Tx),
    /* ComIPduGroup_Tx */

    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_CCP_Response_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_TestResponse_Can_Network_0_Channel_CAN_Tx),
    /* ComIPduGroup_Tx_PNC29 */

    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx),
    (COM_NUM_RX_IPDU + (Com_IpduId_tuo)ComIPdu_Internal_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx)
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"








#ifdef COM_F_ONEEVERYN

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
const Com_OneEveryN_tst Com_OneEveryN_Const_acst[1] =
{
    /* Period   Offset  Occurence*/


    {    1,    5, 1    }    /*  DummyForMisra    */
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #ifdef COM_F_ONEEVERYN */


#if defined (COM_F_MASKEDNEWEQUALSX ) || defined(COM_F_MASKEDNEWDIFFERSX)

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_MaskX_tst Com_MaskX_acst[1] =
{
    /*Mask       X*/



    {    1,    5    }    /*  DummyForMisra    */
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


#endif /* #if defined (COM_F_MASKEDNEWEQUALSX ) || defined(COM_F_MASKEDNEWDIFFERSX) */

#ifdef COM_F_MASKEDNEWDIFFERSOLD

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_32
#include "Com_MemMap.h"

const uint32 Com_Mask_acu32[1] =
{
    /*Mask*/
    1    /* DummyForMisra */
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_32
#include "Com_MemMap.h"

#endif /* #ifdef COM_F_MASKEDNEWDIFFERSOLD */

#if defined (COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS)

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_POSMinMax_tst Com_POSMinMax_acst[16]=
{
    /*  Min      Max */



    /* Signals */
    
    {    0,    0    }    /*  S_CCP_Res_Data_Can_Network_0_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_Debug_infor_1_Can_Network_0_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_Debug_infor_2_Can_Network_0_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_Debug_infor_3_Can_Network_0_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_Debug_infor_4_Can_Network_0_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_SAS_ResponseData_Can_Network_0_Channel_CAN_Tx    */

    ,
    {    0,    65535    }    /*  S_test_0x2A_current_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_FaultStatus_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_current1_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_current2_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_current3_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_current4_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_current5_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_sensor1_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_sensor2_Can_Network_2_Channel_CAN_Tx    */

    ,
    {    0,    0    }    /*  S_test_0x4A_sensor3_Can_Network_2_Channel_CAN_Tx    */

    





};


/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #if defined (COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS) */

#if defined (COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG)

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_NEGMinMax_tst Com_NEGMinMax_acst[7] =
{
    /*  Min      Max */
    /* Signals */
    {    -32768,    32767    }    /*  S_FrntSteerFEstimd1_Can_Network_0_Channel_CAN_Tx    */
,    {    -14848,    14848    }    /*  S_PinionSteerAgGroupPinionSteerAg1_Can_Network_0_Channel_CAN_Tx    */
,    {    -6400,    6400    }    /*  S_PinionSteerAgGroupPinionSteerAgS_Can_Network_0_Channel_CAN_Tx    */
,    {    -7680,    7680    }    /*  S_PinionSteerAgGroupSteerWhlTq_Can_Network_0_Channel_CAN_Tx    */
,    {    -14848,    14848    }    /*  S_PinionSteerAgMax1_Can_Network_0_Channel_CAN_Tx    */
,    {    -7680,    7680    }    /*  S_SteerWhlTqAddl_Can_Network_0_Channel_CAN_Tx    */
,    {    -7680,    7680    }    /*  S_TqAssAddl_Can_Network_0_Channel_CAN_Tx    */


};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #if defined (COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG) */


/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

const Com_MainFunctionCfgType_tst Com_MainFunctionCfg_acst[ COM_NUM_OF_MAINFUNCTION ] =
{
    {
        /* Com_MainFunctionRx_ComMainFunctionRx() - cylce time Rx: 0.001 s */
        0u,  /* Start RxIPdu-Id */
        38u,  /* Num of RxIpdus */
        1u /* TimeBase in ms */
    },
    {
        /* Com_MainFunctionTx_ComMainFunctionTx() - cylce time Tx: 0.001 s */
        0u,  /* Start TxIPdu-Id */
        14u,  /* Num of TxIpdus */
        1u /* TimeBase in ms */
    }
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"






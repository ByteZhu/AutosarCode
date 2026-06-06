
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Com_Prv.h"
#include "Com_Prv_Inl.h"


#ifdef COM_RX_SIGNALGROUP
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
/*
 **********************************************************************************************************************
 Function name    : Com_ReceiveSignalGroup
 Description      : Service used to copy the SignalGroup content from IpduBuffer to Shadowbuffer
 Parameter        : idSignalGroup_u16 -> Id of the SignalGroup
 Return value     : E_OK/COM_SERVICE_NOT_AVAILABLE
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
uint8 Com_ReceiveSignalGroup(Com_SignalGroupIdType idSignalGroup_u16)
{

    Com_RxSigGrpCfg_tpcst           rxSigGrpConstPtr_pcst;
    uint8                           status_u8;

    status_u8 = COM_SERVICE_NOT_AVAILABLE;

# if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroup, COM_E_UNINIT);
    }
    else if (!Com_Prv_IsValidRxSignalGroupId(idSignalGroup_u16))
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroup, COM_E_PARAM);
    }
    else
# endif /* end of COM_PRV_ERROR_HANDLING */
    {
        /* If PB variant is selected, then PduId which is passed to this function will be changed
         * to internal Id which is generated through configuration
         * If PC variant is selected, then no mapping table will be used. */
        idSignalGroup_u16     = COM_GET_RXSIGNALGRP_ID(idSignalGroup_u16);

        rxSigGrpConstPtr_pcst = COM_GET_RXSIGGRP_CONSTDATA(idSignalGroup_u16);

        /* If IPDU Group is Started, then update the status variable */
        if(Com_Prv_CheckRxIPduStatus((PduIdType)(rxSigGrpConstPtr_pcst->idComIPdu_uo)))
        {
            status_u8 = E_OK;
        }

        Com_Prv_ReceiveSignalGroup(idSignalGroup_u16);

    }
    return (status_u8);
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/*
 **********************************************************************************************************************
 Function name    : Com_Prv_ReceiveSignalGroup
 Description      : Service used to copy the SignalGroup content from IpduBuffer to Shadowbuffer
 Parameter        : idSignalGroup_u16 -> Id of the SignalGroup
 Return value     : E_OK/COM_SERVICE_NOT_AVAILABLE
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Com_Prv_ReceiveSignalGroup(Com_SignalGroupIdType idSignalGroup_u16)
{
    Com_RxSigGrpCfg_tpcst           rxSigGrpConstPtr_pcst;
    Com_RxGrpSigCfg_tpcst           rxGrpSigConstPtr_pcst;
    uint16_least                    idxRxGrpSig_qu16;
    Com_IpduId_tuo                  idRxIpdu_uo;
    Com_RxGrpSigBuffIndex_tuo       idxRxGrpSignalBuff_uo;
    uint8                           sigType_u8;
    Com_MainFunc_tuo                idRxMainFunc_uo;

    rxSigGrpConstPtr_pcst = COM_GET_RXSIGGRP_CONSTDATA(idSignalGroup_u16);
    rxGrpSigConstPtr_pcst = COM_GET_RXGRPSIG_CONSTDATA(rxSigGrpConstPtr_pcst->idFirstGrpSig_uo);

    idRxIpdu_uo = rxSigGrpConstPtr_pcst->idComIPdu_uo;

    /* Fetch the Rx-MainFunction internal Id */
    idRxMainFunc_uo       = (COM_GET_RX_IPDU_CONSTDATA(idRxIpdu_uo))->idMainFunc_uo;

    /* Lock the interrupts because second buffer could be updated by interrupt
     * in function Com_RxIndication()
     */
    /* The complete copy operation from the second buffer to primary buffer should be
     * interrupt safe,this is because, the whole signal group should be copied atomically
     * As the lock is around the loop for all the group signals the Interrupt locking time can vary depending on configuration
     */
    SchM_Enter_Com_RxGrpSigSecBuff();

    for (idxRxGrpSig_qu16 = rxSigGrpConstPtr_pcst->numOfGrpSig_uo; idxRxGrpSig_qu16 != COM_ZERO; idxRxGrpSig_qu16--)
    {
        sigType_u8 = Com_GetValue(RXGRPSIG,_TYPE,rxGrpSigConstPtr_pcst->rxGrpSigFields_u8);
        idxRxGrpSignalBuff_uo = rxGrpSigConstPtr_pcst->idxRxGrpSigBuff_uo;

        switch(sigType_u8 >> 1u)
        {
            case 0x00u: /* COM_UINT8, COM_SINT8 */
            case 0x03u: /* COM_BOOLEAN          */
            {
                COM_GET_RXGRPSIGTYPEUINT8_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo) =
                        COM_GET_SECRXGRPSIGTYPEU8_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo);
            }
            break;

            case 0x01u: /* COM_UINT16, COM_SINT16 */
            {
                COM_GET_RXGRPSIGTYPEUINT16_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo) =
                        COM_GET_SECRXGRPSIGTYPEU16_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo);
            }
            break;

            case 0x02u: /* COM_UINT32, COM_SINT32 */
        /* FC_VariationPoint_START */
#ifdef COM_GRPSIGFLOAT32SUPP
            case (COM_FLOAT32 >> 1u): /* FLOAT32 signal */
#endif
        /* FC_VariationPoint_END */
            {
                COM_GET_RXGRPSIGTYPEUINT32_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo) =
                        COM_GET_SECRXGRPSIGTYPEU32_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo);
            }
            break;

#ifdef COM_RXGRPSIG_INT64
            case 0x08u: /* COM_UINT64, COM_SINT64 */
            {
                SchM_Enter_Com_RxGrpSigBuff();
                COM_GET_RXGRPSIGTYPEUINT64_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo) =
                        COM_GET_SECRXGRPSIGTYPEU64_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo);
                SchM_Exit_Com_RxGrpSigBuff();
            }
            break;
#endif /* #ifdef COM_RXGRPSIG_INT64 */

/* FC_VariationPoint_START */
#ifdef COM_RXGRPSIG_FLOAT64SUPP
            case (COM_FLOAT64 >> 1u):
            {
                /* FLOAT64 signal */
                SchM_Enter_Com_RxGrpSigBuff();
                COM_GET_RXGRPSIGTYPEFLOAT64_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo) =
                        COM_GET_SECRXGRPSIGTYPEFLOAT64_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo);
                SchM_Exit_Com_RxGrpSigBuff();
            }
            break;
#endif
/* FC_VariationPoint_END */

            case 0x04u:
            {
                /* UINT8_N signal */
                SchM_Enter_Com_RxGrpSigBuff();
                Com_ByteCopy(&COM_GET_RXGRPSIGTYPEUINT8_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo),
                        &COM_GET_SECRXGRPSIGTYPEU8_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo),
                        rxGrpSigConstPtr_pcst->bitSize_uo);
                SchM_Exit_Com_RxGrpSigBuff();
            }
            break;

#ifdef COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT
            case (COM_UINT8_DYN >> 1u):
            {
                uint16 dynLength_u16;

                SchM_Enter_Com_RxGrpSigBuff();

                dynLength_u16 = COM_GET_RXPDURAM_S(idRxIpdu_uo).dynSigLength_u16;

                Com_ByteCopy(&COM_GET_RXGRPSIGTYPEUINT8DYN_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo),
                        &COM_GET_SECRXGRPSIGTYPEUINT8DYN_BUFF(idRxMainFunc_uo,idxRxGrpSignalBuff_uo),
                        dynLength_u16);

                COM_GET_RXPDURAM_S(idRxIpdu_uo).dynRxGrpSigLength_u16 = dynLength_u16;

                SchM_Enter_Com_RxGrpSigBuff();
            }
            break;
#endif

            default:
            {
                /**
                 * Default case is mandatory in switch syntax. Moreover only AUTOSAR Com defined signal types are allowed
                 * to be configured, hence default case is intentionally left empty.
                 */
            }
            break;
        }

        rxGrpSigConstPtr_pcst++;
    }
    /* TRACE[SWS_Com_00461] The AUTOSAR COM module shall always copy the last known data, or
     * the ComSignalInitValue(s) if not yet written, of the I-PDU to the shadow buffer by a call to
     * Com_ReceiveSignalGroup() even if the I-PDU is stopped and COM_SERVICE_NOT_AVAILABLE is returned. */
    SchM_Exit_Com_RxGrpSigSecBuff();
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/**********************************************************************************************************************
 Function name    : Com_Prv_SigGrpReplaceToInit
 Description      : If the SigGrp is enabled with ArrayAccess, RxSigGrpBuffer will be packed with
                    GroupSignal Init Values OR else
                    GroupSignals Shadow buffers will be replaced with its Init Values
 Parameter        : rxSigGrpConstPtr_pcst   - pointer to RxSignalGroup configuration
                  : idRxMainFunc_uo         - Internally generated RxMainFunction-ID
 Return value     : None
 *********************************************************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_Prv_SigGrpReplaceToInit(Com_RxSigGrpCfg_tpcst rxSigGrpConstPtr_pcst, Com_MainFunc_tuo idRxMainFunc_uo)
{
    Com_RxGrpSigCfg_tpcst               rxGrpSigConstPtr_pcst;
# ifdef COM_RX_SIGNALGROUP_ARRAY
    Com_RxSigGrpArrayCfg_tpcst          rxSigGrpArrayConstPtr_pcst;
    uint8 *                             rxSigGrpArrayBufRamPtr_pu8;
    Com_Bitposition_tuo                 sigGrpBitOffset_uo;
# endif
    uint16_least                        idxRxGrpSig_qu16;
    Com_SigMax_tuo                      sigValue_uo;
    uint8                               sigType_u8;
# ifdef COM_RX_SIGNALGROUP_ARRAY
    boolean                             isSigGrpArrayAccess_b;

    isSigGrpArrayAccess_b = Com_GetValue(RXSIGGRP,_ARRAYACCESS,rxSigGrpConstPtr_pcst->rxSignalGrpFields_u8);

    if ( isSigGrpArrayAccess_b )
    {
        rxSigGrpArrayConstPtr_pcst  = COM_GET_RXSIGGRP_ARRAY_CONSTDATA( rxSigGrpConstPtr_pcst->idxSigGrpArray_uo );

        rxSigGrpArrayBufRamPtr_pu8 = &COM_GET_RXSIGGRP_ARRAY_BUFF(idRxMainFunc_uo, rxSigGrpArrayConstPtr_pcst->idxRxSigGrpBuf_uo );

        sigGrpBitOffset_uo        = (((Com_Bitposition_tuo)rxSigGrpArrayConstPtr_pcst->firstByteNo_uo) * 8u );

        Com_Get_SchM_Enter_Com_RxSigGrpArrayBuff
    }
    else
# endif /* # ifdef COM_RX_SIGNALGROUP_ARRAY */
    {
        Com_Get_SchM_Enter_Com_RxGrpSigSecBuff
    }

    rxGrpSigConstPtr_pcst = COM_GET_RXGRPSIG_CONSTDATA( rxSigGrpConstPtr_pcst->idFirstGrpSig_uo );

    for ( idxRxGrpSig_qu16 = rxSigGrpConstPtr_pcst->numOfGrpSig_uo; idxRxGrpSig_qu16 > COM_ZERO; idxRxGrpSig_qu16-- )
    {
        sigType_u8 = Com_GetValue(RXGRPSIG,_TYPE,rxGrpSigConstPtr_pcst->rxGrpSigFields_u8);

        sigValue_uo = Com_Prv_GetRxGrpSigInitValue(rxGrpSigConstPtr_pcst);

# ifdef COM_RX_SIGNALGROUP_ARRAY
        if ( isSigGrpArrayAccess_b )
        {
            Com_Bitposition_tuo relativeSigBitPos_uo; /* Relative BitPosition in RxSignalGroup Array */
            uint8 sigEndianess_u8;

            /* The Buffer into which Signal Values needs to be packed will be available with starting address
             * of the Rx-SignalGroup Array Buffer.
             * But we have GroupSignal: Bit_Pos, i.e., Signal's actual LSB in the IPdu Buffer.
             * So, Rx-SignalGroup BitOffset(sigGrpBitOffset_uo) is removed from each of the GroupSignal and
             * is used as BitPosition to pack its value into the Rx-SignalGroup Array Buffer */
            relativeSigBitPos_uo = rxGrpSigConstPtr_pcst->bitPos_uo - ( Com_Bitposition_tuo )sigGrpBitOffset_uo;

            /* COM_UINT8_DYN is not handled here, as it cannot be configured in Rx-ComSignalGroup-with-ArrayAccess */

            sigEndianess_u8 = Com_GetValue(RXGRPSIG,_ENDIANESS,rxGrpSigConstPtr_pcst->rxGrpSigFields_u8);

            switch (sigType_u8)
            {
                case COM_UINT8_N:
                {
                    PduLengthType byteOffset_uo;
                    /* Find the starting byte position(ByteNo_uo) of Signal in signal group buffer */
                    byteOffset_uo = ( PduLengthType )( relativeSigBitPos_uo >> 3 );

                    /* MR12 DIR 1.1 VIOLATION: "Cast from a pointer to object type to a pointer to void". As below mem-copy is
                     * optimized operation to copy data, so, type cast warning is ignored here */
                    COM_MEMCOPY(
                            (rxSigGrpArrayBufRamPtr_pu8 + byteOffset_uo),
                            COM_GET_BYTE_ARRAY_SIG_VAL(sigValue_uo).sigByteArray_pau8,
                            rxGrpSigConstPtr_pcst->bitSize_uo
                               );

                }
                break;
#ifdef COM_RXGRPSIG_FLOAT64SUPP
                case COM_FLOAT64:
                {
                    /* Convert the float value into 32 bit stream and then pack the value */
                    Com_Prv_PackFloatSignal( sigEndianess_u8, relativeSigBitPos_uo,
                                             Com_getfloat64SigValue(sigValue_uo), rxSigGrpArrayBufRamPtr_pu8 );
                }
                break;
#endif /* end of COM_RXGRPSIG_FLOAT64SUPP */
                default:
                {
#ifdef COM_RXGRPSIG_INT64
                    if (COM_SIG_IS_INT64_TYPE(sigType_u8))
                    {
                        sigValue_uo = (Com_SigMax_tuo)(COM_GET_INT64_SIG_VALUE(sigValue_uo));
                    }
                    else
#endif /* end of COM_RXSIG_INT64 */
                    {
#ifdef  COM_INITVALOPTIMIZATION
                        sigValue_uo = COM_GET_UNIQUE_INIT_VALUE_CONSTDATA(sigValue_uo);
#endif
                    }

                    /* Pack the signal with Initial Value */
                    Com_Prv_PackSignal( sigEndianess_u8, relativeSigBitPos_uo, rxGrpSigConstPtr_pcst->bitSize_uo,
                                        sigValue_uo, rxSigGrpArrayBufRamPtr_pu8 );
                }
                break;
            } /* end of switch() */
        }
        else
# endif /* #ifdef COM_RX_SIGNALGROUP_ARRAY */
        {
            switch (sigType_u8)
            {
                case COM_UINT8_N:
                {
                    /* MR12 DIR 1.1 VIOLATION: "Cast from a pointer to object type to a pointer to void". As below mem-copy is
                     * optimized operation to copy data, so, type cast warning is ignored here */
                    COM_MEMCOPY(
                        &COM_GET_SECRXGRPSIGTYPEU8_BUFF(idRxMainFunc_uo,rxGrpSigConstPtr_pcst->idxRxGrpSigBuff_uo),
                        COM_GET_BYTE_ARRAY_SIG_VAL(sigValue_uo).sigByteArray_pau8,
                        rxGrpSigConstPtr_pcst->bitSize_uo
                               );

                }
                break;
# ifdef COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT
                case COM_UINT8_DYN:
                {
                    PduLengthType dynLength_uo;
                    dynLength_uo = COM_GET_BYTE_ARRAY_SIG_VAL(sigValue_uo).sigLength_uo;

                    /* MR12 DIR 1.1 VIOLATION: "Cast from a pointer to object type to a pointer to void". As below mem-copy is
                     * optimized operation to copy data, so, type cast warning is ignored here */
                    COM_MEMCOPY(
                        &COM_GET_SECRXGRPSIGTYPEUINT8DYN_BUFF(idRxMainFunc_uo,rxGrpSigConstPtr_pcst->idxRxGrpSigBuff_uo),
                        COM_GET_BYTE_ARRAY_SIG_VAL(sigValue_uo).sigByteArray_pau8, dynLength_uo
                               );

                    COM_GET_RXPDURAM_S(rxSigGrpConstPtr_pcst->idComIPdu_uo).dynSigLength_u16 = (uint16)dynLength_uo;
                }
                break;
# endif /* end of COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT */
# ifdef COM_RXGRPSIG_FLOAT64SUPP
                case COM_FLOAT64:
                {
                    COM_GET_SECRXGRPSIGTYPEFLOAT64_BUFF(idRxMainFunc_uo,rxGrpSigConstPtr_pcst->idxRxGrpSigBuff_uo) =
                                                                          Com_getfloat64SigValue(sigValue_uo);
                }
                break;
# endif /* end of COM_RXGRPSIG_FLOAT64SUPP */
                default:
                {
# ifdef COM_RXGRPSIG_INT64
                    if (COM_SIG_IS_INT64_TYPE(sigType_u8))
                    {
                        sigValue_uo = (Com_SigMax_tuo)(COM_GET_INT64_SIG_VALUE(sigValue_uo));
                    }
                    else
# endif /* end of COM_RXGRPSIG_INT64 */
                    {
# ifdef  COM_INITVALOPTIMIZATION
                        sigValue_uo = COM_GET_UNIQUE_INIT_VALUE_CONSTDATA(sigValue_uo);
# endif
                    }

                    Com_Prv_UpdateRxGroupSignalSecondBuffer(rxGrpSigConstPtr_pcst, sigValue_uo, idRxMainFunc_uo);
                }
                break;
            }
        }

# if defined(COM_RxFilters) && defined(COM_F_MASKEDNEWDIFFERSOLD)
        /* TRACE[SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the filtering mechanisms
         * for each signal to the ComSignalInitValue during start-up */
        if ( ( COM_INIT != Com_InitStatus_en ) &&
             ( COM_MASKED_NEW_DIFFERS_MASKED_OLD == rxGrpSigConstPtr_pcst->filterAlgo_u8 ) )
        {
            COM_GET_F_OLDVALUE(rxGrpSigConstPtr_pcst->idxFilter_uo) = (uint32)sigValue_uo;
        }
# endif /* # if defined(COM_RxFilters) && defined(COM_F_MASKEDNEWDIFFERSOLD) */

        rxGrpSigConstPtr_pcst++;
    }
# ifdef COM_RX_SIGNALGROUP_ARRAY

    if ( isSigGrpArrayAccess_b )
    {
        Com_Get_SchM_Exit_Com_RxSigGrpArrayBuff
    }
    else
# endif /* # ifdef COM_RX_SIGNALGROUP_ARRAY */
    {
        Com_Get_SchM_Exit_Com_RxGrpSigSecBuff
    }
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* #ifdef COM_RX_SIGNALGROUP */


/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef SECOC_PDURIF_H
#define SECOC_PDURIF_H

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

extern Std_ReturnType SecOC_IfTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);
extern Std_ReturnType SecOC_TpTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);

extern void SecOC_TxConfirmation(PduIdType TxPduId, Std_ReturnType result);
extern void SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result);

extern Std_ReturnType SecOC_IfCancelTransmit(PduIdType TxPduId);
extern Std_ReturnType SecOC_TpCancelTransmit(PduIdType TxPduId);

extern void SecOC_TpRxIndication(PduIdType id, Std_ReturnType result);
extern void SecOC_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr);

extern BufReq_ReturnType SecOC_StartOfReception(PduIdType id, const PduInfoType* info, PduLengthType TpSduLength,
                                                PduLengthType* bufferSizePtr);

extern BufReq_ReturnType SecOC_CopyRxData(PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr);

extern Std_ReturnType SecOC_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr);
extern BufReq_ReturnType SecOC_CopyTxData(PduIdType id, const PduInfoType* info, RetryInfoType* retry,
                                          PduLengthType* availableDataPtr);
extern Std_ReturnType SecOC_TpCancelReceive(PduIdType RxPduId);


#endif /* SECOC_PDURIF_H */

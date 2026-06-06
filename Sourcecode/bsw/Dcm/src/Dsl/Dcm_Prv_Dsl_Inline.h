

#ifndef DCM_PRV_DSL_INLINE_H
#define DCM_PRV_DSL_INLINE_H


LOCAL_INLINE PduIdType Dcm_Prv_GetTxPduIdFromTxIndex(PduIdType DcmTxPduIndex)
{
    if (DcmTxPduIndex < DCM_CFG_INVALID_TX_PDUINDEX)
    {
        return Dcm_TxTable_cast[DcmTxPduIndex];
    }
    else
    {
        return Dcm_TxTable_cast[DCM_CFG_INVALID_TX_PDUINDEX];
    }
}


#endif

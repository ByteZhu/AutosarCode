
#ifndef DCM_DSL_PAGEDBUFFER_H
#define DCM_DSL_PAGEDBUFFER_H

/*
 * ********************************************************************************************************************
 * Included header files
 **********************************************************************************************************************
 */

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
extern void Dcm_Prv_Set_RemainingPageLength(PduLengthType RemainingPageLen);
extern void Dcm_Prv_Get_RemainingPageLength(PduLengthType *RemainingPageLen);
#endif

#endif

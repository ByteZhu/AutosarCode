#ifndef _ASW_DEM_COMDIAG_H
#define _ASW_DEM_COMDIAG_H

#include "Com.h"

/* Fault deal type */
typedef enum
{
    FAULT_SET,
    FAULT_CLEAR
}FaultDeal_t;


/* DTC C12182 related */
typedef uint16 DTC_C12182_FaultListType;
#define DTC_C12182_FAULT_VehSpdLgt_UB          ((uint16) 1 << 0)
#define DTC_C12182_FAULT_LatCtrlReqSafe_UB     ((uint16) 1 << 1)
#define DTC_C12182_FAULT_AbsCtrlActv_UB        ((uint16) 1 << 2)
#define DTC_C12182_FAULT_WhlSpdCircumlFrnt_UB  ((uint16) 1 << 3)
#define DTC_C12182_FAULT_WhlSpdCircumlRe_UB    ((uint16) 1 << 4)
#define DTC_C12182_FAULT_BrkPedlPsd_UB         ((uint16) 1 << 5)
#define DTC_C12182_FAULT_Msg_E0_Missing        ((uint16) 1 << 6)
#define DTC_C12182_FAULT_Msg_190_Missing       ((uint16) 1 << 7)
#define DTC_C12182_FAULT_Msg_1B1_Missing       ((uint16) 1 << 8)
#define DTC_C12182_FAULT_Msg_1B7_Missing       ((uint16) 1 << 9)
#define DTC_C12182_FAULT_MASK                  ((uint16) 0x3ff)

/* DTC C15182 related */
typedef uint16 DTC_C15182_FaultListType;
#define DTC_C15182_FAULT_AgDataRawSafe_UB  ((uint16) 1 << 0)
#define DTC_C15182_FAULT_Msg_1B0_Missing   ((uint16) 1 << 1)
#define DTC_C15182_FAULT_MASK              ((uint16) 0x3)

/* DTC C15982 related */
typedef uint16 DTC_C15982_FaultListType;
#define DTC_C15982_FAULT_PrkgPinionAgReqGroup_UB  ((uint16) 1 << 0)
#define DTC_C15982_FAULT_Msg_EB_Missing           ((uint16) 1 << 1)
#define DTC_C15982_FAULT_MASK                     ((uint16) 0x3)

/* DTC C16882 related */
typedef uint16 DTC_C16882_FaultListType;
#define DTC_C16882_FAULT_AsyPinionAgReqSafe_UB  ((uint16) 1 << 0)
#define DTC_C16882_FAULT_AgCtrlTqLowrLim_UB     ((uint16) 1 << 1)
#define DTC_C16882_FAULT_AgCtrlTqUpprLim_UB     ((uint16) 1 << 2)
#define DTC_C16882_FAULT_Msg_33_Missing         ((uint16) 1 << 3)
#define DTC_C16882_FAULT_MASK                   ((uint16) 0xf)

/* DTC C29682 related */
typedef uint16 DTC_C29682_FaultListType;
#define DTC_C29682_FAULT_CrabMovModSts_UB  ((uint16) 1 << 0)
#define DTC_C29682_FAULT_Msg_5B_Missing    ((uint16) 1 << 1)
#define DTC_C29682_FAULT_MASK              ((uint16) 0x3)

/* DTC D10382 related */
typedef uint16 DTC_D10382_FaultListType;
#define DTC_D10382_FAULT_VehSpdLgt_UB          ((uint16) 1 << 0)
#define DTC_D10382_FAULT_LatCtrlReqSafe_UB     ((uint16) 1 << 1)
#define DTC_D10382_FAULT_AbsCtrlActv_UB        ((uint16) 1 << 2)
#define DTC_D10382_FAULT_WhlSpdCircumlFrnt_UB  ((uint16) 1 << 3)
#define DTC_D10382_FAULT_WhlSpdCircumlRe_UB    ((uint16) 1 << 4)
#define DTC_D10382_FAULT_BrkPedlPsd_UB         ((uint16) 1 << 5)
#define DTC_D10382_FAULT_Msg_E0_Missing        ((uint16) 1 << 6)
#define DTC_D10382_FAULT_Msg_190_Missing       ((uint16) 1 << 7)
#define DTC_D10382_FAULT_Msg_1B1_Missing       ((uint16) 1 << 8)
#define DTC_D10382_FAULT_Msg_1B7_Missing       ((uint16) 1 << 9)
#define DTC_D10382_FAULT_MASK                  ((uint16) 0x3ff)

/* DTC D44D82 related */
typedef uint16 DTC_D44D82_FaultListType;
#define DTC_D44D82_FAULT_DrvModReq_UB     ((uint16) 1 << 0)
#define DTC_D44D82_FAULT_SteerSetg_UB     ((uint16) 1 << 1)
#define DTC_D44D82_FAULT_Msg_2AE_Missing  ((uint16) 1 << 2)
#define DTC_D44D82_FAULT_Msg_463_Missing  ((uint16) 1 << 3)
#define DTC_D44D82_FAULT_MASK             ((uint16) 0xf)

/* DTC E71883 related */
typedef uint16 DTC_E71883_FaultListType;
#define DTC_E71883_FAULT_VehMtnSt_E2E  ((uint16) 1 << 0)
#define DTC_E71883_FAULT_MASK          ((uint16) 0x1)

/* DTC E72783 related */
typedef uint16 DTC_E72783_FaultListType;
#define DTC_E72783_FAULT_AsyPinionAgReqSafeAsyPinionAgReq_E2E  ((uint16) 1 << 0)
#define DTC_E72783_FAULT_MASK                                  ((uint16) 0x1)

/* DTC E7B182 related */
typedef uint16 DTC_E7B182_FaultListType;
#define DTC_E7B182_FAULT_UturnTrqRels_UB  ((uint16) 1 << 0)
#define DTC_E7B182_FAULT_Msg_EB_Missing   ((uint16) 1 << 1)
#define DTC_E7B182_FAULT_MASK             ((uint16) 0x3)

/* DTC E7B283 related */
typedef uint16 DTC_E7B283_FaultListType;
#define DTC_E7B283_FAULT_PrkgPinionAgReqGroup_E2E  ((uint16) 1 << 0)
#define DTC_E7B283_FAULT_UturnTrqRels_E2E          ((uint16) 1 << 1)
#define DTC_E7B283_FAULT_MASK                      ((uint16) 0x3)

/* DTC E7B383 related */
typedef uint16 DTC_E7B383_FaultListType;
#define DTC_E7B383_FAULT_CrabMovModSts_E2E  ((uint16) 1 << 0)
#define DTC_E7B383_FAULT_MASK               ((uint16) 0x1)

/* DTC ED3283 related */
typedef uint16 DTC_ED3283_FaultListType;
#define DTC_ED3283_FAULT_BrkPedlPsd_E2E         ((uint16) 1 << 0)
#define DTC_ED3283_FAULT_WhlSpdCircumlRe_E2E    ((uint16) 1 << 1)
#define DTC_ED3283_FAULT_WhlSpdCircumlFrnt_E2E  ((uint16) 1 << 2)
#define DTC_ED3283_FAULT_MASK                   ((uint16) 0x7)

/* DTC ED3383 related */
typedef uint16 DTC_ED3383_FaultListType;
#define DTC_ED3383_FAULT_LatCtrlReqSafe_E2E  ((uint16) 1 << 0)
#define DTC_ED3383_FAULT_AbsCtrlActv_E2E     ((uint16) 1 << 1)
#define DTC_ED3383_FAULT_MASK                ((uint16) 0x3)

/* DTC ED3683 related */
typedef uint16 DTC_ED3683_FaultListType;
#define DTC_ED3683_FAULT_VehSpdLgt_E2E  ((uint16) 1 << 0)
#define DTC_ED3683_FAULT_MASK           ((uint16) 0x1)

/* DTC ED3983 related */
typedef uint16 DTC_ED3983_FaultListType;
#define DTC_ED3983_FAULT_AgDataRawSafe_E2E  ((uint16) 1 << 0)
#define DTC_ED3983_FAULT_MASK               ((uint16) 0x1)

/* DTC ED4183 related */
typedef uint16 DTC_ED4183_FaultListType;
#define DTC_ED4183_FAULT_PrkgPinionAgReqGroup_E2E  ((uint16) 1 << 0)
#define DTC_ED4183_FAULT_MASK                      ((uint16) 0x1)

/* DTC ED5A83 related */
typedef uint16 DTC_ED5A83_FaultListType;
#define DTC_ED5A83_FAULT_VehModMngtGlbSafe1_E2E  ((uint16) 1 << 0)
#define DTC_ED5A83_FAULT_MASK                    ((uint16) 0x1)

/* DTC ED7983 related */
typedef uint16 DTC_ED7983_FaultListType;
#define DTC_ED7983_FAULT_PtTqAtWhlFrntAct_E2E  ((uint16) 1 << 0)
#define DTC_ED7983_FAULT_MASK                  ((uint16) 0x1)

/* DTC ED9683 related */
typedef uint16 DTC_ED9683_FaultListType;
#define DTC_ED9683_FAULT_AbsCtrActv_E2E  ((uint16) 1 << 0)
#define DTC_ED9683_FAULT_MASK            ((uint16) 0x1)


/* Function declaration */

void ComDiag_DealFault_C12182(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_C15182(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_C15982(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_C16882(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_C29682(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_D10382(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_D44D82(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_E71883(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_E72783(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_E7B182(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_E7B283(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_E7B383(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED3283(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED3383(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED3683(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED3983(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED4183(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED5A83(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED7983(uint16 fault, FaultDeal_t type);
void ComDiag_DealFault_ED9683(uint16 fault, FaultDeal_t type);

#endif // _ASW_DEM_COMDIAG_H
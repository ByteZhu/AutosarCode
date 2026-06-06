/*
 * This is Ioc.h, auto-generated for:
 *   Project: Os_Config
 *   Target:  TriCoreTasking
 *   Variant: TC36x
 *   Version: 5.0.21
 *   [$UKS 1359] [$UKS 1334] [$UKS 1454]
 */
#ifndef OS_IOC_H
#define OS_IOC_H
/* -- Start expansion of <OsIoc.h> -- */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, IocRead*, IocWrite*, IocSend*, IocRec*) */
#include "Rte_Type.h"

#define IOC_E_OK        RTE_E_OK         /* [$UKS 1360] */
#define IOC_E_NOK       RTE_E_NOK        /* [$UKS 1361] */
#define IOC_E_LIMIT     RTE_E_LIMIT      /* [$UKS 1362] */
#define IOC_E_LOST_DATA RTE_E_LOST_DATA  /* [$UKS 1363] */
#define IOC_E_NO_DATA   RTE_E_NO_DATA    /* [$UKS 1364] */

/* IOC internal data */

typedef struct {
  Os_Lockable Os_IocLock_Rte_Rx_000223;
  Os_Lockable Os_IocLock_Rte_Rx_000226;
} Os_IocLockDataType;
typedef struct {
  uint32 Os_IocCF_0_0;
  uint32 Os_IocCF_1_0;
} Os_IocCbkDataType;


/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_CALLOUT_CODE) Rte_ReceiverPullCB_Rte_Rx_000223_0(void);
extern FUNC(void, OS_CALLOUT_CODE) Rte_ReceiverPullCB_Rte_Rx_000226_0(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_Rte_Rx_000223(const SRInterface_CoreCrossMsg_impl *value); /* Only callable from: OsApplication_Core1 (Trusted on core 1) */
extern FUNC(Std_ReturnType, OS_CODE) IocRead_Rte_Rx_000223_0(SRInterface_CoreCrossMsg_impl *value); /* Only callable from: OsApplication_Core0 (Trusted on core 0) */
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_Rte_Rx_000226(const SRInterface_CoreCrossMsg_impl *value); /* Only callable from: OsApplication_Core0 (Trusted on core 0) */
extern FUNC(Std_ReturnType, OS_CODE) IocRead_Rte_Rx_000226_0(SRInterface_CoreCrossMsg_impl *value); /* Only callable from: OsApplication_Core1 (Trusted on core 1) */
extern FUNC(void, OS_CODE) Os_ioc_memcpy(void *dest, const void *source, uint32 length);
extern FUNC(void, OS_CODE) Os_ioc_memclr(void *dest, uint32 length);
extern FUNC(void, OS_CODE) IocInit(void); /* [$UKS 2223] */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern VAR(SRInterface_CoreCrossMsg_impl, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000223;
extern VAR(SRInterface_CoreCrossMsg_impl, OS_VAR_NO_INIT) Os_Ioc_Rte_Rx_000226;
extern OS_VOLATILE VAR(Os_Lockable, OS_VAR_NO_INIT) Os_lock_iocaccess;
extern VAR(Os_IocLockDataType, OS_VAR_NO_INIT) Os_IocLockData;
extern VAR(Os_IocCbkDataType, OS_VAR_NO_INIT) Os_IocCbkData;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */

/* -- End expansion of <OsIoc.h> -- */
#endif /* OS_IOC_H */

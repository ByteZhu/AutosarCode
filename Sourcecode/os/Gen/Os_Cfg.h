/*
 * This is Os_Cfg.h, auto-generated for:
 *   Project: Os_Config
 *   Target:  TriCoreTasking
 *   Variant: TC36x
 *   Version: 5.0.21
 *   [$UKS 650]
 */
#ifndef OS_CFG_H
#define OS_CFG_H
/*
 * Note that only documented OS APIs are considered to be public.
 * Functions and data in OS header files that are not documented should not be used in
 * non-OS code.
 */
/* -- Start expansion of <Os_Safe_Cfg.h> -- */
/* -- Start expansion of <Os_Target_Cfg.h> -- */
#define OS_TARGET_TRICORETASKING
#define OS_TRICORE_UNTRUSTED_MASK OS_UNTRUSTED_TMASK
#define OS_TRICORE_TRUSTEDWITHPROTECTION_MASK OS_TWP_TMASK
#define OS_ISRVEC_SENTSR0_ISR (19U)
#define OS_CCPN_SENTSR0_ISR (19U)
#define OS_TABLE_SENTSR0_ISR (0U)
#define OS_ISRVEC_SENTSR1_ISR (20U)
#define OS_CCPN_SENTSR1_ISR (20U)
#define OS_TABLE_SENTSR1_ISR (0U)
#define OS_ISRVEC_SENTSR2_ISR (21U)
#define OS_CCPN_SENTSR2_ISR (21U)
#define OS_TABLE_SENTSR2_ISR (0U)
#define OS_ISRVEC_SENTSR8_ISR (22U)
#define OS_CCPN_SENTSR8_ISR (22U)
#define OS_TABLE_SENTSR8_ISR (0U)
#define OS_ISRVEC_USER_ISR (23U)
#define OS_CCPN_USER_ISR (23U)
#define OS_TABLE_USER_ISR (0U)

#define OS_ISRVEC_DefaultInterruptHandler (24U)
#define OS_CCPN_DefaultInterruptHandler (255U)
#define OS_TABLE_DefaultInterruptHandler (0U)
#define OS_INIT_SRC_GPSR01 (0x1401U)
#define OS_INIT_SRC_GPSR00 (0x401U)
#define OS_INIT_SRC_CAN0INT0 (0x402U)
#define OS_INIT_SRC_CAN0INT1 (0x403U)
#define OS_INIT_SRC_CAN0INT2 (0x404U)
#define OS_INIT_SRC_CAN0INT3 (0x405U)
#define OS_INIT_SRC_CAN0INT4 (0x406U)
#define OS_INIT_SRC_CAN0INT5 (0x407U)
#define OS_INIT_SRC_CAN0INT6 (0x408U)
#define OS_INIT_SRC_CAN0INT7 (0x409U)
#define OS_INIT_SRC_CAN0INT8 (0x40aU)
#define OS_INIT_SRC_CAN0INT9 (0x40bU)
#define OS_INIT_SRC_CAN0INT10 (0x40cU)
#define OS_INIT_SRC_CAN0INT11 (0x40dU)
#define OS_INIT_SRC_CAN1INT12 (0x40eU)
#define OS_INIT_SRC_CAN1INT13 (0x40fU)
#define OS_INIT_SRC_CAN1INT14 (0x410U)
#define OS_INIT_SRC_CAN1INT15 (0x411U)
#define OS_INIT_SRC_STM0SR0 (0x412U)
#define OS_INIT_SRC_SENT0 (0x413U)
#define OS_INIT_SRC_SENT1 (0x414U)
#define OS_INIT_SRC_SENT2 (0x415U)
#define OS_INIT_SRC_SENT8 (0x416U)
#define OS_INIT_SRC_GTMTOM17 (0x417U)
#define OS_VEC_Os_CrossCoreISR1 (1U)
#define OS_CORE_Os_CrossCoreISR1 (1U)
#define OS_BISR_Os_CrossCoreISR1 (1U)
#define OS_VEC_Os_CrossCoreISR0 (1U)
#define OS_CORE_Os_CrossCoreISR0 (0U)
#define OS_BISR_Os_CrossCoreISR0 (1U)
#define OS_VEC_CAN0SR0_ISR (2U)
#define OS_CORE_CAN0SR0_ISR (0U)
#define OS_BISR_CAN0SR0_ISR (2U)
#define OS_VEC_CAN0SR1_ISR (3U)
#define OS_CORE_CAN0SR1_ISR (0U)
#define OS_BISR_CAN0SR1_ISR (3U)
#define OS_VEC_CAN0SR2_ISR (4U)
#define OS_CORE_CAN0SR2_ISR (0U)
#define OS_BISR_CAN0SR2_ISR (4U)
#define OS_VEC_CAN0SR3_ISR (5U)
#define OS_CORE_CAN0SR3_ISR (0U)
#define OS_BISR_CAN0SR3_ISR (5U)
#define OS_VEC_CAN0SR4_ISR (6U)
#define OS_CORE_CAN0SR4_ISR (0U)
#define OS_BISR_CAN0SR4_ISR (6U)
#define OS_VEC_CAN0SR5_ISR (7U)
#define OS_CORE_CAN0SR5_ISR (0U)
#define OS_BISR_CAN0SR5_ISR (7U)
#define OS_VEC_CAN0SR6_ISR (8U)
#define OS_CORE_CAN0SR6_ISR (0U)
#define OS_BISR_CAN0SR6_ISR (8U)
#define OS_VEC_CAN0SR7_ISR (9U)
#define OS_CORE_CAN0SR7_ISR (0U)
#define OS_BISR_CAN0SR7_ISR (9U)
#define OS_VEC_CAN0SR8_ISR (10U)
#define OS_CORE_CAN0SR8_ISR (0U)
#define OS_BISR_CAN0SR8_ISR (10U)
#define OS_VEC_CAN0SR9_ISR (11U)
#define OS_CORE_CAN0SR9_ISR (0U)
#define OS_BISR_CAN0SR9_ISR (11U)
#define OS_VEC_CAN0SR10_ISR (12U)
#define OS_CORE_CAN0SR10_ISR (0U)
#define OS_BISR_CAN0SR10_ISR (12U)
#define OS_VEC_CAN0SR11_ISR (13U)
#define OS_CORE_CAN0SR11_ISR (0U)
#define OS_BISR_CAN0SR11_ISR (13U)
#define OS_VEC_CAN1SR12_ISR (14U)
#define OS_CORE_CAN1SR12_ISR (0U)
#define OS_BISR_CAN1SR12_ISR (14U)
#define OS_VEC_CAN1SR13_ISR (15U)
#define OS_CORE_CAN1SR13_ISR (0U)
#define OS_BISR_CAN1SR13_ISR (15U)
#define OS_VEC_CAN1SR14_ISR (16U)
#define OS_CORE_CAN1SR14_ISR (0U)
#define OS_BISR_CAN1SR14_ISR (16U)
#define OS_VEC_CAN1SR15_ISR (17U)
#define OS_CORE_CAN1SR15_ISR (0U)
#define OS_BISR_CAN1SR15_ISR (17U)
#define OS_VEC_Millisecond (18U)
#define OS_CORE_Millisecond (0U)
#define OS_BISR_Millisecond (18U)
#define OS_VEC_SENTSR0_ISR (19U)
#define OS_CORE_SENTSR0_ISR (0U)
#define OS_BISR_SENTSR0_ISR (19U)
#define OS_VEC_SENTSR1_ISR (20U)
#define OS_CORE_SENTSR1_ISR (0U)
#define OS_BISR_SENTSR1_ISR (20U)
#define OS_VEC_SENTSR2_ISR (21U)
#define OS_CORE_SENTSR2_ISR (0U)
#define OS_BISR_SENTSR2_ISR (21U)
#define OS_VEC_SENTSR8_ISR (22U)
#define OS_CORE_SENTSR8_ISR (0U)
#define OS_BISR_SENTSR8_ISR (22U)
#define OS_VEC_USER_ISR (23U)
#define OS_CORE_USER_ISR (0U)
#define OS_BISR_USER_ISR (23U)
#define OS_Core0_SRN (SRC_GPSR00)
#define OS_Core1_SRN (SRC_GPSR01)
#define OS_NUM_SRNS (463U)

#define OS_CAT1_ID_DefaultInterruptHandler ((uint32)INVALID_ISR)
#define OS_CAT1_ID_SENTSR0_ISR (1U)
#define OS_CAT1_ID_SENTSR1_ISR (2U)
#define OS_CAT1_ID_SENTSR2_ISR (3U)
#define OS_CAT1_ID_SENTSR8_ISR (4U)
#define OS_CAT1_ID_USER_ISR (5U)

extern void SENTSR0_ISR(void);
extern void SENTSR1_ISR(void);
extern void SENTSR2_ISR(void);
extern void SENTSR8_ISR(void);
extern void USER_ISR(void);
extern void DefaultInterruptHandler(void);

/* -- End expansion of <Os_Target_Cfg.h> -- */
#define OS_NUM_APPMODES (2U)
#define OS_NUM_APPLICATIONS (2U)
#define OS_NUM_SPINLOCKS (0U)
#define OS_NUM_TRUSTED_FUNCTIONS (2U)
#define OS_NUM_IOC_CALLBACK_FUNCTIONS (Os_const_ioc_function_count)
#define OS_NUM_EVENTS (0U)
#define OS_NUM_TASKS (19U)
#define OS_NUM_ISRS (17U)
#define OS_NUM_RESOURCES (4U)
#define OS_NUM_ALARMS (0U)
#define OS_NUM_SCHEDULETABLES (1U)
#define OS_NUM_PERIPHERALAREAS (0U)
#define OS_NUM_TRACEPOINTS (2U)
#define OS_NUM_TASKTRACEPOINTS (0U)
#define OS_NUM_INTERVALS (0U)
#define OS_NUM_TRACECATEGORIES (0U)
#define OS_TRACE_CATEGORY_ALWAYS ((Os_TraceCategoriesType)(0x80000000UL))
#define OS_TRACE_CATEGORY_NEVER  ((Os_TraceCategoriesType)(0x00000000UL))
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_TICKS2*) */
#define OS_NUM_COUNTERS (1U)
#define OSCYCLEDURATION (5) /* [$UKS 1224] */
#define OSCYCLESPERSECOND (200000000U) /* [$UKS 1225] */
#define OSSWTICKDURATION (10) /* [$UKS 1226] */
#define OSSWTICKSPERSECOND (100000000U) /* [$UKS 1227] */
#define OS_TICKS2NS_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1000000U)) /* [$UKS 843] */
#define OS_TICKS2US_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1000U)) /* [$UKS 843] */
#define OS_TICKS2MS_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1U)) /* [$UKS 843] */
#define OS_TICKS2SEC_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) / 1000U)) /* [$UKS 843] */
#define OSMAXALLOWEDVALUE_Rte_TickCounter (65535U) /* [$UKS 219] */
#define OSTICKSPERBASE_Rte_TickCounter (1U) /* [$UKS 220] */
#define OSTICKDURATION_Rte_TickCounter OS_TICKS2NS_Rte_TickCounter(1U) /* [$UKS 221] */
#define OSMINCYCLE_Rte_TickCounter (1U) /* [$UKS 222] */
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_SystemCounter /* [$UKS 215] */
#define OSTICKSPERBASE OSTICKSPERBASE_SystemCounter /* [$UKS 216] */
#define OSMINCYCLE OSMINCYCLE_SystemCounter /* [$UKS 218] */
#define OSTICKDURATION OSTICKDURATION_SystemCounter /* [$UKS 217] */
#define OS_NUM_CORES (2U)
#define OS_NUM_OS_CORES (2U)
#define OS_CORE_ID_MASTER (0U)  /* [$UKS 1609] */
/* [$UKS 1611] */
#define OS_CORE_ID_0 (0U)
#define OS_CORE_ID_1 (1U)

/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_CALLOUT_CODE) ErrorHook_OsApplication_Core0(StatusType Error) /* [$UKS 450] */;
extern FUNC(void, OS_CALLOUT_CODE) ErrorHook_OsApplication_Core1(StatusType Error) /* [$UKS 450] */;
extern FUNC(TickType, OS_CALLOUT_CODE) Os_Cbk_Now_Rte_TickCounter(void);
extern FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Set_Rte_TickCounter(TickType Match);
extern FUNC(void, OS_CALLOUT_CODE) Os_Cbk_State_Rte_TickCounter(Os_CounterStatusRefType State);
extern FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Cancel_Rte_TickCounter(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_CODE) TRUSTED_IOC_Rte_ReceiverPullCB_Rte_Rx_000223_0(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams) /* [$UKS 1268] */;
extern FUNC(void, OS_CODE) TRUSTED_IOC_Rte_ReceiverPullCB_Rte_Rx_000226_0(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams) /* [$UKS 1268] */;
extern FUNC(StatusType, OS_CODE) Os_AdvanceCounter_Rte_TickCounter(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_Background_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_ASW_5ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_BSW_5ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_ASW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_BSW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_ASW_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_BSW_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_BSW_100ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_BSW_50ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_ASW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_BSW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_ASW_2ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_ASW_5ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_BSW_5ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_ASW_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_OsTask_BSW_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_BSW_OsTask_SwcRequest(void);
extern FUNC(void, OS_CODE) Os_Entry_Core0_ECU_StartupTask(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_ECU_StartupTask(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR0_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR2_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR3_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR4_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR5_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR6_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR7_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR8_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR9_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR10_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN0SR11_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN1SR12_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN1SR13_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN1SR14_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_CAN1SR15_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_Millisecond(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */

/* -- End expansion of <Os_Safe_Cfg.h> -- */
/* -------- Stack Monitoring --------- */
#define OS_STACK_MONITORING  /* [$UKS 954] */

/* -------- AppMode declarations --------- */

/* ----- OS-Application declarations ----- */
#define OsApplication_Core0 ((ApplicationType)0U) /* [$UKS 412] */
#define OsApplication_Core1 ((ApplicationType)1U) /* [$UKS 412] */

/* ----- Trusted function declarations ----- */
#define IOC_Rte_ReceiverPullCB_Rte_Rx_000223_0 ((TrustedFunctionIndexType)0U) /* [$UKS 969] */
#define IOC_Rte_ReceiverPullCB_Rte_Rx_000226_0 ((TrustedFunctionIndexType)1U) /* [$UKS 969] */

/* ----- PeripheralArea declarations ----- */

/* ----- Spinlock declarations ----- */

/* -------- Event declarations --------- */

/* -------- Task declarations --------- */
#define Core0_OsTask_Background_1ms (&Os_const_tasks0[0])
#define OS_CORE_FOR_Core0_OsTask_Background_1ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_Background_1ms (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_Background_1ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_Background_1ms (0U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_Background_1ms)
#define Core1_OsTask_ASW_5ms (&Os_const_tasks1[0])
#define OS_CORE_FOR_Core1_OsTask_ASW_5ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_ASW_5ms (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_ASW_5ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_OsTask_ASW_5ms (1U) /* [$UKS 2185] */
DeclareTask(Core1_OsTask_ASW_5ms)
#define Core1_OsTask_BSW_5ms (&Os_const_tasks1[1])
#define OS_CORE_FOR_Core1_OsTask_BSW_5ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_BSW_5ms (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_BSW_5ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_OsTask_BSW_5ms (2U) /* [$UKS 2185] */
DeclareTask(Core1_OsTask_BSW_5ms)
#define Core1_OsTask_ASW_10ms (&Os_const_tasks1[2])
#define OS_CORE_FOR_Core1_OsTask_ASW_10ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_ASW_10ms (2U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_ASW_10ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_OsTask_ASW_10ms (3U) /* [$UKS 2185] */
DeclareTask(Core1_OsTask_ASW_10ms)
#define Core1_OsTask_BSW_10ms (&Os_const_tasks1[3])
#define OS_CORE_FOR_Core1_OsTask_BSW_10ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_BSW_10ms (3U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_BSW_10ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_OsTask_BSW_10ms (4U) /* [$UKS 2185] */
DeclareTask(Core1_OsTask_BSW_10ms)
#define Core1_OsTask_ASW_1ms (&Os_const_tasks1[4])
#define OS_CORE_FOR_Core1_OsTask_ASW_1ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_ASW_1ms (4U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_ASW_1ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_OsTask_ASW_1ms (5U) /* [$UKS 2185] */
DeclareTask(Core1_OsTask_ASW_1ms)
#define Core1_OsTask_BSW_1ms (&Os_const_tasks1[5])
#define OS_CORE_FOR_Core1_OsTask_BSW_1ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_BSW_1ms (5U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_BSW_1ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_OsTask_BSW_1ms (6U) /* [$UKS 2185] */
DeclareTask(Core1_OsTask_BSW_1ms)
#define Core0_OsTask_BSW_100ms (&Os_const_tasks0[1])
#define OS_CORE_FOR_Core0_OsTask_BSW_100ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_BSW_100ms (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_BSW_100ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_BSW_100ms (7U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_BSW_100ms)
#define Core0_OsTask_BSW_50ms (&Os_const_tasks0[2])
#define OS_CORE_FOR_Core0_OsTask_BSW_50ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_BSW_50ms (2U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_BSW_50ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_BSW_50ms (8U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_BSW_50ms)
#define Core0_OsTask_ASW_10ms (&Os_const_tasks0[3])
#define OS_CORE_FOR_Core0_OsTask_ASW_10ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_ASW_10ms (3U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_ASW_10ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_ASW_10ms (9U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_ASW_10ms)
#define Core0_OsTask_BSW_10ms (&Os_const_tasks0[4])
#define OS_CORE_FOR_Core0_OsTask_BSW_10ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_BSW_10ms (4U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_BSW_10ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_BSW_10ms (10U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_BSW_10ms)
#define Core0_OsTask_ASW_2ms (&Os_const_tasks0[5])
#define OS_CORE_FOR_Core0_OsTask_ASW_2ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_ASW_2ms (5U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_ASW_2ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_ASW_2ms (11U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_ASW_2ms)
#define Core0_OsTask_ASW_5ms (&Os_const_tasks0[6])
#define OS_CORE_FOR_Core0_OsTask_ASW_5ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_ASW_5ms (6U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_ASW_5ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_ASW_5ms (12U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_ASW_5ms)
#define Core0_OsTask_BSW_5ms (&Os_const_tasks0[7])
#define OS_CORE_FOR_Core0_OsTask_BSW_5ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_BSW_5ms (7U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_BSW_5ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_BSW_5ms (13U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_BSW_5ms)
#define Core0_OsTask_ASW_1ms (&Os_const_tasks0[8])
#define OS_CORE_FOR_Core0_OsTask_ASW_1ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_ASW_1ms (8U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_ASW_1ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_ASW_1ms (14U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_ASW_1ms)
#define Core0_OsTask_BSW_1ms (&Os_const_tasks0[9])
#define OS_CORE_FOR_Core0_OsTask_BSW_1ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_OsTask_BSW_1ms (9U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_OsTask_BSW_1ms (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_OsTask_BSW_1ms (15U) /* [$UKS 2185] */
DeclareTask(Core0_OsTask_BSW_1ms)
#define Core0_BSW_OsTask_SwcRequest (&Os_const_tasks0[10])
#define OS_CORE_FOR_Core0_BSW_OsTask_SwcRequest (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_BSW_OsTask_SwcRequest (10U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_BSW_OsTask_SwcRequest (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_BSW_OsTask_SwcRequest (16U) /* [$UKS 2185] */
DeclareTask(Core0_BSW_OsTask_SwcRequest)
#define Core0_ECU_StartupTask (&Os_const_tasks0[11])
#define OS_CORE_FOR_Core0_ECU_StartupTask (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core0_ECU_StartupTask (11U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core0_ECU_StartupTask (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core0_ECU_StartupTask (17U) /* [$UKS 2185] */
DeclareTask(Core0_ECU_StartupTask)
#define Core1_ECU_StartupTask (&Os_const_tasks1[6])
#define OS_CORE_FOR_Core1_ECU_StartupTask (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_ECU_StartupTask (6U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_ECU_StartupTask (0x8000U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Core1_ECU_StartupTask (18U) /* [$UKS 2185] */
DeclareTask(Core1_ECU_StartupTask)
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_TPL_FOR_TASK, OS_IMASK_FOR_TASK) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_TPL_FOR_TASK) */
#define OS_TPL_FOR_TASK(n) OS_TPL_FOR_##n  /* [$UKS 2008] */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_IMASK_FOR_TASK) */
#define OS_IMASK_FOR_TASK(n) OS_IMASK_FOR_##n  /* [$UKS 2010] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_CORE_FOR_TASK) */
#define OS_CORE_FOR_TASK(t) (t)->core_id /* [$UKS 1921] */

/* -------- ISR declarations --------- */
#define CAN0SR0_ISR (&Os_const_isrs[0U])
#define OS_IMASK_FOR_CAN0SR0_ISR (0x8002U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR0_ISR (0U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR0_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR0_ISR)
#define CAN0SR1_ISR (&Os_const_isrs[1U])
#define OS_IMASK_FOR_CAN0SR1_ISR (0x8003U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR1_ISR (1U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR1_ISR)
#define CAN0SR2_ISR (&Os_const_isrs[2U])
#define OS_IMASK_FOR_CAN0SR2_ISR (0x8004U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR2_ISR (2U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR2_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR2_ISR)
#define CAN0SR3_ISR (&Os_const_isrs[3U])
#define OS_IMASK_FOR_CAN0SR3_ISR (0x8005U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR3_ISR (3U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR3_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR3_ISR)
#define CAN0SR4_ISR (&Os_const_isrs[4U])
#define OS_IMASK_FOR_CAN0SR4_ISR (0x8006U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR4_ISR (4U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR4_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR4_ISR)
#define CAN0SR5_ISR (&Os_const_isrs[5U])
#define OS_IMASK_FOR_CAN0SR5_ISR (0x8007U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR5_ISR (5U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR5_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR5_ISR)
#define CAN0SR6_ISR (&Os_const_isrs[6U])
#define OS_IMASK_FOR_CAN0SR6_ISR (0x8008U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR6_ISR (6U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR6_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR6_ISR)
#define CAN0SR7_ISR (&Os_const_isrs[7U])
#define OS_IMASK_FOR_CAN0SR7_ISR (0x8009U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR7_ISR (7U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR7_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR7_ISR)
#define CAN0SR8_ISR (&Os_const_isrs[8U])
#define OS_IMASK_FOR_CAN0SR8_ISR (0x800AU) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR8_ISR (8U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR8_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR8_ISR)
#define CAN0SR9_ISR (&Os_const_isrs[9U])
#define OS_IMASK_FOR_CAN0SR9_ISR (0x800BU) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR9_ISR (9U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR9_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR9_ISR)
#define CAN0SR10_ISR (&Os_const_isrs[10U])
#define OS_IMASK_FOR_CAN0SR10_ISR (0x800CU) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR10_ISR (10U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR10_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR10_ISR)
#define CAN0SR11_ISR (&Os_const_isrs[11U])
#define OS_IMASK_FOR_CAN0SR11_ISR (0x800DU) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN0SR11_ISR (11U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN0SR11_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN0SR11_ISR)
#define CAN1SR12_ISR (&Os_const_isrs[12U])
#define OS_IMASK_FOR_CAN1SR12_ISR (0x800EU) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN1SR12_ISR (12U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN1SR12_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN1SR12_ISR)
#define CAN1SR13_ISR (&Os_const_isrs[13U])
#define OS_IMASK_FOR_CAN1SR13_ISR (0x800FU) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN1SR13_ISR (13U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN1SR13_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN1SR13_ISR)
#define CAN1SR14_ISR (&Os_const_isrs[14U])
#define OS_IMASK_FOR_CAN1SR14_ISR (0x8010U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN1SR14_ISR (14U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN1SR14_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN1SR14_ISR)
#define CAN1SR15_ISR (&Os_const_isrs[15U])
#define OS_IMASK_FOR_CAN1SR15_ISR (0x8011U) /* [$UKS 2009] */
#define OS_INDEX_FOR_CAN1SR15_ISR (15U) /* [$UKS 2186] */
#define OS_CORE_FOR_CAN1SR15_ISR (0U) /* [$UKS 1909] */
DeclareISR(CAN1SR15_ISR)
#define Millisecond (&Os_const_isrs[16U])
#define OS_IMASK_FOR_Millisecond (0x8012U) /* [$UKS 2009] */
#define OS_INDEX_FOR_Millisecond (16U) /* [$UKS 2186] */
#define OS_CORE_FOR_Millisecond (0U) /* [$UKS 1909] */
DeclareISR(Millisecond)
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_CORE_FOR_ISR) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_CORE_FOR_ISR) */
#define OS_CORE_FOR_ISR(i) OS_CORE_FOR_##i /* [$UKS 1922] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_IMASK_FOR_ISR) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_IMASK_FOR_ISR) */
#define OS_IMASK_FOR_ISR(n) OS_IMASK_FOR_##n  /* [$UKS 2011] */

/* -------- Resource declarations --------- */
#define RTE_RESOURCE_OS_APP_OsApplication_Core1 (&Os_const_resources[0U])
DeclareResource(RTE_RESOURCE_OS_APP_OsApplication_Core1)
#define RTE_RESOURCE_OS_APP_OsApplication_Core0 (&Os_const_resources[1U])
DeclareResource(RTE_RESOURCE_OS_APP_OsApplication_Core0)
#define Os_Core0_RES_SCHEDULER (&Os_const_resources[2U])
DeclareResource(Os_Core0_RES_SCHEDULER)
#define Os_Core1_RES_SCHEDULER (&Os_const_resources[3U])
DeclareResource(Os_Core1_RES_SCHEDULER)
#define RES_SCHEDULER (Os_const_coreconfiguration[GetCoreID()].Os_Res_Scheduler)

/* -------- Counter declarations --------- */
#define Rte_TickCounter (&Os_const_counters[0U])
DeclareCounter(Rte_TickCounter)

/* -------- Alarm declaration --------- */

/* -------- ScheduleTable declaration --------- */
#define Rte_ScheduleTable (&Os_const_scheduletables[0U])
#define OS_DURATION_Rte_ScheduleTable (100U)
DeclareScheduleTable(Rte_ScheduleTable)

/* -------- Tracepoint declarations --------- */
#define OSApp_OsApplication_Core0 (1U)
#define OSApp_OsApplication_Core1 (2U)

/* -------- TaskTracepoint declarations --------- */

/* -------- Interval declarations --------- */

/* -------- Filtered APIs --------- */
#define Os_LogTracepoint(TpointID,Category) /* never */
#define Os_LogTracepointValue(TpointID,Value,Category) /* never */
#define Os_LogTracepointData(TpointID,Data,Length,Category) /* never */
#define Os_LogTaskTracepoint(TTpointID,Category) /* never */
#define Os_LogTaskTracepointValue(TTpointID,Value,Category) /* never */
#define Os_LogTaskTracepointData(TTpointID,Data,Length,Category) /* never */
#define Os_LogIntervalStart(IntervalID,Category) /* never */
#define Os_LogIntervalStartValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalStartData(IntervalID,Data,Length,Category) /* never */
#define Os_LogIntervalEnd(IntervalID,Category) /* never */
#define Os_LogIntervalEndValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalEndData(IntervalID,Data,Length,Category) /* never */
#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, LogTrace*, LogTaskTrace*, LogInterval*) */  #define LogTracepoint(TpointID,Category) Os_LogTracepoint(TpointID,Category)
  #define LogTracepointValue(TpointID,Value,Category) Os_LogTracepointValue(TpointID,Value,Category)
  #define LogTracepointData(TpointID,Data,Length,Category) Os_LogTracepointData(TpointID,Data,Length,Category)
  #define LogTaskTracepoint(TTpointID,Category) Os_LogTaskTracepoint(TTpointID,Category)
  #define LogTaskTracepointValue(TTpointID,Value,Category) Os_LogTaskTracepointValue(TTpointID,Value,Category)
  #define LogTaskTracepointData(TTpointID,Data,Length,Category) Os_LogTaskTracepointData(TTpointID,Data,Length,Category)
  #define LogIntervalStart(IntervalID,Category) Os_LogIntervalStart(IntervalID,Category)
  #define LogIntervalStartValue(IntervalID,Value,Category) Os_LogIntervalStartValue(IntervalID,Value,Category)
  #define LogIntervalStartData(IntervalID,Data,Length,Category) Os_LogIntervalStartData(IntervalID,Data,Length,Category)
  #define LogIntervalEnd(IntervalID,Category) Os_LogIntervalEnd(IntervalID,Category)
  #define LogIntervalEndValue(IntervalID,Value,Category) Os_LogIntervalEndValue(IntervalID,Value,Category)
  #define LogIntervalEndData(IntervalID,Data,Length,Category) Os_LogIntervalEndData(IntervalID,Data,Length,Category)
#endif

#define OS_IMASK_FOR_SENTSR0_ISR (0x8013U) /* [$UKS 2009] */
#define Os_Cat1_SENTSR0_ISR (38U)
#define OS_CORE_FOR_SENTSR0_ISR (0U) /* [$UKS 1909] */
#define OS_IMASK_FOR_SENTSR1_ISR (0x8014U) /* [$UKS 2009] */
#define Os_Cat1_SENTSR1_ISR (39U)
#define OS_CORE_FOR_SENTSR1_ISR (0U) /* [$UKS 1909] */
#define OS_IMASK_FOR_SENTSR2_ISR (0x8015U) /* [$UKS 2009] */
#define Os_Cat1_SENTSR2_ISR (40U)
#define OS_CORE_FOR_SENTSR2_ISR (0U) /* [$UKS 1909] */
#define OS_IMASK_FOR_SENTSR8_ISR (0x8016U) /* [$UKS 2009] */
#define Os_Cat1_SENTSR8_ISR (41U)
#define OS_CORE_FOR_SENTSR8_ISR (0U) /* [$UKS 1909] */
#define OS_IMASK_FOR_USER_ISR (0x8017U) /* [$UKS 2009] */
#define Os_Cat1_USER_ISR (42U)
#define OS_CORE_FOR_USER_ISR (0U) /* [$UKS 1909] */
/* [MISRA 2012 Rule 1.3] */ /*lint -estring(9023, Os_LogCat1ISRStart) */
/* [MISRA 2012 Rule 20.10] */ /*lint -esym(9024, Os_LogCat1ISRStart) */
#define Os_LogCat1ISRStart(IsrId)  /* [$UKS 1036] [$UKS 1037] [$UKS 1177] */
/* [MISRA 2012 Rule 1.3] */ /*lint -estring(9023, Os_LogCat1ISREnd) */
/* [MISRA 2012 Rule 20.10] */ /*lint -esym(9024, Os_LogCat1ISREnd) */
#define Os_LogCat1ISREnd(IsrId)  /* [$UKS 1038] [$UKS 1039] [$UKS 1178] */

#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
  #define LogCat1ISRStart Os_LogCat1ISRStart
  #define LogCat1ISREnd Os_LogCat1ISREnd
#endif
#endif /* OS_CFG_H */

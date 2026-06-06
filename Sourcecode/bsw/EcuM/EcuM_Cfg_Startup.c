


/*
 **************************************************************************************************
 * Includes
 **************************************************************************************************
 */

#include "EcuM.h" /*BSW_HeaderInc_002*/

#include "EcuM_Callout.h"
#include "EcuM_RunTime.h" /*For run time measurement*/

/*Extern module Headers*/
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
#include "Os.h" /* required for Core Id Check */
// #if (!defined(OS_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MAJOR_VERSION != 4))
// #error "AUTOSAR major version undefined or mismatched"
// #endif
// #if (!defined(OS_AR_RELEASE_MINOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != 2))
// #error "AUTOSAR minor version undefined or mismatched"
// #endif
#endif/*ECUM_CFG_MULTICORE_ENABLED */


    
 #if (ECUM_INCLUDE_DET == STD_ON)
    #include "Det.h"
 #endif

 #include "Dem.h"

 #include "Mcu.h"

 #include "McuFunc.h"

 #include "VectorTable_Core0.h"

 #include "Fls.h"

 #include "Port.h"

 #include "EcuM_User.h"

 #include "VectorTable_Core1.h"

 #include "CDD_CORE0.h"

 #include "Can_17_McmCan.h"

 #include "Smu.h"


#include "EcuM_Cfg_Startup.h"

#include "Wdg_17_Scu.h"

#include "Spi.h"

#include "Sent.h"

#include "CDD_TPS653852A.h"

#include "CDD_TCAN1145.h"
/*EcuM Private headers*/
#include "EcuM_Prv.h"

#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/

#define ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_MemMap.h"

/*To store the start and End time EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/

static EcuM_TimeTicks_tu64 EcuM_DriverInitZero_begin_ticks_u64;
static EcuM_TimeTicks_tu64 EcuM_DriverInitZero_end_ticks_u64;

            

static EcuM_TimeTicks_tu64 EcuM_DriverInitOne_begin_ticks_SlaveCore0_u64;
static EcuM_TimeTicks_tu64 EcuM_DriverInitOne_end_ticks_SlaveCore0_u64;

            

static EcuM_TimeTicks_tu64 EcuM_DriverInitOne_begin_ticks_SlaveCore1_u64;
static EcuM_TimeTicks_tu64 EcuM_DriverInitOne_end_ticks_SlaveCore1_u64;

            
            
static EcuM_TimeTicks_tu64 EcuM_DriverInitOne_begin_ticks_u64;
static EcuM_TimeTicks_tu64 EcuM_DriverInitOne_end_ticks_u64;
EcuM_TimeTicks_tu64 EcuM_DeterminePbConfiguration_begin_ticks_u64;
EcuM_TimeTicks_tu64 EcuM_DeterminePbConfiguration_end_ticks_u64;

#define ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_MemMap.h"


#define ECUM_START_SEC_VAR_CLEARED_32
#include "EcuM_MemMap.h"
/*To store the Duration of EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/

static uint32 EcuM_DriverInitZero_delta_us_u32;  

            

static uint32 EcuM_DriverInitOne_delta_us_SlaveCore0_u32;

            

static uint32 EcuM_DriverInitOne_delta_us_SlaveCore1_u32;

            
            
static uint32 EcuM_DriverInitOne_delta_us_u32;
static uint32 EcuM_DriverInitOne_LastReset_begin_us_u32;
static uint32 EcuM_DeterminePbConfiguration_delta_us_u32;

static uint32 EcuM_DriverInitZero_LastReset_begin_us_u32;

static uint32 EcuM_DeterminePbConfiguration_LastReset_begin_us_u32;

#define ECUM_STOP_SEC_VAR_CLEARED_32
#include "EcuM_MemMap.h"

#endif /*ECUM_STARTUP_DURATION*/

/*************************************************************************************************
                            CALLOUTS
*************************************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"
/************************************************************************************************
  Function name     :   EcuM_AL_DriverInitZero
  Description       :   This callout shall provide driver initialization and other hardware-related
                        startup activities for loading the post-build configuration data. Beware:
                        Here only pre-compile and link-time configurable modules may be used.
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
************************************************************************************************/

void EcuM_AL_DriverInitZero(void)
{
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitZero_begin_ticks_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/


#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitZero_end_ticks_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
}

/**********************************************************************************
  Function name     :   EcuM_AL_DriverInitOne
  Description       :   This callout shall provide driver initialization and other
                        hardware-related startup activities in case of a power on reset.
  Parameter (in)    :   ConfigPtr
  Parameter (inout) :   None
 ***********************************************************************************/
extern void EXT_ServiceCpuDog(void);
void EcuM_AL_DriverInitOne( const EcuM_ConfigType * ConfigPtr )
{
    

    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == 0)/*Driver Init for OsCoreId 0*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_SlaveCore0_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
                    (void)VectorTable_Core0_Init();
            
        

      
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
       
    EcuM_DriverInitOne_end_ticks_SlaveCore0_u64    =   EcuM_GetTicks();
    EcuM_DriverInitOne_delta_us_SlaveCore0_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_SlaveCore0_u64,EcuM_DriverInitOne_begin_ticks_SlaveCore0_u64);
       

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    
    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == 1)/*Driver Init for OsCoreId 1*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_SlaveCore1_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
                    (void)VectorTable_Core1_Init();
            
        

      
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
       
    EcuM_DriverInitOne_end_ticks_SlaveCore1_u64    =   EcuM_GetTicks();
    EcuM_DriverInitOne_delta_us_SlaveCore1_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_SlaveCore1_u64,EcuM_DriverInitOne_begin_ticks_SlaveCore1_u64);
       

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    
    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == ECUM_CFG_STARTUP_CORE)/*Driver Init for OsCoreId ECUM_CFG_STARTUP_CORE*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
                    #if (ECUM_INCLUDE_DET == STD_ON)
                    (void)Det_Init(ConfigPtr->ModuleInitPtrPB.DetInitConfigPtr_cpst);
                    EXT_ServiceCpuDog();
                    #endif
                    (void)Dem_PreInit(ConfigPtr->ModuleInitPtrPB.DemInitConfigPtr_cpst);
                    EXT_ServiceCpuDog();
                    (void)Mcu_Init(ConfigPtr->ModuleInitPtrPB.McuInitConfigPtr_cpst);
                    EXT_ServiceCpuDog();
                    (void)McuFunc_InitializeClock();
                    EXT_ServiceCpuDog();
                    (void)Fls_Init(ConfigPtr->ModuleInitPtrPB.FlsInitConfigPtr_cpst);
                    (void)Port_Init(ConfigPtr->ModuleInitPtrPB.PortInitConfigPtr_cpst);
                    (void)EcuM_User_CheckWKSourceAll();
                    EXT_ServiceCpuDog();
                    (void)CDD_CORE0_Init();
                    EXT_ServiceCpuDog();
                    (void)Spi_Init(&Spi_Config);
                    EXT_ServiceCpuDog();
                    CDD_TPS653852A_Init();
                    EXT_ServiceCpuDog();
                    TCAN1145_Init1();
                    EXT_ServiceCpuDog();
                    TCAN1145_Init2();
                    EXT_ServiceCpuDog();
                    (void)Can_17_McmCan_Init(ConfigPtr->ModuleInitPtrPB.Can_17_McmCanInitConfigPtr_cpst);
                    EXT_ServiceCpuDog();
                    (void)Smu_Init(ConfigPtr->ModuleInitPtrPB.SmuInitConfigPtr_cpst);
                  //  (void)Wdg_17_Scu_Init(&Wdg_17_Scu_Config_0);
                    EXT_ServiceCpuDog();
                    (void)Sent_Init(&Sent_Config);
                    EXT_ServiceCpuDog();

#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
 
    EcuM_DriverInitOne_end_ticks_u64    =   EcuM_GetTicks();

    EcuM_DriverInitZero_delta_us_u32 = EcuM_GetDuration(EcuM_DriverInitZero_end_ticks_u64,EcuM_DriverInitZero_begin_ticks_u64);
    EcuM_DriverInitZero_LastReset_begin_us_u32 = EcuM_GetTicksSinceLastReset(EcuM_DriverInitZero_begin_ticks_u64);
    EcuM_DriverInitOne_delta_us_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_u64,EcuM_DriverInitOne_begin_ticks_u64);
    EcuM_DriverInitOne_LastReset_begin_us_u32 = EcuM_GetTicksSinceLastReset(EcuM_DriverInitOne_begin_ticks_u64);
    EcuM_DeterminePbConfiguration_delta_us_u32 = EcuM_GetDuration(EcuM_DeterminePbConfiguration_end_ticks_u64,EcuM_DeterminePbConfiguration_begin_ticks_u64);
    EcuM_DeterminePbConfiguration_LastReset_begin_us_u32 = EcuM_GetTicksSinceLastReset(EcuM_DeterminePbConfiguration_begin_ticks_u64);
        

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    

}

#if  (ECUM_SLEEP_SUPPORT_ENABLE == TRUE)
/**********************************************************************************
  Function name     :   EcuM_AL_DriverRestart
  Description       :   This callout shall provide driver re initialization and other
                        hardware-related startup activities in Wakeup Case.
  Parameter (in)    :   ConfigPtr
  Parameter (inout) :   None
 ***********************************************************************************/

void EcuM_AL_DriverRestart( const EcuM_ConfigType * ConfigPtr )
{
    (void)ConfigPtr;
}
#endif//ECUM_SLEEP_SUPPORT_ENABLE
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"


    
    



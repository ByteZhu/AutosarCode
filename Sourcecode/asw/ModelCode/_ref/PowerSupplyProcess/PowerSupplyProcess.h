/*
 * File: PowerSupplyProcess.h
 *
 * Code generated for Simulink model 'PowerSupplyProcess'.
 *
 * Model version                  : 1.1124
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:00:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PowerSupplyProcess_h_
#define RTW_HEADER_PowerSupplyProcess_h_
#ifndef PowerSupplyProcess_COMMON_INCLUDES_
# define PowerSupplyProcess_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PowerSupplyProcess_COMMON_INCLUDES_ */

#include "PowerSupplyProcess_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "GlobalVar.h"
#include "CalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S3>/HoldPowerLatchCheck' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERHOLD == 0

typedef struct {
  struct {
    UInt32 is_c55_PowerSupplyProcess:2;/* '<S3>/HoldPowerLatchCheck' */
    UInt32 is_active_c55_PowerSupplyProces:1;/* '<S3>/HoldPowerLatchCheck' */
  } bitsForTID0;

  UInt16 hold_cnt;                     /* '<S3>/HoldPowerLatchCheck' */
} PowerSup_DW_HoldPowerLatchCheck;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S4>/IGkeyCANCheck' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERIGCAN == 0

typedef struct {
  struct {
    UInt32 is_c92_PowerSupplyProcess:2;/* '<S4>/IGkeyCANCheck' */
    UInt32 is_active_c92_PowerSupplyProces:1;/* '<S4>/IGkeyCANCheck' */
  } bitsForTID0;

  UInt16 t15j_cnt;                     /* '<S4>/IGkeyCANCheck' */
  UInt16 t15_cnt;                      /* '<S4>/IGkeyCANCheck' */
} PowerSupplyPro_DW_IGkeyCANCheck;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S16>/JudgeVbat_VBRIG' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERVBAT == 0

typedef struct {
  UInt16 alter_batcnt1;                /* '<S17>/CondCounter' */
  UInt16 alter_batcnt2;                /* '<S17>/CondCounter' */
  Bool SysTaskVbatAbnormalPending_pqfw;/* '<S17>/CondCounter' */
} PowerSupplyP_DW_JudgeVbat_VBRIG;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S14>/PowerLevelCheck' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERLEVEL == 0

typedef struct {
  struct {
    UInt32 is_c64_PowerSupplyProcess:3;/* '<S24>/PowerManagement' */
    UInt32 is_active_c64_PowerSupplyProces:1;/* '<S24>/PowerManagement' */
  } bitsForTID0;

  UInt16 PowerNormalTime;              /* '<S24>/PowerManagement' */
  UInt16 PowerAbnormalTime;            /* '<S24>/PowerManagement' */
  UInt16 PowerShutTime;                /* '<S24>/PowerManagement' */
} PowerSupplyP_DW_PowerLevelCheck;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S28>/ResolverPowerCheck' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_ROTORPOWERREG == 0

typedef struct {
  struct {
    UInt32 is_c94_PowerSupplyProcess:2;/* '<S31>/ResolverPowerBrownout' */
    UInt32 is_active_c94_PowerSupplyProces:1;/* '<S31>/ResolverPowerBrownout' */
  } bitsForTID0;

  UInt16 ResolverBrownoutTimej;        /* '<S31>/ResolverPowerBrownout' */
  UInt16 ResolverBrownoutTimei;        /* '<S31>/ResolverPowerBrownout' */
} PowerSupp_DW_ResolverPowerCheck;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S29>/SysPowerCheck' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERLEVEL == 0

typedef struct {
  struct {
    UInt32 is_c93_PowerSupplyProcess:2;/* '<S34>/SysPowerBrownout' */
    UInt32 is_active_c93_PowerSupplyProces:1;/* '<S34>/SysPowerBrownout' */
  } bitsForTID0;

  UInt16 PowerBrownoutTimej;           /* '<S34>/SysPowerBrownout' */
  UInt16 PowerBrownoutTimei;           /* '<S34>/SysPowerBrownout' */
} PowerSupplyPro_DW_SysPowerCheck;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S30>/VbatCheck' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERVBAT == 0

typedef struct {
  struct {
    UInt32 is_c65_PowerSupplyProcess:2;/* '<S37>/VbatCheck' */
    UInt32 is_active_c65_PowerSupplyProces:1;/* '<S37>/VbatCheck' */
  } bitsForTID0;

  UInt16 bat_jdcnt;                    /* '<S37>/VbatCheck' */
  UInt16 batj_jdcnt;                   /* '<S37>/VbatCheck' */
} PowerSupplyProcess_DW_VbatCheck;

#endif
#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'PowerSupplyProcess' */
#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_

typedef struct {

#if DIAGDIS_POWERVBAT == 0

  PowerSupplyProcess_DW_VbatCheck VbatCheck;

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_POWERLEVEL == 0

  PowerSupplyPro_DW_SysPowerCheck SysPowerCheck;

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_ROTORPOWERREG == 0

  PowerSupp_DW_ResolverPowerCheck ResolverPowerCheck;

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_POWERLEVEL == 0

  PowerSupplyP_DW_PowerLevelCheck PowerLevelCheck;

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_POWERVBAT == 0

  PowerSupplyP_DW_JudgeVbat_VBRIG JudgeVbat_VBRIG;/* '<S16>/JudgeVbat_VBRIG' */

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_POWERIGCAN == 0

  PowerSupplyPro_DW_IGkeyCANCheck sf_IGkeyCANCheck;

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_POWERHOLD == 0

  PowerSup_DW_HoldPowerLatchCheck sf_HoldPowerLatchCheck;

#define POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS
#endif

#ifndef POWERSUPPLYPROCESS_DW_FWU4_VARIANT_EXISTS

  char _rt_unused;

#endif

} PowerSupplyProcess_DW_fwu4;

#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

extern void PowerSupplyProcess(void);

#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_
#if DIAGDIS_POWERHOLD == 0

extern void PowerSupply_HoldPowerLatchCheck(void);

#endif

#if DIAGDIS_POWERIGCAN == 0

extern void PowerSupplyProces_IGkeyCANCheck(void);

#endif

#if DIAGDIS_POWERLEVEL == 0

extern void PowerSupplyProc_PowerLevelCheck(void);

#endif

#if DIAGDIS_POWERLEVEL == 1

extern void PowerSupplyP_PowerLevelCheckDis(void);

#endif

#if DIAGDIS_ROTORPOWERREG == 0

extern void PowerSupplyP_ResolverPowerCheck(void);

#endif

#if DIAGDIS_ROTORPOWERREG == 1

extern void PowerSupp_ResolverPowerCheckDis(void);

#endif

#if DIAGDIS_POWERLEVEL == 0

extern void PowerSupplyProces_SysPowerCheck(void);

#endif

#if DIAGDIS_POWERLEVEL == 1

extern void PowerSupplyPro_SysPowerCheckDis(void);

#endif

#if DIAGDIS_POWERVBAT == 0

extern void PowerSupplyProcess_VbatCheck(void);

#endif

extern void Power_DiagSlow_PowerOthersCheck(void);
extern void Po_PowerSupplyCheck_EquSysPower(void);
extern void PowerSupp_PowerSupplyCheck_Vbat(void);
extern void Power_DiagSlow_PowerSupplyCheck(void);

#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

#ifndef PowerSupplyProcess_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern PowerSupplyProcess_DW_fwu4 PowerSupplyProcessrtDW;

#endif                                 /*PowerSupplyProcess_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PowerSupplyProcess'
 * '<S1>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck'
 * '<S2>'   : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck'
 * '<S3>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch'
 * '<S4>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN'
 * '<S5>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck'
 * '<S6>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheckDis'
 * '<S7>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck/DTC_Ctrl_Enabled'
 * '<S8>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck/getDTCEnabled'
 * '<S9>'   : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck'
 * '<S10>'  : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheckDis'
 * '<S11>'  : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck/DTC_Ctrl_Enabled'
 * '<S12>'  : 'PowerSupplyProcess/DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck/getDTCEnabled'
 * '<S13>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower'
 * '<S14>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel'
 * '<S15>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat'
 * '<S16>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat'
 * '<S17>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG'
 * '<S18>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIGDIS'
 * '<S19>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/Compare To Constant'
 * '<S20>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/Compare To Constant1'
 * '<S21>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/Compare To Constant2'
 * '<S22>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/Compare To Zero'
 * '<S23>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/CondCounter'
 * '<S24>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck'
 * '<S25>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheckDis'
 * '<S26>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck/PowerManagement'
 * '<S27>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck/PowerManagement/getDTCEnabled'
 * '<S28>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower'
 * '<S29>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower'
 * '<S30>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat'
 * '<S31>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheck'
 * '<S32>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheckDis'
 * '<S33>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheck/ResolverPowerBrownout'
 * '<S34>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheck'
 * '<S35>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheckDis'
 * '<S36>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheck/SysPowerBrownout'
 * '<S37>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck'
 * '<S38>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck'
 * '<S39>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck/DTC_Ctrl_Enabled'
 * '<S40>'  : 'PowerSupplyProcess/DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck/getDTCEnabled'
 */

/*-
 * Requirements for '<Root>': PowerSupplyProcess
 */
#endif                                 /* RTW_HEADER_PowerSupplyProcess_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

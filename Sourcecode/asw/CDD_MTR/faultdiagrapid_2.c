/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: 
 * Description:
 * Version: 1.0
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : Isolar_Project
 * Component: /Components/faultdiagrapid_2
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 12.0.1
 * Author: tiand
 * Date : ���� 5�� 12 11:16:26 2023
 ****************************************************************************/

#include <common.h>
//#include "Rte_faultdiagrapid_2.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :MTR_MotorControl_100us) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :MTR_MotorControl_100us) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :MTR_MotorControl_100us) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define faultdiagrapid_2_START_SEC_CODE                   
//#include "faultdiagrapid_2_MemMap.h"
FUNC (void, faultdiagrapid_2_CODE) MTR_MotorControl_100us/* return value & FctID */
(
		void
)
{
	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :MTR_MotorControl_100us) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
//	Std_ReturnType retValue = RTE_E_OK;
#if 0
	/*  -------------------------------------- Data Read -----------------------------------------  */
	Tv_PID_DI = Rte_IRead_MTR_MotorControl_100us_FV_TCL_EXT_FVu16_TCL_PID_DI();
	Tv_PID_DP = Rte_IRead_MTR_MotorControl_100us_FV_TCL_EXT_FVu16_TCL_PID_DP();
	Tv_PID_QI = Rte_IRead_MTR_MotorControl_100us_FV_TCL_EXT_FVu16_TCL_PID_QI();
	Tv_PID_QP = Rte_IRead_MTR_MotorControl_100us_FV_TCL_EXT_FVu16_TCL_PID_QP();
	if(Fv_TESTmodeFun_GlbFlag == 0)
	{
		SysTaskCurrentSmpPending1 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysCurrentSmpPending1();
		SysTaskCurrentSmpPending2 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysCurrentSmpPending2();
		SysTaskFocResetPending1 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysFocResetPending1();
		SysTaskFocResetPending2 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysFocResetPending2();
		SysTaskFocResetTrgPending1 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysFocResetTrgPending1();
		SysTaskFocResetTrgPending2 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysFocResetTrgPending2();
		SysTaskResolverFailPending1 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysResolverFailPending_1();
		SysTaskResolverFailPending2 = Rte_IRead_MTR_MotorControl_100us_FV_FRP_STT_FVbl_FRP_SysResolverFailPending_2();
		Fv_VehSpdNew = Rte_IRead_MTR_MotorControl_100us_FV_CAN_VS_FVu16q5_CAN_VehSpd_new();
		Fv_PMSMCurrent_ORGQAIM1 = Rte_IRead_MTR_MotorControl_100us_FV_LMT_STT_FVs32q7_LMT_MotorCurrentORG_aim1();
		Fv_PMSMCurrent_ORGQAIM2 = Rte_IRead_MTR_MotorControl_100us_FV_LMT_STT_FVs32q7_LMT_MotorCurrentORG_aim2();
		Fv_TempSysCel = Rte_IRead_MTR_MotorControl_100us_FV_ENV_TMP_FVs16q3_TMP_TempSysCel();
	}
#else

#endif
#if 0
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs16q7_MTR_SysPowerRelay(Fv_SysPowerRelay);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs16q7_MTR_SysPowerRelay_limit(Fv_LimitedSysPower);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs16q7_MTR_SysPowerRelay_sq3inv(Fv_PowerSqrt3INV);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_alpha1(Fv_MotorVoltage_Alpha1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_alpha2(Fv_MotorVoltage_Alpha2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_beta1(Fv_MotorVoltage_Beta1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_beta2(Fv_MotorVoltage_Beta2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_d1(Fv_MotorVoltage_D1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_d2(Fv_MotorVoltage_D2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_q1(Fv_MotorVoltage_Q1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_VLT_FVs32q10_MTR_MotorVoltage_q2(Fv_MotorVoltage_Q2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs32q3_MTR_dRotorAng_rpm(Fv_dRotorAng_rpm);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs16q13_MTR_RotorAng(Fv_RotorAng);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs16q13_MTR_RotorAng_domin(Fv_Rotor_pos_elcdomin);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs16q4_MTR_BasicSteerAngle(Fv_BasicSteerAngle);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs32q10_MTR_dRotorAng(Fv_dRotorAng);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs32q10_MTR_ddRotorAng(Fv_ddRotorAng);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs32q15_MTR_RotorAng_sum(Fv_RotorAng_AddSum);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_RTR_FVs32q15_MTR_RotorAng_sumfir(Fv_RotorAng_AddSumFilter);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_dact1(Fv_MotorCurrent_Dact1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_dact2(Fv_MotorCurrent_Dact2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_daim1(Fv_MotorCurrent_Daim1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_daim2(Fv_MotorCurrent_Daim2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_qact1(Fv_MotorCurrent_Qact1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_qact2(Fv_MotorCurrent_Qact2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_qaim1(Fv_MotorCurrent_Qaim1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_qaim2(Fv_MotorCurrent_Qaim2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_u1(Fv_MotorCurrent_U1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_u2(Fv_MotorCurrent_U2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_v1(Fv_MotorCurrent_V1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_v2(Fv_MotorCurrent_V2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_w1(Fv_MotorCurrent_W1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_w2(Fv_MotorCurrent_W2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_dact(Fv_MotorCurrent_Dact);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_CRT_FVs32q7_MTR_MotorCurrent_qact(Fv_MotorCurrent_Qact);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMt0_m1(PWM_t0_m1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMt0_m2(PWM_t0_m2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMt1_m1(PWM_t1_m1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMt1_m2(PWM_t1_m2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMt2_m1(PWM_t2_m1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMt2_m2(PWM_t2_m2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMu_m1(Fv_Motor_PWM_U1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMu_m2(Fv_Motor_PWM_U2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMv_m1(Fv_Motor_PWM_V1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMv_m2(Fv_Motor_PWM_V2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMw_m1(Fv_Motor_PWM_W1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVs16_MTR_PWMw_m2(Fv_Motor_PWM_W2);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVu8_MTR_PWMSection_m1(PWM_Section_m1);

	Rte_IWrite_MTR_MotorControl_100us_FV_MTR_PWM_FVu8_MTR_PWMSection_m2(PWM_Section_m2);
#endif
	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :MTR_MotorControl_100us) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}
#define faultdiagrapid_2_STOP_SEC_CODE  
//#include "faultdiagrapid_2_MemMap.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :faultdiagrapid_2) ENABLED START */
/* Start of user defined functions  - Do not remove this comment */
/* End of user defined functions - Do not remove this comment */
/*PROTECTED REGION END */


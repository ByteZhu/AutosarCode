/*
 * NewCode.h
 *
 *  Created on: Jun 14, 2023
 *      Author: jingjing
 */

#ifndef SOURCECODE_ASW_BSS_NEWCODE_H_
#define SOURCECODE_ASW_BSS_NEWCODE_H_
#include "Std_Types.h"
#include "zero_crossing_types.h"
#include "SimDiagMacro.h"
#include "FilterLibrary.h"

/* Block signals and states (default storage) for system '<S155>/RobustfilterFun' */

/* Extern declarations of internal data for system '<S155>/RobustfilterFun' */
extern DW_RobustfilterFun rtRobustfilterFun_DW;

/* Extern declarations of internal data for system '<S155>/TorqueSoftAdv2' */
extern DW_TorqueSoftAdv2 rtTorqueSoftAdv2_DW;

/* Extern declarations of internal data for system '<S155>/ToruqeNotchFilter' */
extern DW_ToruqeNotchFilter rtToruqeNotchFilter_DW;

/* Extern declarations of internal data for system '<S309>/TorqueSoftAdv' */
extern DW_TorqueSoftAdv rtTorqueSoftAdv_DW;

/* Extern declarations of internal data for system '<S309>/ToruqeStableFilter' */
extern DW_ToruqeStableFilter rtToruqeStableFilter_DW;

extern void HarmonicCompensation1(Int32 W);
extern void RobustfilterFun_Init(void);
extern void RobustfilterFun(void);//Tv_BasicAsisTrq_RBS
extern void TorqueSoftAdv2_Init(void);
extern void TorqueSoftAdv2(void);//Tv_BasicAsisTrq_ADV
extern void ToruqeNotchFilter_Init(void);
extern void ToruqeNotchFilter(void);//Tv_BasicAsisTrq_NCH
extern void TorqueSoftAdv_Init(void);
extern void TorqueSoftAdv(void);//Fv_StrTrq0->Fv_StrTrqP2dot5
extern void ToruqeStableFilter_Init(void);
extern void ToruqeStableFilter(void);//Fv_StrTrq_Primed->Fv_StrTrq_FeedForward
extern void Init_CalcFirCoef(void);
extern void ToruqeNotchFilter_SSW(void);//Fv_BassicAssisFedforward->Fv_BassicAssisFedforward_SSW

extern Float64 Fv_FirCof_TorqueSoftAdv_Param[2];// = {0, 0};
extern Float64 Fv_FirCof_TorqueRobus_Param[4];//={0,0,0,0};
extern Float64 Fv_FirCof_TorqueSoftAdv2_Param[2];// = {0, 0};


#endif /* SOURCECODE_ASW_BSS_NEWCODE_H_ */

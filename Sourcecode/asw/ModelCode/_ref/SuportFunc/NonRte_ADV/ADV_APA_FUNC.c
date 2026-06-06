/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_APA_FUNC.c
 *
 * Code generated for Simulink model 'ADV_ExtFunction'.
 *
 * Model version                  : 9.98
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 25 08:42:28 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADV_ExtFunction.h"
#include "rtwtypes.h"
#include "ADV_APA_FUNC.h"
#include "ADV_HANDSOFF_DETECT.h"
#include "ADV_CCP_PROC.h"
#include "Rte_Type.h"
#include "ADV_ExtFunction_private.h"
#include "look1_is16ls32n10tu16_plinlcase.h"
#include "CalVarSupport.h"
#include "GlobalVarSupport.h"
#include "look2_is16u16ls32n10tu_gntPemx1.h"
#include "SimDiagMacro.h"
#include "CalVar.h"
#include "GlobalVarSupport.h"

/* Named constants for Chart: '<S8>/apauseroprtmr' */
#define CONSTCNTMAX                    (1000000U)

/* Named constants for Chart: '<S9>/APAControlLogic' */
#define IN_active                      ((uint8)1U)
#define IN_close                       ((uint8)2U)
#define IN_fault                       ((uint8)3U)
#define IN_open                        ((uint8)4U)

#define RECEIVE_MODE_APA               0

ARID_DEF_ADV_APA_FUNC_ADV_ExtFu rtADV_APA_FUNC_ARID_DEF_ADV_Ext;

/* Output and update for atomic system: '<S1>/APAControl_Cond' */
void APAControl_Cond(void)
{
  uint32 apa_trqstep;
  sint16 rtb_Abs;
  sint16 rtb_Abs3;
  uint16 rtb_overtime;
  uint8 rtb_adsmod_tmp;
  boolean rtb_Compare_gzvr;
  boolean rtb_Compare_inla;
  boolean rtb_Compare_j50a;
  boolean rtb_Compare_jjvp;
  boolean rtb_Compare_l5bu;
  boolean rtb_Compare_lojx;
  boolean rtb_Compare_o4jy;
  boolean rtb_Compare_ondb;
  boolean rtb_OR1;
  boolean rtb_adsmod;
  boolean rtb_angrange;
  boolean rtb_diffinit;
  boolean rtb_diffrange;
  boolean rtb_epsmod_tmp;
  boolean rtb_epsvalid;
  boolean rtb_errmod_detm;
  boolean rtb_errmod_nyr5;
  boolean rtb_errmod_tmp;
  boolean rtb_otherst;
  boolean rtb_revst;
  boolean rtb_trqst;

  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Constant'
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S30>/Compare'
   *  RelationalOperator: '<S31>/Compare'
   *  RelationalOperator: '<S32>/Compare'
   */
  rtb_epsvalid = ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI ==
                   0) &&
                  (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30 ==
                   0) &&
                  (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s ==
                   0));

  /* Abs: '<S8>/Abs2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element24'
   */
#if RECEIVE_MODE_APA
  rtb_Abs3 = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q4_CAN_AdsPkReq();
#else
  rtb_Abs3 = Fv_AdsParkReq;
#endif

  if (rtb_Abs3 < 0) {
    rtb_Abs = (sint16)-rtb_Abs3;
  } else {
    rtb_Abs = rtb_Abs3;
  }

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Abs: '<S8>/Abs2'
   *  Constant: '<S20>/Constant'
   */
  rtb_Compare_jjvp = (rtb_Abs < Cal_APA_LOOP_MAX_ANGLE);

  /* Logic: '<S8>/AND8' incorporates:
   *  Constant: '<S29>/Constant'
   *  Inport generated from: '<Root>/In Bus Element25'
   *  RelationalOperator: '<S29>/Compare'
   */
#if RECEIVE_MODE_APA
  rtb_errmod_detm =
    (Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVbl_CAN_AdsPkInvalid_flag() ==
     false);
#else
  rtb_errmod_detm =(Fv_AdsPkInvalid_flag ==
		     false);
#endif


  /* Logic: '<S8>/AND1' */
  rtb_otherst = (rtb_Compare_jjvp && rtb_errmod_detm);

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   */
#if RECEIVE_MODE_APA
  rtb_adsmod_tmp = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVu8_CAN_AdsMod();
#else
  rtb_adsmod_tmp = Fv_AdsMod;
#endif

  /* Logic: '<S8>/OR' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S17>/Constant'
   *  Inport generated from: '<Root>/In Bus Element3'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   */
#if 1
  rtb_adsmod = (((rtb_adsmod_tmp == ((uint8)13U)) || (rtb_adsmod_tmp == ((uint8)
    14U)) || (rtb_adsmod_tmp == ((uint8)15U))) && (Tv_StrSASAngValid > 0)) && (Fv_LKA_Torque == 0)&&(Fv_DSR_Torque == 0)&&(Fv_LKA_ControlSts!=2);
  /* debug_jing2 = ((rtb_adsmod_tmp == ((uint8)13U)) || (rtb_adsmod_tmp == ((uint8)   //mod by liuyang
    14U)) || (rtb_adsmod_tmp == ((uint8)15U))) | (Tv_StrSASAngValid > 0)<<1 |(Fv_LKA_Torque == 0)<<2|(Fv_DSR_Torque == 0)<<3;*/

#else
  rtb_adsmod = (((rtb_adsmod_tmp == ((uint8)13U)) || (rtb_adsmod_tmp == ((uint8)
    14U)) || (rtb_adsmod_tmp == ((uint8)15U))) && (Tv_StrSASAngValid > 0));
#endif
  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   *  Inport generated from: '<Root>/In Bus Element16'
   */
#if RECEIVE_MODE_APA
  rtb_Compare_j50a =
    (Fv_CAN_AdsTqInvalid_flag ==
     false);
#else
     rtb_Compare_j50a = (Fv_AdsTqInvalid_flag == false) && (Fv_APALostFlag == 0);
#endif

  /* SignalConversion: '<S39>/Signal Copy' incorporates:
   *  Logic: '<S8>/AND10'
   *  Logic: '<S8>/NOT1'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag_ca22 = ((!rtb_adsmod) &&
    rtb_Compare_j50a);

  /* Logic: '<S8>/OR1' incorporates:
   *  Constant: '<S23>/Constant'
   *  RelationalOperator: '<S23>/Compare'
   */
  rtb_OR1 = (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD ==
             HOLD_ACTIVE);
  
  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_Compare_ondb = (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1
                      == false);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   */
  rtb_Compare_inla = (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_jyet
                      == 0);

  /* Logic: '<S8>/AND8' */
  rtb_errmod_detm = (rtb_Compare_j50a && rtb_Compare_ondb && rtb_Compare_inla &&
                     rtb_errmod_detm && rtb_epsvalid);

  /* Logic: '<S8>/NOT3' incorporates:
   *  Logic: '<S8>/NOT12'
   */
  rtb_errmod_tmp = !rtb_errmod_detm;

  /* Logic: '<S8>/NOT4' incorporates:
   *  Logic: '<S8>/NOT8'
   */
  rtb_epsmod_tmp = !rtb_epsvalid;

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S26>/Compare'
   */
  rtb_Compare_o4jy = (rtADV_HANDSOFF_DETECT_ARID_DEF_.Compare == false);

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  /*rtb_Compare_l5bu = (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_
                      >= Cal_APA_VSLOOP);*/

  /*apa锟斤拷锟节碉拷锟斤拷5kph锟剿筹拷  rpa锟斤拷锟节碉拷锟斤拷3锟剿筹拷*/
  rtb_Compare_l5bu = ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_
		  >= Cal_APA_VSLOOP)&&(rtb_adsmod_tmp != 14)) ||
                        ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_
                        >= Cal_APA_VSINIT_RPA)&&(rtb_adsmod_tmp == 14));

  /* Abs: '<S8>/Abs3' incorporates:
   *  Abs: '<S8>/Abs2'
   *  Inport generated from: '<Root>/In Bus Element24'
   *  SignalConversion generated from: '<Root>/In Bus Element19'
   *  Sum: '<S8>/Subtract'
   */
  rtb_Abs3 -= rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG;

  /* Abs: '<S8>/Abs3' */
  if (rtb_Abs3 < 0) {
    rtb_Abs3 = (sint16)-rtb_Abs3;
  }

  /* End of Abs: '<S8>/Abs3' */

  /* Logic: '<S8>/NOT6' incorporates:
   *  Abs: '<S8>/Abs3'
   *  Constant: '<S24>/Constant'
   *  RelationalOperator: '<S24>/Compare'
   */
  rtb_diffrange = (rtb_Abs3 >= Cal_APA_DIFFLIMIT);

  /* Abs: '<S8>/Abs4' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element22'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ < 0) {
    /* Abs: '<S8>/Abs' */
    rtb_Abs = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  } else {
    /* Abs: '<S8>/Abs' */
    rtb_Abs = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  }

  /* End of Abs: '<S8>/Abs4' */

  /* Lookup_n-D: '<S8>/apa_handoverride' incorporates:
   *  Abs: '<S8>/Abs'
   */
  rtb_overtime = look1_is16ls32n10tu16_plinlcase(rtb_Abs, (const sint16 *)
    &Cal_APA_HandOverTimeTab_X[0], (const uint16 *)&Cal_APA_HandOverTimeTab_Y[0],
    &rtADV_APA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_e4kx, 8U);

  /* Chart: '<S8>/apauseroprtmr' incorporates:
   *  Abs: '<S8>/Abs'
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S14>/Compare'
   */
  if (rtb_overtime == 0) {
    apa_trqstep = CONSTCNTMAX;
  } else {
    apa_trqstep = CONSTCNTMAX / rtb_overtime;
  }

  if (rtb_Abs > Cal_APA_TRQLOOP) {
    if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt < CONSTCNTMAX) {
      rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt += apa_trqstep;
    } else {
      rtADV_APA_FUNC_ARID_DEF_ADV_Ext.park_temporary = true;
    }
  } else {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.park_temporary = false;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt = 0U;
  }

  /* End of Chart: '<S8>/apauseroprtmr' */

  /* Logic: '<S8>/AND11' incorporates:
   *  Logic: '<S8>/NOT2'
   *  Logic: '<S8>/NOT3'
   *  Logic: '<S8>/NOT4'
   *  Logic: '<S8>/NOT5'
   */
  /*
  active->fault
  rtb_OR1 : 鍔╁姏妯″紡锛�=HOLD_ACTIVE
  rtb_errmod_tmp 锛氱浉鍏充俊鍙锋棤鏁�
  rtb_epsmod_tmp 锛歟ps鏁呴殰
  rtb_Compare_o4jy 锛氳劚鎵嬩簡
rtb_Compare_l5bu锛氳溅閫熻秴闄�
rtADV_APA_FUNC_ARID_DEF_ADV_Ext.park_temporary 锛氭墜閲屽共棰勮秴闄�
  */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.active2fault_flag = ((!rtb_OR1) ||
    rtb_errmod_tmp || rtb_epsmod_tmp || (!rtb_Compare_o4jy) || rtb_Compare_l5bu ||
    rtb_diffrange || rtADV_APA_FUNC_ARID_DEF_ADV_Ext.park_temporary || (Fv_AdsModLostFlag > 0));
  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   *  Delay: '<S1>/Delay'
   */
  rtb_Compare_lojx = (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay == 0); //APA torque of last step

  /* Logic: '<S8>/AND12' incorporates:
   *  Logic: '<S8>/NOT7'
   */
  /*
  rtb_Compare_lojx锛歛pa鍔涚煩娓呴浂
  !rtADV_APA_FUNC_ARID_DEF_ADV_Ext.active2fault_flag 锛歛ctive->fault鏍囧織娓呴浂浜�
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag_ca22 锛氭帹鍑鸿姹備簡
  */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.fault2close_flag = (rtb_Compare_lojx &&
    (!rtADV_APA_FUNC_ARID_DEF_ADV_Ext.active2fault_flag) &&
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag_ca22);

  /* Logic: '<S8>/AND15' incorporates:
   *  Logic: '<S8>/AND13'
   */
  rtb_errmod_nyr5 = (rtb_adsmod && rtb_Compare_j50a && rtb_errmod_tmp);

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Abs: '<S8>/Abs3'
   *  Constant: '<S21>/Constant'
   */
  rtb_Compare_gzvr = (rtb_Abs3 < Cal_APA_DIFFINIT);

  /* Logic: '<S8>/NOT9' */
  rtb_diffinit = !rtb_Compare_gzvr;

  /* Logic: '<S8>/NOT10' */
  rtb_angrange = !rtb_Compare_jjvp;

  /* Logic: '<S8>/AND14' incorporates:
   *  Logic: '<S8>/NOT11'
   */
  /*
  open->fault
  rtb_errmod_nyr5 : 鏈夋縺娲昏姹傚苟涓旂浉鍏充俊鍙烽兘鏈夋晥
  !rtb_Compare_lojx锛� apa杈撳嚭鍔涚煩!=0,open寰楁椂鍊欑紦瀛樻病娓�
  rtb_diffinit锛氳姹傝搴﹁秴杩囧疄闄呰搴�250搴�   澧炲姞瑙掑害淇″彿鏈夋晥鎬у垽鏂紝鏂紑瑙掑害淇″彿 杩欎釜鍋忓樊鍙兘浼氭湁闂
  rtb_angrange锛氳姹傝搴﹁秴闄�
  */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.open2fault_flag = (rtb_errmod_nyr5 ||
    (!rtb_Compare_lojx) || ((rtb_diffinit)&&(!rtb_Compare_inla)) || rtb_angrange);

  /* Abs: '<S8>/Abs1' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element8'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n < 0) {
    rtb_Abs3 = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n;
  } else {
    rtb_Abs3 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n;
  }

  /* Logic: '<S8>/AND2' incorporates:
   *  Abs: '<S8>/Abs1'
   *  Constant: '<S19>/Constant'
   *  RelationalOperator: '<S19>/Compare'
   */
  rtb_revst = ((rtb_Abs3 < Cal_APA_DANGINIT) && rtb_Compare_inla);

  /* Abs: '<S8>/Abs' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element22'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ < 0) {
    rtb_Abs3 = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  } else {
    rtb_Abs3 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  }

  /* Logic: '<S8>/AND3' incorporates:
   *  Abs: '<S8>/Abs'
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S18>/Compare'
   */
  rtb_trqst = ((rtb_Abs3 < Cal_APA_TRQINIT) && rtb_Compare_o4jy);


  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  /*RPA < 3kph , APA < 5kph, from 184061 v4 ,24.02.05 by zyg*/
  rtb_Compare_o4jy = ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_
                      < Cal_APA_VSINIT)&&(rtb_adsmod_tmp != 14)) || 
                      ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_
                      < Cal_APA_VSINIT_RPA)&&(rtb_adsmod_tmp == 14));

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare_inla = (rtADV_CCP_PROC_ARID_DEF_ADV_Ext.OR == true);

  /* Logic: '<S8>/OR1' incorporates:
   *  Logic: '<S8>/AND4'
   */
  /*
  close->open

  rtb_OR1:鍔╁姏妯″紡 HOLD_ACTIVE
  rtb_Compare_j50a: Fv_AdsTqInvalid_flag鍒ゆ柇190淇″彿鏍￠獙鏄惁鏈夋晥
  rtb_Compare_inla锛氭槸鍚﹂厤缃笂浜�
  rtb_Compare_o4jy锛氳溅閫熸槸鍚︽弧瓒虫縺娲绘潯浠�
  rtb_Compare_ondb锛氳溅閫熸槸鍚︽湁鏁�
  rtb_trqst:鎵嬪姏鏄惁婊¤冻  鏈劚鎵嬩笖鎵嬪姏澶т簬1NM
  rtb_revst:瀹為檯瑙掑害鏄惁鍦�90deg浠ュ唴  骞朵笖瑙掑害淇″彿鏈夋晥
  rtb_otherst:璇锋眰瑙掑害鏄惁瓒呰繃540搴︿笖璇锋眰瑙掑害ub鏈夋晥

  澧炲姞Fv_AdsAgInvalid_flag鍒ゆ柇:0涓篖atCtrlReqSafe_UB ==1  鏈夋晥

  Fv_AbsLostFlag杞﹂�熶俊鍙蜂涪澶卞垽鏂� Fv_AbsLostFlag == 0  鏈涪澶�
  */
/*  rtb_OR1 = (rtb_OR1 && rtb_Compare_j50a && rtb_Compare_inla &&
             (rtb_Compare_o4jy && rtb_Compare_ondb) && rtb_trqst && rtb_revst &&
             rtb_otherst);*/
      
  rtb_OR1 = (rtb_OR1 && rtb_Compare_j50a && rtb_Compare_inla &&
             (rtb_Compare_o4jy && rtb_Compare_ondb) && rtb_trqst && rtb_revst &&
             rtb_otherst)&&(Fv_AdsAgInvalid_flag == 0)&&(Fv_AbsLostFlag == 0);
/*debug_jing3 =  (rtb_OR1 | rtb_Compare_j50a<<1|  rtb_Compare_inla <<2|
             rtb_Compare_o4jy<<3 | rtb_Compare_ondb<<4|  rtb_trqst <<5| rtb_revst <<6|
             rtb_otherst<<7|(Fv_AdsAgInvalid_flag == 0)<<8|(Fv_AbsLostFlag == 0)<<9)|rtb_epsvalid<<10;*/


  /* Logic: '<S8>/AND7' */// 0 -> 1
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.close2open_flag = (rtb_OR1 && rtb_epsvalid);

  /* Logic: '<S8>/AND9' */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.open2active_flag = (rtb_Compare_gzvr &&
    rtb_adsmod && rtb_Compare_inla && rtb_Compare_o4jy && rtb_Compare_jjvp &&
    rtb_Compare_lojx && rtb_errmod_detm);
  /*debug_jing1 = rtb_Compare_gzvr | rtb_adsmod<<1|rtb_Compare_inla<<2| rtb_Compare_o4jy<<3|
   rtb_Compare_jjvp<<4 |rtb_Compare_lojx <<5|rtb_errmod_detm<<6;*/
  /* Chart: '<S8>/Active2FaultRecord' incorporates:
   *  Logic: '<S8>/NOT3'
   *  Logic: '<S8>/NOT4'
   */
  if (rtb_errmod_tmp) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st = PARKERR_SteerCtrlIntErr;
  } else if (rtb_epsmod_tmp) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st = PARKERR_SteerAbortByDrvIntv;
  } else if (rtb_Compare_l5bu) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st = PARKERR_SteerAbortBySpdHi;
  } else if (rtb_diffrange || rtADV_APA_FUNC_ARID_DEF_ADV_Ext.park_temporary) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st = PARKERR_CtrlDifHi;
  } else {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st = PARKERR_NormOper;
  }

  /* End of Chart: '<S8>/Active2FaultRecord' */

  /* Logic: '<S8>/NOT' */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.open2close_flag = !rtb_OR1;

  /* Logic: '<S8>/NOT8' */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.close2fault_flag = rtb_epsmod_tmp;

  /* Chart: '<S8>/Open2FaultRecord' */
  if (rtb_errmod_nyr5) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.opn2flt_st = PARKERR_SteerCtrlIntErr;
  } else if (rtb_diffinit || rtb_angrange) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.opn2flt_st = PARKERR_CtrlDifHi;
  } else {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.opn2flt_st = PARKERR_NormOper;
  }
  /* End of Chart: '<S8>/Open2FaultRecord' */
}

/* Output and update for atomic system: '<S1>/APAControl_Logic' */
void APAControl_Logic(void)
{
  /* Chart: '<S9>/APAControlLogic' */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_active_c24_ADV_ExtFunction == 0U) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_active_c24_ADV_ExtFunction = 1U;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_close;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 0U;
  } else {
    switch (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction) {
     case IN_active:
      if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.active2fault_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi =
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_fault;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.lastst =
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 3U;
      } else if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag_ca22) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_open;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 1U;
      }
      break;

     case IN_close:
 
      if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.close2fault_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi =
          PARKERR_SteerCtrlIntErr;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_fault;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.lastst =
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 3U;
      } else if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.close2open_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_open;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 1U;
      }
      break;

     case IN_fault:
      if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.fault2close_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi = PARKERR_NormOper;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_close;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 0U;
      } else {
        switch (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.lastst) {
         case 1:
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi =
            rtADV_APA_FUNC_ARID_DEF_ADV_Ext.opn2flt_st;
          break;

         case 2:
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi =
            rtADV_APA_FUNC_ARID_DEF_ADV_Ext.actv2flt_st;
          break;

         default:
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi =
            PARKERR_SteerCtrlIntErr;
          break;
        }
      }
      break;

     default:
      /* case IN_open: */
      if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.open2fault_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi =
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.opn2flt_st;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_fault;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.lastst =
          rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 3U;
      } else if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.open2close_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_close;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 0U;
      } else if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.open2active_flag) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.is_c24_ADV_ExtFunction = IN_active;
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts = 2U;
      }
      break;
    }
  }
  	Fv_APA_AbortFeedBack = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi;
  	Fv_APA_ControlSts = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts;
  /* End of Chart: '<S9>/APAControlLogic' */
}

/* Output and update for atomic system: '<S37>/APA_PosLoopControl' */
void APA_PosLoopControl(void)
{
  sint32 mcsl_err_last;

  /* Chart: '<S39>/APA_PosControl' */
  if (Fv_APA_PosClearFlag) {
    Fv_APA_PosClearFlag = false;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err = 0;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag = false;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_cnt = 0U;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.pc_strang_last = 0;
  } else {
    if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_chuv ==
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.pc_strang_last) {
      if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_cnt < Cal_APA_LOOP_STOPTMR) {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_cnt++;
      } else {
        rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag = true;
      }
    } else {
      rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag = false;
      rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_cnt = 0U;
    }

    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.pc_strang_last =
      rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_chuv;
  }

  mcsl_err_last = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err;
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err =
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_eprv -
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_plsa;

  mcsl_err_last = (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err - mcsl_err_last) *
    Cal_APA_POSPID_KD + rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err *
    Cal_APA_POSPID_KP;
  if (mcsl_err_last > Cal_APA_LOOP_MAX_REV) {
    mcsl_err_last = Cal_APA_LOOP_MAX_REV;
  } else if (mcsl_err_last < -Cal_APA_LOOP_MAX_REV) {
    mcsl_err_last = -Cal_APA_LOOP_MAX_REV;
  }

  /* SignalConversion: '<S39>/Signal Copy' */
  /* aimcurrent = MotorCtrl_SpdLoop_APA(mcsl_aimrev,Cal_APA_LOOP_MAX_CURRENT,apa_stop_flag) */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag_ca22 =
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag;

  /* Switch: '<S40>/Switch2' incorporates:
   *  SignalConversion: '<S39>/Signal Copy1'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki =
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err;

  /* SignalConversion: '<S39>/Signal Copy2' incorporates:
   *  Chart: '<S39>/APA_PosControl'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimrevin = (sint16)(-mcsl_err_last / 16);
}

/* Output and update for atomic system: '<S37>/APA_RevCalcParamSet' */
void APA_RevCalcParamSet(void)
{
  sint32 rtb_focrevabs;
  sint32 rtb_revfoc;
  sint16 rtb_errabs;
  uint16 rtb_apalooktab_ki;
  uint16 rtb_apalooktab_kp;
  boolean tmp;

  /* Product: '<S40>/revfoc' incorporates:
   *  Constant: '<S40>/Constant'
   *  DataTypeConversion: '<S40>/Data Type Conversion3'
   *  SignalConversion generated from: '<Root>/In Bus Element21'
   */
  /*rtb_revfoc = (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_MTR_RTR *((uint16)MACRO_RAD2RPM)) >> 14;*/
  rtb_revfoc = (Fv_FOC_RotorSpd *
                ((uint16)MACRO_RAD2RPM)) >> 14;

  /* Abs: '<S40>/focrevabs' incorporates:
   *  DataTypeConversion: '<S45>/FixPt Gateway Out'
   *  Product: '<S40>/revfoc'
   */
  if (rtb_revfoc < 0) {
    /* Abs: '<S40>/focrevabs' */
    rtb_focrevabs = -rtb_revfoc;
  } else {
    /* Abs: '<S40>/focrevabs' */
    rtb_focrevabs = rtb_revfoc;
  }

  /* End of Abs: '<S40>/focrevabs' */

  /* Relay: '<S40>/Relay' */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Relay_Mode = ((rtb_focrevabs >=
    Cal_APA_LOOP_STOPREVUP) || ((rtb_focrevabs > Cal_APA_LOOP_STOPREVDN) &&
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Relay_Mode));
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Relay_Mode) {
    tmp = false;
  } else {
    tmp = true;
  }

  /* Switch: '<S40>/Switch' incorporates:
   *  Logic: '<S40>/AND'
   *  Relay: '<S40>/Relay'
   *  SignalConversion: '<S39>/Signal Copy'
   */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.apa_stop_flag_ca22 && tmp) {
    /* Switch: '<S40>/Switch' incorporates:
     *  SignalConversion generated from: '<Root>/In Bus Element23'
     *  UnaryMinus: '<S40>/Unary Minus'
     */
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_actrev = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_e3ct;
  } else {
    /* Switch: '<S40>/Switch' incorporates:
     *  DataTypeConversion: '<S45>/FixPt Gateway Out'
     *  Product: '<S40>/revfoc'
     */
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_actrev = rtb_revfoc;
  }

  /* End of Switch: '<S40>/Switch' */

  /* DataTypeConversion: '<S48>/FixPt Gateway Out' incorporates:
   *  SignalConversion: '<S39>/Signal Copy2'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_palk =
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimrevin;

  /* Abs: '<S40>/errabs' incorporates:
   *  Switch: '<S40>/Switch2'
   */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki < 0) {
    /* Abs: '<S40>/errabs' */
    rtb_errabs = (sint16)-rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki;
  } else {
    /* Abs: '<S40>/errabs' */
    rtb_errabs = (sint16)rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki;
  }

  /* End of Abs: '<S40>/errabs' */

  /* Lookup_n-D: '<S40>/apalooktab_kp' incorporates:
   *  Abs: '<S40>/errabs'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_apalooktab_kp = look2_is16u16ls32n10tu_gntPemx1(rtb_errabs,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_APA_ErrAdapt_Tab_A[0], (const uint16 *)&Cal_APA_ErrAdapt_Tab_V[0], (
    const uint16 *)&Cal_APA_ErrAdapt_Tab_P[0],
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex, rtCP_apalooktab_kp_maxIndex, 8U);

  /* Lookup_n-D: '<S40>/apalooktab_ki' incorporates:
   *  Abs: '<S40>/errabs'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_apalooktab_ki = look2_is16u16ls32n10tu_gntPemx1(rtb_errabs,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_APA_ErrAdapt_Tab_A[0], (const uint16 *)&Cal_APA_ErrAdapt_Tab_V[0], (
    const uint16 *)&Cal_APA_ErrAdapt_Tab_I[0],
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_lxba, rtCP_apalooktab_ki_maxIndex,
    8U);

  /* Abs: '<S40>/aimrevabs' incorporates:
   *  SignalConversion: '<S39>/Signal Copy2'
   */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimrevin < 0) {
    rtb_errabs = (sint16)-rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimrevin;
  } else {
    rtb_errabs = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimrevin;
  }

  /* Switch: '<S40>/Switch1' incorporates:
   *  Abs: '<S40>/aimrevabs'
   *  Constant: '<S40>/Constant3'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  DataTypeConversion: '<S40>/Data Type Conversion2'
   *  Logic: '<S40>/AND1'
   *  Lookup_n-D: '<S40>/apalooktab_ki'
   *  Product: '<S40>/incki'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S44>/Compare'
   *  Switch: '<S40>/Switch'
   *  Switch: '<S40>/Switch2'
   */
  if ((rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_actrev == 0) && (rtb_errabs >
       Cal_APA_LOOP_INCREVLIMIT)) {
    /* Switch: '<S40>/Switch1' incorporates:
     *  Constant: '<S40>/Constant1'
     *  Lookup_n-D: '<S40>/apalooktab_kp'
     *  Product: '<S40>/inckp'
     */
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_kp = (sint32)((uint32)
      Cal_APA_LOOP_REVPI_PLUS * rtb_apalooktab_kp);
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki = (sint32)((uint32)
      Cal_APA_LOOP_REVPI_PLUS * rtb_apalooktab_ki);
  } else {
    /* Switch: '<S40>/Switch1' incorporates:
     *  DataTypeConversion: '<S40>/Data Type Conversion1'
     *  Lookup_n-D: '<S40>/apalooktab_kp'
     */
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_kp = rtb_apalooktab_kp;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki = rtb_apalooktab_ki;
  }

  /* End of Switch: '<S40>/Switch1' */

  /* DataTypeConversion: '<S47>/FixPt Gateway Out' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut = Cal_APA_LOOP_MAX_CURRENT;
}

/* Output and update for atomic system: '<S37>/APA_RevLoopControl' */
void APA_RevLoopControl(void)
{
  sint32 mcsl_err_last;
  sint32 mcsl_maxI_pi;

  /* Chart: '<S41>/APA_RevControl' incorporates:
   *  DataTypeConversion: '<S47>/FixPt Gateway Out'
   *  DataTypeConversion: '<S48>/FixPt Gateway Out'
   *  Switch: '<S40>/Switch'
   *  Switch: '<S40>/Switch1'
   *  Switch: '<S40>/Switch2'
   */
  if (Fv_APA_RevClearFlag) {
    Fv_APA_RevClearFlag = false;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err_mbvz = 0;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout = 0;
     mcsl_err_last = 0; //added by liuyang at 240919
  }

  mcsl_maxI_pi = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut << 8;
  mcsl_err_last = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err_mbvz;
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err_mbvz =
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_palk -
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_actrev;
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout +=
    ((rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err_mbvz - mcsl_err_last) *
     rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_kp +
     rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_ki *
     rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_err_mbvz) / 16;

  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout > mcsl_maxI_pi) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout = mcsl_maxI_pi;
  } else if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout < -mcsl_maxI_pi) {
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout = -mcsl_maxI_pi;
  }

  mcsl_maxI_pi = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.mcsl_aimout / 256 -
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_palk / 4;
  if (mcsl_maxI_pi > rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut) {
    mcsl_maxI_pi = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut;
  } else if (mcsl_maxI_pi < -rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut) {
    mcsl_maxI_pi = -rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut;
  }

  /* End of Chart: '<S41>/APA_RevControl' */

  /* Product: '<S41>/Divide' incorporates:
   *  Constant: '<S41>/Constant4'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S41>/Gain'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE = (mcsl_maxI_pi << 7) /
    Cal_Motor_TrqCoef;

}

/* Output and update for enable system: '<S10>/Position_AngleLoop' */
void Position_AngleLoop(void)
{
  /* Outputs for Enabled SubSystem: '<S10>/Position_AngleLoop' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Compare) {
    /* Outputs for Atomic SubSystem: '<S37>/APA_PosLoopControl' */
    APA_PosLoopControl();

    /* End of Outputs for SubSystem: '<S37>/APA_PosLoopControl' */

    /* Outputs for Atomic SubSystem: '<S37>/APA_RevCalcParamSet' */
    APA_RevCalcParamSet();

    /* End of Outputs for SubSystem: '<S37>/APA_RevCalcParamSet' */

    /* Outputs for Atomic SubSystem: '<S37>/APA_RevLoopControl' */
    APA_RevLoopControl();

    /* End of Outputs for SubSystem: '<S37>/APA_RevLoopControl' */
  }

  /* End of Outputs for SubSystem: '<S10>/Position_AngleLoop' */
}

/* Output and update for atomic system: '<S10>/Position_Precond' */
void Position_Precond(void)
{
  sint16 rtb_Subtract;
  sint16 rtb_Switch2;

  /* Outputs for Atomic SubSystem: '<S38>/APA_Precond_FlagSet' */
  /* If: '<S50>/If' */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts != 2) {
    /* Outputs for IfAction SubSystem: '<S50>/ActiveState' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* DataStoreWrite: '<S52>/Data Store Write' incorporates:
     *  Constant: '<S52>/Constant'
     */
    Fv_APA_PosClearFlag = true;

    /* DataStoreWrite: '<S52>/Data Store Write1' incorporates:
     *  Constant: '<S52>/Constant'
     */
    Fv_APA_RevClearFlag = true;

    /* DataStoreWrite: '<S52>/Data Store Write2' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    Fv_APA_Torque = 0;
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE = 0;
    Fv_APA_AngleUpdataEn = 1;
    /* End of Outputs for SubSystem: '<S50>/ActiveState' */
  }

  /* End of If: '<S50>/If' */
  /* End of Outputs for SubSystem: '<S38>/APA_Precond_FlagSet' */

  /* Outputs for Atomic SubSystem: '<S38>/APA_Precond_WorkState' */
  /* RelationalOperator: '<S57>/LowerRelop1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element24'
   *  Switch: '<S57>/Switch'
   */
#if RECEIVE_MODE_APA
  rtb_Switch2 = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q4_CAN_AdsPkReq();
#else
    rtb_Switch2 = Fv_AdsParkReq;  

  

#endif

  /* Switch: '<S57>/Switch2' incorporates:
   *  Constant: '<S51>/Constant2'
   *  Delay: '<S51>/Delay1'
   *  Inport generated from: '<Root>/In Bus Element24'
   *  RelationalOperator: '<S57>/LowerRelop1'
   *  RelationalOperator: '<S57>/UpperRelop'
   *  Switch: '<S57>/Switch'
   *  UnaryMinus: '<S51>/Unary Minus'
   */
  if (rtb_Switch2 > Cal_APA_LOOP_MAX_ANGLE) {
    /* Switch: '<S57>/Switch2' */
    rtb_Switch2 = Cal_APA_LOOP_MAX_ANGLE;
  } else if (rtb_Switch2 < (sint16)-Cal_APA_LOOP_MAX_ANGLE) {
    /* Switch: '<S57>/Switch' incorporates:
     *  Delay: '<S51>/Delay1'
     *  Switch: '<S57>/Switch2'
     *  UnaryMinus: '<S51>/Unary Minus'
     */
    rtb_Switch2 = (sint16)-Cal_APA_LOOP_MAX_ANGLE;
  }

  /* End of Switch: '<S57>/Switch2' */

  /* Sum: '<S51>/Subtract' incorporates:
   *  Delay: '<S51>/Delay1'
   *  Switch: '<S57>/Switch2'
   */
  if((Fv_APA_AngleUpdataEn == 1) && (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts == ((uint8)2U)))
   {
	  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE= rtb_Switch2;
 	  Fv_APA_AngleUpdataEn = 0;
   }
   else
   {

   }
  rtb_Subtract = (sint16)(rtb_Switch2 -
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE);


  /* Switch: '<S59>/Switch2' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S51>/Constant5'
   *  RelationalOperator: '<S59>/LowerRelop1'
   *  RelationalOperator: '<S59>/UpperRelop'
   *  Sum: '<S51>/Subtract'
   *  Switch: '<S59>/Switch'
   *  UnaryMinus: '<S51>/Unary Minus1'
   *  UnaryMinus: '<S51>/Unary Minus2'
   */
  if (rtb_Subtract > Cal_APA_LOOP_STEP_ANGLE) {
    rtb_Subtract = Cal_APA_LOOP_STEP_ANGLE;
  } else if (rtb_Subtract < (sint16)-Cal_APA_LOOP_STEP_ANGLE) {
    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S51>/Constant1'
     *  UnaryMinus: '<S51>/Unary Minus1'
     *  UnaryMinus: '<S51>/Unary Minus2'
     */
    rtb_Subtract = (sint16)-Cal_APA_LOOP_STEP_ANGLE;
  }

  /* Sum: '<S51>/Add' incorporates:
   *  Delay: '<S51>/Delay1'
   *  Switch: '<S59>/Switch2'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE += rtb_Subtract;

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Compare =
    (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts == ((uint8)2U));

  /* Switch: '<S58>/Switch2' incorporates:
   *  Constant: '<S51>/Constant3'
   *  RelationalOperator: '<S58>/LowerRelop1'
   *  RelationalOperator: '<S58>/UpperRelop'
   *  SignalConversion generated from: '<Root>/In Bus Element19'
   *  Switch: '<S58>/Switch'
   *  UnaryMinus: '<S51>/Unary Minus1'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG >
      Cal_APA_LOOP_MAX_ANGLE) {
    /* Switch: '<S58>/Switch2' */
    rtb_Subtract = Cal_APA_LOOP_MAX_ANGLE;
  } else if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG <
             (sint16)-Cal_APA_LOOP_MAX_ANGLE) {
    /* Switch: '<S58>/Switch' incorporates:
     *  Switch: '<S58>/Switch2'
     *  UnaryMinus: '<S51>/Unary Minus1'
     */
    rtb_Subtract = (sint16)-Cal_APA_LOOP_MAX_ANGLE;
  } else {
    /* Switch: '<S58>/Switch2' incorporates:
     *  Switch: '<S58>/Switch'
     */
    rtb_Subtract = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG;
  }


  /* End of Switch: '<S58>/Switch2' */

  /* Switch: '<S51>/Switch' */
  if (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Compare) {
    /* DataTypeConversion: '<S54>/FixPt Gateway Out' incorporates:
     *  Sum: '<S51>/Add'
     */
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_eprv =
      rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE;
  } else {
    /* DataTypeConversion: '<S54>/FixPt Gateway Out' incorporates:
     *  Switch: '<S58>/Switch2'
     */
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_eprv = rtb_Subtract;
  }

  /* End of Switch: '<S51>/Switch' */

  /* DataTypeConversion: '<S55>/FixPt Gateway Out' incorporates:
   *  Switch: '<S58>/Switch2'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_plsa = rtb_Subtract;

  /* DataTypeConversion: '<S56>/FixPt Gateway Out' incorporates:
   *  Switch: '<S57>/Switch2'
   */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_chuv = rtb_Switch2;

  /* End of Outputs for SubSystem: '<S38>/APA_Precond_WorkState' */
}

/* Output and update for atomic system: '<S1>/APAControl_Position' */
void APAControl_Position(void)
{
  /* Outputs for Atomic SubSystem: '<S10>/Position_Precond' */
  Position_Precond();

  /* End of Outputs for SubSystem: '<S10>/Position_Precond' */

  /* Outputs for Enabled SubSystem: '<S10>/Position_AngleLoop' */
  Position_AngleLoop();

  /* End of Outputs for SubSystem: '<S10>/Position_AngleLoop' */
}

/* Output and update for atomic system: '<Root>/ADV_APA_FUNC' */
void ADV_APA_FUNC(void)
{
  /* Delay: '<S1>/Delay' */
  rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay =
    rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S1>/APAControl_Cond' */
  APAControl_Cond();

  /* End of Outputs for SubSystem: '<S1>/APAControl_Cond' */

  /* Outputs for Atomic SubSystem: '<S1>/APAControl_Logic' */
  APAControl_Logic();

  /* End of Outputs for SubSystem: '<S1>/APAControl_Logic' */

  /* Outputs for Atomic SubSystem: '<S1>/APAControl_Position' */
  APAControl_Position();

  /* End of Outputs for SubSystem: '<S1>/APAControl_Position' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

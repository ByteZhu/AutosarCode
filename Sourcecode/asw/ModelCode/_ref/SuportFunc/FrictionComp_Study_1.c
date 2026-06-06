/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FrictionComp_Study_1.c
 *
 * Code generated for Simulink model 'FrictionComp_Study_1'.
 *
 * Model version                  : 9.59
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jun  4 11:25:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FrictionComp_Study_1.h"
#include "rtwtypes.h"
#include "FrictionComp_Study_1_private.h"
#include "SimDiagEnum.h"
#include "CalVar.h"
#include "GlobalVar.h"
#include "asr_s32.h"
#include "plook_u32s16u32n32_lincpa_f.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "CalVarSupport.h"
#include "SimDiagMacroCAN.h"

/* Named constants for Chart: '<S2>/StudyProcess_Logic' */
#define IN_Calculate                   ((UInt8)1U)
#define IN_Init                        ((UInt8)2U)
#define IN_Process                     ((UInt8)3U)
#define IN_Wait                        ((UInt8)4U)

/* Exported data definition */

/* Definition for custom storage class: Localizable */
static UInt16 fca_strtrq_diffabs;      /* '<S5>/Switch' */
static UInt16 fca_strtrq_index;        /* '<S3>/Saturation' */
static Bool fca_strtrq_startflag;      /* '<S3>/Logical Operator5' */
static Int16 fca_strtrq_study;         /* '<S4>/Add1' */

/* Block signals and states (default storage) */
DW_l5cf_fcs rtDW_l5cf_fcs;

/* System initialize for atomic system: '<Root>/FCA_StudyDiffTrq' */
void FCA_StudyDiffTrq_Init(void)
{
  /* SystemInitialize for Chart: '<S1>/StudyDiffTrq_SheduleCounter' incorporates:
   *  SubSystem: '<S1>/StudyDiffTrq_Calc'
   */
  /* InitializeConditions for Delay: '<S5>/Delay' */
  rtDW_l5cf_fcs.icLoad = true;
}

/* Output and update for atomic system: '<Root>/FCA_StudyDiffTrq' */
void FCA_StudyDiffTrq(void)
{
  /* local block i/o variables */
  Int16 fca_strtrq_0orglast;
  Int32 rtb_diff_strtrq0;
  Int16 tmp;
  Int16 tmp_0;

  /* Chart: '<S1>/StudyDiffTrq_SheduleCounter' */
  /* Gateway: FCA_StudyDiffTrq/StudyDiffTrq_SheduleCounter */
  /* During: FCA_StudyDiffTrq/StudyDiffTrq_SheduleCounter */
  /* Entry Internal: FCA_StudyDiffTrq/StudyDiffTrq_SheduleCounter */
  /* Transition: '<S6>:137' */
  if (rtDW_l5cf_fcs.shedulecnt < Cal_FC_StudyDtTimer) {
    /* Transition: '<S6>:10' */
    /* Transition: '<S6>:19' */
    rtDW_l5cf_fcs.shedulecnt = (UInt16)((Int32)(((Int32)rtDW_l5cf_fcs.shedulecnt) + 1));

    /* Transition: '<S6>:121' */
  } else {
    /* Transition: '<S6>:96' */
    rtDW_l5cf_fcs.shedulecnt = 0U;

    /* Outputs for Function Call SubSystem: '<S1>/StudyDiffTrq_Calc' */
    /* Delay: '<S5>/Delay' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    /* Event: '<S6>:109' */
    if (rtDW_l5cf_fcs.icLoad) {
      rtDW_l5cf_fcs.Delay_DSTATE = Tv_StrTrq0Orig;
    }

    /* Delay: '<S5>/Delay' */
    fca_strtrq_0orglast = rtDW_l5cf_fcs.Delay_DSTATE;

    /* Signum: '<S5>/Sign1' incorporates:
     *  Delay: '<S5>/Delay'
     */
    if (fca_strtrq_0orglast < 0) {
      tmp = -1;
    } else {
      tmp = (Int16)((fca_strtrq_0orglast > 0) ? ((Int32)1) : ((Int32)0));
    }

    /* Signum: '<S5>/Sign' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    if (Tv_StrTrq0Orig < 0) {
      tmp_0 = -1;
    } else {
      tmp_0 = (Int16)((Tv_StrTrq0Orig > 0) ? ((Int32)1) : ((Int32)0));
    }

    /* Switch: '<S5>/Switch' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator'
     *  Signum: '<S5>/Sign'
     *  Signum: '<S5>/Sign1'
     */
    if (tmp == tmp_0) {
      /* Sum: '<S5>/Subtract' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       *  Delay: '<S5>/Delay'
       */
      rtb_diff_strtrq0 = ((Int32)Tv_StrTrq0Orig) - ((Int32)fca_strtrq_0orglast);

      /* Abs: '<S5>/Abs' incorporates:
       *  Sum: '<S5>/Subtract'
       */
      if (rtb_diff_strtrq0 < 0) {
        /* Switch: '<S5>/Switch' */
        fca_strtrq_diffabs = (UInt16)((Int32)(-rtb_diff_strtrq0));
      } else {
        /* Switch: '<S5>/Switch' */
        fca_strtrq_diffabs = (UInt16)rtb_diff_strtrq0;
      }

      /* End of Abs: '<S5>/Abs' */
    } else {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/Constant'
       */
      fca_strtrq_diffabs = (UInt16)0;
    }

    /* End of Switch: '<S5>/Switch' */

    /* Update for Delay: '<S5>/Delay' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    rtDW_l5cf_fcs.icLoad = false;
    rtDW_l5cf_fcs.Delay_DSTATE = Tv_StrTrq0Orig;

    /* End of Outputs for SubSystem: '<S1>/StudyDiffTrq_Calc' */
  }

  /* End of Chart: '<S1>/StudyDiffTrq_SheduleCounter' */
}

/* Output and update for atomic system: '<Root>/FCA_StudyProcess' */
void FCA_StudyProcess(void)
{
  Int16 temptorque;
  Int32 exitg1;
  Int32 tmp;
  Int16 FriCompAdptiveTorque;
  UInt16 b_index;

  /* Chart: '<S2>/StudyProcess_Logic' incorporates:
   *  Inport: '<Root>/Tv_dStrAng'
   *  Sum: '<S4>/Add1'
   */
  /* Gateway: FCA_StudyProcess/StudyProcess_Logic */
  /* During: FCA_StudyProcess/StudyProcess_Logic */
  if (((UInt32)rtDW_l5cf_fcs.bitsForTID0.is_active_c15_FrictionComp_Stud) == 0U) {
    /* Entry: FCA_StudyProcess/StudyProcess_Logic */
    rtDW_l5cf_fcs.bitsForTID0.is_active_c15_FrictionComp_Stud = 1U;

    /* Entry Internal: FCA_StudyProcess/StudyProcess_Logic */
    /* Transition: '<S7>:96' */
    rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 = IN_Init;

    /* Entry 'Init': '<S7>:94' */
    rtDW_l5cf_fcs.bitsForTID0.restartflag = true;
  } else {
    switch (rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1) {
     case IN_Calculate:
      /* During 'Calculate': '<S7>:7' */
      if (rtDW_l5cf_fcs.bitsForTID0.restartflag) {
        /* Transition: '<S7>:11' */
        rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 = IN_Init;

        /* Entry 'Init': '<S7>:94' */
        rtDW_l5cf_fcs.bitsForTID0.restartflag = true;
      } else {
        /* Transition: '<S7>:111' */
        /* Transition: '<S7>:113' */
        static uint8 nb_index = 0U;
        static Int32 sum=0;
        FriCompAdptiveTorque = 0;
        if (nb_index != 10U) {
            /* Transition: '<S7>:181' */
            /* Transition: '<S7>:115' */
            tmp = ((Int32)rtDW_l5cf_fcs.friction_up[nb_index]) - ((Int32)
              rtDW_l5cf_fcs.friction_down[nb_index]);
            if (tmp < 0) {
              tmp = -tmp;
            }
            sum = sum+tmp;
            nb_index = (nb_index + 1);
            /* Transition: '<S7>:183' */
          } else {
            FriCompAdptiveTorque =  (Int16)(sum/2);
              nb_index = 0;     //mod by liuyang
            /* Transition: '<S7>:179' */
          }
          
        // do {
        //   if (b_index != 10ULL) {
        //     /* Transition: '<S7>:181' */
        //     /* Transition: '<S7>:115' */
        //     tmp = ((Int32)rtDW_l5cf_fcs.friction_up[b_index]) - ((Int32)
        //       rtDW_l5cf_fcs.friction_down[b_index]);
        //     if (tmp < 0) {
        //       tmp = -tmp;
        //     }

        //     FriCompAdptiveTorque = (Int16)(((Int32)FriCompAdptiveTorque) + (tmp /
        //       2));
        //     b_index = (UInt16)((Int32)(((Int32)b_index) + 1));

        //     /* Transition: '<S7>:183' */
        //   } else {
        //     /* Transition: '<S7>:179' */
        //   }

        //   /* Transition: '<S7>:117' */
        //   /* Transition: '<S7>:119' */
        //   /* Transition: '<S7>:120' */
        // } while (b_index <= Cal_FC_StudyAngleIndexMax);//mod by liuyang

        /* Transition: '<S7>:122' */
        FriCompAdptiveTorque = (Int16)(((Int32)FriCompAdptiveTorque) / ((Int32)
          Cal_FC_StudyAngleIndexMax));
        if (FriCompAdptiveTorque > Cal_FC_StudyResultMax) {
          /* Transition: '<S7>:126' */
          /* Transition: '<S7>:130' */
          FriCompAdptiveTorque = Cal_FC_StudyResultMax;

          /* Transition: '<S7>:135' */
          /* Transition: '<S7>:173' */

          /* Transition: '<S7>:138' */
        } else if (FriCompAdptiveTorque < Cal_FC_StudyResultMin) {
          /* Transition: '<S7>:170' */
          /* Transition: '<S7>:172' */
          FriCompAdptiveTorque = Cal_FC_StudyResultMin;

          /* Transition: '<S7>:173' */
        } else {
          /* Transition: '<S7>:174' */
        }

        /* Transition: '<S7>:140' */
        if (Fv_FriCompAdptiveLearnCnt < Cal_FC_StudyFilterCnt) {
          /* Transition: '<S7>:142' */
          /* Transition: '<S7>:147' */
          Fv_FriCompAdptiveLearnCnt = (UInt16)((Int32)(((Int32)
            Fv_FriCompAdptiveLearnCnt) + 1));

          /* Transition: '<S7>:148' */
        } else {
          /* Transition: '<S7>:145' */
          Fv_FriCompAdptiveLearnCnt = Cal_FC_StudyFilterCnt;
        }

        /* Transition: '<S7>:137' */
        Tv_FriCompAdptiveTorque = (Int16)((((Int32)FriCompAdptiveTorque) +
          (((Int32)Tv_FriCompAdptiveTorque) * ((Int32)Fv_FriCompAdptiveLearnCnt)))
          / (((Int32)Fv_FriCompAdptiveLearnCnt) + 1));
        rtDW_l5cf_fcs.Fv_FriCompAdptiveTorque_pch4 = Tv_FriCompAdptiveTorque;

        /* Transition: '<S7>:157' */
        rtDW_l5cf_fcs.bitsForTID0.restartflag = true;
      }
      break;

     case IN_Init:
      /* During 'Init': '<S7>:94' */
      if (!rtDW_l5cf_fcs.bitsForTID0.restartflag) {
        /* Transition: '<S7>:95' */
        rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 = IN_Wait;
      } else {
        /* Transition: '<S7>:98' */
        /* Transition: '<S7>:100' */
        static  tb_index= 0U;
        if(tb_index <= Cal_FC_StudyAngleIndexMax) {
          /* Transition: '<S7>:102' */
          rtDW_l5cf_fcs.cnt_up[tb_index] = 0U;
          rtDW_l5cf_fcs.cnt_down[tb_index] = 0U;
          rtDW_l5cf_fcs.friction_up[tb_index] = 0;
          rtDW_l5cf_fcs.friction_down[tb_index] = 0;
          tb_index = (UInt16)((Int32)(((Int32)tb_index) + 1));

          /* Transition: '<S7>:104' */
          /* Transition: '<S7>:106' */
          /* Transition: '<S7>:107' */
        } else{
          tb_index= 0U;
        }    //mod by liuyang
        // b_index = 0U;
        // do {
        //   /* Transition: '<S7>:102' */
        //   rtDW_l5cf_fcs.cnt_up[b_index] = 0U;
        //   rtDW_l5cf_fcs.cnt_down[b_index] = 0U;
        //   rtDW_l5cf_fcs.friction_up[b_index] = 0;
        //   rtDW_l5cf_fcs.friction_down[b_index] = 0;
        //   b_index = (UInt16)((Int32)(((Int32)b_index) + 1));

        //   /* Transition: '<S7>:104' */
        //   /* Transition: '<S7>:106' */
        //   /* Transition: '<S7>:107' */
        // } while (b_index <= Cal_FC_StudyAngleIndexMax);

        /* Transition: '<S7>:109' */
        rtDW_l5cf_fcs.bitsForTID0.restartflag = false;
      }
      break;

     case IN_Process:
      /* During 'Process': '<S7>:6' */
      if (!fca_strtrq_startflag) {
        /* Transition: '<S7>:9' */
        rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 = IN_Wait;
      } else if (rtDW_l5cf_fcs.bitsForTID0.learnvalid) {
        /* Transition: '<S7>:10' */
        rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 = IN_Calculate;

        /* Entry 'Calculate': '<S7>:7' */
        rtDW_l5cf_fcs.bitsForTID0.learnvalid = false;
      } else {

        /* Transition: '<S7>:13' */
        /* Transition: '<S7>:17' */
        if (Tv_dStrAng > 0) {
          /* Transition: '<S7>:38' */
          /* Transition: '<S7>:42' */

          if (rtDW_l5cf_fcs.cnt_up[fca_strtrq_index] >= Cal_FC_StudyRepeatTimes) {
            /* Transition: '<S7>:44' */
            /* Transition: '<S7>:48' */
  
            rtDW_l5cf_fcs.friction_up[fca_strtrq_index] = (Int16)(((((Int32)
              rtDW_l5cf_fcs.friction_up[fca_strtrq_index]) * (((Int32)
              Cal_FC_StudyRepeatTimes) - 1)) + ((Int32)fca_strtrq_study)) /
              ((Int32)Cal_FC_StudyRepeatTimes));
                 
          }

          else {
            /* Transition: '<S7>:46' */
            rtDW_l5cf_fcs.cnt_up[fca_strtrq_index] = (UInt16)((Int32)(((Int32)
              rtDW_l5cf_fcs.cnt_up[fca_strtrq_index]) + 1));
            rtDW_l5cf_fcs.friction_up[fca_strtrq_index] = (Int16)(((((Int32)
              rtDW_l5cf_fcs.friction_up[fca_strtrq_index]) * (((Int32)
              rtDW_l5cf_fcs.cnt_up[fca_strtrq_index]) - 1)) + ((Int32)
              fca_strtrq_study)) / ((Int32)rtDW_l5cf_fcs.cnt_up[fca_strtrq_index]));

            /* Transition: '<S7>:49' */
          }

          /* Transition: '<S7>:58' */

          /* Transition: '<S7>:40' */
        } else if (rtDW_l5cf_fcs.cnt_down[fca_strtrq_index] >=
                   Cal_FC_StudyRepeatTimes) {
  
          /* Transition: '<S7>:51' */
          /* Transition: '<S7>:55' */
          rtDW_l5cf_fcs.friction_down[fca_strtrq_index] = (Int16)(((((Int32)
            rtDW_l5cf_fcs.friction_down[fca_strtrq_index]) * (((Int32)
            Cal_FC_StudyRepeatTimes) - 1)) + ((Int32)fca_strtrq_study)) /
            ((Int32)Cal_FC_StudyRepeatTimes));
        } else {
          /* Transition: '<S7>:53' */
          rtDW_l5cf_fcs.cnt_down[fca_strtrq_index] = (UInt16)((Int32)(((Int32)
            rtDW_l5cf_fcs.cnt_down[fca_strtrq_index]) + 1));
          rtDW_l5cf_fcs.friction_down[fca_strtrq_index] = (Int16)(((((Int32)
            rtDW_l5cf_fcs.friction_down[fca_strtrq_index]) * (((Int32)
            rtDW_l5cf_fcs.cnt_down[fca_strtrq_index]) - 1)) + ((Int32)
            fca_strtrq_study)) / ((Int32)rtDW_l5cf_fcs.cnt_down[fca_strtrq_index]));

          /* Transition: '<S7>:56' */

          /* Transition: '<S7>:59' */
        }

        /* Transition: '<S7>:61' */
    
       static uint16 TempIndex = 0;

          if ((rtDW_l5cf_fcs.cnt_down[TempIndex] < Cal_FC_StudyRepeatTimes) ||
              (rtDW_l5cf_fcs.cnt_up[TempIndex] < Cal_FC_StudyRepeatTimes)) {
            /* Transition: '<S7>:67' */
            /* Transition: '<S7>:69' */
            rtDW_l5cf_fcs.bitsForTID0.learnvalid = false;
            TempIndex = 0;
          } 
          else{
            if (TempIndex <= Cal_FC_StudyAngleIndexMax) {
              TempIndex = (UInt16)(TempIndex + 1);
            } else {
              /* Transition: '<S7>:79' */
              rtDW_l5cf_fcs.bitsForTID0.learnvalid = true;
              /* Transition: '<S7>:80' */
               TempIndex = 0;
            }
        }   //mod by liuyang
        //debug_jing3 = TempIndex;

           

        // do {
        //   exitg1 = 0;
        //   if ((rtDW_l5cf_fcs.cnt_down[b_index] < Cal_FC_StudyRepeatTimes) ||
        //       (rtDW_l5cf_fcs.cnt_up[b_index] < Cal_FC_StudyRepeatTimes)) {
        //     /* Transition: '<S7>:67' */
        //     /* Transition: '<S7>:69' */
        //     rtDW_l5cf_fcs.bitsForTID0.learnvalid = false;
        //     exitg1 = 1;
        //   } else {
        //     /* Transition: '<S7>:71' */
        //     b_index = (UInt16)((Int32)(((Int32)b_index) + 1));
        //     if (b_index <= Cal_FC_StudyAngleIndexMax) {
        //       /* Transition: '<S7>:74' */
        //       /* Transition: '<S7>:76' */
        //       /* Transition: '<S7>:77' */
        //     } else {
        //       /* Transition: '<S7>:79' */
        //       rtDW_l5cf_fcs.bitsForTID0.learnvalid = true;

        //       /* Transition: '<S7>:80' */
        //       exitg1 = 1;
        //     }
        //   }
        // } while (exitg1 == 0);

//#endif
      }

    //  debug_jing2 = rtDW_l5cf_fcs.bitsForTID0.learnvalid|fca_strtrq_startflag<<1;
      break;

     default:
      /* During 'Wait': '<S7>:4' */
      if (fca_strtrq_startflag) {
        /* Transition: '<S7>:8' */
        rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 = IN_Process;
      }
      break;
    }
       // debug_jing1 = rtDW_l5cf_fcs.bitsForTID0.is_c15_FrictionComp_Study_1 ;
  }

  /* End of Chart: '<S2>/StudyProcess_Logic' */

  /* Product: '<S2>/Product' incorporates:
   *  Lookup_n-D: '<S3>/vehspd_coef_tab'
   */
    temptorque =   (Int16)asr_s32(((Int32)
     rtDW_l5cf_fcs.Fv_FriCompAdptiveTorque_pch4) * ((Int32)rtDW_l5cf_fcs.vehspd_coef_tab),
     7U);
    if(temptorque!=0){
      Fv_FriCompAdptiveTorqueTemp = temptorque;
    }
  // Fv_FriCompAdptiveTorque = (Int16)asr_s32(((Int32)
  //   rtDW_l5cf_fcs.Fv_FriCompAdptiveTorque_pch4) * ((Int32)rtDW_l5cf_fcs.vehspd_coef_tab),
  //   7U);
   // debug_jing1 = (Int32)rtDW_l5cf_fcs.vehspd_coef_tab;
    //debug_jing2 = fca_strtrq_startflag;
}

/* Output and update for atomic system: '<Root>/FCA_StudyStartCond' */
void FCA_StudyStartCond(void)
{
  /* local block i/o variables */
  Bool fca_strtrq_strght;
  UInt32 rtb_anglebreakpoints_o1;
  UInt32 rtb_anglebreakpoints_o2;
  Int16 rtb_Abs1;
  Int16 rtb_angabs;
  Int16 tmp;
  Int16 tmp_0;

  /* Abs: '<S3>/Abs' incorporates:
   *  Inport: '<Root>/Tv_StrAng_Raw'
   */
  if (Tv_StrAng_Raw < 0) {
    rtb_angabs = (Int16)(-Tv_StrAng_Raw);
  } else {
    rtb_angabs = Tv_StrAng_Raw;
  }

  /* End of Abs: '<S3>/Abs' */

  /* Abs: '<S3>/Abs1' incorporates:
   *  Inport: '<Root>/Tv_dStrAng'
   */
  if (Tv_dStrAng < 0) {
    rtb_Abs1 = (Int16)(-Tv_dStrAng);
  } else {
    rtb_Abs1 = Tv_dStrAng;
  }

  /* End of Abs: '<S3>/Abs1' */

  /* Chart: '<S3>/phyflag_strght' incorporates:
   *  Abs: '<S3>/Abs'
   *  Constant: '<S15>/Constant'
   *  DataStoreRead: '<S3>/Data Store Read'
   *  RelationalOperator: '<S15>/Compare'
   */
  /* Gateway: FCA_StudyStartCond/phyflag_strght */
  /* During: FCA_StudyStartCond/phyflag_strght */
  /* Entry Internal: FCA_StudyStartCond/phyflag_strght */
  /* Transition: '<S24>:32' */
  if ((Fv_AOC_StraightFlag) && (!rtDW_l5cf_fcs.bitsForTID0.lastflag)) {
    /* Transition: '<S24>:24' */
    /* Transition: '<S24>:3' */
    rtDW_l5cf_fcs.bitsForTID0.strght_trg = true;
  } else {
    /* Transition: '<S24>:27' */
    /* Transition: '<S24>:28' */
  }

  /* Transition: '<S24>:34' */
  rtDW_l5cf_fcs.bitsForTID0.lastflag = Fv_AOC_StraightFlag;
  if ((rtDW_l5cf_fcs.bitsForTID0.strght_trg) && (Fv_AOC_StraightFlag)) {
    /* Transition: '<S24>:5' */
    if (rtDW_l5cf_fcs.strght_cnt < Cal_FC_StudyStrghtTmr) {
      /* Transition: '<S24>:7' */
      /* Transition: '<S24>:9' */
      rtDW_l5cf_fcs.strght_cnt = (UInt16)((Int32)(((Int32)rtDW_l5cf_fcs.strght_cnt) + 1));

      /* Transition: '<S24>:12' */
    } else {
      /* Transition: '<S24>:11' */
      rtDW_l5cf_fcs.strght_flag = true;
    }

    /* Transition: '<S24>:15' */
    /* Transition: '<S24>:40' */

    /* Transition: '<S24>:14' */
  } else if (!Fv_AOC_StraightFlag) {
    /* Transition: '<S24>:37' */
    /* Transition: '<S24>:39' */
    rtDW_l5cf_fcs.bitsForTID0.strght_trg = false;
    rtDW_l5cf_fcs.strght_cnt = 0U;

    /* Transition: '<S24>:40' */
  } else {
    /* Transition: '<S24>:41' */
  }

  /* Transition: '<S24>:17' */
  if (rtb_angabs > Cal_FC_StudyStrghtRec) {
    /* Transition: '<S24>:19' */
    /* Transition: '<S24>:22' */
    rtDW_l5cf_fcs.strght_flag = false;
    rtDW_l5cf_fcs.bitsForTID0.strght_trg = false;
    rtDW_l5cf_fcs.strght_cnt = 0U;

    /* Transition: '<S24>:31' */
  } else {
    /* Transition: '<S24>:30' */
  }

  /* End of Chart: '<S3>/phyflag_strght' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  if (((UInt8)MACRO_FC_STRAIGHTCOND) != 0ULL) {
    /* Switch: '<S3>/Switch' */
    fca_strtrq_strght = rtDW_l5cf_fcs.strght_flag;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    fca_strtrq_strght = true;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Abs: '<S3>/Abs3' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  if (Tv_StrTrq0Orig < 0) {
    tmp = (Int16)(-Tv_StrTrq0Orig);
  } else {
    tmp = Tv_StrTrq0Orig;
  }

  /* Abs: '<S3>/Abs2' incorporates:
   *  Inport: '<Root>/Tv_ddStrAng'
   */
  if (Tv_ddStrAng < 0) {
    tmp_0 = (Int16)(-Tv_ddStrAng);
  } else {
    tmp_0 = Tv_ddStrAng;
  }

  /* Logic: '<S3>/Logical Operator5' incorporates:
   *  Abs: '<S3>/Abs'
   *  Abs: '<S3>/Abs1'
   *  Abs: '<S3>/Abs2'
   *  Abs: '<S3>/Abs3'
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read3'
   *  DataStoreRead: '<S3>/Data Store Read4'
   *  DataStoreRead: '<S3>/Data Store Read5'
   *  DataStoreRead: '<S3>/Data Store Read6'
   *  DataStoreRead: '<S3>/Data Store Read7'
   *  DataStoreRead: '<S3>/Data Store Read8'
   *  Inport: '<Root>/Fv_VehSpdNew'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S3>/Logical Operator3'
   *  Logic: '<S3>/Logical Operator6'
   *  Logic: '<S3>/Logical Operator7'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Switch: '<S5>/Switch'
   */
  fca_strtrq_startflag = ((((((Fv_AbsInvalidFlag == false) && (Fv_HighFailFlag ==
    0)) && (Fv_AngleMidValidFlag == ANGLE_STS_Valid)) && (Fv_AngleReadyFlag ==
    HELLA_STS_Decode)) && (Fv_LowFailFlag == 0)) && ((((((((((Int32)
    fca_strtrq_diffabs) <= ((Int32)Cal_FC_StudyTrqGridMax)) && (tmp <=
    Cal_FC_StudyTrqMax)) && ((Fv_VehSpdNew <= Cal_FC_StudyVehMax) &&
    (Fv_VehSpdNew >= Cal_FC_StudyVehMin))) && ((rtb_Abs1 <= Cal_FC_StudyRevMax) &&
    (rtb_Abs1 >= Cal_FC_StudyRevMin))) && (tmp_0 <= Cal_FC_StudyAccelMax)) &&
    ((Fv_TempSysCel <= Cal_FC_StudyTempMax) && (Fv_TempSysCel >=
    Cal_FC_StudyTempMin))) && (rtb_angabs <= Cal_FC_StudyAngleMax)) &&
    (fca_strtrq_strght)));
/*debug_jing3 = (((Int32)fca_strtrq_diffabs) <= ((Int32)Cal_FC_StudyTrqGridMax)) |(tmp <= Cal_FC_StudyTrqMax)<<1|
((Fv_VehSpdNew <= Cal_FC_StudyVehMax) && (Fv_VehSpdNew >= Cal_FC_StudyVehMin))<<2 |
(rtb_Abs1 <= Cal_FC_StudyRevMax)<<3| (rtb_Abs1 >= Cal_FC_StudyRevMin)<<4|(tmp_0 <= Cal_FC_StudyAccelMax)<<5|
(rtb_angabs <= Cal_FC_StudyAngleMax)<<6 |(fca_strtrq_strght)<<7;*/
  /* PreLookup: '<S3>/anglebreakpoints' incorporates:
   *  Inport: '<Root>/Tv_StrAng_Raw'
   */
  rtb_anglebreakpoints_o1 = plook_u32s16u32n32_lincpa_f(Tv_StrAng_Raw, (const
    Int16 *)&Cal_FC_StudyAngleBreakPoints[0], 21U, &rtb_anglebreakpoints_o2,
    &rtDW_l5cf_fcs.anglebreakpoints_DWORK1);

  /* Saturate: '<S3>/Saturation' */
  if (rtb_anglebreakpoints_o1 <= ((UInt32)Cal_FC_StudyAngleIndexMax)) {
    fca_strtrq_index = (UInt16)rtb_anglebreakpoints_o1;
  } else {
    fca_strtrq_index = Cal_FC_StudyAngleIndexMax;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Lookup_n-D: '<S3>/vehspd_coef_tab' incorporates:
   *  Inport: '<Root>/Fv_VehSpdNew'
   */
  rtDW_l5cf_fcs.vehspd_coef_tab = look1_iu16ls32n10ts16D_QWHCuzIb(Fv_VehSpdNew, (
    const UInt16 *)&Cal_FC_VehSpdCoef_X[0], (const Int16 *)&Cal_FC_VehSpdCoef_Y
    [0], &rtDW_l5cf_fcs.m_bpIndex, 4U);
}

/* Output and update for atomic system: '<Root>/FCA_StudyTorque' */
void FCA_StudyTorque(void)
{
  Int16 rtb_Add_bw5t;

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant3'
   *  DataStoreRead: '<Root>/Data Store Read'
   *  DataStoreRead: '<Root>/Data Store Read8'
   *  DataTypeConversion: '<S25>/FixPt Gateway Out'
   *  DataTypeConversion: '<S26>/FixPt Gateway Out'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Product: '<S4>/Product1'
   */
  rtb_Add_bw5t = (Int16)(asr_s32((Int32)Tv_StrTrq0Orig, 6U) - ((Int32)((Int16)
    asr_s32(Fv_MotorCurrent_Qact * ((Int32)Cal_FC_CURRENT2STEERTORQUE), 3U))));

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<S4>/c1'
   *  Constant: '<S4>/c2'
   *  Constant: '<S4>/c3'
   *  Delay: '<S4>/Delay'
   *  Delay: '<S4>/Delay1'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Sum: '<S4>/Add'
   */
  fca_strtrq_study = (Int16)((((Int16)asr_s32(((Int32)4) * ((Int32)rtb_Add_bw5t),
    7U)) + ((Int16)asr_s32(((Int32)rtDW_l5cf_fcs.Delay_DSTATE_oagu) * ((Int32)4), 7U)))
    + ((Int16)asr_s32(((Int32)120) * ((Int32)fca_strtrq_study), 7U)));

  /* Update for Delay: '<S4>/Delay' incorporates:
   *  Sum: '<S4>/Add'
   */
  rtDW_l5cf_fcs.Delay_DSTATE_oagu = rtb_Add_bw5t;
}

/* Model step function */
void FrictionComp_Study_1_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/FCA_StudyTorque' */
  FCA_StudyTorque();

  /* End of Outputs for SubSystem: '<Root>/FCA_StudyTorque' */

  /* Outputs for Atomic SubSystem: '<Root>/FCA_StudyDiffTrq' */
  FCA_StudyDiffTrq();

  /* End of Outputs for SubSystem: '<Root>/FCA_StudyDiffTrq' */

  /* Outputs for Atomic SubSystem: '<Root>/FCA_StudyStartCond' */
  FCA_StudyStartCond();

  /* End of Outputs for SubSystem: '<Root>/FCA_StudyStartCond' */

  /* Outputs for Atomic SubSystem: '<Root>/FCA_StudyProcess' */
  FCA_StudyProcess();

  /* End of Outputs for SubSystem: '<Root>/FCA_StudyProcess' */
}

/* Model initialize function */
void FrictionComp_Study_1_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/FCA_StudyDiffTrq' */
  FCA_StudyDiffTrq_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/FCA_StudyDiffTrq' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: AngleOffsetComp.c
 *
 * Code generated for Simulink model 'AngleOffsetComp'.
 *
 * Model version                  : 1.1172
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Nov 25 12:23:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AngleOffsetComp.h"
#include "AngleOffsetComp_private.h"
#include "asr_s32.h"
#include "look1_iu16ls32n10tu16_plinlcase.h"

/* Named constants for Chart: '<S4>/Apull_integ' */
#define AngleOffsetComp_IN_Process     ((UInt8)1U)
#define AngleOffsetComp_IN_Wait        ((UInt8)2U)

/* Named constants for Chart: '<S18>/Apull_integ' */
#define AngleOffsetComp_IN_Process_aivy ((UInt8)1U)
#define AngleOffsetComp_IN_Wait_dv5d   ((UInt8)2U)

/* Exported data definition */

/* Definition for custom storage class: Localizable */
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

static Bool angcrr_active;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

static Int16 angcrr_ang;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

static Int16 angcrr_angoffset;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

static Bool angcrr_calccond;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

static Bool angcrr_learncond;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

static Bool angcrr_midvalid;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

static Bool angcrr_precond;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

static UInt16 angcrr_vsgain;

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

static UInt16 angcrr_vsgainbyd;

#endif

/* Block states (default storage) */
AngleOffsetComp_DW_fwu4 AngleOffsetComprtDW;

/* Output and update for atomic system: '<S2>/AngleOffsetComp_Apull' */
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

void AngleOffs_AngleOffsetComp_Apull(void)
{
#define MACRO_APC_GAINITG_MAX 32768
  /* Chart: '<S4>/Apull_integ' */
  /* Gateway: AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Apull/Apull_integ */
  /* During: AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Apull/Apull_integ */
  if (((UInt32)
       AngleOffsetComprtDW.AngleOffsetComp_ctk5.bitsForTID0.is_active_c1_AngleOffsetComp)
      == 0U) {
    /* Entry: AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Apull/Apull_integ */
    AngleOffsetComprtDW.AngleOffsetComp_ctk5.bitsForTID0.is_active_c1_AngleOffsetComp
      = 1;

    /* Entry Internal: AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Apull/Apull_integ */
    /* Transition: '<S6>:371' */
    AngleOffsetComprtDW.AngleOffsetComp_ctk5.bitsForTID0.is_c1_AngleOffsetComp =
      AngleOffsetComp_IN_Wait;
  } else if (((UInt32)
              AngleOffsetComprtDW.AngleOffsetComp_ctk5.bitsForTID0.is_c1_AngleOffsetComp)
             == AngleOffsetComp_IN_Process) {
    /* During 'Process': '<S6>:372' */
    if (!angcrr_precond) {
      /* Transition: '<S6>:374' */
      AngleOffsetComprtDW.AngleOffsetComp_ctk5.bitsForTID0.is_c1_AngleOffsetComp
        = AngleOffsetComp_IN_Wait;
    } else {
      /* Transition: '<S6>:388' */
      if (angcrr_calccond) {
        /* Transition: '<S6>:390' */
        if (AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_straight_cnt <
            Cal_APC_MONITOR_TMR) {
          /* Transition: '<S6>:392' */
          /* Transition: '<S6>:394' */
          AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_straight_cnt = (UInt16)
            ((Int32)(((Int32)
                      AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_straight_cnt)
                     + 1));

          /* Transition: '<S6>:420' */
          /* Transition: '<S6>:416' */
          /* Transition: '<S6>:419' */
        } else {
          /* Transition: '<S6>:396' */
          AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_gain += (Int32)
            angcrr_vsgain;
          if (AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_gain > ((Int32)
        		  MACRO_APC_GAINITG_MAX)) {
            /* Transition: '<S6>:398' */
            /* Transition: '<S6>:400' */
            AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_gain = (Int32)
		MACRO_APC_GAINITG_MAX;

            /* Transition: '<S6>:403' */
          } else {
            /* Transition: '<S6>:402' */
          }

          /* Transition: '<S6>:405' */
          AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last = (Int16)
            ((((((Int32)angcrr_ang) - ((Int32)
                 AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last)) *
               AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_gain) / ((Int32)
            		   MACRO_APC_GAINITG_MAX)) + ((Int32)
              AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last));
          if (AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last >
          MACRO_APC_GAINITG_MAX) {
            /* Transition: '<S6>:407' */
            /* Transition: '<S6>:409' */
            Fv_AngleCorrectAim = MACRO_APC_GAINITG_MAX;

            /* Transition: '<S6>:416' */
            /* Transition: '<S6>:419' */
          } else {
            /* Transition: '<S6>:411' */
            if (AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last <
                (-MACRO_APC_GAINITG_MAX)) {
              /* Transition: '<S6>:413' */
              /* Transition: '<S6>:415' */
              Fv_AngleCorrectAim = (Int16)(-MACRO_APC_GAINITG_MAX);

              /* Transition: '<S6>:419' */
            } else {
              /* Transition: '<S6>:418' */
              Fv_AngleCorrectAim =
                AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last;
            }
          }
        }

        /* Transition: '<S6>:423' */
      } else {
        /* Transition: '<S6>:422' */
        AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_straight_cnt = 0U;
        AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_gain = 0;
      }
    }
  } else {
    /* During 'Wait': '<S6>:370' */
    if (angcrr_precond) {
      /* Transition: '<S6>:373' */
      AngleOffsetComprtDW.AngleOffsetComp_ctk5.bitsForTID0.is_c1_AngleOffsetComp
        = AngleOffsetComp_IN_Process;

      /* Entry 'Process': '<S6>:372' */
      AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last =
        Fv_AngleCorrectLast;
    } else {
      /* Transition: '<S6>:376' */
      if (angcrr_midvalid) {
        /* Transition: '<S6>:378' */
        /* Transition: '<S6>:380' */
        AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_gain = 0;
        AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_straight_cnt = 0U;
        AngleOffsetComprtDW.AngleOffsetComp_ctk5.apc_offset_last = 0;

        /* Transition: '<S6>:383' */
      } else {
        /* Transition: '<S6>:382' */
      }
    }
  }
#undef MACRO_APC_GAINITG_MAX
  /* End of Chart: '<S4>/Apull_integ' */
}

#endif

/* Output and update for atomic system: '<S2>/AngleOffsetComp_Straight' */
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

void AngleO_AngleOffsetComp_Straight(void)
{
  /* local block i/o variables */
  Int32 angcrr_wssum;
  Int32 angcrr_wsdiff;
  Bool angcrr_wszero;
  Int32 u;
  Int16 tmp;
  Int16 tmp_0;
  Int16 tmp_1;
  Bool tmp_2;

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  DataStoreRead: '<S5>/Data Store Read9'
   */
  angcrr_midvalid = (Fv_AngleMidValidFlag == ANGLE_STS_Valid);

  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<S5>/Data Store Read10'
   *  DataStoreRead: '<S5>/Data Store Read11'
   *  DataStoreRead: '<S5>/Data Store Read7'
   *  DataStoreRead: '<S5>/Data Store Read8'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  angcrr_precond = (((((Fv_AngleCorrectStoredValid == true) && (angcrr_midvalid))
                      && (Fv_HighFailFlag == 0)) && (Fv_AbsInvalidFlag == false))
                    && (Fv_WhsInvalidFlag == false));

  /* Sum: '<S5>/Add2' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read2'
   *  DataStoreRead: '<S5>/Data Store Read3'
   */
  angcrr_ang = (Int16)(Fv_StrAng - Fv_StrAngOffset);

  /* Logic: '<S5>/Logical Operator2' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  DataStoreRead: '<S5>/Data Store Read'
   *  DataStoreRead: '<S5>/Data Store Read1'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   */
  angcrr_wszero = ((Fv_WheelSpeed_FR == ((UInt16)0U)) && (Fv_WheelSpeed_FL ==
    ((UInt16)0U)));

  /* Sum: '<S5>/Add' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read'
   *  DataStoreRead: '<S5>/Data Store Read1'
   */
  angcrr_wssum = (Int32)((UInt32)(((UInt32)Fv_WheelSpeed_FL) + ((UInt32)
    Fv_WheelSpeed_FR)));

  /* Sum: '<S5>/Add1' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read'
   *  DataStoreRead: '<S5>/Data Store Read1'
   */
  u = ((Int32)Fv_WheelSpeed_FL) - ((Int32)Fv_WheelSpeed_FR);

  /* Abs: '<S5>/Abs3' */
  if (u < 0) {
    u = -u;
  }

  /* End of Abs: '<S5>/Abs3' */

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant'
   */
  angcrr_wsdiff = u * ((Int32)Cal_APC_MONITOR_CEF);

  /* Abs: '<S5>/Abs' */
  if (angcrr_ang < 0) {
    tmp = (Int16)(-angcrr_ang);
  } else {
    tmp = angcrr_ang;
  }

  /* End of Abs: '<S5>/Abs' */

  /* Abs: '<S5>/Abs1' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read4'
   */
  if (Fv_HellaFirlterRev < 0) {
    tmp_0 = (Int16)(-Fv_HellaFirlterRev);
  } else {
    tmp_0 = Fv_HellaFirlterRev;
  }

  /* End of Abs: '<S5>/Abs1' */

  /* Abs: '<S5>/Abs2' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read5'
   */
  if (Fv_StrTrq0 < 0) {
    tmp_1 = (Int16)(-Fv_StrTrq0);
  } else {
    tmp_1 = Fv_StrTrq0;
  }

  /* End of Abs: '<S5>/Abs2' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (angcrr_wszero) {
    tmp_2 = false;
  } else {
    tmp_2 = (angcrr_wssum >= angcrr_wsdiff);
  }

  /* End of Switch: '<S5>/Switch' */

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataStoreRead: '<S5>/Data Store Read6'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   */
  angcrr_calccond = (((((tmp <= Cal_APC_MONITOR_ANG) && (tmp_0 <=
    Cal_APC_MONITOR_REV)) && (tmp_1 <= Cal_APC_MONITOR_TRQ)) && (Fv_VehSpd0 >=
    Cal_APC_MONITOR_VHS)) && tmp_2);

  /* Lookup_n-D: '<S5>/vs_aoftgain' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read6'
   */
  angcrr_vsgain = look1_iu16ls32n10tu16_plinlcase(Fv_VehSpd0, ((const UInt16 *)
    &(Cal_APC_MONITOR_VsTab_X[0])), ((const UInt16 *)&(Cal_APC_MONITOR_VsTab_Y[0])),
    &AngleOffsetComprtDW.AngleOffsetComp_ctk5.m_bpIndex, 4U);
}

#endif

/* Output and update for atomic system: '<S3>/AngleOffsetComp_Apull' */
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

void Angl_AngleOffsetComp_Apull_hldl(void)
{
#define MACRO_APC_GAINITG_MAX 32768
  Int16 temp_s16;
  /* Chart: '<S18>/Apull_integ' */
  /* Gateway: AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Apull/Apull_integ */
  /* During: AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Apull/Apull_integ */
  if (((UInt32)
       AngleOffsetComprtDW.AngleOffsetComp_BYD.bitsForTID0.is_active_c2_AngleOffsetComp)
      == 0U) {
    /* Entry: AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Apull/Apull_integ */
    AngleOffsetComprtDW.AngleOffsetComp_BYD.bitsForTID0.is_active_c2_AngleOffsetComp
      = 1;

    /* Entry Internal: AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Apull/Apull_integ */
    /* Transition: '<S20>:371' */
    AngleOffsetComprtDW.AngleOffsetComp_BYD.bitsForTID0.is_c2_AngleOffsetComp =
      AngleOffsetComp_IN_Wait_dv5d;

    /* Entry 'Wait': '<S20>:370' */
    AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt = 0U;
    AngleOffsetComprtDW.AngleOffsetComp_BYD.angcrr_angopt = 0;
  } else if (((UInt32)
              AngleOffsetComprtDW.AngleOffsetComp_BYD.bitsForTID0.is_c2_AngleOffsetComp)
             == AngleOffsetComp_IN_Process_aivy) {
    /* During 'Process': '<S20>:372' */
    if (!angcrr_active) {
      /* Transition: '<S20>:374' */
      AngleOffsetComprtDW.AngleOffsetComp_BYD.bitsForTID0.is_c2_AngleOffsetComp =
        AngleOffsetComp_IN_Wait_dv5d;

      /* Entry 'Wait': '<S20>:370' */
      AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt = 0U;
      AngleOffsetComprtDW.AngleOffsetComp_BYD.angcrr_angopt = 0;
    } else {
      /* Transition: '<S20>:388' */
      if (angcrr_learncond) {
        /* Transition: '<S20>:390' */
        if (AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt <
            Cal_APC_MONITOR_TMR) {
          /* Transition: '<S20>:392' */
          /* Transition: '<S20>:394' */
          AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt = (UInt16)
            ((Int32)(((Int32)
                      AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt)
                     + 1));

          /* Transition: '<S20>:427' */
        } else {
          /* Transition: '<S20>:396' */
          AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_gain = (Int32)angcrr_vsgainbyd;
          if (AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_gain > ((Int32)
               MACRO_APC_GAINITG_MAX)) {
            /* Transition: '<S20>:398' */
            /* Transition: '<S20>:400' */
            AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_gain = (Int32)
              MACRO_APC_GAINITG_MAX;

            /* Transition: '<S20>:403' */
          } else {
            /* Transition: '<S20>:402' */
          }

          /* Transition: '<S20>:405' */
          AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_offset_last = (Int32)
            ((((((float32)angcrr_angoffset*MACRO_APC_GAINITG_MAX) - ((float32)
                 AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_offset_last)) *
               AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_gain)/MACRO_APC_GAINITG_MAX) + ((Int32)
              AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_offset_last));

          temp_s16 = (Int16)(AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_offset_last/MACRO_APC_GAINITG_MAX);

          if (temp_s16 > Cal_APC_MONITOR_ANG) {
            /* Transition: '<S20>:407' */
            /* Transition: '<S20>:409' */
            Fv_AngleCorrectAim = Cal_APC_MONITOR_ANG;

            /* Transition: '<S20>:416' */
            /* Transition: '<S20>:419' */
          } else {
            /* Transition: '<S20>:411' */
            if (temp_s16 <(-Cal_APC_MONITOR_ANG)) {
              /* Transition: '<S20>:413' */
              /* Transition: '<S20>:415' */
              Fv_AngleCorrectAim = (Int16)(-Cal_APC_MONITOR_ANG);

              /* Transition: '<S20>:419' */
            } else {
              /* Transition: '<S20>:418' */
              Fv_AngleCorrectAim = temp_s16;
            }
          }

          /* Transition: '<S20>:428' */
         // AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt = 0U;
        }

        /* Transition: '<S20>:429' */
      } else {
        /* Transition: '<S20>:422' */
        AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_straight_cnt = 0U;
        AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_gain = 0;
      }

      /* Transition: '<S20>:435' */
      AngleOffsetComprtDW.AngleOffsetComp_BYD.angcrr_angopt = Fv_AngleCorrectAim;
    }
  } else {
    /* During 'Wait': '<S20>:370' */
    if (angcrr_active) {
      /* Transition: '<S20>:373' */
      AngleOffsetComprtDW.AngleOffsetComp_BYD.bitsForTID0.is_c2_AngleOffsetComp =
        AngleOffsetComp_IN_Process_aivy;

      /* Entry 'Process': '<S20>:372' */
      AngleOffsetComprtDW.AngleOffsetComp_BYD.apc_offset_last =//2^19
        (Int32)Fv_AngleCorrectLast*MACRO_APC_GAINITG_MAX;
    } else {
      AngleOffsetComprtDW.AngleOffsetComp_BYD.angcrr_angopt = 0;
    }
  }

  /* End of Chart: '<S18>/Apull_integ' */

  /* Gain: '<S18>/Gain' incorporates:
   *  DataStoreWrite: '<S18>/Data Store Write'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   */
  Fv_AngleCorrectOpr = (Int16)asr_s32(((Int32)26214) * ((Int32)((Int16)
    (AngleOffsetComprtDW.AngleOffsetComp_BYD.angcrr_angopt * 16))), 18U);

#undef MACRO_APC_GAINITG_MAX

}

#endif

/* Output and update for atomic system: '<S3>/AngleOffsetComp_Straight' */
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

void A_AngleOffsetComp_Straight_d1qu(void)
{
  Int16 rtb_Constant2;
  Bool rtb_LogicalOperator3;
  Bool rtb_LogicalOperator3_jutd;
  Bool rtb_LogicalOperator3_krld;
  Bool rtb_LogicalOperator3_1;
  Bool rtb_LogicalOperator4;
  Int16 rtb_Add4_j0hv;
  Int32 u;
  Int16 tmp;
  Int16 tmp_0;
  UInt32 rtb_LogicalOperator3_tmp;

  Bool con1 = 0;
  Bool con2 = 0;
  Bool con3 = 0;
  Bool con4 = 0;
  Bool con5 = 0;
  Bool con2_1 = 0;
  Bool con2_2 = 0;


  /* Sum: '<S19>/Add3' incorporates:
   *  Delay: '<S19>/Delay1'
   *  Gain: '<S19>/Gain2'
   *  Sum: '<S19>/Add1'
   */
  rtb_Constant2 = Fv_YawRateDegreeAcc;

  /* Abs: '<S19>/Abs3' */
  if (rtb_Constant2 < 0) {
    rtb_Constant2 = (Int16)(-rtb_Constant2);
  }

  /* End of Abs: '<S19>/Abs3' */
  /* Sum: '<S36>/Add3' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read15'
   *  DataStoreRead: '<S19>/Data Store Read20'
   */
  u = ((Int32)CAN_RLWS) - ((Int32)CAN_VehSpd0);

  /* Abs: '<S36>/Abs4' */
  if (u < 0) {
    u = -u;
  }

  /* End of Abs: '<S36>/Abs4' */

  /* Gain: '<S36>/Gain1' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read20'
   *  Gain: '<S34>/Gain1'
   *  Gain: '<S35>/Gain1'
   *  Gain: '<S37>/Gain1'
   */
  rtb_LogicalOperator3_tmp = ((UInt32)((UInt8)55U)) * ((UInt32)CAN_VehSpd0);

  /* Logic: '<S36>/Logical Operator3' incorporates:
   *  Constant: '<S36>/Constant2'
   *  Delay: '<S36>/Delay'
   *  Gain: '<S36>/Gain'
   *  Gain: '<S36>/Gain1'
   *  RelationalOperator: '<S36>/Relational Operator1'
   *  RelationalOperator: '<S36>/Relational Operator2'
   */
  rtb_LogicalOperator3 = (rtb_LogicalOperator3_tmp > ((Int32)10000 * u));

  /* Sum: '<S37>/Add3' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read17'
   *  DataStoreRead: '<S19>/Data Store Read20'
   */
  u = ((Int32)CAN_RRWS) - ((Int32)CAN_VehSpd0);

  /* Abs: '<S37>/Abs4' */
  if (u < 0) {
    u = -u;
  }

  /* End of Abs: '<S37>/Abs4' */

  /* Logic: '<S37>/Logical Operator3' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Delay: '<S36>/Delay'
   *  Gain: '<S37>/Gain'
   *  RelationalOperator: '<S37>/Relational Operator1'
   *  RelationalOperator: '<S37>/Relational Operator2'
   */
  rtb_LogicalOperator3_jutd = (rtb_LogicalOperator3_tmp > ((Int32)10000 * u));

  /* Sum: '<S34>/Add3' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read1'
   *  DataStoreRead: '<S19>/Data Store Read20'
   */
  u = ((Int32)CAN_FLWS) - ((Int32)CAN_VehSpd0);

  /* Abs: '<S34>/Abs4' */
  if (u < 0) {
    u = -u;
  }

  /* End of Abs: '<S34>/Abs4' */

  /* Logic: '<S34>/Logical Operator3' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Delay: '<S36>/Delay'
   *  Gain: '<S34>/Gain'
   *  RelationalOperator: '<S34>/Relational Operator1'
   *  RelationalOperator: '<S34>/Relational Operator2'
   */
  rtb_LogicalOperator3_krld = (rtb_LogicalOperator3_tmp > ((Int32)10000 * u));

  /* Sum: '<S35>/Add3' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read14'
   *  DataStoreRead: '<S19>/Data Store Read20'
   */
  u = ((Int32)CAN_FRWS) - ((Int32)CAN_VehSpd0);

  /* Abs: '<S35>/Abs4' */
  if (u < 0) {
    u = -u;
  }

  rtb_LogicalOperator3_1 = (rtb_LogicalOperator3_tmp > ((Int32)10000 * u));

  rtb_LogicalOperator4 = ((Fv_WheelSpeedRate[0] < Cal_APC_MONITOR_WHS_Detla)
                        &&(Fv_WheelSpeedRate[0] > -Cal_APC_MONITOR_WHS_Detla))
                       &&((Fv_WheelSpeedRate[1] < Cal_APC_MONITOR_WHS_Detla)
                        &&(Fv_WheelSpeedRate[1] > -Cal_APC_MONITOR_WHS_Detla))
                       &&((Fv_WheelSpeedRate[2] < Cal_APC_MONITOR_WHS_Detla)
                        &&(Fv_WheelSpeedRate[2] > -Cal_APC_MONITOR_WHS_Detla))
                       &&((Fv_WheelSpeedRate[3] < Cal_APC_MONITOR_WHS_Detla)
                        &&(Fv_WheelSpeedRate[3] > -Cal_APC_MONITOR_WHS_Detla));

  /* Sum: '<S19>/Add2' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read2'
   *  DataStoreRead: '<S19>/Data Store Read3'
   */
  angcrr_angoffset = (Int16)(Fv_StrAng - Fv_StrAngOffset);
  /* Abs: '<S19>/Abs' */
  if (angcrr_angoffset < 0) {
    rtb_Add4_j0hv = (Int16)(-angcrr_angoffset);
  } else {
    rtb_Add4_j0hv = angcrr_angoffset;
  }

  /* End of Abs: '<S19>/Abs' */

  /* Abs: '<S19>/Abs1' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read4'
   */
  if (Fv_HellaFirlterRev < 0) {
    tmp = (Int16)(-Fv_HellaFirlterRev);
  } else {
    tmp = Fv_HellaFirlterRev;
  }

  /* End of Abs: '<S19>/Abs1' */

  /* Abs: '<S19>/Abs2' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read5'
   */
  if (Fv_StrTrq0 < 0) {
    tmp_0 = (Int16)(-Fv_StrTrq0);
  } else {
    tmp_0 = Fv_StrTrq0;
  }
  /* End of Abs: '<S19>/Abs2' */

  /* Logic: '<S19>/Logical Operator3' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S35>/Constant2'
   *  DataStoreRead: '<S19>/Data Store Read10'
   *  DataStoreRead: '<S19>/Data Store Read11'
   *  DataStoreRead: '<S19>/Data Store Read12'
   *  DataStoreRead: '<S19>/Data Store Read13'
   *  DataStoreRead: '<S19>/Data Store Read6'
   *  DataStoreRead: '<S19>/Data Store Read8'
   *  Delay: '<S36>/Delay'
   *  Gain: '<S35>/Gain'
   *  Logic: '<S19>/Logical Operator'
   *  Logic: '<S19>/Logical Operator1'
   *  Logic: '<S19>/Logical Operator2'
   *  Logic: '<S35>/Logical Operator3'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S27>/Compare'
   *  RelationalOperator: '<S28>/Compare'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S30>/Compare'
   *  RelationalOperator: '<S32>/Compare'
   *  RelationalOperator: '<S33>/Compare'
   *  RelationalOperator: '<S35>/Relational Operator1'
   *  RelationalOperator: '<S35>/Relational Operator2'
   */

  con1 = (((((Fv_AngleMidValidFlag == ANGLE_STS_Valid) && (Fv_HighFailFlag == 0)) &&
            (Fv_AbsInvalidFlag == false)) && (Fv_WhsInvalidFlag == false)) &&
            (Fv_AngleReadyFlag == HELLA_STS_Decode));

  con2_1 = ((rtb_Add4_j0hv <= Cal_APC_MONITOR_ANG) && (tmp <= Cal_APC_MONITOR_REV));

  con2_2 = (tmp_0 <= Cal_APC_MONITOR_TRQ);

  con2 = ((( con2_1 && con2_2) && (Fv_VehSpd0 >= Cal_APC_MONITOR_VHS)) && (Fv_VehSpd0
    <= Cal_APC_MONITOR_VHS_UpLimit));
  
  con3 = (rtb_LogicalOperator3 && rtb_LogicalOperator3_jutd && rtb_LogicalOperator3_krld
        &&rtb_LogicalOperator3_1 && rtb_LogicalOperator4);
  con4 = 1;//Fv_EspSubFunctionValidFlag;  //mod  by liuyang at 240923 deleted for DBJ 
  con5 = (rtb_Constant2 <= Cal_APC_MONITOR_YawAcc);

  angcrr_learncond = (con1  && con2 && con3 && con4 && con5);
  Fv_AOC_StraightFlag = angcrr_learncond;
  /* Logic: '<S19>/Logical Operator4' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S31>/Constant'
   *  DataStoreRead: '<S19>/Data Store Read21'
   *  DataStoreRead: '<S19>/Data Store Read22'
   *  DataStoreRead: '<S19>/Data Store Read7'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S31>/Compare'
   */
  angcrr_active = (((Fv_APC_Configuration) && (Fv_AngleReadyFlag != HELLA_STS_Error)) &&
                   (Fv_AngleMidValidFlag == ANGLE_STS_Valid));

  /* Lookup_n-D: '<S19>/vs_aoftgain' incorporates:
   *  DataStoreRead: '<S19>/Data Store Read19'
   */
  angcrr_vsgainbyd = look1_iu16ls32n10tu16_plinlcase(Fv_VehSpd0, ((const UInt16 *)
    &(Cal_APC_MONITOR_VsTab_X[0])), ((const UInt16 *)&(Cal_APC_MONITOR_VsTab_Y[0])),
    &AngleOffsetComprtDW.AngleOffsetComp_BYD.m_bpIndex, 4U);
}

#endif

/* Output and update for referenced model: 'AngleOffsetComp' */
void AngleOffsetComp(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/AngleOffsetComp' */
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

  /* Output and update for atomic system: '<S1>/AngleOffsetComp' */

  /* Outputs for Atomic SubSystem: '<S2>/AngleOffsetComp_Straight' */
  AngleO_AngleOffsetComp_Straight();

  /* End of Outputs for SubSystem: '<S2>/AngleOffsetComp_Straight' */

  /* Outputs for Atomic SubSystem: '<S2>/AngleOffsetComp_Apull' */
  AngleOffs_AngleOffsetComp_Apull();

  /* End of Outputs for SubSystem: '<S2>/AngleOffsetComp_Apull' */
#elif MACRO_ANGEL_OFFSET_COMP_SELECT == 1

  /* Output and update for atomic system: '<S1>/AngleOffsetComp_BYD' */

  /* Outputs for Atomic SubSystem: '<S3>/AngleOffsetComp_Straight' */
  A_AngleOffsetComp_Straight_d1qu();

  /* End of Outputs for SubSystem: '<S3>/AngleOffsetComp_Straight' */

  /* Outputs for Atomic SubSystem: '<S3>/AngleOffsetComp_Apull' */
  Angl_AngleOffsetComp_Apull_hldl();

  /* End of Outputs for SubSystem: '<S3>/AngleOffsetComp_Apull' */
#endif

  /* End of Outputs for SubSystem: '<Root>/AngleOffsetComp' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

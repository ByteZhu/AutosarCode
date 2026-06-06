
#include "rtwtypes.h"
#include "GlobalVar.h"
#include "CalVar.h"
#include "Common.h"
#include "asr_s32.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "look1_is16ls32n10ts16D_PDzFBkZ7.h"

//#define MACRO_SAT_HFBACK_DZ            640
/* Block signals and states (default storage) for system '<S155>/OffCenterSAT' */
//typedef struct {
//  Float64 offcenterfilter_states;      /* '<S191>/offcenterfilter' */
//  Float64 offcenterfilter_denStates;   /* '<S191>/offcenterfilter' */
//  Float64 offcenterfilter_tmp;         /* '<S191>/offcenterfilter' */
//  UInt32 m_bpIndex;                    /* '<S191>/vsocsat' */
//} DW_OffCenterSAT;

/* Block signals and states (default storage) for system '<S155>/OnCenterKick' */
//typedef struct {
//  Float64 DataStoreRead3[4];           /* '<S192>/Data Store Read3' */
//  Float64 DataStoreRead4[4];           /* '<S192>/Data Store Read4' */
//  Float64 oncenterhf_states;           /* '<S192>/oncenterhf' */
//  Float64 oncenterhf_denStates;        /* '<S192>/oncenterhf' */
//  Float64 oncenterlf_states;           /* '<S192>/oncenterlf' */
//  Float64 oncenterlf_denStates;        /* '<S192>/oncenterlf' */
//  Float64 oncenterhf_tmp;              /* '<S192>/oncenterhf' */
//  Float64 oncenterlf_tmp;              /* '<S192>/oncenterlf' */
//  UInt32 m_bpIndex;                    /* '<S192>/vsockick' */
//  UInt32 m_bpIndex_fn1k;               /* '<S192>/trqockick' */
//} DW_OnCenterKick;

/* Declare variables for internal data of system '<S155>/OffCenterSAT' */
DW_OffCenterSAT rtOffCenterSAT_DW;

/* Declare variables for internal data of system '<S155>/OnCenterKick' */
DW_OnCenterKick rtOnCenterKick_DW;

/* System initialize for atomic system: '<S155>/OffCenterSAT' */
void OffCenterSAT_Init(void)
{
  /* InitializeConditions for DiscreteFilter: '<S191>/offcenterfilter' */
  rtOffCenterSAT_DW.offcenterfilter_states = 0.0;
  rtOffCenterSAT_DW.offcenterfilter_denStates = 0.0;
}

/* Output and update for atomic system: '<S155>/OffCenterSAT' */
void OffCenterSAT(void)
{
  Int16 rtb_vsocsat;
  Int16 rtb_Add2_jzli;
  Int32 rtb_Gain1;
  Int16 rtb_Switch2_inpr;

  /* Sum: '<S191>/Add2' incorporates:
   *  DataStoreRead: '<S191>/Data Store Read'
   *  DataStoreRead: '<S191>/Data Store Read1'
   *  DataStoreRead: '<S191>/Data Store Read2'
   *  DataStoreRead: '<S191>/Data Store Read3'
   *  Gain: '<S191>/Gain2'
   *  Sum: '<S191>/Add'
   */
  rtb_Add2_jzli = (Int16)((((Int16)((((Int32)Tv_BasicAsisTrq_Primed) + ((Int32)Fv_BassicAssisFedforward)) +
                                    asr_s32(((Int32)Fv_StrTrqP2dot5) + ((Fv_StrTrqP2dot5 < 0) ? 15 : 0), 4U))) -
                           Fv_InrCompTrq0) -
                          Tv_FriCompTrq);

  /* DiscreteFilter: '<S191>/offcenterfilter' incorporates:
   *  DataStoreRead: '<S191>/Data Store Read4'
   *  DataTypeConversion: '<S191>/conv'
   *  DataTypeConversion: '<S198>/FixPt Gateway Out'
   */
  rtOffCenterSAT_DW.offcenterfilter_tmp = ((Fv_FirCof_OffCenter[0] * ((Float64)rtb_Add2_jzli)) +
                                           (Fv_FirCof_OffCenter[1] * rtOffCenterSAT_DW.offcenterfilter_states)) -
                                          (Fv_FirCof_OffCenter[3] * rtOffCenterSAT_DW.offcenterfilter_denStates);

  /* Gain: '<S191>/Gain1' incorporates:
   *  DataTypeConversion: '<S191>/conv1'
   *  DiscreteFilter: '<S191>/offcenterfilter'
   */
  rtb_Gain1 = -((Int32)rtOffCenterSAT_DW.offcenterfilter_tmp);

  /* UnaryMinus: '<S191>/Unary Minus' incorporates:
   *  Constant: '<S191>/Constant1'
   */
  rtb_vsocsat = (Int16)(-Cal_OC_HysComp_SatMaxTorq);

  /* Switch: '<S197>/Switch2' incorporates:
   *  Constant: '<S191>/Constant'
   *  RelationalOperator: '<S197>/LowerRelop1'
   *  RelationalOperator: '<S197>/UpperRelop'
   *  Switch: '<S197>/Switch'
   */
  if (rtb_Gain1 > ((Int32)Cal_OC_HysComp_SatMaxTorq))
  {
    rtb_Switch2_inpr = Cal_OC_HysComp_SatMaxTorq;
  }
  else if (rtb_Gain1 < ((Int32)rtb_vsocsat))
  {
    /* Switch: '<S197>/Switch' */
    rtb_Switch2_inpr = rtb_vsocsat;
  }
  else
  {
    rtb_Switch2_inpr = (Int16)rtb_Gain1;
  }

  /* End of Switch: '<S197>/Switch2' */

  /* Lookup_n-D: '<S191>/vsocsat' */
  rtb_vsocsat =
    look1_iu16ls32n10ts16D_QWHCuzIb(Fv_VehSpdNew, ((const UInt16 *)&(Cal_OC_HysCompVehTab_X[0])),
                                    ((const Int16 *)&(Cal_OC_HysCompVehTab_Y[0])), &rtOffCenterSAT_DW.m_bpIndex, 4U);

  /* Product: '<S191>/Product' incorporates:
   *  Constant: '<S191>/Constant2'
   *  Product: '<S191>/Product1'
   */
  Tv_OffCenterComp =
    (Int16)asr_s32(asr_s32(((Int32)Cal_OC_HysCompPlus) * ((Int32)rtb_Switch2_inpr), 7U) * ((Int32)rtb_vsocsat), 7U);

  /* Update for DiscreteFilter: '<S191>/offcenterfilter' incorporates:
   *  DataTypeConversion: '<S191>/conv'
   *  DataTypeConversion: '<S198>/FixPt Gateway Out'
   */
  rtOffCenterSAT_DW.offcenterfilter_states = (Float64)rtb_Add2_jzli;
  rtOffCenterSAT_DW.offcenterfilter_denStates = rtOffCenterSAT_DW.offcenterfilter_tmp;
}

/* System initialize for atomic system: '<S155>/OnCenterKick' */
void OnCenterKick_Init(void)
{
  /* InitializeConditions for DiscreteFilter: '<S192>/oncenterhf' */
  rtOnCenterKick_DW.oncenterhf_states = 0.0;
  rtOnCenterKick_DW.oncenterhf_denStates = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S192>/oncenterlf' */
  rtOnCenterKick_DW.oncenterlf_states = 0.0;
  rtOnCenterKick_DW.oncenterlf_denStates = 0.0;
}

/* Output and update for atomic system: '<S155>/OnCenterKick' */
void OnCenterKick(void)
{
  Int16 rtb_trqockick;
  Int16 rtb_Add4_kh5p;
  Int32 rtb_Gain1;
  Int32 rtb_UnaryMinus1_eyge;
  Int16 rtb_Product1_jm1x;
  Float64 Subtract;

  /* DataStoreRead: '<S192>/Data Store Read3' */
  rtOnCenterKick_DW.DataStoreRead3[0] = Fv_FirCof_OnCenter[1];

  /* DataStoreRead: '<S192>/Data Store Read4' */
  rtOnCenterKick_DW.DataStoreRead4[0] = Fv_FirCof_OnCenter[0];

  /* DataStoreRead: '<S192>/Data Store Read3' */
  rtOnCenterKick_DW.DataStoreRead3[1] = Fv_FirCof_OnCenter[3];

  /* DataStoreRead: '<S192>/Data Store Read4' */
  rtOnCenterKick_DW.DataStoreRead4[1] = Fv_FirCof_OnCenter[2];

  /* DataStoreRead: '<S192>/Data Store Read3' */
  rtOnCenterKick_DW.DataStoreRead3[2] = Fv_FirCof_OnCenter[5];

  /* DataStoreRead: '<S192>/Data Store Read4' */
  rtOnCenterKick_DW.DataStoreRead4[2] = Fv_FirCof_OnCenter[4];

  /* DataStoreRead: '<S192>/Data Store Read3' */
  rtOnCenterKick_DW.DataStoreRead3[3] = Fv_FirCof_OnCenter[7];

  /* DataStoreRead: '<S192>/Data Store Read4' */
  rtOnCenterKick_DW.DataStoreRead4[3] = Fv_FirCof_OnCenter[6];

  /* Gain: '<S192>/Gain2' */
  rtb_Gain1 = 3 * ((Int32)Tv_StrTrq0);

  /* Sum: '<S192>/Add4' incorporates:
   *  DataStoreRead: '<S192>/Data Store Read1'
   *  DataStoreRead: '<S192>/Data Store Read2'
   *  DataStoreRead: '<S192>/Data Store Read5'
   *  Gain: '<S192>/Gain2'
   */
  rtb_Add4_kh5p = (Int16)(((((Int32)Fv_TorqueTarget) + asr_s32(rtb_Gain1 + ((rtb_Gain1 < 0) ? 7 : 0), 3U)) -
                           ((Int32)Fv_FrcRevCompTrq)) -
                          ((Int32)Fv_InrCompTrq0));

  /* DiscreteFilter: '<S192>/oncenterhf' incorporates:
   *  DataTypeConversion: '<S192>/conv'
   *  DataTypeConversion: '<S201>/FixPt Gateway Out'
   */
  rtOnCenterKick_DW.oncenterhf_tmp = ((rtOnCenterKick_DW.DataStoreRead4[0] * ((Float64)rtb_Add4_kh5p)) +
                                      (rtOnCenterKick_DW.DataStoreRead4[1] * rtOnCenterKick_DW.oncenterhf_states)) -
                                     (rtOnCenterKick_DW.DataStoreRead4[3] * rtOnCenterKick_DW.oncenterhf_denStates);

  /* Sum: '<S192>/Subtract' incorporates:
   *  DataTypeConversion: '<S192>/conv'
   *  DataTypeConversion: '<S201>/FixPt Gateway Out'
   *  DiscreteFilter: '<S192>/oncenterhf'
   */
  Subtract = ((Float64)rtb_Add4_kh5p) - rtOnCenterKick_DW.oncenterhf_tmp;

  /* DiscreteFilter: '<S192>/oncenterlf' */
  rtOnCenterKick_DW.oncenterlf_tmp = ((rtOnCenterKick_DW.DataStoreRead3[0] * Subtract) +
                                      (rtOnCenterKick_DW.DataStoreRead3[1] * rtOnCenterKick_DW.oncenterlf_states)) -
                                     (rtOnCenterKick_DW.DataStoreRead3[3] * rtOnCenterKick_DW.oncenterlf_denStates);

  /* Gain: '<S192>/Gain1' incorporates:
   *  DataTypeConversion: '<S192>/conv3'
   *  DiscreteFilter: '<S192>/oncenterlf'
   */
  rtb_Gain1 = -((Int32)rtOnCenterKick_DW.oncenterlf_tmp);

  /* DataTypeConversion: '<S192>/conv1' incorporates:
   *  Constant: '<S192>/Constant3'
   */
  rtb_UnaryMinus1_eyge = (Int32)((Int16)MACRO_SAT_HFBACK_DZ);

  /* Switch: '<S199>/Switch' incorporates:
   *  Constant: '<S192>/Constant3'
   *  DataTypeConversion: '<S192>/conv1'
   *  RelationalOperator: '<S199>/u_GTE_up'
   */
  if (rtb_Gain1 >= ((Int32)((Int16)MACRO_SAT_HFBACK_DZ)))
  {
  }
  else
  {
    /* UnaryMinus: '<S192>/Unary Minus1' incorporates:
     *  Constant: '<S192>/Constant4'
     *  DataTypeConversion: '<S192>/conv2'
     */
    rtb_UnaryMinus1_eyge = -((Int32)((Int16)MACRO_SAT_HFBACK_DZ));

    /* Switch: '<S199>/Switch1' incorporates:
     *  RelationalOperator: '<S199>/u_GT_lo'
     */
    if (rtb_Gain1 > rtb_UnaryMinus1_eyge)
    {
      rtb_UnaryMinus1_eyge = rtb_Gain1;
    }

    /* End of Switch: '<S199>/Switch1' */
  }

  /* End of Switch: '<S199>/Switch' */

  /* Sum: '<S199>/Diff' */
  rtb_Gain1 -= rtb_UnaryMinus1_eyge;

  /* UnaryMinus: '<S192>/Unary Minus' incorporates:
   *  Constant: '<S192>/Constant2'
   *  DataTypeConversion: '<S192>/conv5'
   */
  rtb_UnaryMinus1_eyge = -((Int32)Cal_FC_StaticMaxTorq);

  /* Lookup_n-D: '<S192>/vsockick' */
  rtb_trqockick = look1_iu16ls32n10ts16D_QWHCuzIb(Fv_VehSpdNew, ((const UInt16 *)&(Cal_FC_FrictionStaticVehTab_X[0])),
                                                  ((const Int16 *)&(Cal_FC_FrictionStaticVehTab_Y[0])),
                                                  &rtOnCenterKick_DW.m_bpIndex, 5U);

  /* Switch: '<S200>/Switch2' incorporates:
   *  Constant: '<S192>/Constant'
   *  DataTypeConversion: '<S192>/conv4'
   *  RelationalOperator: '<S200>/LowerRelop1'
   *  RelationalOperator: '<S200>/UpperRelop'
   *  Switch: '<S200>/Switch'
   */
  if (rtb_Gain1 > ((Int32)Cal_FC_StaticMaxTorq))
  {
    rtb_Product1_jm1x = Cal_FC_StaticMaxTorq;
  }
  else if (rtb_Gain1 < rtb_UnaryMinus1_eyge)
  {
    /* Switch: '<S200>/Switch' */
    rtb_Product1_jm1x = (Int16)rtb_UnaryMinus1_eyge;
  }
  else
  {
    rtb_Product1_jm1x = (Int16)rtb_Gain1;
  }

  /* End of Switch: '<S200>/Switch2' */

  /* Product: '<S192>/Product1' */
  rtb_Product1_jm1x = (Int16)asr_s32(((Int32)rtb_Product1_jm1x) * ((Int32)rtb_trqockick), 7U);

  /* Abs: '<S192>/Abs' */
  if (Tv_StrTrq0 < 0)
  {
    rtb_trqockick = (Int16)(-Tv_StrTrq0);
  }
  else
  {
    rtb_trqockick = Tv_StrTrq0;
  }

  /* End of Abs: '<S192>/Abs' */

  /* Lookup_n-D: '<S192>/trqockick' */
  rtb_trqockick = look1_is16ls32n10ts16D_PDzFBkZ7(rtb_trqockick, ((const Int16 *)&(Cal_FC_StaticCompTorTab_X[0])),
                                                  ((const Int16 *)&(Cal_FC_StaticCompTorTab_Y[0])),
                                                  &rtOnCenterKick_DW.m_bpIndex_fn1k, 4U);

  /* Product: '<S192>/Product2' */
  Tv_OnCenterKickComp = (Int16)asr_s32(((Int32)rtb_Product1_jm1x) * ((Int32)rtb_trqockick), 7U);

  /* Update for DiscreteFilter: '<S192>/oncenterhf' incorporates:
   *  DataTypeConversion: '<S192>/conv'
   *  DataTypeConversion: '<S201>/FixPt Gateway Out'
   */
  rtOnCenterKick_DW.oncenterhf_states = (Float64)rtb_Add4_kh5p;
  rtOnCenterKick_DW.oncenterhf_denStates = rtOnCenterKick_DW.oncenterhf_tmp;

  /* Update for DiscreteFilter: '<S192>/oncenterlf' */
  rtOnCenterKick_DW.oncenterlf_states = Subtract;
  rtOnCenterKick_DW.oncenterlf_denStates = rtOnCenterKick_DW.oncenterlf_tmp;
}

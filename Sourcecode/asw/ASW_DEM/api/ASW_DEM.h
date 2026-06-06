/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  ASW_DEM
 * Description: Testcode for ASW_DEM
 * Version         Author:       Date               Update information
 * 1.0             HAD1HC        7-Nov-2018         Create software
 * 1.1             AGT1HC        19-Nov-2021        Update the Banner
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/

#ifndef DEM_SWC_H_
#define DEM_SWC_H_


#define CAN_TYPE_OK 1
#define CAN_TYPE_NOK 0

#endif /* DEM_SWC_H_*/
/* Block signals and states (default storage) for system '<S1>/CarModeReqTMR' */
typedef struct {
  UInt16 timecnt;                      /* '<S1>/CarModeReqTMR' */
  UInt8 ModeSwitchReq_last;            /* '<S1>/CarModeReqTMR' */
} DW_CarModeReqTMR;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_CarModeReqTMR sf_UsageModeReqTMR; /* '<S1>/UsageModeReqTMR' */
  DW_CarModeReqTMR sf_CarModeReqTMR;   /* '<S1>/CarModeReqTMR' */
  UInt8 Mode;                          /* '<S1>/UsageModeReqTMR' */
  UInt8 Mode_eipi;                     /* '<S1>/CarModeReqTMR' */
} DW_l5cf_1;

/* Block signals and states (default storage) */
extern DW_l5cf_1 rtDW_l5cf;

/* Model entry point functions */
extern void ModeChangeDelay_initialize(void);
extern void ModeChangeDelay_step(void);

extern void CarModeReqTMR_Init(UInt8 *rty_Mode);
extern void CarModeReqTMR(UInt8 rtu_ModeSwitchReq, UInt8 *rty_Mode,
  DW_CarModeReqTMR *localDW);
extern void ModeSwitchLogic_Init(void);
extern void ModeSwitchLogic(void);

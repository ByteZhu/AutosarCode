
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVEXTENDEDDATAREC_H
#define DEM_CFG_ENVEXTENDEDDATAREC_H

#define DEM_CFG_ENVEXTDATA2DATAELEMENT \
{ \
   DEM_DATAELEM_OPERATIONCYCLE_1,    /* Record_OCC_1 */ \
   DEM_DATAELEM_OPERATIONCYCLE_2,    /* Record_OCC_2 */ \
   DEM_DATAELEM_OPERATIONCYCLE_3,    /* Record_OCC_3 */ \
   DEM_DATAELEM_OPERATIONCYCLE_4,    /* Record_OCC_4 */ \
   DEM_DATAELEM_DTCFAULTDETECTIONCOUNTER,    /* Record_DTC_FaultDetectionCNT */ \
   DEM_DATAELEM_MAX_DTC_FAULTDETECTIONCNT_SINCELASTCLEAR,    /* Record_MAX_DTCFaultDetectionCNT_LastClear */ \
   DEM_DATAELEM_SR_EDR_RECORD_TIME_STAMP_22_TIME_STAMP_22,    /* Record_TIME_STAMP_22 */ \
   DEM_DATAELEM_SR_EDR_RECORD_TIME_STAMP_23_TIME_STAMP_23,    /* Record_TIME_STAMP_23 */ \
   0 \
}


#define DEM_EXTDATAREC_RECORD_OCC_1                   1
#define DEM_EXTDATAREC_RECORD_OCC_2                   2
#define DEM_EXTDATAREC_RECORD_OCC_3                   3
#define DEM_EXTDATAREC_RECORD_OCC_4                   4
#define DEM_EXTDATAREC_RECORD_DTC_FAULTDETECTIONCNT   5
#define DEM_EXTDATAREC_RECORD_MAX_DTCFAULTDETECTIONCNT_LASTCLEAR  6
#define DEM_EXTDATAREC_RECORD_TIME_STAMP_22           7
#define DEM_EXTDATAREC_RECORD_TIME_STAMP_23           8


#define DEM_CFG_ENVEXTDATAREC \
{ \
/*	   RecNum Trigger                       Update Index  */ \
	 { 0,     DEM_TRIGGER_NONE,             FALSE,0    } \
	,{ 1,     DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,1    } /* DEM_EXTDATAREC_RECORD_OCC_1 */ \
	,{ 2,     DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,2    } /* DEM_EXTDATAREC_RECORD_OCC_2 */ \
	,{ 3,     DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,3    } /* DEM_EXTDATAREC_RECORD_OCC_3 */ \
	,{ 4,     DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,4    } /* DEM_EXTDATAREC_RECORD_OCC_4 */ \
	,{ 10,    DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,5    } /* DEM_EXTDATAREC_RECORD_DTC_FAULTDETECTIONCNT */ \
	,{ 12,    DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,6    } /* DEM_EXTDATAREC_RECORD_MAX_DTCFAULTDETECTIONCNT_LASTCLEAR */ \
	,{ 22,    DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,7    } /* DEM_EXTDATAREC_RECORD_TIME_STAMP_22 */ \
	,{ 23,    DEM_TRIGGER_ON_TEST_FAILED,   TRUE ,8    } /* DEM_EXTDATAREC_RECORD_TIME_STAMP_23 */ \
}




#define DEM_CFG_ENVEXTDATAREC_ARRAYLENGTH  (8+1)


#endif


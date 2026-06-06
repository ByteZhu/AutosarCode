
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVEXTENDEDDATA_H
#define DEM_CFG_ENVEXTENDEDDATA_H

#define DEM_CFG_ENVEXTDATA2EXTDATAREC \
{                                     \
   DEM_EXTDATAREC_RECORD_MAX_DTCFAULTDETECTIONCNT_LASTCLEAR,   DEM_EXTDATAREC_RECORD_OCC_1,   DEM_EXTDATAREC_RECORD_OCC_2,   DEM_EXTDATAREC_RECORD_OCC_3,   DEM_EXTDATAREC_RECORD_OCC_4,   DEM_EXTDATAREC_RECORD_DTC_FAULTDETECTIONCNT,   DEM_EXTDATAREC_RECORD_TIME_STAMP_23,   DEM_EXTDATAREC_RECORD_TIME_STAMP_22,  /* ExtendedDataClass_DTC_All */ \
   0 \
}


#define DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL         1



#define DEM_CFG_ENVEXTDATA                 \
{                                          \
   { 0, 0 }                                \
,{8,18}   /* DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL */     \
}




#define DEM_CFG_ENVEXTDATA_ARRAYLENGTH  (1+1)


#endif


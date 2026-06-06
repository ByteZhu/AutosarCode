
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVFFRECNUMERATION_H
#define DEM_CFG_ENVFFRECNUMERATION_H

/* ---------------------------------------- */
/* DEM_CFG_FFRECNUM                         */
/* ---------------------------------------- */
#define DEM_CFG_FFRECNUM_CALCULATED   1
#define DEM_CFG_FFRECNUM_CONFIGURED   2

/* This section is for code optmization if no memory is configured as Calculated or configured then no need to compile the appropriate code */
#define DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED    TRUE
#define DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CALCULATED    FALSE
 
/* Freeze frame record configuration for all event memory */
#define DEM_CFG_EVMEM_FFRECNUM \
{ \
   DEM_CFG_FFRECNUM_CONFIGURED  /* Primary memory memId */\
}

#define DEM_CFG_EVMEM_FFRECNUM_SIZE            (0u + 1u)

/* At least one memory is configured as DEM_CFG_FFRECNUM_CONFIGURED */
#define DEM_CFG_FFRECCLASS_NUMBEROF_FFRECCLASSES          1
#define DEM_CFG_FFRECCLASS_MAXNUMBEROF_FFFRECNUMS         2

#define DEM_CFG_FFRECNUMCLASSES \
{ \
   {0x20 ,0x21 }   /* DTC_All_FFRecNumClass */ \
}

#define DEM_CFG_ENVFFREC \
{ \
/*     RecNum    Trigger                                           Update  */ \
     { 0,        DEM_TRIGGER_NONE,                                 FALSE } \
    ,{ 32,       DEM_TRIGGER_ON_TEST_FAILED,                       TRUE } /* DEM_FFREC_REC_SNAPSHOT_RECORD_0X20 */ \
    ,{ 33,       DEM_TRIGGER_ON_TEST_FAILED,                       FALSE } /* DEM_FFREC_REC_SNAPSHOT_RECORD_0X21 */ \
}

#define DEM_CFG_ENVFFREC_ARRAYLENGTH  (2u+1u)



#endif


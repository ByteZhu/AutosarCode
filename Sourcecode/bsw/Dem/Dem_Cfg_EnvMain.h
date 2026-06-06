
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVMAIN_H
#define DEM_CFG_ENVMAIN_H


/* min number of bytes required for storing any eventIds ExtendedData and one FreezeFrame (=> EvBuff) */
#define DEM_CFG_ENVMINSIZE_OF_RAWENVDATA  (90u  + 0u+ 0u + 0u) 
 

/* min number of bytes required for storing any eventIds ExtendedData and multiple FreezeFrame (=> EvMem) */
#define DEM_CFG_ENVMINSIZE_OF_MULTIPLE_RAWENVDATA  (162u + 0u + 0u + 0u)
 

/*min number of bytes required for OBD and WWH-OBD (freeze frame 0x00) related data - This is generated for getting Offset for handling J1939 data*/
#define DEM_CFG_OFFSET_OBDRAWENVDATA         (0u + 0u)




#define DEM_CFG_ENVEVENTID2ENVDATA \
{ \
   { 0u,0u }                                                      /* DEM_EVENTID_INVALID */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_1A0683_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_452654_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_452954_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_452A62_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_502D71_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_505602_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_505662_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_505696_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_516A62_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_600C96_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_9E2B04_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_9E2B44_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_9E2B45_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_9E2B49_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_9E2B4B_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_C12182_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_C15182_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_C15982_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_C16882_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_C29682_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_D10382_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_D14B51_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_D14C51_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_D15282_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_D15283_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_D44D82_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_DC1A88_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_DCC388_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E01104_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E01149_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E01196_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E30055_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E30056_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E71883_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E72783_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E72F81_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E72F83_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E7B182_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E7B283_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_E7B383_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EC3281_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EC3481_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EC3681_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EC4281_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ECEB81_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED3283_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED3383_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED3683_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED3983_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED4183_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED5A83_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED7983_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_ED9683_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EE0368_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EE0468_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EE0B68_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_EE0C68_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00004_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00044_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00045_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00049_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F0004B_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00068_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00093_Event */ \
   ,{  DEM_EXTDATA_EXTENDEDDATACLASS_DTC_ALL, DEM_FREEZEFRAME_FREEZEFRAME_DTC_SNAPSHOT_DIDSET }  /* DTC_F00362_Event */ \
}

/*------         Freeze frame        ,         Expanded Freeze frame -------------*/
#define DEM_CFG_J1939_ENVEVENTID2ENVDATA \
{ \
   { 0u,0u }                                                      /* DEM_EVENTID_INVALID */ \
   ,{  0u, 0u }                                                    /* DTC_1A0683_Event */ \
   ,{  0u, 0u }                                                    /* DTC_452654_Event */ \
   ,{  0u, 0u }                                                    /* DTC_452954_Event */ \
   ,{  0u, 0u }                                                    /* DTC_452A62_Event */ \
   ,{  0u, 0u }                                                    /* DTC_502D71_Event */ \
   ,{  0u, 0u }                                                    /* DTC_505602_Event */ \
   ,{  0u, 0u }                                                    /* DTC_505662_Event */ \
   ,{  0u, 0u }                                                    /* DTC_505696_Event */ \
   ,{  0u, 0u }                                                    /* DTC_516A62_Event */ \
   ,{  0u, 0u }                                                    /* DTC_600C96_Event */ \
   ,{  0u, 0u }                                                    /* DTC_9E2B04_Event */ \
   ,{  0u, 0u }                                                    /* DTC_9E2B44_Event */ \
   ,{  0u, 0u }                                                    /* DTC_9E2B45_Event */ \
   ,{  0u, 0u }                                                    /* DTC_9E2B49_Event */ \
   ,{  0u, 0u }                                                    /* DTC_9E2B4B_Event */ \
   ,{  0u, 0u }                                                    /* DTC_C12182_Event */ \
   ,{  0u, 0u }                                                    /* DTC_C15182_Event */ \
   ,{  0u, 0u }                                                    /* DTC_C15982_Event */ \
   ,{  0u, 0u }                                                    /* DTC_C16882_Event */ \
   ,{  0u, 0u }                                                    /* DTC_C29682_Event */ \
   ,{  0u, 0u }                                                    /* DTC_D10382_Event */ \
   ,{  0u, 0u }                                                    /* DTC_D14B51_Event */ \
   ,{  0u, 0u }                                                    /* DTC_D14C51_Event */ \
   ,{  0u, 0u }                                                    /* DTC_D15282_Event */ \
   ,{  0u, 0u }                                                    /* DTC_D15283_Event */ \
   ,{  0u, 0u }                                                    /* DTC_D44D82_Event */ \
   ,{  0u, 0u }                                                    /* DTC_DC1A88_Event */ \
   ,{  0u, 0u }                                                    /* DTC_DCC388_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E01104_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E01149_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E01196_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E30055_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E30056_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E71883_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E72783_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E72F81_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E72F83_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E7B182_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E7B283_Event */ \
   ,{  0u, 0u }                                                    /* DTC_E7B383_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EC3281_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EC3481_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EC3681_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EC4281_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ECEB81_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED3283_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED3383_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED3683_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED3983_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED4183_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED5A83_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED7983_Event */ \
   ,{  0u, 0u }                                                    /* DTC_ED9683_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EE0368_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EE0468_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EE0B68_Event */ \
   ,{  0u, 0u }                                                    /* DTC_EE0C68_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00004_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00044_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00045_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00049_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F0004B_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00068_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00093_Event */ \
   ,{  0u, 0u }                                                    /* DTC_F00362_Event */ \
}
    
/* ------------------------------------------ */
/* DEM_CFG_ENVIRONMMENT_DATA_CAPTURE          */
/* ------------------------------------------ */

#define DEM_CFG_CAPTURE_SYNCHRONOUS_TO_REPORTING                              1u
#define DEM_CFG_CAPTURE_ASYNCHRONOUS_TO_REPORTING                             2u

/* Only userdefined memories and primary memory */
#define DEM_CFG_EVMEM_ENVIRONMENT_DATA_CAPTURE_SIZE                           (0u + 1u)

/* At least one memory is configured as DEM_CFG_CAPTURE_SYNCHRONOUS_TO_REPORTING */
#define DEM_CFG_IS_SYNC_ENVIRONMENT_DATA_CAPTURE_CONFIGURED                   FALSE

/* This config table is related to the memId */
#define DEM_CFG_EVMEM_2_ENVIRONMENT_DATA_CAPTURE \
{ \
   DEM_CFG_CAPTURE_ASYNCHRONOUS_TO_REPORTING  /* Primary memory memId */ \
}

#endif


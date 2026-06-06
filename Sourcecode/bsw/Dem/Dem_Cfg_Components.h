
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_COMPONENTS_H
#define DEM_CFG_COMPONENTS_H


/* ---------------------------------------- */
/* DEM_CFG_DEPRECOVERYLIMIT                 */
/* ---------------------------------------- */
#define DEM_CFG_DEPRECOVERYLIMIT_OFF  STD_OFF
#define DEM_CFG_DEPRECOVERYLIMIT_ON   STD_ON
#define DEM_CFG_DEPRECOVERYLIMIT  DEM_CFG_DEPRECOVERYLIMIT_OFF



#define DEM_CFG_DEPENDENCY_PENDING_ON             FALSE


#define DEM_CFG_FAILUREDEPENDENCY_RECHECK_LIMIT  80u



/*                  ALLOWEDRECOVERIES             UPDATERECOVERYVALUE IGNORESPRIO FAILEDCALLBACK_IDX                     */

#define DEM_CFG_COMPONENTPARAMS \
{ \
    DEM_COMPONENTS_INIT ((DEM_COMPONENT_INFINITE_RECOVERIES),(0u),    (0u),          (0)                                     ) \
}





#define  DEM_CFG_COMPONENTFAILEDCALLBACK_COUNT  0
#define  DEM_CFG_COMPONENTFAILEDCALLBACK_ARRAYLENGTH  (DEM_CFG_COMPONENTFAILEDCALLBACK_COUNT+1)


#define DEM_CFG_COMPONENTFAILEDCALLBACKS \
{ \
	NULL_PTR \
}

#define DEM_CFG_ADVANCEOPERATIONCYCLE_EVENTSPERLOCK      16u





#endif


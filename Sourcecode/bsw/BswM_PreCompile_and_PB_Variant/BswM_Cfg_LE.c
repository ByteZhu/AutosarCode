
/**********************************************************************************************************************
 *  Include files                                                                                                    
 **********************************************************************************************************************/

#include "BswM.h"
#include "BswM_Prv.h"

/**********************************************************************************************************************
 *  Definition of Global Functions                                                                                                    
 **********************************************************************************************************************/

/********************************  LogicalExpressionEvaluateFunctions  ***************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_AppRequestShutdown (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_AppRequestShutdown(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_APPREQUESTSHUTDOWN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_APPREQUESTSHUTDOWN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_AppRun (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_AppRun(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_APPRUN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_APPRUN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_CH0_ComControlDisabled (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_CH0_ComControlDisabled(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_CH0_COMCONTROLDISABLED) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_CH0_COMCONTROLDISABLED) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_CH0_ComControlEnabled (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_CH0_ComControlEnabled(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_CH0_COMCONTROLENABLED) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_CH0_COMCONTROLENABLED) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_DISABLE_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_TX_NORM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_TX_NORM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_TX_NORM_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_TX_NORM_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_ENABLE_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_TX_NORM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_TX_NORM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM_NM (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_TX_NORM_NM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_TX_NORM_NM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_NetworkRelease (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_NetworkRelease(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_NETWORKRELEASE) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_NETWORKRELEASE) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_NetworkRequest (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_NetworkRequest(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_NETWORKREQUEST) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_NETWORKREQUEST) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_NoWakeupSources (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_NoWakeupSources(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_NOWAKEUPSOURCES) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_NOWAKEUPSOURCES) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_NvMReadAllCompleteOrExpired (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_NvMReadAllCompleteOrExpired(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_NVMREADALLCOMPLETEOREXPIRED) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_NVMREADALLCOMPLETEOREXPIRED) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_NvMWriteAllCompleteOrExpired (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_NvMWriteAllCompleteOrExpired(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_NVMWRITEALLCOMPLETEOREXPIRED) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_NVMWRITEALLCOMPLETEOREXPIRED) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PNC29_NoCom (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_PNC29_NoCom(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_PNC29_NOCOM) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_PNC29_NOCOM) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PNC29_PrepareSleep (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_PNC29_PrepareSleep(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_PNC29_PREPARESLEEP) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_PNC29_PREPARESLEEP) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PNC29_ReadySleep (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_PNC29_ReadySleep(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_PNC29_READYSLEEP) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_PNC29_READYSLEEP) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PNC29_Requested (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_PNC29_Requested(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_PNC29_REQUESTED) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_PNC29_REQUESTED) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PostRun2Run (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_PostRun2Run(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_POSTRUN2RUN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_POSTRUN2RUN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_PrepShutdown (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_PrepShutdown(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_PREPSHUTDOWN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_PREPSHUTDOWN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_Run (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_Run(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_RUN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_RUN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_Run2PostRun (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_Run2PostRun(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_RUN2POSTRUN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_RUN2POSTRUN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_Run_Wakeup_CanMsg (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_Run_Wakeup_CanMsg(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_RUN_WAKEUP_CANMSG) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_RUN_WAKEUP_CANMSG) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_Run_Wakeup_KL15 (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_Run_Wakeup_KL15(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_RUN_WAKEUP_KL15) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_RUN_WAKEUP_KL15) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_Shutdown (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_Shutdown(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_SHUTDOWN) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_SHUTDOWN) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StartupOne (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_StartupOne(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_STARTUPONE) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_STARTUPONE) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_StartupTwo (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_StartupTwo(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_STARTUPTWO) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_STARTUPTWO) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

/*****************************************************************************************
 * Function name :   void BswM_Cfg_LE_BswM_LE_TimerExpiredOrStopped (boolean *validMode_pb,boolean *evalResult_pb)
 * Description   :   Evaluates the logical expression if the mode value is initialized and returns the result  
 * Parameter     :   *validMode_pb: evaluates if all the modes are valid and assigns true to this address if valid, 
 *evalResult_pb: result of the logical expression is copied to this address.
 * Return value  :   void
 * Remarks       :   
 *****************************************************************************************/
void BswM_Cfg_LE_BswM_LE_TimerExpiredOrStopped(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb) {
	/* Initialize the pointers with default values */
	*isValidMode_pb = FALSE;
	*hasLogExpRes_pb = FALSE;

	if (FALSE != BSWMMODEVALUE_BSWM_LE_TIMEREXPIREDORSTOPPED) {
		/* All the mode condition values are valid, assign TRUE to pointer */
		*isValidMode_pb = TRUE;
		if (FALSE != BSWMLOGEXP_BSWM_LE_TIMEREXPIREDORSTOPPED) {
			/* Logical Expression evaluated to TRUE */
			*hasLogExpRes_pb = TRUE;
		}

	}

	return;
}

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

/**********************************************************************************************************************
 *                                                                                                        
 **********************************************************************************************************************/

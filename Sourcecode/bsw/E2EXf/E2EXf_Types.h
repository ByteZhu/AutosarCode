
#ifndef E2EXF_TYPES_H
#define E2EXF_TYPES_H

/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/
//[SWS_E2EXf_00047]
#include "Std_Types.h"     /* AUTOSAR standard type definitions */


/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/* E2EXf function return error codes*/
//[BSW_SWS_E2ETransformer4129][SWS_Xfrm_00032]
#define E_SAFETY_VALID_REP              0x01U
#define E_SAFETY_VALID_SEQ              0x02U
#define E_SAFETY_VALID_ERR              0x03U
#define E_SAFETY_VALID_NND              0x05U

#define E_SAFETY_NODATA_OK              0x20U
#define E_SAFETY_NODATA_REP             0x21U
#define E_SAFETY_NODATA_SEQ             0x22U
#define E_SAFETY_NODATA_ERR             0x23U
#define E_SAFETY_NODATA_NND             0x25U

#define E_SAFETY_INIT_OK                0x30U
#define E_SAFETY_INIT_REP               0x31U
#define E_SAFETY_INIT_SEQ               0x32U
#define E_SAFETY_INIT_ERR               0x33U
#define E_SAFETY_INIT_NND               0x35U

#define E_SAFETY_INVALID_OK             0x40U
#define E_SAFETY_INVALID_REP            0x41U
#define E_SAFETY_INVALID_SEQ            0x42U
#define E_SAFETY_INVALID_ERR            0x43U
#define E_SAFETY_INVALID_NND            0x45U

#define E_SAFETY_SOFT_RUNTIMEERROR      0x77U
#define E_SAFETY_HARD_RUNTIMEERROR      0xFFU

/*
**********************************************************************************************************************
* Type definitions
**********************************************************************************************************************
*/

//[SWS_E2EXf_00030]
typedef struct 
{
    uint8 dummy;
} E2EXf_ConfigType;

/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/


/* E2EXF_TYPES_H */
#endif


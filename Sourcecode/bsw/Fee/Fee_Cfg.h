

#ifndef FEE_CFG_H
#define FEE_CFG_H

/*
 ***************************************************************************************************
 * Type definition and enums
 ***************************************************************************************************
 */

typedef enum
{
    Fee_Rb_DeviceName = 0,
    /* following enums are not valid device-driver-enums */
    Fee_Rb_Device_Max      /* Number of configured Fee Devices */
} Fee_Rb_DeviceName_ten;

/* ******************************************************************************************************************
   ***************************** External declarations of hook functions provided to Fee ****************************
   ****************************************************************************************************************** */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/* Hook into synchronous Fls_MainFunction loop */

/* End of Fee section */
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/* FEE_RB_IDX_H */
#endif


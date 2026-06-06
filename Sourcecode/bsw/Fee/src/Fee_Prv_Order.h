
/*
 * The order unit is responsible for handling all external calls to the Fee besides the main and init function.
 * It stores the received orders in internal order slots.
 * The main function will poll orders from the order unit and inform the order unit if an order is finished.
 */

#ifndef FEE_PRV_ORDER_H
#define FEE_PRV_ORDER_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))
#include "Fee_Cfg.h"

extern Std_ReturnType   Fee_Prv_OrderDetCheckDeviceName            (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8);
extern Std_ReturnType   Fee_Prv_OrderDetCheckModuleInitAndStopMode (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8);
extern Std_ReturnType   Fee_Prv_OrderDetCheckAdrPtr                (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, void const * bfr_pcv);
extern Std_ReturnType   Fee_Prv_OrderDetCheckBlkLen                (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, uint16 blkOfs_u16, uint16 blkLen_u16, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);

# endif
/* FEE_PRV_ORDER_H */
#endif

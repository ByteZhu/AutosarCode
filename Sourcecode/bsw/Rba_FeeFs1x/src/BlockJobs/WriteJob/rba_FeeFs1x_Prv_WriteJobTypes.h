
#ifndef RBA_FEEFS1X_PRV_WRITEJOBTYPES_H
#define RBA_FEEFS1X_PRV_WRITEJOBTYPES_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "rba_FeeFs1x_Prv_Searcher.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef enum
{
    rba_FeeFs1x_WrJob_checkWr_stm_idle_e,
    rba_FeeFs1x_WrJob_checkWr_stm_calcCRC_e,
    rba_FeeFs1x_WrJob_checkWr_stm_compToConfig_e,
    rba_FeeFs1x_WrJob_checkWr_stm_compToDFLASH_e
}rba_FeeFs1x_WrJob_checkWr_stm_ten;


typedef struct
{
    uint8 const *   userbuffer_pcu8;
    uint32          dataCRC_u32;
    uint16          feeIndex_u16;
    uint16          persID_u16;
    uint16          blkLen_u16;
    uint16          statusByte_u16;
    boolean         isUnknownBlk_b;
}rba_FeeFs1x_WrJob_JobData_tst;


typedef struct
{
    uint32 calcedBuffCRC_u32;
    rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en;

    rba_FeeFs1x_WrJob_checkWr_stm_ten state_en;
    boolean entry_b;

}rba_FeeFs1x_WrJob_checkWr_data_tst;

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



#endif /* RBA_FEEFS1X_PRV_WRITEJOBTYPES_H */


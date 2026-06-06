/*

/* BSWEXT-544 */
#ifndef FLS_INTEGRATION_H
#define FLS_INTEGRATION_H

#include "Fee.h"
#include "rba_FeeFs1x_Prv.h"
#include "rba_FeeFs1x_Prv_PAMapTypes.h"
#include "Fls.h"

#if (FLS_AR_RELEASE_MINOR_VERSION == 0)

/************************************************************/
/* See NVM_CFG_NV_BLOCK_LENGTH_<BLOCK_NAME> macros in NvM_Cfg.h and define
 * the below MAX_BLOCK_LENGTH macros to be the biggest one among them
 */
#define MAX_BLOCK_LENGTH (1024u)

#define MAX_BLANK_CHECK_SIZE (((RBA_FEEFS1X_PRV_CFG_LOGL_PAGE_SIZE * RBA_FEEFS1X_PAMAP_DETECTWRPAGE_CHUNKSIZE) > MAX_BLOCK_LENGTH) ? (RBA_FEEFS1X_PRV_CFG_LOGL_PAGE_SIZE * RBA_FEEFS1X_PAMAP_DETECTWRPAGE_CHUNKSIZE) : MAX_BLOCK_LENGTH)

#endif /* FLS_AR_RELEASE_MINOR_VERSION == 0 */
#endif /* FLS_INTEGRATION_H */

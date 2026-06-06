
#ifndef DET_PRV_RTEAPIVISIBILITY_H
#define DET_PRV_RTEAPIVISIBILITY_H

#include "Std_Types.h"
#include "Det_Cfg.h"

/* If RTE is used then set the parameter EcuCRbRteInUse to True */
#if (DET_CFG_CHECK_API_CONSISTENCY == TRUE)
#define DET_HIDE_RTE_API
#endif

#endif /* DET_PRV_RTEAPIVISIBILITY_H */


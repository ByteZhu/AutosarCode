/* BEGIN_FILE_HDR
**************************************************************************
* NOTICE
* This software is the property of XiangBin Electric. Any information contained in this
* doc should not be reproduced, or used, or disclosed without the written authorization from
* XiangBin Electric.
**************************************************************************
* File Name: DRV32345.h
********************************************************************
* Project/Product: EPS
* Title: DRV3245妫板嫰鈹嶉懞顖滃妞瑰崬濮�
* Author: LHC
*********************************************************************
* Description:
*	濮濄倖鏋冩禒鍓佹暏娴滃骸锛愰弰搴☆嚠DRV3245鏉╂稖顢戦幙宥勭稊閻ㄥ嫭甯撮崣锟�
*
* (Requirements, pseudo code and etc.)
*********************************************************************
* Limitations:
* 	閺堫剚鏋冩禒鏈电矌闁倻鏁ゆ禍搴㈡儗鏉炵椿RV3245閼侯垳澧栭惃鍕付閸掕泛娅�
* (limitations)
*********************************************************************
*********************************************************************
* Revision History閿涳拷
*
* Version      Date         Author             Descriptions
* ----------    --------------    ------------   ----------------------------------------
* 1.0       		2024-05-22      	LHC            Original
*
********************************************************************
*END_FILE_HDR */
#ifndef _DRV3245_H_
#define _DRV3245_H_

#include "Std_Types.h"

extern void DRV3245_MainFunction(void);

extern void DRV3245_BridgeOper1(uint8 set);

extern void DRV3245_ClearAllFault1(void);

extern uint8 DRV3245_GetStatus1(void);

extern void DRV3245_BridgeOper2(uint8 set);

extern void DRV3245_ClearAllFault2(void);

extern uint8 DRV3245_GetStatus2(void);

#endif

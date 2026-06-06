/*
 * CDD_TCan1145_Cfg.c
 *
 *  Created on: 2023��8��8��
 *      Author: tiand
 */
#include "CDD_TCAN1145_Cfg.h"


const uint8 TCan1145_Cfg_SW_ID1 = 0;
const uint8 TCan1145_Cfg_SW_ID2 = 0;
const uint8 TCan1145_Cfg_SW_ID3 = 0x14;//0x53F
const uint8 TCan1145_Cfg_SW_ID4 = 0xFC;//0x53F
const uint8 TCan1145_Cfg_SW_ID_MASK1 = 0;
const uint8 TCan1145_Cfg_SW_ID_MASK2 = 0;
const uint8 TCan1145_Cfg_SW_ID_MASK3 = 0;
const uint8 TCan1145_Cfg_SW_ID_MASK4 = 0x07;//0X500-0X53F
const uint8 TCan1145_Cfg_SW_ID_MASK_DLC = 0xF1;//0X500-0X53F
const uint8 TCan1145_Cfg_DATA_0 = 0;//8;
const uint8 TCan1145_Cfg_DATA_1 = 0;//7;
const uint8 TCan1145_Cfg_DATA_2 = 0;//6;
const uint8 TCan1145_Cfg_DATA_3 = 0;//5;
const uint8 TCan1145_Cfg_DATA_4 = 0x20;//4;
const uint8 TCan1145_Cfg_DATA_5 = 0;//3;
const uint8 TCan1145_Cfg_DATA_6 = 0;//2;
const uint8 TCan1145_Cfg_DATA_7 = 0;//1;
const uint8 TCan1145_Cfg_DEVICE_CONFIG1 = 0;
const uint8 TCan1145_Cfg_SWE_DIS = 0x04;
const uint8 TCan1145_Cfg_SW_CONFIG_1 = 0xD0;/* normal can 500kbit/s, FD <= 2Mbit/s else 0xD4*/
const uint8 TCan1145_Cfg_SW_CONFIG_4 = 0x80;




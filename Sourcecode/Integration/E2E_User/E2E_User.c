/*
 **********************************************************************************************************************
 * includes
 **********************************************************************************************************************
*/
#include "E2E_User.h"
#include "Com_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
/*Tx Message E2E Configure&Status*/
const E2E_P11ConfigType E2E_P11ConfigType_SACM_SecCanFrame01_PIN =
{
    8,          /* bit Offset in MSB order */
    0,           /* bit offset in MSB order */
    1967,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    72,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */   
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACM_SecCanFrame01_PIN = 
{
    0
};
const E2E_P11ConfigType E2E_P11ConfigType_SACM_SecCanFrame01_ADL =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2102,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    32,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACM_SecCanFrame01_ADL = 
{
    0
};

const E2E_P11ConfigType E2E_P11ConfigType_SACM_SecCanFrame01_LAT =
{
    8,          /* Counter bit Offset in MSB order */
    0,          /* CRC bit offset in MSB order */
    1966,        /* sender Identifier */
    12,          /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,       /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACM_SecCanFrame01_LAT = 
{
    0
};


const E2E_P11ConfigType E2E_P11ConfigType_SACMFram01_DRV =
{
    8,          /* bit Offset in MSB order */
    0,           /* bit offset in MSB order */
    1965,      /* sender Identifier */ 
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram01_DRV = 
{
    0
};
const E2E_P11ConfigType E2E_P11ConfigType_SACMFram01_STE =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1968,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram01_STE = 
{
    0
};

const E2E_P11ConfigType E2E_P11ConfigType_SACMFram02_SST =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2101,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */ 
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram02_SST = 
{
    0
};
//TODO,ARXML中无相关信息
const E2E_P11ConfigType E2E_P11ConfigType_SACMFram02_SSS =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2101,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */ 
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram02_SSS = 
{
    0
};

const E2E_P11ConfigType E2E_P11ConfigType_SFCMBCCanFDFrame01 =
{
    8,          /* bit Offset in MSB order */
    0,           /* bit offset in MSB order */
    2105,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    14,          /* maximum allowed gap, init value */  
};
E2E_P11ProtectStateType E2E_P11ProtectStateType_SFCMBCCanFDFrame01 = 
{
    0
};

/*Rx Message E2E Configure&Status*/
const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_ADF =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    391,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    32,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_ADF = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_APA =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    389,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    32,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_APA = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_AAM =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    390,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_AAM = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_ALO =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    367,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_ALO = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame02_VSL =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1969,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    40,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame02_VSL = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame02_BPP =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2068,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame02_BPP = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame03_WFS =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1976,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    40,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame03_WFS = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame03_WRT =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1973,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    48,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame03_WRT = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame03_VMS =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1970,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame03_VMS = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
#if 0//24N2新增
const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame04_VMM =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    229,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    48,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame04_VMM = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
#endif
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame06 =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2142,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    48,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame06 = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame01_ES =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2142,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame01_ES = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame01_VMM =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2158,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    48,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame01_VMM = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_ALC =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1845,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_ALC = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_ADR =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2113,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    72,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_ADR = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_AgD =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2114,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    56,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_AgD = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_WSCF =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1971,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    56,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_WSCF = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_WSCR =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1972,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    56,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_WSCR = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_LCR =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1715,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    72,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_LCR = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame07_GLI =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    270,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame07_GLI = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};

const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame07_ACA =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    1997,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    24,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame07_ACA = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame07_PTA =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2124,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    72,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame07_PTA = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame09_ADW =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    2183,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    72,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame09_ADW = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame09_PPA =
{
    8,          /* Counter bit Offset in MSB order */
    0,           /* CRC bit offset in MSB order */
    358,      /* sender Identifier */
    12,           /* bit Offset in MSB order for Profile 1C */
    E2E_P11_DATAID_NIBBLE,             /* two byte, low byte, alternating */
    40,         /* length of data in bits */
    3,          /* maximum allowed gap, init value */  
};
E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame09_PPA = 
{ 
    E2E_P11STATUS_NONEWDATA, /* Status*/ 
    0, /* SyncCounter*/ 
};
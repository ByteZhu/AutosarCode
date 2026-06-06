#include "Platform_Types.h"
#include "E2E.h"

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
   uint8 Impl_Sig6;
   uint8 Impl_Sig7;   
} E2E_ImpleDataType_SACM_SecCanFrame01_PIN;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;  
} E2E_ImpleDataType_SACM_SecCanFrame01_ADL;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SACM_SecCanFrame01_LAT;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SACMFram01_DRV;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SACMFram01_STE;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SACMFram02_SST;
//TODO,ARXML中无相关信息
typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SACMFram02_SSS;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SFCMBCCanFDFrame01;

//RX
typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
} E2E_ImpleDataType_SecCanFrame01_ADF;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
} E2E_ImpleDataType_SecCanFrame01_APA;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SecCanFrame01_AAM;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SecCanFrame01_ALO;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
} E2E_ImpleDataType_SecCanFrame02_VSL;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SecCanFrame02_BPP;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
} E2E_ImpleDataType_SecCanFrame03_WFS;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
} E2E_ImpleDataType_SecCanFrame03_WRT;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_SecCanFrame03_VMS;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
} E2E_ImpleDataType_CanFDFrame06;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_CanFDFrame01_ES;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
} E2E_ImpleDataType_CanFDFrame01_VMM;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
} E2E_ImpleDataType_CanFDFrame04_ALC;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
   uint8 Impl_Sig6;
   uint8 Impl_Sig7;   
} E2E_ImpleDataType_CanFDFrame04_ADR;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
} E2E_ImpleDataType_CanFDFrame04_AgD;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
} E2E_ImpleDataType_CanFDFrame04_WSCF;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
} E2E_ImpleDataType_CanFDFrame04_WSCR;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
   uint8 Impl_Sig6;
   uint8 Impl_Sig7;  
} E2E_ImpleDataType_CanFDFrame04_LCR;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1; 
} E2E_ImpleDataType_CanFDFrame07_GLI;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1; 
} E2E_ImpleDataType_CanFDFrame07_ACA;

typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
   uint8 Impl_Sig6;
   uint8 Impl_Sig7; 
} E2E_ImpleDataType_CanFDFrame07_PTA;
typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
   uint8 Impl_Sig4;
   uint8 Impl_Sig5;
   uint8 Impl_Sig6;
   uint8 Impl_Sig7; 
} E2E_ImpleDataType_CanFDFrame09_ADW;
typedef struct {
   uint8 Impl_Cks;
   uint8 Impl_Cnt;
   uint8 Impl_Sig1;
   uint8 Impl_Sig2;
   uint8 Impl_Sig3;
} E2E_ImpleDataType_CanFDFrame09_PPA;

/*TX*/
extern const E2E_P11ConfigType E2E_P11ConfigType_SACM_SecCanFrame01_ADL;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACM_SecCanFrame01_ADL;
extern const E2E_P11ConfigType E2E_P11ConfigType_SACM_SecCanFrame01_LAT;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACM_SecCanFrame01_LAT;
extern const E2E_P11ConfigType E2E_P11ConfigType_SACM_SecCanFrame01_PIN;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACM_SecCanFrame01_PIN;
extern const E2E_P11ConfigType E2E_P11ConfigType_SACMFram01_DRV;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram01_DRV;
extern const E2E_P11ConfigType E2E_P11ConfigType_SACMFram01_STE;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram01_STE;
extern const E2E_P11ConfigType E2E_P11ConfigType_SACMFram02_SSS;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram02_SSS;
extern const E2E_P11ConfigType E2E_P11ConfigType_SACMFram02_SST;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SACMFram02_SST;
extern const E2E_P11ConfigType E2E_P11ConfigType_SFCMBCCanFDFrame01;
extern E2E_P11ProtectStateType E2E_P11ProtectStateType_SFCMBCCanFDFrame01;

/*RX*/
extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_ADF;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_ADF;

extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_APA;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_APA;

extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_AAM;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_AAM;

extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame01_ALO;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame01_ALO;

extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame02_VSL;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame02_VSL;
extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame02_BPP;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame02_BPP;
extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame03_WFS;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame03_WFS;

extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame03_WRT;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame03_WRT;

extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame03_VMS;
extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame03_VMS;

//extern const E2E_P11ConfigType E2E_P11ConfigType_SecCanFrame04_VMM;
//extern E2E_P11CheckStateType E2E_P11CheckStateType_SecCanFrame04_VMM;

extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame06;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame06;

extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame01_ES;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame01_ES;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame01_VMM;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame01_VMM;

extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_ALC;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_ALC;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_ADR;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_ADR;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_AgD;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_AgD;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_WSCF;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_WSCF;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_WSCR;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_WSCR;

extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame04_LCR;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame04_LCR;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame07_GLI;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame07_GLI;

extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame07_ACA;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame07_ACA;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame07_PTA;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame07_PTA;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame09_ADW;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame09_ADW;
extern const E2E_P11ConfigType E2E_P11ConfigType_CanFDFrame09_PPA;
extern E2E_P11CheckStateType E2E_P11CheckStateType_CanFDFrame09_PPA;

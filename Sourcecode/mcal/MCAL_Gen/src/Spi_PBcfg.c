
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  VERSION   : 17.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2024-08-09, 16:12:51  !!!IGNORE-LINE!!!                   **
**                                                                            **
**  GENERATOR : Build b191017-0938      !!!IGNORE-LINE!!!                   **
**                                                                            **
**  BSW MODULE DECRIPTION : Spi.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Spi configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Spi Driver, AUTOSAR Release 4.2.2     **
**                     Specification of Spi Driver, AUTOSAR Release 4.4.0     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Module header file */
#include "Spi.h"
/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/
/* MISRA2012_RULE_4_9_JUSTIFICATION: More readble as macros. Code coplexity
reduces as well. */
#define Spi_BaudRateAndClockParam(TQ,LB,Q,A,B,C,CPH,CPOL,PAREN)                \
(                                                                  \
(uint32)(                                                         \
((uint32)TQ << 16U)|((uint32)LB << 30U)|((uint32)Q)|\
((uint32)A << 6U)|((uint32)B << 8U)|         \
((uint32)C << 10U)|((uint32)CPH << 12U)|        \
((uint32)CPOL << 13U)|((uint32)PAREN << 14U)     \
)                                                         \
)
/* MISRA2012_RULE_4_9_JUSTIFICATION: More readble as macros. Code coplexity
reduces as well. */
#define Spi_IdleLeadTrailParam(IPRE,IDLE,LPRE,LEAD,TPRE,TRAIL,PARTYP)          \
(                                                                  \
(uint32)(                                                         \
((uint32)IPRE << 1U)|((uint32)IDLE << 4U)|    \
((uint32)LPRE << 7U)|((uint32)LEAD << 10U)|   \
((uint32)TPRE << 13U)|((uint32)TRAIL << 16U)| \
((uint32)PARTYP << 19U)            \
)                                                         \
)
/*******************************************************************************
**                      Extern Declaration                                    **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/******************* GLOBAL CONFIGURATION MEMMAP SECTION *********************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32

/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
    
          
            
  /*Sequence Index Lookup*/
  static const uint8 SequenceLookupIndex[5] =
{
  /* Physical index value for Sequence SpiSequence_PreDriver1 Sequence ID 0 */
  0U,
    /* Physical index value for Sequence SpiSequence_PMIC Sequence ID 1 */
  2U,
    /* Physical index value for Sequence SpiSequence_CAN1 Sequence ID 2 */
  3U,
    /* Physical index value for Sequence SpiSequence_PreDriver2 Sequence ID 3 */
  1U,
    /* Physical index value for Sequence SpiSequence_CAN2 Sequence ID 4 */
  4U  
};

  /*Job Index Lookup*/
static const uint16 JobLookupIndex[5] =
{
  /* Physical index value for Job SpiJob_PreDriver1 Job ID 0 */
  0U,
    /* Physical index value for Job SpiJob_PMIC Job ID 1 */
  2U,
    /* Physical index value for Job SpiJob_CAN1 Job ID 2 */
  3U,
    /* Physical index value for Job SpiJob_PreDriver2 Job ID 3 */
  1U,
    /* Physical index value for Job SpiJob_CAN2 Job ID 4 */
  4U  
};

  /*Channel Index Lookup*/
static const uint8 ChannelLookupIndex[5] =
{
  /* Physical index value for channel SpiChannel_PreDriver1 channel ID 0 */
  1U,
    /* Physical index value for channel SpiChannel_PMIC channel ID 1 */
  2U,
    /* Physical index value for channel SpiChannel_CAN1 channel ID 2 */
  4U,
    /* Physical index value for channel SpiChannel_PreDriver2 channel ID 3 */
  0U,
    /* Physical index value for channel SpiChannel_CAN2 channel ID 4 */
  3U  
};

  /* Linked list for the Job[s] assigned to the sequence[s] Physical*/

static const Spi_JobType SpiSequence_PreDriver1_JobLinkPtr_Physical[] =
{
  0U, /* Physical index value for Job SpiJob_PreDriver1 Job ID 0 */
  
  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_PMIC_JobLinkPtr_Physical[] =
{
  2U, /* Physical index value for Job SpiJob_PMIC Job ID 1 */
  
  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_CAN1_JobLinkPtr_Physical[] =
{
  3U, /* Physical index value for Job SpiJob_CAN1 Job ID 2 */
  
  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_PreDriver2_JobLinkPtr_Physical[] =
{
  1U, /* Physical index value for Job SpiJob_PreDriver2 Job ID 3 */
  
  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_CAN2_JobLinkPtr_Physical[] =
{
  4U, /* Physical index value for Job SpiJob_CAN2 Job ID 4 */
  
  SPI_JOB_DELIMITER
};
  /* Linked list for the channel[s] assigned to the job[s] Physical */

static const Spi_ChannelType SpiJob_PreDriver1_ChannelLinkPtr_Physical[] =
{
  1U, /* Physical index value for Channel SpiChannel_PreDriver1 Channel ID 0 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_PMIC_ChannelLinkPtr_Physical[] =
{
  2U, /* Physical index value for Channel SpiChannel_PMIC Channel ID 1 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_CAN1_ChannelLinkPtr_Physical[] =
{
  4U, /* Physical index value for Channel SpiChannel_CAN1 Channel ID 2 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_PreDriver2_ChannelLinkPtr_Physical[] =
{
  0U, /* Physical index value for Channel SpiChannel_PreDriver2 Channel ID 3 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_CAN2_ChannelLinkPtr_Physical[] =
{
  3U, /* Physical index value for Channel SpiChannel_CAN2 Channel ID 4 */
  
  SPI_CHANNEL_DELIMITER
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/******************* GLOBAL CONFIGURATION MEMMAP SECTION *********************/
  
    
 /******************* CORE0 SEQUENCE CONFIGURATION MEMMAP SECTION *************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_SequenceConfigType Spi_kSequenceConfig_Core0[] =
{
        /* Sequence:SpiSequence_PreDriver1 */
  {
    SpiConf_SpiSequence_SpiSequence_PreDriver1,
    /* Job linked list */
    SpiSequence_PreDriver1_JobLinkPtr_Physical,
    /* No. of jobs in Seq */
    1U,
        /* Hw Module Used (b000001)*/
    0x01U,
        
              0U /* Sync Sequence */
      },
  /* Sequence:SpiSequence_PreDriver2 */
  {
    SpiConf_SpiSequence_SpiSequence_PreDriver2,
    /* Job linked list */
    SpiSequence_PreDriver2_JobLinkPtr_Physical,
    /* No. of jobs in Seq */
    1U,
        /* Hw Module Used (b000001)*/
    0x01U,
        
              0U /* Sync Sequence */
      },
    /* Synchronous Sequence[s] */
    /* Sequence:SpiSequence_PMIC */
  {
    SpiConf_SpiSequence_SpiSequence_PMIC,
    /* Job linked list */
    SpiSequence_PMIC_JobLinkPtr_Physical,
    /* No. of jobs in Seq */
    1U,
        /* Hw Module Used (b000010)*/
    0x02U,
        
              0U /* Sync Sequence */
      },
    /* Synchronous Sequence[s] */
    /* Sequence:SpiSequence_CAN1 */
  {
    SpiConf_SpiSequence_SpiSequence_CAN1,
    /* Job linked list */
    SpiSequence_CAN1_JobLinkPtr_Physical,
    /* No. of jobs in Seq */
    1U,
        /* Hw Module Used (b000011)*/
    0x03U,
        
              0U /* Sync Sequence */
      },
  /* Sequence:SpiSequence_CAN2 */
  {
    SpiConf_SpiSequence_SpiSequence_CAN2,
    /* Job linked list */
    SpiSequence_CAN2_JobLinkPtr_Physical,
    /* No. of jobs in Seq */
    1U,
        /* Hw Module Used (b000011)*/
    0x03U,
        
              0U /* Sync Sequence */
      }};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 SEQUENCE CONFIGURATION MEMMAP SECTION END *************/
    
    
/******************* CORE0 JOB CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_JobConfigType Spi_kJobConfig_Core0[] =
{
      /* Synchronous Job[s] */
  /* Job:SpiJob_PreDriver1 */
  {
    SpiConf_SpiJob_SpiJob_PreDriver1,
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
    (0x00U), (0x00U),          /* TQ , LoopBack */
    (0x04U), (0x00U),          /*  Q , A        */
    (0x00U), (0x01U),          /*  B , C        */
    (0x01U), (0x00U),          /*  CPH , CPOL   */
    (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
    (1U), (0U), /* IPRE,IDLE:   IdleA/B delay = 2.0E-7s */
    (1U), (0U), /* LPRE,LEAD:   Lead delay    = 2.0E-7s */
    (1U), (0U),/* TPRE, TRAIL: Trail delay   = 2.0E-7s */
    (1U)
    ),
    SpiJob_PreDriver1_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)0U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
    /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL5 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Job:SpiJob_PreDriver2 */
  {
    SpiConf_SpiJob_SpiJob_PreDriver2,
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
    (0x00U), (0x00U),          /* TQ , LoopBack */
    (0x04U), (0x00U),          /*  Q , A        */
    (0x00U), (0x01U),          /*  B , C        */
    (0x01U), (0x00U),          /*  CPH , CPOL   */
    (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
    (1U), (0U), /* IPRE,IDLE:   IdleA/B delay = 2.0E-7s */
    (1U), (0U), /* LPRE,LEAD:   Lead delay    = 2.0E-7s */
    (1U), (0U),/* TPRE, TRAIL: Trail delay   = 2.0E-7s */
    (1U)
    ),
    SpiJob_PreDriver2_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)1U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
    /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL0 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Synchronous Job[s] */
  /* Job:SpiJob_PMIC */
  {
    SpiConf_SpiJob_SpiJob_PMIC,
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
    (0x00U), (0x00U),          /* TQ , LoopBack */
    (0x04U), (0x00U),          /*  Q , A        */
    (0x00U), (0x01U),          /*  B , C        */
    (0x01U), (0x00U),          /*  CPH , CPOL   */
    (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
    (1U), (0U), /* IPRE,IDLE:   IdleA/B delay = 2.0E-7s */
    (1U), (0U), /* LPRE,LEAD:   Lead delay    = 2.0E-7s */
    (1U), (0U),/* TPRE, TRAIL: Trail delay   = 2.0E-7s */
    (1U)
    ),
    SpiJob_PMIC_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)1U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
    /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL5 << 4U)|SPI_QSPI2_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Synchronous Job[s] */
  /* Job:SpiJob_CAN1 */
  {
    SpiConf_SpiJob_SpiJob_CAN1,
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
    (0x00U), (0x00U),          /* TQ , LoopBack */
    (0x04U), (0x00U),          /*  Q , A        */
    (0x00U), (0x01U),          /*  B , C        */
    (0x00U), (0x00U),          /*  CPH , CPOL   */
    (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
    (1U), (0U), /* IPRE,IDLE:   IdleA/B delay = 2.0E-7s */
    (1U), (0U), /* LPRE,LEAD:   Lead delay    = 2.0E-7s */
    (1U), (0U),/* TPRE, TRAIL: Trail delay   = 2.0E-7s */
    (1U)
    ),
    SpiJob_CAN1_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
    /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL6 << 4U)|SPI_QSPI3_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Job:SpiJob_CAN2 */
  {
    SpiConf_SpiJob_SpiJob_CAN2,
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
    (0x00U), (0x00U),          /* TQ , LoopBack */
    (0x04U), (0x00U),          /*  Q , A        */
    (0x00U), (0x01U),          /*  B , C        */
    (0x00U), (0x00U),          /*  CPH , CPOL   */
    (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
    (1U), (0U), /* IPRE,IDLE:   IdleA/B delay = 2.0E-7s */
    (1U), (0U), /* LPRE,LEAD:   Lead delay    = 2.0E-7s */
    (1U), (0U),/* TPRE, TRAIL: Trail delay   = 2.0E-7s */
    (1U)
    ),
    SpiJob_CAN2_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
    /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL12 << 4U)|SPI_QSPI3_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  }};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 JOB CONFIGURATION MemMap SECTION END *************/
    
    
/******************* CORE0 CHANNEL CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_ChannelConfigType Spi_kChannelConfig_Core0[] =
{
      /* Synchronous Chnl[s] QSPI1 core0*/
  /* Channel:SpiChannel_PreDriver2 */
  {
    0x00000000U,     /* Default data */
    0x0001U,         /* Number of Data Elements */
    SPI_IB_CHANNEL,  /* Internal Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_PreDriver2
  },
  /* Channel:SpiChannel_PreDriver1 */
  {
    0x00000000U,     /* Default data */
    0x0001U,         /* Number of Data Elements */
    SPI_IB_CHANNEL,  /* Internal Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_PreDriver1
  },
  /* Synchronous Chnl[s] QSPI2 core0*/
  /* Channel:SpiChannel_PMIC */
  {
    0x00000000U,     /* Default data */
    0x0001U,         /* Number of Data Elements */
    SPI_IB_CHANNEL,  /* Internal Buffer Channel */
    0x98U,            /* MSB[7], DataWidth=24[6:0] */
    SpiConf_SpiChannel_SpiChannel_PMIC
  },
  /* Synchronous Chnl[s] QSPI3 core0*/
  /* Channel:SpiChannel_CAN2 */
  {
    0x00000000U,     /* Default data */
    0x0001U,         /* Number of Data Elements */
    SPI_IB_CHANNEL,  /* Internal Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_CAN2
  },
  /* Channel:SpiChannel_CAN1 */
  {
    0x00000000U,     /* Default data */
    0x0001U,         /* Number of Data Elements */
    SPI_IB_CHANNEL,  /* Internal Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_CAN1
  }};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 JOB CONFIGURATION MemMap SECTION END *************/
    
      /******************* CORE0 QSPI1 CONFIGURATION MEMMAP SECTION *************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* QSPI1 */

static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI1 =
{
  0x00210000U,               /* Active CS Level, SSOC SFR value */
  0U,                        /* Queue length can be ignored for Sync */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)0U,                 /* Input class, MRIS bit field in PISEL SFR */
  2U,                         /* Max Sequence Count on the QSPI */
  0U,  /* External Demultiplexer feature is disabled */
  0U /* SLSO0 Strobe delay */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 QSPI1 CONFIGURATION MemMap SECTION END *************/
      /******************* CORE0 QSPI2 CONFIGURATION MEMMAP SECTION *************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* QSPI2 */

static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI2 =
{
  0x00200000U,               /* Active CS Level, SSOC SFR value */
  0U,                        /* Queue length can be ignored for Sync */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)1U,                 /* Input class, MRIS bit field in PISEL SFR */
  1U,                         /* Max Sequence Count on the QSPI */
  0U,  /* External Demultiplexer feature is disabled */
  0U /* SLSO0 Strobe delay */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 QSPI2 CONFIGURATION MemMap SECTION END *************/
      /******************* CORE0 QSPI3 CONFIGURATION MEMMAP SECTION *************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* QSPI3 */

static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI3 =
{
  0x10400000U,               /* Active CS Level, SSOC SFR value */
  0U,                        /* Queue length can be ignored for Sync */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)3U,                 /* Input class, MRIS bit field in PISEL SFR */
  2U,                         /* Max Sequence Count on the QSPI */
  0U,  /* External Demultiplexer feature is disabled */
  0U /* SLSO0 Strobe delay */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 QSPI3 CONFIGURATION MemMap SECTION END *************/
                  
/********************CORE0 RX/TX BUFFERS MEMMAP SECTION***********************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* Lookup table to hold the offset in buffer and total elements to be transferred for all IB channels.
Index - Represents channel number, 1st element - Offset in buffer, 2nd element - Total elements to be transmitted */

static const Spi_CoreChannelOffsetType Spi_ChannelOffsets_Core0[SPI_NUM_IB_CHANNELS_CORE0 +  SPI_NUM_EB_CHANNELS_CORE0 + 1U] =
{
{0, 1},  /* for IB channels SpiChannel_PreDriver2 */
/* Get the Channel Width */
{4, 1},  /* for IB channels SpiChannel_PreDriver1 */
/* Get the Channel Width */
{8, 1},  /* for IB channels SpiChannel_PMIC */
/* Get the Channel Width */
{12, 1},  /* for IB channels SpiChannel_CAN2 */
/* Get the Channel Width */
{16, 1},  /* for IB channels SpiChannel_CAN1 */
/* Get the Channel Width */
  {0xFFFF, 0xFFFF}
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/********************CORE0 RX/TX BUFFERS MEMMAP SECTION***********************/
    
/******************* CORE0 Spi_Config_Core CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* MISRA2012_RULE_8_7_JUSTIFICATION: Spi_Config_Core0 is used outside
* of this file and therefore it is not declared as static */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Agreed violation */

const Spi_CoreConfigType Spi_Config_Core0 =
{
  /* Sequence Configuration */
  Spi_kSequenceConfig_Core0,
  /* Job configuration */
  Spi_kJobConfig_Core0,
  /* Channel Configuration */
  Spi_kChannelConfig_Core0,
  Spi_ChannelOffsets_Core0,
  /* QSPI Hw configuration */
  {
    NULL_PTR,
    &Spi_kQspiHwConfigQSPI1,
    &Spi_kQspiHwConfigQSPI2,
    &Spi_kQspiHwConfigQSPI3,
    
  },
  /* Hw Map Index */      
  /*
  (000 QSPI not configured for core0)
  (001 QSPI configured as Sync for core0)
  (010 QSPI configured as Async for core0)
  (011 QSPI configured for core0)
  QSPI5 - 0
  QSPI4 - 0
  QSPI3 - 1
  QSPI2 - 1
  QSPI1 - 1
  QSPI0 - 0*/
  0x00248U,
  /* No. of Sequences configured */
  5U,
  /* No. of Jobs configured */
  5U,
  /* No. of Channels configured */
  5U
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 Spi_Config_Core CONFIGURATION MemMap SECTION END *************/
          

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

const Spi_ConfigType Spi_Config =
{
  {
    &Spi_Config_Core0,
    NULL_PTR
  },
  SequenceLookupIndex,
  JobLookupIndex,
  ChannelLookupIndex,
  /*Total number of Sequence*/
  5U,
  /*Total number of Jobs*/
  5U,
  /*Total number of Channels*/
  5U,
  /*Sync Delay*/
  65535U
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"/* End Of File */

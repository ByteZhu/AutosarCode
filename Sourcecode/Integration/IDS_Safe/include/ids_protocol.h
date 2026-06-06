/***************************************************************************************
 * File Name   : ids_protocol.h                                                        *
 * Created by  : DengWei  2024/10/12                                                   *
 *                                                                                     *
 * Description : Provide external interfaces for IdsM                                  *
 *                                                                                     *
 * Modified Details (Modified Date/Modifier/ Modified Reason):                         *
 *  1: 2024/10/12    DengWei    initial                                                *
 *                                                                                     *
 ***************************************************************************************/
#ifndef __IDS_PROTOCOL__
#define __IDS_PROTOCOL__

#ifdef __cplusplus
extern "C"
{
#endif

    /****************Include  Section Begin*********************************************/

#include <stdint.h>

    /****************Include  Section  End**********************************************/

    /****************NameSpace  Section  Begin******************************************/

    /****************NameSpace  Section  End********************************************/

    /****************Marco Definition Section Begin*************************************/

    /**
     * IDS Event Frame
     * +--------+----------+-------------+-------+-------+-------+-------+-------+-------+-------+
     * |           Byte0                 | Byte1 | Byte2 | Byte3 | Byte4 | Byte5 | Byte6 | Byte7 |
     * +--------+----------+-------------+-------+-------+-------+-------+-------+-------+-------+
     * | bit7   | bit6     | bit5..0     |                       |                               |
     * | Source | Reserved |              Nanoseconds            |             Seconds           |
     * +--------+----------+-------------+-------+-------+-------+-------+-------+-------+-------+
     * Byte0:
     * Bit[7]: Timestamp source
     * 0: AUTOSAR Standard CP: StbM - AP: ara::tsync
     * 1: Auxiliary / OEM Specific timestamp
     * Bit[6]: reserved
     *
     * Nanoseconds
     * For nanoseconds only 30 Bits are required to encode 0..999 999999 ns = 10-9 seconds.
     *
     * Seconds
     * Seconds are encoded with 32 Bits which result in approximately 127 years resolution.
     */
    typedef uint64_t Ids_TimestampType;

    /**
     * Context Data Frame
     * +----------------+---------+-------+-------+-------+-------+-------+---------+
     * | Byte0                    | Byte1 | Byte2 | Byte3 | Byte4 | Byte5 | Byte..  |
     * +----------------+---------+-------+-------+-------+-------+-------+---------+
     * | bit7           | bit6..0 |                       |                         |
     * | Length Format  | Length  |      Length/Data      |             Data        |
     * +----------------+---------+-------+-------+-------+-------+-------+---------+
     *
     * Context Data Byte[0] Bit[7]
     *   0: 7 Bits length information encoded in Context Data Byte[0] Bit[0..6]: 1-127Bytes
     *   1: 31 Bits Length Information encoded in Context Data Byte[0..3] Bit[0..30]: 1..(2^31-1) Bytes
     */
    typedef uint8_t IdsProtocolContextData;

    /****************Marco Definition Section End***************************************/

    /****************Struct Definition Section Begin************************************/
    /**
     * IDS Event Frame
     * +------------------+----------+-----------+-----------+-------------+
     * |                             Byte0                                 |
     * +------------------+----------+-----------+-----------+-------------+
     * | bit7-bit4        | bit3     | bit2      | bit1      | bit0        |
     * | Protocol Version | Reserved | Signature | Timestamp | ContextData |
     * +------------------+----------+-----------+-----------+-------------+
     *
     * +-----------------+-------------+--------------------+--------------+
     * |       Byte1     |                              Byte2              |
     * +-----------------+-------------+--------------------+--------------+
     * |    bit7-bit0    |   bit7-6    |                bit5-bit0          |
     * |     IDS Instance ID           | Sensor Instance ID                |
     * +-----------------+-------------+--------------------+--------------+
     *
     * +----------------+------------+---------+-----------+---------------+
     * |       Byte3    |   Byte4    |  Byte5  |   Byte6   |     Byte7     |
     * +----------------+------------+---------+-----------+---------------+
     * |     Event Definition ID     |      Count          |   Reserved    |
     * +----------------+------------+---------+-----------+---------------+
     *
     */
    typedef struct IdsProtocolEvent
    {
        uint8_t infoProtocol;
        uint16_t idController;
        uint16_t idSEv;
        uint16_t count;
    } IdsProtocolEvent;

    /****************Struct Definition Section End**************************************/

    /****************Class Declaration Section Begin************************************/

    /**************** Class Declaration Section End*************************************/

    /****************Function Prototype Declaration Section Begin***********************/

    /****************Function Prototype Declaration Section End*************************/

#ifdef __cplusplus
}
#endif

#endif /* __IDS_PROTOCOL__ */

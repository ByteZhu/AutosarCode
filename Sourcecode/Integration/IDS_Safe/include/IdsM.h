/***************************************************************************************
 * File Name   : IdsM.h                                                                *
 * Created by  : DengWei  2024/10/12                                                   *
 *                                                                                     *
 * Description : Provide external interfaces for IdsM                                  *
 *                                                                                     *
 * Modified Details (Modified Date/Modifier/ Modified Reason):                         *
 *  1: 2024/10/12    DengWei    initial                                                *
 *                                                                                     *
 ***************************************************************************************/

#ifndef __IDSM_H__
#define __IDSM_H__

#ifdef __cplusplus
extern "C"
{
#endif

    /****************Include  Section Begin*************************************************/

#include <stdint.h>
#include <stddef.h>
#include "security_event.h"
#include "ids_protocol.h"

    /****************Include  Section  End**************************************************/

    /****************NameSpace  Section  Begin**********************************************/

    /****************NameSpace  Section  End************************************************/

    /****************Marco Definition Section Begin*****************************************/

    /****************Marco Definition Section End*******************************************/

    /****************Struct Definition Section Begin****************************************/

    /****************Struct Definition Section End******************************************/

    /****************Class Declaration Section Begin****************************************/

    /**************** Class Declaration Section End*****************************************/

    /****************Function Prototype Declaration Section Begin***************************/

    /**
     * Initialize the Ids library resources.
     *
     * The Ids module is initialized via Ids_Init. 
     * The API functions of the Ids module may only be called after the
     * module has been properly initialized.
     *
     * @return None
     */
    void Ids_Init(void);

    /**
     * Deinitialize the Ids library resources.
     *
     * The function is used to deinitialize the Ids. 
     * This API needs to be called when shutting down IdsS.
     * 
     * @return None
     */
    void Ids_Deinit(void);

    /**
     * Get Ids state.
     *
     * The function is used to get the state of Ids. 
     * 
     * @return -1: uninit; 0: normal; 1: is writting NVM
     */
    int8_t Ids_GetState(void);

    /**
     * Security event processing.
     *
     * The function is called at regular intervals to process
     * security events in the current queue by IDS.
     *
     * @return None
     */
    void Ids_MainFunction(void);

    /**
     * This API is the application interface to report security events to the IdsM.
     *
     * @param securityEventId Security Event ID.
     * @return None.
     */
    void Ids_SetSecurityEvent(
        IdsM_SecurityEventIdType securityEventId);

    /**
     * This API is the application interface to report security events with context data to the IdsM.
     *
     * @param securityEventId Security Event ID.
     * @param contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
     * @param contextDataSize Size of context data
     * @return None.
     */
    void Ids_SetSecurityEventWithContextData(
        IdsM_SecurityEventIdType securityEventId,
        const uint8_t *contextData,
        uint16_t contextDataSize);

    /**
     * This API is the application interface for Smart Sensors to report security events with a count
     * value to the IdsM.
     *
     * @param securityEventId Security Event ID.
     * @param count Count value which is used as the start value for the security event.
     * @return None.
     */
    void Ids_SetSecurityEventWithCount(
        IdsM_SecurityEventIdType securityEventId,
        uint16_t count);

    /**
     * This API is the application interface for Smart Sensors to report security events with a count
     * value and context data to the IdsM.
     *
     * @param securityEventId Security Event ID.
     * @param count Count value which is used as the start value for the security event.
     * @param contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
     * @param contextDataSize Size of context data
     * @return None.
     */
    void Ids_SetSecurityEventWithCountContextData(
        IdsM_SecurityEventIdType securityEventId,
        uint16_t count,
        const uint8_t *contextData,
        uint16_t contextDataSize);

    /**
     * This API is the application interface for Smart Sensors to report security events with a
     * timestamp and a count value to the IdsM.
     *
     * @param securityEventId Security Event ID.
     * @param timestamp Timestamp used for time reference of the security event.
     * @param count Count value which is used as the start value for the security event.
     * @return None.
     */
    void Ids_SetSecurityEventWithTimestampCount(
        IdsM_SecurityEventIdType securityEventId,
        Ids_TimestampType timestamp,
        uint16_t count);

    /**
     * This API is the application interface for Smart Sensors to report security events with a
     * timestamp, a count value and context data to the IdsM.
     *
     * @param securityEventId Security Event ID.
     * @param timestamp Timestamp used for time reference of the security event.
     * @param count Count value which is used as the start value for the security event.
     * @param contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
     * @param contextDataSize Size of context data
     * @return None.
     */
    void Ids_SetSecurityEventWithTimestampCountContextData(
        IdsM_SecurityEventIdType securityEventId,
        Ids_TimestampType timestamp,
        uint16_t count,
        const uint8_t *contextData,
        uint16_t contextDataSize);

    /****************Function Prototype Declaration Section End*****************************/

#ifdef __cplusplus
}
#endif

#endif /* __IDSM_H__ */

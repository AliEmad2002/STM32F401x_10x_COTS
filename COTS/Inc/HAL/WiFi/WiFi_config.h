/*
 * WiFi_config.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Ali Emad Ali
 */

#ifndef INCLUDE_HAL_WIFI_WIFI_CONFIG_H_
#define INCLUDE_HAL_WIFI_WIFI_CONFIG_H_


#define WIFI_MAX_RESPONSE_LEN			2048

#define WIFI_MAX_PARAM_LEN				128

#define WIFI_MAX_NUMBER_OF_PARAMS		10

#define WIFI_ERR_CODE					0

#define WIFI_ERROR_HANDLER				ErrorHandler_voidExecute(WIFI_ERR_CODE)

#define WIFI_AP_CONNECT_TIMEOUT_MS				30000

#define WIFI_COMMAND_ACK_RESPONSE_TIMEOUT_MS	10000

#define WIFI_COMMUNICATION_INTERVAL_DELAY_MS	100

#endif /* INCLUDE_HAL_WIFI_WIFI_CONFIG_H_ */

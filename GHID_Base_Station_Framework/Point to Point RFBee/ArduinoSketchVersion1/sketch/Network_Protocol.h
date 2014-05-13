/*
 * Network_Protocol.h
 *
 *  Created on: Jul 24, 2013
 *      Author: fjpapin
 */


#ifndef _Network_Protocol_h_
#define _Network_Protocol_h_

//! Internal State Machine.

#include "Hardware_Defines.h"

/**
 * These are the possible commands the router
 * can send.
 */
#define PING						0x01
#define CONFIG_REQ					0x02
#define STATUS_REQ					0x03

/**
 * The sync command is structured as follows:
 * 	- 0x04, time to sync, heartbeat freq
 */
#define SYNC						0x04
#define START						0x05
#define STOP						0x06
#define ABORT						0x07
#define ERROR_RQ					0x08
#define PAUSE						0x09

#define HEARTBEAT_FREQ				0x10
#define REQUEST_NUMBER				0x11

// Packet format macros
#define PACKET_FORMAT				0x03
#define PACKET_PREAMBLE				'@'
#define PACKET_TAIL					'\n'

// Possible reports received
#define SENSOR_ACK					0x14
#define SENSOR_CONFIG_REPORT		0x15
#define SENSOR_STATUS_REPORT		0x16
#define SENSOR_DATA_REPORT			0x17
#define SENSOR_SYNC_REPORT			0x18
#define SENSOR_HEARTBEAT_REPORT		0x19
#define SENSOR_ERROR_REPORT			0x20

// Command Descriptors
#define USB_DEVICE_CMD				0x31

// Internal packet_id values
#define PACKET_ANY					0xFE
#define PACKET_NULL					0xFF

// Base sync time
#define BASE_SYNC_TIME				1000 //1SEC
#define PACKET_WRAP					3

// *************************************************
// *************** REMOTE DOMAIN *******************
// *************************************************

typedef struct sensor_packet_header_t {

	uint8_t message_size;
	uint8_t packet_id;
	uint8_t sensor_id;
	uint32_t sensor_run_time;
	uint8_t packet_version;
};

// *************************************************
//! Sensor acknowledge message structure
//!	- 0/1 true of false
typedef struct sensor_ack_info_t {

	boolean ack;
};

//! Sensor configs report
//! - [sensor type][# of channels][channel types]
//! 	- [A, D][0 - 8][0,0,1,1,1,0,0,0]
typedef struct sensor_configs_t {

	uint8_t sensor_type;
	uint8_t num_channels;
	uint8_t channel_types;
};

#define SENSOR_STATE_OK		1
#define SENSOR_STATE_FAIL	2
#define SENSOR_STATE_ERROR	3
#define SENSOR_STATE_BOOT	4
#define SENSOR_STATE_REBOOT	5
#define SENSOR_STATE_RESET	6

//! Sensor status report
//! - [STATE]
//! - 1 - OK
//! - 2 - FAIL
//! - 3 - ERROR
//! - 4 - BOOT
//! - 5 - REBOOT
//!	- 6 - RESET
//! - 7 - N/A
//! - 8 - N/A
typedef struct sensor_status_report_t {
	uint8_t state;
};

//! Sensor data report
//! - [channel data][channel data][...]
//! - 8*8 bits - max value 0 -> 255
typedef struct sensor_data_struct_t {

	uint8_t data_array[8];
};

//! Sensor sync report
typedef struct sensor_sync_report_t {

	uint16_t sync_time;
	uint8_t interrupt_number;
	uint8_t priority;

};

#define SENSOR_BOOT_TAG		1
#define SENSOR_INIT_TAG		2
#define SENSOR_RUN_TAG		3
#define SENSOR_PAUSE_TAG	4
#define SENSOR_IDLE_TAG		5
#define SENSOR_STOP_TAG		6
#define SENSOR_ERROR_TAG	7
#define SENSOR_REBOOT_TAG	8	

//! Sensor heartbeat report
//! - BOOT		- 1
//! - INIT		- 2
//! - RUN		- 3
//! - PAUSE		- 4
//! - IDLE		- 5
//! - STOP		- 6
//! - ERROR		- 7
//! - REBOOT	- 8
typedef struct sensor_heartbeat_t {
	uint8_t sensor_mode;
	uint16_t battery_voltage;
};

#define SENSOR_BOOT_ERROR		1
#define SENSOR_MEM_ERROR		2
#define SENSOR_RUN_ERROR		3
#define SENSOR_SYNC_ERROR		4
#define SENSOR_PACK_ERROR		5
#define SENSOR_INTE_ERROR		6
#define SENSOR_RESE_ERROR		7
#define SENSOR_SHUT_ERROR		8

//! Sensor error report
//! - Error codes
//! - 1 - Boot error
//! - 2 - Memory error
//! - 3 - Runtime error
//! - 4 - Sync error
//! - 5 - Packet format error
//!	- 6 - Interrupt error
//! - 7 - Reset error
//! - 8 - Shut-down error
typedef struct sensor_error_t {

	uint8_t error_code;
};

#endif






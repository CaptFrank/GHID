/*
 * ProtocolDefinition.h
 *
 *  Created on: 2014-05-26
 *      Author: francispapineau
 */

#ifndef PROTOCOLDEFINITION_H_
#define PROTOCOLDEFINITION_H_

#include "HardwareDefines.h"
#include "BluetoothConnectionCommands.h"

/**
 * This is the generic Sensor to Base Station protocol definition.
 * Within this protocol, the allocated memory space and byte definitions
 * are defined.
 */

//! Packet IDs
#define SENSOR_PACKET_HEARTBEAT					0x01
#define SENSOR_PACKET_ERROR						0x02
#define SENSOR_PACKET_DATA						0x03

#define SENSOR_PACKET_PREAMBLE					'#'
#define SENSOR_PACKET_TAIL						'*'

//! -----------------------------------------------------------------------

/**
 * This is the sensor type enum.
 */
enum sensor_t {

	SENSOR_MOUSE,  		//!< SENSOR_MOUSE
	SENSOR_JOYSTICK		//!< SENSOR_JOYSTICK
};

//! -----------------------------------------------------------------------
//! 						PACKET HEADER
//! -----------------------------------------------------------------------

/**
 * This is the header information that will be sent to the basestation.
 * It holds all the packet configuration data as well as the sensor hardware
 * definitions.
 */
typedef struct sensor_packet_header_t {

	//! Packet Configurations
	struct packet_id_t {

		//! Preamble - Determines when the packet starts
		static const uint8_t 	packet_preamble = SENSOR_PACKET_PREAMBLE;

		uint16_t 				packet_length;
		uint8_t 				packet_type;
		uint32_t 				packet_timestamp;

	} _packet_configs;

	//! Sensor Identification
	struct sensor_id_t{

		uint8_t 				packet_sensor_id;

		//! This is the configuration type, either mouse or joystick.
		sensor_t 				packet_sensor_type;

	} _sensor_id;
};

//! -----------------------------------------------------------------------
//! 						ERROR PACKET
//! -----------------------------------------------------------------------


/**
 * This is the error packet type that is sent when there is a critical error
 * that is produced or asserted within the sensor node system.
 */
typedef struct sensor_packet_error_t {

	//! The header definition
	struct sensor_packet_header_t _header;

	//! The error code
	uint8_t						error_code;

	//! Tail - Determines when the packet stops
	static const uint8_t 		packet_tail = SENSOR_PACKET_TAIL;
};

//! -----------------------------------------------------------------------
//!							HEARTBEAT PACKET
//! -----------------------------------------------------------------------

/**
 * This is the heartbeat packet definition.
 * It is simply a header component with a preamble byte.
 */
typedef struct sensor_packet_heartbeat_t {

	//! The header definition
	struct sensor_packet_header_t _header;

	//! Tail - Determines when the packet stops
	static const uint8_t 		packet_tail = SENSOR_PACKET_TAIL;

};

//! -----------------------------------------------------------------------
//! 						DATAGRAM PACKET
//! -----------------------------------------------------------------------

/**
 * This is the data packet for the sensors on within the sensor node system.
 * It comprises of the header, the configurations of the sensor (Axis, Buttons)
 * and the data in the form of an array of bytes
 */
typedef struct sensor_packet_data_t {

	//! The header definition
	struct sensor_packet_header_t _header;

	//! Sensor Configurations
	struct sensor_config_t {

		//! The mouse or joystick configurations.
		static const uint8_t 		packet_sensor_axis = NUM_AXES;
		static const uint8_t		packet_sensor_buttons = (NUM_BUTTONS / 8) + 1;

	} _sensor_configs;

	//! The Sensor Data
	struct sensor_data_t {

		//! Axis data
		uint16_t 					packet_sensor_axis_data[NUM_AXES];

		//! Button data
		uint16_t 					packet_sensor_button_data[(NUM_BUTTONS / 8) + 1];
	}_sensor_data;

	//! Tail - Determines when the packet stops
	static const uint8_t 		packet_tail = SENSOR_PACKET_TAIL;
};

//! -----------------------------------------------------------------------
//! 					SERVER COMMAND PACKET
//! -----------------------------------------------------------------------

/**
 * These are the possible server commands that can be issued.
 */
enum server_command_t {

	REBOOT_CMD						= REBOOT,  			//!< REBOOT_CMD
	RESET_CMD						= RESET,    		//!< RESET_CMD
	SUSPEND_CMD						= SUSPEND,			//!< SUSPEND_CMD
	RESUME_CMD						= RESUME,  			//!< RESUME_CMD
	START_CMD						= START,    		//!< START_CMD
	STOP_CMD						= STOP,      		//!< STOP_CMD
	GET_CMD							= GET        		//!< GET_CMD

};

#endif /* PROTOCOLDEFINITION_H_ */

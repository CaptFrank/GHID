/*
 * ProtocolDefinition.h
 *
 *  Created on: 2014-05-26
 *      Author: francispapineau
 */

#ifndef PROTOCOLDEFINITION_H_
#define PROTOCOLDEFINITION_H_

/**
 * This is the generic Sensor to Base Station protocol definition.
 * Within this protocol, the allocated memory space and byte definitions
 * are defined.
 */

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
		const uint8_t 		packet_preamble = SENSOR_PACKET_PREAMBLE;

		uint16_t 			packet_length;
		uint8_t 			packet_type;
		uint32_t 			packet_timestamp;
		uint8_t 			packet_status;

	} _packet_configs;

	//! Sensor Identification
	struct sensor_id_t{

		uint8_t 			packet_sensor_id;

		//! This is the configuration type, either mouse or joystick.
		sensor_t 			packet_sensor_type;

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
	uint8_t error_code;

	//! Tail - Determines when the packet stops
	const uint8_t 		packet_tail = SENSOR_PACKET_TAIL;
};

//! -----------------------------------------------------------------------
//!							HEARTBEAT PACKET
//! -----------------------------------------------------------------------

/**
 * This is the hearbeat packet definition.
 * It is simply a header compoenent with a preamble byte.
 */
typedef struct sensor_packet_heartbeat_t {

	//! The header definition
	struct sensor_packet_header_t _header;

	//! Tail - Determines when the packet stops
	const uint8_t 		packet_tail = SENSOR_PACKET_TAIL;

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
		uint8_t 			packet_sensor_axis;
		uint8_t				packet_sensor_buttons;

	} _sensor_configs;

	//! The Sensor Data
	struct sensor_data_t {

		//! Axis data
		uint8_t 			packet_sensor_axis_data[_sensor_configs.packet_sensor_axis];

		//! Button data
		uint8_t 			packet_sensor_button_data[_sensor_configs.packet_sensor_buttons];
	}_sensor_data;

	//! Tail - Determines when the packet stops
	const uint8_t 		packet_tail = SENSOR_PACKET_TAIL;
};

//! -----------------------------------------------------------------------


#endif /* PROTOCOLDEFINITION_H_ */

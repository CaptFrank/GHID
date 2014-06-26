/*
 * DataProcessor.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_

#include <Arduino.h>
#include "RingBuffer.h"
#include "ProtocolDefinition.h"

//! Size of message
#define MAX_SIZE		3*(sizeof(int))

/**
 * This is the buffer type definition.
 */
typedef struct buffer_t {

	//! The length of the buffer.
	byte length;

	//! The data in the buffer.
	byte data[MAX_SIZE + 1];
	
	//! Valid?
	bool valid;
};

/**
 * This class is the data processor for the Bluetooth connection. It is a basic
 * static class which, takes in a buffer of data and strips the unnecessary bytes
 * from it, as well as check if the data is valid or not.
 */
class Data_Processor {

	//! Public Context
	public:
		
		/**
		 *	This creates a heartbeat message to send to the base station.
		 * 
		 * @param sensor_type								- the sensor type (mouse, joystick)
		 * @param sensor_id									- the sensor id	
		 * @param heart										- the structure ptr to store the information
		 */
		static void create_heartbeat(sensor_t sensor_type, char sensor_id, 
									 sensor_packet_heartbeat_t* heart);
		
		/**
		 *	This create an error report.
		 * 
		 * @param sensor_type								- the sensor type (mouse, joystick)
		 * @param sensor_id									- the sensor id
		 * @param error_id									- the error that occured
		 * @param error										- the structure ptr to store the information
		 */
		static void create_error(sensor_t sensor_type, char sensor_id, uint8_t error_id, 
								 sensor_packet_error_t* error);
		
		/**
		 *	This creates a data report
		 * 
		 * @param sensor_type								- the sensor type (mouse, joystick)
		 * @param sensor_id									- the sensor id	
		 * @param buf										- the ring buffer
		 * @param data										- the structure ptr to store the information
		 */
		static void create_data_packet(sensor_t sensor_type, char sensor_id, 
									   RingBuff_t* buf, sensor_packet_data_t* data);
									   
	//! Private Context
	private:
		
		/**
		 *	This creates a header message to send to the base station.
		 * 
		 * @param sensor_type								- the sensor type (mouse, joystick)
		 * @param sensor_id									- the sensor id	
		 * @param heart										- the structure ptr to store the information
		 */
		static void _create_header(sensor_t sensor_type, char sensor_id, 
									 sensor_packet_header_t* head);
};

#endif /* DATAPROCESSOR_H_ */

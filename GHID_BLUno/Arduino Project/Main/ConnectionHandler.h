/*
 * ConnectionHandler.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef CONNECTIONHANDLER_H_
#define CONNECTIONHANDLER_H_

#include <Arduino.h>
#include "DataProcessor.h"

/**
 * This is the definition of the transmit buffer.
 */
typedef struct tx_buffer_t {

	uint8_t _data[DATA_PACKET_SIZE];
	static const uint8_t _size = DATA_PACKET_SIZE;
};

/**
 * This is the callback definition type.
 */
typedef struct callback_t {

	//! Registers the command to trigger on
	byte command_id;

	//! Registers the callback method.
	//! *** Note: This method must be static.
	void(*callback)(void* object, uint8_t command);

	//! Register the object to pass through to act out action
	void* object_ptr;
};

/**
 * This determines what kind of connection the bluetooth connection is
 */
enum connection_type_t {

	DATA_STREAM_BASED,
	DATA_REQUEST_BASED
};

/**
 * This class is the connection handler for any connection type.
 * In this case we are using this handler to handle the Bluetooth connection
 * to the sensor node.
 *
 * This is the base class for communication handlers. It provides
 * an interface to the other communication handler classes.
 */
class Connection_Handler {

	//! Public Context
	public:

		/**
		 * This is the default connection handler constructor.
		 */
		Connection_Handler(callback_t* table);

		/**
		 * A Connection method to connect to the target device.
		 *
		 * @return success						- if the connection was successful
		 */
		virtual bool connect();

		/**
		 * A Connection method to disconnect from the target device.
		 *
		 * @return success						- if the disconnection was successful
		 */
		virtual bool disconnect();

		/**
		 * A reboot method to reset the connection device.
		 */
		virtual void reboot();

		/**
		 * The generic read method, which reads a connection for a certain length
		 * of data and returns a buffer_t structure.
		 *
		 * @param length						- the buffer length to read
		 * @return buffer_t						- the data container
		 */
		virtual buffer_t* read(byte length);

		/**
		 * This is the generic write method that writes a buffer type structure
		 * to the connection.
		 *
		 * @param buf							- the buffer structure to write
		 */
		virtual void write(buffer_t* buf);

	//! Private Context
	protected:

		//! Connection type
		connection_type_t _con_type;
};

#endif /* CONNECTIONHANDLER_H_ */

/*
 * ConnectionProtocolHandler.h
 *
 *  Created on: 2014-05-16
 *      Author: francispapineau
 */

#ifndef CONNECTIONPROTOCOLHANDLER_H_
#define CONNECTIONPROTOCOLHANDLER_H_

#include "DataProcessor.h"
#include "BluetoothConnectionCommands.h"

#define TIMEOUT				2

/**
 * This class is the callback handler. It is used to service incoming commands from
 * the host device.
 *
 * Basically, this class handles the firing of the appropriate
 * service when a command to scan is acquired.
 */
class ConnectionProtocolHandler {

	//! Public Context
	public:

		/**
		 * This is the default constructor for the class
		 *
		 * @param buffer						- The ring buffer pointer
		 * @param table							- The lookup table
		 * @param serial						- The Hardware serial to read and write
		 */
		ConnectionProtocolHandler(RingBuff_t* buffer, callback_t* table, HardwareSerial* serial);

		/**
		 * This method polls to see if there are some commands received.
		 */
		void poll();

		/**
		 * This method is used to generic system wide actions
		 *
		 * @param object						- The access object
		 * @param command						- The issued command
		 */
		static void generic(void* object, uint8_t command);

		/**
		 * This method is used when the request connection type is used.
		 *
		 * @param object						- The access object
		 * @param command						- The issued command
		 */
		static void request(void* object, uint8_t command);

	//! Private Context
	private:

		//! Internal ring buffer
		RingBuff_t* _buffer;

		//! Internal look up table
		callback_t* _table;

		//! Internal serial pointer
		HardwareSerial* _serial;
};

#endif /* CONNECTIONPROTOCOLHANDLER_H_ */

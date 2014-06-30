/*
 * ConnectionProtocolHandler.h
 *
 *  Created on: 2014-05-16
 *      Author: francispapineau
 */

#ifndef CONNECTIONPROTOCOLHANDLER_H_
#define CONNECTIONPROTOCOLHANDLER_H_

#include "Utilities.h"
#include "ConnectionHandler.h"
#include "NRF8001Driver.h"
#include "BluetoothConnectionHandler.h"
#include "BluetoothConnectionCommands.h"
#include "BluetoothConnectionProtocol.h"

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
		 * @param rf							- The spi interface
		 * @param utils							- The global utilities
		 */
		ConnectionProtocolHandler(Utilities* utils);

		/**
		 * This sets up the callback table.
		 *
		 * @param table							- The callback table
		 */
		void set_callback_table(callback_t* table); 
		
		/**
		 * This is the setup method for the class
		 */
		void begin(NRF8001Driver* rf);
		
		/**
		 * This method polls to see if there are some commands received.
		 */
		void poll();

		/**
		 * This method is used to generic system wide actions
		 *
		 * @param command						- The issued command
		 * @param object						- The access object
		 */
		static void server(uint8_t command, void* object);

	//! Private Context
	private:

		//! Internal look up table
		callback_t* _table;

		//! Internal serial pointer
		NRF8001Driver* _rf;
		
		//! Utilities
		Utilities* _utils;
};

#endif /* CONNECTIONPROTOCOLHANDLER_H_ */


/*
 * BluetoothHandler.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef BLUETOOTHCONNECTIONHANDLER_H_
#define BLUETOOTHCONNECTIONHANDLER_H_

#include <Arduino.h>

#include "Utilities.h"
#include "Watchdog.h"
#include "ProtocolDefinition.h"
#include "ConnectionProtocolHandler.h"

//! The connection timeout
#define TIMEOUT				5 //! 10 seconds

//! Forward decleration of the ConnectionProtocolHandler class
class ConnectionProtocolHandler;

//! -----------------------------------------------------------------------
//! 					SERVER COMMAND PACKET
//! -----------------------------------------------------------------------

/**
 * These are the possible server commands that can be issued.
 */
enum server_command_t {

	REBOOT_SERVER_CMD						= REBOOT,  			//!< REBOOT_CMD
	RESET_SERVER_CMD						= RESET,    		//!< RESET_CMD
	SUSPEND_SERVER_CMD						= SUSPEND,			//!< SUSPEND_CMD
	RESUME_SERVER_CMD						= RESUME,  			//!< RESUME_CMD
	START_SERVER_CMD						= START,    		//!< START_CMD
	STOP_SERVER_CMD							= STOP,      		//!< STOP_CMD
	GET_SERVER_CMD							= GET        		//!< GET_CMD

};


/**
 * This is the main class that arbitrates between the point-to-point Bluetooth
 * module. It is needed to connect, disconnect, request data and receive data from the sensor
 * node.
 *
 * This class extends the connection handler class (@see ConnectionHandler.h),
 * as it manages a connection.
 */
class BluetoothConnectionHandler{

	//! Public Context
	public:

		/**
		 * This is the default connection handler constructor.
		 */
		BluetoothConnectionHandler(connection_type_t type,
										ConnectionProtocolHandler* handler,
										Utilities* utils);
		/**
		 * This is the setup method for the class
		 */
		void begin(NRF8001Driver* rf);
		
		/**
		 *  This is the run method
		 */ 
		void run(void);
		
		/**
		 * This writes a command to the remote host device.
		 *
		 * @param command						- the command
		 */
		void _write_command(uint8_t command);
		
		//! A header structure
		struct sensor_packet_header_t				_header;
		
		//! Union for all packet types
		union {
			struct sensor_packet_heartbeat_t		_heartbeat;
			struct sensor_packet_error_t			_error;
			struct sensor_packet_data_t				_data;
					
		} _packet;
		
	//! Private Context
	protected:

		//! Internal Serial for the bluetooth transceiver
		NRF8001Driver* _rf;

		//! table
		callback_t* _table;
		
		//! Internal buffer
		buffer_t _buf;
		
		//! Connection Type
		connection_type_t _con_type;

		//! Protocol Handler
		ConnectionProtocolHandler* _handler;
		
		//! Utilities
		Utilities* _utils;
		
		//! Private Access to the watchdog
		Watchdog _watch;
		
		//! Internal packet 
		uint8_t _packet_bytes[MAX_DATA_SIZE];
		uint8_t* _packet_data;

		/**
		 * We run the request based method... Using callbacks
		 */
		void _run_request_based();

		/**
		 * We run the stream based method... No callbacks
		 */
		void _run_stream_based();

		/**
		 * This is the main read method to read data packets
		 *
		 */
		void _read_packet();

		/**
		 * Polling loop
		 */
		void _poll();

		/**
		 * Gets the packet in byte form
		 *
		 * @param length 						- the length of the packet
		 * @returns bytes						- the packet byte array
		 */
		uint8_t* _get_packet(uint8_t length);

		/**
		 * This gets the data within the sent packet
		 */
		void _get_data();

		/**
		 * This gets the error within the sent packet
		 */
		void _get_error();

		/**
		 * This gets the heartbeat within the sent packet
		 */
		void _get_heartbeat();
		
		/**
		 * Gets the data from the ring buffer of a specific size
		 *
		 * @param size 							- the length of the packet
		 * @returns bytes						- the packet byte array
		 */
		uint8_t* _get_from_ring_buffer(uint8_t size);

};

#endif /* BLUETOOTHHANDLER_H_ */


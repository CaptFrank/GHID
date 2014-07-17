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
#include "ConnectionProtocolHandler.h"

//! Configs Defines
#define BAUDRATE			115200

//! The connection timeout
#define TIMEOUT				10 //! 10 seconds

//! Connection protocol bytes
#define OK					'@'
#define HEARTBEAT			"@"
#define ERROR				'!'

#define CONNECT				'C'
#define DISCONNECT			'D'
#define REBOOT				'R'

#define HEADER_INDEX		0
#define HEADER_ID			'#'

/**
 * This is the main class that arbitrates between the point-to-point Bluetooth
 * module. It is needed to connect, disconnect, request data and receive data from the sensor
 * node.
 *
 * This class extends the connection handler class (@see ConnectionHandler.h),
 * as it manages a connection.
 */
class Bluetooth_Connection_Handler : public Connection_Handler {

	//! Public Context
	public:

		/**
		 * This is the default connection handler constructor.
		 */
		Bluetooth_Connection_Handler(HardwareSerial* hw_serial, connection_type_t type,
										RingBuff_t* ring, ConnectionProtocolHandler* handler,
										utilities* utils);

		/**
		 * A Connection method to connect to the target device.
		 *
		 * @return success						- if the connection was successful
		 */
		bool connect();

		/**
		 * A Connection method to disconnect from the target device.
		 *
		 * @return success						- if the disconnection was successful
		 */
		bool disconnect();

		/**
		 * A reboot method to reset the connection device.
		 */
		void reboot();

		/**
		 * The generic read method, which reads a connection for a certain length
		 * of data and returns a buffer_t structure.
		 *
		 * @param length						- the buffer length to read
		 * @return buffer_t						- the data container
		 */
		buffer_t* read(byte length);

		/**
		 * This is the generic write method that writes a buffer type structure
		 * to the connection.
		 *
		 * @param buf							- the buffer structure to write
		 */
		void write(buffer_t* buf);
		
		/**
		 *  This is the run method
		 */ 
		void run(void);

	//! Private Context
	private:

		//! Internal Serial for the bluetooth transceiver
		HardwareSerial* _serial;

		//! table
		callback_t* _table;

		//! Buffer
		RingBuff_t* _buff;
		
		//! Internal buffer
		buffer_t _buf;
		
		//! Connection Type
		connection_type_t _type;

		//! Protocol Handler
		ConnectionProtocolHandler* _handler;
		
		//! Utilities
		utilities* _utils;

		/**
		 * This writes a command to the remote host device.
		 *
		 * @param command						- the command
		 */
		bool _write_command(uint8_t command);

		/**
		 * This reads a response from the host device in most cases
		 * it will be a simple '@' character to signal the all ok state,
		 * while a '!' signifies and error state.
		 *
		 * @return success						- the command success
		 */
		bool _read_response();

		/**
		 * We run the request based method... Using callbacks
		 */
		void _run_request_based();

		/**
		 * We run the stream based method... No callbacks
		 */
		void _run_stream_based();

};

#endif /* BLUETOOTHHANDLER_H_ */

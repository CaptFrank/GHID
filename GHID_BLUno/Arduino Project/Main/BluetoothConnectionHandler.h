/*
 * BluetoothHandler.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef BLUETOOTHCONNECTIONHANDLER_H_
#define BLUETOOTHCONNECTIONHANDLER_H_

#include <Arduino.h>
#include "DataProcessor.h"
#include "ConnectionHandler.h"
#include "BluetoothConnectionCommands.h"
#include "ConnectionProtocolHandler.h"

//! Configs Defines
#define BAUDRATE			115200

//! The connection timeout
#define TIMEOUT				10 //! 10 seconds

//! Connection protocol bytes
#define OK					'@'
#define ERROR				'!'

#define CONNECT				'C'
#define DISCONNECT			'D'
#define REBOOT				'R'

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
										RingBuff_t* ring, ConnectionProtocolHandler* handler);

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

		//! The run method pointer
		void (*run)(void);

	//! Private Context
	private:

		//! Internal Serial for the bluetooth transceiver
		HardwareSerial* _serial;

		//! table
		callback_t* _table;

		//! Buffer
		RingBuff_t* _buff;

		//! Protocol Handler
		ConnectionProtocolHandler* _handler;

		/**
		 * This is the virtual deconstructor for the class.
		 */
		~Bluetooth_Connection_Handler();

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
		 * We set the run method.
		 *
		 * @param type							- the connection type
		 */
		void _set_run_method(connection_type_t type);

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

/*
 * BluetoothHandler.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef BLUETOOTHCONNECTIONHANDLER_H_
#define BLUETOOTHCONNECTIONHANDLER_H_

#include <Arduino.h>
#include "ConnectionHandler.h"

/**
 * This is the callback table used fro the bluetooth driver.
 */
struct callback_t callback_table[] = {

		// COMMAND,				METHOD POINTER, 				OBJECT POINTER
		// TODO
};

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
		Bluetooth_Connection_Handler(HardwareSerial* hw_serial);

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

	//! Private Context
	private:

		//! Internal Serial for the bluetooth transceiver
		HardwareSerial* _serial;

		/**
		 * This is the virtual deconstructor for the class.
		 */
		~Bluetooth_Connection_Handler();

};

#endif /* BLUETOOTHHANDLER_H_ */

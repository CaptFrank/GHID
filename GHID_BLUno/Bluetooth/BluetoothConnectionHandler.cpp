/*
 * BluetoothHandler.cpp
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#include "BluetoothConnectionHandler.h"

//! Public Context

/**
 * This is the default connection handler constructor.
 */
Bluetooth_Connection_Handler::Bluetooth_Connection_Handler(HardwareSerial* hw_serial){

}

/**
 * A Connection method to connect to the target device.
 *
 * @return success						- if the connection was successful
 */
bool Bluetooth_Connection_Handler::connect();

/**
 * A Connection method to disconnect from the target device.
 *
 * @return success						- if the disconnection was successful
 */
bool Bluetooth_Connection_Handler::disconnect();

/**
 * A reboot method to reset the connection device.
 */
void Bluetooth_Connection_Handler::reboot();

/**
 * The generic read method, which reads a connection for a certain length
 * of data and returns a buffer_t structure.
 *
 * @param length						- the buffer length to read
 * @return buffer_t						- the data container
 */
buffer_t* Bluetooth_Connection_Handler::read(byte length);

/**
 * This is the generic write method that writes a buffer type structure
 * to the connection.
 *
 * @param buf							- the buffer structure to write
 */
void Bluetooth_Connection_Handler::write(buffer_t* buf);

//! Private Context

/**
 * This is the virtual deconstructor for the class.
 */
Bluetooth_Connection_Handler::~Bluetooth_Connection_Handler();

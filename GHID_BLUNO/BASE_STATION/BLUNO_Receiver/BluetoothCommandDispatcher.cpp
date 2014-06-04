/*
 * BluetoothDispatcher.cpp
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#include "BluetoothCommandDispatcher.h"

/**
 * The default constructor for the class
 */
Bluetooth_Dispatcher::Bluetooth_Dispatcher(HardwareSerial* serial){

	//! We set the internal Serial entry
	this->_serial = serial;
	this->_response = 0x00;

	//! We set the appropriate baud rate
	this->_serial->begin(BLUETOOTH_BAUDRATE);
}

/**
 * This is the virtual setup method for the class
 */
void Bluetooth_Dispatcher::setup_dispatch(uint8_t* command_ptr, uint8_t length){

	//! We create a dispatch
	this->_create_dispatch(command_ptr, length);
}

/**
 * This is the run dispatch method
 *
 * @return success							- If the dispatch was successful
 */
bool Bluetooth_Dispatcher::run_dispatch(){

	//! We send the dispatch and we listen for a response
	this->_send_dispatch(&this->_dispatch);

	//! We check for the ack from the CC2540
	this->_response = this->_receive_dispatch_answer(BLUETOOTH_TIMEOUT);

	//! Check if we got something.
	if(this->_response->response_length > EMPTY){
		return true;
	}
	return false;
}

/**
 * Get access to the response entity.
 */
response_t* Bluetooth_Dispatcher::get_response(){
	return this->_response;
}
		

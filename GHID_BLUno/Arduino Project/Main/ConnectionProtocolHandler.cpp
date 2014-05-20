/*
 * ConnectionProtocolHandler.cpp
 *
 *  Created on: 2014-05-16
 *      Author: francispapineau
 */

#include "ConnectionProtocolHandler.h"

//! Public Context

/**
 * This is the default constructor for the class
 *
 * @param buffer						- The ring buffer pointer
 * @param serial						- The Hardware serial to read and write
 */
ConnectionProtocolHandler::ConnectionProtocolHandler(RingBuff_t* buffer, HardwareSerial* serial){

	//! Set internals
	this->_serial = serial;
	this->_buffer = buffer;
}
/**
 * This sets up the callback table.
 *
 * @param table							- The callback table
 */
void ConnectionProtocolHandler::set_callback_table(callback_t* table){
	
	this->_table = table;
}

/**
 * This method polls to see if there are some commands received.
 */
void ConnectionProtocolHandler::poll(){

	//! We check if we got a command
	if(this->_serial->available()){

		//! We read the command
		uint8_t command = this->_serial->read();

		for(register uint8_t i = 0; COMMAND_NULL != this->_table[i].command_id; i++){

			//! If we find the command within the table
			if(this->_table[i].command_id == command){

				//! We fire the particular function
				this->_table[i].callback(command, this->_table[i].object);
			}
		}
	}
}

/**
 * This method is used to generic system wide actions
 *
 * @param command						- The issued command
 */
void ConnectionProtocolHandler::generic(uint8_t command, void* object){

	//! We switch on the command
	switch(command){

		//! We reset the device
		case REBOOT:
		case RESET:
			reset_device();
			break;

		//! We stop the device
		case STOP:
		case SUSPEND:
			stop_device();
			break;

		//! We start the device
		case RESUME:
		case START:
			start_device();
			break;

		//! Nothing happens
		default:
			break;
	}
}

/**
 * This method is used when the request connection type is used.
 *
 * @param command						- The issued command
 */
void ConnectionProtocolHandler::request(uint8_t command, void* object){

	//! Cast the object
	ConnectionProtocolHandler* access = (ConnectionProtocolHandler*) object;

	//! Container
	buffer_t* buff;

	if(!RingBuffer_IsEmpty(access->_buffer)){

		//! We process the data to be sent
		buff = Data_Processor::process_data(access->_buffer, &access->_buff);
	}else{

		//! We get the last values processed
		buff = Data_Processor::get_last_values(&access->_buff);
	}

	//! We send them
	access->_serial->write(buff->data, buff->length);
}


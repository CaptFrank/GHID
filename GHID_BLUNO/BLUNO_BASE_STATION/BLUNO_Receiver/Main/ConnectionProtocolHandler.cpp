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
 * @param serial						- The Hardware serial to read and write
 * @param utils							- The global utilities
 */
ConnectionProtocolHandler::ConnectionProtocolHandler(HardwareSerial* serial,
													 Utilities* utils){

	//! Set internals
	this->_serial = serial;
	this->_utils = utils;
	this->_table = 0;
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
void ConnectionProtocolHandler::server(uint8_t command, void* object){

	//! Cast the object
	ConnectionProtocolHandler* access = (ConnectionProtocolHandler*) object;
	
	//! We switch on the command
	switch(command){

		//! We reset the device
		case CONNECT_CALLBACK:
			access->_utils->connection_state = CONNECTED_STATE;
			access->_serial->write(OK_CALLBACK);
			break;

		//! We stop the device
		case DISCONNECT_CALLBACK:
			access->_utils->connection_state = DISCONNECTED_STATE;
			access->_serial->write(OK_CALLBACK);
			break;

		//! We start the device
		case REBOOT_CALLBACK:
			access->_utils->connection_state = CLOSED_STATE;
			access->_serial->write(OK_CALLBACK);
			break;

		//! Nothing happens
		default:
			break;
	}
}


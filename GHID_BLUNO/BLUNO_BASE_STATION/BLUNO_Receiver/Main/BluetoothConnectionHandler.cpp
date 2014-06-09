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
BluetoothConnectionHandler::BluetoothConnectionHandler(HardwareSerial* hw_serial,
						connection_type_t type,
						ConnectionProtocolHandler* handler, 
						Utilities* utils){

	//! Set the internal serial port
	this->_serial = hw_serial;
	this->_con_type = type;
	this->_handler = handler;
	this->_utils = utils;

	//! Initialize it
	this->_serial->begin(BAUDRATE);
	this->_serial->flush();
	this->_table = 0;
}

void BluetoothConnectionHandler::begin(){

	//! We wait a couple of seconds to get connected.
	uint8_t timeout = TIMEOUT;

	//! We loop until timeout
	while(timeout --){

		//! We have something in the sreial buffer
		if(this->_serial->available()){

			//! Get this byte
			uint8_t rx_byte = this->_serial->read();

			//! Connected?
			if(rx_byte == CONNECT_CALLBACK){
				this->_utils->connection_state = CONNECTED_STATE;
				this->_utils->start_engine = true;

				//! Then we send the start command
				this->_write_command(START_SERVER_CMD);

				//! Not connected
			}else{
				this->_utils->connection_state = DISCONNECTED_STATE;
				this->_utils->start_engine = false;
			}
		}
		delay(100);
	}
}

/**
 *  This is the run method
 */ 
void BluetoothConnectionHandler::run(void){
	
	//! Poll for a protocol command
	this->_handler->poll();

	//! We set the pointer to the right method.
	switch(this->_con_type){
			
		//! Request based
		case DATA_REQUEST_BASED:
			this->_run_request_based();
			return;

		//! Stream based - Default method
		case DATA_STREAM_BASED:
		default:
			this->_run_stream_based();
			return;
	}
}

//! Private Context

/**
 * This writes a command to the remote host device.
 *
 * @param command						- the command
 */
void BluetoothConnectionHandler::_write_command(uint8_t command){

	//! We send the command.
	this->_serial->write(command);
}

/**
 * We run the request based method... Using callbacks
 */
void BluetoothConnectionHandler::_run_request_based(){

	//! We send a data request and we read it
	this->_write_command(GET_SERVER_CMD);
	this->_poll();
}

/**
 * We run the stream based method... No callbacks
 */
void BluetoothConnectionHandler::_run_stream_based(){

	//! We poll for a data packet
	this->_poll();
}

/**
 * This is the main read method to read data packets
 */
void BluetoothConnectionHandler::_read_packet(){

	//! We get the header type first
	uint8_t length = sizeof(sensor_packet_header_t);
	uint8_t header_packet[length];
	this->_serial->readBytes((char*)header_packet, length);

	//! We map it to our header structure
	memmove((void*)&this->_packet._header, (void*)header_packet, length);

	//! Then we check if its a valid header
	if(this->_packet._header._packet_configs.packet_preamble !=
			SENSOR_PACKET_PREAMBLE){
		return;
	}

	//! We now know this is a valid packet.
	//! We then switch on the packet type.
	switch(this->_packet._header._packet_configs.packet_type){

		//! DATA
		case SENSOR_PACKET_DATA:

			//! We get the data
			this->_get_data();
			break;

		//! ERROR
		case SENSOR_PACKET_ERROR:

			//! We map the error
			this->_get_error();
			break;

		//! HEARTBEAT
		case SENSOR_PACKET_HEARTBEAT:

			//! We get the heartbeat
			this->_get_heartbeat();
			break;

		default:
			break;
	}
}

/**
 * Polling loop
 */
void BluetoothConnectionHandler::_poll(){

	//! A container for the timeout constant
	uint8_t timeout = TIMEOUT;

	//! We check a couple of times
	while(timeout --){

		//! Did we receive a response ?
		if(this->_serial->available() > sizeof(sensor_packet_header_t)){
			this->_read_packet();
		}
		delay(100);
	}
}

/**
 * This gets the data within the sent packet
 */
void BluetoothConnectionHandler::_get_data(){

	//! Get the bytes
	uint8_t* packet = this->_get_packet(sizeof(sensor_packet_data_t));

	//! Move the data to another location
	memmove((&this->_packet._heartbeat + sizeof(sensor_packet_header_t)),
									packet, sizeof(sensor_packet_data_t));

	//! Signal the global context that a data packet is received
	this->_utils->type = DATA_PACKET;
}

/**
 * This gets the error within the sent packet
 */
void BluetoothConnectionHandler::_get_error(){

	//! Get the bytes
	uint8_t* packet = this->_get_packet(sizeof(sensor_packet_error_t));

	//! Move the data to another location
	memmove((&this->_packet._heartbeat + sizeof(sensor_packet_header_t)),
									packet, sizeof(sensor_packet_error_t));

	//! Signal the global context that a data packet is received
	this->_utils->type = ERROR_PACKET;

}

/**
 * This gets the heartbeat within the sent packet
 */
void BluetoothConnectionHandler::_get_heartbeat(){

	//! Get the bytes
	uint8_t* packet = this->_get_packet(sizeof(sensor_packet_heartbeat_t));

	//! Move the data to another location
	memmove((&this->_packet._heartbeat + sizeof(sensor_packet_header_t)),
									packet, sizeof(sensor_packet_heartbeat_t));

	//! Signal the global context that a data packet is received
	this->_utils->type = HEARTBEAT_PACKET;

}

/**
 * Gets teh packet in byte form
 *
 * @param length 						- the length of the packet
 * @returns bytes						- the packet byte array
 */
uint8_t* BluetoothConnectionHandler::_get_packet(uint8_t length){

	//! We map the data to our internal structure
	uint8_t header_size = sizeof(sensor_packet_header_t);
	uint8_t len = length - header_size;

	//! Get the data
	this->_serial->readBytes((char*)this->_packet_bytes, len);
	return this->_packet_bytes;
}

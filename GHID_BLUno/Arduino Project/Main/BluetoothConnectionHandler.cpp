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
Bluetooth_Connection_Handler::Bluetooth_Connection_Handler(HardwareSerial* hw_serial,
						connection_type_t type, RingBuff_t* ring,
						ConnectionProtocolHandler* handler) : Connection_Handler(this->_table){

	//! Set the internal serial port
	this->_serial = hw_serial;
	this->_con_type = type;
	this->run = 0x00;
	this->_buff = ring;
	this->_handler = handler;

	//! Initialize it
	this->_serial->begin(BAUDRATE);
	this->_serial->flush();

	//! We set the run type
	this->_set_run_method(type);
}

/**
 * A Connection method to connect to the target device.
 *
 * @return success						- if the connection was successful
 */
bool Bluetooth_Connection_Handler::connect(){

	//! This sends a connect command to the host device
	return this->_write_command(CONNECT);
}

/**
 * A Connection method to disconnect from the target device.
 *
 * @return success						- if the disconnection was successful
 */
bool Bluetooth_Connection_Handler::disconnect(){

	//! This sends a disconnect command to the host device
	return this->_write_command(DISCONNECT);
}

/**
 * A reboot method to reset the connection device.
 */
void Bluetooth_Connection_Handler::reboot(){

	//! Send reboot command
	this->_write_command(REBOOT);

	//! This reboots the device
	reset_device();
}

/**
 * The generic read method, which reads a connection for a certain length
 * of data and returns a buffer_t structure.
 *
 * @param length						- the buffer length to read
 * @return buffer_t						- the data container
 */
buffer_t* Bluetooth_Connection_Handler::read(byte length){

	//! the bufer container
	buffer_t buff, i = 0;

	buff.length = length;

	//! First we see of the host device is ok
	if(!this->_read_response()) return ERROR;

	//! We read a raw response
	while(TIMEOUT --){
		if(this->_serial->available()){
			buff.data[i] = this->_serial->read();
			i ++;
		}
	}
	return buff;
}

/**
 * This is the generic write method that writes a buffer type structure
 * to the connection.
 *
 * @param buf							- the buffer structure to write
 */
void Bluetooth_Connection_Handler::write(buffer_t* buf){

	//! We write raw data
	this->_serial->write(buf->data, buf->length);
}

//! Private Context

/**
 * This is the virtual deconstructor for the class.
 */
Bluetooth_Connection_Handler::~Bluetooth_Connection_Handler(){}

/**
 * This writes a command to the remote host device.
 *
 * @param command						- the command
 */
bool Bluetooth_Connection_Handler::_write_command(uint8_t command){

	//! We send the command.
	this->_serial->write(command);

	//! We check the host device's response
	return this->_read_response();
}

/**
 * This reads a response from the host device in most cases
 * it will be a simple '@' character to signal the all ok state,
 * while a '!' signifies and error state.
 *
 * @return success						- the command success
 */
bool Bluetooth_Connection_Handler::_read_response(){

	while(TIMEOUT --){
		if(this->_serial->available()){
			uint8_t response = this->_serial->read();

			if(response == OK){
				return true;
			}
		}
	}
	return false;
}

/**
 * We set the run method.
 *
 * @param type							- the connection type
 */
void Bluetooth_Connection_Handler::_set_run_method(connection_type_t type){

	//! We set the pointer to the right method.
	switch(type){
		case DATA_REQUEST_BASED:
			this->run = this->_run_request_based();
			break;

		case DATA_STREAM_BASED:
		default:
			this->run = this->_run_stream_based();
			break;
	}
}

/**
 * We run the request based method... Using callbacks
 */
void Bluetooth_Connection_Handler::_run_request_based(){

	//! All we do is poll the protocol handler
	this->_handler->poll();
}

/**
 * We run the stream based method... No callbacks
 */
void Bluetooth_Connection_Handler::_run_stream_based(){

	//! Container
	buffer_t* buff;

	if(!RingBuffer_IsEmpty(this->_buff)){

		//! We process the data to be sent
		buff = Data_Processor::process_data(this->_buff);
	}else{

		//! We get the last values processed
		buff = Data_Processor::get_last_values();
	}

	//! We send them
	this->write(buff);
}

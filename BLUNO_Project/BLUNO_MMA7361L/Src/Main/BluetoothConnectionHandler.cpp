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
						ConnectionProtocolHandler* handler, 
						utilities* utils){

	//! Set the internal serial port
	this->_serial = hw_serial;
	this->_con_type = type;
	this->_buff = ring;
	this->_handler = handler;
	this->_utils = utils;

	//! Initialize it
	this->_serial->begin(BAUDRATE);
	this->_serial->flush();

	//! We set the run type
	this->_type = type;
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
	this->_utils->reboot();
}

/**
 * The generic read method, which reads a connection for a certain length
 * of data and returns a buffer_t structure.
 *
 * @param length						- the buffer length to read
 * @return buffer_t						- the data container
 */
buffer_t* Bluetooth_Connection_Handler::read(byte length){

	byte i = 0;

	this->_buf.length = length;

	//! First we see of the host device is ok
	if(!this->_read_response()){
		 this->_buf.valid = false;
		 return &this->_buf;
	}

	uint8_t timeout = TIMEOUT;
	//! We read a raw response
	while(timeout --){
		if(this->_serial->available()){
			this->_buf.data[i] = this->_serial->read();
			i ++;
		}
	}
	
	//! We check if we got the ok signal
	if(this->_buf.data[HEADER_INDEX] == HEADER_ID){	
		this->_buf.valid = true;
	}else{
		this->_buf.valid = false;
	}
	return &this->_buf;
}

/**
 * This is the generic write method that writes a buffer type structure
 * to the connection.
 *
 * @param ptr							- the pointer to the structure to send
 * @param length						- the length to send
 */
void Bluetooth_Connection_Handler::write(void* ptr, uint8_t length){

	//! We write raw data
	this->_serial->write((uint8_t*)ptr, length);
}

/**
 *  This is the run method
 */ 
void Bluetooth_Connection_Handler::run(void){
	
	//! We set the pointer to the right method.
	switch(this->_type){
		
		//! We check the watchdog for a heartbeat
		if(this->_watch.check_watchdog()){
			this->_send_heartbeat();
			this->_watch.reset();
			return;
		}
			
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

	uint8_t timeout = TIMEOUT;
	while(timeout --){
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

	//! We send data
	this->_send_data();
}

/**
 * Sends data
 */
void Bluetooth_Connection_Handler::_send_data(){

	//! New values?
	if(!RingBuffer_IsEmpty(this->_buff)){

		//! We process the data to be sent
		Data_Processor::create_data_packet(SENSOR_TYPE, SENSOR_ID, this->_buff, &this->_packet._data);
	}

	//! We send them
	this->write((void*)&this->_packet._data, sizeof(this->_packet._data));
}

/**
 * This sends a hearbeat signal
 */
void Bluetooth_Connection_Handler::_send_heartbeat(){
	
	//! We create a heartbeat packet
	Data_Processor::create_heartbeat(SENSOR_TYPE, SENSOR_ID, &this->_packet._heartbeat);
	
	//! We send the heartbeat
	this->write((void*)&this->_packet._heartbeat, sizeof(this->_packet._heartbeat));
}

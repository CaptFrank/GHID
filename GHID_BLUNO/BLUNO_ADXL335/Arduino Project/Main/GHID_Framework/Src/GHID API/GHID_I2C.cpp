/*
 * GHIDI2C.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_I2C.h"

//! Default constructor - no parameters passed
GHID_I2C::GHID_I2C() {

	//! We set the master address to 0x00
	this->master_address = 0x00;

	//! We start the I2C engine
	Wire.begin();
}

//! Default constructor - master address passed
GHID_I2C::GHID_I2C(byte master_adress){

	//! We set the master address to the input address
	this->master_address = master_adress;

	//! We start the I2C engine
	Wire.begin(this->master_address);
}

//! Read more than 1 byte at a time
buffer_struct_t* GHID_I2C::read_bulk(byte device_address, byte length){

	//! We return the internal class struct pointer;
	return &this->buffer;
}

//! Setter method
void GHID_I2C::setup_receive_handler(void (*function_ptr)(int)){

	//! Set the receiver method
	Wire.onReceive(function_ptr);
}

//! Setter method
void GHID_I2C::setup_request_handler(void (*function_ptr)(void)){

	//! Set the request handler
	Wire.onRequest(function_ptr);
}

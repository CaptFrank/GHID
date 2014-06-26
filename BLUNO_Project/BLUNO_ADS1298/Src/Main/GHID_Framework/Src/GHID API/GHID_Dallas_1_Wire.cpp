/*
 * GHIDDallas1Wire.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_Dallas_1_Wire.h"

buffer_struct_t* GHID_Dallas_1_Wire::read_bulk(byte length){

	//! Read for length times
	for(register byte i = 0; i < length; i++)
		this->buffer[i] = this->read();

	//! returns the pointer to the class internal buffer struct
	return &this->buffer;
}

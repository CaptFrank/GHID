/*
 * GHIDDallas1Wire.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef GHIDDALLAS1WIRE_H_
#define GHIDDALLAS1WIRE_H_

#include "OneWire.h"

//! Max buffer size
#define MAX_BUFFER 		255

//! Buffer structure
struct buffer_struct_t {

	byte length;
	byte buffer[MAX_BUFFER];
};

/**
 * This class is an extended class of the Dallas OneWire class. It
 * provides a more comprehensive methodology for the user to implement
 * this type of device.
 *
 * @see OneWire.h
 */
class GHID_Dallas_1_Wire : public OneWire {

	/**
	 * Frankly there is nothing to be implemented in this
	 * api in which is not touched on in the API added to the includes
	 * folder.
	 */

	//! Public Context
	public:

	//! Publicly accessible buffer struct
	buffer_struct_t buffer;

	/**
	 * This is the read bulk method. We give it a length and, this
	 * method handles the reading of the one wire bus.
	 *
	 * @param length - byte
	 * @return buffer_struct_t - buffer struct
	 */
	buffer_struct_t* read_bulk(byte length);

};

#endif /* GHIDDALLAS1WIRE_H_ */

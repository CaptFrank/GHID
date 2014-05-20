/*
 * GHIDI2C.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef GHIDI2C_H_
#define GHIDI2C_H_

#include <Arduino.h>
#include <Wire.h>

//! Max buffer size
#define MAX_BUFFER 		255

//! Buffer structure
struct buffer_struct_t {

	byte length;
	byte buffer[MAX_BUFFER];
};

/**
 * This class is a wrapper class for the I2C buss class already included
 * in the Arduino framework. This class extends the TwoWire class, and still
 * allows access to those functions.
 *
 * @see Wire.h
 *
 * Note: To start a transmission, the user must use the following
 * sequence of events:
 * 		- Init I2C,
 * 		- Start transmission (address)
 * 		- Send
 * 		- Stop transmission (address)
 */
class GHID_I2C : public TwoWire {

	/**
	 * All methods which allows any type of I2C communication
	 * are held inside the TwoWire class.
	 *
	 * @see Wire.h
	 */

	//! Public Context
	public:

	//! Internal class buffer structure
	buffer_struct_t buffer;

	//! The master device address
	byte master_address;

	/**
	 * This is the default constructor for the class.
	 * It sets the address of the master node to the given
	 * parameter.
	 *
	 * @param master_address
	 */
	GHID_I2C(byte master_address);

	/**
	 * This is the default constructor for the class.
	 * It sets the address of the master node to 0x00
	 */
	GHID_I2C();

	/**
	 * This is a wrapper method around the requestFrom method in the
	 * TwoWire class.
	 *
	 * @see requestFrom
	 *
	 * @param device_address - byte device address
	 * @param length - number of bytes to receive
	 * @return buffer_struct_t - buffer containing the response
	 */
	buffer_struct_t* read_bulk(byte device_address, byte length);

	/**
	 * This method sets the function pointer for the interrupt handler,
	 * when the I2C bus receives data.
	 *
	 * @param function_ptr - the receive handler
	 */
	void setup_receive_handler(void (*function_ptr)(int));


	/**
	 * This method sets the function pointer for the interrupt handler,
	 * when the I2C bus requests data from a slave.
	 *
	 * @param function_ptr - the requester handler
	 */
	void setup_request_handler(void (*function_ptr)(void));

};

#endif /* GHIDI2C_H_ */

/*
 * DataProcessor.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_

#include <Arduino.h>
#include "ADS1298Driver.h"

/**
 * This is the buffer type definition.
 */
typedef struct buffer_t {

	//! The length of the buffer.
	byte length;

	//! The data in the buffer.
	byte data[DATA_PACKET_SIZE - 1];
};

/**
 * This class is the data processor for the Bluetooth connection. It is a basic
 * static class which, takes in a buffer of data and strips the unnecessary bytes
 * from it, as well as check if the data is valid or not.
 */
class Data_Processor {

	//! Public Context
	public:

		/**
		 * This is the data processors only public method. It processes the data
		 * passed to this method and returns an axis buffer type structure.
		 *
		 * @param buf								- the buffer type structure
		 * @return axis_t							- the axis type structure returned
		 */
		static buffer_t* process_data(RingBuff_t* buf);

		/**
		 * We simply return the last valid values.
		 *
		 * @return buf								- the last valid buffer values
		 */
		static buffer_t* get_last_values();


	//! Private Context
	private:

		//! The internal access buffer type pointer
		buffer_t _buffer;
};

#endif /* DATAPROCESSOR_H_ */

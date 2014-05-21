/*
 * DataProcessor.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_

#include <Arduino.h>
#include "RingBuffer.h"

#define MAX_SIZE		3*(sizeof(int))

/**
 * This is the buffer type definition.
 */
typedef struct buffer_t {

	//! The length of the buffer.
	byte length;

	//! The data in the buffer.
	byte data[MAX_SIZE + 1];
	
	//! Valid?
	bool valid;
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
		 * @param buffer							- the buffer object
		 * @return axis_t							- the axis type structure returned
		 */
		static buffer_t* process_data(RingBuff_t* buf, buffer_t* buffer);

		/**
		 * We simply return the last valid values.
		 *
		 * @param buffer							- the buffer object
		 * @return buf								- the last valid buffer values
		 */
		static buffer_t* get_last_values(buffer_t* buffer){
			return buffer;
		}
};

#endif /* DATAPROCESSOR_H_ */

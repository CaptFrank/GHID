/*
 * DataProcessor.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_

#include <Arduino.h>

/**
 * This is the buffer type definition.
 */
typedef struct buffer_t {

	//! The length of the buffer.
	byte length;

	//! The data in the buffer.
	byte* data;
};

/**
 * This is the axis data type definition.
 */
typedef struct axis_t {

	//! The axis data
	byte x_axis;
	byte y_axis;
	byte z_Axis;

	//! The buttons data
	byte buttons;
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
		static axis_t* process_data(buffer_t* buf);

	//! Private Context
	private:

		//! The internal access buffer type pointer
		buffer_t* _buffer;

		//! The internal access axis type pointer.
		axis_t _axis;

		/**
		 * This method checks the received packet based on the length and size of the packet.
		 *
		 * @return success							- the check success
		 */
		static bool _check_packet();

		/**
		 * This method maps the data within the context of the class to an axis type structure,
		 * providing that the packe is in fact valid.
		 */
		static void _map_data();
};

#endif /* DATAPROCESSOR_H_ */

/*
 * DataProcessor.cpp
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#include "DataProcessor.h"

//! Public Context

/**
 * This is the data processors only public method. It processes the data
 * passed to this method and returns an axis buffer type structure.
 *
 * @param buf								- the buffer type structure
 * @return buffer_t							- the axis type structure returned
 */
buffer_t* Data_Processor::process_data(RingBuff_t* buf){

	//! First we memset the buffer to reset it
	memset(Data_Processor::_buffer.data, 0x00, sizeof(Data_Processor::_buffer.data));

	//! We get the count
	RingBuff_Count_t buff_count = RingBuffer_GetCount(buf);

	//! Then we remove an object from the ring buffer.
	if(buff_count >= sizeof(Data_Processor::_buffer.data)){
		for(register uint8_t i = 0; i < sizeof(Data_Processor::_buffer.data); i++){

			((uint8_t*)&Data_Processor::_buffer.data)[i] = RingBuffer_Remove(buf);
		}

		//! We remove the spacer
		RingBuffer_Remove(buf);
	}
	return Data_Processor::_buffer;
}

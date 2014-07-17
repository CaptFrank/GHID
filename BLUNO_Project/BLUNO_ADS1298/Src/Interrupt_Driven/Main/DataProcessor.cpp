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
buffer_t* Data_Processor::process_data(RingBuff_t* buf, buffer_t* _buff){

	//! First we memset the buffer to reset it
	memset(_buff->data, 0x00, DATA_PACKET_SIZE);

	//! We get the count
	RingBuff_Count_t buff_count = RingBuffer_GetCount(buf);
	
	//! Then we remove an object from the ring buffer.
	if(buff_count >= DATA_PACKET_SIZE){
		
		for(register uint8_t i = 0; i < sizeof(_buff->data); i++){
			((uint8_t*)&_buff->data)[i] = RingBuffer_Remove(buf);
			_buff->length ++;
		}

		//! We remove the spacer
		RingBuffer_Remove(buf);
	}
	return _buff;
}

/*
 * Dispatcher.cpp
 *
 *  Created on: 2014-05-14
 *      Author: francispapineau
 */

/**
 * This method creates a dispatch item.
 *
 * @param command_ptr							- The command pointer
 * @param length								- The command length
 */
void Dispatcher::_create_dispatch(uint8_t* command_ptr, uint8_t length){

	//! We create a dispatch item
	this->_dispatch.command_pointer = command_ptr;
	this->_dispatch.command_length = length;
}

/**
 * This method sends a dispatch item.
 *
 * @param dispatch								- The dispatch item
 */
void Dispatcher::_send_dispatch(dispatch_t* dispatch){

	//! We write the dispatch
	this->_serial->write(this->_dispatch.command_pointer, this->_dispatch.command_length);
}

/**
 * This method reads a response
 * @param timeout 								- The connection timeout (ms)
 * @return response_t							- The response from the device
 */
response_t Dispatcher::_receive_dispatch_answer(uint8_t timeout){

	//! Index
	uint8_t index = 0;
	while(timeout --){
		//! We loop to get info in the buffers
		while(this->_serial->available()){
			this->_response.response[index] = this->_serial->read();
			this->_response.response_length ++;
			index ++;
		}
		delay(100);
	}

	return this->_response;
}





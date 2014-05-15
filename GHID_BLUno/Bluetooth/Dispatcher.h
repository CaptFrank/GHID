/*
 * Dispatcher.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#define MAX_RESPONSE_SIZE				20

/**
 * The command dispatch structure type definition
 */
typedef struct dispatch_t{

	uint8_t command_length;
	uint8_t* command_pointer;
};

/**
 * This is the response type structure
 */
typedef struct response_t {

	uint8_t response[MAX_RESPONSE_SIZE];
	uint8_t response_length;
};

/**
 * This the interface class for a command / process dispatcher.
 *
 */
class Dispatcher {

	//! Public Context
	public:

		/**
		 * The default constructor for the class
		 */
		virtual Dispatcher(HardwareSerial* serial);

		/**
		 * This is the virtual setup method for the class
		 */
		virtual void setup_dispatch(uint8_t* command_ptr, uint8_t length);

		/**
		 * This is the run dispatch method
		 */
		virtual bool run_dispatch();

	//! Private Context
	private:

		//! Internal access to the Serial stream
		HardwareSerial* _serial;

		//! The command buffer
		dispatch_t _dispatch;

		//! The response buffer
		response_t _response;

		/**
		 * This is the virtual destructor for the class.
		 */
		virtual ~Dispatcher();

		/**
		 * This method creates a dispatch item.
		 *
		 * @param command_ptr							- The command pointer
		 * @param length								- The command length
		 */
		void _create_dispatch(uint8_t* command_ptr, uint8_t length);

		/**
		 * This method sends a dispatch item.
		 *
		 * @param dispatch								- The dispatch item
		 */
		void _send_dispatch(dispatch_t* dispatch);

		/**
		 * This method reads a response
		 *
		 * @param timeout 								- The connection timeout (ms)
		 * @return response_t							- The response from the device
		 */
		response_t _receive_dispatch_answer(uint8_t timeout);
};

#endif /* DISPATCHER_H_ */

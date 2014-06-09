/*
 * BluetoothDispatcher.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef BLUETOOTHDISPATCHER_H_
#define BLUETOOTHDISPATCHER_H_

#include "Dispatcher.h"

//! Generic defines
#define BLUETOOTH_BAUDRATE					9600
#define BLUETOOTH_TIMEOUT					50 //! 5 sec
#define EMPTY								0

/**
 * This is the class which handles the command dispatches to the Bluetooth
 * module.  It is important that this handler class is only for command dispatch
 * to the bluetooth module and not for data.
 */
class BluetoothDispatcher : public Dispatcher{

	//! Public Context
	public:

		/**
		 * The default constructor for the class
		 */
		BluetoothDispatcher(HardwareSerial* serial);

		/**
		 * This is the virtual setup method for the class
		 */
		void setup_dispatch(uint8_t* command_ptr, uint8_t length);

		/**
		 * This is the run dispatch method
		 *
		 * @return success							- If the dispatch was successful
		 */
		bool run_dispatch();
		
		/**
		 * Get access to the response entity.
		 */
		response_t* get_response();
		
	//! Private Context
	protected:

		//! The internal access to the serial
		HardwareSerial* _serial;

		//! The response pointer
		response_t* _response;
};

#endif /* BLUETOOTHDISPATCHER_H_ */

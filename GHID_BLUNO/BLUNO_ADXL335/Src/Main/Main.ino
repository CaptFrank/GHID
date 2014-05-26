/*
 * Main.cpp
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

//! --------------------------------------------------
//! Includes
//! --------------------------------------------------

#include <Arduino.h>

//! Drivers
#include "CC2540Driver.h"
#include "ADXL335Driver.h"

//! Handlers
#include "BluetoothCommandDispatcher.h"
#include "BluetoothConnectionHandler.h"
#include "ConnectionProtocolHandler.h"

//! Commands
#include "BluetoothCommandTable.h"
#include "BluetoothCommandIndexes.h"

//! --------------------------------------------------
//! Defines
//! --------------------------------------------------

//! ADXL335 Defines
//! Digital
#define ADXL335_ST_PIN					3

//! Analog
#define ADXL335_X_AXIS					0
#define ADXL335_Y_AXIS					1
#define ADXL335_Z_AXIS					2

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! Global utilities
utilities global_utilities;

//! The global ring buffer type
RingBuff_t buffer;

//! The pin maps for both the ADXL335 and the MMA7361L
ADXL335_pin_map_t adxl335_pin_map = {
									ADXL335_ST_PIN,
									ADXL335_X_AXIS,
									ADXL335_Y_AXIS,
									ADXL335_Z_AXIS
									};

//! A protocol handler
ConnectionProtocolHandler protocol_handler(&buffer, &Serial, &global_utilities);

//! The Bluetooth Command dispatcher
Bluetooth_Dispatcher dispatcher(&Serial);

//! The Accelerometer Driver
//! The ADXL335
ADXL335_Driver adxl335_driver(&adxl335_pin_map, 5.0);

//! The CC2540 Driver
//! 	- Here we use the default setup function.... We could change it
CC2540_Driver cc2540_driver((char*)"ACCELEROMETER", (char*)command_pointers, &dispatcher);

//! The connection
Bluetooth_Connection_Handler connection(&Serial, DATA_REQUEST_BASED, &buffer,
										&protocol_handler, &global_utilities);

/**
 * This is the callback table used for the bluetooth driver.
 */
struct callback_t callback_table[] = {

		// COMMAND,				METHOD POINTER, 							OBJECT POINTER

		//! Generic commands
		REBOOT,					ConnectionProtocolHandler::generic,			(void*)&protocol_handler,
		RESET,					ConnectionProtocolHandler::generic,			(void*)&protocol_handler,
		SUSPEND,				ConnectionProtocolHandler::generic,			(void*)&protocol_handler,
		RESUME,					ConnectionProtocolHandler::generic,			(void*)&protocol_handler,
		START,					ConnectionProtocolHandler::generic,			(void*)&protocol_handler,

		//! We using the request based method
		GET,					ConnectionProtocolHandler::request,			(void*)&connection
};

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//=========================================
	// INSERT SETUP CODE HERE
	//=========================================

	//! We init the buffer
	RingBuffer_InitBuffer(&buffer);

	//! We set the analog reference (5V)
	analogReference(DEFAULT);

	//! We setup the analog sensor
	adxl335_driver.begin();

	//! SETUP BLUETOOTH
	//! Set the callback table within the connection protocol handler
	protocol_handler.set_callback_table(callback_table);
	
	//! We connect to the host device
	connection.connect();
	
	//! We set the global lock to true
	global_utilities.start_engine = true;
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(void){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//! We trigger the ADC thread
	//! This puts the adc values in the Ringbuffer
	adxl335_driver.run(&buffer);
	
	//! We we are good to go
	if(global_utilities.start_engine){
		
		//! Get the values within the ring buffer
		//! and send them via the Bluetooth interface
		connection.run(); //! We run the engine
	}
	
	delay(100);
}

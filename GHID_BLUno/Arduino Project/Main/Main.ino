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
#include "ADS1298Driver.h"
#include "CC2540Driver.h"

//! Handlers
#include "BluetoothCommandDispatcher.h"
#include "BluetoothConnectionHandler.h"
#include "ConnectionProtocolHandler.h"

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! The start flag
bool start = false;

//! The global ring buffer type
RingBuff_t buffer;

//! A protocol handler
ConnectionProtocolHandler protocol_handler;

/**
 * This is the callback table used for the bluetooth driver.
 */
struct callback_t callback_table[] = {

		// COMMAND,				METHOD POINTER, 						OBJECT POINTER

		//! Generic commands
		REBOOT,					ConnectionProtocolHandler::generic,		(void*)&protocol_handler,
		RESET,					ConnectionProtocolHandler::generic,		(void*)&protocol_handler,
		SUSPEND,				ConnectionProtocolHandler::generic,		(void*)&protocol_handler,
		RESUME,					ConnectionProtocolHandler::generic,		(void*)&protocol_handler,
		START,					ConnectionProtocolHandler::generic,		(void*)&protocol_handler,

		//! We using the request based method
		GET,					ConnectionProtocolHandler::request,		(void*)&protocol_handler,
};

//! The Bluetooth Command dispatcher
Bluetooth_Dispatcher dispatcher(&Serial);

//! The ADS1298 Driver object
//! 	- Here we use the default setup function.... We could change it
ADS1298_Driver ads1298_driver(&buffer);

//! The CC2540 Driver
//! 	- Here we use the default setup function.... We could change it
CC2540_Driver cc2540_driver("ADS1298", &dispatcher);

//! The conenction
Bluetooth_Connection_Handler connection(&Serial, DATA_REQUEST_BASED, callback_table, buffer, &protocol_handler);

//! --------------------------------------------------
//! Prototypes
//! --------------------------------------------------

//! Default functions
void setup(void);
void loop(void);

//! Start / Stop functions
void start_device(void);
void stop_device(void);

//! Reset function
void (*reset_device)(void) = 0;

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

	//! SETUP ADS1298
	//! We setup the ADS1298 with the default settings
	ads1298_driver.setup_ads1298();

	//! We trigger the ISR on the LOW change of the ADS1298 DRDY pin
	attachInterrupt(PIN_DRDY, ads1298_driver.execute_isr, LOW);

	//! SETUP BLUETOOTH
	//! We setup the CC2540 device
	if(cc2540_driver.setup_device()){
		//! We connect to the host device
		connection.connect();
	}else{
		while(1);
	}
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================

	//! We run
	connection.run();

}

/**
 * This function simply acts as a boolean flag toggle. We use
 * it to start the device data acquisition.
 */
void start_device(void){
	start = true;
}

/**
 * This function simply acts as a boolean flag toggle. We use
 * it to stop the device data acquisition.
 */
void stop_device(void){
	start = false;
}

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
#include "MMA7361LDriver.h"

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

//! MMA7361L Defines
//! Digital
#define MMA7361L_SLEEP_PIN				3
#define MMA7361L_ST_PIN					4
#define MMA7361L_0_G_PIN				5
#define MMA7361L_G_SELECT_PIN			6

//! Analog
#define MMA7361L_X_AXIS					0
#define MMA7361L_Y_AXIS					1
#define MMA7361L_Z_AXIS					2

//! --------------------------------------------------
//! Prototypes
//! --------------------------------------------------

//! Interrupt function
void execute_isr(void);

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! Global utilities
utilities global_utilities;

//! The global ring buffer type
RingBuff_t buffer;

//! The pin maps for both the ADXL335 and the MMA7361L
MMA7361L_pin_map_t	mma7361l_pins	= {MMA7361L_SLEEP_PIN,
									   MMA7361L_ST_PIN,
									   MMA7361L_0_G_PIN,
									   MMA7361L_G_SELECT_PIN,
									   MMA7361L_X_AXIS,
									   MMA7361L_Y_AXIS,
									   MMA7361L_Z_AXIS};

//! A protocol handler
ConnectionProtocolHandler protocol_handler(&buffer, &Serial, &global_utilities);

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
		GET,					ConnectionProtocolHandler::request,			(void*)&protocol_handler
};

//! The Bluetooth Command dispatcher
Bluetooth_Dispatcher dispatcher(&Serial);

//! The Accelerometer Driver
//! The MMA7361L
MMA7361L_Driver mma7361l_driver(&mma7361l_pins, 5.0);

//! The CC2540 Driver
//! 	- Here we use the default setup function.... We could change it
CC2540_Driver cc2540_driver((char*)"ACCELEROMETER", (char*)command_pointers, &dispatcher);

//! The connection
Bluetooth_Connection_Handler connection(&Serial, DATA_REQUEST_BASED, &buffer, 
										&protocol_handler, &global_utilities);

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

	//! We set the analog reference (5V)
	analogReference(DEFAULT);

	//! We setup the analog sensor
	Serial.begin(115200);
	Serial.println("MMA73611 Driver INIT");
	mma7361l_driver.begin();
	mma7361l_driver.calibrate();

	//! SETUP BLUETOOTH
	//! Set the callback table within the connection protocol handler
	protocol_handler.set_callback_table(callback_table);
	Serial.println("Callbacks set");
	
	//! We connect to the host device
	Serial.println("Connecting");
	connection.connect();
	
	//! We set the global lock to true
	global_utilities.start_engine = true;
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//! We trigger the ADC thread
	//! This puts the adc values in the Ringbuffer
	mma7361l_driver.run(&buffer);
	
	//! We we are good to go
	if(global_utilities.start_engine){
		
		//! Get the values within the ring buffer
		//! and send them via the Bluetooth interface
		connection.run(); //! We run the engine
	}
}
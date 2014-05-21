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

//! Commands
#include "BluetoothCommandTable.h"
#include "BluetoothCommandIndexes.h"

//! --------------------------------------------------
//! Prototypes
//! --------------------------------------------------

//! Default functions
void setup(void);
void loop(void);

//! Interrupt function
void execute_isr(void);

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! Global utilities
utilities global_utilities;

//! The global ring buffer type
RingBuff_t buffer;

/**
 * We create a device map
 */
uint8_t devices[NUMBER_OF_SPI_DEVICES] = {ADS1298_DEVICE};

/**
 * SPI Settings definition structure
 */
spi_settings_t spi_settings = {
						FALSE,					//! Not in slave mode
						NONE,					//! No service method
			
						SPI_MODE1,				//! set to SPI mode 1
						MSBFIRST,				//! msb first
						SPI_CLOCK_DIV16,		//! devide speed by 6 (16M/6)
						NUMBER_OF_SPI_DEVICES,	//! Only one device on
						devices				//! Address of the device
						};

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

//! The ADS1298 Driver object
//! 	- Here we use the default setup function.... We could change it
ADS1298_Driver ads1298_driver(&buffer, devices, &spi_settings);

//! The CC2540 Driver
//! 	- Here we use the default setup function.... We could change it
CC2540_Driver cc2540_driver((char*)"ADS1298", (char*)command_pointers, &dispatcher);

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

	//! SETUP ADS1298
	//! We trigger the ISR on the LOW change of the ADS1298 DRDY pin
	attachInterrupt(PIN_DRDY, execute_isr, LOW);

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
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//1 We we are good to go
	if(global_utilities.start_engine){
		connection.run(); //! We run the engine
	}
}

/**
 * This is the static method that adds one spi data component
 * to a generic ring buffer for read later on.
 */
void execute_isr(void){

	/**
	 * This ISR is triggered only when the DRDY signal on the ADS1298 chip
	 * is asserted, indicating that there is new data stored on the ADS1298
	 * registers. In which case, this ISR is activated to acquire this data
	 * and store it within a global context RingBuffer.
	 */

	//! Here we add data to the buffer.
	//! We create a buffer object to contain our data.
	//! Format of the packet:
	//! 	- 24 bit header + 24 bit * active channels [3 bytes + 3 * # bytes]

	//! We add the spacer at the end of the data array
	ads1298_driver._rx_buff.data.packet._data[sizeof(ads1298_driver._rx_buff.data.packet._data)] = SPACER;

	//! We get the data and store it within the buffer
	GHID_SPI::transfer_bulk(ADS1298_DEVICE,
			ads1298_driver._rx_buff.data.packet_array,
			DATA_PACKET_SIZE);

	uint8_t size = DATA_PACKET_SIZE;
	while(size --)
		//! Then we input the data into the ring buffer
		RingBuffer_Insert(ads1298_driver._buff, ads1298_driver._rx_buff.data.packet._data[size]);
}
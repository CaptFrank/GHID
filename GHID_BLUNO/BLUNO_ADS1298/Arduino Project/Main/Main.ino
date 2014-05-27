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

#define ISR_NUMBER			PIN_DRDY - 2

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

/**
 * SPI Settings definition structure
 */
spi_settings_t spi_settings = {
						SPI_MODE1,				//! set to SPI mode 1
						MSBFIRST,				//! msb first
						SPI_CLOCK_DIV16,		//! devide speed by 6 (16M/6)
						ADS1298_DEVICE			//! Address of the device
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
ADS1298_Driver ads1298_driver(&buffer, &spi_settings);

//! The CC2540 Driver
//! 	- Here we use the default setup function.... We could change it
//CC2540_Driver cc2540_driver((char*)"ADS1298", (char*)command_pointers, &dispatcher);

//! The connection
//Bluetooth_Connection_Handler connection(&Serial, DATA_REQUEST_BASED, &buffer, 
//										&protocol_handler, &global_utilities);

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
	
	//! Init the ring buffer
	RingBuffer_InitBuffer(&buffer);
	
	Serial.begin(115200);

	//! SETUP ADS1298
	//! We setup the ADS1298 device.
	ads1298_driver.begin();
	
	//! We trigger the ISR on the LOW change of the ADS1298 DRDY pin
	//attachInterrupt(ISR_NUMBER, execute_isr, FALLING);

	//! SETUP BLUETOOTH
	//! Set the callback table within the connection protocol handler
	//protocol_handler.set_callback_table(callback_table);
	
	//! We connect to the host device
	//connection.connect();
	
	//! We set the global lock to true
	//global_utilities.start_engine = true;
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//! We we are good to go
	if(global_utilities.start_engine){
		//connection.run(); //! We run the engine
	}
}

/**
 * This is the ISR that adds one spi data component
 * to a generic ring buffer for read later on.
 */ 
void execute_isr(void){
	
	Serial.println("Interrupt!!");

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

	//! Start conversions
	ADS1298_Driver::_unset_cs_pin();

	//! We issue the read command
	ads1298_driver.send_command(RDATA);

	//! We get the data and store it within the buffer
	for(register uint8_t i = 0; i < DATA_PACKET_SIZE; i++){
		ads1298_driver._rx_buff.data.packet_array[i] = SPI.transfer(EMPTY);
	}
	
	uint8_t size = DATA_PACKET_SIZE;
	while(size --)
		//! Then we input the data into the ring buffer
		RingBuffer_Insert(ads1298_driver._buff, ads1298_driver._rx_buff.data.packet._data[size]);
	
	//! Stop conversions
	ADS1298_Driver::_set_cs_pin();
}
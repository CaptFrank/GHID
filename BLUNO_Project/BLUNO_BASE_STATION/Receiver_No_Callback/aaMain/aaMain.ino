
//! --------------------------------------------------
//! Includes
//! --------------------------------------------------

#include <Arduino.h>
#include <avr/wdt.h>

//! Drivers
#include "NRF8001Services.h"
#include "NRF8001UARTOverBLE.h"
#include "USBDeviceImplementation.h"
#include "HardwareDefines.h"
#include "NRF8001Driver.h"

//! Handlers
#include "BluetoothConnectionHandler.h"
#include "ConnectionProtocolHandler.h"

//! Utilties
#include "Utilities.h"
#include "SystemMonitor.h"

//! Vectored
#include <lib_aci.h>
#include <SPI.h>

//! --------------------------------------------------
//! Defines
//! --------------------------------------------------

//! Global ring buffer size
#define BUFFER_SIZE			100

//! Debug Toggle
#define DEBUG

//! Do we want a callback capability?
//#define CONNECTION_PROTOCOL

#ifdef JOYSTICK_REPORT

//! Define a global report
joystick_report_t report;
#endif

#ifdef MOUSE_REPORT

//! Define a global report
mouse_report_t report;
#endif

/** 
 * Store the setup for the nRF8001 in the flash of the AVR to save on RAM 
 */
hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! BTLE setup
aci_state_t btle_state;
		
//! Global utilities
Utilities global_utilities;

//! Watchdog
Watchdog watch;

//! The USB Handler
USBDevice usb_interface(&report);

//! The bluetooth driver
NRF8001Driver* btle;

//! A protocol handler
#ifdef CONNECTION_PROTOCOL
	ConnectionProtocolHandler protocol_handler(&global_utilities);
#endif

//! The connection
BluetoothConnectionHandler connection(DATA_REQUEST_BASED,
										&protocol_handler, &global_utilities);

//! The System monitor
SystemMonitor system(&report, &global_utilities, &connection, &watch);

/**
 * This is the callback table used for the bluetooth driver.
 */
struct callback_t callback_table[] = {

		// COMMAND,						METHOD POINTER, 								OBJECT POINTER

		//! Generic commands
		CONNECT_CALLBACK,				ConnectionProtocolHandler::server,				&protocol_handler,
		DISCONNECT_CALLBACK,			ConnectionProtocolHandler::server,				&protocol_handler,
		REBOOT_CALLBACK,				ConnectionProtocolHandler::server,				&protocol_handler
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

	// ----------------------------------------------------------------
	// Context setup

	//! Init global buffer here
	global_utilities.ring_buffer.init(BUFFER_SIZE);
	
	//! Clear the content of the ring buffer
	global_utilities.ring_buffer.clear();

	// ----------------------------------------------------------------
	// Bluetooth setup
	
	// Pins
	btle_state.aci_pins.board_name						= BOARD_DEFAULT;
	btle_state.aci_pins.reqn_pin						= 9;
	btle_state.aci_pins.rdyn_pin						= 8;
	btle_state.aci_pins.mosi_pin						= MOSI;
	btle_state.aci_pins.mosi_pin						= MISO;
	btle_state.aci_pins.sck_pin							= SCK;
			
	// Clock setup
	btle_state.aci_pins.spi_clock_divider				= SPI_CLOCK_DIV8;
			
	// Unused pins
	btle_state.aci_pins.reset_pin						= UNUSED;
	btle_state.aci_pins.active_pin						= UNUSED;
	btle_state.aci_pins.optional_chip_sel_pin			= UNUSED;
			
	// Interrupt setup
	btle_state.aci_pins.interface_is_interrupt			= false;
	btle_state.aci_pins.interrupt_number				= 1;
		
	// Setup info
	btle_state.aci_setup_info.number_of_pipes			= NUMBER_OF_PIPES;
	btle_state.aci_setup_info.setup_msgs				= setup_msgs;
	btle_state.aci_setup_info.num_setup_msgs			= NB_SETUP_MESSAGES;
	
	// Create a BTLE object
  	
	#ifdef DEBUG
		Serial.begin(115200);
	#endif

 	btle = new NRF8001Driver(&btle_state, &global_utilities);
 	btle->setup();
	
	// ----------------------------------------------------------------
	// Server setup
	
	//! Set the callback table within the connection protocol handler
	
	#ifdef CONNECTION_PROTOCOL
		protocol_handler.begin(btle);
		protocol_handler.set_callback_table(callback_table);
	#endif

	//! Setup the connection
	connection.begin(btle);
	
	// ----------------------------------------------------------------
	// Engine setup

	//! We perform a mem check to see if we are in the clear
	if(global_utilities.memory_check() == EMPTY){
		global_utilities.reboot();
	}
	
	//! Reset watchdog
	wdt_reset();
	wdt_disable();
	
	//! Setup the USB
	if(!usb_interface.begin()) global_utilities.reboot();
	
	#ifdef DEBUG
		global_utilities.start_engine = true;
	#endif
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(void){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
  	//! Run the BTLE Stack
	btle->run();

	//! We we are good to go
	if(global_utilities.start_engine){

		//! Run the BTLE Stack
		btle->run();
		
		// char* temp = "DEFAULT";
		// btle->write((uint8_t*)temp, sizeof(temp));
		
		//! Run the bluetooth thread
		connection.run(); //! We run the engine
		
		//==========================================
		// INSERT EXTRA LOGIC THREADS HERE
		//==========================================
		//
		//
		//	Insert any other logic code that could
		//	be doing any computations or logic with
		//	the data here. The data acquired is located
		//	within the ring buffer initialized above. 
		//
		//	*** NOTE: Make sure to look at what the data
		//		is doing before getting it from this buffer.
		//
		//==========================================
		// INSERT EXTRA LOGIC THREADS HERE
		//==========================================
		

		//! Run the system monitor
		system.run();
		
		#ifdef DEBUG
//			Serial.print("Data received:");
//			for(uint8_t i = 0; i < sizeof(global_utilities.report); i ++){
//				Serial.print(((uint8_t*)(&global_utilities.report))[i]);
//			}
//			Serial.println();
		#endif

		//! We run the USB engine
		//usb_interface.run_usb();
	}

	delay(500);
}



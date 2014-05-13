// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

//add your includes for the project Arduino_HID_Joystick here


//add your function definitions for the project Arduino_HID_Joystick here

//File System

#ifndef ARDUINO_HID_JOYSTICK_H_
#define ARDUINO_HID_JOYSTICK_H_

#include <HardwareSerial.h>

#include "EEPROM.h"
#include "NVRAM_API.h"
#include "Main_Defines.h"
#include "Hardware_Defines.h"
#include "Packet_Watchdog.h"
#include "Command_Interpreter.h"

#include "Packet_Handler.h"
#include "Packet_Parser.h"

#include "USB_Device_Implementation.h"

#include "Emulation_Device_Implementation.h"
#include "Network_Protocol.h"

#include "Scheduler.h"
#include "RFBee_Stack.h"
#include "User_Configs.h"

/**
 * This file contains all of the device DEFINE macros, and
 * also includes all of the libraries that are needed to
 * be references. All of the structures and classes are also
 * built by default in this header file.
 **/

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~ OBJECT DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//! Define a global error flag...
	//! If this is asserted, we then proceed to the error method.
	//! Only the interrupt can change this to true.
	static boolean global_context_error_flag = false;

	//! Define an EEPROM object.
	EEPROMClass eeprom;

	//! Define an WATCHDOG object
	WATCHDOG watchdog;

	//! Define an NVRAM object
	NVRAM nvram;
	
	// Defining a Sensro DB
	SENSOR sensor_db[MAX_SENSORS]; //Sensor

	//! Define an PACKET_PARSER object
	PACKET_PARSER packet_parser(sensor_db);

	//! Define a packet decoder function table.
	struct packet_handler_t packet_handlers[] = {

			//{/*PACKET ID*/, /*TARGET FUNCTION*/, /*OBJECT ADDRESS*/},

			//! Any packet will trigger this event.
			{PACKET_ANY,       			WATCHDOG::reset,        		&watchdog},

			//! Packet specific function tables for rx.
			{SENSOR_ACK,	   			PACKET_PARSER::parse, 			&packet_parser},
			{SENSOR_HEARTBEAT_REPORT, 	PACKET_PARSER::parse, 			&packet_parser},
			{SENSOR_STATUS_REPORT,    	PACKET_PARSER::parse, 			&packet_parser},
			{SENSOR_CONFIG_REPORT,		PACKET_PARSER::parse, 			&packet_parser},
			{SENSOR_SYNC_REPORT,    	PACKET_PARSER::parse, 			&packet_parser},
			{SENSOR_DATA_REPORT,      	PACKET_PARSER::parse, 			&packet_parser},
			{SENSOR_ERROR_REPORT,		PACKET_PARSER::parse,			&packet_parser} 
	};

	//! Define a PACKET_DECODER object
	PACKET_HANDLER packet_decoder((void*)&packet_handlers);

	//! Define a COMMAND_INTERPRETER object
	COMMAND_PARSER command_interpreter(&nvram, &packet_decoder);
	
	//! An RFBee object
	RFBEE_STACK rfbee_module(&nvram);

	//! This sets up a scheduler entity
	SCHEDULER scheduler(sensor_db, &command_interpreter, &packet_decoder);
	
	#ifdef DEBUG_LEDs
		//! Define a DEBUG_API object if debug.
		DEBUG_API debug_api;
	#endif
	
	// Define a context object
	main_defines main;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~ VARIABLE DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//! A generic pointer to the chosen object.
	void* generic_pointer;
	
	//! A generic pointer to the scheduler object.
	void* schduler_ptr;

	//! The base station address
	byte base_station_address;

	//! The base station state machine mode
	byte base_station_mode;

	//! Define which device was chosen.
	byte emulation_chosen;
	byte usb_device_chosen;

// This checks the context monitors.
// The ISR Is set as an overflow interrupt.
//	- This means that the timer is continuously reloaded with a value, 
//		which is then the trigger to the ISR when overflown.
ISR(TIMER1_OVF_vect){
	
	// Set the interrupt to 10 sec
	TCNT1 = 685720;            // preload timer for 10 sec
	
	// We walk through the sensor db and check their integrity
	for(register byte i = 0; i < MAX_SENSORS; i ++){	
		if(!sensor_db[i].check_sensor_environment())
			global_context_error_flag = true;
	}
	
	// We check the scheduler state
	if(!scheduler._check_scheduler_state())
		global_context_error_flag = true;
	
	// We check the rfbee module
	if(!rfbee_module.check_rfbee_state())
		global_context_error_flag = true;
}

#endif

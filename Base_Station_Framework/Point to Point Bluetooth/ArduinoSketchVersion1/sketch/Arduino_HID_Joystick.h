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
#include <Arduino.h>

#include "User_Configs.h"
#include "EEPROM.h"
#include "NVRAM_API.h"
#include "Main_Defines.h"
#include "Hardware_Defines.h"

#include "Bluetooth_Engine.h"
#include "Bluetooth_Handler.h"

#include "USB_Device_Implementation.h"
#include "Emulation_Device_Implementation.h"


/**
 * This file contains all of the device DEFINE macros, and
 * also includes all of the libraries that are needed to
 * be references. All of the structures and classes are also
 * built by default in this header file.
 **/

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~ OBJECT DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//! Define an EEPROM object.
	EEPROMClass eeprom;

	//! Define an NVRAM object
	NVRAM nvram;
	
	// The bluetooth SPP stack
	BTD btd(&RF_SERIAL);
		
	// The bluetooth HID handler
	WII wii_device(&btd, PAIR);
	
	#ifdef DEBUG_LEDs
		//! Define a DEBUG_API object if debug.
		DEBUG_API debug_api;
	#endif

	//! Define a bluetooth handler
	BLUETOOTH_HANDLER bt_handler(PACKET_TIMEOUT);

	//! Define a bluetooth adapter
	BLUETOOTH_ENGINE bt_device(&bt_handler);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~ VARIABLE DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//! A generic pointer to the chosen object.
	void* generic_pointer;

	//! Define which device was chosen.
	byte emulation_chosen;
	byte usb_device_chosen;
	
	//! Define a global error flag... 
	//! If this is asserted, we then proceed to the error method.
	//! Only the interrupt can change this to true.
	static boolean global_context_error_flag = false;

// This checks the context monitors.
// The ISR Is set as an overflow interrupt.
//	- This means that the timer is continuously reloaded with a value, 
//		which is then the trigger to the ISR when overflown.
ISR(TIMER1_OVF_vect){
	
	// Set the interrupt to 1Hz again
	TCNT1 = 68572;            // preload timer 1hz
	
	// If there is an error we reset our code. \
		The bluetooth stack will then resolad as well.
	if(global_context_error_flag){
		reset_device();
	}
}

#endif

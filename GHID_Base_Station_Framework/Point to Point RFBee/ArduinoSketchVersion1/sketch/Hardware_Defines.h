/*
 * Hardware_Defines.h
 *
 *  Created on: Jul 26, 2013
 *      Author: fjpapin
 */

#ifndef HARDWARE_DEFINES_h_
#define HARDWARE_DEFINES_h_


#include <Arduino.h>

extern "C" {
//! external reference to the end of the BSS for use in checking memory consumption
	extern uint16_t __bss_end;
}

//! This determines the sensor data maps
#define WATCH_ONLY
//#define WATCH_SENSOR_EMG
//#define WATCH_SENSOR_OTHER

//! Environment wide defines.
#define MAX_ROUTER_ERRORS	        10
#define MIN_BATT_LEVEL		        100
#define GOOD						1
#define FIVE_SECONDS		        5000
#define THREE_SECONDS               3000
#define ONE_SECOND					1000
#define EMPTY						0

#define MAX_WARNINGS 		        10
#define MAX_INFO					100000
#define MAX_DEBUG					100000
#define MAX_MEMORY					10

#define F_CPU						16000000

//#define DEBUG_development					//! The debug interface for Serial3, Serial2, Serial1
#define DEBUG								//! Serial Debug Define
#define USER_INPUT							//! User Button Define
//#define DEBUG_LEDs							//! Debug LEDs Define

#define NUMBER_OF_LEDS		        4

//! Serial device map
//!	- Serial 1 - USB Endpoint - PC COMS
//! - Serial 2 - USB Host 	  - RF COMS
//! - Serial 3 - Debug		  - FTDI COMS

 //! Normal Output Stream
#define SERIAL_OUTPUT				Serial
#define PRINT						Serial.print	//! Serial API
#define PRINTLN						Serial.println //! Serial API

//! RF output stream
#define RF_SERIAL					Serial2
#define RF_PRINT					Serial2.print
#define RF_PRINTLN					Serial2.println

//! Debug Output Stream
#ifdef DEBUG
	#define DEBUG_SERIAL			Serial
	#define DEBUG_PRINT 			Serial.print 	//! Serial API
	#define DEBUG_PRINTLN 			Serial.println //! Serial API
 #endif

 //! User Button Activation
 #ifdef USER_INPUT
	#define SELECT_BUTTON_1	        2				//! Choice button
	#define SELECT_BUTTON_2         3				//! Reset button
 #endif

 //! Debug LEDs Activation
	#define DBG_LED_1				22				//! PORT MAPS
	#define DBG_LED_2				24
	#define DBG_LED_3				26
	#define DBG_LED_4				28

#endif /* HARDWARE_DEFINES_H_ */

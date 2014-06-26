/*
 * Main_Defines.h
 *
 *  Created on: Jul 10, 2013
 *      Author: francispapineau
 */

//#include "./Includes.h"

#ifndef MAIN_DEFINES_h_
#define MAIN_DEFINES_h_

//USB Implementation
#include <Arduino.h>
#include "HardwareDefines.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~  C CODE DEFINITIONS  ~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

extern "C" {
//! external reference to the end of the BSS for use in checking memory consumption
	extern word __bss_end;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~ HARDWARE DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * The following are the serial port definitions for the board
 * communications.
 *
 * 	- Serial 1 = USB Communications
 * 	- Serial 2 = Bluetooth Communications
 */

//! USB COMMUNICATIONS

#define USB_COMMS						Serial
#define USB_COMMS_PRINT					Serial.print
#define USB_COMMS_PRINTLN				Serial.println

extern HardwareSerial Serial1;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~  DEBUG DEFINITIONS   ~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * This is the pre-compiler debug toggle. 
 * This toggle will only work if the USB PHY is programed as a Serial pass through.
 * otherwise the serial interface will not display the proper debug messages.
 */

//! You need to uncomment this to debug the device.
#define DEBUG

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~ USB HARDWARE DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//! We can either be a joystick or a mouse
//#define MOUSE_REPORT
#define JOYSTICK_REPORT

#ifdef JOYSTICK_REPORT
//! We define the number of axes needed
#define NUM_AXES						6
#endif

//! We define the number of buttons needed
#define NUM_BUTTONS						30

//! Dynamic USB Configuration -- BETA
// #define DYNAMIC_JOYSTICK_CONFIG

//! Big joystick definition (6 axes and 30 buttons)
// #define BIG_JOYSTICK


#endif


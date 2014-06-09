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

//! BLUETOOTH COMMUNICATIONS

#define BLUETOOTH_COMMS					Serial1
#define BLUETOOTH_COMMS_PRINT			Serial1.print
#define BLUETOOTH_COMMS_PRINTLN			Serial1.println

extern HardwareSerial Serial2;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~ USB HARDWARE DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//! We can either be a joystick or a mouse
//#define MOUSE_REPORT
#define JOYSTICK_REPORT

#ifdef JOYSTICK_REPORT
//! We define the number of axes needed
#define NUM_AXES						3
#endif

//! We define the number of buttons needed
#define NUM_BUTTONS						8

//! Generic empty define
#define EMPTY							0x00


#endif

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

#include "GHID_Project.h"

//! --------------------------------------------------
//! Defines
//! --------------------------------------------------

//! We need digital ports
#define GHID_DIGITAL_PORT

//! We need analog ports
#define GHID_ANALOG_PORT

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! Here we setup a context object
GHID_System_Abstration system;

//! --------------------------------------------------
//! Prototypes
//! --------------------------------------------------

void setup(void);
void loop(void);

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//! Here we setup the USB interface
	system.setup_USB_interface();

	//=========================================
	// INSERT SETUP CODE HERE
	//=========================================

}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================

	//! We delay 10ms
	delay(10);

	system.send_USB_frame();
}

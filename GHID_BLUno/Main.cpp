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
#include "ADS1298Driver.h"

//! --------------------------------------------------
//! Defines
//! --------------------------------------------------


//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------


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

	//=========================================
	// INSERT SETUP CODE HERE
	//=========================================
	attachInterrupt(PIN_DRDY, ADS1298_Driver::execute_isr, CHANGE);
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================

}

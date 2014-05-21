/*
 * GHIDSystemAbstration.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_System_Abstration.h"

//! Sets the analog voltage reference
void GHID_System_Abstration::setup_analog_reference(byte reference){

	//! Set the analog reference
	analogReference(reference);
}

//! Sets up the serial interface
void GHID_System_Abstration::setup_USB_interface(){

	//! Setup the Serial0 to 115200 and default parity
	Serial.begin(115200);
}

//! Sends a USB frame
void GHID_System_Abstration::send_USB_frame(){

	//! Send the frame
	Serial.write((byte*)&this->joystick_report, sizeof(this->joystick_report));
}

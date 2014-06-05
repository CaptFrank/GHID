/*
 * USB_Device_Implementation.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#include "USBDeviceImplementation.h"

//! Default Constructor
USBDevice::USBDevice(void* report){

	//! Initializing the environment variables
	_report = report;
}

//! Sends a USB report frame
void USBDevice::_send_usb_report_frame(void* report){

#ifdef MOUSE_REPORT

	//! Send the structure.
	USB_COMMS.write((uint8_t*)&report, sizeof(mouse_report_t));
#endif

#ifdef JOYSTICK_REPORT

	//! Send the structure.
	USB_COMMS.write((uint8_t*)_report, sizeof(joystick_report_t));
#endif

}

// Run the usb live
void USBDevice::run_usb(){

	/**
	 * Once the state machine gets here, it polls for data from the router
	 * and parses it into the structures.
	 */

	//! Send the valid report.
	_send_usb_report_frame(_report);
	
}

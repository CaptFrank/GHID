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
	#ifdef JOYSTICK_REPORT
		this->_report = (joystick_report_t*)report;
	#endif
	
	#ifdef MOUSE_REPORT
		this->_report = (mouse_report_t*)report;
	#endif
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


/**
 * Sets up the USB device report
 */
#ifdef DYNAMIC_JOYSTICK_CONFIG
bool USBDevice::_setup_usb_device(){

	uint8_t config[] = {CONFIG_HEADER, NUM_AXES, NUM_BUTTONS, CONFIG_TAIL};

	//! Send configs
	USB_COMMS.write((uint8_t*)config, sizeof(config));
	
	//! Loop to configs
	uint8_t timeout = USB_TIMEOUT;
	while(timeout --){
		
		if(USB_COMMS.available()){
			uint8_t response = USB_COMMS.read();
			if (response == CONFIGURED){
				return true;
			}
		}
	}
	return false;
}
#endif

/**
 * Start the USB engine Serial
 */
bool USBDevice::begin(){
	
	USB_COMMS.begin(USB_BAUD);
	
	//! Setup the usb report
	#ifdef DYNAMIC_JOYSTICK_CONFIG
	return this->_setup_usb_device();
	#endif
	return true;
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

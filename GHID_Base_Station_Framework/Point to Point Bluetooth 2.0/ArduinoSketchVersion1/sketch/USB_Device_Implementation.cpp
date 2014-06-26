/*
 * USB_Device_Implementation.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#include "USB_Device_Implementation.h"

//! Default Constructor
USB_DEVICE::USB_DEVICE(BLUETOOTH_ENGINE* bt_engine, byte* internal_flag){

	//! Initializing the enviroment variables
	_packet_buffer = EMPTY;
	_packet_id = EMPTY;
	_packet_in_sending_queue = true;
	_packet_size = 0;
	_bt_engine = bt_engine;
	_internal_error_flag = internal_flag;
}

//! Create a valid packet to send in USB format
void* USB_DEVICE::_create_usb_report_frame(){
	
	// recreate the structures we need.
#ifdef JOYSTICK_REPORT

	// Define the joystick structure
	joystick_report_t joystick_report;
	
	// Copy the data over
	memcpy((void*)&joystick_report, this->_bt_engine->report,
					sizeof(joystick_report_t));
					
	// Return the pointer
	return (void*)&joystick_report;
#endif
			
#ifdef MOUSE_REPORT
	
	// Define the mouse report
	mouse_report_t mouse_report;
	
	// Copy the data over
	memcpy((void*)&mouse_report, this->_bt_engine->report, 
					sizeof(mouse_report_t));
	
	// Return the pointe
	return (void*)&mouse_report;
#endif
}

//! Sends a USB report frame
void USB_DEVICE::_send_usb_report_frame(void* report){

#ifdef MOUSE_REPORT

	//! Send the structure.
	SERIAL_OUTPUT.write((uint8_t*)&report, sizeof(mouse_report_t));
#endif

#ifdef JOYSTICK_REPORT

	//! Send the structure.
	SERIAL_OUTPUT.write((uint8_t*)&report, sizeof(joystick_report_t));
#endif

	_packet_in_sending_queue = false;
}

//! Setup rf link
void USB_DEVICE::_init_bluetooth_network(){

	// Setup the bluetooth device.
	this->_bt_engine->setup_bluetooth_device();
}

// Run the usb live
void USB_DEVICE::run_usb(){

	#ifdef DEBUG
		DEBUG_SERIAL.println("RUNNING BLUETOOTH INIT()");
	#endif
	//! Sets up the rf network and sends the start command
	this->_init_bluetooth_network();

	/**
	 * Once the state machine gets here, it polls for data from the router
	 * and parses it into the structures.
	 */

	#ifdef DEBUG
		DEBUG_SERIAL.println("RUNNING USB LIVE");
	#endif
	
	// Endless thread until error or reset.
	while(1){
		
		//! We check the global error flag
		if(&this->_internal_error_flag)
			error();
		
		//! delay  the sending of the frame.
		delay(100);
		
		// Poll the serial line
		this->_bt_engine->run();
			
		//! Create a valid USB Frame
		void* report = _create_usb_report_frame();
		
		//! Send the valid report.
		_send_usb_report_frame(&report);
	}
}

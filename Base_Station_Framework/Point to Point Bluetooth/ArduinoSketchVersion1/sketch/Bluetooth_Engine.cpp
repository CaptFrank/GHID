/* 
* Bluetooth_Device.cpp
*
* Created: 2/19/2014 11:24:07 PM
* Author: francis-ccs
*/


#include "Bluetooth_Engine.h"

// Public Context
// ============================================

// Default constructor
BLUETOOTH_ENGINE::BLUETOOTH_ENGINE(BLUETOOTH_HANDLER* handler){
	
	// We assign the handler.
	this->handler = handler;
}

BLUETOOTH_ENGINE::BLUETOOTH_ENGINE(BLUETOOTH_HANDLER* handler, 
										bluetooth_settings_t* settings){
	// We assign the handler
	this->handler = handler;
	
	// We copy the struct given.
	memcpy((void*)&this->bt_settings, settings, sizeof(this->bt_settings));

}

// Sets up the bluetooth device
void BLUETOOTH_ENGINE::setup_bluetooth_device(){
	
	// In this method, the local settings structure is passed \
		to the setup method, but it is only a container; there are \
		no valid values in this struct.
		
	// The settings object can be specified by the user and then \
		passed to the constructor in this method to be setup.
	this->handler->setup_device(&this->bt_settings);

	// We set a stream and data reporting
	this->wii_device->setReportMode(true, HID_RPT_PROTOCOL);
	
	// We init the extensions to get unencrypted values
	this->wii_device->initExtension1();
	this->wii_device->initExtension2();
	
	// We check if the connection was successful
	if(!wii_device->activeConnection)
		error();
}
	
// Runs the bluetooth thread
void BLUETOOTH_ENGINE::run(){
	
	// This polls the serial buffer for incoming bytes.\
		This then returns true if the packet is GOOD.
	this->_poll();
		
	// We run the wii engine to see if we need to \
		do anything to the engine itself
	this->wii_device->Run();
	
	if(this->wii_device->valid_packet){
		// Next we determine the direction of the board.
		this->_process_rx_packet();
		this->_set_usb_frame();
	}
}

// Set the device and stack references
void BLUETOOTH_ENGINE::set_btd_wii(BTD* btd, WII* wii){

	this->btd = btd;
	this->wii_device = wii;	
}
	
// Private context
// ============================================

// The polling method
void BLUETOOTH_ENGINE::_poll(){
	
	// We poll the serial bus for data
	this->btd->Poll();	
}

// Processes the data 
void BLUETOOTH_ENGINE::_process_rx_packet(){
	
	// TODO
	
	// Here we do the computations to find the center of gravity, 
	// and the direction of the x and y.
	// To find the center of pressure on the wii balance board, we use the
	// following equation given the data from the board
	//
	// x-axis = (21.59) * ((BR + TR) - (BL - TL)) / ((BR + TR) + (BL + TL)) 
	// y-axis = (12.07) * ((TL + TR) - (BR - BL)) / ((TL + TR) + (BL + BR))
	
	// Compute;
	this->x_axis = ((HALF_X_BOARD_CM) * ((((this->wii_device->bottomRight) + (this->wii_device->topRight)) - 
										((this->wii_device->bottomLeft) - (this->wii_device->topLeft))) / 
										(((this->wii_device->bottomRight) + (this->wii_device->topRight)) +
										((this->wii_device->topLeft) + (this->wii_device->bottomLeft)))));
									
	this->y_axis = ((HALF_Y_BOARD_CM) * ((((this->wii_device->topLeft) + (this->wii_device->topRight)) -
										((this->wii_device->bottomRight) - (this->wii_device->bottomLeft))) /
										(((this->wii_device->topLeft) + (this->wii_device->topRight)) +
										((this->wii_device->bottomLeft) + (this->wii_device->bottomRight)))));
										
	// Map the results to an 8 bit value to fit in our report.
	this->data[0] = map(this->x_axis, 0, BIT16, 0, BIT8);
	this->data[1] = map(this->y_axis, 0, BIT16, 0, BIT8);
}

// Sets up the usb frame
void* BLUETOOTH_ENGINE::_set_usb_frame(){
	
	// Here all we do is return the pointer to our struct
	#ifdef JOYSTICK_REPORT
		for(register byte i = 0; i < NUM_AXES; i ++){
			// We never go above 2
			this->joystick_report.axis[i] = data[i % 2];
		}
		this->report = &this->joystick_report;
	#endif
	
	#ifdef MOUSE_REPORT
		this->mouse_report.x = this->data[0];
		this->mouse_report.y = this->data[1];
		this->report = &this->mouse_report;
	#endif
	
	return this->report;	
}
/*
 * GHIDUART.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_UART.h"

//! The default constructor
GHID_UART::GHID_UART(serial_settings_t* settings) {

	//! We first copy the settings to our container.
	memcpy(&this->settings, settings, sizeof(serial_settings_t));

	//! Then we construct the objects.
	this->_get_object_type();

	//! We then setup the device
	this->_setup_device();
}

//! The object type getter
void GHID_UART::_get_object_type(){

	//! We switch on the settings flag
	switch(this->settings.hw_sw_flag){

		//! If a hw device is chosen
		case HARDWARE_SERIAL_FLAG:

			//! We get the pointer from the map
			this->serial_driver_hw = this->map[this->settings.serial_port];
			delete this->serial_driver_sw;
			break;

		//! If a sw device is chosen
		case SOFTWARE_SERIAL_FLAG:

			//! Set a class object
			this->serial_driver_sw = SoftwareSerial(this->settings.rx_pin,
													this->settings.tx_pin,
													this->settings.logic_type);
			delete this->serial_driver_hw;
			break;

		//! Else we do nothing, and return
		default:
			break;
	}
}

//! The setup method
void GHID_UART::_setup_device(){

	//! Here we check the type of device and set them up accordingly
	//! We switch on the settings flag
	switch(this->settings.hw_sw_flag){

		//! If a hw device is chosen
		case HARDWARE_SERIAL_FLAG:

			//! We start the uart interrupt
			this->serial_driver_hw->begin(this->settings.baudrate,
										  this->settings.parity);
			break;

		//! If a sw device is chosen
		case SOFTWARE_SERIAL_FLAG:

			//! We start the software uart thread
			this->serial_driver_sw->begin(this->settings.baudrate);
			break;

		//! Else we do nothing, and return
		default:
			break;
	}
}

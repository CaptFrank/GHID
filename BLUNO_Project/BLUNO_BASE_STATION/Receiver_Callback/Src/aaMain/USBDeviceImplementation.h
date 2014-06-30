/*
 * USB_Device_Implementation.h
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#ifndef USB_DEVICE_IMPLEMENTATION_H_
#define USB_DEVICE_IMPLEMENTATION_H_

#include <Arduino.h>
#include <inttypes.h>

#include "USBStructures.h"
#include "HardwareDefines.h"

//! USB Defines
#define USB_BAUD						115200
#define USB_TIMEOUT						500
#define CONFIG_HEADER					'@'
#define CONFIG_TAIL						'*'
#define CONFIGURED						0x01

/**
 * This is the USB device interface class. It provides a handling mechanism
 * that is able to communicate with the USB PHY and thus, allow for USB HID
 * reports to be sent to the host computer.
 */
class USBDevice {

	//! Private Context
	private:

		//! The global report pointer

	#ifdef JOYSTICK_REPORT
		joystick_report_t* _report;
	#endif
	#ifdef MOUSE_REPORT

		mouse_report_t* _report;
	#endif

		/**
		 * Sends the usb report
		 */
		void _send_usb_report_frame(void* report);
		
		#ifdef DYNAMIC_JOYSTICK_CONFIG
		/**
		 * Sets up the USB device report
		 */
		bool _setup_usb_device();
		#endif

	//! Public Context
	public:

		/**
		 * The class constructor. We pass it the global void report pointer.
		 */
		USBDevice(void* bt_engine);

		/**
		 * Start the USB engine Serial
		 */
		bool begin();

		/**
		 * Runs the usb device
		 */
		void run_usb();
};


#endif /* USB_DEVICE_IMPLEMENTATION_H_ */



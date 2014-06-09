/*
 * SystemMonitor.h
 *
 *  Created on: 2014-06-05
 *      Author: francispapineau
 */

#ifndef SYSTEMMONITOR_H_
#define SYSTEMMONITOR_H_

#include <Arduino.h>
#include "HardwareDefines.h"
#include "Utilities.h"
#include "BluetoothConnectionHandler.h"
#include "Watchdog.h"
#include "ProtocolDefinition.h"

/**
 * This class is the system context manager. It is used to reboot the device
 * when there is an error, check the remote sensor status when there is a
 * received heartbeat packet and finally assign new data to the USB engine
 * whe new usb data is received.
 *
 */
class SystemMonitor {

	//! Public Context
	public:

		/**
		 * This is the default constructor for the class.
		 *
		 * @param report_prt							- the usb report pointer
		 * @param data									- the global data containers
		 * @param handler								- the bluetooth data handler
		 * @param watch									- the watchdog
		 */
		SystemMonitor(void* report_prt, Utilities* data,
					BluetoothConnectionHandler* handler,
					Watchdog* watch);

		/**
		 * This is the main work thread for the engine.
		 */
		void run();

	//! Private Context
	private:

		/**
		 * The usb report
		 */
	#ifdef JOYSTICK_REPORT
		joystick_report_t* _report;
	#endif

	#ifdef MOUSE_REPORT
		mouse_report_t* _report;
	#endif

		/**
		 * The bluetooth connection handler context
		 */
		Utilities* _data_ptr;

		/**
		 * The data handler
		 */
		BluetoothConnectionHandler* _handler;

		/**
		 * This is the packet watchdog
		 */
		Watchdog* _watch;

		/**
		 * This is the error task thread
		 */
		void _error();

		/**
		 * This is the data received task thread
		 */
		void _data();

		/**
		 * This is the heartbeat received task thread
		 */
		void _heartbeat();
};

#endif /* SYSTEMMONITOR_H_ */

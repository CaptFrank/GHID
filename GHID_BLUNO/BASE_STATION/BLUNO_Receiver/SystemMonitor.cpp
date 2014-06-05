/*
 * SystemMonitor.cpp
 *
 *  Created on: 2014-06-05
 *      Author: francispapineau
 */

#include "SystemMonitor.h"

//! Public Context

/**
 * This is the default constructor for the class.
 *
 * @param report_prt							- the usb report pointer
 * @param data									- the global data containers
 * @param handler								- the bluetooth data handler
 */
SystemMonitor::SystemMonitor(void* report_prt, Utilities* data,
							BluetoothConnectionHandler* handler,
							Watchdog* watch){

	//! Assign internal access
	this->_data_ptr = data;
	this->_handler = handler;
	this->_report = report_prt;
	this->_watch = watch;
}

/**
 * This is the main work thread for the engine.
 */
void SystemMonitor::run(){

	//! We check the internal data type within the bluetooth
	//! connection handler

	//! Packet timeout
	if(this->_watch->check_watchdog()){

		//! Stop the sensor
		this->_handler->_write_command(STOP_SERVER_CMD);

		//! Reboot the sensor
		this->_handler->_write_command(REBOOT_SERVER_CMD);

		//! Reboot the local system
		this->_data_ptr->reboot();
	}

	//! We switch on the type of data received
	switch(this->_data_ptr->type){

		//! We got data
		case DATA_PACKET:

			//! Data
			this->_data();
			break;

		//! We got an error
		case ERROR_PACKET:

			//! Error
			this->_error();
			break;

		//! We got a heartbeat
		case HEARTBEAT_PACKET:

			//! Heartbeat
			this->_heartbeat();
			break;

		default:
			break;

	}
}

//! Private Context

/**
 * This is the error task thread
 */
void SystemMonitor::_error(){

	//! Here we reboot the device remotely and locally to restart the application

	//! Reboot local
	this->_handler->_write_command(REBOOT_SERVER_CMD);
	delay(100);

	//! Reboot local
	this->_data_ptr->reboot();

}

/**
 * This is the data received task thread
 */
void SystemMonitor::_data(){

	//! All we do here is map the data from the sensor device and
	//! the globalized report.
	noInterrupts();

	//! memcopy
	memcpy((void*)this->_report,
			(void*)this->_handler->_packet._data._sensor_data,
			sizeof(this->_handler->_packet._data.sensor_data_t));
	interrupts();
}

/**
 * This is the heartbeat received task thread
 */
void SystemMonitor::_heartbeat(){

	//! Here we check the heartbeat
	//! We check if we have received a heartbeat then we reset the watchdog.
	this->_watch->reset();

}

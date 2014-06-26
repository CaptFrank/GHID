/*
 * Utilities.cpp
 *
 * Created: 5/20/2014 8:29:31 PM
 *  Author: Administrator
 */ 

#include "Utilities.h"

/**
 * This function simply acts as a boolean flag toggle. We use
 * it to start the device data acquisition.
 */
void utilities::start_device(void){
	start_engine = true;
}

/**
 * This function simply acts as a boolean flag toggle. We use
 * it to stop the device data acquisition.
 */
void utilities::stop_device(void){
	start_engine = false;
}

/**
 * Reboot the device
 */
void utilities::reboot(){
	//! Reset the device
	void (*reset_device)(void) = 0;
	reset_device();
}
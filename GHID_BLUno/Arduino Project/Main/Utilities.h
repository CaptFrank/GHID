/*
 * Utilities.h
 *
 * Created: 5/20/2014 12:42:56 PM
 *  Author: Administrator
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! The start flag
bool start = false;

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

//! Reset the mcu
void (*reset_device)(void) = 0;

/**
 * This function simply acts as a boolean flag toggle. We use
 * it to start the device data acquisition.
 */
inline void start_device(void){
	start = true;
}

/**
 * This function simply acts as a boolean flag toggle. We use
 * it to stop the device data acquisition.
 */
inline void stop_device(void){
	start = false;
}

#endif /* UTILITIES_H_ */
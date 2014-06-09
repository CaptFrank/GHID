/*
 * Packet_Watchdog.cpp
 *
 *  Created on: Jul 24, 2013
 *      Author: fjpapin
 */

#include "Watchdog.h"

// Define the empty state
#define EMPTY		0x00

/**
 * The check watchdog method.
 */
bool Watchdog::check_watchdog(){
	
    //! if we have just timed out, next time around the alarm will sound
    if ((millis() - this->_time) > HEARTBEAT_TIMEOUT) {
    		this->_time = 1;
    		return true;
    }
    return false;
}

//! Reset the watchog timer.
void Watchdog::reset(){
		
        //! Remember when we saw this packet
        this->_time = millis();
}

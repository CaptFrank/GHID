/*
 * Packet_Watchdog.h
 *
 *  Created on: Jul 24, 2013
 *      Author: fjpapin
 */

#ifndef PACKET_WATCHDOG_h_
#define PACKET_WATCHDOG_h_

#include <Arduino.h>

//! Global packet macros definition
#define HEARTBEAT_TIMEOUT	1000 //!1sec

/**
 * This class implements the timeout packet receive
 * watchdog, and also implements the check for the
 * timing basis and checks.
 */
class Watchdog{

	// Private Context
	private:
		
		//! Time
		uint32_t _time;
	
	//! Public Context
	public:

		/**
		 * The default constructor for the class
		 */
		Watchdog(){
			
			//! Set the time to 0;
			this->_time = 0;
		};
			

		/**
		 * The publicly accessible method to reset the watchdog.
		 *
		 */
		void reset();

		/**
		 * Checks the watchdog variable
		 */
		bool check_watchdog();

};

#endif


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
#define PACKET_TIMEOUT		1000 //!5sec
#define PACKET_ALARM_RATE	500

/**
 * This class implements the timeout packet receive
 * watchdog, and also implements the check for the
 * timing basis and checks.
 */
class WATCHDOG{

	private:

		//! Time keeping variables.
		unsigned long _last_time_stamp;
		unsigned long _last_alarm;

		//! Sentinel variables for the the alarms
		bool _alarm_inverted;

		/**
		 * Reset function to reset the watchdog
		 */
		void _reset(void);

	public:

		/**
		 * The publicly accessible method to reset the watchdog.
		 * @param arg - void*
		 * @param packet_id - byte
		 * @param packet_ver byte
		 * @param packet_data - void*
		 */
		static void reset(void* arg, byte packet_id, byte packet_ver,
			void* packet_data);

		/**
		 * Checks the watchdog variable
		 */
		void check_watchdog(void);

};

#endif

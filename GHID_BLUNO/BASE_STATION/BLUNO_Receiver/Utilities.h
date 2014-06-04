/*
 * Utilities.h
 *
 * Created: 5/20/2014 12:42:56 PM
 *  Author: Administrator
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "USBStructures.h"

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This is the selector enum
 */
enum axis_t {
	X_AXIS			= 0x01,			//!< X_AXIS
	Y_AXIS			= 0x02,			//!< Y_AXIS
	Z_AXIS 			= 0x03			//!< Z_AXIS
};

/**
 * The remote device state
 */
enum state_t {

	IDLE,     						//!< IDLE
	SUSPENDED,						//!< SUSPENDED
	STOPPED, 						//!< STOPPED
	RUNNING,  						//!< RUNNING
	REBOOT_STATE,   				//!< REBOOT
	ERROR     						//!< ERROR
};

/**
 * Connection state
 */
enum connection_t {

	UNKNOWN,     					//!< UNKNOWN
	INITIALIZED, 					//!< INITIALIZED
	CONNECTED,   					//!< CONNECTED
	DISCONNECTED,					//!< DISCONNECTED
	CLOSED       					//!< CLOSED
};

/**
 * Received packet type
 */
enum packet_type_t {

	DATA_PACKET,    				//!< DATA
	ERROR_PACKET,   				//!< ERROR
	HEARTBEAT_PACKET				//!< HEARTBEAT
};

/**
 * This class is the global device handler. It starts and stops the device processe globally.
 */
class utilities {

	//! Public Context
	public: 
		/**
		 * This function simply acts as a boolean flag toggle. We use
		 * it to start the device data acquisition.
		 */
		void start_device(void);

		/**
		 * This function simply acts as a boolean flag toggle. We use
		 * it to stop the device data acquisition.
		 */
		void stop_device(void);
		
		/**
		 * Reboot the device
		 */
		void reboot();

		/**
		 * This does a memory check of the whole system, and checks
		 * to see how much free mem there is.
		 */
		word memory_check();
			
		//! start engine boolean
		bool start_engine;

		//! Remote device state
		state_t remote_state;

		//! Connection state
		connection_t connection_state;

		//! Packet received signal
		packet_type_t type;

	#ifdef JOYSTICK_REPORT

		//! Joystick report globally accessible
		joystick_report_t report;
	#endif

	#ifdef MOUSE_REPORT

		//! Mouse report globally accessible
		mouse_report_t report;
	#endif
	
};


#endif /* UTILITIES_H_ */

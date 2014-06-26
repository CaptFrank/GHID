/*
 * Utilities.h
 *
 * Created: 5/20/2014 12:42:56 PM
 *  Author: Administrator
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "USBStructures.h"
#include "ByteBuffer.h"

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This is the selector enum
 */
enum axis_t {
	X_AXIS				= 0x01,			//!< X_AXIS
	Y_AXIS				= 0x02,			//!< Y_AXIS
	Z_AXIS 				= 0x03			//!< Z_AXIS
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
	
	
	CONNECTED_STATE,   				//!< CONNECTED
	DISCONNECTED_STATE,				//!< DISCONNECTED
	CLOSED_STATE       				//!< CLOSED
};

/**
 * Received packet type
 */
enum packet_type_t {

	DATA_PACKET			= 0x01,    				//!< DATA
	ERROR_PACKET		= 0x02,   				//!< ERROR
	HEARTBEAT_PACKET	= 0x03			//!< HEARTBEAT
};

/**
 * This class is the global device handler. It starts and stops the device processe globally.
 */
class Utilities {

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
		
		//! Byte buffer for the BLE chip
		ByteBuffer ring_buffer;

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


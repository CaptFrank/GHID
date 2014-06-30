/* 
* NRF8001Driver.h
*
* Created: 6/23/2014 8:14:15 AM
* Author: Administrator
*/

#ifndef __NRF8001DRIVER_H__
#define __NRF8001DRIVER_H__

//! Defaults
#include <Arduino.h>
#include <avr/pgmspace.h>

//! NRF8001 Functionnality
#include "lib_aci.h"
#include "aci_setup.h"

// Local Settings
#include "Utilities.h"
#include "NRF8001Services.h"
#include "NRF8001UARTOverBLE.h"
#include "ConnectionHandler.h"
#include "BluetoothConnectionCommands.h"
#include "BluetoothConnectionProtocol.h"

//! Generic defines
#define OK					        "@"
#define MAX_COMMAND_LENGTH			30
#define COMMAND_LENGTH				2			// Header + command
#define SUCCESS						0
#define EMPTY						0
#define TIMEOUT						5			// 5 Seconds

/**
 * This is the NRF8001 Bluetooth device driver. This class handles the setting up
 * and direct access to the Bluetooth transceivers settings.
 */
class NRF8001Driver {

	//! Public Context
	public:
	
		/**
		 * This is the default constructor for the class.
		 * 
		 * @param state									- the aci settings structure
		 * @param utils									- the system utilities
		 */
		NRF8001Driver(struct aci_state_t* state, Utilities* utils);
		
		// Functionality
		
		/**
		 * This is the default setup loop.
		 */
		void setup();
		
		/**
		 * This is the default run method.
		 */
		void run();
		
		// I/O
		
		/**
		 * This is the default write method.
		 *
		 * @param buffer								- the data buffer
		 * @param length								- the data length
		 * @returns bool								- the write status
		 */
		bool write(uint8_t* buffer, uint8_t length);
		
		/**
		 * This is the default read method.
		 *
		 * @returns buffer_t							- the data buffer
		 */
		buffer_t* read();

		// aci_struct that will contain
		// total initial credits
		// current credit
		// current state of the aci (setup/standby/active/sleep)
		// open remote pipe pending
		// close remote pipe pending
		// Current pipe available bitmap
		// Current pipe closed bitmap
		// Current connection interval, slave latency and link supervision timeout
		// Current State of the the GATT client (Service Discovery)
		// Status of the bond (R) Peer address
		struct aci_state_t* _aci_state;
		
	// ---------------------------------------------------------------------------------------------
	
	//! Private Context	
	protected:
	
		// Private variables
		
		//! The global system settings
		Utilities* _utils;
	
		/**
		 *	Include the services_lock.h to put the setup in the OTP memory of the nRF8001.
		 *	This would mean that the setup cannot be changed once put in.
		 *	However this removes the need to do the setup of the nRF8001 on every reset.
		 */

		#ifdef SERVICES_PIPE_TYPE_MAPPING_CONTENT
			services_pipe_type_mapping_t _services_pipe_type_mapping[NUMBER_OF_PIPES];
		#else
			#define NUMBER_OF_PIPES 0
			services_pipe_type_mapping_t* _services_pipe_type_mapping = NULL;
		#endif

		/**
		 *	Temporary buffers for sending ACI commands
		 */
		hal_aci_evt_t  _aci_data;
		hal_aci_data_t _aci_cmd;
		
		/**
		 *	Timing change state variable
		 */
		bool _timing_change_done;
		
		/**
		 * This is the setup required boolean
		 */
		bool _setup_required;
		
		/**
		 *	Used to test the UART TX characteristic notification
		 */
		uart_over_ble_t _uart_over_ble;
		buffer_t		_uart_buffer;
	
	// ---------------------------------------------------------------------------------------------
	
		// Private Methods
		
		/**
		 * This is the default uart setup method.
		 */
		void _uart_over_ble_init(){
			
			// Set the rts local to true
			this->_uart_over_ble.uart_rts_local = true;
		}
		
		/**
		 * This is the default process control point method.
		 *
		 * @param buffer								- the data buffer
		 * @param length								- the data length
		 */
		bool _uart_process_control_point(uint8_t* buffer, uint8_t length);
		
}; //NRF8001Driver

#endif //__NRF8001DRIVER_H__


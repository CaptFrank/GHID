// Do not remove the include below
//! --------------------------------------------------
//! Includes
//! --------------------------------------------------

#include <Arduino.h>

//! Drivers
#include "DFRobotBluetoothDriver.h"
#include "USBDeviceImplementation.h"
#include "HardwareDefines.h"

//! Handlers
#include "BluetoothCommandDispatcher.h"
#include "BluetoothConnectionHandler.h"
#include "ConnectionProtocolHandler.h"

//! Commands
#include "BluetoothCommandIndexes.h"
#include "BluetoothCommandTable.h"

//! Utilties
#include "Utilities.h"
#include "SystemMonitor.h"

//! --------------------------------------------------
//! Defines
//! --------------------------------------------------

#ifdef JOYSTICK_REPORT

//! Define a global report
joystick_report_t report;
#endif

#ifdef MOUSE_REPORT

//! Define a global report
mouse_report_t report;
#endif

//! --------------------------------------------------
//! Global Variables
//! --------------------------------------------------

//! Global utilities
Utilities global_utilities;

//! The watchdog
Watchdog watchdog;

//! The USB Handler
USBDevice usb_interface(&report);

//! A protocol handler
ConnectionProtocolHandler protocol_handler(&BLUETOOTH_COMMS, &global_utilities);

//! The Bluetooth Command dispatcher
BluetoothDispatcher dispatcher(&BLUETOOTH_COMMS);

//! The Bluetooth Driver
//! 	- Here we use the default setup function.... We could change it
//! The default bluetooth settings are as follows:
//!		- 1. Device class: 0
//!		- 2. Inquiry code: 0x009e8b33
//!		- 3. Device mode: Slave mode
//!		- 4. Binding mode: SPP
//!		- 5. Serial port: 38400 bits/s; 1 stop bit, no parity
//!		- 6. Pairing code: “1234”
//!		- 7. Device name: “BASE_STATION"

DFRobotBluetoothDriver bluetooth_driver((char*)"Bluetooth Master", (char*)command_pointers, &dispatcher);

//! The connection
BluetoothConnectionHandler connection(&BLUETOOTH_COMMS, DATA_REQUEST_BASED,
										&protocol_handler, &global_utilities);

//! The System monitor
SystemMonitor system(&report, &global_utilities, &connection, &watchdog);

/**
 * This is the callback table used for the bluetooth driver.
 */
struct callback_t callback_table[] = {

		// COMMAND,						METHOD POINTER, 								OBJECT POINTER

		//! Generic commands
		CONNECT_CALLBACK,				ConnectionProtocolHandler::server,				&protocol_handler,
		DISCONNECT_CALLBACK,			ConnectionProtocolHandler::server,				&protocol_handler,
		REBOOT_CALLBACK,				ConnectionProtocolHandler::server,				&protocol_handler
};

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(){

	//=========================================
	// INSERT SETUP CODE HERE
	//=========================================

	//! SETUP BLUETOOTH

	//! ----------------------------------------------------------------------
	//! CUSTOM BLUETOOTH SETTINGS

	/**
	 * Here the user must use the AT toggle switch on the device to
	 * enter the AT mode within the bluetooth device. This is the only way
	 * we can setup the device. Once the device is setup once, the user does
	 * not have to run this method. The user could comment it out.
	 */
	//! We initialize the Bluetooth device
	//bluetooth_driver.begin();

	/**
	 * Once this device has been set, it will reset itself and the configurations
	 * will be stored in EEPROM on the bluetooth device. The user must then untoggle
	 * the AT mode switch to enter the normal mode of the device. (The usre must do this
	 * within 5 seconds)
	 */

	//! We delay 5 seconds
	//delay(5000);
	
	//! CUSTOM BLUETOOTH SETTINGS
	//! ----------------------------------------------------------------------

	//! Set the callback table within the connection protocol handler
	protocol_handler.set_callback_table(callback_table);

	//! Setup the connection
	connection.begin();
	
	//! We set the global lock to true
	global_utilities.start_engine = true;

	//! We perform a mem check to see if we are in the clear
	if(global_utilities.memory_check() == EMPTY){
		global_utilities.reboot();
	}
	
	//! Setup the USB
	if(!usb_interface.begin()) global_utilities.reboot();
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================

	//! We we are good to go
	if(global_utilities.start_engine){

		//! Run the bluetooth thread
		connection.run(); //! We run the engine

		//! Run the system monitor
		system.run();

		//! We run the USB engine
		usb_interface.run_usb();
	}

	delay(100);
}


// Do not remove the include below
#include "BLUNOReceiver.h"
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
#include "BluetoothCommandTable.h"
#include "BluetoothCommandIndexes.h"

//! Utilties
#include "Utilities.h"

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
utilities global_utilities;

//! The USB Handler
USB_DEVICE usb_interface(&report);

//! A protocol handler
ConnectionProtocolHandler protocol_handler(&BLUETOOTH_COMMS, &global_utilities);

//! The Bluetooth Command dispatcher
Bluetooth_Dispatcher dispatcher(&BLUETOOTH_COMMS);

//! The Bluetooth Driver
//! 	- Here we use the default setup function.... We could change it
DFRobotBluetoothDriver bluetooth_driver((char*)"Bluetooth Master", (char*)command_pointers, &dispatcher);

//! The connection
Bluetooth_Connection_Handler connection(&BLUETOOTH_COMMS, DATA_REQUEST_BASED,
										&protocol_handler, &global_utilities);

/**
 * This is the callback table used for the bluetooth driver.
 */
struct callback_t callback_table[] = {

		// COMMAND,				METHOD POINTER, 							OBJECT POINTER

		//! Generic commands
		CONNECT,				ConnectionProtocolHandler::server,			(void*)&protocol_handler,
		DISCONNECT,				ConnectionProtocolHandler::server,			(void*)&protocol_handler,
		REBOOT,					ConnectionProtocolHandler::server,			(void*)&protocol_handler
};

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//=========================================
	// INSERT SETUP CODE HERE
	//=========================================

	//! SETUP BLUETOOTH

	/**
	 * Here the user must use the AT toggle switch on the device to
	 * enter the AT mode within the bluetooth device. This is the only way
	 * we can setup the device. Once the device is setup once, the user does
	 * not have to run this method. The user could comment it out.
	 */
	//! We initialize the Bluetooth device
	bluetooth_driver.begin();

	/**
	 * Once this device has been set, it will reset itself and the configurations
	 * will be stored in EEPROM on the bluetooth device. The user must then untoggle
	 * the AT mode switch to enter the normal mode of the device. (The usre must do this
	 * within 5 seconds)
	 */

	//! We delay 5 seconds
	delay(5000);

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
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(void){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================

	//! We we are good to go
	if(global_utilities.start_engine){

		//! Run the bluetooth thread
		connection.run(); //! We run the engine

		// TODO
		// DATA PROCESSOR - MAPS DATA TO THE USB FRAME... OR PARSER.

		//! We run the USB engine
		usb_interface.run_usb();
	}

	delay(100);
}


/*
 * CC2540Driver.h
 *
 *  Created on: 2014-05-14
 *      Author: francispapineau
 */

#ifndef CC2540DRIVER_H_
#define CC2540DRIVER_H_

#include <Arduino.h>
#include "BluetoothCommandTable.h"
#include "BluetoothCommandDispatcher.h"

#define OK							"OK"
#define MAX_COMMAND_LENGTH			30
#define SUCCESS						0
#define EMPTY						0

/**
 * This is the CC2540 chip driver. This class handles the setting up and
 * direct access to the bluetooth transceivers settings.
 */
class CC2540_Driver {

	//! Public Context
	public:

		/**
		 * This is the default constructor for the class.
		 *
		 * @param device_name						- The name of the device
		 * @param command_table						- The pointer to the command list
		 * @param setup_method						- The setup method called.
		 * @param serial							- The hardware serial port used
		 */
		CC2540_Driver(char* device_name = "UNKNOWN",
							void* command_table,
							bool(*setup_method)() = this->_default_setup(),
							Bluetooth_Dispatcher* serial);

		/**
		 * The abstract view of the setup of the device.
		 *
		 * @return success							- If the setup was successful
		 */
		bool setup_device();

	//! Private Context
	private:

		//! Internal access to the command table
		void* _command_table;

		//! Internal access
		bool(*_setup_method)(void* object);

		//! The device name
		char* _name;

		//! The internal command dispacher
		Bluetooth_Dispatcher* _dispacher;

		/**
		 * This is the default setup method.
		 *
		 * @return success							- If the dispatch was successful
		 */
		bool _default_setup();

		//! Generic commands

		/**
		 * Sends the AT Interrupt Command to enter the AT Command Mode
		 * 		- Command = +++
		 *
		 * @return success							- If the dispatch was successful
		 */
		bool _send_at_commad();

		/**
		 * This method sends the generic help command for a specific given command.
		 * 		- Command = ?
		 *
		 * @param command							- The command to execute help on
		 * @return success							- If the dispatch was successful
		 */
		bool _send_help_command(uint8_t command_id);

		//! Getters

		/**
		 * This method gets the firmware version on the ble chip.
		 *
		 * @return version							- The stored ble fw version
		 */
		char* _get_firmware_ver();

		/**
		 * This method gets the rssi value from the ble chip.
		 *
		 * @return rssi								- The RSSI value
		 */
		char* _get_rssi_value();

		/**
		 * This method gets the MAC address of the BLE chip.
		 *
		 * @return mac								- The mac address of the BLE chip
		 */
		char* _get_mac_address();

		//! Setters

		/**
		 * Sets the FSM mode on the ble chip
		 *
		 * @param mode								- The eeprom pointer of the mode
		 * @return success							- If the dispatch was successful
		 */
		bool _set_fsm_mode(uint8_t mode);

		/**
		 * Sets the role for the ble chip
		 *
		 * @param mode								- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_role(uint8_t role);

		/**
		 * Sets the connection min interval
		 *
		 * @param mode								- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_min_interval(uint8_t interval);

		/**
		 * Sets the connection max interval
		 *
		 * @param mode								- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_max_interval(uint8_t interval);

		/**
		 * Sets the baudrate speed
		 *
		 * @param baud								- The baudrate string
		 * @return success							- If the dispatch was successful
		 */
		bool _set_baudrate(char* baud);

		/**
		 * Sets the device binding address
		 *
		 * @param address							- The address string
		 * @return success							- If the dispatch was successful
		 */
		bool _set_binding_address(char* address);

		/**
		 * Sets the connection mode of the BLE chip
		 *
		 * @param mode								- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_connection_mode(uint8_t mode);

		/**
		 * Sets the device name
		 *
		 * @param name								- The name string
		 * @return success							- If the dispatch was successful
		 */
		bool _set_device_name(char* name);

		/**
		 * Sets the setting of the BLE chip
		 *
		 * @param mode								- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_setting(uint8_t mode);

		/**
		 * Sets the ibeacon setting of the BLE chip
		 *
		 * @param setting							- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_ibeacon_setting(uint8_t setting);

		/**
		 * Sets the password on the BLE channel
		 *
		 * @param psw								- The password string
		 * @return success							- If the dispatch was successful
		 */
		bool _set_password(char* psw);

		/**
		 * Sets the power of transmission of the BL chip
		 *
		 * 		- Possible commands:
		 * 			- 4,
		 * 			- 0,
		 * 			- -6,
		 * 			- -23
		 *
		 * @param power								- The char array of the power
		 * @return success							- If the dispatch was successful
		 */
		bool _set_tx_power(char* power);

		/**
		 *  This method reboots the ble chip.
		 *  	- Command = AT+RESTART
		 *
		 * @return success							- If the dispatch was successful
		 */
		bool _reboot();

		//! Utilities

		/**
		 * This gets the command from the eeprom base.
		 *
		 * @param command							- The command index
		 * @return char*							- The command string
		 */
		char* _get_command(uint8_t command);

		/**
		 * This method checks for an ok return signal
		 *
		 * @return success							- If OK was received
		 */
		bool _check_ok_response();

};

#endif /* CC2540DRIVER_H_ */

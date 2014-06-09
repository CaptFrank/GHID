/*
 * DFRobotBluetoothDriver.h
 *
 *  Created on: 2014-06-04
 *      Author: francispapineau
 */

#ifndef DFROBOTBLUETOOTHDRIVER_H_
#define DFROBOTBLUETOOTHDRIVER_H_

#include <Arduino.h>
#include <avr/pgmspace.h>

#include "BluetoothCommandIndexes.h"
#include "BluetoothCommandDispatcher.h"

//! Generic defines
#define OK							"OK"
#define MAX_COMMAND_LENGTH			30
#define SUCCESS						0
#define EMPTY						0
#define MASTER_ROLE					'1'
#define SLAVE_ROLE					'0'
#define ADDRESS						"E0C7,9D,61F56E"
#define PASSWORD					"DFRobot"

/**
 * This is the DFRobot Bluetooth device driver. This class handles the setting up
 * and direct access to the Bluetooth transceivers settings.
 */
class DFRobotBluetoothDriver {

	//! Public Context
	public:

		/**
		 * This is the default constructor for the class.
		 *
		 * @param device_name						- The name of the device
		 * @param command_table						- The pointer to the command list
		 * @param serial							- The hardware serial port used
		 * @param setup								- The setup type
		 */
		DFRobotBluetoothDriver(char* device_name,
							char* command_table,
							BluetoothDispatcher* serial);

		/**
		 * This is the begin method for the class.
		 *
		 * @param setup_method						- The setup Method
		 */
		void begin(void (*setup_method)(DFRobotBluetoothDriver* driver) = _default_setup);

	//! Private Context
	private:

		//! Internal access to the command table
		const char* _command_table;

		//! The device name
		char* _name;
		
		//! Internal command buffer
		char _command_buffer[MAX_COMMAND_LENGTH];

		//! The internal command dispacher
		BluetoothDispatcher* _dispacher;

		/**
		 * This is the default setup method.
		 *
		 * @return success							- If the dispatch was successful
		 */
		static void _default_setup(DFRobotBluetoothDriver* object);

		//! Generic command

		/**
		 * This method sends the generic help command for a specific given command.
		 * 		- Command = ?
		 *
		 * @param command							- The command to execute help on
		 * @return success							- If the dispatch was successful
		 */
		bool _send_help_command(uint8_t command_id);

		//! Setters

		/**
		 * Sets the role for the ble chip
		 *
		 * @param mode								- The eeprom pointer of the setting
		 * @return success							- If the dispatch was successful
		 */
		bool _set_role(uint8_t role);

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
		 * @param command							- The setting to change
		 * @return success							- If the dispatch was successful
		 */
		bool _set_setting(uint8_t command, uint8_t mode);

		/**
		 * Sets the password on the BLE channel
		 *
		 * @param psw								- The password string
		 * @return success							- If the dispatch was successful
		 */
		bool _set_password(char* psw);

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

#endif /* DFROBOTBLUETOOTHDRIVER_H_ */

/*
 * DFRobotBluetoothDriver.cpp
 *
 *  Created on: 2014-06-04
 *      Author: francispapineau
 */

#include "DFRobotBluetoothDriver.h"

/**
 * This is the default constructor for the class.
 *
 * @param device_name						- The name of the device
 * @param command_table						- The pointer to the command list
 * @param serial							- The hardware serial port used
 * @param setup								- The setup type
 */
DFRobotBluetoothDriver::DFRobotBluetoothDriver(char* device_name,
					char* command_table,
					BluetoothDispatcher* serial){

	//! Set the internal access points
	this->_command_table = command_table;
	this->_name = device_name;
	this->_dispacher = serial;
}

/**
 * This is the begin method for the class.
 *
 * @param setup_method						- The setup Method
 */
void DFRobotBluetoothDriver::begin(void (*setup_method)(DFRobotBluetoothDriver* driver)){

		//! Setup the bluetooth device
		setup_method(this);
}

/**
 * This is the default setup method.
 *
 * @return success							- If the dispatch was successful
 */
static void DFRobotBluetoothDriver::_default_setup(DFRobotBluetoothDriver* object){

	//! We set the device name
	if(object->_set_device_name(object->_name)){

		//! We set the role of the device
		if(object->_set_role(MASTER_ROLE)){

			//! We set the remote binding address
			if(object->_set_binding_address(ADDRESS)){

				if(object->_set_password(PASSWORD)){

					//! We reboot
					object->_reboot();
				}
			}
		}
	}
}

//! Generic commands

/**
 * This method sends the generic help command for a specific given command.
 * 		- Command = ?
 *
 * @param command							- The command to execute help on
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_send_help_command(uint8_t command_id){

	//! Get the command
	String command = (this->_get_command(command_id));
	command[command.length()] = this->_get_command(HELP);

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();

}

//! Setters

/**
 * Sets the role for the ble chip
 *
 * @param mode								- The eeprom pointer of the setting
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_role(uint8_t role){

	//! Get the command
	String command = (this->_get_command(ROLE));
	command.concat(this->_get_command(role));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	this->_dispacher->run_dispatch();
	return this->_check_ok_response();
}

/**
 * Sets the baudrate speed
 *
 * @param baud								- The baudrate string
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_baudrate(char* baud){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(SERIAL_SETTINGS));

	//! We format the arg
	sprintf(temp, this->_get_command(STRING_INPUT), baud);
	command.concat(temp);

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the device binding address
 *
 * @param address							- The address string
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_binding_address(char* address){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(BINDING_ADDRESS));

	//! We format the arg
	sprintf(temp, this->_get_command(STRING_INPUT), address);
	command.concat(temp);

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the connection mode of the BLE chip
 *
 * @param mode								- The eeprom pointer of the setting
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_connection_mode(uint8_t mode){

	//! Get the command
	String command = (this->_get_command(CONNECTION_MODE));
	command.concat(this->_get_command(mode));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the device name
 *
 * @param name								- The name string
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_device_name(char* name){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(NAME));

	//! We format the arg
	sprintf(temp, this->_get_command(STRING_INPUT), name);
	command.concat(temp);

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();

}

/**
 * Sets the setting of the BLE chip
 *
 * @param mode								- The eeprom pointer of the setting
 * @param command							- The setting to change
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_setting(uint8_t command, uint8_t mode){

	//! Get the command
	String command_string = (this->_get_command(command));
	command_string.concat(String(mode));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command_string.c_str(), command_string.length());
	return this->_check_ok_response();
}

/**
 * Sets the password on the BLE channel
 *
 * @param psw								- The password string
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_set_password(char* psw){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(PASSWORD_CMD));

	//! We format the arg
	sprintf(temp, this->_get_command(STRING_INPUT), psw);
	command.concat(temp);

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 *  This method reboots the ble chip.
 *  	- Command = AT+RESTART
 *
 * @return success							- If the dispatch was successful
 */
bool DFRobotBluetoothDriver::_reboot(){

	//! Get the command
	String command = (this->_get_command(RESET_CMD));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}


//! Utilities

/**
 * This gets the command from the eeprom base.
 *
 * @param command							- The command index
 * @return char*							- The command string
 */
char* DFRobotBluetoothDriver::_get_command(uint8_t command){

	//! Reset the default buffer.
	char command_buffer[MAX_COMMAND_LENGTH];
	memset(command_buffer, '\0', sizeof(command_buffer));

	//! Copy the command over
	strcpy_P((char*)command_buffer, (char*)pgm_read_word(&(this->_command_table[command])));
	return command_buffer;
}

/**
 * This method checks for an ok return signal
 *
 * @return success							- If OK was received
 */
bool DFRobotBluetoothDriver::_check_ok_response(){

	//! We check the response
	if(this->_dispacher->run_dispatch()){
		if(strcmp((char*)this->_dispacher->get_response()->response, OK) == SUCCESS){
			return true;
		}
	}
	return false;
}

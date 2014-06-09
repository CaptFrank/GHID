/*
 * CC2540Driver.cpp
 *
 *  Created on: 2014-05-14
 *      Author: francispapineau
 */

#include "CC2540Driver.h"

//! Public Context

/**
 * This is the default constructor for the class.
 *
 * @param device_name						- The name of the device
 * @param command_table						- The pointer to the command list
 * @param setup_method						- The setup method called.
 * @param serial							- The hardware serial port used
 * @param setup								- The setup type
 */
CC2540_Driver::CC2540_Driver(char* device_name,
							char* command_table,
							Bluetooth_Dispatcher* serial,
							void (*setup_method)(CC2540_Driver* driver)){

	//! Set the internal access points
	this->_command_table = command_table;
	this->_name = device_name;
	this->_dispacher = serial;
	setup_method(this);
}

//! Private Context

/**
 * This is the default setup method.
 *
 * @return success							- If the dispatch was successful
 */
void CC2540_Driver::_default_setup(CC2540_Driver* driver){
	
	//! We send the at command break
	driver->_send_at_commad();

	//! We set the name of the device
	if(driver->_set_device_name(driver->_name)){

		//! We set the default setting
		if(driver->_set_setting(SETTING_DEFAULT)){

			//! We reboot the device
			driver->_exit_at();
		}
	}
}

//! Utilities

/**
 * This gets the command from the eeprom base.
 *
 * @param command							- The command index
 * @return char*							- The command string
 */
char* CC2540_Driver::_get_command(uint8_t command){

	//! Reset the default buffer.
	char command_buffer[MAX_COMMAND_LENGTH];
	memset(command_buffer, '\0', sizeof(command_buffer));

	//! The string address
	uint16_t flash_address = pgm_read_word(&(this->_command_table[command]));
	
	//! index count
	char c = 0;
	
	//! Read the command and store it
	do {
		command_buffer[c] = (char) pgm_read_byte(flash_address + c);
		c++;
		
	} while (command_buffer[c - 1] != '\0');
	return command_buffer;
}


//! Generic commands

/**
 * Sends the AT Interrupt Command to enter the AT Command Mode
 * 		- Command = +++
 *
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_send_at_commad(){

	//! Get the command
	String command = (this->_get_command(AT_MODE));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * This method sends the generic help command for a specific given command.
 * 		- Command = ?
 *
 * @param command							- The command to execute help on
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_send_help_command(uint8_t command_id){

	//! Get the command
	String command = (this->_get_command(command_id));
	command.concat(this->_get_command(HELP));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

//! Getters

/**
 * This method gets the firmware version on the ble chip.
 *
 * @return version							- The stored ble fw version
 */
char* CC2540_Driver::_get_firmware_ver(){

	//! Get the command
	String command = (this->_get_command(GET_FW_VERSION));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	this->_dispacher->run_dispatch();
	return (char*)this->_dispacher->get_response()->response;
}

/**
 * This method gets the rssi value from the ble chip.
 *
 * @return rssi								- The RSSI value
 */
char* CC2540_Driver::_get_rssi_value(){

	//! Get the command
	String command = (this->_get_command(GET_RSSI_VALUE));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	this->_dispacher->run_dispatch();
	return (char*)this->_dispacher->get_response()->response;
}

/**
 * This method gets the MAC address of the BLE chip.
 *
 * @return mac								- The mac address of the BLE chip
 */
char* CC2540_Driver::_get_mac_address(){

	//! Get the command
	String command = (this->_get_command(GET_MAC_ADDRESS));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	this->_dispacher->run_dispatch();
	return (char*)this->_dispacher->get_response()->response;
}

//! Setters

/**
 * Sets the FSM mode on the ble chip
 *
 * @param mode								- The eeprom pointer of the mode
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_fsm_mode(uint8_t mode){

	//! Get the command
	String command = (this->_get_command(FSM_MODE_CHANGE));
	command.concat(this->_get_command(mode));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the role fo the ble chip
 *
 * @param mode								- The eeprom pointer of the setting
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_role(uint8_t role){

	//! Get the command
	String command = (this->_get_command(ROLE_CHANGE));
	command.concat(this->_get_command(role));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the connection min interval
 *
 * @param mode								- The eeprom pointer of the setting
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_min_interval(uint8_t interval){

	//! Get the command
	String command = (this->_get_command(MIN_CON_INTERVAL_CHANGE));
	command.concat(this->_get_command(interval));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the connection max interval
 *
 * @param mode								- The eeprom pointer of the setting
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_max_interval(uint8_t interval){

	//! Get the command
	String command = (this->_get_command(MAX_CON_INTERVAL_CHANGE));
	command.concat(this->_get_command(interval));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the baudrate speed
 *
 * @param baud								- The baudrate string
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_baudrate(char* baud){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(BAUDRATE_CHANGE));

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
bool CC2540_Driver::_set_binding_address(char* address){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(BINDING_ADDRESS_CHANGE));

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
bool CC2540_Driver::_set_connection_mode(uint8_t mode){

	//! Get the command
	String command = (this->_get_command(CONNECTION_MODE_CHANGE));
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
bool CC2540_Driver::_set_device_name(char* name){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(SET_DEVICE_NAME));

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
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_setting(uint8_t mode){

	//! Get the command
	String command = (this->_get_command(SETTING_CHANGE));
	command.concat(this->_get_command(mode));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the ibeacon setting of the BLE chip
 *
 * @param setting							- The eeprom pointer of the setting
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_ibeacon_setting(uint8_t setting){

	//! Get the command
	String command = (this->_get_command(IBEACON_SETTING_CHANGE));
	command.concat(this->_get_command(setting));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the password on the BLE channel
 *
 * @param psw								- The password string
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_password(char* psw){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(PSW_CHANGE));

	//! We format the arg
	sprintf(temp, this->_get_command(STRING_INPUT), psw);
	command.concat(temp);

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * Sets the power of transmission of the BL chip
 *
 * 		- Possible values:
 * 			- [4],
 * 			- [0],
 * 			- [-6],
 * 			- [-23]
 *
 * @param power								- The char array of the power
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_set_tx_power(char* power){

	char temp[10];

	//! Get the command
	String command = (this->_get_command(TX_POWER_SETTING));

	//! We format the arg
	sprintf(temp, this->_get_command(STRING_INPUT), power);
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
bool CC2540_Driver::_reboot(){

	//! Get the command
	String command = (this->_get_command(REBOOT));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 *  This method exits from the at mode on the ble chip
 *
 * @return success							- If the dispatch was successful
 */
bool CC2540_Driver::_exit_at(){
	
	//! Get the command
	String command = (this->_get_command(EXIT_AT));

	//! We setup a dispatch
	this->_dispacher->setup_dispatch((uint8_t*)command.c_str(), command.length());
	return this->_check_ok_response();
}

/**
 * This method checks for an ok return signal
 *
 * @return success							- If OK was received
 */
bool CC2540_Driver::_check_ok_response(){

	//! We check the response
	if(this->_dispacher->run_dispatch()){
		if(strcmp((char*)this->_dispacher->get_response()->response, OK) == SUCCESS){
			return true;
		}
	}
	return false;
}

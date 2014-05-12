//
//  Bluetooth_Handler.cpp
//  Arduino_Bluetooth_Library
//
//  Created by Francis Papineau on 2/3/2014.
//  Copyright (c) 2014 Francis Papineau. All rights reserved.
//

#include "Bluetooth_Handler.h"

// -------------------------------------------------------------------------
// PRIVATE CONTEXT

void BLUETOOTH_HANDLER::error(byte error_code){
    
    //! We stop teh data stream
    this.stop_device_stream();
    
	//! Set the system wide error flag
	this->flags.runtime_mutex_flags.error_flag = 1;
	
    //! We return to the uC context
    this.return_to_uC_context(error_code);
}

void BLUETOOTH_HANDLER::send_command(byte* command, byte length, byte check_ok = true){
    
    //! Send the command
    RF_SERIAL.write(command, length);
	
	if(check_ok){
		//! We want 2 bytes 'O', 'K'
		byte rx[2];
    
		//! We loop until timeout is reached
		while (this->timeout--){
		
			//! If we have received data
			if(RF_SERIAL.available() > 0){
			
				//! Read 2 bytes
				byte rx[0] = RF_SERIAL.read();
				byte rx[i] = RF_SERIAL.read();
			
				//! If those bytes are 'OK'
				if(rx == "OK"){
				
					//! We are good
					return
				}
			}
		}
		//! We have timed out we exit in error mode.
		this->error(AT_CMD_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::receive_response(byte length, byte* command){
	
	//! Our index
	byte i = 0;
	
	//! We loop until timeout is reached
	while (this->timeout--){
		
		//! Check if we got something back
		if(RF_SERIAL.available() > 0){
			this->response.response[i] = RF_SERIAL.read();
			i++;
		}
	}
	
	//! Check if we have a bogus packet.
	if((i <= length) || (this->response.response[0] == 0)){
		this->error(AT_CMD_ERROR);
		
	}else{ //! The packet is then valid
		this->response.valid = true;
		this->parse_packet(&this->response.response, command_length, packet_length);
	}
	
	//! We send the packet address.
	return &this->response;
}

void BLUETOOTH_HANDLER::parse_response(char* packet, byte command_length, byte packet_length){
	
	//! Copy the packet bytes into an array
	byte packet_byte[packet_length];
	memcpy(packet_byte, packet, packet_length);
	
	//! Convert the array to a String
	String packet_string = String(packet_byte);
	
	//! Get a substring of the response
	String packet_response = packet_string.substring(command_length, packet_length);
	
	//! Assign the substring to the struct.
	this->response.parsed_response = packet_response.c_str();
}

boolean BLUETOOTH_HANDLER::_bluetooth_test(){
    
	//! We send the AT Command
	this->_bluetooth_handle_at_command();
	
	//! We return only if we have received 'OK'
	return true;
}

void BLUETOOTH_HANDLER::_bluetooth_handle_at_command(){
    
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_init_device(){
    
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, INIT_DEVICE_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_reset_device(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, RESET_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_software_version(){
    
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, VERSION_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(VERSION_COMMAND), VERSION_COMMAND);
	}
	else 
		this->error(DEFAULT_ERROR)
}
    
void BLUETOOTH_HANDLER::_bluetooth_restore_defaults(){
    
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, RESTORE_DEFAULTS_COMAMND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_delete_autenticated_device(char* ascii_device, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_device, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, DELETE_DEVICE_ENTRY_FROM_NET_TABLE, command_params,  
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_delete_all_authenticated_devices(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, DELETE_ALL_ENTRIES_FROM_NET_TABLE,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command)); 
}
    
boolean BLUETOOTH_HANDLER::_bluetooth_check_if_listed_devices_active(char* ascii_device, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_device, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_AUTHENTICATED_DEVICE_COMMAND, command_params,
					TAIL_COMMAND};
					
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_network_table_length(){
    
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_NETWORK_TABLE_LIST_LENGTH, TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command), false);
		
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_NETWORK_TABLE_LIST_LENGTH), 
												GET_NETWORK_TABLE_LIST_LENGTH);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
	
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_most_recently_connected_device(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_MOST_RECENTLY_USED_COMAMND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_MOST_RECENTLY_USED_COMAMND), 
												GET_MOST_RECENTLY_USED_COMAMND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_working_status(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_STATE_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_DEVICE_STATE_COMMAND),
												GET_DEVICE_STATE_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_nearby_devices(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, CREATE_NETWORK_MAP_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(CREATE_NETWORK_MAP_COMMAND),
												CREATE_NETWORK_MAP_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}
    
void BLUETOOTH_HANDLER::_bluetooth_cancel_request_nearby_devices(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, CANCEL_NETWORK_MAP_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_pair_device(char* ascii_params){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_device, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, PAIR_DEVICE_COMMAND, command_params,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_link_to_device(char* ascii_device, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_device, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, LINK_DEVICE_COMMAND, command_params,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));	
}
    
void BLUETOOTH_HANDLER::_bluetooth_disconnect(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, DISCONNECT_DEVICE_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_enter_saving_mode(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GO_INTO_ENERGY_SAVING_MODE_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_exit_saving_mode(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, EXIT_ENERGY_SAVING_MODE_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_device_name(char* ascii_name, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_name, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_DEVICE_NAME_COMMAND, command_params,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_set_device_role(char* ascii_role, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_role, length);
		
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_DEVICE_ROLE_COMMAND, command_params,
					TAIL_COMMAND};
		
	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_device_type(char* ascii_type, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_type, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_DEVICE_TYPE_COMMAND, command_params,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_access_code(char* ascii_access_code, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_access_code, length);
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_DEVICE_ACCESS_CODE_COMMAND, command_params,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_inquiry_mode(char* ascii_inquiry_mode, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_inquiry_mode, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_DEVICE_INQUIRY_MODE_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_pairing_password(char* ascii_password, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_password, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_PAIRING_PASSWORD_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_serial_port_params(char* ascii_params, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_params, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_SERIAL_PORT_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_connection_mode(char* ascii_connection_mode, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_connection_mode, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_CONNECTION_MODE_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_binding_address(char* ascii_binding_address, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_binding_address, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_BINDING_ADDRESS_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_led_polarity(char* ascii_polarity, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_polarity, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_POLARITY_LED_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_pio_output(char* ascii_pio, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_pio, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_POI_COMMNAD, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_multiple_output(char* ascii_ports, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_pio, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_MULTIPLE_PIO_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_pio_input(char* ascii_port, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_port, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_POI_COMMNAD, command_params,
	TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_inquiry_params(char* ascii_params, byte length){

	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_params, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_DEVICE_INQUIRY_MODE_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_sniff_power(char* ascii_sniff, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_sniff, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_POWER_SAVING_PARAMETERS_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_security_mode(char* ascii_enc, byte length){
	
	//! Get the full command
	char command_params[length];
	memcpy(command_params, ascii_enc, length);

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, SET_ENCRYPTION_COMMAND, command_params,
					TAIL_COMMAND};

	//! We send the command
	this->send_command(command, sizeof(command));
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_address(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, POLL_ADDRESS_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(POLL_ADDRESS_COMMAND),
												POLL_ADDRESS_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}	
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_name(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_NAME_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_DEVICE_NAME_COMMAND),
												GET_DEVICE_NAME_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_remote_device_name(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_REMOTE_DEVICE_NAME_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_REMOTE_DEVICE_NAME_COMMAND),
												GET_REMOTE_DEVICE_NAME_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_role(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_ROLE_COMAMND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_DEVICE_ROLE_COMAMND),
												GET_DEVICE_ROLE_COMAMND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_type(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_TYPE_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_DEVICE_TYPE_COMMAND),
												GET_DEVICE_TYPE_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_access_code(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_ACCESS_CODE_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_DEVICE_ACCESS_CODE_COMMAND),
												GET_DEVICE_ACCESS_CODE_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_inquiry_mode(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_INQUIRY_MODE_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_DEVICE_INQUIRY_MODE_COMMAND),
												GET_DEVICE_INQUIRY_MODE_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_pairing_password(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_PAIRING_PASSWORD_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_PAIRING_PASSWORD_COMMAND),
												GET_PAIRING_PASSWORD_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_serial_port_params(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_SERIAL_PORT_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_SERIAL_PORT_COMMAND),
												GET_SERIAL_PORT_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_connection_params(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_CONNECTION_MODE_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_CONNECTION_MODE_COMMAND),
												GET_CONNECTION_MODE_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_binding_address(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_BINDING_ADDRESS_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_BINDING_ADDRESS_COMMAND),
												GET_BINDING_ADDRESS_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetoot_get_led_polarity(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_DEVICE_NAME_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_POLARITY_LED_COMMAND),
												GET_POLARITY_LED_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_pio_input(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_PIO_INPUT_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_PIO_INPUT_COMMAND),
												GET_PIO_INPUT_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_inquiry_params(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_INQUIRY_PARAMETERS_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command),  false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_INQUIRY_PARAMETERS_COMMAND),
												GET_INQUIRY_PARAMETERS_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_sniff_power_param(){

	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_POWER_SAVING_PARAMETERS_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_POWER_SAVING_PARAMETERS_COMMAND),
												GET_POWER_SAVING_PARAMETERS_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_security_mode(){
	
	//! Set the appropriate command
	byte command[] = {AT_COMMAND, GET_ENCRYPTION_COMMAND, TAIL_COMMAND};
	
	//! We send the command
	this->send_command(command, sizeof(command), false);
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_response(sizeof(GET_ENCRYPTION_COMMAND),
												GET_ENCRYPTION_COMMAND);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

// -------------------------------------------------------------------------
// PUBLIC CONTEXT

// Check the bluetooth device
void BLUETOOTH_HANDLER::check_device(){
	
	//! We check the hardware
	//!	- First we check the bluetooth hardware
	this->default_operations._bluetooth_test();
	
	
	//! - Second we check to see what happends when we send an \
		at command.
	this->default_operations._bluetooth_handle_at_command();
	
	//! - Third we check the validity of the software version. \
		This also checks the validity of the communication pipe.
	this->default_operations._bluetooth_get_software_version();
	if(!String(this->response.parsed_response) == SOFTWARE_VERSION)
		error(DEFAULT_ERROR);
		
	//! - Forth we check the status of the device
	this->default_operations._bluetooth_check_working_status();
	if(String(this->response.parsed_response) == UNKNOWN){
		error(DEFAULT_ERROR);
	}
}

// Setup the bluetooth device
void BLUETOOTH_HANDLER::setup_device(bluetooth_settings_t* settings){
	
	//! - Zero we init the device.
	this->default_operations._bluetooth_init_device();
	
	//! We check the status of the device to see if it was init
	this->default_operations._bluetooth_check_working_status();
	if(!String(this->response.parsed_response) == INIT){
		error(DEFAULT_ERROR);
	}
	
	//! - First we set the default settings on the device.
	this->default_operations._bluetooth_restore_defaults();
	
	//! - Second we check the size of the nmap list
	this->default_operations._bluetooth_check_network_table_length();
	
	//! - Third we check the actual value we got and if > 0 we \
		delete the entire list to START fresh.
	if(atoi(this->response.parsed_response) > 0)
		this->default_operations._bluetooth_delete_all_authenticated_devices();
	
	//! -  Forth we check the working status of the device
	this->default_operations._bluetooth_check_working_status();
	if(!String(this->response.parsed_response) == READY){
		error(DEFAULT_ERROR);
	}
	
	if(settings->default_values == 1){
		//! We set the device parameters
		this->setter_oprations._bluetooth_set_device_name(settings->device_name, 
															strlen(settings->device_name));
	
		this->setter_oprations._bluetooth_set_device_role(settings->device_role,
															strlen(settings->device_role));
														
		this->setter_oprations._bluetooth_set_device_type(settings->device_type,
															strlen(settings->device_type));
														
		this->setter_oprations._bluetooth_set_access_code(settings->device_access_code,
															strlen(settings->device_access_code));
														
		this->setter_oprations._bluetooth_set_inquiry_mode(settings->device_mode,
															strlen(settings->device_mode));
														
		this->setter_oprations._bluetooth_set_pairing_password(settings->pairing_password,
															strlen(settings->pairing_password));
														
		this->setter_oprations._bluetooth_set_serial_port_params(settings->serial_port_params,
															strlen(settings->serial_port_params));
	
		this->setter_oprations._bluetooth_set_connection_mode(settings->connection_mode,
															strlen(settings->connection_mode));
	
		this->setter_oprations._bluetooth_set_binding_address(settings->binding_address,
															strlen(settings->binding_address));
	
		this->setter_oprations._bluetooth_set_sniff_power(settings->power_params,
															strlen(settings->power_params));
	
		this->setter_oprations._bluetooth_set_security_mode(settings->security_mode,
															strlen(settings->security_mode));
	} else {
		
		this->setter_oprations._bluetooth_set_serial_port_params(settings->serial_port_params,
															strlen(settings->serial_port_params));
															
		this->setter_oprations._bluetooth_set_pairing_password(settings->pairing_password,
															strlen(settings->pairing_password));
	}

// Pair the device
void BLUETOOTH_HANDLER::pair_device(bluetooth_settings_t* settings){
	
	//! We pair the devices.
	this->default_operations._bluetooth_pair_device(settings->remote_device_address_timeout);
	
	//! We connect the devices.
	this->default_operations._bluetooth_link_to_device(settings->remote_device_address);
	
}

// -------------------------------------------------------------------------
// OPERATIONAL CONTEXT

// Start the device (link)
void BLUETOOTH_HANDLER::start_device_stream(){

	//! Set the start flag
	this->flags.runtime_mutex_flags.start_flag = 1;	
}

// Pause the device
void BLUETOOTH_HANDLER::pause_device_stream(){
	
	//! Set the pause flag
	this->flags.runtime_mutex_flags.pause_flag = 1;	
}

// Stop the device
void BLUETOOTH_HANDLER::stop_device_stream(){
	
	//! Set the stop flag
	this->flags.runtime_mutex_flags.stop_flag = 1;
}

// Return to uC context
byte BLUETOOTH_HANDLER::return_to_uC_context(byte error_code){
	
	DEBUG_SERIAL.println("[BLUETOOH ERROR]: Returning to the uC context.");
	reset_device();
}


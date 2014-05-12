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

void BLUETOOTH_HANDLER::error(uint8_t error_code){
    
    //! We stop the data stream
    this->stop_device_stream();
    
	//! Set the system wide error flag
	this->flags.runtime_mutex_flags.error_flag = 1;
	
    //! We return to the uC context
    this->return_to_uC_context(error_code);
}

void BLUETOOTH_HANDLER::send_command(uint8_t* command, uint8_t length){
    
	boolean check_ok = true;
	
    //! Send the command
    RF_SERIAL.write(command, length);
	
	if(check_ok){
		//! We want 2 uint8_ts 'O', 'K'
		uint8_t rx[2];
    
		//! We loop until timeout is reached
		while (this->timeout--){
		
			//! If we have received data
			if(RF_SERIAL.available() > 0){
			
				//! Read 2 uint8_ts
				rx[0] = RF_SERIAL.read();
				rx[1] = RF_SERIAL.read();
			
				//! If those uint8_ts are 'OK'
				if((char*)rx == "OK"){
				
					//! We are good
					return;
				}
			}
		}
		//! We have timed out we exit in error mode.
		this->error(AT_CMD_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::receive_specific_response(uint8_t length, uint8_t* command){
	
	//! Our index
	uint8_t i = 0;
	
	//! We loop until timeout is reached
	while (this->timeout--){
		
		//! Check if we got something back
		if(RF_SERIAL.available() > 0){
			this->response.raw_response[i] = RF_SERIAL.read();
			i++;
		}
	}
	
	// Set the size of the packet
	this->response.size = i;
	
	//! Check if we have a bogus packet.
	if((this->response.size <= 0) || (this->response.raw_response[0] == 0)){
		this->error(AT_CMD_ERROR);
		
	}else{ //! The packet is then valid
		this->response.valid = true;
		this->parse_response(this->response.raw_response, length, (uint8_t)sizeof(this->response.raw_response));
	}
	
	//! We send the packet address.
	return &this->response;
}

bluetooth_response_t* BLUETOOTH_HANDLER::receive_response(){
	
	//! Our index
	uint8_t i = 0;
	
	//! We loop until timeout is reached
	while (this->timeout--){
		
		//! Check if we got something back
		if(RF_SERIAL.available() > 0){
			this->response.raw_response[i] = RF_SERIAL.read();
			i++;
		}
	}
	
	// Set the size of the packet
	this->response.size = i;
	
	//! Check if we have a bogus packet.
	if((this->response.size <= 0) || (this->response.raw_response[0] == 0)){
		this->error(AT_CMD_ERROR);
	}
	
	//! We send the packet address.
	return &this->response;
}

void BLUETOOTH_HANDLER::parse_response(char* packet, uint8_t command_length, uint8_t packet_length){
	
	//! Copy the packet uint8_ts into an array
	uint8_t packet_uint8_t[packet_length];
	memcpy(packet_uint8_t, packet, packet_length);
	
	//! Convert the array to a String
	String packet_string = String((char*)packet_uint8_t);
	
	//! Get a substring of the response
	String packet_response = packet_string.substring(command_length, packet_length);
	
	//! Assign the substring to the struct.
	memcpy(&this->response.parsed_response, packet_response.c_str(), packet_response.length());
}

boolean BLUETOOTH_HANDLER::_bluetooth_test(){
    
	//! We send the AT Command
	this->_bluetooth_handle_at_command();
	
	//! We return only if we have received 'OK'
	return true;
}

void BLUETOOTH_HANDLER::_bluetooth_handle_at_command(){
    
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_init_device(){
    
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, INIT_DEVICE_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_reset_device(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, RESET_COMMAND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_software_version(){
    
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, VERSION_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {VERSION_COMMAND};
		
	//! We send the command
	this->send_command((uint8_t*)command, sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command), (uint8_t*)rx_command);
	}
	else {
		this->error(DEFAULT_ERROR);
	}
}
    
void BLUETOOTH_HANDLER::_bluetooth_restore_defaults(){
    
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, RESTORE_DEFAULTS_COMAMND, TAIL_COMMAND};
		
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_delete_autenticated_device(char* ascii_device, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_device, length); 
	
	//! Set the appropriate command
	uint8_t command[] = {DELETE_DEVICE_ENTRY_FROM_NET_TABLE};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}
    
void BLUETOOTH_HANDLER::_bluetooth_delete_all_authenticated_devices(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, DELETE_ALL_ENTRIES_FROM_NET_TABLE,
					TAIL_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command)); 
}
    
boolean BLUETOOTH_HANDLER::_bluetooth_check_if_listed_devices_active(char* ascii_device, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_device, length);
	
	//! Set the appropriate command
	uint8_t command[] = {GET_AUTHENTICATED_DEVICE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);

}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_network_table_length(){
    
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_NETWORK_TABLE_LIST_LENGTH, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_NETWORK_TABLE_LIST_LENGTH};
		
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
		
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
	
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_most_recently_connected_device(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_MOST_RECENTLY_USED_COMAMND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_MOST_RECENTLY_USED_COMAMND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_working_status(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_STATE_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_DEVICE_STATE_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}
    
bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_check_nearby_devices(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, CREATE_NETWORK_MAP_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {CREATE_NETWORK_MAP_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}
    
void BLUETOOTH_HANDLER::_bluetooth_cancel_request_nearby_devices(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, CANCEL_NETWORK_MAP_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_pair_device(char* ascii_params, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_params, length);
					
	//! Set the appropriate command
	uint8_t command[] = {PAIR_DEVICE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}
    
void BLUETOOTH_HANDLER::_bluetooth_link_to_device(char* ascii_device, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_device, length);

	//! Set the appropriate command
	uint8_t command[] = {LINK_DEVICE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}
    
void BLUETOOTH_HANDLER::_bluetooth_disconnect(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, DISCONNECT_DEVICE_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_enter_saving_mode(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GO_INTO_ENERGY_SAVING_MODE_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}
    
void BLUETOOTH_HANDLER::_bluetooth_exit_saving_mode(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, EXIT_ENERGY_SAVING_MODE_COMMAND,
					TAIL_COMMAND};

	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
}

void BLUETOOTH_HANDLER::_bluetooth_set_device_name(char* ascii_name, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_name, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_DEVICE_NAME_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}
    
void BLUETOOTH_HANDLER::_bluetooth_set_device_role(char* ascii_role, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_role, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_DEVICE_ROLE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);	
}

void BLUETOOTH_HANDLER::_bluetooth_set_device_type(char* ascii_type, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_type, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_DEVICE_TYPE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);	
}

void BLUETOOTH_HANDLER::_bluetooth_set_access_code(char* ascii_access_code, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_access_code, length);
	
	//! Set the appropriate command
	uint8_t command[] = {SET_DEVICE_ACCESS_CODE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_inquiry_mode(char* ascii_inquiry_mode, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_inquiry_mode, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_DEVICE_INQUIRY_MODE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_pairing_password(char* ascii_password, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_password, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_PAIRING_PASSWORD_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_serial_port_params(char* ascii_params, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_params, length);
					
	//! Set the appropriate command
	uint8_t command[] = {SET_SERIAL_PORT_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_connection_mode(char* ascii_connection_mode, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_connection_mode, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_CONNECTION_MODE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_binding_address(char* ascii_binding_address, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_binding_address, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_CONNECTION_MODE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_led_polarity(char* ascii_polarity, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_polarity, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_POLARITY_LED_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_pio_output(char* ascii_pio, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_pio, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_POI_COMMNAD};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_multiple_output(char* ascii_ports, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_ports, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_MULTIPLE_PIO_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_pio_input(char* ascii_port, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_port, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_POI_COMMNAD};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_inquiry_params(char* ascii_params, uint8_t length){

	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_params, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_DEVICE_INQUIRY_MODE_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_sniff_power(char* ascii_sniff, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_sniff, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_POWER_SAVING_PARAMETERS_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

void BLUETOOTH_HANDLER::_bluetooth_set_security_mode(char* ascii_enc, uint8_t length){
	
	//! Get the full command
	uint8_t command_params[length];
	memcpy(command_params, ascii_enc, length);

	//! Set the appropriate command
	uint8_t command[] = {SET_ENCRYPTION_COMMAND};
	
	// Wrap into a command
	bluetooth_command_t* packet = this->_bluetooth_set_command(command, command_params, sizeof(command), length);
	
	//! We send the command
	this->send_command((uint8_t*)packet->command_buffer, (uint8_t)packet->command_length);
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_address(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, POLL_ADDRESS_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {POLL_ADDRESS_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}	
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_name(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_NAME_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_DEVICE_NAME_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_remote_device_name(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_REMOTE_DEVICE_NAME_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_REMOTE_DEVICE_NAME_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_role(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_ROLE_COMAMND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_DEVICE_ROLE_COMAMND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_device_type(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_TYPE_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_DEVICE_TYPE_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_access_code(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_ACCESS_CODE_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_DEVICE_ACCESS_CODE_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_inquiry_mode(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_INQUIRY_MODE_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_DEVICE_INQUIRY_MODE_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_pairing_password(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_PAIRING_PASSWORD_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_PAIRING_PASSWORD_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_serial_port_params(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_SERIAL_PORT_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_SERIAL_PORT_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_connection_params(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_CONNECTION_MODE_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_CONNECTION_MODE_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_binding_address(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_BINDING_ADDRESS_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_BINDING_ADDRESS_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_led_polarity(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_DEVICE_NAME_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_POLARITY_LED_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_pio_input(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_PIO_INPUT_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_PIO_INPUT_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_inquiry_params(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_INQUIRY_PARAMETERS_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_INQUIRY_PARAMETERS_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_sniff_power_param(){

	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_POWER_SAVING_PARAMETERS_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_POWER_SAVING_PARAMETERS_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_response_t* BLUETOOTH_HANDLER::_bluetooth_get_security_mode(){
	
	//! Set the appropriate command
	uint8_t command[] = {AT_COMMAND, GET_ENCRYPTION_COMMAND, TAIL_COMMAND};
	uint8_t rx_command[] = {GET_ENCRYPTION_COMMAND};
	
	//! We send the command
	this->send_command((uint8_t*)command, (uint8_t)sizeof(command));
	
	//! We then receive the response
	if(this->response.valid){
		return this->receive_specific_response((uint8_t)sizeof(rx_command),
												(uint8_t*)rx_command);
	}
	else{
		this->error(DEFAULT_ERROR);
	}
}

bluetooth_command_t* BLUETOOTH_HANDLER::_bluetooth_set_command(uint8_t* command, uint8_t* params, 
																uint8_t command_length, uint8_t params_length){
	uint8_t head[] = {AT_COMMAND};
	uint8_t tail[] = {TAIL_COMMAND};
	
	// We create a command buffer based on the sizes.
	uint8_t command_payload[sizeof(head) + sizeof(tail) + command_length + params_length];
	
	// We copy the head and tail over
	// This one is easy since its from the zeroth position
	// Array[first]
	memcpy((void*)command_payload, (void*)head, sizeof(head));
	
	// This one is a little more challenging since its starts from the end
	// Array[last - sizeof(tail)]
	memcpy((void*)*(command_payload + (sizeof(command_payload) - sizeof(tail))), (void*)tail, sizeof(tail));
	
	// We copy over the command now after the head
	// Array[head, command, tail]
	memcpy((void*)*(command_payload + (sizeof(head) - 1)), (void*)command, command_length);
	
	// We copy over the command parameters now after the command
	// Array[head, command, parameters, tail]
	memcpy((void*)*(command_payload + (sizeof(head) - 1) + (command_length - 1)), (void*)params, params_length);
	
	// We setup a real command object
	bluetooth_command_t command_struct;
	
	// We assign the poitners and values
	command_struct.command_buffer = (char*)command_payload;
	command_struct.command_length = sizeof(command_payload);
	
	return &command_struct;
}

// -------------------------------------------------------------------------
// PUBLIC CONTEXT

// Check the bluetooth device
void BLUETOOTH_HANDLER::check_device(){
	
	//! We check the hardware
	//!	- First we check the bluetooth hardware
	this->_bluetooth_test();
	
	//! - Second we check to see what happends when we send an
	//! at command.
	this->_bluetooth_handle_at_command();
	
	//! - Third we check the validity of the software version. 
	//! This also checks the validity of the communication pipe.
	this->_bluetooth_get_software_version();
	if(strcmp(this->response.parsed_response, SOFTWARE_VERSION) != 0){
		error(DEFAULT_ERROR);
	}
		
	//! - Forth we check the status of the device
	this->_bluetooth_check_working_status();
	if(strcmp(this->response.parsed_response, UNKNOWN) == 0){
		error(DEFAULT_ERROR);
	}
}

// Setup the bluetooth device
void BLUETOOTH_HANDLER::setup_device(bluetooth_settings_t* settings){
	
	//! - Zero we init the device.
	this->_bluetooth_init_device();
	
	//! We check the status of the device to see if it was init
	this->_bluetooth_check_working_status();
	if(strcmp(this->response.parsed_response, INIT) != 0){
		error(DEFAULT_ERROR);
	}
	
	//! - First we set the default settings on the device.
	this->_bluetooth_restore_defaults();
	
	//! - Second we check the size of the nmap list
	this->_bluetooth_check_network_table_length();
	
	//! - Third we check the actual value we got and if > 0 we \
		delete the entire list to START fresh.
	if(atoi(this->response.parsed_response) > 0)
		this->_bluetooth_delete_all_authenticated_devices();
	
	//! -  Forth we check the working status of the device
	this->_bluetooth_check_working_status();
	if(strcmp(this->response.parsed_response, READY) != 0){
		error(DEFAULT_ERROR);
	}
	
	//! We then check if the device is alive or in the local region
	this->_bluetooth_get_remote_device_name();
	if(strcmp(this->response.parsed_response, WII_BOARD_ID) != 0){
		error(DEFAULT_ERROR);
	}
	
	if(settings->default_values == 0){
		//! We set the device parameters
		this->_bluetooth_set_device_name(settings->device_name, 
															strlen(settings->device_name));
	
		this->_bluetooth_set_device_role(settings->device_role,
															strlen(settings->device_role));
														
		this->_bluetooth_set_device_type(settings->device_type,
															strlen(settings->device_type));
														
		this->_bluetooth_set_access_code(settings->device_access_code,
															strlen(settings->device_access_code));
														
		this->_bluetooth_set_inquiry_mode(settings->device_mode,
															strlen(settings->device_mode));
														
		this->_bluetooth_set_pairing_password(settings->pairing_password,
															strlen(settings->pairing_password));
														
		this->_bluetooth_set_serial_port_params(settings->serial_port_params,
															strlen(settings->serial_port_params));
	
		this->_bluetooth_set_connection_mode(settings->connection_mode,
															strlen(settings->connection_mode));
	
		this->_bluetooth_set_binding_address(settings->binding_address,
															strlen(settings->binding_address));
	
		this->_bluetooth_set_sniff_power(settings->power_params,
															strlen(settings->power_params));
	
		this->_bluetooth_set_security_mode(settings->security_mode,
															strlen(settings->security_mode));
															
		this->_bluetooth_set_serial_port_params(settings->serial_port_params,
															strlen(settings->serial_port_params));
															
		this->_bluetooth_set_pairing_password(settings->pairing_password,
															strlen(settings->pairing_password));
	}
}

// Pair the device
void BLUETOOTH_HANDLER::pair_device(bluetooth_settings_t* settings){
	
	//! We pair the devices.
	this->_bluetooth_pair_device(settings->remote_device_address_timeout, 
									strlen(settings->remote_device_address_timeout));
	
	//! We connect the devices.
	this->_bluetooth_link_to_device(settings->remote_device_address,
									strlen(settings->remote_device_address));
	
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
uint8_t BLUETOOTH_HANDLER::return_to_uC_context(uint8_t error_code){
	
	DEBUG_SERIAL.println("[BLUETOOH ERROR]: Returning to the uC context.");
	reset_device();
}

// Default constructor
BLUETOOTH_HANDLER::BLUETOOTH_HANDLER(word timeout){
	this->timeout = timeout;
}

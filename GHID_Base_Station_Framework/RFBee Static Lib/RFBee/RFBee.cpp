/* 
* RFBee_Stack.cpp
*
* Created: 1/25/2014 12:04:03 AM
* Author: francis-ccs
*/

#include "RFBee.h"

// Define a match
#define MATCH		0x00
#define RX_BUF		0x01
#define TIMEOUT		10000

// Init class
RFBEE_STACK::RFBEE_STACK(NVRAM* nvram_object){

	this->nvram_object = nvram_object;
	this->error_flag = true;
}

// Check rfbee intergrity
boolean RFBEE_STACK::check_rfbee_state(){
	
	if(this->error_flag)
		return false;
		
	return true;
}

// Setup the RF module
void RFBEE_STACK::setup_RF_module(){
	
	// Go to the AT mode
	this->_rfbee_handle_AT_command();
	
	// Set the Address check
	rfbee_set_address_checking_scheme(this->nvram_object->nv.address_check_mode);
	
	// Set the host address
	rfbee_set_address(this->nvram_object->nv.node_address);
	
	// Set a broadcast address
	rfbee_set_receivable_address(this->nvram_object->nv.broadcast_address);
	
	// Set transmit power
	rfbee_set_transmit_power(this->nvram_object->nv.transmit_power);
	
	// Set BAUD rate
	rfbee_set_uart_baud(this->nvram_object->nv.baud_rate);
	
	// Set working mode
	rfbee_set_working_mode(this->nvram_object->nv.working_mode);
	
	// Set threshold
	rfbee_set_threshold(this->nvram_object->nv.threashold);
	
	// Set datarate
	rfbee_set_data_rate(this->nvram_object->nv.datarate);
}

// This tests the RFBee
boolean RFBEE_STACK::test_RF_module(){
	
	// the version of the hardware and software
	char version_check[] = {"v1.0"};
	
	// Check hardware version
	rfbee_get_hardware_version();
	if(strcmp(version_check, (char*)this->rx_buffer) == MATCH){
		
		// Check the firmware version
		rfbee_get_firmware_version();
		if(strcmp(version_check, (char*)this->rx_buffer) == MATCH){
			return true;
		}
	}else{
		return false;
	}
}

// Set the address checking scheme
void RFBEE_STACK::rfbee_set_address_checking_scheme(option_t scheme){
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATAC, sizeof(nvram_object->nv.ATAC));
	this->tx_buffer[5] = scheme;
	
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
	
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}

// Set the address of the node
void RFBEE_STACK::rfbee_set_address(option_t address){

	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATMA, sizeof(nvram_object->nv.ATMA));
	this->tx_buffer[5] = address;
	
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
	
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);

}
	
// Set the receive address
void RFBEE_STACK::rfbee_set_receivable_address(option_t address){
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATDA, sizeof(nvram_object->nv.ATDA));
	this->tx_buffer[5] = address;
		
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}
	
// Set the transmit power
void RFBEE_STACK::rfbee_set_transmit_power(option_t power){
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATPA, sizeof(nvram_object->nv.ATPA));
	this->tx_buffer[5] = power;
	
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}
	
// Set the uart baud rate
void RFBEE_STACK::rfbee_set_uart_baud(option_t baud){
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATBD, sizeof(nvram_object->nv.ATBD));
	this->tx_buffer[5] = baud;

	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}
	
// Set the mode
void RFBEE_STACK::rfbee_set_working_mode(option_t mode){
	
	// Setup a command string to send to the rfbee module	
	memcpy(&this->tx_buffer, &nvram_object->nv.ATMD, sizeof(nvram_object->nv.ATMD));
	this->tx_buffer[5] = mode;
	
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}
	
// Set the threshold
void RFBEE_STACK::rfbee_set_threshold(option_t threshold){
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATTH, sizeof(nvram_object->nv.ATTH));
	this->tx_buffer[5] = threshold;
		
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}
	
// Set the datarate
void RFBEE_STACK::rfbee_set_data_rate(option_t datarate){
	
	// Setup a command string to send to the rfbee module	
	memcpy(&this->tx_buffer, &nvram_object->nv.ATDR, sizeof(nvram_object->nv.ATDR));
	this->tx_buffer[5] = datarate;
		
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 6);
}

// Restore defaults
void RFBEE_STACK::rfbee_restore_default_state(){

	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATRS, sizeof(nvram_object->nv.ATRS));
	
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
	
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 5);
}
	
// Get FW ver.
void RFBEE_STACK::rfbee_get_firmware_version(){
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATFV, sizeof(nvram_object->nv.ATFV));
		
	// Put the RFBee into AT mode
	_rfbee_handle_AT_command();
		
	// Send the string
	_rfbee_send_command((void*) tx_buffer, 5);
	
	// read the response
	return this->_rfbee_handle_response_custom();
}
	
// Get HW ver.
void RFBEE_STACK::rfbee_get_hardware_version(){
	
	
	// Setup a command string to send to the rfbee module
	memcpy(&this->tx_buffer, &nvram_object->nv.ATHV, sizeof(nvram_object->nv.ATHV));
	
	// Put the RFBee into AT mode
	this->_rfbee_handle_AT_command();
		
	// Send the string
	this->_rfbee_send_command((void*) tx_buffer, 5);
	
	// read the response
	return this->_rfbee_handle_response_custom();
	
}

rfbee_error_t RFBEE_STACK::rfbee_handle_AT_command(){
	this->_rfbee_handle_AT_command();
}

// Handle RFBee error
boolean RFBEE_STACK::_rfbee_error(){
	
	#ifdef DEBUG
	DEBUG_SERIAL.println("[RFBEE] ERROR WITH CONNECTION TO RFBEE.");
	#endif
	
	this->error_flag = false;
	return false;
}

// Send a command
void RFBEE_STACK::_rfbee_send_command(void* command, byte size){
	
	RF_SERIAL.write((byte*)command, size);
	// We read until something happened
	while(OK > RF_SERIAL.available()){
		if(this->_rfbee_handle_response() == ERROR){
			_rfbee_error();
		}
	}
}

// Handle the AT command
rfbee_error_t RFBEE_STACK::_rfbee_handle_AT_command(){
	
	// We first send the AT Command sequence
	_rfbee_send_command((void*) nvram_object->nv.AT, 4);
}

// Handle the responses
rfbee_error_t RFBEE_STACK::_rfbee_handle_response(){
	
	byte available;

	// We check how many bytes have been received
	available = RF_SERIAL.available();
	
	// If we got 2 that means OK
	if(available == OK)
		return OK;
	
	// If we got 4 that means ERROR
	if(available == ERROR)
		return ERROR;	
}

void RFBEE_STACK::_rfbee_handle_response_custom(){
	
	
	byte index = 0;
	byte available;
	byte timeout = TIMEOUT;

	// We check how many bytes have been received
	while(available < RX_BUF || timeout--){
		available = RF_SERIAL.available();
	}
	
	// If we got 2 that means OK
	if(available > EMPTY){
		while (available--){
			this->rx_buffer[index] = RF_SERIAL.read();
			index++;
		}
	}else{
		error();
	}
}
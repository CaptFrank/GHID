/*
 * ConnectionProtocolHandler.cpp
 *
 *  Created on: 2014-05-16
 *      Author: francispapineau
 */

#include "ConnectionProtocolHandler.h"

//! Public Context

/**
 * This is the default constructor for the class
 *
 * @param rf							- The spi interface
 * @param utils							- The global utilities
 */
ConnectionProtocolHandler::ConnectionProtocolHandler(
													 Utilities* utils){

	//! Set internals
	this->_utils = utils;
	this->_table = 0;
}
/**
 * This sets up the callback table.
 *
 * @param table							- The callback table
 */
void ConnectionProtocolHandler::set_callback_table(callback_t* table){
	
	// Set the internal callback table
	this->_table = table;
}

void ConnectionProtocolHandler::begin(NRF8001Driver* rf){

	// Set the rf driver
	this->_rf = rf;
}

/**
 * This method polls to see if there are some commands received. These are from the client
 * node and cause the server callbacks.
 */
void ConnectionProtocolHandler::poll(){
  
  // A Container
  uint8_t command = 0;
  uint8_t header = 0;

  // We poll only if the connection is open and if there is data 
  // in the ring buffer
  if((this->_utils->connection_state != CLOSED_STATE) && 
     (this->_utils->ring_buffer.getSize() > 0)){
    
        // We peek the header byte
        header = this->_utils->ring_buffer.peek(HEADER_INDEX);
        
        // Sensor Data - We return...
		// We must leave all data where it is to then 
		// allow the system monitor to memmap it to the
		// appropriate data structure.
        if(header == SENSOR_PACKET_PREAMBLE){
            return;
			
		// We got a callback command
        }else if((header == HEADER_ID) && 
                 (this->_utils->ring_buffer.getSize() > 0)){
			
			// Get it
			header = this->_utils->ring_buffer.get();
	        command = this->_utils->ring_buffer.get();

	        // Activate the callback
			for(register uint8_t i = 0; COMMAND_NULL != this->_table[i].command_id; i++){

				//! If we find the command within the table
				if(this->_table[i].command_id == command){
                                
					//! We fire the particular function
					this->_table[i].callback(command, this->_table[i].object);
				}
			}
		}
	}
}

/**
 * This method is used to generic system wide actions
 *
 * @param command						- The issued command
 */
void ConnectionProtocolHandler::server(uint8_t command, void* object){

	//! Cast the object
	ConnectionProtocolHandler* access = (ConnectionProtocolHandler*) object;

	//! We switch on the command
	switch(command){

		//! We reset the device
		case CONNECT_CALLBACK:
			
			// Set the new connection state and write the ACK
			access->_utils->connection_state = CONNECTED_STATE;
			access->_rf->write((uint8_t*)OK_CALLBACK, 0x01);
			
			#ifdef DEBUG
				Serial.println("Connected from Remote node.");
			#endif
			break;

                //! We start the device
		case REBOOT_CALLBACK:
		
			// Set the new connection state and write the ACK
			access->_utils->connection_state = CLOSED_STATE;
			access->_rf->write((uint8_t*)OK_CALLBACK, 0x01);
			
			#ifdef DEBUG
				Serial.println("Rebooting...");
			#endif
			
			// Stop the main thread
            access->_utils->start_engine = false;
			
			// Disconnect and reset
			while(!lib_aci_disconnect(access->_rf->_aci_state, 
									  ACI_REASON_TERMINATE));
			while(!lib_aci_radio_reset());

			// Delay and then reboot the system
			delay(1000);
            access->_utils->reboot();
            break;

		//! We stop the device
		case DISCONNECT_CALLBACK:
		
			// Set the new connection state and write the ACK
			access->_utils->connection_state = DISCONNECTED_STATE;
			access->_rf->write((uint8_t*)OK_CALLBACK, 0x01);
			
			// Disconnect
			while(!lib_aci_disconnect(access->_rf->_aci_state,
										ACI_REASON_TERMINATE));

			#ifdef DEBUG
				Serial.println("Disconnected from Remote node.");
			#endif
			
			// We are now connected
			access->_utils->start_engine = true;
            break;
       
		//! Nothing happens
		default:
			break;
	}
}


/*
 * Command_Interpreter.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: francispapineau
 */
#include "Command_Interpreter.h"

#define ENABLE	1
#define DISABLE 0

// --------------------------------------------------------------------
//! Sets up our non volatile nvram object, our command db.
COMMAND_PARSER::COMMAND_PARSER(NVRAM* nvram_object, PACKET_HANDLER* packet_decoder){
			
	this->command_buffer = 0;
	this->nvram_object = nvram_object;
	this->packet_decoder = packet_decoder;
}

// --------------------------------------------------------------------
// Set the sensor
void COMMAND_PARSER::set_sensor(SENSOR* sensor){
	this->sensor = sensor;
}

// --------------------------------------------------------------------
/**
 * buf. definition: [Target Address][Command Predicate][Arg 1][Arg 2]
 */
//! Sends a command
void COMMAND_PARSER::_send_cmd(byte packet_id, void *buf){

	byte* buffer = (byte*) buf;
	
	byte c = buffer[0];
	
	if(packet_id == USB_DEVICE_CMD){

		//! Construct a command
		_send_command(buffer);
	}
}

// --------------------------------------------------------------------
//! Execute a command from a sensor or router
//! The format of the buf passed -> [command byte][arg1][arg2][...]
void COMMAND_PARSER::_send_command(byte* command){

	byte* command_send;
	switch(command[0]){

 // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case SYNC: 	// Send the sync signal to the remote sensor.
			
			// Form the command to send
			command_send = new byte[4]; 
			command_send[0] = SYNC;
			command_send[1] = this->sensor->sensor_id;
			command_send[2] = (BASE_SYNC_TIME + this->sensor->sensor_id*2) >> 8;
			command_send[3] = (BASE_SYNC_TIME + this->sensor->sensor_id*2) << 8;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_SYNC_REPORT, command_send, 4);
			break;
			
		case PING:
			
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = PING;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_ACK, command_send, sizeof(command_send));
			break;

		case START: 
		
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = START;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_ACK, command_send, sizeof(command_send));	
			break;

		case STOP: 
		
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = STOP;
			command_send[1] = this->sensor->sensor_id;

			// Invoke the send and the check
			_send_check((byte)SENSOR_ACK, command_send, sizeof(command_send));
			break;
			
		case STATUS_REQ:
		
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = STATUS_REQ;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_SYNC_REPORT, command_send, sizeof(command_send));
			break;
			
		case CONFIG_REQ:
		
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = CONFIG_REQ;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_CONFIG_REPORT, command_send, sizeof(command_send));
			break;

		case ABORT: 	
			
			// Form the command to send			
			command_send = new byte[2];
			command_send[0] = ABORT;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_ACK, command_send, sizeof(command_send));
			break;

		case ERROR_RQ: 	

			// Form the command to send
			command_send = new byte[2];
			command_send[0] = ERROR_RQ;
			command_send[1] = this->sensor->sensor_id;
			
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_ACK, command_send, sizeof(command_send));
			break;

		case PAUSE:
		
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = PAUSE;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check((byte)SENSOR_ACK, command_send, sizeof(command_send));
			break;

		case HEARTBEAT_FREQ: 
		
			// Form the command to send			
			command_send = new byte[4];
			command_send[0] = HEARTBEAT_FREQ;
			command_send[1] = this->sensor->sensor_id;
			command_send[2] = (BASE_SYNC_TIME + this->sensor->sensor_id) >> 8;
			command_send[3] = (BASE_SYNC_TIME + this->sensor->sensor_id) << 8;
			
			// Invoke the send and the check
			_send_check(SENSOR_HEARTBEAT_REPORT, command_send, sizeof(command_send));
			break;

		case REQUEST_NUMBER: 	// Pause sensor
		
			// Form the command to send
			command_send = new byte[2];
			command_send[0] = REQUEST_NUMBER;
			command_send[1] = this->sensor->sensor_id;
			
			// Invoke the send and the check
			_send_check(SENSOR_ACK, command_send, sizeof(command_send));
			break;

		default:	// Other commands don't exist
			command_send = 0;
			break;
	}
}

// --------------------------------------------------------------------
//! The public send command method
void COMMAND_PARSER::send_cmd(byte packet_id, void *buf){

	//! Process String
	_send_cmd(packet_id, buf);
}

// --------------------------------------------------------------------
//! Sends and checks a received message.
void COMMAND_PARSER::_send_check(byte receive_packet_id, byte* command, int len){
	
	// Disable the interrupts
	noInterrupts();
	
	//! This formats the packet.
	//!	- [@][Packet Size][Dest. Id][Command][Tail]
	//! - ['@']'2''0x01''0x02''0X0A'
	// Define the packet
	uint8_t packet[len + PACKET_WRAP];
	 
	// Assign the header
	packet[0] = PACKET_PREAMBLE;
	
	// Assign the actual packet data
	packet[1] = len + PACKET_WRAP;
	packet[2] = this->sensor->sensor_id;
	memcpy((void*)&packet[3], (void*)command, len);
	packet[sizeof(packet)] = PACKET_TAIL;
	
	// Resume interrupts
	interrupts();
	
	RF_SERIAL.write(command, len + PACKET_WRAP);
	
	uint8_t timeout_variable = PACKET_TIMEOUT_WATCH;
	while(true){

		//! Gets a packet to the handler and parser.
		this->packet_decoder->poll();
		
		//! Check to see the packet id
		if(packet_decoder->_packet_id == receive_packet_id){
			return;

		//! If the packet is timed out.
		}else if (timeout_variable == EMPTY){
			#ifdef DEBUG_LEDs
				debug_api.set_leds(FATAL_ERROR);
			#endif
			#ifdef DEBUG
				DEBUG_SERIAL.println("NETWORK ERROR - REBOOTING");
			#endif
			error();
		}else{
			#ifdef DEBUG
				DEBUG_SERIAL.println("PING BACK ERROR");
				DEBUG_SERIAL.println(timeout_variable);
			#endif
			timeout_variable--;
			
		}
	}
}
	
// --------------------------------------------------------------------
//! Gets the nmap / enabled sensors
void COMMAND_PARSER::_get_nmap(SENSOR* sensor_db) {
		
	byte command [1];
	//! Check the ping from every sensor.
	for(register byte i = 0; i < MAX_SENSORS; i++){
			
		command[0] = PING;
				
		//! Send until we have a response
		this->_send_check(SENSOR_ACK, command, sizeof(command));
		
		//! We got a response
		if(this->packet_decoder->_packet_id == SENSOR_ACK)
			sensor_db[i].set_state(ENABLE_SENSOR);
			
		else { //! No response
			sensor_db[i].set_state(DISABLE_SENSOR);
		}
	}
}

void COMMAND_PARSER::send_command(uint8_t* command){
	this->_send_command(command);
}

void COMMAND_PARSER::get_nmap(SENSOR* sensor_db){
	this->_get_nmap(sensor_db);
}
/*
 * Sensor_PACKET_PARSER.c
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */
#include "Packet_Parser.h"

// --------------------------------------------------------------------
//! Default constructor
PACKET_PARSER::PACKET_PARSER(SENSOR* db){
	this->db = db;
}

// --------------------------------------------------------------------
//! Sets a particular handler type
void PACKET_PARSER::set_handler(PACKET_HANDLER* packet_handler){
	this->_packet_handler = packet_handler;
}

// --------------------------------------------------------------------
//! Parse the structures.
void PACKET_PARSER::parse(void *arg, byte packet_id, byte packet_ver,
		void *buf) {
	
	//! Process String
	((PACKET_PARSER*) arg)->_parse(packet_id, packet_ver, buf);
}

// --------------------------------------------------------------------
//! Check if a specific packet was read.
bool PACKET_PARSER::_check_read_packet(byte packet_type){
	
	if((!this->_packet_handler->_guard_bool) || 
	!(this->_packet_handler->_packet_id == packet_type)){
		
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
		error();
	}
	return true;
}

// --------------------------------------------------------------------
//! Check the memory space
void PACKET_PARSER::_check_memory_space(size_t mem_space) {

	//! Check memory integrity
	if (memory_check() <= mem_space)
#ifdef DEBUG_LEDs
		debug_api.set_leds(MEMORY_ERROR);
#endif
		error();
}

// --------------------------------------------------------------------
//! Check packet integrity
bool PACKET_PARSER::_check_packet_integrity(char* packet) {

	//! Checks length, Header, Tail
	if (packet[1] > EMPTY)
		if (packet[0] == PACKET_PREAMBLE)
			if (packet[sizeof(packet) - 1] == PACKET_TAIL)
				return true;

	return false;
}

// --------------------------------------------------------------------
//! Checks the ack signal
void PACKET_PARSER::_check_ack() {
	if (this->_ack.ack) {
		return;
	} else {
#ifdef DEBUG_LEDs
		debug_api.set_leds(REBOOT_ERROR);
#endif
		error();
	}
}

// --------------------------------------------------------------------
//! Checks the heartbeat signal
void PACKET_PARSER::_check_heartbeat() {

	//! Checks to see if the sensor mode is in the ok states
	if((_heartbeat.sensor_mode == SENSOR_ERROR_TAG) || 
		(_heartbeat.sensor_mode == SENSOR_REBOOT_TAG)){
		// We have a problem... reboot network
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[SENSOR %d]: Sensor state error.", _header.sensor_id);
		DEBUG_SERIAL.println(debug_info);
#endif
		
		// Reboot network
		error();
	}
	//! Checks the heartbeat of the remote device.
	if (_heartbeat.battery_voltage < MIN_BATT_LEVEL) {
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[SENSOR %d]: Battery level low", _header.sensor_id);
		DEBUG_SERIAL.println(debug_info);
#endif
	}
}

// --------------------------------------------------------------------
//! Checks the router status.
void PACKET_PARSER::_check_sensor_status() {

	#ifdef DEBUG
		char* debug_info;
	#endif

	// Switch on the received state
	switch(_status.state){
		
		// The sensor is ok
		case SENSOR_STATE_OK:
			
			db[_header.sensor_id].set_state(OK_SENSOR_STATE);
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == OK", _header.sensor_id);
				DEBUG_SERIAL.println(debug_info);
			#endif
			break;
			
		// Something went wrong
		case SENSOR_STATE_FAIL:
		case SENSOR_STATE_ERROR:
				
			db[_header.sensor_id].set_state(ERROR_SENSOR_STATE);
			#ifdef DEBUG_LEDs
				debug_api.set_leds(INFO_ERROR);
			#endif
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == ERROR", _header.sensor_id);
				DEBUG_SERIAL.println(debug_info);
			#endif
			
			if(_status.state == SENSOR_STATE_ERROR){
				db[_header.sensor_id].set_error_code(_error.error_code);
				
				#ifdef DEBUG_LEDs
					debug_api.set_leds(INFO_ERROR);
				#endif
				#ifdef DEBUG
					sprintf(debug_info, "[SENSOR %d]: MODE == ERROR code: %d", _header.sensor_id, _error.error_code);
					DEBUG_SERIAL.println(debug_info);
				#endif
			}
			
			//! Reboot the network
			error();
			break;
			
		// The sensor is on a boot mode
		case SENSOR_STATE_BOOT:
		
			db[_header.sensor_id].set_state(ERROR_SENSOR_STATE);
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == BOOT", _header.sensor_id);
				DEBUG_SERIAL.println(debug_info);
			#endif
			break;
			
		// The sensor is rebooting or resetting
		case SENSOR_STATE_REBOOT:
		case SENSOR_STATE_RESET:
			
			db[_header.sensor_id].set_state(ERROR_SENSOR_STATE);
			#ifdef DEBUG_LEDs
				debug_api.set_leds(INFO_ERROR);
			#endif
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == REBOOT/RESET", _header.sensor_id);
				DEBUG_SERIAL.println(debug_info);
			#endif
			break;
			
		// Not a valid packet
		default:
			#ifdef DEBUG_LEDs
				debug_api.set_leds(INFO_ERROR);
			#endif
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: INVALID PACKET", _header.sensor_id);
				DEBUG_SERIAL.println(debug_info);
			#endif
			break;
	}
	
	// Check header by recursivity
	_check_packet_header();
}

// --------------------------------------------------------------------
//! Checks Packet header
void PACKET_PARSER::_check_packet_header() {

	// Check the size value
	if (_header.message_size < 1) {
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[SENSOR %d]: Packet size < 1", _header.sensor_id);
		DEBUG_SERIAL.println(debug_info);
#endif
	
	// we have a net error if we reach this.
		error();
	}
	
	// Check the message size
	if(_header.message_size != this->packet_size){
		
#ifdef DEBUG_LEDs
		debug_api.set_leds(DEBUG_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[BASESTATION]: Packet size issue", _header.packet_version);
		DEBUG_SERIAL.println(debug_info);
#endif
	
	// We discard the packet... we don't use it
	}

	// Check the packet version
	if (_header.packet_version != 0x01) {
#ifdef DEBUG_LEDs
		debug_api.set_leds(DEBUG_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[BASESTATION]: Packet ver (%d) not supported", _header.packet_version);
		DEBUG_SERIAL.println(debug_info);
#endif
	}
	
	// Check the timestamp
	if(_header.sensor_run_time < this->old_sensor_time_stamp){
#ifdef DEBUG_LEDs
		debug_api.set_leds(DEBUG_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[BASESTATION]: Packet timestamp is wrong.", _header.packet_version);
		DEBUG_SERIAL.println(debug_info);
#endif	
	}
}

// --------------------------------------------------------------------
//! Gets the sensor configs
void PACKET_PARSER::_get_sensor_configs() {
	
	//! Set the sensor data type
	memcpy(&db[_header.sensor_id].sensor_config, &_configs.sensor_type, sizeof(_configs));
}

// --------------------------------------------------------------------
//! Checks the sync signal from the sensor
void PACKET_PARSER::_check_sensor_sync(){
	
	//! Check the interrupt number
	if(_sync.interrupt_number != 
		db[_header.sensor_id].sensor_sync.sensor_interrupt_number){
		
		#ifdef DEBUG_LEDs
			debug_api.set_leds(INFO_ERROR);
		#endif
		#ifdef DEBUG
			char* debug_info;
			sprintf(debug_info, "[SENSOR %d]: Interrupt issue.", _header.sensor_id);
			DEBUG_SERIAL.println(debug_info);
		#endif
		goto error_label;
		}
	
	//! Check the priority
	if(_sync.priority != 
		db[_header.sensor_id].sensor_sync.sensor_priority){
			
		#ifdef DEBUG_LEDs
			debug_api.set_leds(INFO_ERROR);
		#endif
		#ifdef DEBUG
			char* debug_info;
			sprintf(debug_info, "[SENSOR %d]: Priority issue", _header.sensor_id);
			DEBUG_SERIAL.println(debug_info);
		#endif
		goto error_label;
		}
		
	//! Check the sync time
	if(_sync.sync_time != 
		db[_header.sensor_id].sensor_sync.sensor_priority){
			
		#ifdef DEBUG_LEDs
			debug_api.set_leds(INFO_ERROR);
		#endif
		#ifdef DEBUG
			char* debug_info;
			sprintf(debug_info, "[SENSOR %d]: Sync. time issue", _header.sensor_id);
			DEBUG_SERIAL.println(debug_info);
		#endif
		goto error_label;
		}
		
	// We have an error and we need to reboot the network.
	error_label:
		error();
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
}

//! Parse the packet
void PACKET_PARSER::_parse(byte packet_id, byte packet_ver, void *buf) {

	char* buffer = (char*) buf;
    char* debug_info;

	//! Check if there is space left
	_check_memory_space();

	//! Check if the string is ok to process.
	this->_check_packet_integrity((char*) buf);

	//! Assigns the new construct
	memcpy(&_header, buffer, sizeof(sensor_packet_header_t));
	_check_packet_header();

	buffer += sizeof(sensor_packet_header_t);

	switch (packet_id) {

	case SENSOR_ACK:
		_alloc_mem(&_ack, sizeof(_ack), buffer);
		_check_ack();
		return;

	case SENSOR_HEARTBEAT_REPORT:
		_alloc_mem(&_heartbeat, sizeof(_heartbeat), buffer);
		_check_heartbeat();
		return;

	case SENSOR_STATUS_REPORT:
		_alloc_mem(&_status, sizeof(_status), buffer);
		_check_sensor_status();
		return;

	case SENSOR_CONFIG_REPORT:
		_check_memory_space(sizeof(sensor_configs_t));
		_alloc_mem(&_configs, sizeof(sensor_configs_t), buffer);
		_get_sensor_configs();
		return;

	case SENSOR_DATA_REPORT:
		_check_memory_space(sizeof(sensor_data_struct_t));
		_alloc_mem(&_data, sizeof(sensor_data_struct_t), buffer);
		return;

	case SENSOR_ERROR_REPORT:
		_alloc_mem(&_error, sizeof(_error), buffer);

#ifdef DEBUG
		sprintf(debug_info, "[%d] %d -> %d", _header.sensor_id, _error.error_code,
				_header.sensor_run_time);
		DEBUG_SERIAL.println(debug_info);
#endif
		return;

	case SENSOR_SYNC_REPORT:
		_alloc_mem(&_sync, sizeof(_sync), buffer);
		_check_sensor_sync();
		return;

	default: //! Nothing done here -- discard the packet.
		return;
	}
}
	
	
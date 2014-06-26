/*
 * DataProcessor.cpp
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#include "DataProcessor.h"

//! Public Context

/**
 *	This creates a heartbeat message to send to the base station.
 * 
 * @param sensor_type								- the sensor type (mouse, joystick)
 * @param sensor_id									- the sensor id	
 * @param heart										- the structure ptr to store the information
 */
void Data_Processor::create_heartbeat(sensor_t sensor_type, char sensor_id, sensor_packet_heartbeat_t* heart){
								
	//! We create the heartbeat
	Data_Processor::_create_header(sensor_type, sensor_id, &heart->_header);
}
		
/**
 *	This create an error report.
 * 
 * @param sensor_type								- the sensor type (mouse, joystick)
 * @param sensor_id									- the sensor id
 * @param error_id									- the error that occured
 * @param error										- the structure ptr to store the information
 */
void Data_Processor::create_error(sensor_t sensor_type, char sensor_id, uint8_t error_id, sensor_packet_error_t* error){
		
	//! We create the header
	Data_Processor::_create_header(sensor_type, sensor_id, &error->_header);		
		
	//! We assign the error
	error->error_code = error_id;							 
}
		
/**
 *	This creates a data report
 * 
 * @param sensor_type								- the sensor type (mouse, joystick)
 * @param sensor_id									- the sensor id	
 * @param buf										- the ring buffer
 * @param data										- the structure ptr to store the information
 */
void Data_Processor::create_data_packet(sensor_t sensor_type, char sensor_id, RingBuff_t* buf, sensor_packet_data_t* data){
	//! We create the header
	Data_Processor::_create_header(sensor_type, sensor_id, &data->_header);
				
	//! First we memset the buffer to reset it
	memset(data->_sensor_data.packet_sensor_axis_data, 0x00, 
				data->_sensor_configs.packet_sensor_axis);
	
	//! First we memset the buffer to reset it
	memset(data->_sensor_data.packet_sensor_button_data, 0x00, 
				data->_sensor_configs.packet_sensor_buttons);

	//! We get the count
	RingBuff_Count_t buff_count = RingBuffer_GetCount(buf);

	//! Then we remove an object from the ring buffer.
	if(buff_count >= sizeof(data->_sensor_data)){
		for(register uint8_t i = 0; i < sizeof(data->_sensor_data); i++){

			((uint8_t*)&data->_sensor_data)[i] = RingBuffer_Remove(buf);
		}

		//! We remove the spacer
		RingBuffer_Remove(buf);
	}	
}

//! Private Context

/**
 *	This creates a header message to send to the base station.
 * 
 * @param sensor_type								- the sensor type (mouse, joystick)
 * @param sensor_id									- the sensor id	
 * @param head										- the structure ptr to store the information
 */
 void Data_Processor::_create_header(sensor_t sensor_type, char sensor_id, sensor_packet_header_t* head){
	//! Set the sensor id
	head->_sensor_id.packet_sensor_id = sensor_id;
	head->_sensor_id.packet_sensor_type = sensor_type;
	
	//! Set the packet configs
	head->_packet_configs.packet_type = SENSOR_PACKET_HEARTBEAT;
	head->_packet_configs.packet_timestamp = millis();
	head->_packet_configs.packet_length = sizeof(sensor_packet_heartbeat_t);								
}
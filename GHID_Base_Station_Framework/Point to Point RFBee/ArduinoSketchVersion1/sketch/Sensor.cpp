/* 
* Sensor.cpp
*
* Created: 1/25/2014 12:57:59 AM
* Author: francis-ccs
*/


#include "Sensor.h"

// default constructor
SENSOR::SENSOR(){
} //Sensor

void SENSOR::set_priority(byte priority){
	this->priority = priority;
	
}

// Checks if the sensor is still operable
boolean SENSOR::_check_integrity_sensor(){

	// Check if the state was changed to an error or not.
	if((this->state != ERROR_SENSOR_STATE))
		return true;
	else
		return false;	
}
	
boolean SENSOR::check_sensor_environment(){
	
	// we check the error code field first
	if(this->sensor_error_code > 0){
		return false;
		#ifdef DEBUG
			DEBUG_SERIAL.println("[SENSOR %d] Error Code", this->sensor_id);
		#endif
	}
	
	// we then check the state
	if(!_check_integrity_sensor())
		return false;
		#ifdef DEBUG
			DEBUG_SERIAL.println("[SENSOR %d] Error", this->sensor_id);
		#endif
		
	return true;
}

// Sets the state externally
void SENSOR::set_state(sensor_state_t state){
	this->state = state;
}

sensor_state_t SENSOR::get_state(){
	return this->state;
}

void SENSOR::set_error_code(byte error_code){
	this->sensor_error_code = error_code;
	this->state = ERROR_SENSOR_STATE;
}
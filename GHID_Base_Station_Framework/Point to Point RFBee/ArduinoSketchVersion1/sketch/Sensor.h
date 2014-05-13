/* 
* Sensor.h
*
* Created: 1/25/2014 12:57:59 AM
* Author: francis-ccs
*/


#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <Arduino.h>
#include "User_Configs.h"

// Sensor status
enum sensor_state_t {	
	ENABLE_SENSOR,
	DISABLE_SENSOR,
	BOOT_SENSOR_STATE,
	OK_SENSOR_STATE,
	RUN_SENSOR_STATE,
	PAUSE_SENSOR_STATE, 
	IDLE_SENSOR_STATE,
	ERROR_SENSOR_STATE,
	REBOOT_SENSOR_STATE
};

class SENSOR{

public:
	// Sensor id
	byte sensor_id;
	
	//! sensor priority
	byte priority;
	
	// The configs for the sensor
	struct {
			
		// Sensor Channels
		byte sensor_channels;
			
		// Sensor enabled channels
		byte sensor_en_channels;
			
		// Sensor data type
		// - 'A' - analog
		// - 'D' - digital
		byte sensor_data_type;
			
	}sensor_config;
		
	// The sensor sync struct
	struct{
			
		// Sensor sync frequency
		byte sensor_sync_freq;
			
		// Sensor sync priority
		byte sensor_priority;
			
		// Sensor interrupt number
		byte sensor_interrupt_number;
			
	}sensor_sync;
	
	// INIT the sensor object with its priority
	SENSOR();
	
	// Sets the state externally
	void set_state(sensor_state_t state);
	
	// Get the state
	sensor_state_t get_state();
	
	// Checks the sensor environment context
	boolean check_sensor_environment();
	
	//! Sets the priority of the device
	void set_priority(byte priority);
	
	//! Set teh error code
	void set_error_code(byte error_code);

private:
	
	// Sensor error code if needed
	byte sensor_error_code;

	// Sensor state
	// - ENABLE
	// - DISABLE
	sensor_state_t state;
	
	// Checks the integrity of the sensor
	boolean _check_integrity_sensor();
	
};

#endif //__SENSOR_H__

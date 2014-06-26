/*
 * LightSensorDriver.cpp
 *
 *  Created on: 2014-04-16
 *      Author: francispapineau
 */

#include "AnalogSensorDriver.h"

/**
 * The default constructor for the class.
 */
Analog_Sensor_Driver::Analog_Sensor_Driver(uint8_t port) : ADC_Driver (port, 'I'){

	//! Setup the filter
	this->create_FIR_filter(passband_gain, FIR_Coefficients);
}

/**
 * This is the measure method where all the work is done.
 *
 * @return analog_measurement_t		- the result
 */
analog_measurement_t* Analog_Sensor_Driver::measure(){

	//! We filter the input
	this->_measurement.measurement = this->filter(this->read());

	//! Check if its a valid value
	if(this->_measurement.measurement > 0){
		this->_measurement.valid = true;
	}else{
		this->_measurement.valid = false;
	}

	return &this->_measurement;
}


/*
 * ADCDriver.cpp
 *
 *  Created on: 2014-04-16
 *      Author: francispapineau
 */

#include "ADCDriver.h"

// ----------------------------------------------------
// PUBLIC ACCESS

//! The default constructor
ADC_Driver::ADC_Driver(byte pin, byte direction){

	//! Set the important values
	this->_pin_number = pin;
	this->_pin_direction = direction;

	//! Initialize internal variables.
	this->_read_value = 0;

	//! Setup the port
	this->_setup_analog_port();
}

//! The read port method
word ADC_Driver::read(){

	//! Assign the internal value and return it.
	return this->_read_value = analogRead(this->_pin_number);
}

//! The write to the port method
void ADC_Driver::write(byte duty_cycle){

	//! Write the analog duty cycle to the PWM generator.
	analogWrite(this->_pin_number, duty_cycle);
}

/**
 * This is the create method to create an FIR Filter from the base FIR
 * filter class.
 *
 * @param gain						- The filter gain
 * @param coefs						- The filter coefficients.
 * @return bool						- Successful creation
 */
bool ADC_Driver::create_FIR_filter(const float gain, const float* coefs){

	//! We enter the FIR class
	this->_filter = new FIR_Filter(gain, coefs);

	//! Check if the filter is valid
    return true;
}

// ----------------------------------------------------
// PRIVATE ACCESS

//! The setup method
void ADC_Driver::_setup_analog_port(){

	byte direction;

	//! Setup the pin by using the Arduino function
	switch(this->_pin_direction){

		//! Setup an input
		case 'I':
			direction = 0x00;
			break;

		//! Setup an output
		case 'O':
			direction = 0x01;
			break;

		//! Other settings are not supported.
		default:
			break;
	}

	pinMode(this->_pin_number, direction);
}

// ----------------------------------------------------
// PROTECTED ACCESS

/**
 * This is an averaging filter for the signal input read.
 *
 * @return value					- the filtered value
 */
word ADC_Driver::filter(word value){

	//! Process the input
	return (word) this->_filter->process((float) value);
}


/*
 * GHIDDigitalSensor.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_Digital_Port.h"

// ---------------------------------------------------
// PUBLIC CONTEXT

//! The default constructor
Digital_Port::Digital_Port(byte pin, byte direction){

	//! Set the parameters within the class
	this->pin_number = pin;
	this->pin_direction = direction;

	//! initializing the internal variables
	this->trigger_function_pointer = 0;
	this->interrupt_number = 0;
	this->trigger_value = 0;
	this->read_value = 0;

	//! Setup the pin with the values.
	this->_setup_digital_port();

}

//! The trigger settings setter method
void Digital_Port::set_trigger_settings(int trigger_value,
							void* function_ptr, byte interrupt_number){

	//! Check if applicable
	if((this->pin_number < 18) || (this->pin_number > 21)
			|| (this->pin_number < 2) || (this->pin_number > 3)){
		return;
	}

	//! Check if valid interrupt
	if(interrupt_number > 5){
		return;
	}

	//! Assign parameters internaly
	this->trigger_value = trigger_value;

	//! Assign the function address to the internal function pointer.
	this->trigger_function_pointer = &function_ptr;
	this->interrupt_number = interrupt_number;

	//! Set the interrupt on the vector table
	attachInterrupt(this->interrupt_number, this->trigger_function_pointer,
					this->trigger_value);

}

//! The read port method
byte Digital_Port::read_port(){

	//! We read the digital port and return the
	//! read value
	return digitalRead(this->pin_number);

}

//! The write port method
void Digital_Port::write_port(byte value){

	//! We write the value given
	//! We only write the last bit though...
	//! - 01010001 & 0x01 = 1
	//! - 00101000 & 0x01 = 0
	digitalWrite(this->pin_number, value & 0x01);

}

// ---------------------------------------------------
// PRIVATE CONTEXT

//! The setup digital port method (Private)
void Digital_Port::_setup_digital_port(){

	byte direction;

	//! Setup the pin by using the Arduino function
	switch(this->pin_direction){

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

	pinMode(this->pin_number, direction);
}




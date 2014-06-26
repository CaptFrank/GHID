// Do not remove the include below
#include "GHID_Analog_Port.h"

// ----------------------------------------------------
// PUBLIC ACCESS

//! The default constructor
Analog_Port::Analog_Port(byte pin, byte direction){

	//! Set the important values
	this->pin_number = pin;
	this->pin_direction = direction;

	//! Initialize internal variables.
	this->read_value = 0;

	//! Setup the port
	this->_setup_analog_port();
}

//! The read port method
word Analog_Port::read_port(){

	//! Assign the internal value and return it.
	return this->read_value = analogRead(this->pin_number);
}

//! The write to the port method
void Analog_Port::write_port(byte duty_cycle){

	//! Write the analog duty cycle to the PWM generator.
	analogWrite(this->pin_number, duty_cycle);
}

// ----------------------------------------------------
// PRIVATE ACCESS

//! The setup method
void Analog_Port::_setup_analog_port(){

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

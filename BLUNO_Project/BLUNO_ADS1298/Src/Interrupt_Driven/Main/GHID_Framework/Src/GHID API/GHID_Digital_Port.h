/*
 * GHIDDigitalSensor.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef Digital_Port_h_
#define Digital_Port_h_

#include "Arduino.h"

/**
 * This framework back end allows for easy programming of each type of
 * sensor. Either Analog, Digital or Serial Bus devices.
 */
class Digital_Port {

	//! Private Context
	private:

	/**
	 * The pin number, mapped to the Arduino PCB
	 */
	byte pin_number;

	/**
	 * The pin direction, this can be input or output.
	 * 	- Input 	= 'I'
	 * 	- Output 	= 'O'
	 */
	byte pin_direction;

	/**
	 * The pin value that is read from the port.
	 * This can vary from either a binary 0 or binary 1.
	 */
	byte read_value;

	/**
	 * This is the function pointer (address) that is jumped too when the
	 * interrupt is set.
	 */
	void(*trigger_function_pointer)();

	/**
	 * This is the trigger value. The digital pin will trigger an interrupt on
	 * this specific value. This value can be one of the following:
	 * 	- LOW 		-> 0 (0V or reference voltage)
	 * 	- HIGH 		-> 1 (5V)
	 * 	- CHANGE	-> 1 (When the pin toggles)
	 * 	- FALLING	-> 2 (HIGH to LOW)
	 * 	- RISING	-> 3 (LOW to HIGH)
	 *
	 */
	int trigger_value;

	/**
	 * This is the specific interrupt number of which the digital pin is not set.
	 */
	byte interrupt_number;

	/**
	 * This method is the private access setup routine for the digital sensor.
	 * It sets up all the necessary settings on the digital port to
	 * receive the appropriate data.
	 */
	void _setup_digital_port();

	//! Public Context
	public:

	/**
	 * This is the default constructor for digital ports. We can use this
	 * for individual digital ports used.
	 *
	 * 	- The pin value is the digital port used on the Arduino, this
	 * 		value is the mapped name (i.e. digital port 1 = 1)
	 *
	 * 	- The direction value is the direction of the analog pin that is
	 * 		used. In this case this value can be input ('I'), output ('O')
	 * 		or even an input channel with a pull-up resistor ('P')
	 *
	 * @param pin - byte the pin that is used as digital pin
	 * @param direction - byte the direction of the pin (Input / Output)
	 */
	Digital_Port(byte pin, byte direction);

	/**
	 * This method sets a trigger on the digital port. The 2 parameters
	 * trigger value is the actual triggered value. This value can be on
	 * of the following:
	 * 	 - LOW 		-> 0 (0V or reference voltage)
	 * 	- HIGH 		-> 1 (5V)
	 * 	- CHANGE	-> 1 (When the pin toggles)
	 * 	- FALLING	-> 2 (HIGH to LOW)
	 * 	- RISING	-> 3 (LOW to HIGH)
	 *
	 * 	While the function pointer is a void* to the function that will be
	 * 	activated when we get an interrupt on the digital interface.
	 *
	 * 	Note: The interrupts can only be set on pins {2, 3, 21, 20, 19, 18}.
	 * 	These are mapped to {0, 1, 2, 3, 4, 5} respectively.
	 *
	 * @param trigger_value - byte triggered value
	 * @param function_ptr - void* function that will be activated
	 */
	void set_trigger_settings(int trigger_value, void* function_ptr, byte interrupt_number);

	/**
	 * This method is the public access reading method to enable reading of the digital
	 * port. This returns the value read in an unsigned character container. This value can
	 * be either:
	 * 	- Min: 0
	 * 	- Max: 1
	 *
	 * @return result - byte the read value from the digital port
	 */
	byte read_port();

	/**
	 * This method is the write method to write to a digital port.
	 * This is a bit wise write. The value that is written to the port,
	 * must either be 1 or 0.
	 *
	 * @param value - byte either 1 or 0
	 */
	void write_port(byte value);

};

#endif /* Digital_Sensor_h_ */

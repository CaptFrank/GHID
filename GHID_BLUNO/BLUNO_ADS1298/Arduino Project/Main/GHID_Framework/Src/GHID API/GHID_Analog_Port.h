// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section


#ifndef Analog_Port_h_
#define Analog_Port_h_

#include <Arduino.h>

#define MAX_ANALOG_PORTS	15

/**
 * This framework back end allows for easy programming of each type of
 * sensor. Either Analog, Digital or Serial Bus devices.
 */
class Analog_Port{

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
	 * This is the received value from the ADC when read the ADC.
	 */
	word read_value;

	/**
	 * This method is the private access setup routine for the analog sensor.
	 * It sets up all the necessary settings on the analog port to
	 * receive the appropriate data.
	 */
	void _setup_analog_port();

	//! Public Context
	public:

	/**
	 * This is the default constructor for analog ports. We can use this
	 * for individual analog ports used.
	 *
	 * 	- The pin value is the analog port used on the Arduino, this
	 * 		value is the mapped name (i.e. Analog port 1 = A1)
	 *
	 * 	- The direction value is the direction of the analog pin that is
	 * 		used. In this case this value can be input ('I'), output ('O')
	 *
	 * @param pin - byte the pin that is used as analog pin
	 * @param direction - byte the direction of the pin (Input / Output)
	 */
	Analog_Port(byte pin, byte direction);

	/**
	 * This method is the public access reading method to enable reading of the analog
	 * port. This returns the value read in an unsigned integer (word - 16bit value),
	 * the ADC read results in a 10bit value with a range or:
	 * 	- Min: 0
	 * 	- Max: 1024
	 *
	 * @return result - word the read value from the ADC.
	 */
	word read_port();

	/**
	 * This method is the public access method that writes to the analog value.
	 * Note: This method does not output a digital value such as: 00001010
	 * Instead, this method outputs a PWM (Pulse width modulated) signal, with range oF:
	 *	- Min: 0
	 * 	- Max: 255
	 */
	void write_port(byte duty_cycle);

};

//Do not add code below this line
#endif

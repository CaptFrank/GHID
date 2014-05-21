/*
 * ADCDriver.h
 *
 *  Created on: 2014-04-16
 *      Author: francispapineau
 */

#ifndef ADCDRIVER_H_
#define ADCDRIVER_H_

// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section 

#include <Arduino.h>
#include "FIRFilter.h"

/**
 * We define the max number of ports that could exist
 */
#define MAX_ANALOG_PORTS	15

//! -------------------------------------------------------
//! The analog sensor measurments
//! -------------------------------------------------------

//! This is the structure used to encapsulate the analog sensor
//! readings.
typedef struct analog_measurement_t{

	//! The raw voltage measurement
	uint16_t measurement;

	//! The valid measurement flag
	bool valid;
};


/**
 * This framework back end allows for easy programming of each type of
 * sensor. Either Analog, Digital or Serial Bus devices. This is the base
 * class for the analog devices interfaced to the host.
 */
class ADC_Driver{

	//! Private Context
	private:

		/**
		 * The pin number, mapped to the Arduino PCB
		 */
		byte _pin_number;

		/**
		 * The pin direction, this can be input or output.
		 * 	- Input 	= 'I'
		 * 	- Output 	= 'O'
		 */
		byte _pin_direction;

		/**
		 * This is the received value from the ADC when read the ADC.
		 */
		word _read_value;

		/**
		 * The internal container for the filter object.
		 */
		FIR_Filter* _filter;

		/**
		 * This method is the private access setup routine for the analog sensor.
		 * It sets up all the necessary settings on the analog port to
		 * receive the appropriate data.
		 */
		void _setup_analog_port();

	//! Public Context
	public:

		/**
		 * The internal measurment.
		 */
		analog_measurement_t _measurement;

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
		ADC_Driver(const uint8_t pin, const uint8_t direction);

		/**
		 * This is the create method to create an FIR Filter from the base FIR
		 * filter class.
		 *
		 * @param gain						- The filter gain
		 * @param coefs						- The filter coefficients.
		 * @return bool						- Successful creation
		 */
		bool create_FIR_filter(float gain, const float* coefs);

		/**
		 * This method is the public access reading method to enable reading of the analog
		 * port. This returns the value read in an unsigned integer (word - 16bit value),
		 * the ADC read results in a 10bit value with a range or:
		 * 	- Min: 0
		 * 	- Max: 1024
		 *
		 * @return result 					- word the read value from the ADC.
		 */
		word read();

		/**
		 * This method is the public access method that writes to the analog value.
		 * Note: This method does not output a digital value such as: 00001010
		 * Instead, this method outputs a PWM (Pulse width modulated) signal, with range oF:
		 *	- Min: 0
		 * 	- Max: 255
		 */
		void write(byte duty_cycle);
		
	//! Protected Context
	protected:

		/**
		 * This is an averaging filter for the signal input read.
		 *
		 * @param value						- the value to be processed
		 * @return value					- the filtered value
		 */
		word filter(word value);

};

//Do not add code below this line
#endif

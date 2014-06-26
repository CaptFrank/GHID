/*
 * FIRFilter.h
 *
 *  Created on: 2014-04-24
 *      Author: francispapineau
 */

#ifndef FIRFILTER_H_
#define FIRFILTER_H_

#include <Arduino.h>

//! -------------------------------------------------------
//! The FIR filter coefficients
//! -------------------------------------------------------

//! number of filter taps used in FIR Filter
#define FILTER_TAPS					5

//! This is the generic unity gain passband gain coeficient
const float passband_gain = 1.00;

//! This are soem generic coeficients for the FIR filter.
const float FIR_Coefficients[] = {0.021, 0.096, 0.146, 0.096, 0.021};

/**
 * This is the FIR filter class handler
 */
class FIR_Filter {

	// Public Context
	public:
		/**
		 * This is the default constructor for the class object.
		 *
		 * @param gain						- The passband gain
		 * @param coefs						- The FIR ceofficients
		 */
		FIR_Filter(const float gain, const float* coefs);

		/**
		 *	This sets the gain to the filter object.
		 *
		 * @param gain						- The passband gain
		 */
		void set_gain(float gain);

		/**
		 *	This sets the pointer to the FIR coefficients.
		 *
		 * @param coefs						- The FIR coefficients
		 */
		void set_coefficients(const float *coefs);

		/**
		 *	This sets one coefficient within the FIR coefficient array
		 *
		 * @param idx						- The index of the coefficient
		 * @param coef						- The new coef.
		 */
		void set_coefficient(int idx, const float coef);

		/**
		 *	This is the worker method of the class.
		 *
		 * @param in						- The input signal
		 *
		 * @return float					- The signal output
		 */
		int process(float in);

	// Private Context
	private:

		/**
		 * This is the filtered values.
		 */
		float _values[FILTER_TAPS];

		/**
		* This is the filter coefficients.
		*/
		float _coef[FILTER_TAPS];

		/**
		* Declare gain coefficient to scale the output back to normal.
		* Set to 1 and input unity to see what this needs to be.
		*/
		float _gain;

		/**
		* k stores the index of the current array read to create
		* a circular memory through the array
		*/
		uint8_t _k;
};

#endif /* FIRFILTER_H_ */

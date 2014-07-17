/*
 * FIRFilter.h
 *
 *  Created on: 2014-04-24
 *      Author: francispapineau
 */

#ifndef FIRFILTER_H_
#define FIRFILTER_H_

#include "System/Configs.h"

class FIR_Filter {

	// Public Context
	public:
		/**
		 * This is the default constructor for the class object.
		 *
		 * @param gain						- The passband gain
		 * @param coefs						- The FIR ceofficients
		 */
		FIR_Filter(float gain, float* coefs);

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
		void set_coefficients(float *coefs);

		/**
		 *	This sets one coefficient within the FIR coefficient array
		 *
		 * @param idx						- The index of the coefficient
		 * @param coef						- The new coef.
		 */
		void set_coefficient(int idx, float coef);

		/**
		 *	This is the worker method of the class.
		 *
		 * @param in						- The input signal
		 *
		 * @return float					- The signal output
		 */
		float process(float in);

		/**
		 * This is the default deconstructor of the class.
		 */
		virtual ~FIR_Filter();

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

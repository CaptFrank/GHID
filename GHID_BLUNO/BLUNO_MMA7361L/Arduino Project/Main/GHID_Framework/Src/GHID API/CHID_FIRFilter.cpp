/*
 * FIRFilter.cpp
 *
 *  Created on: 2014-04-24
 *      Author: francispapineau
 */

#include "FIRFilter.h"

/**
 * This is the default constructor for the class object.
 *
 * @param gain						- The passband gain
 * @param coefs						- The FIR ceofficients
 */
FIR_Filter::FIR_Filter(float gain, float* coefs){

	//! Init the internal variables.
	this->_k = 0;
	this->_gain = 0;

	//! We set the passband gain
	this->set_gain(gain);

	//! Reset the values array
	for(register uint8_t i = 0; i < FILTER_TAPS; i++){
		this->_values[i] = 0;
	}

	//! Set the coefficient array
	this->set_coefficients(coefs);
}

/**
 *	This sets the gain to the filter object.
 *
 * @param gain						- The passband gain
 */
void FIR_Filter::set_gain(float gain){

	//! Set the passband gain
	this->_gain = gain;
}

/**
 *	This sets the pointer to the FIR coefficients.
 *
 * @param coefs						- The FIR coefficients
 */
void FIR_Filter::set_coefficients(float *coefs){

	//! Set the coefficient array
	for(register uint8_t i = 0; i < FILTER_TAPS; i++){
		this->_coef[i] = coefs[i];
	}
}

/**
 *	This sets one coefficient within the FIR coefficient array
 *
 * @param idx						- The index of the coefficient
 * @param coef						- The new coef.
 */
void FIR_Filter::set_coefficient(int idx, float coef){

	//! Set a single coefficient
	this->_coef[idx] = coef;
}

/**
 *	This is the worker method of the class.
 *
 * @param in						- The input signal
 *
 * @return float					- The signal output
 */
float FIR_Filter::process(float in){

	//! Reset the output variable
	float out = 0;

	//! Store a value in the values array
	this->_values[this->_k] = in;

	//! Process values
	for(register uint8_t i = 0; i < FILTER_TAPS; i ++){
		out += this->_coef[i] * this->_values[(i + _k) % FILTER_TAPS];
	}

	//! We scale the output with the gain value
	out /= this->_gain;

	//! Update the k index
	this->_k = (this->_k++) % FILTER_TAPS;

	//! Output the result
	return out;

}

/*
 * LightSensorDriver.h
 *
 *  Created on: 2014-04-16
 *      Author: francispapineau
 */

#ifndef LIGHTSENSORDRIVER_H_
#define LIGHTSENSORDRIVER_H_

#include "ADCDriver.h"

//! The Light output measurement
#define V_LIGHT							A6

//! The Battery output measurement
#define V_BATTERY						A0

//! The Microphone Buffered Output measurement
#define MIC_BUFF_OUTPUT					A7

/**
 * This class is the handler class that measures the battery voltage.
 * This class extends the ADCDriver class (@see ADCDriver) as it is in
 * fact an analog measurement.
 */
class Analog_Sensor_Driver: public ADC_Driver{

	// Public Context
	public:

		/**
		 * The default constructor for the class.
		 */
		Analog_Sensor_Driver(uint8_t port);

		/**
		 * This is the measure method where all the work is done.
		 */
		 analog_measurement_t* measure();

};
#endif /* LIGHTSENSORDRIVER_H_ */

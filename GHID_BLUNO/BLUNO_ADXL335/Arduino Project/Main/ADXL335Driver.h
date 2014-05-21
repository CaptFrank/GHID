/*
 * ADXL335Driver.h
 *
 * Created: 5/21/2014 1:09:57 PM
 *  Author: Administrator
 */ 


#ifndef ADXL335DRIVER_H_
#define ADXL335DRIVER_H_

#include <Arduino.h>
#include "Utilities.h"
#include "RingBuffer.h"
#include "AnalogSensorDriver.h"

//! Ref voltage defines
#define V_3V					3.3

/**
 * This is the pin map structure for the ADX355 sensor.
 * We use this to setup the sensor.
 */
typedef struct ADXL335_pin_map_t {

	uint8_t self_test_pin;			//!	- PIN 1 ON IC
	uint8_t x_pin;					//! - PIN 7 ON IC
	uint8_t y_pin;					//! - PIN 8 ON IC
	uint8_t z_pin;					//! - PIN 9 ON IC

};

/**
 * This is the ADX355 Analog sensor driver. We use it to acquire data from the
 * sensor as well as trigger actions within the sensor device.
 */
class ADXL335_Driver{
	
	//! Public Context
	public:

		/**
		 * This is the default constructor for the class. A pin map
		 * is passed to the constructor to allow for setting up of the device.
		 *
		 * @param pin_map							- MMA7361L_pin_map_t*
		 * @param ref								- The reference voltage
		 */
		ADXL335_Driver(ADXL335_pin_map_t* pin_map, double ref);

		/**
		 * This is the pin setup method.
		 */
		void begin();
		
		/**
		 *	This method runs the ADC thread
		 *
		 * @param buff								- The RingBuff type
		 */
		void run(RingBuff_t* buff);

		/**
		 * This is a method that gets the raw selected axis value.
		 *
		 * @param axis								- The axis needed to be measured
		 * @return int								- The analog value
		 */
		int get_raw(axis_t axis);

		/**
		 * This is a method that gets the filtered selected axis value.
		 *
		 * @param axis								- The axis needed to be measured
		 * @return int								- The analog value
		 */
		int get_filtered(axis_t axis);

		/**
		 * This is a method that gets the voltage of the selected axis.
		 *
		 * @param axis								- The axis needed to be measured
		 * @return int								- The analog value
		 */
		int get_volt(axis_t axis);

		/**
		 * This is a method that gets the accelerometer value of the selected axis.
		 *
		 * @param axis								- The axis needed to be measured
		 * @return int								- The analog value
		 */
		int get_accel(axis_t axis);

		/**
		 * This method does all conversions and returns the values.
		 *
		 * @param _XAxis							- The x axis value
		 * @param _YAxis							- The y axis value
		 * @param _ZAxis							- The z axis value
		 */
		void get_accel_xyz(int *_XAxis, int *_YAxis, int *_ZAxis);

		/**
		 * This gets the total vector of the 3 components.
		 *
		 * @return int								- The total vector
		 */
		int get_total_vector();

		/**
		 * This method sets the offsets of the axes
		 *
		 * @param xOffSet							- The x axis offset
		 * @param yOffSet							- The y axis offset
		 * @param zOffSet							- The z axis offset
		 */
		void set_offsets(int xOffSet, int yOffSet, int zOffSet);

		/**
		 *	This method calibrates the sensor
		 */
		void calibrate();

		/**
		 * This gets to global orientation of the sensor
		 *
		 * @return									- The orientation
		 */
		int get_orientation();

		//! Private Context
		private:

			//! Pin Map pointer
			ADXL335_pin_map_t* _pin_map;

			//! Axis sensor objects
			struct {
				Analog_Sensor_Driver* _x;
				Analog_Sensor_Driver* _y;
				Analog_Sensor_Driver* _z;
			}_axis;

			//! Offsets structure
			union {
				struct {
					int _x_offset;
					int _y_offset;
					int _z_offset;
				}_offsets;
				int _offsets_array[3];
			}_offset_configs;

			//! Polarities structure
			union {
				struct {
					int _x_pol;
					int _y_pol;
					int _z_pol;
				}_pols;
				int _pols_array[3];
			}_pols_configs;

			//! Ref voltage
			double _ref;

			/**
			 * This maps a voltage value to an integer value
			 *
			 * @param value								- The read voltage
			 * @return int								- The mapped value
			 */
			int _mapADXL335V(int value);

			/**
			 * This maps a gravity value to an integer value
			 *
			 * @param value								- The read value
			 * @return int								- The mapped value
			 */
			int _mapADXL335G(int value);

};



#endif /* ADXL335DRIVER_H_ */

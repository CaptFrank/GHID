/*
 * MMA7361LDriver.cpp
 *
 * Created: 5/21/2014 1:10:40 PM
 *  Author: Administrator
 */ 

#include "MMA7361LDriver.h"

//! Public Context

/**
 * This is the default constructor for the class. A pin map
 * is passed to the constructor to allow for setting up of the device.
 *
 * @param pin_map							- MMA7361L_pin_map_t*
 */
MMA7361L_Driver::MMA7361L_Driver(MMA7361L_pin_map_t* pin_map, double ref){

	//! We set the internal pin map reference
	this->_pin_map = pin_map;

	//! Set the other vars
	this->_sensitivity = false;
	this->_sleep = false;

	//! Set the reference voltage
	this->_ref = ref;
}

/**
 * This is the pin setup method.
 */
void MMA7361L_Driver::begin(){

	//! We setup the Analog sensors
	this->_axis._x = new Analog_Sensor_Driver(this->_pin_map->x_pin);
	this->_axis._y = new Analog_Sensor_Driver(this->_pin_map->y_pin);
	this->_axis._z = new Analog_Sensor_Driver(this->_pin_map->z_pin);

	//! We save the config pins
	this->_pins._g_select_pin = this->_pin_map->g_select_pin;
	this->_pins._self_test_pin = this->_pin_map->self_test_pin;
	this->_pins._sleep_pin = this->_pin_map->sleep_pin;
	this->_pins._zero_g_pin = this->_pin_map->zero_g_pin;

	//! We setup the pins
	pinMode(this->_pins._g_select_pin, 			OUTPUT);
	pinMode(this->_pins._self_test_pin, 		OUTPUT);
	pinMode(this->_pins._sleep_pin, 			OUTPUT);
	pinMode(this->_pins._zero_g_pin, 			OUTPUT);

	//! We configure the device
	digitalWrite(this->_pins._sleep_pin, 		HIGH);
	digitalWrite(this->_pins._self_test_pin, 	LOW);

	//! We set sleep to false
	this->_sleep = false;

	//! We set the offsets
	this->set_offsets(0, 0, 0);

	//! We set the sensiticity
	this->set_sensitivity(HIGH);
}


/**
 *	This method runs the ADC thread
 *
 * @param buff								- The RingBuff type
 */
void MMA7361L_Driver::run(RingBuff_t* buff){
	
	//! Containers
	int x_axis;
	int y_axis;
	int z_axis;
	
	//! We get all axis values
	x_axis = this->get_accel(X_AXIS);
	delay(10);
	y_axis = this->get_accel(Y_AXIS);
	delay(10);
	z_axis = this->get_accel(Z_AXIS);
	delay(10);
	
	//! Create a data container
	uint8_t _data[SIZE_OF_DATA] = {x_axis, y_axis, z_axis, 0x00};
	
	//! We put the data into the ringbuffer
	for(uint8_t i = 0; i < sizeof(_data); i++){
		RingBuffer_Insert(buff, _data[i]);
	}
}

/**
 * This is a method that gets the raw selected axis value.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int MMA7361L_Driver::get_raw(axis_t axis){

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
			return analogRead(this->_pin_map->x_pin);

		case Y_AXIS:
			return analogRead(this->_pin_map->y_pin);

		case Z_AXIS:
			return analogRead(this->_pin_map->z_pin);

		//! Nothing to do
		default:
			return 0;
	}

}

/**
 * This is a method that gets the filtered selected axis value.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int MMA7361L_Driver::get_filtered(axis_t axis){

	//! Temp data
	Analog_Sensor_Driver* temp;
	word offset;

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
			temp = this->_axis._x;
			offset = this->_offset_configs._offsets._x_offset;
			break;

		case Y_AXIS:
			temp = this->_axis._y;
			offset = this->_offset_configs._offsets._y_offset;
			break;

		case Z_AXIS:
			temp = this->_axis._z;
			offset = this->_offset_configs._offsets._z_offset;
			break;

		//! Nothing to do
		default:
			return 0;
	}

	//! We measure
	analog_measurement_t* measurment = temp->measure();
	if(measurment->valid){
		return int(measurment->measurement) + offset;
	}else{
		return 0;
	}
}

/**
 * This is a method that gets the voltage of the selected axis.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int MMA7361L_Driver::get_volt(axis_t axis){
		return this->_mapMMA7361V(this->get_raw(axis));
}

/**
 * This is a method that gets the accelerometer value of the selected axis.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int MMA7361L_Driver::get_accel(axis_t axis){

	//! Temp data
	int value;

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
		value = this->get_raw(X_AXIS);
		break;

		case Y_AXIS:
		value = this->get_raw(Y_AXIS);
		break;

		case Z_AXIS:
		value = this->get_raw(Z_AXIS);
		break;

		//! Nothing to do
		default:
		return 0;
	}

	return this->_mapMMA7361G(value);
}

/**
 * This method does all conversions and returns the values.
 *
 * @param _XAxis							- The x axis value
 * @param _YAxis							- The y axis value
 * @param _ZAxis							- The z axis value
 */
void MMA7361L_Driver::get_accel_xyz(int *_XAxis, int *_YAxis, int *_ZAxis){

	*_XAxis = this->get_accel(X_AXIS);
	*_YAxis = this->get_accel(Y_AXIS);
	*_ZAxis = this->get_accel(Z_AXIS);

}

/**
 * This gets the total vector of the 3 components.
 *
 * @return int								- The total vector
 */
int MMA7361L_Driver::get_total_vector(){

	return sqrt(square(this->_mapMMA7361G(this->get_raw(X_AXIS))) +
				square(this->_mapMMA7361G(this->get_raw(Y_AXIS))) +
				square(this->_mapMMA7361G(this->get_raw(Z_AXIS))));

}

/**
 * This method sets the offsets of the axes
 *
 * @param xOffSet							- The x axis offset
 * @param yOffSet							- The y axis offset
 * @param zOffSet							- The z axis offset
 */
void MMA7361L_Driver::set_offsets(int xOffSet, int yOffSet, int zOffSet){

	int mapper;

	//! Switch based on the reference voltage
	if(this->_ref == V_3V){
		mapper = 3300;
	}else{
		mapper = 5000;
	}

	//! Set the offsets
	this->_offset_configs._offsets._x_offset = map(xOffSet, 0, mapper, 0, 1024);
	this->_offset_configs._offsets._y_offset = map(yOffSet, 0, mapper, 0, 1024);
	this->_offset_configs._offsets._z_offset = map(zOffSet, 0, mapper, 0, 1024);
}

/**
 *	This method calibrates the sensor
 */
void MMA7361L_Driver::calibrate(){

	//! Set containers
	double var = 5000;
	double sumX = 0;
	double sumY = 0;
	double sumZ = 0;

	//! Get the values of the voltage on each axis 5000 times.
	for (int i = 0; i < var; i++){

		sumX = sumX + this->get_volt(X_AXIS);
		sumY = sumY + this->get_volt(Y_AXIS);
		sumZ = sumZ + this->get_volt(Z_AXIS);
	}

	//! If the sensitivity is not set
	if (!this->_sensitivity){

		//! We adjust the offsets based on the coefficients in the datasheet
		this->set_offsets(1672 - sumX / var, 1671 - sumY / var, 1876 - sumZ / var);

	}else{

		//! We adjust the offsets based on the coefficients in the datasheet
		this->set_offsets(1650 - sumX / var,1650 - sumY / var, 2450 - sumZ / var);
	}
}

/**
 * This gets to global orientation of the sensor
 *
 * @return									- The orientation
 */
int MMA7361L_Driver::get_orientation(){

	//! Set containers
	int gemiddelde = 10;
	int x = 0;
	int y = 0;
	int z = 0;
	int xAbs = 0;
	int yAbs = 0;
	int zAbs = 0;

	//! We take 10 samples to average
	for(int i = 0; i < gemiddelde ; i++){

		x = x + this->get_accel(X_AXIS);
		y = y + this->get_accel(Y_AXIS);
		z = z + this->get_accel(Z_AXIS);
	}

	//! We average
	x = x/gemiddelde;
	y = y/gemiddelde;
	z = z/gemiddelde;

	//! We get the absolute value of the values
	xAbs = abs(100 - abs(x));
	yAbs = abs(100 - abs(y));
	zAbs = abs(100 - abs(z));

	//! If in the direction of x
	if (xAbs < yAbs && xAbs < zAbs){

		//! negative or positive?
		if (x > 0){
			return 1;
		}
		return -1;
	}

	//! If in the direction of y
	if (yAbs < xAbs && yAbs < zAbs){

		//! negative or positive?
		if (y>0){
			return 2;
		}
		return -2;
	}

	//! If in the direction of z
	if (zAbs < xAbs && zAbs < yAbs){

		//! negative or positive?
		if (z > 0){
			return 3;
		}
		return -3;
	}
	return 0;
}

/**
 * This sets the sensitivity of the device to either LOW
 * or HIGH
 *
 * @param sensi								- The sensitivity
 */
void MMA7361L_Driver::set_sensitivity(bool sensi){

	//! We set the sensitivity
	this->_sensitivity = sensi;
	digitalWrite(this->_pins._g_select_pin, !sensi);
}

/**
 *	This triggers a remtoe sleep.
 */
void MMA7361L_Driver::sleep(){

	//! We check that the device isn't already in sleep
	if(!this->_sleep){
		digitalWrite(this->_pins._sleep_pin, LOW);
		this->_sleep = true;
	}
}

/**
 * This wakes the sensor.
 */
void MMA7361L_Driver::wake(){

	//! Check to see if the device is not already alive
	if(this->_sleep){
		digitalWrite(this->_pins._sleep_pin, HIGH);
		this->_sleep = false;
		delay(2);
	}
}

//! Private Context

/**
 * This maps a voltage value to an integer value
 *
 * @param value								- The read voltage
 * @return int								- The mapped value
 */
int MMA7361L_Driver::_mapMMA7361V(int value){

	//! We check if the sensitivity is on
	if(!this->_sensitivity){

		//! Switch on the reference voltage
		if (this->_ref == V_3V){

			return map(value,0,1024,-825,800);

		//! 5V
		}else{

			return map(value,0,1024,-800,1600);
		}

	}else{

		//! Switch on the reference voltage
		if (this->_ref == V_3V){

			return map(value,0,1024,-206,206);

		}else{

			return map(value,0,1024,-260,419);
		}
	}
}

/**
 * This maps a gravity value to an integer value
 *
 * @param value								- The read value
 * @return int								- The mapped value
 */
int MMA7361L_Driver::_mapMMA7361G(int value){

	//! Switch on the reference voltage
	if (this->_ref == V_3V){

		return map(value,0,1024,(-MAX_AXIS_VALUE),(MAX_AXIS_VALUE));

	//! 5V
	}else{

		return map(value,0,1024,(-MAX_AXIS_VALUE),(MAX_AXIS_VALUE));
	}
}

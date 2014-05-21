/*
 * ADXL335Driver.cpp
 *
 * Created: 5/21/2014 1:10:12 PM
 *  Author: Administrator
 */ 
/*
 * ADXL335Driver.cpp
 *
 * Created: 5/21/2014 1:10:40 PM
 *  Author: Administrator
 */

#include "ADXL335Driver.h"

//! Public Context

/**
 * This is the default constructor for the class. A pin map
 * is passed to the constructor to allow for setting up of the device.
 *
 * @param pin_map							- MMA7361L_pin_map_t*
 */
ADXL335_Driver::ADXL335_Driver(ADXL335_pin_map_t* pin_map, double ref){

	//! We set the internal pin map reference
	this->_pin_map = pin_map;

	//! Set the reference voltage
	this->_ref = ref;
}

/**
 * This is the pin setup method.
 */
void ADXL335_Driver::begin(){

	//! We setup the Analog sensors
	this->_axis._x = new Analog_Sensor_Driver(this->_pin_map->x_pin);
	this->_axis._y = new Analog_Sensor_Driver(this->_pin_map->y_pin);
	this->_axis._z = new Analog_Sensor_Driver(this->_pin_map->z_pin);

	//! Set the output pins
	pinMode(this->_pin_map->self_test_pin,				OUTPUT);
	digitalWrite(this->_pin_map->self_test_pin,			LOW);
	
	//! We set the offsets
	this->set_offsets(0, 0, 0);
}

/**
 *	This method runs the ADC thread
 *
 * @param buff								- The RingBuff type
 */
void ADXL335_Driver::run(RingBuff_t* buff){
	
	//! Containers
	int x_axis;
	int y_axis;
	int z_axis;
	
	//! We get all axis values
	x_axis = this->get_accel(X_AXIS);
	y_axis = this->get_accel(Y_AXIS);
	z_axis = this->get_accel(Z_AXIS);
	
	//! Create a data container
	uint8_t _data[7] = {x_axis, y_axis, z_axis, 0x00};
	
	//! We put the data into the ringbuffer
	for(register uint8_t i = 0; i < sizeof(_data); i++){
		RingBuffer_Insert(buff, _data[i]);
	}
}

/**
 * This is a method that gets the raw selected axis value.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int ADXL335_Driver::get_raw(axis_t axis){

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
			return analogRead(this->_pin_map->x_pin) + this->_offset_configs._offsets._x_offset + 2;

		case Y_AXIS:
			return analogRead(this->_pin_map->y_pin) + this->_offset_configs._offsets._y_offset + 2;

		case Z_AXIS:
			return analogRead(this->_pin_map->z_pin) + this->_offset_configs._offsets._z_offset;

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
int ADXL335_Driver::get_filtered(axis_t axis){

	//! Temp data
	Analog_Sensor_Driver* temp;
	word offset;

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
			temp = this->_axis._x;
			offset = this->_offset_configs._offsets._x_offset + 2;
			break;

		case Y_AXIS:
			temp = this->_axis._y;
			offset = this->_offset_configs._offsets._y_offset + 2;
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
		return measurment->measurement + offset;
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
int ADXL335_Driver::get_volt(axis_t axis){
		return this->_mapADXL335V(this->get_raw(axis));
}

/**
 * This is a method that gets the accelerometer value of the selected axis.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int ADXL335_Driver::get_accel(axis_t axis){

	//! Temp data
	Analog_Sensor_Driver* temp;

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
			temp = this->_axis._x;
			break;

		case Y_AXIS:
			temp = this->_axis._y;
			break;

		case Z_AXIS:
			temp = this->_axis._z;
			break;

		//! Nothing to do
		default:
			return 0;
	}

	//! We measure
	analog_measurement_t* measurment = temp->measure();
	if(measurment->valid){
		return this->_mapADXL335G((int)measurment->measurement);
	}else{
		return 0;
	}

}

/**
 * This method does all conversions and returns the values.
 *
 * @param _XAxis							- The x axis value
 * @param _YAxis							- The y axis value
 * @param _ZAxis							- The z axis value
 */
void ADXL335_Driver::get_accel_xyz(int *_XAxis, int *_YAxis, int *_ZAxis){

	*_XAxis = this->get_accel(X_AXIS);
	*_YAxis = this->get_accel(Y_AXIS);
	*_ZAxis = this->get_accel(Z_AXIS);

}

/**
 * This gets the total vector of the 3 components.
 *
 * @return int								- The total vector
 */
int ADXL335_Driver::get_total_vector(){

	return sqrt(square(this->_mapADXL335G(this->get_raw(X_AXIS))) +
				square(this->_mapADXL335G(this->get_raw(Y_AXIS))) +
				square(this->_mapADXL335G(this->get_raw(Z_AXIS))));

}

/**
 * This method sets the offsets of the axes
 *
 * @param xOffSet							- The x axis offset
 * @param yOffSet							- The y axis offset
 * @param zOffSet							- The z axis offset
 */
void ADXL335_Driver::set_offsets(int xOffSet, int yOffSet, int zOffSet){

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
void ADXL335_Driver::calibrate(){

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

	//! We adjust the offsets based on the coefficients in the datasheet
	this->set_offsets(1650 - sumX / var,1650 - sumY / var, 2450 - sumZ / var);

	//! Otherwise no calibration can be done we reset the offsets
	if (abs(this->get_orientation()) != 3 ) {
		this->set_offsets(0, 0, 0);
	}

}

/**
 * This gets to global orientation of the sensor
 *
 * @return									- The orientation
 */
int ADXL335_Driver::get_orientation(){

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

//! Private Context

/**
 * This maps a voltage value to an integer value
 *
 * @param value								- The read voltage
 * @return int								- The mapped value
 */
int ADXL335_Driver::_mapADXL335V(int value){

	//! Switch on the reference voltage
	if (this->_ref == V_3V){

		return map(value,0,1024,-206,206);

	}else{

		return map(value,0,1024,-260,419);
	}
}

/**
 * This maps a gravity value to an integer value
 *
 * @param value								- The read value
 * @return int								- The mapped value
 */
int ADXL335_Driver::_mapADXL335G(int value){

	//! Switch on the reference voltage
	if (this->_ref == V_3V){

		return map(value,0,1024,0,3300);

	//! 5V
	}else{

		return map(value,0,1024,0,5000);
	}
}
